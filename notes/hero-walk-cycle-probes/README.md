# Hero locomotion probes

Evidence behind LAKE's `CINEMATIC_HERO_WALK_LEFT_0..14` and
`CINEMATIC_HERO_RUN_LEFT_WINDUP_0..3` families, and behind the routine renames
that went with them.

| script | question it answers | run it |
|---|---|---|
| `lake_hero_left_locomotion.py` | Is the loop formerly called `HERO_FALL_LEFT_LOOP` a fall, and is the one formerly called `HERO_WALK_LEFT_LOOP` a walk? Exits non-zero if the fall reading turns out to hold after all, so it is also a regression test on the rename. | `python3 notes/hero-walk-cycle-probes/lake_hero_left_locomotion.py` |
| `apply_walk_left_rebase.py` | The re-base itself, kept because it produced the count quoted in the commit: **401** references over **13** LAKE files, and it prints its own file scope. It refuses to run on an already-re-based tree. | `python3 notes/hero-walk-cycle-probes/apply_walk_left_rebase.py` |

The scope line in that script is the point of keeping it. The first cut was not
restricted to LAKE and renamed `HERO_WALK_LEFT_LOOP` in PRISON, CAVES and
CAPSULE too — three independent routines this measurement says nothing about,
611 references instead of 401. It now prints how many files it will touch and
asserts that no affected label is defined in a cross-stage `_helpers/` chunk.

## What it found

| | steady loop | burst loop |
|---|---|---|
| frames | 15 | 12 |
| `HERO_X` per frame | −2, twice −3; mean **−2.13** | −5, −7, **−13**, −12, −2, −7, −4, −7 |
| `HERO_Y` writes | 4, **every one `add [HERO_Y], 0x0000`** | none |
| sounds | `play id=0x0051` ×2 | none |
| ends in | its own hold loop | `CINEMATIC_HERO_STOP_LEFT_0..2` |

**A fall moves the actor down the screen.** The loop named for one never writes
`HERO_Y` at all: all four writes are `add [HERO_Y], 0x0000`, which is why a grep
for `HERO_Y` in that routine is misleading and why the probe reports zero and
non-zero writes separately. Fifteen frames at a steady −2 px with two footsteps
is a walk cycle. The other loop is 4.3× faster, starts from a standstill and
decelerates into the stop frames: it is the run, and its first four frames —
which have no `HERO_X` motion at all and are immediately followed by
`CINEMATIC_HERO_RUN_LEFT_0` — are the run's wind-up.

The art agrees. The probe's docstring carries the exact
`awvm-render-polygons` + `montage` commands; the eight entries of the
contiguous 0x28-stride block (0x0A3C … 0x0B54) render as one upright walk
cycle, stride opening to its widest at 0x0AB4 and closing back to a stand at
0x0B54. Nothing is airborne in any frame.

## What changed because of it

`CINEMATIC_HERO_LEFT_PROFILE` + `CINEMATIC_HERO_FALL_LEFT_1..4` +
`CINEMATIC_HERO_RESUME_LEFT_0..9` were one animation split across three
families, with a gap at index 0 that `docs/NAMING.md` §2 forbids. They are now
`CINEMATIC_HERO_WALK_LEFT_0..14`, gap-free, in the order the loop draws them.
The four frames that previously held the `WALK_LEFT` name are
`CINEMATIC_HERO_RUN_LEFT_WINDUP_0..3`.

That also unblocked five msdos routines the 2026-09-14 verifier had downgraded
*for this exact defect* — msdos composites the hero from `COMMON_VIDEO` parts
rather than one polygon per frame, and its stubs now run
`DRAW_HERO_WALK_LEFT_F0` … `F14` with no gap.

## Scope, and what is still wrong

**Left-facing only.** The right-facing mirror has the same shape — the loop at
`HERO_FALL_RIGHT_LOOP` moves `+2` px/frame, writes `HERO_Y` only as
`add [HERO_Y], 0x0000`, and fires the same two `play id=0x0051` footsteps — so
"FALL" is refuted there too. It was **not** renamed, because its fifteen frames
come from four different families rather than three, and five of them are
`CINEMATIC_HERO_LEAP_RIGHT_F0<nn>_BUNDLE` whose index is a `COMMON_VIDEO` bank
index in disguise. Re-basing those means deciding what happens to the
`LEAP_RIGHT` family as a whole, which is entangled with plan item T7 (re-key the
shared bank by offset). Run the probe with `--port msdos` and read
`HERO_FALL_RIGHT_LOOP` by hand to see it.

To re-check the right side quickly:

```bash
awk '/^HERO_FALL_RIGHT_LOOP:/{f=1} f&&/video offset=|\[HERO_X\]|\[HERO_Y\]|play id/{print} \
     f&&/^HERO_STAND_RIGHT_LOOP:/{exit}' src/levels/chahi_amiga_1991/LAKE.asm
```
