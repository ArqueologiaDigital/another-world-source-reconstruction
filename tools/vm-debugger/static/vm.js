// The Another World virtual machine, in the browser.
//
// `AnotherWorld_VMTools` has no interpreter: `awvm` unpacks, disassembles and
// renders polygons, and `exectrace` crawls code paths statically. Nothing in
// the toolchain runs the bytecode, so this does.
//
// The opcode set is the one `awvm/src/disasm.rs` decodes -- same operand widths,
// same encodings, same two `video` forms -- so a disagreement between what this
// executes and what `src/levels/<branch>/<STAGE>.asm` says is a bug here and
// nowhere else.
//
// What it is built for, beyond running: every `video` instruction appends a
// record to `frame.draws` with the constant's offset, its anchor, its zoom, the
// palette in force, the thread and pc that issued it, and the polygons it
// produced. That list is the whole point -- it is what lets the debugger label
// what is on screen, count what is still numbered, and light up the exact area
// one constant covers.

import { PolygonRenderer } from "./polygons.js";

export const W = 320, H = 200;

// The handful of variables the VM itself reads or writes. Names as the
// disassembly spells them, so a panel can show the same word the .asm does.
export const VAR = {
  RANDOM_SEED: 0x3C,
  LAST_KEYCHAR: 0xDA,
  HERO_POS_UP_DOWN: 0xE5,
  MUS_MARK: 0xF4,
  SCROLL_Y: 0xF9,
  HERO_ACTION: 0xFA,
  HERO_POS_JUMP_DOWN: 0xFB,
  HERO_POS_LEFT_RIGHT: 0xFC,
  HERO_POS_MASK: 0xFD,
  HERO_ACTION_POS_MASK: 0xFE,
  PAUSE_SLICES: 0xFF,
};

const INACTIVE = 0xFFFF;
const KILL = 0xFFFE;
const NUM_THREADS = 64;

export class VM {
  /**
   * @param {object} roms {bytecode, cinematic, palettes, video2, chargen,
   *                       strData, strIndex} as Uint8Array
   * @param {object} [opts] {checkpoints} -- the parsed static/checkpoints.json.
   *   Without it the VM can still run, but only from the all-zero state that
   *   leaves four of the eight stages deleting all 64 threads on entry.
   */
  constructor(roms, opts) {
    this.roms = roms;
    this.checkpoints = (opts && opts.checkpoints) || null;
    this.cine = new PolygonRenderer(roms.cinematic, roms.palettes);
    this.vid2 = roms.video2
      ? new PolygonRenderer(roms.video2, roms.palettes) : null;

    this.vars = new Int16Array(256);
    this.pc = new Uint16Array(NUM_THREADS).fill(INACTIVE);
    this.requestedPc = new Uint16Array(NUM_THREADS).fill(INACTIVE);
    this.frozen = new Uint8Array(NUM_THREADS);
    this.requestedFreeze = new Uint8Array(NUM_THREADS).fill(0xFF);

    this.pages = [0, 1, 2, 3].map(() => new Uint8Array(W * H));
    this.workPage = 2;        // getPagePtr's default is page 0; set by setupPart
    this.frontPage = 2;
    this.backPage = 1;

    this.level = 0;
    this.palette = 0;
    this.frame = 0;
    this.halted = false;
    this.gameOver = false;

    // Input. `keys` is a bitmask in the reference's order: up 1, right 2,
    // down 4, left 8, action 16.
    this.keys = 0;

    // per-frame, cleared by runFrame
    this.draws = [];
    this.sounds = [];
    this.texts = [];
    this.events = [];
    this.seq = 0;
  }

  // ---- setup ---------------------------------------------------------
  /** The five variables the copy-protection check reads, and passing values.
   *
   * Kept as the FALLBACK for when no checkpoint table is loaded, and as the
   * documentation of why an unseeded stage is silent. Four stages -- LAKE,
   * CAVES, ENDING and, in msdos, PASSCODE -- run a check before doing anything,
   * and its failure path is `deleteChannels first=0x00, last=0x3F`: it deletes
   * all 64 threads and the stage draws nothing forever. The conditions, off
   * `LIKELY_A_COPY_PROTECTION_MECHANISM` in `src/levels/dos_1992/CAVES.asm`:
   *
   *     and [0xBC], 0x0010   je [0xBC], 0x00 -> fail    bit 4 of 0xBC set
   *     and [0xF8], 0x0080   je [0xF8], 0x00 -> fail    bit 7 of 0xC6 set
   *     and [0xF8], 0x003C   jne [0xF8], 0x14 -> fail   0xE4 & 0x3C == 0x14
   *     jne [0xF2], 0x0FA0 -> fail                      0xF2 == 0x0FA0
   *     jne [COPY_PROTECT_TOKEN], 0x21 -> fail          0xDC == 0x21
   *
   * `and [0xBC], 0x0010` writes back into 0xBC, so these are read once and
   * consumed, and the failure path latches: it sets 0xF2 to 0x1770, not 0x0FA0.
   *
   * **These five are enough to make a stage DRAW and not enough to make it
   * PLAY.** The reference engines carry 49 registers per checkpoint, and the
   * rest are what a real playthrough would have left behind -- hero position,
   * screen number, the scroll anchor, the room's own state. A stage seeded with
   * only these five reaches its entry point and then behaves like a machine
   * missing most of its memory, which is the freeze this project hit before
   * `checkpoints.json` existed. The check's own table, LEVEL_00, is these five
   * plus 0x54 -- the intro needs nothing else, which is why they were what an
   * independent derivation from the listing found.
   */
  static PROTECTION_PASS = { 0xBC: 0x0010, 0xC6: 0x0080, 0xE4: 0x0014,
                             0xF2: 0x0FA0, 0xDC: 0x0021 };

  /** Which checkpoints exist for a part, in order. [] when none are loaded. */
  checkpointsFor(part) {
    if (!this.checkpoints) return [];
    return this.checkpoints.checkpoints.filter((c) => c.part === (part & 0xF));
  }

  /** Start a stage: the reference's setupPart, plus a checkpoint's registers.
   *
   * `opts.checkpoint` selects one by its `level` number; the default is the
   * first one listed for this part. CAVES has nine, CAPSULE three, the rest
   * one each, and they are different rooms -- picking one is picking where in
   * the stage you arrive.
   *
   * Registers 0x00..0x3F are zeroed before the table is applied and
   * 0x40..0xFF are left alone, exactly as the reference's `restart_level`
   * does: a checkpoint table is the delta from what the previous part left
   * behind, not a whole machine state.
   *
   * `opts.protection === false` applies nothing at all and enters truly cold,
   * which is what a fresh boot does and what leaves four of the eight stages
   * blank. With no table loaded, the five-variable fallback above is used
   * instead, which is enough to draw and not enough to play.
   */
  setupPart(level, opts) {
    this.level = level & 0xF;
    this.cine.setLevel(this.level);
    this.pc.fill(INACTIVE);
    this.requestedPc.fill(INACTIVE);
    this.frozen.fill(0);
    this.requestedFreeze.fill(0xFF);
    this.pc[0] = 0;
    this.palette = 0;
    this.frame = 0;
    this.halted = false;
    this.gameOver = false;
    this.keys = 0;
    for (const p of this.pages) p.fill(0);
    this.workPage = 2; this.frontPage = 2; this.backPage = 1;

    const cold = opts && opts.protection === false;
    let applied = null;
    if (!cold) {
      const avail = this.checkpointsFor(this.level);
      const want = opts && opts.checkpoint;
      const cp = avail.find((c) => c.level === want) || avail[0];
      if (cp) {
        for (let i = 0; i < 0x40; i++) this.vars[i] = 0;
        for (const [v, val] of Object.entries(cp.registers))
          this.vars[Number(v)] = val;
        applied = cp.level;
      } else {
        for (const [v, val] of Object.entries(VM.PROTECTION_PASS))
          this.vars[Number(v)] = val;
      }
    }
    this.checkpoint = applied;
    this.events.push({ kind: "setupPart", level: this.level,
                       checkpoint: applied, protection: !cold });
  }

  // ---- input ----------------------------------------------------------
  /** up 1, right 2, down 4, left 8, action 16 -- the reference's bit order. */
  static KEY = { UP: 1, RIGHT: 2, DOWN: 4, LEFT: 8, ACTION: 16 };

  keyDown(bit) { this.keys |= bit; }
  keyUp(bit) { this.keys &= ~bit; }

  /** Publish the key state into the six variables the scripts poll.
   *
   * Called once per frame, before any thread runs, which is where the
   * reference calls it (at the wrap back to thread 0). Without this the hero
   * never moves however the stage is seeded: nothing else writes these.
   *
   * 0xFC left/right as -1/0/+1, 0xE5 and 0xFB up/down the same, 0xFD a bitmask
   * of the directions held (right 1, left 2, down 4, up 8), 0xFA the action
   * key as 0/1, and 0xFE the same mask with 0x80 set while action is held.
   */
  processInput() {
    const K = VM.KEY;
    let lr = 0, ud = 0, mask = 0;
    if (this.keys & K.RIGHT) { lr = 1; mask |= 1; }
    if (this.keys & K.LEFT) { lr = -1; mask |= 2; }
    if (this.keys & K.DOWN) { ud = 1; mask |= 4; }
    if (this.keys & K.UP) { ud = -1; mask |= 8; }
    this.vars[0xFC] = lr;
    this.vars[0xE5] = ud;
    this.vars[0xFB] = ud;
    this.vars[0xFD] = mask;
    if (this.keys & K.ACTION) {
      this.vars[0xFA] = 1;
      this.vars[0xFE] = mask | 0x80;
    } else {
      this.vars[0xFA] = 0;
      this.vars[0xFE] = mask;
    }
  }

  // ---- bytecode access ------------------------------------------------
  fetch() {
    const v = this.roms.bytecode[(this.level << 16) | this.sp];
    this.sp = (this.sp + 1) & 0xFFFF;
    return v;
  }
  fetch16() { const h = this.fetch(); return (h << 8) | this.fetch(); }

  pageIndex(id) {
    if (id <= 3) return id;
    if (id === 0xFF) return this.backPage;
    if (id === 0xFE) return this.frontPage;
    return 0;
  }

  // ---- one frame -------------------------------------------------------
  /**
   * Run every live thread until each breaks or dies. Returns the frame record
   * the debugger panels are built from.
   */
  runFrame() {
    this.draws = []; this.sounds = []; this.texts = []; this.events = [];
    this.seq = 0;
    this.processInput();

    for (let i = 0; i < NUM_THREADS; i++) {
      if (this.requestedFreeze[i] !== 0xFF) {
        this.frozen[i] = this.requestedFreeze[i];
        this.requestedFreeze[i] = 0xFF;
      }
    }
    for (let i = 0; i < NUM_THREADS; i++) {
      if (this.requestedPc[i] !== INACTIVE) {
        this.pc[i] = this.requestedPc[i] === KILL ? INACTIVE : this.requestedPc[i];
        this.requestedPc[i] = INACTIVE;
      }
    }

    const ran = [];
    for (let i = 0; i < NUM_THREADS; i++) {
      if (this.frozen[i] || this.pc[i] === INACTIVE) continue;
      this.sp = this.pc[i];
      this.thread = i;
      this.stack = [];
      this.stop = false;
      const startPc = this.sp;
      let guard = 0;
      while (!this.stop && guard++ < 200000) this.step();
      if (guard >= 200000) {
        this.events.push({ kind: "runaway", thread: i, pc: startPc });
        this.pc[i] = INACTIVE;
      } else if (this.pc[i] !== INACTIVE) {
        this.pc[i] = this.sp;
      }
      ran.push({ thread: i, from: startPc, to: this.sp });
    }

    this.frame++;
    return {
      frame: this.frame,
      level: this.level,
      palette: this.palette,
      draws: this.draws,
      sounds: this.sounds,
      texts: this.texts,
      events: this.events,
      ran,
      frontPage: this.frontPage,
    };
  }

  // ---- one instruction --------------------------------------------------
  step() {
    const pcAt = this.sp;
    const op = this.fetch();

    if (op & 0x80) {                       // compact video
      const lo = this.fetch();
      const offset = (((op & 0x7F) << 8) | lo) * 2;
      const x = this.fetch(), y = this.fetch();
      return this.video("cinematic", offset, x, y, 0x40, pcAt,
                        { x: "imm", y: "imm", zoom: "imm" });
    }
    if (op & 0x40) {                       // full video
      const o1 = this.fetch(), o2 = this.fetch();
      const offset = (((o1 & 0x7F) << 8) | o2) * 2;

      let x = this.fetch(), ax = "imm";
      if ((op & 0x20) === 0) {
        if ((op & 0x10) === 0) x = (x << 8) | this.fetch();
        else { x = this.vars[x]; ax = "var"; }
      } else if (op & 0x10) x += 0x100;

      let y, ay = "imm";
      if ((op & 8) === 0) {
        if ((op & 4) === 0) { y = this.fetch(); y = (y << 8) | this.fetch(); }
        else { y = this.vars[this.fetch()]; ay = "var"; }
      } else y = this.fetch();

      let zoom = 0x40, az = "imm";
      if ((op & 2) === 0) {
        if (op & 1) { zoom = this.vars[this.fetch()]; az = "var"; }
      } else if ((op & 1) === 0) zoom = this.fetch();

      const kind = (op & 3) === 3 ? "video2" : "cinematic";
      return this.video(kind, offset, x, y, zoom, pcAt, { x: ax, y: ay, zoom: az });
    }

    switch (op) {
      case 0x00: { const d = this.fetch(); this.vars[d] = this.fetch16() << 16 >> 16; break; }
      case 0x01: { const d = this.fetch(), s = this.fetch(); this.vars[d] = this.vars[s]; break; }
      case 0x02: { const d = this.fetch(), s = this.fetch(); this.vars[d] += this.vars[s]; break; }
      case 0x03: { const d = this.fetch(); this.vars[d] += this.fetch16() << 16 >> 16; break; }
      case 0x04: { const a = this.fetch16(); this.stack.push(this.sp); this.sp = a; break; }
      case 0x05: {
        if (this.stack.length === 0) { this.stop = true; break; }
        this.sp = this.stack.pop(); break;
      }
      case 0x06: this.stop = true; break;                       // break
      case 0x07: this.sp = this.fetch16(); break;               // jmp
      case 0x08: {                                              // setup channel
        const th = this.fetch(), a = this.fetch16();
        this.requestedPc[th] = a;
        this.events.push({ kind: "setup", thread: th, address: a, by: this.thread });
        break;
      }
      case 0x09: {                                              // djnz
        const v = this.fetch(), a = this.fetch16();
        this.vars[v]--;
        if (this.vars[v] !== 0) this.sp = a;
        break;
      }
      case 0x0A: {                                              // conditional jmp
        const sub = this.fetch(), b = this.fetch(), c = this.fetch();
        let rhs;
        if (sub & 0x80) rhs = this.vars[c];
        else if (sub & 0x40) rhs = ((c << 8) | this.fetch()) << 16 >> 16;
        else rhs = c;
        const a = this.fetch16();
        const lhs = this.vars[b];
        let take = false;
        switch (sub & 7) {
          case 0: take = lhs === rhs; break;
          case 1: take = lhs !== rhs; break;
          case 2: take = lhs > rhs; break;
          case 3: take = lhs >= rhs; break;
          case 4: take = lhs < rhs; break;
          case 5: take = lhs <= rhs; break;
          default: this.stop = true; return;
        }
        if (take) this.sp = a;
        break;
      }
      case 0x0B: { this.palette = this.fetch(); this.fetch(); break; }   // setPalette
      case 0x0C: {                                              // freeze/unfreeze/delete
        const first = this.fetch(), last = this.fetch(), type = this.fetch();
        if (last < first) break;
        for (let i = first; i <= last && i < NUM_THREADS; i++) {
          if (type === 2) this.requestedPc[i] = KILL;
          else this.requestedFreeze[i] = type;
        }
        this.events.push({ kind: ["freeze", "unfreeze", "delete"][type] || "?",
                           first, last, by: this.thread });
        break;
      }
      case 0x0D: this.workPage = this.pageIndex(this.fetch()); break;
      case 0x0E: {
        const p = this.pageIndex(this.fetch()), c = this.fetch();
        this.pages[p].fill(c & 0x0F);
        break;
      }
      case 0x0F: {                                              // copyVideoPage
        let src = this.fetch(); const dst = this.pageIndex(this.fetch());
        let vscroll = 0;
        if (src >= 0xFE || !(src & 0x80)) {
          src = this.pageIndex(src);
        } else {
          vscroll = this.vars[VAR.SCROLL_Y];
          src = this.pageIndex(src & 3);
        }
        this.copyPage(src, dst, vscroll);
        break;
      }
      case 0x10: {                                              // blitFramebuffer
        const id = this.fetch();
        this.vars[VAR.PAUSE_SLICES] = this.vars[VAR.PAUSE_SLICES]; // pacing is the host's
        if (id !== 0xFE) {
          if (id === 0xFF) { const t = this.frontPage; this.frontPage = this.backPage; this.backPage = t; }
          else this.frontPage = this.pageIndex(id);
        }
        this.events.push({ kind: "blit", page: this.frontPage });
        break;
      }
      case 0x11: this.pc[this.thread] = INACTIVE; this.stop = true; break;  // killChannel
      case 0x12: {                                              // text
        const id = this.fetch16(), x = this.fetch(), y = this.fetch(), color = this.fetch();
        this.texts.push({ id, x, y, color, thread: this.thread, pc: pcAt });
        break;
      }
      case 0x13: { const a = this.fetch(), b = this.fetch(); this.vars[a] -= this.vars[b]; break; }
      case 0x14: { const a = this.fetch(); this.vars[a] &= this.fetch16(); break; }
      case 0x15: { const a = this.fetch(); this.vars[a] |= this.fetch16(); break; }
      case 0x16: { const a = this.fetch(); this.vars[a] <<= (this.fetch16() & 15); break; }
      case 0x17: { const a = this.fetch(); this.vars[a] = (this.vars[a] & 0xFFFF) >>> (this.fetch16() & 15); break; }
      case 0x18: {                                              // play
        const res = this.fetch16(), freq = this.fetch(), vol = this.fetch(), ch = this.fetch();
        this.sounds.push({ kind: "sfx", res, freq, vol, channel: ch, thread: this.thread, pc: pcAt });
        break;
      }
      case 0x19: {                                              // load / bankSwitch
        const id = this.fetch16();
        if (id > 0x100 && (id & 0xFFF0) === 0x3E80) {
          this.events.push({ kind: "bankSwitch", level: id & 0xF, by: this.thread });
          this.pendingPart = id & 0xF;      // the host applies it after the frame
          this.stop = true;
        } else {
          this.events.push({ kind: "load", id });
        }
        break;
      }
      case 0x1A: {                                              // song
        const res = this.fetch16(), delay = this.fetch16(), pos = this.fetch();
        this.sounds.push({ kind: "song", res, delay, pos, thread: this.thread, pc: pcAt });
        break;
      }
      case 0x1B: this.gameOver = true; this.stop = true; break;
      default:
        this.events.push({ kind: "illegal", opcode: op, pc: pcAt, thread: this.thread });
        this.pc[this.thread] = INACTIVE;
        this.stop = true;
        this.halted = true;
        break;
    }
  }

  // ---- video -----------------------------------------------------------
  // `anchor` is {x, y, zoom} with each field "var" | "imm", recovered from the
  // opcode bits by the caller. It changes nothing about the drawing; it is the
  // one fact about a draw that cannot be recovered from the record afterwards,
  // and notes/on-screen-priority/ ranks on it.
  video(kind, offset, x, y, zoom, pcAt, anchor) {
    const r = kind === "video2" ? this.vid2 : this.cine;
    if (!r) return;
    if (kind === "video2") r.setLevel(0);
    let polys = [];
    try {
      polys = r.draw(offset, this.palette, zoom, x, y);
    } catch (e) {
      this.events.push({ kind: "drawError", offset, message: String(e.message) });
    }
    if (kind === "video2") this.cine.setLevel(this.level);

    const page = this.pages[this.workPage];
    for (const p of polys) fillPolygonInto(page, p, undefined, this.pages[0]);

    this.draws.push({
      seq: this.seq++, kind, offset, x, y, zoom,
      palette: this.palette, thread: this.thread, pc: pcAt,
      page: this.workPage, polys,
      anchor: anchor || { x: "imm", y: "imm", zoom: "imm" },
    });
  }

  copyPage(src, dst, vscroll) {
    const s = this.pages[src], d = this.pages[dst];
    if (src === dst) return;
    if (!vscroll) { d.set(s); return; }
    const off = vscroll * W;
    for (let i = 0; i < W * H; i++) {
      const j = i + off;
      d[i] = (j >= 0 && j < W * H) ? s[j] : 0;
    }
  }
}

/**
 * Scanline fill of one polygon into a 320x200 index buffer.
 *
 * The GEOMETRY here is exact -- `tests/compare_render.mjs` checks every point
 * against `awvm-render-polygons`. The RASTERISATION is a standard even-odd
 * scanline fill rather than the reference VM's two-edge walk, so a shape's
 * outermost pixel can land one across from what the original hardware drew.
 * Nothing in `notes/` is measured off rasterised pixels -- extents and
 * `canonical_md5` both come from the polygon tree -- so this affects what the
 * screen looks like and nothing that is written down.
 */
/** Paint one polygon into a page, the way the game paints it.
 *
 * A line-for-line port of MAME's `another_world_vm_state::fillPolygon`
 * (felipesanches/mame, branch `anotherworld`,
 * `src/mame/video/anotherworld_vm.cpp`), which matches Fabien Sanglard's
 * interpreter and therefore the original.
 *
 * **This replaced an even-odd scanline fill that had never been checked
 * against anything.** `tests/compare_render.mjs` compares polygon GEOMETRY --
 * colour, point count, coordinates -- against the Rust tool's SVG output, and
 * an SVG is not rasterised, so nothing in this repository had ever tested the
 * step from polygons to pixels. The old README line calling the difference
 * "up to one pixel" was a guess, not a measurement.
 *
 * Three things the scanline fill got wrong and this does not:
 *
 *   1. **The walk.** The game walks two edges at once, from the ends of the
 *      point list inwards, in 16.16 fixed point, with `cpt1 |= 0x7FFF` and
 *      `cpt2 |= 0x8000` before each span so the two sides round outwards. An
 *      even-odd fill with rounded endpoints is a different shape, not a
 *      shifted one.
 *   2. **Colour 0x10 and above.** Below 0x10 is a solid colour. Exactly 0x10
 *      BLENDS -- each pixel becomes `(what is there & 7) | 8`, which is the
 *      game's transparency. Above 0x10 COPIES FROM PAGE 0, which is how the
 *      backdrop shows through a cut-out. The old fill wrote a solid index for
 *      all three, so every masked and blended polygon was painted opaque.
 *   3. **The degenerate point.** A four-point polygon with zero width and one
 *      row of height is one pixel, not a lozenge (see `polygons.js`).
 *
 * @param {Uint8Array} page   the page being drawn into
 * @param {object} poly       one entry from PolygonRenderer.draw()
 * @param {number} [colorOverride] force a solid index -- the blink overlay
 *   uses this, and it deliberately bypasses blend and page-0 copy so that
 *   highlighting an asset shows its full footprint.
 * @param {Uint8Array} [page0] page 0, needed for the copy mode. Without it a
 *   copy-mode polygon is skipped rather than painted wrong.
 */
export function fillPolygonInto(page, poly, colorOverride, page0) {
  const pts = poly.points;
  if (!pts || pts.length < 3) return;

  const solid = colorOverride !== undefined;
  const raw = poly.raw === undefined ? (poly.index || 0) : poly.raw;
  // 0 solid, 1 blend, 2 copy from page 0
  const mode = solid ? 0 : raw < 0x10 ? 0 : raw === 0x10 ? 1 : 2;
  if (mode === 2 && !page0) return;
  const ci = solid ? colorOverride : raw & 0x0F;

  const put = (y, x1, x2) => {
    const row = y * W;
    if (x1 > x2) { const t = x1; x1 = x2; x2 = t; }
    for (let x = x1; x <= x2; x++) {
      if (mode === 0) page[row + x] = ci;
      else if (mode === 1) page[row + x] = (page[row + x] & 7) | 8;
      else page[row + x] = page0[row + x];
    }
  };

  if (poly.degenerate) {
    const x = Math.round(poly.anchorX), y = Math.round(poly.anchorY);
    if (x >= 0 && x < W && y >= 0 && y < H) put(y, x, x);
    return;
  }

  let ymin = Infinity, ymax = -Infinity, xmin = Infinity, xmax = -Infinity;
  for (const [x, y] of pts) {
    if (y < ymin) ymin = y; if (y > ymax) ymax = y;
    if (x < xmin) xmin = x; if (x > xmax) xmax = x;
  }
  if (xmin >= W || xmax < 0 || ymin >= H || ymax < 0) return;

  // `calcStep`: 0x4000/dy as an integer, times dx, times 4. The integer
  // division is the whole character of the edge walk and must not become a
  // float divide.
  const calcStep = (p1, p2) => {
    const dy = Math.round(p2[1]) - Math.round(p1[1]);
    const v = dy > 0 ? Math.trunc(0x4000 / dy) : 0x4000;
    return [Math.trunc((Math.round(p2[0]) - Math.round(p1[0])) * v) * 4, dy];
  };

  let hliney = Math.round(ymin);
  let n = pts.length;
  let i = 0, j = n - 1;
  let cpt2 = Math.round(pts[i][0]) * 65536;
  let cpt1 = Math.round(pts[j][0]) * 65536;
  i++; j--;

  for (;;) {
    n -= 2;
    if (n === 0) return;
    const [step1, h1] = calcStep(pts[j + 1], pts[j]);
    const [step2] = calcStep(pts[i - 1], pts[i]);
    let h = h1;
    i++; j--;
    cpt1 = (cpt1 & ~0xFFFF) | 0x7FFF;
    cpt2 = (cpt2 & ~0xFFFF) | 0x8000;
    if (h === 0) {
      cpt1 += step1;
      cpt2 += step2;
    } else {
      for (; h !== 0; --h) {
        if (hliney >= 0) {
          let x1 = Math.floor(cpt1 / 65536), x2 = Math.floor(cpt2 / 65536);
          if (x1 <= W - 1 && x2 >= 0) {
            if (x1 < 0) x1 = 0;
            if (x2 > W - 1) x2 = W - 1;
            put(hliney, x1, x2);
          }
        }
        cpt1 += step1;
        cpt2 += step2;
        hliney++;
        if (hliney > H - 1) return;
      }
    }
  }
}
