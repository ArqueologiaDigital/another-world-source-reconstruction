LABEL_1237:
	break
	break
	break
	video offset=CINEMATIC_100, x=6, y=126
	break
	video offset=CINEMATIC_100, x=221, y=109
	break
	video offset=CINEMATIC_100, x=486, y=102, zoom=0x40
	killChannel
	video offset=CINEMATIC_100, x=6, y=126
	setup channel=0x01, address=LABEL_0026
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	break
	selectVideoPage 0x00
	call DRAW_CIN_069
	video offset=CINEMATIC_060, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_100, x=221, y=109
	break
	video offset=CINEMATIC_100, x=486, y=102, zoom=0x40
	killChannel
	break
	break
	break
	video offset=CINEMATIC_100, x=73, y=56
	break
	video offset=CINEMATIC_100, x=266, y=79, zoom=0x40
	break
	video offset=CINEMATIC_100, x=576, y=91, zoom=0x40
	killChannel

LABEL_1282:
	mov [0x52], 0x017C
	mov [0x53], 0x0075
	mov [HACK_VAR_54], 0x0040
	mov [0x55], 0x0008

LABEL_1292:
	video offset=CINEMATIC_101, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0004
	video offset=CINEMATIC_102, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0002
	video offset=CINEMATIC_103, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_104, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_105, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_106, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_107, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_108, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_109, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0048
	djnz [0x55], LABEL_1292
	mov [0x55], 0x001E

DELAY_LOOP_VAR55:
	break
	djnz [0x55], DELAY_LOOP_VAR55
	jmp LABEL_1282
	killChannel

LABEL_12EE:
	mov [0x52], 0x017C
	mov [0x53], 0x0075
	mov [HACK_VAR_54], 0x0040
	mov [0x55], 0x0008

LABEL_12FE:
	sub [0x52], 0x0004
	video offset=CINEMATIC_102, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0002
	video offset=CINEMATIC_104, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_262, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_107, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_109, x=[0x52], y=[0x53], zoom=[0x54]
	sub [0x52], 0x0048
	break
	djnz [0x55], LABEL_12FE
	jmp LABEL_12EE
LABEL_1334:
	db 0x11

LABEL_1335:
	break
	jle [0x37], 0x00, LABEL_1335
	sub [0x37], 0x0001
	mov [0x39], 0x00A0
	mov [0x3A], 0x0064
	mov [0x38], 0x0000
	mov [0x3B], 0x0006

LABEL_1350:
	break
	call LABEL_13C9
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_13E0
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_13F7
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_140E
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_1425
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_143C
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_1425
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_140E
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_13F7
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_13E0
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_13C9
	call APPLY_HERO_DAMAGE_AND_HIT
	jmp LABEL_1350
LABEL_13C8:
	db 0x11

LABEL_13C9:
	video offset=CINEMATIC_174, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_175, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_13E0:
	video offset=CINEMATIC_176, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_177, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_13F7:
	video offset=CINEMATIC_178, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_179, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_140E:
	video offset=CINEMATIC_180, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_181, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_1425:
	video offset=CINEMATIC_182, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_183, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_143C:
	video offset=CINEMATIC_184, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_185, x=[0x39], y=[0x3a], zoom=0x40
	ret

APPLY_HERO_DAMAGE_AND_HIT:
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	sub [0x37], 0x0001
	mov [0x45], 0x0001
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x42], [0x64]
	and [0x42], 0x001F
	mov [0xF8], [0x38]
	shl [0xF8], 0x0004
	add [0x42], [0xF8]
	shl [0xF8], 0x0001
	add [0x42], [0xF8]
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x43], [0x64]
	and [0x43], 0x000F
	add [0x43], 0x005F
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x44], [0x64]
	and [0x44], 0x000F
	je [0x57], 0x00, INCREMENT_VAR44_BY_37
	add [0x43], 0x000F
	and [0x44], 0x0003
	add [0x44], 0x0007
