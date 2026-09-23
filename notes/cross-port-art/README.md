# The art is the bridge between ports, never the index

| file | question it answers | command |
| --- | --- | --- |
| `transfer_by_art.py` | Which pictures are named in one priority port and still numbered in the other? | `python3 notes/cross-port-art/transfer_by_art.py` |
| `name_art_agreement.py` | Does a name shared by both ports sit on the **same picture** in each? | `python3 notes/cross-port-art/name_art_agreement.py` |
| `bank_copy_in_stage.py` | Which still-numbered cinematic constants are a stage's own copy of art the shared bank already names? | `python3 notes/cross-port-art/bank_copy_in_stage.py` |

`docs/NAMING.md` records hazard #0107: the two releases index their art
differently, so a name moved **by index** lands on whatever the other port
keeps at that number. Both modules here bridge on `canonical_md5` instead.

## Transferring

Where one port has a semantic name and the other a bare index on the same
picture, the name transfers. One guard makes it safe: a name carrying a screen
number is only transferred when the receiving port draws that picture **on
that same screen**, checked through `../screen-scope/`. That is not
hypothetical — amiga installs `CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME` on
screen 0xED and msdos on 0xEE.

It caught three, one of them sharp: amiga's `CINEMATIC_424` is drawn on screen
**0x4D**, and msdos' name for that picture says `SCREEN_6D`. Transferring on
art alone would have written the wrong screen into the tree.

### What it will not transfer, and the one thing left blocked

A `_BACKDROP_LAYER_<i>` name is **never** transferred. That index is the
position in the receiving port's *own* paint sequence, computed by
`../screen-scope/backdrop_phase.py` from that port's entry routine, and it is
not a property of the picture. msdos proves it: amiga's
`CAVES_SCREEN_ED_BACKDROP_LAYER_5` and `_6` are msdos'
`CAVES_SCREEN_EE_BACKDROP_LAYER_4` and `_5` — a different screen *and* a
different position, because msdos has a screen amiga does not. Nine names were
held back on that rule.

After it, six remained: `CINEMATIC_BUDDY_SMASHING_WINDOW_F0..F4` and `F8` in
CAPSULE, refused by the applier as a new family-index gap. That was a guard
doing its job on a case it read slightly wrong — **amiga's own family has
exactly that shape**, F0 through F4 and F8 with no F5, F6 or F7 anywhere,
because the 1991 release has frames the 1992 ports dropped. Transferring it
reproduces a family the tree already accepts.

The fix went into the guard rather than round it
(`another-world-archaeology`, `apply_cinematic_renames.py`): the gaps a
proposal is judged against now include those of the **same family name in the
other branches of the stage**. Reproducing a sibling's shape is not inventing
a gap. The existing `inherited` mechanism could not cover this — it only fires
when every proposed member comes from one source family at the same index, and
a transfer's sources are bare `CINEMATIC_<n>` constants.

Cross-port transfers then went **6 -> 0**, and the fix reached further than
this directory: `../screen-scope/backdrop_phase.py`'s permanently-blocked
batches went **107 -> 70**, because several of those families exist in a
sibling branch with the same holes.

## And the audit that came out of it

The transfer probe kept proposing names the applier refused as *already in
use*, and the reason was worth more than the transfers: msdos already had the
name — on the wrong constant.

`name_art_agreement.py` checks every name that exists in both ports for the
same stage. Measured 2026-09-23:

```
2064  same art in both ports
   6  ** name on the wrong constant
   4  different art, no counterpart -- per-port divergence
```

The six are all in INTRO, and the pattern is unmistakable. For each, msdos'
named constant holds art that amiga calls by a bare number, and amiga's art
sits on a different msdos number a few indices away:

| name | msdos' holder is amiga's | amiga's art is msdos' |
| --- | --- | --- |
| `CINEMATIC_LIFT_SCENE_BG` | `CINEMATIC_533` | `CINEMATIC_535` |
| `CINEMATIC_LIFT_SCENE_VIEW` | `CINEMATIC_528` | `CINEMATIC_530` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR` | `CINEMATIC_378` | `CINEMATIC_380` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR` | `CINEMATIC_243` | `CINEMATIC_255` |
| `CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE` | `CINEMATIC_171` | `CINEMATIC_183` |
| `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2` | `CINEMATIC_517` | `CINEMATIC_517` |

A consistent small index offset is the signature of a transfer done on the
number. The last row is the same fault seen from both ends at once — the two
ports' `CINEMATIC_517` hold each other's art.

The other four, in CAPSULE and PASSCODE, are **not** defects: the amiga name's
art is absent from msdos altogether and vice versa, so the ports genuinely
drew different pictures for one role, which is the documented case where the
shared name is the role and the per-port value is that port's art.

Telling the two apart is why the report names the *counterpart* rather than
just the mismatch. A defect has a twin somewhere in the other port; a
divergence does not.

## A third axis: the stage's own copy of bank art

Cross-port and cross-stage matching were both tried. **Cinematic against
shared bank** was not, and it is the largest of the three.

`../substitute-layers/fire_frames.py` found PRISON and CAPSULE drawing the
hero's shot from their own cinematic banks with art byte-identical to the
shared-bank pieces. The name did not have to be re-derived — it was read off
the `canonical_md5` match. That generalises: of the still-numbered cinematic
constants that are actually drawn, **91 are byte-identical to exactly one
named shared-bank picture**, most of them in PRISON.

The name transfers because the bank names describe a *pose* —
`HERO_CROUCH_DOWN_LEFT`, `CV_FIGURE_GUN_UPPER_RIGHT_POSE_00`. A
byte-identical picture is that pose whatever the stage does with it. The
stage prefix keeps the two apart: `CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT` is
PRISON's copy and the bare `HERO_CROUCH_DOWN_LEFT` is the bank's.

**90 applied**, taking priority-port assets from 62.2% to 63.1%.

### The one that had to be put back, and the guard it earned

`CINEMATIC_555` in PRISON is drawn from
`prison/prison_step_draws_and_breaks.inc`, which `PRISON.asm.in` includes
**unconditionally** — so every branch reads that draw line. Renaming the EQU
in amiga and msdos left their copies of the symbol undefined and took
verify-unified to **27/29**.

The applier warns about this (*"N shared draw line(s) reference a renamed
constant and are not inside a conditional"*), and the warning was missed
because the apply loop grepped only for `applied;`. The constant was renamed
back and the probe now refuses the whole class: a constant drawn from a
chunk with no `<port>__` filename prefix is skipped, which is **560** of
them.

### What that guard actually costs, and why it is not merely cautious

560 skipped sounds expensive and is not. Of those, exactly **one** was
nameable — `CINEMATIC_555` itself. The rest either have no bank match, are
not readable in both priority ports, or already carry a name.

And the guard is not just caution. Among the shared-chunk constants, **21
hold different art in amiga and msdos** despite every branch executing the
same draw line. A first measurement over PRISON, CAVES and CAPSULE alone
found 201 of 201 agreeing, which would have supported extending a global
rename to cartridge on the reasoning that ports do not diverge on shared
lines. Widening it to all nine stages shows they do. The inference would have
been wrong, and the guard blocks it for a reason rather than for tidiness.

Renaming one of these needs every branch at once, and that needs cartridge's
art. The cartridge romsets carry `bytecode.rom` but no `cinematic.rom`, so
its polygons are genuinely unextracted — unlike `gba_2004`, whose cinematic
bank **is** readable (65,536 bytes via `slab("cinematic", "gba_usa", n)`) and
which every art-based probe here could include, though it is not a priority
port.

## `align_draw_sites.py` -- when one md5 holds several constants

`transfer_by_art.py` refuses a picture whose `canonical_md5` maps to more than
one constant in a port, and it is right to: the hash cannot say which is
which. That is not a corner case. PRISON's wake-up scene stores the head, the
neck and each arm **three times over**, byte for byte identical, so that one
pass of the draw routine can put the same shape on screen at three zoom
levels:

```
  (183,40)   CINEMATIC_638 641 645   all canonical_md5 2d66cda0
```

Fourteen of that scene's nineteen constants were unreachable by art alone.

The second bridge is position. Where the two ports run the same program, the
n-th `video` instruction in one is the n-th in the other. This is **not**
naming from the index -- #0107 is about the bank index inside
`CINEMATIC_<n>`, which the ports assign independently -- but it needs its own
proof, twice over, and the second proof is the point of this entry.

### The scope is chunk pairs, not files

A whole-file gate fails in every stage. Measured 2026-09-23:

```
  PRISON   1420 draw sites vs 1480      CAPSULE  1473 vs 2026
  CAVES    2346 vs 2485                 TANK      572 vs  693
```

even in PRISON, which `docs/NAMING.md` calls one of the three stages that are
"wholly identical". What does line up is the unified tree's own pairing:
`amiga__post_X.inc` and `dos__post_X.inc` are the two branches' arms of one
region. PRISON has 88 such pairs; 39 of them carry draw sites that match in
count and in every argument.

### The control refuted the first version

Gate the transfer on the alignment alone and run it against the sites where
**both** ports are already named, and it gets 592 of 636 right. The 44 it gets
wrong are all one family, and they are wrong in a shape:

```
  amiga CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_0  vs  msdos ..._ZOOM_IN_RIGHT_13
  amiga ..._ZOOM_IN_LEFT_1                        vs  msdos ..._ZOOM_IN_RIGHT_12
  amiga ..._ZOOM_IN_LEFT_2                        vs  msdos ..._ZOOM_IN_RIGHT_11
```

`canonical_md5` disagrees at every one of the 44. The tool's own control
splits the both-named sites by whether the art matches, and the
`same art / DISAGREE` bucket is **empty**: every wrong answer is a site where
the two ports draw different pictures. The sites really are aligned; the
pictures drawn there are not the same pictures. Which is obvious
in hindsight -- a chunk is branch-scoped *because* the branches differ in it,
and two different pictures at the same x, y and zoom pass an argument check
unchanged.

A 6.9% error rate is not a naming method. So the tool requires **both**
bridges: the site must align and `canonical_md5` must agree.

```
  552 of 552 aligned-and-same-art site(s) re-derive the name a person wrote
  193 aligned site(s) refused because the art differs
   44 of those would have been wrong
```

Neither bridge is sufficient alone. The alignment resolves what the hash
cannot distinguish; the hash catches what the alignment cannot see.

A name carrying a screen number, or a `_BACKDROP_LAYER_<n>` paint position, is
refused here whatever the gates say -- `transfer_by_art.py` has the check for
those and this tool does not.

### Still open

The 44 `PRISON_CUTSCENE_ZOOM_IN_*` disagreements are a real conflict, not
noise: the ports are named from opposite ends of the family with `LEFT` and
`RIGHT` swapped, `LEFT_n` against `RIGHT_(13-n)`. The art differs, so both may
be right about their own port -- but nobody has checked, and this is where to
start.

## What `canonical_md5` cannot see: colour

`tools/polygon_tree.py` builds a solid polygon as
`("solid", bbox_w, bbox_h, [(x, y), ...])` -- **no colour field**. Only a group
*child* carries one, as its `color_override`. So two solids of the same shape
in different colours have the same hash, and every tool here that says
"identical art" is saying "identical shape".

`colour_blind_hashes.py` measures how much that costs. amiga/INTRO,
569 constants:

```
  556 distinct canonical_md5, 0 unparseable
  COLLIDING   4 hash(es) held by more than one constant
  RECOLOURED  3 of those draw in more than one colour set
```

Small, but concentrated exactly where it hurts. One hash, `afafd0dda5fb`, is
held by **ten** constants -- every 2.0x1.0 one-path mark in the stage -- and
the renderer gives them ten different fills:

```
  CINEMATIC_348 / 349 / 350 / 351        #204464 #103054 #305474 #102044
  CINEMATIC_124, CINEMATIC_131           #ebcb00
  ..._HOLO_CONSOLE_DOT_RISE_FAST         #fbfb74
  ..._LAB_DOOR_SCENE_LAMP                #fbfba7
  ..._PARTICLE_LAB_HOLO_CONSOLE_LED_3/4  #870000 #b78700
```

The rule that follows:

> A `canonical_md5` match carries a name across ports only when the picture has
> something to be identical *about*. For a two-pixel mark it has nothing, and
> the match must come from the offset and the draw site instead.

That is how `CINEMATIC_LAB_DOOR_SCENE_LAMP` was carried -- same constant name,
same offset 0x06CC, same single draw at `x=96, y=131` in the same loop -- and
`proposals_dos_1992__INTRO_collision_leftovers.md` says so in its evidence
column rather than claiming a hash it could not rely on.

Run it after rendering the stage at any palette; the comparison is between
constants at the *same* palette, so which one does not matter:

```
python3 notes/cross-port-art/colour_blind_hashes.py \
    --branch chahi_amiga_1991 --stage INTRO --renders <dir>
```

