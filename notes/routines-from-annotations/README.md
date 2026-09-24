# Routine names the annotations made possible

**These names rest on art names, which rest on a person's sentences.** When the
constants a routine draws all got names in one batch, the routine's own name
follows from its draw list with nothing left to guess -- but the chain back to
the evidence runs through `../play-and-describe/`, so they are grouped here to
be audited, or reverted, as a set.

Why not in `../play-and-describe/` with the art: a table there may rename
`CINEMATIC_*` and nothing else. `apply_branch_scoped_names.py` admits only that
shape in column one, so a routine row in such a table is neither applied nor
rejected nor mentioned -- `annotation_queue.py --check` refuses those rows for
exactly that reason. Routine labels go through
`apply_routine_renames.py` and its own gates, in their own table, here.

| file | what it is |
| --- | --- |
| `proposals_<branch>__<STAGE>.md` | routine names derived from a now-named draw list |

## The rule used here

A routine is renamed only when **every constant it draws is already named** and
the name is a plain description of that draw list. Nothing in these rows is read
off a picture, and none of them quotes an annotation directly: the sentence
reached the constant, the constant reached the routine. A routine still drawing
a numbered constant keeps its placeholder, because a name would be describing
something the tree cannot yet say.

The `HANG_` prefix is kept where the disassembler put it. It is not noise: it
marks an infinite draw loop with no exit, which is a fact about the routine that
a subject word would hide. `../on-screen-priority/` marks rows STUCK on the
strength of it.
