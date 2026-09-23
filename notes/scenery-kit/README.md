# Counting placements, because coordinates cannot be names

## What question this directory answers

`../remaining-art/by_anchor.py` sorts the still-numbered art by how it is drawn
and finds the largest class -- **1,152 distinct pictures drawn at fixed literal
`x, y`** -- has no method. It cannot be named from its coordinates
(`docs/NAMING.md` §1), and there is no actor slot to hang it on.

The method is a counting one:

    one placement by one routine, at 160,100  ->  a backdrop layer, named from its screen
    many placements by many routines          ->  a kit piece, named from its construction

    python3 notes/scenery-kit/kit_pieces.py
    python3 notes/scenery-kit/kit_pieces.py --min-placements 3 --min-routines 2

Per candidate: leaf count, extent, placements, and how many routines place it.
A picture whose every draw is a fixed literal one, repeated across routines, is
scenery the stage dresses with, and what separates one from another is size --
which is measured, so it can carry an index.

## What it does not do

Name anything. Same leaf count and neighbouring sizes makes two constants
*candidates* to be one family; whether they are wants a composite and the eye.
The probe narrows 1,152 to the handful where that is worth doing, and says
which to look at together.

## Runs of 2026-09-23

With the strict default, after the stalactite kit had been named, amiga returns
7. Lowered to three placements in two routines it returns **26**, of which ten
are CAVES one-leaf shapes; five of those ten were named the same day
(`../render-and-name/proposals_chahi_amiga_1991__CAVES_terrain.md`) and five
were not, because two of them render in the background colour at the one palette
that had been looked at.

The kit this directory was written for was found by hand first:
`CINEMATIC_CAVES_STALACTITE_0..4`, placed **61 times by eighteen routines**,
against `CINEMATIC_747` in the same routine placed once at `160, 100` -- the
backdrop slot. That contrast is the whole rule.

## The tell that decided one of them

`CINEMATIC_437` -- now `CINEMATIC_CAVES_WALL_TILE` -- is placed at `x=179` with
`y = 31, 62, 93`. The interval is exactly its own height. Nothing else in the
kit tiles, and a rectangle repeated at its own height is a wall being built out
of one block.

> A placement list is evidence about a picture even when the coordinates
> themselves can never be part of its name.
