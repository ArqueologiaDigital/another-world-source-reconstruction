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

## Phase 2 — Whole-port reconstruction (DOS)

**Goal**: full byte-matching MS-DOS 1992 build.

Bytecode is done (Phase 1). Phase 2 covers the rest of the
on-disk artifacts:

- Engine binary (the `.EXE`) — likely the hardest part; might
  need to be deferred and stubbed (just copy from original).
- Bank packing pipeline (`memlist.bin` + `bank01..bank0d`):
  given a set of resources (BYTECODE, POLY_CINEMATIC, PALETTE,
  SOUND, MUSIC), produce byte-matching bank files. The pack
  format is well-understood — issue #0060 tracks.
- Polygon resource builder: the inverse of
  `another-world-archaeology/tools/polygon_render.py` — given
  SVG/internal-rep, emit AW polygon bytes. Probably easier as a
  Python tool that emits the canonical AW polygon binary
  directly from the parser's representation.
- Palette resource builder: trivial; copy bytes verbatim from
  user-supplied originals (or, for retail+presskit, just copy
  with one byte altered for the codewheel-patched version).
- Sound + music samples: also trivial copy.

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
