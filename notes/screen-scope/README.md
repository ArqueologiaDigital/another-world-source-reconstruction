# Which screen is a routine reachable under?

| file | question it answers | command |
| --- | --- | --- |
| `screen_scope.py` | For every label in a stage, which values of `[SCREEN_NUM]` can it be entered under? | `python3 notes/screen-scope/screen_scope.py --stage CAVES` |
| | Does the derivation agree with the routines a human already named for a screen? | `... --control` |

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
