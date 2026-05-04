ANIM_CIN_376_LOOP_VARE8:
	video type=1, offset=CINEMATIC_376, x=137, y=100
	break
	djnz [0xE8], ANIM_CIN_376_LOOP_VARE8
	video type=1, offset=CINEMATIC_377, x=137, y=100
	break
	video type=1, offset=CINEMATIC_373, x=137, y=100
	break
	mov [0xE8], 0x0014
	video type=1, offset=CINEMATIC_374, x=137, y=100
	break
	video type=1, offset=CINEMATIC_374, x=137, y=102
	break
	video type=1, offset=CINEMATIC_374, x=137, y=106
	break
	video type=1, offset=CINEMATIC_374, x=137, y=108
	break
	video type=1, offset=CINEMATIC_374, x=137, y=112
	break
	video type=1, offset=CINEMATIC_374, x=137, y=116
	break
	video type=1, offset=CINEMATIC_374, x=137, y=120
	killChannel

LABEL_25BB:
	video type=1, offset=CINEMATIC_373, x=66, y=91
	video type=1, offset=CINEMATIC_374, x=95, y=97
	video type=1, offset=CINEMATIC_375, x=160, y=100
	break
	jmp LABEL_25BB
LABEL_25CB:
	db 0x11

LABEL_25CC:
	mov [0x29], 0x03E8
	mov [0x2F], 0x0019
	setup channel=0x05, address=LABEL_25DC
	jmp DISPATCH_VAR2F_STATE
LABEL_25DB:
	db 0x11

LABEL_25DC:
	add [0x68], 0x0001
	break
	jl [HACK_VAR_67], [0x6A], LABEL_25DC
	jg [HACK_VAR_67], [0x6A], LABEL_25FA
	mov [0xF8], [0x01]
	add [0xF8], 0x001E
	jg [0x68], [0xF8], LABEL_25DC

LABEL_25FA:
	add [0x68], 0x0002
	jmp LABEL_25DC

LABEL_2601:
	mov [0x2F], 0x0000
	jne [0x10], 0x6B, SHARED_RET
	mov [0x2F], 0x0023
	setup channel=0x38, address=LABEL_3D5C
	ret

LABEL_2614:
	mov [0x2F], 0x0019
	mov [0x29], 0x0320
	jne [0x10], 0x6D, SHARED_RET
	mov [0x2F], 0x001E
	ret

LABEL_2627:
	mov [0x2F], 0x001F
	jg [0x07], 0x78, SHARED_RET
	mov [0x2F], 0x0019
	mov [0x29], 0x0096
	ret

LABEL_263A:
	mov [0x2F], 0x0020
	je [0x10], 0x6F, LABEL_2653
	jg [0x10], [HACK_VAR_67], LABEL_2653
	mov [0x2F], 0x0019
	mov [0x29], 0x01C2
	ret

LABEL_2653:
	mov [0x2F], 0x0012
	jg [0x07], 0xA0, SHARED_RET
	mov [0x2F], 0x0019
	mov [0x29], 0x00BA
	ret

LABEL_2666:
	mov [0x2F], 0x0020
	jne [0x10], 0x8E, LABEL_263A
	ret

LABEL_2671:
	mov [0x68], 0x0090
	mov [0x69], 0x0062
	break
	jl [0x01], 0x28, LABEL_2671
	or [0xB9], 0x0040
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_465, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_466, x=[0x68], y=[0x69], zoom=0x40
	play id=0x0075, freq=0x0F, vol=0x40, channel=0x00
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x02
	break
	video type=1, offset=CINEMATIC_467, x=[0x68], y=[0x69], zoom=0x40
	break
	play id=0x006B, freq=0x14, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_468, x=[0x68], y=[0x69], zoom=0x40
	video type=1, offset=CINEMATIC_469, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_470, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_471, x=[0x68], y=[0x69], zoom=0x40
	video type=1, offset=CINEMATIC_472, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_473, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0xFF
	play id=0x006B, freq=0x14, vol=0x20, channel=0x02
	break
	video type=1, offset=CINEMATIC_474, x=[0x68], y=[0x69], zoom=0x40
	video type=1, offset=CINEMATIC_475, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_476, x=[0x68], y=[0x69], zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_477, x=[0x68], y=[0x69], zoom=0x40
	video type=1, offset=CINEMATIC_478, x=[0x68], y=[0x69], zoom=0x40
	break
	video type=1, offset=CINEMATIC_477, x=[0x68], y=[0x69], zoom=0x40
	break
	video type=1, offset=CINEMATIC_479, x=[0x68], y=[0x69], zoom=0x40
	break
	video type=1, offset=CINEMATIC_480, x=[0x68], y=[0x69], zoom=0x40
	break
	video type=1, offset=CINEMATIC_481, x=[0x68], y=[0x69], zoom=0x40
	setup channel=0x01, address=LABEL_3F38
	call LABEL_3599
	killChannel

LABEL_2718:
	video type=1, offset=CINEMATIC_409, x=160, y=100
	play id=0x006B, freq=0x0A, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_410, x=160, y=100
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x02
	break
	video type=1, offset=CINEMATIC_411, x=160, y=100
	break
	video type=1, offset=CINEMATIC_412, x=160, y=100
	play id=0x006B, freq=0x0A, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_413, x=160, y=100
	video type=1, offset=CINEMATIC_414, x=160, y=100
	play id=0x0055, freq=0x10, vol=0x20, channel=0x03
	break
	video type=1, offset=CINEMATIC_415, x=160, y=100
	video type=1, offset=CINEMATIC_416, x=160, y=100
	play id=0x006B, freq=0x14, vol=0x40, channel=0x02
	break
	video type=1, offset=CINEMATIC_417, x=160, y=100
	video type=1, offset=CINEMATIC_418, x=160, y=100
	break
	video type=1, offset=CINEMATIC_419, x=160, y=100
	video type=1, offset=CINEMATIC_420, x=160, y=100
	break
	play id=0x006C, freq=0x14, vol=0x18, channel=0x02
	video type=1, offset=CINEMATIC_421, x=160, y=100
	video type=1, offset=CINEMATIC_422, x=160, y=100
	break
	video type=1, offset=CINEMATIC_423, x=144, y=127
	video type=1, offset=CINEMATIC_424, x=160, y=100
	break
	play id=0x006C, freq=0x18, vol=0x18, channel=0x02
	video type=1, offset=CINEMATIC_423, x=143, y=127
	video type=1, offset=CINEMATIC_425, x=160, y=100
	break
	video type=1, offset=CINEMATIC_423, x=142, y=127
	play id=0x006C, freq=0x12, vol=0x18, channel=0x01
	video type=1, offset=CINEMATIC_426, x=160, y=100
	break
	video type=1, offset=CINEMATIC_423, x=142, y=127
	play id=0x006C, freq=0x10, vol=0x18, channel=0x02
	video type=1, offset=CINEMATIC_427, x=160, y=100
	mov [0xF0], 0x000A

LABEL_27B6:
	break
	video type=1, offset=CINEMATIC_423, x=141, y=127
	djnz [0xF0], LABEL_27B6
	break
	play id=0x0057, freq=0x10, vol=0x18, channel=0x02
	video type=1, offset=CINEMATIC_428, x=141, y=127
	break
	video type=1, offset=CINEMATIC_429, x=141, y=127
	break
	video type=1, offset=CINEMATIC_430, x=141, y=127
	break
	video type=1, offset=CINEMATIC_431, x=141, y=127
	setup channel=0x0F, address=HANG_DRAW_CIN_433__CART__POST_INLINE_SET_VARE8_TO_F
	setup channel=0x1D, address=HANG_DRAW_CIN_434
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_432, x=141, y=127
	selectVideoPage 0xFF
	call INIT_BIRD_AI_VARS
	mov [PAUSE_SLICES], 0x0004
	song id=0x0BD8, delay=0x0000, pos=0x00
	setup channel=0x14, address=LABEL_C381
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=LABEL_B74A
	killChannel

HANG_DRAW_CIN_433__CART__POST_INLINE_SET_VARE8_TO_F:
	video type=1, offset=CINEMATIC_433, x=141, y=127
	break
	jmp HANG_DRAW_CIN_433__CART__POST_INLINE_SET_VARE8_TO_F

HANG_DRAW_CIN_434:
	video type=1, offset=CINEMATIC_434, x=141, y=127
	break
	jmp HANG_DRAW_CIN_434
	killChannel

LABEL_2814:
	break
	jl [0x01], 0xB4, LABEL_2814
	or [0x74], 0x4000
	setPalette 0x09
	killChannel

LABEL_2823:
	setup channel=0x22, address=LABEL_4561
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	setup channel=0x24, address=LABEL_4581
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	setup channel=0x26, address=LABEL_45BC
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=LABEL_45F7
	ret

LABEL_2840:
	je [HACK_VAR_67], 0xEC, LABEL_2847
	ret

LABEL_2847:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, LABEL_2857
	call LABEL_361F

LABEL_2857:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_2873
	mov [0xA9], 0x00B9
	mov [0xAA], 0x03E8
	mov [0xAB], 0x00EC
	call LABEL_3640

LABEL_2873:
	ret

LABEL_2874:
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CV_304_305
	break
	mov [0x0E], 0x0004
	call LABEL_7D43
	break
	mov [0x0E], 0x0000
	call LABEL_7D61
	break
	mov [0x29], 0x0002

LABEL_2890:
	mov [0x0E], 0x0003
	call LABEL_7D61
	break
	djnz [0x29], LABEL_2890
	mov [0x29], 0x0002

LABEL_28A0:
	mov [0x0E], 0x0000
	call LABEL_7D43
	break
	djnz [0x29], LABEL_28A0
	mov [0xF8], [0x07]
	sub [0xF8], [0x01]
	jl [0xF8], 0x64, LABEL_28C7
	call LABEL_53FF
	jne [0x12], 0x28, LABEL_28C7
	je [0x21], 0x00, LABEL_2874

LABEL_28C7:
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	mov [0x29], 0x0002
	jmp DISPATCH_VAR2F_STATE
	killChannel
	mov [0xEE], 0x00FA
	mov [0xEF], 0x0005

LABEL_28DF:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=98, zoom=0x40
	sub [0xEE], 0x000A
	break
	djnz [0xEF], LABEL_28DF
	mov [0xEF], 0x0004

LABEL_28F1:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=99, zoom=0x40
	sub [0xEE], 0x0008
	break
	djnz [0xEF], LABEL_28F1
	mov [0xEF], 0x0004

LABEL_2903:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0006
	break
	djnz [0xEF], LABEL_2903
	mov [0xEF], 0x0004

LABEL_2915:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0004
	break
	djnz [0xEF], LABEL_2915
	mov [0xEF], 0x0004

LABEL_2927:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0003
	break
	djnz [0xEF], LABEL_2927
	mov [0xEF], 0x0004

LABEL_2939:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0002
	break
	djnz [0xEF], LABEL_2939
	mov [0xEF], 0x0004

LABEL_294B:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	djnz [0xEF], LABEL_294B
	mov [0xEF], 0x0002

LABEL_295D:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	break
	djnz [0xEF], LABEL_295D

HANG_DRAW_CIN_711:
	video type=1, offset=CINEMATIC_711, x=[0xee], y=100, zoom=0x40
	break
	jmp HANG_DRAW_CIN_711
	killChannel

LABEL_297B:
	je [0xB6], 0x00, KILL_CHAN_AT_157F
	jne [HACK_VAR_67], [0xB6], KILL_CHAN_AT_157F
	jl [0x01], 0x0148, LABEL_299B
	mov [0x01], 0x0148
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_297B
	killChannel

LABEL_299B:
	break
	jmp LABEL_297B
	killChannel

LABEL_29A0:
	break
	jl [0x01], 0x78, LABEL_29A0
	jg [0x01], 0xF0, LABEL_29A0
	mov [0xF8], [0xB2]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, KILL_CHAN_AT_157F
	or [0xB2], 0x0100
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	call LABEL_36A3
	setup channel=0x34, address=LABEL_69F2
	setup channel=0x33, address=LABEL_69BB
	break
	break
	break
	break
	break
	call LABEL_36A3
	killChannel

LABEL_29DA:
	jl [HACK_VAR_67], 0x4A, LABEL_29FC
	jg [HACK_VAR_67], 0x4C, LABEL_29FC
	jne [0x1D], 0x29, LABEL_29FC
	je [0xB0], 0x00, SET_VARB1_TO_0000
	mov [0xB0], 0x0000
	ret
