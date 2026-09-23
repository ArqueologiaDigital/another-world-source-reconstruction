// Another World polygon renderer — a port of AnotherWorld_VMTools/awvm/src/polygons.rs.
//
// Kept deliberately line-for-line with the Rust so the two can be diffed by eye
// as well as by `tests/compare_render.mjs`, which checks every polygon of every
// entry in a stage against the SVGs `awvm-render-polygons` writes. The notes
// this project keeps are full of measurements taken from that renderer; a
// debugger that drew even slightly different shapes would quietly invalidate
// them.
//
// Two details that are easy to get wrong and are load-bearing:
//
//  * `fetchPolygonData` indexes `(level << 16) | offset` into ONE flat
//    cinematic.rom of nine 64 KiB slabs. The offset is not masked, so a walk
//    that runs off the end of a slab reads into the next one -- which is what
//    the real VM does too.
//  * A group header's two size bytes are a PIVOT the engine subtracts whole,
//    while a solid header's two are a bounding box that is HALVED. Halving both
//    shifts every group child by half the pivot; `notes/polygon-extent-correction/`
//    is the pass that found that, and this port keeps the corrected rule.

export const DEFAULT_ZOOM = 0x40;
export const MAX_POINTS = 50;
export const COLOR_BLACK = 0xFF;   // "no colour of my own; take the parent's"

export class PolygonRenderer {
  /**
   * @param {Uint8Array} cinematic  the whole cinematic.rom (9 x 64 KiB)
   * @param {Uint8Array} palettes   the whole palettes.rom  (9 x 2 KiB)
   */
  constructor(cinematic, palettes) {
    this.data = cinematic;
    this.palettes = palettes;
    this.level = 0;
    this.off = 0;
  }

  setLevel(level) { this.level = level | 0; }

  fetch() {
    const idx = ((this.level << 16) | this.off) >>> 0;
    const v = this.data[idx];
    if (v === undefined) {
      throw new RangeError(
        `polygon data out of bounds: level ${this.level} offset ` +
        `0x${this.off.toString(16)} needs byte ${idx} of a ${this.data.length}` +
        `-byte polygon ROM (${Math.floor(this.data.length / 0x10000)} slabs)`);
    }
    this.off = (this.off + 1) >>> 0;
    return v;
  }

  /** @returns {[number,number,number]} r,g,b each 0..1 */
  colorOf(paletteNumber, color) {
    const p = ((this.level << 11) | (32 * paletteNumber + 2 * (color % 16))) >>> 0;
    const c1 = this.palettes[p], c2 = this.palettes[p + 1];
    const r = ((c1 & 0x0F) << 2) | ((c1 & 0x0F) >> 2);
    const g = ((c2 & 0xF0) >> 2) | ((c2 & 0xF0) >> 6);
    const b = ((c2 & 0x0F) >> 2) | ((c2 & 0x0F) << 2);
    return [r / 64, g / 64, b / 64];
  }

  /**
   * Draw one entry. Returns a flat list of filled polygons:
   *   { color: [r,g,b], points: [[x,y], ...] }
   * in the order the engine paints them, which is the order they must be
   * composited in.
   */
  draw(address, paletteNumber, zoom, x, y) {
    const out = [];
    this.readAndDraw(address, paletteNumber, COLOR_BLACK, zoom, x, y, out);
    return out;
  }

  readAndDraw(address, palette, color, zoom, x, y, out) {
    this.off = address >>> 0;
    const value = this.fetch();
    if (value >= 0xC0) {
      const effective = (color & 0x80) !== 0 ? (value & 0x3F) : color;
      const backup = this.off;
      this.fillPolygon(palette, effective, zoom, x, y, out);
      this.off = backup;
    } else if ((value & 0x3F) === 2) {
      this.readAndDrawHierarchy(palette, zoom, x, y, out);
    }
    // Anything else is the reference VM's error case; a library skips it.
  }

  fillPolygon(palette, color, zoom, cx, cy, out) {
    const rgb = this.colorOf(palette, color);
    const bboxW = this.fetch() * zoom / DEFAULT_ZOOM;
    const bboxH = this.fetch() * zoom / DEFAULT_ZOOM;
    const n = this.fetch();
    if ((n & 1) !== 0 || n === 0 || n >= MAX_POINTS) return;

    const px = new Array(n), py = new Array(n);
    for (let i = 0; i < n; i++) {
      const dx = this.fetch() * zoom / DEFAULT_ZOOM;
      const dy = this.fetch() * zoom / DEFAULT_ZOOM;
      px[i] = cx - bboxW / 2 + dx;
      py[i] = cy - bboxH / 2 + dy;
    }
    // A four-point polygon that is really a line gets bumped to a two-pixel
    // lozenge so it is visible. The reference does this; `polygon_extent.py`
    // documents that it is why the renderer reports thin art wider than the
    // polygon extent does.
    if (n === 4 && px[0] === px[3] && px[1] === px[2]
                && py[0] === py[3] && py[1] === py[2]) {
      px[2] += 2; px[3] += 2;
    }
    const points = new Array(n);
    for (let i = 0; i < n; i++) points[i] = [px[i], py[i]];
    out.push({ color: rgb, points });
  }

  readAndDrawHierarchy(palette, zoom, pgcX, pgcY, out) {
    const ptX = pgcX - this.fetch() * zoom / DEFAULT_ZOOM;
    const ptY = pgcY - this.fetch() * zoom / DEFAULT_ZOOM;
    const children = this.fetch() + 1;
    for (let i = 0; i < children; i++) {
      const offHi = this.fetch(), offLo = this.fetch();
      const offset = (offHi << 8) | offLo;
      const poX = ptX + this.fetch() * zoom / DEFAULT_ZOOM;
      const poY = ptY + this.fetch() * zoom / DEFAULT_ZOOM;
      let color = 0xFF;
      if ((offset & 0x8000) !== 0) {
        color = this.fetch() & 0x7F;
        this.fetch();                     // waste a byte, as the reference does
      }
      const backup = this.off;
      this.readAndDraw((offset & 0x7FFF) * 2, palette, color, zoom, poX, poY, out);
      this.off = backup;
    }
  }
}

/** `#rrggbb` for a polygon's colour, rounded exactly as the SVG writer does. */
export function hexOf(rgb) {
  const b = (v) => Math.min(255, Math.max(0, Math.round(v * 255)));
  return "#" + [b(rgb[0]), b(rgb[1]), b(rgb[2])]
    .map((v) => v.toString(16).padStart(2, "0")).join("");
}

/** Axis-aligned bounds of a draw's polygons, or null when it drew nothing. */
export function boundsOf(polys) {
  let x0 = Infinity, y0 = Infinity, x1 = -Infinity, y1 = -Infinity;
  for (const p of polys) for (const [x, y] of p.points) {
    if (x < x0) x0 = x; if (x > x1) x1 = x;
    if (y < y0) y0 = y; if (y > y1) y1 = y;
  }
  return x0 === Infinity ? null : { x0, y0, x1, y1 };
}
