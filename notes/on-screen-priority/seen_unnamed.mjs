// Of the constants still numbered, which ones does a player actually SEE?
//
// Question answered
// -----------------
// Every other probe in notes/ ranks unnamed art by structure: how it is drawn,
// what family it sits in, whether the other port holds the same tree. None of
// them can say whether a human ever looks at it. A constant drawn in one frame
// of one cutscene and a constant on screen for a quarter of the stage are worth
// very different amounts of naming effort, and until the VM existed there was
// no way to tell them apart.
//
// This runs the stage in the interpreter from tools/vm-debugger/ and counts, per
// still-numbered constant, how many frames it was drawn in, which routines drew
// it, and how its position was anchored. The ranking is SCREEN TIME.
//
// Signal read
// -----------
//   * a draw is one `video` op executed by the VM -- the same record the
//     debugger's polygon panel shows, from vm.runFrame().draws
//   * "unnamed" is the debugger's own test: CINEMATIC_<digits> or CV_<4 hex>
//     (tools/vm-debugger/static/app.js RE_NUMBERED), i.e. the placeholder names
//   * the routine is the nearest label at or before the drawing pc, from
//     server.py --dump's label table, which check_label_addresses.mjs verifies
//     lands on every `setup channel` target
//   * the anchor is how x and y reached the op: `var` (a variable, so something
//     else computes the position), `imm` (a literal in the bytecode) or a mix.
//     A var-anchored draw is a moving object; an imm-anchored one is furniture.
//
// Caveat, and it is the whole limitation: the VM enters the stage with no state
// carried from a real playthrough, so a scene gated on a variable a previous
// stage set will not run and its art will not appear here. Absence from this
// list is not evidence; presence is.
//
// The copy-protection variables ARE seeded by default (VM.PROTECTION_PASS in
// static/vm.js says which and why), because without them four of the eight
// stages delete all 64 threads on entry and draw nothing whatsoever. `--cold`
// turns that off and reproduces the blank.
//
// Run it
//   python3 tools/vm-debugger/server.py --dump dos_1992 PRISON > /tmp/n.json
//   node notes/on-screen-priority/seen_unnamed.mjs --names /tmp/n.json \
//       --romset <romset dir> --stage-id 3 --frames 400
//   ... --top 40        how many rows to print (default 25)
//   ... --named         rank the already-NAMED constants instead, as a control
//   ... --cold          enter the stage with NO copy-protection seeding, which
//                       is what a fresh boot does and what leaves LAKE, CAVES,
//                       ENDING and PASSCODE drawing nothing at all

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM } from "../../tools/vm-debugger/static/vm.js";

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const has = (k) => argv.includes("--" + k);
const NAMES = arg("names"), ROMSET = arg("romset");
const STAGE_ID = Number(arg("stage-id", "1"));
const FRAMES = Number(arg("frames", "400"));
const TOP = Number(arg("top", "25"));
const WANT_NAMED = has("named"), COLD = has("cold");
if (!NAMES || !ROMSET) { console.error("need --names and --romset"); process.exit(2); }

const meta = JSON.parse(readFileSync(NAMES, "utf8"));
const RE_NUMBERED = /^CINEMATIC_\d+$|^CV_[0-9A-F]{4}$/;
const hex4 = (v) => "0x" + v.toString(16).toUpperCase().padStart(4, "0");
const nameOf = (d) =>
  (d.kind === "video2" ? meta.video2 : meta.cinematic)[hex4(d.offset)] || null;
const isNamed = (n) => !!n && !RE_NUMBERED.test(n);

// nearest label at or before a pc -- the debugger's own routineAt()
const LABELS = Object.entries(meta.labels).map(([n, a]) => [a, n]).sort((p, q) => p[0] - q[0]);
function routineAt(pc) {
  let lo = 0, hi = LABELS.length - 1, best = null;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (LABELS[mid][0] <= pc) { best = LABELS[mid][1]; lo = mid + 1; } else hi = mid - 1;
  }
  return best || "?";
}

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const vm = new VM({
  bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
  palettes: rd("palettes.rom"), video2: rd("video2.rom"),
});
vm.setupPart(STAGE_ID, { protection: !COLD });

const seen = new Map();   // key -> {kind, offset, name, frames, first, last, routines, anchors}
let ran = 0;
for (let i = 0; i < FRAMES; i++) {
  const f = vm.runFrame();
  ran++;
  const thisFrame = new Set();
  for (const d of f.draws) {
    const name = nameOf(d);
    if (isNamed(name) !== WANT_NAMED) continue;
    const key = d.kind + hex4(d.offset);
    let e = seen.get(key);
    if (!e) {
      e = { kind: d.kind, offset: d.offset, name, frames: 0, first: i, last: i,
            routines: new Set(), anchors: new Set() };
      seen.set(key, e);
    }
    e.last = i;
    e.routines.add(routineAt(d.pc));
    e.anchors.add(`x:${d.anchor.x} y:${d.anchor.y} z:${d.anchor.zoom}`);
    if (!thisFrame.has(key)) { e.frames++; thisFrame.add(key); }
  }
  if (vm.halted || vm.pendingPart !== undefined) break;
}

const rows = [...seen.values()].sort((a, b) => b.frames - a.frames || a.offset - b.offset);
const total = rows.reduce((s, r) => s + r.frames, 0);
console.log(`${meta.branch}/${meta.stage}: ${ran} frames run, ` +
            `${rows.length} ${WANT_NAMED ? "named" : "still-numbered"} constant(s) drawn, ` +
            `${total} constant-frames of screen time`);
console.log("");
console.log("frames  %run  constant                 offset  first-last  anchor                routine(s)");
for (const r of rows.slice(0, TOP)) {
  const pct = ((r.frames / ran) * 100).toFixed(0).padStart(3);
  const rt = [...r.routines];
  console.log(
    `${String(r.frames).padStart(6)}  ${pct}%  ` +
    `${(r.name || "(no EQU)").padEnd(24)} ${hex4(r.offset)}  ` +
    `${String(r.first).padStart(4)}-${String(r.last).padEnd(4)}  ` +
    `${[...r.anchors].join(",").padEnd(21)} ${rt.slice(0, 2).join(" ")}` +
    (rt.length > 2 ? ` +${rt.length - 2}` : ""));
}
if (rows.length > TOP) console.log(`... ${rows.length - TOP} more (--top)`);
process.exit(0);
