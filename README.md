# Another World — source reconstruction

Sibling repo to `another-world-archaeology`, `another-world-archive`,
and `another-world-hacks`. Goal: **a single C/C++ source tree that
builds back to byte-matching binaries for every cataloged release of
*Another World* / *Out of This World***, with feature differences
expressed as **conditional compilation flags** rather than as
divergent source forks.

Why: the archaeology project has so far reconstructed individual
findings (the gun-ammo mechanic, the codewheel patch, the beetle gate
1+2, the SNES/Genesis byte-identical bytecode). The natural next step
is to express the *full* port-divergence map as a structured codebase
where every divergence has a name and a per-release setting.

## Strategy

1. Pick **one port** as the reference for the initial reconstruction.
   Likely **MS-DOS** (Heineman 1992) because it's the most-archived
   and the bytecode is well-disassembled.
2. Reconstruct the source code of the port — engine + per-level
   bytecode "as if" it were the original C source. Doesn't need to
   look like the original character-for-character, just compile to
   the same bytes.
3. Write a `Makefile` (or build system) that drives the toolchain
   end-to-end, from .c sources to byte-matching `.bin` /
   `bank01..bank0d` / `.adf` etc.
4. Identify each *divergence* between releases (e.g., gate 1, gate 2,
   beetle suppression, codewheel-protection, SNES-EU/Genesis-EU
   bytecode differences) and gate the matching code with a
   **conditional compilation flag**. Flags are named *semantically*
   — what feature they govern, not which release uses them.
5. Maintain a **per-release flag-values table** (e.g.,
   `releases/msdos.flags`, `releases/amiga.flags`) listing which
   flags are on/off for that target.
6. The build system, when given a target release name, reads its
   flag values, configures the build, and produces byte-matching
   output.

The end state: **one codebase, N targets, each fully byte-matching**.

## What divergences look like

Examples surfaced by archaeology research findings #01–#05 that would
become flags:

| Flag | Type | Meaning | Set on |
|---|---|---|---|
| `BEETLE_KICK_GATE_1` | bool | Disable kick-detector via channel-0x2E overwrite | All ports (intentional pre-shipping cut) |
| `BEETLE_RENDERING_GATE_2` | bool | Kill the beetle's rendering channel at level entry | DOS, SNES-EU, Genesis-EU, GBA Foxy |
| `CODEWHEEL_CHECK` | bool | Include codewheel copy-protection check (level 0) | DOS retail, Amiga retail (vs. nologo presskit + archive.org) |
| `BYTECODE_BRANCH` | enum {chahi-1991, heineman-dos-1992, heineman-cartridge-1992} | Which bytecode tree this release inherits from | per-port |
| `LEVEL3_SUPERBLAST_COST` | int | -100 in level 3, -50 elsewhere | shared across all ports |
| `MAC_SEGMENT_LAYOUT` | enum {v1.0, v1.0.2, v1.0.3} | Symantec C runtime segment layout | Mac builds |

Some flags will be enums (multiple discrete values), some bools, some
integer parameters. The key invariant: any byte difference between
two releases is either explained by a flag, or is a bug in the
reconstruction.

## Directory layout

```
src/                  C/C++ source tree (engine + bytecode).
include/              headers
build/                generated build artifacts (gitignored)
releases/             one *.flags file per cataloged release
toolchain/            byte-matching toolchain (assemblers, packers, ADF builders, …)
tests/                byte-equivalence tests (run after each build)
docs/                 narrative documentation; flag glossary; per-divergence rationale
Makefile              top-level orchestrator
```

## Repo policy

- **No original game files.** Same as the hacks repo. Builds operate
  on local copies the user supplies; outputs are reproducible from
  source + flag values.
- **Frequent commits.** Every measurable progress increment (a flag
  added, a file reconstructed, a byte-match verified) is its own
  commit.
- **Byte-equivalence tests are CI gates.** The repo doesn't carry
  reference binaries (those are in `another-world-archive/`), but
  the test suite verifies that local builds match those references.
- **Sub-projects can fork from this repo** if they want a frozen
  baseline, but the canonical state is `master` with all flags
  expressed.

## Status

Just initialised (2026-04-30). See [PLAN.md](PLAN.md) for the
phased roadmap and [docs/glossary.md](docs/glossary.md) for the
growing flag glossary. Issues tracked in the
[archaeology repo's issue tracker](../another-world-archaeology/issues/)
under issue numbers `#0059..#0064` (this repo's first phase).
