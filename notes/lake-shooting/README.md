# LAKE: the scene the coordinate group was hiding

`../lake-decor-split/` split `CINEMATIC_DECOR_AT_305_155_*` — the group whose
name NAMING.md §1 uses as its example of what not to write — and named seven
members. It left a remainder and described part of it like this:

    F01..F04  ~40x16/12  drifting decor (DECOR_F1_DRIFT_LOOP, F2_DRIFT_LOOP)

**That is wrong.** F01..F04 are not decor and nothing drifts. They are the
hero, and the group's four "decor" frames are the last four frames of the
scene in which he is shot. That note is corrected in the same commit as this
one.

## How the error survived a render

The first pass rendered the group and grouped what it saw. The frames *look*
like low wide shapes and the drawer labels said `DRIFT`, so the two agreed
and the reading stopped there — but the drawer labels were themselves guesses
from the same pass, so the agreement was circular. Nothing had checked the one
fact that settles it, which is in the operand, not the picture:

    video offset=CINEMATIC_DECOR_AT_305_155_F1, x=[HERO_X], y=[HERO_Y]

Decor is not drawn at the hero's coordinates. The four frames sit at the same
slot as the four established `CINEMATIC_LAKE_LESTER_*` frames immediately
before them, and are contiguous with them in one straight line of code.

## What the scene is

`shooting_scene_geometry.py` measures anchor + signed bbox, so every piece
gets a screen span rather than a size. The spans compose into one event:

    CINEMATIC_LAKE_DECOR_AT_327_164     x 282..345  y 126..184   5 leaves
    CINEMATIC_LAKE_SCENE_DECOR_RIGHT    x 279..344  y 126..184   5 leaves

A figure at the right screen edge (the screen is 320 wide, so it is half
off it), with an arm extended LEFT holding a barrel. Two frames differing
only in how far that arm reaches: -45 against -48 from the anchor.

    CINEMATIC_DECOR_AT_305_155_F0       x 282..328  y 154..156   1 leaf
    CINEMATIC_DECOR_AT_327_164_F0       x 232..454  y 148..164   5 leaves
    CINEMATIC_DECOR_AT_327_164_F1       x 100..314  y 154..156   3 leaves
                        (again)         x -40..174  y 154..156
                        (again)         x -166..46  y 154..156

A beam. It starts against the figure's left edge at barrel height, and the
spans step leftwards one per frame until they are off the screen. The first
draw carries `play id=0x0052`. The 47x3 bar at the muzzle runs in its own
channel from the shot until the body stops moving.

    CINEMATIC_LAKE_LESTER_RECOVER       216 wide, 18 leaves, at the hero slot

Not a pose at all: a group of a 17x26 solid and three 213x1 bars — the same
bar primitive as the beam span. It is the beam arriving, drawn at the hero.

Then the hero anchor, with the step read off the `sub`/`add` before each draw:

    LESTER_RECOVER     dx  -3  dy -2
    LESTER_RISE        dx -12  dy +3     (x2)
    ..._F1             dx -10  dy +5     (x2)
    ..._F2             dx  -3           (x4)
    ..._F3             dx  -2
    ..._F4             dx  -1            then held forever

62 px leftwards, decelerating monotonically, descending. The bodies measure
65x25, 41x19, 29x23, 39x16, 43x13 against 48 tall standing — horizontal, and
flattening. The last frame is held in a loop while the channel it frees is
handed to `LAKE_PALETTE_FADE_IN`.

A figure at the right edge fires left; the hero is hit, thrown backwards,
skids to a stop and does not get up.

`CINEMATIC_LAKE_LESTER_RISE` was therefore also false — it is the first
airborne frame of that throw, moving left and **down**.

## Applied: 11 constants, 7 routines

    CINEMATIC_LAKE_SHOOTER_AIM_LEFT_F0, _F1    (was ..._DECOR_AT_327_164,
                                                    ..._SCENE_DECOR_RIGHT)
    CINEMATIC_LAKE_SHOT_BEAM_HEAD              (was ..._AT_327_164_F0)
    CINEMATIC_LAKE_SHOT_BEAM_SPAN              (was ..._AT_327_164_F1)
    CINEMATIC_LAKE_SHOT_MUZZLE_BEAM            (was ..._AT_305_155_F0)
    CINEMATIC_LAKE_SHOT_BEAM_IMPACT            (was ..._LESTER_RECOVER)
    CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F0..F4  (was ..._LESTER_RISE,
                                                    ..._AT_305_155_F1..F4)

    SHOOTER_AIM_HOLD_LOOP              (was DECOR_AT_327_164_SCENE_RIGHT_LOOP)
    SHOT_BEAM_SWEEP_LEFT               (was DECOR_AT_327_164_BLINK_LOOP)
    SHOT_MUZZLE_BEAM_LOOP              (was DECOR_AT_305_155_F0_LOOP)
    LESTER_KNOCKED_BACK_F0_LOOP        (was LESTER_RISE_LOOP)
    LESTER_KNOCKED_BACK_F1_LOOP        (was DECOR_F1_DRIFT_LOOP)
    LESTER_KNOCKED_BACK_F2_LOOP        (was DECOR_F2_DRIFT_LOOP)
    LESTER_KNOCKED_BACK_F4_HOLD_LOOP   (was DECOR_F4_HOLD_LOOP)

Constants went through `apply_cinematic_renames.py`, which checks collisions,
refuses coordinates in a name and refuses a proposal that would add a gap to a
family run: 11 accepted, 0 rejected, 71 files, every port still byte-matching.
The routine labels were substituted globally because all four branches define
all seven under the same spelling.

Coordinate-embedding `CINEMATIC_*` names drop from 15 to **7**.

## What is deliberately NOT claimed

**Species.** The figure at x=327 is a silhouette. The repo does use `ALIEN`
(`CINEMATIC_ENDING_ALIEN_WALK_F0..F5` and others), and this is very likely one,
but nothing measurable here says so — a silhouette with a barrel is a shooter
whatever it is. `SHOOTER` is the role the geometry proves: the beam's y-range
(148..164) meets the barrel's, and its first span abuts the figure's left edge
at x=282. If the species is settled later from other evidence, the rename is a
one-word edit.

**Whether the hero dies.** He is hit, thrown 62 px and held motionless under a
fade. `KNOCKED_BACK` is what the anchor arithmetic shows. Whether the scene
kills him or hands him to the next stage is not in these bytes, and
`CINEMATIC_HERO_DEATH_F0..F2` — the existing death frames shared by PRISON,
CAVES and CAPSULE — are **not** this art: a cross-stage `canonical_md5` sweep
over every named picture in all nine stages matched none of these sixteen.

## The rest of the group: F07..F13, and why two renders had missed them

F07..F13 are drawn at

    video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]

a different slot from both the hero pair and every literal anchor in the
shooting scene, so they were never part of it. Tracing that slot is what
identified them. `[0x32],[0x33]` is not a position: it is a *shared* one that

    MULTIPLEX_ANIM_RING3_SLOT_0:
        mov [0x4C], [0x32] / mov [0x4D], [0x33] / mov [0x4E], [0x14]
        mov [0x32], [0x46] / mov [0x33], [0x47] / mov [0x14], [0x48]
        break / jmp MULTIPLEX_ANIM_RING3_SLOT_0

rotates between three records every frame. Three of those run on channels
0x0B, 0x0E, 0x11, interleaved by channel number with three reed loops (0x0C,
0x0F, 0x14), two speck loops (0x0D, 0x10) and one sway loop (0x15): a
cooperative multiplexer that lets one set of draw loops serve three reeds at
three positions, each walked left a pixel per draw by
`DRAW_REED_DRIFT_LEFT_LOOP`. So F07..F13 share the *reed's* anchor.

That is also why two passes had failed on them. Rendered one offset per SVG,
F09..F13 are "a small angular shape beside a vertical line". Drawn at the
anchor they share with `CINEMATIC_LAKE_REED`, by `composite_at_anchor.py`,
they are a stalk with two fronds standing over the reed's trunk — and
`REED_SWAY_CYCLE` plays them 9,10,11,10,9,12,13,12 and repeats, a ping-pong
about F09.

**The lean does not order them.** Measuring top-point x minus bottom-point x
per frame gives 18.5, 18.5, 19.5, 20.0, 23.5 with F10 and F13 exactly tied —
the shape has two stalks and the metric cannot separate them. So the index
comes from the play cycle, not from geometry: F0 is the frame the cycle
returns to twice, F1/F2 are the first excursion and F3/F4 the second. Offset
order agrees with that reading, which is the check, not the source.

**F07 and F08 are the same picture.** Both are 10-byte records:

    F8 @0xDC0A: 02 80 80 00 ec 35 72 56 04 80
    F7 @0xDC14: 02 80 80 00 ec 35 72 56 04 6e

A group header, pivot 0x80,0x80, one child at (0xEC35 & 0x7FFF)*2 = 0xD86A
with a colour override. The colour byte is `04` in both; the byte after it is
the one `readAndDrawPolygonHierarchy` fetches and throws away. Identical
`canonical_md5`, identical bbox — a 0x1 hairline at (-14,-42.5), inside the
reed's box near its top. So `DECOR_F7_BLINK_3X_LOOP` alternated two constants
that draw the same thing: the blink it was named for does not exist.

### Applied: 7 more constants, 13 more routines

    CINEMATIC_LAKE_REED_TIP_SPECK_F0, _F1   (was ..._AT_305_155_F7, _F8)
    CINEMATIC_LAKE_REED_SWAY_F0..F4         (was ..._AT_305_155_F9..F13)

    REED_TIP_SPECK_LOOP, _F0_HOLD, _F1_HOLD
    REED_SWAY_CYCLE, REED_SWAY_F0..F4_HOLD,
    REED_SWAY_F0_RETURN_HOLD, _F1_RETURN_HOLD, _F3_RETURN_HOLD
    REED_SWAY_F0_TO_BACKGROUND              (was DECOR_AT_305_155_F14_F9_BG)

`_unified/lake/lake_decor_at_305_155.inc` is renamed to
`lake_reed_sway_and_tip_speck.inc`, and its header comment — which asserted
"fixed screen position (305, 155)" — is rewritten to describe the
multiplexer.

**Coordinate-embedding `CINEMATIC_*` names in the tree: 0.** The class the
rule was written for is gone. 34 identifiers of other kinds still carry
coordinates (`SHOW_TEXT_*_AT_x_y`, `DRAW_CIN_*_AT_x_y`, and in LAKE the single
`LOOP_DRAW_LAKE_097_DECOR_AT_71_171`); most are text-placement labels where
the coordinate is the argument, which is a different question.

## Running it

    python3 notes/lake-shooting/shooting_scene_geometry.py
    python3 notes/lake-shooting/shooting_scene_geometry.py --port msdos

Prints the table above plus the cross-port check: **16 of 16 pictures in this
scene are byte-identical between amiga and msdos** by `canonical_md5`, which
is why one name is right for both and the shared unified chunks stay
consistent. The renders it is checked against are regenerated with

    awvm-render-polygons --port amiga --stage 2 --romset <dir> \
        --bank cinematic --out <dir>

and are not committed: they are a few hundred SVGs and the command above
remakes them. The numbers that matter are in the probe's output, not the
pictures.
