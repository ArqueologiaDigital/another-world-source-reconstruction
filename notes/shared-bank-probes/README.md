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
independent strong agreements. For amiga and msdos it is now more than
survival — see the byte-level check below, which settles it.

The single disagreement in the whole tree is the two-line pair amiga
`DRAW_HERO_POSE_0_0` (offset 0x1C78) against `DRAW_CV_298` (0x3FB8) in
CAPSULE, and it appears identically against **both** msdos and snes_eu — those
two agree with each other, which is what a genuinely different routine on
amiga looks like, not a bank difference.

## What the assembly test does not establish — and the one that does

**Coverage is 24.1%.** The agreeing pairs touch 85 distinct offsets of the 352
amiga defines; the other three quarters are untested, not proven equal. That
is a failure to refute, not a proof, and it is why the second probe exists.

## `shared_bank_bytes_identical.py` — the same question, answered exactly

`docs/NAMING.md` §5 already identifies the bank as a single file:

> Also: resource `0x11`, typed "UNKNOWN", is the shared video2 bank … the
> highest `COMMON_VIDEO` EQU value (`0x61B0` = 25,008) fits inside its 25,108
> bytes with 100 to spare, which no other resource does.

So the premise is a statement about one file per port, and is answerable
exactly.

```bash
python3 notes/shared-bank-probes/shared_bank_bytes_identical.py
```

```
  amiga        25108 bytes  ee98e9d5cca18a4fd0c3d0dac884e38a...  matches baseline
  msdos        25108 bytes  ee98e9d5cca18a4fd0c3d0dac884e38a...  matches baseline
  gba_usa                    (no resource-0x11.bin; not covered)
```

Baseline, recorded so a fresh extraction can be checked against it:

```
25108 bytes
sha256 ee98e9d5cca18a4fd0c3d0dac884e38a11533cd8fd88825cd503eeb0658494b0
```

**T7's premise is proven for the two priority ports at 100% coverage**, not
merely unrefuted over a quarter of the bank. The 25,108 also matches the size
NAMING.md §5 arrived at independently.

The resource dumps live under `another-world-archaeology/tmp/output/<port>/`,
which is volatile and not in git, so the hash is committed here and the recipe
to regenerate the input is `python3 tools/aw_unpacker.py` from the archaeology
repo. The probe exits 2 rather than 0 when fewer than two ports have the
resource, because with nothing to compare, reporting success would be a lie.

**Still not covered:** snes_eu and gba_usa have no extracted resource 0x11 —
and the GBA release packages its art differently, shipping a `cinematic.rom`
the others do not. For snes_eu the only evidence remains the 61 assembly-level
agreements above.
