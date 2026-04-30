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

## Phase 3 — Unified source via conditional compilation (still in scope)

**Goal**: a single source tree that produces byte-matching
resources for multiple ports via flags.

Bytecode is the only place this matters at present, since raw
assets are passthrough. So Phase 3 reduces to:

- Diff the per-port .asm files (e.g., amiga_level-2.asm vs
  msdos_level-2.asm) and identify the divergent regions.
- Refactor into a unified .asm with `#ifdef BYTECODE_BRANCH ...`
  or similar conditionals.
- Per-port .flags file selects the right branch.
- The build assembles the unified .asm with the selected flags and
  produces byte-matching bytecode.

The bytecode has 4 distinct branches across the 5 ports we cover:
1. Chahi 1991 (Amiga + Atari ST)
2. Heineman DOS 1992
3. Heineman cartridge 1992-93 (SNES-EU + Genesis-EU)
4. Foxy GBA 2004

Phase 3 is therefore non-trivial (it has to capture every
between-branch divergence) but well-bounded (only 4 source trees
to merge per level). Issue #0061 tracks.

**Acceptance**: `make verify TARGET=<any>` succeeds with a single
unified `src/levels/level-N.asm` per level.

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
