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
