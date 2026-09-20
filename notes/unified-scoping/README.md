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
