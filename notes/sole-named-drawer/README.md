# Naming polygons without rendering them: what works, and what it is worth

`named_art_only.py` established the direction of the backlog — the big
stages' routine layer waits on their polygon layer, because a routine drawing
only unidentified art cannot be named from it. True of the bulk, and this
directory is the exception: the cases where the **routine layer can name the
polygon layer**, with no render.

Every rule here derives a constant's name from something already earned, so
none of them proposes a subject. That is also their ceiling.

## The rules, and what each returned on 2026-09-19

| rule | where | found | applied |
|---|---|---|---|
| sole `_DRAW` routine, one exclusive draw | `nameable_from_drawer.py` (default) | 8 | 8 |
| named routine, whole draw set exclusive, **one anchor** | `--animations` | 31 routines / 171 constants | 22 routines / 108 constants |
| family completion from earned members | `../family-completion/` | 4 | 4 |
| `*_COMPOSITE` routine, whole part-set exclusive | measured, not kept | **0** | — |

`--pool` prints the wider population: **658** unnamed constants whose sole
drawer is named. That is the pool, not the yield. The gap between 658 and the
~120 above is the whole content of this directory.

## Why most of the pool does not qualify

Each of these cost a batch, a revert or both before becoming a filter:

- **the routine names a mechanism, not a subject.** `FILL_PAGE_00_COLOR_08`
  draws two constants; the art is not "a page fill". 16 routines dropped.
- **the routine's own name carries a raw constant index** —
  `DRAW_CITY_SEQ_435_436`, `DRAW_CINEMATICS_166_TO_171`. It is a placeholder
  under NAMING.md §1 whatever else it says, and deriving from it would copy
  the placeholder onto the art.
- **the other port already uses the derived name for other art.** 6 routines.
  This one is invisible to every per-port check, by design, because a
  branch-scoped rename is judged against that branch's files — and it is the
  one that actually bit: naming msdos/INTRO's `LESTER_EXITING_CAR` frames
  passed `make test` 29/29 and silently moved the cross-port audit from 10
  disagreements to 23.
- **several anchors.** One anchor means frames of one thing; several mean
  props along a path, and a prop needs identifying on its own. 12 routines /
  87 constants sit here.
- **the sizes do not support one family.** `TANK_DESTROYED_CUTSCENE_BLAST_
  ENTRY` passes every structural test and its six frames measure 11x4, 11x4,
  10x5, 10x4, 8x3 and then 205x138. Five specks and a full-screen flash are
  not six frames of one thing.
- **two earned routine names for one art** (#0120). amiga's
  `STORM_AMBIENT_DRIFT_DRAW_LOOP` and msdos's
  `STORM_PARTICLE_TUMBLE_ANIM_LOOP` draw art identical five for five by md5.
  Not ours to adjudicate.

## What is left

What remains in the pool needs a render, which is the E3 work these rules
exist to avoid and cannot replace. The honest read of the table above is that
naming-without-looking is worth about a sixth of the constants it can see,
and the rest of the 64% still unnamed will be found by looking at it.
