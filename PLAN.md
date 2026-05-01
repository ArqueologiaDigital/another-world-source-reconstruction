# Phased roadmap

The reconstruction project has natural dependencies on the
archaeology project's *findings*. Several flags can't be defined
until the archaeology has surfaced them. Phases are designed so
that each is independently useful even if later phases stall.

## Phase 0 — Scaffolding (committed 2026-04-30)

- README + PLAN + initial directory structure
- Issues opened in `another-world-archaeology/issues/` to track
  reconstruction progress: `#0059..#0064`
- No code yet — pure planning artifact

## Phase 1 — Bytecode round-trip (✅ achieved 2026-05-01 for 5 ports)

**Goal**: prove the reconstruction loop works end-to-end for the
bytecode resource of every port we have disassembly for.

**Achieved**: `make verify-all` now reports
**29/29 levels round-trip byte-identically across 5 ports**:

| Port | Levels | Format |
|---|---|---|
| amiga          | 9/9 | resource-bin |
| msdos          | 9/9 | resource-bin |
| genesis_europe | 7/7 | cartridge (64 KB chunks) |
| snes_eu        | 2/2 | cartridge (only 2 levels disasm currently) |
| gba_usa        | 2/2 | cartridge (only 2 levels disasm currently) |

The driver lives in `another-world-archaeology/tools/roundtrip_bytecode.py`
and is invoked via `make verify TARGET=<port>` or `make verify-all`.

The toolchain at this stage is: **`awvm-disasm` (in AWVM_Tools)
extracts .asm from user-supplied originals → `awvm-asm` (in
AWVM_Tools) re-assembles .asm → byte-compare to the original or
to the equivalent cartridge chunk**. The `.asm` files act as
intermediate "source" but aren't yet diverging between ports —
they're just the disasm output. Phase 3 starts unifying them.

**Genealogy bonus surfaced by Phase 1**: SNES-EU level 1 and
Genesis-EU level 0 produce **byte-identical 64-KB cartridge
chunks** (md5 `e24580ddb549...`), confirming research/05's
SNES↔Genesis byte-identity finding now at the cartridge-ROM level
(not just at the bytecode-resource level).

**Not yet covered** in Phase 1 (those become later phases):
- Atari ST 1991 (gated on memlist parser, issue #0004 — even
  though it's known to share Amiga's bytecode byte-identically)
- Apple IIgs 1993 (gated on WOZ extractor, issue #0014)
- 3DO, Mac, Mega-CD, Symbian, NDS, Apple II demake

## Phase 2 — Raw-asset byte-matching (in scope)

**Goal**: byte-match every non-bytecode resource (POLY_CINEMATIC,
POLY_ANIM, PALETTE, SOUND, MUSIC) for every port.

Raw assets aren't "reconstructed" the way bytecode is; they're
binary blobs. So the build pipeline for raw assets is a verbatim
file-copy from the user's extracted originals to the build
output, with a per-resource md5 verification step.

The deliverable for Phase 2 is therefore much simpler than originally
planned:

- Per-port resource manifest (committed in this repo) that lists
  every expected resource with its md5.
- Build rule that copies raw resources from
  `<output_root>/resources/` (or `<output_root>/romset/` for
  cartridges) and verifies each copy against the manifest.
- `make verify-resources TARGET=<port>` reports pass/fail per
  resource.

For the polygon resource specifically, **no inverse builder is
required for Phase 2** — we treat the polygon bytes as opaque.
A polygon-source language + builder would be a separate Phase 4
research project (out of current scope).

**Acceptance**: every non-bytecode resource for every port byte-
matches the manifest md5.

## ~~Phase 2.5 — Whole-port packaging~~ (DROPPED FROM SCOPE)

**Originally planned but explicitly out of scope (2026-05-01)**:
- Engine binary reconstruction
- Bank packing pipeline (memlist.bin + bank01..bank0d)
- ADF / cartridge ROM construction
- Sound encoding pipelines

These are non-trivial and not part of the current research goal.
The source-reconstruction project produces byte-matching SETS OF
RESOURCES (bytecode + raw assets), not byte-matching distribution
packages.

## Phase 3a — Branch-organized canonical sources (✅ achieved 2026-05-01)

**Goal**: collapse per-port .asm files into per-branch canonical
sources, sharing one file across ports when their bytecode is
byte-identical.

**Achieved**: `make verify-stages` reports
**29/29 (port, stage) byte-matches across 28 canonical .asm
files**. Source tree at `src/levels/<branch>/<stage>.asm`:

| Branch | Source files | Targets covered |
|---|---|---|
| `chahi_amiga_1991` | 9 stages | amiga (atari_st when extractor lands) |
| `dos_1992` | 9 stages | msdos |
| `cartridge_1992` | 8 stages | snes_eu + genesis_europe |
| `gba_2004` | 2 stages | gba_usa |
| **Total** | **28 .asm files** | **29 (port, stage) targets** |

The deduplication: `cartridge_1992/LAKE.asm` produces
byte-identical output for **both** SNES-EU level_1 and
Genesis-EU level_0. (Two targets, one source.)

The driver (`tools/verify_stage.py` in archaeology repo) reads a
table that maps each port's level slots to (branch, stage)
pairs:
- `snes_eu`: { CODE_WHEEL=0, LAKE=1 }
- `genesis_europe`: { LAKE=0, PRISON=1, …, PASSCODE=6 }
- `msdos`: { CODE_WHEEL=0x15, INTRO=0x18, LAKE=0x1B, … }
- `amiga`: same indices as msdos
- `gba_usa`: { CODE_WHEEL=0, LAKE=1 }

For each canonical .asm, the driver finds every port that uses
that (branch, stage) and verifies byte-match against the port's
expected bytes (cartridge chunk or resource bin).

**Honest scope note**: Phase 3a achieves only **one inter-port
deduplication** — the SNES-EU + Genesis-EU LAKE share. That's
because the four bytecode branches genuinely diverge:
Amiga vs DOS share NO byte-identical stages, DOS vs cartridge
likewise, etc. (See research/07 in archaeology for the full
hash matrix.) Phase 3a's value is **structural**: organizing
the source tree by genealogical branch rather than by port slot,
making future deduplications trivial when more ports come online
(Atari ST will share Amiga's chahi_amiga_1991 sources verbatim).

## Phase 3b — Conditional-compilation pipeline (✅ infrastructure achieved 2026-05-01)

### Initial deferral, then revival via structural diff

The first cut at Phase 3b was deferred (research/07) on the
assumption that branches share too little for `#ifdef` merging
to be useful. Then the structural-diff tool
([research/08](../another-world-archaeology/docs/content/research/08-cross-branch-structural-similarity.md))
revealed much higher cross-branch overlap than byte-equality had
shown:

- INTRO: 83-99% structural similarity across all 4 branches
- LAKE: 88-92% within Heineman lineage (DOS / cartridge / GBA)
- Other stages: 50-90% similar within Heineman lineage

So Phase 3b became attractive again, at least for stages within
the Heineman lineage.

### Pipeline (working)

The build pipeline now supports conditional compilation via
**comment-syntax directives**:

```asm
;@if BRANCH == "cartridge_1992"
    setup channel=0x09, address=LABEL_CARTRIDGE_SPECIFIC
;@elif BRANCH == "dos_1992"
    setup channel=0x09, address=LABEL_DOS_SPECIFIC
;@else
    setup channel=0x09, address=LABEL_DEFAULT
;@endif
```

The preprocessor (`another-world-archaeology/tools/awvm_preprocess.py`)
reads a `releases/<target>.flags` file, evaluates each `;@if`
condition, and emits a per-branch `.asm` ready for `awvm-asm`.

`make preprocess SRC=foo.asm.in TARGET=cartridge_1992`
produces `build/cartridge_1992/foo.asm`.

End-to-end test passing as of 2026-05-01: a stub
`src/levels/_phase3b_demo/LAKE.asm.in` with three conditional
comment branches preprocesses correctly for both
`cartridge_1992` and `dos_1992` targets, and (since the
conditional content was just inline comments) the assembled
output for the cartridge target is byte-identical to the original
Genesis-EU level_0 chunk (`md5=e24580ddb549...`).

### What's still pending

The infrastructure is in place. **What's deferred** is the
labour-intensive part: actually authoring unified
`.asm.in` files for each (branch-pair, stage). For each pair to
be unified, the maintainer must:

1. Find every byte-level divergence between the two source files.
2. Decide which divergences belong in `;@if` blocks (genuine
   per-branch differences) vs which can be unified by parameter-
   ising labels.
3. Author the unified `.asm.in`.
4. Verify byte-match against both ports' original output.

The most promising next-step targets (highest cross-branch
similarity):

| Pair | Stage | Structural sim | Notes |
|---|---|---|---|
| cartridge_1992 ↔ gba_2004 | INTRO | 0.988 | Easiest target |
| dos_1992 ↔ cartridge_1992 | INTRO | 0.979 | Next |
| cartridge_1992 ↔ gba_2004 | LAKE | 0.920 | After INTRO |
| dos_1992 ↔ cartridge_1992 | LAKE | 0.914 | |

Cross-branch unification across to **chahi_amiga_1991** (Amiga) is
lower-priority — most stages share 60-65% structure with the
Heineman lineage, which would require many `;@if` blocks.

## Phase 4 — Atari ST 1991 + other gated ports

Once Atari ST's memlist parser lands (issue #0004), Atari ST will
trivially extend Phase 1 + 2 + 3 (since its bytecode is byte-
identical to Amiga's per research/05).

Mac, Apple IIgs, 3DO, Mega-CD, Symbian, NDS, Apple II demake —
each gated on its own extractor work. As they come online, drop
into the same loop.

## Cross-cutting infrastructure

These get implemented as needed, not in a separate phase:

- **Byte-equivalence test framework**: per-target, per-artifact
  comparison against a reference dump in `another-world-archive/`.
- **Flag glossary**: every flag has a one-paragraph explanation in
  `docs/glossary.md` describing what it controls, why, and what
  evidence motivated its addition.
- **Toolchain**: AWVM_Tools provides `awvm-asm` (assembler) and
  `awvm-disasm` (disassembler). New tools will be added as needed
  (e.g., a polygon-resource builder, an ADF packer with checksum
  recompute, …).

## Strategic dependencies on the archaeology project

The reconstruction project is fundamentally **downstream** of
archaeology findings. A flag can't be added until the divergence it
governs has been surfaced and characterised. The archaeology issue
tracker therefore feeds this repo:

| Archaeology issue | Reconstruction flag(s) |
|---|---|
| #0048 (gate-1 intent) | `BEETLE_KICK_GATE_1` |
| #0051 (DOS-vs-SNES bytecode divergence) | `BYTECODE_BRANCH` enum |
| #0054 (unused-polygon scan) | (will surface previously-unknown flags) |
| #0055 (unused SOUND scan) | (likely surface unused-music flags) |
| #0058 (dead-bytecode reachability) | (clarifies gate-1/2 mechanism for the BEETLE_* flags) |
| (all closed beetle research) | `BEETLE_RENDERING_GATE_2`, `BEETLE_KICK_GATE_1` |
| #0002 codewheel | `CODEWHEEL_CHECK` |
| #0001 gun ammo | numeric constants — likely no flag, just shared `#define`s |
| #0004 (Mac patch chain) | `MAC_SEGMENT_LAYOUT` enum |

Phase 1 is unblocked today. Phase 3+ benefits substantially from
issues #0054..#0058 completing first, since they'll surface flags
we haven't predicted.
