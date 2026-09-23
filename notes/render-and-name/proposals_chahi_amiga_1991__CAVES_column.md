# CAVES: two masses growing upward, with splinters that come and go

Both runs draw at `160,100`, both read at palette 0x05.

## `LABEL_3535`, 800 to 805: drawn beside the twin columns

The routine's **first instruction** is
`setup channel=0x06, address=CAVES_TWIN_COLUMN_RISE_INIT` -- an earned name --
so these six play alongside that already-named rise, on the screen it happens
on.

```
        extent        paths   fills
  800   30.0x18.0      3      one each of #004497, #0064cb, #000097
  801   25.0x94.0     15      6 + 3 + 3, and three #fbfbfb
  802   74.5x75.0     16      8 + 7, and one #202044
  803  101.5x72.0     12      6 + 5, one #202044
  804   91.0x63.0      4      two #004497, one #202044, one #0064cb
  805   91.0x63.0      4      the same four
```

Height goes 18 to 94 and back to 63 while width goes 30 to 101.5 and settles
at 91. The path count peaks at 16 in the middle and falls to **4**, and the
three `#fbfbfb` paths appear in exactly one frame. Rendered: a small slab, then
a spray of bright splinters, then a dark mass with splinters around it, then
the splinters gone and a smooth mound left.

## `LABEL_C6AE`, 572 to 578: the same shape of event, larger

Reached by `jg [HERO_X], 0x8C`, so it fires on the hero's position.

```
  572   30.0x  7.0   2 paths
  573   46.0x111.0   8 paths
  574   57.0x154.0  19 paths
  575   76.0x169.5  21 paths
  576   76.0x170.0  17 paths
  577  109.0x171.0  14 paths
  578  123.0x171.0  13 paths
```

Height 7.0 to 171.0 and then **fixed** for the last four frames while width
goes on to 123.0; the path count peaks at 21 and falls to 13, and the two dark
fills `#304464` and `#203054` are present once each in **every** frame -- a
base that never changes while everything above it does.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_800 | CINEMATIC_CAVES_GROUND_BREACH_F0 | medium | 30.0x18.0, 3 paths, one of each blue: the smallest, before anything rises |
| CINEMATIC_801 | CINEMATIC_CAVES_GROUND_BREACH_F1 | medium | 25.0x94.0, 15 paths, and the **only frame with `#fbfbfb`** -- three of them. Height jumps 76 in one step |
| CINEMATIC_802 | CINEMATIC_CAVES_GROUND_BREACH_F2 | medium | 74.5x75.0, **16 paths**, the most: a dark mass with splinters all around it |
| CINEMATIC_803 | CINEMATIC_CAVES_GROUND_BREACH_F3 | medium | 101.5x72.0, 12 paths, the widest: splinters leaving |
| CINEMATIC_804 | CINEMATIC_CAVES_GROUND_BREACH_F4 | medium | 91.0x63.0, **4 paths**: the splinters are gone and a smooth mound is left |
| CINEMATIC_805 | CINEMATIC_CAVES_GROUND_BREACH_F5 | medium | 91.0x63.0, 4 paths, the same extent as F4 to the pixel and a distinct `canonical_md5`, so the mound changes inside its own outline. Drawn last and then F4 again |
| CINEMATIC_572 | CINEMATIC_CAVES_COLUMN_EMERGE_F0 | medium | 30.0x7.0, 2 paths -- `#304464` and `#203054`, the two fills every later frame also carries exactly once |
| CINEMATIC_573 | CINEMATIC_CAVES_COLUMN_EMERGE_F1 | medium | 46.0x111.0, 8 paths: 104 taller in one step, with four `#004497` splinters appearing |
| CINEMATIC_574 | CINEMATIC_CAVES_COLUMN_EMERGE_F2 | medium | 57.0x154.0, 19 paths |
| CINEMATIC_575 | CINEMATIC_CAVES_COLUMN_EMERGE_F3 | medium | 76.0x169.5, **21 paths**, the most of the seven |
| CINEMATIC_576 | CINEMATIC_CAVES_COLUMN_EMERGE_F4 | medium | 76.0x170.0, 17 paths: the same width as F3 and four splinters fewer |
| CINEMATIC_577 | CINEMATIC_CAVES_COLUMN_EMERGE_F5 | medium | 109.0x171.0, 14 paths: height has stopped, width has not |
| CINEMATIC_578 | CINEMATIC_CAVES_COLUMN_EMERGE_F6 | medium | 123.0x171.0, 13 paths, the widest |

## What these names do not claim

`GROUND_BREACH` and `COLUMN_EMERGE` are the height rising and stopping, the
width going on, and a splinter count that peaks in the middle and falls away.
Neither says what the mass is made of, and neither claims the two runs are the
same event: they are in different routines, reached by different conditions,
and their `canonical_md5`s share nothing.

`CINEMATIC_806`, drawn twice by `LABEL_3535` at 169,136 and 169,160 after the
six, is **left numbered**.
