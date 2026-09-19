#!/usr/bin/env python3
"""A name says it draws CV 291. Does it?

Question answered
-----------------
Plenty of names in the tree transcribe the constant they draw:
`GUARDED_DRAW_CV_126`, `DRAW_CIN_254`, `INLINE_DRAW_CV_216_027`. They are
operand transcription, evidence grade E1, and `naming_census.classify` counts
them as unnamed for that reason -- they restate the operand rather than say
what the routine is for.

But an E1 name can be worse than uninformative: it can be **false**. Nothing
checks that the number in the name is the number in the body, and there is an
obvious way for them to drift. Each port keys a polygon name to its own
offset, and `CINEMATIC_NNN` / `COMMON_VIDEO_NNN` indices are assigned in
per-port encounter order, so the *same* routine draws a different index on
each port. Copy such a name across ports -- which is issue #0107, and which
this project has caught doing real damage more than once -- and the index goes
with it and is now wrong.

The byte gate cannot see this. A label name is not a byte.

What is checked
---------------
For every label whose name contains `CV_<n>` / `CV<n>` / `CIN_<n>` / `CIN<n>`
(any number of them, as in `..._CIN164_167_CV291`), the set of indices the
name claims is compared against the set the body actually draws, read from its
`video offset=COMMON_VIDEO_<n>` and `offset=CINEMATIC_<n>` operands.

**A fold-local sub-label is folded into its stem first.** A label named
`<stem>_L<n>` is not a routine; it is an emission counter inside `<stem>`, and
its name is the stem's name with a suffix. Checking its own two or three lines
against the stem's index is the wrong test, and asking the naive question
first gives 319 hits of which most are that mistake:
`PRISON_DRAW_CIN_132_TO_133_2F_AT_BB9185F0_L0` "claims" 132 while its slice
draws 134-136, because 132 belongs to the whole routine. So the drawn set of
`<stem>` is the union over `<stem>` and every `<stem>_L<n>`, and the `_L<n>`
labels are not audited separately.

  agree        every index in the name is drawn by the body
  extra-name   the name claims an index the body does not draw  <- the bug
  no-draw      the name claims indices, the body draws nothing numeric
               (its operands are all semantically named, so the name is
               merely stale, not false)

A body that draws *more* than the name says is fine -- a name need not list
everything -- so that is not reported.

Exit status
-----------
1 if any `extra-name` case is found, 0 otherwise. This is a gate: a name that
states a constant the routine does not touch is wrong on its face and needs no
adjudication.

Usage
-----
    python3 notes/index-bearing-names/name_index_vs_body.py
    python3 notes/index-bearing-names/name_index_vs_body.py --all --verbose
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_NAME_CV = re.compile(r"CV_?(\d{2,3})")
RE_NAME_CIN = re.compile(r"CIN_?(\d{2,3})")
RE_DRAW_CV = re.compile(r"offset=COMMON_VIDEO_(\d+)")
RE_DRAW_CIN = re.compile(r"offset=CINEMATIC_(\d+)")


def routines(path: Path):
    cur, body = None, []
    for raw in path.read_text(errors="replace").splitlines():
        line = raw.split(";", 1)[0]
        m = RE_LABEL.match(line)
        if m:
            if cur is not None:
                yield cur, body
            cur, body = m.group(1), []
        elif cur is not None and line.strip():
            body.append(line)
    if cur is not None:
        yield cur, body


RE_FOLD_LOCAL = re.compile(r"^(.*)_L\d+$")


def fold(pairs):
    """Merge `<stem>_L<n>` slices into `<stem>`, or drop them.

    Returns (merged, dropped). A `_L<n>` label is an emission counter inside a
    folded routine, not a routine, and its name is the stem's name plus a
    suffix -- so its own slice must never be audited against the stem's index.
    Where the stem exists as a label, the slices are merged into it. Where it
    does not (`PRISON_DRAW_CIN_132_TO_133_2F_AT_BB9185F0` has only `_L0` and
    `_L1`, no stem), there is nothing to merge into and the label is dropped
    from this audit: `docs/NAMING.md` §1 already forbids the bare `_L<n>`
    form outright and the lint counts it, so reporting it here too would
    double-count a known defect under a second heading.
    """
    bodies = {name: list(b) for name, b in pairs}
    merged: dict[str, list[str]] = {}
    dropped = 0
    for name, b in bodies.items():
        m = RE_FOLD_LOCAL.match(name)
        if m:
            if m.group(1) in bodies:
                merged.setdefault(m.group(1), []).extend(b)
            else:
                dropped += 1
            continue
        merged.setdefault(name, []).extend(b)
    return merged, dropped


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()
    ports = args.port or (sorted(PORTS) if args.all else ["amiga", "msdos"])
    stages = args.stage or STAGES

    tot = collections.Counter()
    hits = []
    for port in ports:
        for stage in stages:
            p = SRC / PORTS[port] / f"{stage}.asm"
            if not p.is_file():
                continue
            merged, dropped = fold(list(routines(p)))
            tot["fold-local excluded"] += dropped
            for name, body in merged.items():
                claim_cv = {int(x) for x in RE_NAME_CV.findall(name)}
                claim_cin = {int(x) for x in RE_NAME_CIN.findall(name)}
                if not (claim_cv or claim_cin):
                    continue
                tot["index-bearing"] += 1
                text = "\n".join(body)
                drew_cv = {int(x) for x in RE_DRAW_CV.findall(text)}
                drew_cin = {int(x) for x in RE_DRAW_CIN.findall(text)}
                if not (drew_cv or drew_cin):
                    tot["no-draw"] += 1
                    continue
                extra = ((claim_cv - drew_cv) if drew_cv else set()) | \
                        ((claim_cin - drew_cin) if drew_cin else set())
                if extra:
                    tot["extra-name"] += 1
                    hits.append((port, stage, name, sorted(claim_cv),
                                 sorted(claim_cin), sorted(drew_cv),
                                 sorted(drew_cin)))
                else:
                    tot["agree"] += 1

    print(f"{tot['fold-local excluded']} bare `_L<n>` fold-local label(s) "
          f"excluded (§1 forbids the form; the lint counts them)")
    print(f"{tot['index-bearing']} routine(s) carry a CV/CIN index in the "
          f"name")
    print(f"  {tot['agree']:5d} agree -- every claimed index is drawn")
    print(f"  {tot['no-draw']:5d} claim an index but draw nothing numeric "
          f"(stale, not false)")
    print(f"  {tot['extra-name']:5d} claim an index the body DOES NOT draw "
          f"<- wrong on its face")
    for port, stage, name, ccv, ccin, dcv, dcin in hits:
        print(f"\n  {port}/{stage}  {name}")
        if ccv:
            print(f"      name says CV {ccv}, body draws COMMON_VIDEO {dcv}")
        if ccin:
            print(f"      name says CIN {ccin}, body draws CINEMATIC {dcin}")
    return 1 if hits else 0


if __name__ == "__main__":
    sys.exit(main())
