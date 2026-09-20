# Naming polygons without rendering them: what works, and what it is worth

`named_art_only.py` established the direction of the backlog — the big
stages' routine layer waits on their polygon layer, because a routine drawing
only unidentified art cannot be named from it. True of the bulk, and this
directory is the exception: the cases where the **routine layer can name the
polygon layer**, with no render.

Every rule here derives a constant's name from something already earned, so
none of them proposes a subject. That is also their ceiling.

## The rules, and what each returned on 2026-09-19

| rule | where | found | applied |
|---|---|---|---|
| sole `_DRAW` routine, one exclusive draw | `nameable_from_drawer.py` (default) | 8 | 8 |
| named routine, whole draw set exclusive, **one anchor** | `--animations` | 31 routines / 171 constants | 22 routines / 108 constants |
| family completion from earned members | `../family-completion/` | 4 | 4 |
| `*_COMPOSITE` routine, whole part-set exclusive | measured, not kept | **0** | — |

`--pool` prints the wider population: **658** unnamed constants whose sole
drawer is named. That is the pool, not the yield. The gap between 658 and the
~120 above is the whole content of this directory.

## Why most of the pool does not qualify

Each of these cost a batch, a revert or both before becoming a filter:

- **the routine names a mechanism, not a subject.** `FILL_PAGE_00_COLOR_08`
  draws two constants; the art is not "a page fill". 16 routines dropped.
- **the routine's own name carries a raw constant index** —
  `DRAW_CITY_SEQ_435_436`, `DRAW_CINEMATICS_166_TO_171`. It is a placeholder
  under NAMING.md §1 whatever else it says, and deriving from it would copy
  the placeholder onto the art.
- **the other port already uses the derived name for other art.** 6 routines.
  This one is invisible to every per-port check, by design, because a
  branch-scoped rename is judged against that branch's files — and it is the
  one that actually bit: naming msdos/INTRO's `LESTER_EXITING_CAR` frames
  passed `make test` 29/29 and silently moved the cross-port audit from 10
  disagreements to 23.
- **several anchors.** One anchor means frames of one thing; several mean
  props along a path, and a prop needs identifying on its own. 12 routines /
  87 constants sit here.
- **the sizes do not support one family.** `TANK_DESTROYED_CUTSCENE_BLAST_
  ENTRY` passes every structural test and its six frames measure 11x4, 11x4,
  10x5, 10x4, 8x3 and then 205x138. Five specks and a full-screen flash are
  not six frames of one thing.
- **two earned routine names for one art** (#0120). amiga's
  `STORM_AMBIENT_DRIFT_DRAW_LOOP` and msdos's
  `STORM_PARTICLE_TUMBLE_ANIM_LOOP` draw art identical five for five by md5.
  Not ours to adjudicate.

## What is left

What remains in the pool needs a render, which is the E3 work these rules
exist to avoid and cannot replace. The honest read of the table above is that
naming-without-looking is worth about a sixth of the constants it can see,
and the rest of the 64% still unnamed will be found by looking at it.

## 2026-09-20: rule 1 widened past the `_DRAW` suffix

The original rule 1 was "the routine's name ends in `_DRAW`". That is a strong
signal and far too narrow a one. After the routine layer gained 284 names from
the shared-bank work, the `_DRAW` form matched **zero** of them — those are
spelled `DRAW_HERO_WALK_RIGHT_F03` — and the probe reported 0 nameable while
431 constants had exactly one named drawer.

Rule 1 is now "semantic, and denotes a subject", enforced by the filters the
suffix was standing in for. Each of these was added because a real candidate
reached the list:

| filter | what it caught |
|---|---|
| `MECHANISM` + `SHARED_RET`, `DISPATCH`, `_TICK`, `PAGE_`… | `SHARED_RET`, `PRISON_SHOT_STATE_FRAME_DISPATCH_LEFT` |
| `KILL_ALL`, `_AND_KILL`, `_AND_RET` | `CINEMATIC_KILL_ALL_CHANNELS_AND_KILL`, which reached the apply step |
| `_BY_FACING`, `_BY_STATE`, `_SELECT` | `PRISON_TELEPORT_UP_POSE_BY_FACING` — a **selector**, not a subject |
| `RE_HEXTAIL` | 556 names ending in a raw hex token inherited from the routine's own `jne` literal, which §1 forbids on a constant |

779 → 71 → **69** as those went in.

### Verifying instead of transferring, which caught one

The docstring says to check the derived name against the measured shape. Done
on a sample, and it earned its keep:

    CINEMATIC_505  ->  PRISON_SHOT_BEAM_SINGLE_DOT      0x1,  1 leaf
    CINEMATIC_129  ->  BIOMETRIC_SCAN_LINE_SWEEP        1x210, 1 leaf
    CINEMATIC_775  ->  CAVES_LASER_IMPACT_..._ABOVE_02  17x12, 7 leaves
    CINEMATIC_553  ->  PRISON_TELEPORT_UP_POSE_BY_FACING 6x94, 4 leaves

The first three corroborate exactly — a "single dot" that measures one pixel,
a "scan line" that is one unit wide and 210 tall. The fourth is a thin
vertical sliver, which is a *beam*, under a name that says "pose". That is
what `_BY_FACING` now excludes.

### Two application hazards, both caught before they landed

**The proposal file must be per stage.** `apply_branch_scoped_names.py`
matches rows by constant number and takes the stage from its own `--stage`
flag, so a per-*port* file holding PASSCODE and PRISON rows together offers
`CINEMATIC_013 -> CINEMATIC_PASSCODE_ALPHANUM_CODE_CASE_03` **for PRISON**.
Seen in a dry run. The probe now writes one file per (port, stage).

**The `EQU` must follow the use.** The applier renames the canonical `.asm`
and the shared unified draw sites, but not the `EQU` in a branch's own entry
chunk. That leaves a shared chunk naming a symbol only the canonical file
defines: 7 undefined references, verify-unified **26/29**, verify-stages still
29/29 because each canonical file was self-consistent.
`../unified-scoping/sync_equ_rename.py` carries the rename into that branch's
own chunks and nowhere else.

Applied: **69 constants**, `make test` 29/29 and 29/29, `undefined_symbols.py`
clean. 20 of the proposals were rejected by the validator and the sync tool
skipped them, because a proposal is not an application.

## Widening to all four branches, and a target the checker does not see

The routine-naming pass was losing 81 renames because the cartridge and GBA
builds share labels with amiga and msdos and had **no proposals of their
own** — and they had none because this probe only scanned the two priority
ports. Their cinematic constants are their own bank at their own offsets, so
the sole-named-drawer rule applies to them independently.

Scanning all four took the probe from 32 nameable to **112**.

Two things had to be fixed to get there:

**Rule 6 must tolerate a missing ROM.** It compares art by `canonical_md5`,
which needs the port's `cinematic.rom`; snes_eu and gba_usa have no extracted
resources, and `slab()` raises `SystemExit`, which is a `BaseException` and
walked straight past the handler — aborting the whole run the moment the
probe was widened. Ports without a ROM are now skipped and named in the
output, so the check covers the pairs it can see and says which it cannot.

**`genesis_europe` is a verify target that `undefined_symbols.py` does not
check.** Applying all seven per-stage batches gave `undefined_symbols` clean
and `make test` **28/29**: `genesis_europe/CAVES: MISMATCH`. That build is
assembled from `cartridge_1992`'s source but compared against its own
binary, and the checker's `BRANCHES` list has four entries that do not
include it. Re-applying without the cartridge CAVES batch is **29/29 and
29/29**, so those 18 names are the ones at fault and are held.

Applied: 43 constants across snes_eu CAPSULE, ENDING, INTRO, PRISON, TANK and
gba_usa INTRO. Held: the 18 cartridge CAVES names, pending a checker that
covers `genesis_europe` — which is the real fix, since right now only the
byte gate can see that target and it cannot say *which* symbol moved.

### The `genesis_europe` mismatch was a name collision, not a checker gap

Diagnosed rather than left as "a target no checker sees". `cart__entry.inc`
ended up with **two** `EQU`s of one name:

    cart__entry.inc:2242  CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG  EQU 0x6B86
    cart__entry.inc:2262  CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG  EQU 0x73A8

The second is `CINEMATIC_315`, renamed by this pass onto a name cartridge
already used at a different offset. Two definitions, the later one wins, and
the bytes move — which is why `genesis_europe/CAVES` mismatched while
`undefined_symbols.py` stayed clean: nothing was *undefined*, one thing was
defined twice.

**The taken-check never looked at `EQU`s.** It tested `new in bodies or new
in drawn` — labels and drawn symbols — so a name that exists as an `EQU` but
is not drawn in that file looked free. It now also collects every `EQU` name
in the canonical file *and* in the unified arms that carry that branch's
copy, which is where the collision actually was.

With that fixed the cartridge CAVES batch applies cleanly: **29/29 and
29/29**, no duplicate `EQU` in the cart arms, `--duplicates` still one name
per picture. The `genesis_europe` checker gap is real and still worth closing
— it is why only the byte gate caught this — but it was not the cause.
