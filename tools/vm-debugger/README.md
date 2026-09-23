# A web debugger for the Another World VM

## What it is for

The naming effort has always read pictures out of a renderer one at a time: pick
a constant, render it, crop it, decide. What it has never had is **the game
running**, with every polygon on screen labelled, a counter of how many of them
are still numbered, and a way to say "that one is the hero's gun arm" at the
moment you are looking at it.

That is what this is. It runs the VM in the browser against the same ROM slabs
every probe in `notes/` measures, and it puts the naming record beside the
picture.

    python3 tools/vm-debugger/server.py
    # then open http://127.0.0.1:8017

Stdlib Python only, no build step, no install.

## What it does not do

**It does not rename anything in the tree.** A rename typed here is appended to
`rename_log.jsonl` and nothing else. Applying a name is what
`apply_branch_scoped_names.py` is for, and behind it sit a family-gap rule, a
collision check, `undefined_symbols.py` and the byte gate -- none of which a web
form should be allowed to skip.

What the log carries is a **human saying what a picture is, with the frame they
said it on**. That is guidance for an agent to turn into a proposal table with
evidence, exactly like any other batch in `notes/render-and-name/`.

## Why there is a VM in here at all

`AnotherWorld_VMTools` has no interpreter. `awvm` unpacks, disassembles and
renders polygons; `exectrace` crawls code paths statically. Nothing in the
toolchain *runs* the bytecode, so the debugger has to.

## The renderer is checked against the Rust one, exactly

Every measurement in `notes/` -- every extent, leaf count and `canonical_md5` a
proposal quotes -- comes from `awvm-render-polygons` or the tree it parses. A
debugger that drew even slightly different shapes would quietly invalidate them,
and nobody would notice.

So `static/polygons.js` is a line-for-line port of `awvm/src/polygons.rs`, and
`tests/compare_render.mjs` diffs the two over a whole stage: fill colour, point
count, and every point to the three decimals the SVG writer emits.

    awvm-render-polygons --port amiga --stage 3 \
        --romset ../another-world-archaeology/tmp/output/amiga/romset \
        --bank cinematic --out /tmp/ref --palette 2
    node tools/vm-debugger/tests/compare_render.mjs --ref /tmp/ref \
        --stage PRISON --stage-id 3 --palette 2 --branch chahi_amiga_1991 \
        --romset ../another-world-archaeology/tmp/output/amiga/romset

It compares the draws whose x and y are **both variables and whose zoom is
absent**, because those are the ones the Rust tool is known to have anchored at
its 160, 100, 0x40 fallback; anything else would be checked against a default
whose inputs the test cannot see.

Run of 2026-09-23, amiga:

```
  INTRO      13 entries    64 polygons   0 mismatches
  PRISON    466 entries  3463 polygons   0 mismatches
  CAVES     543 entries  4250 polygons   0 mismatches
  CAPSULE   393 entries  3534 polygons   0 mismatches
```

## What the VM is checked against

`static/vm.js` decodes the two `video` encodings by hand, from the same bit
tests `awvm/src/disasm.rs` uses. A slip in any of them would not crash: it would
draw *something*, at a plausible-looking offset, and the debugger would label it
with whatever name happened to live there.

The disassembler already wrote every offset the stage draws -- the
`CINEMATIC_* EQU` and `CV_* EQU` lines of the `.asm`. So
`tests/check_draw_offsets.mjs` runs the VM and checks that **every offset it
draws is one of them**:

    node tools/vm-debugger/tests/check_draw_offsets.mjs --romset <dir> \
        --stage PRISON --stage-id 3 --frames 400

Run of 2026-09-23, amiga, 400 frames each:

```
  INTRO      749 draws   every offset recorded by the disassembler
  PRISON    4174 draws   every offset recorded
  TANK      4669 draws   every offset recorded
```

It is not a proof that the right constant was drawn at the right moment -- only
that every offset reached is one the static analysis found. That is the
strongest check available without a reference emulator to diff against, and it
catches an operand-order slip, which is the failure that would otherwise be
invisible.

## Stages that draw nothing when started cold

LAKE, CAVES, CAPSULE and ENDING run their entry point and then stop with no live
threads. That is the game, not the VM: `ENTRY_POINT_OF_CAVES` ends in
`call CAVES_SCREEN_ENTRY_DISPATCH`, which switches on `SCREEN_NUM` (`0x67`), and
a stage entered cold has every variable at zero, so the dispatch falls through.
INTRO, PRISON and TANK open on a cutscene and need nothing.

Two ways round it, both in the UI: let INTRO run and follow the `bankSwitch`
into the next stage, which carries the state the scripts expect; or set the
variables by hand in the state panel -- `SCREEN_NUM` first. The variable names
come from `src/levels/_common_vars.inc` and the stage's own file, so the panel
shows `SCREEN_NUM` and `HERO_X`, not `[0x67]` and `[0x01]`.

## What the backend serves

| route | what |
| --- | --- |
| `/api/config` | which branches have a romset on disk, and the stage ids |
| `/api/rom/<port>/<file>` | a ROM slab file, straight from the archaeology repo |
| `/api/names/<branch>/<stage>` | offset -> semantic name, from `src/levels/<branch>/<STAGE>.asm` |
| `/api/renames` | the log so far |
| `POST /api/rename` | append one entry to the log |

Names come from the **canonical** tree, which is what
`notes/shared-bank-naming/asset_naming_share.py` counts. The unified tree lags
it by 452 missing and 544 moved names (`notes/tree-name-drift/`), so reading the
canonical files is the only way the debugger's labels match the record.
