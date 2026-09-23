# What sits together in the bank

## What question this directory answers

Every other queue in these notes groups art by what **draws** it -- a routine's
run of frames, a dispatcher's slots, a screen's backdrop stack. That misses any
family whose frames each get their own one-line routine, because no routine ever
holds more than one of them.

The bank groups them anyway. Art for one animation is laid down together, so a
stretch of consecutive still-numbered constants between two named ones is a
family the naming has not reached.

    python3 notes/bank-locality/offset_runs.py
    python3 notes/bank-locality/offset_runs.py --port msdos --stage CAPSULE
    python3 notes/bank-locality/offset_runs.py --min-run 8

Per run: the offsets, the stride if it is constant, and each member's extent and
leaf count -- so a size ladder or a symmetric pair shows up in the listing.

## What it found

**PRISON's longest run**, fifteen constants at `0x2190 + 0x14k`, is the cage's
chain at fifteen tilt angles: one dispatch on a **signed** `[0x06]` from +7 to
-7, widths symmetric about zero to the pixel, the lean reversing, the foot
fixed. Fifteen one-line routines, which is why no routine-level queue had ever
put them side by side.
See `../render-and-name/proposals_chahi_amiga_1991__PRISON_cage_chain.md`.

**CAPSULE's longest**, `0xA8E6..0xAC82`, is two families end to end. Its first
four thin out monotonically -- 28, 18, 12 and 3 leaves across 123.5, 119.5,
100.5 and 11.5 pixels of spread -- and are the debris settling after
`CAPSULE_DEBRIS_RAIN_F5`. Its other eight are a round mass with a figure on it
that no reading yet accounts for, and they were left numbered with that said out
loud.

That split is the point of the caveat below.

## Two tells worth carrying

- **An unvarying stride is an array.** Fifteen constants exactly 0x14 apart were
  emitted in one go; a run with nine different steps is just neighbours.
- **Read the sign.** `0xFFFA` is -6, and a dispatch running
  `0, 1, ... 6, 0xFFFF, 0xFFFE, ...` is a range centred on zero, not a jump to
  65535. `../coordinate-signedness/` established the same for `video` operands.

## What a run is not

A family. Adjacency is the game's memory layout, not its meaning: a run can hold
two families end to end, or one family plus whatever the assembler happened to
put beside it. It says where to look, and in what company.
