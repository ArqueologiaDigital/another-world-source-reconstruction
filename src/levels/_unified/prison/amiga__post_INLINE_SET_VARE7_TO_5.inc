DELAY_LOOP_VARE7:
	break
	djnz [0xE7], DELAY_LOOP_VARE7
	mov [0xE7], 0x0002
	mov [0xE8], 0x00C6

LABEL_0BEF:
	video offset=CINEMATIC_454, x=163, y=[0xe8]
	sub [0xE8], 0x0002
	break
	djnz [0xE7], LABEL_0BEF
	video offset=CINEMATIC_455, x=170, y=198
	video offset=CINEMATIC_456, x=170, y=197
	break
	video offset=CINEMATIC_455, x=170, y=197
	jmp INLINE_SET_VARE7_TO_5
LABEL_0C0D:
	db 0x11
