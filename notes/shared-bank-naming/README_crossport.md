# Does a name mean the same picture on both ports?

`crossport_art_identity.py` answers it by **rendering**, and the reason it
does is a mistake worth keeping.

## The invalid test that came first

The obvious check is: read each port's polygon EQU offset, seek into that
stage's cinematic resource dump, compare the bytes. That is what this probe
did first, and it reported **968 names** as pointing at different art across
amiga and msdos — including most of LAKE, a stage that has had more
verification than any other.

It was wrong. The offsets index the stage slab the renderer assembles, not the
layout of the standalone `resource-0x??.bin` dump, so for most stages the
comparison reads unrelated bytes. It agreed for TANK, which is exactly what
made it look sound.

One render refuted it: amiga's `CINEMATIC_BACKGROUND_BEAST_BODY` at 0x73F6 and
msdos's at 0x5FE6 are the same beast, pixel for pixel.

**A resource differing in size does not mean a given polygon differs.** TANK's
cinematic resource is 24,152 bytes on amiga and 29,212 on msdos, and all 48
`CAPSULE_DOME_CLOSING_F<n>` constants sit at the same offset with the same
art on both.

## The test that works

Two SVGs of the same art are byte-identical once the port name is normalised
out — same path data, same coordinates, same colours. So the comparator is the
renderer's own output, and the answer is exact rather than a similarity score.

```bash
cd another-world-archaeology
R=~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons
for p in amiga msdos; do
  $R --port $p --stage 2 --romset tmp/output/$p/romset \
     --bank cinematic --out /tmp/art/$p/LAKE --palette 5
done
cd ../another-world-source-reconstruction
python3 notes/shared-bank-naming/crossport_art_identity.py \
    --svg-root /tmp/art --stage LAKE --stage TANK
```

Stage numbers: CODE_WHEEL 0, INTRO 1, LAKE 2, PRISON 3, CAVES 4, TANK 5,
CAPSULE 6, ENDING 7, PASSCODE 8. Renders are a large regenerable corpus and
are not committed; this recipe is.

## Result

| stage | names on both ports | same art | differ |
|---|---:|---:|---:|
| LAKE | 668 | 651 | **17** |
| TANK | 48 | 48 | 0 |

TANK's 48 of 48 independently confirm the dome names applied the same day by
draw-position pairing.

## The 17, found and deliberately not fixed

All hero locomotion. On amiga each is a striding figure of 6–10 paths; on
msdos the same name is a single featureless slab, 1 path, and the offsets sit
10 bytes apart in the last ~170 bytes of the bank.

Known: the names predate this session; amiga's hero art has **no matching
render anywhere** in msdos's LAKE bank, so msdos is not merely holding it
elsewhere; and the shared video2 bank does hold lower-body poses drawn as
overlays after a sprite dispatcher.

Not known: whether msdos composes its hero differently — shared lower body
plus a small per-stage piece, which those 10-byte records could be — or
whether 17 msdos names are simply on the wrong constants.

**Nothing was renamed.** A wrong name is worse than a number, and that cuts
both ways: demoting 17 names that turn out to be right would be the same
error in the other direction.
