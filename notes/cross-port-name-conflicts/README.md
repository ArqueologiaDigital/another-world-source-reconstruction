# When two ports name the same routine differently

`another-world-archaeology/tools/align_branch_names.py` pairs routines between
branches by instruction stream and sorts each pair into agree / gain /
backport / **conflict**. A conflict is both sides carrying a semantic name and
the names differing, and the tool deliberately refuses to arbitrate — **#0120**:
a tool must not pick a winner between two names a person wrote.

That refusal is correct and it means conflicts accumulate unread. This
directory measures the pile and makes one pair at a time readable.

## `conflict_dossier.py`

**Question:** two ports name one routine differently — are the bodies even the
same, and is the disagreement about wording or about shape?

```bash
cd another-world-source-reconstruction
python3 notes/cross-port-name-conflicts/conflict_dossier.py --stage LAKE
python3 notes/cross-port-name-conflicts/conflict_dossier.py \
    --target snes_eu --stage CAVES --bodies
```

It pairs on **identical body**, not on stream position: bodies are normalised
by masking `CINEMATIC_*` and `COMMON_VIDEO_*` symbols, which legitimately
differ per port because each branch keys a polygon name to its own offset. A
pair is only formed when the normalised body occurs exactly once on each side;
anything ambiguous is counted and skipped rather than guessed.

That is stricter than the aligner. On amiga vs gba_usa LAKE the aligner
reported 26 conflicts; pairing on body gives 407 agreements and **6** genuine
same-code-two-names cases, because the other 20 pairs did not have matching
bodies at all.

## The surface, measured 2026-09-19

| vs amiga | same name | different name | of those, structural |
|---|---:|---:|---:|
| msdos | 2,246 | 395 | 29 |
| snes_eu | 1,811 | 444 | 25 |
| gba_usa | 598 | 4 | 1 |
| **total** | **4,655** | **843** | **55** |

**84.7%** of body-identical pairs already agree. The remaining 843 are a real
backlog nobody had counted: each is one routine wearing two names, and at most
one of them can be the better name.

## `STRUCTURAL` — the flag that exists because of a mistake

An identical body does **not** mean an identical role. That cost a wrong
rename here on 2026-09-19, applied and reverted within the hour.

amiga's `HERO_AI_DISPATCH` has byte-for-byte the body cartridge, dos and gba
call `HERO_AI_DISPATCH_AIRBORNE`. It looks like amiga is using a name that is
too general, and three ports against one is a tempting argument. It is wrong.
`src/levels/_unified/lake/hero_ai_dispatch_airborne.inc` puts
`HERO_AI_DISPATCH:` **before** a `.if BRANCH in ("cartridge_1992",
"dos_1992", "gba_2004")` block that ends with the label
`HERO_AI_DISPATCH_AIRBORNE:`. amiga skips the block, so its single label falls
straight through to the airborne body. The other three have two labels because
they have an extra ground-dispatch arm — not because amiga's label is wrong.
All four ports do `setup channel=0x16, address=<the AI entry>`, and on amiga
that entry is this code. **On amiga the routine is the dispatcher**, and
`_AIRBORNE` would assert it is one arm of something amiga does not have.

So a pair is now flagged `STRUCTURAL` when the other side **also defines the
name in question**. That means the ports disagree about which routine wears
the name, or one port has a routine the other lacks, and the shared body alone
cannot settle it. It is a warning to go read the other definition — the step
that was skipped.

55 of the 843 are structural.

## Applied on 2026-09-19

Five of LAKE's six amiga/gba_usa conflicts, in
`another-world-archaeology/docs/content/research/2026-09-19-lake-crossport-name-conflicts/`.
Four of the five removed a gba name that asserted something its body does not
do:

| gba name, before | body | after |
|---|---|---|
| `FIRST_SCREEN_R_BEAST_TRIGGER` | `copyVideoPage src=0x00, dst=0x03` + cache screen num | `CYCLE_VIDEO_PAGES_2WAY` |
| `FIRST_SCR_R_YIELD_RESTART` | sets `HERO_Y` from a `HERO_X` range test, arm 0 of a ladder | `HERO_Y_FROM_X_RANGE_0` |
| `IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD` | `je [0x07],0x01, SLUG_R_PHASE1_F6_THEN_DEATH` | `SLUG_DISPATCH_PHASE1_F6_DEATH` |
| `IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD_2` | `je [0x07],0x01, SLUG_R_F4_RAND_DELAY_INIT` | `SLUG_DISPATCH_F4_DELAY` |

The two `IF_BEAST_NEAR_…` names also differed only by a bare `_2`, which
`conventions/feedback_no_index_suffixes.md` bars; the adopted names
distinguish the twins by their jump targets instead.

The fifth was a swap the aligner could not perform and reported as
`LABEL_1AA3 -> FIRST_SCREEN_R_BEAST_TRIGGER (already taken in target)`: the
name was on the two-line page copy above, while the routine that actually ends
in `setup channel=0x07, address=THE_BEAST_WANDERS_ON_THE_FIRST_SCREEN_TO_THE_RIGHT`
was still `LABEL_1AA3`. Freeing the name in pass 1 let pass 2 place it.

The sixth is the `HERO_AI_DISPATCH` pair, left alone, and now the probe's
worked example of why.

Result on LAKE: amiga vs gba_usa goes from 6 conflicts to 1, that one flagged
`STRUCTURAL`, and gba_usa/LAKE from 4 placeholder routines to 3.
