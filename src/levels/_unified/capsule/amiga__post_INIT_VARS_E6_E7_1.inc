LABEL_11B5:
	break
	sub [0xE6], 0x0004
	jg [0xE6], 0xFFEC, LABEL_11B5
	setup channel=0x2C, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_11C6:
	video type=1, offset=CINEMATIC_014, x=239, y=102
	mov [0xEB], 0x00C8
	mov [0xEC], 0x0061
	mov [0xE9], 0x00EF
	mov [0xEA], 0x0066
	video type=1, offset=CINEMATIC_015, x=2, y=103
	video type=1, offset=CINEMATIC_014, x=200, y=97
	video type=1, offset=CINEMATIC_015, x=171, y=100
	break
	jmp LABEL_11C6
LABEL_11EA:
	db 0x11, 0x54, 0x5B, 0x31, 0xE9, 0xEA, 0x06, 0x07
	db 0x11, 0xEB

HANG_DRAW_CIN_003_AT_11F4:
	video type=1, offset=CINEMATIC_003, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_003_AT_11F4

LABEL_11FD:
	video type=1, offset=CINEMATIC_120, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_005_AT_1203:
	video type=1, offset=CINEMATIC_005, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_005_AT_1203

LABEL_120C:
	video type=1, offset=CINEMATIC_005, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_006, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x0070, freq=0x1E, vol=0x0A, channel=0x01
	video type=1, offset=CINEMATIC_007, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_008, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_003_AT_122A:
	video type=1, offset=CINEMATIC_003, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_003_AT_122A

LABEL_1233:
	video type=1, offset=CINEMATIC_120, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_005_AT_1239:
	video type=1, offset=CINEMATIC_005, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_005_AT_1239

LABEL_1242:
	video type=1, offset=CINEMATIC_005, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_006, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_007, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_008, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_003_AT_125A:
	video type=1, offset=CINEMATIC_003, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_003_AT_125A

HANG_DRAW_CIN_004:
	video type=1, offset=CINEMATIC_004, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_004

LABEL_126C:
	video type=1, offset=CINEMATIC_012, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_011:
	video type=1, offset=CINEMATIC_011, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_011

LABEL_127B:
	video type=1, offset=CINEMATIC_009, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_010, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x008D, freq=0x1E, vol=0x0A, channel=0x02
	video type=1, offset=CINEMATIC_011, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_012, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_013:
	video type=1, offset=CINEMATIC_013, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_013
