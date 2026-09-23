# The shot-impact burst, and a label that was not a frame

## What is here

| file | question it answers | command |
| --- | --- | --- |
| `impact_ladder.py` | Which picture does each shot-impact dispatch draw at each value of the timer `[0x13]`, and do the branches agree? | `python3 notes/laser-impact-anim/impact_ladder.py` |
| `proposals_<branch>__<STAGE>.md` | the names those answers earn, one table per (branch, stage) | `impact_ladder.py --proposals` |

The probe finds its own subjects. A dispatch entry is the block containing the
second comparison of the binary search, `jle [0x13], 0x05, <arm>`; there are
**six per branch** — PRISON, CAVES and CAPSULE times two directions — and none
in `gba_2004`, which drops the effect. Direction is not read from the label
either: PRISON's rightward dispatch is still called `LABEL_3BB3` and says
nothing, so the probe takes the direction from the `[0x0E]` the calling advance
block sets (0 rightward, 1 leftward), which is what the drawing code itself
reads to pick the mirrored art.

## Why it exists

`notes/sole-named-drawer/nameable_from_drawer.py` proposed six names in CAVES,
all of the form

```
amiga/CAVES  CINEMATIC_777  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04
```

and the indices it produced were `01, 02, 04` — a family with a hole at `03`,
which `docs/NAMING.md` §2 forbids. The hole was the tell. The names were taken
from the label of the routine that draws each picture, and those labels are not
frames:

```
CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT:
        jge [0x13], 0x64, LABEL_684D
        jle [0x13], 0x03, CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_02
        jle [0x13], 0x05, CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04
        video offset=CINEMATIC_778
        mov [0x13], 0xFFFE
        ret

CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04:
        jle [0x13], 0x04, DRAW_CIN_776
        video offset=CINEMATIC_777
        ret
```

`..._ABOVE_04` is an **interior node of a binary search**. It is entered for
timer values 4 and 5, and the picture drawn *at the label itself* is the one for
value 5. So the inherited name is off by one, and it records a search threshold
in a slot where a frame index belongs. The three pictures that got no proposal
at all — `CINEMATIC_773`, `776`, `778` — are not missing art; they sit behind
`DRAW_CIN_<n>` fallthrough labels that carry no name to inherit. The gap was in
the labels, never in the animation.

`impact_ladder.py` therefore ignores labels and **evaluates** the ladder: for
each timer value it follows the comparisons until a `video offset=` is reached,
and reports the constant that value actually draws.

## What the evaluation found

A closed six-frame one-shot per direction — **and the same one in three
stages**. The caller is the clock:

```
CAVES_LASER_IMPACT_ANIM_ADVANCE_RIGHT:
        and [0x13], 0x7FFF        <- low 15 bits: the frame counter
        mov [0x0E], 0x0000           high bit: this slot is mid-impact
        call CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT
        add [0x13], 0x0001        <- one frame per tick
        or  [0x13], 0x8000
```

All three stages use that advance block verbatim, and all three seed the timer
the same way — `CAVES_LASER_SHOT_IMPACT_RESOLVE_RIGHT`,
`PRISON_SHOT_RIGHT_IMPACT_RESOLVE` and `CAPSULE_SHOT_BLOCKED_RESOLVE_RIGHT` each
do `mov [0x13], 0x0001`, and the helper each calls on the way in never writes
`[0x13]`. So the run is v = 1..6, and **there is no frame 0**: the only other
entry to the dispatch is `jl [0x13], 0x00` from the slot loop, which is the
continuation path where the high bit is set, and `je [0x13], 0x00` goes to the
in-flight shot instead. At v >= 6 the dispatch
writes `[0x13] = 0xFFFE`; the `add`/`or` that follow turn it into 0xFFFF, which
is exactly the value `CAVES_LASER_SHOT_SLOTS_UPDATE_LOOP` tests for a free slot
(`je [0x88], 0xFFFF`). The run starts at 1 and terminates itself at 6, so 1..6
is the machine's own index and `F01..F06` has no gap in it.

Measured by `impact_ladder.py` on 2026-09-23 — extent and leaf count of the
polygon tree at each constant's EQU value in that stage's cinematic bank. The
figures below are identical for all six ladders in both priority ports, because
**the art is the same picture**: `canonical_md5` agrees frame for frame across
PRISON, CAVES and CAPSULE and across amiga and msdos (`80fe8a4c, c3c706a1,
1e6ec76a, 8206ed61, cc7e82ee, 3a6aa371` rightward; `fc789def, 8d55ee4b,
96974614, e7e27f0b, cf24afd9, 599129dd` leftward). Three stages draw one
effect out of three copies of the bank.

| v | extent | leaves | what it looks like |
| --- | --- | --- | --- |
| 1 | 2.0 x 5.0 | 6 | a spark |
| 2 | 9.0 x 10.0 | 6 | opening |
| 3 | 17.0 x 12.0 | 7 | widest leaf count |
| 4 | 17.0 x 17.0 | 6 | full flash |
| 5 | 16.0 x 17.0 | 4 | thinning |
| 6 | 4.0 x 6.0 | 2 | residue, and the slot is freed |

LEFT and RIGHT are different art from each other, as a mirrored sprite pair
should be.

## The index base, and a convention this pass first got wrong

The first version of this work named CAVES' frames `..._F01..F06`, keyed
directly to the timer value. That was out of line with `docs/NAMING.md` line
208, which fixes the form as

```
CINEMATIC_<ENTITY>[_<ACTION|STATE>][_<DIRECTION>]_<frame index, decimal, 0-based>
```

and out of line with the two sibling stages, which already named the same art
`CINEMATIC_PRISON_SHOT_HIT_BURST_<DIR>_0..4` and
`CINEMATIC_CAPSULE_SHOT_HIT_BURST_<DIR>_0..4`. So the CAVES names were
renumbered to `_0.._5`; frame n is the picture drawn at timer value n+1.

The probe now enforces this rather than trusting it. It reports, per ladder,
the offset between each named index and the timer value that draws it, and
**fails if the whole tree does not agree on one offset**:

```
index base: every named frame is the timer value shifted by ['-1']
```

Before the renumber that line read `['-1', '0']  ** not one convention **` and
the probe exited 1.

The siblings were also short a frame. PRISON and CAPSULE each named `_0.._4`
and left the sixth picture — the residue that frees the slot — as a bare
`CINEMATIC_<index>` in every branch. Those four are now `_5`, so all six
families run 0..5 with no hole.

## The correction this forced

msdos' v=1 picture was already named — **wrongly**:

```
src/levels/dos_1992/CAVES.asm:825    CINEMATIC_CAVES_DRAW_HERO_IDLE_LEFT_1  EQU 0x290A
src/levels/dos_1992/CAVES.asm:11762  CAVES_DRAW_HERO_IDLE_LEFT_1:
src/levels/dos_1992/CAVES.asm:11763      video offset=CINEMATIC_CAVES_DRAW_HERO_IDLE_LEFT_1, ...
```

It is a 2.0 x 5.0 six-leaf spark whose `canonical_md5` equals amiga's
`CINEMATIC_773`, and its only reference in the whole tree is the `jle [0x13],
0x01` arm of the impact ladder. It is the first frame of the rightward impact
flash, not a hero idle pose. There is no other `CAVES_DRAW_HERO_IDLE_*` name in
any branch, so it was not part of a family either — a one-off mislabel, msdos
only. Corrected in the same commit as the evidence, per the standing rule.

## Why the names are branch-scoped

The *art* agrees across ports but the *symbols* do not. In CAVES, amiga's impact
frames are `CINEMATIC_773..778` / `816..821`; msdos' are `CINEMATIC_799..803` /
`840..845`. Both branches also define a `CINEMATIC_774`, and msdos' 774 is
unrelated art. CAPSULE diverges the same way (amiga `497`/`512`, msdos
`643`/`659`); only PRISON happens to use the same numbers in every branch. A global rename keyed on the amiga number would therefore stamp
an impact-frame name onto an msdos picture that is not one — the exact failure
that had to be reverted in `36139804` (see `notes/dispatch-ladders/README.md`).
So each branch gets its own proposal table and
`tools/apply_branch_scoped_names.py` is used **without** `--agreeing`.

The byte gate cannot see any of this: a rename moves no bytes, so `make test`
stays 29/29 whether the name is right or wrong. The check that can see it is
re-running `impact_ladder.py` after the rename and reading the mapping back out
of the ladder, which is why the probe derives rather than transcribes.

## Where the family stem comes from

Not from the dispatch label. PRISON's rightward dispatch is `LABEL_3BB3`, which
offers nothing, and CAPSULE's is `CAPSULE_SHOT_STATE_FRAME_DISPATCH_RIGHT`
while its constants are `CINEMATIC_CAPSULE_SHOT_HIT_BURST_RIGHT_*` — a
label-derived stem would have opened a second family beside the real one. So
`--proposals` takes the stem from the frames **already named for the same
(stage, direction) in any branch**, and falls back to the label only when no
branch has named any frame of that ladder. If two branches disagree on the
stem it proposes nothing there and says so, rather than picking (#0120).

That is what lets `cartridge_1992`, which has no extracted ROM and so gets no
geometry check at all, still be named correctly: its ladder is evaluated from
its own source, and the stem comes from its amiga and msdos siblings.
