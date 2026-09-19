# The twelve background bitmaps, and which routine loads each

A scene's identity is often **not in the polygon bank**. `notes/render-
attempts/` measured that eight of the ten largest unnamed polygon runs left
in the big three have no semantically-named routine anywhere in their setup
block — and chasing one showed why: amiga/CAPSULE's baths scene installs
eleven channels whose art is 13x24 to 71x68, all small animated elements,
because the backdrop is a 320x200 bitmap resource that no polygon probe can
see.

`render_backdrop.py` decodes them. Twelve resources in the whole game are
32,000 bytes (320*200 at 4bpp), and all twelve are legible.

## What they are

| res | image | loaded by | palette |
|---|---|---|---|
| 0x12 | the Interplay logo | — | — |
| 0x13 | the "Out of This World" title, the US name | — | — |
| 0x43 | a tall panel of falling vertical streaks framed left and right by stone blockwork | amiga/CAVES `LABEL_D0DF` | 0x06 |
| 0x44 | a colonnade of arches over a walkway, open sky behind | amiga/CAVES `LOAD_RES44_AND_RET` | — |
| 0x45 | pillars and a parapet walkway, stone arches below, sky, a small lit figure top-left | amiga/CAVES `LABEL_CDA8` | 0x08 |
| 0x46 | a cavern of tall dripping columns over a pool | amiga/CAVES `LABEL_CDA8` | 0x08 |
| 0x47 | "Delphine Software", (C) 1991 | — | — |
| 0x48 | a cave interior, rock forms and a large round mass | amiga/PRISON `LABEL_018D` | 0x19 |
| 0x49 | an open landscape: pale spires, curved black forms, a disc low in the sky | amiga/PRISON `LABEL_018D` | 0x19 |
| 0x53 | the "Another World par Eric Chahi" title, the European name | — | — |
| 0x90 | a dark interior of vertical structures with a dithered band | amiga/CAPSULE `LOAD_BATHS_BACKDROP_PAGES` | 0x01 |
| 0x91 | **the baths** — a vaulted hall, columns, draped arches, a blue pool | amiga/CAPSULE `LOAD_BATHS_BACKDROP_PAGES` | 0x01 |

The palette column matters: it is the one the calling scene's `setPalette`
gives, and rendering with another produces a perfectly legible picture in
the wrong colours. 0x43 read as "blue with orange streaks" at palette 1 and
as gold-on-black masonry at its own 0x06.

## What has been named from this

- `CAPSULE_BATHS_SCENE_INIT` and `LOAD_BATHS_BACKDROP_PAGES`, both ports.
  The scene is entered on `je [SCREEN_NUM], 0x4A`, and "baths" was already
  the project's word for the place: `TANK_ARENA_EXIT_CAPSULES_RISE_TO_BATHS`
  predates this.
- **Nothing, for 0x43 — and the attempt is instructive.** I named
  `LABEL_D0DF` `CAVES_LOAD_WATERFALL_BACKDROP` on the strength of the image
  (a curtain of falling streaks between masonry) and reverted it: msdos
  already called the byte-identical routine
  `CAVES_BUDDY_CRAWLING_SCENE_SETUP`, so the rename invented a second name
  for one routine. It is back to msdos's.

  The disagreement is older than my mistake. That same scene contains a
  routine both ports already call
  `CAVES_WATERFALL_SPRAY_DRIFT_LEFT_LOOP` — so the tree holds two earned
  names for one place, one saying a crawl and one saying a waterfall, and
  #0120 says neither a tool nor I should pick. The polygon families named
  there take only their measured form: `CAVES_FALLING_STREAK`,
  `CAVES_SPRAY_LINE`, `CAVES_DROPLET`.

  `notes/crossport-routine-names/same_body_two_names.py` exists because of
  this, and finds 13 more routines carrying two semantic names.

## What is deliberately not named yet

`LABEL_CDA8` loads two images, a cavern and a walkway, so one name will not
cover it honestly. `LABEL_018D` loads a cave interior and an open landscape;
the landscape is recognisable as the game's exterior vista but PRISON is an
odd place for it and the pairing wants understanding first.

Neither is blocked on the renderer. They are blocked on saying something
about the picture that a reader could check.

## Compositing polygons over a backdrop: works, but not statically

The obvious next step is to draw a scene's animated elements onto its
backdrop and look at the tableau. Half of it works: the backdrop decodes
and the elements paste.

Placing them does **not** work from a static read, and the failure is
worth recording so it is not re-attempted the same way. Screen position
ought to be the draw's `x`,`y` plus the polygon's anchor-relative extent,
and for the baths scene that puts two of three elements off a 320-wide
screen — `CINEMATIC_016` at x=283 and `CINEMATIC_014` at x=322 — including
one whose draw coordinates are **literal** (239,102), so the variables are
not the whole story. Only `CINEMATIC_024`, drawn at a literal (66,91),
lands somewhere plausible, at the pool's edge.

Two candidate causes, neither settled: the scene sets `[0x46]`, `[0x47]`,
`[0x42]`, `[0x43]` before loading, which look like scroll or clip bounds
and would shift the page; and a group's authored child offsets can be large
(CAVES has polygons whose ink sits 90 units from the anchor), so "draw x
plus extent" may not be the composition the VM performs for every shape.

Resolving it wants the VM rather than more reading: `AnotherWorld_VMTools`
carries `awvm` and an `exectrace` directory, and a trace that logs each
draw's final screen coordinates would settle both causes at once and make
scene tableaux a routine tool. That is a piece of work, not a look.

Until then the backdrops are still worth what the table above is worth:
they identify the **scene**, which is what the polygon runs were missing.
