#!/usr/bin/env python3
"""CAVES' hero direction machine: which routine is which, derived not guessed.

Question answered
-----------------
CAVES carries a four-state machine for the hero's facing. Ten entry points are
already named in both priority ports --
`START_HERO_DIRECTION_<A>_TO_<B>_TURN` for every ordered pair of
LEFT/RIGHT/UP/DOWN -- but eight of the ten **bodies** they install were still
`LABEL_<hex>`, as were two of the four steady-state loops. The names were
sitting one indirection away from the routines that need them.

This derives the whole machine from the assembly, so the names are read off a
table rather than proposed:

  * the dispatcher's input -> state mapping, from the compare immediates;
  * for each `START_..._TURN`, the body it installs on channel 0x15, plus a
    count of **every** `setup` in the stage that installs that body;
  * for each body, the `[0x63]` state it leaves behind, the loop it falls into,
    and the routine it installs on channel 0x16.

The installer count is the part that makes this safe to act on. A body reached
from two different entry points cannot take either one's name -- that is issue
#0118 (two labels, one name) arriving from the other direction. The tool exits
non-zero if any body has more than one installer, so a future edit that merges
two transitions cannot quietly invalidate the names this pass applied.

The signal being read
---------------------
`[0x63]` is the hero state variable. `HERO_POS_JUMP_DOWN` (0xFB) is the VM's
vertical input: **-1 when up is held, +1 when down is held**. That sign is not
assumed here -- it is corroborated inside the same file by
`je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_JUMP_LEFT_RUN_PRELUDE`, an
already-earned name where -1 is the jump key.

What it does NOT settle
-----------------------
The art. See `layer_colour_census.py` next to this file: the body layer and the
channel-0x16 layer are disjoint in colour, and the second layer's anatomy is
**not** identified. No name applied from this table describes a body part.

Usage
-----
    python3 notes/hero-direction-machine/derive_state_map.py
    python3 notes/hero-direction-machine/derive_state_map.py --port amiga
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_SETUP = re.compile(r"setup\s+channel=(0x[0-9A-Fa-f]+),\s*address=(\w+)")
RE_STATE = re.compile(r"mov\s+\[0x63\],\s*(0x[0-9A-Fa-f]+)")
RE_JMP = re.compile(r"^\s*jmp\s+(\w+)")
RE_START = re.compile(r"^START_HERO_DIRECTION_([A-Z]+)_TO_([A-Z]+)_TURN$")
RE_CMP = re.compile(r"jne\s+\[(\w+)\],\s*(0x[0-9A-Fa-f]+),")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=(\w+)")


def bodies(path: Path) -> dict[str, list[str]]:
    """label -> its lines, up to the next column-0 label."""
    out: dict[str, list[str]] = {}
    cur = None
    for line in path.read_text(errors="replace").splitlines():
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            out.setdefault(cur, [])
            continue
        if cur is not None:
            out[cur].append(line.split(";", 1)[0])
    return out


def dispatcher(bod: dict[str, list[str]]) -> dict[int, str]:
    """state id -> the input condition that selects it.

    The dispatcher is a fallthrough ladder: each rung tests one input against
    one immediate and, when it matches, sets [0x63]. `jne X, V, SKIP` means the
    assignment below it runs when X == V, so the rung's condition is the
    immediate in the `jne`.
    """
    seen: dict[int, str] = {}
    label = "HERO_DIRECTION_STATE_FROM_INPUT"
    if label not in bod:
        return seen
    order = list(bod)
    i = order.index(label)
    pend: tuple[str, str] | None = None
    for lab in order[i:i + 12]:
        for line in bod[lab]:
            c = RE_CMP.search(line)
            if c:
                pend = (c.group(1), c.group(2))
                continue
            s = RE_STATE.search(line)
            if s and pend:
                val = int(s.group(1), 16)
                sign = "-1" if pend[1] == "0xFFFF" else f"+{int(pend[1], 16)}"
                seen.setdefault(val, f"{pend[0]} == {sign}")
                pend = None
    return seen


def trace(body: list[str]) -> dict:
    """What a transition body leaves behind: state, chan-0x16 loop, next loop."""
    state, ch16, nxt = None, None, None
    art = []
    for line in body:
        s = RE_STATE.search(line)
        if s:
            v = int(s.group(1), 16)
            if v != 0x64:          # 0x64 is the "in transition" sentinel
                state = v
        u = RE_SETUP.search(line)
        if u and u.group(1) == "0x16":
            ch16 = u.group(2)
        j = RE_JMP.match(line)
        if j:
            nxt = j.group(1)
        d = RE_DRAW.search(line)
        if d:
            art.append(d.group(1))
    return {"state": state, "ch16": ch16, "next": nxt, "art": art}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()
    bad = 0
    for port in args.port or ["amiga", "msdos"]:
        path = ROOT / "src" / "levels" / PORTS[port] / "CAVES.asm"
        bod = bodies(path)
        text = path.read_text(errors="replace")
        installs: dict[str, int] = {}
        for m in RE_SETUP.finditer(text):
            installs[m.group(2)] = installs.get(m.group(2), 0) + 1

        print(f"\n=== {port}/CAVES")
        disp = dispatcher(bod)
        print("  dispatcher, [0x63] <- input:")
        for k in sorted(disp):
            print(f"    state {k}  when  {disp[k]}")

        print(f"\n  {'entry point':<40}{'body':<34}{'inst':>5}"
              f"{'->state':>8}  {'idle loop':<32}{'chan 0x16':<14}")
        rows = []
        for lab in bod:
            m = RE_START.match(lab)
            if not m:
                continue
            inst = [RE_SETUP.search(l) for l in bod[lab]]
            body = next((x.group(2) for x in inst
                         if x and x.group(1) == "0x15"), None)
            if body is None:
                continue
            n = installs.get(body, 0)
            t = trace(bod.get(body, []))
            rows.append((lab, body, n, t))
            flag = "" if n == 1 else "  <-- NOT sole installer"
            if n != 1:
                bad += 1
            print(f"  {lab:<40}{body:<34}{n:>5}{str(t['state']):>8}  "
                  f"{str(t['next']):<32}{str(t['ch16']):<14}{flag}")

        # the steady-state loops, keyed by the state they re-assert
        print("\n  steady-state loops (the [0x63] each re-asserts on entry):")
        for lab in bod:
            first = next((l for l in bod[lab] if l.strip()), "")
            s = RE_STATE.search(first)
            if s and int(s.group(1), 16) in (1, 2, 3, 4):
                reach = sorted({r[3]["next"] for r in rows
                                if r[3]["next"] == lab})
                if reach:
                    print(f"    state {int(s.group(1), 16)}  {lab:<34}"
                          f"reached by {sum(1 for r in rows if r[3]['next'] == lab)}"
                          f" transition(s)")
    if bad:
        print(f"\n{bad} body/bodies have more than one installer -- a name "
              f"taken from one\nentry point would be wrong there (#0118).")
        return 1
    print("\nEvery transition body has exactly one installer, so each may take "
          "the name of\nthe START_ entry point that installs it.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
