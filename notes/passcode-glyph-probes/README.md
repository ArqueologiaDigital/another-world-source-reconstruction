# PASSCODE's 17 glyph constants — what is established, and what blocks naming

amiga PASSCODE has 57 unnamed `CINEMATIC_NNN` constants. Seventeen of them,
`CINEMATIC_000`..`CINEMATIC_016`, are the arms of one dispatch ladder and look
like the cheapest asset-naming win in the stage. They are **not named**, and
this records how far the reading got so the next attempt starts here instead of
at the renders.

## Established

**The dispatch is traced, not assumed.** The ladder at PASSCODE.asm:229-296
keys on `[0x05]`, one arm per value `0x00`..`0x10`, each drawing one constant at
`x=[0x2d], y=[0x2e]`:

| `[0x05]` | constant | offset |
|---|---|---|
| 0x00 | `CINEMATIC_016` | 0x0F64 |
| 0x01 | `CINEMATIC_015` | 0x0F74 |
| … | … | … |
| 0x10 | `CINEMATIC_000` | 0x104C |

so value N selects `CINEMATIC_(0x10 − N)`. That mapping is what the arm names
`PASSCODE_ALPHANUM_CODE_CASE_01`..`_10` were checked against when they landed
(2026-09-19); `apply_routine_renames.py` verifies a `_CASE_<n>` tail against the
arm's own first-line guard, so the table above is machine-checked.

**They are not the CODE_WHEEL alphabet.** `CINEMATIC_ALIEN_GLYPH_00..29` in
CODE_WHEEL are large graphical sigils — arrows, hexagons, decagons, a bracket
pair — rendered 60-100 px. PASSCODE's seventeen are chunky 5-30 px pixel runes.
Rendering both settles it at a glance; the two sets share no shape.

**Their geometry is measured** (`polygon_extent.py --stage 8 --port amiga`), and
it is the reason naming stalled:

| `[0x05]` | size | leaves | box |
|---|---|---|---|
| 0x00–0x04 | 28-30 × **14** | 18-29 | x 126..156, y 116..130 |
| 0x05–0x09 | 18-20 × 7 | 22-28 | x 136..156, y 116..122 |
| 0x0A–0x0F | 12-14 × 7 | 11-16 | x 135..148, y 116..122 |
| 0x10 | **5 × 7** | 9 | x 126..130, y **122..130** |

All seventeen are authored inside one small box and differ in how much of it
they fill: the first five are two 7 px rows tall, the next eleven one row, and
the last is a single 5 × 7 cell sitting in the *lower* row at the left edge.
Rendered, the wide ones read as two or three rune-like shapes side by side.

## The blocker

The driver does not behave like a 17-cell chart, which is the obvious reading
and is wrong.

```
SETUP_PASSCODE_SCREEN:                       (PASSCODE.asm:165)
        mov [0x09], 0x0010                   ; 16 iterations
        text id=0x013E … "   ENTER ACCESS CODE"
        text id=0x013C … "        ACCESS CODE:"
        mov [0x2D], 0x0072                   ; 114, 62 — set ONCE
        mov [0x2E], 0x003E
        mov [0x05], 0x0000
DRAW_LETTER_AT_PAGE_00:
        call PASSCODE_GRID_KEY_LOOKUP_CASE_00    ; [0x06] = code buffer[ [0x05] ]
        selectVideoPage 0x00
        call DERIVE_AND_DRAW_LETTER
        selectVideoPage 0xFF
        add [0x05], 0x0001
        djnz [0x09], DRAW_LETTER_AT_PAGE_00
```

Two things do not fit:

1. **`[0x2D]`/`[0x2E]` never change inside the loop.** All sixteen draws land at
   the same anchor, so the seventeen constants are not "one per grid cell laid
   out across the screen" — whatever separates them is baked into the polygon's
   own coordinates, and those overlap almost completely.
2. **There is a second, different ladder for characters.** `[0x06]` — loaded by
   `PASSCODE_GRID_KEY_LOOKUP_CASE_<n>` from the per-cell buffer `[0x0A + n]` —
   drives `PASSCODE_GLYPH_DIGIT_2`..`_9`, `PASSCODE_GLYPH_LETTER_A` and the rest
   (PASSCODE.asm:823+). *That* is the character→glyph map. So the `[0x05]`
   ladder is keyed on the cell **index**, not on the character in it, and the
   17 constants are something else again.

The real grid is 8 × 2 and is computed elsewhere:
`PASSCODE_GRID_CELL_POSITION` does `[0x07] = [0x05] & 7` for the column and
`[0x08] = ([0x05] & 8) ? 0x96 : 0x86` for the row — y 134 or 150. The 17
constants live at y 116..130, above both rows.

## Progress 2026-09-19: the category is settled, the text is not

Three things changed, and one of them closes the experiment this file used to
recommend.

**1. They are alphanumeric strings, not runes.** This file said "chunky 5-30 px
pixel runes" and "the wide ones read as two or three rune-like shapes side by
side". Rendered trimmed and enlarged to ~200 px tall they are plainly **letters
and digits in a chunky pixel font** -- the first glyph of `0x0F64`, `0x0F74` and
`0x0F84` is the same capital N, followed by a 1, followed by a character that
differs between them. That matches what the arm names have said all along:
`PASSCODE_ALPHANUM_CODE_CASE_<n>`. The seventeen constants are printed code
strings.

**2. The box is a 6x2 grid of 5x7 character cells.** Per-constant extents,
finer than the grouped table above:

| offset | size | box |
|---|---|---|
| 0x0F64..0x0FA4 | 28-30 x 14 | x 126..156, y 116..130 (both rows) |
| 0x0FB4..0x0FF4 | 18-20 x 7 | x 136..156, y 116..122 (top row) |
| 0x1004..0x1040 | 12-14 x 7 | x 135..148, y 116..122 (top row) |
| 0x104C | **5 x 7** | x 126..130, y 122..130 (bottom row, left edge) |

The whole box is 31 x 15 -- two 7 px rows with a 1 px gap -- and the smallest
constant is exactly one 5 x 7 cell. 5 x 7 is a character cell, so the set is
strings of 1, 2-3, 3-4 and 6 characters laid out in one six-by-two grid.

**3. The composited render this file recommended CANNOT work.** It was run.
`awvm-render-polygons` **normalises every polygon to the anchor and discards
its authored offset** -- `0x0F64`'s content, authored at x 126..154, comes out
at x 156..179 in the SVG, centred on (160,100) like every other. So passing all
seventeen to `render_scene_composite.py` at a common anchor stacks them into a
single 23 x 7 blob rather than laying them out. The output is below; it is not
a picture of anything.

Placing them by their authored boxes needs a compositor that reads the polygon
records' own coordinates, which `polygon_extent.py` reports and the SVG
renderer throws away. That is the tool gap, and it is the real blocker now.

**What is still missing** is only the text: which characters each string
spells. That needs a glyph-by-glyph comparison against the stage's own font at
1:1 pixel scale with both rows visible, not a guess from a magnified thumbnail.
Nothing is named here, for the same reason as before -- a plausible-but-wrong
name is the failure mode this stage keeps producing.

## What would settle it (superseded -- see above)

A composited render of the whole screen: draw all seventeen at (114, 62) in
bytecode order onto the two `text` lines, under the palette the stage sets, and
see what the assembled picture is. `tools/render_scene_composite.py` does this,
but it skips draws with variable coordinates, so the seventeen have to be passed
as explicit `--also CINEMATIC_0NN@114,62` arguments.

Until then these stay `CINEMATIC_NNN`. NAMING.md §2's rule is render-and-look
before naming, and the render has been looked at — it is the *meaning* of what
was seen that is not settled, and a name invented here would be the
plausible-but-wrong kind this stage's earlier passes kept producing.

## Reproducing the renders

```bash
cd another-world-archaeology
~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
    --port amiga --stage 8 --romset tmp/output/amiga/romset \
    --out /tmp/awvm_svg/amiga_stage8_pal0 --palette 0
cd /tmp/awvm_svg/amiga_stage8_pal0
for off in 0x0F64 0x0F74 0x0F84 0x0F94 0x0FA4 0x0FB4 0x0FC4 0x0FD4 0x0FE4 \
           0x0FF4 0x1004 0x1010 0x101C 0x1028 0x1034 0x1040 0x104C; do
  f=$(ls | grep -iE "_${off}\.svg$")
  convert -density 700 -background '#999999' "$f" -trim +repage -resize x120 \
          -bordercolor '#999999' -border 8 /tmp/sym_${off}.png
done
montage -label '%t' /tmp/sym_0x*.png -tile 5x4 -geometry +8+8 \
        -background '#333' -fill white -pointsize 22 /tmp/sym_sheet.png
```

Stage 8 is PASSCODE; CODE_WHEEL is stage 0, for the comparison against
`CINEMATIC_ALIEN_GLYPH_*` (offsets 0x0188, 0x01CA, 0x0200, 0x0246, 0x0288,
0x02C2, 0x031E, 0x0364, 0x03C4, 0x0414, 0x0462, 0x04BA, 0x0516, 0x055A, 0x05A6,
0x0604, 0x067C).
