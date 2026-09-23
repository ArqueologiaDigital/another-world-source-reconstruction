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
