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

## The workflow: describe, don't name

The thing to type here is **not a name**. It is a sentence:

> this is Buddy stuck in a tunnel while crawling. He is clearly struggling to
> move further down because there is a ring in the way, and he is moving the
> ring with his hands as if trying to get rid of the obstruction

Click the asset in **on screen**, watch its area blink so you are sure you have
the right one, and describe what is happening. That is worth more than a name
typed into a box, for two reasons.

**One description names a whole family.** The log entry records the routine that
issued the draw, and "all the frames of that sequence" is exactly "the other
draws in that routine" -- the same grouping
`notes/render-and-name/frame_runs.py` works from, and it is stored in the entry
as `routine_draws`. An agent reads the sentence, finds the run, and names every
frame of it with the evidence a proposal table needs. A rename box cannot do
that.

**Concatenated, the annotations are a description of the game.**

    curl http://127.0.0.1:8017/api/guidance
    python3 tools/vm-debugger/server.py --export

Every probe in `notes/` reasons from geometry, control flow or bank layout. Not
one of them has ever been able to say what a scene is *about*. A person who has
played the game can, and this is the only channel through which that reaches the
naming effort. Read end to end, the log is the game's semantics in the words of
someone who watched it happen.

## What it does not do

**It does not rename anything in the tree.** Renaming is here -- one asset, or
all names matching a pattern, with a preview -- and both are appended to
`rename_log.jsonl` and nothing else. Applying a name is what
`apply_branch_scoped_names.py` is for, and behind it sit a family-gap rule, a
collision check, `undefined_symbols.py` and the byte gate; none of which a web
form should be allowed to skip.

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
| `POST /api/rename` | append one entry to the log: `annotate`, `rename` or `bulk_rename` |
| `/api/guidance` | the annotations concatenated into one readable document |

Names come from the **canonical** tree, which is what
`notes/shared-bank-naming/asset_naming_share.py` counts. The unified tree lags
it by 452 missing and 544 moved names (`notes/tree-name-drift/`), so reading the
canonical files is the only way the debugger's labels match the record.


## The panels

| panel | what it shows |
| --- | --- |
| **on screen** | every distinct constant this frame drew: its name in green, or its number in red when it still has none, with the offset, the bank (`CV` for the shared one), the thread and how many times it was drawn |
| **threads** | every live channel, its pc, and the routine that pc sits in; frozen ones dimmed |
| **state** | the VM variables the disassembly has names for, editable -- poke `SCREEN_NUM` to reach a stage's scenes |
| **events** | what the frame did besides draw: thread setups, freezes, page blits, bank switches, and any illegal opcode |

The counter in the header is the number of distinct constants on the current
frame with no semantic name, and **pause on unnamed** stops the moment a frame
draws one and selects it. That turns the debugger into a way of walking the game
until it shows you something nobody has named yet.

Clicking a row makes that constant's area blink. The highlight re-fills the
polygons the renderer produced for *that draw* -- not a bounding box and not a
mask bitmap -- so what blinks is exactly the pixels it painted.

## Routine names from a listing with no addresses

`awvm-disasm` emits labels, data and instructions in address order and no
address column. `label_addresses` in `server.py` recovers them by walking the
bytecode's instruction lengths in step with the listing's instruction lines.

That walk is only as good as its length table, and a wrong length anywhere
shifts every label after it -- silently, because a shifted label is still a
plausible name. The first run put every label three bytes late: `org 0x0000` was
being counted as an instruction.

So it is checked. Every `setup channel=N, address=A` the VM executes targets a
label, because that is what the disassembler declared them from, and
`tests/check_label_addresses.mjs` requires every such address to be a computed
label address:

```
  INTRO    335 labels,  12 setups   every address is a label address
  PRISON  2113 labels,  35 setups   every address is a label address
  TANK     224 labels,  49 setups   every address is a label address
  CAVES   2917 labels,  15 setups   every address is a label address
```
