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

**Corrected since:** CAVES' 26 were applied the same day. Then the identity
key moved from extent-plus-leaf-count to the md5 of the whole parsed tree,
which is stricter: three names the old key called equal are not, so the
remainder is **59**, not 56 — PRISON 20, LAKE 17, CAPSULE 11, INTRO 10,
PASSCODE 1. The stricter key also broke the three "collisions" that had
refused INTRO, PRISON and CAPSULE; each was two constants sharing an extent,
and under md5 exactly one of each pair matches.

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

**Disagreement is not proof, and neither is direction.** Two separate traps.

The releases really do differ — the 1991 release has frames the 1992 ports
dropped, so a family can legitimately hold neighbouring frames at one index.

Worse, the emitter rewrites msdos to match amiga, which assumes amiga is the
port that got it right. Nothing justified that, and it is false at least
twice:

- **PRISON — and I had this backwards at first.** I read the widths, saw
  msdos growing and amiga shrinking, and concluded amiga was the misordered
  port. It is not. Both ports draw the animation shrinking; what differs is
  the numbering, and the convention is that the k-th frame is the k-th
  **drawn**. Measured as index-against-draw-order, amiga scores +1.00 and
  msdos −1.00. The size heuristic blocked a correct permutation, which is
  the expensive direction to be wrong in, and it is gone.

  msdos also had the two halves **swapped**, settled without any cross-port
  comparison by reading where the polygons sit: amiga `LEFT` at x −44..26 and
  `RIGHT` at x 102..172; msdos `LEFT` at x 100..172 and `RIGHT` at x −44..28.
  Both defects were corrected in one 29-row permutation.
- **INTRO.** `PARTICLE_LAB_BG_F0/F1/F3` measure 190x26, 342x182 and 30x28 in
  amiga — a 30x28 five-leaf polygon is not a lab background — against
  149x114, 190x116 and 149x203 in msdos.

`better_ordered_elsewhere()` now decides this on index-against-draw-order,
per family, because the answer differs per family even inside one stage. It
clears PRISON and refuses INTRO.

`--sides` is the other check that came out of PRISON, and it needs no
cross-port comparison at all: a family named `LEFT` should sit at lower
authored x than its `RIGHT` counterpart. It only judges families whose sides
are genuinely separated — more than 16px and more than half their own width —
because where they overlap, LEFT/RIGHT is a **facing** and not a position,
and the x says nothing. Without that restriction it flagged 14 families, the
same ones with the same numbers in both ports, which is what a broken test
looks like rather than two ports sharing one mistake. Restricted, it reports
the tree clean and would still have caught PRISON.

A row is actionable when these line up:

1. `--suggest` finds the same art in the other port under another name;
2. the routine that draws that other constant has a name that agrees with the
   proposed one (`notes/sole-named-drawer/` is the fast way to check);
3. the port being rewritten is the one that is actually wrong — see above;
4. the correction is expressed as **one batch**, because it is a permutation —
   the misapplied holder has to be demoted in the same run that moves the name
   onto the right constant. `apply_branch_scoped_names.py --demote` does both,
   and checks the demoted index against the constant's own EQU table position.
