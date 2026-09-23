# Which stages run from a cold entry, and what stops the rest

**Half the game was unreachable in the debugger, and the reason on record was
wrong.** LAKE, CAVES, CAPSULE and ENDING ran their entry point in
`tools/vm-debugger/` and drew nothing whatsoever, for thousands of frames, in
both priority ports. CAVES and CAPSULE are the two least-named stages in the
project, so this was not a corner: it was the tool being blind exactly where it
was most needed.

| file | question it answers | command |
| --- | --- | --- |
| `entry_state.mjs` | Why does this stage draw nothing, and what unlocks it? | below |

    python3 tools/vm-debugger/server.py --dump dos_1992 CAVES > /tmp/n.json
    node notes/stage-entry/entry_state.mjs --names /tmp/n.json \
        --romset ../another-world-archaeology/tmp/output/msdos/romset \
        --stage-id 4 --frames 600 [--screens]

## The measurement, dos_1992, 600 frames

    stage      cold                     seeded
    LAKE         0 painted,    0 draws    101 painted,  1622 draws
    CAVES        0 painted,    0 draws    595 painted,  1999 draws
    CAPSULE      0 painted,    0 draws    599 painted,  3241 draws
    ENDING       0 painted,    0 draws    344 painted,  1212 draws

INTRO, PRISON and TANK open on a cutscene and are identical either way.

"Seeded" means **a checkpoint's whole register table**, not the five variables
the protection check reads. Those five make a stage draw; they do not make it
play, and the difference is measurable -- CAPSULE reaches 12.5% of the screen
on the five and 68.5% on checkpoint 12's forty-nine. See "A checkpoint is not
five variables" below.

## The explanation that was on record, and the two measurements that killed it

It said `CAVES_SCREEN_ENTRY_DISPATCH` switches on `SCREEN_NUM` (`0x67`), and a
stage entered cold has every variable at zero, so the dispatch falls through.
It is a reasonable-sounding story and it is wrong.

**`--screens` sweeps `SCREEN_NUM` over 28 values, 0x00 to 0xC0, with no
seeding. None of them makes CAVES draw anything.**

**The thread census is the other half, and it is the decisive one.** CAVES ends
a cold run with **zero live threads**. A dispatch that falls through leaves the
thread running; something that ends with no thread at all has had its threads
*deleted*. That points at one instruction, and there is exactly one that does
it:

    LABEL_00B3:                          ; the failure path
        deleteChannels first=0x00, last=0x3F

reached from `LIKELY_A_COPY_PROTECTION_MECHANISM`, which reads five variables:

    and [0xBC], 0x0010   je [0xBC], 0x00 -> fail     bit 4 of 0xBC set
    and [0xF8], 0x0080   je [0xF8], 0x00 -> fail     bit 7 of 0xC6 set
    and [0xF8], 0x003C   jne [0xF8], 0x14 -> fail    0xE4 & 0x3C == 0x14
    jne [0xF2], 0x0FA0 -> fail                       0xF2 == 0x0FA0
    jne [COPY_PROTECT_TOKEN], 0x21 -> fail           0xDC == 0x21

Entered cold every one is zero, so it always fails, and it **latches**: the
failure path writes `0xF2 = 0x1770`, not the `0x0FA0` it wants, so a second
attempt fails too. The routine appears in CAVES, ENDING and PRISON in both
priority ports, and in msdos's PASSCODE.

`VM.PROTECTION_PASS` in `tools/vm-debugger/static/vm.js` holds the passing
values and seeds them by default; the debugger's `cold boot` checkbox turns the
seeding off and reproduces the blank, which is what `--cold` does here and in
`../on-screen-priority/`.

## Why the refuted explanation is a mode rather than a deleted sentence

`--screens` exists only to refute a hypothesis nobody holds any more. It stays
because a corrected sentence tells the next person what to believe, and a
command tells them how to check. The story was plausible, it survived being
written into a README, and what removed it was one census of live threads
costing a second to run.

## A checkpoint is not five variables

The five copy-protection variables were derived here from the listing, and they
are right as far as they go: the reference's own table for the intro,
`LEVEL_00`, is those five plus `0x54`, and nothing else. Every other level's
table has **49** registers -- hero position, screen number, the scroll anchor,
the room's own state -- because a checkpoint is what a real playthrough would
have left behind, and a stage missing most of that reaches its entry point and
then behaves like a machine missing most of its memory.

`tools/vm-debugger/static/checkpoints.json` holds all sixteen, transcribed from
the local Rust engine at `../../../another-world-suite/engine` by
`tools/vm-debugger/tools/extract_checkpoints.py` -- generated, not typed,
because 16 x 49 hand-copied numbers is 784 chances to be wrong in a way nothing
would catch. The parts they cover are this project's stage ids:

| part | stage | checkpoints |
| --- | --- | --- |
| 1 | INTRO | 0 |
| 2 | LAKE | 1 |
| 3 | PRISON | 2 |
| 4 | CAVES | 3, 4, 5, 6, 7, 8, 9, 10, 11 |
| 5 | TANK | 14 |
| 6 | CAPSULE | 12, 13, 15 |

Registers `0x00..0x3F` are zeroed before a table is applied and `0x40..0xFF`
are left alone, exactly as the reference's `restart_level` does: a table is a
delta, not a whole machine state.

CAVES' nine are nine different rooms, and it shows:

    checkpoint  3:  2.5% of the screen at its fullest   (a hang loop)
    checkpoint  5: 57.3%
    checkpoint  6: 59.2%
    checkpoint  9:  6.1%

The first one listed is the default, which is faithful to the reference's
ordering and is **not** the one that shows the most. Pick one in the debugger's
header, or use `../on-screen-priority/ --sweep` to ask about all of them at
once.

## What this does not fix

Seeding the protection variables is not the same as arriving from a real
playthrough. A scene gated on a variable an earlier stage set still will not
run. **Absence from a run here is not evidence; presence is.**
