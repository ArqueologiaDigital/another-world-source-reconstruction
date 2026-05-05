LABEL_0DD9:
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_302, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0DD9
	video offset=CINEMATIC_303, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0008

LABEL_0E02:
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_305, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0E02
	mov [0x03], 0x0002

LABEL_0E15:
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_306, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0E15
	mov [0x03], 0x0008

LABEL_0E28:
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_306, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0E28
	mov [0x03], 0x000A
	mov [HERO_X], 0x00C7

LABEL_0E3F:
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0E3F
	video offset=CINEMATIC_303, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_305, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_307, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_307, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=100
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=60
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=20
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=65516
	break
	mov [0x32], 0x0001
	mov [HERO_Y], 0xFFD8
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[HERO_X], y=150
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=100
	mov [HERO_Y], [0x40]
	setup channel=0x16, address=LABEL_B74A
	jmp LABEL_9A64
LABEL_0EC0:
	db 0x11

LABEL_0EC1:
	mov [0x07], 0x000F
	or [0x12], 0x2000
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_7DD1
	break
	call LABEL_7DE0
	break
	mov [0x29], 0x0005

LABEL_0ED9:
	call LABEL_1064
	jne [0x21], 0x00, LABEL_0FCE
	call LABEL_7DEF
	break
	djnz [0x29], LABEL_0ED9
	mov [0x29], 0x0005
	mov [0x07], 0x000C

LABEL_0EF2:
	call LABEL_1064
	jne [0x21], 0x00, LABEL_0FCE
	call LABEL_7DFE
	break
	djnz [0x29], LABEL_0EF2
	mov [0x07], 0x000E
	mov [0x29], 0x0005

LABEL_0F0B:
	call LABEL_1064
	jne [0x21], 0x00, LABEL_0FCE
	call LABEL_7DEF
	break
	djnz [0x29], LABEL_0F0B
	mov [0x29], 0x0002
	mov [0x07], 0x000C

LABEL_0F24:
	call LABEL_7DFE
	break
	djnz [0x29], LABEL_0F24
	call LABEL_8C93
	break
	mov [0x07], 0x000D
	mov [0x29], 0x0005

LABEL_0F38:
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_0F38
	call LABEL_8C93
	break
	mov [0x07], 0x000C
	mov [0x29], 0x0003

LABEL_0F55:
	mov [0x07], 0x000C
	call LABEL_7DFE
	break
	call LABEL_1064
	jne [0x21], 0x00, LABEL_0FCE
	mov [0x07], 0x000E
	call LABEL_7DEF
	break
	djnz [0x29], LABEL_0F55
	mov [0x29], 0x0006
	mov [0x07], 0x000F

LABEL_0F7A:
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_7DEF
	break
	djnz [0x29], LABEL_0F7A
	call LABEL_8C93
	break
	mov [0x29], 0x0003
	mov [0x07], 0x0014
	jl [HERO_X], 0x78, LABEL_0FA1
	mov [0x29], 0x0006

LABEL_0FA1:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_1064
	jg [HERO_X], 0x64, LABEL_0FBD
	je [0x21], 0x00, LABEL_0FA1

LABEL_0FBD:
	djnz [0x29], LABEL_0FA1
	jl [HERO_X], 0x64, LABEL_0FCE
	call LABEL_8C93
	break
	jmp LABEL_0EC1

LABEL_0FCE:
	mov [0x07], 0x0016
	call LABEL_89D0
	break
	mov [0x07], 0x0017
	mov [0x29], 0x000A

LABEL_0FDE:
	call LABEL_89DF
	break
	jne [HACK_VAR_67], [0x10], LABEL_0FEE
	jl [HERO_X], 0x32, LABEL_1052

LABEL_0FEE:
	jl [HERO_X], 0x53, LABEL_0FDE
	djnz [0x29], LABEL_0FDE
	mov [0x07], 0x0018
	mov [0x29], 0x0002
	and [0x49], 0xFF9F
	and [0x4B], 0xFF9F
	or [0xB9], 0x1000

LABEL_100C:
	call LABEL_89FD
	video offset=CINEMATIC_315, x=161, y=101
	video offset=CINEMATIC_315, x=160, y=100
	video offset=CINEMATIC_315, x=159, y=99
	jg [HERO_X], 0x6E, LABEL_102E
	jl [HERO_X], 0x5A, LABEL_102E
	mov [HERO_X], 0x006E
	mov [0x28], [HERO_X]

LABEL_102E:
	break
	djnz [0x29], LABEL_100C
	call LABEL_89EE
	break
	call LABEL_89D0
	break
	jne [HACK_VAR_67], [0x10], LABEL_104A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE

LABEL_104A:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	jmp LABEL_0EC1
LABEL_1051:
	db 0x11

LABEL_1052:
	add [0x07], 0x0012
	video offset=CINEMATIC_283, x=[0x07], y=[0x08]
	video offset=CINEMATIC_317, x=[0x07], y=[0x08]
	jmp LABEL_4E00
LABEL_1063:
	db 0x11

LABEL_1064:
	mov [0x21], 0x0000
	jl [0x4B], 0x2000, SHARED_RET
	mov [0xF8], [0x04]
	and [0xF8], 0x0014
	jne [0xF8], 0x00, SHARED_RET
	jne [0x63], 0x64, SHARED_RET
	mov [0x21], 0x0001
	ret

LABEL_1087:
	video offset=CINEMATIC_315, x=160, y=100
	break
	video offset=CINEMATIC_315, x=160, y=100
	break
	video offset=CINEMATIC_315, x=160, y=100
	break
	break
	break
	jmp LABEL_1087

LABEL_109B:
	call GUARDED_DRAW_CV_304_305
	break
	jne [0x10], 0x8E, LABEL_1155
	jne [0x10], [HACK_VAR_67], LABEL_109B
	jg [HERO_X], 0x64, LABEL_10C9
	mov [0x29], 0x0003

LABEL_10B5:
	call LABEL_7D99
	break
	djnz [0x29], LABEL_10B5
	mov [0x29], 0x0003

LABEL_10C1:
	call LABEL_7DB5
	break
	djnz [0x29], LABEL_10C1

LABEL_10C9:
	call GUARDED_DRAW_CV_304_305
	break
	jl [HERO_X], 0x78, LABEL_10C9
	mov [0x29], 0x0007

LABEL_10D7:
	jne [0x10], [HACK_VAR_67], LABEL_10E2
	video offset=CINEMATIC_309, x=[0x07], y=[0x08]

LABEL_10E2:
	break
	djnz [0x29], LABEL_10D7
	jne [0x10], [HACK_VAR_67], LABEL_10F2
	video offset=CINEMATIC_309, x=[0x07], y=[0x08]

LABEL_10F2:
	break
	jne [0x10], [HACK_VAR_67], LABEL_109B
	video offset=CINEMATIC_296, x=[0x07], y=[0x08]
	break
	jne [0x10], [HACK_VAR_67], LABEL_109B
	video offset=CINEMATIC_296, x=[0x07], y=[0x08]
	break
	jne [0x10], [HACK_VAR_67], LABEL_109B
	video offset=CINEMATIC_297, x=[0x07], y=[0x08]
	break
	jne [0x10], [HACK_VAR_67], LABEL_1122
	video offset=CINEMATIC_308, x=[0x07], y=[0x08]

LABEL_1122:
	break
	jne [0x10], [HACK_VAR_67], LABEL_112E
	video offset=CINEMATIC_264, x=[0x07], y=94

LABEL_112E:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1141
	video offset=CINEMATIC_264, x=[0x07], y=48
	break
	video offset=CINEMATIC_264, x=[0x07], y=65521

LABEL_1141:
	setup channel=0x37, address=LABEL_0DA7
	or [0xBB], 0x0010
	setup channel=0x03, address=LABEL_0D3A
	mov [0x10], 0x006E
	jmp LABEL_109B
LABEL_1154:
	db 0x11

LABEL_1155:
	call GUARDED_DRAW_CV_304_305
	break
	je [HACK_VAR_67], 0x8E, LABEL_1155
	jg [0x10], [HACK_VAR_67], LABEL_1155
	mov [0x29], 0x0003

LABEL_1169:
	call LABEL_7D99
	break
	djnz [0x29], LABEL_1169
	mov [0x29], 0x0003

LABEL_1175:
	call LABEL_7DB5
	break
	djnz [0x29], LABEL_1175

LABEL_117D:
	call GUARDED_DRAW_CV_304_305
	break
	mov [0xF8], [HERO_X]
	add [0xF8], 0x0032
	jl [0xF8], [0x07], LABEL_117D
	mov [0x2F], 0x0019
	mov [0x29], 0x01A4
	jmp DISPATCH_VAR2F_STATE

LABEL_1199:
	mov [0x07], 0x0113
	video offset=CINEMATIC_119, x=[0x07], y=50
	break
	video offset=CINEMATIC_119, x=[0x07], y=73
	break
	video offset=CINEMATIC_119, x=[0x07], y=96
	break
	video offset=CINEMATIC_119, x=[0x07], y=122
	break
	video offset=CINEMATIC_119, x=[0x07], y=153
	break
	play id=0x0055, freq=0x14, vol=0x30, channel=0x01
	video offset=CINEMATIC_120, x=[0x07], y=168
	break
	video offset=CINEMATIC_120, x=[0x07], y=168
	break
	video offset=CINEMATIC_120, x=[0x07], y=168
	break
	video offset=CINEMATIC_121, x=[0x07], y=168
	mov [0x08], 0x00A8
	mov [0x10], 0x008D
	mov [0x11], 0x3000
	break
	mov [0x29], 0x000A

LABEL_11E9:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_11E9
	mov [0x29], 0x021C
	mov [0x2F], 0x0019
	mov [0x12], 0x0005
	jmp DISPATCH_VAR2F_STATE
LABEL_1200:
	db 0x11

LABEL_1201:
	break
	jl [0x70], 0x012C, LABEL_1201
	mov [0x07], 0x008C
	video offset=CINEMATIC_119, x=[0x07], y=50
	break
	song id=0x0BDA, delay=0x0000, pos=0x00
	video offset=CINEMATIC_119, x=[0x07], y=73
	break
	video offset=CINEMATIC_119, x=[0x07], y=96
	break
	video offset=CINEMATIC_119, x=[0x07], y=122
	break
	video offset=CINEMATIC_119, x=[0x07], y=153
	break
	play id=0x0055, freq=0x14, vol=0x30, channel=0x01
	video offset=CINEMATIC_120, x=[0x07], y=157
	break
	video offset=CINEMATIC_120, x=[0x07], y=157
	break
	video offset=CINEMATIC_120, x=[0x07], y=157
	break
	video offset=CINEMATIC_121, x=[0x07], y=157

LABEL_124E:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	jne [0x72], 0x92, LABEL_124E

LABEL_1258:
	break
	jl [0x70], 0x32, LABEL_1258
	break
	song id=0x0BDB, delay=0x0000, pos=0x00
	video offset=CINEMATIC_122, x=65517, y=110
	break
	video offset=CINEMATIC_122, x=0, y=105
	break
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	video offset=CINEMATIC_122, x=25, y=112
	break
	mov [0x07], 0x0041
	video offset=CINEMATIC_123, x=[0x07], y=[0x08]
	break
	add [0x07], 0x000F
	video offset=CINEMATIC_124, x=[0x07], y=[0x08]
	setup channel=0x13, address=RAMP_VAR1_PLUS_C_9_5_3_BREAKS
	break
	add [0x07], 0x000A

LABEL_1297:
	mov [0xEF], 0x0006
