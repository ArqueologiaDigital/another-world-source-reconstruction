# Caller-derived naming

| script | question it answers | run it |
|---|---|---|
| `sole_named_caller.py` | How many trivial routines (whole body one `ret`, `killChannel` or `break`) can now be named from the one site that reaches them, because that site has itself been named? Also emits the proposal table. | `python3 notes/caller-derived-naming/sole_named_caller.py` · `… --port amiga --stage CAVES --proposals` |
| `named_art_only.py` | One layer up: how many unnamed routines with a body draw **only** polygons that already carry a name, so the art has settled their subject at E3 and the routine inherits it? | `python3 notes/caller-derived-naming/named_art_only.py` · `… --port amiga --stage CAVES --list` |
| `art_with_named_drawers.py` | The inverse: which still-numeric `CINEMATIC_<n>` constants are drawn **only** by routines that already have a name, so the render can be opened with a caption in hand? Groups them by the stem the drawing routines share, because a shared stem is a run to render together. | `python3 notes/caller-derived-naming/art_with_named_drawers.py` · `… --port amiga --stage PRISON --list` |

### The two are not the same lever, and the PRISON pass showed it

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
