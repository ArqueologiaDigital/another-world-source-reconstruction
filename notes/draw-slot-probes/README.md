# The actor-context pipeline, and why #0138 cannot be talked around

Issue **#0138** is one of the two documented blockers on the routine backlog.
`notes/caller-derived-naming/what_blocks_the_rest.py` weighs it: of the 8,919
reachable unnamed routines in the big three on amiga and msdos, **187** draw at
`x=[0x07], y=[0x08]` and **247** more do that *and* draw only shared-bank art.
All 434 are in CAVES. The rule is that a routine drawing at that pair cannot be
named for **who** it draws, because the pair is loaded from a different record
before each draw.

That rule was recorded as a sentence — "a shared actor-record pair loaded from
nine different records" — with no layout behind it. This directory derives the
layout from the bytecode.

## `actor_record_layout.py`

**Question:** what is the record behind `[0x07],[0x08]` — how wide, how many,
which fields, and who else touches the same words?

```bash
cd another-world-source-reconstruction
python3 notes/draw-slot-probes/actor_record_layout.py            # big three, 2 ports
python3 notes/draw-slot-probes/actor_record_layout.py --blocks   # every site
python3 notes/draw-slot-probes/actor_record_layout.py --all      # 4 ports x 9 stages
```

It keys on a **swap block**: a straight run of `mov [A], [B]` between the low
working registers and consecutive variables at some base. Each maximal run is
split where the direction changes and each part is kept only if its memory
words are distinct and densely packed.

Both of those conditions were learned the hard way and both matter:

* Without the **direction split**, a rotation is invisible. `LABEL_4E0A` stores
  eight registers to 0x68 and loads 0x70 into the same eight in one unbroken
  run of sixteen `mov`s; testing the whole run for a single direction threw
  both halves away and the probe reported bases `0x68 0x78`, stride 16 — a real
  record array, described wrongly.
* Without the **density filter**, unrelated `mov`s that merely sat next to each
  other were reported as four-field records spanning 21 words.

## What it found

Identical in **PRISON, CAVES and CAPSULE**, on **amiga, msdos and snes_eu**:

```
8 field(s), width 8: +0->0x07 +1->0x08 +2->0x10 +3->0x11
                     +4->0x12 +5->0x09 +6->0x13 +7->0x29
  bases 0x68 0x70 0x78   stride 8
  -> an array of 3 record(s) of 8 word(s), 0x68..0x7F, packed
     0x68 load  ..._ACTOR_CONTEXT_LOAD_SLOT0_LOOP          channel 0x22
     0x68 store ..._ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP   channel 0x24
     0x70 load  ..._ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP   channel 0x24
     0x70 store ..._ACTOR_CONTEXT_ROTATE_INTO_SLOT2_LOOP   channel 0x26
     0x78 load  ..._ACTOR_CONTEXT_ROTATE_INTO_SLOT2_LOOP   channel 0x26
     0x78 store ..._ACTOR_CONTEXT_COMMIT_SLOT2_LOOP        channel 0x28
```

Four threads, installed by **one `setup` block on consecutive even channels
0x22, 0x24, 0x26, 0x28**, sharing one set of working registers. The VM runs
channels in increasing order within a frame, so the chain order *is* the
channel order:

| channel | does | leaves in the registers |
|---|---|---|
| 0x22 | load record 0 | record 0 |
| 0x24 | tick, store record 0, load record 1 | record 1 |
| 0x26 | tick, store record 1, load record 2 | record 2 |
| 0x28 | tick, store record 2 | — |

So `[0x07]` and `[0x08]` are fields 0 and 1 — x and y — of **whichever record
the pipeline is currently holding**, and which one that is depends on which
channel is executing. Field +5 (`0x09`) is packed: every stage calls
`SPLIT_VAR09_BITS_INTO_VAR0D` after a load, and the tick re-packs it with
`shl [0x0E], 0x0C` / `shl [0x0D], 0x0B` before the store.

In CAVES the tick (`LABEL_4D5E`) wraps x by 0x15F when it passes 0x150 or
0xFFF0, steps the screen index in field +2, and re-derives y from the ground
map — which is what the `CAVES_GROUND_MAP_SCREEN_<hex>_SEGMENT_<n>` family is
for.

## The part that changes how the region may be named

26 other CAVES routines load 0x68..0x7F into the same working registers under a
**different layout** — `CAVES_FALLING_ROCK_SLOT_0_*` reads 0x74/0x75/0x76 as
x/y/state, which under the 8-word map are record 1's fields 4, 5 and 6 with
entirely different registers. Both cannot be true at once.

They are not at once. The probe resolves it by channel: the rock and trap loops
are installed on **the same channels** 0x22/0x24/0x26/0x28, and a channel holds
one address at a time.

> **0x68..0x7F is scene-scoped.** Different scenes install different bodies on
> the same channels and reuse the same words under different layouts. So
> **no stage-wide alias for these words is correct**, in the same way a global
> `CACHED_SCREEN_NUM` was wrong because TANK uses 0x66 as a `djnz` counter.

## What this licenses, and what it does not

It licensed naming the pipeline itself — ten routines, applied 2026-09-19 and
propagated to three branches, in
`another-world-archaeology/docs/content/research/2026-09-19-actor-context-pipeline/`.
Two of the ten were named `PRISON_FILL_AND_DRAW_CIN_24_28_L1` and `_L3`: a bare
`_L<n>` fold suffix, which NAMING.md §1 forbids, on a stem that **is not
defined anywhere in PRISON**. They are `setup` thread entry points, not inner
labels of a fill-and-draw routine.

It does **not** unblock the 434. Knowing the shape of the record does not make
the occupant knowable; if anything this is the clearest statement yet of why it
is not — three interchangeable records, rotated by channel, with the choice
made by whoever filled them. **#0138 stands, and is now explicable rather than
merely asserted.**

The name `ACTOR_CONTEXT` follows CAPSULE, which already carried
`CAPSULE_ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP` and `..._SLOT2_LOOP` before this
pass; the other two stages and the two chain ends were brought into line with
it. It claims an active entity with a position, which the fields and the tick
establish, and no particular character, which they do not.
