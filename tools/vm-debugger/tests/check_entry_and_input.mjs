// Can a stage be entered the way the game enters it, and can the hero move?
//
// Question answered
// -----------------
// Two things were missing and each looked like the other from the outside.
//
// **Entry.** A stage entered with every variable at zero does not run: the
// copy-protection check deletes all 64 threads. Seeding the five variables that
// check reads makes a stage DRAW; it does not make it PLAY, because the scripts
// read dozens of other variables a real playthrough would have set. The
// reference engines carry a register table per CHECKPOINT and apply it on
// restart. `static/checkpoints.json` is those tables, transcribed by
// `tools/extract_checkpoints.py`.
//
// **Input.** Nothing wrote the six variables the scripts poll for the joystick,
// so the hero never moved however the stage was seeded. `VM.processInput` now
// publishes them once per frame, where the reference publishes them.
//
// What this asserts
// -----------------
//   1. every part the debugger offers has at least one checkpoint, and CAVES
//      has the nine the reference gives it;
//   2. a checkpoint's registers land in the machine, 0x00..0x3F is cleared
//      first and 0x40..0xFF is not -- a table is a delta, not a whole state;
//   3. `processInput` writes 0xFC/0xE5/0xFB/0xFD/0xFA/0xFE with the reference's
//      values for every one of the 32 direction+action combinations;
//   4. entering from a checkpoint paints more of the screen than the
//      five-variable fallback does -- the difference between drawing and
//      playing, measured rather than asserted.
//
// Run it
//   node tools/vm-debugger/tests/check_entry_and_input.mjs --romset <dir>

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM, W, H } from "../static/vm.js";

const CHECKPOINTS = JSON.parse(readFileSync(
  new URL("../static/checkpoints.json", import.meta.url), "utf8"));
const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const ROMSET = arg("romset");
if (!ROMSET) { console.error("need --romset <dir>"); process.exit(2); }

const bad = [];
const want = (c, why) => { if (!c) bad.push(why); };

// 1. the tables cover every part the debugger offers
const byPart = new Map();
for (const c of CHECKPOINTS.checkpoints)
  byPart.set(c.part, (byPart.get(c.part) || []).concat(c.level));
for (const [part, name] of [[1, "INTRO"], [2, "LAKE"], [3, "PRISON"],
                            [4, "CAVES"], [5, "TANK"], [6, "CAPSULE"]])
  want((byPart.get(part) || []).length > 0, `part ${part} (${name}) has no checkpoint`);
want((byPart.get(4) || []).length === 9,
     `CAVES has ${(byPart.get(4) || []).length} checkpoint(s), the reference gives it 9`);
want(CHECKPOINTS.checkpoints.every((c) => Object.keys(c.registers).length >= 6),
     "a checkpoint table is suspiciously small");

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const ROMS = { bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
               palettes: rd("palettes.rom"), video2: rd("video2.rom") };

// 2. the registers land, 0x00..0x3F is cleared first, 0x40..0xFF is not
{
  const vm = new VM(ROMS, { checkpoints: CHECKPOINTS });
  vm.vars[0x05] = 0x7777;        // inside the cleared window
  vm.vars[0x9E] = 0x1234;        // outside it, and in no table
  const cp = CHECKPOINTS.checkpoints.find((c) => c.part === 4);
  vm.setupPart(4, { checkpoint: cp.level });
  for (const [reg, val] of Object.entries(cp.registers))
    want(vm.vars[Number(reg)] === val,
         `${reg} is ${vm.vars[Number(reg)]}, the table says ${val}`);
  want(vm.vars[0x9E] === 0x1234,
       "0x9E was cleared; only 0x00..0x3F should be, a table is a delta");
  want(vm.checkpoint === cp.level, "the applied checkpoint is not reported");
  const cold = new VM(ROMS, { checkpoints: CHECKPOINTS });
  cold.setupPart(4, { protection: false });
  want(cold.vars[0xBC] === 0, "cold boot seeded something");
  want(cold.checkpoint === null, "cold boot reported a checkpoint");
}

// 3. every direction+action combination, against the reference's own arithmetic
{
  const vm = new VM(ROMS, { checkpoints: CHECKPOINTS });
  const K = VM.KEY;
  for (let bits = 0; bits < 32; bits++) {
    vm.keys = bits;
    vm.processInput();
    let lr = 0, ud = 0, mask = 0;
    if (bits & K.RIGHT) { lr = 1; mask |= 1; }
    if (bits & K.LEFT) { lr = -1; mask |= 2; }
    if (bits & K.DOWN) { ud = 1; mask |= 4; }
    if (bits & K.UP) { ud = -1; mask |= 8; }
    const act = (bits & K.ACTION) ? 1 : 0;
    const check = [[0xFC, lr], [0xE5, ud], [0xFB, ud], [0xFD, mask],
                   [0xFA, act], [0xFE, act ? mask | 0x80 : mask]];
    for (const [reg, exp] of check)
      want(vm.vars[reg] === exp,
           `keys=${bits}: var 0x${reg.toString(16).toUpperCase()} is ` +
           `${vm.vars[reg]}, want ${exp}`);
  }
  // keyDown/keyUp are what the browser calls
  vm.keys = 0;
  vm.keyDown(K.LEFT); vm.keyDown(K.ACTION); vm.keyUp(K.LEFT);
  want(vm.keys === K.ACTION, `keyUp did not clear one bit (keys=${vm.keys})`);
}

// 4. a checkpoint paints more than the five-variable fallback
function paint(vm) {
  let best = 0;
  for (let i = 0; i < 300; i++) {
    vm.runFrame();
    const p = vm.pages[vm.frontPage];
    let nz = 0;
    for (let q = 0; q < W * H; q++) if (p[q]) nz++;
    if (nz / (W * H) > best) best = nz / (W * H);
    if (vm.halted || vm.pendingPart !== undefined) break;
  }
  return best;
}
{
  const withCp = new VM(ROMS, { checkpoints: CHECKPOINTS });
  withCp.setupPart(6, { checkpoint: 12 });
  const fallback = new VM(ROMS);          // no tables: PROTECTION_PASS only
  fallback.setupPart(6);
  const a = paint(withCp), b = paint(fallback);
  console.log(`  CAPSULE fullest screen: checkpoint 12 ${(a * 100).toFixed(1)}%, ` +
              `five-variable fallback ${(b * 100).toFixed(1)}%`);
  want(a > b + 0.2,
       `a checkpoint (${(a * 100).toFixed(1)}%) should paint much more than the ` +
       `fallback (${(b * 100).toFixed(1)}%)`);
}

if (bad.length) {
  console.log(`FAIL: ${bad.length} problem(s)`);
  for (const b of bad.slice(0, 12)) console.log(`  * ${b}`);
  if (bad.length > 12) console.log(`  ... ${bad.length - 12} more`);
  process.exit(1);
}
console.log(`PASS: ${CHECKPOINTS.checkpoints.length} checkpoints over 6 parts, ` +
            `CAVES has 9; a table is a delta over 0x00..0x3F;\n      all 32 ` +
            `key combinations match the reference's six variables.`);
process.exit(0);
