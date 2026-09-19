# INTRO's keypad frames: three names on the wrong art (#0107)

| script | question it answers | run it |
|---|---|---|
| `swap_unified_amiga_arms.py` | Can the amiga keypad-frame swap be applied inside the unified tree's `.if BRANCH` arms without touching any other branch — and does every affected line actually sit in a branch arm? | `python3 notes/intro-keypad-frames/swap_unified_amiga_arms.py` (dry run) · `… --apply` |

It refuses to run on an already-swapped tree, because it is a *swap*: a second
run would put the names back on the wrong constants.

## The finding

amiga INTRO carried `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1`, `_F2` and `_F4`
on offsets 0x446C, 0x44B0 and 0x06A8. Measured with
`another-world-archaeology/tools/polygon_extent.py --stage 1 --port amiga`:

| offset | carried | extent | leaves |
|---|---|---|---|
| 0x446C | `..._F1` | 153 × 137 | 4 |
| 0x44B0 | `..._F2` | 153 × 87 | 4 |
| 0x06A8 | `..._F4` | **0 × 1** | **1** |

A hand is not a single point. dos's five keypad frames are at 0x1DFA, 0x1E82,
0x1F0E, 0x1C72 and 0x1CF6, and `crossport_polygon_map.py --stage INTRO --equ
<name>` maps each to amiga at **delta +0x000** — the same offset, so the same
art. On amiga those five measure 188×214, 178×209, 182×208, 188×216 and
192×218: one animation at one scale. Two of them, `_F3` (0x1F0E) and `_F5`
(0x1CF6), already carried the right name.

And amiga draws the other three, consecutively at one anchor
(`chahi_amiga_1991/INTRO.asm:3621-3630`):

```
	video offset=CINEMATIC_116,                              x=[0x01], y=[0x02]
	video offset=CINEMATIC_117,                              x=[0x01], y=[0x02]
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3,   x=[0x01], y=[0x02]
	video offset=CINEMATIC_119,                              x=[0x01], y=[0x02]
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5,   x=[0x01], y=[0x02]
```

F1, F2, F3, F4, F5 in draw order, with three of the five unnamed and their
names sitting on neighbouring constants instead. This is NAMING.md §2's
"320 of the 327 divergences … are within 8 indices" in its smallest form.

## The swap

| offset | was | is |
|---|---|---|
| 0x1DFA | `CINEMATIC_116` | `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1` |
| 0x1E82 | `CINEMATIC_117` | `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F2` |
| 0x1C72 | `CINEMATIC_119` | `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F4` |
| 0x446C | `..._F1` | `CINEMATIC_121` |
| 0x44B0 | `..._F2` | `CINEMATIC_122` |
| 0x06A8 | `..._F4` | `CINEMATIC_124` |

The three numeric names are the emitter's **own amiga indices**, recovered from
commit `f68797db`, not invented: `CINEMATIC_<n>` means "the nth polygon this
port's bytecode references", so it is specific to an offset and cannot be
reassigned to a different one.

19 references in `chahi_amiga_1991/INTRO.asm` and 19 in the amiga arms of the
unified chunks, **with zero occurrences in an unconditional region** — which is
the number the script exists to report, because a swap in an unconditional line
would change the name for every branch.

## What it cost, and the tool that should have been used

Two names applied earlier the same day fell with this. `DRAW_CIN_130_*` had been
renamed `INTRO_KEYPAD_HANDS_{STEP,HOLD}_LOOP` on the strength of the constant it
draws being called a hand. It draws the 1-leaf point, twice, at y=16 and y=18,
with x seeded 8 apart at 122 and 130 and stepped +2/−2 over five iterations so
the pair meets at 126 and crosses, three frames held per step. They are now
`INTRO_DOT_PAIR_CROSSING_SWEEP_{CYCLE_INIT,STEP_LOOP,HOLD_LOOP}`.

**`another-world-archaeology/tools/apply_branch_scoped_names.py` is the proper
home for this kind of rename** and was not noticed until afterwards; its
docstring makes the same argument about `.if BRANCH` arms, measured over all
1,116 divergent draw sites in INTRO. This script is kept only as the record of
what was actually run, in the same spirit as
`archaeology/tools/big_stage_family_probes/`. Reach for that tool first.
