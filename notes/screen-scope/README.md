# Which screen is a routine reachable under?

| file | question it answers | command |
| --- | --- | --- |
| `screen_scope.py` | For every label in a stage, which values of `[SCREEN_NUM]` can it be entered under? | `python3 notes/screen-scope/screen_scope.py --stage CAVES` |
| | Does the derivation agree with every routine whose name states a screen? | `... --control` |
| | Which routines state a screen the dataflow contradicts? | `... --proposals` |
| `screen_entry.py` | Which routines are a stage's per-screen entry points, and which chain dispatches them? | `python3 notes/screen-scope/screen_entry.py` |
| `backdrop_phase.py` | Which pictures does a screen paint before anything starts animating, and in what order? | `python3 notes/screen-scope/backdrop_phase.py` |

## Why

`../remaining-art/` found 42 backdrop composites — `fill`, then N pictures at
one anchor, then `ret` — and showed that naming their layers needs the one
fact none of them carries: **which screen**. Three readings were tried and all
failed: the label's hex token is not the screen (0 of 54 match a `SCREEN_NUM`
guard), the draw count matches 42 of 74, and the call site carries no guard.

The screen is not a lookup. It is a reachability property: a routine belongs
to screen NN when *every* path that reaches it has already tested
`[SCREEN_NUM]` and found NN. So it is a forward dataflow.

## The lattice, and why `None` is top

Each point carries a frozenset of possible screens, or `None` for
**unconstrained**. Merging is conservative:

```
None | anything  ->  None
{a}  | {b}       ->  {a, b}
```

One path that arrives without the screen pinned poisons the label. That is the
point: "this is screen NN's backdrop" has to be true of every way in, not of
one convenient way. Only the two guard forms that give a *positive* fact are
used —

```
je  [SCREEN_NUM], 0xNN, T   ->  at T, the screen IS NN
jne [SCREEN_NUM], 0xNN, T   ->  on the FALLTHROUGH, the screen IS NN
```

— because the other arm of each says `!= NN`, which over 52 possible values is
worth almost nothing. A label with no incoming edge, and any label installed
by a `setup`, starts at `None`: a thread the scheduler may start at any time
really is reachable under any screen.

## The bug that made the first run useless

The first version pinned none of the backdrops. Every one came back
unconstrained, and the reason was three characters of assembly:

```
LABEL_A627:
        db 0x11
```

`tools/redisasm_db.py:784` has `TERMINATING_OPCODES = {0x05, 0x07, 0x11}` —
`ret`, `jmp`, `killChannel`. A lone `db 0x11` between two routines **is** a
`killChannel`, written as data. Treating it as an ordinary byte and falling
through chained unrelated routines end to end, so a context from one screen's
setup flowed into the next one's and every merge went to top.

Handling it took the control from **12 agreeing** to **29**.

## The control

CAVES already contains 32 routines whose names carry a screen, written by a
person from other evidence — `CAVES_SCREEN_92_BACKDROP_DRAW`,
`CAVES_SCREEN_AD_RIGHT_PASSAGE_CLAMP_HERO_X_UPTO_C8` and so on. The module is
not told about them. It derives 29 of the 32 independently and identically.

```
python3 notes/screen-scope/screen_scope.py --control
```

That is what makes it usable as a naming instrument rather than a guess, and
it is why `../remaining-art/by_anchor.py --proposals` consults it.

## The three it did not reproduce, and what each turned out to be

The first clean run left three disagreements. None of them was a limit of the
method; two were bugs in it and one was a defect in the tree.

**An unreferenced label is not an entry point.** The pass that seeds unreached
labels as top was seeding *every* one, including data. amiga's
`CAVES_SCREEN_92_BACKDROP_DRAW` is preceded by

```
LABEL_D3B8:
        db 0x78, 0x7A, 0x94, 0x4C, 0x7B, 0x11
```

which nothing references and which nothing falls into either — the routine
before it ends in `ret`. Seeding it top sent top straight through the blob
into the backdrop, so amiga came back unconstrained while msdos, whose
equivalent gap is real code ending in `killChannel`, came back `0x92`. Seeding
only labels something mentions fixed it.

Multi-byte blobs are deliberately **not** treated as terminating. Of 1,396 of
them only 191 even end in a terminating byte, so "it ends in killChannel" is
not a rule — and assuming termination would make labels look *more* pinned
than they are, which is the unsafe direction for naming.

**A scheduler thread has no single screen, but its install site does.** A
routine installed only by `setup` keeps running across screen changes, so top
is the right answer for the routine. The claim its *name* makes is about where
it was installed, so `--control` now compares those against the `setup` site
instead. That resolved amiga's `CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME`,
installed on the fallthrough of `jne [SCREEN_NUM], 0xED`.

**One was a real wrong name.** The same routine in msdos and cartridge is
installed on the fallthrough of `jne [SCREEN_NUM], 0x**EE**`, not 0xED. The
screen sets corroborate it: of CAVES' screen values all 54 of amiga's are
shared with msdos, and msdos carries three more — `0x03`, `0x04` and `0xEE`.
So msdos has a screen amiga does not, the event lives on it, and the shared
label was true only of amiga. Corrected branch-scoped to
`CAVES_SCREEN_EE_EVENT_PALETTE_FLASH_FRAME` in both branches.

`--proposals` emits exactly this kind of correction: every routine whose name
states a screen the dataflow contradicts.

## Where the control stands

```
python3 notes/screen-scope/screen_scope.py --control
  48 agree, 0 do not (3 compared against their setup site)
```

across all four branches, and it exits 0. That is 48 screen assignments a
person made from other evidence, re-derived from the guards alone.

## Using it: the per-screen entry routines

Pinning a label to a screen says *which screen*, not *what it is*. For one
shape it says both.

Each big stage has a chain of `je [SCREEN_NUM], 0xNN, T` lines whose targets
all do the same four things: write the camera bounds `[0x40]..[0x47]`, tear
down the previous screen's channels, `setPalette`, and install the new
screen's threads before drawing its backdrop. That is a screen transition,
and each target is one screen's entry.

The classification is measured. Across every chain of four or more
consecutive `je [SCREEN_NUM]` lines in the tree, the fraction of targets
writing a bounds variable is either **all of them or essentially none** —
nine chains at 11/11, 50/50, 7/7, 11/11, 51/51, 41/41, 11/11, 51/51, 41/41,
and the rest at 1/33, 0/11, 0/8, 0/6. There is no middle, so the 90% threshold
this module uses is the same as any other. Teardown and palette corroborate
without being required: on the nine, 274 of 274 targets write bounds, 271 tear
down channels, 265 set a palette.

Reassuringly, the two chains that already had human names —
`CAVES_GROUND_MAP_DISPATCH` and `CAPSULE_FLOOR_LEVEL_SELECT_BY_HEIGHT` — fall
on the negative side. They dispatch on the screen for other reasons and are
not screen entries, exactly as their names say.

```
<STAGE>_SCREEN_<NN>_ENTRY          each target, NN from its own `je`
<STAGE>_SCREEN_ENTRY_DISPATCH      the chain's owning label
```

`NN` is the machine's screen number, read from the comparison that selects the
routine. A target is proposed only when `screen_scope.py` *independently*
pins it to that one screen, so the `je` and the whole-graph reachability have
to agree — 17 of the 274 failed that and were held back.

**264 applied** on 2026-09-23. Afterwards `screen_entry.py` reports 257 of 274
already named and nothing nameable, and `--control` rises from 48 to **303
agree, 0 do not**, because every new name carries a screen the dataflow can
check.

## Using it again: the backdrop phase

Every `<STAGE>_SCREEN_<NN>_ENTRY` has the same shape — bounds, teardown,
`setPalette`, **paint**, then `setup` the threads that animate the screen. The
first `setup` is the line between static and moving: nothing drawn before it
is animated by anything, because nothing is running yet. So the pictures an
entry draws before that line, directly or through routines it calls, are the
screen's painted background, in the order they go down.

```
CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>
```

`i` is the position in that sequence — the machine's order, not one a namer
chose. The sequence ends at the first `setup` **or the first conditional
jump**: a draw a branch can skip is not part of the backdrop. **226 applied**
on 2026-09-23, taking priority-port assets from 59.6% to **60.8%**.

### The conditional guard, added after five wrong names

The first version truncated only at `setup`, and it named five state overlays
as backdrop layers across three branches:

```
CAVES_SCREEN_68_ENTRY:
        ...
        je [0xF8], 0x00, LABEL_A1C3        <- [0xF8] = [0xB1] & 0x0010
        video offset=..., x=160, y=100        a progress flag

CAPSULE_SCREEN_8D_ENTRY:
        ...
        jl [HERO_X], 0x00, LABEL_A8CA      <- which side the hero entered from
        video offset=..., x=160, y=100
```

Both are painted in the backdrop phase and both are skippable, so neither is a
layer of the backdrop. They were demoted back to their indices and the phase
now ends at the first conditional. That costs only those five — 286 of the 291
had no conditional before them — and it cannot overclaim.

This was found by rendering a screen to look at it, which is worth recording:
`PRISON_SCREEN_04_ENTRY` turned out to draw `CINEMATIC_BUDDY_HACKING_SECURITY_
DOOR` behind two guards, and that named constant sitting in the middle of what
the probe called a backdrop is what gave the rule away.

### Why this index, and not the composite's

`../remaining-art/by_anchor.py` had already named 73 layers by their position
inside a `fill`-led composite. The two orders come from different places — one
counts draws inside a single routine, the other the whole phase across several
— and they agree in **57 of 60** cases where both exist. That is an
independent check on both.

The 3 that disagree are screens where the entry paints something outside the
composite, so the composite's internal index is not the phase position:
`CAPSULE_SCREEN_4B` (composite 2, phase 3) and `CAPSULE_SCREEN_6D` (0 and 1,
phases 7 and 8). Phase position is defined for every painted picture and the
composite index only for those inside a composite, so those three were
renumbered and the whole tree is on one scheme.

### What it refuses, and why that is right

```
590  painted twice in the same phase
296  in several screens' backdrop phase
291  already correct
107  still numbered, nameable but blocked
 50  named something else, left alone
```

**Painted twice** is the largest class and it is a refusal, not a gap in the
method: CAPSULE screen 0x92 paints `CINEMATIC_557` at positions 1 *and* 6, so
it has no single position and cannot take a position-indexed name. Same shape
as a limb piece shared between frames in `../actor-sprite-sheet/` — what is
shared has no index. This was caught by the applier seeing fewer rows than the
proposal files contained, not by the probe.

**In several screens' phase** is the same argument across screens, and the
same one that kept screens 0x92 and 0x93 from claiming their shared base.

The remaining **107** are blocked permanently by the family-gap guard, and a
second pass confirms it yields nothing more. PRISON screen 0x04 proposes
positions 8, 9, 10, 12, 13, 14, 15, 17 — the holes at 11 and 16 are where a
twice-painted or shared layer sits, and they can never be filled. The guard is
right to refuse and the holes are meaningful, exactly as in
`../draw-label-follows-constant/footstep_frames.py`.

### The tile hypothesis, tested and refuted

The largest refused class is "painted twice in the same phase", and the
obvious reading is that those are **tiles** — one picture stamped repeatedly
to build a wall or a floor. This project has measured tiling before (a tile
steps exactly one pixel less than its own routine's step: 15/16, 47/48,
111/112), so a tile run would be nameable as such.

It is not that. Over every picture painted more than once at a literal anchor
in one screen's backdrop phase:

```
 232  painted once (not in this class)
  82  painted exactly twice
  33  painted three or more times, irregular spacing
   0  painted three or more times with a constant step
```

Two points always have a "constant step", so the test is vacuous below three
copies — and above three, **nothing** is regular. The twice-painted ones are
pairs at offsets like (165, 0) and (-160, 0), which is a mirrored or repeated
prop, not a run. There is no tiling structure in the backdrop phase to
exploit, and a twice-painted picture still has no single position.
