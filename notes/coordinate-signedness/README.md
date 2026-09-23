# `video` coordinates are signed, and the listing does not say so

## The problem

`CINEMATIC_112` in amiga/INTRO is drawn five times at
`y = 65527, 65530, 65529, 65531, 65534`. Where is it?

The toolchain is self-consistent and gives one answer:
`AnotherWorld_VMTools/awvm/src/disasm.rs:686-692` reads the two operand bytes
into a `u32` and formats that decimal -- which is why the listing says 65527 --
and `awvm/src/polygons.rs:180` parses the string straight back and renders at
`y = 65527.0`. So awvm places the picture 65,327 lines below a 200-line page.

An engine keeping polygon coordinates in `int16_t` gives the other answer: the
same bytes are **-9**, and the picture sits just above the top edge, entering
the frame.

Opposite places, same bytes, and the difference decides whether a name may
mention a position at all.

## The bytecode settles it without an engine

If the operands were unsigned, values above 0x8000 would be scattered through
that 32,768-wide range like any other intended coordinate. If they are signed,
they must all cluster just below 0x10000, because a coordinate slightly off the
edge of a 320x200 page is a small negative number and nothing else.

`signed_coordinates.py` collects every literal `video` x and y in every
branch's `.asm` and looks:

```
$ python3 notes/coordinate-signedness/signed_coordinates.py
  14668 literal y operand(s) across every branch .asm
  75 are >= 0x8000, in 17 distinct value(s)
  range above 0x8000: 65456..65535  =  -80..-1 signed
  that is 80 wide inside a 32768-wide space
  ordinary range below 0x8000: 0..400

$ python3 notes/coordinate-signedness/signed_coordinates.py --axis x
  129 are >= 0x8000
  range above 0x8000: 65374..65535  =  -162..-1 signed
  that is 162 wide inside a 32768-wide space
  ordinary range below 0x8000: 0..576
```

**Eighty distinct pixels of range used out of 32,768 available, and none
outside it, on both axes.** Unsigned, the game would be placing 75 draws
between 65,456 and 65,535 lines below the screen and nowhere else in between.
Signed, y runs -80..400 and x runs -162..576 -- one contiguous band around a
320x200 page with margins on each side, which is what a scene that pans and
lets art run off the edges looks like.

So the operands are signed. A listing printing `y=65527` is printing **-9**.

## What this changes

- A picture drawn at `y=65527` is **on screen**, or entering it, not discarded.
  `CINEMATIC_112` steps -9, -6, -7, -5, -2 across five hold-loops: a mark
  coming in over the top edge, not one thrown away below the page.
- `awvm-render-polygons` renders such a draw in the wrong place. It does not
  affect any measurement in `notes/` that used the renderer, because those
  render each polygon at its own default anchor and never pass a draw's x or y
  -- but anything that does pass them has to convert first.
- Reading a listing, `65535` is `-1`. There are 204 such operands in the tree.

## Run it

```
python3 notes/coordinate-signedness/signed_coordinates.py
python3 notes/coordinate-signedness/signed_coordinates.py --axis x
python3 notes/coordinate-signedness/signed_coordinates.py --sites
```

Reads only `src/levels/<branch>/*.asm`; no romset, no renderer.
