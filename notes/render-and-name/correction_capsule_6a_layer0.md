# `CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0` is a backdrop layer in msdos and cartridge, and a 26-pixel blob in amiga

## How the contradiction surfaced

`notes/cross-stage-widget/same_widget.py --port amiga --pairs PRISON:CAPSULE`
reported

    CAPSULE  CINEMATIC_384  0x875A  ==  PRISON  CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0  ...

on a **26.0x22.0, three-leaf** tree. A screen backdrop layer that small is not
a backdrop layer. Measuring the same name in the port it was earned on settles
it:

```
  msdos  CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0  0xF9A8  459.0x232.5  54 leaf
  amiga  CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0  0x3E1C   26.0x22.0    3 leaf
```

`notes/cross-port-art/name_art_agreement.py` already had it in its
"name on the wrong constant" list -- it was simply never worked. This is that
row being closed.

## Why the wrong constant got the name

The name was earned on msdos, on `CINEMATIC_000`, by
`notes/remaining-art/proposals_dos_1992__CAPSULE.md`: msdos'
`CAPSULE_SCREEN_6A_BACKDROP_DRAW` is `fill`, then two pictures at one anchor,
then `ret`, and this is position 0 of 2. That reading is correct, and msdos
keeps the name.

What went wrong is the **scope of the apply**. The three entry files are
parallel by index, line for line:

```
  amiga__entry.inc:643   CINEMATIC_000   EQU 0x3E1C
  dos__entry.inc:643     CINEMATIC_000   EQU 0xF9A8
  cart__entry.inc:643    CINEMATIC_000   EQU 0xDBD4
```

so a rename of `CINEMATIC_000` applied **globally** rather than `--branch
dos_1992` lands on all three ports' index 0 -- which is #0107 exactly, the
hazard the whole naming convention exists to prevent, arriving through the
applier rather than through a proposal. The sibling row in the same batch,
`CINEMATIC_001 -> ..._LAYER_1`, *was* branch-scoped and touched only
`dos__entry.inc:644`, which is why amiga has a `LAYER_0` and no `LAYER_1`: a
one-member family, and that asymmetry was the visible symptom all along.

> A numbered constant is a per-port index. Renaming one is **never** a global
> operation unless the art has been shown identical in every branch it
> touches.

## What amiga's constant actually is

Rendered at palette 14 (`palette_in_force.py` on `LABEL_40B6`), three nested
irregular blobs -- `#444464` rim, `#0097fb` middle, `#fbfbfb` core -- 26x22:

    <path fill="#444464" d="M167 82 L172 88 L170 99 L165 104 L154 104 L146 99 L149 88 L158 82 Z"/>
    <path fill="#0097fb" d="M163.5 86 L168.5 90 L170.5 95 L163.5 102 L148.5 102 L147.5 95 L151.5 90 L152.5 86 Z"/>
    <path fill="#fbfbfb" d="M166.5 88.5 L168.5 94.5 L161.5 99.5 L156.5 99.5 L153.5 94.5 L155.5 88.5 Z"/>

A white-hot core in a blue halo. It is drawn in exactly two situations, and
both are the same event:

**1. The last frame of the charge widget.** `LABEL_411F`, the target of every
`je [0x09], 0x01` guard in the glow loop, draws it at `[BUDDY_X], [BUDDY_Y]`
at `zoom=0x96` (1.5x) -- the cycle of `SEGMENT_BAR` -> `DISCHARGE_FLASH` ->
`CHARGE_GLOW_F0..F3` ends here. In msdos the same draw is followed immediately
by **four simultaneous** `play id=0x005B` on channels 0..3, which is as loud as
this stage gets.

**2. Where a target stops existing.** Three routines, one per actor, each:

    deleteChannels first=0x2A, last=0x2B      ; that actor's two channels
    mov [0x13], 0x0070
    add [0x21], 0x0010
    add [0x27], 0x0028
    mov [0x4B], 0x7FFF
    video offset=<this>, x=[0x70], y=93, zoom=0x5a

`[0x70]`, `[0x6e]` and `[0x72]` hold screen x positions (`0x012C`, `0x0064`,
`0x0122`, `0x0032` elsewhere in the stage); `y=93` is their common standing
height. The actor's animation is deleted and this is drawn where it stood.

So: the blast the charge produces, and the mark it leaves on what it hits.

## The name

`CINEMATIC_<STAGE>_CHARGE_BLAST` -- it terminates the
`SEGMENT_BAR`/`DISCHARGE_FLASH`/`CHARGE_GLOW` sequence and it is what is drawn
where the charge lands.

Deliberately **not** `..._SHOT_IMPACT_BURST_*`: that family already exists in
CAPSULE and is a nine-frame collapse from 53.5x68.0 in 7 leaves down to
20.0x1.0 in 4, a different animation entirely. And deliberately not
`ENERGY_BURST`, which would read as a member of it.

`medium`: the picture is measured and rendered, the two draw contexts are
read off the disassembly, but "charge" is the widget's already-agreed word
rather than an independently established fact.

## Rows

amiga/CAPSULE:

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0 | CINEMATIC_CAPSULE_CHARGE_BLAST | medium | 0x3E1C, 26.0x22.0 in 3 leaves, `f5c16106ac46`. No amiga routine draws it at 160,100 and amiga has no `..._LAYER_1`; it is drawn once at `zoom=0x96` at the end of the charge loop and three times at `zoom=0x5a` where an actor's channels have just been deleted |
