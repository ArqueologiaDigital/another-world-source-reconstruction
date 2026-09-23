#!/usr/bin/env python3
"""Which unnamed constants anywhere in the game are text?

Question answered
-----------------
PASSCODE and CODE_WHEEL both draw short code strings as a group of inlined
5x7 character sub-groups, and both were decoded by matching each sub-group's
shape against the named font. That method is not stage-specific, so this asks
the obvious next question: **is there text anywhere else?**

The answer, today, is no. Every `CINEMATIC_<n>` in all nine stages of both
priority ports was tested and none decodes fully. The 36-glyph font is used
by exactly the two stages that display codes, which is a reasonable thing for
a game to do and is now measured rather than assumed.

Keep running it. The font grows as glyphs are named -- it currently gets 36
shapes from `CINEMATIC_PASSCODE_FONT_*` plus three CODE_WHEEL variants of H, J
and L -- so a constant that fails today can decode tomorrow.

How a match works
-----------------
`sig()` reduces a subtree to the sorted set of its solid leaves' boxes,
translated so the subtree's own bounding box starts at the origin. That makes
the signature invariant to where the character sits inside its string, which
is what lets an inlined character match a standalone glyph constant --
`canonical_md5` cannot, because it serialises the header bytes including the
group pivot.

A constant is reported only when EVERY child matches. A partial match is not
printed, because a string with one unknown character is exactly where a
plausible-but-wrong reading comes from; `../passcode-glyph-probes/` records
what that cost the first time.

Usage
-----
    python3 notes/dispatch-ladders/decode_text_constants.py
    python3 notes/dispatch-ladders/decode_text_constants.py --partial
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree                  # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
       "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
BY_X = lambda c: c[0]                                        # noqa: E731


def leaves(n, ox=0.0, oy=0.0, out=None):
    if out is None:
        out = []
    if n is None:
        return out
    if n[0] == "solid":
        w, h, pts = n[1], n[2], n[3]
        xs = [ox - w / 2 + px for px, py in pts]
        ys = [oy - h / 2 + py for px, py in pts]
        out.append((min(xs), min(ys), max(xs), max(ys)))
    else:
        for px, py, _c, sub in n[3]:
            leaves(sub, ox - n[1] + px, oy - n[2] + py, out)
    return out


def sig(n):
    ls = leaves(n)
    if not ls:
        return None
    mx = min(l[0] for l in ls)
    my = min(l[1] for l in ls)
    return tuple(sorted((round(a - mx, 1), round(b - my, 1),
                         round(c - mx, 1), round(d - my, 1))
                        for a, b, c, d in ls))


def font() -> dict:
    """Signature -> character, from every glyph this tree has named."""
    fm: dict = {}
    b8 = slab("cinematic", "msdos", 8)
    t8 = (SRC / "src/levels/dos_1992/PASSCODE.asm").read_text(errors="replace")
    for n, v in re.findall(r"^(CINEMATIC_PASSCODE_FONT_[A-Z0-9_]+)\s+EQU\s+"
                           r"(0x[0-9A-Fa-f]+)", t8, re.M):
        fm[sig(parse_polygon_tree(b8, int(v, 16)))] = n.split("_")[-1]
    # CODE_WHEEL's bank has its own art for H, J and L; harvest every
    # character of every already-decoded string so those variants are known.
    b0 = slab("cinematic", "msdos", 0)
    t0 = (SRC / "src/levels/dos_1992/CODE_WHEEL.asm").read_text(
        errors="replace")
    for n, v in re.findall(r"^(CINEMATIC_CODEWHEEL_CODE_[A-Z0-9_]+)\s+EQU\s+"
                           r"(0x[0-9A-Fa-f]+)", t0, re.M):
        txt = n.replace("CINEMATIC_CODEWHEEL_CODE_", "").replace("_STRING", "")
        tr = parse_polygon_tree(b0, int(v, 16))
        if tr is None or tr[0] != "group":
            continue
        for child, ch in zip(sorted(tr[3], key=BY_X), txt):
            fm.setdefault(sig(child[3]), ch)
    return fm


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--partial", action="store_true",
                    help="also show constants where only SOME children match")
    args = ap.parse_args()

    fm = font()
    print(f"font: {len(fm)} signature(s)\n")
    full = partial = 0
    for port, br in sorted(PORTS.items()):
        for stage, sid in SID.items():
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            try:
                b = slab("cinematic", port, sid)
            except BaseException as exc:
                print(f"  ({port}/{stage} skipped: {exc})")
                continue
            equ = {n: int(v, 16) for n, v in re.findall(
                r"^(CINEMATIC_\d+)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                p.read_text(errors="replace"), re.M)}
            for n, o in sorted(equ.items()):
                tr = parse_polygon_tree(b, o)
                if tr is None or tr[0] != "group" or not tr[3]:
                    continue
                chs = [fm.get(sig(c[3])) for c in sorted(tr[3], key=BY_X)]
                if all(c is not None for c in chs):
                    full += 1
                    print(f"  {port}/{stage:<11}{n:<18} -> {''.join(chs)}")
                elif args.partial and any(c is not None for c in chs):
                    partial += 1
                    print(f"  {port}/{stage:<11}{n:<18} ?  "
                          f"{''.join(c or '?' for c in chs)}")
    print(f"\n{full} constant(s) decode fully as text.")
    if args.partial:
        print(f"{partial} decode partially -- NOT a reading, see the "
              f"docstring.")
    elif full == 0:
        print("The font is used only by the two stages that display codes, "
              "and both are named.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
