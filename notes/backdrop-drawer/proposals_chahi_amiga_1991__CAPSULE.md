# Backdrop painters in CAPSULE -- chahi_amiga_1991

Derived by notes/backdrop-drawer/backdrop_drawer.py.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_7F4E | CAPSULE_SCREEN_4D_BACKDROP_DRAW | high | draws 5 picture(s), of which 2 are already named for screen 0x4D (`CINEMATIC_CAPSULE_SCREEN_4D_BACKDROP_LAYER_3`), and the `[SCREEN_NUM]` dataflow independently pins the routine to that same screen |
| LABEL_7F22 | CAPSULE_SCREEN_92_BACKDROP_DRAW | high | draws 5 still-numbered picture(s); the `[SCREEN_NUM]` dataflow pins it to this screen, and the other port's routine painting byte-identical art derives the same screen from its own disassembly |
