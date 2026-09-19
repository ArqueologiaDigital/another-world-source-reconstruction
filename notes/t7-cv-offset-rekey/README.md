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

And it **re-specifies T7**. Keying by offset makes the name port-specific for
346 of 353 entries, while the unified tree makes **3,205** references to these
names from code outside any `.if`. A straight rename leaves every one of those
resolving to a name only one branch defines — and, as this project has learned
the hard way, *an undefined symbol assembles silently*; only the byte gate
would catch it, after the fact.

So T7's interim step cannot be a rename. Either

* the shared chunks gain branch arms around every CV reference — de-unifying
  exactly what the unified tree exists to unify, 3,205 times; or
* the **emitter** change comes first and the tree is regenerated around offset
  keys, which is what §2's "the emitter must key them by offset" always said
  and which this makes non-optional.

## `rekey_common_video_by_offset.py` — written, deliberately not run

The rename itself, per-file and byte-neutral, refusing up front if any file
defines one offset under two names or if a target `CV_<OFFSET4>` is taken. On
LAKE it plans 489 definitions and 1,072 tokens across 5 files with no
problems.

It is **not applied**, and the reason is the finding above: it handles the
per-branch `.asm` files correctly and has nothing to say about the 3,205
shared references. Applying half would leave the canonical tree and the
unified tree disagreeing about 979 names — worse than leaving both alone.

Kept because the per-file offset resolution is the part that is easy to get
catastrophically wrong: the same index is a different offset in different
files, so a global search-and-replace would corrupt the tree while looking
entirely reasonable.

## What would unblock the 1,147 routines

Not this rename. The bank is one file, so the art can be identified **once**
per offset. What is missing is a key that survives both ports, and the honest
route is the emitter half of T7 — after which a single identification names
the art everywhere, which `COMMON_VIDEO_NNN` makes impossible by construction.
