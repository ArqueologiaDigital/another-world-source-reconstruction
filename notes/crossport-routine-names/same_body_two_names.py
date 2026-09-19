#!/usr/bin/env python3
"""One routine, two names: the ports disagreeing about what something is.

Question answered
-----------------
`notes/crossport-name-audit/` checks whether the ports agree about what a
shared polygon NAME draws. Nothing checked the mirror case: whether the same
ROUTINE carries two different semantic names in the two ports.

It is not hypothetical. Writing `CAVES_LOAD_WATERFALL_BACKDROP` onto an
amiga routine on 2026-09-20 produced exactly that -- msdos already called
the byte-identical routine `CAVES_BUDDY_CRAWLING_SCENE_SETUP`. The byte gate
cannot see it (a label rename moves nothing), `undefined_symbols.py` cannot
see it (both names are defined), and the polygon audit cannot see it
(routines are not constants). It was found by accident.

How identity is decided
-----------------------
A routine's body with every symbol replaced by `@` -- so `LABEL_<hex>`,
`CINEMATIC_*` and `CV_*` differences, which are per-port by construction, do
not prevent a match -- hashed, and matched only where the hash is unique
within each port. Bodies under six lines are skipped: short stubs collide by
the hundred and say nothing.

Result on 2026-09-20
--------------------
621 routines have the same body under a different name, which is mostly
`LABEL_<hex>` against a real name and is just unfinished work. **14 have a
semantic name on BOTH sides**, and those are disagreements about meaning:

    INTRO   INTRO_COMPOSE_PAGE3_THEN_RECEDE_DOWN_ACCELERATOR_TUNNEL
            ACCELERATOR_TUNNEL_PULSE_SHRINKS_TO_POINT
    INTRO   BIOMETRIC_SCANNER_RING_ORBIT_PASS
            BIOMETRIC_SCAN_PANEL_SEGMENTS_LIGHT_UP
    ENDING  PTERANODON_HEAD_BEAK_OPEN_ANIM / PTERANODON_HEAD_CRY_ANIM
    LAKE    HERO_AI_DISPATCH / HERO_AI_DISPATCH_AIRBORNE
    ... and ten more, listed by `--all`

Some are harmless restatements (`CLEAR_PAGES_1_2_AND_BLIT` against
`TANK_CLEAR_AND_BLIT_PAGES_1_2_FF`). Others are two different claims about
the same code, and #0120 says a tool must not pick between them.

The CAVES case is worth keeping in view because the disagreement runs deeper
than the pair. The scene whose backdrop loader msdos calls
`CAVES_BUDDY_CRAWLING_SCENE_SETUP` also contains a routine both ports
already call `CAVES_WATERFALL_SPRAY_DRIFT_LEFT_LOOP`. Two earned names, one
scene, and they do not agree about what the place is -- which is why the
polygon families named there on 2026-09-20 take only their measured form
(`CAVES_FALLING_STREAK`, `CAVES_SPRAY_LINE`, `CAVES_DROPLET`) and do not
take a side.

Usage
-----
    python3 notes/crossport-routine-names/same_body_two_names.py
    python3 notes/crossport-routine-names/same_body_two_names.py --all
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from naming_census import classify                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_L = re.compile(r"^([A-Za-z_]\w*):")
RE_SYM = re.compile(r"\b(LABEL_[0-9A-F]{4}|CINEMATIC_\w+|CV_[0-9A-F]{4})\b")
MIN_LINES = 6


def bodies(path: Path) -> dict[str, list[str]]:
    out: dict[str, list[str]] = {}
    cur = None
    for line in path.read_text(errors="replace").splitlines():
        m = RE_L.match(line)
        if m:
            cur = m.group(1)
            out.setdefault(cur, [])
            continue
        if cur is not None:
            t = line.split(";", 1)[0].strip()
            if t:
                out[cur].append(RE_SYM.sub("@", t))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true",
                    help="also list the pairs where only one side is named")
    args = ap.parse_args()

    tot = collections.Counter()
    both: list[tuple] = []
    one: list[tuple] = []
    for stage in STAGES:
        B = {}
        for port, br in PORTS.items():
            f = ROOT / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                B = {}
                break
            B[port] = bodies(f)
        if len(B) < 2:
            continue
        sig = {}
        for port in PORTS:
            sig[port] = collections.defaultdict(list)
            for lab, b in B[port].items():
                if len(b) < MIN_LINES:
                    continue
                sig[port][hashlib.md5("\n".join(b).encode()).hexdigest()]\
                    .append(lab)
        for h, a in sig["amiga"].items():
            m = sig["msdos"].get(h)
            if not m or len(a) != 1 or len(m) != 1 or a[0] == m[0]:
                continue
            tot["same body, different name"] += 1
            pair = (stage, a[0], m[0], len(B["amiga"][a[0]]))
            if classify(a[0]) == "semantic" and classify(m[0]) == "semantic":
                tot["  and BOTH names are semantic"] += 1
                both.append(pair)
            else:
                one.append(pair)

    for k, v in tot.items():
        print(f"{v:5d}  {k}")
    print("\nboth sides named -- the ports disagree about what this is:\n")
    for stage, a, m, n in sorted(both, key=lambda r: -r[3]):
        print(f"  {stage:<9} {n:3d} lines")
        print(f"      amiga  {a}")
        print(f"      msdos  {m}")
    if args.all:
        print(f"\none side still a placeholder ({len(one)}) -- ordinary "
              f"unfinished work, not a disagreement:")
        for stage, a, m, n in sorted(one, key=lambda r: -r[3])[:30]:
            print(f"  {stage:<9} {n:3d}  {a}  /  {m}")
    return 1 if both else 0


if __name__ == "__main__":
    sys.exit(main())
