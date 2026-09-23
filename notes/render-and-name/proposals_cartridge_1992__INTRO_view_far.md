# INTRO (cartridge_1992): the debris layer this branch still calls a number

Argument in `proposals_chahi_amiga_1991__INTRO_view_far.md`. This branch
already had `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR` on the right picture --
0x2BF2, the tunnel -- which is how amiga's and msdos's error was found. What it
still calls a number is the lower debris layer that amiga and msdos had the
view's name on.

The unified tree's shared `.else` arm already reads `..._DEBRIS_LOWER` at
0xCB2E after the msdos batch; this row brings the branch's own `.asm` into
line and touches nothing else.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_380 | CINEMATIC_ACCELERATOR_TUNNEL_DEBRIS_LOWER | high | 0xCB2E, the offset amiga holds at 0xCBBC and msdos at 0xCB2E, `607639c52ec8` where it can be rendered: 72 paths of scattered specks confined to the lower half of the frame, drawn between the view and `..._TUNNEL_DEBRIS` |
