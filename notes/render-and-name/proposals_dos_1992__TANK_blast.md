# TANK (msdos): two blast clouds from one earned routine

`TANK_ARENA_ATTACK_BLAST_SEQUENCE` is an **earned name** and it draws thirteen
still-numbered pictures, opening with the same sound on all four channels at
once:

```
	video offset=CINEMATIC_106, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
```

These are **msdos-only art**: of the 41 still-numbered constants in
`dos_1992/TANK.asm`, 35 have no `canonical_md5` match anywhere in
`chahi_amiga_1991/TANK.asm`, so nothing can be carried across and every one of
them needs its own render. `frame_runs.py --stages` also reports "this stage
only".

## The x ranges split the thirteen in two, with a gap of 190 between them

```
  right-hand group   x from  +69.5 to +142.5,  y from  -36.0 to  +20.0
  left-hand group    x from -172.5 to  -47.0,  y from  +14.0 to +105.0
```

No frame of one group comes within 190 pixels of the other. Every one of the
thirteen is **two paths**, and rendered every one is a dark core inside a pale
ring.

The right group grows 33.0 wide to 73.0 and 25.0 tall to 56.0; the left group
grows 67.0 to 122.0 and 33.5 to 90.0. Both start small and end large, and the
routine interleaves them -- `106 107 108 107 109 110 107 111 108 112 113 ...`
-- so the two go off together.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_106 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F0 | medium | 43.0x34.0, 2 paths, x[81.5, 124.5] y[-22.0, 12.0] |
| CINEMATIC_107 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F1 | medium | 38.0x29.0, 2 paths, x[87.0, 125.0] y[-20.5, 8.5] |
| CINEMATIC_108 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F2 | medium | 33.0x34.0, 2 paths, x[89.5, 122.5] y[-22.0, 12.0] |
| CINEMATIC_109 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F3 | medium | 43.0x25.0, 2 paths, x[82.5, 125.5] y[-19.5, 5.5] |
| CINEMATIC_113 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F4 | medium | 54.0x41.0, 2 paths, x[78.0, 132.0] y[-28.5, 12.5] |
| CINEMATIC_115 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F5 | medium | 57.0x49.0, 2 paths, x[77.5, 134.5] y[-33.5, 15.5] |
| CINEMATIC_116 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F6 | medium | 49.0x56.0, 2 paths, x[80.5, 129.5] y[-36.0, 20.0] |
| CINEMATIC_118 | CINEMATIC_TANK_ARENA_BLAST_RIGHT_F7 | medium | 73.0x40.0, 2 paths, x[69.5, 142.5] y[-27.0, 13.0] |
| CINEMATIC_110 | CINEMATIC_TANK_ARENA_BLAST_LEFT_F0 | medium | 67.0x33.5, 2 paths, x[-172.5, -105.5] y[69.0, 102.5] |
| CINEMATIC_111 | CINEMATIC_TANK_ARENA_BLAST_LEFT_F1 | medium | 78.0x46.0, 2 paths, x[-172.0, -94.0] y[57.0, 103.0] |
| CINEMATIC_112 | CINEMATIC_TANK_ARENA_BLAST_LEFT_F2 | medium | 91.0x78.0, 2 paths, x[-169.5, -78.5] y[26.0, 104.0] |
| CINEMATIC_114 | CINEMATIC_TANK_ARENA_BLAST_LEFT_F3 | medium | 86.0x90.0, 2 paths, x[-170.0, -84.0] y[14.0, 104.0] |
| CINEMATIC_117 | CINEMATIC_TANK_ARENA_BLAST_LEFT_F4 | medium | 122.0x62.0, 2 paths, x[-169.0, -47.0] y[43.0, 105.0] |

## What these names do not claim

`BLAST` comes from the routine, which is named
`TANK_ARENA_ATTACK_BLAST_SEQUENCE` and is the only routine that draws any of
the thirteen. What the pictures add is that each is two paths, a dark core in
a pale ring, and that each group grows monotonically.

`RIGHT` and `LEFT` are the x ranges, 190 pixels apart and never overlapping.
They are positions on the screen, not directions anything faces.

The index is order of first appearance within each group; the routine
interleaves and repeats them, so it is not a count of frames drawn.
