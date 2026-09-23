# The routine that paints a screen's backdrop

| file | question it answers | command |
| --- | --- | --- |
| `backdrop_drawer.py` | Which screen's backdrop does this routine paint? | `python3 notes/backdrop-drawer/backdrop_drawer.py` |
| | Do both sources reproduce the screen of every routine already named for one? | `... --control` |
| | Where the layers are still numbered, do the two ports agree? | `... --pairs` |
| | | `... --proposals` |
| `proposals_<branch>__<STAGE>.md` | the tables `apply_routine_renames.py` consumes | regenerate with `--proposals \| python3 notes/proposal-tables/split_by_branch_stage.py --out notes/backdrop-drawer --header routine` |

## The gap this closes

499 pictures were already named `CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>`
and only **10** routines were named `<STAGE>_SCREEN_<NN>_BACKDROP_DRAW`. The
painters were still `LABEL_CDB2`, `JUNK__9DD7`,
`DRAW_CIN_305_TO_309_5F_AT_AACB4DF5` — two of those three forms carrying the
raw hex tail `docs/NAMING.md` §1 forbids — while every picture in their bodies
already said, by name, which screen they were painting.

63 painters named. The name was one hop from where it was needed.

## The two sources

A routine is proposed only when both agree:

1. **Its own layers.** Every named picture it draws is
   `CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP...` for a single NN.
2. **`../screen-scope/`** — the forward dataflow on `[SCREEN_NUM]` — pins the
   label to exactly `{NN}`.

They share no input. Source 1 reads names a person wrote from the art; source
2 reads `je`/`jne` guards and was never told the names exist.

`--control` re-derives NN for every routine already named
`<STAGE>_SCREEN_<NN>_BACKDROP_DRAW`, from both sources: **84 agree, 0 do not.**

## What it refuses, and why each guard earned its place

| held | why |
| --- | --- |
| 2468 | the name is already earned — a descriptive name someone derived from the art is never displaced (#0120) |
| 2170 | not a backdrop painter |
| 23 | only the dataflow pins it; nothing confirms |
| 4 | its named pictures do not all point at one screen — two screens' layers, or a backdrop layer beside a picture that claims no screen |
| 4 | its layers and the dataflow disagree — see below |
| 1 | the dataflow cannot pin it |

**"Not a backdrop painter"** is the guard that matters most, and it was added
after the probe got it wrong. A backdrop is scenery: every layer at a literal
`x,y`, and either a page wipe (`fill`/`copyVideoPage`) or a layer covering the
whole 240x160 view. Without that test the dataflow cheerfully labelled
`LABEL_136B` — two frames of the buddy walking, drawn at `[BUDDY_X],[BUDDY_Y]`
— the backdrop of the screen he walks across. That is hazard **#0138** in a new
costume: the scene a figure is drawn in does not name the figure, and the
figure does not name the scene. The guard removed 13 such proposals.

**"Several painters in one file derive the same screen"** exists because four
PRISON labels all derived 0x24: where several do, none of them is *the*
painter, so all are dropped (#0118).

## Three corrections this turned up

### A name on a routine that draws nothing

amiga CAVES carried `DRAW_CAVES_FIRST_ROOM_BG` on

```
DRAW_CAVES_FIRST_ROOM_BG:
        break
        jmp CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X
```

— the join of that routine's two-way assignment to `[0x42]`, then a yield and
a loop back. It paints nothing. The msdos counterpart of that exact position
was the unnamed `LABEL_D1E3`; the real painter, in both ports, is the `fill` +
two-layer routine further down. Both join labels are now
`CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X_LOOP`, and both painters are
`DRAW_CAVES_FIRST_ROOM_BG`.

That also cost a name: the probe had named amiga's painter
`CAVES_SCREEN_67_BACKDROP_DRAW` while msdos had long called it
`DRAW_CAVES_FIRST_ROOM_BG`, so the port that had the descriptive name could no
longer give it away. The probe now refuses any routine whose counterpart in
the other port — matched by the md5 of the art it paints, never by index
(#0107) — already carries an earned name.

### A screen number is a property of the port

`align_branch_names.py` pairs routines across ports by aligned instruction
stream and carries names over, which is right for a routine name and **wrong
for one containing a screen number**. It backported msdos's
`CAPSULE_SCREEN_6C_BACKDROP_DRAW` onto the aligned amiga routine, and the
control caught it:

```
amiga CAPSULE  CAPSULE_SCREEN_6C_BACKDROP_DRAW   name 0x6C  layers -  flow 0x4C  **
```

amiga CAPSULE compares `[SCREEN_NUM]` to 0x4C **four times and to 0x6C not
once**; msdos compares it to both. The two ports number this screen
differently. The amiga routine is now `CAPSULE_SCREEN_4C_BACKDROP_DRAW`, the
value its own port actually uses. Anything of this shape must be re-checked
with `--control` after an `align_branch_names --merge`.

### Four routines whose layers claim a screen the dataflow denies

Left alone, and recorded here because they are the next piece of work rather
than noise. `python3 notes/backdrop-drawer/backdrop_drawer.py` prints them.

```
amiga CAVES    LABEL_D2EB   layers say 0x8F, flow says 0xAF
msdos CAVES    LABEL_D7CB   layers say 0x8F, flow says 0xAF
msdos CAPSULE  LABEL_9CCB   layers say 0xAB, flow says 0xEC
msdos CAPSULE  LABEL_9CFF   layers say 0xAB, flow says 0xCB
```

In CAVES, `LABEL_D2EB` (screen 0xAF) and the routine now named
`CAVES_SCREEN_8F_BACKDROP_DRAW` paint the **same three layers at the same
anchors** and then diverge, so those three are a base shared by two screens
and `CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_{0,1,2}` claims an exclusivity
it does not have — the same rule `../remaining-art/` states for screens 0x92
and 0x93.

In CAPSULE it is worse: `CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_0` is
painted by three routines at three different `y` anchors (198, 151, 187),
**no** routine in either port is pinned to 0xAB, and amiga CAPSULE never
compares `[SCREEN_NUM]` to 0xAB at all. Those names are very likely wrong.
Demoting them is a separate change with its own evidence, not a side effect of
this one.
