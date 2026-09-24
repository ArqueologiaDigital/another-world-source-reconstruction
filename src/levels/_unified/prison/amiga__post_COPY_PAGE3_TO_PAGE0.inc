LABEL_8149:
	selectVideoPage 0x00
	jne [0x0A], 0x00, LABEL_8155
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5, x=251, y=175

LABEL_8155:
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F2, x=181, y=146
	selectVideoPage 0xFF
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED

PRISON_SCREEN_02_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x0FA0
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	selectVideoPage 0x00
	call PRISON_SCREEN_02_BACKDROP_DRAW
	selectVideoPage 0xFF
	setup channel=0x01, address=LABEL_0C4F
	setup channel=0x02, address=LABEL_0CC3
	setup channel=0x03, address=DRAW_CIN_318_TO_318_2F_AT_93A8CE70
	setup channel=0x04, address=PRISON_DRAW_CIN_311_TO_312_2F_AT_A6494EF7_L0
	setup channel=0x05, address=PRISON_DRAW_CIN_311_TO_312_2F_AT_A6494EF7_L2
	setup channel=0x38, address=LABEL_0895
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_81A1:
	db 0x11

PRISON_SCREEN_03_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x0FA0
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	setPalette 0x02
	call TEARDOWN_CHANS_AND_KILL_LANDING
	selectVideoPage 0x00
	call PRISON_SCREEN_03_BACKDROP_DRAW
	selectVideoPage 0xFF
	setup channel=0x01, address=DRAW_CIN_319_TO_319_4F_AT_9E666694
	jne [0x6C], 0x04, PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
	mov [0xF8], [0x6B]
	and [0xF8], 0x4800
	jne [0xF8], 0x00, PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
	setup channel=0x23, address=PRISON_BUDDY_HACK_SECOND_BURST_DISPATCH
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED

PRISON_SCREEN_04_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x0FA0
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	setPalette 0x02
	call TEARDOWN_CHANS_AND_KILL_LANDING
	selectVideoPage 0x00
	call PRISON_SCREEN_04_BACKDROP_DRAW
	jne [0x6C], 0x04, LABEL_822F
	video offset=CINEMATIC_379, x=160, y=100
	jge [0x6B], 0x4000, LABEL_822F
	video offset=CINEMATIC_BUDDY_HACKING_SECURITY_DOOR, x=260, y=182
	video offset=CINEMATIC_390, x=260, y=182

LABEL_822F:
	selectVideoPage 0xFF
	mov [0x48], 0x011D
	mov [0x49], 0x039B
	setup channel=0x34, address=LABEL_0DE2
	setup channel=0x35, address=LABEL_22F4
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_8244:
	db 0x15, 0x49, 0x00, 0x40, 0x11

PRISON_SCREEN_05_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x00C1
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	call PRISON_BACKDROP_TILE_REPEAT_DOWN
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call PRISON_LIFT_LANDING_BACKGROUND_DRAW
	selectVideoPage 0xFF
	setup channel=0x00, address=LABEL_7F0E
	setup channel=0x34, address=PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
	setup channel=0x35, address=LABEL_8320
	call LABEL_78BF
	jl [0x06], 0x64, TRAMP_8290
	mov [0x06], 0x0063

TRAMP_8290:
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_8293:
	db 0x11

PRISON_SCREEN_25_ENTRY:
	mov [0x42], 0x000F
	mov [0x43], 0x0082
	mov [0x46], 0xF060
	mov [0x47], 0x00C1
	mov [0x40], [0x21]
	mov [0x41], 0x008C
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	call PRISON_BACKDROP_TILE_REPEAT_DOWN
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call PRISON_LIFT_LANDING_BACKGROUND_DRAW
	selectVideoPage 0xFF
	setup channel=0x00, address=LABEL_7F0E
	setup channel=0x34, address=PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
	call LABEL_78BF
	mov [0x70], 0x00D2
	mov [0x71], 0x00B6
	mov [0x72], 0x0024
	mov [0x73], 0x2000
	mov [0x74], 0x0030
	mov [0x75], 0x0031
	mov [0x76], 0x03E8
	setup channel=0x25, address=LABEL_2563
	jl [0xB2], 0x02, TRAMP_82FD
	jg [0xB2], 0x09, TRAMP_82FD
	mov [0xB2], 0x0002

TRAMP_82FD:
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_8300:
	db 0x11

LABEL_8301:
	mov [0x78], 0x0008
	mov [0x79], [HERO_Y]
	mov [0x7A], [SCREEN_NUM]
	mov [0x7B], 0x3000
	mov [0x7C], 0x0038
	mov [0x7D], 0x0021
	mov [0x7E], 0x03E8
	setup channel=0x27, address=LABEL_25A5
	ret


LABEL_8320:
	break
	jne [0xB2], 0x00, LABEL_8320
	jg [0x06], 0x00, LABEL_8320
	jne [SCREEN_NUM], 0x05, LABEL_8320
	jl [HERO_X], 0x14, LABEL_8320
	jg [HERO_X], 0x64, LABEL_8320
	call LABEL_8301

LABEL_8342:
	break
	break
	break
	break
	break
	jge [0x04], 0x4000, LABEL_8342
	call LABEL_0DBD
	jmp LABEL_8342
LABEL_8354:
	db 0x11

PRISON_SCREEN_24_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x0105
	mov [0x46], 0x0053
	mov [0x47], 0x0FA0
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	selectVideoPage 0x00
	call PRISON_SCREEN_24_BACKDROP_DRAW
	setPalette 0x02
	mov [0x50], 0x0064
	mov [0x51], [0x44]
	mov [0x52], [0x40]
	mov [0x48], 0x0096
	mov [0x49], [0xB3]
	mov [0x4A], 0x00FA
	mov [0x4B], 0x120B
	je [0xB2], 0x00, LABEL_83A1
	mov [0x4B], 0x100B

LABEL_83A1:
	setup channel=0x03, address=INLINE_SET_VARE6_TO_50
	setup channel=0x04, address=PRISON_INLINE_SET_VARE6_TO_50_L3
	setup channel=0x05, address=INLINE_SET_VARE7_TO_5
	je [0xB4], 0x00, LABEL_83BB
	setup channel=0x05, address=KILL_CHANNEL_LANDING
	and [0x49], 0xFFBF

LABEL_83BB:
	call LABEL_1333
	selectVideoPage 0xFF
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_83C3:
	db 0x11

PRISON_SCREEN_23_ENTRY:
	mov [0x42], 0x00F0
	mov [0x43], 0x0FA0
	mov [0x46], 0xF060
	mov [0x47], 0x0122
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	selectVideoPage 0x00
	call PRISON_SCREEN_23_BACKDROP_DRAW
	selectVideoPage 0xFF
	setPalette 0x02
	mov [0x50], 0x00FF
	mov [0x51], [0x44]
	mov [0x52], [0x40]
	mov [0x48], 0x0032
	mov [0x49], 0x120B
	mov [0x4A], 0x00C8
	mov [0x4B], 0x124B
	setup channel=0x3B, address=LABEL_0CE7
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED

PRISON_SCREEN_45_ENTRY:
	mov [0x42], 0xF060
	mov [0x43], 0x00C1
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	call PRISON_BACKDROP_TILE_REPEAT_DOWN
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call PRISON_LIFT_LANDING_BACKGROUND_DRAW
	selectVideoPage 0xFF
	setup channel=0x00, address=LABEL_7F0E
	setup channel=0x34, address=PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
	call LABEL_78BF
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED

PRISON_SCREEN_44_ENTRY:
	mov [0x42], 0x0092
	mov [0x43], 0x0FA0
	mov [0x46], 0x000F
	mov [0x47], 0x0082
	mov [0x40], [0x21]
	mov [0x41], 0x0050
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	setPalette 0x02
	selectVideoPage 0x00
	call DRAW_ENERGY_TRANSMISSION_LINE_FG
	selectVideoPage 0xFF
	setup channel=0x01, address=INIT_VARS_E7_E8
	setup channel=0x02, address=INLINE_SET_VARE9_TO_8
	je [0xB4], 0x00, TRAMP_848D
	setup channel=0x01, address=KILL_CHANNEL_LANDING
	setup channel=0x02, address=KILL_CHANNEL_LANDING

TRAMP_848D:
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_8490:
	db 0x11

PRISON_SCREEN_65_ENTRY:
	mov [0x42], 0x0028
	mov [0x43], 0x0118
	mov [0x46], 0x0028
	mov [0x47], 0x0118
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	call TEARDOWN_CHANS_AND_KILL_LANDING
	call PRISON_BACKDROP_TILE_REPEAT_DOWN
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call PRISON_LIFT_LANDING_BACKGROUND_DRAW
	selectVideoPage 0xFF
	setup channel=0x35, address=LABEL_018D
	setup channel=0x00, address=LABEL_7F0E
	setup channel=0x34, address=PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
	call LABEL_78BF
	setPalette 0x1A
	jmp PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED
LABEL_84D4:
	db 0x11

PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_01:
	jne [0x27], 0x01, PRISON_SCREEN_FLOOR_Y_LOOKUP_UPTO_04
	mov [0x22], 0x005A
	mov [0x21], 0x00B6
	ret


PRISON_SCREEN_FLOOR_Y_LOOKUP_UPTO_04:
	jg [0x27], 0x04, LABEL_84F3
	mov [0x22], 0x0050
	mov [0x21], 0x00B6
	ret


LABEL_84F3:
	jne [0x27], 0x05, LABEL_8506
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret


LABEL_8506:
	jne [0x27], 0x25, PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_24
	mov [0x22], 0x0081
	mov [0x21], 0x00B4
	mov [0x23], 0x0001
	ret


PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_24:
	jne [0x27], 0x24, PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_23
	mov [0x22], 0x005D
	mov [0x21], 0x00B6
	ret


PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_23:
	jne [0x27], 0x23, LABEL_8537
	mov [0x22], 0x005C
	mov [0x21], 0x00B6
	ret


LABEL_8537:
	jne [0x27], 0x45, PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_44
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret


PRISON_SCREEN_FLOOR_Y_LOOKUP_CASE_44:
	jne [0x27], 0x44, LABEL_8559
	mov [0x22], 0x0046
	mov [0x21], 0x008B
	ret


LABEL_8559:
	jne [0x27], 0x65, LABEL_856C
	mov [0x22], 0x0081
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret


LABEL_856C:
	ret


LABEL_856D:
	db 0x11
