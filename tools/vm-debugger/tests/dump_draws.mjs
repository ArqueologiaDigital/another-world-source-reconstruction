// Did a change to the VM alter any draw?
//
// Question answered
// -----------------
// The other three checks here answer "is the VM right?". This one answers a
// narrower question that comes up every time `static/vm.js` is touched for a
// reason unrelated to drawing: **did anything move?** It prints one line per
// draw -- frame, kind, offset, x, y, zoom, pc, polygon count -- so two
// revisions of the VM can be diffed against each other directly.
//
// Signal read: `vm.runFrame().draws`, the same records the debugger's polygon
// panel shows. Polygon *count* rather than geometry, because geometry is
// compare_render.mjs's job and this is meant to be cheap enough to run on every
// edit.
//
// Run it
//   git show HEAD:tools/vm-debugger/static/vm.js > /tmp/old_vm.js
//   cp tools/vm-debugger/static/polygons.js /tmp/          # vm.js imports it
//   node tools/vm-debugger/tests/dump_draws.mjs /tmp/old_vm.js <romset> 3 > /tmp/before
//   node tools/vm-debugger/tests/dump_draws.mjs \
//       $PWD/tools/vm-debugger/static/vm.js <romset> 3 > /tmp/after
//   diff /tmp/before /tmp/after        # must be empty for a behaviour-preserving change
//
// Arguments are positional: <abs path to vm.js> <romset dir> <stage id>.
// The path must be absolute -- it is passed to a dynamic import().
import { readFileSync } from "node:fs";
import { join } from "node:path";

const CHECKPOINTS = JSON.parse(readFileSync(
  new URL("../static/checkpoints.json", import.meta.url), "utf8"));
const VMMOD = process.argv[2], ROMSET = process.argv[3], SID = Number(process.argv[4]);
const { VM } = await import(VMMOD);
const rd = (n) => new Uint8Array(readFileSync(join(ROMSET, n)));
const vm = new VM({ bytecode: rd("bytecode.rom"), cinematic: rd("cinematic.rom"),
                    palettes: rd("palettes.rom"), video2: rd("video2.rom") }, { checkpoints: CHECKPOINTS });
vm.setupPart(SID);
for (let i = 0; i < 400; i++) {
  const f = vm.runFrame();
  for (const d of f.draws)
    console.log(`${i} ${d.kind} ${d.offset} ${d.x} ${d.y} ${d.zoom} ${d.pc} ${d.polys.length}`);
  if (vm.halted || vm.pendingPart !== undefined) break;
}
