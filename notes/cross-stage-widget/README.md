# The same drawing in two stages of one port

## What question this directory answers

Which still-numbered `CINEMATIC_<n>` in one stage is **byte-for-byte the same
polygon tree** as something already named in another stage of the same port?

Each stage has its own 0x10000 bank, so a widget the game reuses -- a charge
meter, a readout bar, a burst -- is *copied into* every bank that shows it, at
its own offset, under its own constant number. Nothing in the disassembly links
the copies. The art does.

    python3 notes/cross-stage-widget/same_widget.py --port amiga
    python3 notes/cross-stage-widget/same_widget.py --port amiga --pairs PRISON:CAPSULE
    python3 notes/cross-stage-widget/same_widget.py --port amiga \
        --show PRISON:CINEMATIC_361,CINEMATIC_362

The first two match; the third is the measurement table a proposal quotes
(offset, extent, leaf count, md5) with no matching at all.

## The signal being read

`canonical_md5(parse_polygon_tree(slab, offset))` where

    slab = rom[stage * 0x10000 : (stage + 1) * 0x10000]

of `tmp/output/<port>/romset/cinematic.rom` in the archaeology repo. Equal md5
means every header byte and every vertex is equal.

It is **colour-blind** -- `notes/cross-port-art/colour_blind_hashes.py` found
one hash held by ten distinct one-path INTRO marks. A match on a one- or
two-leaf shape is therefore weak on its own and needs the draw site to back it;
a match on a four-leaf 4x3 bar is not.

The extent column is `polygon_extent.extent`, the polygon extent, **not** the
drawn one. A leaf whose header bbox is 0 or 1 wide is inflated to two pixels by
the rasteriser, so the renderer's picture of a thin bar is wider than this
number by up to 2 px per such leaf. Both are correct measurements of different
things; quote this one and say so.

## What a match licenses, and what it does not

**The words, not the symbol.** `docs/NAMING.md` §1 and #0107 both say a name
describes what the constant is *in its stage*, and the stage-prefixed
convention makes that explicit: PRISON's copy of CAPSULE's meter is
`CINEMATIC_PRISON_SEGMENT_BAR_F0`, not CAPSULE's name pasted across.

**Not the whole family.** On 2026-09-23 this found five of an eight-constant
widget identical between amiga PRISON and amiga CAPSULE, and three not: the
four bar frames share F0 but PRISON redraws F1, F2 and F3 -- which is what a
bar whose lit segments mean something stage-specific would do. Five identities
settled *this is that widget*; the play order settled the other three. A run of
identities is evidence about the widget. Each frame still has to be placed by
the routine that draws it.

**And a match can indict a name rather than earn one.** The same run reported

    CAPSULE  CINEMATIC_384  0x875A  ==  PRISON  CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0

on a 26.0x22.0 three-leaf tree -- while msdos's constant of that same name is
459.0x232.5 in **54** leaves. A backdrop layer and a 26-pixel mark cannot be
the same thing, and they are not: the name was earned on msdos's
`CAPSULE_SCREEN_6A_BACKDROP_DRAW` and had reached amiga's constant by index.
See `../capsule-6a-misname/`.

## The first run, in full

`--port amiga --pairs PRISON:CAPSULE`, 2026-09-23, 15 identities. Eight became
names in the same session (the widget batch in `../render-and-name/`), one
became a correction, and the rest are a queue:

| numbered | in | is the same drawing as | in |
|---|---|---|---|
| 200, 201, 202, 204 | PRISON | `CINEMATIC_SHIELD_DEPLOY_PHASE_3, _2, _0, _1` | CAPSULE |
| 385, 386 | PRISON | `CINEMATIC_CAPSULE_CHARGE_GLOW_F2, F3` | CAPSULE |
| 384 | PRISON | (the 6A misname -- see above) | CAPSULE |
| 452 | PRISON | `CINEMATIC_CAPSULE_SCREEN_6E_BACKDROP_LAYER_0` | CAPSULE |
| 514, 515 | PRISON | `CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_{RIGHT,LEFT}_4` | CAPSULE |
| 090, 538 | CAPSULE | `CINEMATIC_PRISON_SHIELD_DECAY_PHASE_0_CASE_01` **and** `..._PHASE_1_CASE_01` | PRISON |
| 513 | CAPSULE | `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT` | PRISON |

090 and 538 are the case #0120 exists for: one md5, two earned names, nothing
to choose between them. The probe reports both rather than picking, and they
stay numbered until a draw site separates them.

513 is the other refusal: `0.0x1.0`, **one leaf**. A single-point tree is the
weakest possible identity and the colour-blindness note applies at full force.

## `--min-leaf`, because one-leaf matches are mostly noise

The full amiga scan returns 154 identities and most of them are one hash,
`afafd0dda5fb`: a 0.0x1.0 single point, held by `DRIFTING_PARTICLE_0..3`,
`HOLO_CONSOLE_DOT_RISE_FAST`, `LAB_AUTH_DOT`, `LAB_DOOR_SCENE_LAMP`,
`DROPLET_FALL_TRAIL` and half a dozen more. Every pairing of those with every
numbered dot in another stage is reported, and none of it is a name.

`--min-leaf 3` cuts it to a queue a person can read. What survives is the real
work: on 2026-09-23 the six-frame `CAVES_CREATURE_WALK_RIGHT_F0..F5`, held
unnamed by msdos CAPSULE as 708..713, went in on one such row.

## `--hash`

    python3 notes/cross-stage-widget/same_widget.py --port amiga --hash 816e097d250f

Every constant in the port holding one exact drawing, any stage. It is how the
beam-span ladder turned out to be the same art in PRISON, CAVES and CAPSULE, and
how a family's copies are found once one member has been identified anywhere.
