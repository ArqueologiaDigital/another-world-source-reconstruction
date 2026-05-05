LABEL_2A12:
	mov [0x9F], [0x8B]
	mov [0x8E], [0x8C]
	mov [0x8F], [0x8D]
	break
	jmp LABEL_2A12

LABEL_2A1F:
	break
	jg [HERO_X], 0x78, LABEL_2A1F
	call LABEL_53FF
	je [0x21], 0x00, LABEL_2A1F
	mov [0x9C], 0x0320
	mov [0x9D], 0x0320
	killChannel

LABEL_2A38:
	break
	jg [HERO_X], 0x64, LABEL_2A38
	jl [0x7B], 0x4000, LABEL_2A38
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFFE2
	add [0x21], [0x3A]
	mov [0x27], 0x0082
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B78
	break
	jmp LABEL_2A38
	jge [0x04], 0x4000, KILL_CHAN_AT_157F
	killChannel

LABEL_2A6E:
	jg [HACK_VAR_67], 0x4D, LABEL_2AAF
	jl [HACK_VAR_67], 0x4B, LABEL_2BB6
	jl [0x73], 0x4000, LABEL_2A93
	je [0xB0], 0x00, LABEL_2A8A
	call LABEL_3385

LABEL_2A8A:
	je [0xB1], 0x00, LABEL_2A93
	call LABEL_3385

LABEL_2A93:
	jl [0x7B], 0x4000, LABEL_2BB6
	je [0xB2], 0x00, LABEL_2AA3
	call LABEL_3364

LABEL_2AA3:
	je [0xB3], 0x00, LABEL_2BB6
	call LABEL_3364
	jmp LABEL_2BB6

LABEL_2AAF:
	jne [HACK_VAR_67], 0x8D, LABEL_2ACF
	mov [0xF8], [0xB4]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_2BB6
	or [0xB4], 0x0001
	call LABEL_33A6
	call LABEL_33C7
	jmp LABEL_2BB6

LABEL_2ACF:
	jne [HACK_VAR_67], 0xEC, LABEL_2B05
	mov [0xF8], [0xB4]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, LABEL_2AED
	jl [0x73], 0x4000, LABEL_2AED
	or [0xB4], 0x0008

LABEL_2AED:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_2BB6
	jl [0x7B], 0x4000, LABEL_2BB6
	or [0xB4], 0x0010

LABEL_2B05:
	jne [HACK_VAR_67], 0xAA, LABEL_2B57
	jg [0x71], 0x78, LABEL_2B31
	jne [0x72], 0xAA, LABEL_2B31
	mov [0xF8], [0xB4]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, LABEL_2B31
	call LABEL_01D2
	je [0x21], 0x00, LABEL_2B31
	or [0xB4], 0x0004

LABEL_2B31:
	jl [0x79], 0x78, LABEL_2BB6
	jne [0x7A], 0xAA, LABEL_2BB6
	mov [0xF8], [0xB4]
	and [0xF8], 0x0020
	jne [0xF8], 0x00, LABEL_2BB6
	call LABEL_01EF
	je [0x21], 0x00, LABEL_2BB6
	or [0xB4], 0x0020

LABEL_2B57:
	jne [HACK_VAR_67], 0x8A, LABEL_2B80
	jne [0x7A], 0x8A, LABEL_2BB6
	mov [0xF8], [0xB4]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_2BB6
	call LABEL_01EF
	je [0x21], 0x00, LABEL_2BB6
	or [0xB4], 0x0002
	jmp LABEL_2BB6

LABEL_2B80:
	jne [HACK_VAR_67], 0x6B, LABEL_2BB6
	mov [0xF8], [0xB4]
	and [0xF8], 0x0040
	jne [0xF8], 0x00, LABEL_2B9E
	jl [0x73], 0x4000, LABEL_2B9E
	or [0xB4], 0x0040

LABEL_2B9E:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, LABEL_2BB6
	jl [0x7B], 0x4000, LABEL_2BB6
	or [0xB4], 0x0080

LABEL_2BB6:
	break
	jmp LABEL_2A6E
LABEL_2BBA:
	db 0x11

LABEL_2BBB:
	video offset=CINEMATIC_440, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_441, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_442, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_443, x=160, y=[0xe7]
	killChannel

LABEL_2BD3:
	video offset=CINEMATIC_440, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_441, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_442, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_443, x=160, y=[0xe8]
	killChannel
	mov [0xE6], 0x001E

DELAY_LOOP_VARE6_AT_2BEF:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2BEF
	mov [0xE7], 0x00AA
	setup channel=0x36, address=LABEL_2BBB
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_2C00:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C00
	mov [0xE7], 0x0064
	setup channel=0x36, address=LABEL_2BBB
	mov [0xE6], 0x0002
	or [0xB1], 0x0020

DELAY_LOOP_VARE6_AT_2C15:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C15
	mov [0xE8], 0x0082
	setup channel=0x39, address=LABEL_2BD3
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_2C26:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C26
	setup channel=0x38, address=LABEL_2CB8
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2BBB
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_2BD3
	break
	break
	mov [0xE7], 0x0096
	setup channel=0x39, address=LABEL_2BBB
	break
	break
	mov [0xE6], 0x0007

DELAY_LOOP_VARE6_AT_2C54:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C54
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2BBB
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_2C65:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C65
	mov [0xE8], 0x0064
	setup channel=0x39, address=LABEL_2BD3
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2BBB
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_2BD3
	break
	break
	mov [0xE7], 0x0064
	setup channel=0x39, address=LABEL_2BBB
	break
	break
	break
	setup channel=0x36, address=LABEL_2D82
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_2C9C:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2C9C
	setup channel=0x38, address=LABEL_2EBF
	break
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	break
	break
	break
	break
	setup channel=0x3A, address=LABEL_2E21
	break
	mov [0x74], 0x4018
	killChannel

LABEL_2CB8:
	video offset=CINEMATIC_444, x=65506, y=114
	video offset=CINEMATIC_445, x=65506, y=114
	break
	video offset=CINEMATIC_444, x=7, y=116
	video offset=CINEMATIC_446, x=7, y=116
	break
	video offset=CINEMATIC_444, x=43, y=120
	video offset=CINEMATIC_447, x=43, y=120
	break
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_448, x=75, y=121
	break
	video offset=CINEMATIC_444, x=119, y=116
	video offset=CINEMATIC_448, x=124, y=116
	break
	video offset=CINEMATIC_444, x=153, y=118
	video offset=CINEMATIC_447, x=153, y=118
	break
	video offset=CINEMATIC_444, x=190, y=120
	video offset=CINEMATIC_447, x=190, y=120
	break
	video offset=CINEMATIC_444, x=223, y=117
	video offset=CINEMATIC_446, x=223, y=117
	break
	video offset=CINEMATIC_444, x=266, y=112
	video offset=CINEMATIC_445, x=266, y=112
	break
	video offset=CINEMATIC_444, x=301, y=114
	video offset=CINEMATIC_446, x=301, y=114
	break
	video offset=CINEMATIC_444, x=331, y=114
	video offset=CINEMATIC_447, x=331, y=114
	break
	killChannel
	video offset=CINEMATIC_444, x=65506, y=114
	break
	video type=0, offset=COMMON_VIDEO_246, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_249, x=180, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_252, x=200, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_255, x=220, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_259, x=240, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_261, x=260, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_243, x=280, y=100, zoom=0x40
	break
	video offset=CINEMATIC_444, x=121, y=118
	break
	video offset=CINEMATIC_444, x=154, y=120
	break
	video offset=CINEMATIC_444, x=186, y=116
	break
	video offset=CINEMATIC_444, x=219, y=112
	break
	video offset=CINEMATIC_444, x=251, y=114
	break
	video offset=CINEMATIC_444, x=281, y=116
	break
	video offset=CINEMATIC_444, x=310, y=117
	break
	video offset=CINEMATIC_444, x=329, y=118
	break
	video offset=CINEMATIC_444, x=352, y=114
	killChannel

LABEL_2D82:
	video offset=CINEMATIC_444, x=65506, y=114
	video offset=CINEMATIC_445, x=65506, y=114
	video offset=CINEMATIC_449, x=65506, y=114
	break
	video offset=CINEMATIC_444, x=7, y=116
	video offset=CINEMATIC_446, x=7, y=116
	video offset=CINEMATIC_449, x=7, y=116
	break
	video offset=CINEMATIC_444, x=43, y=120
	video offset=CINEMATIC_447, x=43, y=120
	video offset=CINEMATIC_449, x=43, y=120
	break
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_448, x=75, y=121
	video offset=CINEMATIC_449, x=75, y=121
	break
	video offset=CINEMATIC_444, x=119, y=116
	video offset=CINEMATIC_448, x=124, y=116
	video offset=CINEMATIC_449, x=119, y=116
	break
	video offset=CINEMATIC_444, x=153, y=118
	video offset=CINEMATIC_447, x=153, y=118
	video offset=CINEMATIC_449, x=153, y=118
	break
	video offset=CINEMATIC_444, x=190, y=120
	video offset=CINEMATIC_447, x=190, y=120
	video offset=CINEMATIC_449, x=190, y=120
	break
	video offset=CINEMATIC_444, x=223, y=117
	video offset=CINEMATIC_446, x=223, y=117
	video offset=CINEMATIC_449, x=223, y=117
	break
	video offset=CINEMATIC_444, x=266, y=112
	video offset=CINEMATIC_445, x=266, y=112
	video offset=CINEMATIC_449, x=266, y=112
	break
	video offset=CINEMATIC_444, x=301, y=114
	video offset=CINEMATIC_446, x=301, y=114
	video offset=CINEMATIC_449, x=301, y=114
	break
	video offset=CINEMATIC_444, x=331, y=114
	video offset=CINEMATIC_447, x=331, y=114
	video offset=CINEMATIC_449, x=331, y=114
	break
	killChannel

LABEL_2E21:
	video offset=CINEMATIC_444, x=65506, y=114
	video offset=CINEMATIC_445, x=65506, y=114
	video offset=CINEMATIC_450, x=65506, y=114
	break
	video offset=CINEMATIC_444, x=7, y=116
	video offset=CINEMATIC_446, x=7, y=116
	video offset=CINEMATIC_450, x=7, y=116
	break
	video offset=CINEMATIC_444, x=43, y=120
	video offset=CINEMATIC_447, x=43, y=120
	video offset=CINEMATIC_450, x=43, y=120
	break
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_448, x=75, y=121
	video offset=CINEMATIC_450, x=75, y=121
	break
	video offset=CINEMATIC_444, x=119, y=116
	video offset=CINEMATIC_448, x=124, y=116
	video offset=CINEMATIC_450, x=119, y=116
	break
	video offset=CINEMATIC_444, x=153, y=118
	video offset=CINEMATIC_447, x=153, y=118
	video offset=CINEMATIC_450, x=153, y=118
	break
	video offset=CINEMATIC_444, x=190, y=120
	video offset=CINEMATIC_447, x=190, y=120
	video offset=CINEMATIC_450, x=190, y=120
	break
	video offset=CINEMATIC_444, x=223, y=117
	video offset=CINEMATIC_446, x=223, y=117
	video offset=CINEMATIC_450, x=223, y=117
	break
	video offset=CINEMATIC_444, x=266, y=112
	video offset=CINEMATIC_445, x=266, y=112
	video offset=CINEMATIC_450, x=266, y=112
	break
	video offset=CINEMATIC_444, x=301, y=114
	video offset=CINEMATIC_446, x=301, y=114
	video offset=CINEMATIC_450, x=301, y=114
	break
	video offset=CINEMATIC_444, x=331, y=114
	video offset=CINEMATIC_447, x=331, y=114
	video offset=CINEMATIC_450, x=331, y=114
	killChannel

LABEL_2EBF:
	video offset=CINEMATIC_444, x=65506, y=114
	video offset=CINEMATIC_445, x=65506, y=114
	video offset=CINEMATIC_451, x=65506, y=114
	break
	video offset=CINEMATIC_444, x=7, y=116
	video offset=CINEMATIC_446, x=7, y=116
	video offset=CINEMATIC_451, x=7, y=116
	break
	video offset=CINEMATIC_444, x=43, y=120
	video offset=CINEMATIC_447, x=43, y=120
	video offset=CINEMATIC_451, x=43, y=120
	break
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_448, x=75, y=121
	video offset=CINEMATIC_451, x=75, y=121
	break
	video offset=CINEMATIC_444, x=119, y=116
	video offset=CINEMATIC_448, x=124, y=116
	video offset=CINEMATIC_451, x=119, y=116
	break
	video offset=CINEMATIC_444, x=153, y=118
	video offset=CINEMATIC_447, x=153, y=118
	video offset=CINEMATIC_451, x=153, y=118
	break
	video offset=CINEMATIC_444, x=190, y=120
	video offset=CINEMATIC_447, x=190, y=120
	video offset=CINEMATIC_451, x=190, y=120
	break
	video offset=CINEMATIC_444, x=223, y=117
	video offset=CINEMATIC_446, x=223, y=117
	video offset=CINEMATIC_451, x=223, y=117
	break
	video offset=CINEMATIC_444, x=266, y=112
	video offset=CINEMATIC_445, x=266, y=112
	video offset=CINEMATIC_451, x=266, y=112
	break
	video offset=CINEMATIC_444, x=301, y=114
	video offset=CINEMATIC_446, x=301, y=114
	video offset=CINEMATIC_451, x=301, y=114
	break
	video offset=CINEMATIC_444, x=331, y=114
	video offset=CINEMATIC_447, x=331, y=114
	video offset=CINEMATIC_451, x=331, y=114
	killChannel

LABEL_2F5D:
	setPalette 0x11
	jl [HERO_X], 0xAE, LABEL_2F6F
	jg [HERO_X], 0xE1, LABEL_2F6F
	setPalette 0x09

LABEL_2F6F:
	break
	jmp LABEL_2F5D
	killChannel

LABEL_2F74:
	break
	jl [HERO_X], 0x7A, LABEL_2F74
	jg [HERO_X], 0xA1, LABEL_2F74
	jl [HERO_Y], 0x96, LABEL_2F74
	jg [HERO_Y], 0xCE, LABEL_2F74
	mov [HERO_Y], 0x00B4
	jmp INCREMENT_VAR31
	killChannel

LABEL_2F95:
	break
	jl [HERO_Y], 0x46, LABEL_2F95
	mov [HERO_Y], 0x006E
	jmp INCREMENT_VAR31
LABEL_2FA3:
	db 0x11
