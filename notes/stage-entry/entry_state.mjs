// Why does this stage draw nothing, and what unlocks it?
//
// Question answered
// -----------------
// Four of the eight stages -- LAKE, CAVES, CAPSULE, ENDING -- ran their entry
// point in `tools/vm-debugger/` and then drew nothing whatsoever, for thousands
// of frames, in both priority ports. That put half the game out of reach of the
// only tool that can show a polygon in context.
//
// The reason on record was wrong, and this probe is what replaced it. It
// reports three things per stage:
//
//   * painted frames, with the copy-protection variables seeded and without
//   * the LIVE THREAD census at the end of the run, with each thread's pc
//     resolved to the nearest label
//   * optionally, a sweep of SCREEN_NUM, to test the explanation that was
//     on record before this
//
// What it established
// -------------------
// The old explanation was that `CAVES_SCREEN_ENTRY_DISPATCH` switches on
// `SCREEN_NUM` (0x67) and a cold entry leaves every variable zero, so the
// dispatch falls through. Two measurements kill it, and `--screens` plus the
// thread census are exactly those two:
//
//   * seeding SCREEN_NUM with each of 28 values, 0x00 through 0xC0, leaves
//     CAVES drawing exactly nothing;
//   * CAVES ends a 400-frame run with ZERO live threads, which no dispatch
//     fall-through can cause -- a fall-through leaves the thread running.
//
// The cause is `LIKELY_A_COPY_PROTECTION_MECHANISM`, whose failure path is
// `deleteChannels first=0x00, last=0x3F`: it deletes all 64 threads. It reads
// five variables, all zero on a cold entry, so it always fails, and it latches
// (the failure path writes 0xF2 = 0x1770, not the 0x0FA0 it wants). The five
// conditions and the passing values are `VM.PROTECTION_PASS` in
// `tools/vm-debugger/static/vm.js`, quoted from `dos_1992/CAVES.asm`.
//
// Signal read
// -----------
//   * "painted" is a frame whose front page is more than 2% non-background,
//     the same test tools/vm-debugger/tests/smoke_frames.mjs uses
//   * a thread is live when its pc is not INACTIVE (0xFFFF)
//   * the routine is the nearest label at or before the pc, from
//     `server.py --dump`'s label table
//
// Run it
//   for S in INTRO:1 LAKE:2 PRISON:3 CAVES:4 TANK:5 CAPSULE:6 ENDING:7; do
//     python3 tools/vm-debugger/server.py --dump dos_1992 ${S%:*} > /tmp/n.json
//     node notes/stage-entry/entry_state.mjs --names /tmp/n.json \
//         --romset <romset dir> --stage-id ${S#*:}
//   done
//   ... --frames N     how long to run (default 600)
//   ... --screens      also sweep SCREEN_NUM 0x00..0xC0 with no seeding, and
//                      report whether ANY value makes the stage draw
//   ... --checkpoints  report every checkpoint this stage has, separately.
//                      CAVES has nine and they are nine different rooms, so
//                      "the stage runs" is not one number

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM, W, H } from "../../tools/vm-debugger/static/vm.js";

const CHECKPOINTS = JSON.parse(readFileSync(
  new URL("../../tools/vm-debugger/static/checkpoints.json", import.meta.url), "utf8"));

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const has = (k) => argv.includes("--" + k);
const NAMES = arg("names"), ROMSET = arg("romset");
const STAGE_ID = Number(arg("stage-id", "1"));
const FRAMES = Number(arg("frames", "600"));
if (!NAMES || !ROMSET) { console.error("need --names and --romset"); process.exit(2); }

const meta = JSON.parse(readFileSync(NAMES, "utf8"));
const LABELS = Object.entries(meta.labels).map(([n, a]) => [a, n]).sort((p, q) => p[0] - q[0]);
function routineAt(pc) {
  let lo = 0, hi = LABELS.length - 1, best = null;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (LABELS[mid][0] <= pc) { best = LABELS[mid]; lo = mid + 1; } else hi = mid - 1;
  }
  return best ? `${best[1]}+${pc - best[0]}` : "?";
}

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const ROMS = { bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
               palettes: rd("palettes.rom"), video2: rd("video2.rom") };

function run({ protection, screen, checkpoint }) {
  const vm = new VM(ROMS, { checkpoints: CHECKPOINTS });
  vm.setupPart(STAGE_ID, { protection, checkpoint });
  if (screen !== undefined) vm.vars[0x67] = screen;   // SCREEN_NUM
  let painted = 0, draws = 0, best = 0;
  for (let i = 0; i < FRAMES; i++) {
    const f = vm.runFrame();
    draws += f.draws.length;
    const page = vm.pages[vm.frontPage];
    let nz = 0;
    for (let p = 0; p < W * H; p++) if (page[p]) nz++;
    const fill = nz / (W * H);
    if (fill > best) best = fill;
    if (fill > 0.02) painted++;
    if (vm.halted || vm.pendingPart !== undefined) break;
  }
  const live = [];
  for (let t = 0; t < 64; t++)
    if (vm.pc[t] !== 0xFFFF) live.push([t, vm.pc[t], vm.frozen[t]]);
  return { painted, draws, live, best };
}

const cold = run({ protection: false });
const seeded = run({ protection: true });
console.log(`${meta.branch}/${meta.stage}, ${FRAMES} frames`);
console.log(`  cold   : ${String(cold.painted).padStart(4)} painted, ` +
            `${String(cold.draws).padStart(5)} draw(s), ${cold.live.length} live thread(s)`);
console.log(`  seeded : ${String(seeded.painted).padStart(4)} painted, ` +
            `${String(seeded.draws).padStart(5)} draw(s), ${seeded.live.length} live thread(s)`);

if (cold.live.length === 0 && cold.painted === 0) {
  console.log("  ** entered cold, the stage ends with NO live thread at all. " +
              "That is not a\n     dispatch falling through -- a fall-through " +
              "leaves the thread running. It is\n     `deleteChannels " +
              "first=0x00, last=0x3F`, the copy-protection failure path.");
}
for (const [t, pc, fr] of cold.live.slice(0, 8))
  console.log(`      cold   thread ${t.toString(16).padStart(2, "0")} pc=${pc}` +
              `${fr ? " frozen" : ""}  ${routineAt(pc)}`);
for (const [t, pc, fr] of seeded.live.slice(0, 8))
  console.log(`      seeded thread ${t.toString(16).padStart(2, "0")} pc=${pc}` +
              `${fr ? " frozen" : ""}  ${routineAt(pc)}`);

if (has("checkpoints")) {
  // "Does the stage run?" is not one number when the stage has nine entries.
  // The fullest screen each one reaches is the cheapest thing that separates a
  // room worth opening from a hang loop.
  const probe = new VM(ROMS, { checkpoints: CHECKPOINTS });
  const avail = probe.checkpointsFor(STAGE_ID);
  if (!avail.length) console.log("  no checkpoint table for this part");
  for (const c of avail) {
    const r = run({ protection: true, checkpoint: c.level });
    console.log(`  checkpoint ${String(c.level).padStart(2)}: ` +
                `${String(r.painted).padStart(4)} painted, fullest ` +
                `${(r.best * 100).toFixed(1).padStart(5)}%, ` +
                `${String(r.draws).padStart(5)} draw(s), ` +
                `${r.live.length} live thread(s)`);
  }
  if (avail.length > 1)
    console.log("  The first listed is the default and is faithful to the " +
                "reference's ordering;\n  it is not the one that shows the " +
                "most. ../on-screen-priority/ --sweep asks\n  all of them " +
                "about unnamed art at once.");
}

if (has("screens")) {
  // The explanation that was on record until 2026-09-23. Kept as a mode rather
  // than deleted: a refuted hypothesis with the command that refuted it beside
  // it is worth more than a corrected sentence on its own.
  const tried = [];
  let any = 0;
  for (let s = 0; s <= 0xC0; s += (s < 0x10 ? 1 : 0x10)) {
    const r = run({ protection: false, screen: s });
    tried.push(s);
    if (r.draws) { any++; console.log(`  SCREEN_NUM 0x${s.toString(16)}: ${r.draws} draw(s)`); }
  }
  console.log(`  SCREEN_NUM swept over ${tried.length} value(s), 0x00..0xC0: ` +
              `${any} made the stage draw.`);
  if (!any)
    console.log("     So the dispatch-falls-through explanation is refuted: " +
                "no value of\n     SCREEN_NUM unlocks this stage, and the " +
                "protection seed does.");
}
process.exit(0);
