DELAY_LOOP_VARED_AT_0DAE:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0DAE
	break
	break
	break
	setup channel=0x36, address=LABEL_0E92
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_0DBE:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0DBE
	setup channel=0x36, address=LABEL_0E92
	setup channel=0x37, address=LABEL_0ED5
	setup channel=0x04, address=LABEL_0DED
	setup channel=0x05, address=LABEL_2856
	mov [0xED], 0x0006

DELAY_LOOP_VARED_AT_0DD7:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0DD7
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_0DE0:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0DE0
	setup channel=0x36, address=LABEL_0E92
	jmp INLINE_SET_VARED_TO_5
LABEL_0DEC:
	db 0x11

LABEL_0DED:
	video type=1, offset=CINEMATIC_029, x=216, y=149
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	break
	video type=1, offset=CINEMATIC_029, x=218, y=149
	break
	video type=1, offset=CINEMATIC_030, x=220, y=149
	break
	video type=1, offset=CINEMATIC_030, x=222, y=149
	video type=1, offset=CINEMATIC_031, x=223, y=149
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_031, x=223, y=148
	selectVideoPage 0xFF
	killChannel

LABEL_0E13:
	video type=1, offset=CINEMATIC_029, x=72, y=143
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	video type=1, offset=CINEMATIC_026, x=93, y=90
	break
	video type=1, offset=CINEMATIC_029, x=75, y=143
	video type=1, offset=CINEMATIC_026, x=94, y=90
	break
	video type=1, offset=CINEMATIC_030, x=77, y=143
	break
	video type=1, offset=CINEMATIC_031, x=79, y=143
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_031, x=80, y=144
	selectVideoPage 0xFF
	killChannel

LABEL_0E3D:
	video type=1, offset=CINEMATIC_029, x=213, y=149
	play id=0x0075, freq=0x12, vol=0x18, channel=0x03
	break
	video type=1, offset=CINEMATIC_029, x=231, y=150
	break
	video type=1, offset=CINEMATIC_029, x=233, y=150
	break
	video type=1, offset=CINEMATIC_030, x=235, y=150
	break
	video type=1, offset=CINEMATIC_030, x=236, y=150
	break
	video type=1, offset=CINEMATIC_031, x=238, y=149
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_031, x=239, y=149
	selectVideoPage 0xFF
	killChannel
	video type=1, offset=CINEMATIC_029, x=80, y=148
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_032, x=89, y=149
	selectVideoPage 0xFF
	killChannel

LABEL_0E76:
	video type=1, offset=CINEMATIC_033, x=160, y=100, zoom=[0x50]	;@enc=alt
	play id=0x0075, freq=0x0C, vol=0x10, channel=0x03
	break
	video type=1, offset=CINEMATIC_033, x=160, y=100, zoom=[0x46]	;@enc=alt
	break

HANG_DRAW_CIN_033:
	video type=1, offset=CINEMATIC_033, x=160, y=100
	break
	jmp HANG_DRAW_CIN_033

LABEL_0E92:
	video type=1, offset=CINEMATIC_048, x=160, y=100
	video type=1, offset=CINEMATIC_033, x=160, y=100, zoom=[0x43]	;@enc=alt
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x03
	setup channel=0x06, address=LABEL_0EB3
	break
	video type=1, offset=CINEMATIC_049, x=160, y=100
	video type=1, offset=CINEMATIC_033, x=160, y=100
	jmp HANG_DRAW_CIN_033
LABEL_0EB2:
	db 0x11

LABEL_0EB3:
	video type=1, offset=CINEMATIC_036, x=160, y=100
	break
	video type=1, offset=CINEMATIC_050, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_037, x=188, y=100, zoom=[0xe8]
	add [0xE8], 0x000A
	selectVideoPage 0xFF
	jl [0xE8], 0xA0, KILL_CHAN_AT_03F2
	mov [0xE8], 0x0022
	killChannel

LABEL_0ED5:
	video type=1, offset=CINEMATIC_034, x=160, y=100
	break
	video type=1, offset=CINEMATIC_035, x=160, y=100
	break
	video type=1, offset=CINEMATIC_036, x=78, y=84
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_037, x=107, y=84
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_038, x=160, y=100
	break
	video type=1, offset=CINEMATIC_039, x=160, y=100
	break
	video type=1, offset=CINEMATIC_040, x=160, y=100
	break
	killChannel
	video type=1, offset=CINEMATIC_041, x=160, y=100
	break
	video type=1, offset=CINEMATIC_042, x=160, y=100
	killChannel
	video type=1, offset=CINEMATIC_043, x=160, y=100
	break
	video type=1, offset=CINEMATIC_044, x=160, y=100
	setup channel=0x38, address=LABEL_0F14
	killChannel

LABEL_0F14:
	video type=1, offset=CINEMATIC_045, x=160, y=100
	break
	video type=1, offset=CINEMATIC_046, x=160, y=100
	killChannel

HANG_DRAW_CIN_047:
	video type=1, offset=CINEMATIC_047, x=160, y=100
	break
	jmp HANG_DRAW_CIN_047
LABEL_0F26:
	db 0x11

HANG_DRAW_CIN_145:
	video type=1, offset=CINEMATIC_145, x=160, y=100
	break
	jmp HANG_DRAW_CIN_145
LABEL_0F2F:
	db 0x11

LABEL_0F30:
	video type=1, offset=CINEMATIC_137, x=160, y=100
	play id=0x0052, freq=0x22, vol=0x40, channel=0x02
	setPalette 0x02
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_138, x=160, y=100
	video type=1, offset=CINEMATIC_139, x=72, y=56
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_140, x=72, y=56
	selectVideoPage 0xFF
	killChannel

LABEL_0F53:
	mov [0xE8], 0x008C
	play id=0x0052, freq=0x1B, vol=0x40, channel=0x02
	mov [0xE9], 0x0032
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE8], [0x3D]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE9], [0x3D]
	setPalette 0x02
	video type=1, offset=CINEMATIC_141, x=[0xe8], y=[0xe9], zoom=0x40
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_142, x=[0xe8], y=[0xe9], zoom=0x40
	break
	sub [0xE8], 0x005F
	sub [0xE9], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video type=1, offset=CINEMATIC_139, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_140, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel

LABEL_0F9F:
	mov [0xEA], 0x0064
	mov [0xEB], 0x0032
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x02
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEA], [0x3E]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEB], [0x3D]
	setPalette 0x02
	video type=1, offset=CINEMATIC_143, x=[0xea], y=[0xeb], zoom=0x40
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_144, x=[0xea], y=[0xeb], zoom=0x40
	break
	add [0xEA], 0x0014
	sub [0xEB], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video type=1, offset=CINEMATIC_139, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_140, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel
