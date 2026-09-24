# PRISON: the guard's gun, knocked away and landing

`ann:90a7d36bcda4` -- dos_1992/PRISON frame 3069, on `CINEMATIC_576`:
"the guard's gun flying away from his hands when we is hit y the falling cage",
with `ann:1c211b155a6a` (f3070) "the gun rotating mid-air", `ann:430e56cf523c`
(f3071) "yet another frame of the gun mid-air", `ann:14e5df86e392` (f3072) "the
gun in the floor" and `ann:2d924f5ac0a3` (f3075) "the gun on the floor".

The sentences supply the **subject word** and nothing else. Four independent
non-visual measurements supply the family, the order and the event, all from
`DRAW_CIN_576_578_BLOCK` at `PRISON.asm:4202-4226` and the polygon trees:

**1. The trajectory is a ballistic arc, in literal coordinates.**

    576  (215,131)   577  (227,141)   578  (231,158)   579  (239,175)
    578  (243,174)   274  (245,175)   580  (247,175)   274  (249,175)
    274  (250,175)   274  (251,175)

x rises monotonically 215 -> 251; y falls 131 -> 141 -> 158 -> 175 and then
stays at 174/175. Something thrown, landing, and skidding to a stop.

**2. The aspect ratio rotates.** Measured extents, in offset order:

    576  16.5 x  6.0     wide and flat
    577  12.5 x  9.0     shorter, taller
    578  10.0 x 14.0     narrow and TALL -- end-on
    579  16.0 x  6.0     wide and flat again
    580  15.0 x  4.5     flatter
    274  14.0 x  3.5     flattest -- lying down

Wide -> tall -> wide is a rotation, and nothing about it came from looking.

**3. A sound fires on impact.** `play id=0x0060, freq=0x14, vol=0x40` appears
twice in the routine: immediately before `CINEMATIC_274` at (245,175) and again
before `CINEMATIC_274` at (249,175) -- as the object reaches the floor line and
again as it settles.

**4. The offsets are one contiguous run**, 0x564C 0x5670 0x5698 0x56C4 0x56E8
0x5700, six members with no gap. The index below is that run's order, not draw
order, because `CINEMATIC_578` is drawn twice and `CINEMATIC_274` four times;
offset order agrees with the trajectory for every member whose position is
distinct.

amiga holds all six at the same offsets and draws them in the same order at the
same literal coordinates, so the rows carry across unchanged.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_576 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F0 | high | 0x564C, first of the contiguous run 0x564C..0x5700; drawn at the literal (215,131), the top of the arc, extent 16.5x6.0 flat; annot:90a7d36bcda4 frame 3069 `DRAW_CIN_576_578_BLOCK`, "the guard's gun flying away from his hands" |
| CINEMATIC_577 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F1 | high | 0x5670, second of the run; (227,141), x+12 y+10 along the arc; extent 12.5x9.0, mid-rotation; annot:1c211b155a6a frame 3070, "the gun rotating mid-air" |
| CINEMATIC_578 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F2 | high | 0x5698, third of the run; drawn twice, (231,158) then (243,174); extent 10.0x14.0, the only TALL member -- the gun end-on; annot:430e56cf523c frame 3071, "yet another frame of the gun mid-air" |
| CINEMATIC_579 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F3 | high | 0x56C4, fourth of the run; (239,175), the first draw on the floor line y=175; extent 16.0x6.0, flat again after the tall frame; annot:14e5df86e392 frame 3072, "the gun in the floor" |
| CINEMATIC_580 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F4 | high | 0x56E8, fifth of the run; (247,175), on the floor line, after the first `play id=0x0060` impact sound; extent 15.0x4.5; annot:2d924f5ac0a3 frame 3075, "the gun on the floor" |
| CINEMATIC_274 | CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5 | high | 0x5700, last of the contiguous run despite its low constant number; drawn four times at (245,175) (249,175) (250,175) (251,175), the skid to a stop, twice preceded by `play id=0x0060`; extent 14.0x3.5, the flattest -- lying down. No annotation names this one; it is the run's sixth member and the resting pose the other five arrive at |
