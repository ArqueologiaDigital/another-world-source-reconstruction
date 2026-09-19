# CAVES' hero direction machine

CAVES runs the hero's facing as a four-state machine in a variable, `[0x63]`.
Ten entry points were **already named in both priority ports** —
`START_HERO_DIRECTION_<A>_TO_<B>_TURN`, one per ordered pair of
LEFT/RIGHT/UP/DOWN — but eight of the ten routines they install were still
`LABEL_<hex>`, and so were two of the four steady-state loops. The names were
one indirection away from the routines that needed them.

## `derive_state_map.py`

**Question it answers.** Which routine is which arm of the machine, read off
the assembly rather than proposed.

    python3 notes/hero-direction-machine/derive_state_map.py
    python3 notes/hero-direction-machine/derive_state_map.py --port amiga

It prints, per port: the dispatcher's input → state mapping; for each
`START_..._TURN` the body it installs on channel 0x15 together with a count of
**every** `setup` in the stage that installs that body; and for each body the
`[0x63]` it leaves behind, the loop it falls into, and what it installs on
channel 0x16.

**The signal being read.** `[0x63]` is the hero state variable.
`HERO_POS_JUMP_DOWN` is VM variable `0xFB` and `HERO_POS_UP_DOWN` is `0xE5`;
both are **−1 while up is held and +1 while down is held**. That sign is not
assumed — it is corroborated inside the same file by
`je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_JUMP_LEFT_RUN_PRELUDE`, an
already-earned name in which −1 is the jump key.

**Pass condition.** Exit 0 means every transition body has exactly one
installer, which is what makes it safe for a body to take its entry point's
name. Exit 1 names the bodies with more than one, where a name taken from one
caller would be wrong (#0118 arriving from the other direction). Run it after
any edit to the machine.

**What it found (2026-09-19).** Both ports agree, which was not a given — the
state ids are a per-port choice and #0107 exists because indices usually do
diverge. Here they do not:

| `[0x63]` | selected when | steady-state loop reached |
|---|---|---|
| 1 | `HERO_POS_LEFT_RIGHT == -1` | LEFT |
| 2 | `HERO_POS_LEFT_RIGHT == +1` | RIGHT |
| 3 | vertical input `== -1` (up) | UP |
| 4 | vertical input `== +1` (down) | DOWN |

The one port difference is which vertical variable is read: amiga tests
`HERO_POS_JUMP_DOWN` (0xFB), msdos tests `HERO_POS_UP_DOWN` (0xE5).

Ten transition bodies, ten installers, no body with two — so the eight unnamed
bodies took their entry points' names in each port, matching the two pairs
(`LEFT_TO_RIGHT`, `RIGHT_TO_LEFT`) that were already spelled that way in the
tree. The two unnamed steady-state loops took `HERO_DIRECTION_UP_IDLE_LOOP` and
`HERO_DIRECTION_DOWN_IDLE_LOOP`, alongside the existing
`HERO_DIRECTION_LEFT_IDLE_LOOP` / `..._RIGHT_IDLE_LOOP`.

## What this does NOT settle

The art. Each state also installs a **second** animation on channel 0x16 that
cycles independently of the body — 11 frames against the body's 2 to 8 — and
those four routines are deliberately still `LABEL_<hex>`. See
`layer_colour_census.py` in this directory: the two layers are disjoint in
colour, and the second layer's subject is not identified. **No name applied
from the table above describes a body part or a scene.**

## Scope note for future renames

The labels here are per-stage, and the same hex spellings occur in other
stages: `LABEL_3980` is also a PRISON cartridge routine, `LABEL_3B78` also a
CAPSULE amiga one, and `LABEL_3AFE` is a *different* routine in each of the two
CAVES ports. A rename must be scoped to `<branch>/CAVES.asm` plus
`_unified/caves/<amiga|dos>__*.inc`. No shared (non-port-prefixed) CAVES chunk
references any of these twenty labels — checked before applying, and worth
re-checking, because four unified-tree breakages earlier in this work came from
exactly that assumption going unverified.
