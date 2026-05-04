# Source tree organization (`src/levels/`)

The source-reconstruction project builds back to byte-identical
bytecode resources for every cataloged port. To support both
per-branch development and unified cross-branch maintenance, the
`src/levels/` tree is organised in three layers.

```
src/levels/
├── _common_vars.inc          (1)  shared VM-variable aliases
├── _unified/                 (2)  cross-branch unified sources
│   ├── INTRO.asm.in
│   ├── LAKE.asm.in
│   ├── ...
│   ├── _helpers/             (2c) cross-stage shared routines
│   │   ├── KILL_CHANNEL_LANDING.inc
│   │   ├── DRAW_CV_NNN.inc
│   │   └── ...
│   ├── intro/                (2a) per-stage chunk tree
│   │   ├── intro_entry_and_dispatchers.inc
│   │   ├── intro_first_scene_init.inc
│   │   ├── ...
│   │   ├── amiga__entry.inc           (2b) per-arm chunk
│   │   ├── amiga__post_<ROUTINE>.inc
│   │   ├── cart__entry.inc
│   │   └── ...
│   └── lake/                 ...
├── cartridge_1992/           (3)  per-branch standalone sources
│   ├── INTRO.asm
│   ├── LAKE.asm
│   └── ...
├── chahi_amiga_1991/         ...
├── dos_1992/                 ...
└── gba_2004/                 ...
```

## (1) `_common_vars.inc` — shared VM-variable aliases

Defines the 15 VM-variable aliases that are byte-identical across
every branch and stage that uses them: `RANDOM_SEED`, `HACK_VAR_*`,
`HERO_*`, `MUS_MARK`, `SCROLL_Y`, `LAST_KEYCHAR`, `PAUSE_SLICES`.

Every per-branch source and unified `.asm.in` `;@include`s this
file at the top, replacing what used to be 15 inline `EQU` lines
per file.

## (2) Unified sources — `_unified/<STAGE>.asm.in`

Each `<STAGE>.asm.in` is a single source-of-truth for the stage
across all four branches. The toolchain runs `tools/awvm_preprocess.py`
on the file with a per-target `<release>.flags` configuration to
produce a plain `.asm` for that one branch, which `awvm-asm` then
assembles to bytecode.

The preprocessor handles:

- `;@if BRANCH == "<branch>"` / `;@elif` / `;@else` / `;@endif`
  for branch-conditional sections.
- `;@include "<rel-path>"` for chunk inlining.
- `FILL(n, 0xXX)` macros for trailing-padding regions.

A typical `.asm.in` is structured as:

```
; STAGE <NAME>: narrative documentation header.
;@include "../_common_vars.inc"
<EQU declarations shared by 2+ chunks>

    org 0x0000
;@include "<stage>/<arm>__entry.inc"        ; per-arm entry chunk
<shared body of folded routine A>
;@include "<stage>/<arm>__post_<A>.inc"     ; per-arm post-A chunk
<shared body of folded routine B>
;@include "<stage>/<arm>__post_<B>.inc"
...
```

### (2a) Per-stage chunk tree — `_unified/<stage>/`

The chunk tree under each stage's directory holds:

- **Chapter chunks** (e.g. `intro_first_scene_init.inc`,
  `lake/beast_ai_dispatch.inc`,
  `tank/tank_var5f_manipulation.inc`): named thematically by the
  gameplay scene or routine cluster they contain. **Every stage
  except CODE_WHEEL has chapter chunks** — they're the primary
  organizing unit of the unified source. Created by
  `tools/split_asm_chapter.py` (see "chapter-split" below).
- **Per-arm fold chunks**: `<arm>__entry.inc` and
  `<arm>__post_<ROUTINE>.inc` are arm-specific (amiga / cart /
  dos) and hold the divergent prefix or suffix of the bytecode
  around a folded shared body.

#### Chapter-split

`tools/split_asm_chapter.py STAGE CHAPTER START_SPEC END_SPEC`
moves a contiguous range of bytecode from the unified `.asm.in`
into a chapter chunk file at
`_unified/<stage>/<chapter>.inc`, then replaces the moved range
in the `.asm.in` with `;@include "<stage>/<chapter>.inc"`.

`START_SPEC` / `END_SPEC` accept four forms:
- `<LABEL>` — line where `LABEL:` is at depth 0
- `AFTER:<LABEL>` — first depth-0 boundary after the body of
  `LABEL`
- `INCLUDE_NEXT` — first depth-0 `;@include` after start
- `LINE:<N>` — direct line-number cut (use when no depth-0
  routine labels are available, as in CODE_WHEEL where every
  routine is `;@if`-wrapped)

The cut MUST happen at "entering depth==0" boundaries — the
chapter must not split the middle of an open `;@if` block.

When extracting a chapter, the tool rewrites the chunk's internal
`;@include` paths so they resolve correctly from the chunk's
new location:
- `<stage>/<arm>__post_X.inc` → `<arm>__post_X.inc`
- `_helpers/X.inc` → `../_helpers/X.inc`

After the chapter-split sweep, the 9 unified `.asm.in` files
total ~1650 lines (down from ~14,000+ before any chapter cuts).
Average ~180 lines per `.asm.in`; max ~347 (PRISON), ~307 (CAVES).
122 named chapter chunks across the 9 stages. Largest single
chapter chunk is `capsule/capsule_init_dispatch.inc` at 816
lines (only 2 depth-0 labels — mostly fold-body include
scaffolding, not productively splittable). Largest chapter
with multiple labels is `caves/caves_dedup_helpers_cluster.inc`
at 786 lines (5 labels). Most chapters are 100–500 lines;
chapters with many small init/setter routines are typically
200–400 lines.

### (2b) Per-arm chunks — multi-fold technique

When two or more branches share a body of bytecode but differ in
the surrounding context, the unified file:

1. Splits each branch's source at the routine boundary.
2. Stores the **divergent prefix** in `<arm>__entry.inc`.
3. Includes a **single shared body** in the `.asm.in` file
   directly (wrapped in a `;@if BRANCH in (...)` block).
4. Stores the **divergent suffix** in `<arm>__post_<ROUTINE>.inc`.

The same pattern repeats for every folded routine, producing a
cascade of `<arm>__post_<ROUTINE>.inc` chunks per arm.

#### Body-localised EQUs

EQUs that are not referenced by the `.asm.in` body itself are
stored in the chunk file that uses them rather than at the top
of the `.asm.in`. Per-branch values are preserved via
`;@if BRANCH == "<branch>"` blocks at the top of the chunk. When
multiple chunks reference the same EQU, it lives in the chunk
that's `;@include`d earliest (so the symbol is in scope for any
later chunk that also needs it). See
`tools/localize_single_use_equs.py`.

**Exception**: any EQU whose name contains `_UNUSED_` (e.g.
`CINEMATIC_LAKE_UNUSED_175`) stays at the top of the `.asm.in` as
a research-flag annotation. Those declarations document slots
present in the resource bank but never invoked by gameplay
bytecode, and the localizer skips them so they remain visible to
anyone reading the file's banner.

### (2c) Cross-stage shared helpers — `_unified/_helpers/`

When a routine appears in 2+ stages with byte-identical body and
no internal jumps/calls (the bytes are stage-independent — see the
constraint discussion below), the body is hoisted to a single
shared file under `_unified/_helpers/<NAME>.inc`. Each stage's
`.asm.in` then references it via `;@include "_helpers/<NAME>.inc"`
in place of redefining the routine.

**Why the jump/call-free constraint**: AW VM bytecode encodes
jumps/calls as 2-byte absolute addresses. A routine with internal
flow control would emit different bytes per stage even from
identical source text, since the call/jmp operand depends on the
target's stage-specific resolved address. Jump-free routines (only
var moves, arithmetic, page copies, video draws with literal/var
operands) emit the same bytes regardless of where they land in the
stage's bytecode bank, so they can be safely shared.

See `tools/scan_cross_stage_helpers.py` (candidate finder) and
`tools/extract_cross_stage_helpers.py` (extraction driver).

## (3) Per-branch sources — `<branch>/<STAGE>.asm`

Standalone sources for each branch + stage combination, each one
disassembled directly from the corresponding port's bytecode
resource. These are the **canonical reference** that the unified
sources must round-trip to.

A per-branch source is one big monolithic file:

```
; STAGE <NAME>: narrative + branch-identification header.
; Generated by AnotherWorld_VMTools
;@include "../_common_vars.inc"
<EQU declarations: CINEMATIC_NNN, COMMON_VIDEO_NNN, etc.>
<bytecode body>
```

Per-branch sources don't have chunks; they share `_common_vars.inc`
with the unified pipeline but otherwise stand alone.

## Verification regime

Two complementary verifiers ensure byte-identical reconstruction:

- **`tools/verify_stage.py`** — assembles each per-branch
  `<branch>/<STAGE>.asm` and byte-compares against every port that
  ships that branch+stage. Currently **29/29** combinations green.
- **`tools/verify_unified.py`** — preprocesses each unified
  `_unified/<STAGE>.asm.in` for every branch+port combination,
  assembles, and byte-compares. Currently **27/27** green.

Both verifiers must pass for any change to merge.

## Tooling reference

| Tool | Role |
|---|---|
| `tools/awvm_preprocess.py` | Expand `;@if`/`;@include`/`FILL` directives |
| `tools/verify_stage.py` | Byte-check every per-branch source |
| `tools/verify_unified.py` | Byte-check every unified source × branch |
| `tools/strip_unused_equs.py` | Per-file unused-EQU stripper |
| `tools/strip_unused_equs_unified.py` | Unified-tree unused-EQU stripper |
| `tools/consolidate_common_vars.py` | Replace inline shared EQUs with `;@include` |
| `tools/localize_single_use_equs.py` | Move EQUs from `.asm.in` into the chunks that reference them |
| `tools/scan_cross_stage_helpers.py` | Find jump-free routines defined in 2+ stages with identical body |
| `tools/extract_cross_stage_helpers.py` | Hoist cross-stage helpers to `_unified/_helpers/` |
| `tools/multi_fold.py` | Chunk split + unified body emit |
| `tools/match_arms.py` | Body-shape matching for fold candidates |
| `tools/auto_fold.py` | Automatic fold orchestration |
| `tools/auto_fold_rename.py` | Body-hash-derived FOLD_BODY name renaming |
| `tools/fold_body_rename_round_*.py` | Per-round semantic renames of FOLD_BODY routines |
| `tools/sync_*_renames.py` | Cross-branch propagation of semantic renames |
| `tools/find_cross_stage.py` | Identify routines shared across stages |
| `tools/unify_cross_stage_names.py` | Apply cross-stage name unification |
| `tools/add_stage_doc_headers.py` | Generate stage-narrative `;`-comment headers |

## Conventions

- **No emojis** in source files (project-wide rule).
- **Routine names** describe what the body does, not where it's
  called from. `LABEL_<HEX>` is the unnamed-routine convention;
  semantically-clear routines get a named replacement
  (e.g. `INIT_VARS_E6_07_08`, `DRAW_CIN_473_AT_X21_Y27_ZOOM_40`).
- **Chunk filenames** mirror the routine they bracket:
  `<arm>__post_<ROUTINE>.inc`. Do not use `_chunk_<N>` suffixes
  (project rule, see archaeology memory `feedback_no_chunk_indices`).
- **Avoid arbitrary suffixes** like `_A`/`_B`/`_VARIANT_1` to
  distinguish byte-identical labels — investigate the role and
  use a meaningful suffix instead (memory:
  `feedback_no_index_suffixes`).
- **`;@raw=` annotations** are authoritative bytes for opcodes
  that `awvm-asm` can't unambiguously regenerate (typically
  bankSwitch, video, setPalette, and any cross-chunk call/je/jmp
  whose target offset can't be known without preprocessing). Strip
  only the redundant ones (see `tools/strip_redundant_raw.py`).
- **`_UNUSED_` EQUs are research flags**: cinematic-bank slots that
  exist in the resource ROM but are never invoked by gameplay
  bytecode keep their `_UNUSED_` named EQU declarations at the top
  of the unified `.asm.in`, scoped to the branches where the slot
  is actually present. Never strip or relocate these (the
  localizer was patched to enforce this).
