# Does a picture's gait word agree with whoever draws it?

| file | question it answers | command |
| --- | --- | --- |
| `motion_vs_drawer.py` | Which named pictures carry a motion word that **no** routine drawing them shares? | `python3 notes/motion-word-audit/motion_vs_drawer.py` |
| `piece_family_vs_label.py` | Which routines name one gait while every figure piece they draw comes from another gait's sheet? | `python3 notes/motion-word-audit/piece_family_vs_label.py` |

`--pairs` summarises by (picture motion, drawer motion); `--pair RUN WALK`
lists one class.

## Why

`CAVES_DRAW_HERO_IDLE_LEFT_1` drew the first frame of a laser-impact flash and
the byte gate never blinked, because a rename moves no bytes. The only thing
that catches that is reading a name against the thing it names. This module
does it over the one vocabulary narrow enough to check mechanically — the gait
words — sharing the list and synonyms with
`../shared-bank-geometry/hero_pose_consensus.py` so there is one vocabulary,
not two.

The precedent is real: `HERO_FALL_LEFT_LOOP` was a name of exactly this shape
and turned out to be the walk.

## What it measures

Over both priority ports, 2026-09-23:

```
 1978  named pictures carrying a motion word
 1324    agrees with at least one drawer
  547    no drawer names a motion
  107    ** every drawer names a different motion
```

The 107 sort by pairing (as first measured; RUN/WALK is 2 after the correction
below, and the total 97):

| picture says | drawer says | times |
| --- | --- | --- |
| PRONE | CRAWL | 24 |
| JUMP | RUN | 21 |
| PRONE | WALK | 18 |
| CRAWL | WALK | 13 |
| RUN | WALK | 12 |
| JUMP | WALK | 12 |
| CROUCH | AIM | 4 |
| CROUCH | SHOOT | 4 |
| CRAWL | STAND | 4 |
| STAND | AIM | 4 |
| STAND | CROUCH | 4 |
| STAND | WALK | 2 |

## Why it is a reading list and not a gate

Frequency separates a convention from an accident. It does **not** separate
right from wrong — a systematic mislabel is systematic, which is exactly what
the sixteen INTRO names copied by index were. So the classes were read, and
the top ones are the code being correct:

**A loop draws the pose it exits into.** This is the big one.

```
HERO_CROUCH_HOLD_LEFT_LOOP:
        break
        video type=0, offset=HERO_CROUCH_LEFT, ...      <- what it is
        je [HERO_POS_JUMP_DOWN], 0x01, HERO_CROUCH_HOLD_LEFT_LOOP
        break
        sub [HERO_X], 0x0002
        video type=0, offset=HERO_STAND_ARMED_LEFT, ... <- standing back up
        mov [0x63], 0x0001
        jmp HERO_WALK_LEFT_LOOP
```

The crouch is drawn in the loop; the upright armed pose is drawn once, on the
way out. Both names are right and they will never share a word. That is
STAND/CROUCH and STAND/WALK, and it is worth stating because those two look
like the sharpest contradictions in the list — a hero cannot be standing and
crouching — and they are not contradictions at all.

`HERO_STAND_ARMED_LEFT` is 0x17CC and `..._RIGHT` is 0x1664, which
`../shared-bank-geometry/pose_height.py` measured at 45.0 and 44.5 against an
upright median of 49.0, versus 33.0–33.5 for the real crouches. They were
renamed from a CROUCH claim to a STAND one in `87a48f38` on that measurement.
The names are settled; the pairing is an artefact of where the draw sits.

**A transition is named for the state it reaches.** `HERO_PRONE_TRANSITION_*`
drawn by `PRISON_HERO_CRAWL_RIGHT_START` and `..._STOP` — PRONE/CRAWL and
PRONE/WALK, 42 of the 107.

**A sprite sheet can lift the figure inside its own frames.** JUMP/RUN and
JUMP/WALK, 33 of them, are `../actor-sprite-sheet/`'s finding: the jump sheets
are driven from the run and walk loops and the lift is drawn rather than
written to `HERO_Y`.

## The one class that was left open, and how it closed

RUN/WALK, and not the LAKE row in it — `HERO_SHADOW_RUN_RIGHT_0` is drawn by
`HERO_WALK_RIGHT_LOOP` once, on the same exit-transition pattern. It is
PRISON:

```
CV_FIGURE_RUN_LEFT_BODY_F00  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_0_DONE
CV_FIGURE_RUN_LEFT_BODY_F03  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_3_DONE
CV_FIGURE_RUN_LEFT_BODY_F05  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_5_DONE
CV_FIGURE_RUN_LEFT_BODY_F07  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_7_DONE
CV_FIGURE_RUN_LEFT_BODY_F08  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_8_DONE
```

The frame index and the phase index agree every time, so this was one animation
under two conventions rather than a misattribution.

It did not need travel-per-frame in the end. `piece_family_vs_label.py` settles
it without a name contest, by asking which **sheet** the pieces come from — and
those sheets were named from geometry in `../shared-bank-geometry/` and
`../actor-sprite-sheet/`, independently of any stage's label conventions.

The three stages that animate this actor split cleanly except for one:

```
amiga/CAVES     RUN  PHASE -> RUN  (30)     WALK PHASE -> WALK (19)
amiga/CAPSULE   RUN  DRAW  -> RUN  (30)
amiga/PRISON    RUN  POSE  -> RUN  (6)      WALK POSE  -> WALK (46)
                WALK PHASE -> RUN (10) + WALK (19)      <- mixed
```

CAVES draws the same two sequences and keeps them apart. PRISON's
`WALK ... PHASE` family holds both — the *same 19* WALK draws, and 10 more
that are pure RUN. The 19 matching exactly is the corroboration: PRISON is not
using a different scheme, it has ten labels in the wrong half of its own. And
the routine is literally the same code in all three stages: same shape, same
`sub [<actor>_Y], 0x0001`, same `CV_320A` fallback, same two draws.

The ten, identical in all three branches that have them, none drawing a piece
from more than one family:

```
PRISON_ACTOR_WALK_LEFT_PHASE_{0,3,5,7,8}_DONE  ->  ..._RUN_LEFT_PHASE_{...}_DONE
PRISON_BUDDY_WALK_LEFT_PHASE_{0,3,5,7,8}       ->  ..._RUN_LEFT_PHASE_{...}
```

each drawing a `CV_FIGURE_RUN_LEFT_BODY_F<nn>` together with a
`CV_FIGURE_RUN_LEFT_UPPER_POSE_<nn>` — a body and an upper from the run sheet,
under a label that said walk. Applied to all three branches, 30 renames.

Afterwards `piece_family_vs_label.py` reports **0** and exits 0, and this
module's RUN/WALK class fell from 12 to 2. The 2 that remain are the LAKE
exit-transition rows, which are the code being correct.

Unlike the drawer comparison, the piece comparison **does** fail the build when
it finds something, because it has no benign explanation: a body and an upper
from one sheet is what the routine draws, not what it exits into.

## The 547 that name no motion at all

Those are pictures whose drawers are all mechanism-named or unnamed. They are
not a finding; they are the same backlog
`../draw-label-follows-constant/` reports from the other direction.
