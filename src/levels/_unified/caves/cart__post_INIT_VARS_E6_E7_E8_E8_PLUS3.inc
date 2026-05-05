DELAY_LOOP_VAREE:
	break
	djnz [0xEE], DELAY_LOOP_VAREE
	mov [0xE7], 0x000A
	call SETUP_VAR8B_6E_VAR97_B7_VAR96_0
	mov [0xEE], 0x0011

LABEL_06CA:
	break
	jl [0x01], 0x50, LABEL_06D5
	djnz [0xEE], LABEL_06CA

LABEL_06D5:
	song id=0x0BD0, delay=0x0000, pos=0x00
	setup channel=0x39, address=LABEL_48C1
	setup channel=0x3A, address=LABEL_48F4
	killChannel

LABEL_06E4:
	break
	je [0xE7], 0x00, LABEL_06E4
	selectVideoPage 0x00
	video offset=CINEMATIC_624, x=[0xe6], y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_625, x=[0xe6], y=100
	selectVideoPage 0xFF

LABEL_06FE:
	break
	je [0xE7], 0x00, LABEL_0709
	djnz [0xE7], LABEL_06FE

LABEL_0709:
	selectVideoPage 0x00
	video offset=CINEMATIC_626, x=[0xe6], y=100
	selectVideoPage 0xFF
	mov [0xE7], 0x0000
	break
	video offset=CINEMATIC_624, x=[0xe6], y=100
	jmp LABEL_06E4
LABEL_071F:
	db 0x11

LABEL_0720:
	video offset=CINEMATIC_255, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_254, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_253, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_252, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_250, x=[0x01], y=[0x02]
	video offset=CINEMATIC_251, x=[0x01], y=[0x02]
	mov [0x32], 0x0009
	sub [0x02], 0x0001

LABEL_074A:
	break
	video offset=CINEMATIC_250, x=[0x01], y=[0x02]
	video offset=CINEMATIC_263, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_250, x=[0x01], y=[0x02]
	video offset=CINEMATIC_264, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_250, x=[0x01], y=[0x02]
	video offset=CINEMATIC_265, x=[0x01], y=[0x02]
	jmp LABEL_074A
LABEL_076E:
	db 0x11

LABEL_076F:
	video offset=CINEMATIC_250, x=[0x01], y=[0x02]
	video offset=CINEMATIC_251, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_252, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_253, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_254, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_255, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02]
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_EA2E
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	killChannel

LABEL_07A4:
	break
	video offset=CINEMATIC_256, x=160, y=100
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
	video offset=CINEMATIC_256, x=160, y=100
	break
	jmp LABEL_07A4
LABEL_07E9:
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

LABEL_0820:
	break
	jl [0x01], 0x0122, LABEL_0820
	jmp DRAW_CIN_437_439_BLOCK
LABEL_082B:
	db 0x11

LABEL_082C:
	break
	break
	video offset=CINEMATIC_230, x=[0xed], y=[0xee]
	play id=0x0059, freq=0x08, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_231, x=[0xed], y=[0xee]
	break
	play id=0x006F, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_232, x=[0xed], y=[0xee]
	break
	play id=0x005B, freq=0x0A, vol=0x40, channel=0x02
	video offset=CINEMATIC_233, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_234, x=[0xed], y=[0xee]
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x03
	video offset=CINEMATIC_235, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_236, x=[0xed], y=[0xee]
	break
	play id=0x0058, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_237, x=[0xed], y=[0xee]
	break
	video offset=CINEMATIC_238, x=[0xed], y=[0xee]
	mov [0x32], 0x0000
	break
	video offset=CINEMATIC_239, x=[0xed], y=[0xee]
	setup channel=0x14, address=LABEL_076F
	killChannel

LABEL_0890:
	video offset=CINEMATIC_240, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0xFFFF, LABEL_08FA
	video offset=CINEMATIC_244, x=[0x6c], y=[0x6d]
	break

LABEL_08A3:
	video offset=CINEMATIC_242, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_243, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0xFFFF, LABEL_08FA
	video offset=CINEMATIC_242, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_244, x=[0x6c], y=[0x6d]
	break
	jmp LABEL_0890
LABEL_08C5:
	db 0x11

LABEL_08C6:
	video offset=CINEMATIC_248, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0x01, LABEL_08FA
	video offset=CINEMATIC_247, x=[0x6c], y=[0x6d]
	break

LABEL_08D8:
	video offset=CINEMATIC_245, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_246, x=[0x6c], y=[0x6d]
	break
	video offset=CINEMATIC_245, x=[0x6c], y=[0x6d]
	break
	jne [0x71], 0x01, LABEL_08FA
	video offset=CINEMATIC_247, x=[0x6c], y=[0x6d]
	break
	jmp LABEL_08C6
LABEL_08F9:
	db 0x11

LABEL_08FA:
	video offset=CINEMATIC_241, x=[0x6c], y=[0x6d]

LABEL_08FF:
	break
	je [0x71], 0x00, LABEL_08FA
	je [0x71], 0xFFFF, LABEL_08A3
	je [0x71], 0x01, LABEL_08D8
	video offset=CINEMATIC_249, x=[0x6c], y=[0x6d]
	jmp LABEL_08FF
LABEL_091B:
	db 0x11

LABEL_091C:
	mov [0x6C], 0x013B
	je [HACK_VAR_67], 0xC8, INIT_VARS_6D_71_70
	mov [0x6C], 0xFFFB
