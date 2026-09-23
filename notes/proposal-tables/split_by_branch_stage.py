#!/usr/bin/env python3
"""Split a probe's `--proposals` output into one table per (branch, stage).

Question answered
-----------------
Every applier in `tools/` takes `--branch` and `--stage` and one proposal
file, but the probes that *derive* proposals scan the whole tree at once and
emit a single stream with `----- <branch> / <STAGE> -----` separators. The
split between them was being done by hand, which means the committed
`proposals_<branch>__<STAGE>.md` files had no recorded recipe -- you could
read them, but not regenerate them. This is that recipe.

The separator is the only contract: a line matching

    ----- <branch> / <STAGE> -----

opens a section, and every following line beginning `| ` that is not the
header or the `| --- |` rule is a row of that section's table.

Which probes feed it
--------------------
    python3 notes/laser-impact-anim/impact_ladder.py --proposals \\
      | python3 notes/proposal-tables/split_by_branch_stage.py \\
          --out notes/laser-impact-anim \\
          --title 'The shot-impact burst in {stage} -- {branch}' \\
          --note 'Derived by notes/laser-impact-anim/impact_ladder.py.'

    python3 notes/draw-label-follows-constant/label_vs_constant.py --proposals \\
      | python3 notes/proposal-tables/split_by_branch_stage.py \\
          --out notes/draw-label-follows-constant --header routine \\
          --title 'Draw-only labels in {stage} -- {branch}' \\
          --note 'Derived by notes/draw-label-follows-constant/label_vs_constant.py.'

    python3 notes/motion-word-audit/piece_family_vs_label.py --proposals \\
      | python3 notes/proposal-tables/split_by_branch_stage.py \\
          --out notes/motion-word-audit --header routine \\
          --title 'Actor gait labels in {stage} -- {branch}' \\
          --note 'Derived by notes/motion-word-audit/piece_family_vs_label.py.'

`--header routine` writes a `| routine |` column for the routine appliers;
the default `constant` is for `apply_cinematic_renames` and
`apply_branch_scoped_names`.

Usage
-----
    <probe> --proposals | python3 notes/proposal-tables/split_by_branch_stage.py \\
        --out <dir> [--header constant|routine] [--title T] [--note N] [--dry]
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

RE_SECTION = re.compile(r"^-----\s*(\S+)\s*/\s*(\S+)\s*-----\s*$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--header", default="constant",
                    choices=["constant", "routine"])
    ap.add_argument("--title", default="{stage} -- {branch}")
    ap.add_argument("--note", default="")
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()

    sections: dict[tuple[str, str], list[str]] = {}
    cur = None
    for line in sys.stdin.read().splitlines():
        if m := RE_SECTION.match(line):
            cur = (m.group(1), m.group(2))
            sections.setdefault(cur, [])
        elif cur and line.startswith("| "):
            if line.startswith(f"| {args.header} |") or set(
                    line.replace("|", "").replace("-", "").strip()) == set():
                continue
            sections[cur].append(line.rstrip())

    if not sections:
        print("no '----- <branch> / <STAGE> -----' section found",
              file=sys.stderr)
        return 1

    for (branch, stage), rows in sorted(sections.items()):
        if not rows:
            continue
        f = args.out / f"proposals_{branch}__{stage}.md"
        text = (f"# {args.title.format(branch=branch, stage=stage)}\n\n"
                + (f"{args.note}\n\n" if args.note else "")
                + f"| {args.header} | proposed name | confidence | "
                  f"evidence |\n| --- | --- | --- | --- |\n"
                + "\n".join(rows) + "\n")
        if args.dry:
            print(f"  would write {f}  ({len(rows)} rows)")
        else:
            f.write_text(text)
            print(f"  {f}  ({len(rows)} rows)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
