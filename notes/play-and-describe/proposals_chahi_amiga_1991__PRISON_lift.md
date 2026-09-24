# PRISON (amiga): the lift car, and the two bodies riding in it

Four sentences from the 2026-09-25 session, at frame 6924:

- `ann:040ecc568ee3` on `CINEMATIC_103`: "this is the floor of the lift"
- `ann:37f3c77cb380` on `CINEMATIC_130`: "this rectangle seems to be the total
  size of the lift car / the lift-cabinet region, or something similar..."
- `ann:b11926ea82b6` on `CINEMATIC_102`: "i dont understand why, but this seems
  to be the bounding box of lester's body while he is travelling up or down in
  the lift"
- `ann:e46e510b56c1` on `CINEMATIC_131`: "i dont understand why, but this seems
  to be a polygonal bounding box of buddy's body while he is travelling up or
  down in the lift"

msdos and amiga hold all four at the same offsets and draw them in the same
routines; the measurement was taken on msdos.

The two "i dont understand why" sentences are the strongest rows in this batch,
and four measurements say so. None of them is a picture.

**1. The anchors assign the two bodies exactly as the person did**, and the
person had never read the tree. `PRISON.asm:14018-14021`:

    video offset=CINEMATIC_102, x=[HERO_X],  y=[HERO_Y]
    video offset=CINEMATIC_103, x=160,       y=[HERO_Y]
    je [0x11], 0x00, SCENE_DISPATCH_NOOP_RET
    video offset=CINEMATIC_131, x=[BUDDY_X], y=[BUDDY_Y]

`CINEMATIC_102` is drawn at the hero's anchor and `CINEMATIC_131` at the
companion's. The sentences say Lester and Buddy, in that order, unprompted.

**2. Buddy's is conditional and Lester's is not.** The `je [0x11], 0x00` skips
131 entirely, which is what a companion who may not be present looks like.

**3. The floor is exactly as wide as the car.** Measured extents:

    CINEMATIC_130   58.0 x 70.0   1 leaf     the car
    CINEMATIC_103   58.0 x  5.0   1 leaf     a 5-pixel strip, same width
    CINEMATIC_102   15.0 x 49.0   1 leaf     tall and thin
    CINEMATIC_131   29.0 x 60.0   1 leaf     wider and taller

58.0 against 58.0 is not a coincidence, and 15x49 against 29x60 is a slighter
figure against a bulkier one, which is these two characters.

**4. All four are ONE polygon in ONE colour, index 1.** A featureless
single-colour block is what the person was looking at and could not place --
these are silhouettes, not sprites, which is also why the question "why" came
up. The name says silhouette and claims nothing about why the scene uses them.

The actor words follow `docs/NAMING.md`: the person said Lester and Buddy, and
this stage's already-earned names at those anchors are `HERO_*` and `BUDDY_*`
(`DRAW_PRISON_HERO_POSE_0_1`, `DRAW_PRISON_BUDDY_POSE_3`), so the names take the
stage's words and the person's go in the evidence.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_130 | CINEMATIC_PRISON_LIFT_CAR_BODY | high | 0xD07E, drawn alone at the literal (160,100) by LABEL_7AE8 onto page 3; 58.0x70.0, one polygon, colour index 1; the same 58.0 width as the floor strip below; annot:37f3c77cb380 frame 6924, "the total size of the lift car" |
| CINEMATIC_103 | CINEMATIC_PRISON_LIFT_CAR_FLOOR | high | 0x8E7E, drawn at x=160 with y following [HERO_Y] (PRISON.asm:14019) and at the literal (160,129) at 13940; 58.0x5.0, one polygon, colour index 1 -- a five-pixel strip exactly as wide as CINEMATIC_130's car; annot:040ecc568ee3 frame 6924, "the floor of the lift" |
| CINEMATIC_102 | CINEMATIC_PRISON_LIFT_HERO_SILHOUETTE | high | 0x8E5E, drawn at x=[HERO_X], y=[HERO_Y] at PRISON.asm:13939 and 14018, unconditionally; 15.0x49.0, one polygon, colour index 1; annot:b11926ea82b6 frame 6924, "the bounding box of lester's body while he is travelling up or down in the lift" -- the anchor is the hero slot and the person named Lester with no access to it |
| CINEMATIC_131 | CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE | high | 0x9AF0, drawn at x=[BUDDY_X], y=[BUDDY_Y] at PRISON.asm:14021, behind `je [0x11], 0x00` so only when the companion is present; 29.0x60.0, one polygon, colour index 1, larger than the hero's in both axes; annot:e46e510b56c1 frame 6924, "a polygonal bounding box of buddy's body" -- the anchor is the companion slot and the person named Buddy |
