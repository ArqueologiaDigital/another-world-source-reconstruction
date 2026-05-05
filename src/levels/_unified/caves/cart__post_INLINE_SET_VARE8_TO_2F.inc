LABEL_3703:
	sub [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_3729
	break
	djnz [0xE8], LABEL_3703
	mov [0xE8], 0x002F

LABEL_3716:
	add [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_3729
	break
	djnz [0xE8], LABEL_3716
	jmp INLINE_SET_VARE8_TO_2F
LABEL_3728:
	db 0x11

LABEL_3729:
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	sub [0x21], 0x0064
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	add [0x21], 0x00AA
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	ret
LABEL_3741:
	db 0x11

LABEL_3742:
	setup channel=0x06, address=INIT_VARS_EB_EC_ED
	selectVideoPage 0x03
	video offset=CINEMATIC_815, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_816, x=160, y=100
	break
	video offset=CINEMATIC_817, x=160, y=100
	break
	video offset=CINEMATIC_818, x=160, y=100
	break
	video offset=CINEMATIC_819, x=160, y=100
	break
	video offset=CINEMATIC_820, x=160, y=100
	break
	video offset=CINEMATIC_819, x=160, y=100
	selectVideoPage 0x03
	video offset=CINEMATIC_821, x=169, y=136
	video offset=CINEMATIC_821, x=169, y=160
	selectVideoPage 0xFF
	killChannel

LABEL_3778:
	mov [0x6B], 0x0001
	song id=0x0BC7, delay=0x0000, pos=0x00

DELAY_LOOP_VAR6B:
	break
	djnz [0x6B], DELAY_LOOP_VAR6B
	mov [0x6B], 0x0003
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x05, address=LABEL_3742

DELAY_LOOP_VAR6B_AT_3793:
	break
	djnz [0x6B], DELAY_LOOP_VAR6B_AT_3793
	mov [0x6C], 0x0003
	mov [0x6D], 0x0003
	setup channel=0x07, address=LABEL_369E
	mov [0x6B], 0x0011

LABEL_37A8:
	mov [0x09], 0x008A
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0xFFEC
	add [0x07], [0x21]
	call LABEL_36C2
	call LABEL_363A
	call LABEL_35EF
	break
	add [0x6C], 0x0001
	djnz [0x6B], LABEL_37A8
	mov [0x6C], 0x0064
	mov [0x6B], 0x0016
	play id=0x006C, freq=0x14, vol=0x20, channel=0x02

LABEL_37D6:
	mov [0x09], 0x0089
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00A0
	add [0x07], [0x21]
	call LABEL_36C2
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	mov [0x09], 0x008A
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0xFF4C
	add [0x07], [0x21]
	call LABEL_36C2
	call LABEL_363A
	call LABEL_35EF
	break
	add [0x6C], 0x0001
	djnz [0x6B], LABEL_37D6
	mov [0x6C], 0x0078
	mov [0x6B], 0x0014
	play id=0x006C, freq=0x0F, vol=0x20, channel=0x02

LABEL_381B:
	mov [0x09], 0x0089
	mov [0x07], 0x009D
	mov [0x08], 0x00B0
	call LABEL_363A
	break
	add [0x6C], 0x0001
	djnz [0x6B], LABEL_381B
	mov [0x6B], 0x0007

LABEL_3837:
	mov [0x09], 0x0089
	mov [0x07], 0x008F
	mov [0x08], 0x00B0
	add [0x07], [0x6B]
	add [0x07], [0x6B]
	call LABEL_363A
	mov [0x07], 0x0073
	mov [0x08], 0x00C8
	mov [0x21], [0x6B]
	shl [0x21], 0x0003
	add [0x08], [0x21]
	call GUARDED_DRAW_CIN_589_801
	mov [0x09], 0x0088
	mov [0x07], 0x0104
	mov [0x08], 0x00AF
	mov [0x21], [0x6B]
	shl [0x21], 0x0003
	add [0x08], [0x21]
	shr [0x21], 0x0001
	sub [0x07], [0x21]
	call GUARDED_DRAW_CIN_589_801
	mov [0x07], 0x00F0
	add [0x07], [0x21]
	add [0x07], [0x21]
	call GUARDED_DRAW_CIN_589_801
	break
	djnz [0x6B], LABEL_3837
	mov [0x6C], 0x0096
	mov [0x6B], 0x0007

LABEL_389B:
	mov [0x09], 0x0089
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x0044
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call LABEL_36C2
	add [0x08], 0x0005
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	mov [0x09], 0x0088
	mov [0x07], 0x00BC
	mov [0x08], 0x00C8
	mov [0x21], [0x6B]
	shl [0x21], 0x0003
	add [0x08], [0x21]
	call GUARDED_DRAW_CIN_589_801
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00AB
	add [0x07], [0x21]
	mov [0x08], 0x00A9
	call LABEL_36C2
	add [0x08], 0x0008
	jg [0x07], 0xE2, LABEL_38F6
	mov [0x07], 0x00E2
	mov [0x08], 0x00B4

LABEL_38F6:
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x0154
	sub [0x07], [0x21]
	mov [0x08], 0x00A7
	call LABEL_36C2
	add [0x08], 0x0009
	call LABEL_3593
	call GUARDED_DRAW_CIN_589_801
	break
	add [0x6C], 0x0001
	djnz [0x6B], LABEL_389B
	mov [0x6B], 0x0015

LABEL_3924:
	mov [0x09], 0x0089
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0xFF67
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call LABEL_36C2
	add [0x08], 0x0005
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	mov [0x09], 0x0088
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0xFFF6
	add [0x07], [0x21]
	mov [0x08], 0x00A8
	call LABEL_36C2
	add [0x08], 0x0008
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	add [0x07], 0x008C
	mov [0x08], 0x00A8
	call LABEL_36C2
	add [0x08], 0x0007
	call GUARDED_DRAW_CIN_589_801
	break
	add [0x6C], 0x0001
	djnz [0x6B], LABEL_3924
	mov [0x6B], 0x0028

LABEL_3981:
	mov [0x09], 0x0087
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0xFF9C
	add [0x07], [0x21]
	mov [0x08], 0x0064
	call LABEL_36C2
	jg [0x07], 0x0116, LABEL_39A5
	mov [0x07], 0x010C
	mov [0x08], 0x00B4

LABEL_39A5:
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	jle [0x01], 0x8C, INIT_VARS_6C_6B
	break
	djnz [0x6B], LABEL_3981
