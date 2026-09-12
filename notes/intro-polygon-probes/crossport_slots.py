#!/usr/bin/env python3
"""Compare one drawing routine's `video offset=` draw list across ports.

Question it answers: "does port A's routine R draw the same polygons, in the
same slots, at the same x,y as port B's routine R -- and does either port
already have a semantic name for the polygon in that slot?"

That slot-by-slot alignment is the evidence used to carry a semantic
CINEMATIC_* name from one port to another, and to detect a name that has
landed on the wrong offset in one port's EQU table.

Usage:
    crossport_slots.py LEVEL ROUTINE [port ...]
e.g.
    crossport_slots.py INTRO DRAW_PARTICLE_LAB_BG_COMPOSITE
    crossport_slots.py INTRO LESTER_HAND_PRESSING_KEYPAD_ANIMATION

Default ports: chahi_amiga_1991 dos_1992 cartridge_1992 gba_2004.
Read it as: slot N of the routine, in each port, as "NAME (offset)".  A slot
where one port shows a semantic name and another shows CINEMATIC_<digits> is a
naming gap; a slot where two ports show *different* semantic names, or the same
name at different offsets, is a mis-assignment to investigate.
"""
import os, re, sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                    "..", "..", "src", "levels")
PORTS = ["chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004"]


def load(port, level):
    path = os.path.join(ROOT, port, level + ".asm")
    if not os.path.exists(path):
        return None, None
    txt = open(path).read()
    equ = dict(re.findall(r"^(\S+)\s+EQU (0x[0-9A-Fa-f]+)$", txt, re.M))
    return txt, equ


def draws(txt, routine):
    lines = txt.split("\n")
    try:
        i = lines.index(routine + ":")
    except ValueError:
        return None
    out = []
    for ln in lines[i + 1:]:
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*:", ln):
            break
        m = re.match(r"\s*video offset=(\S+?),\s*x=(\S+?),\s*y=([^,\s]+)", ln)
        if m:
            out.append(m.groups())
        if re.match(r"\s*(killChannel|ret)\s*$", ln):
            break
    return out


def main():
    level, routine = sys.argv[1], sys.argv[2]
    ports = sys.argv[3:] or PORTS
    tables = {}
    for p in ports:
        txt, equ = load(p, level)
        if txt is None:
            print(f"{p}: no {level}.asm")
            continue
        d = draws(txt, routine)
        if d is None:
            print(f"{p}: no routine {routine}")
            continue
        tables[p] = [(n, equ.get(n, "?"), x, y) for n, x, y in d]
    width = max((len(p) for p in tables), default=0)
    for slot in range(max((len(v) for v in tables.values()), default=0)):
        print(f"slot {slot}:")
        for p, rows in tables.items():
            if slot < len(rows):
                n, off, x, y = rows[slot]
                print(f"  {p:<{width}}  {n:<52} {off:<8} @{x},{y}")
        print()


if __name__ == "__main__":
    main()
