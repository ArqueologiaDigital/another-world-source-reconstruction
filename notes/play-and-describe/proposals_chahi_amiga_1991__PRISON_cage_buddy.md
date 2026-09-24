# PRISON (amiga): Buddy in the cage, named from the scene and a width

`ann:6ffbe43f0af1` on `CINEMATIC_035`, frame 118: "this is buddy sitting down
inside the cage".

This is the constant `notes/on-screen-priority/` ranks first in the whole stage
-- on screen for **284 of 400 frames**, longer than anything that has a name --
and the one that probe could describe only as "a routine nobody named draws
something nobody named, for most of the stage".

Buddy is a specific character, an alien who befriends Lester, and the guards are
aliens of the same species (`../actor-anchors/README.md`, section "2026-09-25").
So the actor word here may come from the **scene** and from nothing else: not
from the anchor, and not from looking, because between two aliens of one species
a render shows the species.

**The scene.** `CINEMATIC_035` is drawn at `[0x1a],[0x1b]` -- a per-scene scratch
anchor, not an actor's; the same pair positions the eye close-up pupils, the cage
landing, the cage debris and the flexing band. In the swing loop it is drawn
FIRST, before `LABEL_7473` lays the cage and Lester over it, and two lines later
the routine installs `PRISON_GUARD_GUN_KNOCKED_ARC` on channel 0x12: this
passage is the hanging cage and its collapse. So the figure is inside or behind
the cage, in the scene where Lester and Buddy are both caged.

**The width, and this is the part that came from measurement.** Two silhouettes
named earlier today had their identities fixed by their anchors alone -- one
drawn at `[HERO_X],[HERO_Y]` unconditionally, the other at `[BUDDY_X],[BUDDY_Y]`
behind a `je [0x11], 0x00` companion gate. They give each character's build:

    CINEMATIC_PRISON_LIFT_HERO_SILHOUETTE    15.0 x 49.0    Lester
    CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE   29.0 x 60.0    Buddy
    CINEMATIC_PRISON_CAGE_HERO_TILT_ZERO     23.5 x 49.5    Lester, in the cage
    CINEMATIC_035                            27.5 x 34.5    ?

27.5 sits beside Buddy's 29.0 and nowhere near Lester's 15.0, and the same
stage's standing Lester in the cage is 23.5. The height is the other half: 34.5
against Buddy's standing 60.0 is a figure **sitting down**, which is what the
sentence says and what the numbers say separately.

10 leaves at colour indices 6, 0, 6, 9, 0, 0, 9, 6, 6, 5 -- a detailed figure,
not a silhouette or a mask.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_035 | CINEMATIC_PRISON_CAGE_BUDDY_SEATED | high | 0x23B4, drawn at the per-scene anchor [0x1a],[0x1b] -- NOT an actor anchor -- first in the cage swing loop before LABEL_7473 lays the cage and Lester over it, in the passage that installs PRISON_GUARD_GUN_KNOCKED_ARC two lines later, so the scene is the hanging cage and its collapse. 27.5x34.5 in 10 leaves: the width sits beside CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE's 29.0 and nowhere near the hero's 15.0 or the caged hero's 23.5, and 34.5 against Buddy's standing 60.0 is seated. annot:6ffbe43f0af1 frame 118, "this is buddy sitting down inside the cage". The actor word is taken from the scene, per ../actor-anchors/ -- the species makes a render unable to tell these two apart |
