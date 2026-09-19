"""Is this draw at the shared actor slot? Aliases count.

Issue #0138 bars naming an actor from a draw at `[0x07],[0x08]`: the pair is
a shared actor-record slot, loaded from whichever record the dispatcher last
rotated in, so the occupant is not knowable at the draw site.

Every probe in this tree tested that with the literal
`x=\\[0x07\\]\\s*,\\s*y=\\[0x08\\]`, and on 2026-09-19 that turned out to
miss most of it. PRISON, CAPSULE and ENDING alias the pair:

    BUDDY_X		EQU 0x07
    BUDDY_Y		EQU 0x08

and then write `x=[BUDDY_X], y=[BUDDY_Y]` everywhere. Measured over both
priority ports: **1,027 draws use the literal form and 1,844 use an alias**,
so the literal test saw about a third of the slot and reported zero for the
three stages that use it most -- the same three where the routine-naming
backlog is. Worse than under-reporting: the probes that EXCLUDE actor-slot
draws before offering a name were offering PRISON, CAPSULE and ENDING
candidates they should have refused.

The alias is not a fix for #0138 either. `BUDDY_X` names the slot after one
possible occupant, which is the very claim the issue says cannot be made at
the draw site; that it reads as a name rather than an address is what made
it invisible.

Usage
-----
    from actor_slot import actor_slot_matcher
    at_slot = actor_slot_matcher(path.read_text())
    if any(at_slot(line) for line in body): ...
"""

from __future__ import annotations

import re

RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)
RE_DRAW_XY = re.compile(r"x=\[(\w+)\]\s*,\s*y=\[(\w+)\]")


def actor_slot_names(text: str) -> tuple[set[str], set[str]]:
    """The spellings of variable 0x07 and 0x08 in this file, aliases included."""
    xs = {"0x07"}
    ys = {"0x08"}
    for m in RE_EQU.finditer(text):
        v = m.group(2).lower()
        if v in ("0x07", "0x7"):
            xs.add(m.group(1))
        elif v in ("0x08", "0x8"):
            ys.add(m.group(1))
    return xs, ys


def actor_slot_matcher(text: str):
    """A predicate: does this line draw at the shared actor slot?"""
    xs, ys = actor_slot_names(text)

    def at_slot(line: str) -> bool:
        m = RE_DRAW_XY.search(line)
        return bool(m and m.group(1) in xs and m.group(2) in ys)

    return at_slot
