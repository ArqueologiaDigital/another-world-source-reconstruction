// What colour is a constant drawn in?
//
// Question answered
// -----------------
// Every other measurement in this repository describes a polygon tree's SHAPE:
// extent, leaf count, `canonical_md5`. None of them reports the colour, and
// there are families where the shape is identical across members and the colour
// is the only thing that differs. This directory's held item is exactly that
// case: the beam ladder's two longest rungs each carry two pairs, the pairs are
// the same single 126x1 and 62x1 line, and what separates them is one palette
// index.
//
// Signal read
// -----------
// `PolygonRenderer.draw()` from `tools/vm-debugger/static/polygons.js`, a
// line-for-line port of `awvm/src/polygons.rs` and the one this repository
// diffs against the Rust reference with zero mismatches
// (`tools/vm-debugger/tests/compare_render.mjs`). Per polygon it returns
// `index`, the palette slot the tree asked for, before any palette is applied.
// The INDEX is the stable fact and is what to quote; the rgb depends on which
// palette is in force at that moment, which
// `notes/render-and-name/palette_in_force.py` answers separately.
//
// A hierarchy node can override its children's colour or let them inherit it --
// the child descriptor's 0x8000 bit -- so two trees over the same child data
// can differ in nothing but this.
//
// What it established here
// ------------------------
// msdos, all three stages carrying the kit: the NAMED beam-span members are
// colour index 15 and the alternate set is colour index 13, without exception.
//
//     PRISON  SHOT_BEAM_SPAN_RIGHT_5/LEFT_5     15    CINEMATIC_518/519   13
//     CAVES   LASER_BOLT_SPAN_RIGHT_5/LEFT_5    15    CINEMATIC_859/860   13
//     CAPSULE SHOT_BEAM_SPAN_RIGHT_5/LEFT_5     15    CINEMATIC_673/674   13
//
// It also catches a name in the wrong place cheaply: a member of a one-polygon
// family that renders as four polygons at four indices is not in that family.
// `CINEMATIC_TELEPORT_UP_BEAM_LEFT` is 4 polygons at 7, 4, 15, 6 -- which is how
// the unified tree's drift was spotted printing it into a rung slot the
// canonical tree still calls CINEMATIC_858.
//
// Run it
//   node notes/beam-span-ladder/colour_of.mjs --romset <dir> --level 6 \
//       --branch dos_1992 --stage CAPSULE \
//       CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_5 CINEMATIC_673
//   ... --palette N     which palette to resolve rgb through (default 0)
//   ... --offset 0x3EB4 name an offset directly instead of an EQU name
//
// `--level` is the stage's slab index, the same number `server.py --dump` calls
// stage_id: CODE_WHEEL 0, INTRO 1, LAKE 2, PRISON 3, CAVES 4, TANK 5,
// CAPSULE 6, ENDING 7, PASSCODE 8.

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { PolygonRenderer } from "../../tools/vm-debugger/static/polygons.js";

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const ROMSET = arg("romset"), BRANCH = arg("branch"), STAGE = arg("stage");
const LEVEL = Number(arg("level", "0")), PALETTE = Number(arg("palette", "0"));
const ROOT = new URL("../..", import.meta.url).pathname;
const names = argv.filter((a, i) => !a.startsWith("--") &&
                          !(i > 0 && argv[i - 1].startsWith("--")));
if (!ROMSET || !names.length) {
  console.error("need --romset <dir> and one or more constant names " +
                "(or --offset 0xNNNN)");
  process.exit(2);
}

let equ = new Map();
if (BRANCH && STAGE) {
  const asm = readFileSync(join(ROOT, "src/levels", BRANCH, STAGE + ".asm"), "utf8");
  for (const m of asm.matchAll(/^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$/gm))
    equ.set(m[1], parseInt(m[2], 16));
}

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const r = new PolygonRenderer(rd("cinematic.rom"), rd("palettes.rom"));
r.setLevel(LEVEL);

for (const name of names) {
  const off = /^0x/i.test(name) ? parseInt(name, 16) : equ.get(name);
  if (off === undefined) { console.log(`${name.padEnd(46)} no EQU in ${BRANCH}/${STAGE}`); continue; }
  let polys;
  try { polys = r.draw(off, PALETTE, 0x40, 160, 100); }
  catch (e) { console.log(`${name.padEnd(46)} unreadable: ${e.message}`); continue; }
  const idx = polys.map((p) => p.index);
  console.log(`${name.padEnd(46)} 0x${off.toString(16).toUpperCase().padStart(4, "0")}  ` +
              `${String(polys.length).padStart(2)} poly  colour index ${idx.join(",")}`);
}
process.exit(0);
