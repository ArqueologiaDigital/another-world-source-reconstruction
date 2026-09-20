#!/usr/bin/env python3
"""How many of the rescued proposals are actually live in the tree?

Question answered
-----------------
`README.md` here claims "69 tables, 489 distinct proposed names, of which 396
are in the tree right now". That number was first produced by a shell one-liner
that was never committed -- precisely the thing the working rules forbid, and
the reason this file exists. Run it and the claim either reproduces or it does
not.

The ratio is the point, not the total. A proposal table is *input*: the
appliers reject rows for collisions, for a coordinate in the name, for adding
a gap to a family's index run, and rows get superseded by a later table or
reverted after the fact. So a gap between "proposed" and "live" is expected
and healthy -- it is the guards doing their job. What would be alarming is
the ratio approaching 1.0, which would mean nothing was ever rejected.

Signals read
------------
    tables/*.md      every markdown row whose second column is an
                     ALL_CAPS identifier -- the applier's own input format,
                     `| constant | proposed name | confidence | evidence |`.
                     `SKIP` in that column is a real answer and is counted
                     separately, not silently dropped.
    src/levels       whether that exact name is defined or referenced
                     anywhere in the tree today, by word-boundary match.

What "pass" looks like
----------------------
No fixed threshold. It prints the three counts and the per-table breakdown;
the README's sentence should match the totals. `--missing` lists the names
that are NOT live, which is the useful view when a table looks suspicious --
a table with zero live names usually means it was superseded wholesale.

Usage
-----
    python3 notes/naming-proposals/coverage.py
    python3 notes/naming-proposals/coverage.py --missing
    python3 notes/naming-proposals/coverage.py --per-table
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
SRC = HERE.parents[1]
TABLES = HERE / "tables"
RE_NAME = re.compile(r"^[A-Z][A-Z0-9_]{5,}$")


def proposed() -> dict[str, list[str]]:
    """{table filename: [proposed names]} -- second column, ALL_CAPS only."""
    out: dict[str, list[str]] = {}
    for p in sorted(TABLES.glob("*.md")):
        names = []
        for line in p.read_text(errors="replace").splitlines():
            if not line.lstrip().startswith("|") or "---" in line:
                continue
            cols = [c.strip() for c in line.strip().strip("|").split("|")]
            if len(cols) >= 2 and RE_NAME.match(cols[1]):
                names.append(cols[1])
        out[p.name] = names
    return out


def live_index() -> set[str]:
    """Every ALL_CAPS token defined or referenced in src/levels today."""
    r = subprocess.run(
        ["grep", "-rhoE", r"\b[A-Z][A-Z0-9_]{5,}\b", "src/levels"],
        cwd=SRC, capture_output=True, text=True)
    return set(r.stdout.split())


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--missing", action="store_true",
                    help="list proposed names that are NOT in the tree")
    ap.add_argument("--per-table", action="store_true")
    ap.add_argument("--quality", action="store_true",
                    help="what these tables are NOT: duplicates and "
                         "per-batch evidence")
    args = ap.parse_args()

    if not TABLES.is_dir():
        print(f"no {TABLES}", file=sys.stderr)
        return 1

    tables = proposed()
    live = live_index()
    every = sorted({n for ns in tables.values() for n in ns})
    skips = sum(ns.count("SKIP") for ns in tables.values())
    real = [n for n in every if n != "SKIP"]
    landed = [n for n in real if n in live]

    print(f"{len(tables)} table(s)")
    print(f"{len(real)} distinct proposed name(s), {skips} row(s) marked SKIP")
    print(f"{len(landed)} of those are in src/levels now "
          f"({100.0 * len(landed) / len(real):.1f}%)")
    print(f"{len(real) - len(landed)} were rejected by a guard, superseded by "
          f"a later table, or reverted.")

    if args.per_table:
        print()
        for name, ns in sorted(tables.items()):
            ns = [n for n in ns if n != "SKIP"]
            if not ns:
                continue
            hit = sum(1 for n in ns if n in live)
            flag = "   <- none live" if hit == 0 else ""
            print(f"  {name:<34}{hit:>4}/{len(ns):<4}{flag}")

    if args.quality:
        import hashlib
        import collections
        by_hash = collections.defaultdict(list)
        for f in sorted(TABLES.glob("*.md")):
            by_hash[hashlib.md5(f.read_bytes()).hexdigest()].append(f.name)
        dups = {h: ns for h, ns in by_hash.items() if len(ns) > 1}
        print(f"\n{len(dups)} group(s) of byte-identical tables "
              f"({sum(len(n) for n in dups.values())} files). The filenames "
              f"claim a port or stage the bytes do not carry:")
        for _h, ns in sorted(dups.items(), key=lambda kv: kv[1]):
            print(f"  {' == '.join(ns)}")

        flat = []
        for f in sorted(TABLES.glob("*.md")):
            ev = []
            for line in f.read_text(errors="replace").splitlines():
                if not line.lstrip().startswith("|") or "---" in line:
                    continue
                c = [x.strip() for x in line.strip().strip("|").split("|")]
                if len(c) >= 4 and c[3] and c[3].lower() != "evidence":
                    ev.append(c[3])
            if len(ev) >= 3 and len(set(ev)) == 1:
                flat.append((f.name, len(ev), ev[0]))
        print(f"\n{len(flat)} table(s) repeat ONE evidence string on every "
              f"row -- the rationale is per-batch, not per-name:")
        for name, n, e in flat:
            print(f"  {name:<32}{n:>3} rows  \"{e[:72]}...\"")
        return 0

    if args.missing:
        print("\nproposed but not in the tree:")
        for n in sorted(set(real) - set(landed)):
            print(f"  {n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
