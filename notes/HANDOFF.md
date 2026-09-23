# Handoff — semantic labelling of the disassembly

Written 2026-09-20, updated 2026-09-23. Everything below is either in git or
named as disposable. Both repos are clean.

## Where things stand, measured

Run these; do not trust the numbers below without re-running them.

    make test                                            # the byte gate
    python3 notes/unified-symbol-check/undefined_symbols.py
    # after ANY branch-scoped rename, before make test:
    python3 notes/unified-scoping/sync_equ_rename.py <table.md> <STAGE> <branch> --apply
    python3 notes/shared-bank-naming/asset_naming_share.py
    python3 notes/crossstage-duplicates/one_picture_many_names.py
    python3 notes/laser-impact-anim/impact_ladder.py
    python3 notes/draw-label-follows-constant/label_vs_constant.py
    python3 notes/backdrop-drawer/backdrop_drawer.py --control
    python3 notes/frame-label-siblings/sibling_template.py --control
    python3 notes/placeholder-census/placeholder_roles.py

As of the last commit:

| measure | value | producer |
|---|---|---|
| byte gate | 29/29 stages, 29/29 unified | `make test` |
| undefined symbols in the unified tree | 0 | `undefined_symbols.py` |
| priority-port assets named | 73.2% (7,420/10,147) | `asset_naming_share.py` |
| pictures carrying two or more names | 73 amiga / 76 msdos of 2,530 / 2,552 named | `one_picture_many_names.py` |
| coordinate-embedding `CINEMATIC_*` names | **0** | `grep -rhoE '\bCINEMATIC_[A-Za-z0-9_]*_AT_[0-9]+_[0-9]+'` |
| shared-bank keys still unnamed | 48, blocking 250 drawing labels | `shared-bank-geometry/blocked_by_bank.py` |
| named keys agreeing with their drawers' unanimous claim | 152 of 158 | `shared-bank-geometry/blocked_by_bank.py --claims` |
| draw-only labels agreeing with their picture | 212, 0 nameable left, 0 contradicting | `label_vs_constant.py` |
| routines naming a gait and drawing another's sheet | 0 (was 30) | `motion-word-audit/piece_family_vs_label.py` |
| shot-impact ladders complete | 18 of 18 (3 stages x 2 directions x 3 branches) | `impact_ladder.py` |
| routines whose name states a screen the guards confirm | 303 of 303 | `screen-scope/screen_scope.py --control` |
| per-screen entry routines named | 257 of 274, 0 nameable left | `screen-scope/screen_entry.py` |
| backdrop painters named | 64 distinct / 106 labels (was 10 / 20), 0 nameable left | `backdrop-drawer/backdrop_drawer.py` |
| painters whose two sources agree on the screen | 139 of 139, all four branches | `backdrop-drawer/backdrop_drawer.py --control` |
| layer names claiming a screen nothing connects them to | 0 of 312 | `backdrop-drawer/backdrop_drawer.py --audit-layers` |
| placeholder labels in PRISON/CAVES/CAPSULE, both ports | 7,594 of 14,503, classified by how control reaches them | `placeholder-census/placeholder_roles.py` |
| names that exist and break NAMING.md §1 | 1,238 `_L<n>` + 153 others, all four branches | `placeholder-census/placeholder_roles.py --forbidden` |
| complete `_F` families indexed by order of first appearance | 159 of 159 | `placeholder-census/placeholder_roles.py --frames` |
| frame labels reproduced from their siblings' template | 127 of 127, 0 nameable left | `frame-label-siblings/sibling_template.py --control` |
| bare-`ret` tails named `<owner>_RET` | 174 exact + 10 refined of 198, 0 nameable left | `bare-ret-tails/owner_ret.py --control` |
| limb-pose indices reproduced from the bank layout | 16 of 16 | `actor-sprite-sheet/subpiece_poses.py --control` |
| named LEFT/RIGHT pairs that are an exact mirror (≤2 leaves) | 42 of 42 | `shared-bank-geometry/mirror_exact.py --control` |

## Added 2026-09-23, later session

**PRISON's wake closeup, the figure it cuts to, and six more groups.** 76
pictures named across both priority ports from renders, all listed in
`notes/render-and-name/README.md` with their confidence. Two of the groups are
**ladders, not animations** -- chains of `jg [var], N` picking one picture for
the current value of a variable the driver moves up *and* down, so draw order
does not exist and the rung is the index. `notes/render-and-name/ladder_rungs.py`
reads the rungs out of the bytecode and compares two branches on rung count and
threshold, never on constant spelling.

**A name that meant two things, and the branch whose art cannot be measured.**
The pupil ladder has seven rungs; the three names it already carried were
rungs 2, 6 and 7 numbered 0, 1 and 2. Renumbering forced the cartridge branch
to follow, and cartridge art **cannot be rendered at all** -- archaeology
#0106 is open and there is no `cinematic.rom` for it. Those seven names rest
on the rung, and `proposals_cartridge_1992__PRISON.md` says so in its first
paragraph. `ladder_rungs.py --diff` went FAIL/3 -> PASS/0 across that fix.

**Two tool defects, both of which corrupted the tree before being caught.**

* `apply_cinematic_renames.py`'s `collides()` treated a *rejected* row as
  freeing its name, so re-running an applied renumber admitted exactly one row
  and would have defined one name at two offsets. `retiring` is now a
  fixpoint; two fixtures in `tools/tests/`, one that must reject and one that
  must accept.
* `sync_equ_rename.py` rewrote sequentially, so a renumber ate its own output.
  Fixed to one simultaneous pass (`--self-test` reproduces the failure) -- and
  the fix introduced a worse bug, because **a rename table is not idempotent
  and cannot be made so**: after `682 -> PUPIL_0` and `PUPIL_0 -> PUPIL_1`
  land, the tree is indistinguishable from the state before a second run. Only
  the history differs. `applied_rows.tsv` now records it. **Write one table
  file per batch.**

**`align_draw_sites.py`: two bridges, because one was 6.9% wrong.** When one
`canonical_md5` maps to several constants in a port, the hash cannot say which
is which -- fourteen of one scene's nineteen were unreachable by art alone.
Pairing by draw site inside the unified tree's own chunk pairs got 592 of 636
already-named sites right, and every one of the 44 misses is a site where the
two ports draw different pictures. Requiring BOTH gates: 552 of 552. See
`notes/cross-port-art/README.md`, including the 44 `PRISON_CUTSCENE_ZOOM_IN_*`
disagreements left open.

**237 of 889 unified chunk FILENAMES name a label that no longer exists.**
`notes/unified-scoping/stale_chunk_names.py`. Invisible to `make test`,
because `.include` resolves by filename. Open work.

## Added 2026-09-23

**The shot-impact burst is one effect drawn from three stages.** PRISON, CAVES
and CAPSULE each run a six-frame flash off a binary search on the timer
`[0x13]`, and `canonical_md5` says all six frames are the same art in all three
stages and both priority ports. All 18 ladder positions now carry a complete
`_0.._5` family. `notes/laser-impact-anim/`.

**A label ending in a threshold is not a frame index.** `..._ABOVE_04` is an
interior node of that search, entered for timer values {4,5}, drawing the frame
for 5. `nameable_from_drawer.py` was inheriting those onto constants; it now
rejects `_ABOVE_/_UPTO_/_BELOW_<n>` (75 skipped, proposals 28 -> 4) and the
README records why `_OVER_<n>` is excluded from that rule.

**"Cannot check" was printing as "does not match".** `apply_branch_scoped_names`
reverted every cartridge rename claiming the bytes moved, when the truth was
that the cartridge baseline is reached through a *relative* root and only
resolves from the archaeology repo. Run cartridge appliers from there. The
message now says which case it hit.

**Every drawer-side seam is now measured and worth 0.** The ledger is in
`notes/sole-named-drawer/README.md`: sole named drawer 0, the one-hop through
an unnamed stub 0, the same hop for `--animations` 0, dispatch ladders 19, art
named in another stage ~38, art named in the other port for the same stage 22.
What remains is **1,655 pictures numbered in *both* priority ports with
identical art** — 667 CAVES, 511 PRISON, 403 CAPSULE — which nothing in the
call graph distinguishes.

**The method that worked, stated once.** Everything that moved after the
mechanical seams ran out came from one idea: *the control flow and the art
identity around a picture identify it when the picture itself cannot.* Six
probes, each with a control:

| probe | what it reads | control |
| --- | --- | --- |
| `screen-scope/screen_scope.py` | forward dataflow on `[SCREEN_NUM]` | re-derives 303 of 303 human screen assignments |
| `screen-scope/screen_entry.py` | the chain whose targets write the camera bounds | the two already-named chains fall on the negative side |
| `substitute-layers/alternative_of.py` | the branch that picks between a named and an unnamed picture | — |
| `substitute-layers/fire_frames.py` | the muzzle offset's sign | re-derives 9 already-correct namings |
| `shared-bank-geometry/mirror_match.py` | point sets flipped in x | **fails** on aim-vs-shoot; used only where the gap is wide |
| `cross-port-art/bank_copy_in_stage.py` | `canonical_md5` against named bank art | 21 shared-chunk constants differing proves the guard needed |

Rendering, by contrast, produced one screen's names in a whole round and a
bug in my own rule. Reach for the control flow first.

**The standing population, measured.** `notes/substitute-layers/draw_threads.py`
finds **126** unnamed threads whose whole body is a run of three or more
still-numbered draws — the shape of an animation. Exactly **4** sit beside a
named, non-mechanism routine in their `setup` block; the CAVES trap columns
were one such case and yielded 42 names. The other **122** have no naming
anchor at all. They are a characterised population, not a lead: each is a
short animation at a known slot, needing recognition, which is the render
problem. One worked example of that difficulty is recorded in the probe
rather than guessed at.

**The compounding does not happen, twice measured.** Naming 264 routines
freed 2 constants (both bad, both filtered); naming 226 constants freed 0
draw-only labels. The two layers are not a chain — the 465 draw-only labels
wait on pictures drawn by *one-picture stubs*, and the pictures being named
now are painted inside multi-draw composites. Do not plan work on the
assumption that one layer unlocks the other.

**The screen blocker is solved.** `notes/screen-scope/screen_scope.py`
derives which `[SCREEN_NUM]` value a routine is reachable under, by forward
dataflow on the guards, and `--control` re-derives **303 of 303** screen
assignments that names already state. Two things came out of it: 69 backdrop
layers named `<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>`, and 264 per-screen
routines named `<STAGE>_SCREEN_<NN>_ENTRY` plus their nine dispatchers. It
also found one wrong name (msdos and cartridge install the CAVES palette-flash
event on screen 0xEE, not the 0xED the shared label claimed) and can find more
with `--proposals`.

`screen-scope/backdrop_phase.py` then named **226** more: everything a screen
entry paints before its first `setup`, indexed by position in that sequence.
It refuses far more than it names, and correctly — 590 pictures are painted
twice in one phase and so have no single position, 296 appear in several
screens' phases, and 107 are blocked permanently by the family-gap guard
because the holes are exactly those shared and twice-painted layers.

**So start from `notes/remaining-art/by_anchor.py`**, which sorts that backlog
by how each picture is anchored, because the classes need different evidence:
1152 at a fixed literal `x,y` (scenery, the class with no method yet), 1534 at
an actor/prop slot, 788 at the hero slot, 228 mixed.

**The one concrete lead inside it:** 42 routines are `fill` + layers at one
anchor — backdrops. Six already carry their screen in the label, and
`by_anchor.py --proposals` turns that into names for the layers exclusive to
that screen (4 applied 2026-09-23). The other 36 need the screen, which is a
multi-hop reachability problem: the label's hex token is **not** the screen
(0 of 54 match a `[SCREEN_NUM]` guard), the call site does not carry it, and
there is no single dispatcher — `[SCREEN_NUM]` is compared 182 times across 52
values in CAVES alone. Solving that unlocks the largest class.

**The render-and-look method is now set up and demonstrated.**
`notes/prison-cell-block/README.md` names PRISON screen 0x04 end to end and
carries the recipe, including the two tool conventions that cost an hour:
`render_scene_composite.py` wants the **painter** routine, not the entry (the
entry composites 3 draws and looks empty), and `polygon_render_png.py` wants
the extracted 64 KB slab with the raw EQU value, not `cinematic.rom` with
`3 * 0x10000 + equ`, which silently renders nothing.

Every screen entry is now named, so the next screen is
`<STAGE>_SCREEN_<NN>_ENTRY` -> its painter -> composite -> per-layer renders.
The rate is **four names per screen** against roughly fifty screens a stage,
three of the seven layers held back because a render can mislead. That is the
honest cost, and it is why every mechanical seam was exhausted first.

**Also still open:** the 465 draw-only labels whose picture is unnamed — each
becomes free the moment its constant is named, so the asset work unlocks the
routine work. Re-run `label_vs_constant.py` after any asset batch.

## The method that worked, in one paragraph

Measure before looking. The pictures mislead — two passes over LAKE misread
the same group from renders — and the bytecode does not: **which variable
pair a `video` draws at** settles what a thing is more reliably than the art
does. Match across ports and stages by `canonical_md5`, never by index.
When two earned names disagree, name the intersection or report the conflict;
do not pick a winner (#0120). Explain every gap rather than filling it. Run
`undefined_symbols.py` before `make test`. The byte gate is the oracle, but
remember what it cannot see: **a rename cannot move a byte, so the gate is
blind to a wrong name.** It only catches a half-applied one.

## The trap that caught me twice, in the same group

`CINEMATIC_DECOR_AT_305_155_*` was grouped by *where it is drawn*, so it held
a hero, a gunman, a beam and a drifting reed under one name. The first pass
split it from renders and got four frames wrong, calling the hero "drifting
decor" — because it grouped by size and by drawer label, and it had coined
those drawer labels itself, in the same pass, from the same look at the same
pictures. **Two guesses agreeing is not evidence.** What settled it was one
operand: `x=[HERO_X], y=[HERO_Y]`. Decor is not drawn at the hero's
coordinates.

The second half of the group failed for the opposite reason: one SVG per
offset showed "a shape beside a line", because the bytecode draws two
pictures *at the same anchor* and the renders were each trimmed to their own
art. `notes/lake-shooting/composite_at_anchor.py` exists to fix that; reach
for it whenever two draws share an anchor.

## Open work, roughly in order of value

**0. Keep the render-and-name batches going.** It is the only method still
producing names on its own: `nameable_from_drawer.py` reports 1,
`transfer_by_art.py` and `align_draw_sites.py` report 0 after each batch is
carried across. PRISON is down from 135 still-numbered pictures >=24x24 to 30.

**Work the runs, not the sizes.** `sheet.py --list` is ordered biggest first
and that is the wrong order: the biggest things left are screen backdrops,
which are the hardest to name honestly. `frame_runs.py` finds what a routine
plays as a straight-line animation, which is where every `high` this session
came from:

    python3 notes/render-and-name/frame_runs.py --stage CAVES --min 4 --stages

`--stages` reports whether the run's art is in another stage, so the name gets
its scope **before** it is written. Its control is `11 of 19` -- read the
module docstring before trusting a run to be one family.

The loop that works:

    python3 notes/render-and-name/sheet.py --stage PRISON --list
    # pick a routine that draws several of them; read its body
    # render its bank at the palette THAT ROUTINE sets, not palette 0
    # compose the layers in draw order and look
    # write ONE proposal table per batch, then:
    (archaeology) python3 tools/apply_branch_scoped_names.py --stage S \
        --branch B --min-confidence medium --apply --proposals <table>
    python3 notes/unified-scoping/sync_equ_rename.py <table> S B --shared --apply
    python3 notes/cross-port-art/transfer_by_art.py --proposals > <dos table>
    # ... apply + sync that too, then undefined_symbols.py and make test

The palette matters, twice over. PRISON's wake closeup reads as a blue eye at
palette 0 and as a brown-irised face at 0x0B, which is what the scene sets two
lines before the first draw. CAVES' `CINEMATIC_CAVES_CRACK_SPREAD_*` is a
monochrome scribble at palette 0 and resolves at 0x05 into two populations --
dark slivers and white-in-blue flashes -- that the fill counts then separate
without any judgement at all.

**Held, with what would settle each:**

* `LABEL_3CD9` / `LABEL_3813` in CAVES, 22 constants: an exact mirror pair of
  11-frame runs, drawn on channel 0x16 alongside the hero's idle. Thin bars at
  foot level that shorten, extend and then fold into a shallow V. Rendered at
  palette 0 they are unreadable; the palette its `setup` site runs under has
  not been traced. **Trace it and re-render** before naming.
* **Which way is the swimmer's "up"?** The ten frames are now named by the
  measured hair height (`CINEMATIC_CAVES_HERO_SWIM_HEAD_{UP,DOWN}_*`), which
  needed no answer. The question itself is still open: the eight
  `HERO_DIRECTION_*_TURN` routines name it the other way round --
  `HERO_DIRECTION_UP_TO_RIGHT_TURN` draws `474`, the hair-lowest frame, first.
  `[0x19]` and `[0x2A]` were checked and do **not** settle it: `[0x19]`
  offsets a copy of `[HERO_Y]` and `[0x2A]` offsets `[HERO_X]`, so they are
  the vertical and horizontal extents, but both vertical poses are reached
  with `[0x2A] = 0x05` and left with `[0x19] = 0x00`, symmetrically.
  **What would settle it:** what the game does to `[HERO_Y]` while the hero
  holds each of the two vertical poses.
* `CINEMATIC_458`..`464` in CAVES, from `LABEL_3C0E`: two thin curved strokes
  that spread apart, flatten and close again while the pair moves from above
  the anchor to below it. Two paths is not enough to say what a pair of curves
  is. **Find another routine that draws them**, or a frame where a third path
  appears.
* `CINEMATIC_134` and `CINEMATIC_280` in PRISON: white bodies in blue edges,
  five paths, the `XRAY_FLASH` treatment and the lunge's 34.0 height, but
  neither width nor signed box matches the lunge. **Find the pose they
  flash.**
* CAVES' 8 copies of `CINEMATIC_WIDE_FLASH_*`: their shared-chunk reference
  really is compiled for cartridge as well
  (`--guards CINEMATIC_008` shows it), so renaming for the priority ports
  alone would leave cartridge reading a name it does not define. **Needs all
  four branches at once**, and cartridge art cannot be rendered (#0106).
  PRISON's 28 `TUMBLING_CHUNK` copies looked like the same case and were
  not -- their guard is amiga+dos only, and they are now named.

0a. **Naming from a render is live, under explicit approval, and has its own
   directory.** `notes/render-and-name/` holds every name derived by looking
   at the art, each row carrying a stated confidence and its evidence. Those
   names have **no independent check**: a rename moves no bytes, so `make
   test` cannot catch one being wrong. They are grouped so they can be
   audited or reverted as a set. `sheet.py` is the looking tool; its tiles
   carry the measured extent, the draw count and screen y, and the drawing
   routines, because the risk is not failing to look but believing a
   magnified thumbnail — `CINEMATIC_336` renders as a perfect toadstool and
   is four pixels wide.

   What it bought beyond the names: a **subject** name has no index and no
   family, so the `_BACKDROP_LAYER_<i>` problem that blocks 185 of 186 layers
   simply does not apply to it.

0. **The two halves now both have a map, and the maps say different things.**

   The art half: `notes/remaining-art/by_anchor.py`. The label half, new on
   2026-09-23: `notes/placeholder-census/placeholder_roles.py`, 7,594
   placeholders in the three big stages sorted by how control reaches them.

   What the label census says is that the label half is **not** mostly a
   judgement problem. 2,360 placeholders unblock in chains as their jumpers
   get names and need nothing else; 828 are a position inside a routine that
   already has a name, and the only thing stopping those is that the role
   vocabulary would have to be invented — a decision about the project's
   naming rather than a measurement, so it is written down and left for the
   owner. Deciding it one way unblocks 828 labels in an afternoon.

   What the art half says is the opposite. `backdrop-drawer --layers` refuses
   185 of 186 candidates because the art is **shared between screens**, and
   `--audit-layers` shows the 312 layer names already in the tree are clean.
   That remainder is not waiting on a convention; it is waiting on a name
   that does not claim one screen, which nothing in `docs/NAMING.md` provides
   yet.

   Both of those are one decision each. They are worth more than any probe.

0a. **Art family gaps, two of three explained.** `HERO_RUN_LEFT_ARM` is
   missing F04 because that frame draws no arm (`run_left_body.map`), and
   `HERO_WALK_LEFT_ARM` is missing F05..F13 for the same reason, verified
   three ways in `notes/shared-bank-geometry/walk_left_arm_gap.md` --
   including that the offsets those pieces would occupy are already held by
   `HERO_WALK_RIGHT_ARM_F09..F12`. Neither is outstanding naming work.

1. **Routine family gaps: 86, not the 73 recorded here before** (`notes/
   family-gaps/routine_family_gaps.py`). The count rose because the 210
   draw-label renames of 2026-09-23 created 47 new `<STAGE>_DRAW_*` families,
   21 of them with an interior gap. Those 21 are **not** outstanding work:
   their indices are inherited from the constant each label draws, and
   `notes/draw-label-follows-constant/footstep_frames.py` shows every hole
   holds a drawer that also does `play id=0x0060` — the footstep. The run
   cycle steps on frames 0 and 5 of ten, the walk cycle on 5 and 13 of
   fifteen. Renumbering them densely would put the wrong frame on the name.

   The "one animation under two conventions" class is **closed**: it was
   PRISON's ten `ACTOR/BUDDY_WALK_LEFT_PHASE_{0,3,5,7,8}` labels drawing the
   run sheet, settled by `notes/motion-word-audit/piece_family_vs_label.py`
   without overriding any earned name — the pieces decide, and they were named
   from geometry independently of any stage's label conventions.
2. **81 routine renames blocked by a dependency chain**: family gaps → cart
   and GBA art unnamed → no proposals → a shared `_helpers` label that cannot
   be renamed for one branch alone. Breaking any link unblocks the rest.
2a. **18 of the remaining shared-bank keys are unreachable, not unnamed.**
   `CV_5F74..CV_5FFC` pair one-to-one with the named
   `CV_FIGURE_WALK_<DIR>_UPPER_POSE_00..08` and are drawn only behind
   `jg [0xF6], 0x00`. `[0xF6]` is written nine times across all four
   branches and every write is `mov [0xF6], 0x0001`; nothing sets it to
   zero, and every stage containing the guard also contains the write. So
   all 180 guards jump and all 162 draws are dead. Per #0126 they take no
   role name. `notes/shared-bank-geometry/unreachable_guarded_art.py`
   re-checks it and exits 1 if any draw is ever found outside the guard.

   **The real remaining count is therefore 59, not 77.**

3. **53 shared-bank keys** (`notes/shared-bank-geometry/`), down from 77 on
   2026-09-23 when `subpiece_poses.py` was fixed: it hardcoded `CYCLE = 16`,
   the walk cycle, and applied it to RUN, whose ten-frame sheet has a mirror
   sum of **9**. Every RUN piece was reported "not symmetric about
   mid-stride" when all of them are. The sum is derived per family now, the
   order comes from the bank layout with the phases checking it, and
   `CV_FIGURE_RUN_RIGHT_LIMB_POSE_00..03` is named. **RUN_LEFT was held and is now named**, by
   `mirror_exact.py`. I held it because `CV_3200` is attested at phases 8 and
   9 and never at 1 where its twin is attested at both, so bank order and
   phase order disagreed and the mirror was the only thing placing it. The
   mirror is no longer alone: it is exact and one-to-one at a leaf count
   where the control has 0 failures in 32, and it agrees with the
   descending-offset order the layout control reproduces 16 of 16. The phase
   says *when* a piece is drawn; the slot is what the name asserts.

   Formerly-77 text follows. 113 are
   actor-slot offsets, blocked by #0138 for *who* they draw but nameable by
   *pose*. The RUN sub-pieces are neither symmetric nor complete, which is
   why they stalled. 50 are hero-art, of which the consensus engine can
   reach 5 — see the next item for why so few.

   The 26 jump frames came out of this pool on 2026-09-23 once item 6 was
   resolved (`jump_left.map`, `jump_right.map`).

3a. **`hero_pose_consensus.py` cannot see most of its evidence.** Two
   mechanical reasons, both measured and neither yet fixed:

   * ~~Rule 8 discards any routine drawing 3+ pictures as a dispatcher.~~
     **Measured and NOT worth changing.** The criticism is real — the bound
     is applied per *routine* where the evidence only supports it per
     *frame*, and all 28 routines that exceed it draw at most one picture per
     frame — but after the jump sheets were named, **zero** unresolved hero
     offsets are blocked by it, and none of their drawers draws more than one
     picture per frame. Changing it would gain nothing. Left as is.
   * ~~`RE_MOTION` requires motion and direction to be adjacent.~~ **Fixed.**
     `motion_of()` now reads the motion word **immediately before the
     direction**; earlier motion words are the approach. Consensus went 5 → 7
     (the two new ones are the `HERO_CROUCH_ARMED_LEFT_...` pair the
     adjacency rule could not parse) with the five previous results
     unchanged. A name making two different motion claims is refused, not
     guessed.

   * **Token-order: tested 2026-09-23 and REJECTED, after I applied it.**
     `motion_of` reads the motion word immediately BEFORE the direction, so
     the 13 names that put every motion word after it yield no claim --
     including the whole `BUDDY_<DIR>_FIRE_{AIM,RECOIL,RECOVER}_PHASE_<n>`
     family, five shared-bank keys that 302 drawing labels wait on. I changed
     it to read the adjacent token after the direction, committed that, and
     it is wrong.

     All **6** of the BUDDY names it takes draw shared-bank art whose signed
     bounding box points the OPPOSITE way from the direction in their name:
     `BUDDY_LEFT_FIRE_RECOVER_PHASE_4` draws `CV_FIGURE_CROUCH_FACING_RIGHT`,
     spanning x −5.5..+28.0. Six for six is not six errors in the art names;
     it means `<DIR>` there does not denote the figure's facing. The other 2
     names draw no bank art. **0 agree with the art, 6 contradict it.**

     So the adjacency requirement in `motion_of` is not an oversight, it is
     load-bearing. `hero_pose_consensus.py --token-order` is the measurement
     and the docstring says so.

     Two things the earlier commit `94e7b39c` claims are therefore **wrong**
     and are corrected here: it says the change "made an exclusion
     principled" because `CV_2570` and `CV_3212` gained two claims — after
     the revert they are excluded by `subpiece_poses.py`'s layout cut again,
     which is where they were — and it reports the dependent probes passing,
     which they did, because none of them was checking the claim against the
     art.

   * **Vocabulary gap, closed.** `AIM`, `FIRE` and `SHOT` were missing.
     `FIRE` and `SHOT` are one action — the routines containing each draw
     exactly the same four offsets — so both normalise to `SHOOT`, which
     appears in no hero routine name at all. `LEAP` was deliberately left
     out: it draws nothing at the hero anchor, so there is no art to check
     `LEAP == JUMP` against.

     Adding them took consensus 7 → **5**, and that is the probe getting
     more honest, not worse. `CV_17CC` and `CV_1664` were being named CROUCH
     on the strength of two CAVES routines while CAPSULE's
     `HERO_GUN_AIM_HOLD_*_LOOP` was silently unparseable. Making it parse
     converted a false unanimity into a recorded conflict.

   **The AIM-vs-CROUCH conflicts are resolved by measurement**
   (`pose_height.py`). Against the 15 committed `HERO_WALK_LEFT_BODY` frames
   (median height 49.0) the disputed offsets are bimodal with an 11-unit gap
   and nothing in between:

       CV_1664 44.5, CV_17CC 45.0          upright  -- CAVES's CROUCH is wrong
       CV_3764, CV_39A2, CV_389E,
       CV_3ADC, CV_1784   33.0..33.5       crouched -- CROUCH is right

   `CV_1784` is the control: both its sources already agreed on CROUCH with
   no AIM claim against it, and it lands in the crouched mode. Height settles
   the body and says nothing about the arms, so for the four crouched ones
   both names are partly right — that is the #0120 intersection, and naming
   them is the next step. **Done** — `armed_poses.map`, 11 offsets.

   **What blocks the rest: the drawers are unnamed.** 28 of 35 have no
   parseable drawer in any stage — not a disagreement, an absence. The way
   through is the jump-sheet method: motion from **scheduling and geometry**
   (anchor arithmetic, `airborne_in_art.py`, `pose_height.py`) rather than
   from any name.
3c. **Half-named mirrors are invisible in every count**, so they have their
   own check: `notes/shared-bank-geometry/half_named_mirrors.py`. It asks,
   for each named piece containing `_LEFT`/`_RIGHT`, whether the flipped name
   exists. It found `HERO_CROUCH_RIGHT` and `HERO_STAND_RIGHT_{BODY,ARM}`.
   **All 20 entries are now adjudicated and none is open.** The three
   `HERO_GUN_ARM_LEFT_CASE_0n_CHARGE_BLINK` are absences — the left switch
   draws a blink only at case 4, against four on the right — and the
   CINEMATIC scenario name is a false positive, since "right" there names a
   place rather than a facing.

3b. **Six of the eight consensus "disagreements" are one artefact.** CAVES
   indexes a single crawl cycle forwards as `HERO_CRAWL_LEFT_PHASE_n` and
   backwards as `HERO_CRAWL_RIGHT_PHASE_(15-n)` — six pieces claimed in both
   directions, and the two phase numbers sum to exactly 15 every time.
   `notes/shared-bank-geometry/crawl_one_cycle_two_labels.py` re-checks it
   and exits 1 if the sum ever stops being constant. The two directions are
   therefore not independent sources. Which labeling is right is NOT settled
   and needs anchor arithmetic or a render.

4. **60 amiga / 59 msdos pictures with multiple names.** Reported, not
   reconciled, per #0120. 49 have the shape of one family named twice.
5. ~~**`genesis_europe` is not covered by `undefined_symbols.py`.**~~
   **Wrong — checked 2026-09-23 and corrected.** `BRANCH` is only ever
   compared against the four branch directory names; `snes_eu` and
   `genesis_europe` are two verify TARGETS built from one branch,
   `cartridge_1992`, and they assemble identical text. The four-entry list
   already covers all five targets.

   The rename that did move genesis bytes was a **redefinition** — two EQUs
   for one name — and the probe was blind to it for a different reason:
   `defs` was a `set`, so a symbol defined twice looked exactly like a symbol
   defined once. That check now exists. It grades severity: different values
   are an error, same value is a warning, because 30 same-value redundancies
   are already in the tree and failing on them would make the probe useless
   as a pre-`make test` gate. See `--redundant`.
6. ~~**Jump sheets held**~~ **— resolved 2026-09-23, and the reasoning
   recorded here was wrong.** "Neither writes `HERO_Y`" is true; the
   inference that they are therefore not jumps is not. The anchor is the
   ground reference, and the lift is drawn **inside the sprite**:
   `notes/shared-bank-geometry/airborne_in_art.py` measures each frame's
   bottom edge and finds the feet leave the ground for frames 6..7 of the
   12-frame sheet and 1..4 of the 9-frame one, against a modal ground level
   of +0.5. Fifteen committed `HERO_WALK_LEFT_BODY` frames show no airborne
   frame at all, which is the control.

   There was also far less disagreement than this entry claimed. CAVES
   (`HERO_JUMP_*_FROM_STAND`) and PRISON (`PRISON_HERO_WALK_JUMP_*`) draw the
   **same twelve CV offsets in the same order** with the same net X
   displacement (±57), and both names say JUMP. They differ only in how they
   describe the approach. The 9-frame `*_FROM_RUN` / `*_RUN_JUMP_*` pair
   agrees the same way and does write `HERO_Y` three times.
7. **34 non-`CINEMATIC_` identifiers still embed coordinates**, mostly
   `SHOW_TEXT_*_AT_x_y` where the coordinate *is* the argument. Different
   question from the one just closed; decide whether the rule applies.

## Things that are wrong or fragile, so you do not rediscover them

- **`notes/naming-proposals/tables/` extents from before 2026-09-19 are
  wrong for group polygons** — they were computed with a group's size bytes
  halved, which is right for a solid and wrong for a group (a group's two
  bytes are a pivot, subtracted whole). `canonical_md5` matches in those
  tables are unaffected. See `notes/polygon-extent-correction/`.
- **Probe nondeterminism**: iterating a `set` let `PYTHONHASHSEED` change a
  calibration tie-break; three runs gave 22, 21, 22. All iteration in the
  committed probes is sorted now. Keep it that way.
- **Circular calibration**: a probe that parses names with the same regex the
  names under test were written by will confirm itself. `phase_base_calibration.py`
  has its own regex for exactly this reason.
- **`SystemExit` escapes `except Exception`.** `slab()` raises it for a port
  with no romset, which aborted a whole four-branch run. Use `except
  BaseException` and skip the port.
- **Only amiga, msdos and gba_usa romsets exist** under
  `another-world-archaeology/tmp/output/`. Cross-port checks silently cover
  two ports unless you notice.

## What is disposable, and why

The session scratchpad under `/tmp/claude-1000/.../scratchpad` holds 781
files. 577 are PNG/SVG renders — **regenerable and deliberately not
committed**, per the working rules on large corpora. The recipe is:

    awvm-render-polygons --port amiga --stage 2 --romset <dir> \
        --bank cinematic --out <dir>

The 69 markdown proposal tables that carried per-name evidence have been
rescued into `notes/naming-proposals/`, with `coverage.py` beside them to
reproduce the 69 / 489 / 396 counts its README quotes.

### This session's scratch, adjudicated

Seven new files. All disposable, and each superseded by something committed in
the same session rather than merely judged unimportant:

| script | verdict | why |
|---|---|---|
| `peek.py`, `comp.py` | **disposable** | One-off dumps asking "what screen does `screen_scope` give each backdrop composite, and who else draws its layers?" `notes/backdrop-drawer/backdrop_drawer.py` answers both over the whole tree, with a control. |
| `first_room.md` | **disposable** | A rejected one-row table — the applier refused it because the name was still on another routine. Its corrected successor is committed as `notes/backdrop-drawer/corrections/03_*`. |
| `fix_a.md` .. `fix_d.md` | **rescued** | These carried the evidence for four hand-applied corrections quoted in a commit. Committed as `notes/backdrop-drawer/corrections/`, with a README giving the order they must be applied in. |
| `st_noshape.py` | **rescued as a flag** | It produced the "21 of 27" that `notes/frame-label-siblings/README.md` quotes. Now `sibling_template.py --no-shape`, so the rejected rule stays re-runnable by whoever wants to check the rejection. |
| `hpc_before.py` | **disposable** | A copy of `hero_pose_consensus.py` taken before editing it, so the edit could be compared. `git show` does that from history, and the edit has since been reverted anyway. It produced no number. |
| `split.py`, `split2.py`, `dm.py` | **disposable** | Written earlier the same day. The first two are the hand-written predecessors of `notes/proposal-tables/split_by_branch_stage.py`, which was committed to replace exactly them and carries `tests/run.sh`. `dm.py` writes five demotion tables from hardcoded rows — it formats text and measures nothing, and its output is committed as `notes/screen-scope/demote_*.md`. |

The three ad-hoc heredoc measurements this session published *without* a file
behind them have producers now: `blocked_by_bank.py` for the 53-keys/302-labels
leverage figure and the 152-of-158 drawer control, and
`hero_pose_consensus.py --token-order` for the 823/13 split and the six-for-six
contradiction that rejected the parser change.

The remaining numbers this session published all have committed producers:
`backdrop_drawer.py` for the 139/139 control, the 0/312 layer audit and the
42-value `--guards` census; `placeholder_roles.py` for the 7,594 breakdown,
the 159/159 frame ordering and the 9/16 loop pairing; `sibling_template.py`
for 127/127.

### The three scratch scripts, adjudicated

The scratch-artefact hook flagged three `.py` files. None produced a number
that is published anywhere without a committed producer; each is superseded:

| script | verdict | why |
|---|---|---|
| `scope_fix.py` | **disposable** | Byte-identical body to the committed `notes/unified-scoping/scope_fix.py` — diffed, the only difference is that the committed one carries the 50-line docstring recording the bug it had (it scoped every proposed row, when the applier applies only some). The scratch copy is its undocumented predecessor. |
| `remeasure.py` | **disposable** | A per-index debugging view of `extent_old` vs `extent`. Superseded by `notes/polygon-extent-correction/what_the_correction_moves.py`, which answers the same question over the whole tree, has `--names` for the per-name view, and is the producer of the figure now quoted in that note. |
| `_*.py` (9 files) | **disposable, as a class** | `_audit.py`, `_audit2.py`, `_audit3.py`, `_audit_cov.py`, `_audit_pairs.py`, `_cmp.py`, `_cmp2.py`, `_global.py`, `_global2.py` — written by the audit's own subagents, one per slice. Each hardcodes the scratch path and answers one throwaway question ("is this file's content already in the repo?", "is this a duplicate of that?"). None is referenced by any committed text. The underscore prefix is the tell: it is the convention the subagents converged on for their own working tools. The published numbers they contributed to have committed producers — `notes/naming-proposals/coverage.py` for the table counts, `notes/scratch-audit/grounds.py` for the refutation histogram. The set is final: the workflow has ended, so no more will appear. |

### The sweep, and its result

Deleting the scratchpad loses nothing that is not either committed or
reproducible by the command above. That is not an impression -- it was
measured, and the measurement is in `notes/scratch-audit/`:

  * 194 non-render files audited by ten agents, each backed by a second agent
    told to **refute** its keep-calls.
  * 41 files proposed for rescue. **All 41 refuted.** `verdicts.md` has the
    grounds one file at a time.
  * The strongest refutations checked out the pre-apply tree in a throwaway
    worktree, re-ran the committed probe, and showed the scratch file was
    byte-identical to its output. Sixteen went that way.

Three things did come out of it, and all three are fixed in the tree rather
than rescued: the `--held` flag on `transfer_across_stages.py` (a counted
hold with no subject sent an agent rummaging in /tmp for a pair HEAD computes
every run), the corrected per-row-evidence claim in
`notes/naming-proposals/README.md`, and `coverage.py --quality`.

The lesson generalises past this repo: **a proposal table is a worse record
than the commit that applied it.** The diff carries the same (constant, name)
pairs plus the EQU offsets the table omits. The tables were still worth
keeping, but as the appliers' input, not as the evidence of record.
