DELAY_LOOP_VAREE:
	break
	djnz [0xEE], DELAY_LOOP_VAREE
	mov [0xE7], 0x000A
	call SETUP_VAR8B_6E_VAR97_B7_VAR96_0
	mov [0xEE], 0x0011

LABEL_074A:
	break
	jl [HERO_X], 0x50, LABEL_0755
	djnz [0xEE], LABEL_074A

LABEL_0755:
	setup channel=0x39, address=LABEL_4A04
	setup channel=0x3A, address=LABEL_4A37
	killChannel

LABEL_075E:
	break
	je [0xE7], 0x00, LABEL_075E
	selectVideoPage 0x00
	video offset=CINEMATIC_633, x=[0xe6], y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_634, x=[0xe6], y=100
	selectVideoPage 0xFF

LABEL_0778:
	break
	je [0xE7], 0x00, LABEL_0783
	djnz [0xE7], LABEL_0778

LABEL_0783:
	selectVideoPage 0x00
	video offset=CINEMATIC_635, x=[0xe6], y=100
	selectVideoPage 0xFF
	mov [0xE7], 0x0000
	break
	video offset=CINEMATIC_633, x=[0xe6], y=100
	jmp LABEL_075E
LABEL_0799:
	db 0x11

LABEL_079A:
	video offset=CINEMATIC_256, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_255, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_254, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_253, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_251, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_252, x=[HERO_X], y=[HERO_Y]
	mov [0x32], 0x0009
	sub [HERO_Y], 0x0001

LABEL_07C4:
	break
	video offset=CINEMATIC_251, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_264, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_251, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_265, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_251, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_266, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_07C4
LABEL_07E8:
	db 0x11

LABEL_07E9:
	video offset=CINEMATIC_251, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_252, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_253, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_254, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_255, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_256, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_174, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_E9A5
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	killChannel

LABEL_081E:
	break
	video offset=CINEMATIC_257, x=160, y=100
	break
	video offset=CINEMATIC_258, x=160, y=100
	break
	video offset=CINEMATIC_259, x=160, y=100
	break
	video offset=CINEMATIC_260, x=160, y=100
	break
	video offset=CINEMATIC_261, x=160, y=100
	break
	video offset=CINEMATIC_262, x=160, y=100
	break
	video offset=CINEMATIC_263, x=160, y=100
	break
	video offset=CINEMATIC_262, x=160, y=100
	break
	video offset=CINEMATIC_261, x=160, y=100
	break
	video offset=CINEMATIC_260, x=160, y=100
	break
	video offset=CINEMATIC_259, x=160, y=100
	break
	video offset=CINEMATIC_258, x=160, y=100
	break
	video offset=CINEMATIC_257, x=160, y=100
	break
	jmp LABEL_081E
LABEL_0863:
	db 0x11

DRAW_CIN_437_439_BLOCK:
	video offset=CINEMATIC_437, x=160, y=100
	break
	video offset=CINEMATIC_438, x=160, y=100
	break
	video offset=CINEMATIC_439, x=160, y=100
	break
	video offset=CINEMATIC_440, x=160, y=100
	break
	video offset=CINEMATIC_441, x=160, y=100
	break
	video offset=CINEMATIC_442, x=160, y=100
	break
	video offset=CINEMATIC_441, x=160, y=100
	break
	video offset=CINEMATIC_439, x=160, y=100
	break
	video offset=CINEMATIC_443, x=160, y=100
	break
	video offset=CINEMATIC_438, x=160, y=100
	break
	video offset=CINEMATIC_437, x=160, y=100

LABEL_089A:
	break
	jl [HERO_X], 0x0122, LABEL_089A
	jmp DRAW_CIN_437_439_BLOCK
LABEL_08A5:
	db 0x11

LABEL_08A6:
	break
	break
	video offset=CINEMATIC_231, x=[0xed], y=[0xee]
	play id=0x0059, freq=0x08, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_232, x=[0xed], y=[0xee]
	break
	play id=0x006F, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_233, x=[0xed], y=[0xee]
	break
	play id=0x005B, freq=0x0A, vol=0x40, channel=0x02
	video offset=CINEMATIC_234, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_235, x=[0xed], y=[0xee]
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x03
	video offset=CINEMATIC_236, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_237, x=[0xed], y=[0xee]
	break
	play id=0x0058, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_238, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_239, x=[0xed], y=[0xee]
	mov [0x32], 0x0000
	break
	video offset=CINEMATIC_240, x=[0xed], y=[0xee]
	setup channel=0x14, address=LABEL_07E9
	killChannel

LABEL_090A:
	video offset=CINEMATIC_241, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0xFFFF, LABEL_0974
	video offset=CINEMATIC_245, x=[0x6c], y=[0x6d]
	break

LABEL_091D:
	video offset=CINEMATIC_243, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_244, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0xFFFF, LABEL_0974
	video offset=CINEMATIC_243, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_245, x=[0x6c], y=[0x6d]
	break
	jmp LABEL_090A
LABEL_093F:
	db 0x11

LABEL_0940:
	video offset=CINEMATIC_249, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0x01, LABEL_0974
	video offset=CINEMATIC_248, x=[0x6c], y=[0x6d]
	break

LABEL_0952:
	video offset=CINEMATIC_246, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_247, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_246, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0x01, LABEL_0974
	video offset=CINEMATIC_248, x=[0x6c], y=[0x6d]
	break
	jmp LABEL_0940
LABEL_0973:
	db 0x11

LABEL_0974:
	video offset=CINEMATIC_242, x=[0x6c], y=[0x6d]

LABEL_0979:
	break
	je [0x71], 0x00, LABEL_0974
	je [0x71], 0xFFFF, LABEL_091D
	je [0x71], 0x01, LABEL_0952
	video offset=CINEMATIC_250, x=[0x6c], y=[0x6d]
	jmp LABEL_0979
LABEL_0995:
	db 0x11

LABEL_0996:
	mov [0x6C], 0x013B
	je [HACK_VAR_67], 0xC8, INIT_VARS_6D_71_70
	mov [0x6C], 0xFFFB
