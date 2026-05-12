CODEWHEEL_SYMBOL_DISPATCH_CASE_1E:
	jne [0x06], 0x1E, CODEWHEEL_DRAW_ALIEN_GLYPH_41_IF_VAR06_EQ_1F
	video offset=CINEMATIC_ALIEN_GLYPH_29, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_41_IF_VAR06_EQ_1F:
	jne [0x06], 0x1F, CODEWHEEL_DRAW_ALIEN_GLYPH_40_IF_VAR06_EQ_20
	video offset=CINEMATIC_ALIEN_GLYPH_30, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_40_IF_VAR06_EQ_20:
	jne [0x06], 0x20, CODEWHEEL_DRAW_ALIEN_GLYPH_39_IF_VAR06_EQ_21
	video offset=CINEMATIC_ALIEN_GLYPH_31, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_39_IF_VAR06_EQ_21:
	jne [0x06], 0x21, CODEWHEEL_DRAW_ALIEN_GLYPH_38_IF_VAR06_EQ_22
	video offset=CINEMATIC_ALIEN_GLYPH_32, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_38_IF_VAR06_EQ_22:
	jne [0x06], 0x22, CODEWHEEL_DRAW_ALIEN_GLYPH_37_IF_VAR06_EQ_23
	video offset=CINEMATIC_ALIEN_GLYPH_33, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_37_IF_VAR06_EQ_23:
	jne [0x06], 0x23, CODEWHEEL_DRAW_ALIEN_GLYPH_36_IF_VAR06_EQ_24
	video offset=CINEMATIC_ALIEN_GLYPH_34, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_36_IF_VAR06_EQ_24:
	jne [0x06], 0x24, CODEWHEEL_DRAW_ALIEN_GLYPH_35_IF_VAR06_EQ_25
	video offset=CINEMATIC_ALIEN_GLYPH_35, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_35_IF_VAR06_EQ_25:
	jne [0x06], 0x25, CODEWHEEL_DRAW_ALIEN_GLYPH_34_IF_VAR06_EQ_26
	video offset=CINEMATIC_ALIEN_GLYPH_36, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_34_IF_VAR06_EQ_26:
	jne [0x06], 0x26, CODEWHEEL_DRAW_ALIEN_GLYPH_33_IF_VAR06_EQ_27
	video offset=CINEMATIC_ALIEN_GLYPH_37, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_33_IF_VAR06_EQ_27:
	jne [0x06], 0x27, CODEWHEEL_DRAW_ALIEN_GLYPH_32_IF_VAR06_EQ_28
	video offset=CINEMATIC_ALIEN_GLYPH_28_DUP_1, x=[0x07], y=[0x08], zoom=[0x04]
	ret

CODEWHEEL_DRAW_ALIEN_GLYPH_32_IF_VAR06_EQ_28:
	jne [0x06], 0x28, SHARED_RET
	video offset=CINEMATIC_ALIEN_GLYPH_38, x=[0x07], y=[0x08], zoom=[0x04]
	ret

SHARED_RET:
	ret
	killChannel
	video offset=CINEMATIC_079, x=160, y=100

BLITTER_LOOP_WITH_VAR1B_2B:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x002B
	break
	jmp BLITTER_LOOP_WITH_VAR1B_2B

; Three infinite frame-hold loops with `mov [0x1B], <const>`
; / break / jmp self. The constants 0x2B vs 0x15 set
; different music/sound IDs (var1B is the audio-track
; slot). 10A3 is used both for initial wheel display and
; for failure-reset; 10B2 is the ERROR-screen idle; 10C1
; is the alternate ERROR-screen with a different track,
; triggered when var31==1 AND var1B==0x2B already (i.e.
; re-entering ERROR after a previous attempt).
CODEWHEEL_ERROR_SCREEN_HOLD_FRAME:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x002B
	break
	jmp CODEWHEEL_ERROR_SCREEN_HOLD_FRAME

; Three infinite frame-hold loops with `mov [0x1B], <const>`
; / break / jmp self. The constants 0x2B vs 0x15 set
; different music/sound IDs (var1B is the audio-track
; slot). 10A3 is used both for initial wheel display and
; for failure-reset; 10B2 is the ERROR-screen idle; 10C1
; is the alternate ERROR-screen with a different track,
; triggered when var31==1 AND var1B==0x2B already (i.e.
; re-entering ERROR after a previous attempt).
CODEWHEEL_ERROR_SCREEN_HOLD_FRAME_ALT_MUSIC:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	mov [0x1B], 0x0015
	break
	jmp CODEWHEEL_ERROR_SCREEN_HOLD_FRAME_ALT_MUSIC
