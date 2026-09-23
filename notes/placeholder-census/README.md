# What the placeholder labels are

| file | question it answers | command |
| --- | --- | --- |
| `placeholder_roles.py` | How is each still-placeholder label reached, and which evidence could therefore name it? | `python3 notes/placeholder-census/placeholder_roles.py` |
| | Of the ones internal to a named routine, what role does the position give them? | `... --roles` |
| | Is a complete `_F` family indexed by order of first appearance? | `... --frames` |
| | Does a `<STEM>_DONE` label close its loop onto `<STEM>_LOOP`? | `... --loops` |

The asset half of the backlog has a map — `../remaining-art/by_anchor.py`
sorts still-numbered art by how it is drawn. The label half had none. The lint
says amiga/CAVES is 32.6% semantic and msdos/CAPSULE 24.0%, which says there
is a lot left and nothing about what it is.

Measured 2026-09-23 over PRISON, CAVES and CAPSULE in both priority ports:

| | |
| --- | --- |
| labels | 14,503 |
| placeholders | **7,594** |
| — its only jumper is itself a placeholder | 2,360 |
| — unreferenced (a dead byte, or a fall-through-only join) | 2,253 |
| — reached by `call`/`setup`: an entry point | 1,690 |
| — **internal to one named routine** | **828** |
| — jumped to from 2 routines | 287 |
| — from 3 or more | 176 |

The 828 are the tractable ones. A placeholder jumped to only from inside a
routine that already has a name is a *position* in that routine, and a
position can be named without knowing what any art depicts.

## Why this is a census and not a renamer

Their roles sort cleanly — 629 forward-jump targets with a real body, 127
backward targets (loop heads), 44 two-instruction tails, 28 bare `ret` — and
549 of the 649 owning routines have exactly one, so `<OWNER>_<ROLE>` would
need no index.

The role *vocabulary* is the problem. Measured over the labels already named
in each of those positions, the final token is a content word or a phase
number far more often than a positional one: of 3,384 named forward-conditional
targets, 67 end in `DONE` and 58 in `RET`; of 433 named backward targets, 38
end in `LOOP`. A positional suffix is allowed by the tree; it is not what the
tree mostly does, and renaming 828 labels this way would make it what the tree
mostly does. That is a decision about the project's naming, not a measurement,
so it is written down here and left.

## Two rules derived from the tree, measured, and rejected

### Frames by order of first appearance — exact, and unusable

A routine that draws a **complete** `CINEMATIC_<STEM>_F*` family numbers it by
order of first appearance in its body. `--frames` re-derives it: **159 of 159**
such families obey it, 0 do not. The 19 families that looked like
counter-examples are every family the routine only *partly* draws, where the
ordinal is taken over a partial view and cannot match — a clean split, not a
threshold.

What cannot be derived is the **stem**. Of the 159, **82** have a stem
unrelated to the routine's name:

```
ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP  draws  CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F*
PTERANODON_HEAD_BEAK_OPEN_ANIM                 draws  CINEMATIC_PTERANODON_BEAK_OPEN_F*
```

Only 77 are the routine's name, or its name with a suffix removed. Using the
routine's name regardless yields 10 families and 37 pictures across both
priority ports, and reading them kills most: one would be
`CINEMATIC_PRISON_DRAW_CIN505_AT_X21_Y27_L35_F0`, a name carrying a raw
constant index *and* two screen coordinates, both forbidden by
`docs/NAMING.md` §1. Not worth a module.

### `<STEM>_DONE` names its loop head `<STEM>_LOOP` — 9 of 16

In the PRISON cutscene zoom ladder the shape repeats exactly:

```
PRISON_CUTSCENE_ZOOM_IN_PHASE_04_LOOP:
        break
        add [SCROLL_Y], 0x0002
        je [0xDB], 0x01, PRISON_CUTSCENE_ZOOM_IN_PHASE_04_DONE
        video ... x3, zoom=[0xe7]
        add [0xE7], 0x0001
PRISON_CUTSCENE_ZOOM_IN_PHASE_04_DONE:
        djnz [0xE6], PRISON_CUTSCENE_ZOOM_IN_PHASE_04_LOOP
```

Tree-wide the pairing holds 9 times out of 16, which is not a rule, so
`--loops` reports and does not propose. It does find two certain names inside
that one ladder — phases 00 and 01 are `LABEL_0236` and `LABEL_025F` while
phases 04 and 05 prove the convention twelve lines away in the same file — and
those two were taken by hand.

## Where this leaves the label half

The three classes that are not the 828 are each blocked on something real:

- **2,253 unreferenced.** Some are dead bytes, which `#0126` says must keep an
  address-shaped name. The rest are fall-through-only joins, which no jump
  points at, so reachability says nothing about them.
- **2,360 whose only jumper is itself a placeholder.** These unblock in chains
  as their jumpers get names; nothing else is needed.
- **1,690 entry points.** A `call` or `setup` target is a routine in its own
  right, and naming it needs what it *does* — the same problem the art half
  has.
