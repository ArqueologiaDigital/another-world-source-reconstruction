// The debugger's wiring: canvas, panels, selection, annotation, rename.
//
// Everything here is presentation over two things that are checked elsewhere --
// `vm.js`, whose draw offsets are verified against the disassembler, and
// `polygons.js`, whose geometry is verified against `awvm-render-polygons`.
// Nothing in this file is allowed to be the only place a fact lives.

import { VM, W, H, fillPolygonInto } from "./vm.js";

const $ = (id) => document.getElementById(id);
const hex4 = (v) => "0x" + v.toString(16).toUpperCase().padStart(4, "0");

// A name is a NAME only if it is not one of the two generated forms: a
// `CINEMATIC_<index>` from the stage's own bank or a `CV_<hex offset>` from the
// shared one. `notes/shared-bank-naming/asset_naming_share.py` counts the same
// two shapes, so the badge here and the percentage in the notes agree.
const RE_NUMBERED = /^CINEMATIC_\d+$|^CV_[0-9A-F]{4}$/;
const isNamed = (n) => !!n && !RE_NUMBERED.test(n);

const state = {
  cfg: null, branch: null, stage: null, meta: null,
  vm: null, roms: {}, frame: null, sel: null,
  running: false, timer: null, blink: 0,
};

// ---- boot -------------------------------------------------------------
const cfg = await (await fetch("/api/config")).json();
state.cfg = cfg;
for (const b of Object.keys(cfg.branches)) {
  $("branch").append(new Option(b, b));
}
for (const s of Object.keys(cfg.stages)) $("stage").append(new Option(s, s));
$("branch").value = "chahi_amiga_1991" in cfg.branches
  ? "chahi_amiga_1991" : Object.keys(cfg.branches)[0];
$("stage").value = "INTRO";

async function loadRoms(port) {
  const get = async (n) => {
    const r = await fetch(`/api/rom/${port}/${n}`);
    return r.ok ? new Uint8Array(await r.arrayBuffer()) : null;
  };
  return {
    bytecode: await get("bytecode.rom"),
    cinematic: await get("cinematic.rom"),
    palettes: await get("palettes.rom"),
    video2: await get("video2.rom"),
  };
}

async function loadStage() {
  pause();
  state.branch = $("branch").value;
  state.stage = $("stage").value;
  const port = state.cfg.branches[state.branch];
  $("hint").textContent = `loading ${state.branch}/${state.stage}…`;
  state.meta = await (await fetch(
    `/api/names/${state.branch}/${state.stage}`)).json();
  if (!state.roms[port]) state.roms[port] = await loadRoms(port);
  const roms = state.roms[port];
  if (!roms.palettes) {
    $("hint").textContent =
      `${port} has no palettes.rom — only ports with one can be displayed. ` +
      `(Run \`make extract\` for it in the archaeology repo.)`;
    return;
  }
  state.vm = new VM(roms);
  // Seeded by default: without it four of the eight stages delete all 64
  // threads on entry and draw nothing at all. See VM.PROTECTION_PASS.
  state.vm.setupPart(state.cfg.stages[state.stage],
                     { protection: !$("coldboot").checked });
  state.sel = null;
  state.frame = state.vm.runFrame();
  $("hint").textContent =
    `${Object.keys(state.meta.cinematic).length} cinematic and ` +
    `${Object.keys(state.meta.video2).length} shared-bank constants known here. ` +
    `Press run.`;
  draw();
}

// ---- names ------------------------------------------------------------
function nameOf(d) {
  const tbl = d.kind === "video2" ? state.meta.video2 : state.meta.cinematic;
  return tbl[hex4(d.offset)] || null;
}
/** The routine a pc sits in: the nearest label at or before it. */
function routineAt(pc) {
  const labels = state.meta.labels || {};
  let best = null, bestAt = -1;
  for (const [name, addr] of Object.entries(labels)) {
    if (addr <= pc && addr > bestAt) { bestAt = addr; best = name; }
  }
  return best;
}
/** Every draw in the frame issued from the same routine as `d`. */
function siblingsOf(d) {
  const r = routineAt(d.pc);
  return state.frame.draws
    .filter((o) => routineAt(o.pc) === r)
    .map((o) => ({ kind: o.kind, offset: o.offset, name: nameOf(o) }));
}

// ---- rendering --------------------------------------------------------
const screen = $("screen").getContext("2d", { willReadFrequently: true });
const overlay = $("overlay").getContext("2d");
const img = screen.createImageData(W, H);

function draw() {
  const vm = state.vm;
  if (!vm) return;
  const page = vm.pages[vm.frontPage];
  const pal = [];
  for (let i = 0; i < 16; i++) {
    const [r, g, b] = vm.cine.colorOf(vm.palette, i);
    pal.push([Math.round(r * 255), Math.round(g * 255), Math.round(b * 255)]);
  }
  for (let i = 0; i < W * H; i++) {
    const c = pal[page[i] & 15];
    img.data[i * 4] = c[0]; img.data[i * 4 + 1] = c[1];
    img.data[i * 4 + 2] = c[2]; img.data[i * 4 + 3] = 255;
  }
  screen.putImageData(img, 0, 0);
  paintOverlay();
  paintPanels();
}

/**
 * The selected constant's area, alternating. Re-filling the draw's own polygons
 * is exact -- no mask bitmap, no bounding box -- because `vm.js` kept the point
 * lists the renderer produced for that very draw.
 */
function paintOverlay() {
  overlay.clearRect(0, 0, W, H);
  if (!state.sel) return;
  const d = state.frame.draws.find((x) => x.seq === state.sel);
  if (!d) return;
  const on = (state.blink & 1) === 0;
  overlay.globalAlpha = on ? 0.75 : 0.25;
  overlay.fillStyle = isNamed(nameOf(d)) ? "#58a6ff" : "#ff7b72";
  for (const p of d.polys) {
    overlay.beginPath();
    p.points.forEach(([x, y], i) => i ? overlay.lineTo(x, y) : overlay.moveTo(x, y));
    overlay.closePath(); overlay.fill();
  }
  overlay.globalAlpha = 1;
}
setInterval(() => { state.blink++; paintOverlay(); }, 320);

// ---- panels -----------------------------------------------------------
function paintPanels() {
  const f = state.frame;
  $("frame").textContent = `frame ${f.frame}`;

  const seen = new Map();
  for (const d of f.draws) {
    const k = d.kind + d.offset;
    if (!seen.has(k)) seen.set(k, { d, n: 0 });
    seen.get(k).n++;
  }
  const unnamed = [...seen.values()].filter(({ d }) => !isNamed(nameOf(d)));
  $("drawcount").textContent = `${seen.size} distinct, ${f.draws.length} draw(s)`;
  const badge = $("unnamed");
  badge.textContent = `${unnamed.length} unnamed`;
  badge.classList.toggle("clean", unnamed.length === 0);

  const ul = $("draws"); ul.textContent = "";
  for (const { d, n } of seen.values()) {
    const name = nameOf(d);
    const li = document.createElement("li");
    li.className = state.sel === d.seq ? "sel" : "";
    li.innerHTML =
      `<span class="nm ${isNamed(name) ? "ok" : "un"}">${name || hex4(d.offset)}</span>` +
      `<span class="off">${d.kind === "video2" ? "CV " : ""}${hex4(d.offset)}` +
      `${n > 1 ? " ×" + n : ""} t${d.thread}</span>`;
    li.onclick = () => select(d.seq);
    ul.append(li);
  }

  const tl = $("threads"); tl.textContent = "";
  for (let i = 0; i < 64; i++) {
    const pc = state.vm.pc[i];
    if (pc === 0xFFFF) continue;
    const li = document.createElement("li");
    li.className = state.vm.frozen[i] ? "frozen" : "";
    li.innerHTML = `<span class="pc">t${String(i).padStart(2, "0")} ${hex4(pc)}</span>` +
                   `<span class="rt">${routineAt(pc) || "—"}</span>`;
    tl.append(li);
  }

  const vl = $("vars"); vl.textContent = "";
  const named = Object.entries(state.meta.vars || {})
    .sort((a, b) => Number(a[0]) - Number(b[0]));
  for (const [num, nm] of named) {
    const li = document.createElement("li");
    const inp = document.createElement("input");
    inp.value = state.vm.vars[Number(num)];
    inp.onchange = () => { state.vm.vars[Number(num)] = Number(inp.value) | 0; };
    li.innerHTML = `<span class="n">${nm}</span>`;
    li.append(inp);
    vl.append(li);
  }

  const el = $("events"); el.textContent = "";
  for (const e of f.events.slice(-14)) {
    const li = document.createElement("li");
    li.textContent = JSON.stringify(e);
    el.append(li);
  }
}

function select(seq) {
  state.sel = seq;
  const d = state.frame.draws.find((x) => x.seq === seq);
  const name = d ? nameOf(d) : null;
  $("annotarget").textContent = d
    ? `${name || hex4(d.offset)} — ${hex4(d.offset)}, drawn by ${routineAt(d.pc) || "?"}`
    : "nothing selected";
  $("annosave").disabled = !d;
  $("rn-save").disabled = !d;
  if (d && !$("rn-to").value) $("rn-to").placeholder = name || "CINEMATIC_...";
  paintPanels(); paintOverlay();
}

// ---- running ----------------------------------------------------------
function tick() {
  const vm = state.vm;
  if (!vm) return;
  state.frame = vm.runFrame();
  if (vm.pendingPart !== undefined) {
    const part = vm.pendingPart; delete vm.pendingPart;
    const stage = Object.keys(state.cfg.stages)
      .find((k) => state.cfg.stages[k] === part);
    if (stage) { $("stage").value = stage; loadStage(); return; }
    vm.setupPart(part);
  }
  draw();
  if ($("autopause").checked) {
    const any = state.frame.draws.some((d) => !isNamed(nameOf(d)));
    if (any) {
      pause();
      const first = state.frame.draws.find((d) => !isNamed(nameOf(d)));
      if (first) select(first.seq);
      $("hint").textContent =
        "paused: this frame draws something with no semantic name.";
    }
  }
  if (vm.halted) { pause(); $("hint").textContent = "halted on an illegal opcode."; }
}
function run() {
  if (state.running) return;
  state.running = true; $("run").textContent = "pause";
  state.timer = setInterval(tick, Math.max(8, 1000 / Number($("speed").value)));
}
function pause() {
  state.running = false; $("run").textContent = "run";
  if (state.timer) clearInterval(state.timer);
  state.timer = null;
}

$("run").onclick = () => (state.running ? pause() : run());
$("step").onclick = () => { pause(); tick(); };
$("reset").onclick = loadStage;
$("branch").onchange = loadStage;
$("stage").onchange = loadStage;
$("speed").oninput = () => { if (state.running) { pause(); run(); } };

// ---- logging ----------------------------------------------------------
async function post(body) {
  const r = await fetch("/api/rename", {
    method: "POST", headers: { "Content-Type": "application/json" },
    body: JSON.stringify(body),
  });
  return r.json();
}
function context() {
  const d = state.frame.draws.find((x) => x.seq === state.sel);
  const onScreen = [];
  const seen = new Set();
  for (const o of state.frame.draws) {
    const k = o.kind + o.offset;
    if (seen.has(k)) continue;
    seen.add(k);
    onScreen.push({ kind: o.kind, offset: o.offset, name: nameOf(o),
                    routine: routineAt(o.pc) });
  }
  return {
    branch: state.branch, stage: state.stage, frame: state.frame.frame,
    target: d && { kind: d.kind, offset: d.offset, name: nameOf(d),
                   thread: d.thread, pc: d.pc, zoom: d.zoom, x: d.x, y: d.y },
    routine: d && routineAt(d.pc),
    routine_draws: d && siblingsOf(d),
    on_screen: onScreen,
  };
}

// Disable the button for the length of the POST. A second click before the
// first reply lands posts the identical payload, and since an entry's id is
// the sha1 of its line, the same line twice is the same id twice -- in an
// append-only file, which makes it unfixable afterwards. The server refuses a
// byte-identical append as well; this is the half that stops the user seeing
// an error they did not cause.
async function whileSaving(id, fn) {
  const b = $(id);
  if (b.disabled) return;
  b.disabled = true;
  try { await fn(); } finally { b.disabled = false; }
}

$("annosave").onclick = () => whileSaving("annosave", async () => {
  const text = $("annotext").value.trim();
  if (!text) return;
  const res = await post({ kind: "annotate", text, ...context() });
  $("annostatus").textContent = res.ok
    ? `saved ${res.at}  ${res.id || ""}` : `error: ${res.error}`;
  if (res.ok) $("annotext").value = "";
});

$("rn-save").onclick = () => whileSaving("rn-save", async () => {
  const d = state.frame.draws.find((x) => x.seq === state.sel);
  const to = $("rn-to").value.trim();
  if (!d || !to) return;
  const res = await post({ kind: "rename", ...context(),
    renames: [{ kind: d.kind, offset: d.offset, from: nameOf(d), to }] });
  $("annostatus").textContent = res.ok
    ? `rename logged ${res.at}  ${res.id || ""}` : `error: ${res.error}`;
  if (res.ok) $("rn-to").value = "";
});

function bulkMatches() {
  const pat = $("bulk-pat").value.trim(), rep = $("bulk-rep").value;
  if (!pat) return [];
  const out = [];
  for (const [kind, tbl] of [["cinematic", state.meta.cinematic],
                             ["video2", state.meta.video2]]) {
    for (const [off, nm] of Object.entries(tbl)) {
      if (nm.includes(pat)) {
        out.push({ kind, offset: parseInt(off, 16), from: nm,
                   to: nm.split(pat).join(rep) });
      }
    }
  }
  return out;
}
$("bulk-prev").onclick = () => {
  const rows = bulkMatches();
  const ul = $("bulk-list"); ul.textContent = "";
  for (const r of rows.slice(0, 200)) {
    const li = document.createElement("li");
    li.textContent = `${r.from} → ${r.to}`;
    ul.append(li);
  }
  $("bulk-save").disabled = rows.length === 0;
  $("annostatus").textContent = `${rows.length} name(s) match`;
};
$("bulk-save").onclick = () => whileSaving("bulk-save", async () => {
  const rows = bulkMatches();
  if (!rows.length) return;
  const res = await post({ kind: "bulk_rename", ...context(),
    pattern: $("bulk-pat").value.trim(), replacement: $("bulk-rep").value,
    renames: rows });
  $("annostatus").textContent = res.ok
    ? `${res.logged} rename(s) logged ${res.at}  ${res.id || ""}`
    : `error: ${res.error}`;
});

await loadStage();
