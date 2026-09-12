# CAVES ground-map probe

| script | question it answers | how to run |
|---|---|---|
| `ground_map_attribution.py` | Which screen owns each block of the CAVES per-screen ground-height map, and is that attribution exclusive? | `python3 notes/caves-ground-map-probe/ground_map_attribution.py src/levels/chahi_amiga_1991/CAVES.asm` |

## The signal being read

`CAVES_COPY_VAR40_TO_VAR22_L1` (amiga CAVES.asm line 12852) is a 33-arm
`je [HACK_VAR_67], 0xHH, <head>` ladder. `HACK_VAR_67` is the screen number
(`docs/NAMING.md` section 3). Its callers make the meaning unambiguous:

* `CAVES_COPY_VAR40_TO_VAR22_L3` loads `[0x21] <- HERO_X`, `[0x22] <- HERO_Y`
  and calls the ladder;
* `CAVES_COPY_VAR40_TO_VAR22_L5` writes the answer back: `mov [HERO_Y], [0x22]`;
* `CAVES_COPY_VAR40_TO_VAR22_L4` starts a fall when `[0x22] - HERO_Y >= 0x10`.

So `[0x21]` in, `[0x22]` out: the surface Y under an X on the current screen.
Each arm is a chain of x-range segments, flat (`mov [0x22], base; ret`) or
sloped (`sub [0x21], off; shr [0x21], k; mov [0x22], base; add|sub [0x22], [0x21]`).

## Baseline, amiga CAVES.asm as of 2026-09-12

```
arms: 33
reachable blocks: 225  unique: 218  shared: 7
unique blocks span lines 18215-19956
referenced from outside the ground region: 0
28 screens with a private profile, each a contiguous line run
0xCB / 0xCC / 0xCE share one profile; 0x4A / 0x6A share one block
```

`referenced from outside the ground region: 0` is the load-bearing number: it
is what makes `CAVES_GROUND_MAP_SCREEN_<HH>_SEGMENT_<n>` safe to assert, since
no other code path reaches into the table.
