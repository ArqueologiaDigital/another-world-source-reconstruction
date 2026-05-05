LABEL_0CFC:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_299, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0CFC
	video offset=CINEMATIC_300, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0008

LABEL_0D25:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_302, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0D25
	mov [0x03], 0x0002

LABEL_0D38:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_303, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0D38
	mov [0x03], 0x0008

LABEL_0D4B:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_303, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0D4B
	mov [0x03], 0x000A
	mov [HERO_X], 0x00C7

LABEL_0D62:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], LABEL_0D62
	video offset=CINEMATIC_300, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_301, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_302, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=100
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=60
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=20
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=65516
	break
	mov [0x32], 0x0001
	mov [HERO_Y], 0xFFD8
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=150
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=100
	mov [HERO_Y], [0x40]
	setup channel=0x16, address=LABEL_B666
	jmp LABEL_99FB
LABEL_0DE3:
	db 0x11

LABEL_0DE4:
	mov [0x07], 0x000F
	or [0x12], 0x2000
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_7D68
	break
	call LABEL_7D77
	break
	mov [0x29], 0x0005

LABEL_0DFC:
	call LABEL_0F87
	jne [0x21], 0x00, LABEL_0EF1
	call LABEL_7D86
	break
	djnz [0x29], LABEL_0DFC
	mov [0x29], 0x0005
	mov [0x07], 0x000C

LABEL_0E15:
	call LABEL_0F87
	jne [0x21], 0x00, LABEL_0EF1
	call LABEL_7D95
	break
	djnz [0x29], LABEL_0E15
	mov [0x07], 0x000E
	mov [0x29], 0x0005

LABEL_0E2E:
	call LABEL_0F87
	jne [0x21], 0x00, LABEL_0EF1
	call LABEL_7D86
	break
	djnz [0x29], LABEL_0E2E
	mov [0x29], 0x0002
	mov [0x07], 0x000C

LABEL_0E47:
	call LABEL_7D95
	break
	djnz [0x29], LABEL_0E47
	call LABEL_8C2A
	break
	mov [0x07], 0x000D
	mov [0x29], 0x0005

LABEL_0E5B:
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_0E5B
	call LABEL_8C2A
	break
	mov [0x07], 0x000C
	mov [0x29], 0x0003

LABEL_0E78:
	mov [0x07], 0x000C
	call LABEL_7D95
	break
	call LABEL_0F87
	jne [0x21], 0x00, LABEL_0EF1
	mov [0x07], 0x000E
	call LABEL_7D86
	break
	djnz [0x29], LABEL_0E78
	mov [0x29], 0x0006
	mov [0x07], 0x000F

LABEL_0E9D:
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_7D86
	break
	djnz [0x29], LABEL_0E9D
	call LABEL_8C2A
	break
	mov [0x29], 0x0003
	mov [0x07], 0x0014
	jl [HERO_X], 0x78, LABEL_0EC4
	mov [0x29], 0x0006

LABEL_0EC4:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_0F87
	jg [HERO_X], 0x64, LABEL_0EE0
	je [0x21], 0x00, LABEL_0EC4

LABEL_0EE0:
	djnz [0x29], LABEL_0EC4
	jl [HERO_X], 0x64, LABEL_0EF1
	call LABEL_8C2A
	break
	jmp LABEL_0DE4

LABEL_0EF1:
	mov [0x07], 0x0016
	call LABEL_8967
	break
	mov [0x07], 0x0017
	mov [0x29], 0x000A

LABEL_0F01:
	call LABEL_8976
	break
	jne [HACK_VAR_67], [0x10], LABEL_0F11
	jl [HERO_X], 0x32, LABEL_0F75

LABEL_0F11:
	jl [HERO_X], 0x53, LABEL_0F01
	djnz [0x29], LABEL_0F01
	mov [0x07], 0x0018
	mov [0x29], 0x0002
	and [0x49], 0xFF9F
	and [0x4B], 0xFF9F
	or [0xB9], 0x1000

LABEL_0F2F:
	call LABEL_8994
	video offset=CINEMATIC_314, x=161, y=101
	video offset=CINEMATIC_314, x=160, y=100
	video offset=CINEMATIC_314, x=159, y=99
	jg [HERO_X], 0x6E, LABEL_0F51
	jl [HERO_X], 0x5A, LABEL_0F51
	mov [HERO_X], 0x006E
	mov [0x28], [HERO_X]

LABEL_0F51:
	break
	djnz [0x29], LABEL_0F2F
	call LABEL_8985
	break
	call LABEL_8967
	break
	jne [HACK_VAR_67], [0x10], LABEL_0F6D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE

LABEL_0F6D:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	jmp LABEL_0DE4
LABEL_0F74:
	db 0x11

LABEL_0F75:
	add [0x07], 0x0012
	video offset=CINEMATIC_282, x=[0x07], y=[0x08]
	video offset=CINEMATIC_316, x=[0x07], y=[0x08]
	jmp LABEL_4E24
LABEL_0F86:
	db 0x11

LABEL_0F87:
	mov [0x21], 0x0000
	jl [0x4B], 0x2000, SHARED_RET
	mov [0xF8], [0x04]
	and [0xF8], 0x0014
	jne [0xF8], 0x00, SHARED_RET
	jne [0x63], 0x64, SHARED_RET
	mov [0x21], 0x0001
	ret

LABEL_0FAA:
	video offset=CINEMATIC_314, x=160, y=100
	break
	video offset=CINEMATIC_314, x=160, y=100
	break
	video offset=CINEMATIC_314, x=160, y=100
	break
	break
	break
	jmp LABEL_0FAA

LABEL_0FBE:
	call GUARDED_DRAW_CV_304_305
	break
	jne [0x10], 0x8E, LABEL_1074
	jne [0x10], [HACK_VAR_67], LABEL_0FBE
	jg [HERO_X], 0x64, LABEL_0FEC
	mov [0x29], 0x0003

LABEL_0FD8:
	call LABEL_7D30
	break
	djnz [0x29], LABEL_0FD8
	mov [0x29], 0x0003

LABEL_0FE4:
	call LABEL_7D4C
	break
	djnz [0x29], LABEL_0FE4

LABEL_0FEC:
	call GUARDED_DRAW_CV_304_305
	break
	jl [HERO_X], 0x78, LABEL_0FEC
	mov [0x29], 0x0007

LABEL_0FFA:
	jne [0x10], [HACK_VAR_67], LABEL_1005
	video offset=CINEMATIC_308, x=[0x07], y=[0x08]

LABEL_1005:
	break
	djnz [0x29], LABEL_0FFA
	jne [0x10], [HACK_VAR_67], LABEL_1015
	video offset=CINEMATIC_308, x=[0x07], y=[0x08]

LABEL_1015:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1021
	video offset=CINEMATIC_307, x=[0x07], y=[0x08]

LABEL_1021:
	break
	jne [0x10], [HACK_VAR_67], LABEL_102D
	video offset=CINEMATIC_307, x=[0x07], y=[0x08]

LABEL_102D:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1039
	video offset=CINEMATIC_306, x=[0x07], y=[0x08]

LABEL_1039:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1045
	video offset=CINEMATIC_305, x=[0x07], y=[0x08]

LABEL_1045:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1051
	video offset=CINEMATIC_263, x=[0x07], y=94

LABEL_1051:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1064
	video offset=CINEMATIC_263, x=[0x07], y=48
	break
	video offset=CINEMATIC_263, x=[0x07], y=65521

LABEL_1064:
	setup channel=0x37, address=LABEL_0CD0
	setup channel=0x03, address=LABEL_0C7B
	mov [0x10], 0x006E
	jmp LABEL_0FBE
LABEL_1073:
	db 0x11

LABEL_1074:
	call GUARDED_DRAW_CV_304_305
	break
	je [HACK_VAR_67], 0x8E, LABEL_1074
	jg [0x10], [HACK_VAR_67], LABEL_1074
	mov [0x29], 0x0003

LABEL_1088:
	call LABEL_7D30
	break
	djnz [0x29], LABEL_1088
	mov [0x29], 0x0003

LABEL_1094:
	call LABEL_7D4C
	break
	djnz [0x29], LABEL_1094

LABEL_109C:
	call GUARDED_DRAW_CV_304_305
	break
	mov [0xF8], [HERO_X]
	add [0xF8], 0x0032
	jl [0xF8], [0x07], LABEL_109C
	mov [0x2F], 0x0019
	mov [0x29], 0x01A4
	jmp DISPATCH_VAR2F_STATE

LABEL_10B8:
	mov [0x07], 0x0113
	video offset=CINEMATIC_118, x=[0x07], y=50
	break
	video offset=CINEMATIC_118, x=[0x07], y=73
	break
	video offset=CINEMATIC_118, x=[0x07], y=96
	break
	video offset=CINEMATIC_118, x=[0x07], y=122
	break
	video offset=CINEMATIC_118, x=[0x07], y=153
	break
	play id=0x0055, freq=0x14, vol=0x30, channel=0x01
	video offset=CINEMATIC_119, x=[0x07], y=168
	break
	video offset=CINEMATIC_119, x=[0x07], y=168
	break
	video offset=CINEMATIC_119, x=[0x07], y=168
	break
	video offset=CINEMATIC_120, x=[0x07], y=168
	mov [0x08], 0x00A8
	mov [0x10], 0x008D
	mov [0x11], 0x3000
	break
	mov [0x29], 0x000A

LABEL_1108:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_1108
	mov [0x29], 0x021C
	mov [0x2F], 0x0019
	mov [0x12], 0x0005
	jmp DISPATCH_VAR2F_STATE
LABEL_111F:
	db 0x11

LABEL_1120:
	break
	jl [0x70], 0x012C, LABEL_1120
	mov [0x07], 0x008C
	video offset=CINEMATIC_118, x=[0x07], y=50
	break
	video offset=CINEMATIC_118, x=[0x07], y=73
	break
	video offset=CINEMATIC_118, x=[0x07], y=96
	break
	video offset=CINEMATIC_118, x=[0x07], y=122
	break
	video offset=CINEMATIC_118, x=[0x07], y=153
	break
	play id=0x0055, freq=0x14, vol=0x30, channel=0x01
	video offset=CINEMATIC_119, x=[0x07], y=157
	break
	video offset=CINEMATIC_119, x=[0x07], y=157
	break
	video offset=CINEMATIC_119, x=[0x07], y=157
	break
	video offset=CINEMATIC_120, x=[0x07], y=157

LABEL_1167:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	jne [0x72], 0x92, LABEL_1167

LABEL_1171:
	break
	jl [0x70], 0x32, LABEL_1171
	break
	video offset=CINEMATIC_121, x=65517, y=110
	break
	video offset=CINEMATIC_121, x=0, y=105
	break
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	video offset=CINEMATIC_121, x=25, y=112
	break
	mov [0x07], 0x0041
	video offset=CINEMATIC_122, x=[0x07], y=[0x08]
	break
	add [0x07], 0x000F
	video offset=CINEMATIC_123, x=[0x07], y=[0x08]
	setup channel=0x13, address=RAMP_VAR1_PLUS_C_9_5_3_BREAKS
	break
	add [0x07], 0x000A

LABEL_11AA:
	mov [0xEF], 0x0006
