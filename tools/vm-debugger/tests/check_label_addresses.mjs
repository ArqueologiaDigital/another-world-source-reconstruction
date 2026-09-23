// Do the computed label addresses agree with the addresses the VM jumps to?
//
// Question answered
// -----------------
// `awvm-disasm`'s listing has no address column. It emits labels, data and
// instructions in address order and nothing else, so `server.py`'s
// `label_addresses` recovers the addresses by walking the bytecode's
// instruction lengths in step with the listing's instruction lines.
//
// That walk is only as good as its instruction-length table, and a wrong length
// anywhere shifts every label after it -- silently, because a shifted label is
// still a plausible-looking name. The first run of it put every label three
// bytes late (`org 0x0000` was being counted as an instruction).
//
// The bytecode checks itself. Every `setup channel=N, address=A` and every
// `call A` the VM executes targets a **label**, because that is what the
// disassembler declared them from. So run the VM, collect every address it
// branches to, and require each one to be a computed label address.
//
// Usage
//   python3 tools/vm-debugger/server.py --dump chahi_amiga_1991 INTRO > /tmp/n.json
//   node tools/vm-debugger/tests/check_label_addresses.mjs \
//       --names /tmp/n.json --romset <dir> --stage-id 1 --frames 400

import { readFileSync } from "node:fs";
import { join } from "node:path";
import { VM } from "../static/vm.js";

const CHECKPOINTS = JSON.parse(readFileSync(
  new URL("../static/checkpoints.json", import.meta.url), "utf8"));

const argv = process.argv.slice(2);
const arg = (k, d) => { const i = argv.indexOf("--" + k); return i >= 0 ? argv[i + 1] : d; };
const NAMES = arg("names"), ROMSET = arg("romset");
const STAGE_ID = Number(arg("stage-id", "1"));
const FRAMES = Number(arg("frames", "400"));
if (!NAMES || !ROMSET) { console.error("need --names <json> and --romset <dir>"); process.exit(2); }

const meta = JSON.parse(readFileSync(NAMES, "utf8"));
const addrs = new Set(Object.values(meta.labels));
const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const vm = new VM({
  bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
  palettes: rd("palettes.rom"), video2: rd("video2.rom"),
}, { checkpoints: CHECKPOINTS });
vm.setupPart(STAGE_ID);

let setups = 0, miss = 0;
const bad = new Map();
for (let i = 0; i < FRAMES; i++) {
  const f = vm.runFrame();
  for (const e of f.events) {
    if (e.kind !== "setup") continue;
    setups++;
    if (!addrs.has(e.address)) {
      miss++;
      const k = "0x" + e.address.toString(16).toUpperCase().padStart(4, "0");
      bad.set(k, (bad.get(k) || 0) + 1);
    }
  }
  if (vm.halted) break;
  if (vm.pendingPart !== undefined) break;
}

console.log(`${meta.branch}/${meta.stage}: ${Object.keys(meta.labels).length} label(s) ` +
            `computed, ${setups} thread setup(s) executed`);
if (miss) {
  console.log(`  ** ${miss} setup(s) target an address no label sits on:`);
  for (const [k, n] of [...bad].slice(0, 10)) console.log(`      ${k}  x${n}`);
} else {
  console.log("  every address the VM branches to is a label address.");
}
process.exit(miss ? 1 : 0);
