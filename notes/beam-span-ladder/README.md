# The beam-span ladder, and the rung a name claims

## What question this answers

PRISON, CAVES and CAPSULE each hold the same routine --
`<branch>__post_COPY_VAR27_TO_VAR07.inc`, the same file name in all three --
which draws a shot as a **pair of one-pixel-tall horizontal bars**, one
extending right from `[0x21]` and one extending left from `[0x22]`, picked from
a ladder by the span between them.

A name like `..._SPAN_RIGHT_4` claims a position in that ladder. This checks the
claim:

    python3 notes/beam-span-ladder/rung_thresholds.py
    python3 notes/beam-span-ladder/rung_thresholds.py --port msdos --stage PRISON

Per rung it prints the threshold, both constants, and each one's measured width,
and marks a row `**` when they disagree.

## The signal, and why the rung index is not a guess

    [0x26] = [0x22] - [0x21]
    jl [0x26], 0x7E -> ...
    ...

The thresholds are `0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E` = **2, 6, 14, 30, 62,
126**, each `2n + 2` of the one below -- and each equals the drawn width
(`polygon_extent.extent`) of the pair it selects. So the ladder position is a
measurement, not a reading.

Two exceptions, neither a defect:

- the `0x64` (100) rung reuses the 62 pair; there is no 100-wide art;
- below `0x02`, one 0-wide dot on the right slot only, which PRISON names
  `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`.

The **`bit set`** rows are a second set at 62 and 126 only, in another colour
index (`#fb6487` against `#a74400` at palette 2), chosen when bit 0x2000 of the
shot's state word `[0x12]` is set --
`amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc` sets it for the scripted beam
drawn between `[BUDDY_X]` and `[HERO_X]`. Those four constants per stage are
left numbered deliberately: the fact is established, the meaning of the bit is
not, and a colour word under a palette that varies is not a name.

## Run of 2026-09-23

Every rung in amiga and msdos, in all three stages, is in its right place: not
one `**`. That result took two corrections, and both are worth more than the
result.

**The `0x2000` arm runs when the bit is CLEAR.** `jge [0x12], 0x2000, T` jumps
*away* to `T`, so the block containing the test is the bit-clear path. Labelled
the other way round, the default ladder looked like the exception.

**A unified routine must be resolved against the unified EQU tables.** The body
walked here comes from `src/levels/_unified/...`. Resolving its symbols against
`src/levels/<branch>/<STAGE>.asm` reported msdos CAVES' entire ladder as
misplaced, `CINEMATIC_TELEPORT_UP_BEAM_LEFT` as a 6-pixel beam rung and amiga
CAPSULE's `SCREEN_91_BACKDROP_LAYER_3` as a 224-pixel one. **Every one of those
was false.** The symbols all resolved -- to the wrong pictures.

> A name means what the tree it was read from says it means. A probe that reads
> a body from one tree must read its table from the same tree.

The tool now resolves unified-first and prints a `!` line for each name the two
trees disagree about. `../tree-name-drift/` measures that disagreement across
the whole repository, which is how it stopped being a surprise.

## What it fed

`CINEMATIC_{514,515,520,521}` in PRISON became
`CINEMATIC_PRISON_SHOT_BEAM_SPAN_{RIGHT,LEFT}_{4,5}` in amiga, msdos and
cartridge -- see `../render-and-name/proposals_*__PRISON_beam_rungs.md`.

Still numbered and nameable from this probe alone, in a later batch: the whole
cartridge CAVES ladder (rungs 0..5 plus the dot), most of msdos CAVES' and
msdos CAPSULE's, and amiga CAPSULE's and amiga CAVES' rung 5. Cartridge
CAPSULE's `SPAN_LEFT_4` and `SPAN_RIGHT_4` are drawn at its **rung 0** and its
below-ladder fallback, which the routine shows without any ROM; that pair wants
correcting before its ladder is completed.

## Held: the second set at the top two rungs, 34 constants, no name in any port

The ladder's two longest rungs each carry **two** pairs, chosen by
`jge [0x12], 0x2000`. One pair is named in each stage —
`PRISON_SHOT_BEAM_SPAN_*`, `CAVES_LASER_BOLT_SPAN_*`,
`CAPSULE_SHOT_BEAM_SPAN_*` — and the other pair is numbered. That is 3 stages x
3 ports x 2 rungs x 2 sides = **36 slots, and 34 of them are still numbered**;
the other two are unified-tree drift, not names (see below).

What is measured about the alternate set, `rung_thresholds.py` plus the polygon
renderer, msdos, all three stages:

Reproduce it with the probe committed beside this note:

    node notes/beam-span-ladder/colour_of.mjs --romset <msdos romset> \
        --level 6 --branch dos_1992 --stage CAPSULE \
        CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_5 CINEMATIC_673 \
        CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_5  CINEMATIC_674

| | named set | alternate set |
| --- | --- | --- |
| polygons | 1 | 1 |
| width at rung 5 / rung 4 | 126 / 62 | 126 / 62 |
| height | 1 | 1 |
| **colour index** | **15** | **13** |

It holds without exception across PRISON (`CINEMATIC_516..519`), CAVES
(`857..860`) and CAPSULE (`671..674`). The two sets are **the same line in a
different colour**, and in the tree the difference is one bit: the child
descriptor's `0x8000` flag, which decides whether an explicit colour byte
follows or the caller's colour is inherited.

**What is not known is what the colour means**, and that is the whole of what
stands between these 34 constants and a name. `[0x12]` is not the span — the
span is `[0x26] = [0x22] - [0x21]`. `[0x12]` carries a small magnitude in its
low bits (`and [0x12], 0x1FFF` then `jl [0x12], 0x08` then `shr` by 3) with bit
0x2000 packed in as a flag beside it, and the sites that set the flag do not
agree across stages: msdos/CAPSULE sets it at `LABEL_0DE4`, immediately after
`mov [BUDDY_X], 0x000F`, while msdos/CAVES sets `mov [0x12], 0x2010` right after
`CAVES_BEAST_PER_FRAME_TICK`. Buddy in one stage and the beast in the other is
not one subject, so no subject word is earned.

**What would settle it:** someone firing in `tools/vm-debugger/` and saying what
changes about the beam when it changes colour. This is the exact shape of
question `notes/play-and-describe/` exists for — a fact about what the player
sees, which no measurement in this directory can reach. Until then: held, not
guessed.

### Two rows that look named and are not

`rung_thresholds.py` resolves names in the tree the routine came from, which is
the unified tree, and the unified tree lags (`../tree-name-drift/`). So two
alternate-set slots print with names attached:

    msdos/CAVES    rung 4 left   CINEMATIC_TELEPORT_UP_BEAM_LEFT
    amiga/CAPSULE  rung 4 left   CINEMATIC_CAPSULE_SCREEN_91_BACKDROP_LAYER_3

Neither is in the naming record. The canonical trees have `CINEMATIC_858` and
`CINEMATIC_525` in those slots, still numbered. The giveaway is that
`TELEPORT_UP_BEAM_LEFT` renders as **4 polygons at colour indices 7, 4, 15, 6**,
which no member of a one-polygon family can be -- one line of `colour_of.mjs`
output, with `--level 4 --stage CAVES`.
