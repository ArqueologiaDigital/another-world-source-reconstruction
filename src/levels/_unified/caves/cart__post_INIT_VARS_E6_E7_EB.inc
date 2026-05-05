LABEL_40B1:
	break
	video offset=CINEMATIC_637, x=160, y=[0xe6], zoom=0x40
	video offset=CINEMATIC_636, x=180, y=[0xe7], zoom=0x40
	add [0xE6], 0x0006
	add [0xE7], 0x0008
	djnz [0xEB], LABEL_40B1
	selectVideoPage 0x00
	video offset=CINEMATIC_637, x=160, y=[0xe6], zoom=0x40
	video offset=CINEMATIC_636, x=180, y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	mov [0xE6], 0x0013
	mov [0xE7], 0x0013
	mov [0xEB], 0x000C

LABEL_40E2:
	break
	video offset=CINEMATIC_637, x=230, y=[0xe6], zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_636, x=170, y=[0xe7], zoom=0x40
	add [0xE6], 0x0008
	add [0xE7], 0x0006
	djnz [0xEB], LABEL_40E2
	selectVideoPage 0x00
	video offset=CINEMATIC_637, x=230, y=[0xe6], zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_636, x=170, y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	mov [0xE6], 0x002A
	mov [0xE7], 0x000E
	mov [0xEB], 0x000C

LABEL_4115:
	break
	video offset=CINEMATIC_720, x=100, y=[0xe6], zoom=[0x20]	;@enc=alt
	add [0xE6], 0x0006
	add [0xE7], 0x0008
	djnz [0xEB], LABEL_4115
	selectVideoPage 0x00
	video offset=CINEMATIC_720, x=100, y=[0xe6], zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_637, x=147, y=101, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_720, x=206, y=107
	video offset=CINEMATIC_637, x=153, y=114
	video offset=CINEMATIC_637, x=194, y=86
	selectVideoPage 0xFF
	video offset=CINEMATIC_636, x=193, y=73
	mov [0xE6], 0x002A
	mov [0xEB], 0x0006

LABEL_4150:
	break
	video offset=CINEMATIC_636, x=193, y=[0xe6], zoom=0x40
	add [0xE6], 0x0006
	djnz [0xEB], LABEL_4150
	selectVideoPage 0x00
	video offset=CINEMATIC_636, x=193, y=[0xe6], zoom=0x40
	selectVideoPage 0xFF
	killChannel

LABEL_4168:
	mov [0x7F], 0x000A
	mov [0xF8], [0xBB]
	and [0xF8], 0x0001
	je [0xF8], 0x00, DELAY_LOOP_VAR7F
	play id=0x006E, freq=0x0A, vol=0x22, channel=0x03
	mov [0x7F], 0x0001
	mov [0x75], 0xFFEC
	mov [0x78], 0xFFE2
	mov [0x7B], 0xFFF6

DELAY_LOOP_VAR7F:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F
	play id=0x006E, freq=0x07, vol=0x22, channel=0x03
	setup channel=0x34, address=LABEL_4089
	mov [0x7F], 0x0001

DELAY_LOOP_VAR7F_AT_41A2:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_41A2
	or [0xBB], 0x0001
	setup channel=0x2C, address=INLINE_SET_VAR79_TO_1
	mov [0x7F], 0x0002

DELAY_LOOP_VAR7F_AT_41B3:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_41B3
	setup channel=0x34, address=KILL_CHANNEL_LANDING
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_039
	mov [0x7F], 0x0002

DELAY_LOOP_VAR7F_AT_41C4:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_41C4
	setup channel=0x34, address=LABEL_4089
	setup channel=0x2B, address=INLINE_SET_VAR76_TO_0001_037
	mov [0x7F], 0x0006

DELAY_LOOP_VAR7F_AT_41D5:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_41D5
	mov [0x77], 0x0118
	mov [0x78], 0xFF56
	mov [0x79], 0x0001
	setup channel=0x2C, address=INLINE_SET_VAR79_TO_1
	mov [0x7F], 0x0004
	play id=0x006E, freq=0x08, vol=0x22, channel=0x03

DELAY_LOOP_VAR7F_AT_41F4:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_41F4
	mov [0x74], [0x01]
	mov [0x75], 0xFFE2
	mov [0x76], 0x0001
	setup channel=0x2B, address=INLINE_SET_VAR76_TO_0001_038
	mov [0x7A], 0x00F0
	mov [0x7B], 0xFF9C
	mov [0x7C], 0x0001
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_039
	play id=0x006E, freq=0x07, vol=0x40, channel=0x03
	killChannel
