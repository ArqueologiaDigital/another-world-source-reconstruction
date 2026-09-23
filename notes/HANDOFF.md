# Handoff — semantic labelling of the disassembly

Written 2026-09-20, updated 2026-09-23. Everything below is either in git or
named as disposable. Both repos are clean.

## Where things stand, measured

Run these; do not trust the numbers below without re-running them.

    make test                                            # the byte gate
    python3 notes/unified-symbol-check/undefined_symbols.py
    # after ANY branch-scoped rename, before make test:
    python3 notes/unified-scoping/sync_equ_rename.py <table.md> <STAGE> <branch> --apply
    python3 notes/shared-bank-naming/asset_naming_share.py
    python3 notes/crossstage-duplicates/one_picture_many_names.py
    python3 notes/laser-impact-anim/impact_ladder.py
    python3 notes/draw-label-follows-constant/label_vs_constant.py
    python3 notes/backdrop-drawer/backdrop_drawer.py --control

As of the last commit:

| measure | value | producer |
|---|---|---|
| byte gate | 29/29 stages, 29/29 unified | `make test` |
| undefined symbols in the unified tree | 0 | `undefined_symbols.py` |
| priority-port assets named | 63.5% (6,447/10,147) | `asset_naming_share.py` |
| pictures carrying two or more names | 60 amiga / 59 msdos | `one_picture_many_names.py` |
| coordinate-embedding `CINEMATIC_*` names | **0** | `grep -rhoE '\bCINEMATIC_[A-Za-z0-9_]*_AT_[0-9]+_[0-9]+'` |
| shared-bank keys still unnamed | 77 of 352 (59 reachable) | `notes/shared-bank-geometry/` |
| draw-only labels agreeing with their picture | 212, 0 nameable left, 0 contradicting | `label_vs_constant.py` |
| routines naming a gait and drawing another's sheet | 0 (was 30) | `motion-word-audit/piece_family_vs_label.py` |
| shot-impact ladders complete | 18 of 18 (3 stages x 2 directions x 3 branches) | `impact_ladder.py` |
| routines whose name states a screen the guards confirm | 303 of 303 | `screen-scope/screen_scope.py --control` |
| per-screen entry routines named | 257 of 274, 0 nameable left | `screen-scope/screen_entry.py` |
| backdrop painters named | 52 distinct / 84 labels (was 10 / 20), 0 nameable left | `backdrop-drawer/backdrop_drawer.py` |
| painters whose two sources agree on the screen | 84 of 84 | `backdrop-drawer/backdrop_drawer.py --control` |

## Added 2026-09-23

**The shot-impact burst is one effect drawn from three stages.** PRISON, CAVES
and CAPSULE each run a six-frame flash off a binary search on the timer
`[0x13]`, and `canonical_md5` says all six frames are the same art in all three
stages and both priority ports. All 18 ladder positions now carry a complete
`_0.._5` family. `notes/laser-impact-anim/`.

**A label ending in a threshold is not a frame index.** `..._ABOVE_04` is an
interior node of that search, entered for timer values {4,5}, drawing the frame
for 5. `nameable_from_drawer.py` was inheriting those onto constants; it now
rejects `_ABOVE_/_UPTO_/_BELOW_<n>` (75 skipped, proposals 28 -> 4) and the
README records why `_OVER_<n>` is excluded from that rule.

**"Cannot check" was printing as "does not match".** `apply_branch_scoped_names`
reverted every cartridge rename claiming the bytes moved, when the truth was
that the cartridge baseline is reached through a *relative* root and only
resolves from the archaeology repo. Run cartridge appliers from there. The
message now says which case it hit.

**Every drawer-side seam is now measured and worth 0.** The ledger is in
`notes/sole-named-drawer/README.md`: sole named drawer 0, the one-hop through
an unnamed stub 0, the same hop for `--animations` 0, dispatch ladders 19, art
named in another stage ~38, art named in the other port for the same stage 22.
What remains is **1,655 pictures numbered in *both* priority ports with
identical art** — 667 CAVES, 511 PRISON, 403 CAPSULE — which nothing in the
call graph distinguishes.

**The method that worked, stated once.** Everything that moved after the
mechanical seams ran out came from one idea: *the control flow and the art
identity around a picture identify it when the picture itself cannot.* Six
probes, each with a control:

| probe | what it reads | control |
| --- | --- | --- |
| `screen-scope/screen_scope.py` | forward dataflow on `[SCREEN_NUM]` | re-derives 303 of 303 human screen assignments |
| `screen-scope/screen_entry.py` | the chain whose targets write the camera bounds | the two already-named chains fall on the negative side |
| `substitute-layers/alternative_of.py` | the branch that picks between a named and an unnamed picture | — |
| `substitute-layers/fire_frames.py` | the muzzle offset's sign | re-derives 9 already-correct namings |
| `shared-bank-geometry/mirror_match.py` | point sets flipped in x | **fails** on aim-vs-shoot; used only where the gap is wide |
| `cross-port-art/bank_copy_in_stage.py` | `canonical_md5` against named bank art | 21 shared-chunk constants differing proves the guard needed |

Rendering, by contrast, produced one screen's names in a whole round and a
bug in my own rule. Reach for the control flow first.

**The standing population, measured.** `notes/substitute-layers/draw_threads.py`
finds **126** unnamed threads whose whole body is a run of three or more
still-numbered draws — the shape of an animation. Exactly **4** sit beside a
named, non-mechanism routine in their `setup` block; the CAVES trap columns
were one such case and yielded 42 names. The other **122** have no naming
anchor at all. They are a characterised population, not a lead: each is a
short animation at a known slot, needing recognition, which is the render
problem. One worked example of that difficulty is recorded in the probe
rather than guessed at.

**The compounding does not happen, twice measured.** Naming 264 routines
freed 2 constants (both bad, both filtered); naming 226 constants freed 0
draw-only labels. The two layers are not a chain — the 465 draw-only labels
wait on pictures drawn by *one-picture stubs*, and the pictures being named
now are painted inside multi-draw composites. Do not plan work on the
assumption that one layer unlocks the other.

**The screen blocker is solved.** `notes/screen-scope/screen_scope.py`
derives which `[SCREEN_NUM]` value a routine is reachable under, by forward
dataflow on the guards, and `--control` re-derives **303 of 303** screen
assignments that names already state. Two things came out of it: 69 backdrop
layers named `<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>`, and 264 per-screen
routines named `<STAGE>_SCREEN_<NN>_ENTRY` plus their nine dispatchers. It
also found one wrong name (msdos and cartridge install the CAVES palette-flash
event on screen 0xEE, not the 0xED the shared label claimed) and can find more
with `--proposals`.

`screen-scope/backdrop_phase.py` then named **226** more: everything a screen
entry paints before its first `setup`, indexed by position in that sequence.
It refuses far more than it names, and correctly — 590 pictures are painted
twice in one phase and so have no single position, 296 appear in several
screens' phases, and 107 are blocked permanently by the family-gap guard
because the holes are exactly those shared and twice-painted layers.

**So start from `notes/remaining-art/by_anchor.py`**, which sorts that backlog
by how each picture is anchored, because the classes need different evidence:
1152 at a fixed literal `x,y` (scenery, the class with no method yet), 1534 at
an actor/prop slot, 788 at the hero slot, 228 mixed.

**The one concrete lead inside it:** 42 routines are `fill` + layers at one
anchor — backdrops. Six already carry their screen in the label, and
`by_anchor.py --proposals` turns that into names for the layers exclusive to
that screen (4 applied 2026-09-23). The other 36 need the screen, which is a
multi-hop reachability problem: the label's hex token is **not** the screen
(0 of 54 match a `[SCREEN_NUM]` guard), the call site does not carry it, and
there is no single dispatcher — `[SCREEN_NUM]` is compared 182 times across 52
values in CAVES alone. Solving that unlocks the largest class.

**The render-and-look method is now set up and demonstrated.**
`notes/prison-cell-block/README.md` names PRISON screen 0x04 end to end and
carries the recipe, including the two tool conventions that cost an hour:
`render_scene_composite.py` wants the **painter** routine, not the entry (the
entry composites 3 draws and looks empty), and `polygon_render_png.py` wants
the extracted 64 KB slab with the raw EQU value, not `cinematic.rom` with
`3 * 0x10000 + equ`, which silently renders nothing.

Every screen entry is now named, so the next screen is
`<STAGE>_SCREEN_<NN>_ENTRY` -> its painter -> composite -> per-layer renders.
The rate is **four names per screen** against roughly fifty screens a stage,
three of the seven layers held back because a render can mislead. That is the
honest cost, and it is why every mechanical seam was exhausted first.

**Also still open:** the 465 draw-only labels whose picture is unnamed — each
becomes free the moment its constant is named, so the asset work unlocks the
routine work. Re-run `label_vs_constant.py` after any asset batch.

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

0a. **Art family gaps, two of three explained.** `HERO_RUN_LEFT_ARM` is
   missing F04 because that frame draws no arm (`run_left_body.map`), and
   `HERO_WALK_LEFT_ARM` is missing F05..F13 for the same reason, verified
   three ways in `notes/shared-bank-geometry/walk_left_arm_gap.md` --
   including that the offsets those pieces would occupy are already held by
   `HERO_WALK_RIGHT_ARM_F09..F12`. Neither is outstanding naming work.

1. **Routine family gaps: 86, not the 73 recorded here before** (`notes/
   family-gaps/routine_family_gaps.py`). The count rose because the 210
   draw-label renames of 2026-09-23 created 47 new `<STAGE>_DRAW_*` families,
   21 of them with an interior gap. Those 21 are **not** outstanding work:
   their indices are inherited from the constant each label draws, and
   `notes/draw-label-follows-constant/footstep_frames.py` shows every hole
   holds a drawer that also does `play id=0x0060` — the footstep. The run
   cycle steps on frames 0 and 5 of ten, the walk cycle on 5 and 13 of
   fifteen. Renumbering them densely would put the wrong frame on the name.

   The "one animation under two conventions" class is **closed**: it was
   PRISON's ten `ACTOR/BUDDY_WALK_LEFT_PHASE_{0,3,5,7,8}` labels drawing the
   run sheet, settled by `notes/motion-word-audit/piece_family_vs_label.py`
   without overriding any earned name — the pieces decide, and they were named
   from geometry independently of any stage's label conventions.
2. **81 routine renames blocked by a dependency chain**: family gaps → cart
   and GBA art unnamed → no proposals → a shared `_helpers` label that cannot
   be renamed for one branch alone. Breaking any link unblocks the rest.
2a. **18 of the remaining shared-bank keys are unreachable, not unnamed.**
   `CV_5F74..CV_5FFC` pair one-to-one with the named
   `CV_FIGURE_WALK_<DIR>_UPPER_POSE_00..08` and are drawn only behind
   `jg [0xF6], 0x00`. `[0xF6]` is written nine times across all four
   branches and every write is `mov [0xF6], 0x0001`; nothing sets it to
   zero, and every stage containing the guard also contains the write. So
   all 180 guards jump and all 162 draws are dead. Per #0126 they take no
   role name. `notes/shared-bank-geometry/unreachable_guarded_art.py`
   re-checks it and exits 1 if any draw is ever found outside the guard.

   **The real remaining count is therefore 59, not 77.**

3. **77 shared-bank keys** (`notes/shared-bank-geometry/`). 113 are
   actor-slot offsets, blocked by #0138 for *who* they draw but nameable by
   *pose*. The RUN sub-pieces are neither symmetric nor complete, which is
   why they stalled. 50 are hero-art, of which the consensus engine can
   reach 5 — see the next item for why so few.

   The 26 jump frames came out of this pool on 2026-09-23 once item 6 was
   resolved (`jump_left.map`, `jump_right.map`).

3a. **`hero_pose_consensus.py` cannot see most of its evidence.** Two
   mechanical reasons, both measured and neither yet fixed:

   * ~~Rule 8 discards any routine drawing 3+ pictures as a dispatcher.~~
     **Measured and NOT worth changing.** The criticism is real — the bound
     is applied per *routine* where the evidence only supports it per
     *frame*, and all 28 routines that exceed it draw at most one picture per
     frame — but after the jump sheets were named, **zero** unresolved hero
     offsets are blocked by it, and none of their drawers draws more than one
     picture per frame. Changing it would gain nothing. Left as is.
   * ~~`RE_MOTION` requires motion and direction to be adjacent.~~ **Fixed.**
     `motion_of()` now reads the motion word **immediately before the
     direction**; earlier motion words are the approach. Consensus went 5 → 7
     (the two new ones are the `HERO_CROUCH_ARMED_LEFT_...` pair the
     adjacency rule could not parse) with the five previous results
     unchanged. A name making two different motion claims is refused, not
     guessed.

   * **Vocabulary gap, closed.** `AIM`, `FIRE` and `SHOT` were missing.
     `FIRE` and `SHOT` are one action — the routines containing each draw
     exactly the same four offsets — so both normalise to `SHOOT`, which
     appears in no hero routine name at all. `LEAP` was deliberately left
     out: it draws nothing at the hero anchor, so there is no art to check
     `LEAP == JUMP` against.

     Adding them took consensus 7 → **5**, and that is the probe getting
     more honest, not worse. `CV_17CC` and `CV_1664` were being named CROUCH
     on the strength of two CAVES routines while CAPSULE's
     `HERO_GUN_AIM_HOLD_*_LOOP` was silently unparseable. Making it parse
     converted a false unanimity into a recorded conflict.

   **The AIM-vs-CROUCH conflicts are resolved by measurement**
   (`pose_height.py`). Against the 15 committed `HERO_WALK_LEFT_BODY` frames
   (median height 49.0) the disputed offsets are bimodal with an 11-unit gap
   and nothing in between:

       CV_1664 44.5, CV_17CC 45.0          upright  -- CAVES's CROUCH is wrong
       CV_3764, CV_39A2, CV_389E,
       CV_3ADC, CV_1784   33.0..33.5       crouched -- CROUCH is right

   `CV_1784` is the control: both its sources already agreed on CROUCH with
   no AIM claim against it, and it lands in the crouched mode. Height settles
   the body and says nothing about the arms, so for the four crouched ones
   both names are partly right — that is the #0120 intersection, and naming
   them is the next step. **Done** — `armed_poses.map`, 11 offsets.

   **What blocks the rest: the drawers are unnamed.** 28 of 35 have no
   parseable drawer in any stage — not a disagreement, an absence. The way
   through is the jump-sheet method: motion from **scheduling and geometry**
   (anchor arithmetic, `airborne_in_art.py`, `pose_height.py`) rather than
   from any name.
3c. **Half-named mirrors are invisible in every count**, so they have their
   own check: `notes/shared-bank-geometry/half_named_mirrors.py`. It asks,
   for each named piece containing `_LEFT`/`_RIGHT`, whether the flipped name
   exists. It found `HERO_CROUCH_RIGHT` and `HERO_STAND_RIGHT_{BODY,ARM}`.
   **All 20 entries are now adjudicated and none is open.** The three
   `HERO_GUN_ARM_LEFT_CASE_0n_CHARGE_BLINK` are absences — the left switch
   draws a blink only at case 4, against four on the right — and the
   CINEMATIC scenario name is a false positive, since "right" there names a
   place rather than a facing.

3b. **Six of the eight consensus "disagreements" are one artefact.** CAVES
   indexes a single crawl cycle forwards as `HERO_CRAWL_LEFT_PHASE_n` and
   backwards as `HERO_CRAWL_RIGHT_PHASE_(15-n)` — six pieces claimed in both
   directions, and the two phase numbers sum to exactly 15 every time.
   `notes/shared-bank-geometry/crawl_one_cycle_two_labels.py` re-checks it
   and exits 1 if the sum ever stops being constant. The two directions are
   therefore not independent sources. Which labeling is right is NOT settled
   and needs anchor arithmetic or a render.

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
