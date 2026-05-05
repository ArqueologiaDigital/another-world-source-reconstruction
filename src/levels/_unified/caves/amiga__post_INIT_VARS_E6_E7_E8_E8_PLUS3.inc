DELAY_LOOP_VAREE:
	break
	djnz [0xEE], DELAY_LOOP_VAREE
	mov [0xE7], 0x000A
	call SETUP_VAR8B_6E_VAR97_B7_VAR96_0
	mov [0xEE], 0x0011

LABEL_0729:
	break
	jl [0x01], 0x50, LABEL_0734
	djnz [0xEE], LABEL_0729

LABEL_0734:
	setup channel=0x39, address=LABEL_46F3
	setup channel=0x3A, address=LABEL_4726
	killChannel

LABEL_073D:
	break
	je [0xE7], 0x00, LABEL_073D
	selectVideoPage 0x00
	video offset=CINEMATIC_612, x=[0xe6], y=100, zoom=0x40
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_613, x=[0xe6], y=100, zoom=0x40
	selectVideoPage 0xFF

LABEL_0757:
	break
	je [0xE7], 0x00, LABEL_0762
	djnz [0xE7], LABEL_0757

LABEL_0762:
	selectVideoPage 0x00
	video offset=CINEMATIC_614, x=[0xe6], y=100, zoom=0x40
	selectVideoPage 0xFF
	mov [0xE7], 0x0000
	break
	video offset=CINEMATIC_612, x=[0xe6], y=100, zoom=0x40
	jmp LABEL_073D
LABEL_0778:
	db 0x11

LABEL_0779:
	video offset=CINEMATIC_238, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_237, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_236, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_235, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_233, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_234, x=[0x01], y=[0x02], zoom=0x40
	mov [0x32], 0x0009
	sub [0x02], 0x0001

LABEL_07A3:
	break
	video offset=CINEMATIC_233, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_246, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_233, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_247, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_233, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_248, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_07A3
LABEL_07C7:
	db 0x11

LABEL_07C8:
	video offset=CINEMATIC_233, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_234, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_235, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_236, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_237, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_238, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_E41E
	setup channel=0x16, address=LABEL_DF3B
	killChannel

LABEL_07FD:
	break
	video offset=CINEMATIC_239, x=160, y=100
	break
	video offset=CINEMATIC_240, x=160, y=100
	break
	video offset=CINEMATIC_241, x=160, y=100
	break
	video offset=CINEMATIC_242, x=160, y=100
	break
	video offset=CINEMATIC_243, x=160, y=100
	break
	video offset=CINEMATIC_244, x=160, y=100
	break
	video offset=CINEMATIC_245, x=160, y=100
	break
	video offset=CINEMATIC_244, x=160, y=100
	break
	video offset=CINEMATIC_243, x=160, y=100
	break
	video offset=CINEMATIC_242, x=160, y=100
	break
	video offset=CINEMATIC_241, x=160, y=100
	break
	video offset=CINEMATIC_240, x=160, y=100
	break
	video offset=CINEMATIC_239, x=160, y=100
	break
	jmp LABEL_07FD
LABEL_0842:
	db 0x11

DRAW_CIN_437_439_BLOCK:
	video offset=CINEMATIC_416, x=160, y=100
	break
	video offset=CINEMATIC_417, x=160, y=100
	break
	video offset=CINEMATIC_418, x=160, y=100
	break
	video offset=CINEMATIC_419, x=160, y=100
	break
	video offset=CINEMATIC_420, x=160, y=100
	break
	video offset=CINEMATIC_421, x=160, y=100
	break
	video offset=CINEMATIC_420, x=160, y=100
	break
	video offset=CINEMATIC_418, x=160, y=100
	break
	video offset=CINEMATIC_422, x=160, y=100
	break
	video offset=CINEMATIC_417, x=160, y=100
	break
	video offset=CINEMATIC_416, x=160, y=100

LABEL_0879:
	break
	jl [0x01], 0x0122, LABEL_0879
	jmp DRAW_CIN_437_439_BLOCK
LABEL_0884:
	db 0x11

LABEL_0885:
	break
	break
	video offset=CINEMATIC_213, x=[0xed], y=[0xee], zoom=0x40
	play id=0x0059, freq=0x08, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_214, x=[0xed], y=[0xee], zoom=0x40
	break
	play id=0x006F, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_215, x=[0xed], y=[0xee], zoom=0x40
	break
	play id=0x005B, freq=0x0A, vol=0x40, channel=0x02
	video offset=CINEMATIC_216, x=[0xed], y=[0xee], zoom=0x40
	break
	video offset=CINEMATIC_217, x=[0xed], y=[0xee], zoom=0x40
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x03
	video offset=CINEMATIC_218, x=[0xed], y=[0xee], zoom=0x40
	break
	video offset=CINEMATIC_219, x=[0xed], y=[0xee], zoom=0x40
	break
	play id=0x0058, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_220, x=[0xed], y=[0xee], zoom=0x40
	break
	video offset=CINEMATIC_221, x=[0xed], y=[0xee], zoom=0x40
	mov [0x32], 0x0000
	break
	video offset=CINEMATIC_222, x=[0xed], y=[0xee], zoom=0x40
	setup channel=0x14, address=LABEL_07C8
	killChannel

LABEL_08E9:
	video offset=CINEMATIC_223, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jne [0x71], 0xFFFF, LABEL_0953
	video offset=CINEMATIC_227, x=[0x6c], y=[0x6d], zoom=0x40
	break

LABEL_08FC:
	video offset=CINEMATIC_225, x=[0x6c], y=[0x6d], zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jne [0x71], 0xFFFF, LABEL_0953
	video offset=CINEMATIC_225, x=[0x6c], y=[0x6d], zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jmp LABEL_08E9
LABEL_091E:
	db 0x11

LABEL_091F:
	video offset=CINEMATIC_231, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jne [0x71], 0x01, LABEL_0953
	video offset=CINEMATIC_230, x=[0x6c], y=[0x6d], zoom=0x40
	break

LABEL_0931:
	video offset=CINEMATIC_228, x=[0x6c], y=[0x6d], zoom=0x40
	break
	video offset=CINEMATIC_229, x=[0x6c], y=[0x6d], zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jne [0x71], 0x01, LABEL_0953
	video offset=CINEMATIC_230, x=[0x6c], y=[0x6d], zoom=0x40
	break
	jmp LABEL_091F
LABEL_0952:
	db 0x11

LABEL_0953:
	video offset=CINEMATIC_224, x=[0x6c], y=[0x6d], zoom=0x40

LABEL_0958:
	break
	je [0x71], 0x00, LABEL_0953
	je [0x71], 0xFFFF, LABEL_08FC
	je [0x71], 0x01, LABEL_0931
	video offset=CINEMATIC_232, x=[0x6c], y=[0x6d], zoom=0x40
	jmp LABEL_0958
LABEL_0974:
	db 0x11

LABEL_0975:
	mov [0x6C], 0x013B
	je [HACK_VAR_67], 0xC8, INIT_VARS_6D_71_70
	mov [0x6C], 0xFFFB
