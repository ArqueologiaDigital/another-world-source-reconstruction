# INTRO polygon-naming probes

Two small tools used to name `CINEMATIC_*` polygons from evidence rather than
from their index. Both read the committed `src/levels/<port>/<LEVEL>.asm` tree;
neither needs the original game data.

## `crossport_slots.py` — what is this polygon, according to the other ports?

**Question it answers:** does port A's routine draw the same polygons, in the
same slots, at the same `x,y` as port B's routine — and does either port already
have a semantic name for the polygon sitting in that slot?

```
python3 notes/intro-polygon-probes/crossport_slots.py INTRO DRAW_PARTICLE_LAB_BG_COMPOSITE
python3 notes/intro-polygon-probes/crossport_slots.py INTRO LESTER_HAND_PRESSING_KEYPAD_ANIMATION
```

**Signal being read:** the `video offset=<CONST>, x=, y=` list inside one
routine, printed slot by slot with each port's constant *and* the offset its
`EQU` resolves to.

* A slot where one port prints a semantic name and another prints
  `CINEMATIC_<digits>` is a **naming gap** — the semantic name can be carried
  over, because the same slot of the same routine at the same coordinates is the
  same asset.
* A slot where two ports print *different* semantic names, or where one port's
  semantic name appears at a **different offset** from the other ports', is a
  **mis-assignment**: a name that has landed on the wrong polygon.

Worth knowing before reading the output: in `INTRO` the polygon bank is
offset-identical between amiga and MS-DOS over roughly `0x1800`–`0x3F00` (the
same offset really is the same artwork there), but *not* above `0x4000` — in the
walk-away run `0x42A6`–`0x4366` the amiga bank is the DOS bank shifted by a
uniform `+0x8E`. So treat equal offsets as strong evidence where they occur, and
fall back on slot position plus `x,y` everywhere else.

## `compose_scene.py` — what does the finished scene actually look like?

**Question it answers:** what does a scene look like once *every* `video
offset=…, x=, y=` in a routine is painted, instead of each polygon alone on a
grey field? Several polygons are unreadable in isolation and obvious in place.

```
python3 notes/intro-polygon-probes/compose_scene.py out.svg <svgdir> \
    418C:150:100:#303030 187E:160:111:#c02020
```

Each argument is `OFFSET:X:Y[:COLOR]` taken straight from the `video` line
(`x=65532` and other 16-bit wrap-arounds are handled as negative). `<svgdir>` is
a directory of per-polygon SVGs as emitted by
`awvm-disasm … all_levels amiga` — files named
`amiga_stage1_{group,solid}_0x<OFFSET>.svg`, each authored 320x200 with the
shape centred on (160,100), which is why drawing at `(x,y)` is a
`translate(x-160, y-100)`. Distinct colours per argument let you tell which
polygon contributed which part of the picture.

Regenerating the SVG corpus is cheap, so it is deliberately not committed.
