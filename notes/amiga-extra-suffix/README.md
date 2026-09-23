# `_AMIGA_EXTRA` is a collision record, not a name

## What the suffix actually means

`another-world-archaeology/tools/apply_tree_canonical_renames.py:157` says it
in its own comment:

```
# For each collision target T, the amiga polygon currently named T is
# a port-exclusive survivor (no msdos counterpart with this name). To
# free up the slot, rename the survivor away to T_AMIGA_EXTRA<N>.
# Then the main rename can proceed cleanly.
```

So when a cross-port transfer wanted a name that amiga already used, the
**incumbent** was pushed aside and the **incoming** name won, every time,
without either picture being looked at. `_AMIGA_EXTRA` marks the loser of that
coin flip. It is a hex tail with better spelling: it tells you a collision
happened and nothing about what is drawn.

It does not even mean "amiga-only". Of the 19 suffixed constants in
`chahi_amiga_1991`, **17 are defined in `dos_1992` as well**, carrying the same
suffix.

## Which flips went the wrong way

`deconflict_survivors.py` settles each one with `canonical_md5` -- the only
legitimate cross-port bridge (#0107) -- by asking a branch that was not party
to the collision. For INTRO that branch is `gba_2004`.

```
$ python3 notes/amiga-extra-suffix/deconflict_survivors.py
  38 `_AMIGA_EXTRA` constant(s); showing 38
  ...
  verdicts: KEPT 35  NO_ART 1  RESTORE 2
```

| verdict | count | meaning |
|---|---|---|
| `KEPT` | 35 | the un-suffixed name now sits on art another branch independently gives that name to. The displacement was correct. |
| `RESTORE` | 2 | another branch gives the **suffixed constant's own art** the un-suffixed name. The incumbent was right and the incoming name was wrong. |
| `NO_ART` | 1 | `cartridge_1992`, which has no romset at all (#0106). |

The two `RESTORE` rows are the same picture in two branches:

```
  INTRO  chahi_amiga_1991  CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1_AMIGA_EXTRA  0xFB26  b07528b7eb2e  RESTORE  gba_2004
  INTRO  dos_1992          CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1_AMIGA_EXTRA  0xFA98  b07528b7eb2e  RESTORE  gba_2004
```

`gba_2004` calls `b07528b7eb2e` plain `CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1`,
and the render agrees: a seated figure from behind with one arm raised to the
head, between `_F0` (arm out to the right) and `_F2` (arms down). What had
taken the slot in amiga and msdos is a frame of the accelerator-tunnel pulse
and is not a person at all -- see `notes/render-and-name/proposals_*__INTRO_pulse.md`.

## What the 35 `KEPT` rows still owe

`KEPT` clears the *displacement*, not the *label*. Each of those 35 constants
is a picture that never earned its base word; it only ever collided with
something that did. Whether `EXPERIMENT_LIGHTNING` or `LIFT_DOORS_OPENING`
still describes it has to be settled by sight, one at a time. Counted as named
by `asset_naming_share.py`, they are 35 assets whose name is one render away
from being either confirmed or corrected.

## The gba slab is calibrated, not assumed

`gba_usa/romset/cinematic.rom` is two 0x10000 slabs and the stage they hold is
not the stage index: **INTRO is slab 0**. The probe never assumes this. It
tries every slab and keeps the one agreeing with amiga on the most
identically-named, identically-valued constants, needing at least 20
agreements and 3x the runner-up:

```
$ python3 notes/amiga-extra-suffix/deconflict_survivors.py --calibration
  INTRO        [67, 0]  ->  slab 0
  LAKE         [0, 2]  ->  none (gba contributes no art)
  ... every other stage: none
```

67 against 0 is the whole basis for trusting gba's vote on INTRO. Outside
INTRO gba contributes nothing, so a `RESTORE` can only ever be found there
until more of its romset is unpacked.

## Run it

```
python3 notes/amiga-extra-suffix/deconflict_survivors.py
python3 notes/amiga-extra-suffix/deconflict_survivors.py --verdict RESTORE
python3 notes/amiga-extra-suffix/deconflict_survivors.py --calibration
```

Needs `another-world-archaeology/tmp/output/<port>/romset/cinematic.rom` from
`tools/aw_unpacker.py`. The signal read is
`canonical_md5(parse_polygon_tree(slab, offset))` per branch; equal hash means
the same drawing, and that is the only claim being made.
