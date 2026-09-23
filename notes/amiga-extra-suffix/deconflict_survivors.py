#!/usr/bin/env python3
"""`_AMIGA_EXTRA` is not a name. Which of them were displaced wrongly?

Question answered
-----------------
`another-world-archaeology/tools/apply_tree_canonical_renames.py:158` explains
the suffix in its own comment:

    # For each collision target T, the amiga polygon currently named T is
    # a port-exclusive survivor (no msdos counterpart with this name). To
    # free up the slot, rename the survivor away to T_AMIGA_EXTRA<N>.

So `_AMIGA_EXTRA` says nothing about a picture. It marks the **incumbent** of a
name slot that a cross-port transfer wanted, and the transfer always won. That
is a coin flip resolved the same way every time, and it was resolved without
looking at either picture.

Two outcomes are possible per suffixed constant, and this probe tells them
apart using `canonical_md5` -- the only legitimate cross-port bridge (#0107):

  RESTORE   some branch that was **not** party to the collision names this
            exact art with the un-suffixed name. The incumbent was right and
            the incoming name was wrong; the suffix should come off and
            whatever took the slot needs its own name.

  KEPT      the un-suffixed name in this branch now holds art that another
            branch independently gives that same name to. The displacement was
            correct; the suffixed constant is an unnamed picture wearing a
            misleading label, and needs a name from its own draw site.

  UNDECIDED neither holds -- no third branch has an opinion.

The signal read is `canonical_md5(parse_polygon_tree(bank, offset))` of the
stage's own 0x10000-byte cinematic slab, per branch. Equal hash means the same
drawing; that is the whole claim. A hash is never compared across *banks* by
index, only art to art.

Run it
------
    python3 notes/amiga-extra-suffix/deconflict_survivors.py
    python3 notes/amiga-extra-suffix/deconflict_survivors.py --verdict RESTORE

A third branch is what breaks the tie, because amiga and msdos are usually
*both* party to the collision and so both carry the same wrong name. gba_2004
is that third branch for INTRO. Its romset is two 0x10000 slabs, and which slab
holds which stage is **not** assumed: `gba_slab()` tries each one and keeps the
slab that agrees with amiga on the most identically-named constants, requiring
at least MIN_CAL agreements and CAL_MARGIN times the runner-up. `--calibration`
prints those counts. If no slab clears the bar, gba contributes no art for that
stage and every verdict there falls back to amiga/msdos alone.

Needs `another-world-archaeology/tmp/output/<port>/romset/cinematic.rom`
(`tools/aw_unpacker.py`). cartridge_1992 has no romset -- #0106 -- so it can
contribute names but never art, and is excluded from the md5 side.
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys
from collections import defaultdict

HERE = pathlib.Path(__file__).resolve().parents[2]
ARCH = HERE.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from polygon_tree import parse_polygon_tree, canonical_md5  # noqa: E402

SRC = HERE / "src" / "levels"
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3,
            "CAVES": 4, "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
# branch -> the port whose romset holds its art
PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos", "gba_2004": "gba_usa"}
BRANCHES = ["chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004"]

RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)
SUFFIX = re.compile(r"_AMIGA_EXTRA(_\d+)?$")

MIN_CAL = 20        # agreements a gba slab needs before it counts as this stage
CAL_MARGIN = 3      # ... and how many times the runner-up it must beat

_raw: dict[str, bytes | None] = {}
_gba_cal: dict[str, tuple[int | None, list[int]]] = {}
_md5: dict[tuple[str, int, int], str | None] = {}


def raw(port: str) -> bytes | None:
    if port not in _raw:
        p = ARCH / "tmp" / "output" / port / "romset" / "cinematic.rom"
        _raw[port] = p.read_bytes() if p.is_file() else None
    return _raw[port]


def window(port: str, idx: int) -> bytes | None:
    b = raw(port)
    if not b or (idx + 1) * 0x10000 > len(b):
        return None
    return b[idx * 0x10000:(idx + 1) * 0x10000]


def hash_at(port: str, idx: int, offset: int) -> str | None:
    """canonical_md5 of the polygon at `offset` in slab `idx` of `port`.

    A wrong offset parses as garbage often enough, and deep enough, that
    canonical_bytes can overflow its 2-byte length field. That is a failed
    parse, not a hash, so it is reported as one.
    """
    key = (port, idx, offset)
    if key not in _md5:
        b = window(port, idx)
        try:
            t = parse_polygon_tree(b, offset) if b else None
            _md5[key] = canonical_md5(t) if t else None
        except (OverflowError, ValueError, IndexError):
            _md5[key] = None
    return _md5[key]


def gba_slab(stage: str) -> tuple[int | None, list[int]]:
    """Which gba slab is this stage? Decided by agreement, never assumed."""
    if stage in _gba_cal:
        return _gba_cal[stage]
    shared = [(n, o) for n, o in equs("gba_2004", stage).items()
              if equs("chahi_amiga_1991", stage).get(n) == o]
    scores = []
    idx = 0
    while window("gba_usa", idx) is not None:
        hit = sum(1 for n, o in shared
                  if hash_at("gba_usa", idx, o) is not None
                  and hash_at("gba_usa", idx, o) == hash_at("amiga", STAGE_ID[stage], o))
        scores.append(hit)
        idx += 1
    best = max(range(len(scores)), key=lambda i: scores[i]) if scores else None
    if best is None or scores[best] < MIN_CAL:
        best = None
    else:
        rest = sorted(scores, reverse=True)[1:]
        if rest and scores[best] < CAL_MARGIN * max(rest[0], 1):
            best = None
    _gba_cal[stage] = (best, scores)
    return _gba_cal[stage]


def art(branch: str, stage: str, offset: int) -> str | None:
    port = PORT.get(branch)
    if port is None:
        return None
    if port == "gba_usa":
        idx, _ = gba_slab(stage)
        return hash_at(port, idx, offset) if idx is not None else None
    return hash_at(port, STAGE_ID[stage], offset)


def equs(branch: str, stage: str) -> dict[str, int]:
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return {}
    return {n: int(v, 16) for n, v in RE_EQU.findall(f.read_text())}


def scan(only_stage: str | None):
    rows = []
    for stage in STAGE_ID:
        if only_stage and stage != only_stage:
            continue
        table = {b: equs(b, stage) for b in BRANCHES}
        # md5 -> set of un-suffixed names that branch gives it
        names_for: dict[str, dict[str, set[str]]] = defaultdict(lambda: defaultdict(set))
        for b in BRANCHES:
            for n, off in table[b].items():
                if SUFFIX.search(n):
                    continue
                h = art(b, stage, off)
                if h:
                    names_for[h][b].add(n)

        for b in BRANCHES:
            for n, off in sorted(table[b].items()):
                if not SUFFIX.search(n):
                    continue
                base = SUFFIX.sub("", n)
                mine = art(b, stage, off)
                # who else, in another branch, calls THIS art `base`?
                restore = sorted(o for o in BRANCHES
                                 if o != b and mine and base in names_for.get(mine, {}).get(o, ()))
                # what art wears `base` in my branch now, and who agrees?
                incumbent = table[b].get(base)
                inc_h = art(b, stage, incumbent) if incumbent is not None else None
                kept = sorted(o for o in BRANCHES
                              if o != b and inc_h and base in names_for.get(inc_h, {}).get(o, ()))
                if mine is None:
                    verdict = "NO_ART"
                elif restore:
                    verdict = "RESTORE"
                elif kept:
                    verdict = "KEPT"
                else:
                    verdict = "UNDECIDED"
                rows.append((stage, b, n, off, mine, verdict, restore or kept))
    return rows


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", choices=sorted(STAGE_ID))
    ap.add_argument("--verdict", choices=["RESTORE", "KEPT", "UNDECIDED", "NO_ART"])
    ap.add_argument("--calibration", action="store_true",
                    help="print which gba slab was picked for each stage, and why")
    args = ap.parse_args()

    if args.calibration:
        print("  gba slab calibration -- agreements with amiga on identically")
        print("  named, identically valued constants, per candidate slab:\n")
        for stage in STAGE_ID:
            if args.stage and stage != args.stage:
                continue
            idx, scores = gba_slab(stage)
            pick = f"slab {idx}" if idx is not None else "none (gba contributes no art)"
            print(f"  {stage:<12} {scores}  ->  {pick}")
        print(f"\n  a slab needs >= {MIN_CAL} agreements and {CAL_MARGIN}x the runner-up")
        return 0

    rows = scan(args.stage)
    counts = defaultdict(int)
    for r in rows:
        counts[r[5]] += 1

    shown = [r for r in rows if not args.verdict or r[5] == args.verdict]
    print(f"  {len(rows)} `_AMIGA_EXTRA` constant(s)"
          + (f" in {args.stage}" if args.stage else "")
          + f"; showing {len(shown)}\n")
    w = max((len(r[2]) for r in shown), default=10)
    for stage, b, n, off, h, verdict, who in shown:
        print(f"  {stage:<10} {b:<18} {n:<{w}} 0x{off:04X}  "
              f"{(h or '-')[:12]}  {verdict:<9} {','.join(who)}")
    print("\n  verdicts: " + "  ".join(f"{k} {v}" for k, v in sorted(counts.items())))
    print("\n  RESTORE   the incumbent was right: drop the suffix, and whatever")
    print("            took the slot needs a name of its own.")
    print("  KEPT      the displacement was right: this is an unnamed picture")
    print("            wearing a misleading label; name it from its draw site.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
