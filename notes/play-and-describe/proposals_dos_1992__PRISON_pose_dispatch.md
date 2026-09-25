# PRISON: the last six of the left-facing pose dispatcher

Three annotations open this, and the dispatcher closes it:

- `ann:e6e210434666` on `CINEMATIC_231` (f2158): "head of the guard, maybe
  starting to look up..."
- `ann:1537f4f21492` on `CINEMATIC_228` (f2159): "head of the guard tilting up
  to call the attention of prisoners lester and buddy when they start shaking
  their hanging cell"
- `ann:73696220db3d` on `CINEMATIC_227` (f2171): "head of the guard looking up
  and speaking to lester and buddy"

## The index is not a choice

`DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E` (PRISON.asm:9360) is a complete
two-level switch, and nine of its fifteen leaves are already named
`CINEMATIC_PRISON_FIGURE_POSE_LEFT_<a>_<b>`. Reading the dispatcher gives what
`<a>` and `<b>` are:

    mov [0xF8], [0x09]
    shr [0xF8], 0x0004          <- <b> is [0x09] >> 4
    jne [0x0E], 0x00, ...       <- <a> is [0x0E]

| `[0x0E]` | `[0x09]>>4` | constant | |
| --- | --- | --- | --- |
| 0 | 0,1,2,3 | `..._0_0` `_0_1` `_0_2` `_0_3` | named |
| 1 | 1 | `..._1_1` | named |
| 1 | else | **CINEMATIC_235** | |
| 2 | 1 | `..._2_1` | named |
| 2 | else | **CINEMATIC_233** | |
| 3 | any | **CINEMATIC_231** | no variant test |
| 4 | 1 | `..._4_1` | named |
| 4 | else | **CINEMATIC_230** | |
| 5 | any | **CINEMATIC_228** | no variant test |
| 6 | any | **CINEMATIC_227** | no variant test |
| 7 | 0 | `..._7_0` | named |
| 7 | 1 | `..._7_1` | named |

So every index below is read off a `je` or a `jne`, not chosen. `_OTHER` is the
fall-through of a `je <n>` and `_ANY` is a case with no variant test at all;
both state the dispatch rather than inventing a number for it.

## The pairs measure as the same pose twice

Each `else` constant matches its `_1` sibling exactly on size and leaf count:

    _1_1  11.0 x 10.0  3 leaves      CINEMATIC_235  11.0 x 10.0  3 leaves
    _2_1  10.0 x 10.0  2 leaves      CINEMATIC_233  10.0 x 10.0  2 leaves
    _4_1  13.0 x 10.0  4 leaves      CINEMATIC_230  13.0 x 10.0  4 leaves

One pose, two appearance variants -- which is what a switch on an actor-record
field should produce, and it is measured rather than assumed.

## A note on the stem, which is inherited and imprecise

All fifteen occupy y[-60,-48] on a figure whose body,
`CV_FIGURE_WALK_LEFT_BODY_F00`, is 34x57 at y[-56,+1] at the same anchor, and
the dispatcher is called one line *before* that body draw (PRISON.asm:9755-9756).
These are **heads**, 10-13 wide against a body's 34, and the person annotating
called all three of them heads.

The rows below keep `POSE_LEFT` anyway: nine committed siblings already use it,
and splitting a fifteen-member family across two stems to fix a word is worse
than the word. Renaming all fifteen to `HEAD_LEFT` is a separate change with its
own table, noted here so the next person does not have to rediscover it.

No actor word is taken. The person says guard three times and
`../actor-anchors/` records why that is not admissible from this anchor.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_235 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_OTHER | high | 0x42B0, the `jmp DRAW_CIN_235` fall-through of `je [0xF8], 0x01` in PRISON_BUDDY_POSE_DISPATCH_CASE_01 (PRISON.asm:9373-9375); 11.0x10.0 in 3 leaves at y[-59,-49], identical in size and leaf count to its `_1_1` sibling at 0xD0AC -- one pose, two variants |
| CINEMATIC_233 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_OTHER | high | 0x42EC, the fall-through of the same test in PRISON_BUDDY_POSE_DISPATCH_CASE_02 (9377-9380); 10.0x10.0 in 2 leaves at y[-59,-49], matching `_2_1` at 0xD0E8 exactly on both |
| CINEMATIC_231 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_3_ANY | high | 0x4304, case 3 at LABEL_5166 (9382-9384) which has NO `[0xF8]` test, so one picture serves every variant -- hence `_ANY` rather than an invented index; 12.0x10.0 in 4 leaves at y[-59,-49]; annot:e6e210434666 frame 2158, "head of the guard, maybe starting to look up" |
| CINEMATIC_230 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_OTHER | high | 0x4338, the fall-through in PRISON_BUDDY_POSE_DISPATCH_CASE_04 (9386-9389); 13.0x10.0 in 4 leaves at y[-59,-49], matching `_4_1` at 0xD114 exactly |
| CINEMATIC_228 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_5_ANY | high | 0x531E, case 5 at LABEL_517E (9391-9393), no variant test; 11.0x12.0 in 4 leaves at y[-60,-48] -- taller than cases 1-4, which is the head tilted; annot:1537f4f21492 frame 2159, "head of the guard tilting up to call the attention of prisoners lester and buddy" |
| CINEMATIC_227 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_6_ANY | high | 0x53E0, case 6, drawn inline in PRISON_BUDDY_POSE_DISPATCH_CASE_06 (9395-9397), no variant test; 11.0x12.0 in 6 leaves at y[-60,-48] -- the same box as case 5 with two more leaves, the extra detail of an open mouth against a closed one; annot:73696220db3d frame 2171, "head of the guard looking up and speaking to lester and buddy" |
