# Backdrop painters in CAPSULE -- dos_1992

Derived by notes/backdrop-drawer/backdrop_drawer.py.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_9E59 | CAPSULE_SCREEN_6D_BACKDROP_DRAW | high | draws 7 picture(s), of which 4 are already named for screen 0x6D (`CINEMATIC_CAPSULE_SCREEN_6D_BACKDROP_LAYER_3`), and the `[SCREEN_NUM]` dataflow independently pins the routine to that same screen |
| LABEL_9C52 | CAPSULE_SCREEN_92_BACKDROP_DRAW | high | draws 5 still-numbered picture(s); the `[SCREEN_NUM]` dataflow pins it to this screen, and the other port's routine painting byte-identical art derives the same screen from its own disassembly |
