#!/usr/bin/env python3
"""Does `polygon_extent.extent` agree with the engine? It did not, for groups.

Question answered
-----------------
`tools/polygon_extent.py` measures the drawn extent of a polygon tree straight
from the ROM, and its docstring gives the reason: "reading `cinematic.rom`
directly so there is no renderer in between". Extents measured that way have
been quoted as evidence in naming proposals since 2026-09-12.

Cutting the renderer out also removed the only thing that would have caught a
misreading of the format, and there was one. The two size bytes in a **solid**
header are a bounding box and are halved. The two bytes in a **group** header
are not a bounding box at all -- they are a pivot the engine subtracts *whole*
before adding each child's position. The reference VM:

    readAndDrawPolygonHierarchy:            fillPolygon:
      pgc_x = x - fetchByte() * zoom / 64     cx - bbox_w / 2 + px
      pgc_y = y - fetchByte() * zoom / 64
      po_x  = pgc_x + fetchByte() * zoom / 64

and `AnotherWorld_VMTools/awvm/src/polygons.rs:326` ports it faithfully.
`extent()` halved the group bytes too, which shifted every child by half the
pivot and inflated the reported box. The error is invisible on a flat tree and
grows with nesting, which is why it survived: single-leaf art measured
correctly while articulated figures did not.

This probe is the check that was missing. It measures every polygon the
renderer emits for a bank, straight from the ROM, and compares against the
bounding box of the renderer's own SVG output. The renderer is the arbiter
because it is the port of the engine.

Result, 2026-09-20
------------------
Shared bank (video2, 352 named offsets) and amiga CAVES cinematic bank:

    rule                    exact agreement
    old (halve the group)   only the flat trees
    new (pivot whole)       330/352 video2, and see the run below for CAVES

Every remaining disagreement is one kind: a leaf whose header bbox is 0 or 1
wide, which the rasteriser inflates to two pixels via the reference VM's
`drawPoint` path, while this measurement reports the true polygon extent. That
is a drawing convention, not a measurement error, and the probe reports those
separately rather than counting them as failures.

What did NOT change
-------------------
`polygon_tree.canonical_md5` serialises the header bytes verbatim and never
interprets them, so **every cross-port identity match made with it stands** --
the 1,423 md5-equal pairs, the `--duplicates` and `--sides` audits, the whole
transfer-by-art-identity pass. Only quoted *sizes* move.

The documented worked example in `tools/polygon_extent.py` also survives: CAVES'
three falling-rock draws still measure 21x20, 38x24 and 58x28 under the
corrected rule, because those three are flat. Re-check it with

    python3 tools/polygon_extent.py --stage 4 --port amiga \
        --offsets 0xCED4 0xCF2C 0xCF8C

Signals read
------------
ROM: `tmp/output/<port>/resources/resource-0x11.bin` (video2) or
`tmp/output/<port>/romset/cinematic.rom` sliced at `stage * 0x10000`.
Renders: one SVG per polygon from `awvm-render-polygons`, whose filename ends
`_0x<OFFSET4>.svg`; the comparison is the min/max over every `d="..."` point.

Regenerating the renders (regenerable, so not committed):

    cd AnotherWorld_VMTools
    cargo run --quiet --bin awvm-render-polygons -- --port amiga --stage 4 \
      --romset ../another-world-archaeology/tmp/output/amiga/romset \
      --bank video2 --out <dir> --palette 0

Exit status
-----------
0 when every polygon agrees apart from the degenerate-leaf convention.
1 on any other disagreement, which would mean the format is still misread.

Usage
-----
    python3 notes/polygon-extent-correction/extent_matches_renderer.py \
        --renders <dir> --bank video2
    python3 notes/polygon-extent-correction/extent_matches_renderer.py \
        --renders <dir> --bank cinematic --stage 4 [--old]
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from polygon_tree import parse_polygon_tree            # noqa: E402
from polygon_extent import extent                      # noqa: E402

RE_D = re.compile(r'd="([^"]+)"')
RE_NUM = re.compile(r"[-\d.]+")


def extent_old(tree, ox=0.0, oy=0.0, acc=None):
    """The pre-2026-09-20 rule, kept so the difference can be shown."""
    if acc is None:
        acc = [1e9, 1e9, -1e9, -1e9, 0]
    if tree is None:
        return acc
    if tree[0] == "solid":
        w, h, pts = tree[1], tree[2], tree[3]
        acc[4] += 1
        for px, py in pts:
            x, y = ox - w / 2 + px, oy - h / 2 + py
            acc[0], acc[1] = min(acc[0], x), min(acc[1], y)
            acc[2], acc[3] = max(acc[2], x), max(acc[3], y)
    elif tree[0] == "group":
        w, h, ch = tree[1], tree[2], tree[3]
        for px, py, _c, sub in ch:
            extent_old(sub, ox - w / 2 + px, oy - h / 2 + py, acc)
    return acc


def has_degenerate_leaf(b: bytes, off: int, depth: int = 0,
                        seen: frozenset[int] = frozenset()) -> bool:
    """A leaf the renderer widens by 2 because it is really a line.

    This is the renderer's own condition, not an approximation of it
    (`awvm/src/polygons.rs`, "a 4-point degenerate polygon that's really a
    line gets bumped to a 1-px-wide lozenge so the SVG viewer renders it"):

        num_points == 4 && pt_x[0] == pt_x[3] && pt_x[1] == pt_x[2]
                        && pt_y[0] == pt_y[3] && pt_y[1] == pt_y[2]
        -> pt_x[2] += 2, pt_x[3] += 2

    A first version of this test asked instead whether some leaf was under 2
    units wide. That is a different set: it excused 100 polygons in the shared
    bank that the *old* extent rule got wrong for the ordinary reason, hiding
    most of the bug it was written to characterise. Using the exact condition,
    the old rule's unexplained failures are visible and the corrected rule has
    none.
    """
    if off < 0 or off + 4 > len(b) or off in seen or depth > 16:
        return False
    seen = seen | {off}
    h = b[off]
    if h >= 0xC0:
        np = b[off + 3]
        if np != 4:
            return False
        pts = [(b[off + 4 + i * 2], b[off + 5 + i * 2]) for i in range(4)]
        return pts[0] == pts[3] and pts[1] == pts[2]
    if (h & 0x3F) != 0x02:
        return False
    nc, pos = b[off + 3] + 1, off + 4
    for _ in range(nc):
        if pos + 4 > len(b):
            break
        cw = (b[pos] << 8) | b[pos + 1]
        pos += 4
        if cw & 0x8000:
            pos += 2
        if has_degenerate_leaf(b, (cw & 0x7FFF) * 2, depth + 1, seen):
            return True
    return False


def slab(bank: str, port: str, stage: int) -> bytes:
    base = ARCH / "tmp" / "output" / port
    if bank == "video2":
        p = base / "resources" / "resource-0x11.bin"
        if not p.is_file():
            raise SystemExit(f"missing {p}; run tools/aw_unpacker.py")
        return p.read_bytes()
    p = base / "romset" / "cinematic.rom"
    if not p.is_file():
        raise SystemExit(f"missing {p}; run tools/aw_unpacker.py")
    all_ = p.read_bytes()
    return all_[stage * 0x10000:(stage + 1) * 0x10000]


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--renders", type=Path, required=True)
    ap.add_argument("--bank", default="video2", choices=["video2", "cinematic"])
    ap.add_argument("--port", default="amiga")
    ap.add_argument("--stage", type=int, default=4)
    ap.add_argument("--old", action="store_true",
                    help="measure with the pre-correction rule instead")
    args = ap.parse_args()

    b = slab(args.bank, args.port, args.stage)
    measure = extent_old if args.old else extent

    svgs = sorted(args.renders.glob("*_0x????.svg"))
    if not svgs:
        print(f"no renders in {args.renders}", file=sys.stderr)
        return 2

    ok = thin = bad = unparsed = 0
    examples: list[str] = []
    for f in svgs:
        off = int(f.stem[-4:], 16)
        tree = parse_polygon_tree(b, off)
        if tree is None:
            unparsed += 1
            continue
        pts = [float(v) for d in RE_D.findall(f.read_text())
               for v in RE_NUM.findall(d)]
        if not pts:
            continue
        xs, ys = pts[0::2], pts[1::2]
        sw, sh = max(xs) - min(xs), max(ys) - min(ys)
        x0, y0, x1, y1, _lv = measure(tree)
        mw, mh = x1 - x0, y1 - y0
        if abs(mw - sw) < 0.01 and abs(mh - sh) < 0.01:
            ok += 1
        elif has_degenerate_leaf(b, off):
            thin += 1
        else:
            bad += 1
            if len(examples) < 10:
                examples.append(f"  0x{off:04X}  measured {mw:.0f}x{mh:.0f}  "
                                f"rendered {sw:.0f}x{sh:.0f}")

    rule = "OLD (halve the group header)" if args.old else \
           "corrected (group header is a pivot, subtracted whole)"
    total = ok + thin + bad
    print(f"{args.port} {args.bank}"
          f"{'' if args.bank == 'video2' else f' stage {args.stage}'}: "
          f"{total} polygons compared against the renderer")
    print(f"rule: {rule}\n")
    print(f"  {ok:5d}  agree exactly")
    print(f"  {thin:5d}  differ, and contain a degenerate line leaf "
          f"(renderer widens it by 2)")
    print(f"  {bad:5d}  differ for another reason")
    if unparsed:
        print(f"  {unparsed:5d}  the renderer emitted, but parse_polygon_tree "
              f"rejected")
    for e in examples:
        print(e)
    if bad:
        print("\nFAIL: the format is still being misread.")
        return 1
    print("\nEvery disagreement is the degenerate-leaf drawing convention.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
