# CAVES: a crack network spreading, ten frames that accumulate

`LABEL_0885` is set up on channel 0x19 by `LABEL_3273`, which also does
`setPalette 0x05` -- the palette every colour below is read at -- and seeds the
anchor `[0xED],[0xEE]` to 160,100, or to 167,10 on screen 0x4F. It draws ten
pictures, one per `break`, punctuated by five `play` calls at vol 0x40.

## They accumulate

Between the first draw and the last the routine issues **no** `fill`, no
`copyVideoPage` and no `selectVideoPage`. Nothing clears the page, so each
frame is added to what the ones before it left there, and the ten together are
one growing picture rather than ten alternatives.

## Two populations of path, by fill

```
  F0   #202044 x5   #0097fb x1  #fbfbfb x1
  F1   #202044 x5
  F2   #202044 x6   #0097fb x1  #fbfbfb x1
  F3   #202044 x5
  F4   #202044 x6
  F5   #202044 x6   #0097fb x3  #fbfbfb x3   #004497 x3
  F6   #202044 x6   #0097fb x1  #fbfbfb x1   #004497 x1
  F7   #202044 x8
  F8   #202044 x8
  F9   #202044 x7
```

Every frame has five to eight `#202044` paths and nothing else in that colour
changes: rendered, they are thin angular branching slivers, and each frame
puts them somewhere the earlier ones did not.

Four frames -- and only four -- also carry `#0097fb` and `#fbfbfb` in **equal
numbers**: one and one, one and one, three and three, one and one. Rendered,
each pair is a white core inside a bright blue ring, compact, at a place where
several of the dark slivers meet. F5 and F6 add `#004497`, a mid blue, exactly
one per pair.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_213 | CINEMATIC_CAVES_CRACK_SPREAD_F0 | medium | 43.0x72.5, 7 paths: five `#202044` slivers and one `#0097fb`/`#fbfbfb` pair. First of the ten, and the first `play` follows it immediately |
| CINEMATIC_214 | CINEMATIC_CAVES_CRACK_SPREAD_F1 | medium | 43.0x72.5, 5 paths, all `#202044`: slivers only |
| CINEMATIC_215 | CINEMATIC_CAVES_CRACK_SPREAD_F2 | medium | 104.0x72.5, 8 paths -- the extent more than doubles here -- six slivers and one bright pair |
| CINEMATIC_216 | CINEMATIC_CAVES_CRACK_SPREAD_F3 | medium | 103.5x73.0, 5 paths, all `#202044` |
| CINEMATIC_217 | CINEMATIC_CAVES_CRACK_SPREAD_F4 | medium | 100.5x72.5, 6 paths, all `#202044` |
| CINEMATIC_218 | CINEMATIC_CAVES_CRACK_SPREAD_F5 | medium | 92.0x74.5, **15 paths**, the most of the ten: six slivers and **three** bright pairs, each with a `#004497` ring. Preceded by `play id=0x0058` at vol 0x40 |
| CINEMATIC_219 | CINEMATIC_CAVES_CRACK_SPREAD_F6 | medium | 74.5x78.5, 9 paths: six slivers and one bright pair. The tallest of the ten at 78.5 |
| CINEMATIC_220 | CINEMATIC_CAVES_CRACK_SPREAD_F7 | medium | 99.0x73.5, 8 paths, all `#202044`. No bright pair appears again after F6 |
| CINEMATIC_221 | CINEMATIC_CAVES_CRACK_SPREAD_F8 | medium | 99.0x73.0, 8 paths, all `#202044` |
| CINEMATIC_222 | CINEMATIC_CAVES_CRACK_SPREAD_F9 | medium | 100.5x74.0, 7 paths, all `#202044`, and the last drawn |

## What these names do not claim

`CRACK` is thin branching angular slivers that **accumulate** -- nothing
clears the page between the ten -- laid down where the bright pairs were, with
impacts playing through the run. It does not say what is cracking. None of the
ten contains a surface, an edge or a background; they are lines on whatever
the screen already had.

`SPREAD` is the extent: 43.0 wide at F0 and F1, then 104.0 from F2 on. The
index is the routine's own draw order, which for an accumulating picture is
the only order there is.

The bright `#0097fb`/`#fbfbfb` pairs are **not named separately**. They are
paths inside these pictures, not constants of their own.
