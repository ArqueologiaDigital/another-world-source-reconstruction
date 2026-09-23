# Names that came from someone watching the game

**Every name in this directory rests partly on a sentence a person typed while
looking at a frame.** The frame was live in `tools/vm-debugger/`, the asset's
own polygons were blinking, and what was typed was prose -- what the thing is
doing -- rather than a name.

Like `../render-and-name/`, that evidence has **no independent check**. A
rename moves no bytes, so `make test` cannot catch one of these being wrong.
They are grouped in one directory for exactly that reason: they can be audited,
or reverted, as a set.

Unlike a render it is also **not reproducible**. The frame can be reached
again -- `tools/vm-debugger/README.md` says how to drive a stage to it -- but
the sentence cannot. Nothing in this repository regenerates a person's reading
of a scene, and the person may not be here tomorrow. That is why these tables
do not live in `../render-and-name/`: both directories hold unchecked evidence,
and only one of the two can be re-derived from the ROM.

| file | question it answers | command |
| --- | --- | --- |
| `annotation_queue.py` | Which annotations has nobody acted on, and what does each one actually point at? | `python3 notes/play-and-describe/annotation_queue.py` |
| `verdicts.tsv` | The annotations that produced no name, and why | `annotation_queue.py --verdict <id> <verdict> --grounds ...` |
| `proposals_<branch>__<STAGE>_<tag>.md` | The names a batch of sentences earned, with their evidence | fed to `apply_branch_scoped_names.py` |
| `tests/run.sh` | Does `--check` actually fail on each way the bookkeeping can break? | `sh notes/play-and-describe/tests/run.sh` |

The sentences themselves stay where the server writes them,
`tools/vm-debugger/rename_log.jsonl`. They are this directory's input, not its
record.

## What a sentence is evidence OF

**A sentence is evidence for the subject word of a name and nothing else.**
This is the admissibility rule; `docs/NAMING.md` states it once and everything
here applies it.

Every other component of a `CINEMATIC_*` name comes out of the listing exactly
as it always has:

* **the index** -- position in the run (`../render-and-name/frame_runs.py`),
  the rung of a dispatch ladder (`../render-and-name/ladder_rungs.py`), or the
  slot in the bank (`../bank-locality/offset_runs.py`). Somebody watching an
  animation play does not count its frames, and the one thing a viewer is
  certain to get wrong is an order the routine states itself;
* **the family bounds** -- the EQU run and the routine's draw list. What the
  person saw was one frame, and a family named from one frame is a guess about
  the other four;
* **the `_SCREEN_<NN>_` component** -- `../screen-scope/screen_scope.py`'s
  forward dataflow on `[SCREEN_NUM]`, whose `--control` re-derives the screen
  assignments the tree's own names already state. A person knows they are in a
  cave; they do not know which screen ordinal the dispatch reached it under;
* **the port** -- `canonical_md5`, through
  `../cross-port-art/transfer_by_art.py`. The person watched one branch's ROM
  run and said nothing about the other three. Carry by **art**, never by the
  sentence.

### The confidence cap

A row is `high` only when something **non-visual** corroborates the subject:
the draw anchor, the run, the rung, the measured extent, the leaf count,
`canonical_md5`. Prose plus a render the agent did itself is not two sources;
it is **one picture described twice**, and two guesses agreeing is not
evidence. `CINEMATIC_DECOR_AT_305_155_*` was got wrong twice in precisely that
shape -- see `notes/HANDOFF.md`, "The trap that caught me twice, in the same
group". A row resting on the sentence alone is `low`, and
`--min-confidence medium` refuses it mechanically rather than on judgement.

### The actor word

An actor word the person used -- Buddy, Lester -- enters a name only where
that stage's already-earned names use it **at that anchor**. Otherwise it goes
in the evidence column, and a contradiction with `../actor-anchors/` is
**reported, not adjudicated**, per #0120.

    $ python3 notes/actor-anchors/anchor_identity.py
      72 conflict(s) between a name's own actor word and
      the actor word of the anchor it is drawn at.

An anchor says *the same actor*; it never says *which* actor, and neither does
a viewer who has been told the companion's name by the box art. The tree's own
practice where the two disagree is the neutral word `FIGURE`.

### Names typed into the box

`kind:"rename"` and `kind:"bulk_rename"` entries carry a name with no stated
grounds. They enter the same queue and are **never above `low` on their own**;
whatever would justify them has to be found in the listing afterwards, exactly
as for a description. A `bulk_rename` is a **convention proposal for the
owner**, not a batch -- it asserts a spelling rule across many names at once,
which is the class of decision `notes/HANDOFF.md` records as worth more than
any probe and leaves to the owner.

## The id

An annotation's id is `ann:` plus the first twelve hex digits of the sha1 of
its raw log line, with the trailing newline stripped. One shell command, no
tool, no index file:

    $ sed -n '1p' tools/vm-debugger/rename_log.jsonl | tr -d '\n' | sha1sum
      cff7052605ce75f469b065bd08daf7c7ef7b5916  -

so the log's one entry today is `ann:cff7052605ce`.

Four properties, each of which something else on the shortlist lacked:

* **stable.** The only write `server.py` performs on the log is an append
  (`LOG.open("a")`), so a line that exists never changes.
* **order-independent**, unlike a line ordinal. Sorting or filtering the file
  for reading does not renumber anything.
* **not the timestamp.** `at` has one-second resolution and is supplied by the
  appending machine, so it is neither unique nor portable.
* **content-derived.** An edited line gets a new id, so its old citations show
  as **orphans** rather than silently pointing at a sentence that no longer
  says what they quoted.

Twelve hex rather than eight is collision headroom, and `--check` fails on a
collision instead of guessing.

**The cost, which is the whole of it: the log is append-only.** Never edit,
reorder or delete a line. Rewriting one orphans every proposal row and every
verdict that cites it, and the sentence it replaces cannot be recovered by
re-running anything. The alternative considered -- a hash over the
canonicalised JSON with an `id` field excluded -- survives reformatting of the
file, but reformatting is already forbidden, there is one writer, and it costs
the one-line recomputation above, which is what an agent actually reaches for.
Rejected on that trade.

Because the id is taken over the whole line, `server.py` cannot stamp it into
the entry without circularity. It computes the id from the line it has just
written and prints and returns it, which is the half that matters: the person
at the screen can quote `ann:<id>` in a message.

## How consumption is known

**Derived wherever the tree can record it; asserted only where it cannot.**

An annotation is **consumed-as-named** by a two-hop test, applied **per row**:

1. the token `annot:<id>` appears in the evidence cell of a proposal row
   anywhere under `notes/`;
2. that row's new name is defined in `src/levels/<branch>/<STAGE>.asm` as
   `NAME EQU` or `NAME:` -- the same adoption test `sync_equ_rename.py`
   already uses.

Both hops for every citing row gives **NAMED**. Hop one alone gives
**PROPOSED**, printed loudly, because that is either a row the applier rejected
or a half-applied batch, and it is how work gets lost. Per row rather than per
table, so one rejected row in a batch of twenty stays visible instead of being
averaged away. Reading the second hop out of the **tree** rather than out of
the applier's stdout is also what catches the documented cartridge silent
no-op, which prints "N proposed, 0 rejected" while reverting everything
(`../render-and-name/README.md`, "`cartridge_1992` applies have to be run from
the archaeology repo"). The bookkeeping cannot drift from the tree because it
is read out of the tree on every run.

**Consumed-with-no-name is asserted**, because nothing in the tree can record
it. `verdicts.tsv`, one row per id, columns
`id / at / branch|stage / offset / verdict / grounds / settled_by`:

| verdict | when |
| --- | --- |
| `CORROBORATES` | the sentence agrees with a name already earned. The specific case; use it in preference to `NO_NAME` |
| `NO_NAME` | true and useful, yields no rename -- the family is already complete, or the sentence is narrative |
| `HELD` | `settled_by` required, naming what would settle it, matching `notes/HANDOFF.md`'s "Held, with what would settle each" |
| `REJECTED` | the sentence cannot support a name -- a misclick, or it describes the scene rather than the click. Record the `on_screen` offset it should have pointed at, which turns a wasted annotation into a pointer |

This is the only hand-written state in the mechanism. **A verdict row and a
citation are mutually exclusive**, and `--check` fails when an id has both.

### The status vocabulary

`OPEN` (nobody has touched it), `PROPOSED`, `NAMED`, `AMENDED` (a fresh
sentence about a target already settled, keyed on branch, stage and
`target.offset`, with the earlier outcome printed beside it), plus the four
written verdicts. **Work PROPOSED before OPEN.**

### Provenance runs both ways

Forward, from a name to the sentence that suggested it:

    grep -rn "annot:cff7052605ce" notes/

which lands on the row, carrying the frame, the routine and the quoted clause.
Backward, from the sentence to everything resting on it:

    python3 notes/play-and-describe/annotation_queue.py --id ann:cff7052605ce

`--check` walks the same edges in reverse and exits 1, so a broken provenance
edge is an error rather than a silence.

### Double-apply

**The three layers below are post-commit guards.** Between two agents reading
the queue and either of them committing, nothing stops both picking the same
id: there is no reservation state, deliberately, because a claim that is not in
git is a claim the next clone cannot see. The cover for that window is step 6's
convention -- **commit the table before applying, because committing is
claiming** -- and it is a convention, not a mechanism. Two agents worked in
parallel on one annotation would collide, and the collision would surface as
`apply_cinematic_renames.validate` refusing the second rename rather than as
anything this directory printed.

Three layers, earliest first. The queue does not show a NAMED or verdicted id,
so a second agent never picks it up. Committing the table **before** applying
makes the claim visible to anyone who pulls. Underneath both,
`apply_cinematic_renames.validate` refuses a name already defined and
`sync_equ_rename.py`'s `../unified-scoping/applied_rows.tsv` journal makes a
re-run inert rather than destructive. This directory adds no new double-apply
risk; it inherits the two guards that would be the ones catching it, and the
PROPOSED state catches the half-applied case those guards cannot see.

Everything `--check` reads is in git -- the log, the tables, the tree,
`verdicts.tsv`. No session state, no database, nothing in `/tmp`. A fresh clone
reproduces the same queue, which is also why the log must be committed: an id
computed from a file only one machine has is not a shared identity.

## The procedure

This is the only copy. `CLAUDE.md`, `notes/HANDOFF.md` and
`tools/vm-debugger/README.md` point here and repeat nothing but the first
sentence of step 4.

**0. Commit the log before interpreting it.**

    git status --short tools/vm-debugger/rename_log.jsonl

The file is tracked and in HEAD. `server.py` appends into the **working
tree**, so a play session leaves it dirty, and that is the state this step is
about.
A `git clean`, a discarded worktree or a fresh clone takes every sentence with
it, and a sentence is the one kind of evidence in this repository that cannot
be regenerated by re-running anything. If it is dirty, commit it alone and
unedited: `vm-debugger: N annotations from <date>'s play session`. Never edit,
reorder or delete a line: an id is the sha1 of its line, and rewriting one
orphans every table and verdict that cites it. `annotation_queue.py` refuses to
call anything consumed while the log has uncommitted lines.

**1. Read the queue.**

    python3 notes/play-and-describe/annotation_queue.py

One line per annotation: status, `ann:<id>`, branch/stage, frame, the target's
current name and offset, the first clause of the text. `--all`, `--stage`,
`--branch` narrow it. Statuses: OPEN, NAMED, PROPOSED (cited but the tree does
not define the name — a rejected row or a half-applied batch; start here),
AMENDED (a fresh sentence about a target already settled), and the four written
verdicts. Work PROPOSED before OPEN.

**2. Measure the target before believing the sentence.**

    python3 notes/play-and-describe/annotation_queue.py --id ann:<id> --measure

Prints the sentence beside the target's current name and namespace, every draw
site of that constant in the branch's `.asm` with its anchor expression, the
routine's **static** draw list, and the log's `routine_draws` and `on_screen`
next to it. Read the two lists together. `routine_draws` is what that routine
drew **in one frame** -- `static/app.js:91-96` filters `state.frame.draws` — so
it under-reports: `ann:cff7052605ce` carries one constant while
`STORM_AMBIENT_DRIFT_DRAW_LOOP` draws five (`INTRO.asm:1145-1153`). Taking it
for the family names a five-frame run from a sample of one.

If the target is a `CV_*` key, stop: `apply_cinematic_renames.py` matches
`CINEMATIC_*` only, so there is no applier behind it. Verdict HELD, settled_by
`notes/shared-bank-geometry/`.

**3. Get the family, the index and the scope from the bytecode.**

    python3 notes/render-and-name/frame_runs.py --stage <S> --min 3 --stages
    python3 notes/render-and-name/ladder_rungs.py        # if the draws are dispatched on a variable: the index is the RUNG, not draw order
    python3 notes/actor-anchors/anchor_identity.py --stage <S>   # if the sentence names an actor
    python3 notes/screen-scope/screen_scope.py           # if a _SCREEN_<NN>_ word is wanted
    python3 notes/cross-port-art/transfer_by_art.py      # does the other port hold the same art?

**4. Apply the admissibility rule.**

**A sentence is evidence for the subject word of a name and nothing else.**
The index, the family bounds, the `_SCREEN_<NN>_` component and the port come
out of the listing exactly as before — the person watched one branch's ROM run
and said nothing about the other three. A row is `high` only when something
**non-visual** corroborates the subject: the draw anchor, the run, the rung,
the extent, the leaf count, `canonical_md5`. Prose plus a render the agent did
itself is not two sources; it is one picture described twice, which is how
`CINEMATIC_DECOR_AT_305_155_*` was got wrong twice. A row resting on the
sentence alone is `low`, and `--min-confidence medium` refuses it mechanically.
An actor word the person used (Buddy, Lester) enters a name only where that
stage's already-earned names use it at that anchor; otherwise it goes in the
evidence column and a contradiction with `notes/actor-anchors/` is reported,
not adjudicated. `kind:"rename"` and `kind:"bulk_rename"` entries are names
typed into a box with no stated grounds: same queue, never above `low` on their
own, and a `bulk_rename` is a convention proposal for the owner, not a batch.

**5. Look, only to check the sentence against the art.**

    python3 notes/render-and-name/palette_in_force.py --branch <B> --stage <S> --const <C>
    python3 notes/render-and-name/compose_run.py --progressive --routine <LABEL>

**6. Write one table per batch**, `notes/play-and-describe/proposals_<branch>__<STAGE>_<tag>.md`,
same four columns the applier parses. Never append a section to an existing
table — a rename table is not idempotent (`notes/unified-scoping/applied_rows.tsv`
records why). Its opening paragraph names the id and quotes the sentence
verbatim. Every row resting on it carries three parts in its evidence cell, in
this order: the mechanical anchor (offset, extent, anchor expression, position
in the run or rung), then `annot:<id>` with the frame and the routine, then no
more than twelve quoted words carrying the subject. Part 1 can be re-run; part 3
can only be re-read, and separating them is what makes the index checkable.
**Commit the table before applying anything -- committing is claiming.**

**7. Apply, watching the cwd.**

    # cwd = ../another-world-archaeology
    python3 tools/apply_branch_scoped_names.py --stage <S> --branch <B> \
        --min-confidence medium --apply --proposals <abs path to table>
    # read the output for "applied": a cartridge run from the wrong cwd reverts silently
    # cwd = this repo
    python3 notes/unified-scoping/sync_equ_rename.py <table> <S> <B> --shared --apply
    python3 notes/cross-port-art/transfer_by_art.py --proposals > notes/play-and-describe/proposals_<other>__<S>_<tag>.md
    # then apply + sync that one too; carry by ART, never by the sentence
    # AND put `annot:<id>` into each carried row's evidence cell by hand, after
    # the canonical_md5 that carried it: `carried by canonical_md5 <hash> from
    # annot:<id>`. The generator writes a fixed evidence cell with no token, so
    # without this the second port's name -- which exists only because a person
    # described the picture -- is invisible to `grep -rn "annot:<id>" notes/`
    # and the queue's second hop never checks that it landed.
    python3 notes/unified-symbol-check/undefined_symbols.py
    make test
    make lint-naming-strict STAGE=<S>

**8. Close the annotation.**

Names landed — write nothing. The status is derived; confirm it:

    python3 notes/play-and-describe/annotation_queue.py --check   # exit 1 on inconsistency

and require NAMED, not PROPOSED. No names — record the verdict with grounds, so
nobody re-reads the sentence from scratch:

    python3 notes/play-and-describe/annotation_queue.py --verdict ann:<id> corroborates \
        --grounds "..."            # HELD additionally requires --settled-by "..."

**9. Commit as one batch**: table, `verdicts.tsv`, the tree change, and the log
if it grew. Any count quoted in the message comes from `--summary`.

**10. If a number moved, update `notes/HANDOFF.md` in the same commit.**

## What keeps the ear honest

`../render-and-name/` has a section on what keeps the eye honest, and the risk
there is believing a magnified thumbnail. The risk here is different: the
sentence is true and the agent extends it past what was seen. Three traps, each
with the measurement that exposes it.

**`routine_draws` is one frame's draws, not the routine's.** The debugger
builds the field from the draws of the frame that was on screen when the click
happened:

    $ sed -n '91,96p' tools/vm-debugger/static/app.js
      /** Every draw in the frame issued from the same routine as `d`. */
      function siblingsOf(d) {
        const r = routineAt(d.pc);
        return state.frame.draws
          .filter((o) => routineAt(o.pc) === r)
          .map((o) => ({ kind: o.kind, offset: o.offset, name: nameOf(o) }));
      }

A routine that draws one frame per `break` therefore contributes exactly one
entry. `ann:cff7052605ce` carries one constant; its routine draws five:

    $ sed -n '1145,1153p' src/levels/chahi_amiga_1991/INTRO.asm | grep -c video
      5

Treating `routine_draws` as the family would name a five-frame run from a
sample of one. It is a **pointer to the routine**, and the routine's static
draw list is read from the `.asm`.

**The prose may name an actor the anchor cannot confirm.** `../actor-anchors/`
measured this and declined to encode actor identity from anchors at all; its
probe reports 72 conflicts between a name's own actor word and the anchor it is
drawn at. A person who has played the game names the companion with complete
confidence and no access to `[BUDDY_X]`. The word is recorded in the evidence
cell; it enters the name only where that stage's earned names already use it at
that anchor.

**The sentence may be about the scene rather than the click.** The blink
confirms which polygons were selected, not which of them the writer was
thinking about, and a description of what is *happening* often belongs to
something else on screen -- which is why the entry carries `on_screen`. That is
what `REJECTED` is for, and its `grounds` records the offset the click should
have landed on, so the annotation ends up a pointer rather than a loss.

## The worked example, which produced no names and was still worth having

`ann:cff7052605ce` — chahi_amiga_1991/INTRO, frame 2062,
`CINEMATIC_STORM_PARTICLE_F01` (0xAEE2), drawn by
`STORM_AMBIENT_DRIFT_DRAW_LOOP`: *"resembles tumbleweed even though it is
probably something else ... strong wind blowing stuff such as dust ... rotating
and kicking in the floor ... light weight in order to float"*. `--measure` shows
the family complete — `F00..F04` at `INTRO.asm:376-380`, drawn one per iteration
at `x=[0x07], y=[0x09]` at `1145-1153` — so nothing is renamed. "Tumbleweed" is
not a name; the writer hedges it themself, and `notes/storm-particles/` earned
`STORM_PARTICLE` as the intersection of amiga's *ambient drift* and msdos's
*particle tumble*. Verdict CORROBORATES: a person who has never read the tree
agreeing with a name two ports' own labels disagreed about is the strongest
control this channel has produced, and it is worth exactly as much as the fact
that it changed nothing.

## What NAMED does not certify

NAMED means the tree defines the proposed name and no longer defines the old
one. It does **not** mean `apply_branch_scoped_names.py` is what put it there.
A rename moves no bytes, so nothing separates a gated apply from a `sed -i`, and
that is a real hole rather than a pedantic one: it is the only way a name from a
human sentence could reach `src/levels/**` with no validator and no collision
check behind it.

The obvious fix does not work here, and the measurement is worth recording so
nobody builds it twice. `notes/unified-scoping/applied_rows.tsv` is a 2173-row
journal of what was applied, and demanding a journal row for every NAMED looked
like the third hop. It is not: the journal is written by `sync_equ_rename.py`,
which step 7 needs only when the branch-scoped applier has not already reached
the unified tree, so a correctly-gated rename is routinely absent from it. The
two `CINEMATIC_PRISON_CAGE_*_TILT_ZERO` renames of 2026-09-23 went through the
applier and the byte gate and appear nowhere in the journal; separately, 48 of
its first 400 rows name constants the tree no longer defines, having been
renamed again since. A check built on it would cry wolf on the prescribed path
and stay silent on the hand-edit, which is worse than no check.

So this is held, and the cover is social rather than mechanical: the proposal
table is committed before the apply, the table is what review reads, and a name
in the tree with no table behind it is visible to `git log -S`. If a mechanical
third hop is ever wanted, the thing to build is a journal the **branch-scoped
applier itself** writes, not a reinterpretation of one written for another
purpose.

## What this is not

**Not a place for routine-label rows.** A table here may rename
`CINEMATIC_*` constants and nothing else, because
`apply_branch_scoped_names.py` admits nothing else in column one -- it will not
apply a label row, nor reject it, nor mention it. The agent sees a green apply,
finds the label untouched, and the obvious repair is a `sed -i`, which is
byte-neutral and therefore invisible to `make test`; the queue would then
report NAMED and `--check` would pass over a name that reached
`src/levels/**` with no applier, no validator and no collision check.
`--check` refuses such a row outright, and `tests/run.sh`'s `noapplier`
fixture holds it refused. Routine labels earned from a sentence go through
`apply_routine_renames.py` and its own gates, in their own table, outside this
directory.

**There is no `--proposals` mode, deliberately.** Every other probe in `notes/`
that offers one derives its rows from a measurement -- a rung threshold, a
`canonical_md5`, a bank stride -- and can be audited by re-running it. A table
generated from a sentence would wear the appearance of derivation while
carrying none of it, and `--min-confidence medium` reads the word in the
column, not the reasoning behind it. The tables here are written by hand, one
batch per file, and each row states its mechanical anchor before it quotes the
prose.

**It is not a rename path.** The debugger's rename box writes to
`rename_log.jsonl` and to nothing else. Names reach the tree through
`apply_branch_scoped_names.py`, behind which sit the family-gap rule, the
collision check, `undefined_symbols.py` and the byte gate. An annotation is
evidence; it is not an instruction to rename.
