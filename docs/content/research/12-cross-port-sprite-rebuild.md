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
