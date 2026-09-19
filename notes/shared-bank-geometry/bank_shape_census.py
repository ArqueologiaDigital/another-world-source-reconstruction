#!/usr/bin/env python3
"""What shape is the art at each shared-bank offset, and where is it drawn?

Question answered
-----------------
`docs/NAMING.md` §2 closes with: "Hand-naming the bank is still forbidden until
an identification is actually made from a render." The re-key landed on
2026-09-19, so the bank is now keyed by offset (`CV_<OFFSET4>`) and
port-invariant -- one identification names it in every file and on both
priority ports, which is what 1,147 routines were waiting on.

The obvious lever from the cinematic banks does **not** transfer here, and this
probe was written after measuring why. `notes/sole-named-drawer/` names a
picture from the one semantically-named routine that draws it. Applied to the
shared bank that yields **1 candidate out of 352**: 349 of the 352 offsets the
tree draws are drawn from **more than one stage**. A shared-bank name therefore
cannot come from a scene -- whatever CV_1B14 is, it is that same thing in
PRISON and in ENDING -- so it has to come from the shape.

So this measures the shape, before any montage. Per offset:

  extent      w x h of the box the art actually fills, from
              `extent(parse_polygon_tree(bank, off))`, anchor-relative
  leaves      solid polygons in the expanded tree
  colours     the set of colour indices, read from the ROM with a walker that
              honours the group colour-override byte (bit 15 of a child word),
              so it is palette-independent
  stages      which stages draw it, and how many call sites

and it cross-checks the amiga and msdos copies of resource `0x11` parse to the
same `canonical_md5` at every offset -- the per-symbol form of the whole-file
hash that `notes/shared-bank-probes/shared_bank_bytes_identical.py` proved.
A disagreement there would invalidate one-name-per-offset, so it exits 1.

What the shape can and cannot settle is the point of the `--classes` view.
A 3x3 one-leaf shape drawn from seven stages is a particle by construction and
its name is defensible in all seven. A 60x80 twenty-leaf figure drawn from
seven stages is a *character*, and which character is exactly what the shape
does not say. The classes sort the bank into those two situations so effort
goes where a name is actually earnable.

Signals read
------------
resource `0x11` of each port, the shared video2 bank (`docs/NAMING.md` §5
identifies it; 25,108 bytes, sha256 ee98e9d5... on both ports). The offsets
come from the `CV_<OFFSET4> EQU 0x<OFFSET4>` lines in the stage sources, and
the call sites from `video ... offset=CV_xxxx` operands.

The bank dumps live in `another-world-archaeology/tmp/output/<port>/resources/`,
which is volatile. Regenerate with:

    cd another-world-archaeology && python3 tools/aw_unpacker.py

Usage
-----
    python3 notes/shared-bank-geometry/bank_shape_census.py
    python3 notes/shared-bank-geometry/bank_shape_census.py --classes
    python3 notes/shared-bank-geometry/bank_shape_census.py --class particle
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from polygon_extent import extent                            # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]

RE_EQU = re.compile(r"^(CV_[0-9A-F]{4})\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_USE = re.compile(r"offset=(CV_[0-9A-F]{4})")


def bank(port: str) -> bytes:
    p = ARCH / "tmp" / "output" / port / "resources" / "resource-0x11.bin"
    if not p.is_file():
        raise SystemExit(f"missing {p}; see the regeneration recipe in the "
                         f"module docstring")
    return p.read_bytes()


def colours(b: bytes, off: int, depth: int = 0,
            seen: frozenset[int] = frozenset(),
            out: set | None = None, override: int | None = None) -> set:
    """Colour indices in the expanded tree, honouring group overrides.

    Mirrors `tools/polygon_tree.py`'s header rules and keeps the colour that
    file drops: a solid header >= 0xC0 carries its index in the low six bits.
    A group child may override the colour of everything below it (bit 15 of
    the child word); `override` carries that down. Omitting it misreports
    exactly the art that uses overrides.
    """
    if out is None:
        out = set()
    if off < 0 or off + 4 > len(b) or off in seen or depth > 16:
        return out
    seen = seen | {off}
    h = b[off]
    if h >= 0xC0:
        out.add((h & 0x3F) if override is None else override)
        return out
    if (h & 0x3F) == 0x02:
        nc, pos = b[off + 3] + 1, off + 4
        for _ in range(nc):
            if pos + 4 > len(b):
                break
            cw = (b[pos] << 8) | b[pos + 1]
            ca, ov = (cw & 0x7FFF) * 2, bool(cw & 0x8000)
            pos += 4
            sub = override
            if ov:
                if pos + 2 > len(b):
                    break
                sub = b[pos] & 0x7F
                pos += 2
            colours(b, ca, depth + 1, seen, out, sub)
    return out


def classify_shape(w: float, h: float, leaves: int) -> str:
    """Sort by what a name could honestly assert from the geometry alone."""
    area = w * h
    if leaves <= 2 and area <= 64:
        return "particle"          # a speck; true in every stage that draws it
    if leaves <= 2 and max(w, h) >= 40 and min(w, h) <= 6:
        return "bar"               # a long thin sliver: beam, edge, bolt
    if leaves == 1:
        return "single-shape"
    if leaves >= 12 and area >= 1200:
        return "figure"            # articulated; subject NOT settled by shape
    if area >= 1200:
        return "large"
    return "small-cluster"


def collect() -> tuple[dict, dict, dict]:
    offs, uses, stages = {}, collections.Counter(), collections.defaultdict(set)
    for port, br in PORTS.items():
        for st in STAGES:
            p = SRC / "src" / "levels" / br / f"{st}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            for name, val in RE_EQU.findall(text):
                offs[name] = int(val, 16)
            for name in RE_USE.findall(text):
                uses[name] += 1
                stages[name].add(st)
    return offs, uses, stages


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--classes", action="store_true")
    ap.add_argument("--class", dest="only")
    ap.add_argument("--min-stages", type=int, default=0)
    args = ap.parse_args()

    offs, uses, stages = collect()
    ba, bm = bank("amiga"), bank("msdos")

    rows, bad, unparsed = [], [], []
    for name, off in sorted(offs.items(), key=lambda kv: kv[1]):
        ta = parse_polygon_tree(ba, off)
        tm = parse_polygon_tree(bm, off)
        if ta is None:
            unparsed.append(name)
            continue
        if tm is None or canonical_md5(ta) != canonical_md5(tm):
            bad.append(name)
            continue
        x0, y0, x1, y1, leaves = extent(ta)
        w, h = (x1 - x0, y1 - y0) if leaves else (0, 0)
        cs = colours(ba, off)
        rows.append({"name": name, "off": off, "w": w, "h": h,
                     "leaves": leaves, "colours": cs,
                     "uses": uses.get(name, 0),
                     "stages": stages.get(name, set()),
                     "cls": classify_shape(w, h, leaves)})

    if bad:
        print(f"FAIL: {len(bad)} offsets differ between amiga and msdos: "
              f"{', '.join(bad[:8])}")
        return 1
    print(f"{len(rows)} shared-bank offsets parsed; amiga and msdos agree on "
          f"every one (canonical_md5 over the whole tree).")
    if unparsed:
        print(f"{len(unparsed)} did not parse as a polygon: "
              f"{', '.join(unparsed[:8])}")

    drawn = [r for r in rows if r["uses"]]
    multi = [r for r in drawn if len(r["stages"]) > 1]
    print(f"{len(drawn)} are drawn by the tree; {len(multi)} of those from "
          f"more than one stage.\n")

    if args.classes:
        by = collections.Counter(r["cls"] for r in drawn)
        print(f"{'class':<16}{'count':>6}{'multi-stage':>13}"
              f"{'median leaves':>15}   what a name could assert")
        note = {
            "particle": "shape alone: spark/speck, true in every stage",
            "bar": "shape alone: beam/bolt/edge",
            "single-shape": "shape alone, if the outline is recognisable",
            "small-cluster": "needs a render",
            "large": "needs a render",
            "figure": "NOT settled by shape -- which figure is the question",
        }
        for cls, n in by.most_common():
            rs = [r for r in drawn if r["cls"] == cls]
            ls = sorted(r["leaves"] for r in rs)
            m = len([r for r in rs if len(r["stages"]) > 1])
            print(f"{cls:<16}{n:>6}{m:>13}{ls[len(ls) // 2]:>15}   {note[cls]}")
        return 0

    sel = [r for r in drawn
           if (args.only is None or r["cls"] == args.only)
           and len(r["stages"]) >= args.min_stages]
    sel.sort(key=lambda r: (-r["uses"], r["name"]))
    print(f"{'symbol':<10}{'extent':>10}{'lv':>4}{'use':>5}{'st':>4}  "
          f"{'colours':<18}{'class':<14}stages")
    for r in sel[:80]:
        cs = ",".join(str(c) for c in sorted(r["colours"]))
        print(f"{r['name']:<10}{r['w']:>4.0f}x{r['h']:<5.0f}{r['leaves']:>4}"
              f"{r['uses']:>5}{len(r['stages']):>4}  {cs[:17]:<18}"
              f"{r['cls']:<14}{','.join(sorted(r['stages']))[:40]}")
    if len(sel) > 80:
        print(f"  ... and {len(sel) - 80} more")
    return 0


if __name__ == "__main__":
    sys.exit(main())
