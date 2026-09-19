# A name that says it draws CV 291, and does not

Plenty of names in the tree transcribe the constant they draw:
`GUARDED_DRAW_CV_126`, `DRAW_CIN_254`, `DRAW_CV_113`. That is operand
transcription, evidence grade **E1**, and `naming_census.classify` counts such
a name as unnamed for exactly that reason — it restates the operand instead of
saying what the routine is for.

An E1 name is uninformative. This directory is about the ones that are
**false**, which is worse than `LABEL_<hex>`: a reader who trusts
`DRAW_CV_113` goes looking for `COMMON_VIDEO_113` in a routine that draws
`COMMON_VIDEO_74`.

There is an obvious way for them to drift. Each port assigns `CINEMATIC_NNN`
and `COMMON_VIDEO_NNN` indices in its own encounter order, so the same routine
draws a different index on each port. Copy such a name across ports — **#0107**
— and the index comes along and is now wrong. The byte gate cannot see it; a
label name is not a byte.

## `name_index_vs_body.py`

**Question:** for every label carrying a `CV<n>` / `CIN<n>` in its name, does
the body actually draw that constant?

```bash
cd another-world-source-reconstruction
python3 notes/index-bearing-names/name_index_vs_body.py --all
```

Exit 1 if any name claims an index its routine does not draw. This is a gate,
not a judgement call: a name stating a constant the routine never touches is
wrong on its face.

A body that draws *more* than the name says is fine — a name need not be
exhaustive — so that is not reported.

## Measured 2026-09-19, all four ports, all nine stages

```
1288 bare `_L<n>` fold-local label(s) excluded
1015 routine(s) carry a CV/CIN index in the name
     946 agree -- every claimed index is drawn
      42 claim an index but draw nothing numeric (stale, not false)
      27 claim an index the body DOES NOT draw   <- wrong on its face
```

**The first line is the probe's own bug, fixed.** Asked naively the question
returns **319** hits, and most are an artefact: a `<stem>_L<n>` label is an
emission counter inside a folded routine, not a routine, and its name is the
stem's name plus a suffix. `PRISON_DRAW_CIN_132_TO_133_2F_AT_BB9185F0_L0`
"claims" 132 while its own slice draws 134–136, because 132 belongs to the
whole routine — whose stem label does not even exist in the file. Those are
already forbidden by `docs/NAMING.md` §1 and already counted by the lint, so
reporting them here would be double-counting a known defect under a second
heading. 319 → 27 once they are excluded.

## What the 27 look like

The signature of a cross-port copy is the same name wrong on several ports and
right on one:

| name | claims | actually draws | where |
|---|---|---|---|
| `DRAW_CV_113` | 113 | `COMMON_VIDEO_74` | msdos + snes_eu × PRISON/CAVES/CAPSULE (correct on amiga) |
| `DRAW_CV_298` | 298 | `COMMON_VIDEO_355` | msdos + snes_eu × CAVES/CAPSULE |
| `GUARDED_DRAW_CV_126` | 126 | `COMMON_VIDEO_4` | amiga PRISON + CAVES |
| `GUARDED_HERO_ANIM_CV_291` | 291 | `COMMON_VIDEO_247` | amiga PRISON |
| `BEAST_ANIM_HEAD_CV211` | 211 | `COMMON_VIDEO_164` | msdos CAVES |
| `DRAW_CIN_058_AT_..._IF_...` | 58 | `CINEMATIC_5` | snes_eu PASSCODE ×2 |

`GUARDED_HERO_ANIM_CV_291` is the clearest: its only sibling,
`GUARDED_HERO_ANIM_CV_009`, draws `COMMON_VIDEO_009`, so the family convention
is that the index *is* the constant — and 291 is what the **msdos** copy of
this routine draws.

## Not fixed, and why

Most of the 27 are **cross-stage shared helpers**: `DRAW_CV_113` lives in
`src/levels/_unified/_helpers/DRAW_CV_113.inc` and is included by PRISON,
CAVES and CAPSULE on every port. Renaming one touches three stages and four
branches at once, which is the hazard that has caused real damage in this
project more than once, so it is not folded into an unrelated pass.

The two single-stage ones were proposed and **refused by the applier**:

```
GUARDED_HERO_ANIM_CV_291 -> GUARDED_HERO_ANIM_CV_247:
    still a generated form (operand_mech), not an improvement
BEAST_ANIM_HEAD_CV211 -> BEAST_ANIM_HEAD_CV164:
    still a generated form (operand_mech), not an improvement
```

That guard is right about **class** and blind to **truth**: it exists to stop
churn between equally mechanical names, and it cannot tell that one of the two
is false. Rather than route around it, the case is recorded here. The proper
fix is a semantic name for the family, which means settling whether the
routine draws the hero or the buddy — it calls a HERO-named dispatcher and
draws at `[0x07],[0x08]`, the actor-context slot that
`notes/draw-slot-probes/` shows names nobody (#0138). So these two wait on the
same blocker as the rest of that family.

## Fixed

`IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD` and its `_2` twin on **dos_1992**
and **cartridge_1992** → `SLUG_DISPATCH_PHASE1_F6_DEATH` and
`SLUG_DISPATCH_F4_DELAY`. Not an index error but the same family of mistake,
and found the same day by asking which of the 843 cross-port name conflicts
have the two ports asserting **different characters** for an identical body:
5 instances, 3 distinct pairs, of which these were two. amiga and gba_2004 had
been corrected earlier; dos and cartridge had not, and dos is a priority port.

All four ports now agree.
