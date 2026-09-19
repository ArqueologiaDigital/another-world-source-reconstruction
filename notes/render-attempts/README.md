# What has been rendered, and what it settled

Rendering is the only route left for most of the unnamed polygon pool — the
derivation rules in `../sole-named-drawer/` are worth about a sixth of what
they can see, and `../crossport-transfer/` is spent. So the cost that matters
now is **re-rendering something someone already looked at**. This is the
record of that, kept so the next pass starts from the frames nobody has
resolved rather than the ones that keep looking promising.

## How a target is chosen

A run of unnamed `CINEMATIC_<index>` constants drawn by **one** routine and
by nothing else, at one anchor where possible, largest first:

    python3 notes/sole-named-drawer/nameable_from_drawer.py --animations
    # and for runs whose routine is itself unnamed, the ad-hoc scan in the
    # 2026-09-19/20 session log — largest exclusive runs per stage

**Exclude actor-slot draws first.** `notes/actor_slot.py` resolves the
aliases; six of the largest amiga runs in the big three are `[BUDDY_X],
[BUDDY_Y]`, which is `[0x07],[0x08]`, which is #0138. Rendering them is not
wasted — seeing the art is fine — but no name can come of it, so they are
not targets.

## Rendered and resolved

| run | what it turned out to be |
|---|---|
| amiga/CAVES 438..447, `LABEL_26EE` | **Named.** A blue burst, 15x14 growing to 88x93 and dispersing to 74x67, drawn at the hero's x and at the exact y the concurrent landing routine sets. `CINEMATIC_CAVES_LANDING_SPLASH_F0..F9`, and the routine `CAVES_HERO_LANDING_SPLASH`. |
| msdos/TANK 106..111, `LABEL_0692` | **Routine named.** A white core expanding inside a tan rim under sound 0x5B on all four channels; installed after a delay and falling into `TANK_ARENA_ATTACK_FINAL_HIT_UNLESS_ESCAPED`. `TANK_ARENA_ATTACK_BLAST_SEQUENCE`. Its constants are NOT named: the set mixes the growing flash with 112, 114, 115 and 118 reused as layers, which is not one indexed family. |

## Rendered and NOT resolved

These render cleanly. The picture simply does not say what the thing is, and
the surrounding code does not either. Listed so they are not re-rendered in
hope.

| run | what the render shows | why it stops there |
|---|---|---|
| amiga/CAVES 514..524, 857..867 (`LABEL_3CD9`, `LABEL_3813`) | one flesh-coloured limb, 16x2 to 7x6, sweeping out and back; the two runs are the same animation mirrored, ten of ten steps opposite | which limb, and whether it is a limb at all. See `../hero-direction-machine/layer_colour_census.py` |
| amiga/CAVES 480..490 (`LABEL_3BA3`) | a symmetric pair of the same flesh-coloured marks, overhead sweep | same |
| amiga/CAVES 213..222 (`LABEL_0885`) | grey field with black cracks spreading, plus bright blue-white blobs at 213, 215, 218, 219 | **Not** the laser impacts, tested and excluded: the run measures 99x74 to 186x128 with 5 to 15 leaves and the whole `CINEMATIC_CAVES_LASER_IMPACT_*` family measures 54x68 down to 23x7, sharing no md5 with it. So it is a large cracked surface with flashes, drawn at `[0xED],[0xEE]` which its installer sets to x=160, under sounds 0x59 and 0x6F. What breaks, and what the flashes are, is still open. |
| amiga/CAVES 301..309 (`LABEL_203D`) | horizontal blue and grey bands, wide then narrowing then broken | drawn at y=0xA6 fixed with x from `[0x3D]`; a band is not a subject |
| amiga/PRISON 540..548 (`DRAW_CIN_540_543_WITH_SFX_57`) | dark purple curved bars, then a large purple fill, then bars again, under sound 0x57 | drawn at `[0x1A],[0x1B]`, which the installer sets to the same point as CINEMATIC_081/082/083 — so it is a layer over that scene element, and the shape alone settles nothing |
| amiga/INTRO 112, 184, 430; amiga/TANK 100 | 1x6, 29x14, 16x9 and 6x12 specks; two are teal diagonal streaks | these gate the last ~18 unnamed routines in INTRO and TANK, and at that size a render is a handful of magnified pixels |

## The standing lesson

Six of the seven runs above rendered *legibly* and still could not be named.
Legibility is not identification: `CAVES_LANDING_SPLASH` was nameable because
the **code** placed it — same x as the hero, same y as the landing, running
concurrently with a routine already named from its own evidence — not because
a blue burst looks like anything in particular. Render to see; read the
scheduling to name.
