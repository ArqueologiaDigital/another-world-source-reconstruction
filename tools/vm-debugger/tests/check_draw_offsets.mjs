// Does the VM decode `video` operands the way the disassembler does?
//
// Question answered
// -----------------
// `static/vm.js` decodes the two `video` encodings by hand, from the same bit
// tests `awvm/src/disasm.rs` uses. A slip in any of them -- an operand read in
// the wrong order, a variable fetched where a literal was meant -- would not
// crash. It would draw *something*, at a plausible-looking offset, and the
// debugger would label it with whatever name happened to live there.
//
// The disassembler already wrote down every offset the stage draws: they are
// the `CINEMATIC_* EQU` and `VIDEO2_* EQU` lines of
// `src/levels/<branch>/<STAGE>.asm`. So run the VM and check that **every
// offset it draws is one of them**. A decoding bug puts the offset somewhere
// the disassembler never recorded, and this says so.
//
// It is not a proof that the right constant was drawn at the right moment --
// only that every offset reached is an offset the static analysis found. That
// is the strongest check available without a reference emulator to diff
// against, and it is enough to catch an operand order slip.
//
// Usage
//   node tools/vm-debugger/tests/check_draw_offsets.mjs \
//       --romset <dir> --branch chahi_amiga_1991 --stage INTRO --stage-id 1 \
//       --frames 600

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM } from "../static/vm.js";

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const ROMSET = arg("romset");
const BRANCH = arg("branch", "chahi_amiga_1991");
const STAGE = arg("stage", "INTRO");
const STAGE_ID = Number(arg("stage-id", "1"));
const FRAMES = Number(arg("frames", "600"));
const ROOT = new URL("../../..", import.meta.url).pathname;
if (!ROMSET) { console.error("need --romset <dir>"); process.exit(2); }

const asm = readFileSync(join(ROOT, "src/levels", BRANCH, STAGE + ".asm"), "utf8");
const known = { cinematic: new Set(), video2: new Set() };
for (const line of asm.split("\n")) {
  const m = /^(CINEMATIC_\w+|CV_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$/.exec(line);
  if (!m) continue;
  // `CV_*` is the shared bank -- the disassembly spells those draws
  // `video type=0, offset=CV_...`, and an unnamed key is `CV_<hex offset>`.
  (m[1].startsWith("CV_") ? known.video2 : known.cinematic).add(parseInt(m[2], 16));
}

const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const vm = new VM({
  bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
  palettes: rd("palettes.rom"), video2: rd("video2.rom"),
});
vm.setupPart(STAGE_ID);

let frames = 0, draws = 0, stranger = 0, halted = null;
const unknown = new Map();
for (let i = 0; i < FRAMES; i++) {
  const f = vm.runFrame();
  frames++;
  for (const d of f.draws) {
    draws++;
    if (!known[d.kind].has(d.offset)) {
      stranger++;
      const k = `${d.kind} 0x${d.offset.toString(16).toUpperCase().padStart(4, "0")}`;
      unknown.set(k, (unknown.get(k) || 0) + 1);
    }
  }
  if (vm.halted) { halted = f.events.filter((e) => e.kind === "illegal"); break; }
  if (vm.pendingPart !== undefined) { vm.setupPart(vm.pendingPart); delete vm.pendingPart; }
}

console.log(`${BRANCH}/${STAGE}: ${frames} frame(s), ${draws} draw(s)`);
console.log(`  ${known.cinematic.size} cinematic and ${known.video2.size} video2 ` +
            `offsets in the .asm`);
if (halted) console.log(`  HALTED on an illegal opcode: ${JSON.stringify(halted)}`);
if (stranger) {
  console.log(`  ** ${stranger} draw(s) at ${unknown.size} offset(s) the ` +
              `disassembler never recorded:`);
  for (const [k, n] of [...unknown].sort((a, b) => b[1] - a[1]).slice(0, 12)) {
    console.log(`      ${k}  x${n}`);
  }
} else {
  console.log("  every offset drawn is one the disassembler recorded.");
}
process.exit(stranger || halted ? 1 : 0);
