# What a named routine draws

One probe. It exists because a scanning convention used all over this repo is
wrong in a specific, one-directional way, and I only noticed when it caused a
wrong rejection.

## The convention, and where it breaks

"Which routines draw picture X" is normally answered by crediting each
`video offset=` line to the **nearest preceding label**. Routines here span
several labels:

    PRISON_HERO_STAND_LEFT_DRAW:
        jne [0x0A], 0x00, LABEL_6DBF
        video offset=CV_3322, ...        <- credited correctly
        jmp LABEL_6DC2
    LABEL_6DBF:
        call GUARDED_DRAW_CV_126
    LABEL_6DC2:
        call LABEL_6D1E
        video offset=CV_0358, ...        <- credited to LABEL_6DC2

Nothing but that routine reaches the second draw, and it performs it
unconditionally, but the rule files it under an address placeholder.

The bias is one-directional: **named sources are undercounted, never
overcounted.** So "at least N independent sources agree" stays sound, and
"only one source, so reject" is sometimes wrong. That is exactly what
happened — the shared-bank consensus pass rejected `CV_0358` for having one
source when it has three.

## The fix, and the mistake in the first version

Build the intra-file CFG (fallthrough, `jmp`, conditional jumps, `call`) and
compute, for each unnamed block, the set of named routines that reach it
without passing through another named label. Credit the block only when that
set has exactly one member.

The first version had no exclusivity rule: it walked forward from each named
routine and credited everything reachable. That took msdos/CAPSULE from 297
(routine, picture) pairs to **10,402** — 21 pictures per named routine —
because a forward walk floods the large unnamed regions these stages still
have, and every routine that can reach a shared helper collects everything the
helper draws. The docstring at that moment claimed the analysis "undercounts,
never the other way round", which was true of the rule it replaced and false
of the replacement.

With exclusivity:

    $ python3 notes/routine-extent/named_routine_draws.py --compare
    TOTAL   nearest-label 6511   control-flow 7598   gained 1087

A 17 % gain rather than a 5x flood, and every gained pair is a picture drawn
by a block only that routine reaches.

`--shared` lists what is deliberately attributed to nobody, and it is the
right shape: `DRAW_PRISON_BUDDY_POSE_0_0` is reached by 59 named routines,
`DRAW_ALIEN_POSE_0_5` by 126. Those are shared pose drawers; no caller's name
describes what they draw.

## Usage

    python3 notes/routine-extent/named_routine_draws.py --symbol HERO_STAND_LEFT_BODY
    python3 notes/routine-extent/named_routine_draws.py --routine PRISON_HERO_STAND_LEFT_DRAW
    python3 notes/routine-extent/named_routine_draws.py --compare
    python3 notes/routine-extent/named_routine_draws.py --shared

Reads only `src/levels/<branch>/<STAGE>.asm`; nothing from the ROM, because
this is a property of the control flow rather than of the art.

## What still is not modelled

Indirect dispatch. A `setup channel=..., address=X` installs a thread rather
than jumping, so a routine installed by another is not reached here and should
not be — but it does mean this measures *static intra-file* control flow, not
everything the VM will run.
