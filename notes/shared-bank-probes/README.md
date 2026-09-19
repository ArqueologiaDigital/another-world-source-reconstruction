# Does T7's premise hold?

Plan item **T7** is the largest single blocker in the routine backlog.
`notes/caller-derived-naming/what_blocks_the_rest.py` weighs it: **900**
reachable unnamed routines draw only shared-bank art, and **247** more do that
*and* hit #0138. `docs/NAMING.md` §2 says why they cannot be named and what
would unblock them:

> **The shared bank (`COMMON_VIDEO_NNN`) has no semantic names at all** … Its
> numbering is worse than arbitrary: it is the order the disassembler happened
> to encounter entries across a whole `all_levels` run … Before these can be
> named, the emitter must key them by offset (plan item T7) and the existing
> names must move to an interim port-invariant `CV_<OFFSET4>` — **the bank is
> byte-identical between Amiga and MS-DOS, so one name per offset is correct.**
> Until that lands, do not hand-name `COMMON_VIDEO_NNN`.

Everything rests on the bold sentence. If it is false, keying by offset gives
one name to different art on different ports — baking in the exact error
#0107 exists to prevent, at the scale of the whole bank and 1,147 routines.

It had not been checked.

## `cv_offset_is_port_invariant.py`

```bash
cd another-world-source-reconstruction
python3 notes/shared-bank-probes/cv_offset_is_port_invariant.py --coverage
```

Exit 1 if any **load-bearing** pair disagrees.

Indices are per-port encounter order, so `COMMON_VIDEO_074` on two ports are
unrelated labels and comparing them proves nothing. Offsets are the claim. So
the probe pairs routines between two ports by **identical body** with every
polygon symbol masked, keeps only bodies unique on each side, resolves each
side's `offset=COMMON_VIDEO_*` operands through its own port's EQU table, and
compares the two offset sequences position by position.

## The qualifier that decides the answer

A two-line body —

```
video type=0, offset=<poly>, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
ret
```

— is the most generic shape in the tree. Two routines sharing it are **not**
thereby the same routine, even when it happens to be unique on each side. So
pairs are split by body length and only those of **three lines or more** count
as evidence.

That distinction is the whole result. Without it the probe reports a
disagreement and the natural headline is "T7's premise is false" — which would
have been wrong, and would have stalled the project's largest unblocking task
on a bad measurement.

## Result, 2026-09-19

| | pairs drawing shared-bank art | agree (3+ line body) | disagree (3+ line body) | coverage |
|---|---:|---:|---:|---:|
| amiga vs msdos | 73 | **71** | **0** | 24.1% |
| amiga vs snes_eu | 62 | **61** | **0** | 15.9% |
| amiga vs gba_usa | 1 | 1 | 0 | — |

**T7's premise survives.** No routine paired on a body of three lines or more
draws the shared bank at a different offset on two ports, across 132
independent strong agreements.

The single disagreement in the whole tree is the two-line pair amiga
`DRAW_HERO_POSE_0_0` (offset 0x1C78) against `DRAW_CV_298` (0x3FB8) in
CAPSULE, and it appears identically against **both** msdos and snes_eu — those
two agree with each other, which is what a genuinely different routine on
amiga looks like, not a bank difference.

## What this does not establish

**Coverage is 24.1%.** The agreeing pairs touch 85 distinct offsets of the 352
amiga defines; the other three quarters of the bank are untested, not proven
equal. This is a failure to refute over the part of the bank the game's shared
routines actually use — good enough to proceed with T7, not a proof that the
banks are byte-identical. Anyone doing the `CV_<OFFSET4>` migration should
compare the ROM bytes directly, which this probe does not do: it reads only
the assembly.
