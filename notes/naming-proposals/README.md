# The proposal tables the applied names came from

`apply_cinematic_renames.py` and `apply_routine_names.py` take a markdown
table and refuse or accept each row:

    | constant | proposed name | confidence | evidence |

The names they accepted are in `src/levels`. The **evidence column is not**,
and until this commit those tables lived only in a session scratch directory
under `/tmp`. That is exactly the failure the working rules name: a claim
whose evidence nobody can check, including me later.

So they are here. 69 tables, 489 distinct proposed names, of which **396 are
in the tree right now** — the remainder were rejected by the appliers'
guards, marked `SKIP`, superseded by a later table, or reverted.

## What they are, and what they are not

Each row's evidence column says why that name was proposed: a measured
extent, a drawer routine, a cross-port `canonical_md5` match, a control-flow
position. That is the reviewable part.

They are **working input, not a record of what was applied.** A table says
what was proposed at one moment; `git log` says what landed. Where the two
disagree, the tree wins — several of these were superseded, and at least one
whole batch was reverted after `--duplicates` caught a split family. Do not
read a row here as a claim about the current tree without checking the name
is still there.

They are also uneven: some were written against a render, some against a
probe's output, some by hand. The appliers' guards (collision, coordinate in
a name, new family gaps, and a byte re-verify of every port) are what stood
between them and the tree, not the tables' own quality.

## Regenerating rather than trusting

The probes that produced the measurements are committed beside what they
measure — `../shared-bank-geometry/`, `../polygon-extent-correction/`,
`../routine-extent/`, `../lake-shooting/` and the rest. A number in a table
here that matters should be re-derived from those, not cited from here.

Note that figures in the older tables predate the group-pivot correction in
`../polygon-extent-correction/`: extents quoted for group polygons before
2026-09-19 were computed with the size bytes halved, which is wrong for a
group. 2,468 of 10,144 named polygons were affected. The identity matches
(`canonical_md5`) are unaffected, since that serialises header bytes verbatim.

## Naming of the files

The filenames are the scratch names — `caves_batch2.md`, `prison_zoom.md`,
`wf_amiga_DROPLET.md`. They are kept as they were rather than tidied, so
that a future `git log -S` on a name lands on the file the applier actually
read.
