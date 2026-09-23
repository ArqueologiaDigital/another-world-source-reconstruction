#!/bin/sh
# Does run.sh actually notice when the probe stops working?
#
# run.sh passing proves nothing on its own: a suite whose fixtures are wrong
# passes against anything, and this directory's whole idempotency claim rests on
# `--check`. So break `annotation_queue.py` on purpose, one attribute at a time,
# and require run.sh to fail the cases that fault touches. The faults are the
# five ways the mechanism could be quietly hollowed out and still look right:
#
#   exit0   --check prints every problem and exits 0 anyway
#   mute    --check fails without naming the offending id
#   trust   hop two skipped: a cited name is believed rather than read out of
#           `src/levels/<branch>/<STAGE>.asm` -- the cartridge silent no-op
#   noflag  no NAMING.md flag on a name typed into the rename box
#   ident   the rejected id scheme (sha256 over canonicalised JSON) instead of
#           sha1 over the raw line
#
# Injection is by attribute, not by patching source text: the probe is imported
# and one name rebound, so this keeps working while the probe is edited, and
# says so loudly if a name it reaches for has gone.
#
#     sh notes/play-and-describe/tests/mutants.sh
#
# It is NOT a second test of the bookkeeping -- every assertion here is about
# run.sh. Cases are asserted as a subset: a fault may well break more than the
# cases named for it, and that is not a defect in either script.
set -e

here=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
queue=${1:-$here/../annotation_queue.py}
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
bad=0

[ -f "$queue" ] || { echo "no probe at $queue -- pass one as \$1"; exit 2; }

cat > "$tmp/mutant.py" <<'PY'
"""annotation_queue.py with one fault injected, named by $MUTANT.

Imported rather than copied, so the fault is one rebound attribute and the rest
is the probe as committed. Only used by tests/mutants.sh.
"""
import contextlib, hashlib, importlib.util, io, json, os, sys

spec = importlib.util.spec_from_file_location("q", os.environ["QUEUE"])
q = importlib.util.module_from_spec(spec)
spec.loader.exec_module(q)                 # __name__ is "q", so main() is not run
fault = os.environ["MUTANT"]

if fault == "exit0":
    inner = q.check
    q.check = lambda ix: (inner(ix), 0)[1]
elif fault == "mute":
    inner = q.check
    def check(ix):
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            rc = inner(ix)
        print("the bookkeeping is inconsistent" if rc else buf.getvalue())
        return rc
    q.check = check
elif fault == "trust":
    q.Asm.defines = lambda self, *a, **k: True
elif fault == "noflag":
    q.FORBIDDEN = []
elif fault == "ident":
    q.aid = lambda line: "ann:" + hashlib.sha256(
        json.dumps(json.loads(line), sort_keys=True).encode()).hexdigest()[:12]
else:
    sys.exit(f"unknown fault {fault!r}")
sys.exit(q.main())
PY

# baseline: unmutated, every case has to pass, or nothing below means anything
if out=$(sh "$here/run.sh" "$queue" 2>&1); then
    echo "PASS  baseline: $(printf '%s' "$out" | sed -n 's/^PASS: //p')"
else
    echo "FAIL  baseline: run.sh does not pass the probe as committed"
    printf '%s\n' "$out" | sed 's/^/        | /'
    exit 1
fi

fault() {                                # fault <name> <case that must fail>...
    name=$1; shift
    MUTANT=$name QUEUE=$queue sh "$here/run.sh" "$tmp/mutant.py" > "$tmp/out" 2>&1 \
        && { echo "FAIL  $name: run.sh still passes a probe broken this way"
             bad=$((bad + 1)); return 0; }
    grep -q "Traceback" "$tmp/out" && {
        echo "FAIL  $name: the injection itself broke -- an attribute it rebinds has moved"
        sed 's/^/        | /' "$tmp/out"; bad=$((bad + 1)); return 0; }
    miss=
    for c in "$@"; do
        grep -q "^FAIL  $c:" "$tmp/out" || miss="$miss $c"
    done
    n=$(grep -c '^FAIL  ' "$tmp/out")
    if [ -z "$miss" ]; then
        echo "PASS  $name: $n case(s) fail, including$(printf ' %s' "$@")"
    else
        echo "FAIL  $name: survives$miss"
        sed -n 's/^\(FAIL  \|PASS: \|FAIL: \)/        | \1/p' "$tmp/out"
        bad=$((bad + 1))
    fi
}

fault exit0  orphan edited proposed both held
fault mute   orphan edited proposed both held
fault trust  proposed
fault noflag forbidden/flag
fault ident  clean

echo
if [ "$bad" = 0 ]; then
    echo "PASS: 5 faults, each caught"
else
    echo "FAIL: $bad of 5 faults survive run.sh"
    exit 1
fi
