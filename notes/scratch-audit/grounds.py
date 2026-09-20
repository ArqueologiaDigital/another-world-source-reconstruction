#!/usr/bin/env python3
"""On what grounds were the 41 rescue proposals refuted?

Question answered
-----------------
`README.md` here prints a histogram:

    21  conclusion already in a committed note or a commit diff
    16  regenerable byte-for-byte from a committed probe
    15  byte-identical to a sibling already in scratch
    10  the "evidence" column is a hardcoded literal
     3  the filename misattributes the port or the stage

That came from a shell one-liner over the workflow's JSON result, and the
one-liner was not committed -- the same lapse this directory's own audit
caught elsewhere. This reproduces it from `verdicts.md`, which IS committed,
so the histogram can be checked without re-running 18 agents.

Signal being read
-----------------
Substring probes over each verdict's prose. **This is a keyword tally, not a
classification**, and the distinction matters for how the numbers are read:

  * A verdict can match several grounds, so the counts **sum to more than
    41** by design. They answer "how often was this reason given", not "how
    many files fell into this bucket".
  * A verifier who made the same point in different words is missed. The
    tally is a floor.

Both properties are why the README quotes it as recurring grounds rather than
as a partition. `--verdicts` prints which file matched which ground, so a
suspicious count can be traced to the prose behind it.

Usage
-----
    python3 notes/scratch-audit/grounds.py
    python3 notes/scratch-audit/grounds.py --verdicts
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

# ground -> substrings, any of which counts as that ground being given
GROUNDS = {
    "conclusion already in a committed note or a commit diff":
        ["already", "committed note", "commit diff", "is in commit"],
    "regenerable byte-for-byte from a committed probe":
        ["REGENERAT", "regenerate", "regenerates", "byte-for-byte"],
    "byte-identical to a sibling already in scratch":
        ["byte-identical to"],
    'the "evidence" column is a hardcoded literal':
        ["hardcoded"],
    "the filename misattributes the port or the stage":
        ["filename lies", "no port attribution", "not an amiga record",
         "mislabelled"],
}


def verdicts() -> dict[str, str]:
    """{scratch-relative path: the refutation prose}, from verdicts.md."""
    text = (HERE / "verdicts.md").read_text(errors="replace")
    out: dict[str, str] = {}
    cur = None
    buf: list[str] = []
    for line in text.splitlines():
        m = re.match(r"^## `(.+)`$", line)
        if m:
            if cur:
                out[cur] = "\n".join(buf).strip()
            cur, buf = m.group(1), []
            continue
        if cur is not None:
            buf.append(line)
    if cur:
        out[cur] = "\n".join(buf).strip()
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--verdicts", action="store_true",
                    help="show which file matched which ground")
    args = ap.parse_args()

    v = verdicts()
    if not v:
        print("verdicts.md parsed to nothing", file=sys.stderr)
        return 1

    tally: collections.Counter = collections.Counter()
    per_file: dict[str, list[str]] = {}
    for path, why in sorted(v.items()):
        hit = [g for g, keys in GROUNDS.items() if any(k in why for k in keys)]
        per_file[path] = hit
        tally.update(hit)

    print(f"{len(v)} refuted proposal(s)\n")
    print("recurring grounds (a verdict may give several, so these sum to "
          "more than the file count):")
    for g, n in tally.most_common():
        print(f"  {n:4d}  {g}")

    none = [p for p, h in per_file.items() if not h]
    if none:
        print(f"\n{len(none)} verdict(s) matched no ground keyword -- the "
              f"tally is a floor, and these are the prose it cannot see:")
        for p in none:
            print(f"  {p}")

    if args.verdicts:
        print()
        for path, hit in sorted(per_file.items()):
            print(f"  {path}")
            for g in hit:
                print(f"      {g}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
