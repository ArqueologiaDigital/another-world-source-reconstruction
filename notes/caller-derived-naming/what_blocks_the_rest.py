#!/usr/bin/env python3
"""What is actually blocking the unnamed routines that are left?

Question answered
-----------------
Two sibling probes narrowed the backlog: `sole_named_caller.py` took the
trivial tail whose dependency was discharged, and `named_art_only.py` showed
that 3,469 of the 3,493 draw routines in the big three draw only unidentified
art, so the routine layer waits on the polygon layer. A day of polygon naming
moved that from 3,495 to 3,469 — real, and slow.

Working the largest remaining CAVES families by hand then hit the same two
walls over and over, so this measures them instead of meeting them one at a
time. Both are named, open issues with their own tracking, not a shortage of
effort:

  **T7 — the shared bank.** `docs/NAMING.md` §2: "**The shared bank
  (`COMMON_VIDEO_NNN`) has no semantic names at all** … Before these can be
  named, the emitter must key them by offset (plan item T7)". A routine whose
  every draw comes from that bank cannot have its subject settled from its art
  at all, no matter how many renders anyone makes.

  **#0138 — the actor record.** The 2026-09-14 pass had 30 CAVES names rejected
  for asserting an actor on a dispatcher that draws at `[0x07],[0x08]`, a
  shared actor-record pair loaded from nine different records before the draw.
  A routine drawing there cannot be named for *who* it draws.

A routine can be blocked by both, by one, or by neither, and the useful number
is the split. `--families` groups the blocked ones by abstracted body, because
a block that covers one family of fifty is a different problem from one spread
over fifty singletons.

What is measured
----------------
Over reachable routines that `naming_census.classify` still calls non-semantic:

  common-video-only   every `video offset=` operand is `COMMON_VIDEO_<n>`
                      (T7)
  actor-slot          at least one draw is at `x=[0x07], y=[0x08]`  (#0138)
  both                blocked by both at once
  neither             blocked by neither; these are where naming effort
                      actually has room, and they are the population the
                      other two probes already rank

Usage
-----
    python3 notes/caller-derived-naming/what_blocks_the_rest.py
    python3 notes/caller-derived-naming/what_blocks_the_rest.py --families
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
sys.path.insert(0, str(Path(__file__).resolve().parents[0].parent))
from actor_slot import actor_slot_matcher  # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
BIG3 = ["PRISON", "CAVES", "CAPSULE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_][A-Za-z0-9_]*)")
# The actor slot is matched through notes/actor_slot.py, which resolves
# aliases. PRISON, CAPSULE and ENDING write `x=[BUDDY_X], y=[BUDDY_Y]`
# with BUDDY_X EQU 0x07, and the literal test reported ZERO #0138 draws
# for all three -- 1,844 of them across the two priority ports.
# After T7 re-keyed the shared bank (2026-09-19) the placeholder form is
# `CV_<OFFSET4>`, not `COMMON_VIDEO_<n>`. Matching only the old spelling made
# this probe report T7 as blocking ZERO routines the moment the re-key landed --
# the same silent under-count the lint had until NUMERIC_CV was widened.
RE_CV = re.compile(r"^(COMMON_VIDEO_\d+|CV_[0-9A-F]{4})$")


def abstract(body: list[str]) -> str:
    out = []
    for line in body:
        s = re.sub(r"\b0x[0-9A-Fa-f]+\b", "#", line)
        s = re.sub(r"\b[A-Za-z_][A-Za-z0-9_]*\b", "@", s)
        out.append(s.strip())
    return "\n".join(out)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--families", action="store_true")
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()
    ports = args.port or ["amiga", "msdos"]

    grand = collections.Counter()
    fams: collections.Counter = collections.Counter()
    examples: dict[str, str] = {}
    print(f"{'port/stage':<18}{'unnamed':>9}{'CV-only (T7)':>14}"
          f"{'actor slot':>12}{'both':>7}{'neither':>9}")
    for port in ports:
        for stage in BIG3:
            path = AW_SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if not path.is_file():
                continue
            text = path.read_text()
            at_slot = actor_slot_matcher(text)
            lines = text.splitlines()
            dead = {n for n, *_ in analyse(path)}
            bodies: dict[str, list[str]] = {}
            cur = None
            for line in lines:
                m = RE_LABEL.match(line)
                if m:
                    cur = m.group(1)
                    bodies.setdefault(cur, [])
                    continue
                if cur:
                    t = line.split(";", 1)[0]
                    if t.strip():
                        bodies[cur].append(t)
            n = collections.Counter()
            for label, body in bodies.items():
                if classify(label) == "semantic" or label in dead:
                    continue
                n["unnamed"] += 1
                art = [s for l in body for s in RE_DRAW.findall(l)]
                cv_only = bool(art) and all(RE_CV.match(a) for a in art)
                actor = any(at_slot(l) for l in body)
                if cv_only and actor:
                    n["both"] += 1
                elif cv_only:
                    n["cv"] += 1
                elif actor:
                    n["actor"] += 1
                else:
                    n["neither"] += 1
                if cv_only or actor:
                    key = abstract(body)
                    fams[key] += 1
                    examples.setdefault(key, f"{port}/{stage} {label}")
            grand.update(n)
            print(f"{port + '/' + stage:<18}{n['unnamed']:>9}{n['cv']:>14}"
                  f"{n['actor']:>12}{n['both']:>7}{n['neither']:>9}")

    print(f"\n{'TOTAL':<18}{grand['unnamed']:>9}{grand['cv']:>14}"
          f"{grand['actor']:>12}{grand['both']:>7}{grand['neither']:>9}")
    blocked = grand['cv'] + grand['actor'] + grand['both']
    pct = 100.0 * blocked / grand['unnamed'] if grand['unnamed'] else 0
    print(f"\n{blocked} of {grand['unnamed']} ({pct:.0f}%) are blocked by T7, "
          f"#0138 or both.\nNeither is a naming problem: T7 needs the shared "
          f"bank re-keyed by offset, and\n#0138 needs the actor question "
          f"settled. The `neither` column is the part a\nnaming pass can move "
          f"today.")
    if args.families:
        print(f"\nblocked routines group into {len(fams)} abstracted bodies; "
              f"the largest:")
        for key, count in fams.most_common(12):
            first = key.split("\n")[0][:64]
            print(f"  {count:4d}  {examples[key]:<28} {first}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
