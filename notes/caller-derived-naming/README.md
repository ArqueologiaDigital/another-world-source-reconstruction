# Caller-derived naming

| script | question it answers | run it |
|---|---|---|
| `sole_named_caller.py` | How many trivial routines (whole body one `ret`, `killChannel` or `break`) can now be named from the one site that reaches them, because that site has itself been named? Also emits the proposal table. | `python3 notes/caller-derived-naming/sole_named_caller.py` · `… --port amiga --stage CAVES --proposals` |
| `named_art_only.py` | One layer up: how many unnamed routines with a body draw **only** polygons that already carry a name, so the art has settled their subject at E3 and the routine inherits it? | `python3 notes/caller-derived-naming/named_art_only.py` · `… --port amiga --stage CAVES --list` |
| `art_with_named_drawers.py` | The inverse: which still-numeric `CINEMATIC_<n>` constants are drawn **only** by routines that already have a name, so the render can be opened with a caption in hand? Groups them by the stem the drawing routines share, because a shared stem is a run to render together. | `python3 notes/caller-derived-naming/art_with_named_drawers.py` · `… --port amiga --stage PRISON --list` |

| `what_blocks_the_rest.py` | Of the unnamed routines that are left, how many are blocked by plan item T7 (they draw only from the un-re-keyed `COMMON_VIDEO` bank) or by #0138 (they draw at the shared `[0x07],[0x08]` actor record), rather than merely being hard? | `python3 notes/caller-derived-naming/what_blocks_the_rest.py --families` |

### T7 and #0138 gate 15%, not the bulk — and that corrects a guess

Working CAVES' largest families by hand kept hitting those two walls, which
made it look as though the remaining bulk was blocked on them. Measured, it is
not:

```
port/stage          unnamed  CV-only (T7)  actor slot   both  neither
amiga/PRISON           1166           166           0      0     1000
amiga/CAVES            1738            86          91    123     1438
amiga/CAPSULE          1103           192           0      0      911
msdos/PRISON           1275           171           0      0     1104
msdos/CAVES            1883            89          96    124     1574
msdos/CAPSULE          1714           196           0      0     1518
TOTAL                  8879           900         187    247     7545
```

**1,334 of 8,879, 15%.** The other 7,545 are not blocked on anything external;
they are simply hard, and need the per-family reading the 2026-09-12 and
2026-09-14 passes did. Worth knowing before anyone waits on T7 to unblock the
project — it would unblock a ninth of it.

Two details the split makes visible. The actor-record block is **CAVES-only**:
PRISON and CAPSULE have zero routines drawing at `[0x07],[0x08]`, so #0138 is a
one-stage problem despite being phrased generally. And the `COMMON_VIDEO`-only
block is heaviest in CAPSULE (192 and 196), which is also the stage whose banks
do not correspond across ports at all.

### The two art probes are not the same lever, and the PRISON pass showed it

`art_with_named_drawers.py` orders constants by **how cheap they are to
identify**. That is not the same as how much they unblock. The 42 cage
constants unblocked 18 routines, because six of their drawers were still
`DRAW_CIN0NN_AT_X03_Y04` helpers. The 10 shot-hit-burst constants, named right
after from the same work order, unblocked **zero** — every routine that draws
them was already named, which is precisely why they appeared on the list.

Both are worth doing; they just pay in different currencies. Naming a
constant whose drawers are all named improves the asset layer and the
readability of code that is already named. Naming one whose drawers are *not*
all named is what moves `named_art_only.py`.

## The measurement that says where the work actually is

`named_art_only.py` over the big three, both priority ports, 2026-09-19:

```
port/stage            unnamed w/ art  all art named   mixed  no art named
amiga/PRISON                     488              0       1           487
amiga/CAVES                      673              1       3           669
amiga/CAPSULE                    448              7       5           436
msdos/PRISON                     521              0       2           519
msdos/CAVES                      722              0       1           721
msdos/CAPSULE                    663              0       0           663
TOTAL                           3515              8      12           3495
```

**3,495 of 3,515.** Almost every routine left in the big three that draws
anything draws only polygons nobody has identified. The routine layer there is
not independently workable — it is gated by the polygon layer, and a plan that
treats the ~3,800 remaining routine names as the unit of work is measuring the
wrong thing. The unit is the ~2,100 unnamed `CINEMATIC_NNN` constants those
three stages hold on amiga (677 + 903 + 521), each of which needs a render.

Of the eight the probe reported ready, **two** survived reading and were
applied; six are recorded with their blockers in
`archaeology/docs/content/research/2026-09-19-.../`. Two of those six are the
probe working as designed rather than failing: `LABEL_4CC4` and `LABEL_4DDE`
draw `CINEMATIC_BUDDY_SMASHING_WINDOW_F8`/`_F7`, but their bodies tile a beam
(`CAPSULE_SHOT_BEAM_TILE_MEDIUM` is the sibling, and the step is 0x70 per
tile). **A named polygon settles a routine's subject only when the routine uses
it as that subject** — the probe finds candidates, not verdicts.


## Why this exists

`another-world-archaeology/tools/nameable_backlog.py` splits the backlog into
*real* bodies and *trivial* ones, and says of the trivial ones:

> nameable ONLY from their callers, so they are the tail of the dependency, and
> a pass that tackles them early can only invent.

That is a claim about **timing**. Eighteen family-naming passes have since named
thousands of callers, so the question worth asking is which of those
dependencies are now discharged. The script answers it by splitting the trivial
population four ways, and only the first is nameable:

| | meaning |
|---|---|
| `ready` | exactly one reaching site, and that site's enclosing routine classifies as semantic |
| `multi-site` | several reaching sites — a shared exit, and no single caller names it |
| `caller unnamed` | one site, but it is still a placeholder — the dependency stands |
| `no site` | nothing reaches it at all (these should be #0126 dead bytes and are excluded before counting) |

## Measured 2026-09-19

Before the pass, over the big three on both priority ports:

```
port/stage            trivial   ready  multi-site  caller unnamed  no site
amiga/PRISON               71      23          18              30        0
amiga/CAVES                70      18          17              35        0
amiga/CAPSULE              69      15          15              39        0
msdos/PRISON               77      23          19              35        0
msdos/CAVES                73      18          18              37        0
msdos/CAPSULE              71      15          16              40        0
TOTAL                     431     112         103             216        0
```

All 112 were applied (56 on amiga, the rest reaching msdos and cartridge through
`align_branch_names --merge`). Re-running the script afterwards reports
`ready = 0` in every stage, with `multi-site` and `caller unnamed` unchanged at
103 and 216 — the pass took exactly the population whose dependency was
discharged and nothing else.

## The rule, and why it is not an index suffix

The tail comes from the **body**, not from the caller:

* `ret` → `_RET`, which NAMING.md §1's suffix table already defines as "exists
  to be returned from";
* `killChannel` → `_KILL`, the thread ends here;
* `break` → `_YIELD`.

The stem comes from the sole caller. `conventions/feedback_no_index_suffixes.md`
forbids `_A`/`_B`/`_VARIANT_<n>` for separating similar routines and tells you to
distinguish **by caller, role or scene** instead; this is that first remedy,
applied mechanically where it is provably available.

Worked example, amiga CAVES:

```
CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1:
        jne [SCREEN_NUM], [0x10], SHARED_RET
        call DRAW_HERO_SPRITE_BY_VAR09_0E
        video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
        video type=0, offset=COMMON_VIDEO_124, x=[0x07], y=[0x08], zoom=0x40
        call DRAW_HERO_SUBFRAME_3_VAR09
        je [0x0D], 0x00, LABEL_8CC6
        call LABEL_8877
        jmp LABEL_8CC9          <- the only site that names it
LABEL_8CC6:
        call LABEL_8BDC
LABEL_8CC9:                     <- CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1_RET
        ret
```

## What it deliberately does not do

* **`multi-site` is left alone.** A `ret` reached from six named routines is a
  shared exit; picking one of the six would be a coin toss, and the corpus
  already has the right form for these (`SHARED_RET`, `TRIVIAL_RET`).
* **No transitive round.** A named `_RET` has no outgoing edges, so naming these
  cannot discharge further dependencies; re-running the script confirms it —
  `caller unnamed` did not move.
* **Nothing is claimed about what the caller does.** The name asserts only
  "this is where `<caller>` returns / ends its thread", which the single
  reaching edge proves.

---

## 2026-09-20: the polygon layer paid out — 108 routine names

`named_art_only.py`'s whole point was that the routine layer is gated by the
polygon layer. On 2026-09-19 it measured 112 routines drawing only identified
art and just **12** with a draw-set no sibling shared. Naming 73 shared-bank
offsets that day took the unique count to **140**, and this pass turns them
into names.

`name_routines_from_art.py` proposes, `apply_routine_names.py` writes.

### Choosing the name

**Reuse before invent.** If a routine in any other file draws exactly the same
set and already has a semantic name, take it — the same block exists in
several ports and stages and should read the same everywhere. 19 of 108 came
out that way.

**Never carry a stage prefix into another stage.** The first run proposed
`CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_00` for a block in CAPSULE and the
LEFT variant for one in PRISON. The art is shared between stages; the routine
is not.

**Put the shared index back.** Deriving from the art means the longest common
prefix with the layer word (`BODY`, `ARM`) and per-name index dropped — and
then the index restored when every drawn name carries the same one. Without
that step the four gun-arm blocks all derive `DRAW_HERO_GUN_ARM_RIGHT`: one
name, four labels, which is the collision the probe exists to prevent.

**Match an earned sibling's spelling.** `name_routines_from_art.spelling`
pins `DRAW_HERO_GUN_ARM_RIGHT_CASE_01` onto `HERO_GUN_ARM_POSE_CASE_01`,
because cases 02 and 03 were already earned under that spelling in CAVES.
Without it the result is two families with a hole each rather than one
complete run 01..04, which NAMING.md §2 forbids. Each line names the sibling
that justifies it.

**Honour recorded skips.** `name_routines_from_art.skip` holds what an earlier
pass looked at and rejected, with the reason. Without it this pass silently
re-proposes CAPSULE's `LABEL_4CC4`, whose art is itself disputed — the routine
tiles a beam while the polygon claims to be the alien breaking a window. A
routine cannot inherit a subject from art whose subject is in doubt.

### Applying it is not a token replace

A label is per branch. `LABEL_6C78` exists in amiga/PRISON and msdos/PRISON
and is different code at the same address. The applier writes to the canonical
`.asm` and to `_unified/<stage>/` chunks whose `__`-prefix says which branches
read them, and only when every reading branch agrees on the new name.

**A label any all-branch chunk references is dropped from the pass entirely** —
20 of the 128 were. Skipping just that chunk is worse than useless: amiga and
msdos would rename their canonical copies while the shared chunk still names
the old spelling, a dangling reference the pass created itself.
`capsule_init_dispatch.inc` naming `GUARDED_DRAW_CV_126` is the case that
forced the rule.

### Result

    128 proposals, 20 dropped as all-branch, 108 applied
    360 canonical tokens + 165 unified-chunk tokens rewritten
    make test 29/29 and 29/29, undefined_symbols clean

Complete families, no index gaps: `DRAW_HERO_WALK_RIGHT_F00..F14`,
`DRAW_HERO_RUN_RIGHT_F00..F09`,
`DRAW_HERO_WATER_DEPTH_{LEFT,RIGHT}_CASE_00..03`,
`HERO_GUN_ARM_POSE_{,LEFT_}CASE_01..04`.

Routine-layer share, before → after: amiga/CAVES 27.0 → 28.0 %, amiga/PRISON
→ 32.7 %, amiga/CAPSULE → 27.0 %. Routines drawing only identified art fall
from 3,441 to 3,333, and the unique-and-nameable pool from 140 to 32 — the
pass consumed what it could reach.

### Second pass, same day: 35 more, after the actor sheet

Naming 40 actor-slot offsets unblocked another round. `name_routines_from_art.py`
proposed 64; 29 were dropped by the all-branch-chunk rule and **35 applied**.
The new material is a complete `DRAW_FIGURE_WALK_LEFT_F00..F15` run, plus
copies of `DRAW_HERO_RUN_RIGHT_F*` and `DRAW_HERO_STAND_LEFT` landing in the
ports and stages the first pass could not reach.

The `DRAW_FIGURE_` stem comes from the derivation dropping the bank word:
`CV_FIGURE_WALK_LEFT_BODY_F00` gives `FIGURE_WALK_LEFT` plus the shared index.
Like the art it is named for, it claims a figure and no character.

Routine-layer share after both passes: amiga/PRISON 32.8 %, amiga/CAVES
28.6 % (from 26.3 % at the start of the day), amiga/CAPSULE 27.2 %. Routines
drawing only identified art 3,441 → 3,298; those drawing nothing but
placeholders 3,138 → 3,052.
