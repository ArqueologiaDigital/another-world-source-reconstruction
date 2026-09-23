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

The recurring motif is a ceiling band with columns flaring where they meet it,
one such structure per screen, each drawn once at x=160, y=100 by that
screen's own backdrop painter and by nothing else. `CINEMATIC_340` is the one
that is not a column: two arch silhouettes springing from pillars.

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
