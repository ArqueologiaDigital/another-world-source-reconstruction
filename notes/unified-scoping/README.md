# Keeping the unified tree building after a per-port rename

One script, `scope_fix.py`. It is here because it **mutated the committed
tree** during the naming passes and existed only in a session scratchpad,
which is the one place work does not count.

## What it is for

A naming pass renames `CINEMATIC_NNN` in one branch's canonical `.asm`. The
unified tree shares chunks, and those chunks define the constant
unconditionally, so after the rename the branches that did *not* get the new
name read a definition that no longer matches their references. `make test`
then shows the signature split: **verify-stages stays at 29/29 and
verify-unified drops**, because the canonical files are self-consistent and
only the shared tree is not.

`scope_fix.py` wraps the affected definitions in a `.if BRANCH` guard naming
the branches that still use the old spelling.

## The bug worth remembering

The first version scoped every row of the proposal table. The validator
rejects some rows, so in CAPSULE it scoped all 14 when only 8 had landed, and
the six the other branch still legitimately used under their old names
disappeared.

**A proposal is not an application.** It now re-reads the target `.asm`, scopes
only names actually defined there, and prints both numbers so a mismatch is
visible rather than silent:

    8 of 14 name(s) actually applied

It also rewrites only definitions that are currently unconditional, so a
definition already inside an `.if` is left alone instead of nested.

## Running it

    python3 notes/unified-scoping/scope_fix.py <table.md> <STAGE> <port> <branch>

`<port>` is the branch that received the new names; the guard emitted is the
complement. Afterwards, in this order, every time:

    python3 notes/unified-symbol-check/undefined_symbols.py
    make test

`undefined_symbols.py` names the symbols, which is what makes a failure
fixable; `make test` is the only thing that proves no byte moved. Note the
limit that cost a 27/29 elsewhere this week: `undefined_symbols.py` checks the
**unified** tree only, so a breakage confined to the canonical `.asm` files
passes it and is caught by the byte gate alone.

## `sync_equ_rename.py` rewrote in sequence -- fixed 2026-09-23

`apply_branch_scoped_names.py` renames the canonical `.asm` **simultaneously**,
which is what lets a permutation work: its docstring records the case of
`CINEMATIC_795` taking `_0` while the old `_0` becomes `_2`, ending with every
name used once.

`sync_equ_rename.py` does not. It rewrites tokens in the unified chunks one
rule at a time, so a permutation can catch a name the sync itself just
created. Renumbering the PRISON zoom family did exactly that:

```
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4 defined 2 times, 2 DIFFERENT values
    amiga__entry.inc:1486   EQU 0xCA7C     <- old LEFT_0, correctly shifted
    amiga__entry.inc:1495   EQU 0xCA04     <- new LEFT_0, then shifted AGAIN
```

The canonical file was right and the unified tree was wrong, so `make test`
caught it as 28/29 on the unified half only.

The rule that followed from this was **put the shift rows first and in
descending index order, and the rows introducing new names last** -- then no
rule ever sees a name a previous rule produced.

### That rule is withdrawn; the tool was fixed instead

A proposal table's row order is documentation. Encoding a tool's defect in it
means every future table has to be written defensively by someone who
remembers this page, and the failure when they don't is silent in the
canonical half.

`sync_equ_rename.py` now does one pass with a single alternation over all the
old names (`rename_simultaneously`), so every row lands on its own name in
whatever order the table lists them. Alternatives are tried longest-first so
a name that is another's prefix cannot shadow it.

The control is in the file and reproduces the failure:

```
python3 notes/unified-scoping/sync_equ_rename.py --self-test
```

It feeds in the PRISON pupil renumber -- `CINEMATIC_682` claiming `PUPIL_0`
in the same table where `PUPIL_0` becomes `PUPIL_1` and `PUPIL_1` becomes
`PUPIL_5` -- and prints both what the tool produces and what row-by-row would
have produced. Row-by-row collapses three constants onto `PUPIL_5`. PASS is:
four source spellings, four distinct destination spellings, four
substitutions.

Tables in `../render-and-name/` no longer need the ordering caveat. The
PRISON eye batch of 2026-09-23 is the first renumber written in plain reading
order and synced without one.

## The sync also carries routine labels now (2026-09-23)

`sync_equ_rename.py` began as a constants tool: it filed a rename as live only
when the canonical `.asm` defined the new name as `NAME  EQU 0x....`. Handed a
routine table from `apply_routine_renames.py` it parsed **zero rows** and said
`no rows`, which reads like a format error rather than what it was -- a filter
that could not see a label.

Adoption is now `NAME  EQU` **or** `NAME:`. The rule behind it is unchanged
and is the point of the filter: a proposal the validator rejected must not
reach the unified tree through the sync, so only a name the canonical file has
actually taken is rewritten.

### `--shared`, and the one thing it will not touch

Branch-prefixed chunks (`amiga__*.inc`) are safe to rewrite from one branch's
table, because the branch is known. Shared chunks are not, and until now the
sync simply left them, so a routine renamed in all four canonical files kept
its old spelling in `prison_pagefill_inits.inc`.

`--shared` handles them under one rule: rewrite a pair only when **no**
branch's canonical `.asm` still defines the old name. While any branch still
calls the routine by its old spelling, the shared chunk keeps it and the pair
is reported as held.

One class is refused outright, whatever that rule says: a bare
`LABEL_<hex>` address placeholder. Those are per-branch by construction --
amiga's `LABEL_4E09` is the eyelid rung at `[0x15] <= 0x12` and dos's
`LABEL_4E09` is the pupil rung at `[0x16] <= 0x04`, in the same scene -- so
one branch's table cannot say what the token means to the other readers of a
shared chunk. The prefixed pass renames them, where the branch is known.

On the PRISON wake closeup this was 22 address labels refused and 2 eligible,
both content-derived names (`DRAW_CIN_683_TO_685_3F_AT_1EB7324B`,
`INLINE_DRAW_CIN_659_AT_160_100`) -- which is exactly why those two were in a
shared chunk in the first place.

## Chunk FILENAMES go stale and nothing fixes them

`stale_chunk_names.py` measures it. A chunk is filed as
`<prefix>__post_<LABEL>.inc` after the label it follows, and no rename touches
the filename:

```
  prison           257      89     34.6%
  tank              52      41     78.8%
  passcode           8       8    100.0%
  237 of 889 chunk file(s) name a label that is defined nowhere  (27%)
```

This is invisible to `make test` -- `.include` resolves by filename -- so it
has accumulated silently across every routine rename the project has applied.
It is not the residue of any one batch. **Open work**: a pass that renames the
file and its `.include` line together, and a check that keeps it from
recurring.

## The journal: a rename table is not idempotent, and cannot be made so

Making the sync simultaneous (above) removed the ordering trap for a *fresh*
table. It introduced a worse one for a table run twice.

Once `CINEMATIC_682 -> ..._PUPIL_0` and `..._PUPIL_0 -> ..._PUPIL_1` have
been applied, the tree looks exactly as it would have before a second run of
the same rows: `_PUPIL_0` is defined, `_PUPIL_1` is defined. **No test on the
end state can tell "fresh" from "already done"** -- the end states are
identical and only the history differs. Every local guard tried here fails one
case or the other.

It happened the same afternoon. The proposals file had grown a new section, so
re-running it was the ordinary thing to do, and the renumber rows in its old
section fired again. PRISON's amiga pupil ladder came out

```
  _1, _5, _6, _3, _4, _5
```

against the dos arm's correct `_0, _1, _2, _3, _4, _5`. Both backstops worked:
`undefined_symbols.py` reported two symbols defined twice with different
values, and `make test` went to **28/29 on the unified half with the canonical
half still at 29/29** -- the exact signature described further up this page.
`git checkout -- src/levels/_unified/prison/` undid it.

So the history is recorded. `applied_rows.tsv` beside this file holds one line
per `(branch, stage, old, new)` the tool has written; a row already there is
skipped, and reported. `--again` forces it, for repairing a tree and nothing
else. `--record-only` adopts a table applied before the journal existed,
without touching a file.

**And write one table file per batch.** The journal makes a re-run inert
rather than destructive, but a file that accumulates sections is a file whose
old sections keep being offered to every tool that reads it. The PRISON eye
batch and the PRISON figure batch are in separate files for that reason.
