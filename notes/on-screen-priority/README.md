# Which unnamed art does a player actually see?

Every other probe in `notes/` ranks still-numbered art by **structure**: how it
is anchored, what family it sits in, whether the other port holds the same tree,
how many leaves it has. None of them can say whether a human ever looks at it.

A constant drawn in one frame of one cutscene and a constant on screen for
three quarters of a stage are worth very different amounts of naming effort, and
until `tools/vm-debugger/` existed there was no way to tell them apart, because
telling them apart requires **running the game**.

| file | question it answers | command |
| --- | --- | --- |
| `seen_unnamed.mjs` | Of the constants still numbered, which does a player see, for how many frames, drawn by which routine, anchored how? | see below |

    python3 tools/vm-debugger/server.py --dump dos_1992 PRISON > /tmp/n.json
    node notes/on-screen-priority/seen_unnamed.mjs --names /tmp/n.json \
        --romset ../another-world-archaeology/tmp/output/msdos/romset \
        --stage-id 3 --frames 400 --top 20

`--named` ranks the already-named constants instead, as a control: if the named
list is not dominated by the same kind of long-lived, variable-anchored art, the
ranking is measuring something other than screen time.

## What the columns are

**frames / %run** — distinct frames in which the constant was drawn at least
once, out of the frames actually executed. This is the ranking.

**first-last** — the frame span it appears across. A narrow span at a high
count is a continuous animation; a wide span at a low count is something
intermittent, and the two want different naming treatment.

**anchor** — how `x`, `y` and `zoom` reached the `video` op: `var` when the
operand was a variable index, `imm` when it was a literal in the bytecode. This
is recovered from the same opcode bits `awvm/src/disasm.rs` tests, recorded onto
the draw record by `static/vm.js`. It is the one fact about a draw that cannot
be recovered afterwards from the record, which is why the VM stores it. A
`var`-anchored draw is something whose position is computed elsewhere — a
moving object; an `imm`-anchored one is furniture.

**routine** — the nearest label at or before the drawing pc, the debugger's own
`routineAt()`. `LABEL_<hex>` here means the *routine* is unnamed too, and those
rows are the best value in the table: one routine name and one family name
bought by the same investigation.

## The limitation, which is the whole caveat

The VM enters the stage with no variables carried in from a real playthrough. A
scene gated on a variable an earlier stage set will not run, and its art will
not appear in this list. So:

> **Absence from this list is not evidence. Presence is.**

Never read a zero here as "nothing looks at this". Read it as "this run did not
reach it".

The five copy-protection variables **are** seeded, by `setupPart` — without them
LAKE, CAVES, ENDING and PASSCODE delete all 64 threads on entry and draw
nothing whatever, which is not a limitation worth preserving in a debugger.
`--cold` turns the seeding off and reproduces the blank; `VM.PROTECTION_PASS` in
`tools/vm-debugger/static/vm.js` says which variables and why.

## The measurement as of 2026-09-23

    dos_1992/PRISON: 400 frames run over 1 checkpoint(s),
                     39 still-numbered constant(s) drawn,
                     1667 constant-frames of screen time

    284  71%  CINEMATIC_035  0x23B4  116-399  x:var y:var z:imm  LABEL_795A
    140  35%  CINEMATIC_241  0xC4DE  150-399  x:var y:var z:imm  DRAW_CIN_241
    140  35%  CINEMATIC_240  0xC4FA  150-399  x:var y:var z:imm  DRAW_CIN_240
    132  33%  CINEMATIC_017  0x952A  118-394  x:var y:var z:imm  LABEL_1D82
    124  31%  CINEMATIC_016  0x950E  117-399  x:var y:var z:imm  LABEL_1D6A

Of the 39, 32 have a `var` x and 31 have both coordinates from variables; 7 are
`imm/imm` furniture.

**The control matters more than that tally.** `--named` ranks the same stage's
*named* constants, and its top row --
`CINEMATIC_PRISON_CAGE_BARS_TILT_ZERO` at 0x0EDA -- is on screen for 96 frames,
24% of the run. It is also `x:var y:var`. So "the unnamed art moves" is **not**
a finding: essentially everything PRISON draws is variable-anchored, and a probe
that reported the anchor mix as a discovery would be reporting the stage's
drawing style back to itself.

What the control does establish is the gap. The most-seen *named* constant in
PRISON is on screen 96 frames. `CINEMATIC_035` is on screen **284**, nearly
three times as long as anything that has a name. The single most visible object
in the stage is anonymous, and its drawing routine, `LABEL_795A`, is anonymous
too.

## One checkpoint shows one room, so sweep them

A stage is entered at a checkpoint (`../stage-entry/`), and CAVES has nine of
them -- nine different rooms. Asking about one is asking about one room, and it
reads as "this stage has almost no unnamed art left" when the truth is "this
room does not". `--sweep` runs every checkpoint the stage has and merges:

| stage | first checkpoint only | every checkpoint |
| --- | --- | --- |
| PRISON | 39 | 39 (it has one) |
| CAVES | 5 | **34** |
| CAPSULE | 13 | **49** |

That is 122 still-numbered constants a player actually sees across the three
stages that have any, against the 57 a single-checkpoint run reports. **Use
`--sweep` before concluding a stage is done.**
