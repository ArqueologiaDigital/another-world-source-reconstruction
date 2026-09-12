# Naming standard

What a finished name looks like in this source tree, and what may not be called a
name at all. The executable half is
`another-world-archaeology/tools/lint_naming.py`; run it with
`make lint-naming-strict STAGE=<X>` before calling a stage done.

This is descriptive before it is prescriptive. The rules below were derived from
the two stages the project treats as finished — LAKE and CODE_WHEEL, both ports,
1,660 label lines and 1,674 EQU lines, 929 unique names — by the probes under
`another-world-archaeology/tools/label_grammar/`. Where the existing corpus is
inconsistent, that is said plainly rather than papered over.

Evidence grades (E0–E4) are defined in
`another-world-archaeology/SEMANTIC_DISASSEMBLY_PLAN.md` §2 and are used here
without redefinition. **E1 is operand transcription and does not count as named.**

## 1. Routine labels

### The shape, as it actually is

The plan proposed `<ACTOR>_<VERB>_<QUALIFIER>_<SUFFIX>`. Measured against the
finished stages, that template matches **72 of 929 names, 7.8 %**. It is not the
grammar in use and aiming at it would mean rewriting most good names.

What the corpus actually does:

| property | measurement |
|---|---|
| head is an actor or scope | 583 / 929 (62.8 %) |
| head is a verb | 231 / 929 (24.9 %) |
| has any control-flow suffix | 310 / 929 (33.4 %) |
| segments per name | median 5, mean 5.07, range 2–11 |

So the real shape is:

```
<SCOPE>_<SUBSYSTEM|STATE>_[<QUALIFIER>…]_[<ROLE-SUFFIX>]
```

`<SCOPE>` is an actor (`HERO`, `BEAST`, `BEETLE`, `SLUG`, `DROPLET`, `LESTER`,
`TENTACLE`, `VINE`, `REED`, `ALIEN`), a stage (`LAKE`, `CODEWHEEL`), a screen
ordinal (`FIRST`, `SECOND`, `THIRD`), or a verb. After an actor head, slot two is
usually a **subsystem or state noun**, not a verb — `HERO_TICK`, `HERO_PHYSICS`,
`BEETLE_AI`, `BEETLE_ANIM`, `DROPLET_POS`, `SLUG_ATTACK`. Only 187 of 583
actor-headed names have a verb in slot two.

The role suffix is optional and absent from two thirds of names. Write it when the
routine's control-flow role is the point, omit it when the subject is.

### Suffix vocabulary

Use these; they already carry meaning in this tree. Counts are from the finished
stages.

| suffix | n | means |
|---|---|---|
| `_LOOP` | 131 | repeats until a condition or `djnz` |
| `_CASE_<n>` | 123 | one arm of a dispatch — see the radix rule below |
| `_UPTO_<n>` `_FROM_<n>` `_BELOW_<n>` `_ABOVE_<n>` | 0 | one arm of a range ladder: the band it handles, from its own guard — see below |
| `_HOLD` | 8 | spins on the same frame for a counted delay |
| `_DELAY` | 13 | counted wait with no drawing |
| `_DONE` | 16 | the join point after a conditional sequence |
| `_INIT` | 13 | one-shot setup, usually falls through |
| `_RET` | 12 | exists to be returned from |
| `_DISPATCH` | 10 | selects among arms on a variable |
| `_ENTRY` | 3 | a thread entry point, the target of a `setup` |
| `_PHASE_<n>` | 14 | a named step in a scripted sequence |
| `_TICK` | 4 | one frame of an animation |
| `_REPEAT` | 7 | re-enters itself after a `break` |
| `_PRELUDE` | 5 | runs before the routine it precedes |

`_GATE` appears in exactly one label (`DROPLET_SOUND_START_GATE`) despite being
heavily used in the *flag* vocabulary. Do not reach for it for ordinary
conditionals; reserve it for a deliberate suppression point, matching the
`BEETLE_KICK_GATE_1` sense.

### Forbidden

The lint fails on each of these.

- `LABEL_<hex>`, `JUNK__<hex>` — the emitter's placeholders.
- `RET_TARGET_<hex>`, `ADDR_AT_<hex>`, `KILL_CHAN_AT_<hex>`, or any name ending in
  a raw address. A name that contains the address tells the reader nothing the
  label line did not. Two such names were removed from LAKE in 2026-09:
  `RET_TARGET_1A88` became `SHARED_GUARD_RET`, and
  `YIELD_THEN_RESTART_AT_1B22` became `YIELD_THEN_RECHECK_LAKE_EDGE`.
- Bare `_L<n>` fold-local suffixes. 39 remain in CODE_WHEEL, worst being
  `CW_CLEAR_VAR_22_L0` through `_L34` — 35 labels on one stem. These are emission
  counters.
- `FOLD_BODY`, `DEDUP`, `__HELPER` — consolidation artefacts (#0093). **Do not fix
  `__HELPER` by stripping the suffix.** Tried 2026-09-12: 12 of the 13 such labels
  collide with an existing label of the same stem, so stripping creates a duplicate
  and the byte gate falls from 29/29 to 23/29. The suffix is what distinguishes the
  shared helper from a same-named label elsewhere. Give the helper a real name
  instead, which removes the collision as a side effect.
- Any identifier containing the substring `EQU`. The assembler used to treat such
  a line as an EQU definition and silently drop it, so `..._SEQUENCE:` changed the
  assembled bytes with no error (#0073, fixed 2026-09-12). The lint keeps the rule
  because the failure was silent for months and the word is an easy one to reach
  for.
- `_A` / `_B` / `_VARIANT_<n>` to separate two similar routines. Distinguish by
  caller, role or scene instead. This is a standing project convention, see
  `another-world-archaeology/docs/content/conventions/feedback_no_index_suffixes.md`.
- Two labels with the same name in one stage. The assembler keeps one definition
  and every reference collapses onto it, so the other assembles to the wrong
  target (#0118). LAKE had three such cases in the unified tree, passing the byte
  gate only through positional resolution.

### `_CASE_<n>`: state the radix

The corpus uses two incompatible conventions for the tail, and `CASE_10` is
ambiguous between them:

- **Immediate** (hex): `CW_ALPHANUM_CASE_10` guards `jne [0x05], 0x10`. Used by
  `CODEWHEEL_SYMBOL_DISPATCH_CASE` (41), `CW_ALPHANUM_CASE` (31),
  `CW_PUZZLE_KEY_CASE` (28).
- **Ordinal** (decimal, 1-based): `DROPLET_POS_CHECK_CASE_10` guards
  `jne [0x3B], 0x0A`. Used by `DROPLET_POS_CHECK` (14), `AMBIENT_RND_CASE` (3),
  `BEAST_AMBIENT_CASE` (3), `DROPLET_VARIANT_CASE` (3).

**Rule: the tail is the immediate, written in hex with the same width as the
operand.** The ordinal form is retired. And `_CASE_<n>` is only legitimate when
the dispatcher has a name and the case order has been **traced**, not assumed —
see #0104.

### Range ladders: the arm's own guard names its band

A fold chain whose arms test thresholds rather than values is a piecewise
function written as code, and `_CASE_<n>` is wrong for it: the immediate is a
bound, not the value matched. The arm **handles the complement of its guard**,
and the suffix says which side:

| first line of the arm | the arm runs when | suffix |
|---|---|---|
| `jne [v], N, next` | `v == N` | `_CASE_N` |
| `jg [v], N, next` | `v <= N` | `_UPTO_N` |
| `jl [v], N, next` | `v >= N` | `_FROM_N` |
| `jge [v], N, next` | `v < N` | `_BELOW_N` |
| `jle [v], N, next` | `v > N` | `_ABOVE_N` |
| `je [v], N, next` | `v != N` | none of these — name the arm by its role |

`N` is the immediate in hex at the operand's width, the same radix rule as
`_CASE_`. Decided 2026-09-12 (#0132) after measuring the 26 chains this affects:
12 of them mix equality and relational guards from arm to arm, so no single
chain-level suffix can be right, and the arm has to be named from what it
itself tests. `tools/apply_routine_renames.py` rejects a band or case tail
that disagrees with the arm's first line, and `tools/fold_chain_cases.py
--names` writes these tails given a name per chain.

Two shapes the fold tool also leaves as `_L<n>` are not ladders at all and take
no tail: a chain of **one** arm is the routine's body past its first
conditional, and a **mixed** chain is a routine cut at every conditional. Name
those as routines.

### Prefer one spelling

The corpus carries both halves of many doublets. Prefer the left column:

`CHECK` over `CHK` · `SCREEN` over `SCR` · `POSITION` over `POS` in prose
positions · `RANDOM` over `RND` · `CINEMATIC` over `CIN` · `RETURN` over `RET`
except as the `_RET` suffix · `LEFT`/`RIGHT` over `L`/`R` except in an established
family · `CODEWHEEL` over `CW`.

`HERO` and `LESTER` both name the same character, 137 and 34 times. They are not
interchangeable: **`HERO` is the engine identity** (it owns the `HERO_X`,
`HERO_ACTION` variables and the hero thread), **`LESTER` is the narrative one**
(use it in scene and cutscene names). `BEAST_KILLS_LESTER_F6_LOOP` and
`SNEAKY_TENTACLE_HIT_HERO` are both correct under that split.

Narrative sentence labels are allowed and good where a routine *is* a story beat:
`THE_BEAST_IS_KILLED_BY_A_LASER_SHOT`,
`A_CALM_ALIEN_POOL_BEFORE_LESTERS_ARRIVAL`. Seventeen exist; they are the 9–11
segment tail of the distribution. Do not use the form for a loop or a helper.

## 2. Polygon EQUs: `CINEMATIC_` and the shared bank

```
CINEMATIC_<ENTITY>[_<ACTION|STATE>][_<DIRECTION>]_<frame index, decimal, 0-based>
```

822 unique names, 86 % ending in a frame index, 213 families, and **no family has a
gap in its index run**. Keep it that way: a gap means a frame was missed or
misfiled.

- Minimum grade **E3**: render the polygon and look at it before naming it. This
  is a standing convention
  (`conventions/feedback_render_before_renaming.md`), and the Amiga renderer works
  as of 2026-09-12 (#0097) — `awvm-disasm … all_levels amiga` emits 4,209 SVGs.
- Never name from the index. `LOOP_DRAW_CINEMATIC_199_AT_CENTER` became
  `LOOP_DRAW_CINEMATIC_VINE_SCREEN_BG_DECOR_AT_CENTER` once the polygon was known.
- Never embed screen coordinates. `CINEMATIC_DECOR_AT_305_155_F0` both leaks a
  magic number and breaks frame-index parsing —
  `CINEMATIC_LAKE_DECOR_AT_327_164` parses as family `…AT_327`, frame 164.
### When the ports draw different art at the same slot

A polygon constant is one symbol shared by the branches with a per-port value,
used at one bytecode position. The ports do not always draw the same thing there,
and then **the name belongs to the branch whose art it describes, not to the
symbol**.

Measured on INTRO, 2026-09-12, with `tools/check_constant_pairings.py`:

| constants | pairs | same picture in both ports |
|---|---:|---:|
| already carrying a semantic name | 172 | 159 (92 %) |
| still `CINEMATIC_<index>` | 366 | 8 (2 %) |

`CINEMATIC_<index>` was never a cross-port claim. It means "the Nth polygon this
port's bytecode references", numbered per port. Where it diverges it is not by
much: 320 of the 327 divergences that could be traced are within 8 indices, the
two releases drawing neighbouring frames of the same run, because the 1991
release has frames the 1992 ports dropped and one extra frame early shifts
everything after it. **The family is shared; the frame is not.**

So:

- Name a constant on every branch only when the art agrees. Check, do not assume.
- Otherwise scope the name to its branch with
  `tools/apply_branch_scoped_names.py`. This costs nothing structurally: every
  draw site referencing a divergent constant is already inside a `.if BRANCH`
  block, because the divergent art is what made that line diverge.
- Never carry a name earned on one port's render onto another port's symbol. It
  would be right 2 % of the time.

And before commissioning a naming pass over a stage, run the pairing check
first. Ten passes over INTRO produced sound evidence that could not be used as
written, because nobody had asked whether the names they were naming meant one
thing or four.

- Cross-port name sharing needs ≥95 % full-polygon similarity
  (`tree_audit.py --min-similarity 95`). That threshold is the 2026-05-11 default
  and is **not settled**: #0107's own bands put 158 pairs between 75 % and 99.5 %,
  to be walked by eye. Until then, a pair in that band is neither accepted nor
  dropped.
- `_UNUSED_` in a cinematic name is a research flag for a bank slot that exists
  but is never invoked. Keep those EQUs at top level and never strip them
  (`conventions/feedback_unused_equs_top_level.md`). One that turns out to be
  referenced is mislabelled — the lint checks this.
- `_DUP_<n>` and `_ALT` collision-breakers (`CINEMATIC_ALIEN_GLYPH_28_DUP_1`) are
  the index-suffix smell in another costume. Name the second instance by role.

**The shared bank (`COMMON_VIDEO_NNN`) has no semantic names at all** — 1,021 on
Amiga, 2,969 references in `_unified`, zero named. Its numbering is worse than
arbitrary: it is the order the disassembler happened to encounter entries across a
whole `all_levels` run, so level N's header lists every entry seen in levels ≤ N.
Before these can be named, the emitter must key them by offset (plan item T7) and
the existing names must move to an interim port-invariant `CV_<OFFSET4>` — the
bank is byte-identical between Amiga and MS-DOS, so one name per offset is
correct. Until that lands, do not hand-name `COMMON_VIDEO_NNN`.

## 3. VM variables

Convention: `<ROLE>_<QUALIFIER>`, and it already works — the 15 engine aliases in
`src/levels/_common_vars.inc` need no change.

**Scoping rule.** A name belongs in `_common_vars.inc` only if it means the same
thing in every stage and every port. Anything stage-variant belongs in the
registry's per-stage `variable_aliases` instead. Today that holds 5 names
(`HERO_X`, `HERO_Y`, `BUDDY_X`, `BUDDY_Y`, `COUNTER`) against 218 distinct
variable ids in use, so 20 names cover 28 % of references.

A label may not embed a raw variable number once that number has an alias. 78
labels in the finished stages still do (`BLITTER_LOOP_WITH_VAR1B_2B`,
`SUM_HASH_VARS_TO_VAR_37`), which is backlog rather than a violation — the lint
reports it as advisory for exactly this reason.

### Which ids are ready, and the ones that never will be

`tools/variable_roles.py` reads the role straight out of the opcodes: a variable
consumed as `video … x=[v]` is a screen X, one counted down by `djnz` is a
counter, one compared against a constant is a flag. Measured 2026-09-12:

| stage (msdos) | raw ids | role stated outright | used in several roles |
|---|---:|---:|---:|
| LAKE | 151 | 82 | 17 |
| INTRO | 30 | 13 | 14 |

**LAKE is the stage this document calls finished** — 99.5 % of its *labels* are
semantic — and 151 of its variables are still raw ids, 82 of them nameable
today. The variable layer is untouched everywhere, not merely behind.

The last column is the part that changes the convention. `<ROLE>_<QUALIFIER>`
assumes a variable *has* a role. INTRO's low ids are scratch registers reused per
scene: `0x01` is a countdown 66 times, a screen X 7 times and a screen Y 3 times,
in different routines. No single name can be right for it, and inventing one
(`COUNTER_OR_X_01`) would be a worse lie than the raw id, which at least claims
nothing.

So: name a variable only where one role accounts for its uses. Where several do,
leave the raw id and let the routine name carry the meaning. Nearly half of
INTRO's variables are in that state against a ninth of LAKE's — the difference
between a cinematic stage and a gameplay one, not a defect in either.

### The four `HACK_VAR_` placeholders

`HACK_VAR_<hex>` is `LABEL_<hex>` for variables and must go. Evidence gathered
2026-09-12:

| var | evidence | ready? |
|---|---|---|
| `0x67` | 6,281 references, the most-referenced named variable. Guards hundreds of routines with `jne [0x67], [COUNTER], …_NOOP_RET`. Helpers already named `COPY_HACK67_TO_VAR66`, `ADD_HACK67_BY_20`, `SUB_HACK67_BY_20` — ±0x20 is screen-grid navigation. Proposed `SCREEN_NUM`, making `0x66` `CACHED_SCREEN_NUM`. | **yes, E2** |
| `0xDC` | One of five constants in the copy-protection gate (`LIKELY_A_COPY_PROTECTION_MECHANISM`, registered at offset 0x0080 of every stage): `jne [0xDC], 0x21, …`. The bytecode also sets it to 0x21 itself. Proposed `COPY_PROTECT_MAGIC` — and the same find names four never-named siblings: `0xBC`, `0xC6`, `0xE4`, `0xF2`. | **yes, E2** |
| `0x54` | 155 references. A sign/high-bit discriminator selecting which title bitmap loads (`jge [0x54], 0x80, LOAD_RESOURCE_13`), but it is also ANDed with 1, set to 0x40 and to −5, and swapped with var 0x13. May be stage-variant. | no — check its LAKE/TANK/CAPSULE sites first |
| `0xF7` | 8 references, all `add [0x37], [0xF7]` — a term in the codewheel/passcode validation hash. Below the plan's own ≥20-reference threshold. | no |

`0xF8` is an unclaimed easy win: a heavily used scratch register, already implied
by `COPY_VAR00_TO_VARF8`. `SCRATCH` at E2.

## 4. Channels

`CH_<ROLE>` for port-and-stage-invariant slots, `CH_<STAGE>_<ROLE>` otherwise.
63 distinct channel ids are used across 3,965 `setup` sites.

**A channel name is derived, not independently evidenced.** A channel's role is
the union of the roles of the routines scheduled on it, so a stage's channels
become nameable only once its labels are. Four of nine stages are still dominated
by placeholder routine names, so their channels must wait. No channel name can
ever be E4: there is no VM runtime in any repo (#0089).

Verify any channel claim with
`operand_inventory.py --layer channel-roles`, which reports setups, how many stages
use the channel, and the dominant role of the routines on it. Invariant and
nameable now, at E2 — four are named as of 2026-09-12 and the rest deliberately are
not, with a test asserting that stage-scoped channels such as 0x01 (196 setups over
20 files, no single role) stay literals:

| channel | role | evidence |
|---|---|---|
| `0x3C` | frame present / blit loop | 333 setups, all 9 stages; second busiest |
| `0x14` | hero state machine | 433 setups, all 9 stages; the busiest channel in the game |
| `0x15` | hero run and deceleration | `deleteChannels 0x14,0x16` is the most common range operation at 94 sites — the triple is one unit |
| `0x16` | hero physics and AI tick | as above |
| `0x00` | stage entry | `ENTRY_POINT_OF_<STAGE>` |
| `0x3D`–`0x3F` | treated as a unit by the engine | `freezeChannels 0x3D,0x3F` is the most common freeze range (13), and `0x3D` is the only id in `0x00`–`0x3F` that is never a `setup` target anywhere. Call the *range* reserved, not each slot: `0x3F` carries 75 setups over 6 stages and its dominant classified role is `init`, so it is in use |

LAKE's full per-channel table is nameable today because LAKE is fully named; it is
recorded in `another-world-archaeology/docs/content/research/17-vm-channel-map.md`.
Note that document is stale by 88 setups and must be regenerated before its counts
are quoted.

**Carve-out against the no-index-suffix rule.** Two LAKE families are positional
by nature: the four-slot animation multiplexer ring (`0x0B`, `0x0D`, `0x0F`,
`0x11`) and the ambient-audio pair (`0x24`, `0x25`). There the index *is* the
role, so `CH_LAKE_ANIM_RING_SLOT0` is correct and not a violation.

## 5. Resources

Three symbol spaces, because `load id=` currently conflates them:

```
SND_<what>       sound sample          MUS_<what>    music
SCR_<stage>_<what>  full-screen bitmap  PART_<what>   bank switch, not a resource
```

**`load id=` mixes resource ids with bank switches.** `load id=0x07D0 + N` and
`load id=0x3E80 + N` are `bankSwitch N`; 19 of the 126 distinct `load` operands
are these. A name table that treats them as resources will be wrong for all 19.

**`song id=` has an undecoded class.** Beyond the three real music ids, the
cartridge ports use a contiguous `0x0BB9`–`0x0BE0` block and GBA adds
`0x0FA0`–`0x0FA3`. These are above the 146-entry memlist, so they are host-side
audio requests, not resource ids. Nothing in either repo decodes the numbering —
do not invent `MUS_3001`.

**A prefix collision to fix.** `MUS_MARK` is a *VM variable* alias (0xF4, the
music-position marker) and predates this standard, while `MUS_<what>` is the prefix
for *music resource ids*. A listing now defines both `MUS_MARK EQU 0xF4` and
`MUS_INTRO_THEME EQU 0x0007` — different namespaces, and no assembler conflict since
they occupy different operand positions, but a reader cannot tell which is which.
Rename the variable to `MUSIC_POS_MARK` when the variable layer is next touched; the
resource prefix is the one worth keeping, since there are three music ids and only
one such variable.

Readiness by kind:

- **Music: complete.** Three ids, all identified at E3 by rendering and
  listening. `MUS_INTRO_THEME` 0x07, `MUS_END_CREDITS` 0x8A, and
  `MUS_LAKE_CUT_AMBIENT` 0x89 — a 26.5 s track loaded in LAKE behind a `jmp` and
  never played.
- **Screens: unblocked as of 2026-09-12.** All 12 type-2 resources unpack to exactly
  32,000 bytes, one 320×200 4bpp page, each loaded at exactly one site in one stage.
  They are full-screen bitmaps, not the "POLY_ANIM" the extractor calls them.
  `another-world-archaeology/tools/render_screen.py` renders them: Amiga-style
  planar, four 8,000-byte bitplanes, palette decoded the same way the polygon
  renderer does it.

  Use `--contact`, which renders the screen under all 32 palettes in one sheet.
  Which palette a screen displays under is a runtime fact — the bytecode usually
  loads the bitmap under a black palette and fades up, so the palette live at the
  `load` site is often all-black and renders nothing. The contact sheet makes the
  choice a look rather than a guess. Sheets for all twelve are committed under
  `docs/assets/screens/`.

  One is already identifiable beyond doubt: **`0x12` is the Interplay logo**, the US
  publisher's title card, loaded in CODE_WHEEL. It uses 15 palette indices, index 0
  being 88 % background, so the lettering carries a gradient — which is why it looks
  speckled under a palette that was not designed for it.
- **Sounds: not ready.** 4 of 103 identified. `SND_UNUSED_<hex>` is the right
  holding form, mirroring the cinematic convention.

Also: resource `0x11`, typed "UNKNOWN", is the shared video2 bank. It is bound by
the engine's part table rather than by any `load`, and the highest
`COMMON_VIDEO` EQU value (`0x61B0` = 25,008) fits inside its 25,108 bytes with 100
to spare, which no other resource does.

## 6. Video pages

```
PAGE_0 … PAGE_3     the four real pages
PAGE_WORK   = 0xFF  back buffer: the select, fill and blit target
PAGE_DISPLAY = 0xFE the currently displayed buffer
SCROLLED    = 0x80  a copyVideoPage src flag: offset the copy by SCROLL_Y
```

Six of the eight distinct operand values are nameable now at E2, proven from
committed source without needing an engine citation:

- `0xFF` is the work buffer — the universal `fill page=0xFF` / `selectVideoPage
  0xFF` / draw / `blitFramebuffer 0xFF` idiom, and it is the most common operand
  in all three positions.
- `0xFE` is the displayed buffer, and `blitFramebuffer 0xFE` is a **re-present
  without redrawing**: `setPalette N` immediately followed by
  `blitFramebuffer 0xFE` occurs 38 times, usually with a one-slice pause. A
  palette flash changes the colours of pixels already on screen.

Bit 7 of a `copyVideoPage src` is **probably** a scrolled copy, and the evidence is
weaker than it first looks. Of 214 sites with bit 7 set, only 68 are preceded
within three lines by a write to `SCROLL_Y`; 146 are not. That is consistent with
`SCROLL_Y` being set once outside a loop, and the project already named routines
`SCROLL_Y_BLIT_DISPATCHER` and `BLITTER_LOOP_COPY_PAGE_80` on that reading — but
it is an inference, not a proof. Treat `SCROLLED` as provisional until it is
checked against engine source, and do not let a name assert more than the evidence
does.

Write the composite form `copyVideoPage src=PAGE_3|SCROLLED` so the flag reads as
a flag. Bit 6 (`0x40`, `0xC0`) is **not** nameable yet: 32 sites are consistent
with "bit 6 is masked off", but nothing in either repo settles it.

Page symbols must never share a spelling with variable symbols, even though they
cannot collide in the assembler: `PAGE_WORK` is 0xFF and so is `PAUSE_SLICES`.

## 7. Strings

`STR_<first words>` for stable text, but with one hard rule:

**Name the slot's role, not its rendered text, wherever the text varies by
release.** String ids resolve against a per-port ROM, so the same id is different
text in different releases. `0x01FA` is the proof: it is the US Interplay teaser
in one table and the EU "ANOTHER WORLD / L'AUTRE MONDE" title in another. It must
be `STR_TITLE_SCREEN`, never `STR_OUT_OF_THIS_WORLD`.

126 distinct `text id=` values over 1,200 sites. About 40 — the UI, credits and
INTRO dialogue — are legible inline in the listings today and can be named at E3
immediately. 14 ids do not resolve at all and appear as `string_<hex>`; the lint
flags those.

The layer cannot be finished until the per-port string ROMs are extracted. Amiga,
SNES, GBA and Symbian listings currently show **MS-DOS** strings, which is a
correctness bug rather than a naming gap, and Amiga's string ROM is recorded as
`BAD_DUMP`. Cross-port name sharing for strings needs the same justification
#0107 demands for polygons: SNES-EU and Genesis-EU have byte-identical bytecode
and different text.

## 8. Palettes

`PAL_<STAGE>_<SCENE>`, **stage-scoped**, unlike every other layer here. The same
`setPalette 0x02` selects different colours in LAKE and TANK, because slots are
per-resource and there is one palette resource per stage.

Zero of 32 slots have an identified meaning today — the weakest layer in this
document. What exists is a used/unused partition per stage and a swatch gallery.
Naming is an E3 render-and-review task and the renderer already exists.

Two structural cautions:

- Many slots are **steps in a fade ramp**, not scenes. CODE_WHEEL already names
  the ramps rather than their interior slots (`PAL_FADE_DOWN_17_TO_11`,
  `PAL_FADE_UP_9_TO_F`). Prefer naming the ramp; do not invent
  `PAL_<STAGE>_<RAMP>_STEP<n>`.
- The research note claiming "slot 28 is never used in any level" is wrong, and
  its own table shows it: ENDING uses `setPalette 0x1C` in all three ported
  branches, and CAVES uses it on cartridge only. Correct that note when the first
  palette names land.

## 9. Constants

Bit names for masks, taken from how the code tests them rather than invented:
`HERO_ACTION_POS_MASK` is already the model. A constant name is worth coining only
where the same literal is tested in more than one place.

## 10. Recording the evidence

Every rename commit body carries, per name:

```
LABEL_HHHH -> NEW_NAME
  Evidence: E<0-4> <artefact path, or "render <file>.svg", or "trace <file>">
  <prose, optional>
```

`apply_label_comments.py` injects the `Evidence:` line into the source as a
comment, and the registry work in plan item T6 parses those comments, so a name
made today is graded later without re-reading the bytecode.

Two numbers go in the commit body for any stage touched: the strict-semantic share
and the placeholder count, both from
`another-world-archaeology/tools/naming_census.py`. The classifier in that file is
the project's definition of "placeholder", "mechanical" and "semantic" — if you
disagree with a classification, change the classifier, not the number.

## Reproducing every number in this document

```bash
cd another-world-archaeology
python3 tools/operand_inventory.py                    # channels, resources, palettes, pages, strings, vars
python3 tools/operand_inventory.py --layer proofs     # the three structural arguments above
python3 tools/operand_inventory.py --tree per-branch  # the same over the 28 per-branch files
cd ../another-world-source-reconstruction
python3 ../another-world-archaeology/tools/label_grammar/label_grammar_probe.py .
python3 ../another-world-archaeology/tools/naming_census.py table
```

The two trees give different counts for the same layer — the unified tree has been
consolidated and the per-branch files duplicate shared code across four branches —
so always say which tree a number came from. Counts above are from the unified
tree unless stated. Note that
`another-world-archaeology/docs/content/research/17-vm-channel-map.md` reports
4,053 setup sites where the tree now has 3,965; regenerate it before quoting it.
