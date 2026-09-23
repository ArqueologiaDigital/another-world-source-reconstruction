// Does the whole pipeline produce a picture and a counter?
//
// The browser is where this normally runs, so the parts that only exist there
// -- canvas, panels, clicks -- are not covered by any test. What *is* coverable
// is everything underneath: VM to page buffer to palette to pixels, and the
// unnamed-asset count the header badge shows.
//
// So: run a stage, and report per frame how much of the screen is non-background
// and how many distinct constants were drawn with no semantic name. A pipeline
// that silently drew nothing would show up here as a screen that never fills.
//
// Usage
//   python3 tools/vm-debugger/server.py --dump chahi_amiga_1991 INTRO > /tmp/n.json
//   node tools/vm-debugger/tests/smoke_frames.mjs --names /tmp/n.json \
//       --romset <dir> --stage-id 1 --frames 400

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM, W, H } from "../static/vm.js";

const CHECKPOINTS = JSON.parse(readFileSync(
  new URL("../static/checkpoints.json", import.meta.url), "utf8"));

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const NAMES = arg("names"), ROMSET = arg("romset");
const STAGE_ID = Number(arg("stage-id", "1"));
const FRAMES = Number(arg("frames", "400"));
if (!NAMES || !ROMSET) { console.error("need --names and --romset"); process.exit(2); }

const meta = JSON.parse(readFileSync(NAMES, "utf8"));
const RE_NUMBERED = /^CINEMATIC_\d+$|^CV_[0-9A-F]{4}$/;
const hex4 = (v) => "0x" + v.toString(16).toUpperCase().padStart(4, "0");
const nameOf = (d) =>
  (d.kind === "video2" ? meta.video2 : meta.cinematic)[hex4(d.offset)] || null;
const isNamed = (n) => !!n && !RE_NUMBERED.test(n);

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const vm = new VM({
  bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
  palettes: rd("palettes.rom"), video2: rd("video2.rom"),
}, { checkpoints: CHECKPOINTS });
vm.setupPart(STAGE_ID);

let painted = 0, bestFill = 0, unnamedFrames = 0;
const unnamedSeen = new Set(), namedSeen = new Set();
for (let i = 0; i < FRAMES; i++) {
  const f = vm.runFrame();
  const page = vm.pages[vm.frontPage];
  let nonZero = 0;
  for (let p = 0; p < W * H; p++) if (page[p]) nonZero++;
  const fill = nonZero / (W * H);
  if (fill > bestFill) bestFill = fill;
  if (fill > 0.02) painted++;

  const distinct = new Map();
  for (const d of f.draws) distinct.set(d.kind + d.offset, d);
  let un = 0;
  for (const d of distinct.values()) {
    const n = nameOf(d);
    if (isNamed(n)) namedSeen.add(n);
    else { un++; unnamedSeen.add(`${d.kind} ${hex4(d.offset)}`); }
  }
  if (un) unnamedFrames++;
  if (vm.halted || vm.pendingPart !== undefined) break;
}

console.log(`${meta.branch}/${meta.stage}: ${painted} frame(s) with a painted screen, ` +
            `fullest ${(bestFill * 100).toFixed(1)}%`);
console.log(`  ${namedSeen.size} named and ${unnamedSeen.size} unnamed constant(s) seen; ` +
            `${unnamedFrames} frame(s) would trip "pause on unnamed"`);
if (painted === 0) {
  console.log("  ** nothing was ever painted -- the pipeline is broken, or the " +
              "stage needs state (see the README on cold entry)");
}
process.exit(0);
