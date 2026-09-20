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

Each row has an evidence column. **How much it is worth varies, and a
verification pass measured by how much** -- see `coverage.py --quality`:

  * 14 of the 69 repeat **one evidence string on every row**. The rationale
    is real ("the stage prefix is falsified by the art…") but it is
    per-batch, not per-name: it tells you why the batch was proposed, not
    why *this* constant got *that* name.
  * 5 groups, 12 files, are **byte-identical to each other** --
    `death_amiga.md == death_msdos.md == death_other.md`,
    `g_INTRO.md == h_INTRO.md == xp_INTRO.md`, and three more. The filename
    claims a port or a stage the bytes do not carry, so do not read
    `hd_msdos_CAVES.md` as an msdos record; it is the same file as the amiga
    one.

An earlier version of this README said "each row's evidence column says why
that name was proposed". For 14 of 69 that is an overstatement, and it was
caught by an adversarial audit of the scratch directory rather than by
reading them. The rest do carry per-row evidence -- a measured extent, a
drawer routine, a cross-port `canonical_md5` match, a control-flow position.

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
group. About a quarter of named polygons were affected -- 2,468 of 10,144 when
the correction landed, 2,195 of 9,397 when re-run a day later, the population
having shifted under a day of naming. See that note for why the totals differ.
The identity matches (`canonical_md5`) are unaffected, since that serialises
header bytes verbatim.

## Checking this README's own numbers

    python3 notes/naming-proposals/coverage.py
    python3 notes/naming-proposals/coverage.py --quality

The first prints the three counts quoted above and reproduces them;
`--per-table` shows which tables landed nothing and `--missing` lists the
names that never made it. `--quality` prints the duplicate groups and the
per-batch-evidence tables, so the caveats above are measured rather than
remembered.

## Naming of the files

The filenames are the scratch names — `caves_batch2.md`, `prison_zoom.md`,
`wf_amiga_DROPLET.md`. They are kept as they were rather than tidied, so
that a future `git log -S` on a name lands on the file the applier actually
read.
