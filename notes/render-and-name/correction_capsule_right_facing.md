# Correction: the five CAPSULE pose names that never got their facing

`proposals_chahi_amiga_1991__CAPSULE_facings.md` gave every slot of both
CAPSULE sprite sheets a `LEFT`/`RIGHT` word except five, which the applier
refused: the right-facing group-0 run would have been `{1, 2, 3, 4, 6}`, and a
family may not gain a gap. Index 5 of that run is `CINEMATIC_178`, one picture
serving **both** facings, which already carries the left-facing name.

The refusal was right at the time and is not right now. The five currently sit
in the tree as `CINEMATIC_CAPSULE_FIGURE_POSE_0_1..0_6`, so the source family
`..._POSE_0` **already has the hole at 5**. Renaming every one of its members
to `..._POSE_RIGHT_0_<same index>` reproduces a gap that exists rather than
adding one -- which is exactly the case `apply_cinematic_renames.py` documents:

> A family renamed WHOLESALE carries its gaps with it, and they are not gaps
> this proposal added. Where every proposed member of a destination family
> comes from one source family at the SAME index, the gaps to beat are that
> source family's.

So the hole is inherited, the names get their facing, and the picture at index
5 stays where it is with the left-facing name and a note.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_CAPSULE_FIGURE_POSE_0_1 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_1 | high | correction: the right-facing dispatcher's group 0 index 1, `je [0xF8], 0x01` |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_2 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_2 | high | correction: index 2 |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_3 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_3 | high | correction: index 3 |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_4 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_4 | high | correction: index 4 |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_6 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_6 | high | correction: index 6. Index 5 is `CINEMATIC_178`, dispatched at group 0 index 5 by both facings and named `..._POSE_LEFT_0_5` |
