LABEL_7AF1:
	je [HACK_VAR_67], 0x65, LABEL_7B0D
	video offset=CINEMATIC_106, x=160, y=100
	je [HACK_VAR_67], 0x45, LABEL_7B05
	video offset=CINEMATIC_092, x=160, y=100

LABEL_7B05:
	call LABEL_7AAF
	video offset=CINEMATIC_105, x=160, y=129
	ret

LABEL_7B0D:
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	call LABEL_7AAF
	video offset=CINEMATIC_104, x=200, y=100
	video offset=CINEMATIC_105, x=160, y=129
	ret
LABEL_7B21:
	db 0x11

LABEL_7B22:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	call INCREMENT_VAR31
	jne [RANDOM_SEED], 0x00, LABEL_7B32
	setup channel=0x38, address=DRAW_CIN_154_TO_156_3F_AT_A74B7DB1

LABEL_7B32:
	jne [RANDOM_SEED], 0x01, LABEL_7B3C
	setup channel=0x39, address=DRAW_CIN_151_TO_153_3F_AT_40D20636

LABEL_7B3C:
	jne [RANDOM_SEED], 0x02, LABEL_7B46
	setup channel=0x38, address=DRAW_CIN_149_TO_150_2F_AT_F63AB95D

LABEL_7B46:
	jne [RANDOM_SEED], 0x03, LABEL_7B50
	setup channel=0x39, address=DRAW_CIN_132_TO_133_2F_AT_BB9185F0

LABEL_7B50:
	jne [RANDOM_SEED], 0x04, LABEL_7B5C
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x03

LABEL_7B5C:
	jne [RANDOM_SEED], 0x05, LABEL_7B68
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x02

LABEL_7B68:
	jne [RANDOM_SEED], 0x06, LABEL_7B74
	play id=0x0058, freq=0x14, vol=0x20, channel=0x03

LABEL_7B74:
	jl [RANDOM_SEED], 0x1E, LABEL_7B80
	play id=0x0058, freq=0x0A, vol=0x18, channel=0x00

LABEL_7B80:
	call LABEL_7D42
	call LABEL_7A3E
	call LABEL_7AAF
	video offset=CINEMATIC_102, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_103, x=160, y=[HERO_Y]
	je [0x11], 0x00, SHARED_RET
	video offset=CINEMATIC_131, x=[0x07], y=[0x08]
	ret

LABEL_7B9F:
	jne [0x63], 0xFFFF, SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y
	add [0x14], 0x0010
	add [0x18], 0x0010
	add [SCROLL_Y], 0x0010
	ret
