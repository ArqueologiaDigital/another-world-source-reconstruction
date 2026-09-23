# CAPSULE: two small figures, one walking into place and one sinking

Palette 1 (`palette_in_force.py` on `ANIM_CIN_027_LOOP_VARE8`), each constant
rendered alone and cropped to its own extent.

## The one that walks and stops

Three routines -- `LABEL_0DED`, `LABEL_0E13`, `LABEL_0E3D` -- do the same thing
at three places, each with `play id=0x0057` or `0x0075` on the first frame:

```
  video 029, x=216, y=149        video 029, x=72,  y=143     video 029, x=213, y=149
  video 029, x=218, y=149        video 029, x=75,  y=143     video 029, x=231, y=150
  video 030, x=220, y=149        video 030, x=77,  y=143     video 029, x=233, y=150
  video 030, x=222, y=149        video 031, x=79,  y=143     video 030, x=235, y=150
  video 031, x=223, y=149        selectVideoPage 0x00        video 030, x=236, y=150
  selectVideoPage 0x00           video 031, x=80,  y=144     video 031, x=238, y=149
  video 031, x=223, y=148        selectVideoPage 0xFF        selectVideoPage 0x00
  selectVideoPage 0xFF           killChannel                 video 031, x=239, y=149
```

x only ever increases, 029 and 030 alternate two frames each, and 031 is always
last and always painted into **page 0** -- the walk ends and the figure is baked
into the backdrop where it stopped. Every one of 029's eight sites and 031's six
follows that pattern.

Rendered: a figure in a dark tunic with a **red belt**, teal and pale limbs,
one cyan boot. 029 has its legs apart mid-stride, 030 has one leg forward, 031
stands with an arm across the chest. `CINEMATIC_032` is the same figure again,
also painted into page 0 and also last, but 21.0x40.5 against 031's 15.5x29.5 --
half again as large.

## The one that sinks

`ANIM_CIN_027_LOOP_VARE8` holds 027 in a `djnz` loop, then plays 028, 024, 025
and repeats 025 at `x=137` with y going 100, 102, 106, 108, 112, 116, 120 --
**descending**, one pose held. All four are a hooded, robed figure in profile:
teal robe, pale face, 13.0 to 14.5 wide and 23.5 to 29.0 tall, three to six
leaves. They are named as frames in the order the routine plays them, which is
not the order of their numbers.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_029 | CINEMATIC_CAPSULE_TUNIC_FIGURE_WALK_RIGHT_F0 | medium | 0xBA22, 22.5x33.5 in 14 leaves, legs apart mid-stride; drawn first and second in every one of the three walks, x increasing |
| CINEMATIC_030 | CINEMATIC_CAPSULE_TUNIC_FIGURE_WALK_RIGHT_F1 | medium | 0xB97A, 20.0x34.5 in 10 leaves, one leg forward; drawn third and fourth, x still increasing |
| CINEMATIC_031 | CINEMATIC_CAPSULE_TUNIC_FIGURE_STANDING_SMALL | medium | 0xBA64, 15.5x29.5 in 10 leaves, standing with an arm across the chest; always the last draw of a walk and always into page 0 |
| CINEMATIC_032 | CINEMATIC_CAPSULE_TUNIC_FIGURE_STANDING_LARGE | medium | 0xBDC6, **21.0x40.5** in 13 leaves, the same standing figure half again as large, its one draw also into page 0 at the end of a walk |
| CINEMATIC_027 | CINEMATIC_CAPSULE_ROBED_FIGURE_F0 | medium | 0xB14A, 14.5x29.0 in 6 leaves, hooded and stooped; held in the `djnz` loop that opens the routine |
| CINEMATIC_028 | CINEMATIC_CAPSULE_ROBED_FIGURE_F1 | medium | 0xB166, 14.0x25.5 in 6 leaves; drawn once, straight after the loop |
| CINEMATIC_024 | CINEMATIC_CAPSULE_ROBED_FIGURE_F2 | medium | 0xB182, 13.0x24.0 in 6 leaves, more upright; third |
| CINEMATIC_025 | CINEMATIC_CAPSULE_ROBED_FIGURE_F3 | medium | 0xB1C6, 13.0x23.5 in **3** leaves, the plainest; fourth, and then held while y goes 100, 102, 106, 108, 112, 116, 120 |
| CINEMATIC_026 | CINEMATIC_CAPSULE_LIT_PANEL | medium | 0xB8CE, 15.0x24.0 in **one** leaf, a plain filled cyan rectangle; drawn twice a pixel apart beside a walk and once at 160,100 |

`medium` throughout. What is measured: the sizes, the leaf counts, the walk's x
direction, which draw goes into page 0, and the descent. What is read off the
render: "tunic", "robed", "hooded", and that 029 and 030 are two phases of one
gait. Nothing claims who either figure is -- `../actor-anchors/` is why the
anchor could not have told us anyway.
