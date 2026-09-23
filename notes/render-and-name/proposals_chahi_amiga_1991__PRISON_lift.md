# PRISON: the lift landing, read from a render

`PRISON_LIFT_LANDING_BACKGROUND_DRAW` chooses its background by screen:

```
	je [SCREEN_NUM], 0x65, PRISON_DRAW_CIN_092_L1
	video offset=CINEMATIC_106, x=160, y=100
	je [SCREEN_NUM], 0x45, PRISON_DRAW_CIN_092_L2
	video offset=CINEMATIC_092, x=160, y=100
...
PRISON_DRAW_CIN_092_L1:
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	call PRISON_DRAW_CIN_092_L3
	video offset=CINEMATIC_104, x=200, y=100
	video offset=CINEMATIC_105, x=160, y=129
```

so 090/091/104 are one screen's background and 106/092 are the others'. The
routine's own name and `PRISON_LIFT_LANDING_DRAW_BUDDY_IF_SCREEN_05` settle
where this is.

## The vault is two halves, and the extents prove it

```
  090   239.5x130.0   2 paths   x[-186.0,  53.5]
  091   240.0x132.0   2 paths   x[ -53.5, 186.5]
```

Mirror ranges about the anchor, meeting at ±53.5, each two paths: a dark mass
`#202044` and a bright rim `#0097fb` along its outer curve. Rendered alone,
090 is the left half of an arched vault with a lit edge and 091 is the right
half of the same arch. Neither is a layer over the other.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_090 | CINEMATIC_PRISON_LIFT_LANDING_VAULT_HALF_0 | high | 239.5x130.0, two paths, x[-186.0, 53.5]: the screen-left half of an arched vault -- a dark mass in `#202044` with a bright `#0097fb` rim along the outer curve. `HALF` is a composition word, not a facing direction: its x range meets `_1`'s at ±53.5 and the two together are one arch |
| CINEMATIC_091 | CINEMATIC_PRISON_LIFT_LANDING_VAULT_HALF_1 | high | 240.0x132.0, two paths, x[-53.5, 186.5]: the screen-right half, the same two colours in the same roles, mirrored |
| CINEMATIC_104 | CINEMATIC_PRISON_LIFT_LANDING_SLOPE | medium | 77.5x65.0, five paths, drawn at 200,100 -- inside the arch and to its right. A triangular wedge in `#302064` rising left to right, with a `#545454` edge and a `#0097fb` highlight along its top. `SLOPE` is the shape; it does not say whether it is a ramp, a girder or a light shaft |
| CINEMATIC_106 | CINEMATIC_PRISON_LIFT_LANDING_WALL_PANEL | medium | 193.0x70.0, **one path**, x[-220.5, -27.5] y[-40.0, 30.0]: a single filled rectangle in `#202044`, well left of the anchor. One path means there is nothing in it to identify; what it has is a place and a role -- the background this routine draws on every screen except 0x65 |
| CINEMATIC_092 | CINEMATIC_PRISON_LIFT_LANDING_COLUMN | medium | 60.0x200.0, **one path**, x[-27.0, 33.0] y[-100.0, 100.0]: a filled bar sixty wide running the full 200 of screen height, centred on the anchor. Drawn after `_WALL_PANEL` on every screen except 0x45, so the two are alternatives layered by screen, not a figure and its detail |

## What these names do not claim

`HALF_0` and `HALF_1` are screen-left and screen-right. The index is draw
order and the extents say which is which.

`WALL_PANEL` and `COLUMN` are each **one path**. Their names come from their
measured shape -- a broad rectangle and a full-height bar -- and from the
routine that draws them, not from anything inside the picture, which is why
both are `medium`.
