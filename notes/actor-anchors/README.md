# The anchor does not tell you whose picture it is

## The mistake

`x=[BUDDY_X], y=[BUDDY_Y]` looks like proof that a picture is the companion's,
and `x=[HERO_X], y=[HERO_Y]` like proof it is the player character's. That
reasoning was used in this repo to name ten CAPSULE constants
`CINEMATIC_BUDDY_*`, and it is **not safe**. Those ten have since been renamed;
see below.

## What contradicts it

| file | question it answers |
| --- | --- |
| `anchor_identity.py` | Does an anchor's own name agree with the names drawn at it? |
| `shared_actor_art.py` | Two characters stand in one anchor slot -- do they share any art? |
| `var_retasking.py` | Does a VM variable mean the same thing everywhere it is used? |

`anchor_identity.py` lists every anchor that is a pair of named variables, the
named constants drawn there, and any name whose own actor word disagrees with
the anchor's:

```
$ python3 notes/actor-anchors/anchor_identity.py --stage CAPSULE
  === chahi/CAPSULE
      x=[HERO_X], y=[HERO_Y]    170 draw(s), 79 named / 35 still numbered
          CONFLICT  CINEMATIC_BUDDY_SMASHING_WINDOW_F0 says BUDDY, anchor says HERO
      x=[BUDDY_X], y=[BUDDY_Y]  153 draw(s), 51 named / 63 still numbered
          CONFLICT  routine DRAW_HERO_POSE_0_1 says HERO, but draws at the BUDDY anchor
          ... eight more DRAW_HERO_POSE_* routines

$ python3 notes/actor-anchors/anchor_identity.py
  72 conflict(s) [all stages, both priority ports]
```

So in one stage, a constant that commits to the companion is drawn at the
hero's anchor, and nine routines that commit to the hero draw at the
companion's. Both namings were earned by earlier passes; both cannot be right.

Nothing in the bytecode settles it. The variable numbers are the VM's own
convention -- `HERO_X EQU 0x01`, `BUDDY_X EQU 0x07` -- and a script may drive
any actor through any variable. An anchor is evidence that two pictures belong
to the **same** actor, which is real and useful; it is not evidence of **which**
actor.

## What the tree already does

Every other figure name at either anchor uses the neutral word **FIGURE**:

```
  at [HERO_X]:   CAPSULE_FIGURE_FLUNG_F0..F4, CAPSULE_FIGURE_PROP_UP_F0..F4
  at [BUDDY_X]:  CAPSULE_FIGURE_THROW_F0..F8, CAPSULE_FIGURE_WALK_RIGHT_BODY_F0..F4,
                 CAPSULE_KNEELING_FIGURE_*, CAPSULE_PRONE_FIGURE_*
```

An earlier pass met this question and declined to answer it, which is exactly
what #0120 asks for when two earned names disagree. The ten `BUDDY_*` names
broke that practice on the strength of a variable name, and are now
`CINEMATIC_CAPSULE_{SEGMENT_BAR,DISCHARGE_FLASH,CHARGE_GLOW}_*`.

## The rule

> Group by the anchor -- it reliably says *the same actor* -- but do not put
> that actor's name in the constant. Say `FIGURE`, or scope by stage, and put
> the anchor in the evidence column where it can be checked.

## What settled it: CAVES

An earlier draft of this note said the question would be decided by which pair
the script **writes**, on the theory that the engine maintains the player's.
That was tried and it decides nothing: amiga/PRISON writes `HERO_X` 273 times
and `BUDDY_X` 196, amiga/CAPSULE 289 and 132. Both are script-driven.

**CAVES decides it.** There is no companion in CAVES -- Lester is alone --
and yet:

```
  === chahi/CAVES
      x=[HERO_X], y=[HERO_Y]    298 draw(s), 137 named / 68 still numbered
      x=[BUDDY_X], y=[BUDDY_Y]  194 draw(s),  60 named / 83 still numbered
          CONFLICT  CINEMATIC_CAVES_HERO_COLLAPSE_F0 says HERO, anchor says BUDDY
          ... F1 through F6
```

194 draws at `[0x07]` in a stage with only one character in it, seven of them
named `CAVES_HERO_COLLAPSE_*` by an earlier pass. So `[0x07]` is not "the
companion's position". It is a second coordinate slot a script may use for
anything, including the player.

`HERO_X` and `BUDDY_X` are the VM's conventional names for variable slots.
They are useful and they are not identities, and no constant name should be
built on them.

## A spelling trap in the same place

A stage only spells a variable `HERO_X` if its own file defines that EQU, and
the files do not agree. CAVES defines `HERO_X` and **not** `BUDDY_X`, then
draws 403 times at a raw `[0x07]`; ENDING defines `BUDDY_X` and not `HERO_X`,
then draws 73 times at `[0x01]`. A scan that groups on the spelling reports
those stages as single-actor, which is how the first version of this probe
missed CAVES entirely and nearly produced the opposite conclusion.
`anchor_identity.py` now normalises `0x01/0x02/0x07/0x08` before grouping.

## 2026-09-25: a person who played the game says the PRISON slot holds two

The note above argues from the tree that an anchor does not identify an actor.
A play session has now supplied the other kind of evidence, and it agrees --
from someone who had never read any of this.

Annotating `dos_1992/PRISON` frame by frame, the same person called the figure
drawn at `[BUDDY_X],[BUDDY_Y]`:

| frames | what they called it | constants |
| --- | --- | --- |
| 118 - 2546 | **the main guard** | 633, 342, 240, 241, 168, 169, 162, 231, 228, 227, 629 |
| 3073 - 3136 | **Buddy** | 438, 440, 441, 447 |

with sentences that leave no doubt which they meant -- "full body of the main
guard, standing with his back to the camera right after removing and storing his
cloak" against "buddy's right arm while tapping lester's back/shoulder".

The two sets are drawn from two separate regions of the bytecode:

    guard set   PRISON.asm:8849 - 10045
    Buddy set   PRISON.asm:3631 -  3757

and the changeover falls at the cage collapse, which the same session annotates
at frames 3069-3075 -- the gun knocked away (`..._GUARD_GUN_KNOCKED_F0..F5`),
the debris passing the camera, the wreck at rest, and then "frame of buddy
starting to wake up from the fallen cage" at 3073.

**So `BUDDY_X`/`BUDDY_Y` in PRISON is a slot, and the scene decides who stands
in it.** That is this directory's thesis, stated by a witness instead of a probe.

### What it puts in question

`dos_1992/PRISON.asm` defines **9** `CINEMATIC_PRISON_BUDDY_*` constants and
**98** routine labels containing `BUDDY`. None of them is retracted here --
nothing above shows any particular one is wrong, and this is not the place to
adjudicate. What it does mean is that the actor word in any PRISON name anchored
on `BUDDY_*` needs the scene it is drawn in, not the anchor, and an audit should
start from the two line ranges above.

### Then the same person said the species is one

> "Buddy and the guards are of the same species. They are all aliens of this
> world. So they look similar and that may be a source of confusion when
> labeling assets."

That is a fact about the fiction, and it has a mechanical consequence: **for
this cast, looking cannot tell you who.** `docs/NAMING.md` grade E3 asks for
render-before-naming and this directory's whole subject is that the anchor
cannot substitute for it -- but between two aliens of one species, a render
cannot either. The scene can, and nothing else here can.

Three measurements, taken after that sentence, against `dos_1992/PRISON.asm`:

| question | answer |
|---|---|
| constants drawn at `[BUDDY_X],[BUDDY_Y]` in both regions | **0** of 299 |
| buddy-region constants whose `canonical_md5` matches a guard-region one | **0** of 10 against 111 |
| `CV_*` constants drawn at both `HERO_X` and `BUDDY_X` | **0** |

    python3 notes/actor-anchors/shared_actor_art.py \
        --branch dos_1992 --stage PRISON --anchor BUDDY \
        --scene guard:8800-10100 --scene buddy:3600-3800 \
        --cross-anchor HERO,BUDDY

So the resemblance is in the artwork and **not** in the assets: the two are
drawn from entirely separate constants with entirely different polygon trees,
and the shared bank is not serving both from one figure either. The slot reading
above survives this and is strengthened by it -- two characters, two disjoint
sets of art, one anchor.

What it costs is the ability to check the actor word by looking, for every name
in this class.

### Where the word actually came from, which is worse than a bad look

The nine `CINEMATIC_PRISON_BUDDY_*` names were not read off a picture. Their
evidence cells in `../render-and-name/` are geometric and compositional --
"22x29, one path: a torso, wider at the shoulders and hips than at the waist",
"9x25, spans -17.5..-8.5, sharing the -17.5 shoulder edge with the other three".
Sound work, every row.

The actor word came from the routine they are drawn by, and that table says so
in as many words: *"It is the sole picture of `DRAW_BUDDY_FIGURE_BASE`"*.

So `BUDDY` rode in from a pre-existing label, through a chain of derivations
each of which was about geometry and none of which was about the actor. No step
tested the word, because no step was for testing the word -- and the species
fact says the one check that would have felt decisive, rendering it and looking,
could not have caught it either.

**The rule this leaves**, for PRISON and anywhere else two same-species
characters share a stage: an actor word is admissible from the SCENE a draw
belongs to, and from nothing else. Not the anchor, not the render, and not a
neighbouring label that has the word already. The shared bank shows what the
discipline looks like when it is kept -- all 104 `CV_*` names in this stage are
`CV_FIGURE_*`, generic, with no actor word claimed by any of them:

    grep -oP '^CV_\w+(?=\s+EQU)' src/levels/dos_1992/PRISON.asm \
      | grep -oP '^CV_[A-Z]+' | sort | uniq -c
    #   104 CV_FIGURE

### Why nothing was renamed from these sentences

The rule in `docs/NAMING.md` is that an actor word the person used enters a name
only where that stage's already-earned names use it at that anchor. Here they
do -- `DRAW_PRISON_BUDDY_POSE_3` draws `CINEMATIC_231`, which the person calls
the guard's head -- so the person and the tree **disagree about the same
constant**. `#0120` says not to pick between earned names, so the eleven guard
constants are held, one verdict each in
`../play-and-describe/verdicts.tsv`, with this section as what would settle them.


## 2026-09-25, later: the variable is re-tasked, and here is the size of it

The owner asked the question this note had been circling: are `BUDDY_X` and
`BUDDY_Y` used for other characters, perhaps because the VM is short of
variables? Both halves are yes, and the second half is measurable.

    python3 notes/actor-anchors/var_retasking.py --var BUDDY_X
    python3 notes/actor-anchors/var_retasking.py --scarcity

### The variable is `0x07`, and every stage draws with it

`BUDDY_X` is `0x07` and `BUDDY_Y` is `0x08` -- **low** numbers, which in this VM
is scratch space. Of the nine stages in `dos_1992`, three name it and all nine
draw with it:

| stage | names `0x07` | raw `[0x07]` uses | draws anchored on it |
| --- | --- | ---: | ---: |
| PRISON | `BUDDY_X` | 0 | 465 |
| CAPSULE | `BUDDY_X` | 0 | 467 |
| ENDING | `BUDDY_X` | 0 | 51 |
| CAVES | — | 790 | 425 |
| CODE_WHEEL | — | 68 | 47 |
| PASSCODE | — | 70 | 43 |
| TANK | — | 24 | 13 |
| INTRO | — | 16 | 5 |
| LAKE | — | 54 | 2 |

INTRO, CODE_WHEEL and PASSCODE draw hundreds of pictures positioned by `0x07`
in stages where **Buddy does not exist** -- he is introduced in PRISON. The
clearest single case is the first annotation this project ever received:
`CINEMATIC_STORM_PARTICLE_F00..F04` are drawn at `x=[0x07], y=[0x09]` in INTRO.
The same word that positions Buddy in three stages positions wind-blown debris
in the first.

So `BUDDY_X` is a **stage-local alias**. It is asserted only in the three stages
where Buddy appears, which is the right discipline; it says nothing about `0x07`
anywhere else, and reading it as a global fact is how art gets attributed to the
wrong actor.

### Scarcity is real, which is the reason to expect this

Distinct VM variables each stage touches, of 256:

    CAVES 188   PRISON 183   CAPSULE 180   LAKE 155   TANK 101
    CODE_WHEEL 84   PASSCODE 52   INTRO 21   ENDING 14      UNION 216

The three big stages each consume about seventy per cent of the register file
and the game as a whole touches 216 of 256. A machine that full has to reuse
words, and the low numbers are exactly where a compiler-less codebase puts its
scratch.

### And it is re-tasked WITHIN a stage, six times over

`var_retasking.py --stage PRISON` groups the writes and the anchored draws into
line clusters. PRISON has 212 writes to `0x07` in 8 clusters and 465 anchored
draws in **6**:

    2686-3766   5217-5226   6289-6381   8809-8942   9396-11769   14021

Feeding those six to `shared_actor_art.py` gives 49, 2, 10, 33, 208 and 1
constants, and **no two of them share a picture**: the only constants appearing
in more than one cluster are two drawn in both, not two constants drawn from one
asset. Six groups of subjects, one register.

### What this changes

Nothing is retracted, and the rule this directory already reached is the right
one -- an actor word comes from the scene. What changes is how far the suspicion
should travel:

- a variable NAME is evidence about the stage that asserts it and nowhere else;
- inside a stage, a name on a variable is still not evidence about which scene
  a draw belongs to, because the same word serves six of them here;
- `--scarcity` is the reason to expect all of this rather than treat it as a
  quirk, and it is worth re-running before assuming any low-numbered variable
  means one thing.


## 2026-09-25, later still: it is a scheduler, and the thread does not save you

The owner narrowed the question: is the variable repurposed **within a single
scene**, and specifically, is `BUDDY_X` carrying the guard's movements? Yes, and
the tree names the mechanism itself -- somebody labelled these routines before
any of this came up and the words were sitting there:

    PRISON_ACTOR_CONTEXT_LOAD_SLOT0_LOOP:
        call PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_25
        mov [BUDDY_X], [0x68]      mov [BUDDY_Y], [0x69]
        mov [0x10],    [0x6A]      mov [0x11],    [0x6B]
        mov [0x09],    [0x6D]      mov [0x12],    [0x6C]
        mov [0x13],    [0x6E]      mov [0x29],    [0x6F]
        call SPLIT_VAR09_BITS_INTO_VAR0D
        break
        jmp PRISON_ACTOR_CONTEXT_LOAD_SLOT0_LOOP

    PRISON_ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP:
        call PRISON_ACTOR_SLOT_WRITEBACK_PREP
        mov [0x68], [BUDDY_X]      ... writes the whole set back ...
        mov [BUDDY_X], [0x70]      ... then loads the next slot ...

**`[0x07]` and `[0x08]` are the working registers of a cooperative actor
scheduler.** Three actor records of eight words each live at `0x68`, `0x70` and
`0x78`; a thread writes its record back, loads the next, runs one frame's worth
of logic, `break`s, and repeats. `PRISON_ACTOR_CONTEXT_COMMIT_SLOT2_LOOP` closes
the chain by writing back without loading.

The record layout, read off the loads:

    +0 X   +1 Y   +2 [0x10]   +3 [0x11]   +4 [0x12]   +5 [0x09]   +6 [0x13]   +7 [0x29]

How many actors run is per scene, from the `setup channel` lines: the guard
scene at `PRISON.asm:8882` installs two of them, on channels 0x21 and 0x24; the
cage scene at 13500 installs three, on 0x22, 0x24 and 0x26.

So `BUDDY_X` does not name Buddy's X. It names **the current actor's** X, and
which actor is current is a property of the thread and the moment.

### And the thread is not the answer either

The obvious next move is to identify the actor by the thread, since
`tools/vm-debugger/` records one on every draw and therefore on every
annotation. Grouping the 46 PRISON annotations by thread does separate the cast
cleanly -- 3 and 4 are the background miners, 17 the background runner, 18 the
gun, 20 Buddy in the cage, 52 the cage wreck and later the lift, 56 and 57 the
lift sparkles -- and then it fails on the one that matters:

    thread 35   f136    "full body of the main guard, standing with his back..."
    thread 35   f2546   "right arm of the guard point a gun upwards"
    thread 35   f3073   "frame of buddy starting to wake up from the fallen cage"
    thread 35   f3136   "buddy's right arm pointing forward -- to the right"

**One thread, one slot, two characters**, with the changeover at the cage
collapse. The slot is re-occupied, so neither the variable nor the thread
identifies the actor.

### The rule, now with its mechanism

This directory's rule is unchanged and now has a reason rather than a warning
behind it: **an actor word comes from the scene.** Three levels of re-tasking
sit under that sentence --

1. across stages: all nine draw with `0x07`, three name it;
2. across scenes in one stage: six anchor clusters in PRISON, no shared art;
3. across time in one thread: slot re-occupied at the cage collapse.

-- and one consequence worth stating plainly. `BUDDY_X` and `BUDDY_Y` are
**misnamed**, not merely ambiguous. `ACTOR_X`/`ACTOR_Y` is what the scheduler
says they are. That is 1008 references in PRISON, 1043 in CAPSULE and 57 in
ENDING, so it is the owner's call and not a change to make in passing.
