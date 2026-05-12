CODEWHEEL_SYMBOL_DISPATCH_CASE_1E:
	jne [0x06], 0x1E, SHARED_RET
	video offset=CINEMATIC_ALIEN_GLYPH_29, x=[0x07], y=[0x08], zoom=[0x04]
	ret

SHARED_RET:
	ret
LABEL_0D94:
	db 0x11, 0x80, 0x06, 0xA0, 0x64

LABEL_0D99:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x002B
	break
	jmp LABEL_0D99

LABEL_0DA8:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x002B
	break
	jmp LABEL_0DA8

LABEL_0DB7:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x0015
	break
	jmp LABEL_0DB7
