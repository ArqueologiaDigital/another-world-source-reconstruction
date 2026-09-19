#!/usr/bin/env python3
"""How many trivial routines can now be named from the one site that reaches them?

Question answered
-----------------
`tools/nameable_backlog.py` splits the unnamed backlog into *real* bodies and
*trivial* ones — a body that is nothing but `ret`, `killChannel`, `break` or a
`jmp`. Its verdict on the trivial ones is that they are

> nameable ONLY from their callers, so they are the tail of the dependency, and
> a pass that tackles them early can only invent.

That is right, and it is a statement about *timing*, not about impossibility.
Eighteen family-naming passes have since named thousands of the callers. So the
question this asks is: **for how many trivial routines is the dependency now
satisfied** — that is, how many are reached from exactly one site, and that site
already carries a semantic name?

Where that holds, the routine has one true description available and it is not
invented: "the thread termination belonging to <caller>". Where it does not —
several reaching sites, or a placeholder caller — nothing has changed and the
routine stays backlog.

What is measured
----------------
For each port and stage, over routines that `naming_census.classify` still calls
non-semantic and that are reachable (`find_dead_tail_bytes` exclusions applied):

  trivial          body is only `ret` / `killChannel` / `break` / `jmp <label>`
  sites            every `setup|call|jmp|je|jne|jl|jle|jg|jge|djnz` that names it,
                   excluding its own self-reference
  caller named     the single site's enclosing routine classifies as semantic

and it reports the four-way split so the ready population is visible next to
the three that are not.

The proposed tail is chosen from the body, not from the caller:

  `killChannel` -> `_KILL`      the caller's thread ends here
  `ret`         -> `_RET`       already in NAMING.md §1's suffix table
  `break`       -> `_YIELD`
  `jmp`         -> `_JMP_<target>` is refused; a one-line trampoline is named
                   for what it jumps to only if that target is itself named,
                   and is reported separately either way.

Why this is not an index suffix
-------------------------------
`conventions/feedback_no_index_suffixes.md` forbids `_A`/`_B`/`_VARIANT_<n>` to
separate two similar routines, and NAMING.md §1 repeats it. A caller-derived
name is the opposite move: it distinguishes by caller, which is the first
remedy both documents name.

Usage
-----
    python3 notes/caller-derived-naming/sole_named_caller.py
    python3 notes/caller-derived-naming/sole_named_caller.py --port amiga --stage CAVES
    python3 notes/caller-derived-naming/sole_named_caller.py --port amiga \
        --stage CAVES --proposals      # a table apply_routine_renames.py accepts
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ARCH = Path(__file__).resolve().parents[2].parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from _paths import AW_SRC                      # noqa: E402
from find_dead_tail_bytes import analyse        # noqa: E402
from naming_census import classify              # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_REACH = re.compile(
    r"^\s*(setup|call|jmp|je|jne|jl|jle|jg|jge|djnz)\b[^;]*?"
    r"([A-Za-z_][A-Za-z0-9_]*)\s*$")
RE_DIRECTIVE = re.compile(r"^\s*\.(if|elif|else|endif|include)\b")

TAIL = {"killChannel": "_KILL", "ret": "_RET", "break": "_YIELD"}


def load(port: str, stage: str):
    path = AW_SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
    if not path.is_file():
        return None
    lines = path.read_text().splitlines()

    # label -> [body lines]; and the routine each line belongs to
    bodies: dict[str, list[str]] = {}
    owner: list[str | None] = []
    cur = None
    for line in lines:
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            bodies.setdefault(cur, [])
            owner.append(None)
            continue
        owner.append(cur)
        text = line.split(";", 1)[0].strip()
        if text and not RE_DIRECTIVE.match(line) and cur:
            bodies[cur].append(text)

    # reaching sites: label -> [(caller, opcode)]
    sites: dict[str, list[tuple[str, str]]] = collections.defaultdict(list)
    for i, line in enumerate(lines):
        m = RE_REACH.match(line.split(";", 1)[0])
        if not m:
            continue
        op, target = m.group(1), m.group(2)
        caller = owner[i]
        if caller is None or caller == target:
            continue
        sites[target].append((caller, op))
    return path, lines, bodies, sites


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append", choices=STAGES)
    ap.add_argument("--proposals", action="store_true",
                    help="emit a proposal table instead of the census")
    args = ap.parse_args()
    ports = args.port or ["amiga", "msdos"]
    stages = args.stage or STAGES

    grand = collections.Counter()
    rows = []
    if not args.proposals:
        print(f"{'port/stage':<20}{'trivial':>9}{'ready':>8}{'multi-site':>12}"
              f"{'caller unnamed':>16}{'no site':>9}")
    for port in ports:
        for stage in stages:
            got = load(port, stage)
            if got is None:
                continue
            path, lines, bodies, sites = got
            dead = {name for name, *_ in analyse(path)}
            n = collections.Counter()
            for label, body in bodies.items():
                if classify(label) == "semantic" or label in dead:
                    continue
                if len(body) != 1:
                    continue
                head = body[0].split()[0]
                if head not in TAIL:
                    continue
                n["trivial"] += 1
                reach = [c for c, _ in sites.get(label, []) if c != label]
                uniq = sorted(set(reach))
                if not uniq:
                    n["no site"] += 1
                elif len(uniq) > 1:
                    n["multi-site"] += 1
                elif classify(uniq[0]) != "semantic":
                    n["caller unnamed"] += 1
                else:
                    n["ready"] += 1
                    rows.append((port, stage, label, uniq[0] + TAIL[head]))
            grand.update(n)
            if not args.proposals and n["trivial"]:
                print(f"{port + '/' + stage:<20}{n['trivial']:>9}{n['ready']:>8}"
                      f"{n['multi-site']:>12}{n['caller unnamed']:>16}"
                      f"{n['no site']:>9}")

    if args.proposals:
        by = collections.defaultdict(list)
        for port, stage, old, new in rows:
            by[(port, stage)].append((old, new))
        for (port, stage), pairs in sorted(by.items()):
            print(f"\n# {port}/{stage} — trivial routines with one named "
                  f"reaching site\n")
            print("| routine | new name | confidence |")
            print("|---|---|---|")
            seen = collections.Counter()
            for old, new in sorted(pairs):
                seen[new] += 1
                if seen[new] > 1:      # two trivial tails, one caller
                    continue
                print(f"| {old} | {new} | medium |")
        return 0

    print(f"\n{'TOTAL':<20}{grand['trivial']:>9}{grand['ready']:>8}"
          f"{grand['multi-site']:>12}{grand['caller unnamed']:>16}"
          f"{grand['no site']:>9}")
    print("\n`ready` is the population whose dependency is satisfied: one "
          "reaching site,\nand that site already carries a semantic name. The "
          "other three columns are\nstill the tail of the dependency and "
          "naming them now would invent.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
