# Naming the shared bank, now that a name can mean one thing

`docs/NAMING.md` §2 forbade hand-naming the shared bank "until that lands",
where "that" is plan item **T7**. T7's source half landed on 2026-09-19: the
bank is re-keyed from per-port encounter order to `CV_<OFFSET4>`, which is
port-invariant because the bank is literally one file — resource 0x11, 25,108
bytes, identical sha256 on amiga and msdos.

That is what makes naming worth doing at all. Before, identifying a picture
told you about `COMMON_VIDEO_099` on amiga and **nothing** about msdos,
because that same label is a different picture there: 346 of 353 names denoted
different art across the two ports. Now one identification names the art
everywhere, so these renames are global rather than per branch.

## The pipeline, which is the actual unlock

The renderer takes the bank directly and **names its output by offset** —
which is exactly the key T7 created:

```bash
cd another-world-archaeology
~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
    --port amiga --stage 3 --bank video2 \
    --romset tmp/output/amiga/romset --out /tmp/cv_svg --palette 2
# -> /tmp/cv_svg/amiga_stage3_group_0x40CA.svg, one file per offset
```

`--bank video2` is the shared bank; the default `cinematic` is the per-stage
one. For amiga that walked 1,212 polygons (822 solid, 390 group) and wrote
1,212 SVGs.

Contact sheet, ranked by how many references each key carries — naming a
heavily-referenced one is worth more:

```bash
cd another-world-source-reconstruction
grep -rho '\bCV_[0-9A-F]\{4\}\b' src/levels/chahi_amiga_1991/ \
  | sort | uniq -c | sort -rn | head -12 | awk '{print $2}' \
  | while read k; do off=${k#CV_}
      magick -background '#909090' -density 600 /tmp/cv_svg/*_0x$off.svg \
        -trim +repage -resize 240x240 -bordercolor '#909090' -border 12 \
        /tmp/lab_$off.png
    done
magick montage -label '%t' /tmp/lab_*.png -tile 6x -geometry +8+8 \
    -background '#101010' -fill white -pointsize 20 /tmp/sheet.png
```

Two details that cost a round each: **trim before resizing** or every shape is
a speck in a 320×200 frame, and put the label **outside** the image
(`montage -label`) rather than annotating over it, or the text covers the art
you are trying to identify.

## First six names

| key | offset | what the render shows |
|---|---|---|
| `CV_FIGURE_CROUCH_FACING_LEFT` | 0x3E4E | low crouched body, boot pointing left |
| `CV_FIGURE_FRONT_STANCE_WIDE` | 0x3F8C | front-on, legs apart, boots splayed |
| `CV_FIGURE_FRONT_STANCE_NARROW` | 0x3FD4 | front-on, legs closer, knees bent |
| `CV_FIGURE_PROFILE_STANCE` | 0x40CA | profile, legs together, standing |
| `CV_FIGURE_PROFILE_STRIDE` | 0x40EC | profile, one leg forward, mid-stride |
| `CV_FIGURE_CROUCH_FACING_RIGHT` | 0x4132 | mirror of 0x3E4E, boot pointing right |

588 tokens across 48 files, on three branches and the unified tree, from six
renames — which is the point of the port-invariant key.

## What the names deliberately do not say

**Whose** body it is. These draw at `x=[0x07], y=[0x08]`, the actor-context
slot whose occupant is set by whichever channel filled it (#0138, and
`notes/draw-slot-probes/`). `CAVES_HERO_PER_FRAME_TICK` and
`CAPSULE_BUDDY_PER_FRAME_TICK` are parallel routines that both draw
`CV_FIGURE_PROFILE_STANCE` right after calling the same sprite dispatcher —
each animating whoever its stage has. That is correct, not a conflict, and it
is exactly why the polygon cannot carry a character.

The offset is not lost: the EQU keeps it
(`CV_FIGURE_PROFILE_STANCE EQU 0x40CA`), so anything can be re-rendered.

## `asset_naming_share.py` — the metric that was missing

Naming six assets moved the lint's per-stage percentage by **zero**, and that
is correct: its docstring says it counts "strict-semantic **labels**", and the
code divides by `len(labels)`. Labels are routines. The goal is bytecode *and
assets*, and the asset layer had counts but no denominator, so there was no
number to put beside PRISON's 32.0 %.

```
port/stage          assets   named  numbered  offset-key  named %
amiga/LAKE             742     741         0           1    99.9%
amiga/CODE_WHEEL        54      53         1           0    98.1%
amiga/INTRO            569     459       110           0    80.7%
amiga/PRISON           986     138       554         294    14.0%
amiga/CAPSULE          892      72       479         341     8.1%
amiga/CAVES           1218      78       794         346     6.4%
amiga/TANK             224       0       224           0     0.0%
amiga/ENDING           133       0       108          25     0.0%
...
TOTAL                10145    2818      5176        2151    27.8%
```

`CV_<4 hex>` counts as **unnamed**. It is a real improvement — the same art on
every port, so one identification serves all — but it is not an
identification.

The distribution is the useful part, and the label percentage hides it: LAKE
and CODE_WHEEL are effectively finished, INTRO is 80.7 % on amiga and 33.9 %
on msdos, and TANK-amiga and ENDING have not been started at all.
