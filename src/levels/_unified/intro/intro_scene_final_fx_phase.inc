INTRO_PLAY_FX_AND_PALETTE_4_LOOP:
	break
.if BRANCH != "chahi_amiga_1991"
	setPalette 0x04
.endif
	play id=0x000D, freq=0x14, vol=0x19, channel=0x02
	mov [PAUSE_SLICES], 0x0003
	mov [0x01], 0x0032
	break
	play id=0x003C, freq=0x14, vol=0x01, channel=0x01
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_0, x=229, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_1, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_2, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_3, x=230, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_4, x=229, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_5, x=229, y=97
	play id=0x003C, freq=0x14, vol=0x3F, channel=0x00
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_6, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_7, x=229, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_8, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_9, x=231, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_10, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_11, x=231, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_12, x=231, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_13, x=232, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_14, x=232, y=97
	play id=0x003C, freq=0x0A, vol=0x3F, channel=0x00
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_15, x=231, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_16, x=232, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_17, x=232, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_18, x=231, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_19, x=230, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_20, x=226, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_21, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_22, x=230, y=96
	break
	play id=0x003C, freq=0x0F, vol=0x0F, channel=0x02
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_23, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_24, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_25, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_26, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_27, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_28, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_29, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_30, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_31, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_32, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_33, x=230, y=96
	break
	video offset=CINEMATIC_WALKING_FEET_ARRIVING_34, x=230, y=96
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_ENTRANCE_DOORWAY_OPEN, x=160, y=100
	video offset=CINEMATIC_ENTRANCE_DOOR_PART_OPEN, x=160, y=100
.else
	video offset=CINEMATIC_ENTRANCE_DOORWAY_OPEN, x=160, y=100
	video offset=CINEMATIC_ENTRANCE_DOOR_PART_OPEN, x=160, y=100
.endif
	selectVideoPage 0xFF
	video offset=CINEMATIC_WALKING_FEET_ENTERING_0, x=230, y=96
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_ENTRANCE_DOORWAY_OPEN, x=160, y=100
.else
	video offset=CINEMATIC_ENTRANCE_DOORWAY_OPEN, x=160, y=100
.endif
	selectVideoPage 0xFF
	video offset=CINEMATIC_WALKING_FEET_ENTERING_1, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_2, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_3, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_4, x=125, y=98
	break
	mov [PAUSE_SLICES], 0x0002
	video offset=CINEMATIC_WALKING_FEET_ENTERING_5, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_6, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_7, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_8, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_9, x=125, y=98
	play id=0x003C, freq=0x0A, vol=0x14, channel=0x02
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=125, y=98
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=94, y=97
	break
	video offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=71, y=115
	break
	mov [PAUSE_SLICES], 0x0002
.if BRANCH == "chahi_amiga_1991"
	mov [0x01], 0x001E
.else
	mov [0x01], 0x001C
.endif

DELAY_28F_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_28F_BEFORE_BLITTER_SETUP
.if BRANCH != "chahi_amiga_1991"
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	mov [PAUSE_SLICES], 0x0002
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_ENTRANCE_DOOR_PART_OPEN, x=160, y=100
.else
	video offset=CINEMATIC_ENTRANCE_DOOR_PART_OPEN, x=160, y=100
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_ENTRANCE_DOOR_CLOSED, x=160, y=100
.else
	video offset=CINEMATIC_ENTRANCE_DOOR_CLOSED, x=160, y=100
.endif
	selectVideoPage 0xFF
	play id=0x000D, freq=0x0C, vol=0x3F, channel=0x03
	mov [0x01], 0x0014

DELAY_20F_BEFORE_PAL_7_INIT:
	break
	djnz [0x01], DELAY_20F_BEFORE_PAL_7_INIT
	setup channel=0x01, address=INTRO_SET_PAL_7_FILL_PAGE0_5
	setup channel=0x02, address=LIFT_DOORS_CLOSING_INIT
	setup channel=0x03, address=LIFT_SCENE_FIXED_OVERLAY_REDRAW_LOOP
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

DRAW_CARPARK_ENTRANCE_COMPOSITE:
	fill page=0x00, color=0x02
	selectVideoPage 0x00
; The amiga arm carries its own full list, so the three draws the 1992
; ports share afterwards belong in the .else arm -- left outside, amiga
; drew them twice. Its `setPalette 0x04` also has to sit inside this arm:
; the splice anchored it inside the .else, where its own branch test can
; never be true.
.if BRANCH == "chahi_amiga_1991"
	setPalette 0x04
	video offset=CINEMATIC_ENTRANCE_WALL_PANEL, x=192, y=100
	video offset=CINEMATIC_CARPARK_NEAR_PILLAR, x=14, y=80
	video offset=CINEMATIC_CARPARK_WALL_FACE, x=189, y=68
	video offset=CINEMATIC_CARPARK_WALL_DOORWAY_RECESS, x=64, y=70
	video offset=CINEMATIC_CARPARK_PILLAR_OUTER_SHADE, x=244, y=56
	video offset=CINEMATIC_CARPARK_PILLAR_MID_SHADE, x=246, y=56
	video offset=CINEMATIC_CARPARK_PILLAR_LIT_FACE, x=247, y=50
	video offset=CINEMATIC_CARPARK_PILLAR_HIGHLIGHT, x=117, y=86
	video offset=CINEMATIC_CARPARK_PILLAR_SEAM, x=61, y=69
	video offset=CINEMATIC_ENTRANCE_WALL_AND_FLOOR_DEBRIS, x=160, y=100
	video offset=CINEMATIC_ENTRANCE_DOOR_CLOSED, x=160, y=100
.else
	video offset=CINEMATIC_ENTRANCE_WALL_PANEL, x=192, y=100
	video offset=CINEMATIC_CARPARK_NEAR_PILLAR, x=14, y=80
	video offset=CINEMATIC_CARPARK_WALL_FACE, x=189, y=68
	video offset=CINEMATIC_CARPARK_WALL_DOORWAY_RECESS, x=64, y=70
	video offset=CINEMATIC_CARPARK_PILLAR_OUTER_SHADE, x=244, y=56
	video offset=CINEMATIC_CARPARK_PILLAR_MID_SHADE, x=246, y=56
	video offset=CINEMATIC_CARPARK_PILLAR_LIT_FACE, x=247, y=50
	video offset=CINEMATIC_CARPARK_PILLAR_HIGHLIGHT, x=117, y=86
	video offset=CINEMATIC_CARPARK_PILLAR_SEAM, x=61, y=69
	video offset=CINEMATIC_ENTRANCE_WALL_AND_FLOOR_DEBRIS, x=160, y=100
	video offset=CINEMATIC_ENTRANCE_DOOR_CLOSED, x=160, y=100
.endif
.if BRANCH != "chahi_amiga_1991"
	selectVideoPage 0xFF
.endif
	killChannel

DRAW_CINEMATIC_053_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_CARPARK_NEAR_PILLAR, x=14, y=80
.else
	video offset=CINEMATIC_CARPARK_NEAR_PILLAR, x=14, y=80
.endif
	break
	jmp DRAW_CINEMATIC_053_LOOP
LABEL_26A6:
.if BRANCH == "dos_1992"
	db 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
.else
	killChannel
.endif
.endif
.if BRANCH == "cartridge_1992"
.elif BRANCH == "gba_2004"
.endif
