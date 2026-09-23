# CAVES: one small object thrown in an arc, fourteen frames

`DRAW_CIN_110_BLOCK` is set up on channel 0x15 by `LABEL_48B4`, in the middle
of a sequence that also draws `CINEMATIC_HERO_DEATH_F0..F2` and hands off to
`DRAW_CIN_98_99_BLOCK`, the blast debris. It draws fourteen pictures, one per
`break`, at `[HERO_X],[HERO_Y]` -- an actor slot, so **#0138** applies and the
names come from the art.

## The arc is in the polygon data, not in the draw calls

Every one of the fourteen is drawn at the same unchanged anchor. What moves is
the shape's own offset **inside** the picture, so the trajectory is a property
of the art and can be measured from it:

```
  F0   4x6  centre ( +3.0, -25.0)      F7   5x5  centre (+27.0, -10.0)
  F1   5x5  centre ( +4.0, -22.0)      F8   4x6  centre (+29.0,  -1.0)
  F2   4x6  centre ( +5.0, -18.0)      F9   5x5  centre (+32.0,  -5.0)
  F3   5x5  centre ( +9.0, -21.0)      F10  4x6  centre (+36.0,  -2.0)
  F4   4x6  centre (+15.0, -23.0)      F11  5x5  centre (+37.0,  -1.0)
  F5   5x5  centre (+19.0, -22.0)      F12  4x5  centre (+37.0,  -1.0)
  F6   4x6  centre (+24.0, -17.0)      F13  5x5  centre (+36.0,  -1.0)
```

x rises from +3.0 to +37.0 and stops. y falls to -18.0, climbs back to -23.0,
then drops to -1.0 and stays there for the last four frames. -1.0 is the
ground: it is where every standing figure in this stage has its bottom edge.

So: out, up, over, down, and then it does not move again. The routine draws
F12 three times at the end, which is what a thing that has stopped looks like.

**The aspect alternates.** 4x6, 5x5, 4x6, 5x5, ... for eleven frames without
exception. A single path that is taller than it is wide on every odd frame and
wider than tall on every even one is one object turning over.

## No stage word

`canonical_md5` matches all fourteen in **PRISON** (`CINEMATIC_284..297`) and
**CAPSULE** (`CINEMATIC_246..259`), both priority ports, all still numbered.
Three stages, so `../crossstage-transfer/README.md`'s condition is met before
the name is written rather than after: this is not CAVES art and does not take
a `CAVES_`.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_110 | CINEMATIC_TUMBLING_CHUNK_F0 | high | 4.0x6.0, one path, centred at (+3.0, -25.0) relative to the anchor |
| CINEMATIC_111 | CINEMATIC_TUMBLING_CHUNK_F1 | high | 5.0x5.0, one path, centred at (+4.0, -22.0) relative to the anchor |
| CINEMATIC_112 | CINEMATIC_TUMBLING_CHUNK_F2 | high | 4.0x6.0, one path, centred at (+5.0, -18.0) relative to the anchor |
| CINEMATIC_113 | CINEMATIC_TUMBLING_CHUNK_F3 | high | 5.0x5.0, one path, centred at (+9.0, -21.0) relative to the anchor |
| CINEMATIC_114 | CINEMATIC_TUMBLING_CHUNK_F4 | high | 4.0x6.0, one path, centred at (+15.0, -23.0) relative to the anchor |
| CINEMATIC_115 | CINEMATIC_TUMBLING_CHUNK_F5 | high | 5.0x5.0, one path, centred at (+19.0, -22.0) relative to the anchor |
| CINEMATIC_116 | CINEMATIC_TUMBLING_CHUNK_F6 | high | 4.0x6.0, one path, centred at (+24.0, -17.0) relative to the anchor |
| CINEMATIC_117 | CINEMATIC_TUMBLING_CHUNK_F7 | high | 5.0x5.0, one path, centred at (+27.0, -10.0) relative to the anchor |
| CINEMATIC_118 | CINEMATIC_TUMBLING_CHUNK_F8 | high | 4.0x6.0, one path, centred at (+29.0, -1.0) relative to the anchor |
| CINEMATIC_119 | CINEMATIC_TUMBLING_CHUNK_F9 | high | 5.0x5.0, one path, centred at (+32.0, -5.0) relative to the anchor |
| CINEMATIC_120 | CINEMATIC_TUMBLING_CHUNK_F10 | high | 4.0x6.0, one path, centred at (+36.0, -2.0) relative to the anchor |
| CINEMATIC_121 | CINEMATIC_TUMBLING_CHUNK_F11 | high | 5.0x5.0, one path, centred at (+37.0, -1.0) relative to the anchor |
| CINEMATIC_122 | CINEMATIC_TUMBLING_CHUNK_F12 | high | 4.0x5.0, one path, centred at (+37.0, -1.0) relative to the anchor |
| CINEMATIC_123 | CINEMATIC_TUMBLING_CHUNK_F13 | high | 5.0x5.0, one path, centred at (+36.0, -1.0) relative to the anchor |

## What these names do not claim

`CHUNK` is a single path four to six pixels across. It says the thing is one
small solid piece rather than a cloud -- which is what separates it from
`CINEMATIC_FALLING_DEBRIS` and `CINEMATIC_BLAST_DEBRIS`, both of which are
tens of paths and are drawn in this same death sequence. It does not say what
it is a chunk of.

The sequence runs on its own channel alongside the hero's death frames, and
nothing here names it from that. At four pixels wide there is no silhouette to
read; the claim is the trajectory, which is measured.
