# Carrying a name between stages, not just between ports

`../crossport-transfer/` moves a name between **ports** when the art is
byte-identical. The same move works between **stages of one port**, and
nothing was doing it — the cinematic banks share art, and a picture
identified in CAVES is the same picture in PRISON.

`../shot-hit-burst/` is what prompted it: CAPSULE's five-frame spark was
stuck behind a routine-family gap while PRISON had the identical five frames
under a complete constant family. Transferring by `canonical_md5` named all
ten. That was done by hand; `transfer_across_stages.py` generalises it.

## Most candidates are not usable, and the reasons are the interesting part

Matching alone gives 49 on amiga and 46 on msdos. What survives is 9.

| held | why |
|---:|---|
| 36 / 34 | **the name carries another stage's prefix.** `CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` moved into PRISON asserts CAVES inside PRISON. The art travels between stages; the stage word does not. Held rather than rewritten — stripping `CAVES_` and re-prefixing invents a name nobody earned. |
| 35 / 36 | the art matches two or more *different* names elsewhere, so there is nothing to transfer (#0120) |
| 6 / 7 | **several constants in the target stage match one name** (#0118). Six amiga/INTRO constants are byte-identical to `CINEMATIC_DROPLET_FALL_TRAIL`; one name cannot go on six. |
| 2 | **referenced from an all-branch chunk.** The `EQU` is renamed per branch, and an unprefixed `_unified/<stage>/*.inc` is read by every branch — so renaming amiga's and msdos's definitions while cartridge keeps `CINEMATIC_555` leaves that shared reference undefined for the two that moved. Found by applying it: verify-unified **27/29**, two undefined, while verify-stages stayed 29/29 because each canonical file was internally consistent. |
| 1 | on `disputed.txt` — `CINEMATIC_BUDDY_SMASHING_WINDOW_F8`, whose own subject is unsettled. Transferring it would spread the dispute. |

## The 9

    amiga/CAPSULE   CINEMATIC_114 -> CINEMATIC_HERO_LIFTOFF
    amiga/CAVES     CINEMATIC_170 -> CINEMATIC_HERO_LIFTOFF
    amiga/PASSCODE  CINEMATIC_037 -> CINEMATIC_OK_BUTTON
    amiga/PASSCODE  CINEMATIC_038 -> CINEMATIC_DEL_BUTTON
    amiga/PRISON    CINEMATIC_568 -> CINEMATIC_HERO_LIFTOFF
    msdos/CAVES     CINEMATIC_170 -> CINEMATIC_HERO_LIFTOFF
    msdos/PASSCODE  CINEMATIC_037 -> CINEMATIC_OK_BUTTON
    msdos/PASSCODE  CINEMATIC_038 -> CINEMATIC_DEL_BUTTON
    msdos/PRISON    CINEMATIC_568 -> CINEMATIC_HERO_LIFTOFF

`make test` 29/29 and 29/29, `undefined_symbols.py` clean, `--duplicates`
still one name per picture.

That the same 9 come out of both ports independently, at the same constant
numbers, is itself a check: these are stage-shared pictures in both releases.

## `deprefix_shared_art.py`: a stage prefix the art falsifies

The largest held category above — 36 on amiga, 34 on msdos — was "the name
carries another stage's prefix". Held is right for a *transfer*, but the
situation is not a transfer problem, it is a **wrong name**. NAMING.md scopes
a name to a stage when it means something there and not elsewhere; if the
identical picture is drawn in CAVES, PRISON and CAPSULE then `CAVES_` is
false about it. So the prefix comes off and every stage that draws the
picture uses the one name — which also names the siblings that had none.

**This corrects earned names, including three from earlier the same day.**
`CINEMATIC_PRISON_HERO_DEATH_F0..F2`, named from the scene that kills the
hero, is byte-identical art in CAVES and CAPSULE. The hero dies in every
stage: the frames were right and the prefix was not. (That group is
currently held by the all-branch-chunk guard, so the correction is recorded
and not yet applied.)

Applied: **26 groups, 76 constants** — `CINEMATIC_TELEPORT_UP_BEAM`,
`CINEMATIC_TELEPORT_DOWN_BEAM`, `CINEMATIC_CHARGED_BLAST_SWEEP_NEAR`,
`CINEMATIC_SHIELD_DECAY_PHASE_*` and others, each now one name across the
stages that share the picture.

### Two guards learned by breaking things

**Whole family or none.** The script works per *picture*, and a picture is
one member of a family. `CINEMATIC_CAVES_HERO_IDLE_DOWN_0`'s art appears in
CAPSULE while `_1` to `_4`'s does not, so de-prefixing that one member left
`CINEMATIC_HERO_IDLE_DOWN_0` beside `CINEMATIC_CAVES_HERO_IDLE_DOWN_1..4` —
two families with a hole each, and the two ports disagreeing about one
picture. `--duplicates` caught it; reverted, and a member whose
stage-prefixed siblings are not all in the group is now held.

**Both ports or neither.** Two groups de-prefixed on amiga while msdos's
equivalents were held by other guards, so one picture ended up with two names
across ports. One was fixed by de-prefixing msdos too; the other was the
family split above.

Verified after: `make test` 29/29 and 29/29, `undefined_symbols.py` clean,
`--duplicates` back to one name per picture over 1,898 pictures.

### The all-branch guard is avoidable when every branch has the name

`CINEMATIC_PRISON_HERO_DEATH_F0..F2` was held because
`prison_inline_setters_and_init.inc` — read by every branch — references it,
and the per-branch `EQU` rename would leave that reference dangling for the
branches that moved.

But all three branches *define* it (`chahi_amiga_1991`, `dos_1992` and
`cartridge_1992` PRISON.asm each have it), so renaming it **in every branch
and in the shared chunk at once** is consistent: 38 tokens across 8 files,
and nothing dangles. The guard protects against a *partial* rename, not
against this one.

So the rule is sharper than "held": a name referenced from an all-branch
chunk is safe to change when every branch defines it and the rename covers
them all together. The CAVES and CAPSULE siblings are then named per port as
usual, because those constants are per-port numbers (`263..265` on amiga,
`178..180` on msdos) even though the art is one picture.

Applied: `CINEMATIC_HERO_DEATH_F0..F2`, now one name across PRISON, CAVES
and CAPSULE in both priority ports, replacing the `PRISON_`-prefixed name
earned earlier the same day. The hero dies in every stage.

Remaining held by that guard: 2 groups per port, where not every branch
defines the name.

## The third way with a stage-prefixed name: drop the prefix

This module holds a transfer whose source name carries another stage's
prefix — 36 amiga and 34 msdos candidates — because "stripping `CAVES_` and
re-prefixing would invent a name nobody earned". That is right about
re-prefixing and it leaves a third option unconsidered.

If the art is byte-identical in **three** stages, it is not stage-specific,
and the stage word in any of its names is wrong rather than merely
untransferable. The fix is to remove it, which invents nothing.

The seven actor charge-glow frames are that case: identical `canonical_md5` in
PRISON, CAVES and CAPSULE, in both priority ports — 42 constants, exactly one
per frame per stage per port. They are now
`CINEMATIC_ACTOR_CHARGE_GLOW_F0..F6` everywhere, with no stage word.

The `PRISON_` prefix they briefly carried was not earned either: it was given
an hour earlier in the same session by `../render-and-name/`, before the CAVES
and CAPSULE copies were found. Dropping one's own scope is cheaper than
arguing about someone else's.

### Three conditions, and I found the second two by nearly breaking them

Written as "art in three stages, so drop the stage word", the rule produces
wrong names. Run over the whole tree it offered thirteen, and only one was
safe. The other twelve fail on one of these:

1. **The stage word must not be part of the subject.**
   `CINEMATIC_CAVES_FIRST_ROOM_BG` names a place; stripping `CAVES_` leaves a
   claim about no room in particular.

2. **The name must not carry a screen number.** This is the one that would
   have done real damage. The rule offered

   ```
   PRISON  CINEMATIC_384  ->  CINEMATIC_SCREEN_6A_BACKDROP_LAYER_0
   CAVES   CINEMATIC_134  ->  CINEMATIC_SCREEN_6A_BACKDROP_LAYER_0
   ```

   from `CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0`. A screen number is
   per stage **and** per port — this session already had to fix
   `CAPSULE_SCREEN_6C_BACKDROP_DRAW` because amiga numbers that screen 0x4C
   and never guards on 0x6C. `SCREEN_6A` with no stage is a number with
   nothing to index into. Three of the thirteen were this shape.

3. **The prefix being dropped must not be an earned name.** The charge glow
   qualified because the `PRISON_` on it was mine, from an hour earlier.
   `CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_0` and
   `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT` are someone else's, and rescoping
   them is a separate argument from naming the unnamed copies. Held.

The one that survived all three, `CINEMATIC_752` ->
`CINEMATIC_BUDDY_SMASHING_WINDOW_F8`, this module already holds under "art
matches two or more names", which is its own #0118 guard and is right.

So the net effect of the third way, beyond the charge glow, was **zero further
names** — and the conditions above are why, written down so the rule is not
reapplied from its one-line form.

### 2026-09-23: the same three conditions, 96 names

That "zero" was a fact about the tree at the time, not about the rule. A later
session named seven PRISON families from renders -- falling debris, blast
debris and its deposits, a blast mark, the x-ray flash and skeleton in both
facings, a hero aim pose -- and `canonical_md5` then matched every one of them
in **CAVES and CAPSULE**, both priority ports.

Twenty-four names, all three conditions met:

1. Falling debris, a blast mark, an x-ray flash and an aim pose name no place.
2. None carries a screen number. The three `CAPSULE_SCREEN_*_BACKDROP_LAYER`
   and one `CAVES_SCREEN_EE_BACKDROP_LAYER` candidates in the same held list
   fail on this and stayed held.
3. The `PRISON_` being dropped was the same session's own, hours old --
   exactly the charge glow's situation. `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`
   is in the same list, passes 1 and 2, and **stayed held** because its prefix
   is somebody else's.

Dropping the word in PRISON unblocked 96 constants in CAVES and CAPSULE across
both ports, applied in the same session. Assets went 67.2% to 69.1%, and
`one_picture_many_names.py` was unchanged at 73 amiga / 76 msdos while the
named-picture count rose from 2,482 to 2,530 -- the transfer added no new
name to any picture that already had one.

The tables are in `xstage_2026-09-23/` and the rescope in
`rescope_<branch>__PRISON.md`.
