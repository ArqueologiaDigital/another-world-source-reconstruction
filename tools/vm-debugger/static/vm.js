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
   */
  constructor(roms) {
    this.roms = roms;
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

    // per-frame, cleared by runFrame
    this.draws = [];
    this.sounds = [];
    this.texts = [];
    this.events = [];
    this.seq = 0;
  }

  // ---- setup ---------------------------------------------------------
  /** Start a stage: the reference's setupPart -- everything off, thread 0 at 0. */
  setupPart(level) {
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
    for (const p of this.pages) p.fill(0);
    this.workPage = 2; this.frontPage = 2; this.backPage = 1;
    this.events.push({ kind: "setupPart", level: this.level });
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
    for (const p of polys) fillPolygonInto(page, p);

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
export function fillPolygonInto(page, poly, colorOverride) {
  const pts = poly.points;
  if (pts.length < 3) return;
  let ymin = Infinity, ymax = -Infinity;
  for (const [, y] of pts) { if (y < ymin) ymin = y; if (y > ymax) ymax = y; }
  const y0 = Math.max(0, Math.ceil(ymin)), y1 = Math.min(H - 1, Math.floor(ymax));
  const ci = colorOverride !== undefined ? colorOverride : poly.index;
  const idx = ci === undefined ? 0 : ci;
  for (let y = y0; y <= y1; y++) {
    const xs = [];
    for (let i = 0, j = pts.length - 1; i < pts.length; j = i++) {
      const [xi, yi] = pts[i], [xj, yj] = pts[j];
      if ((yi > y) !== (yj > y)) xs.push(xi + (y - yi) / (yj - yi) * (xj - xi));
    }
    xs.sort((a, b) => a - b);
    for (let k = 0; k + 1 < xs.length; k += 2) {
      const a = Math.max(0, Math.round(xs[k])), b = Math.min(W - 1, Math.round(xs[k + 1]));
      for (let x = a; x <= b; x++) page[y * W + x] = idx;
    }
  }
}
