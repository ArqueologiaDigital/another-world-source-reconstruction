# Another World — Source Reconstruction

Sibling repo to [`another-world-archaeology`](https://github.com/ArqueologiaDigital/another-world-archaeology),
[`another-world-archive`](https://github.com/ArqueologiaDigital/another-world-archive),
and [`another-world-hacks`](https://github.com/ArqueologiaDigital/another-world-hacks).

**Goal:** a single source tree that builds back to byte-matching
binaries for every cataloged release of *Another World* / *Out of
This World*, with feature differences expressed as **conditional
compilation flags** rather than as divergent source forks.

The archaeology project has reconstructed individual findings (the
gun-ammo mechanic, the codewheel patch, the beetle gate 1+2, the
SNES/Genesis byte-identical bytecode, etc.). This repo's purpose is
to express the *full* port-divergence map as a structured codebase
where every divergence has a name and a per-release setting.

## Strategy

1. **Pick reference ports** for each branch lineage. For the
   bytecode tree we currently track four:
   `chahi_amiga_1991`, `dos_1992`, `cartridge_1992` (Heineman
   SNES + Genesis), `gba_2004` (Foxy Studios).
2. **Reconstruct the source code** of each port — engine + per-level
   bytecode "as if" it were the original C source. Doesn't need to
   look like the original character-for-character, just compile to
   the same bytes.
3. **Drive the toolchain end-to-end** from .c sources to byte-matching
   `.bin` / `bank01..bank0d` / `.adf` etc. (Phase 1 byte-match for
   bytecode is in place; Phase 2 will extend to non-bytecode
   resources and bank-packaging.)
4. **Identify each divergence** between releases (gate 1, gate 2,
   beetle suppression, codewheel-protection, SNES-EU/Genesis-EU
   bytecode differences, …) and gate the matching code with a
   **conditional compilation flag**. Flags are named *semantically*
   — what feature they govern, not which release uses them.
5. **Maintain a per-release flag-values table** (`releases/*.flags`)
   listing which flags are on/off for that target.
6. The build system, given a target release name, reads its flag
   values, configures the build, and produces byte-matching output.

The end state: **one codebase, N targets, each fully byte-matching**.

## What divergences look like

Examples that have already been promoted into flags:

| Flag | Type | Meaning | Set on |
|---|---|---|---|
| `BEETLE_KICK_GATE_1` | bool | Disable kick-detector via channel-0x2E overwrite | All ports (intentional pre-shipping cut) |
| `BEETLE_RENDERING_GATE_2` | bool | Kill the beetle's rendering channel at level entry | DOS, SNES-EU, Genesis-EU, GBA Foxy |
| `CODEWHEEL_CHECK` | bool | Include codewheel copy-protection check (level 0) | DOS retail, Amiga retail (vs. nologo presskit + archive.org) |
| `BYTECODE_BRANCH` | enum | Which bytecode tree this release inherits from (`chahi_amiga_1991`, `dos_1992`, `cartridge_1992`, `gba_2004`) | per-port |
| `LEVEL3_SUPERBLAST_COST` | int | -100 in level 3, -50 elsewhere | shared across all ports |
| `MAC_SEGMENT_LAYOUT` | enum | Symantec C runtime segment layout | Mac builds |

Some flags are enums (multiple discrete values), some bools, some
integers. The key invariant: **any byte difference between two
releases is either explained by a flag, or is a bug in the
reconstruction**.

## Phase 3 unification (current)

The latest milestone is the **multi-way unified bytecode source** at
`src/levels/_unified/<STAGE>.asm.in`. A single file expresses the
bytecode for all four cart/gba/amiga/dos branches; the differences
are wrapped in `;@if BRANCH == "..."` directives processed by
`tools/awvm_preprocess.py` (in the archaeology repo). LAKE is
currently 4-way; INTRO is 2-way (cart + gba) pending dos and amiga
integration.

## Directory layout

```
src/                  Source tree (per-branch and unified).
  levels/<branch>/    Phase 3a: per-branch canonical .asm files.
  levels/_unified/    Phase 3b: cross-port unified .asm.in files.
include/              Headers.
build/                Generated build artifacts (gitignored).
releases/             One *.flags file per cataloged release.
toolchain/            Byte-matching toolchain (assemblers, packers, ADF builders, …).
tests/                Byte-equivalence tests.
docs/                 Narrative documentation; flag glossary; per-divergence rationale.
Makefile              Top-level orchestrator.
```

## Repo policy

- **No original game files.** Same as the hacks repo. Builds operate
  on local copies the user supplies; outputs are reproducible from
  source + flag values.
- **Frequent commits.** Every measurable progress increment (a flag
  added, a file reconstructed, a byte-match verified) is its own
  commit.
- **Byte-equivalence tests are CI gates.** The repo doesn't carry
  reference binaries (those are in
  [`another-world-archive`](https://github.com/ArqueologiaDigital/another-world-archive)),
  but the test suite verifies that local builds match those
  references.

## Getting started

Clone alongside its siblings (the verification tools and original
fixtures are expected at sibling paths):

```bash
mkdir another-world && cd another-world
git clone git@github.com:ArqueologiaDigital/another-world-archaeology.git
git clone git@github.com:ArqueologiaDigital/another-world-archive.git
git clone git@github.com:ArqueologiaDigital/another-world-source-reconstruction.git
git clone https://github.com/felipesanches/AnotherWorld_VMTools.git
cd AnotherWorld_VMTools && cargo build --release && cd ..

# Run all per-branch byte-match checks
make -C another-world-source-reconstruction verify-stages

# Per-port bytecode round-trip
make -C another-world-source-reconstruction verify-bytecode TARGET=gba_usa
```

## Status

Active. See [`PLAN.md`](PLAN.md) for the phased roadmap and
[`docs/glossary.md`](docs/glossary.md) for the growing flag glossary.
Issues are tracked in the
[archaeology repo's issue tracker](https://github.com/ArqueologiaDigital/another-world-archaeology/tree/master/issues).
