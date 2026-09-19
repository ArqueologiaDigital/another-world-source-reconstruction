# T7: what re-keying the shared bank actually requires

Plan item **T7** is the largest blocker in the routine backlog — 900 unnamed
routines draw only shared-bank art and 247 more do that *and* hit #0138.
`docs/NAMING.md` §2 states the remedy in one sentence: key the bank by offset
and move the names to an interim port-invariant `CV_<OFFSET4>`, because "the
bank is byte-identical between Amiga and MS-DOS, so one name per offset is
correct."

The premise is true — `notes/shared-bank-probes/` proves resource 0x11 is one
file, 25,108 bytes, same sha256 on both ports. This directory is about what
follows from it, and what does not.

## `cv_name_denotes_different_art.py` — the finding

**Question:** does one `COMMON_VIDEO_NNN` name mean one picture?

```bash
python3 notes/t7-cv-offset-rekey/cv_name_denotes_different_art.py --list 4
```

`COMMON_VIDEO_099` is referenced from `_unified/_helpers/DRAW_CV_099.inc`, a
chunk every branch includes, outside any `.if`. The EQU that gives it a value
lives in a **branch-specific** chunk:

```
amiga  COMMON_VIDEO_099 EQU 0x037C
msdos  COMMON_VIDEO_099 EQU 0x3674
```

The bank is one file, so two offsets are two places in it. Reading the bytes:

```
353 distinct (name, amiga offset, msdos offset) triple(s)
    7 offsets equal -- one place, one picture
    0 offsets differ but the first 32 bank bytes match
  346 offsets differ AND the bank bytes differ   <- two pictures, one name
```

> **346 of 353 canonical `COMMON_VIDEO` names denote different art on the two
> ports.** Not one picture under two indices — two pictures under one label.

## Why this is the important half

It **strengthens** NAMING.md's ban on hand-naming these. The stated reason is
that the numbering is arbitrary encounter order. The real reason is worse: any
semantic name earned by rendering one port's art is wrong for the other
port — #0107, built structurally into the shared tree rather than introduced
by a careless rename.

### Correction, same day: the rename *is* safe, and has been applied

This README first concluded that T7's rename was impossible without an emitter
change, because "the unified tree makes **3,205** references to these names
from code outside any `.if`". **That measurement was wrong**, and
`cv_refs_by_reaching_branch.py` is the correction.

"Outside a `.if`" is not "shared between branches". A reference can sit at the
top level of a file that is itself branch-specific.
`_unified/_helpers/DRAW_CV_099.inc` looks maximally shared — it is in
`_helpers/` and three stages include it — and all three includers are
`amiga__*` files. It is a **cross-stage** helper inside one branch.

Walking the include graph once per branch, honouring `.if BRANCH`:

```
3693 COMMON_VIDEO reference(s) reachable in the unified tree
  3230  single-branch
   463  multi-branch, agreeing
     0  multi-branch, DIFFERING
```

and globally, over every (chunk, token) pair and every reaching
(branch, stage), the offset is unique in **2,963 of 2,963** cases. No
(branch, stage) unit has two names sharing one offset either, in either tree.
So the rename is unambiguous everywhere, and it **unifies** the 463
multi-branch references rather than splitting them.

Applied 2026-09-19: 225 files, 3,581 definitions, 14,891 tokens.
`make test` stays at 29/29 and 29/29 — it is byte-neutral by construction.

## `rekey_common_video_by_offset.py` — applied

Per-file and byte-neutral, refusing up front if any file defines one offset
under two names or if a target `CV_<OFFSET4>` is taken. Per-branch `.asm`
files are rewritten against their own EQU table; unified chunks against the
reachability map above. It must be run for **all stages at once**: `_helpers/`
chunks are cross-stage, so re-keying one stage would leave the others
referencing a renamed chunk with symbols they no longer define — and an
undefined symbol assembles silently (#0073).

The per-file resolution is the part that is easy to get catastrophically
wrong: the same index is a different offset in different files, so a global
search-and-replace would corrupt the tree while looking entirely reasonable.

**358 `CV_<OFFSET4>` keys now exist** where 3,581 `COMMON_VIDEO_NNN`
definitions were.

## What this does and does not buy

It does **not** name anything. `CV_037C` is a key, not a name: it says where
the art is, not what it is, and `naming_census.classify` correctly calls it
`addr_suffixed` — still unnamed. The semantic share of the big three is
unchanged at 32.0 / 26.3 / 25.9 %, as it should be.

What it buys is that **the key is now port-invariant**. Before, identifying a
picture told you about `COMMON_VIDEO_099` on amiga and nothing about msdos,
because that same label is a different picture there. Now the art at bank
offset 0x037C is `CV_037C` in every file and on every port, so one act of
identification can name it everywhere — which is exactly what
`COMMON_VIDEO_NNN` made impossible by construction, and what the 900 + 247
blocked routines were waiting for.

The lint was taught the new form in the same change. Without that, every stage
lost one violation and appeared to improve without a single polygon having
been identified.

The **emitter** half of T7 is still open: until the disassembler keys the bank
by offset itself, a regeneration would reintroduce `COMMON_VIDEO_NNN`. The
source tree is the artefact of record and is hand-maintained, so the re-key
stands on its own.
