#!/usr/bin/env python3
"""Name the routine that paints a screen's backdrop, from the layers it paints.

Question answered
-----------------
499 pictures are already named `CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>`
across PRISON, CAVES and CAPSULE, but only **10** routines are named
`<STAGE>_SCREEN_<NN>_BACKDROP_DRAW`. The rest of the painters are still
`LABEL_CDB2`, `JUNK__9DD7`, `DRAW_CIN_305_TO_309_5F_AT_AACB4DF5` -- generated
names, two of those three forms carrying a raw hex tail that `docs/NAMING.md`
§1 forbids -- while every picture in their body already states, by name, which
screen's backdrop they are painting.

That is a name sitting one hop away from where it is needed. The rule is the
one `../draw-label-follows-constant/` established in the other direction: a
label whose body is one draw takes its picture's name. Here the body is a
*layer stack*, and the stack agrees with itself.

The two sources, and why they are independent
---------------------------------------------
A routine is proposed only when both of these give the same screen:

1. **Its own layers.** Every named picture it draws is
   `CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP...` for a single NN. A routine that
   draws two screens' named layers, or a named picture that is not a backdrop
   layer at all, is dropped -- it is not a single screen's painter.
2. **`../screen-scope/`**, the forward dataflow on `[SCREEN_NUM]`, which pins
   the label to exactly {NN} because every path that reaches it has already
   tested the guard and found NN.

These do not share an input. Source 1 reads names a person wrote from the art;
source 2 reads `je`/`jne` guards in the bytecode and was never told the names
exist. When a rename is driven by one of them, the other is a check on it.

Where the layers are all still numbered, source 1 has nothing to say. Those
routines are proposed only when the **other port** independently derives the
same screen for the routine drawing byte-identical art -- two separate
disassemblies, same answer. `--pairs` shows that matching.

Which names may be replaced
---------------------------
Only generated ones: `LABEL_<hex>`, `JUNK__<hex>`, `DRAW_CIN_..._AT_<hash>`,
`FILL_PAGE_<n>_COLOR_<n>`. A descriptive name someone earned from the art --
`DRAW_STALACTITE_CAVERN_BG`, `DRAW_BUDDY_CRAWLING_BG` -- is left alone even
when the dataflow pins its screen, under hazard #0120: two earned names is not
a reason to pick. The screen is recorded in this module's output instead.

The control
-----------
The 10 routines already named `<STAGE>_SCREEN_<NN>_BACKDROP_DRAW` were named
by a person from other evidence. `--control` re-derives each one's NN from
both sources and exits 1 on any disagreement. It is the same shape of check
`../screen-scope/ --control` runs, one level up: there the claim was about a
screen guard, here it is about a painter.

Usage
-----
    python3 notes/backdrop-drawer/backdrop_drawer.py --control
    python3 notes/backdrop-drawer/backdrop_drawer.py
    python3 notes/backdrop-drawer/backdrop_drawer.py --pairs
    python3 notes/backdrop-drawer/backdrop_drawer.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC / "notes" / "screen-scope"))
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
import screen_scope                                          # noqa: E402
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from polygon_extent import extent                            # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
# The cartridge and GBA trees carry painter names that `align_branch_names.py`
# pushed across from the priority ports. A screen NUMBER does not travel --
# amiga CAPSULE calls a screen 0x4C that msdos calls 0x6C -- so those names
# have to be checked against each port's OWN guards. --control and
# --audit-layers therefore run over these too. They are not naming targets
# here: the cartridge romsets ship no extracted cinematic bank, so nothing in
# this module can measure their art.
AUDIT_PORTS = dict(PORTS, cart="cartridge_1992", gba="gba_2004")
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=(\d+),\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*),\s*x=([^,]+),\s*y=([^,\s]+)")
RE_WIPE = re.compile(r"^\s*(fill|copyVideoPage)\s")
# redisasm_db.py: TERMINATING_OPCODES = {0x05 ret, 0x07 jmp, 0x11 killChannel}.
# Everything after one of these, up to the next label, is unreachable from the
# label above it.
RE_END = re.compile(r"^\s*(ret\s*$|jmp\s|db 0x11\s*$)")
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)

# A generated label states how the disassembler found it, not what it does.
# Only these may be replaced; anything else is a name someone earned.
RE_GENERIC = re.compile(r"^(LABEL_[0-9A-F]+|JUNK__[0-9A-F]+"
                        r"|DRAW_CIN_.*_AT_[0-9A-F]{8}"
                        r"|FILL_PAGE_[0-9A-Fx]+_COLOR_[0-9A-Fx]+)$")
RE_DRAWER = re.compile(r"^([A-Z]+)_SCREEN_([0-9A-F]{2})_BACKDROP_DRAW$")


def layer_screen(name: str, stage: str):
    """The screen a named picture claims, or None if it claims none."""
    m = re.match(rf"^CINEMATIC_{stage}_SCREEN_([0-9A-F]{{2}})_BACKDROP",
                 name)
    return int(m.group(1), 16) if m else None


def bodies(lines):
    """{label: (pictures drawn, all anchors literal?, wipes the page?)}.

    A label's body runs to the next label **or to the first terminating
    opcode**, whichever comes first, so a routine that falls through into the
    next one is credited only with its own draws. Both halves of that were
    forced by a case:

        LABEL_9C52:
                fill page=0x00, color=0x08
                video offset=CINEMATIC_522, ...
                video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F1, ...
                ...
                ret
                                                  <- no label here
                video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_5, ...
                video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_6, ...
                ret

    Stopping only at the next label credited `LABEL_9C52` with two layers it
    cannot reach, and those two were its ONLY claim to a screen -- the probe
    would have named a routine that draws the buddy smashing a window after
    the backdrop of screen 0x92. `redisasm_db.py` already lists the three
    opcodes that end a routine; this uses the same three.

    The two flags are what separate a backdrop painter from any other routine
    that happens to run under a screen guard. A backdrop is scenery: every
    layer goes at a literal `x,y`, never at `[BUDDY_X]` or the hero slot.
    Without that test the dataflow happily labels `LABEL_136B` -- two frames
    of the buddy walking, drawn at `[BUDDY_X],[BUDDY_Y]` -- the backdrop of
    the screen it walks across, which is exactly the `#0138` error in a new
    costume: the scene a figure is drawn in does not name the figure, and the
    figure does not name the scene.
    """
    out: dict[str, list] = {}
    lit: dict[str, bool] = {}
    wipe: dict[str, bool] = {}
    done: dict[str, bool] = {}
    cur = None
    for line in lines:
        if m := RE_LBL.match(line):
            cur = m.group(1)
            out.setdefault(cur, [])
            lit.setdefault(cur, True)
            wipe.setdefault(cur, False)
            done.setdefault(cur, False)
            continue
        if cur is None or done.get(cur):
            continue
        if RE_END.match(line):
            done[cur] = True
            continue
        if RE_WIPE.match(line):
            wipe[cur] = True
            continue
        if v := RE_V.match(line):
            out[cur].append(v.group(2))
            x, y = v.group(3).strip(), v.group(4).strip()
            if not (x.isdigit() and y.isdigit()):
                lit[cur] = False
    return {k: (v, lit[k], wipe[k]) for k, v in out.items()}


def full_screen_set(port: str, stage: str, sid: int):
    """The pictures in this stage's bank that cover the whole 240x160 view.

    Empty when the port ships no extracted cinematic bank, which is the
    cartridge case. `backdroplike` then falls back to "literal anchors and a
    page wipe", which is strictly narrower, so an audited port can only be
    judged on routines that clear the page first. That is stated rather than
    hidden: a cartridge painter with no `fill` is simply not looked at.
    """
    f = SRC / "src" / "levels" / AUDIT_PORTS[port] / f"{stage}.asm"
    if not f.is_file():
        return set()
    try:
        bank = slab("cinematic", port, sid)
    except BaseException:
        return set()
    equ = {n: int(v, 16)
           for n, v in RE_EQU.findall(f.read_text(errors="replace"))}
    out = set()
    for name, off in equ.items():
        try:
            x0, y0, x1, y1, _lv = extent(parse_polygon_tree(bank, off))
        except Exception:
            continue
        if (x1 - x0) >= 240 and (y1 - y0) >= 160:
            out.add(name)
    return out


def analyse_port_stage(port: str, stage: str):
    """-> (rows, drawn_by) where a row is one label's two screen readings."""
    lines = screen_scope.load(port, stage)
    if lines is None:
        return [], {}
    scoped, _at = screen_scope.analyse(lines)
    body = bodies(lines)
    big = full_screen_set(port, stage, STAGE_ID[stage])

    drawn_by: dict[str, set] = collections.defaultdict(set)
    for lab, (pics, _l, _w) in body.items():
        for p in pics:
            drawn_by[p].add(lab)

    rows = []
    for lab, (pics, literal, wipes) in sorted(body.items()):
        if not pics:
            continue
        # A backdrop painter puts scenery at literal coordinates and either
        # clears the page first or paints something that covers it.
        backdroplike = literal and (wipes or any(p in big for p in pics))
        # Source 1: what this routine's own already-named layers say.
        # A picture named descriptively -- CINEMATIC_CAPSULE_ARCH_WALL_FAR --
        # claims no screen. It is not evidence for one and it is not evidence
        # against one either, so it must not veto the layers that do claim
        # one: a backdrop is allowed to contain a named prop. Only a SECOND
        # positive claim is a contradiction.
        claims = {layer_screen(p, stage) for p in pics
                  if not re.match(r"^(CINEMATIC_\d+|CV_[0-9A-F]{4})$", p)}
        positive = {c for c in claims if c is not None}
        by_layers = next(iter(positive)) if len(positive) == 1 else None
        # Source 2: the dataflow on [SCREEN_NUM].
        ctx = scoped.get(lab)
        by_flow = next(iter(ctx)) if ctx is not None and len(ctx) == 1 else None
        rows.append({"label": lab, "pics": pics, "layers": by_layers,
                     "flow": by_flow, "mixed": len(positive) > 1,
                     "backdroplike": backdroplike})
    return rows, drawn_by


_ART_CACHE: dict = {}


def art_key(port, stage, sid, pics):
    """An order-independent fingerprint of the art a routine paints.

    Used only to match a routine in one port against its counterpart in the
    other, so it must not depend on a name: the ports index their cinematic
    banks differently (hazard #0107) and a name moved by index lands on
    unrelated art. The bytes are the bridge, as everywhere else.

    The first version hashed 512 raw bytes from each offset, which matched
    **nothing** -- the polygon is shorter than that, so the hash was mostly
    whatever art happened to follow it in the bank, and that differs between
    ports by construction. It reported "0 pairs" and looked like a finding.
    `canonical_md5` hashes the parsed polygon tree instead, which is what the
    rest of the project uses for exactly this reason.
    """
    key = (port, stage)
    if key not in _ART_CACHE:
        f = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
        equ = {n: int(v, 16)
               for n, v in RE_EQU.findall(f.read_text(errors="replace"))}
        bank = slab("cinematic", port, sid)
        md: dict[str, str] = {}
        for name, off in equ.items():
            try:
                md[name] = canonical_md5(parse_polygon_tree(bank, off))
            except Exception:
                pass
        _ART_CACHE[key] = md
    md = _ART_CACHE[key]
    if any(p not in md for p in pics):
        return None
    return "|".join(sorted(md[p] for p in pics))


def equ_position(port: str, stage: str) -> dict:
    """{constant: its row number in the stage's CINEMATIC EQU table}."""
    f = SRC / "src" / "levels" / AUDIT_PORTS[port] / f"{stage}.asm"
    if not f.is_file():
        return {}
    rows = re.findall(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+0x[0-9A-Fa-f]+",
                      f.read_text(errors="replace"), re.M)
    return {n: i for i, n in enumerate(rows)}


def guards() -> int:
    """Where the four branches disagree about what to call a screen.

    `align_branch_names.py` carries a routine name across ports by aligned
    instruction stream, which is right for a routine name and wrong for one
    holding a screen NUMBER. It backported msdos'
    `CAPSULE_SCREEN_6C_BACKDROP_DRAW` onto the aligned amiga routine, and the
    control caught it. This is the measurement that settled which port was
    right, kept runnable because the commit quotes it: a value one port never
    compares `[SCREEN_NUM]` against is not a screen that port has.
    """
    print("  screen values one branch guards on and another never does:\n")
    print(f"  {'stage':<10}{'value':<8}" +
          "".join(f"{p:>8}" for p in AUDIT_PORTS))
    n = 0
    for stage in STAGE_ID:
        counts: dict[str, dict] = {}
        for port, branch in AUDIT_PORTS.items():
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            c = collections.Counter()
            if f.is_file():
                for m in re.finditer(r"\[SCREEN_NUM\],\s*(0x[0-9A-Fa-f]+)",
                                     f.read_text(errors="replace")):
                    c[int(m.group(1), 16)] += 1
            counts[port] = c
        present = [p for p in AUDIT_PORTS if counts[p]]
        for v in sorted({v for p in present for v in counts[p]}):
            seen = [counts[p][v] for p in present]
            if 0 in seen and any(seen):
                n += 1
                print(f"  {stage:<10}0x{v:02X}    " +
                      "".join(f"{counts[p][v]:>8}" if p in present
                              else f"{'-':>8}" for p in AUDIT_PORTS))
    print(f"\n  {n} value(s) guarded by at least one branch and not by "
          f"another. A name carrying one of these is branch-scoped, whatever "
          f"`align_branch_names.py` thinks.\n")

    # A tested guess, kept because it failed. The disagreeing CAPSULE values
    # look like a constant offset -- amiga 0x4C against msdos 0x6C, 0x4D
    # against 0x6D, 0x49 against 0x69 -- which would mean the ports number the
    # same grid from a different row, 0x20 being one row of the 32-column grid
    # `docs/` measures. They do not: no shift beats shift zero anywhere.
    print("  is the difference a constant shift of the screen grid?\n")
    print(f"  {'stage':<10}{'amiga':>7}{'msdos':>7}{'shared':>8}"
          f"   best shift other than 0")
    for stage in STAGE_ID:
        g = {}
        for port in ("amiga", "msdos"):
            f = SRC / "src" / "levels" / AUDIT_PORTS[port] / f"{stage}.asm"
            g[port] = {int(m, 16) for m in re.findall(
                r"\[SCREEN_NUM\],\s*0x([0-9A-Fa-f]+)",
                f.read_text(errors="replace"))} if f.is_file() else set()
        a, m = g["amiga"], g["msdos"]
        if not a or not m:
            continue
        best = max(((len({v + d for v in a} & m), d)
                    for d in range(-0x60, 0x61) if d), default=(0, 0))
        print(f"  {stage:<10}{len(a):>7}{len(m):>7}{len(a & m):>8}"
              f"   {best[1]:+#06x} hits {best[0]}/{len(a)}, against "
              f"{len(a & m)}/{len(a)} at shift 0")
    print("\n  No shift wins. CAPSULE simply is not the same set of screens "
          "in the two ports -- amiga guards 32 distinct values, msdos 59 --"
          "\n  which is the same thing `../cross-port-art/` records for "
          "CAVES, where msdos has three screens amiga does not.")
    return 0


def audit_layers(data, as_proposals: bool) -> int:
    """Which `..._SCREEN_<NN>_BACKDROP_LAYER_<i>` names claim the wrong screen?

    The name asserts that the picture is part of screen NN's backdrop. The
    weakest check that asserts anything: **at least one routine that draws it
    must be on screen NN**, where "on screen NN" means the routine's own name
    says so or `../screen-scope/`'s dataflow pins it there. If every routine
    that paints the picture is demonstrably on some other screen, the name is
    making a claim about a screen nothing connects it to.

    This is deliberately weaker than the rule that governs *new* layer names,
    which also requires exclusivity. A picture shared between two screens has
    a defensible name under this audit and an indefensible one under that
    rule, and the difference is the point: demoting a name needs proof it is
    wrong, not absence of proof that it is right.

    A routine the dataflow cannot pin counts as neither for nor against, so a
    layer drawn from even one unpinned routine is left alone.

    Demoting, not renaming
    ----------------------
    A demoted name goes back to `CINEMATIC_<index>`, and the index
    `apply_branch_scoped_names.py --demote` insists on is the constant's
    position in the stage's EQU table. That convention is checked here rather
    than assumed: across msdos CAVES, of the 908 CINEMATIC EQU rows, **0** of
    the ones still carrying a number disagree with their table position.
    """
    out: dict[tuple, list] = collections.defaultdict(list)
    held = collections.Counter()
    for (port, stage), (rows, drawn_by) in sorted(data.items()):
        where: dict[str, int | None] = {}
        for r in rows:
            m = RE_DRAWER.match(r["label"])
            if m and m.group(1) == stage:
                where[r["label"]] = int(m.group(2), 16)
            else:
                where[r["label"]] = r["flow"]
        seen: set[str] = set()
        for r in rows:
            for pic in r["pics"]:
                if pic in seen:
                    continue
                seen.add(pic)
                want = layer_screen(pic, stage)
                if want is None or "_BACKDROP_LAYER_" not in pic:
                    continue
                painters = sorted(drawn_by[pic])
                got = [where.get(l) for l in painters]
                if any(g is None for g in got):
                    held["a routine that draws it cannot be pinned"] += 1
                    continue
                if want in got:
                    held["a routine that draws it is on that screen"] += 1
                    continue
                pos = equ_position(port, stage).get(pic)
                out[(AUDIT_PORTS[port], stage)].append(
                    (pic, want, painters, got, pos))
    if not as_proposals:
        n = sum(len(v) for v in out.values())
        print(f"{n} layer name(s) claim a screen no routine that draws them "
              f"is on\n")
        for (branch, stage), rows in sorted(out.items()):
            for pic, want, painters, got, _pos in rows:
                seen_s = ", ".join(f"{l}=0x{g:02X}"
                                   for l, g in zip(painters, got))
                print(f"  {branch:<18}{stage:<9}{pic}")
                print(f"      claims 0x{want:02X}; painted only by {seen_s}")
        print()
        for why, c in held.most_common():
            print(f"  held: {c:>4}  {why}")
        return 0
    for (branch, stage), rows in sorted(out.items()):
        print(f"\n----- {branch} / {stage} -----")
        print("| constant | proposed name | confidence | evidence |")
        print("| --- | --- | --- | --- |")
        for pic, want, painters, got, pos in sorted(rows):
            seen_s = "; ".join(f"`{l}` is on screen 0x{g:02X}"
                               for l, g in zip(painters, got))
            print(f"| {pic} | CINEMATIC_{pos} | high | the name claims screen "
                  f"0x{want:02X}, and every routine that draws this picture "
                  f"is on another screen: {seen_s}. Nothing connects the "
                  f"picture to 0x{want:02X}, so it goes back to its EQU table "
                  f"position {pos} |")
    return 0


def layers(data, as_proposals: bool) -> int:
    """Name a painter's still-numbered layers, once the painter has a screen.

    63 routines gained a screen in this module's first pass, and a layer one of
    them paints is that screen's backdrop layer at the position the machine
    draws it. Two restrictions do all the work:

    * the layer must be painted by **that routine and nothing else** in the
      stage. `../remaining-art/` states the rule from the case that forced it:
      CAVES screens 0x92 and 0x93 share their base and their top layer and
      differ in one, so the two shared ones belong to neither screen. 104
      layers are shared that way.
    * the index is the **draw position** in the painter's body, so the name
      says where in the stack the layer goes.

    Those two together mean the whole stack must be exclusive or none of it
    can be named. A stack with a shared position would be named 0, 1, 3, 4 and
    `docs/NAMING.md` §2 bars a family with a hole in its index run.

    I first assumed `_BACKDROP_LAYER` was exempt from §2, on the grounds that
    a hole there means "shared position" rather than "missing frame", and that
    the tree already contained such families. It does not: of **140**
    `_BACKDROP_LAYER` families across all branches, **0** have a gap, against
    12 gapped families among the other 610. The exception was not there to
    discover, so the rule is applied as written and a stack with any shared
    position is left alone entirely.

    A tested guess that failed
    --------------------------
    If a shared layer were a tall scroll strip, the screens sharing it would
    be a column -- numbers differing by 0x20, one row in the 32-column grid
    `docs/` measures. They are not. The two-screen cases differ by 0x01, 0x1E
    and 0x42, and most shared layers are also painted by routines with no
    screen at all. There is no strip; they are just shared art.
    """
    out: dict[tuple, list] = collections.defaultdict(list)
    held = collections.Counter()
    for (port, stage), (rows, drawn_by) in sorted(data.items()):
        for r in rows:
            m = RE_DRAWER.match(r["label"])
            if not m or m.group(1) != stage or not r["backdroplike"]:
                continue
            screen = m.group(2)
            bad = [p for p in r["pics"]
                   if drawn_by[p] != {r["label"]} or r["pics"].count(p) != 1]
            if bad:
                held["the stack has a position it does not own, so naming the "
                     "rest would leave a hole (NAMING.md §2)"] += len(
                         [p for p in r["pics"]
                          if re.match(r"^CINEMATIC_\d+$", p)])
                continue
            for i, pic in enumerate(r["pics"]):
                if not re.match(r"^CINEMATIC_\d+$", pic):
                    continue
                new = (f"CINEMATIC_{stage}_SCREEN_{screen}_BACKDROP"
                       f"_LAYER_{i}")
                out[(PORTS[port], stage)].append(
                    (pic, new, r["label"], i, len(r["pics"])))
    if not as_proposals:
        n = sum(len(v) for v in out.values())
        print(f"{n} still-numbered layer(s) nameable\n")
        for k, v in sorted(out.items()):
            print(f"  {k[0]:<20}{k[1]:<9}{len(v):>4}")
        print()
        for why, c in held.most_common():
            print(f"  held: {c:>4}  {why}")
        return 0
    for (branch, stage), rows in sorted(out.items()):
        print(f"\n----- {branch} / {stage} -----")
        print("| constant | proposed name | confidence | evidence |")
        print("| --- | --- | --- | --- |")
        for pic, new, lab, i, n in sorted(rows, key=lambda t: t[1]):
            print(f"| {pic} | {new} | high | `{lab}` paints this screen's "
                  f"backdrop and draws this picture at position {i} of {n}; "
                  f"no other routine in the stage draws it, so it belongs to "
                  f"that backdrop and to no other |")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true",
                    help="re-derive the screen of every routine already named "
                         "<STAGE>_SCREEN_<NN>_BACKDROP_DRAW, from both sources")
    ap.add_argument("--pairs", action="store_true",
                    help="show the cross-port matching used where a routine's "
                         "layers are all still numbered")
    ap.add_argument("--audit-layers", action="store_true",
                    help="find layer names claiming a screen no routine that "
                         "draws them is on")
    ap.add_argument("--layers", action="store_true",
                    help="name the still-numbered layers of the routines that "
                         "now carry a screen")
    ap.add_argument("--guards", action="store_true",
                    help="how many times each port compares [SCREEN_NUM] to "
                         "each value, per stage -- the measurement that says "
                         "a screen number belongs to one port")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    if args.guards:
        return guards()

    wide = args.control or args.audit_layers
    data = {}
    for port in (AUDIT_PORTS if wide else PORTS):
        for stage in STAGE_ID:
            data[(port, stage)] = analyse_port_stage(port, stage)

    if args.control:
        ok = bad = 0
        for (port, stage), (rows, _db) in sorted(data.items()):
            for r in rows:
                m = RE_DRAWER.match(r["label"])
                if not m or m.group(1) != stage:
                    continue
                want = int(m.group(2), 16)
                hit = [s for s in (r["layers"], r["flow"]) if s is not None]
                agree = (bool(hit) and all(s == want for s in hit)
                         and r["backdroplike"])
                ok += agree
                bad += not agree
                def show(v):
                    return "-" if v is None else f"0x{v:02X}"
                print(f"  {port:<6}{stage:<9}{r['label']:<36}"
                      f"name 0x{want:02X}   layers {show(r['layers'])}   "
                      f"flow {show(r['flow'])}   "
                      f"{'painter' if r['backdroplike'] else 'NOT-A-PAINTER'}"
                      f"   {'AGREE' if agree else '**'}")
        print(f"\n  {ok} agree, {bad} do not")
        return 1 if bad else 0

    if args.audit_layers:
        return audit_layers(data, args.proposals)

    if args.layers:
        return layers(data, args.proposals)

    # Routines whose layers are all still numbered: match across ports by art.
    unnamed_art: dict[tuple, list] = collections.defaultdict(list)
    for (port, stage), (rows, _db) in data.items():
        for r in rows:
            if r["layers"] is not None or r["flow"] is None:
                continue
            if not r["backdroplike"]:
                continue
            if not RE_GENERIC.match(r["label"]):
                continue
            k = art_key(port, stage, STAGE_ID[stage], r["pics"])
            if k:
                unnamed_art[(stage, k)].append((port, r))

    # A routine whose counterpart in the other port already carries an earned
    # name must not be renamed here. Before this guard the probe named amiga
    # `LABEL_CDB2` CAVES_SCREEN_67_BACKDROP_DRAW while msdos had long called
    # the same routine `DRAW_CAVES_FIRST_ROOM_BG`, which cost that port the
    # descriptive name it would otherwise have inherited. The counterpart is
    # found by the art it paints, never by index (#0107).
    earned_elsewhere: dict[tuple, str] = {}
    by_art: dict[tuple, list] = collections.defaultdict(list)
    for (port, stage), (rows, _db) in data.items():
        for r in rows:
            if not r["backdroplike"]:
                continue
            k = art_key(port, stage, STAGE_ID[stage], r["pics"])
            if k:
                by_art[(stage, k)].append((port, r["label"]))
    for (stage, _k), members in by_art.items():
        named = [(p, l) for p, l in members if not RE_GENERIC.match(l)
                 and not RE_DRAWER.match(l)]
        if not named:
            continue
        for port, lab in members:
            if RE_GENERIC.match(lab):
                earned_elsewhere[(port, stage, lab)] = named[0][1]

    cross: dict[tuple, int] = {}
    pair_rows = []
    for (stage, k), members in sorted(unnamed_art.items()):
        if len({p for p, _ in members}) != 2:
            continue
        flows = {r["flow"] for _p, r in members}
        pair_rows.append((stage, members, flows))
        if len(flows) == 1:
            for port, r in members:
                cross[(port, stage, r["label"])] = next(iter(flows))

    if args.pairs:
        print("Routines whose layers are all still numbered, matched across "
              "the two ports by the md5 of the art they paint:\n")
        for stage, members, flows in pair_rows:
            got = ", ".join(f"{p}:{r['label']}=0x{r['flow']:02X}"
                            for p, r in sorted(members,
                                               key=lambda t: t[0]))
            print(f"  {stage:<9}{got:<62}"
                  f"{'AGREE' if len(flows) == 1 else '** differ'}")
        agree = sum(1 for _s, _m, f in pair_rows if len(f) == 1)
        print(f"\n  {len(pair_rows)} pair(s), {agree} agree")
        return 0 if agree == len(pair_rows) else 1

    props: dict[tuple, list] = collections.defaultdict(list)
    held = collections.Counter()
    disagree: list = []
    for (port, stage), (rows, _db) in sorted(data.items()):
        taken = {r["label"] for r in rows}
        for r in rows:
            lab = r["label"]
            if not RE_GENERIC.match(lab):
                held["name already earned"] += RE_DRAWER.match(lab) is None
                continue
            if not r["backdroplike"]:
                held["not a backdrop painter (figure slot, or no page wipe "
                     "and no full-screen layer)"] += 1
                continue
            if (port, stage, lab) in earned_elsewhere:
                held[f"the other port already calls it "
                     f"{earned_elsewhere[(port, stage, lab)]}"] += 1
                continue
            if r["mixed"]:
                held["its named layers point at two different screens"] += 1
                continue
            src = []
            if r["layers"] is not None and r["flow"] is not None:
                if r["layers"] != r["flow"]:
                    held["its layers and the dataflow disagree"] += 1
                    disagree.append((port, stage, lab, r))
                    continue
                screen = r["layers"]
                src = ["layers", "flow"]
            elif r["layers"] is not None:
                held["dataflow cannot pin it"] += 1
                continue
            elif (port, stage, lab) in cross:
                screen = cross[(port, stage, lab)]
                src = ["flow", "other port"]
            elif r["flow"] is not None:
                held["only the dataflow pins it; its layers are unnamed or "
                     "named for something other than a screen, and the "
                     "other port does not confirm"] += 1
                continue
            else:
                continue
            new = f"{stage}_SCREEN_{screen:02X}_BACKDROP_DRAW"
            if new in taken:
                held["that name is already on another label"] += 1
                continue
            props[(PORTS[port], stage)].append((lab, new, src, r))

    # Two labels cannot share a name (#0118). Where several painters in one
    # file derive the same screen, none of them is *the* painter for it, so
    # all are dropped and counted rather than arbitrarily ranked.
    for key, rows in list(props.items()):
        seen = collections.Counter(n for _l, n, _s, _r in rows)
        keep = [t for t in rows if seen[t[1]] == 1]
        held["several painters in one file derive the same screen"] += (
            len(rows) - len(keep))
        props[key] = keep

    if not args.proposals:
        n = sum(len(v) for v in props.values())
        print(f"{n} backdrop painter(s) nameable\n")
        for k, v in sorted(props.items()):
            two = sum(1 for _l, _n, s, _r in v if s == ["layers", "flow"])
            print(f"  {k[0]:<20}{k[1]:<9}{len(v):>3}  "
                  f"({two} from its own layers + dataflow, "
                  f"{len(v) - two} from dataflow + the other port)")
        print()
        for why, c in held.most_common():
            print(f"  held: {c:>4}  {why}")
        if disagree:
            print("\n  the disagreements, which are the ones worth reading:")
            for port, stage, lab, r in disagree:
                print(f"    {port:<6}{stage:<9}{lab:<20}"
                      f"layers say 0x{r['layers']:02X}, "
                      f"flow says 0x{r['flow']:02X}")
                for pic in r["pics"]:
                    print(f"        {pic}")
        return 0

    for (branch, stage), rows in sorted(props.items()):
        print(f"\n----- {branch} / {stage} -----")
        print("| routine | proposed name | confidence | evidence |")
        print("| --- | --- | --- | --- |")
        for lab, new, src, r in sorted(rows, key=lambda t: t[1]):
            n = len(r["pics"])
            if src == ["layers", "flow"]:
                named = [p for p in r["pics"] if layer_screen(p, stage)
                         is not None]
                ev = (f"draws {n} picture(s), of which {len(named)} are "
                      f"already named for screen 0x{new.split('_')[2]} "
                      f"(`{named[0]}`), and the `[SCREEN_NUM]` dataflow "
                      f"independently pins the routine to that same screen")
            else:
                ev = (f"draws {n} still-numbered picture(s); the "
                      f"`[SCREEN_NUM]` dataflow pins it to this screen, and "
                      f"the other port's routine painting byte-identical art "
                      f"derives the same screen from its own disassembly")
            print(f"| {lab} | {new} | high | {ev} |")
    return 0


if __name__ == "__main__":
    sys.exit(main())
