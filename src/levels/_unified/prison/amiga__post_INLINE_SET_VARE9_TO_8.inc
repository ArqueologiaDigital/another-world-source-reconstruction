DELAY_LOOP_VARE9:
	break
	djnz [0xE9], DELAY_LOOP_VARE9
	mov [0xE9], 0x0008

ANIM_CIN_186_LOOP_VARE9:
	video type=1, offset=CINEMATIC_186, x=145, y=100
	break
	djnz [0xE9], ANIM_CIN_186_LOOP_VARE9
	jmp INLINE_SET_VARE9_TO_8
LABEL_0C4E:
	db 0x11

LABEL_0C4F:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_326, x=160, y=100
	video type=1, offset=CINEMATIC_327, x=192, y=65
	selectVideoPage 0xFF
	break
	break
	break
	break
	break
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_326, x=160, y=101
	video type=1, offset=CINEMATIC_279, x=192, y=65
	selectVideoPage 0xFF
	break
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_326, x=160, y=102
	selectVideoPage 0xFF
	break
	break
	break
	break
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_326, x=160, y=101
	selectVideoPage 0xFF
	break
	break
	break
	jmp LABEL_0C4F
LABEL_0C8D:
	db 0x11

LABEL_0C8E:
	video type=1, offset=CINEMATIC_320, x=160, y=100
	jmp LABEL_0CC3

LABEL_0C95:
	video type=1, offset=CINEMATIC_321, x=160, y=100
	jmp LABEL_0CC3

LABEL_0C9C:
	video type=1, offset=CINEMATIC_322, x=160, y=100
	selectVideoPage 0xFF
	break
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_323, x=160, y=100
	jmp LABEL_0CC3

LABEL_0CAE:
	video type=1, offset=CINEMATIC_324, x=160, y=100
	selectVideoPage 0xFF
	break
	break
	break
	break
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_325, x=160, y=100
	jmp LABEL_0CC3

LABEL_0CC3:
	selectVideoPage 0xFF
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	selectVideoPage 0x00
	je [RANDOM_SEED], 0x00, LABEL_0C8E
	je [RANDOM_SEED], 0x01, LABEL_0C95
	je [RANDOM_SEED], 0x02, LABEL_0C9C
	je [RANDOM_SEED], 0x03, LABEL_0CAE
	jmp LABEL_0CC3
LABEL_0CE6:
	db 0x11

LABEL_0CE7:
	break
	jg [0x01], 0xBE, LABEL_0CE7
	mov [0xF8], [0x6A]
	and [0xF8], 0x00E0
	jne [0xF8], 0x20, LABEL_0D07
	jne [0x6A], 0x23, LABEL_0CE7
	jg [0x68], 0xBE, LABEL_0CE7

LABEL_0D07:
	and [0x4B], 0x7F9F
	mov [0x78], 0xFFF6
	mov [0x79], [0x44]
	mov [0x7A], 0x0023
	mov [0x7B], 0x3000
	mov [0x7C], 0x0018
	mov [0x7D], 0x0810
	mov [0x7E], 0x03E8
	setup channel=0x27, address=LABEL_25A5
	mov [0x6C], 0x0001
	killChannel

LABEL_0D2F:
	break
	mov [0xF8], [0x68]
	sub [0xF8], [0x78]
	jg [0xF8], 0x28, LABEL_0D2F
	setup channel=0x27, address=LABEL_161E
	break
	break
	break
	setup channel=0x23, address=INLINE_SET_VAR29_TO_28
	killChannel

LABEL_0D48:
	break
	jg [0x01], 0x41, LABEL_0D48
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	setup channel=0x14, address=BANK4_AFTER_CIN_414
	killChannel

LABEL_0D58:
	break
	mov [0xAF], 0x0000
	je [0xB0], 0x00, KILL_CHANNEL_LANDING	;@raw=0x0A,0x00,0xB0,0x00,0x0D,0x97
	je [0xB0], 0x01, LABEL_0D58
	je [0x72], [HACK_VAR_67], LABEL_0D58
	jne [0x6A], [HACK_VAR_67], LABEL_0D58
	jl [0x70], 0x00, LABEL_0D58
	jg [0x68], 0x010E, LABEL_0D58
	call LABEL_0D98
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0xAF], [0x3A]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF:
	break
	djnz [0xAF], DELAY_LOOP_VARAF
	jmp LABEL_0D58
