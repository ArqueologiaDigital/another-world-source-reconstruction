#!/usr/bin/env python3
"""How many unnamed routines draw ONLY polygons that already have a name?

Question answered
-----------------
`sole_named_caller.py` discharged the trivial tail — routines with no body worth
naming, nameable from their one caller. This asks the same kind of question one
layer up, for routines that *do* have a body:

  **A draw stub whose every `video offset=` names an already-identified polygon
  has its subject settled by the art, not by the namer.**

That is the E3 bar `docs/NAMING.md` §2 sets — render the polygon and look at it
before naming it — already met, by whoever named the constant. The routine
inherits it. Where even one operand is still `CINEMATIC_<index>` or
`COMMON_VIDEO_<n>`, nothing is settled and the routine stays backlog: §2 bars
hand-naming the shared bank at all until it is re-keyed by offset (plan item
T7), and a `CINEMATIC_<index>` is a per-port encounter counter, not a subject.

This is what gates the big three. Their largest remaining families are two-line
draw stubs — CAVES has 51 routines sharing the shape of `DRAW_CIN_254`, CAPSULE
36 sharing `DRAW_CIN_195` — and each member differs from its siblings only by
which polygon it draws. So the routine layer cannot move until the polygon
layer does, for most of them. The point of this probe is to measure *how much*
of the routine layer is already unblocked, instead of assuming it is none.

What is measured
----------------
For every reachable routine that `naming_census.classify` still calls
non-semantic, in the given stages and ports:

  draws         how many `video offset=<SYM>` the body issues
  named art     every one of those symbols classifies as semantic
  mixed         at least one named and at least one not
  no art        the body draws nothing (these are `sole_named_caller.py`'s
                population, or a control-flow body, and are not counted here)

`--list` prints the ready ones with the polygons they draw, which is the input
a namer needs and the whole of it.

Why this is not naming from the index
-------------------------------------
Nothing here is derived from a polygon's number. A routine qualifies only when
the constants it draws carry names somebody earned from a render, and the
proposed name repeats those names' subject. A routine drawing
`CINEMATIC_124` does not qualify, which is the point — that constant is exactly
the kind that cost this project three misapplied hand names.

Usage
-----
    python3 notes/caller-derived-naming/named_art_only.py
    python3 notes/caller-derived-naming/named_art_only.py --port amiga --stage CAVES --list
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
BIG3 = ["PRISON", "CAVES", "CAPSULE"]
ALL = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
       "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_][A-Za-z0-9_]*)")


def art_is_named(sym: str) -> bool:
    """A polygon operand counts as identified only if it carries a real name.

    `CINEMATIC_<index>` is the disassembler's per-port encounter counter and
    `COMMON_VIDEO_<n>` is the shared bank, which NAMING.md §2 bars from being
    hand-named until it is re-keyed by offset. Both are placeholders here even
    though they are not `LABEL_<hex>`.
    """
    if re.fullmatch(r"CINEMATIC_\d+", sym):
        return False
    if re.fullmatch(r"COMMON_VIDEO_\d+", sym):
        return False
    return classify(sym) == "semantic"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append", choices=ALL)
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()
    ports = args.port or ["amiga", "msdos"]
    stages = args.stage or BIG3

    grand = collections.Counter()
    if not args.list:
        print(f"{'port/stage':<20}{'unnamed w/ art':>16}{'all art named':>15}"
              f"{'mixed':>8}{'no art named':>14}")
    for port in ports:
        for stage in stages:
            path = AW_SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if not path.is_file():
                continue
            lines = path.read_text().splitlines()
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
                    bodies[cur].append(line.split(";", 1)[0])
            n = collections.Counter()
            ready = []
            for label, body in bodies.items():
                if classify(label) == "semantic" or label in dead:
                    continue
                art = [s for line in body for s in RE_DRAW.findall(line)]
                if not art:
                    continue
                n["with art"] += 1
                named = [a for a in art if art_is_named(a)]
                if len(named) == len(art):
                    n["all named"] += 1
                    ready.append((label, art))
                elif named:
                    n["mixed"] += 1
                else:
                    n["none named"] += 1
            grand.update(n)
            if args.list:
                print(f"\n# {port}/{stage} — {len(ready)} routine(s) whose every "
                      f"drawn polygon is already identified\n")
                for label, art in sorted(ready):
                    uniq = list(dict.fromkeys(art))
                    shown = ", ".join(uniq[:6]) + (" …" if len(uniq) > 6 else "")
                    print(f"  {label}\n      {len(art)} draw(s): {shown}")
            elif n["with art"]:
                print(f"{port + '/' + stage:<20}{n['with art']:>16}"
                      f"{n['all named']:>15}{n['mixed']:>8}{n['none named']:>14}")

    if not args.list:
        print(f"\n{'TOTAL':<20}{grand['with art']:>16}{grand['all named']:>15}"
              f"{grand['mixed']:>8}{grand['none named']:>14}")
        print("\n`all art named` is the population the polygon layer has already "
              "unblocked.\nThe other two wait on it — which is the honest shape "
              "of the remaining work:\nthe big three's routine layer is gated by "
              "their polygon layer, not the reverse.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
