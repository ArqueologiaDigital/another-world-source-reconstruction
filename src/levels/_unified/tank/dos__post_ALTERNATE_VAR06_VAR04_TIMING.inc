LABEL_1B75:
	mov [0x06], 0x0002
	mov [0x04], 0x0002
	break
	break
	mov [0x06], 0x0003
	break
	mov [0x04], 0x0001
	break
	mov [0x06], 0x0004
	break
	break
	mov [0x06], 0x0001
	break
	mov [0x04], 0x0002
	break
	break
	mov [0x06], 0x0002
	mov [0x04], 0x0003
	break
	break
	mov [0x06], 0x0004
	mov [0x04], 0x0004
	sub [0x07], 0x0001
	break
	sub [0x07], 0x0004
	break
	mov [0x06], 0x0001
	sub [0x07], 0x0001
	sub [0x05], 0x0002
	break
	break
	mov [0x04], 0x0001
	sub [0x05], 0x0002
	break
	mov [0x06], 0x0002
	sub [0x05], 0x0002
	break
	jmp LABEL_1ADA
LABEL_1BD9:
	db 0x11

; Looping background animation. Set up by
; TANK_STAGE_BOOT_SETUP_CHANNELS as channel 0x02; runs
; forever drawing CINEMATIC_221 (4x) then CINEMATIC_222
; then more — the continuous tank-arena ambient effect
; (probably steam vents or screen-edge framing).
TANK_BG_ANIM_CIN221_222_BOOT_CHANNEL_02:
	video offset=CINEMATIC_221, x=[0x0a], y=100
	break
	video offset=CINEMATIC_221, x=[0x0a], y=100
	break
	video offset=CINEMATIC_221, x=[0x0a], y=100
	break
	video offset=CINEMATIC_221, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_223, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	video offset=CINEMATIC_222, x=[0x0a], y=100
	break
	jmp TANK_BG_ANIM_CIN221_222_BOOT_CHANNEL_02
