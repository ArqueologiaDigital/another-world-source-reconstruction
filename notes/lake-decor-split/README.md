# Splitting a group named after a coordinate

`../crossstage-duplicates/` found `CINEMATIC_DECOR_AT_305_155_F7` — the exact
name NAMING.md §1 uses as its example of what not to write — and showed the
group is not one subject: F00 is 47x3/1, F01..F04 ~40x16/12, F07,F08 are 0x1
specks, F09..F13 22x48/5, F14 20x69/1, at scattered offsets. It was formed by
**where it is drawn**, not by what it is, which is how a coordinate got into
the name.

Fixing it therefore means splitting by subject. That needed a render.

## What the render showed, and what the code corrected

Rendered from LAKE's cinematic bank, the 19 frames are plainly several
things: a figure lying and rising, a small angular object beside a vertical
line, a thin bar, a solid vertical mass.

My reading of the figure frames was **wrong in one place and the code said
so**. I took F05/F06 for "propped up on elbows" and F15..F18 for "sitting
up". The routines that draw them:

    LESTER_FALL_PHASE_1                  F05
    LESTER_FALL_PHASE_2                  F06
    LESTER_DROP_LAND_AT_POOL_EDGE_BODY   F15 F16 F17 F18   (in that order)
    DRAW_REED_DRIFT_LEFT_LOOP            F14

Lester is *falling*, then *landing at the pool edge* — LAKE's opening, not
someone waking up. The drawer also supplies the frame order for the landing,
so the index is read rather than inferred.

## Applied: 7

    CINEMATIC_LAKE_LESTER_FALL_F0, _F1            (was ..._F5, ..._F6)
    CINEMATIC_LAKE_LESTER_DROP_LAND_F0..F3        (was ..._F15..F18)
    CINEMATIC_LAKE_REED                           (was ..._F14, 20x69/1)

Renamed in **every branch at once** — all four define the same constant and
routine names, and the art is byte-identical between the priority ports
(`canonical_md5`, seven for seven), so one name is right everywhere and the
shared unified chunks stay consistent. 92 tokens in 8 files.

Coordinate-embedding names drop from 22 to **15**.

## What is left, and why

    F00       47x3/1     a thin horizontal bar
    F01..F04  ~40x16/12  drifting decor (DECOR_F1_DRIFT_LOOP, F2_DRIFT_LOOP)
    F07,F08   0x1        specks, in hold loops
    F09..F13  22x48/5    a small angular shape beside a vertical line
    F327_164  221x15/5, 213x1/3   two wide thin bars

F09..F13 were magnified and are still not identifiable — the shape could be
a creature, a plant or part of a mechanism, and nothing in the drawer names
(`DECOR_F9_THEN_F10_F9_BODY`, `DECOR_F11_HOLD_LOOP`) says which. They keep
the coordinate name, which is now at least attached to a genuinely
unidentified remainder rather than to Lester falling into a lake.
