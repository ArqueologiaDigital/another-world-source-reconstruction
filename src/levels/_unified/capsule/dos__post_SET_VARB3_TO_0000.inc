LABEL_289B:
	mov [0x9F], [0x8B]
	mov [0x8E], [0x8C]
	mov [0x8F], [0x8D]
	break
	jmp LABEL_289B

LABEL_28A8:
	break
	jg [HERO_X], 0x78, LABEL_28A8
	call LABEL_5423
	je [0x21], 0x00, LABEL_28A8
	mov [0x9C], 0x0320
	mov [0x9D], 0x0320
	killChannel

LABEL_28C1:
	break
	jg [HERO_X], 0x64, LABEL_28C1
	jl [0x7B], 0x4000, LABEL_28C1
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFFE2
	add [0x21], [0x3A]
	mov [0x27], 0x0082
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B75
	break
	jmp LABEL_28C1
	jge [0x04], 0x4000, KILL_CHAN_AT_1471
	killChannel

LABEL_28F7:
	jg [HACK_VAR_67], 0x4D, LABEL_2938
	jl [HACK_VAR_67], 0x4B, LABEL_2A39
	jl [0x73], 0x4000, LABEL_291C
	je [0xB0], 0x00, LABEL_2913
	call LABEL_31F6

LABEL_2913:
	je [0xB1], 0x00, LABEL_291C
	call LABEL_31F6

LABEL_291C:
	jl [0x7B], 0x4000, LABEL_2A39
	je [0xB2], 0x00, LABEL_292C
	call LABEL_31D5

LABEL_292C:
	je [0xB3], 0x00, LABEL_2A39
	call LABEL_31D5
	jmp LABEL_2A39

LABEL_2938:
	jne [HACK_VAR_67], 0x8D, LABEL_2958
	mov [0xF8], [0xB4]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_2A39
	or [0xB4], 0x0001
	call LABEL_3217
	call LABEL_3238
	jmp LABEL_2A39

LABEL_2958:
	jne [HACK_VAR_67], 0xEC, LABEL_298E
	mov [0xF8], [0xB4]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, LABEL_2976
	jl [0x73], 0x4000, LABEL_2976
	or [0xB4], 0x0008

LABEL_2976:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_2A39
	jl [0x7B], 0x4000, LABEL_2A39
	or [0xB4], 0x0010

LABEL_298E:
	jne [HACK_VAR_67], 0xAA, LABEL_29DC
	jg [0x71], 0x78, LABEL_29B8
	jne [0x72], 0xAA, LABEL_29B8
	mov [0xF8], [0xB4]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, LABEL_29B8
	jl [0x73], 0x4000, LABEL_29B8
	or [0xB4], 0x0004

LABEL_29B8:
	jl [0x79], 0x78, LABEL_2A39
	jne [0x7A], 0xAA, LABEL_2A39
	mov [0xF8], [0xB4]
	and [0xF8], 0x0020
	jne [0xF8], 0x00, LABEL_2A39
	jl [0x7B], 0x4000, LABEL_2A39
	or [0xB4], 0x0020

LABEL_29DC:
	jne [HACK_VAR_67], 0x8A, LABEL_2A03
	jne [0x7A], 0x8A, LABEL_2A39
	mov [0xF8], [0xB4]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_2A39
	jl [0x7B], 0x4000, LABEL_2A39
	or [0xB4], 0x0002
	jmp LABEL_2A39

LABEL_2A03:
	jne [HACK_VAR_67], 0x6B, LABEL_2A39
	mov [0xF8], [0xB4]
	and [0xF8], 0x0040
	jne [0xF8], 0x00, LABEL_2A21
	jl [0x73], 0x4000, LABEL_2A21
	or [0xB4], 0x0040

LABEL_2A21:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, LABEL_2A39
	jl [0x7B], 0x4000, LABEL_2A39
	or [0xB4], 0x0080

LABEL_2A39:
	break
	jmp LABEL_28F7
LABEL_2A3D:
	db 0x11

LABEL_2A3E:
	video offset=CINEMATIC_436, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_437, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_438, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_439, x=160, y=[0xe7]
	killChannel

LABEL_2A56:
	video offset=CINEMATIC_436, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_437, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_438, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_439, x=160, y=[0xe8]
	killChannel
	mov [0xE6], 0x001E

DELAY_LOOP_VARE6_AT_2A72:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2A72
	mov [0xE7], 0x00AA
	setup channel=0x36, address=LABEL_2A3E
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_2A83:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2A83
	mov [0xE7], 0x0064
	setup channel=0x36, address=LABEL_2A3E
	mov [0xE6], 0x0002
	or [0xB1], 0x0020

DELAY_LOOP_VARE6_AT_2A98:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2A98
	mov [0xE8], 0x0082
	setup channel=0x39, address=LABEL_2A56
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_2AA9:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2AA9
	setup channel=0x38, address=LABEL_2B3B
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2A3E
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_2A56
	break
	break
	mov [0xE7], 0x0096
	setup channel=0x39, address=LABEL_2A3E
	break
	break
	mov [0xE6], 0x0007

DELAY_LOOP_VARE6_AT_2AD7:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2AD7
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2A3E
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_2AE8:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2AE8
	mov [0xE8], 0x0064
	setup channel=0x39, address=LABEL_2A56
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_2A3E
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_2A56
	break
	break
	mov [0xE7], 0x0064
	setup channel=0x39, address=LABEL_2A3E
	break
	break
	break
	setup channel=0x36, address=LABEL_2C05
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_2B1F:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2B1F
	setup channel=0x38, address=LABEL_2D42
	break
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	break
	break
	break
	break
	setup channel=0x3A, address=LABEL_2CA4
	break
	mov [0x74], 0x4018
	killChannel

LABEL_2B3B:
	video offset=CINEMATIC_440, x=65506, y=114
	video offset=CINEMATIC_441, x=65506, y=114
	break
	video offset=CINEMATIC_440, x=7, y=116
	video offset=CINEMATIC_442, x=7, y=116
	break
	video offset=CINEMATIC_440, x=43, y=120
	video offset=CINEMATIC_443, x=43, y=120
	break
	video offset=CINEMATIC_440, x=75, y=121
	video offset=CINEMATIC_444, x=75, y=121
	break
	video offset=CINEMATIC_440, x=119, y=116
	video offset=CINEMATIC_444, x=124, y=116
	break
	video offset=CINEMATIC_440, x=153, y=118
	video offset=CINEMATIC_443, x=153, y=118
	break
	video offset=CINEMATIC_440, x=190, y=120
	video offset=CINEMATIC_443, x=190, y=120
	break
	video offset=CINEMATIC_440, x=223, y=117
	video offset=CINEMATIC_442, x=223, y=117
	break
	video offset=CINEMATIC_440, x=266, y=112
	video offset=CINEMATIC_441, x=266, y=112
	break
	video offset=CINEMATIC_440, x=301, y=114
	video offset=CINEMATIC_442, x=301, y=114
	break
	video offset=CINEMATIC_440, x=331, y=114
	video offset=CINEMATIC_443, x=331, y=114
	break
	killChannel
	video offset=CINEMATIC_440, x=65506, y=114
	break
	video type=0, offset=COMMON_VIDEO_246, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_249, x=180, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_252, x=200, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_255, x=220, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_259, x=240, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_261, x=260, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_243, x=280, y=100, zoom=0x40
	break
	video offset=CINEMATIC_440, x=121, y=118
	break
	video offset=CINEMATIC_440, x=154, y=120
	break
	video offset=CINEMATIC_440, x=186, y=116
	break
	video offset=CINEMATIC_440, x=219, y=112
	break
	video offset=CINEMATIC_440, x=251, y=114
	break
	video offset=CINEMATIC_440, x=281, y=116
	break
	video offset=CINEMATIC_440, x=310, y=117
	break
	video offset=CINEMATIC_440, x=329, y=118
	break
	video offset=CINEMATIC_440, x=352, y=114
	killChannel

LABEL_2C05:
	video offset=CINEMATIC_440, x=65506, y=114
	video offset=CINEMATIC_441, x=65506, y=114
	video offset=CINEMATIC_445, x=65506, y=114
	break
	video offset=CINEMATIC_440, x=7, y=116
	video offset=CINEMATIC_442, x=7, y=116
	video offset=CINEMATIC_445, x=7, y=116
	break
	video offset=CINEMATIC_440, x=43, y=120
	video offset=CINEMATIC_443, x=43, y=120
	video offset=CINEMATIC_445, x=43, y=120
	break
	video offset=CINEMATIC_440, x=75, y=121
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_445, x=75, y=121
	break
	video offset=CINEMATIC_440, x=119, y=116
	video offset=CINEMATIC_444, x=124, y=116
	video offset=CINEMATIC_445, x=119, y=116
	break
	video offset=CINEMATIC_440, x=153, y=118
	video offset=CINEMATIC_443, x=153, y=118
	video offset=CINEMATIC_445, x=153, y=118
	break
	video offset=CINEMATIC_440, x=190, y=120
	video offset=CINEMATIC_443, x=190, y=120
	video offset=CINEMATIC_445, x=190, y=120
	break
	video offset=CINEMATIC_440, x=223, y=117
	video offset=CINEMATIC_442, x=223, y=117
	video offset=CINEMATIC_445, x=223, y=117
	break
	video offset=CINEMATIC_440, x=266, y=112
	video offset=CINEMATIC_441, x=266, y=112
	video offset=CINEMATIC_445, x=266, y=112
	break
	video offset=CINEMATIC_440, x=301, y=114
	video offset=CINEMATIC_442, x=301, y=114
	video offset=CINEMATIC_445, x=301, y=114
	break
	video offset=CINEMATIC_440, x=331, y=114
	video offset=CINEMATIC_443, x=331, y=114
	video offset=CINEMATIC_445, x=331, y=114
	break
	killChannel

LABEL_2CA4:
	video offset=CINEMATIC_440, x=65506, y=114
	video offset=CINEMATIC_441, x=65506, y=114
	video offset=CINEMATIC_446, x=65506, y=114
	break
	video offset=CINEMATIC_440, x=7, y=116
	video offset=CINEMATIC_442, x=7, y=116
	video offset=CINEMATIC_446, x=7, y=116
	break
	video offset=CINEMATIC_440, x=43, y=120
	video offset=CINEMATIC_443, x=43, y=120
	video offset=CINEMATIC_446, x=43, y=120
	break
	video offset=CINEMATIC_440, x=75, y=121
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_446, x=75, y=121
	break
	video offset=CINEMATIC_440, x=119, y=116
	video offset=CINEMATIC_444, x=124, y=116
	video offset=CINEMATIC_446, x=119, y=116
	break
	video offset=CINEMATIC_440, x=153, y=118
	video offset=CINEMATIC_443, x=153, y=118
	video offset=CINEMATIC_446, x=153, y=118
	break
	video offset=CINEMATIC_440, x=190, y=120
	video offset=CINEMATIC_443, x=190, y=120
	video offset=CINEMATIC_446, x=190, y=120
	break
	video offset=CINEMATIC_440, x=223, y=117
	video offset=CINEMATIC_442, x=223, y=117
	video offset=CINEMATIC_446, x=223, y=117
	break
	video offset=CINEMATIC_440, x=266, y=112
	video offset=CINEMATIC_441, x=266, y=112
	video offset=CINEMATIC_446, x=266, y=112
	break
	video offset=CINEMATIC_440, x=301, y=114
	video offset=CINEMATIC_442, x=301, y=114
	video offset=CINEMATIC_446, x=301, y=114
	break
	video offset=CINEMATIC_440, x=331, y=114
	video offset=CINEMATIC_443, x=331, y=114
	video offset=CINEMATIC_446, x=331, y=114
	killChannel

LABEL_2D42:
	video offset=CINEMATIC_440, x=65506, y=114
	video offset=CINEMATIC_441, x=65506, y=114
	video offset=CINEMATIC_447, x=65506, y=114
	break
	video offset=CINEMATIC_440, x=7, y=116
	video offset=CINEMATIC_442, x=7, y=116
	video offset=CINEMATIC_447, x=7, y=116
	break
	video offset=CINEMATIC_440, x=43, y=120
	video offset=CINEMATIC_443, x=43, y=120
	video offset=CINEMATIC_447, x=43, y=120
	break
	video offset=CINEMATIC_440, x=75, y=121
	video offset=CINEMATIC_444, x=75, y=121
	video offset=CINEMATIC_447, x=75, y=121
	break
	video offset=CINEMATIC_440, x=119, y=116
	video offset=CINEMATIC_444, x=124, y=116
	video offset=CINEMATIC_447, x=119, y=116
	break
	video offset=CINEMATIC_440, x=153, y=118
	video offset=CINEMATIC_443, x=153, y=118
	video offset=CINEMATIC_447, x=153, y=118
	break
	video offset=CINEMATIC_440, x=190, y=120
	video offset=CINEMATIC_443, x=190, y=120
	video offset=CINEMATIC_447, x=190, y=120
	break
	video offset=CINEMATIC_440, x=223, y=117
	video offset=CINEMATIC_442, x=223, y=117
	video offset=CINEMATIC_447, x=223, y=117
	break
	video offset=CINEMATIC_440, x=266, y=112
	video offset=CINEMATIC_441, x=266, y=112
	video offset=CINEMATIC_447, x=266, y=112
	break
	video offset=CINEMATIC_440, x=301, y=114
	video offset=CINEMATIC_442, x=301, y=114
	video offset=CINEMATIC_447, x=301, y=114
	break
	video offset=CINEMATIC_440, x=331, y=114
	video offset=CINEMATIC_443, x=331, y=114
	video offset=CINEMATIC_447, x=331, y=114
	killChannel

LABEL_2DE0:
	setPalette 0x11
	jl [HERO_X], 0xAE, LABEL_2DF2
	jg [HERO_X], 0xE1, LABEL_2DF2
	setPalette 0x09

LABEL_2DF2:
	break
	jmp LABEL_2DE0
	killChannel

LABEL_2DF7:
	break
	jl [HERO_X], 0x7A, LABEL_2DF7
	jg [HERO_X], 0xA1, LABEL_2DF7
	jl [HERO_Y], 0x96, LABEL_2DF7
	jg [HERO_Y], 0xCE, LABEL_2DF7
	mov [HERO_Y], 0x00B4
	jmp INCREMENT_VAR31
	killChannel

LABEL_2E18:
	break
	jl [HERO_Y], 0x46, LABEL_2E18
	mov [HERO_Y], 0x006E
	jmp INCREMENT_VAR31
LABEL_2E26:
	db 0x11
