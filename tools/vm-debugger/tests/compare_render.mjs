// Does the debugger's JS renderer draw exactly what the Rust one draws?
//
// Question answered
// -----------------
// Every measurement in `notes/` -- every extent, leaf count and `canonical_md5`
// a proposal table quotes -- comes from `awvm-render-polygons` or the polygon
// tree it parses. The debugger draws the same art with its own port in
// `static/polygons.js`. If the two ever disagreed, the debugger would be
// showing a picture the record does not describe, and nobody would notice.
//
// So: render a stage with the Rust tool, render the same entries with the JS
// port, and compare **every polygon of every entry** -- fill colour, point
// count, and each point to three decimals, which is the precision the SVG
// writer emits.
//
// Which entries
// -------------
// The Rust tool falls back to x=160, y=100, zoom=0x40 whenever an entry's
// operands are not numeric literals. So the comparison set is the draws whose
// x and y are BOTH variables and whose zoom is absent -- for those, and only
// those, the anchor the tool used is known exactly and can be reproduced here.
// Everything else would be comparing against a fallback whose inputs this test
// cannot see.
//
// Usage
// -----
//   awvm-render-polygons --port amiga --stage 3 --romset <dir> \
//       --bank cinematic --out /tmp/ref --palette 2
//   node tools/vm-debugger/tests/compare_render.mjs \
//       --ref /tmp/ref --stage PRISON --stage-id 3 --palette 2 \
//       --branch chahi_amiga_1991 --romset <dir>

import { readFileSync, readdirSync } from "node:fs";
import { join } from "node:path";
import { PolygonRenderer, hexOf } from "../static/polygons.js";

const argv = process.argv.slice(2);
const arg = (k, d) => {
  const i = argv.indexOf("--" + k);
  return i >= 0 ? argv[i + 1] : d;
};
const REF = arg("ref");
const STAGE = arg("stage", "PRISON");
const STAGE_ID = Number(arg("stage-id", "3"));
const PALETTE = Number(arg("palette", "2"));
const BRANCH = arg("branch", "chahi_amiga_1991");
const ROMSET = arg("romset");
const ROOT = new URL("../../..", import.meta.url).pathname;

if (!REF || !ROMSET) {
  console.error("need --ref <dir of rust SVGs> and --romset <dir>");
  process.exit(2);
}

// --- the draws whose anchor the Rust tool is known to have defaulted --------
const asm = readFileSync(join(ROOT, "src/levels", BRANCH, STAGE + ".asm"), "utf8");
const equ = new Map();
for (const line of asm.split("\n")) {
  const m = /^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$/.exec(line);
  if (m) equ.set(m[1], parseInt(m[2], 16));
}
const wanted = new Set();
for (const line of asm.split("\n")) {
  const m = /^\s*video offset=(CINEMATIC_\w+), x=\[[^\]]+\], y=\[[^\]]+\]\s*$/.exec(line);
  if (m && equ.has(m[1])) wanted.add(equ.get(m[1]));
}

// --- the Rust output --------------------------------------------------------
const refPolys = new Map();     // offset -> [{fill, pts:[[x,y]...]}, ...]
for (const f of readdirSync(REF)) {
  const m = /_0x([0-9A-F]{4})\.svg$/.exec(f);
  if (!m) continue;
  const off = parseInt(m[1], 16);
  if (!wanted.has(off)) continue;
  const txt = readFileSync(join(REF, f), "utf8");
  const polys = [];
  for (const pm of txt.matchAll(/<path fill="(#[0-9a-f]{6})" d="([^"]+)"/g)) {
    const pts = [...pm[2].matchAll(/(-?[\d.]+) (-?[\d.]+)/g)]
      .map((p) => [Number(p[1]), Number(p[2])]);
    polys.push({ fill: pm[1], pts });
  }
  refPolys.set(off, polys);
}

// --- the JS port ------------------------------------------------------------
const cine = new Uint8Array(readFileSync(join(ROMSET, "cinematic.rom")));
const pal = new Uint8Array(readFileSync(join(ROMSET, "palettes.rom")));
const r = new PolygonRenderer(cine, pal);
r.setLevel(STAGE_ID);

let checked = 0, polygons = 0, bad = 0;
const fmt = (v) => v.toFixed(3);
for (const [off, ref] of [...refPolys].sort((a, b) => a[0] - b[0])) {
  let mine;
  try {
    mine = r.draw(off, PALETTE, 0x40, 160, 100);
  } catch (e) {
    console.log(`  0x${off.toString(16).toUpperCase().padStart(4, "0")}  threw: ${e.message}`);
    bad++; continue;
  }
  checked++;
  const tag = `0x${off.toString(16).toUpperCase().padStart(4, "0")}`;
  if (mine.length !== ref.length) {
    console.log(`  ${tag}  ${mine.length} polygon(s) here, ${ref.length} there`);
    bad++; continue;
  }
  for (let i = 0; i < ref.length; i++) {
    polygons++;
    const a = mine[i], b = ref[i];
    if (hexOf(a.color) !== b.fill) {
      console.log(`  ${tag} #${i}  fill ${hexOf(a.color)} vs ${b.fill}`);
      bad++; break;
    }
    if (a.points.length !== b.pts.length) {
      console.log(`  ${tag} #${i}  ${a.points.length} points vs ${b.pts.length}`);
      bad++; break;
    }
    let slip = null;
    for (let k = 0; k < a.points.length; k++) {
      if (fmt(a.points[k][0]) !== fmt(b.pts[k][0]) ||
          fmt(a.points[k][1]) !== fmt(b.pts[k][1])) {
        slip = `point ${k}: (${fmt(a.points[k][0])}, ${fmt(a.points[k][1])}) vs ` +
               `(${fmt(b.pts[k][0])}, ${fmt(b.pts[k][1])})`;
        break;
      }
    }
    if (slip) { console.log(`  ${tag} #${i}  ${slip}`); bad++; break; }
  }
}

console.log(`\n${checked} entr(ies) compared, ${polygons} polygon(s), ${bad} mismatch(es)`);
console.log(bad === 0
  ? "the JS renderer draws what awvm-render-polygons draws."
  : "MISMATCH -- the debugger would show art the notes do not describe.");
process.exit(bad === 0 ? 0 : 1);
