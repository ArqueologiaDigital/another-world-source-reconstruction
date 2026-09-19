# Screen-index probes

Evidence behind the VM-variable names in `src/levels/_common_vars.inc` and the
per-stage `CACHED_SCREEN_NUM` declarations.

| script | question it answers | run it |
|---|---|---|
| `var67_screen_grid.py` | Is VM variable `0x67` a screen index into a 32-column row-major grid, and is `0x66` its per-stage cache? Five independent checks; the script exits non-zero if any fails, so it is also a regression test on the `SCREEN_NUM` rename. | `python3 notes/screen-index-probes/var67_screen_grid.py` |
| `apply_screen_num_rename.py` | The migration itself, kept because it produced the reference counts quoted in the rename commit: **6,242** `HACK_VAR_67`, **312** raw `[0x66]` (305 net — the companion script below reverts 7 of them in TANK), and 32 labels that had spelled the placeholder into their own names. Prints the per-name tally. | `python3 notes/screen-index-probes/apply_screen_num_rename.py` |
| `apply_cached_screen_num_scoping.py` | The second half: revert TANK's `[0x66]` to the raw id (**7** sites over the branch files and unified chunks), declare `CACHED_SCREEN_NUM` in the **16** stage files that need it, and rename the **27** unified chunk files whose names embedded the retired labels. | `python3 notes/screen-index-probes/apply_cached_screen_num_scoping.py` |

Both appliers refuse to run on an already-migrated tree. That guard is not
decoration: the first one rewrites *every* `[0x66]` it finds, which is how
TANK's `djnz` counter got aliased in the first place, and a second run would
do it again.

## The signal being read

`var67_screen_grid.py` reads the committed `.asm` sources, not a runtime. What it
measures, and what each measurement would look like if the name were wrong:

1. **Arithmetic on `0x67`.** 29 sites across four ports, all of them `+1`, `-1`,
   `+0x20` or `-0x20`. A single `add [0x67], 0x0003` anywhere would mean the
   variable is a counter, not a grid index, and the check fails on it.
2. **Immediates assigned to `0x67`.** They fall into eight bands whose starts are
   0x1F–0x23 apart. A free-running counter would give one dense run instead. The
   check fails if any band-to-band stride is more than 6 away from a multiple of
   0x20.
3. **The four `*_SCREEN_EXIT_<DIR>_LINK_CASE_*` chains in amiga CAVES.** Each is
   a fall-through ladder of special-case room links ending in one generic step.
   The probe walks each ladder from the source and asserts
   DOWN→`+0x20`, UP→`-0x20`, RIGHT→`+1`, LEFT→`-1`. This is what fixes the
   stride at 32 *columns* and the orientation as row-major rather than the
   other way round.
4. **`and [scratch], 0x001F` after `mov [scratch], [0x66]`.** Six sites, in
   CAPSULE and PRISON — two stages that are not CAVES, so the 32 stride is not
   an artefact of one stage's room layout. `& 31` is the column, written out in
   opcodes.
5. **`je [0x66], [0x67], <cache>` followed by `copyVideoPage src=0x00,
   dst=0xFF`.** The backdrop is repainted from page 0 exactly when the screen
   changed since the last frame, and `0x66` is then updated. That is what makes
   `0x66` a *cache* of `0x67` rather than a second independent variable.

## Why `CACHED_SCREEN_NUM` is not in `_common_vars.inc`

`0x66` is the backdrop cache in LAKE, PRISON, CAVES and CAPSULE on every port,
and a plain `djnz` countdown in TANK (`mov [0x66], 0x0032` /
`djnz [0x66], TANK_ARENA_AMBIENT_LASER_FIRE_LOOP`, three sites per port).
`docs/NAMING.md` §3 says a name belongs in `_common_vars.inc` only if it means
the same thing in every stage and every port, so the alias is declared in the
four stages that use it that way and TANK keeps the raw id. Check 4 of the probe
would not catch a regression here — re-run the per-stage audit if `0x66` picks
up new sites:

```bash
for f in src/levels/*/{LAKE,PRISON,CAVES,CAPSULE,TANK}.asm; do
  echo "== $f"; grep -hE '\[(0x66|CACHED_SCREEN_NUM)\]' "$f" | sed 's/;.*//' | sort | uniq -c
done
```

## What is still raw, and why

- **`0x65`** holds the screen whose backdrop sits in page 3 — LAKE's
  `CYCLE_VIDEO_PAGES_3WAY` shelves page 0 to page 3 and rotates
  `0x67 → 0x66 → 0x65` so that walking back two screens restores a backdrop
  instead of redrawing it. But `0x65` is also `mov [RANDOM_SEED], [0x65]`,
  `and [0x65], 0x00FF` and `mov [0x65], [0x64]` elsewhere, which is more than
  one role, so NAMING.md §3 leaves it as the raw id.
- **`0xF8`** is the scratch register the column mask is computed in. NAMING.md
  §3 grades `SCRATCH` ready at E2; it is not part of this pass.
