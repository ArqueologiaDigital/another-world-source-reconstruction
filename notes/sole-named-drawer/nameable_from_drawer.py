#!/usr/bin/env python3
"""Polygons the routine layer can name, instead of the other way round.

Question answered
-----------------
`notes/caller-derived-naming/named_art_only.py` established the direction of
the backlog: the big stages' routine layer waits on their polygon layer,
because a routine drawing only unidentified art cannot be named from it. That
is true of the bulk. It is not true of everything, and this measures the
exception -- **unnamed polygons whose drawer is already named**, where the
dependency runs the other way and the polygon layer is the one that can move.

Across the two priority ports, 799 unnamed `CINEMATIC_<index>` constants are
drawn by exactly one routine and that routine has a semantic name. That number
is the *pool*, not the yield, and the gap between them is the whole point of
this file: a routine's name describes the routine, and only sometimes
describes its art.

Two counter-examples from CAVES, both real:

  * `FILL_PAGE_00_COLOR_08` draws two constants. It is a mechanism name. The
    art is not "a page fill".
  * `CAVES_SCREEN_70_BACKDROP_DRAW` draws three, and two of them are drawn by
    *other* screens' backdrop routines as well. A shared layer named for one
    screen would be wrong for the others -- the shape of #0118.

So the rule here is deliberately narrow, and it is the narrowness that makes
the result applicable without a render:

  1. the routine's name is semantic and denotes a **subject**, not a
     mechanism. This was originally "ends in `_DRAW`", which is a strong
     signal and far too narrow a one: after the routine layer gained 284
     names from the shared bank, the `_DRAW` form matched **zero** of them,
     because those are spelled `DRAW_HERO_WALK_RIGHT_F03`. The rule is now
     the mechanism filter plus the raw-index filter, which is what `_DRAW`
     was standing in for. `SHARED_RET`, `PRISON_SHOT_STATE_FRAME_DISPATCH_LEFT`
     and `CAVES_BUDDY_IDLE_HOLD_PHASE_14` all reached the candidate list when
     the suffix went and are excluded by name-shape, not by hand;
  2. it draws exactly one distinct constant, and that constant is still
     `CINEMATIC_<index>`;
  3. no other routine in the stage draws it;
  4. it is not drawn at `x=[0x07], y=[0x08]` (#0138 -- no actor claim);
  5. the derived name is not already taken in that file;
  6. **no other port has already derived a different name for the same
     art.** Rule 5 compares name strings, which cannot see this: the two
     ports' routines for one picture are often worded differently, so each
     port derives its own name and the picture ends up with two. That is
     exactly what happened on the first run of the widened rule --
     `CINEMATIC_BIOMETRIC_SCAN_LINE_SWEEP_ACROSS` on amiga against
     `CINEMATIC_BIOMETRIC_SCAN_RIGHTWARD_LINE` on msdos, and
     `CINEMATIC_LESTER_PRONE_BODY` against `CINEMATIC_LESTER_PRONE_STILL_HOLD`,
     both caught afterwards by `crossport-transfer --duplicates`. Rule 6
     compares the **art**, by `canonical_md5` over the parsed tree, and holds
     both rows so a human names the intersection.

The constant then takes the routine's name. One routine, one draw, one user:
there is no index to invent and no second subject to confuse.

Verify, do not just transfer
----------------------------
A name arriving this way should still be checked against the art's measured
shape, because the check is nearly free and it has teeth. For the eight this
reported on 2026-09-19 it passed loudly: the two teleport beams measure 6x94
and 6x80 with 4 leaves -- a thin vertical sliver, which is what a beam is --
and the two backdrops measure 538x436 with 240 leaves and 544x470 with 24.
Cross-port the four pairs are identical in extent, leaf count and corners at
different indices (amiga 856/854/432/540, msdos 879/877/453/561), which is
the offset-and-render agreement NAMING.md wants and never an index match.

Usage
-----
    python3 notes/sole-named-drawer/nameable_from_drawer.py
    python3 notes/sole-named-drawer/nameable_from_drawer.py --pool
    python3 notes/sole-named-drawer/nameable_from_drawer.py --proposals OUT.md

`--pool` prints the wider 799 instead, grouped by drawer, for picking further
batches by hand. Those need a render; the default list does not.

A second, weaker rule: `--animations`
-------------------------------------
A named routine whose WHOLE draw set is still numeric and is drawn nowhere
else is an animation whose frames can take the routine's name indexed by draw
order. 63 routines and 322 constants qualify on the two priority ports -- but
"frames" has to be earned, so the anchor decides it: **one anchor for every
draw means frames of one thing; several anchors mean props along a path**,
and a prop needs identifying on its own. That split is 44 routines / 205
constants fixed against 19 / 117 moving.

It still needs the mechanism filter above, which is why this mode reports
rather than proposes. `FILL_PAGE_00_COLOR_08` and
`TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C` both pass every structural test and
neither name describes its art.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from naming_census import classify                      # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parents[0].parent))
from actor_slot import actor_slot_matcher  # noqa: E402

# All four branches. The two priority ports are amiga and MS-DOS, but the
# cartridge and GBA builds gate them: the routine-naming pass cannot rename a
# label those builds share unless they have a proposal for it too, and 81
# otherwise-good routine renames were blocked on exactly that. Their
# cinematic constants are their own -- a per-port bank at per-port offsets --
# so the sole-named-drawer rule applies to them independently.
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)")
# Matched through notes/actor_slot.py, which resolves aliases: PRISON,
# CAPSULE and ENDING spell the slot `[BUDDY_X],[BUDDY_Y]` and the
# literal test saw none of it.
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_V = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)\s*,"
                  r"\s*x=(\S+?)\s*,\s*y=(\S+?)(?:\s*,|\s*$)")
# A routine's name has to denote a SUBJECT for its art to inherit it. These
# denote a mechanism, a timer or a side effect, and the art they happen to
# draw is not "a page fill" or "a random delay". Found by reading the
# fixed-anchor list, not guessed: every one of these is a real row it would
# otherwise have proposed.
MECHANISM = ("FILL_PAGE", "RANDOM_DELAY", "PLAY_SOUND", "ENTRY_POINT",
             "SET_VAR", "COPY_", "JUMP_TO", "KILL_CHANNEL", "SETUP_CHAN",
             "_AT_RET", "FOLD_BODY", "DEDUP", "BLINK_PAGE",
             # added when rule 1 was widened past the `_DRAW` suffix: these
             # reached the candidate list and none of them names a picture.
             "SHARED_RET", "DISPATCH", "_TICK", "_HOLD_PHASE", "DELAY_LOOP",
             "PRELOAD", "SCROLL_STEP", "PAGE_",
             # A name that says the routine CHOOSES something is a selector,
             # not a subject. Caught by the verify-the-shape step rather than
             # by inspection: PRISON_TELEPORT_UP_POSE_BY_FACING draws a
             # 6x94 four-leaf vertical sliver -- a beam -- so the picture is
             # not "a pose selected by facing", it is what the selector
             # happened to draw.
             "_BY_FACING", "_BY_STATE", "_SELECT",
             # KILL_CHANNEL did not catch KILL_ALL_CHANNELS_AND_KILL, which
             # reached the apply step as CINEMATIC_KILL_ALL_CHANNELS_AND_KILL.
             "KILL_ALL", "_AND_KILL", "_AND_RET", "_THEN_RET")
# A routine whose own name carries a raw constant index -- DRAW_CITY_SEQ_435_436,
# DRAW_CINEMATICS_166_TO_171, DRAW_INTRO_DECOR_337 -- is itself a placeholder
# under NAMING.md §1, whatever else it says. Deriving constant names from it
# would copy the placeholder onto the art.
RE_RAWINDEX = re.compile(r"_\d{3,}(_|$)")
RE_EQU_NAME = re.compile(r"^([A-Za-z_]\w*)\s+EQU\s", re.M)
UNIFIED_PREFIX = {"chahi_amiga_1991": "amiga", "dos_1992": "dos",
                  "cartridge_1992": "cart", "gba_2004": "gba"}
# A name ending in a raw hex token is the forbidden form of NAMING.md §1, and
# it arrives here by inheritance: PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_9A and
# CAVES_BARRIER_BREACH_EVENT_CASE_8A are routine names that carry a literal
# from their own `jne`, and transferring them would copy an address-shaped
# suffix onto a picture. Two-digit decimals like `_04` are a family index and
# are allowed; a token with a hex letter in it is not.
RE_HEXTAIL = re.compile(r"_[0-9A-F]*[A-F][0-9A-F]*$")

# A name ending in a THRESHOLD token is the same inheritance bug that
# RE_HEXTAIL catches, except the token is decimal and so looks exactly like a
# family index. `CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04` is not frame 4: it is
# the arm of a binary search over the impact timer, entered for timer values
# {4,5}, and the picture it draws is the one for value 5. Copying the label's
# number onto the art gets the frame off by one and records a comparison
# threshold where an index belongs -- and it names only the arms that happen to
# carry a label, leaving the rest behind `DRAW_CIN_<n>` fallthroughs, which
# shows up downstream as a family with a hole in it. That hole was how this was
# found; see ../laser-impact-anim/README.md.
#
# Measured over the whole tree: of the 36 distinct labels ending _ABOVE_<n>,
# _UPTO_<n> or _BELOW_<n>, 34 are directly the target of an inequality
# (`jg`/`jl`/`jge`/`jle`) on the variable their ladder switches on. The two
# that are not -- PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_16, reached by `call`, and
# PRISON_SCREEN_FLOOR_Y_LOOKUP_UPTO_04, reached by `jne` -- are arms of those
# same ladders and carry a threshold inherited from a sibling, so they are no
# more a frame index than the rest.
#
# `_OVER_<n>` is deliberately NOT in this set. All four of its labels are
# CREDITS_SCROLL_RENDER_PAGE_80_OVER_83 and kin, where 80 and 83 are page
# numbers and "over" is compositing, not comparison.
RE_THRESHOLD = re.compile(r"_(ABOVE|UPTO|BELOW)_[0-9A-F]+$")


# A namer strips the words that describe the routine's plumbing rather than
# its subject, so the derived constant base is not the routine name verbatim.
# The cross-port check below has to use the SAME base a namer would, or it
# compares the wrong string and passes a collision: amiga defines
# CINEMATIC_LESTER_EXITING_CAR_F13, and against the unstripped
# CINEMATIC_LESTER_EXITING_CAR_ANIMATION it looks free.
DROP_PREFIX = ("DRAW_",)
DROP_SUFFIX = ("_AFTER_HOLD", "_ANIM_LOOP", "_ANIMATION", "_DRAW_LOOP",
               "_SCROLL_LOOP", "_RUN", "_LOOP")


def derived_base(routine: str) -> str:
    """The `CINEMATIC_<...>` stem a namer would give this routine's frames."""
    r = routine
    for pre in DROP_PREFIX:
        if r.startswith(pre):
            r = r[len(pre):]
    for suf in DROP_SUFFIX:
        if r.endswith(suf):
            r = r[:-len(suf)] + ("_SCROLL" if suf == "_SCROLL_LOOP" else "")
            break
    return "CINEMATIC_" + r


def parse(path: Path) -> dict[str, list[str]]:
    bodies: dict[str, list[str]] = {}
    cur = None
    for line in path.read_text(errors="replace").splitlines():
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            bodies.setdefault(cur, [])
            continue
        if cur is not None:
            t = line.split(";", 1)[0]
            if t.strip():
                bodies[cur].append(t)
    return bodies


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--pool", action="store_true")
    ap.add_argument("--animations", action="store_true",
                    help="the second, weaker rule: a named routine whose "
                         "WHOLE draw set is unnamed and exclusive to it, "
                         "split by whether the anchor is fixed")
    ap.add_argument("--proposals", type=Path)
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()

    rows: list[tuple[str, str, str, str]] = []
    pool: list[tuple[str, str, str, str]] = []
    skipped = collections.Counter()
    for port in args.port or sorted(PORTS):
        for stage in STAGES:
            path = ROOT / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if not path.is_file():
                continue
            bodies = parse(path)
            text = path.read_text()
            at_slot = actor_slot_matcher(text)
            # Every EQU name already defined for this stage, in the canonical
            # file AND in the unified arms that carry this branch's copy. The
            # taken-check used to look only at labels and drawn symbols, so a
            # name that exists as an EQU but is not drawn in this file looked
            # free -- and CINEMATIC_315 was proposed as
            # CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG in cartridge/CAVES,
            # where that name already sat on 0x6B86. Applying it put two EQUs
            # of one name in cart__entry.inc, which moved bytes for
            # genesis_europe and took verify-unified to 28/29.
            equ_names = set(RE_EQU_NAME.findall(text))
            arms = ROOT / "src" / "levels" / "_unified" / stage.lower()
            if arms.is_dir():
                pre = UNIFIED_PREFIX[PORTS[port]]
                for f in arms.rglob("*.inc"):
                    head = f.name.split("__", 1)[0] if "__" in f.name else ""
                    if head and pre not in head.split("_"):
                        continue
                    equ_names |= set(
                        RE_EQU_NAME.findall(f.read_text(errors="replace")))
            drawn: dict[str, set[str]] = collections.defaultdict(set)
            for lab, body in bodies.items():
                for line in body:
                    for m in RE_DRAW.finditer(line):
                        if RE_NUM.match(m.group(1)):
                            drawn[m.group(1)].add(lab)
            for const, labs in drawn.items():
                if len(labs) == 1 and classify(next(iter(labs))) == "semantic":
                    pool.append((port, stage, const, next(iter(labs))))
            for lab, body in bodies.items():
                if classify(lab) != "semantic":
                    continue
                if any(t in lab for t in MECHANISM) or RE_RAWINDEX.search(lab):
                    skipped["name denotes a mechanism, not a subject"] += 1
                    continue
                if RE_HEXTAIL.search(lab):
                    skipped["name ends in a raw hex token (§1)"] += 1
                    continue
                if RE_THRESHOLD.search(lab):
                    skipped["name ends in a comparison threshold, not an "
                            "index"] += 1
                    continue
                seq = [m.group(1) for line in body
                       for m in RE_DRAW.finditer(line)]
                nums = [c for c in seq if RE_NUM.match(c)]
                if len(set(seq)) != 1 or len(nums) != 1:
                    continue
                const = nums[0]
                if drawn[const] != {lab}:
                    continue
                if any(at_slot(line) for line in body):
                    skipped["draws at the actor slot (#0138)"] += 1
                    continue
                # derived_base already prepends CINEMATIC_; the `_DRAW`
                # branch does not, and concatenating both gave
                # CINEMATIC_CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT.
                new = ("CINEMATIC_" + lab[:-len("_DRAW")]
                       if lab.endswith("_DRAW") else derived_base(lab))
                if new in bodies or new in drawn or new in equ_names:
                    skipped["derived name already taken"] += 1
                    continue
                rows.append((port, stage, const, new))

    if args.animations:
        fixed: list = []
        moving: list = []
        mech = 0
        taken = 0
        # Every CINEMATIC_* name each port already defines, per stage. A
        # derived name that the OTHER port already uses for other art turns
        # a naming pass into a #0107 disagreement -- which is what happened
        # on 2026-09-19: naming msdos/INTRO's LESTER_EXITING_CAR_F0..F12
        # from its drawer moved the cross-port audit from 10 disagreements
        # to 23, because amiga already carries those names for other
        # frames. The per-port collision check cannot see it, by design:
        # a branch-scoped rename is judged against that branch's files.
        defined: dict = {}
        for prt in PORTS:
            for stg in STAGES:
                f = ROOT / "src" / "levels" / PORTS[prt] / f"{stg}.asm"
                if f.is_file():
                    defined[(prt, stg)] = set(
                        re.findall(r"^(CINEMATIC_\w+)\s+EQU", 
                                   f.read_text(errors="replace"), re.M))
        for port in args.port or sorted(PORTS):
            for stage in STAGES:
                path = ROOT / "src" / "levels" / PORTS[port] / f"{stage}.asm"
                if not path.is_file():
                    continue
                bodies = parse(path)
                at_slot = actor_slot_matcher(path.read_text())
                seen: dict[str, set[str]] = collections.defaultdict(set)
                for lab, body in bodies.items():
                    for line in body:
                        for m in RE_V.finditer(line):
                            seen[m.group(1)].add(lab)
                for lab, body in bodies.items():
                    if classify(lab) != "semantic":
                        continue
                    vs = [(m.group(1), m.group(2), m.group(3))
                          for line in body for m in RE_V.finditer(line)]
                    uniq = list(dict.fromkeys(c for c, _, _ in vs))
                    if len(uniq) < 2 or not all(RE_NUM.match(c) for c in uniq):
                        continue
                    if any(seen[c] != {lab} for c in uniq):
                        continue
                    if any(at_slot(line) for line in body):
                        continue
                    if any(t in lab for t in MECHANISM) or \
                            RE_RAWINDEX.search(lab):
                        mech += 1
                        continue
                    base = derived_base(lab)
                    other = "msdos" if port == "amiga" else "amiga"
                    if any(n.startswith(base) for n
                           in defined.get((other, stage), ())):
                        taken += 1
                        continue
                    anchors = {(x, y) for _, x, y in vs}
                    row = (port, stage, lab, uniq, sorted(anchors)[0])
                    (fixed if len(anchors) == 1 else moving).append(row)
        nf = sum(len(r[3]) for r in fixed)
        nm = sum(len(r[3]) for r in moving)
        print(f"fixed anchor  -> frames of ONE animation: "
              f"{len(fixed)} routines, {nf} constants")
        print(f"moving anchor -> props along a path:      "
              f"{len(moving)} routines, {nm} constants")
        print(f"({mech} routine(s) dropped: the name denotes a mechanism, "
              f"not a subject;\n {taken} dropped: the other port already "
              f"defines that name for other art)\n")
        for port, stage, lab, uniq, anc in sorted(fixed,
                                                  key=lambda r: -len(r[3])):
            print(f"  {port}/{stage:<9} {lab:<48} {len(uniq):>3} frames "
                  f"at {anc[0]},{anc[1]}")
        return 0

    if args.pool:
        by: dict[str, list[str]] = collections.defaultdict(list)
        for port, stage, const, lab in pool:
            by[f"{port}/{stage}  {lab}"].append(const)
        print(f"{len(pool)} unnamed constants have exactly one drawer and it "
              f"is named.\nThese need a render; the default list does not.\n")
        for k in sorted(by, key=lambda k: -len(by[k]))[:40]:
            print(f"  {len(by[k]):3d}  {k}")
        return 0

    print(f"{len(rows)} constant(s) nameable from a sole named drawer:\n")
    for port, stage, const, new in rows:
        print(f"  {port}/{stage:<10} {const:<18} -> {new}")
    for why, n in skipped.items():
        print(f"\n  ({n} skipped: {why})")
    # Rule 6: two ports deriving different names for one picture.
    try:
        sys.path.insert(0, str(Path(__file__).resolve().parents[1]
                               / "polygon-extent-correction"))
        from polygon_tree import canonical_md5, parse_polygon_tree
        from extent_matches_renderer import slab
        RE_EQU2 = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
        SID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3,
               "CAVES": 4, "TANK": 5, "CAPSULE": 6, "ENDING": 7,
               "PASSCODE": 8}
        # Rule 6 needs the port's cinematic ROM. snes_eu and gba_usa have no
        # extracted resources, and slab() raises SystemExit for them -- which
        # is a BaseException and escaped the handler below, aborting the whole
        # run once the probe was widened to four branches. Ports without a
        # ROM are skipped: the check then covers the pairs it can see, which
        # is the two priority ports, and says so rather than dying.
        have_rom = set()
        for port in PORTS:
            try:
                slab("cinematic", port, 0)
                have_rom.add(port)
            except BaseException:
                pass
        skipped_ports = sorted(set(PORTS) - have_rom)
        art: dict[tuple, str] = {}
        for port, stage, const, new in rows:
            if port not in have_rom:
                continue
            text2 = (ROOT / "src" / "levels" / PORTS[port]
                     / f"{stage}.asm").read_text(errors="replace")
            off = dict(RE_EQU2.findall(text2)).get(const)
            if not off:
                continue
            tree = parse_polygon_tree(slab("cinematic", port, SID[stage]),
                                      int(off, 16))
            if tree is not None:
                art[(port, stage, const)] = canonical_md5(tree)
        bym: dict[tuple, set] = collections.defaultdict(set)
        for (port, stage, const), m in art.items():
            bym[(stage, m)].add(
                next(n for p2, s2, c2, n in rows
                     if (p2, s2, c2) == (port, stage, const)))
        clash = {k for k, v in bym.items() if len(v) > 1}
        if clash:
            drop = {(p2, s2, c2) for (p2, s2, c2), m in art.items()
                    if (s2, m) in clash}
            rows = [r for r in rows if (r[0], r[1], r[2]) not in drop]
            print(f"\n  ({len(drop)} held by rule 6: the two ports derive "
                  f"different names for the same art)")
            for stage, m in sorted(clash):
                print(f"     {stage}: {' vs '.join(sorted(bym[(stage, m)]))}")
        if skipped_ports:
            print(f"\n  (rule 6 covers {', '.join(sorted(have_rom))}; "
                  f"{', '.join(skipped_ports)} have no extracted ROM)")
    except BaseException as exc:                 # ROM not extracted
        print(f"\n  (rule 6 not checked: {exc})")

    if args.proposals:
        ev = ("Sole-named-drawer. The routine's name is semantic and denotes "
              "a subject -- not a mechanism, a selector, a raw index or a hex "
              "tail -- it draws this one constant and nothing else, and no "
              "other routine in the stage draws it, so the routine's subject "
              "is this polygon's subject with no index to invent. Not drawn "
              "at `[0x07],[0x08]`, so no actor is asserted (#0138).")
        # One file per (port, STAGE). A combined per-port file is unsafe:
        # tools/apply_branch_scoped_names.py matches rows by constant number
        # and takes the stage from its own --stage flag, so a file holding
        # PASSCODE and PRISON rows together will write PASSCODE's names onto
        # PRISON's art. Caught in a dry run that offered
        # CINEMATIC_013 -> CINEMATIC_PASSCODE_ALPHANUM_CODE_CASE_03 for PRISON.
        for port, stage in sorted({(r[0], r[1]) for r in rows}):
            out = args.proposals.with_name(
                args.proposals.stem + f"_{port}_{stage}"
                + args.proposals.suffix)
            with out.open("w") as f:
                f.write("| constant | proposed name | confidence | evidence |\n")
                f.write("| --- | --- | --- | --- |\n")
                for p, s, c, n in rows:
                    if (p, s) == (port, stage):
                        f.write(f"| {c} | {n} | high | {ev} |\n")
            print(f"\nwrote {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
