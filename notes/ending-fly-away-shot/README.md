# ENDING's fly-away shot: what is `CINEMATIC_066`?

## The question, and why it was open

`ENDING_PTERANODON_RIDER_HOLD_LOOP` (channel 0x0E of the fly-away shot) draws
one polygon, `CINEMATIC_066`, forever at the shot's shared anchor. dos_1992 has
carried that name for some time. amiga carried the placeholder
`HANG_DRAWING_CIN_066_VAR03`, because the 2026-09-14 naming pass **skipped** it
and its verifier upheld the skip
(`another-world-archaeology/docs/content/research/2026-09-14-small-stage-finish/verdicts_amiga_ENDING_0.md`):

> neither the body, the single `setup channel=0x0E` caller nor anything
> downstream discriminates a subject. […] A composited whole-shot render is
> still what is needed.

So the two branches disagreed, and the branch with the name had never been held
to the test the branch without it failed. Running
`align_branch_names.py --merge` in 2026-09-19 carried the dos name onto amiga,
which resolves the disagreement without settling the claim. This note settles
it.

## What was measured

Every layer of the shot is drawn at the same anchor with the same zoom —
`ENDING_CLOSEUP_SHOT_CUT_TO_FLY_AWAY_ENTRY` sets `[0x01]=0xA0`, `[0x02]=0x64`,
`[0x03]=0x40` and the four channels it then installs all draw at
`x=[0x01], y=[0x02], zoom=[0x03]`. That makes the polygons' own extents directly
comparable, which is the same reasoning the 2026-09-14 verdicts used against the
`PARTICLE` names in INTRO.

```bash
cd another-world-archaeology
python3 tools/polygon_extent.py --stage 7 --port amiga \
    --equ CINEMATIC_066 --equ CINEMATIC_067 --equ CINEMATIC_059 \
    --equ CINEMATIC_086 --equ CINEMATIC_075
```

| polygon | channel / role | extent | box |
|---|---|---|---|
| `CINEMATIC_086` | 0x0C `PTERANODON_WING_LEFT_FLAP_LOOP` | 140x81 | x −78..61, y −32..50 |
| `CINEMATIC_075` | 0x0D `PTERANODON_WING_RIGHT_FLAP_LOOP` | 140x81 | x 66..206, y −32..50 |
| `CINEMATIC_067` | 0x0A body, first frame | 232x102 | x −64..168, y 6..107 |
| `CINEMATIC_059` | 0x0F `PTERANODON_LEG_DANGLE_LOOP` | 8x50 | x 50..58, y 57..107 |
| **`CINEMATIC_066`** | **0x0E, the routine in question** | **30x66** | **x 41..71, y 20..86** |

The two wings abut at x 61..66 — that is the creature's centreline. The leg
hangs from x 50..58 downward to y 107. `CINEMATIC_066` straddles that same
centreline (x 41..71) in the upper half of the body (y 20..86), above where the
leg starts and inside the span of the body. That is the creature's back.

## The colours

```bash
# build the SVGs the composite tool consumes, at the palette the shot sets
~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
    --port amiga --stage 7 --romset tmp/output/amiga/romset \
    --out /tmp/awvm_svg/amiga_stage7_pal11 --palette 11
python3 tools/render_scene_composite.py ENDING_PTERANODON_FLY_AWAY_SHOT_ENTRY \
    --port amiga --stage 7 --palette 11 \
    --also CINEMATIC_067@160,100 --also CINEMATIC_086@160,100 \
    --also CINEMATIC_075@160,100 --also CINEMATIC_059@160,100 \
    --also CINEMATIC_066@160,100 --out /tmp/fly_with066.png
```

Under `setPalette 0x0B` — the palette `ENDING_PTERANODON_FLY_AWAY_SHOT_ENTRY`
itself sets — **every other layer renders pure black and `CINEMATIC_066` is the
only coloured thing in the frame**: a pale block over a dark red element, with
two small pale limb shapes below and to the right. Re-run the command with and
without the last `--also` and the black frame is identical.

That is the shot as designed: the creature is a silhouette against the sky
backdrop (which comes from page 3 via `copyVideoPage src=0x03, dst=0x00`, so it
is not a polygon and cannot be composited), and the figures it carries are the
only lit thing.

The 2026-09-14 verdict had already measured the fill set as
`#000000 / #a70000 / #b79797 / #cb8774` and identified `#b79797` as the alien's
tone and `#cb8774` as Lester's, while ruling out the head — `CINEMATIC_074`, the
head polygon, is pure `#000000`. It called that "narrows the tie toward the
carried-figures reading but does not settle it on colour alone". The geometry
above is the other half.

## Conclusion

`CINEMATIC_066` is the figures riding on the pteranodon's back: on the
centreline between the wing roots, above the dangling leg, two figures' worth of
palette, and the only non-silhouette layer in the shot.
`ENDING_PTERANODON_RIDER_HOLD_LOOP` is correct and the amiga skip is lifted.

One caveat worth keeping: the name is singular and the colour set is two
figures. It was not changed, because dos has carried the singular spelling for
long enough that renaming it now would churn both branches for a nuance the art
at 30x66 px does not resolve beyond the palette.
