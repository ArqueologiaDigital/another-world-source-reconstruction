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

## Still unnamed, and now for a stated reason

F07..F13 keep the coordinate name, and the reason is no longer "we could not
tell". They are drawn at

    video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]

a different slot from both the hero pair and every literal anchor in this
scene. So they are a separate subject that merely shared a group name, which
is consistent with the render: 0x1 specks (F07, F08) and a 22x48/5 angular
shape beside a vertical line (F09..F13), magnified twice and still not
identifiable. The coordinate in their name is doubly wrong — they are not
drawn at 305,155 either.

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
