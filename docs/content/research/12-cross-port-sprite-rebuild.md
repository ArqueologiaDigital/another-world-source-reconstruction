# 12 — Cross-port sprite-byte rebuild patterns (amiga 1991 ↔ dos 1992)

## Question

When Eric Chahi's 1991 amiga release was rebuilt by Daniel Morais
into the 1992 DOS port, did the polygon banks change? If so, in
what direction — was the DOS version a faithful re-encoding, a
trimming-down (cut content), an additive expansion (new sprites),
or a content rework? Does the rebuild pattern differ per stage?

This research extends the per-stage unused-polygon counts from
[research/06](#/research/06-unused-polygons-survey) by computing
the actual byte-content set difference between each pair of
matched polygon-cinematic resources.

## Method

For each stage (CODE_WHEEL, INTRO, LAKE, PRISON, CAVES, TANK,
CAPSULE, ENDING, PASSCODE), the corresponding POLY_CINEMATIC
resource is extracted from both ports' resource banks (DOS at
manifest-typed entries 0x16/0x19/0x1c/.../0x7f; amiga at the same
indices via `tmp/output/amiga/resources/resource-0xNN.bin`).

For each port:

1. **Linear-walk** the polygon resource via
   `tools/polygon_walker.py`. Every solid polygon yields a
   `(offset, header+body bytes)` tuple. Skip group polygons
   (their bytes embed child references that differ per port even
   when the rendered sprite matches; solids are the meaningful
   sprite-content unit).
2. **md5-hash** each solid polygon's bytes.
3. **Compute reachability** from the port's bytecode via
   `tools/asset_references.py` (direct `video=1` refs) +
   `polygon_walker.reachable_set()` (transitive group-child
   closure). Record which solid polygons are "used" by that
   port's bytecode.
4. **Diff** the set of hashes between the two ports — both the
   raw set difference (what each bank ships) and the
   used-only set difference (what each port's bytecode actively
   renders that the other port's bank doesn't even contain).

Tools:

  - `tools/cross_port_polygon_diff.py` — raw-bank set difference
  - `tools/cross_port_used_polygon_diff.py` — used-by-bytecode set
    difference (the higher-signal variant)

## Findings

### Per-stage USED-sprite cross-port diff

| Stage      | amiga-USES-but-dos-LACKS | dos-USES-but-amiga-LACKS | Pattern             |
|------------|--------------------------|--------------------------|---------------------|
| CODE_WHEEL | 0                        | 8                        | DOS-additive        |
| INTRO      | 2                        | 2                        | nearly stable       |
| LAKE       | **201**                  | 0                        | amiga-vestigial     |
| PRISON     | 0                        | 1                        | nearly stable       |
| CAVES      | 0                        | 16                       | DOS-additive (mild) |
| TANK       | 0                        | 90                       | DOS-additive        |
| CAPSULE    | 107                      | 360                      | major rework        |
| ENDING     | 0                        | 1                        | nearly stable       |
| PASSCODE   | 1                        | 1                        | nearly stable       |

### Three rebuild patterns

#### 1. Amiga-vestigial (cut content)

**LAKE** is the cleanest example. The 1991 amiga build has 201
unique solid polygons that its bytecode actively renders (via
`video offset=` calls or transitive group-polygon references),
which **do not exist at any offset in the 1992 DOS polygon bank**.
The DOS rebuild trimmed them entirely.

These 201 sprites are the strongest cut-content candidates in the
entire archaeology project — they're not just "unused on DOS",
they're not even shipped with DOS. The amiga release ships +
renders sprites that the 1992 rebuild decided weren't needed.

Per-offset list persisted at
`docs/cut_content/cut_polygons_amiga_only.json`. The set is
dominated by 12-20 byte simple polygons (likely character body
parts or scene-decoration leaves). To identify them visually,
render each via `tools/polygon_render.py` against amiga's LAKE
palettes (0x1a, half=first); palette 5–7 is most likely the
shipping LAKE-stage colour scheme.

#### 2. DOS-additive (new sprites)

**TANK** (+90), **CAVES** (+16), and **CODE_WHEEL** (+8) show the
opposite pattern: the 1992 DOS port's bytecode renders solid
polygons that don't exist in the amiga 1991 bank. Net additions:

- `docs/cut_content/dos_added_polygons.json` lists offsets within
  DOS's polygon resources.
- TANK's 90 additions are striking — possibly Heineman 1992's
  rework of the tank-arena with new enemy variants, projectiles,
  or HUD elements.
- CAVES's 16 additions are mild but present.
- CODE_WHEEL's 8 additions match the screen's "DOS got
  CODEWHEEL_CHECK = on" feature that the amiga build also has,
  but with different sprite-bank layouts.

#### 3. Major rework (re-spritefication)

**CAPSULE** is unique. It has both directions of difference at
substantial scale: 107 amiga-only USED + 360 dos-only USED.
The 1992 DOS port both removed amiga sprites AND added dos
sprites — full content rework.

This complements [issue #0080](#/issues/0080-capsule-cinematic-bank-divergence)'s
finding that the alien sub-anim CIN range (CIN_109..113 in 1992
vs CIN_180..184 in 1991) is purely a renumbering at the named
mapping points (header bytes match), but the bank as a whole
underwent significant bidirectional content rework around those
mapped routines.

### Sanity checks

- INTRO, PRISON, ENDING, PASSCODE all show ≤2 sprites in either
  direction. These stages have **stable polygon banks** between
  the 1991 and 1992 ports — corroborates the bytecode-structural
  finding from [research/08](#/research/08-cross-branch-structural-similarity)
  that the 1992 DOS port largely reused the 1991 sprite content.
- The named-and-mapped CIN_109..184 alien sub-anim sprites in
  CAPSULE (issue #0080) are CONFIRMED in the "common content"
  set of CAPSULE — they survived the rework intact, just at
  different offsets.

### Confirmed cut: HERO_RESUME_LEFT 10-frame animation cycle

Following the address-clustering hint up to its named-EQU
attribution: `tools/find_parent_polygons.py` walks the polygon
hierarchy in reverse (child → parent group) and shows that the
207 LAKE cut amiga sub-polys are referenced by **87 distinct
parent group polygons**.

The first 6 of those parent group offsets — `0x0310, 0x039C,
0x0408, 0x0488, 0x0504, 0x0574` — match exactly the amiga LAKE
EQUs `CINEMATIC_HERO_RESUME_LEFT_F4` through `F9`. Walking
both polygon banks at these offsets with `polygon_walker.py`:

| Offset | Amiga       | DOS           |
|--------|-------------|---------------|
| 0x0310 | group 32 B  | PARSE-FAIL    |
| 0x039C | group 32 B  | solid 20 B    |
| 0x0408 | group 32 B  | PARSE-FAIL    |
| 0x0488 | group 32 B  | PARSE-FAIL    |
| 0x0504 | group 32 B  | PARSE-FAIL    |
| 0x0574 | group 36 B  | group 22 B    |
| 0x0ADC | group 40 B  | PARSE-FAIL    | (HERO_RESUME_LEFT_F0)
| 0x0B04 | group 40 B  | PARSE-FAIL    | (HERO_RESUME_LEFT_F1)
| 0x0B2C | group 40 B  | PARSE-FAIL    | (HERO_RESUME_LEFT_F2)
| 0x0B54 | group 40 B  | PARSE-FAIL    | (HERO_RESUME_LEFT_F3)

DOS's polygon bank has **no valid polygon at all** at most of
these amiga-RESUME-LEFT offsets, and where it does parse the
content is unrelated (different size, different kind). DOS LAKE
bytecode also doesn't reference any `CINEMATIC_HERO_RESUME_LEFT_F*`
— the EQU symbols don't even exist in
`src/levels/dos_1992/LAKE.asm`.

**Verdict: the 10-frame `HERO_RESUME_LEFT` animation cycle was
**REBUILT** in the 1992 DOS port, not strictly cut.** Refined
finding: walking the DOS bytecode at the equivalent state shows
DOS DOES have a hero-resume-left animation, but it uses
COMPOSITE COMMON_VIDEO helpers instead of the bespoke
LAKE-specific CINEMATIC_HERO_RESUME_LEFT_F* frames:

```
DOS LAKE (line 6932 onward):
MAYBE_RESUME_WALK_LEFT_DRAW:
    call DRAW_VIDEO_073_AND_CIN_002
    ...
    call DRAW_VIDEO_074_AND_CINEMATIC_HERO_SHADOW_RET
    ...
    call DRAW_VIDEO_075_AND_CINEMATIC_2_RET
    ...
    call DRAW_VIDEO_076_AND_CIN_002
```

The `DRAW_VIDEO_NNN_*` calls draw COMMON_VIDEO sprites (shared
across all stages, indexed by NNN) plus a small CINEMATIC overlay.
amiga's per-stage detailed sprite frames have been replaced with
shared common-video sprites composited together.

**Architectural shift surfaced by this finding**: amiga 1991
gave each stage its own dedicated detail sprites for hero
animations; DOS 1992 unified hero animations across stages by
using the COMMON_VIDEO bank for shared sprites + per-stage
overlays for stage-specific bits. The 1992 rebuild is therefore
a *re-pipelining* (composite-sprite based) rather than a
content cut.

The 207 amiga LAKE cut sub-polys are nonetheless real artifacts
of this pipelining shift: amiga's per-stage detailed sprites
literally don't exist in DOS's polygon bank because DOS uses the
shared COMMON_VIDEO bank instead. Visual rendering of the amiga
group polygons at offsets 0x0ADC..0x0B54 + 0x0310..0x0574 (via
`tools/polygon_render_png.py`) would produce the original
amiga-1991 detailed frames; DOS displays the same animation more
crudely via shared sprites.

### Full parent-group attribution

86 of the 87 parent group offsets in amiga's polygon bank match
named EQUs in `chahi_amiga_1991/LAKE.asm`. The breakdown by
animation cycle:

| Animation cycle              | # frames cut at sub-poly level |
|------------------------------|---------------------------------|
| HERO_LEAP_LEFT               | 10                              |
| HERO_LEAP_RIGHT              | 10                              |
| HERO_RESUME_LEFT             | 10                              |
| HERO_RESUME_RIGHT            | 7                               |
| POOL_LESTER                  | 7                               |
| HERO_RUN_LEFT                | 6                               |
| HERO_RUN_RIGHT               | 6                               |
| HERO_FALL_LEFT               | 4                               |
| HERO_WALK_LEFT               | 4                               |
| HERO_WALK_RIGHT              | 4                               |
| HERO_STOP_LEFT               | 3                               |
| HERO_STOP_RIGHT              | 3                               |
| HERO_LEAP_RIGHT_F0??_BUNDLE  | 3                               |
| HERO_OUT_POOL                | 2                               |
| LESTER_WAIT                  | 2                               |
| HERO_RESUME_WALK_R           | 2                               |
| HERO_STANDING_LEFT_IDLE      | 1                               |
| HERO_LEFT_PROFILE            | 1                               |
| HERO_STAND_R_BG_GHOST        | 1                               |

Plus 1 unattributed parent at 0x1354 (no matching EQU; possibly
an internal sub-group rather than a named animation root).

**Total: ~85 named hero/Lester animation frames are affected** —
i.e., their sub-polygon content in amiga's polygon bank includes
bytes that the 1992 DOS rebuild doesn't carry. Whether each
specific animation was cut entirely vs. rebuilt with different
sub-polys depends on whether DOS has a parsable polygon at the
same offset:

- **Cleanly cut** (DOS has no polygon at the offset): the
  HERO_RESUME_LEFT_F4..F9 set sample (0x0310..0x0574) shows
  most fail to parse in DOS.
- **Rebuilt** (DOS has a different polygon at the offset): the
  HERO_LEAP_RIGHT cycle has a DOS equivalent routine
  (`HERO_LEAP_RIGHT_LOOP`) that draws COMPOSITE cinematics
  via `DRAW_HERO_STOP_R_BUNDLE_NN_MM` helpers — different
  sprite-bundling strategy.

The general pattern: the 1992 DOS port redrew amiga's
fine-grained per-frame hero animations as composite/bundled
sprites, possibly to fit the polygon bank into cartridge-target
size budgets. The amiga 1991 release had richer hero animations
(more individual frames per cycle, more sub-polygon detail per
frame); DOS 1992 simplified both the frame count and the
per-frame sub-polygon composition.

Visual rendering (`tools/polygon_render_png.py` against amiga's
LAKE palette 5..7) of any of the affected parent group offsets
would show the original-fidelity 1991 sprite. The same offset
in DOS, where it parses, would show the simplified 1992 version.

### Address-clustering hint for the LAKE 201 cut set

The 207 amiga offsets in
`docs/cut_content/cut_polygons_amiga_only.json["LAKE"]` cluster
bimodally:

- **Low region** (0x300..0x1FFF): adjacent to amiga LAKE's
  named hero-animation EQUs `HERO_FALL_LEFT_*`,
  `HERO_RESUME_LEFT_*`, `HERO_LIFTOFF`,
  `GETTING_OUT_OF_THE_POOL_*`, `RIGHT_KICK_1`.
- **High region** (0xF400..0xFAFF): adjacent to
  `HERO_WALK_LEFT_FRAME_*`, `HERO_RUN_LEFT_FRAME_*`,
  `HERO_STOP_LEFT_FRAME_*`, `HERO_RUN_RIGHT_FRAME_*`.

**Strong hypothesis**: most of the 201 cut sprites are **extra
hero animation in-between frames** that the 1991 amiga release
shipped at a higher frame count than the 1992 DOS rebuild
preserved. Not "removed cutscene actors", more like "decimated
walk/run/jump animation cycles". This recasts LAKE's cut content
as a smoothness-vs-bank-size tradeoff during the DOS port rather
than a content cut.

Per-sprite rendering would confirm or refute this on a per-cluster
basis. See [issue #0082](#/issues/0082-render-lake-201-cut-sprites-for-visual-identification)
for the rendering follow-on task.

## Implications

1. **The 1992 DOS port wasn't a uniform translation of the 1991
   amiga release.** It applied stage-specific rebuilds: trimming
   cut content (LAKE), adding new sprites (TANK, CAVES,
   CODE_WHEEL), or fully reworking (CAPSULE).
2. **LAKE has the most archaeological value going forward.** The
   201 cut sprites are a focused, well-bounded set ripe for
   visual identification. With a working SVG→PNG renderer
   (currently blocked on rsvg-convert/inkscape availability), each
   sprite could be classified manually to surface specific
   gameplay elements that didn't ship in 1992.
3. **TANK's +90 DOS additions are a Heineman-1992 rework signature.**
   Combined with research/05's finding that the cartridge SNES/Genesis
   ports inherit Heineman's DOS bytecode, these +90 sprites may
   also be present in the SNES/Genesis polygon banks (gated on
   cart polygon extraction — issue [#0068](#/issues/0068-awvm-tools-cartridge-ports-extract-cinematic-rom-too)).

   The +90 cluster sits in a contiguous 8 KB block (0x5e00..0x7100)
   of DOS's TANK polygon resource. That range contains CINEMATIC_036,
   037, 088–105+ (18 sequential cinematic indices), suggesting
   a single multi-frame animation sequence added in the DOS port.
   Likely candidates: tank enemy sprite cycles, projectile
   variants, or HUD elements. Visual rendering would identify
   which.
4. **CAPSULE's bidirectional rework (107+360) is unique.** Worth
   investigating which scene transitions or character animations
   trigger the rebuild — the alien sub-anim renumbering (issue
   #0080) is one symptom, but the additional 360 dos-only sprites
   suggest the rework went well beyond just renumbering.

## Related issues + research

- [research/06 — Unused-polygons survey](#/research/06-unused-polygons-survey)
  (extended by this finding)
- [research/08 — Cross-branch structural similarity](#/research/08-cross-branch-structural-similarity)
  (corroborates the rebuild pattern at the bytecode level)
- [issue #0054 — Build unused-polygon scanner pipeline](#/issues/0054-build-unused-polygon-scanner-pipeline-run-on-all-ports-level)
- [issue #0080 — CAPSULE alien CIN renumbering](#/issues/0080-capsule-cinematic-bank-divergence)
- [issue #0068 — Cart polygon extraction (gating cart inclusion in this analysis)](#/issues/0068-awvm-tools-cartridge-ports-extract-cinematic-rom-too)

## Changelog

- **2026-05-04** — first cross-port sprite-byte diff. Tools shipped:
  `cross_port_polygon_diff.py` (raw bank diff) and
  `cross_port_used_polygon_diff.py` (used-by-bytecode diff). Per-
  stage findings tabulated above. JSON offsets persisted at
  `docs/cut_content/{cut_polygons_amiga_only,dos_added_polygons}.json`.
