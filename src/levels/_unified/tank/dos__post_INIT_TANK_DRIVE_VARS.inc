LABEL_1323:
	break
	break
	break
	video offset=CINEMATIC_038, x=6, y=126
	break
	video offset=CINEMATIC_038, x=221, y=109
	break
	video offset=CINEMATIC_038, x=486, y=102, zoom=0x40
	killChannel

LABEL_1336:
	video offset=CINEMATIC_038, x=6, y=126
	setup channel=0x01, address=LABEL_001F
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	break
	selectVideoPage 0x00
	call DRAW_CIN_6_AND_RET
	video offset=CINEMATIC_000, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_038, x=221, y=109
	break
	video offset=CINEMATIC_038, x=486, y=102, zoom=0x40
	killChannel
	break
	break
	break
	video offset=CINEMATIC_038, x=73, y=56
	break
	video offset=CINEMATIC_038, x=266, y=79, zoom=0x40
	break
	video offset=CINEMATIC_038, x=576, y=91, zoom=0x40
	killChannel

LABEL_136E:
	mov [0x52], 0x017C
	mov [0x53], 0x0075
	mov [HACK_VAR_54], 0x0040
	mov [0x55], 0x0008

LABEL_137E:
	video offset=CINEMATIC_039, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0004
	video offset=CINEMATIC_040, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0002
	video offset=CINEMATIC_041, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_042, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_043, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_044, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_045, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_046, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_047, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0048
	djnz [0x55], LABEL_137E
	mov [0x55], 0x001E

DELAY_LOOP_VAR55:
	break
	djnz [0x55], DELAY_LOOP_VAR55
	jmp LABEL_136E
	killChannel

LABEL_13DA:
	mov [0x52], 0x017C
	mov [0x53], 0x0075
	mov [HACK_VAR_54], 0x0040
	mov [0x55], 0x0008

LABEL_13EA:
	sub [0x52], 0x0004
	video offset=CINEMATIC_040, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0002
	video offset=CINEMATIC_042, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_277, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_045, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_047, x=[0x52], y=[0x53], zoom=[0x54]
	sub [0x52], 0x0048
	break
	djnz [0x55], LABEL_13EA
	jmp LABEL_13DA
LABEL_1420:
	db 0x11

LABEL_1421:
	break
	jle [0x37], 0x00, LABEL_1421
	sub [0x37], 0x0001
	mov [0x39], 0x00A0
	mov [0x3A], 0x0064
	mov [0x38], 0x0000
	mov [0x3B], 0x0006

LABEL_143C:
	break
	call LABEL_14B5
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_14CC
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_14E3
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_14FA
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_1511
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call LABEL_1528
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_1511
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_14FA
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_14E3
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_14CC
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call LABEL_14B5
	call APPLY_HERO_DAMAGE_AND_HIT
	jmp LABEL_143C
LABEL_14B4:
	db 0x11

LABEL_14B5:
	video offset=CINEMATIC_150, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_151, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_14CC:
	video offset=CINEMATIC_152, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_153, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_14E3:
	video offset=CINEMATIC_154, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_155, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_14FA:
	video offset=CINEMATIC_156, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_157, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_1511:
	video offset=CINEMATIC_158, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_159, x=[0x39], y=[0x3a], zoom=0x40
	ret

LABEL_1528:
	video offset=CINEMATIC_160, x=[0x39], y=[0x3a], zoom=0x40
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_161, x=[0x39], y=[0x3a], zoom=0x40
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
