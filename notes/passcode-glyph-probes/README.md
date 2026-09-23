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

Placing them by their authored boxes needed a compositor that reads the
polygon records' own coordinates. `compose_at_authored_coords.py` beside this
file is that tool -- it trims each rendered SVG to its ink and pastes it at the
box `polygon_extent.py` reports.

**4. Run with the right tool, the answer is that there is no assembled
picture.** All seventeen land in the SAME 6x2 character box: the overlay fills
six cells on the top row and one at the left of the bottom row, which is
exactly the union of the per-constant extents in the table above. They are
**alternatives selected by `[0x05]`, not pieces of one image**, so no composite
could ever have assembled them. The experiment this file recommended was not
merely unsupported by the tooling -- its premise was wrong.

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

## 2026-09-23: the FONT is named — 34 glyphs — and the amiga ladder is off by one

This file spent two passes on the seventeen `[0x05]` constants and said the
missing piece was "which characters each string spells". The answer came from
the *other* ladder, the one this file had already identified and set aside:

> `[0x06]` … drives `PASSCODE_GLYPH_DIGIT_2`..`_9`, `PASSCODE_GLYPH_LETTER_A`
> and the rest (PASSCODE.asm:823+). **That** is the character→glyph map.

It is, and it is machine-readable. Each arm guards `jne [0x06], 0x<v>` and
draws one constant, so value → constant is read off the switch, and the
encoding is fixed by the arms' own guards: digits at values 1..9, letters at
`0x0A`..`0x23`, hence *letter index = value − 9*.

**Rendered at 1:1, all 35 glyphs read as exactly the character that mapping
predicts** — digits 1–9, letters A–Z, a chunky 5×7 pixel font. That is the
render-before-naming rule satisfied against a prediction rather than a guess,
which is what this stage's earlier passes lacked.

Named `CINEMATIC_PASSCODE_FONT_DIGIT_1..9` and
`CINEMATIC_PASSCODE_FONT_LETTER_A..Z`, 34 of 35. PASSCODE's asset share goes
**23.7% → 81.4%** (amiga) and 63.9% → 78.7% (msdos).

### The amiga ladder is shifted by one from N to Z

Comparing the two ports' ladders value by value, they agree on `0`..`M` and
diverge from `N`:

    value  char   amiga           msdos
     0x16   M     CINEMATIC_030   CINEMATIC_030
     0x17   N     CINEMATIC_030   CINEMATIC_029     <- amiga repeats M
     0x18   O     CINEMATIC_029   CINEMATIC_028
     …
     0x23   Z     CINEMATIC_018   CINEMATIC_017

Amiga draws the **M** picture for N and then lags one glyph behind for every
letter through Z. Checked by `canonical_md5`, not by eye: 24 of 37 values draw
the same picture in both ports and the 13 from N to Z do not.

The art itself is not divergent — 35 of the 36 font constants hold the same
picture in both ports — so naming the constants by the letter they DEPICT is
correct for both, and that is what was done. The shift is a property of the
amiga *ladder*, not of its font.

**`CINEMATIC_023` is held.** It is the one font constant whose picture really
does differ between ports: msdos's is the `T` glyph, amiga's is the `U`. One
shared name cannot describe both, and #0120 bars picking. It needs a
branch-scoped name.

Whether the amiga shift is a bug in the original release or a mis-derived
`_CASE_<n>` tail in the routine names is **not settled here**. The routine
names are identical in both ports, so one set of them is wrong about its own
port; which set needs evidence this pass did not gather.

## The seventeen strings are decoded — mechanically, not by eye

This file's whole subject was the seventeen `[0x05]` constants, and it ended
saying the missing piece was "which characters each string spells … not a
guess from a magnified thumbnail". With the font named, that is a lookup.

Each string constant is a **group whose children are inlined 5×7 character
sub-groups** — not references to the font constants, so `canonical_md5` does
not match them. Normalising each child's leaf set to its own bounding box
gives a shape signature that does: 34 named glyphs produce 34 distinct
signatures with no collisions, and every character in every string matches
exactly one. Characters are ordered by their x offset within the group.

    N11  N16  N15  N17  N20  G10
    O17  O14  O13  U20  U1   I5
    U5   I6   I9   I1   K

Rendered at 1:1 the strings read as exactly that, so the decode is confirmed
the way NAMING.md asks — against a prediction, not as the source of one.

Three characters initially came back unmatched and all three were the same
glyph, `CINEMATIC_036` — the constant the ladder arm guarded `jne [0x06],
0x00` draws. Value 0 completes the encoding as **base-36**: 0-9 then A-Z.
Rendered, it is a slashed zero. Named `CINEMATIC_PASSCODE_FONT_DIGIT_0`.

Named `CINEMATIC_PASSCODE_CODE_<text>`. The trailing digits are safe from
frame-index parsing because there is no underscore before them —
`…_CODE_N11` is not `…_CODE_N` frame 11, which is exactly the distinction
`CINEMATIC_LAKE_DECOR_AT_327_164` fell foul of.

**PASSCODE: 23.7% → 94.9% (amiga), 91.8% (msdos).**

### What is still unnamed, and why

    (CINEMATIC_023  RESOLVED -- see below. It is T in both ports.)
    CINEMATIC_055   24.5x26.0, 4 leaves -- not a glyph, not decoded here
    CINEMATIC_056   70.0x15.0 amiga / 222.0x11.0 msdos, 1 leaf -- a rule or
                    bar, and its size differs by port
    CINEMATIC_057   msdos only, 18.0x18.0
    CINEMATIC_058   msdos only, a 0x1 degenerate line

### `CINEMATIC_023` resolved: it is T in both ports

The first reading was that msdos's copy is `T` and amiga's is `U`, needing a
branch-scoped name. That was wrong, and it was wrong because it applied
amiga's ladder *without* the one-place shift the same section documents.

With the shift applied both ladders agree: msdos value `0x1D` is T and selects
this constant directly; amiga value `0x1E` is T under the shift and selects it
too. The font's own completeness confirms it independently — after naming
everything else, digits 0-9 were complete and letters A..Z were complete
**except T**, with `CINEMATIC_023` the single remaining font-range constant.
One hole, one candidate.

The two ports do hold different pictures here, and it is the only one of the
36 font constants that does. That needs no branch scoping: a shared name with
per-port values is exactly for this. The name is the role, the value is that
port's art.

**The font is complete: 10 digits and 26 letters, base-36.**
PASSCODE 23.7% → **96.6%** (amiga), 93.4% (msdos).

