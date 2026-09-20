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
| amiga/CAVES 438..447, `LABEL_26EE` | **Named.** A blue burst, 15x14 swelling to 32x33 at F4 and then shrinking away to 8x15, drawn at the hero's x and at the exact y the concurrent landing routine sets. `CINEMATIC_CAVES_LANDING_SPLASH_F0..F9`, and the routine `CAVES_HERO_LANDING_SPLASH`. |
| amiga/CAVES 301..309, `LABEL_203D` | **Named.** Not the bands the magnified thumbnail showed -- specks: 0x1, 1x1, 2x1, 1x2, then 1x4, 0x7, 1x11 elongating downward, then 6x3 and 12x2 flattening, the shape descending y 62..64 to 76..78 in its own frame. Installed on channel 0x04 in the same block as `CAVES_WATERFALL_BACKDROP_HOLD_LOOP`, at fixed y=0xA6 with x alternating between two spots 16px apart. `CINEMATIC_CAVES_WATERFALL_DRIP_F0..F8`, routine `CAVES_WATERFALL_DRIP_LOOP`. |
| msdos/TANK 106..111, `LABEL_0692` | **Routine named.** A white core expanding inside a tan rim under sound 0x5B on all four channels; installed after a delay and falling into `TANK_ARENA_ATTACK_FINAL_HIT_UNLESS_ESCAPED`. `TANK_ARENA_ATTACK_BLAST_SEQUENCE`. Its constants are NOT named: the set mixes the growing flash with 112, 114, 115 and 118 reused as layers, which is not one indexed family. |

## Rendered and NOT resolved

These render cleanly. The picture simply does not say what the thing is, and
the surrounding code does not either. Listed so they are not re-rendered in
hope.

| run | what the render shows | why it stops there |
|---|---|---|
| amiga/CAVES 514..524, 857..867 (`LABEL_3CD9`, `LABEL_3813`) | one flesh-coloured limb, 16x2 to 7x6, sweeping out and back; the two runs are the same animation mirrored, ten of ten steps opposite | which limb, and whether it is a limb at all. See `../hero-direction-machine/layer_colour_census.py` |
| amiga/CAVES 480..490 (`LABEL_3BA3`) | a symmetric pair of the same flesh-coloured marks, overhead sweep | same |
| amiga/CAVES 213..222 (`LABEL_0885`) | grey field with black cracks spreading, plus bright blue-white blobs at 213, 215, 218, 219 | **Not** the laser impacts, tested and excluded: the run measures 43x72 to 104x73 with 5 to 15 leaves and the whole `CINEMATIC_CAVES_LASER_IMPACT_*` family measures 54x68 down to 23x7, sharing no md5 with it. So it is a large cracked surface with flashes, drawn at `[0xED],[0xEE]` which its installer sets to x=160, under sounds 0x59 and 0x6F. What breaks, and what the flashes are, is still open. |

| amiga/PRISON 540..548 (`DRAW_CIN_540_543_WITH_SFX_57`) | measured rather than eyeballed: six near-identical narrow bars, 12 to 18 wide by 49 tall, at ONE spot (541, 543, 545..548), plus two large shapes offset up and right (138x81 at y -73..8, 66x140 at y -113..27) and one 16x32. Every one a SINGLE leaf in colour index 2 alone | narrowed a long way and still open. It is the suspended-cage scene -- the enclosing code calls `PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH` and draws the cage at the same `[0x1A],[0x1B]` -- and the six bar variants track the swing tilt. But colour 2 is **not** in the cage (`{0,5,6,9}`) and **is** in the scene's backdrops, so these are flat fills in a backdrop colour at the cage's position: plausibly the repaint of what the cage vacates as it swings, plausibly a dark opening behind it, and nothing measured separates those. |
| amiga/INTRO 112, 184, 430; amiga/TANK 100 | 1x6, 29x14, 16x9 and 6x12 specks; two are teal diagonal streaks | these gate the last ~18 unnamed routines in INTRO and TANK, and at that size a render is a handful of magnified pixels |

A second lesson from the same run: **read the extents before the montage.**
CAVES 301..309 sat in the unresolved table as "horizontal blue and grey
bands" because a nine-pixel speck blown up to 210px tall looks like a band.
The extents said 0x1 and 1x11, and the animation read immediately.

## Anchored scenes examined, 2026-09-20

Inverting the measurement below -- asking which scenes have a named routine
AND unnamed art in the same setup block -- gives eleven candidates. One
resolved (`PRISON_HERO_DEATH_FLASH`, from `PRISON_HERO_KILLED`). Two more
were examined and are recorded here rather than left for someone to redo:

| run | measured | why it stops |
|---|---|---|
| amiga/CAVES 191..193 (`LABEL_11F9`) | 3x8/1, 5x16/2, 7x16/2, growing, at `[0xE6],[0xE7]`; colours {16} and {10,16} | colour 16 is the page-copy special, not a palette entry, so these are masked shapes rather than drawn ones. The scene anchor is `HERO_PRONE_IDLE_LEFT_LOOP`, which says the hero is prone and nothing about a small growing mask. |
| msdos/PRISON 637..655 (`LABEL_4FCC`) | four SINGLE-leaf shapes at four fixed positions -- 54x65 at (172,110), 101x76 at (182,40), 45x110 at (88,146), 56x109 at (289,147) -- each drawn three times in a **different colour**; plus 24x49 twice and one 78x178 with 19 leaves at (160,100) | the structure is unmistakable, a colour cycle over four screen regions, but a single-leaf silhouette at a fixed spot has no features to identify. The scene's only named peers are `PRISON_DOUBLE_BLIT_PAGE_0_THEN_HELPER` and `SET_PAL_07_FILL_TWO_PAGES_...`, both mechanism names, so the anchor says nothing about the place. |

The second is the clearest statement of the limit: everything structural is
measurable -- how many shapes, where, how many colours, in what order -- and
none of it says what the shapes ARE.

## Why the rest stall, measured

Both runs that resolved had a **named routine in their own setup block**:
`CAVES_LANDING_SPLASH` was installed beside `CAVES_HERO_FALL_LANDING_AND_
SCENE_RESET`, and `CAVES_WATERFALL_DRIP` beside
`CAVES_WATERFALL_BACKDROP_HOLD_LOOP`. In both cases the neighbour said what
the scene was and the art only had to agree.

Counted over the ten largest exclusive unnamed runs left in the big three,
actor-slot runs excluded:

    10  runs
     2  have any semantically-named routine in the same setup block

and the two are runs already understood for other reasons. **Eight have no
named peer at all** — `LABEL_070A` and `LABEL_0636` have zero peers,
`LABEL_116D` has ten peers and not one of them named.

That is the shape of the remaining polygon work, and it is not a rendering
problem. These runs sit in scenes where nothing is named, so there is
nothing for the art to agree with. Rendering them produces a legible
picture and no name, which is what the table above records eight times
over. The lever that would move them is naming the **scenes** — the setup
blocks and the routines they install — after which the art has an anchor.

Measured extents for four of them, so the next pass need not:

| run | shape |
|---|---|
| amiga/CAPSULE 16..23 (`LABEL_116D`) | 8 frames, 56..76 x 68, 8 to 12 leaves, one colour set {0,5,6,9,12}, fixed y 64..132 — one figure-sized object, width shrinking then jumping back |
| amiga/CAPSULE 358..365 (`LABEL_070A`) | 8 frames, 16..29 x 18..21, 2 leaves, {6,9}, fixed low y — a symmetric width cycle 29,27,22,18,16,18,22,27 |
| amiga/CAPSULE 386..393 (`LABEL_0636`) | NOT one family: 386 is 86x9 {0,10}, 387 is 45x22 {0,13}, and 388..393 are 28..52 x 159 with 3 leaves {1,3,9}, widening |
| amiga/PRISON 119..126 (`LABEL_0E68`) | 8 frames, 4x2 to 18x3, 1 or 2 leaves, colours 8 and 16 |

## The standing lesson

Most of the runs above rendered *legibly* and still could not be named.
Legibility is not identification: `CAVES_LANDING_SPLASH` was nameable because
the **code** placed it — same x as the hero, same y as the landing, running
concurrently with a routine already named from its own evidence — not because
a blue burst looks like anything in particular. Render to see; read the
scheduling to name.


## Correction, 2026-09-20: three figures above were re-measured

`polygon_extent.extent` misread a group polygon's header as a bounding box to
halve when it is a pivot to subtract whole, so extents of *nested* art came out
inflated. `../polygon-extent-correction/` has the probe that establishes this
against the renderer and the re-measurement. Flat art -- most of this ledger --
is unaffected, and `canonical_md5` never interprets the header, so every
cross-port identity claim here stands untouched.

Three rows changed and have been corrected in place:

| row | was | is |
|---|---|---|
| `CINEMATIC_CAVES_LANDING_SPLASH_F0..F9` | 15x14 growing to 88x93, dispersing at 74x67 | 15x14 swelling to 32x33 at F4, shrinking to 8x15 |
| amiga/CAVES 213..222 | 99x74 to 186x128 | 43x72 to 104x73 |
| msdos/PRISON 655 | 114x178 | 78x178 |

**No name changes.** `CAVES_HERO_LANDING_SPLASH` is if anything better supported
by the corrected figures: a splash that swells and then subsides is the expected
shape, where "grows to 88x93 and disperses at 74x67" was neither growth nor
dispersal but the inflation curve of the bug. The 213..222 exclusion also
stands, because the decisive part of it was that the run shares no md5 with the
laser-impact family, and the laser family measures the same under both rules
(54x68 down to 23x7 -- its trees are flat).

Everything else in this file was re-measured and did not move: the waterfall
drips, CAVES 191..193, amiga/PRISON 540..548, amiga/CAPSULE 386..393,
amiga/PRISON 119..126, msdos/TANK 106..111, the two CAVES limb runs, and the
INTRO and TANK specks. Reproduce with

    python3 notes/polygon-extent-correction/what_the_correction_moves.py --worst
