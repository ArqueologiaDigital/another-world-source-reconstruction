# CAPSULE: a figure dissolving, and a mass falling through a debris field

## `LABEL_10B1` / `LABEL_111D` / `LABEL_10ED` / `LABEL_1140`: one run, four anchors

`CINEMATIC_051` to `CINEMATIC_057` are drawn as a seven-frame run by **four**
different routines, at `[0xE9],[0xEA]`, at `2,103`, at `[0xEB],[0xEC]` and at
`179,100`. One effect, played in four places.

```
  051  32.0x47.0  10 paths     055  24.5x38.0   7 paths
  052  37.5x32.0   8 paths     056  16.5x31.5   7 paths
  053  32.0x24.5  11 paths     057   6.0x14.0   3 paths
  054  22.5x55.0  15 paths
```

Height falls 47.0 to 24.5 across the first three and then **jumps to 55.0** at
F3, which also has the most paths, 15. After that everything falls together:
38.0, 31.5, 14.0 tall and 7, 7, 3 paths.

Rendered, F0 is a standing figure with arms; by F2 the figure is a low mass
with narrow spikes rising out of it; F3 is those spikes at their tallest,
higher than the figure ever was and half its width; F4 to F6 are fewer, shorter
spikes and then almost nothing.

`CINEMATIC_058` is drawn once, by `LABEL_10B1` only, immediately before its
copy of the run: 29.5x47.5, six paths, a figure at the same place and scale as
F0 and without its arms.

## `LABEL_13B1`: fourteen frames that are three things

The routine draws 059 to 072 in order at `160,100`, and the extents sort them
into three groups that interleave:

```
  a mass with a trail        a debris field            the mass at rest
  060   84.0x 72.5  21p      059   74.5x 30.5   6p     065  55.5x36.5   6p
  061  108.5x114.5  24p      064  121.5x133.5  16p     067  48.0x35.5  10p
  062  131.5x139.5  24p      066  123.0x114.5  24p     069  43.0x35.5  10p
  063   84.0x 81.5  15p      068  124.0x 87.5  21p     071  37.5x35.5   8p
                             070  124.0x 64.5  39p
                             072  127.0x 37.5  36p
```

The debris field is the clearest: its width is **121 to 127 in every frame
after the first** while its height falls 133.5 to 37.5 and its y band walks
down, `[-63.5, 70.0]` to `[37.5, 75.0]`. A band of constant width whose top
edge descends and whose bottom edge stops is a field of things landing.

The four at rest share a y range to the half pixel -- `[8.5, 44.0]` for three
of them -- and shrink 55.5 to 37.5 wide. Nothing moves; it gets smaller.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_051 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0 | medium | 32.0x47.0, 10 paths: a standing figure with arms, the start of a run four separate routines play |
| CINEMATIC_052 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F1 | medium | 37.5x32.0, 8 paths: 15 shorter and 5.5 wider -- the figure going down |
| CINEMATIC_053 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F2 | medium | 32.0x24.5, 11 paths, the shortest of the seven: a low mass with narrow spikes coming out of it |
| CINEMATIC_054 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F3 | medium | 22.5x**55.0**, **15 paths**: the tallest and the most-pathed, and 9.5 narrower than F0. Taller than the figure ever was and half its width -- the spikes at their fullest |
| CINEMATIC_055 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F4 | medium | 24.5x38.0, 7 paths |
| CINEMATIC_056 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F5 | medium | 16.5x31.5, 7 paths |
| CINEMATIC_057 | CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F6 | medium | 6.0x14.0, **3 paths**: what is left |
| CINEMATIC_058 | CINEMATIC_CAPSULE_FIGURE_UPRIGHT | medium | 29.5x47.5, 6 paths: a figure at the same place and scale as `_DISSOLVE_F0`, four paths fewer and with no arms. Drawn once, by `LABEL_10B1` only, immediately before its copy of the run. No index: one picture, not a family |
| CINEMATIC_060 | CINEMATIC_CAPSULE_FALLING_MASS_F0 | medium | 84.0x72.5, 21 paths: a round mass with straight lines trailing behind it, upper left |
| CINEMATIC_061 | CINEMATIC_CAPSULE_FALLING_MASS_F1 | medium | 108.5x114.5, 24 paths: 24.5 wider and 42 taller, the trail longer and the mass further down and right |
| CINEMATIC_062 | CINEMATIC_CAPSULE_FALLING_MASS_F2 | medium | 131.5x139.5, 24 paths: the largest extent in the whole run |
| CINEMATIC_063 | CINEMATIC_CAPSULE_FALLING_MASS_F3 | medium | 84.0x81.5, 15 paths, x[-66.0, 18.0]: the mass has crossed the anchor and the trail is short |
| CINEMATIC_065 | CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F0 | medium | 55.5x36.5, 6 paths, y[8.5, 45.0]: the mass with a stub of trail, low and right. The four in this family share a y range to the half pixel |
| CINEMATIC_067 | CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F1 | medium | 48.0x35.5, 10 paths, y[8.5, 44.0] |
| CINEMATIC_069 | CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F2 | medium | 43.0x35.5, 10 paths, y[8.5, 44.0] |
| CINEMATIC_071 | CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F3 | medium | 37.5x35.5, 8 paths, y[8.5, 44.0]: 18 narrower than `_F0` at the same height and the same place |
| CINEMATIC_059 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F0 | medium | 74.5x30.5, 6 paths, y[-114.0, -83.5]: a few small angular pieces, the highest thing in the run and the only frame of this family narrower than 121 |
| CINEMATIC_064 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F1 | medium | 121.5x133.5, 16 paths, y[-63.5, 70.0] |
| CINEMATIC_066 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F2 | medium | 123.0x114.5, 24 paths, y[-44.5, 70.0]: the top edge has come down 19, the bottom has not moved |
| CINEMATIC_068 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F3 | medium | 124.0x87.5, 21 paths, y[-17.5, 70.0] |
| CINEMATIC_070 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F4 | medium | 124.0x64.5, **39 paths**, the most in the run, y[9.5, 74.0] |
| CINEMATIC_072 | CINEMATIC_CAPSULE_DEBRIS_RAIN_F5 | medium | 127.0x37.5, 36 paths, y[37.5, 75.0]: everything is in the bottom 37 pixels of the band |

## What these names do not claim

`DISSOLVE` is a figure becoming tall narrow spikes that then dwindle to three
paths. It is **not** the same animation as
`CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F0..F14`, which has fifteen frames and
whose path count *grows* 6 to 35; `frame_runs.py --stages` reports no shared
art between them. The two are named with different words for that reason.

`MASS` is a round shape with straight lines behind it. It does not say what
the shape is, and `LANDED` is the y range holding still at `[8.5, 44.0]` while
the width falls -- not an impact, which no frame shows.

`RAIN` is a band 121 to 127 wide whose top edge descends while its bottom edge
stops. It does not claim the pieces and the mass are the same material or the
same event, only that the routine draws them in one run.
