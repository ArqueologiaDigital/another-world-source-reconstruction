DRAW_CODEWHEEL_SYMBOL_BY_VAR06:
	jne [0x06], 0x01, LABEL_0C00
	video offset=CINEMATIC_ALIEN_GLYPH_73, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C00:
	jne [0x06], 0x02, LABEL_0C0D
	video offset=CINEMATIC_ALIEN_GLYPH_72, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C0D:
	jne [0x06], 0x03, LABEL_0C1A
	video offset=CINEMATIC_ALIEN_GLYPH_71, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C1A:
	jne [0x06], 0x04, LABEL_0C27
	video offset=CINEMATIC_ALIEN_GLYPH_70, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C27:
	jne [0x06], 0x05, LABEL_0C34
	video offset=CINEMATIC_ALIEN_GLYPH_69, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C34:
	jne [0x06], 0x06, LABEL_0C41
	video offset=CINEMATIC_ALIEN_GLYPH_68, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C41:
	jne [0x06], 0x07, LABEL_0C4E
	video offset=CINEMATIC_ALIEN_GLYPH_67, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C4E:
	jne [0x06], 0x08, LABEL_0C5B
	video offset=CINEMATIC_ALIEN_GLYPH_66, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C5B:
	jne [0x06], 0x09, LABEL_0C68
	video offset=CINEMATIC_ALIEN_GLYPH_65, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C68:
	jne [0x06], 0x0A, LABEL_0C75
	video offset=CINEMATIC_ALIEN_GLYPH_64, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C75:
	jne [0x06], 0x0B, LABEL_0C82
	video offset=CINEMATIC_ALIEN_GLYPH_63, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C82:
	jne [0x06], 0x0C, LABEL_0C8F
	video offset=CINEMATIC_ALIEN_GLYPH_62, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0C8F:
	jne [0x06], 0x0D, CODEWHEEL_CHECK_DIGIT_2_VAR2C
	video offset=CINEMATIC_ALIEN_GLYPH_61, x=[0x07], y=[0x08], zoom=[0x04]
	ret

; The three-stage code validation chain. Each stage compares
; one entered digit (var 0x2A, 0x2B, 0x2C) against four
; acceptable values (vars 0x1E, 0x1F, 0x20, 0x21 — the
; per-puzzle expected codes). All three must match to
; reach SETUP_CODEWHEEL_CHANNELS (success); any failure
; jumps straight to CODEWHEEL_FAILURE_RESET.
CODEWHEEL_CHECK_DIGIT_2_VAR2C:
	jne [0x06], 0x0E, LABEL_0CA9
	video offset=CINEMATIC_ALIEN_GLYPH_60, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CA9:
	jne [0x06], 0x0F, LABEL_0CB6
	video offset=CINEMATIC_ALIEN_GLYPH_59, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CB6:
	jne [0x06], 0x10, LABEL_0CC3
	video offset=CINEMATIC_ALIEN_GLYPH_58, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CC3:
	jne [0x06], 0x62, LABEL_0CD0
	video offset=CINEMATIC_DEL_BUTTON, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CD0:
	jne [0x06], 0x63, LABEL_0CDD
	video offset=CINEMATIC_OK_BUTTON, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CDD:
	jne [0x06], 0x11, LABEL_0CEA
	video offset=CINEMATIC_ALIEN_GLYPH_55, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CEA:
	jne [0x06], 0x12, LABEL_0CF7
	video offset=CINEMATIC_ALIEN_GLYPH_54, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0CF7:
	jne [0x06], 0x13, LABEL_0D04
	video offset=CINEMATIC_ALIEN_GLYPH_53, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D04:
	jne [0x06], 0x14, LABEL_0D11
	video offset=CINEMATIC_ALIEN_GLYPH_52, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D11:
	jne [0x06], 0x15, LABEL_0D1E
	video offset=CINEMATIC_ALIEN_GLYPH_51, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D1E:
	jne [0x06], 0x16, LABEL_0D2B
	video offset=CINEMATIC_ALIEN_GLYPH_50, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D2B:
	jne [0x06], 0x17, LABEL_0D38
	video offset=CINEMATIC_ALIEN_GLYPH_49, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D38:
	jne [0x06], 0x18, LABEL_0D45
	video offset=CINEMATIC_ALIEN_GLYPH_48, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D45:
	jne [0x06], 0x19, LABEL_0D52
	video offset=CINEMATIC_ALIEN_GLYPH_47, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D52:
	jne [0x06], 0x1A, LABEL_0D5F
	video offset=CINEMATIC_ALIEN_GLYPH_46, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D5F:
	jne [0x06], 0x1B, LABEL_0D6C
	video offset=CINEMATIC_ALIEN_GLYPH_45, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D6C:
	jne [0x06], 0x1C, LABEL_0D79
	video offset=CINEMATIC_ALIEN_GLYPH_44, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D79:
	jne [0x06], 0x1D, LABEL_0D86
	video offset=CINEMATIC_ALIEN_GLYPH_43, x=[0x07], y=[0x08], zoom=[0x04]
	ret

LABEL_0D86:
	jne [0x06], 0x1E, SHARED_RET
	video offset=CINEMATIC_ALIEN_GLYPH_42, x=[0x07], y=[0x08], zoom=[0x04]
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
