LABEL_7BBC:
	je [HACK_VAR_67], 0x65, LABEL_7BD8
	video offset=CINEMATIC_106, x=160, y=100
	je [HACK_VAR_67], 0x45, LABEL_7BD0
	video offset=CINEMATIC_092, x=160, y=100

LABEL_7BD0:
	call LABEL_7B7A
	video offset=CINEMATIC_105, x=160, y=129
	ret

LABEL_7BD8:
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	call LABEL_7B7A
	video offset=CINEMATIC_104, x=200, y=100
	video offset=CINEMATIC_105, x=160, y=129
	ret
LABEL_7BEC:
	db 0x11

LABEL_7BED:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	call INCREMENT_VAR31
	jne [RANDOM_SEED], 0x00, LABEL_7BFD
	setup channel=0x38, address=DRAW_CIN_154_TO_156_3F_AT_A74B7DB1

LABEL_7BFD:
	jne [RANDOM_SEED], 0x01, LABEL_7C07
	setup channel=0x39, address=DRAW_CIN_151_TO_153_3F_AT_40D20636

LABEL_7C07:
	jne [RANDOM_SEED], 0x02, LABEL_7C11
	setup channel=0x38, address=DRAW_CIN_149_TO_150_2F_AT_F63AB95D

LABEL_7C11:
	jne [RANDOM_SEED], 0x03, LABEL_7C1B
	setup channel=0x39, address=DRAW_CIN_132_TO_133_2F_AT_BB9185F0

LABEL_7C1B:
	jne [RANDOM_SEED], 0x04, LABEL_7C27
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x03

LABEL_7C27:
	jne [RANDOM_SEED], 0x05, LABEL_7C33
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x02

LABEL_7C33:
	jne [RANDOM_SEED], 0x06, LABEL_7C3F
	play id=0x0058, freq=0x14, vol=0x20, channel=0x03

LABEL_7C3F:
	jl [RANDOM_SEED], 0x1E, LABEL_7C4B
	play id=0x0058, freq=0x0A, vol=0x18, channel=0x00

LABEL_7C4B:
	call LABEL_7E0D
	call LABEL_7B09
	call LABEL_7B7A
	video offset=CINEMATIC_102, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_103, x=160, y=[HERO_Y]
	je [0x11], 0x00, SHARED_RET
	video offset=CINEMATIC_131, x=[0x07], y=[0x08]
	ret

LABEL_7C6A:
	jne [0x63], 0xFFFF, SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y
	add [0x14], 0x0010
	add [0x18], 0x0010
	add [SCROLL_Y], 0x0010
	ret
