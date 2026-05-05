LABEL_18FA:
	break
	video offset=CINEMATIC_412, x=[BUDDY_X], y=[BUDDY_Y]
	jl [HERO_X], 0x8C, LABEL_18FA
	jl [HERO_X], 0x91, LABEL_18FA
	mov [0xB6], 0x0001
	mov [0x2A], 0x0005
	mov [0x42], 0x0037
	mov [0x43], 0x009C
	setup channel=0x14, address=LABEL_04BB
	setup channel=0x16, address=LABEL_0D48
	break
	video offset=CINEMATIC_411, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_409, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_408, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_413, x=160, y=36
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_407, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_633D
	break
	call LABEL_5661
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [BUDDY_X], 0x0001
	break
	call LABEL_61E0
	call INLINE_OR_VAR11_WITH_1000
	add [BUDDY_X], 0x0001
	break

LABEL_1964:
	call GUARDED_HERO_ANIM_CV_009
	break
	jmp LABEL_1964
LABEL_196B:
	db 0x03, 0x07, 0x00, 0x01, 0x06, 0x04, 0x64, 0xDC
	db 0x03, 0x07, 0xFF, 0xFF, 0x06, 0x04, 0x56, 0x43
	db 0x04, 0x29, 0xD6, 0x03, 0x07, 0xFF, 0xFF, 0x06
	db 0x00, 0x2F, 0x00, 0x18, 0x00, 0x29, 0xFF, 0xF0
	db 0x07, 0x29, 0xE0, 0x11
