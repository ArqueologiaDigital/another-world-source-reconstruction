# Handoff — semantic labelling of the disassembly

Written 2026-09-20 at the end of a long session. Everything below is either
in git or named as disposable. Both repos are clean.

## Where things stand, measured

Run these; do not trust the numbers below without re-running them.

    make test                                            # the byte gate
    python3 notes/unified-symbol-check/undefined_symbols.py
    python3 notes/shared-bank-naming/asset_naming_share.py
    python3 notes/crossstage-duplicates/one_picture_many_names.py

As of the last commit:

| measure | value | producer |
|---|---|---|
| byte gate | 29/29 stages, 29/29 unified | `make test` |
| undefined symbols in the unified tree | 0 | `undefined_symbols.py` |
| priority-port assets named | 50.8% (5,154/10,147) | `asset_naming_share.py` |
| pictures carrying two or more names | 60 amiga / 59 msdos | `one_picture_many_names.py` |
| coordinate-embedding `CINEMATIC_*` names | **0** | `grep -rhoE '\bCINEMATIC_[A-Za-z0-9_]*_AT_[0-9]+_[0-9]+'` |
| shared-bank keys still unnamed | 189 of 352 | `notes/shared-bank-geometry/` |

## The method that worked, in one paragraph

Measure before looking. The pictures mislead — two passes over LAKE misread
the same group from renders — and the bytecode does not: **which variable
pair a `video` draws at** settles what a thing is more reliably than the art
does. Match across ports and stages by `canonical_md5`, never by index.
When two earned names disagree, name the intersection or report the conflict;
do not pick a winner (#0120). Explain every gap rather than filling it. Run
`undefined_symbols.py` before `make test`. The byte gate is the oracle, but
remember what it cannot see: **a rename cannot move a byte, so the gate is
blind to a wrong name.** It only catches a half-applied one.

## The trap that caught me twice, in the same group

`CINEMATIC_DECOR_AT_305_155_*` was grouped by *where it is drawn*, so it held
a hero, a gunman, a beam and a drifting reed under one name. The first pass
split it from renders and got four frames wrong, calling the hero "drifting
decor" — because it grouped by size and by drawer label, and it had coined
those drawer labels itself, in the same pass, from the same look at the same
pictures. **Two guesses agreeing is not evidence.** What settled it was one
operand: `x=[HERO_X], y=[HERO_Y]`. Decor is not drawn at the hero's
coordinates.

The second half of the group failed for the opposite reason: one SVG per
offset showed "a shape beside a line", because the bytecode draws two
pictures *at the same anchor* and the renders were each trimmed to their own
art. `notes/lake-shooting/composite_at_anchor.py` exists to fix that; reach
for it whenever two draws share an anchor.

## Open work, roughly in order of value

1. **72 of 73 routine family gaps** (`notes/family-gaps/`). 17 of them are
   "one animation under two conventions" and need a decision that overrides
   an earned name — that is a judgement call, not a measurement, and it has
   been deferred each time.
2. **81 routine renames blocked by a dependency chain**: family gaps → cart
   and GBA art unnamed → no proposals → a shared `_helpers` label that cannot
   be renamed for one branch alone. Breaking any link unblocks the rest.
3. **189 shared-bank keys** (`notes/shared-bank-geometry/`). 148 are
   actor-slot offsets, blocked by #0138 for *who* they draw but nameable by
   *pose*. The RUN sub-pieces are neither symmetric nor complete, which is
   why they stalled.
4. **60 amiga / 59 msdos pictures with multiple names.** Reported, not
   reconciled, per #0120. 49 have the shape of one family named twice.
5. ~~**`genesis_europe` is not covered by `undefined_symbols.py`.**~~
   **Wrong — checked 2026-09-23 and corrected.** `BRANCH` is only ever
   compared against the four branch directory names; `snes_eu` and
   `genesis_europe` are two verify TARGETS built from one branch,
   `cartridge_1992`, and they assemble identical text. The four-entry list
   already covers all five targets.

   The rename that did move genesis bytes was a **redefinition** — two EQUs
   for one name — and the probe was blind to it for a different reason:
   `defs` was a `set`, so a symbol defined twice looked exactly like a symbol
   defined once. That check now exists. It grades severity: different values
   are an error, same value is a warning, because 30 same-value redundancies
   are already in the tree and failing on them would make the probe useless
   as a pre-`make test` gate. See `--redundant`.
6. ~~**Jump sheets held**~~ **— resolved 2026-09-23, and the reasoning
   recorded here was wrong.** "Neither writes `HERO_Y`" is true; the
   inference that they are therefore not jumps is not. The anchor is the
   ground reference, and the lift is drawn **inside the sprite**:
   `notes/shared-bank-geometry/airborne_in_art.py` measures each frame's
   bottom edge and finds the feet leave the ground for frames 6..7 of the
   12-frame sheet and 1..4 of the 9-frame one, against a modal ground level
   of +0.5. Fifteen committed `HERO_WALK_LEFT_BODY` frames show no airborne
   frame at all, which is the control.

   There was also far less disagreement than this entry claimed. CAVES
   (`HERO_JUMP_*_FROM_STAND`) and PRISON (`PRISON_HERO_WALK_JUMP_*`) draw the
   **same twelve CV offsets in the same order** with the same net X
   displacement (±57), and both names say JUMP. They differ only in how they
   describe the approach. The 9-frame `*_FROM_RUN` / `*_RUN_JUMP_*` pair
   agrees the same way and does write `HERO_Y` three times.
7. **34 non-`CINEMATIC_` identifiers still embed coordinates**, mostly
   `SHOW_TEXT_*_AT_x_y` where the coordinate *is* the argument. Different
   question from the one just closed; decide whether the rule applies.

## Things that are wrong or fragile, so you do not rediscover them

- **`notes/naming-proposals/tables/` extents from before 2026-09-19 are
  wrong for group polygons** — they were computed with a group's size bytes
  halved, which is right for a solid and wrong for a group (a group's two
  bytes are a pivot, subtracted whole). `canonical_md5` matches in those
  tables are unaffected. See `notes/polygon-extent-correction/`.
- **Probe nondeterminism**: iterating a `set` let `PYTHONHASHSEED` change a
  calibration tie-break; three runs gave 22, 21, 22. All iteration in the
  committed probes is sorted now. Keep it that way.
- **Circular calibration**: a probe that parses names with the same regex the
  names under test were written by will confirm itself. `phase_base_calibration.py`
  has its own regex for exactly this reason.
- **`SystemExit` escapes `except Exception`.** `slab()` raises it for a port
  with no romset, which aborted a whole four-branch run. Use `except
  BaseException` and skip the port.
- **Only amiga, msdos and gba_usa romsets exist** under
  `another-world-archaeology/tmp/output/`. Cross-port checks silently cover
  two ports unless you notice.

## What is disposable, and why

The session scratchpad under `/tmp/claude-1000/.../scratchpad` holds 781
files. 577 are PNG/SVG renders — **regenerable and deliberately not
committed**, per the working rules on large corpora. The recipe is:

    awvm-render-polygons --port amiga --stage 2 --romset <dir> \
        --bank cinematic --out <dir>

The 69 markdown proposal tables that carried per-name evidence have been
rescued into `notes/naming-proposals/`, with `coverage.py` beside them to
reproduce the 69 / 489 / 396 counts its README quotes.

### The three scratch scripts, adjudicated

The scratch-artefact hook flagged three `.py` files. None produced a number
that is published anywhere without a committed producer; each is superseded:

| script | verdict | why |
|---|---|---|
| `scope_fix.py` | **disposable** | Byte-identical body to the committed `notes/unified-scoping/scope_fix.py` — diffed, the only difference is that the committed one carries the 50-line docstring recording the bug it had (it scoped every proposed row, when the applier applies only some). The scratch copy is its undocumented predecessor. |
| `remeasure.py` | **disposable** | A per-index debugging view of `extent_old` vs `extent`. Superseded by `notes/polygon-extent-correction/what_the_correction_moves.py`, which answers the same question over the whole tree, has `--names` for the per-name view, and is the producer of the figure now quoted in that note. |
| `_*.py` (9 files) | **disposable, as a class** | `_audit.py`, `_audit2.py`, `_audit3.py`, `_audit_cov.py`, `_audit_pairs.py`, `_cmp.py`, `_cmp2.py`, `_global.py`, `_global2.py` — written by the audit's own subagents, one per slice. Each hardcodes the scratch path and answers one throwaway question ("is this file's content already in the repo?", "is this a duplicate of that?"). None is referenced by any committed text. The underscore prefix is the tell: it is the convention the subagents converged on for their own working tools. The published numbers they contributed to have committed producers — `notes/naming-proposals/coverage.py` for the table counts, `notes/scratch-audit/grounds.py` for the refutation histogram. The set is final: the workflow has ended, so no more will appear. |

### The sweep, and its result

Deleting the scratchpad loses nothing that is not either committed or
reproducible by the command above. That is not an impression -- it was
measured, and the measurement is in `notes/scratch-audit/`:

  * 194 non-render files audited by ten agents, each backed by a second agent
    told to **refute** its keep-calls.
  * 41 files proposed for rescue. **All 41 refuted.** `verdicts.md` has the
    grounds one file at a time.
  * The strongest refutations checked out the pre-apply tree in a throwaway
    worktree, re-ran the committed probe, and showed the scratch file was
    byte-identical to its output. Sixteen went that way.

Three things did come out of it, and all three are fixed in the tree rather
than rescued: the `--held` flag on `transfer_across_stages.py` (a counted
hold with no subject sent an agent rummaging in /tmp for a pair HEAD computes
every run), the corrected per-row-evidence claim in
`notes/naming-proposals/README.md`, and `coverage.py --quality`.

The lesson generalises past this repo: **a proposal table is a worse record
than the commit that applied it.** The diff carries the same (constant, name)
pairs plus the EQU offsets the table omits. The tables were still worth
keeping, but as the appliers' input, not as the evidence of record.
