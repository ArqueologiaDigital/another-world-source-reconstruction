// Does the rasteriser do what the game's rasteriser does?
//
// Question answered
// -----------------
// Nothing in this repository had ever tested the step from polygons to pixels.
// `compare_render.mjs` compares polygon GEOMETRY -- colour, point count,
// coordinates -- against `awvm-render-polygons`, and that tool emits SVG, which
// is not rasterised. So `fillPolygonInto` was unchecked, and the README's claim
// that it differed from the reference "by up to one pixel" was a guess.
//
// `fillPolygonInto` is now a port of MAME's
// `another_world_vm_state::fillPolygon` (felipesanches/mame, branch
// `anotherworld`), which matches Fabien Sanglard's interpreter and the
// original. This holds the three behaviours that port exists for, none of which
// the old even-odd scanline fill had.
//
// What this asserts
// -----------------
//   1. **Solid.** A colour below 0x10 writes that index, and a convex polygon
//      fills its own bounding box and nothing outside it.
//   2. **Blend (colour exactly 0x10).** Each covered pixel becomes
//      `(what was there & 7) | 8` -- the game's transparency. Checked against a
//      page pre-filled with a known pattern, so a solid write would be visible
//      as such.
//   3. **Copy from page 0 (colour above 0x10).** Each covered pixel takes page
//      0's value at the same address. This is how a cut-out shows the backdrop
//      through, and getting it wrong paints a mask as a block:
//      `CINEMATIC_222` in CAVES, the constant with the most screen time in the
//      stage, is colour 0x11 and was being drawn as a solid 50x40 rectangle.
//   4. **The degenerate point.** A four-point polygon with zero width and one
//      row of height is ONE pixel, which is what the game does; the Rust tool
//      bumps it into a lozenge for SVG visibility and `polygons.js` keeps both.
//   5. **The override.** A forced colour -- what the blink overlay uses -- is
//      always solid, so highlighting an asset shows its whole footprint even
//      when the asset itself is a mask.
//
// Run it
//   node tools/vm-debugger/tests/check_fill.mjs
//   node tools/vm-debugger/tests/check_fill.mjs <an absolute path to a vm.js>
//
// The second form is how a case here is shown to be real rather than asserted,
// the same convention `notes/play-and-describe/tests/run.sh` uses for its `$1`
// and `check_guidance.py` for its argument. Against the rasteriser as of
// `0d09f1e6~1`, four of the five assertions fail -- everything but the solid
// one, which is why nobody noticed for three sessions:
//
//     git show 0d09f1e6~1:tools/vm-debugger/static/vm.js       > /tmp/old/vm.js
//     git show 0d09f1e6~1:tools/vm-debugger/static/polygons.js > /tmp/old/polygons.js
//     node tools/vm-debugger/tests/check_fill.mjs /tmp/old/vm.js

const MOD = process.argv[2]
  || new URL("../static/vm.js", import.meta.url).href;
const { fillPolygonInto, W, H, VM } = await import(MOD);

const bad = [];
const want = (c, why) => { if (!c) bad.push(why); };
const page = () => new Uint8Array(W * H);
const at = (p, x, y) => p[y * W + x];
const count = (p, v) => { let n = 0; for (const q of p) if (q === v) n++; return n; };

// a 10x10 axis-aligned square, given the way the renderer gives them:
// point list walking one side down and the other side up
const square = (x, y, w, h, raw) => ({
  raw, index: raw & 0x0F, degenerate: false,
  points: [[x + w, y], [x + w, y + h], [x, y + h], [x, y]],
});

// 1. solid
{
  const p = page();
  fillPolygonInto(p, square(100, 50, 10, 10, 5));
  want(count(p, 5) > 0, "a solid polygon painted nothing");
  want(at(p, 105, 55) === 5, "the middle of a solid square is not its colour");
  want(at(p, 100 - 3, 55) === 0, "something was painted left of the square");
  want(at(p, 100 + 14, 55) === 0, "something was painted right of the square");
  want(at(p, 105, 50 - 3) === 0, "something was painted above the square");
  want(at(p, 105, 50 + 14) === 0, "something was painted below the square");
}

// 2. blend, colour exactly 0x10
{
  const p = page();
  p.fill(6);                                   // 6 & 7 | 8 == 14
  fillPolygonInto(p, square(100, 50, 10, 10, 0x10));
  want(at(p, 105, 55) === 14,
       `blend wrote ${at(p, 105, 55)}, want (6 & 7) | 8 = 14`);
  want(at(p, 50, 55) === 6, "blend touched a pixel outside the polygon");
  want(count(p, 0x10) === 0, "blend wrote the raw colour somewhere");
}

// 3. copy from page 0, colour above 0x10
{
  const p = page(), p0 = page();
  for (let i = 0; i < p0.length; i++) p0[i] = 3;
  fillPolygonInto(p, square(100, 50, 10, 10, 0x11), undefined, p0);
  want(at(p, 105, 55) === 3, `copy wrote ${at(p, 105, 55)}, want page 0's 3`);
  want(at(p, 50, 55) === 0, "copy touched a pixel outside the polygon");
  const q = page();
  fillPolygonInto(q, square(100, 50, 10, 10, 0x11));   // no page 0 given
  want(count(q, 0) === q.length,
       "with no page 0 a copy-mode polygon should be skipped, not guessed");
}

// 4. the degenerate point
{
  const p = page();
  fillPolygonInto(p, { raw: 7, index: 7, degenerate: true,
                       anchorX: 160, anchorY: 100,
                       points: [[160, 100], [160, 101], [162, 101], [162, 100]] });
  want(count(p, 7) === 1, `a degenerate polygon painted ${count(p, 7)} pixels, want 1`);
  want(at(p, 160, 100) === 7, "the degenerate pixel is not at the anchor");
}

// 5. the override is always solid
{
  const p = page(), p0 = page();
  fillPolygonInto(p, square(100, 50, 10, 10, 0x11), 9, p0);
  want(at(p, 105, 55) === 9,
       "a forced colour on a mask polygon did not paint -- the blink overlay " +
       "would show nothing for exactly the assets hardest to recognise");
  const q = page();
  q.fill(6);
  fillPolygonInto(q, square(100, 50, 10, 10, 0x10), 9);
  want(at(q, 105, 55) === 9, "a forced colour on a blend polygon blended instead");
}

// 6. a scrolled page copy moves a BAND and leaves the rest of the destination
// alone. This is the code path PRISON's lift runs on: PRISON_LIFT_MOVE_STEP does
// `add [SCROLL_Y], 0x0010` or `sub` by the same, and the whole scene going up or
// down IS that offset reaching copyVideoPage -- there is no car that moves.
// Zeroing the uncovered rows, which this did before the MAME port, is a black
// bar sliding across exactly that scene.
{
  const vm = Object.create(VM.prototype);
  vm.pages = [new Uint8Array(W * H), new Uint8Array(W * H)];
  vm.pages[0].fill(7);                       // source: all 7
  vm.pages[1].fill(3);                       // destination: all 3
  vm.copyPage(0, 1, 10);                     // scroll down by 10 rows
  const d = vm.pages[1];
  want(d[10 * W + 5] === 7, "the scrolled band did not arrive");
  want(d[5] === 3,
       `row 5 of the destination is ${d[5]}, want the 3 it already held -- ` +
       `zeroing the uncovered rows is a black bar sliding across the lift`);
  want(d[(H - 1) * W] === 7, "the band is shorter than it should be");

  const wild = Object.create(VM.prototype);
  wild.pages = [new Uint8Array(W * H), new Uint8Array(W * H)];
  wild.pages[0].fill(7);
  wild.pages[1].fill(3);
  wild.copyPage(0, 1, 500);                  // outside -199..199
  want(count(wild.pages[1], 3) === W * H,
       "a scroll beyond +-199 must copy nothing, not something arbitrary");
}

if (bad.length) {
  console.log(`FAIL: ${bad.length} problem(s)`);
  for (const b of bad) console.log(`  * ${b}`);
  process.exit(1);
}
console.log("PASS: solid fills its box and nothing else; 0x10 blends to " +
            "(n & 7) | 8;\n      above 0x10 copies page 0 and is skipped " +
            "without one; a degenerate\n      polygon is one pixel; a forced " +
            "colour is always solid; and a scrolled\n      page copy moves a " +
            "band without blanking the rest -- which is the lift.");
process.exit(0);
