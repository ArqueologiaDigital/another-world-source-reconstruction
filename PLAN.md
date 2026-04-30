# Phased roadmap

The reconstruction project has natural dependencies on the
archaeology project's *findings*. Several flags can't be defined
until the archaeology has surfaced them. Phases are designed so
that each is independently useful even if later phases stall.

## Phase 0 — Scaffolding (this commit)

- README + PLAN + initial directory structure
- Issues opened in `another-world-archaeology/issues/` to track
  reconstruction progress: `#0059..#0064`
- No code yet — pure planning artifact

## Phase 1 — Pick a reference port + reproduce a single resource

**Goal**: prove the reconstruction loop works end-to-end for one
small artifact.

- Pick **MS-DOS 1992** as the reference port.
- Reconstruct **just the level-0 bytecode** (the codewheel screen).
  This is small (~3.5 KB), well-understood, and has a known
  divergence (the codewheel patch) that becomes the first flag.
- Write a Makefile rule that assembles a `.asm` source file (using
  AWVM_Tools' `awvm-asm`) into a byte-matching `level-0.bin`.
- Verify byte equivalence against the original.
- Add the first flag: `CODEWHEEL_CHECK` (default on for retail,
  off for `nologo_noprotec` Amiga presskit).

**Acceptance**: `make level-0.bin TARGET=msdos` produces a binary
byte-identical to the DOS retail dump.

## Phase 2 — Whole-port reconstruction (DOS)

**Goal**: full byte-matching MS-DOS 1992 build.

- Reconstruct all 9 levels' bytecode (.asm sources)
- Reconstruct the engine binary (the .EXE) — this is the hard
  part; might need to be deferred and stubbed
- Reconstruct the bank packing pipeline (memlist + bankNN)
- Reconstruct the polygon resources (POLY_CINEMATIC + POLY_ANIM)
  — these require a tool that converts SVG (or our internal
  representation) back to AW polygon bytes
- Reconstruct the palette resources, sound + music samples (just
  copy bytes from the originals into the build)

**Acceptance**: `make TARGET=msdos` produces every original file
byte-identical to the DOS retail dump.

## Phase 3 — Add Amiga as a second target

**Goal**: prove the conditional-compilation strategy works.

- Add Amiga-specific code paths (different banking, different
  palette format, different bank packing)
- Identify the first batch of cross-port flags:
    - `BEETLE_RENDERING_GATE_2` (off for Amiga, on for DOS)
    - `BYTECODE_BRANCH` (chahi-1991 vs heineman-dos-1992)
    - …others surfaced by the asset-scan work in archaeology
      issues #0054..#0058
- Maintain a *single* `src/` tree that compiles to both
  byte-matching outputs

**Acceptance**: `make TARGET=amiga` and `make TARGET=msdos` both
produce byte-identical outputs.

## Phase 4 — Add the cartridge ports (SNES-EU, Genesis-EU, GBA)

**Goal**: cover the Heineman cartridge branch + Foxy 2004.

- Re-encode the bytecode for cartridge formats (per the SNES↔Genesis
  byte-identity finding from archaeology research/05)
- Add cartridge-specific flags
- Add Foxy 2004 modifications as a flag delta off Genesis-EU

## Phase 5 — Atari ST 1991

**Goal**: complete the Chahi 1991 branch.

- Atari ST shares Amiga's level-2 bytecode byte-identically (per
  archaeology research/05). So the source side might be identical
  to Amiga; only the engine binary differs.

## Phase 6 — Mac patch chain

**Goal**: cover v1.0 / v1.0.2 / v1.0.3 + the two updaters.

- Most Mac-specific flags govern the Symantec C runtime segment
  layout. Different from the bytecode-level flags.

## Phase 7+ — Less-common ports

3DO, Apple IIgs, Mega-CD, Symbian, NDS, GBA, Apple II demake. Each
has its own structural differences that need their own
sub-architectures.

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
