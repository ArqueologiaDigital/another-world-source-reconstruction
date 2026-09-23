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
