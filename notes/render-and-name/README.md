# Names read off a render

**Every name listed here has no independent check behind it.** It was read
from a rendered picture, at the confidence stated per row, with the measured
extent and the draw position quoted as the corrective. A rename moves no
bytes, so `make test` cannot catch one of these being wrong. They are grouped
in one directory for exactly that reason: they can be audited, or reverted, as
a set.

This was done under explicit approval to name from rendered sight at a stated
confidence, after every structural method in `notes/` had been measured to
zero — `../cross-port-art/`, `../backdrop-drawer/ --layers`,
`../shared-bank-geometry/mirror_exact.py`, `../scene-reading/composed_of.py`,
`../placeholder-census/ --shapes` all propose 0.

| file | what it is |
| --- | --- |
| `sheet.py` | the looking tool: contact sheets of still-numbered art, biggest first, with the draw context on every tile |
| `proposals_<branch>__<STAGE>.md` | every name given this way, with its evidence |

## What keeps the eye honest

`docs/NAMING.md` grade E3 has always asked for render-before-naming. The risk
is the opposite of not looking: looking at a magnified thumbnail and believing
it. This project has three recorded wrong readings of exactly that kind — a
1x12 speck read as a "band", a gun barrel read off a scaled render. So every
tile carries three things besides the picture:

* **the measured extent and path count.** A 4x2 glyph blown up to fill a tile
  looks like a mushroom; the label says it is four pixels wide. This is why
  `CINEMATIC_336` is *not* named here even though it renders as a perfect
  little toadstool.
* **how many times it is drawn and at what screen y.** Independent of the
  picture, and often decisive. `CINEMATIC_410` is a 12x30 spike that tapers
  upward from a wide base — a stalagmite or a stalactite depending on which
  way is up. It is drawn four times at **y=165** on a 200-tall screen, spread
  along x at 83, 136, 233 and 293. It stands on the floor.
* **the routines that draw it**, which give the screen scope for free and
  bound the subject before the picture is seen.

## Naming by subject, which is what unblocked this

`../backdrop-drawer/README.md` records why 185 of 186 layers cannot be named
`_BACKDROP_LAYER_<i>`: the index is a draw position, and most pictures are
painted several times or sit in a stack whose other positions are shared, so
the family would have holes. Naming by **subject** — what the picture is —
has no index and no family, so none of that applies. That is what looking
buys, beyond the name itself.

## The names so far

CAVES, both priority ports. Each amiga name was read from the render; each
msdos one was carried across by `../cross-port-art/transfer_by_art.py` on
`canonical_md5`, never on the index, and its `_SCREEN_<NN>_` component was
checked against the receiving port's own guards.

| amiga | msdos | name | confidence |
| --- | --- | --- | --- |
| CINEMATIC_410 | CINEMATIC_431 | `..._SCREEN_6C_STALAGMITE` | high |
| CINEMATIC_408 | CINEMATIC_429 | `..._SCREEN_6C_CAVERN_COLUMNS` | medium |
| CINEMATIC_409 | CINEMATIC_430 | `..._SCREEN_6C_CAVERN_COLUMN_LARGE` | medium |
| CINEMATIC_341 | CINEMATIC_362 | `..._SCREEN_4D_CAVERN_COLUMNS` | medium |
| CINEMATIC_340 | CINEMATIC_361 | `..._SCREEN_4D_ARCHES` | medium |
| CINEMATIC_332 | CINEMATIC_353 | `..._SCREEN_4C_CAVERN_COLUMNS` | medium |
| CINEMATIC_333 | CINEMATIC_354 | `..._SCREEN_4C_CAVERN_ARCH` | medium |
| CINEMATIC_279 | CINEMATIC_300 | `CINEMATIC_CAVES_WATERFALL` | high |
| CINEMATIC_323, 325, 326, 327, 328, 329 | CINEMATIC_344, 346..350 | `CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F0..F5` | high |
| CINEMATIC_402 | (msdos twin) | `CINEMATIC_CAVES_WALL_BREACH_STRAND` | high |
| CINEMATIC_423 | (msdos twin) | `CINEMATIC_CAVES_DROPPED_GUN` | medium |
| CINEMATIC_203, 190..195 | (msdos twins) | `CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F0..F6` | medium |
| CINEMATIC_634 | (msdos twin) | `CINEMATIC_PRISON_PRISONER_BEHIND_BARS` | high |
| CINEMATIC_636 | (msdos twin) | `CINEMATIC_PRISON_CELL_BARS` | high |
| CINEMATIC_391..399 | (msdos twins) | `CINEMATIC_PRISON_BUDDY_TYPING_ARM_{LEFT,RIGHT}_F0..F3` + `_FIGURE_BASE` | high |
| CINEMATIC_370, 379..385 | (msdos twins) | `CINEMATIC_CAPSULE_HERO_CRAWL_F0..F7` | high |
| CINEMATIC_366..378 (9) | (msdos twins) | `CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F0..F8` | high |
| CINEMATIC_683, 684, 685 | (msdos twins) | `CINEMATIC_PRISON_WAKE_CLOSEUP_FACE_HALF_0`, `_HALF_1`, `_IRIS_STRIATIONS` | high |
| CINEMATIC_656, 658 | (msdos twins) | `CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_BASE`, `_EYE_GLINT` | high |
| CINEMATIC_682, 680, 679, 678 + a renumber of `_PUPIL_0/1/2` | (msdos + cartridge twins) | `CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0..6` | high |
| CINEMATIC_659..676 (18) | (msdos twins) | `CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_0..17` | high |
| CINEMATIC_638, 642, 646 | (msdos twins) | `CINEMATIC_PRISON_WAKE_FIGURE_HEAD_0..2` | high |
| CINEMATIC_651..655 | (msdos twins) | `CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_0..4` | high |
| CINEMATIC_637, 641, 645 | (msdos twins) | `CINEMATIC_PRISON_WAKE_FIGURE_NECK_0..2` | medium |
| CINEMATIC_639/643/647, 640/644/648, 649/650 | (msdos twins) | `CINEMATIC_PRISON_WAKE_FIGURE_ARM_{LEFT,RIGHT}_0..2`, `_ARM_RIGHT_EDGE_0..1` | medium |
| CINEMATIC_173, 174 | (msdos twins) | `CINEMATIC_PRISON_GUN_CLOSEUP_BACKDROP_0..1` | high |
| CINEMATIC_176, 177, 172 | (msdos twins) | `CINEMATIC_PRISON_GUN_INDICATOR_{DARK,LIT}`, `_GUN_ON_GROUND` | medium |
| CINEMATIC_032, 033, 034 | (msdos twins) | `CINEMATIC_PRISON_WALL_{HIGHLIGHTS,SHADOW_BANDS,CORNER_SHADOW}` | medium |
| CINEMATIC_085, 086 | (msdos twins) | `CINEMATIC_PRISON_GRAVEL_TILE_0..1` | high |
| CINEMATIC_087, 088, 089 | (msdos twins) | `CINEMATIC_PRISON_DEBRIS_SHARDS_0..2` | medium |
| CINEMATIC_090, 091 | (msdos twins) | `CINEMATIC_PRISON_LIFT_LANDING_VAULT_HALF_0..1` | high |
| CINEMATIC_104, 106, 092 | (msdos twins) | `CINEMATIC_PRISON_LIFT_LANDING_{SLOPE,WALL_PANEL,COLUMN}` | medium |
| CINEMATIC_080..084 | (msdos twins) | `CINEMATIC_PRISON_CAGE_LANDING_F0..F4` | high |
| CINEMATIC_368..375 | (msdos twins) | `CINEMATIC_PRISON_FALLING_DEBRIS_F0..F7` | high |
| CINEMATIC_138..140, 142..144 | (msdos twins) | `CINEMATIC_PRISON_BLAST_DEBRIS_F0..F5` | high |
| CINEMATIC_141, 145, 137 | (msdos twins) | `CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED_0..1`, `_BLAST_MARK` | high / medium |
| CINEMATIC_596..614 (19) | (msdos twins) | `CINEMATIC_PRISON_CLOAKED_FIGURE_F0..F18` | medium |
| CINEMATIC_616/618/620/622 | (msdos twins) | `CINEMATIC_PRISON_STANDING_FIGURE_F0..F3` | high |
| CINEMATIC_615/617/619/621/623 | (msdos twins) | `CINEMATIC_PRISON_STANDING_FIGURE_ARM_F0..F4` | high |
| CINEMATIC_406..409, 411, 412 | (msdos twins) | `CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F0..F5` | medium |
| CINEMATIC_426, 427 | (msdos twins) | `CINEMATIC_PRISON_FIGURE_CROUCHED_F0..F1` | medium |
| CINEMATIC_365, 376 | (msdos twins) | `CINEMATIC_PRISON_XRAY_FLASH_{LEFT,RIGHT}` | high |
| CINEMATIC_366/367, 377/378 | (msdos twins) | `CINEMATIC_PRISON_XRAY_SKELETON_{LEFT,RIGHT}_{LIT,DARK}` | high |
| CINEMATIC_563 | (msdos twin) | `CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT` | high |
| CINEMATIC_556, 561, 560, 567 | (msdos twins) | `CINEMATIC_PRISON_HERO_{STAND,ARM_OUT}_{LEFT,RIGHT}` | high |
| CINEMATIC_222, 213 | (msdos twins) | `CINEMATIC_PRISON_HERO_LUNGE_{LEFT,RIGHT}` | high |
| CAVES CINEMATIC_110..123 | (msdos + CAPSULE twins) | `CINEMATIC_TUMBLING_CHUNK_F0..F13` | high |
| CAVES CINEMATIC_239..245, 416..422 | (msdos twins) | `CINEMATIC_CAVES_SPINNING_SPIKE_{0,1}_F0..F6` | medium |
| CAVES CINEMATIC_213..222 | (msdos twins) | `CINEMATIC_CAVES_CRACK_SPREAD_F0..F9` | medium |
| CAVES 451/494..498, 469/499..503 | (msdos + amiga CAPSULE twins) | `CINEMATIC_HERO_SWIM_PITCH_{RIGHT,LEFT}_0..5` | high (**renamed**, see `correction_swim_pitch.md`) |
| CAVES CINEMATIC_504..508 | (msdos + amiga CAPSULE twins) | `CINEMATIC_RISING_SPECKS_0..4` | medium |
| CAVES CINEMATIC_194..199 | (msdos twins) | `CINEMATIC_CAVES_SHATTER_F0..F5` | medium |
| CAVES 643, 651..656 | (msdos twins) | `CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0..F6` | medium |
| CAPSULE CINEMATIC_051..058 | (msdos twins) | `CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0..F6`, `_FIGURE_UPRIGHT` | medium |
| CAPSULE CINEMATIC_059..072 | (msdos twins) | `CINEMATIC_CAPSULE_{FALLING_MASS,FALLING_MASS_LANDED,DEBRIS_RAIN}_*` | medium |
| CAPSULE CINEMATIC_388..393 | (msdos twins) | `CINEMATIC_CAPSULE_BEAM_ENDS_F0..F5` | medium |
| CAPSULE CINEMATIC_400..406 | amiga only, see below | `CINEMATIC_CAPSULE_BEAM_COLUMN_F0..F6` | medium |
| CAPSULE CINEMATIC_356..365 | (msdos twins) | `CINEMATIC_CAPSULE_DISTANT_WALK_F0..F9` | high |
| CAPSULE CINEMATIC_407..410 | (msdos twins) | `CINEMATIC_CAPSULE_DIAGONAL_TRAIL_F0..F3` | medium |
| CAPSULE CINEMATIC_125..128 | (msdos twins; CAVES held) | `CINEMATIC_WIDE_FLASH_F0..F3` | medium |
| CAPSULE CINEMATIC_334..338 | (msdos twins) | `CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F0..F4` | high |
| CAPSULE 345..350, 354, 415..419 | (msdos twins) | `CINEMATIC_CAPSULE_{PRONE,KNEELING}_FIGURE_{0,1}_F*` | medium |
| CAPSULE CINEMATIC_434..442 | (msdos twins) | `CINEMATIC_CAPSULE_FIGURE_THROW_F0..F8` | medium |
| CAPSULE CINEMATIC_016..023 | (msdos twins) | `CINEMATIC_CAPSULE_FLYER_F0..F7` | medium |
| CAPSULE 448..452, 454..458 | msdos: `PROP_UP` only, see below | `CINEMATIC_CAPSULE_FIGURE_{PROP_UP,FLUNG}_F0..F4` | medium |
| TANK **msdos** 106..118 | amiga has no twin | `CINEMATIC_TANK_ARENA_BLAST_{RIGHT,LEFT}_F*` | medium |
| TANK **msdos** 120..125, 129..134 | amiga has no twin | `CINEMATIC_TANK_DESTROYED_{READOUT_F*,SHARDS}`, `_LAUNCH_{PLUME_F*,BASE_BAR}` | medium |
| TANK 006, 027, 028 | both ports | `CINEMATIC_TANK_{TWO_BAND_BACKDROP,ARCH_ROW,WRECKAGE}` | medium |
| PRISON 107..126 | (msdos twins) | `CINEMATIC_PRISON_GREEN_TRACER_F0..F7`, `_TRACER_BURST_{LEFT,RIGHT}_F0..F5` | medium |
| PRISON 541..548, 624..628 | (msdos twins) | `CINEMATIC_PRISON_FLEXING_BAND_F0..F5`, `_BAR_PANEL_F0..F4` | medium |
| CAVES 514..524, 857..867 | (msdos twins) | `CINEMATIC_CAVES_HERO_SWIM_ARM_{RIGHT,LEFT}_F0..F10` | high |
| CAVES 458..464, 480..490 | (msdos twins) | `CINEMATIC_CAVES_HERO_SWIM_LEGS_{DOWNSWEEP,CYCLE}_F*` | high |
| CAVES 572..578, 800..805 | (msdos twins) | `CINEMATIC_CAVES_{COLUMN_EMERGE,GROUND_BREACH}_F*` | medium |
| CAVES 143..147, 283..285, 403..405, 534..536 | (msdos twins) | `CINEMATIC_CAVES_{SWINGING_LIMB,BAR_CLUSTER,TWIN_LAMP_BRACKET,RIPPLE_LINE}_F*` | medium |
| CAVES 718, 719, 734, 735 | (msdos twins) | `CINEMATIC_CAVES_STALACTITE_CAVERN_{FLOOR,CEILING}_{LEFT,RIGHT}` | high |
| CAVES 452/453/470/471, 472..474/491..493 | (msdos twins) | `CINEMATIC_CAVES_HERO_SWIM_HEAD_{UP,DOWN}_{RIGHT,LEFT}_*` | high |
| INTRO 243, 246, 247, 250..260 | 249, 252, 253, 256..266 | `CINEMATIC_ACCELERATOR_TUNNEL_{VIEW_NEAR,PULSE_NEAR_F0..F14}` | high |
| INTRO `EXPERIMENT_LIGHTNING_F23..F28_AMIGA_EXTRA` | (same names) | `CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F0..F5` | high |
| INTRO 268..276 | 274..282 | `CINEMATIC_FRAGMENTS_RECEDING_F0..F8` | medium |

The recurring motif is a ceiling band with columns flaring where they meet it,
one such structure per screen, each drawn once at x=160, y=100 by that
screen's own backdrop painter and by nothing else. `CINEMATIC_340` is the one
that is not a column: two arch silhouettes springing from pillars.

`CINEMATIC_CAVES_WATERFALL` is the one name here that three things agree on.
The picture is 818 paths of dense vertical streaks in horizontal bands.
`DRAW_WATERFALL_BG_FOUR_PASS` draws **this constant and nothing else**, four
times at x=161 y=61, x=161 y=62, x=161 y=60 and x=160 y=62 across two video
pages -- the one-pixel offsets that give the routine its `FOUR_PASS` name.
`../sole-named-drawer/` cannot reach it, because rule 3 refuses a picture two
routines draw; the second here is `CAVES_BUDDY_CRAWLING_SCENE_SETUP`, painting
it full-screen as that scene's background, and the two agree. Looking is what
shows they agree.

## What was looked at and deliberately not named

* `CINEMATIC_336` / `CINEMATIC_407` — the 4x2 speck and the field of 19 of
  them (`../scene-reading/composed_of.py` proves the composition exactly).
  The speck renders as a mushroom and is four pixels wide. Not named.
* `CINEMATIC_589`, `CINEMATIC_590` — screen 0x8A's two backdrops, which read
  as dark rock with rounded light openings. The renderer uses a two-colour
  palette here, so light-against-dark is not depth, and "opening" is a
  reading the picture does not support on its own.
* `CINEMATIC_718`, `CINEMATIC_719`, `CINEMATIC_734` — ledges and floors,
  each shared between two screens, so no screen scope is available and the
  subject alone does not distinguish them from each other.
* `CINEMATIC_575`, `576`, `577`, `578` — four pictures, all 170-171 tall,
  each a rocky mound with a small railed structure on top, the mound
  narrowing and the structure growing across the four. That reads as one
  object approached, or as four different formations, and nothing decides
  between them: all four are drawn twice at x=160, y=100 with no named
  drawer. Subject and ordering are both guesses, so neither is taken.
* `CINEMATIC_635` — drawn in the same breath as the two cell-scene names
  below, at the bars' own anchor, so "the second prisoner" is the obvious
  reading. Its silhouette is a blocky mass with one small protrusion on top:
  no limbs, no head profile, nothing that resolves as a person the way
  `CINEMATIC_634` does. A bunk would look the same. Held.

## The walk cycle, and the check that had to come before naming six of it

Rendered in phase order, `CINEMATIC_323`, `325`, `326`, `327`, `328` and `329`
are a four-legged creature in profile facing right — head high at the right,
body sloping down to the left — differing frame to frame in leg position. Each
is the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_1..6`, whose bodies
are one `video` and a `ret`.

The render alone would have got the count wrong. The six bounding boxes pair
up exactly — 51x30, 56x30 and 67x30, twice each — and the paired tiles look
identical at tile scale, which reads as three pictures alternating rather than
six frames. They are **six distinct `canonical_md5`s**. The legs differ; the
boxes do not. Six frames.

All six are drawn at `x=[0x07], y=[0x08]`, the actor slot, so **#0138**
applies: the name is read from the art and not inferred from the scene the
picture appears in. That is the one thing looking is allowed to do at that
anchor.

`CREATURE` rather than `BEAST` because the routines drawing *this* art say so,
and the render agrees it is a creature. The tree's `DRAW_BEAST_POSE_*`
routines draw 10x10 pictures, which are not this.

## Seven agreeing routines is not one routine

`../sole-named-drawer/README.md` records a relaxation of its rule 3 that this
session tested and refuted: where a picture has **one** semantic drawer plus
some placeholder stubs, deriving the picture's name from that routine is right
**0 times out of 4**, because the routine is named for a moment in an
animation — `_ENTRY`, `_PRELUDE`, `_FINAL_HOLD` — and the art is named for a
thing.

Three of the names above lean on routine names anyway, and the difference is
worth stating rather than glossing:

* `CINEMATIC_402` is drawn 35 times and **every one** comes from
  `CAVES_WALL_BREACH_STRAND_SWAY_PHASE_1..7`, which draw it and nothing else.
  Seven separately written names agreeing about one picture is not one name.
  And the measurement agrees with the word independently: **1x20**, one unit
  wide and twenty tall, which is a strand and little else.
* `CINEMATIC_423` has the same seven-routine agreement
  (`CAVES_DROPPED_GUN_SKID_LEFT_PHASE_1..7`), and 16x4 is consistent with an
  object lying down. The render is **not** evidence here: at 16x4 the tile is
  a magnified sliver, and reading one of those is how this project got a
  "band" out of a 1x12 speck. Medium, and the row says why.
* The seven charge-glow frames have seven agreeing routines *and* a render
  that orders them: 5x6, 6x8, 12x8, 12x12, 12x14, then 12x12 and 12x14, all
  two paths. `GLOW` is supported by the shape; `CHARGE` comes from the
  routines. Medium.

None of the three is a routine naming a moment. That is the line the
refutation drew, and it is the line these stay on.

## The one that needed no argument

`CINEMATIC_634` is 278x360 and 49 paths, and it is a human figure in profile
-- rounded head with hair, neck, sloping shoulders, a bent arm -- seen through
five vertical bars running the full height. Every other name in this file
needed the extent or the draw position or a routine to corroborate it. This
one is just legible.

`CINEMATIC_636` beside it is 158x205 in **three paths**: three vertical bars
and nothing else, where the path count says the same thing the picture does.
`LABEL_4EE9` draws both twenty times under a `djnz` seeded to 0x14, at two
variable x anchors -- a pan across a row of cells.

## The typing animation, where the signed bbox did the separating

`BUDDY_HACK_SECOND_TYPING_LOOP` draws one right arm and one left arm over a
body base on each `break`, five frames in all. The nine pictures are eight
one-path elongated forms and one torso — enough to see it is a figure at a
keyboard, not enough to say which arm is which.

The signed bounding box says it without reference to draw order: four span
positive x, four negative, and **all four left arms share the same left edge
at −17.5** — one shoulder with the forearm at four angles. The right arms
likewise cluster at +2..+4.

Indices are order of first appearance in that routine, which
`../placeholder-census/ --frames` reproduces 159 times out of 159 for a
complete family drawn by one routine. All nine sit at `[BUDDY_X],[BUDDY_Y]`,
the actor slot, so **#0138** applies and the names come from the art rather
than the scene.

## The crawl, where the usual direction test had to be refused

Eight frames of a prone figure, 54-56 long, the body rising and falling —
11.5, 12.5, 11.5, 10.5, 9.5, 8.5, 9.5, 11.5 — and eight distinct
`canonical_md5`s, so eight real frames.

The name carries **no direction**, for two reasons that point the same way.
`HERO_CRAWL_LEFT_LOOP` does `sub [HERO_X]` and plays 370, 379, 380, 381, 382,
383; `HERO_CRAWL_RIGHT_LOOP` does `add [HERO_X]` and plays 370, 385, 384, 383,
382, 381. One cycle read forwards and backwards — the travel direction is in
the routine's arithmetic, not in the art.

And the signed bounding box, which settled facing for the teleport beams, the
run limbs and the typing arms, is **refused here**. It is the same for all
eight (x −44.5..+11.0, mass left), and that test assumes the draw anchor is
where a standing figure's feet meet the ground. A prone figure's anchor is not
that. This project already has one recorded case of an argument that was right
once and wrong when its embedded assumption did not travel —
`notas/blog/2026-09-23_o_mesmo_argumento_certo_e_depois_errado.md` — and this
would have been the second.

## What the arm-raise names do not claim

Nine frames of the same prone body as the crawl — same left edge at −44.5,
and the routine ends by drawing two crawl frames — with the arm reaching to
+18.5, then lifting to 23.5 tall while drawing back in, then settling.

In F6 through F8 there is a blocky shape at the end of the arm that looks
like a held object. **No name here claims one.** `ARM_RAISE` is what the
extents support: height and right edge, measured across the run. Whether the
figure is holding something, and what, is a further claim the pictures do not
settle at this size, and the session already has a list of names refused for
exactly that reason.

## Ladder families, and the one probe in this directory with a control

Most of what is named here is an animation: a routine plays frames in order
and the frame index is draw order. The PRISON wake closeup is not. Its two
picture families are **ladders** -- `jg [0x15], N` / `jg [0x16], N` chains
that pick one picture for the current value of a variable the driver moves up
*and* down. Draw order does not exist; what does is the rung.

`ladder_rungs.py` reads those rungs out of the bytecode, and is the only
script in this directory that produces a checkable number rather than a
picture to look at:

    python3 notes/render-and-name/ladder_rungs.py --stage PRISON --var 0x15
    python3 notes/render-and-name/ladder_rungs.py --stage PRISON --var 0x16 \
        --diff chahi_amiga_1991 cartridge_1992

`--diff` judges two branches on rung count and threshold, never on constant
spelling -- once one branch is renamed the spellings differ by construction.
It additionally fails a rung where both branches carry a semantic name and the
two names disagree, which is hazard #0118. It found three such rungs when this
batch renumbered amiga and msdos and left cartridge behind, and it is the
artefact that says the cartridge fix worked: FAIL, 3 disagree -> PASS, 0.

That check is what the cartridge names rest on, because the cartridge art
**cannot be measured** -- archaeology #0106 is open and no `cinematic.rom`
exists for it. See `proposals_cartridge_1992__PRISON.md`, which says so in its
first paragraph.

## `routines/` -- the labels, generated rather than written

Twenty of the twenty-four labels in the wake closeup are ladder rungs, and the
only honest name for a rung is its own guard: the arm handles `[var] <= N`, so
it is `..._UPTO_<N>`. Twenty of those transcribed by hand is how a threshold
gets copied wrong.

`routines/generate.py` reads them off the disassembly through
`ladder_rungs.py` instead, and writes the three proposal tables. The check is
that `apply_routine_renames.py` re-derives every guard independently, from the
routine's own first line, and rejects any row where the two disagree. It took
all 72 rows across three branches with 0 rejected.

Four rows per table are not rungs and carry hand-written evidence: the
backdrop painter, the frame routine, the join after the pupil ladder, and the
frame tail.

## `compose_run.py` -- looking at a frame where the engine puts it

The composite rule in this file said *what* to do and left the doing to a
one-off heredoc each time. `compose_run.py` is that heredoc, kept.

Given the renderer's output it writes one SVG per frame with a chosen set of
offsets drawn behind it, plus a `trail.svg` with every frame at once, and
prints the measurement that decides whether a run is one animation:

```
$ python3 notes/render-and-name/compose_run.py --renders <dir> --out <dir> \
      --under 3052 EA1C EA30 \
      --frames 887C 8890 8958 8A24 8AE0 8B90 8C04 8C68 8CD8 8D4A 8DA0 \
               8DF0 8E10 8E30 8E3E \
      --track '#fb7474' '#fbdbb7'
  F0  0x887C    398.0x 227.0  ...    4  125.0x84.0  93.0x57.0
  ...
  F14 0x8E3E      2.0x   3.0  ...    1        -         -
  first 398.0x227.0  ->  last 2.0x3.0
  last frame's box: x[166.0, 168.0] y[82.5, 85.5]
```

`--track` is the part worth explaining. A run's outer box can shrink for
boring reasons; a **fill colour** that carries through the run at shrinking
sizes is the same object seen smaller. On the INTRO pulse the salmon core
going 125x84, 42x24, 32x17, 21x10, 12x6, 7x5 is what proved the fifteen
pictures were one thing -- and it is what caught two frames wearing other
subjects' names, because their cores interpolated their neighbours' exactly.

It reads the renderer's SVG rather than the ROM on purpose:
`../polygon-extent-correction/` records a measurement bug that lived for eight
days precisely because there was no renderer in between.

The palette is the routine's own. Rendering this run at palette 0 gives black
on black, and the table above would be a table of zeroes.

## `frame_runs.py` -- the work queue, and how far to trust it

`sheet.py` lists what is left biggest first, and that is the wrong order to
work in. A 438x248 screen backdrop drawn six times across two screens is one
of the hardest things in a stage to name honestly; a run of eight pictures
drawn one per `break` at one anchor is one of the easiest, because the routine
states the frame order itself and the extents then have a motion to agree or
disagree with.

`frame_runs.py` finds the second kind: consecutive `video` lines sharing an
anchor, separated by nothing that can bring control in from elsewhere. Every
PRISON batch here that earned `high` came from such a run -- the cage landing
(5), the falling debris (8), the blast (9), the cloaked figure (19) -- and
they were found by reading the file by hand.

    python3 notes/render-and-name/frame_runs.py --stage CAVES --min 4
    python3 notes/render-and-name/frame_runs.py --stage PRISON --control --min 4

**The control says 11 of 19.** Of the PRISON runs whose members are now all
named, eleven carry one family prefix and eight do not -- and the eight are
right to. `FILL_AND_DRAW_CIN_24_28` is a run of five that is a screen
*composition*: a pillar, a grating, a highlight pass, a shadow pass, a corner.
`GUN_PICKUP_SCENE` is a backdrop, a gun and an indicator.
`DRAW_CIN_137_138_BLOCK` is a debris animation and the deposits it leaves.

The anchor does not separate the two cases: 8 of 13 actor-slot runs are one
family against 3 of 6 literal ones, and the body-and-limb splits are at actor
slots. So a run is a **candidate to look at**, not a family, and the render
still decides.

`--stages` answers the other question a namer should ask first: does this art
exist in another stage? Naming a run `CAVES_...` and finding an hour later
that the same `canonical_md5` is in PRISON and CAPSULE costs a rescope, a
re-sync and a second commit -- which happened to seven families at once on
2026-09-23. All nine CAVES runs of seven or more report "this stage only", so
they may take a stage word; the fourteen-frame `DRAW_CIN_110_BLOCK` run does
not, and `CINEMATIC_TUMBLING_CHUNK_F0..F13` never carried one.

### `--partners`: the other queue

Some numbered constants are drawn on the line before or after a constant that
already has a name, at the same anchor, **every time**. That is how
`CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F0..F4` were found: each sits
against its own `CV_FIGURE_WALK_RIGHT_UPPER_POSE_*`.

    python3 notes/render-and-name/frame_runs.py --stage CAPSULE --partners

**A companion is not a synonym.** Which of a pair is the subject and which is
an overlay took a render and two extents to settle -- the numbered one was
59.5 tall standing on the floor, the named one 30 tall and two paths, floating
in the torso band. The mode narrows the question and does not answer it.

Its control, run against the tree before that batch, is **4 of 5**: it would
have offered 334, 335, 336 and 337 and missed 338. The reason for the miss is
not the obvious one -- 338 *is* paired with `..._POSE_06` at both its draws,
but at both it also has the previous frame's `..._POSE_04` two lines above, so
its neighbour set has two names and the "exactly one" test fails. It
under-offers, and specifically on frames in the middle of a dense run.

### Composite before you judge a sliver

Three CAVES runs -- 22 arm frames and 18 leg frames -- sat in the handoff's
held list as "unreadable at palette 0". They were not unreadable; they were
being looked at **alone**. Each is one or two untextured paths a few pixels
across, and each is drawn on its own channel *over* a figure another channel
draws.

Composited over `CINEMATIC_CAVES_HERO_IDLE_RIGHT_0` at palette 0x05 they
resolve immediately into an arm stroking and two legs kicking. The rule that
follows: when a run's pictures are one or two paths and its routine is set up
with `setup channel=...` beside another draw channel, **render it over what
that other channel draws** before concluding it cannot be read.
