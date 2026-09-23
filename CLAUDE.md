# CLAUDE.md

Guidance for Claude Code (claude.ai/code) in this repository: **invariants and
entry points only, no numbers.** Every measurement lives in `notes/HANDOFF.md`
beside the script that produced it, because a number in an automatically loaded
file is a number nobody re-runs.

## Read first

- `notes/HANDOFF.md` — where the work stands, and the probes to re-run before
  trusting any figure in it.
- `docs/NAMING.md` — what may be called a name.
- `notes/play-and-describe/README.md` — the annotation queue.

## A human is annotating the running game

`tools/vm-debugger/` runs the game in a browser: a person plays it, clicks a
polygon whose area blinks, and types a sentence about what is happening. Those
sentences land in `tools/vm-debugger/rename_log.jsonl` and are the only channel
through which someone who has played the game reaches the naming effort — every
probe in `notes/` reasons from geometry, control flow or bank layout, and none
of them can say what a scene is *about*.

    make annotations      # python3 notes/play-and-describe/annotation_queue.py

Run it when you pick up naming work, before choosing what to name.

## An annotation is evidence, not an instruction to rename

True of the `kind:"rename"` and `kind:"bulk_rename"` entries too, where a human
typed an actual name: those are names with no stated grounds. A name enters the
tree only through a proposal table and `apply_branch_scoped_names.py`, behind
which sit the family-gap rule, the collision check, `undefined_symbols.py` and
the byte gate. **A sentence is evidence for the subject word of a name and
nothing else**; the index, the family bounds, the `_SCREEN_<NN>_` component and
the port come out of the listing as they always have. Procedure and confidence
rule: `notes/play-and-describe/README.md`.

## Never edit, reorder or delete a line of `rename_log.jsonl`

An annotation's id is the sha1 of its line; rewriting one orphans every proposal
table and verdict that cites it. The file is append-only and it is committed — a
sentence is the one kind of evidence here that re-running something cannot
regenerate.

## Two things the gates cannot do

- **A rename moves no byte**, so `make test` cannot catch a wrong name, only a
  half-applied one. Names read off a picture or off a sentence have no
  independent check, and are grouped in `notes/render-and-name/` and
  `notes/play-and-describe/` so they can be audited, or reverted, as a set.
- **`cartridge_1992` applies must run with `../another-world-archaeology` as
  cwd**, or the applier reverts them while printing "N proposed, 0 rejected".
  Read the output for `applied`.

## Working rules

- **One proposal table per batch.** A rename table is not idempotent;
  `notes/unified-scoping/applied_rows.tsv` records why.
- Run `notes/unified-symbol-check/undefined_symbols.py` before `make test`; it
  catches what the byte gate does not.
- Any number written into a commit message, a note or a README gets its
  producing script committed beside it, in the same session.
