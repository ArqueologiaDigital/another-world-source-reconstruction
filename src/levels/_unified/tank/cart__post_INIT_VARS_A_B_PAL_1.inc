LABEL_1B95:
	add [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_1B95
	mov [0x0B], 0x0032

LABEL_1BA2:
	sub [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_1BA2
	jmp INIT_VARS_A_B_PAL_1
LABEL_1BAE:
	db 0x11

LABEL_1BAF:
	je [0x6D], 0x01, SHARED_RET
	selectVideoPage 0x03
	fill page=0x03, color=0x0C
	video offset=CINEMATIC_060, x=160, y=100
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_CIN_064_065_FIELD
	call DRAW_CIN_069
	selectVideoPage 0xFF
	ret

LABEL_1BCA:
	selectVideoPage 0x00
	call LABEL_1BD7
	selectVideoPage 0x03
	call LABEL_1BD7
	selectVideoPage 0xFF
	ret

LABEL_1BD7:
	video offset=CINEMATIC_069, x=160, y=100
	video offset=CINEMATIC_098, x=160, y=100
	je [0xDB], 0x01, SHARED_RET
	video offset=CINEMATIC_099, x=160, y=100
	ret

BLACKHOLE_FRAME_DRAW:
	jne [0x6D], 0x00, LABEL_1C0E
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_060, x=160, y=100
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_CIN_091_061_FIELD
	call DRAW_CIN_069
	selectVideoPage 0xFF
	ret

LABEL_1C05:
	call BLACKHOLE_FRAME_DRAW
	copyVideoPage src=0x03, dst=0xFF
	jmp INIT_VARS_A_B_PAL_1

LABEL_1C0E:
	mov [SCROLL_Y], 0xFF9C
	copyVideoPage src=0x83, dst=0x00
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0x03
	call DRAW_CIN_SEQ_068_068_068
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0xFF
	video offset=CINEMATIC_089, x=[0x0f], y=[0x10]
	video offset=CINEMATIC_090, x=160, y=90
	copyVideoPage src=0xFF, dst=0x00
	selectVideoPage 0x00
	call DRAW_CIN_069
	selectVideoPage 0x03
	call DRAW_CIN_069
	selectVideoPage 0xFF
	ret

DRAW_CIN_069:
	video offset=CINEMATIC_069, x=160, y=100
	ret
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_060, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_CIN_091_061_FIELD
	call DRAW_CIN_069
	selectVideoPage 0x03
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_CIN_064_065_FIELD
	call DRAW_CIN_069
	selectVideoPage 0xFF
	ret

DRAW_CIN_186_THEN_CIN_187:
	video offset=CINEMATIC_186, x=[0x0f], y=[0x10]
	video offset=CINEMATIC_187, x=[0x0f], y=[0x10]
	ret

LABEL_1C6E:
	selectVideoPage 0x00
	video offset=CINEMATIC_196, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	ret

LABEL_1C78:
	selectVideoPage 0x00
	video offset=CINEMATIC_193, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	jg [HACK_VAR_67], 0x02, SHARED_RET
	mov [HACK_VAR_67], 0x0002
	ret

LABEL_1C8C:
	jge [HACK_VAR_67], 0x03, SHARED_RET
	selectVideoPage 0x00
	video offset=CINEMATIC_192, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	mov [HACK_VAR_67], 0x0003
	ret

DRAW_CIN_093_TO_097_VAR:
	video offset=CINEMATIC_093, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_094, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_095, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_096, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_097, x=[0x01], y=[0x02], zoom=[0x03]
	ret

DRAW_CIN_061_HORIZ_THEN_062:
	video offset=CINEMATIC_061, x=114, y=22
	video offset=CINEMATIC_061, x=86, y=21
	video offset=CINEMATIC_061, x=53, y=21
	video offset=CINEMATIC_061, x=21, y=21
	video offset=CINEMATIC_061, x=1, y=21
	video offset=CINEMATIC_062, x=68, y=21
	video offset=CINEMATIC_062, x=100, y=21
	video offset=CINEMATIC_062, x=47, y=22
	video offset=CINEMATIC_062, x=23, y=20
	video offset=CINEMATIC_062, x=0, y=20
	video offset=CINEMATIC_063, x=87, y=23
	video offset=CINEMATIC_063, x=62, y=20
	video offset=CINEMATIC_063, x=49, y=21
	video offset=CINEMATIC_063, x=24, y=21
	video offset=CINEMATIC_063, x=2, y=23
	video offset=CINEMATIC_063, x=115, y=14
	video offset=CINEMATIC_063, x=75, y=31
	video offset=CINEMATIC_063, x=42, y=31
	video offset=CINEMATIC_063, x=28, y=38
	video offset=CINEMATIC_063, x=96, y=20
	ret
	killChannel
	video offset=CINEMATIC_061, x=114, y=22
	video offset=CINEMATIC_061, x=86, y=21
	video offset=CINEMATIC_061, x=53, y=21
	break
	video offset=CINEMATIC_061, x=21, y=21
	video offset=CINEMATIC_061, x=1, y=21
	video offset=CINEMATIC_062, x=68, y=21
	break
	video offset=CINEMATIC_062, x=100, y=21
	video offset=CINEMATIC_062, x=47, y=22
	video offset=CINEMATIC_062, x=23, y=20
	break
	video offset=CINEMATIC_062, x=0, y=20
	video offset=CINEMATIC_063, x=87, y=23
	video offset=CINEMATIC_063, x=62, y=20
	break
	video offset=CINEMATIC_063, x=49, y=21
	video offset=CINEMATIC_063, x=24, y=21
	video offset=CINEMATIC_063, x=2, y=23
	break
	video offset=CINEMATIC_063, x=115, y=14
	video offset=CINEMATIC_063, x=75, y=31
	break
	video offset=CINEMATIC_063, x=42, y=31
	video offset=CINEMATIC_063, x=28, y=38
	video offset=CINEMATIC_063, x=96, y=20
	killChannel

DRAW_CIN_091_061_FIELD:
	video offset=CINEMATIC_091, x=299, y=37
	video offset=CINEMATIC_091, x=289, y=23
	video offset=CINEMATIC_061, x=205, y=21
	video offset=CINEMATIC_061, x=187, y=27
	video offset=CINEMATIC_061, x=247, y=25
	video offset=CINEMATIC_061, x=167, y=20
	video offset=CINEMATIC_061, x=142, y=21
	video offset=CINEMATIC_061, x=228, y=22
	video offset=CINEMATIC_061, x=279, y=21
	video offset=CINEMATIC_061, x=310, y=20
	video offset=CINEMATIC_062, x=186, y=24
	video offset=CINEMATIC_062, x=207, y=21
	video offset=CINEMATIC_062, x=161, y=22
	video offset=CINEMATIC_062, x=240, y=21
	video offset=CINEMATIC_062, x=303, y=18
	video offset=CINEMATIC_062, x=140, y=20
	video offset=CINEMATIC_062, x=242, y=22
	video offset=CINEMATIC_062, x=224, y=21
	video offset=CINEMATIC_062, x=287, y=21
	video offset=CINEMATIC_062, x=259, y=27
	video offset=CINEMATIC_062, x=140, y=20
	video offset=CINEMATIC_063, x=164, y=23
	video offset=CINEMATIC_063, x=198, y=21
	video offset=CINEMATIC_063, x=216, y=25
	video offset=CINEMATIC_063, x=147, y=24
	video offset=CINEMATIC_063, x=302, y=17
	video offset=CINEMATIC_063, x=273, y=21
	video offset=CINEMATIC_063, x=255, y=21
	video offset=CINEMATIC_063, x=222, y=18
	video offset=CINEMATIC_063, x=134, y=21
	video offset=CINEMATIC_063, x=114, y=23
	video offset=CINEMATIC_063, x=190, y=20
	video offset=CINEMATIC_063, x=245, y=23
	video offset=CINEMATIC_063, x=294, y=19
	video offset=CINEMATIC_092, x=211, y=26
	video offset=CINEMATIC_092, x=196, y=19
	video offset=CINEMATIC_092, x=156, y=17
	video offset=CINEMATIC_092, x=141, y=28
	video offset=CINEMATIC_092, x=124, y=23
	video offset=CINEMATIC_092, x=182, y=13
	video offset=CINEMATIC_092, x=221, y=17
	video offset=CINEMATIC_092, x=257, y=18
	video offset=CINEMATIC_092, x=242, y=18
	video offset=CINEMATIC_092, x=295, y=21
	video offset=CINEMATIC_092, x=303, y=19
	video offset=CINEMATIC_092, x=280, y=17
	video offset=CINEMATIC_092, x=87, y=20
	video offset=CINEMATIC_092, x=107, y=22
	video offset=CINEMATIC_092, x=35, y=17
	video offset=CINEMATIC_092, x=61, y=18
	video offset=CINEMATIC_092, x=0, y=21
	video offset=CINEMATIC_092, x=10, y=21
	ret

DRAW_CIN_SEQ_068_068_068:
	video offset=CINEMATIC_068, x=156, y=17
	video offset=CINEMATIC_068, x=141, y=28
	video offset=CINEMATIC_068, x=110, y=23
	video offset=CINEMATIC_068, x=188, y=15
	ret
LABEL_1E58:
	db 0x11

DRAW_CIN_064_065_FIELD:
	video offset=CINEMATIC_064, x=299, y=37
	video offset=CINEMATIC_064, x=289, y=23
	video offset=CINEMATIC_065, x=205, y=21
	video offset=CINEMATIC_065, x=187, y=27
	video offset=CINEMATIC_065, x=247, y=25
	video offset=CINEMATIC_065, x=167, y=20
	video offset=CINEMATIC_065, x=142, y=21
	video offset=CINEMATIC_065, x=228, y=22
	video offset=CINEMATIC_065, x=279, y=21
	video offset=CINEMATIC_065, x=310, y=20
	video offset=CINEMATIC_066, x=186, y=24
	video offset=CINEMATIC_066, x=207, y=21
	video offset=CINEMATIC_066, x=161, y=22
	video offset=CINEMATIC_066, x=240, y=21
	video offset=CINEMATIC_066, x=303, y=18
	video offset=CINEMATIC_066, x=140, y=20
	video offset=CINEMATIC_066, x=242, y=22
	video offset=CINEMATIC_066, x=224, y=21
	video offset=CINEMATIC_066, x=287, y=21
	video offset=CINEMATIC_066, x=259, y=27
	video offset=CINEMATIC_066, x=140, y=20
	video offset=CINEMATIC_067, x=164, y=23
	video offset=CINEMATIC_067, x=198, y=21
	video offset=CINEMATIC_067, x=216, y=25
	video offset=CINEMATIC_067, x=147, y=24
	video offset=CINEMATIC_067, x=302, y=17
	video offset=CINEMATIC_067, x=273, y=21
	video offset=CINEMATIC_067, x=255, y=21
	video offset=CINEMATIC_067, x=222, y=18
	video offset=CINEMATIC_067, x=134, y=21
	video offset=CINEMATIC_067, x=114, y=23
	video offset=CINEMATIC_067, x=190, y=20
	video offset=CINEMATIC_067, x=245, y=23
	video offset=CINEMATIC_067, x=294, y=19
	video offset=CINEMATIC_068, x=211, y=26
	video offset=CINEMATIC_068, x=196, y=19
	video offset=CINEMATIC_068, x=156, y=17
	video offset=CINEMATIC_068, x=141, y=28
	video offset=CINEMATIC_068, x=124, y=23
	video offset=CINEMATIC_068, x=182, y=13
	video offset=CINEMATIC_068, x=221, y=17
	video offset=CINEMATIC_068, x=257, y=18
	video offset=CINEMATIC_068, x=242, y=18
	video offset=CINEMATIC_068, x=295, y=21
	video offset=CINEMATIC_068, x=303, y=19
	video offset=CINEMATIC_068, x=280, y=17
	video offset=CINEMATIC_068, x=87, y=20
	video offset=CINEMATIC_068, x=107, y=22
	video offset=CINEMATIC_068, x=35, y=17
	video offset=CINEMATIC_068, x=61, y=18
	video offset=CINEMATIC_068, x=0, y=21
	video offset=CINEMATIC_068, x=10, y=21
	ret

HANG_BLITTING_PAGE_FF:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp HANG_BLITTING_PAGE_FF

JUNK__1F43:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__1F43

BLITTER_LOOP_COPY_PAGE_03:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	call SUM_HASH_VARS_TO_VAR_64
	break
	jmp BLITTER_LOOP_COPY_PAGE_03
LABEL_1F59:
	db 0x11

PALETTE_FLASH_1F_TO_01:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0002
	setPalette 0x1F
	blitFramebuffer 0xFE
	setPalette 0x01
	blitFramebuffer 0xFE
	mov [PAUSE_SLICES], 0x0006
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_03
LABEL_1F77:
	db 0x11
