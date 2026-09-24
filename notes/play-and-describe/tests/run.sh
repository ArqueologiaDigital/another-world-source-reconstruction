#!/bin/sh
# Does --check actually fail on each way the bookkeeping can break, and is an
# id stable under append?
#
# `--check` is the whole idempotency guarantee of this directory. It is the only
# thing that can see a proposal row citing a sentence that no longer exists, or
# a row that was written and never applied, and the queue's statuses are derived
# from the same two hops it walks. A guarantee asserted by the program that
# provides it is worth nothing, so every way the bookkeeping is known to break
# is built here as a fixture and fed to the probe, and what passes is the exit
# code *and* the id in the message -- a check that fails without naming the
# offending line sends the next agent reading all of `notes/` by hand.
#
# Each case builds a whole small repository under fixtures/<case>/ -- log,
# verdicts, one proposal table, one `.asm` -- and runs the probe against it with
# `--root`. The fixtures are `git init`-ed and committed because step 0 of the
# procedure refuses to derive consumption from a log with uncommitted lines;
# sealing them means a case measures the check and not the harness. They are
# rebuilt from scratch on every run and deleted at exit: this script is the
# record of them. KEEP=1 leaves them in place to be read.
#
#     sh notes/play-and-describe/tests/run.sh              # the committed probe
#     sh notes/play-and-describe/tests/run.sh <other.py>   # a candidate probe
#
# What it is NOT: it asserts nothing about whether any name is right. A rename
# moves no bytes and nothing in this repository can check a name mechanically --
# that is why this directory exists at all. Every fixture name below is
# deliberately fictional. What is asserted is narrower and is the only thing
# that can be: that an annotation's state is READ OUT OF the log, the tables and
# the tree on every run, and that each way that reading can be contradicted is
# an error with an id attached rather than a silence.
set -e

here=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
queue=${1:-$here/../annotation_queue.py}
fix=$here/fixtures
repo=$here/../../..
pass=0
fail=0

[ -f "$queue" ] || { echo "no probe at $queue -- pass one as \$1"; exit 2; }
trap '[ -n "$KEEP" ] || rm -rf "$fix"' EXIT

# ---- the id, computed the way the README says an agent computes it ----------
# `ann:` + the first twelve hex of the sha1 of the raw line, newline stripped.
# Deliberately the documented shell pipeline and not a call into the probe: a
# harness that asked the probe for the id could not catch the probe changing it.
aid() {                                  # aid <file> <line number>
    sed -n "${2}p" "$1" | tr -d '\n' | sha1sum | cut -c1-12
}

root() {                                 # root <case> -> path to a fresh tree
    rm -rf "$fix/$1"
    mkdir -p "$fix/$1/tools/vm-debugger" "$fix/$1/notes/play-and-describe" \
             "$fix/$1/src/levels/chahi_amiga_1991"
    echo "$fix/$1"
}

seal() {                                 # seal <root>: make the log committed
    git -C "$1" init -q
    git -C "$1" add -A
    git -C "$1" -c user.email=fixtures@localhost -c user.name=fixtures \
        commit -qm "fixture: $(basename "$1")"
}

# ---- the log lines ---------------------------------------------------------
# Shaped like what server.py appends (see its `annotate` handler): one JSON
# object per line, kind/at/branch/stage/frame/target/routine/routine_draws/
# on_screen/text. Abridged -- on_screen is emptied and the prose is one clause
# -- because an id is the sha1 of whatever the line is, so a fixture needs the
# fields the probe reads, not the ones the browser sent.
storm() {                                # storm <subject word>
    printf '{"at": "2026-09-23T20:24:19+0100", "kind": "annotate", "branch": "chahi_amiga_1991", "stage": "INTRO", "frame": 2062, "target": {"kind": "cinematic", "offset": 44770, "name": "CINEMATIC_STORM_PARTICLE_F01", "thread": 16, "pc": 1275, "zoom": 64, "x": 217, "y": 130}, "routine": "STORM_AMBIENT_DRIFT_DRAW_LOOP", "routine_draws": [{"kind": "cinematic", "offset": 44770, "name": "CINEMATIC_STORM_PARTICLE_F01"}], "on_screen": [], "text": "resembles %s blown by a night storm, rotating and kicking in the floor", "pattern": null, "replacement": null, "renames": []}\n' "$1"
}

column() {                               # the second sentence: a CAVES target
    printf '{"at": "2026-09-23T20:31:02+0100", "kind": "annotate", "branch": "chahi_amiga_1991", "stage": "CAVES", "frame": 118, "target": {"kind": "cinematic", "offset": 31589, "name": "CINEMATIC_412", "thread": 3, "pc": 2044, "zoom": 64, "x": 136, "y": 165}, "routine": "CAVES_TRAP_COLUMN_DRAW_LOOP", "routine_draws": [{"kind": "cinematic", "offset": 31589, "name": "CINEMATIC_412"}], "on_screen": [], "text": "a column drops from the ceiling and crushes whatever is under it", "pattern": null, "replacement": null, "renames": []}\n'
}

bulk() {                                 # a name typed into the box, breaking NAMING.md
    printf '{"at": "2026-09-23T20:33:40+0100", "kind": "bulk_rename", "branch": "chahi_amiga_1991", "stage": "CAVES", "frame": 118, "target": {"kind": "cinematic", "offset": 31589, "name": "CINEMATIC_412", "thread": 3, "pc": 2044, "zoom": 64, "x": 136, "y": 165}, "routine": "CAVES_TRAP_COLUMN_DRAW_LOOP", "routine_draws": [], "on_screen": [], "text": "", "pattern": "CINEMATIC_412", "replacement": "CAVES_COLUMN_AT_136_165", "renames": [{"old": "CINEMATIC_412", "new": "CAVES_COLUMN_AT_136_165"}]}\n'
}

# ---- the other three things --check reads ----------------------------------
verdicts() {                             # verdicts <root>; rows on stdin
    { printf '# Annotations that produced no name, and why.\n'
      printf '# id\tat\tbranch/stage\toffset\tverdict\tgrounds\tsettled_by\n'
      cat; } > "$1/notes/play-and-describe/verdicts.tsv"
}

table() {                                # table <root> <id> <tag>
    { printf '# CAVES: the trap columns, described at the screen\n\n'
      printf '`ann:%s` -- "a column drops from the ceiling and crushes\n' "$2"
      printf 'whatever is under it", chahi_amiga_1991/CAVES frame 118.\n\n'
      printf '| old | new | confidence | evidence |\n'
      printf '|---|---|---|---|\n'
      printf '| CINEMATIC_412 | CINEMATIC_CAVES_TRAP_COLUMN_F00 | medium | 0x7B65, first of the run drawn at `x=[0x07], y=[0x09]`; annot:%s frame 118 `CAVES_TRAP_COLUMN_DRAW_LOOP`; "a column drops from the ceiling" |\n' "$2"
    } > "$1/notes/play-and-describe/proposals_chahi_amiga_1991__CAVES_$3.md"
}

asm() {                                  # asm <root> <defined|undefined>
    { printf 'CINEMATIC_411\t\tEQU 0x7B52\n'
      [ "$2" = defined ] \
        && printf 'CINEMATIC_CAVES_TRAP_COLUMN_F00\t\tEQU 0x7B65\n' \
        || printf 'CINEMATIC_412\t\tEQU 0x7B65\n'
      printf 'CINEMATIC_413\t\tEQU 0x7B78\n'
    } > "$1/src/levels/chahi_amiga_1991/CAVES.asm"
}

# ---- assertions ------------------------------------------------------------
# `out` and `rc` are what the last probe run produced; sh has no locals, and
# naming them once beats threading them through every case.
probe() {                                # probe <root> [args...]
    r=$1; shift
    out=$(python3 "$queue" --root "$r" "$@" 2>&1) && rc=0 || rc=$?
}

expect() {                               # expect <case> <want rc> <needle...>
    name=$1; want=$2; shift 2
    why=
    [ "$rc" = "$want" ] || why="exit $rc, wanted $want"
    for n in "$@"; do
        case $out in *"$n"*) ;; *) why="$why; does not name '$n'" ;; esac
    done
    verdict "$name" "$why"
}

verdict() {                              # verdict <case> <why, empty = pass>
    if [ -z "$2" ]; then
        pass=$((pass + 1)); echo "PASS  $1"
    else
        fail=$((fail + 1)); echo "FAIL  $1: ${2#; }"
        printf '%s\n' "$out" | sed 's/^/        | /'
    fi
}

# ---------------------------------------------------------------------------
# clean -- the storm entry and the CORROBORATES row it actually earned.
# The control. Everything below is this tree with one thing broken, so a
# failure here means the fixtures are wrong and not that the probe is.
r=$(root clean)
storm tumbleweed > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:24:19+0100	chahi_amiga_1991/INTRO	0xAEE2	CORROBORATES	the family F00..F04 is already complete; ../storm-particles/ earned the subject word from two ports' own labels	
EOF
seal "$r"
probe "$r" --check
expect clean 0

# orphan -- a verdict for an id no line in the log yields. The shape a hand
# edit of verdicts.tsv leaves, and the one thing in the mechanism nothing
# else can catch, since a verdict is the only hand-written state there is.
r=$(root orphan)
storm tumbleweed > "$r/tools/vm-debugger/rename_log.jsonl"
verdicts "$r" <<'EOF'
ann:0123456789ab	2026-09-23T20:24:19+0100	chahi_amiga_1991/INTRO	0xAEE2	NO_NAME	an id that was never in the log	
EOF
seal "$r"
probe "$r" --check
expect orphan 1 0123456789ab

# edited -- one word of a cited line changed: "tumbleweed" -> "sagebrush".
# The cost the README puts on the id being content-derived, made visible. The
# table's name IS defined in the tree, so the only thing wrong is the citation,
# and the sentence it quoted is gone -- which is exactly why the log is
# append-only. The new id must appear as OPEN: unedited work, nobody's yet.
r=$(root edited)
storm sagebrush > "$r/tools/vm-debugger/rename_log.jsonl"
column >> "$r/tools/vm-debugger/rename_log.jsonl"
was=$(storm tumbleweed | tr -d '\n' | sha1sum | cut -c1-12)
now=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
table "$r" "$was" trap_columns
asm "$r" defined
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
expect edited 1 "$was"
probe "$r" --all
case $out in
    *"$now"*) printf '%s\n' "$out" | grep -Eq "($now.*OPEN|OPEN.*$now)" \
                  && verdict "edited/OPEN" "" \
                  || verdict "edited/OPEN" "the re-typed line is not OPEN" ;;
    *) verdict "edited/OPEN" "the queue does not list $now at all" ;;
esac

# proposed -- a table cites a live id and the tree does not define the name it
# proposes. A rejected row, or a batch applied from the wrong cwd: the
# cartridge no-op prints "N proposed, 0 rejected" and reverts everything, and
# reading the tree instead of that stdout is the only reason this is visible.
r=$(root proposed)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
table "$r" "$a" trap_columns
asm "$r" undefined
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
expect proposed 1 "$a" PROPOSED

# both -- one id carrying a verdict and a citation. Mutually exclusive: the
# verdict says the sentence yielded no name while a row rests on it for one,
# and whichever is stale, the id is claimed twice and the next agent cannot
# tell which claim to believe.
r=$(root both)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
table "$r" "$a" trap_columns
asm "$r" defined
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:31:02+0100	chahi_amiga_1991/CAVES	0x7B65	NO_NAME	narrative, not a subject	
EOF
seal "$r"
probe "$r" --check
expect both 1 "$a"

# held -- a HELD row with an empty settled_by. HELD without what would settle
# it is indistinguishable from an abandonment, and notes/HANDOFF.md's "Held,
# with what would settle each" is the standing form it has to feed.
r=$(root held)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:31:02+0100	chahi_amiga_1991/CAVES	0x7B65	HELD	the column may be shared with another screen	
EOF
seal "$r"
probe "$r" --check
expect held 1 "$a"

# forbidden -- a bulk_rename typing CAVES_COLUMN_AT_136_165, which is the
# click's own x,y. Not a bookkeeping break, so exit 0: the entry is admissible
# evidence and queued like any other. But the name embeds screen coordinates,
# which docs/NAMING.md forbids and which grouped a hero, a gunman and a beam
# under one family in notes/lake-shooting/ -- so the queue has to say so where
# it is read, not leave it to be caught by the lint after the table is written.
r=$(root forbidden)
bulk > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
expect forbidden/check 0
probe "$r" --all
expect forbidden/flag 0 "$a" NAMING

# stable -- appending a second sentence does not move the first's id. The
# property the whole scheme rests on: a line ordinal would have survived this
# too, but not the reordering the README rejects it for, and every citation
# already written stays pointing at the same sentence.
r=$(root stable)
storm tumbleweed > "$r/tools/vm-debugger/rename_log.jsonl"
before=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
column >> "$r/tools/vm-debugger/rename_log.jsonl"
after=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
second=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 2)
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
out="first $before, after the append $after, second line $second"
[ "$before" = "$after" ] && [ "$before" != "$second" ] && [ "$rc" = 0 ] \
    && verdict stable "" \
    || verdict stable "id moved under append, or --check exit $rc"

# ---------------------------------------------------------------------------
# The five cases below were written from an adversarial review of this
# mechanism on 2026-09-23. Each one is a way the bookkeeping was measured to
# break silently -- reporting success while losing a sentence -- so each one
# is a fixture before it is a fix.

# missing -- no log at all. The failure this catches is the nastiest of the
# set, because it is invisible: zero pending out of no log and zero pending out
# of a finished queue printed the same string, so "I am not reading the
# evidence" looked exactly like "there is no work to do".
r=$(root missing)
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
expect missing 1 "does not exist" "not an empty queue"
probe "$r"
expect missing/queue 0 "not found" "NOT an empty queue"

# denominator -- a log that exists and is fully consumed must say so WITH the
# count it was computed from. A bare zero is what made `missing` invisible.
r=$(root denominator)
storm tumbleweed > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:24:19+0100	chahi_amiga_1991/INTRO	0xAEE2	NO_NAME	the family is already complete	
EOF
seal "$r"
probe "$r"
expect denominator 0 "1 annotation(s), all consumed"

# collision -- the applier REJECTED the row, because the stage already uses
# that name for a polygon at another offset. The rejected row left the old
# name in place. Asking only "is the new name defined?" reads this as done and
# drops the sentence off the queue with no trace, which is exactly the class
# PROPOSED exists to catch.
r=$(root collision)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" </dev/null
table "$r" "$a" collide
{ printf 'CINEMATIC_411\t\tEQU 0x7B52\n'
  printf 'CINEMATIC_412\t\tEQU 0x7B65\n'
  printf 'CINEMATIC_CAVES_TRAP_COLUMN_F00\t\tEQU 0x9999\n'
} > "$r/src/levels/chahi_amiga_1991/CAVES.asm"
seal "$r"
probe "$r" --check
expect collision 1 "ann:$a" PROPOSED
probe "$r" --all
expect collision/queue 0 PROPOSED

# dupline -- one sentence logged twice, byte for byte: a double-clicked Save
# inside the `at` field's one-second resolution. Two identical lines yield one
# id twice, and calling that a hash collision gives advice nobody can follow,
# since the only remedy would be deleting a line and the log is append-only.
r=$(root dupline)
storm tumbleweed > "$r/tools/vm-debugger/rename_log.jsonl"
storm tumbleweed >> "$r/tools/vm-debugger/rename_log.jsonl"
verdicts "$r" </dev/null
seal "$r"
probe "$r" --check
expect dupline 1 "SAME line" "server-side"

# noapplier -- a row whose column one is a routine label. Nothing applies it:
# apply_branch_scoped_names.py admits only CINEMATIC_*, so the row is neither
# applied nor rejected nor mentioned, and the tempting repair is a byte-neutral
# `sed -i` that `make test` cannot see. A name from a human sentence would then
# reach src/levels/ with no applier, no validator and no collision check.
r=$(root noapplier)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" </dev/null
{ printf '# CAVES: the trap columns\n\n'
  printf '| old | new | confidence | evidence |\n'
  printf '|---|---|---|---|\n'
  printf '| CAVES_TRAP_COLUMN_DRAW_LOOP | CAVES_CEILING_TRAP_DRAW_LOOP | medium | annot:%s frame 118 |\n' "$a"
} > "$r/notes/play-and-describe/proposals_chahi_amiga_1991__CAVES_label.md"
asm "$r" undefined
seal "$r"
probe "$r" --check
expect noapplier 1 "not a CINEMATIC_* constant" "its own applier"

# conflict -- an id carrying BOTH a written verdict and a live proposal row.
# Reporting the verdict hides the unapplied row from the queue and from
# --summary, which is what HANDOFF quotes, so only --check ever saw it.
r=$(root conflict)
column > "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:31:02+0100	chahi_amiga_1991/CAVES	0x7B65	NO_NAME	the family is already complete	
EOF
table "$r" "$a" both2
asm "$r" undefined
seal "$r"
probe "$r" --all
expect conflict 0 CONFLICT
probe "$r" --check
expect conflict/check 1 "BOTH"

# amended -- a second sentence about a target already ruled on. The status must
# name the earlier id AND its outcome, which is what the README promises;
# without it the agent has to hunt the first annotation by hand. The
# representative is also the place an unsorted set iteration made the output
# depend on PYTHONHASHSEED, so this case is run twice under different seeds.
r=$(root amended)
column > "$r/tools/vm-debugger/rename_log.jsonl"
printf '{"at": "2026-09-23T21:02:11+0100", "kind": "annotate", "branch": "chahi_amiga_1991", "stage": "CAVES", "frame": 140, "target": {"kind": "cinematic", "offset": 31589, "name": "CINEMATIC_412"}, "routine": "CAVES_TRAP_COLUMN_DRAW_LOOP", "routine_draws": [], "on_screen": [], "text": "it crushes whatever is under it", "pattern": null, "replacement": null, "renames": []}\n' \
    >> "$r/tools/vm-debugger/rename_log.jsonl"
a=$(aid "$r/tools/vm-debugger/rename_log.jsonl" 1)
verdicts "$r" <<EOF
ann:$a	2026-09-23T20:31:02+0100	chahi_amiga_1991/CAVES	0x7B65	NO_NAME	the family is already complete	
EOF
asm "$r" undefined
seal "$r"
probe "$r" --all
expect amended 0 "AMENDED($a,NO_NAME)"
out=$(PYTHONHASHSEED=1 python3 "$queue" --root "$r" --all 2>&1; \
      PYTHONHASHSEED=9 python3 "$queue" --root "$r" --all 2>&1) && rc=0 || rc=$?
n=$(printf '%s\n' "$out" | grep -c "AMENDED($a,NO_NAME)")
[ "$n" = 2 ] && verdict amended/seeded "" \
    || verdict amended/seeded "the representative moved with PYTHONHASHSEED"

# teaser -- the queue line must not cut a sentence before its subject arrives.
# An annotation reading "i dont understand why, but this seems to be the
# bounding box of lester's body" was ruled REJECTED on the strength of a line
# truncated at that comma. The procedure says to --measure before believing the
# queue, and it still does; a teaser that REVERSES a sentence's meaning is a
# trap rather than a teaser.
r=$(root teaser)
printf '{"at": "2026-09-25T00:00:00+0100", "kind": "annotate", "branch": "chahi_amiga_1991", "stage": "CAVES", "frame": 6924, "target": {"kind": "cinematic", "offset": 31589, "name": "CINEMATIC_412"}, "routine": "R", "routine_draws": [], "on_screen": [], "text": "i dont understand why, but this seems to be the bounding box of the lift car", "pattern": null, "replacement": null, "renames": []}\n' \
    > "$r/tools/vm-debugger/rename_log.jsonl"
verdicts "$r" </dev/null
asm "$r" undefined
seal "$r"
probe "$r" --all
expect teaser 0 "bounding box"
case $out in
    *"i dont understand why\""*) verdict teaser/cut "the line stops at the comma" ;;
    *) verdict teaser/cut "" ;;
esac

# documented -- the id notes/play-and-describe/README.md and this repo's
# CLAUDE.md both quote, recomputed from the log the debugger actually wrote.
# Not a fixture: it is the assertion that the log in the tree has not been
# rewritten under the citations that already point into it. Skipped before the
# first play session, when there is no log to read.
log=$repo/tools/vm-debugger/rename_log.jsonl
if [ -s "$log" ]; then
    got=$(aid "$log" 1)
    out="line 1 of $log hashes to ann:$got"
    [ "$got" = cff7052605ce ] && verdict documented "" \
        || verdict documented "the storm entry is ann:cff7052605ce, got ann:$got"
else
    echo "SKIP  documented: no $log yet"
fi

echo
if [ "$fail" = 0 ]; then
    echo "PASS: $pass cases"
else
    echo "FAIL: $fail of $((pass + fail)) cases"
    exit 1
fi
