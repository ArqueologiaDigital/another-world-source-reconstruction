# Do the ports agree about what a shared polygon name draws?

`shared_name_art_audit.py` answers that for every semantic `CINEMATIC_*` name
defined in both priority ports, by measuring the art each port's symbol
actually points at.

    python3 notes/crossport-name-audit/shared_name_art_audit.py
    python3 notes/crossport-name-audit/shared_name_art_audit.py --stage CAVES --suggest

It exits 1 while any shared name disagrees, so the number cannot drift upward
unnoticed.

## Why it exists

A polygon name is earned by rendering, in one port, and `docs/NAMING.md` §2
forbids carrying it to another port's symbol — "it would be right 2% of the
time". Issue #0107 is that rule being broken. It has been caught twice by
suspicion, one family at a time: sixteen CAPSULE names in an earlier pass, and
six CAVES hero-idle names on 2026-09-19. Both times the wrong names sat at the
**same EQU-table index** as the port they came from, which is the same line
number, because the tables are emitted in index order.

Catching the third one by suspicion again is not a plan. This measures all of
them at once.

## What it found, 2026-09-19

1,482 shared semantic names compared: **1,400 agree, 82 do not** — CAVES 26,
PRISON 19, LAKE 17, INTRO 10, CAPSULE 9, PASSCODE 1.

They are shuffles rather than noise, which is the signature of a by-index
copy. `--suggest` searches the other port for a constant whose art matches
exactly and names it, so the output is a correction list and not just a
complaint:

| name | amiga | msdos | msdos holds amiga's art under |
|---|---|---|---|
| `CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0` | 410x253/525 | 37x4/8 | `CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING` |
| `CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING` | 94x86/7 | 410x253/525 | `CINEMATIC_338` |
| `CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_0` | 202x188/431 | 26x17/8 | `CINEMATIC_217` |
| `CINEMATIC_CAVES_SCREEN_6D_BACKDROP_0` | 418x324/397 | 30x198/14 | `CINEMATIC_434` |

The first two rows are the two names sitting on each other's art.

This was not found by looking for it. `notes/sole-named-drawer/` proposed
naming msdos `CINEMATIC_217` as `CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_0` from
its sole drawer, and the rename validator refused: the stage already used that
name for a polygon at a different offset. The refusal was the finding.

## How to act on a row

**Disagreement is not proof.** The releases really do differ — the 1991
release has frames the 1992 ports dropped, so a family can legitimately hold
neighbouring frames at one index. A row is actionable when three things line
up:

1. `--suggest` finds the same art in the other port under another name;
2. the routine that draws that other constant has a name that agrees with the
   proposed one (`notes/sole-named-drawer/` is the fast way to check);
3. the correction is expressed as **one batch**, because it is a permutation —
   the misapplied holder has to be demoted in the same run that moves the name
   onto the right constant. `apply_branch_scoped_names.py --demote` does both,
   and checks the demoted index against the constant's own EQU table position.
