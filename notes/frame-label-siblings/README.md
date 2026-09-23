# A label that draws one frame is named the way its siblings are

| file | question it answers | command |
| --- | --- | --- |
| `sibling_template.py` | Which placeholder labels draw only frame `<nn>` of one family, and what do their named siblings call that position? | `python3 notes/frame-label-siblings/sibling_template.py` |
| | Does the template derived from the other siblings reproduce a name someone already wrote? | `... --control` |
| | | `... --proposals` |
| `proposals_<branch>__<STAGE>.md` | the tables `apply_routine_renames.py` consumes | `... --proposals \| python3 notes/proposal-tables/split_by_branch_stage.py --out notes/frame-label-siblings --header routine` |

```
LABEL_6B98:
        video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
        jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
        video offset=CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y]
        ret
```

Both pictures say `F10`. Twelve lines below,
`PRISON_HERO_WALK_RIGHT_POSE_11` has the identical body with `F11`, and so do
POSE_12, 13, 14, 00..06 and 08. The name is not a judgement about what the art
depicts — the art is already named. It is the sibling convention applied at
the index the art states, which is `../draw-label-follows-constant/`'s rule
for the two-draw case with the frame index doing the work the single picture
did there.

**4 named** — PRISON poses 09 and 10 in both priority ports, the two holes in
a fifteen-frame run.

## The template is derived, and the derivation is checked

For a candidate drawing family `<FAM>` at index `nn`, every *other* label in
the same file with the same body shape drawing `<FAM>` at some `mm` is a
sibling. If all of them split into one prefix and one zero-padding width, that
is the file's convention for this family; if they disagree there is no
convention to follow and nothing is proposed.

`--control` hides each named sibling in turn, derives the template from the
rest, and checks it reproduces the name a person actually wrote: **127 of
127.**

## The normalisation that made it work at all, and the key that had to stay

The first run proposed **zero**, including the case above. The arm in
`LABEL_6B98` is `CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10` — a stage-scoped
copy in the cinematic bank — while its siblings draw
`HERO_WALK_RIGHT_ARM_F11` from the shared bank. Grouping on the raw family
string put the same limb in two groups. Stripping the bank prefix and the
stage token (`../cross-port-art/` already treats a stage-scoped copy as the
same art) fixes it without touching the control.

The opposite temptation — dropping the **body shape** from the group key,
which looks over-strict — was tested and rejected by measurement rather than
taste: the control falls from 127/127 to **21 of 27**, because PRISON holds
both `DRAW_HERO_WALK_RIGHT_F07` and `PRISON_HERO_WALK_RIGHT_POSE_07`-style
names on bodies of different shapes, and merging them makes each convention
contradict the other. It yields nothing extra either.

## What is left, and why

| held | why |
| --- | --- |
| 56 | fewer than two named siblings of the same shape — one sibling is a coincidence, not a convention |
| 3 | the named siblings agree on no one template |

Those 56 are the remainder of the 63 labels whose whole body is one frame of
one family. They are not blocked on evidence about the art; they are blocked
on there being no convention in that file to copy. A person naming one of
their siblings unblocks the rest.

Pooling siblings across branches — the same stage and family in amiga, msdos,
cartridge and GBA together — was tried, on the theory that one port might have
named what another left numbered. The control survives it (124 reproduced, 0
not) and it yields **0** extra proposals: these families have no named drawer
in *any* branch. Not adopted, since a wider pool with no yield is only a wider
surface for a mistake.
