# The two trees, and the names they disagree about

## What question this answers

The repository holds the same program twice -- `src/levels/<branch>/<STAGE>.asm`
and `src/levels/_unified/<stage>/` -- and `make test` checks both, 29/29 and
29/29. **Neither gate checks that they use the same names.** An EQU emits
nothing, so a rename applied to one tree and not synced to the other leaves the
same offset under two symbols and both trees still assemble byte-identically.

    python3 notes/tree-name-drift/name_drift.py
    python3 notes/tree-name-drift/name_drift.py --kind moved --stage CAVES --list

Two kinds of row:

- **missing** -- a semantic name in the canonical file that appears nowhere in
  the unified stage directory;
- **moved** -- a name both trees define, and the canonical offset is among none
  of the unified tree's definitions of it.

## Why `moved` is the dangerous one

It is what made `../beam-span-ladder/rung_thresholds.py` report msdos CAVES'
entire beam ladder as misplaced, plus two names as absurdly wrong-sized
constants, when it resolved a **unified** routine against the **canonical**
table. Every symbol resolved. Nothing warned. All of it was false.

> A name means what the tree it was read from says it means.

## The one trap in measuring it

A shared `.inc` may define one name **once per `.if BRANCH` arm**, so a name
legitimately has one value per port. A first version of this probe took the
first definition and called the rest a disagreement: 631 false rows in amiga
LAKE alone, because `pool_underwater_cinematic.inc` defines
`CINEMATIC_CONSOLE_UNDERWATER_EXPLOSION_0` at 0x1D82 on line 11 and 0x3142 on
line 52, and 0x3142 is amiga's.

So a name counts as `moved` only when the canonical offset matches **none** of
the unified tree's definitions. That under-reports -- two ports' values swapped
between arms would pass -- and that is the right direction: every row printed is
real.

## Run of 2026-09-23

```
  452  semantic names missing from the unified tree
  544  names both trees define at different offsets
```

Concentrated in: dos CAVES 282 moved, TANK 330 missing across amiga, msdos and
cartridge, dos CAPSULE 76 moved, cartridge CAVES 61 moved and 20 missing.

**Which tree is right?** The canonical files are what
`../shared-bank-naming/asset_naming_share.py` counts, so the naming record is
the canonical tree and the unified tree is the one that is behind. The drift
therefore costs **no coverage** -- it is a consistency debt, not a naming gap --
and the fix is a sync pass per stage, not renaming.

It also explains an open item `../HANDOFF.md` has carried without a cause: the
`PRISON_CUTSCENE_ZOOM_IN_*` disagreements are this, not a naming dispute.
