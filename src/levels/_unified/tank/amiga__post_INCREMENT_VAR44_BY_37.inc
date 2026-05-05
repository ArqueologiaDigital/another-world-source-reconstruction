WAIT_VAR45_PLAY_8C_DRAW_CIN_011:
	break
	je [0x45], 0x00, WAIT_VAR45_PLAY_8C_DRAW_CIN_011
	play id=0x008C, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_080, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_081, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_082, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_083, x=[0x42], y=[0x43], zoom=[0x44]
	je [0x57], 0x00, DRAW_CIN_84_ON_PAGE_3
	jl [0x43], 0x69, LABEL_10D9

DRAW_CIN_84_ON_PAGE_3:
	selectVideoPage 0x03
	video offset=CINEMATIC_084, x=[0x42], y=[0x43], zoom=[0x44]
	selectVideoPage 0xFF

LABEL_10D9:
	mov [0x45], 0x0000
	jmp WAIT_VAR45_PLAY_8C_DRAW_CIN_011
LABEL_10E0:
	db 0x11

LABEL_10E1:
	break
	je [0x4F], 0x00, LABEL_10E1
	sub [0x4F], 0x0001
