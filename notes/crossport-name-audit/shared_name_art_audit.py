#!/usr/bin/env python3
"""Do the two priority ports agree about what a shared polygon name draws?

Question answered
-----------------
A polygon name is earned by rendering, in one port. `docs/NAMING.md` §2 then
forbids carrying it to another port's symbol: "Never take a name earned on one
port's render to another port's symbol. It would be right 2% of the time."
Issue #0107 is that rule being broken, and it has been broken more than once --
sixteen CAPSULE names in an earlier pass, and six CAVES hero-idle names on
2026-09-19, all of them landing at the SAME EQU-table index in the other port,
which is the same line number, because the tables are emitted in index order.

Those were found one family at a time, by suspicion. This measures the whole
tree instead: for every semantic `CINEMATIC_*` name defined in both priority
ports, it measures the art each port's symbol actually points at and reports
the ones that disagree.

What it measures
----------------
Per name, in each port's own ROM slab: the md5 of the whole parsed polygon
tree at that port's offset. Agreement means the two ports' symbols hold the
same picture, which is what a shared name claims. It never compares indices.

This started out keyed on the extent plus the leaf count, which is the
project's long-standing test and is very nearly as strong -- of 1,426 names
it called equal, 1,423 survive the md5. The three that do not were reported
as agreements, so the headline was 56 disagreements when it is **59**. The
weaker key also could not break a tie: where two constants in a port share an
extent it matched both, and the permutation was refused as inconsistent in
INTRO, PRISON and CAPSULE. Under md5 exactly one of each pair matches and all
three refusals go away.

For a disagreement the tool also searches the other port's whole table for a
constant whose art DOES match, and names it. That is the constructive half:
it says not just "this name is wrong here" but "this is the constant it
belongs on".

Result on 2026-09-19
--------------------
1,482 shared semantic names compared, **1,400 agree and 82 do not**, spread
over CAVES 26, PRISON 19, LAKE 17, INTRO 10, CAPSULE 9, PASSCODE 1. CAVES'
26 were corrected the same day; re-keying the identity on md5 then moved the
remainder from 56 to 59.

The disagreements are shuffles, not noise. msdos's
`CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING` measures 410x253 with 525 leaves,
which is exactly what amiga's `CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0` measures;
msdos's own `..._BG_0` is a 37x4 eight-leaf sliver. The names were copied by
index and landed on each other's art.

Caveat, stated plainly
----------------------
Disagreement is not proof of misapplication. The ports really do differ: the
1991 release has frames the 1992 ports dropped, so a family can legitimately
hold neighbouring frames at one index. What makes a row actionable is the
second column -- a different constant in the same port whose art matches
exactly -- plus a check of which routine draws it. Treat the list as a
worklist, not a verdict.

And the emitter carries an assumption that is **not** always true: it rewrites
msdos to match amiga, which assumes amiga is the port that got it right. That
was never justified, and measuring found two stages where it is false --
PRISON, whose ZOOM_IN families grow monotonically in msdos and shrink in
amiga although the name says zoom IN, and INTRO, whose PARTICLE_LAB_BG frames
measure 190x26, 342x182 and 30x28 in amiga against a coherent 149x114,
190x116, 149x203 in msdos. `better_ordered_elsewhere` refuses both, and after
that refuses every stage that still has disagreements. That is the correct
state: CAVES was the one stage where amiga was demonstrably right, and it has
been corrected.

Exit status
-----------
1 when any shared name disagrees, so the count cannot drift upward unnoticed.

Usage
-----
    python3 notes/crossport-name-audit/shared_name_art_audit.py
    python3 notes/crossport-name-audit/shared_name_art_audit.py --stage CAVES
    python3 notes/crossport-name-audit/shared_name_art_audit.py --suggest
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                       # noqa: E402
from polygon_tree import (parse_polygon_tree,      # noqa: E402
                          canonical_md5)
from polygon_extent import extent                  # noqa: E402

STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SLAB = 0x10000
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


# Both spellings occur: `..._LEFT_3` and `..._BG_F3`. Matching only
# the first made every `_F<n>` family invisible to the guards below,
# which is how INTRO's PARTICLE_LAB_BG passed a check designed to
# catch exactly it.
RE_FAM = re.compile(r"^(.*?)_(F?)(\d+)$")


def better_ordered_elsewhere(diff: set, tabs: dict, art: dict) -> list[str]:
    """Families where the port we would REWRITE looks better ordered.

    The emitter moves msdos's names to match amiga's art, which silently
    assumes amiga is the port that got it right. PRISON proves that
    assumption is not free. Its `PRISON_CUTSCENE_ZOOM_IN_LEFT/RIGHT`
    families disagree across the ports, and measuring the frames settles
    which port is wrong without a render:

        msdos LEFT   48x142 62x235 66x233 68x235 70x236 72x234 73x234 ...
        amiga LEFT   70x236 68x235 66x233 62x235 56x235 52x235 50x239 ...

    The name says ZOOM_IN. msdos grows monotonically, which is what zooming
    in looks like; amiga shrinks, and its RIGHT family is not even monotonic.
    **amiga is the misordered port here**, so "correcting" msdos to match it
    would have destroyed a correctly ordered family and propagated the error.

    So: for every indexed family touched by a disagreement, compare the width
    sequences. If msdos's is monotonic and amiga's is not, the emission is
    refused for that stage and the family is named. This is a guard, not a
    verdict -- it does not claim msdos is right, only that amiga is not
    evidently right, which is all the emitter needs to stop.
    """
    fams: dict[tuple[str, str], set[int]] = collections.defaultdict(set)
    for n in diff:
        m = RE_FAM.match(n)
        if m:
            fams[(m.group(1), m.group(2))].add(int(m.group(3)))
    # a family member absent from one port cannot be compared, but the rest
    # of the family still can, so only the missing index is dropped
    for key in list(fams):
        base, sep = key
        fams[key] = {i for i in fams[key]
                     if all(art[p].get(f"{base}_{sep}{i}") for p in PORTS)}
    bad = []
    for (base, sep), idxs in fams.items():
        fam = base + ("_" + sep if sep else "")
        if len(idxs) < 3:
            continue
        seqs = {}
        for port in PORTS:
            w = []
            for i in sorted(idxs):
                a = art[port].get(f"{base}_{sep}{i}")
                w.append(a[1][0] if a else None)
            seqs[port] = w
        if any(x is None for v in seqs.values() for x in v):
            continue
        def mono(v):
            return (all(x < y for x, y in zip(v, v[1:]))
                    or all(x > y for x, y in zip(v, v[1:])))
        if mono(seqs["msdos"]) and not mono(seqs["amiga"]):
            bad.append(f"{fam} (monotonic in msdos, not in amiga)")
            continue
        # Second signal, which monotonicity misses. Frames of one thing are
        # about the same size. INTRO's PARTICLE_LAB_BG measures 190x26,
        # 342x182 and 30x28 in amiga -- a 30x28 five-leaf polygon is not a
        # lab background -- against 149x114, 190x116 and 149x203 in msdos.
        # Neither sequence is monotonic, because these are backdrop frames
        # and not a zoom, so the first check passes them both.
        def spread(v):
            return max(v) / min(v) if min(v) > 0 else float("inf")
        if spread(seqs["amiga"]) > 3 * spread(seqs["msdos"]):
            bad.append(f"{fam} (widths vary {spread(seqs['amiga']):.1f}x in "
                       f"amiga against {spread(seqs['msdos']):.1f}x in msdos)")
    return bad


def emit_permutation(stage: str, tabs: dict, art: dict, rev: dict,
                     out: Path) -> None:
    """The correction as ONE rename table, promotions and demotions together.

    A correction is a permutation and cannot be applied a row at a time: the
    symbol that wrongly holds a name has to give it up in the same batch that
    puts the name on the right constant. Emitting halves of it would be
    rejected by the rename validator, correctly.

    Demotion targets are the index the msdos EQU table position gives.
    `apply_branch_scoped_names.py --demote` recomputes them independently and
    refuses any that disagree, so this file proposing a wrong index cannot
    turn into a wrong index on disk.
    """
    order = list(tabs["msdos"])
    idx = {n: i for i, n in enumerate(order)}
    shared = [n for n in tabs["amiga"]
              if not RE_NUM.match(n) and n in tabs["msdos"]]
    diff = {n for n in shared
            if art["amiga"][n] and art["msdos"][n]
            and art["amiga"][n][0] != art["msdos"][n][0]}
    owner: dict = collections.defaultdict(list)
    for n in shared:
        if art["amiga"][n]:
            owner[art["amiga"][n][0]].append(n)
    rows: dict[str, str] = {}
    for n in order:
        a = art["msdos"][n]
        cands = ([x for x in owner.get(a[0], []) if x in diff]
                 if a else [])
        if len(cands) == 1 and cands[0] != n:
            rows[n] = cands[0]
        elif n in diff:
            rows[n] = f"CINEMATIC_{idx[n]}"
    clash = [t for t, c in collections.Counter(rows.values()).items() if c > 1]
    if clash:
        print(f"{stage}: NOT emitted -- {len(clash)} target collision(s); "
              f"the permutation is not consistent", file=sys.stderr)
        return
    worse = better_ordered_elsewhere(diff, tabs, art)
    if worse:
        print(f"{stage}: NOT emitted -- this would rewrite msdos to match "
              f"amiga, and amiga is not\n  evidently the port that got it "
              f"right. Settle which is authoritative first:", file=sys.stderr)
        for w in worse:
            print(f"    {w}", file=sys.stderr)
        return
    left = sorted(diff - set(rows.values()))
    if left:
        # A shuffle within the stage is closed: every disagreeing name finds
        # the constant holding its art. When names find NO home the cause is
        # something else and a blanket demotion would be wrong.
        #
        # LAKE, 2026-09-19: 16 of 17 found no home, and the reason is not a
        # copy at all -- msdos draws the hero from the SHARED bank and keeps a
        # 2x5 per-frame companion locally, so the name landed on the
        # companion. The art is not missing, it is in video2.rom. See
        # notes/shared-bank-naming/cv_subject_from_other_port.py, which pairs
        # those names to CV_ symbols and verifies each by extent.
        #
        # Emitting a demotion-only table here would have demoted seventeen
        # names on a diagnosis this tool cannot make, so it refuses and says
        # what to look at.
        print(f"{stage}: NOT emitted -- {len(left)} of {len(diff)} "
              f"disagreeing name(s) find no constant holding their art, so "
              f"this is not a\n  shuffle within the stage. Check whether the "
              f"art moved to the shared bank before\n  demoting anything: "
              f"{left[:4]}{' ...' if len(left) > 4 else ''}",
              file=sys.stderr)
        return
    base = (f"Cross-port name audit: {len(diff)} shared semantic name(s) in "
            f"{stage} disagreed about their art between the priority ports, "
            f"the signature of a name copied by EQU-table index rather than "
            f"earned on this port's render (#0107). Identity is extent and "
            f"leaf count measured in each port's own ROM slab, never an "
            f"index. The set resolves to one consistent permutation of "
            f"{len(rows)} constants with no target collision.")
    with out.open("w") as f:
        f.write("| constant | proposed name | confidence | evidence |\n")
        f.write("| --- | --- | --- | --- |\n")
        for src, dst in sorted(rows.items(),
                               key=lambda kv: (bool(RE_NUM.match(kv[1])),
                                               kv[1])):
            if RE_NUM.match(dst):
                ev = (f"{base} Demotion: this symbol's art is not what its "
                      f"name claims and no other name matches it, so it "
                      f"returns to the index its EQU table position gives. A "
                      f"false name is worse than a number.")
            else:
                ev = (f"{base} This constant's polygon tree is identical to "
                      f"amiga's `{dst}` -- same md5 over every vertex, not "
                      f"merely the same extent -- so the name belongs here.")
            f.write(f"| {src} | {dst} | high | {ev} |\n")
    print(f"{stage}: wrote {out} -- {len(rows)} row(s), "
          f"{sum(1 for v in rows.values() if RE_NUM.match(v))} "
          f"demotion(s); every disagreeing name found a home")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", action="append")
    ap.add_argument("--proposals", type=Path,
                    help="write the msdos correction as a rename table: the "
                         "whole permutation, promotions and demotions "
                         "together, which is the only way it can be applied")
    ap.add_argument("--suggest", action="store_true",
                    help="for each disagreement, the other port's constant "
                         "whose art matches")
    args = ap.parse_args()
    want = set(args.stage) if args.stage else None

    roms = {}
    for p in PORTS:
        f = REPO_ROOT / "tmp" / "output" / p / "romset" / "cinematic.rom"
        if not f.is_file():
            print(f"{f} missing -- run `make extract`", file=sys.stderr)
            return 2
        roms[p] = f.read_bytes()

    tot = collections.Counter()
    rows: list[tuple] = []
    for si, stage in STAGES.items():
        if want and stage not in want:
            continue
        tabs = {}
        for port, br in PORTS.items():
            f = ROOT / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                tabs = {}
                break
            tabs[port] = {m.group(1): int(m.group(2), 16)
                          for m in RE_EQU.finditer(f.read_text(errors="replace"))}
        if len(tabs) < 2:
            continue
        slabs = {p: roms[p][si * SLAB:(si + 1) * SLAB] for p in PORTS}

        def measure(port: str, off: int):
            """(identity, display) -- md5 of the whole tree, and the extent.

            The identity used to BE the extent plus the leaf count, which is
            the project's long-standing test and is very nearly as strong:
            of 1,426 shared names it called equal, 1,423 are equal under the
            md5 of the parsed tree. Three are not, so the weaker test was
            reporting three disagreements as agreements.

            It also could not break a tie. Where two constants in one port
            share an extent, an extent-keyed search matched both and the
            permutation was refused as inconsistent -- which looked like
            #0120, a tool being asked to choose between two names, and was
            really just a blunt instrument. Under md5 exactly one of each
            pair matches, in all three stages where this happened.
            """
            t = parse_polygon_tree(slabs[port], off)
            a = extent(t)
            if a[4] == 0:
                return None
            return (canonical_md5(t),
                    (round(a[2] - a[0]), round(a[3] - a[1]), a[4]))

        art = {p: {n: measure(p, o) for n, o in tabs[p].items()} for p in PORTS}
        # reverse index for the suggestion: art -> names, per port
        rev = {p: collections.defaultdict(list) for p in PORTS}
        for p in PORTS:
            for n, a in art[p].items():
                if a:
                    rev[p][a[0]].append(n)

        if args.proposals:
            emit_permutation(stage, tabs, art, rev, args.proposals)
            continue

        for name in tabs["amiga"]:
            if RE_NUM.match(name) or name not in tabs["msdos"]:
                continue
            a, m = art["amiga"][name], art["msdos"][name]
            if a is None or m is None:
                tot["unparsable in one port"] += 1
                continue
            tot["shared semantic names compared"] += 1
            if a[0] == m[0]:
                tot["  art agrees"] += 1
            else:
                tot["  art DIFFERS"] += 1
                holder = [x for x in rev["msdos"].get(a[0], []) if x != name]
                rows.append((stage, name, a[1], m[1], holder))

    for k, v in tot.items():
        print(f"{v:6d}  {k}")
    if rows:
        print("\ndisagreements by stage:")
        for k, v in collections.Counter(r[0] for r in rows).most_common():
            print(f"  {v:5d}  {k}")
        print("\n  stage      name"
              "                                     amiga        msdos")
        for stage, name, a, m, holder in sorted(
                rows, key=lambda r: (-abs(r[2][2] - r[3][2]))):
            s = (f"  {stage:<9} {name:<45} "
                 f"{a[0]}x{a[1]}/{a[2]:<6} {m[0]}x{m[1]}/{m[2]}")
            if args.suggest and holder:
                s += f"\n{'':<12}-> msdos holds amiga's art under {holder[0]}"
            print(s)
        print(f"\n{len(rows)} shared name(s) disagree about their art. "
              f"Disagreement is not proof:\nthe releases really do differ. A "
              f"row is actionable when --suggest finds the same\nart in the "
              f"other port under another name, and the routine that draws it "
              f"agrees.")
        return 1
    print("\nEvery shared semantic polygon name holds the same art in both "
          "priority ports.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
