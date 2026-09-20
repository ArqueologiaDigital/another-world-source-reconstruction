# The group header is a pivot, not a bounding box

A measurement bug in `tools/polygon_extent.py`, found on 2026-09-20, fixed, and
its consequences chased down.

## What was wrong

Both polygon header forms carry two size bytes, and they do not mean the same
thing:

| header | bytes 1,2 | engine does |
|---|---|---|
| solid (`>= 0xC0`) | bounding box | `cx - bbox_w / 2 + px` per point |
| group (`& 0x3F == 0x02`) | **pivot** | `pgc_x = x - b1`, then `pgc_x + px` per child |

`extent()` halved both. That shifts every group child by half the pivot and
inflates the reported box, invisibly on a flat tree and worse with nesting.

The reference VM's `readAndDrawPolygonHierarchy` subtracts the group bytes
whole, and `AnotherWorld_VMTools/awvm/src/polygons.rs:326` ports it faithfully.

## Why it survived so long

`tools/polygon_extent.py`'s docstring states the design goal: "reading
`cinematic.rom` directly so there is no renderer in between". Cutting the
renderer out was the point -- and it removed the only thing that would have
caught a misreading of the format. Nothing compared the two until now.

It also hid in the sample. Single-leaf art measures correctly under both rules,
and single-leaf art is most of what gets measured: specks, bars, slivers. The
figures are the minority, and they are exactly the ones that were wrong.

## `extent_matches_renderer.py` -- which rule is right

Measures every polygon the renderer emits, from the ROM, and compares against
the bounding box of the renderer's own SVG.

    $ ... --renders <dir> --bank video2            # 1,212 polygons
    old rule          1069 exact   39 degenerate-leaf   104 unexplained
    corrected         1177 exact   35 degenerate-leaf     0 unexplained

    $ ... --renders <dir> --bank cinematic --stage 4   # 2,893 polygons
    old rule          2311 exact  434 degenerate-leaf   148 unexplained
    corrected         2544 exact  349 degenerate-leaf     0 unexplained

"Degenerate-leaf" is not a fudge: it is the renderer's own documented
heuristic, tested by its exact condition rather than an approximation of it --
a 4-point polygon with `pt[0]==pt[3]` and `pt[1]==pt[2]` is really a line, and
`polygons.rs` widens it by 2 "so the SVG viewer renders it". The measurement
reports the true extent instead. A first version of the test asked the looser
question "does some leaf measure under 2 units wide", which excused 100
polygons the old rule got wrong for the ordinary reason and so concealed most
of the bug it was written to characterise.

## `what_the_correction_moves.py` -- what it costs

    2468 of 10144 named polygons change extent        (2026-09-19, when the
                                                       correction landed)
    2195 of  9397 named polygons change extent        (2026-09-20, re-run)

**Re-run it before quoting either.** The proportion is stable at ~24%, but the
population is not: the denominator is "EQU names in `src/levels` starting
`CINEMATIC_`, `DRAW_CIN_` or `CV_`", and a day of naming, de-prefixing and
shared-bank re-keying moved it by 747. Which of those passes accounts for the
drop has **not** been established -- it was noticed during a staleness sweep,
not investigated, and it is recorded here as an open question rather than
given a cause it has not earned.

Neither figure is wrong; they measure different populations a day apart. What
would be wrong is repeating the first one as though it still reproduces, which
is what this file did until now.

Nested art moves by a median of ~60 units and up to 208. Pairwise size-order
inversions do occur, so a size *comparison* could in principle have flipped,
which is why the affected claims were re-measured one by one rather than waved
through.

## What did not change

- **Every cross-port identity claim.** `polygon_tree.canonical_md5` serialises
  the header bytes verbatim and never interprets them. The md5-equal pairs, the
  duplicate audit, and the transfer-by-art-identity pass are untouched.
- **Every audit still passes**, re-run after the fix: `--sides` clean,
  `--duplicates` clean at 1,842 pictures with one name each, and the cross-port
  art audit still reports the same 9 disagreements.
- **The worked example in `tools/polygon_extent.py`.** CAVES' three
  falling-rock draws still measure 21x20, 38x24 and 58x28 -- those trees are
  flat, so SMALL/MEDIUM/LARGE was never at risk.

## What did change

Three figures in `../render-attempts/README.md`, corrected in place there with
a table; **no name was affected**. The largest was
`CINEMATIC_CAVES_LANDING_SPLASH_F0..F9`, recorded as "15x14 growing to 88x93
and dispersing to 74x67". It actually swells to 32x33 and then shrinks to 8x15
-- which supports `CAVES_HERO_LANDING_SPLASH` better than the old numbers did,
since a splash subsides and the recorded "dispersal at 74x67" was the bug's
inflation curve rather than anything in the art.

## Running these

    python3 notes/polygon-extent-correction/extent_matches_renderer.py \
        --renders <dir> --bank video2 [--old]
    python3 notes/polygon-extent-correction/what_the_correction_moves.py [--worst]

The renders are regenerable and not committed:

    cd AnotherWorld_VMTools
    cargo run --quiet --bin awvm-render-polygons -- --port amiga --stage 4 \
      --romset ../another-world-archaeology/tmp/output/amiga/romset \
      --bank video2 --out <dir> --palette 0

`video2.rom` there is resource `0x11` zero-padded to 32 KiB; its first 25,108
bytes are identical, so offsets agree with the resource dump.

`extent_matches_renderer.py` exits 1 if any polygon disagrees for a reason
other than the degenerate-line convention, so it will not pass silently if the
format is misread again.
