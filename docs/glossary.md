# Flag glossary

Every flag used by the build system has an entry here. New flags
arrive when a divergence between releases is discovered (typically
via [the archaeology project](../../another-world-archaeology/)).

## Naming convention

- All-caps, underscore-separated.
- Prefixed by the **subsystem** the flag governs:
    - `BEETLE_*` — level-2 beetle mechanic
    - `GUN_*` — gun / energy mechanic
    - `CODEWHEEL_*` — copy protection
    - `MAC_*` — Mac-specific
    - `BYTECODE_*` — bytecode lineage / branch selection
- Boolean flags use `_*=on/off`; enums use descriptive values
  (`BYTECODE_BRANCH=heineman_dos_1992`); ints are decimal.

A flag's name describes **what feature** it governs — never **which
release** it's used in. The release-to-flag mapping lives in the
per-release `.flags` files.

---

## Index

| Flag | Type | Governs | Evidence |
|---|---|---|---|
| `BYTECODE_BRANCH` | enum | Which bytecode tree this release descends from | [research/05](../../another-world-archaeology/docs/content/research/05-beetle-in-the-lake-stage.md) cartridge cross-check |
| `CODEWHEEL_CHECK` | bool | Include the level-0 codewheel copy-protection check | [research/02](../../another-world-archaeology/docs/content/research/02-amiga-codewheel-protection.md) |
| `BEETLE_KICK_GATE_1` | bool | Disable the kick-detector via channel-0x2E setup-then-overwrite | [research/05](../../another-world-archaeology/docs/content/research/05-beetle-in-the-lake-stage.md), [open question 06](../../another-world-archaeology/docs/content/open-questions/06-gate-1-intent.md) |
| `BEETLE_RENDERING_GATE_2` | bool | Kill the beetle's rendering channel at level entry | [research/05](../../another-world-archaeology/docs/content/research/05-beetle-in-the-lake-stage.md) |
| `MAC_SEGMENT_LAYOUT` | enum | Symantec C runtime segment-layout version | [research/04](../../another-world-archaeology/docs/content/research/04-mac-port-patch-chain.md) |

---

## Per-flag details

### `BYTECODE_BRANCH`

**Type**: enum  
**Values**: `chahi_1991`, `heineman_dos_1992`, `heineman_cartridge_1992`, `foxy_gba_2004`  
**Default**: `heineman_dos_1992` (the most-archived port)

Selects which bytecode tree this release inherits from. The
2026-04-30 cartridge cross-check
([research/05](../../another-world-archaeology/docs/content/research/05-beetle-in-the-lake-stage.md))
established that the Heineman 1992-93 ports carry **two** distinct
bytecode branches, not one — DOS has its own hash; SNES-EU +
Genesis-EU share a byte-identical resource.

Per-port mapping:
- `chahi_1991`: Amiga 1991 + Atari ST 1991 (byte-identical bytecode)
- `heineman_dos_1992`: MS-DOS 1992
- `heineman_cartridge_1992`: SNES-EU 1992 + Genesis-EU 1993
  (byte-identical bytecode — strong cross-CPU port reuse signal)
- `foxy_gba_2004`: GBA fan port (modified bytecode, gates preserved)

### `CODEWHEEL_CHECK`

**Type**: bool  
**Default**: `on` (matches retail releases)

Enables the level-0 codewheel copy-protection check. Off for the
Amiga `_nologo_noprotec` presskit, which has a 13-byte diff in
level-0 bytecode confined to offsets `0x9fc..0xa88` — exactly the
codewheel-check region.

### `BEETLE_KICK_GATE_1`

**Type**: bool  
**Default**: `on`  
**Per-port**: present on **all** disassembled ports.

Registers the kick-detector on channel `0x2E`, then immediately
registers a cleanup-watcher on the same channel slot — the second
`setup` call overrides the first, leaving the kick-detector dead.

[Issue #0048](../../another-world-archaeology/issues/) (gate-1
intent) tracks the question of whether this is intentional or
accidental. As of 2026-04-30 it strongly leans intentional, since
the wing-flip animation it silences leads into a broken death
cutscene that crashes the VM.

### `BEETLE_RENDERING_GATE_2`

**Type**: bool  
**Default**: `on` (matches the Heineman-lineage majority)  
**Per-port**:
- `off`: Amiga 1991, Atari ST 1991 (Chahi master)
- `on`: DOS 1992, SNES-EU 1992, Genesis-EU 1993, GBA 2004
  (Heineman + descendants)

Adds a `setup channel=0x09, address=KILL_CHANNEL_ROUTINE`
immediately after the beetle's spawn line in the level-2 entry
script, killing the beetle's rendering thread. With this on, the
beetle isn't visible in the lake stage at all.

### `MAC_SEGMENT_LAYOUT`

**Type**: enum  
**Values**: `v1.0`, `v1.0.2`, `v1.0.3`  
**Per-port**: only meaningful for Mac targets.

Per
[research/04](../../another-world-archaeology/docs/content/research/04-mac-port-patch-chain.md):
the 1993 Mac port shipped three close-versioned builds bundled in
a single StuffIt archive. v1.0 → v1.0.2 was a focused 3-segment
fix; v1.0.2 → v1.0.3 was a structural reorganisation almost
certainly driven by a Symantec C runtime upgrade. The `OOTW`
4cc resource carries human-readable copyright strings that
differ per version.
