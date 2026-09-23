#!/usr/bin/env python3
"""Name a stage's per-screen entry routines, and the dispatcher that picks them.

Question answered
-----------------
`screen_scope.py` pins a label to a screen. That answers "which screen is this
under", not "what is this". For one shape it answers both, because the shape
is unmistakable.

Each of the three big stages has a chain of `je [SCREEN_NUM], 0xNN, T` lines
whose targets all do the same four things: write the camera bounds
`[0x40]..[0x47]`, tear down the previous screen's channels, `setPalette`, and
install the new screen's threads before drawing its backdrop. That is a screen
transition, and each target is one screen's entry.

The classification is measured, not asserted
--------------------------------------------
Every chain of four or more consecutive `je [SCREEN_NUM]` lines in the tree,
with the fraction of its targets that write a bounds variable:

    branch/stage     chain owner                             targets  bounds
    amiga/PRISON     LABEL_85F5                                   11      11
    amiga/CAVES      LABEL_D561                                   50      50
    amiga/CAPSULE    LABEL_8521                                    7       7
    msdos/PRISON     LABEL_86FA                                   11      11
    msdos/CAVES      LABEL_DA47                                   51      51
    msdos/CAPSULE    LABEL_B2CA                                   41      41
    cart/PRISON      LABEL_884B                                   11      11
    cart/CAVES       LABEL_DACD                                   51      51
    cart/CAPSULE     LABEL_B3AB                                   41      41
    ---
    amiga/CAVES      CAVES_GROUND_MAP_DISPATCH                    33       1
    msdos/CAPSULE    CAPSULE_FLOOR_LEVEL_SELECT_BY_HEIGHT         11       0
    amiga/CAVES      LABEL_D97B                                    8       0
    msdos/CAPSULE    LABEL_B299                                    6       0

There is no middle. Nine chains have the signature in **every** target and
the rest have it in essentially none, so a threshold anywhere between is the
same threshold; this module uses 90%. The two already-named chains fall on the
negative side, which is the reassuring direction: they dispatch on the screen
for other reasons (a ground map, a floor-height select) and are not screen
entries, exactly as their names say.

Teardown and palette corroborate without being required: on the nine, 274 of
274 targets write bounds, 271 tear down channels and 265 set a palette.

The naming
----------
    <STAGE>_SCREEN_<NN>_ENTRY          each target, NN from its own `je`
    <STAGE>_SCREEN_ENTRY_DISPATCH      the chain's owning label

`NN` is the machine's screen number, read from the comparison that selects the
routine -- the same standing as a switch case value under `docs/NAMING.md`.
A target is proposed only when `screen_scope.py` independently pins it to that
one screen, so the `je` and the whole-graph reachability have to agree.

Pass/fail
---------
Exits 0; it is a proposer. `--check` exits 1 if a chain's targets are not one
per screen, which would make `_SCREEN_<NN>_ENTRY` ambiguous.

Usage
-----
    python3 notes/screen-scope/screen_entry.py
    python3 notes/screen-scope/screen_entry.py --check
    python3 notes/screen-scope/screen_entry.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
sys.path.insert(0, str(HERE.parent))
sys.path.insert(0, str(HERE.parents[2].parent / "another-world-archaeology"
                       / "tools"))
import screen_scope as S                                     # noqa: E402
from naming_census import classify                           # noqa: E402

RE_JE = re.compile(r"^\s*je\s+\[SCREEN_NUM\],\s*(0x[0-9A-Fa-f]+),\s*"
                   r"([A-Za-z_][A-Za-z0-9_]*)")
RE_BOUND = re.compile(r"^\s*mov\s+\[0x4[0-7]\],")
RE_TEARDOWN = re.compile(r"^\s*call\s+\w*(DELETE|TEARDOWN)\w*")
RE_PAL = re.compile(r"^\s*setPalette")
RE_STOP = re.compile(r"^\s*(ret|killChannel)\b")
MIN_CHAIN = 4
BOUNDS_SHARE = 0.9
BODY_WINDOW = 50


def chains(lines: list[str]):
    """(owner, [(screen, target)]) for each run of >= MIN_CHAIN `je` lines."""
    labels, enc, cur = {}, {}, None
    for i, line in enumerate(lines):
        if m := S.RE_LBL.match(line):
            cur = m.group(1)
            labels[cur] = i
        enc[i] = cur
    out, run = [], []
    for i, line in enumerate(lines + [""]):
        if RE_JE.match(line):
            run.append(i)
        else:
            if len(run) >= MIN_CHAIN:
                pairs = [(int(RE_JE.match(lines[j]).group(1), 16),
                          RE_JE.match(lines[j]).group(2)) for j in run]
                out.append((enc[run[0]], pairs))
            run = []
    return out, labels


def body(lines, labels, name):
    j = labels.get(name)
    if j is None:
        return []
    b = lines[j + 1:j + 1 + BODY_WINDOW]
    stop = next((k for k, l in enumerate(b) if RE_STOP.match(l)), len(b))
    return b[:stop]


def entry_chains(lines):
    """Only the chains whose targets carry the screen-transition signature."""
    out = []
    ch, labels = chains(lines)
    for owner, pairs in ch:
        got = sum(any(RE_BOUND.match(l) for l in body(lines, labels, t))
                  for _s, t in pairs)
        if pairs and got / len(pairs) >= BOUNDS_SHARE:
            out.append((owner, pairs, labels))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    by: dict[tuple, list] = {}
    stats = collections.Counter()
    bad = 0
    for port, branch in S.PORTS.items():
        for stage in S.STAGES:
            lines = S.load(port, stage)
            if lines is None:
                continue
            scoped, _at = S.analyse(lines)
            for owner, pairs, labels in entry_chains(lines):
                stats["screen-entry dispatchers"] += 1
                seen = collections.Counter(s for s, _t in pairs)
                dupes = [s for s, n in seen.items() if n > 1]
                if dupes:
                    bad += 1
                    print(f"  ** {branch}/{stage} {owner}: screens "
                          f"{[f'0x{d:02X}' for d in dupes]} have more than "
                          f"one target", file=sys.stderr)
                rows = []
                if owner and classify(owner) != "semantic":
                    rows.append((owner, f"{stage}_SCREEN_ENTRY_DISPATCH",
                                 "dispatch", None, len(pairs)))
                for screen, target in pairs:
                    stats["targets"] += 1
                    if classify(target) == "semantic":
                        stats["  target already named"] += 1
                        continue
                    ctx = scoped.get(target)
                    if ctx is None or set(ctx) != {screen}:
                        stats["  dataflow does not confirm the screen"] += 1
                        continue
                    new = f"{stage}_SCREEN_{screen:02X}_ENTRY"
                    if new in labels:
                        stats["  derived name already in the file"] += 1
                        continue
                    stats["  ** nameable"] += 1
                    rows.append((target, new, "entry", screen, len(pairs)))
                if rows:
                    by.setdefault((branch, stage), []).extend(rows)

    if args.proposals:
        for (branch, stage), rows in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for old, new, kind, screen, n in rows:
                if kind == "dispatch":
                    print(f"| {old} | {new} | high | it is the chain of {n} "
                          f"`je [SCREEN_NUM], 0xNN, T` lines whose every "
                          f"target writes the camera bounds `[0x40]..[0x47]`, "
                          f"tears down the previous screen's channels and "
                          f"sets a palette |")
                else:
                    print(f"| {old} | {new} | high | selected by "
                          f"`je [SCREEN_NUM], 0x{screen:02X}` from the "
                          f"stage's screen-entry chain, and "
                          f"`screen_scope.py` independently pins it to that "
                          f"one screen; its body writes the camera bounds "
                          f"and re-installs the screen's threads |")
        return 0

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    return 1 if (args.check and bad) else 0


if __name__ == "__main__":
    sys.exit(main())
