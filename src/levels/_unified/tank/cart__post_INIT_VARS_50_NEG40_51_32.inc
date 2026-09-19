LABEL_150A:
	break
	call LABEL_151A
	add [0x50], 0x000A
	djnz [0x51], LABEL_150A
	jmp TANK_GROUND_DEBRIS_SWEEP_INIT
LABEL_1519:
	db 0x11

LABEL_151A:
	jle [0x4F], 0x00, SHARED_RET
	jne [0x4E], 0x00, SHARED_RET
	sub [0x4F], 0x0001
	mov [0x4E], 0x0001
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4B], [0x64]
	and [0x4B], 0x001F
	add [0x4B], [0x50]
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4C], [0x64]
	and [0x4C], 0x0007
	add [0x4C], 0x0089
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4D], [0x64]
	and [0x4D], 0x000F
	add [0x4D], 0x0037
	ret


TANK_GROUND_DEBRIS_BURST_LOOP:
	break
	je [0x4E], 0x00, TANK_GROUND_DEBRIS_BURST_LOOP
	play id=0x008C, freq=0x1E, vol=0x14, channel=0x01
	video offset=CINEMATIC_201, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video offset=CINEMATIC_202, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video offset=CINEMATIC_203, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0x03
	video offset=CINEMATIC_204, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0xFF
	mov [0x4E], 0x0000
	jmp TANK_GROUND_DEBRIS_BURST_LOOP
LABEL_158A:
	db 0x11

TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C:
	break
	jle [0x3E], 0x00, TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C
	sub [0x3E], 0x0001
	call TANK_RANDOM_HASH_ADVANCE
	mov [RANDOM_SEED], [0x65]
	mov [0x3D], [0x64]
	shr [0x3D], 0x0008
	and [0x3D], 0x001F
	add [0x3D], 0x005A
	play id=0x008C, freq=0x19, vol=0x0D, channel=0x00
	video offset=CINEMATIC_205, x=[0x3c], y=[0x3d]
	selectVideoPage 0x03
	call TANK_RANDOM_HASH_ADVANCE
	mov [0xF8], [0x64]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, LABEL_15CD
	video offset=CINEMATIC_208, x=[0x3c], y=[0x3d]

LABEL_15CD:
	jne [0xF8], 0x01, LABEL_15D8
	video offset=CINEMATIC_207, x=[0x3c], y=[0x3d]

LABEL_15D8:
	jl [0xF8], 0x02, TANK_GROUND_DEBRIS_WAIT_LOOP
	video offset=CINEMATIC_206, x=[0x3c], y=[0x3d]

; `break; if var4F == 0: loop; else sub var4F-=1`. A
; counter-based delay — yields a frame and tries again
; until var4F is non-zero, then decrements it. Different
; semantics from 17AB: this one DECREMENTS the counter on
; exit (consuming the trigger), 17AB just LEAVES the
; trigger for the caller to consume.
TANK_GROUND_DEBRIS_WAIT_LOOP:
	selectVideoPage 0xFF
	jmp TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C
LABEL_15E8:
	db 0x11

HANG_DRAW_CIN_089:
	video offset=CINEMATIC_089, x=[0x0f], y=[0x10]
	break
	jmp HANG_DRAW_CIN_089

HANG_DRAW_CIN_090:
	video offset=CINEMATIC_090, x=[0x01], y=[0x02]
	break
	jmp HANG_DRAW_CIN_090

TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER:
	break
	je [0x46], 0x00, TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_056, x=160, y=100
	break
	video offset=CINEMATIC_056, x=160, y=100
	break
	video offset=CINEMATIC_057, x=160, y=100
	break
	video offset=CINEMATIC_058, x=160, y=100
	break
	video offset=CINEMATIC_059, x=160, y=100
	break
	break
	break
	killChannel

TANK_PROJECTILE_ARC_AND_EXPLOSION:
	break
	je [0x56], 0x00, TANK_PROJECTILE_ARC_AND_EXPLOSION
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_020, x=195, y=79
	break
	video offset=CINEMATIC_020, x=202, y=75
	break
	video offset=CINEMATIC_021, x=212, y=66
	break
	video offset=CINEMATIC_020, x=220, y=58
	break
	video offset=CINEMATIC_019, x=235, y=55
	break
	video offset=CINEMATIC_001, x=247, y=61
	break
	video offset=CINEMATIC_002, x=258, y=73
	break
	video offset=CINEMATIC_022, x=269, y=80
	break
	video offset=CINEMATIC_022, x=272, y=77, zoom=0x3c
	break
	video offset=CINEMATIC_022, x=275, y=74, zoom=0x32
	break
	video offset=CINEMATIC_022, x=278, y=71, zoom=0x2d
	break
	video offset=CINEMATIC_022, x=278, y=68, zoom=0x22
	break
	video offset=CINEMATIC_022, x=280, y=65, zoom=0x1f
	break
	selectVideoPage 0x00
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_045, x=264, y=103
	selectVideoPage 0x03
	video offset=CINEMATIC_045, x=264, y=103
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_046, x=264, y=105
	break
	video offset=CINEMATIC_047, x=264, y=105
	break
	video offset=CINEMATIC_048, x=264, y=103
	break
	video offset=CINEMATIC_049, x=264, y=103
	break
	video offset=CINEMATIC_050, x=264, y=103
	break
	video offset=CINEMATIC_051, x=264, y=103
	break
	video offset=CINEMATIC_052, x=264, y=103
	killChannel

LABEL_16BF:
	jg [0x41], 0x00, LABEL_16C9
	break
	jmp LABEL_16BF

LABEL_16C9:
	video offset=CINEMATIC_053, x=135, y=100
	video offset=CINEMATIC_054, x=160, y=100
	video offset=CINEMATIC_054, x=145, y=100
	break
	video offset=CINEMATIC_053, x=137, y=100
	video offset=CINEMATIC_054, x=160, y=100
	video offset=CINEMATIC_054, x=145, y=100
	break
	video offset=CINEMATIC_053, x=140, y=100
	video offset=CINEMATIC_054, x=160, y=100
	video offset=CINEMATIC_054, x=145, y=100
	break
	video offset=CINEMATIC_053, x=143, y=100
	video offset=CINEMATIC_054, x=160, y=100
	video offset=CINEMATIC_054, x=145, y=100
	break
	video offset=CINEMATIC_053, x=146, y=100
	video offset=CINEMATIC_054, x=160, y=100
	break
	video offset=CINEMATIC_053, x=149, y=100
	video offset=CINEMATIC_054, x=160, y=100
	break
	video offset=CINEMATIC_053, x=152, y=100
	video offset=CINEMATIC_054, x=160, y=100
	break
	video offset=CINEMATIC_053, x=155, y=100
	video offset=CINEMATIC_054, x=160, y=100
	break
	video offset=CINEMATIC_053, x=157, y=100
	video offset=CINEMATIC_054, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_053, x=160, y=100
	selectVideoPage 0xFF

LABEL_1731:
	break
	jle [0x41], 0x00, LABEL_1731
	sub [0x41], 0x0001
	selectVideoPage 0x00
	video offset=CINEMATIC_054, x=189, y=100
	video offset=CINEMATIC_054, x=176, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_054, x=189, y=100
	video offset=CINEMATIC_054, x=176, y=100
	video offset=CINEMATIC_053, x=155, y=100
	video offset=CINEMATIC_054, x=160, y=100
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x01
	video offset=CINEMATIC_055, x=247, y=91
	break
	video offset=CINEMATIC_053, x=159, y=100
	video offset=CINEMATIC_054, x=160, y=100
	video offset=CINEMATIC_055, x=300, y=91
	selectVideoPage 0x00
	video offset=CINEMATIC_053, x=160, y=100
	selectVideoPage 0xFF
	break
	jmp LABEL_1731
	killChannel

LABEL_177D:
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F35, x=239, y=123
	play id=0x0052, freq=0x1E, vol=0x10, channel=0x01
	break
	video offset=CINEMATIC_055, x=240, y=123
	break
	break
	jmp LABEL_177D
LABEL_1791:
	db 0x11
