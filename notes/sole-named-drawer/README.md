# Naming polygons without rendering them: what works, and what it is worth

`named_art_only.py` established the direction of the backlog — the big
stages' routine layer waits on their polygon layer, because a routine drawing
only unidentified art cannot be named from it. True of the bulk, and this
directory is the exception: the cases where the **routine layer can name the
polygon layer**, with no render.

Every rule here derives a constant's name from something already earned, so
none of them proposes a subject. That is also their ceiling.

## The rules, and what each returned on 2026-09-19

| rule | where | found | applied |
|---|---|---|---|
| sole `_DRAW` routine, one exclusive draw | `nameable_from_drawer.py` (default) | 8 | 8 |
| named routine, whole draw set exclusive, **one anchor** | `--animations` | 31 routines / 171 constants | 22 routines / 108 constants |
| family completion from earned members | `../family-completion/` | 4 | 4 |
| `*_COMPOSITE` routine, whole part-set exclusive | measured, not kept | **0** | — |

`--pool` prints the wider population: **658** unnamed constants whose sole
drawer is named. That is the pool, not the yield. The gap between 658 and the
~120 above is the whole content of this directory.

## Why most of the pool does not qualify

Each of these cost a batch, a revert or both before becoming a filter:

- **the routine names a mechanism, not a subject.** `FILL_PAGE_00_COLOR_08`
  draws two constants; the art is not "a page fill". 16 routines dropped.
- **the routine's own name carries a raw constant index** —
  `DRAW_CITY_SEQ_435_436`, `DRAW_CINEMATICS_166_TO_171`. It is a placeholder
  under NAMING.md §1 whatever else it says, and deriving from it would copy
  the placeholder onto the art.
- **the other port already uses the derived name for other art.** 6 routines.
  This one is invisible to every per-port check, by design, because a
  branch-scoped rename is judged against that branch's files — and it is the
  one that actually bit: naming msdos/INTRO's `LESTER_EXITING_CAR` frames
  passed `make test` 29/29 and silently moved the cross-port audit from 10
  disagreements to 23.
- **several anchors.** One anchor means frames of one thing; several mean
  props along a path, and a prop needs identifying on its own. 12 routines /
  87 constants sit here.
- **the sizes do not support one family.** `TANK_DESTROYED_CUTSCENE_BLAST_
  ENTRY` passes every structural test and its six frames measure 11x4, 11x4,
  10x5, 10x4, 8x3 and then 205x138. Five specks and a full-screen flash are
  not six frames of one thing.
- **two earned routine names for one art** (#0120). amiga's
  `STORM_AMBIENT_DRIFT_DRAW_LOOP` and msdos's
  `STORM_PARTICLE_TUMBLE_ANIM_LOOP` draw art identical five for five by md5.
  Not ours to adjudicate.

## What is left

What remains in the pool needs a render, which is the E3 work these rules
exist to avoid and cannot replace. The honest read of the table above is that
naming-without-looking is worth about a sixth of the constants it can see,
and the rest of the 64% still unnamed will be found by looking at it.

## 2026-09-20: rule 1 widened past the `_DRAW` suffix

The original rule 1 was "the routine's name ends in `_DRAW`". That is a strong
signal and far too narrow a one. After the routine layer gained 284 names from
the shared-bank work, the `_DRAW` form matched **zero** of them — those are
spelled `DRAW_HERO_WALK_RIGHT_F03` — and the probe reported 0 nameable while
431 constants had exactly one named drawer.

Rule 1 is now "semantic, and denotes a subject", enforced by the filters the
suffix was standing in for. Each of these was added because a real candidate
reached the list:

| filter | what it caught |
|---|---|
| `MECHANISM` + `SHARED_RET`, `DISPATCH`, `_TICK`, `PAGE_`… | `SHARED_RET`, `PRISON_SHOT_STATE_FRAME_DISPATCH_LEFT` |
| `KILL_ALL`, `_AND_KILL`, `_AND_RET` | `CINEMATIC_KILL_ALL_CHANNELS_AND_KILL`, which reached the apply step |
| `_BY_FACING`, `_BY_STATE`, `_SELECT` | `PRISON_TELEPORT_UP_POSE_BY_FACING` — a **selector**, not a subject |
| `RE_HEXTAIL` | 556 names ending in a raw hex token inherited from the routine's own `jne` literal, which §1 forbids on a constant |

779 → 71 → **69** as those went in.

### Verifying instead of transferring, which caught one

The docstring says to check the derived name against the measured shape. Done
on a sample, and it earned its keep:

    CINEMATIC_505  ->  PRISON_SHOT_BEAM_SINGLE_DOT      0x1,  1 leaf
    CINEMATIC_129  ->  BIOMETRIC_SCAN_LINE_SWEEP        1x210, 1 leaf
    CINEMATIC_775  ->  CAVES_LASER_IMPACT_..._ABOVE_02  17x12, 7 leaves
    CINEMATIC_553  ->  PRISON_TELEPORT_UP_POSE_BY_FACING 6x94, 4 leaves

The first three corroborate exactly — a "single dot" that measures one pixel,
a "scan line" that is one unit wide and 210 tall. The fourth is a thin
vertical sliver, which is a *beam*, under a name that says "pose". That is
what `_BY_FACING` now excludes.

### Two application hazards, both caught before they landed

**The proposal file must be per stage.** `apply_branch_scoped_names.py`
matches rows by constant number and takes the stage from its own `--stage`
flag, so a per-*port* file holding PASSCODE and PRISON rows together offers
`CINEMATIC_013 -> CINEMATIC_PASSCODE_ALPHANUM_CODE_CASE_03` **for PRISON**.
Seen in a dry run. The probe now writes one file per (port, stage).

**The `EQU` must follow the use.** The applier renames the canonical `.asm`
and the shared unified draw sites, but not the `EQU` in a branch's own entry
chunk. That leaves a shared chunk naming a symbol only the canonical file
defines: 7 undefined references, verify-unified **26/29**, verify-stages still
29/29 because each canonical file was self-consistent.
`../unified-scoping/sync_equ_rename.py` carries the rename into that branch's
own chunks and nowhere else.

Applied: **69 constants**, `make test` 29/29 and 29/29, `undefined_symbols.py`
clean. 20 of the proposals were rejected by the validator and the sync tool
skipped them, because a proposal is not an application.

## Widening to all four branches, and a target the checker does not see

The routine-naming pass was losing 81 renames because the cartridge and GBA
builds share labels with amiga and msdos and had **no proposals of their
own** — and they had none because this probe only scanned the two priority
ports. Their cinematic constants are their own bank at their own offsets, so
the sole-named-drawer rule applies to them independently.

Scanning all four took the probe from 32 nameable to **112**.

Two things had to be fixed to get there:

**Rule 6 must tolerate a missing ROM.** It compares art by `canonical_md5`,
which needs the port's `cinematic.rom`; snes_eu and gba_usa have no extracted
resources, and `slab()` raises `SystemExit`, which is a `BaseException` and
walked straight past the handler — aborting the whole run the moment the
probe was widened. Ports without a ROM are now skipped and named in the
output, so the check covers the pairs it can see and says which it cannot.

**`genesis_europe` is a verify target that `undefined_symbols.py` does not
check.** Applying all seven per-stage batches gave `undefined_symbols` clean
and `make test` **28/29**: `genesis_europe/CAVES: MISMATCH`. That build is
assembled from `cartridge_1992`'s source but compared against its own
binary, and the checker's `BRANCHES` list has four entries that do not
include it. Re-applying without the cartridge CAVES batch is **29/29 and
29/29**, so those 18 names are the ones at fault and are held.

Applied: 43 constants across snes_eu CAPSULE, ENDING, INTRO, PRISON, TANK and
gba_usa INTRO. Held: the 18 cartridge CAVES names, pending a checker that
covers `genesis_europe` — which is the real fix, since right now only the
byte gate can see that target and it cannot say *which* symbol moved.

### The `genesis_europe` mismatch was a name collision, not a checker gap

Diagnosed rather than left as "a target no checker sees". `cart__entry.inc`
ended up with **two** `EQU`s of one name:

    cart__entry.inc:2242  CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG  EQU 0x6B86
    cart__entry.inc:2262  CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG  EQU 0x73A8

The second is `CINEMATIC_315`, renamed by this pass onto a name cartridge
already used at a different offset. Two definitions, the later one wins, and
the bytes move — which is why `genesis_europe/CAVES` mismatched while
`undefined_symbols.py` stayed clean: nothing was *undefined*, one thing was
defined twice.

**The taken-check never looked at `EQU`s.** It tested `new in bodies or new
in drawn` — labels and drawn symbols — so a name that exists as an `EQU` but
is not drawn in that file looked free. It now also collects every `EQU` name
in the canonical file *and* in the unified arms that carry that branch's
copy, which is where the collision actually was.

With that fixed the cartridge CAVES batch applies cleanly: **29/29 and
29/29**, no duplicate `EQU` in the cart arms, `--duplicates` still one name
per picture. The `genesis_europe` checker gap is real and still worth closing
— it is why only the byte gate caught this — but it was not the cause.

## A fourth filter: a threshold is not an index

The probe offered these, and every one was wrong:

```
amiga/CAVES  CINEMATIC_777  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04
```

The indices it produced ran `01, 02, 04`. The hole at `03` was the tell.
`CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04` is an arm of a binary search over the
impact timer `[0x13]`: it is entered for timer values 4 and 5, and the picture
drawn at the label is the one for value **5**. So the inherited name is off by
one *and* it records a comparison threshold where a frame index belongs. The
three pictures that got no proposal were not missing art — they sit behind
`DRAW_CIN_<n>` fallthrough labels with no name to inherit. The gap was in the
labels, never in the animation. `../laser-impact-anim/` has the full reading
and the twelve names it earned instead.

This is the same inheritance bug `RE_HEXTAIL` already caught, except the token
is decimal and therefore looks exactly like a family index, so the existing
filter could not see it.

Measured over the whole tree: of the **36** distinct labels ending `_ABOVE_<n>`,
`_UPTO_<n>` or `_BELOW_<n>`, **34** are directly the target of an inequality on
the variable their ladder switches on. The two that are not —
`PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_16` (reached by `call`) and
`PRISON_SCREEN_FLOOR_Y_LOOKUP_UPTO_04` (reached by `jne`) — are arms of those
same ladders carrying a threshold inherited from a sibling, so they are no more
an index than the rest. `RE_THRESHOLD` rejects all three tails.

`_OVER_<n>` is deliberately **not** in that set. All four of its labels are
`CREDITS_SCROLL_RENDER_PAGE_80_OVER_83` and kin, where `80` and `83` are page
numbers and "over" is compositing, not comparison. Reproduce with:

```
python3 notes/sole-named-drawer/nameable_from_drawer.py
```

which now reports **75 skipped: name ends in a comparison threshold, not an
index**, and is left with 4 proposals — all four themselves arms of a CAPSULE
ladder named `_PHASE_1` and `_PHASE_4` with no 2 or 3, which is the same shape
of hole and is treated in `../laser-impact-anim/`.

## `--hop`: a lever that looked worth 93 names and is worth 0

The main rule needs the sole drawer to carry a semantic name. Counting what it
turns away, the largest class by far is a sole drawer that is an **unnamed
stub** — a bare `LABEL_<hex>` that draws one picture and rets. If such a stub
has exactly one reference and that reference is a named routine, the name
looks like it should hop across the `call`:

```
CAVES_SHAFT_DESCENT_STAGE_CASE_06:
        ...
        call LABEL_2693
LABEL_2693:
        video offset=CINEMATIC_674, ...
```

Counted that way there are **93** of them, and every one is wrong.

The direct rule gets two conditions for free that the hop has to ask for
explicitly, and both were being skipped:

**The stub must draw one picture.** A constant having a single drawer does not
give that. `LABEL_2693` above is the sole drawer of `CINEMATIC_674`, `675`,
`676`, `677` *and* `678` — one stub, five pictures, one caller. Without the
test, all five collected the same name, and the first run of `--hop` proposed
`CINEMATIC_CAVES_SHAFT_DESCENT_STAGE_CASE_06` twenty-one times.

**The caller must put one picture on screen.** A routine that delegates to
three stubs draws three pictures, and handing each of them the caller's name
gives one name to a family.

With both tests in, in msdos/CAVES: 18 candidates pass the naive test, 9 are
rejected because the stub draws more than one picture, 9 because the caller
puts more than one on screen, and **0 survive**. Tree-wide the same: 42 and
89 rejected, 0 proposed.

```
python3 notes/sole-named-drawer/nameable_from_drawer.py --hop
```

The code is kept rather than deleted because the negative result is the useful
part: the stub indirection is not an untapped seam, it is mostly *one stub
serving a whole run of frames*, and a run needs the ladder or sequence
treatment in `../laser-impact-anim/`, not a name copied across one `call`.

This is also why the scouting number and the real number differ by 93. A count
taken before the exclusivity conditions are written down is a count of
candidates, not of names.

### The same hop applied to `--animations`, also 0

If one stub serving a run of frames is not a name-hop, it might still be an
*animation* — a named routine whose whole on-screen output is one stub drawing
N consecutive unnamed constants would give `<caller>_F0..F<N-1>`. That is the
`--animations` rule reaching one level deeper, and `--animations` badly needs
it: of the 51 fixed-anchor routines it finds today, almost none are in
PRISON, CAVES or CAPSULE, because in those stages the draws sit behind labels.

Measured over both priority ports, it yields **0**, and the rejections say why:

```
  726  stub's art is not exclusive to it
  211  no single named caller
    4  the caller draws elsewhere too
    1  the caller's name is a mechanism
```

726 to 211 is the shape of the answer. These labels are not private helpers
with their own picture; they are shared, and a picture reached from two places
cannot take the name of one of them.

The motivating example turned out not to be a stub at all:

```
CAVES_SHAFT_DESCENT_STAGE_CASE_06:
        jne [0x03], 0x06, LABEL_2693
        mov [0x34], 0xFFF7
        ...
LABEL_2693:                              <- reached by FALLTHROUGH, not a call
        video offset=CINEMATIC_664, x=[HERO_X], y=[HERO_Y]
        je [0x63], 0x02, LABEL_2715
        break
        sub [HERO_X], 0x0001
        video offset=CINEMATIC_672, x=[HERO_X], y=[HERO_Y]
```

It is a long sequence body with `break`s between frames, drawing at the hero
slot — the hero descending the shaft. `#0138` would have refused it anyway.

## The ledger of levers, and what each is worth today

Every mechanical seam into the remaining art, measured rather than assumed:

| lever | yield | why |
| --- | --- | --- |
| sole **named** drawer (the main rule) | 0 | all applied 2026-09-23 |
| sole drawer is a stub, one named caller (`--hop`) | 0 | stub draws a run, or caller draws several |
| the same hop for `--animations` | 0 | 726 of the stubs' art is not exclusive |
| a `[0x13]`-style dispatch ladder | 19 | the six big ones were named 2026-09-23 |
| identical art already named in another **stage** | ~38 | and the role must be re-stemmed per stage |
| identical art already named in the other **port**, same stage | 22 | the two ports are already well synchronised |
| numbered in **both** ports with identical art | **1,655** | neither port has a name; no drawer-side evidence exists |

The last row is the work. 667 in CAVES, 511 in PRISON, 403 in CAPSULE, and
nothing in the call graph distinguishes them — which is what
`tools/nameable_backlog.py` means by "the `real` column is the work". They need
the polygon layer: geometry, anchors and rendering, the methods in
`../shared-bank-geometry/` and `../lake-shooting/`, one scene at a time.

## Rule 3 relaxed to ignore placeholder drawers — refuted, 0 of 4

Rule 3 refuses a picture that more than one routine draws. The obvious
complaint is that a **placeholder** drawer says nothing about the subject, so
it should not veto a semantic one. Relaxing it that way offers 16 names,
including a clean-looking seven-member
`CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_FRAME_*` family and six
`CINEMATIC_CAVES_CREATURE_WALK_RIGHT_PHASE_*`.

Tested against constants that are **already named** in exactly that
configuration — one semantic drawer that draws nothing else, plus one or more
`LABEL_` stubs — the derived name is right **0 times out of 4** with this
module's own filters applied, and 2 of 13 with only `naming_census.classify`.

The misses all say the same thing:

```
PRISON_HERO_RUN_RIGHT_TURN_PRELUDE    draws  CINEMATIC_HERO_LIFTOFF
CAVES_BURST_CHUNKS_FINAL_HOLD_LOOP    draws  CINEMATIC_CAVES_BURST_CHUNKS_F0
PRISON_HERO_CROUCH_LEFT_ENTRY         draws  CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT
```

The routine is named for a **moment in an animation** — the prelude, the final
hold, the entry — and the art is named for a **thing**. They are different
kinds of name, and this module's premise is that sometimes they coincide.
Where a second drawer exists at all, they mostly do not.

So rule 3 stays as it is, and the 16 candidates stay numbered.
