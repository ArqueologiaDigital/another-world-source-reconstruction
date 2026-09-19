# A polygon reference that is not even a symbol

`make test`'s lint reports `raw-video`: "every polygon reference should be
symbolic". A `video offset=0x…` operand is below `CINEMATIC_NNN` on the
evidence ladder — a numeric name is at least a symbol somebody can rename
later, and a bare literal in an operand is not.

gba_usa/LAKE carried **24** of them over 10 distinct offsets while otherwise
sitting at 99.1% semantic.

## `resolve_raw_offsets.py`

**Question:** what name does a raw offset deserve, without committing #0107 —
taking a name earned by rendering on one port and putting it on another port's
constant, which "would be right 2% of the time"?

```bash
python3 notes/raw-polygon-operands/resolve_raw_offsets.py
python3 notes/raw-polygon-operands/resolve_raw_offsets.py --port gba_usa \
    --stage LAKE --ref amiga
```

Exit 0 when every raw operand resolves, 1 when any does not, so a new one that
this reasoning cannot settle gets flagged rather than guessed at.

The answer is an **address** correspondence rather than an index one. Each port
keys a polygon name to its own offset, but the banks are not independently
shuffled: where a port's bank is the same data relocated, every shared name
sits at a constant delta. The probe measures the delta distribution over
hundreds of names first, works out which gba address range each delta governs,
checks the ranges do not overlap, and only then resolves an offset — by adding
the delta of the region it falls in and asking whether the reference port has a
name at exactly that address.

Measured 2026-09-19, amiga vs gba_usa LAKE, 659 polygon EQUs on both ports:

```
delta 0x1410   522 names   gba_usa 0x4962..0xDE2E
delta 0x13C0   103 names   gba_usa 0x096E..0x4712
```

Two regions, disjoint, so every offset has exactly one valid reading. The
leftover deltas (0x1DA4 ×9, 0x0A68 ×2, 0 ×2 and singletons) are art the GBA
release moved or replaced; the probe asserts none of them covers an address a
raw operand uses rather than assuming it.

## The one that is weaker, said out loud

`0x08FC` sits **0x72 bytes below** the 0x13C0 region's lowest measured name, so
resolving it is extrapolation, not interpolation. The probe reports it as
`EXTRAPOLATED` with the margin and refuses to treat it as equal to the other
nine.

It was adjudicated on separate evidence: it resolves to
`CINEMATIC_HERO_LAND_LEFT`; its mirror `0x0C1E` is in-region and resolves to
`CINEMATIC_HERO_LAND_RIGHT` under the same delta; both ports use each name
exactly three times; every use has the same `zoom=[0x03]` operand shape; and
the routine using it on gba is `HERO_RUN_LEFT_LOOP`. Five agreements — but
recorded as the weaker class, not folded in with the nine.

## `apply_gba_lake_raw_offsets.py`

The one-off migration: adds ten `CINEMATIC_… EQU 0x…` lines with **gba's own
offsets** — the rule `tools/canonicalize_cinematic_refs.py` states, "Each
branch keeps its own EQU value for the canonical name" — and rewrites the 24
operands. It refuses to run on an already-migrated file and refuses if any raw
operand is left uncovered.

Not a byte change: an EQU resolves to the number the literal was, and
`make test` stays at 29/29 and 29/29. The `raw-video` violation is gone from
gba_usa/LAKE, which goes 99.1% → 99.2% semantic with 3 violations → 1.
