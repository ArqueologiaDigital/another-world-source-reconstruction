LABEL_8CFB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_245, x=[BUDDY_X], y=[BUDDY_Y]
	call LABEL_8CD5
	ret

LABEL_8D0A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_289, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_782F
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret

LABEL_8D2C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_782F
	ret

LABEL_8D3E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0004
	sub [BUDDY_Y], 0x000D
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8599
	sub [BUDDY_Y], 0x000D
	ret

LABEL_8D6D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8599
	sub [BUDDY_Y], 0x000D
	ret

LABEL_8D87:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_262, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8599
	sub [BUDDY_Y], 0x000D
	ret

LABEL_8DAE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_261, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_289, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8583
	sub [BUDDY_Y], 0x000D
	add [BUDDY_X], 0x0001
	ret

LABEL_8DDD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_77AF
	add [BUDDY_Y], 0x000D
	ret

LABEL_8DF7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_292, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000E
	call LABEL_77DD
	add [BUDDY_Y], 0x000E
	add [BUDDY_X], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_780F
	add [BUDDY_Y], 0x000D
	ret

LABEL_8E33:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_77DD
	add [BUDDY_Y], 0x000D
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret

JUNK__8E5C:
	call LABEL_8C7D
	break
	call LABEL_8C7D
	break
	call LABEL_8C7D
	sub [BUDDY_X], 0x0001
	break
	call LABEL_8C8F
	add [BUDDY_X], 0x0001
	break
	jmp JUNK__8E5C
LABEL_8E77:
	db 0x11

LABEL_8E78:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8E87
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8E87:
	call LABEL_8293
	add [BUDDY_X], 0x0007
	break
	jl [BUDDY_X], [0x29], LABEL_8E9E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8E9E:
	call LABEL_82C0
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8EB5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8EB5:
	call LABEL_82E5
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8ECC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8ECC:
	call LABEL_8318
	add [BUDDY_X], 0x0008
	break
	jl [BUDDY_X], [0x29], LABEL_8EE3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8EE3:
	call LABEL_8345
	add [BUDDY_X], 0x000A
	break
	jl [BUDDY_X], [0x29], LABEL_8EFA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8EFA:
	call LABEL_836A
	add [BUDDY_X], 0x0007
	break
	jl [BUDDY_X], [0x29], LABEL_8F11
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8F11:
	call LABEL_8397
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8F28
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8F28:
	call LABEL_83BC
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8F3F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8F3F:
	call LABEL_83EF
	add [BUDDY_X], 0x0008
	break
	jl [BUDDY_X], [0x29], LABEL_8F56
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B4C

LABEL_8F56:
	call LABEL_841C
	add [BUDDY_X], 0x000A
	break
	jmp LABEL_8E78
	killChannel

LABEL_8F62:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_8F62
LABEL_8F69:
	db 0x11

LABEL_8F6A:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8F79
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8F79:
	call LABEL_864B
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_8F90
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8F90:
	call LABEL_8671
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_8FA7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FA7:
	call LABEL_869F
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_8FBE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FBE:
	call LABEL_86C0
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_8FD5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FD5:
	call LABEL_86ED
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_8FEC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FEC:
	call LABEL_870E
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9003
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9003:
	call LABEL_8734
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_901A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_901A:
	call LABEL_875A
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_9031
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9031:
	call LABEL_8780
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_9048
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9048:
	call LABEL_87A6
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_905F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_905F:
	call LABEL_87D4
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9076
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9076:
	call LABEL_87FA
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_908D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_908D:
	call LABEL_882C
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_90A4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90A4:
	call LABEL_884D
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_90BB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90BB:
	call LABEL_886E
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_90D2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90D2:
	call LABEL_888F
	add [BUDDY_X], 0x0002
	break
	jmp LABEL_8F6A
LABEL_90DD:
	db 0x11

LABEL_90DE:
	je [0x0A], [0x0C], KILL_CHAN_AT_90FC
	jg [0x0A], [0x0C], LABEL_90FD

LABEL_90EA:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_90F6
	break

LABEL_90F6:
	jl [0x0A], [0x0C], LABEL_90EA

KILL_CHAN_AT_90FC:
	killChannel

LABEL_90FD:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_9109
	break

LABEL_9109:
	jg [0x0A], [0x0C], LABEL_90FD
	killChannel

LABEL_9110:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_9145
	je [HERO_POS_MASK], 0x00, LABEL_9133
	call LABEL_30C3
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_90DE
	ret

LABEL_9133:
	call LABEL_30C3
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_90DE

LABEL_9145:
	ret

LABEL_9146:
	video type=0, offset=COMMON_VIDEO_331, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_332, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9164:
	video offset=CINEMATIC_331, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9182:
	jne [0x05], 0x00, LABEL_918E
	video type=0, offset=COMMON_VIDEO_015, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_918E:
	jne [0x05], 0x01, LABEL_919A
	video type=0, offset=COMMON_VIDEO_345, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_919A:
	jne [0x05], 0x02, LABEL_91A6
	video type=0, offset=COMMON_VIDEO_344, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_91A6:
	jne [0x05], 0x03, LABEL_91B2
	video type=0, offset=COMMON_VIDEO_343, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_91B2:
	ret

LABEL_91B3:
	video type=0, offset=COMMON_VIDEO_036, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_037, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

GUARDED_DRAW_CV_159:
	call LABEL_9110
	jne [0x0A], 0x01, LABEL_91EB
	video type=0, offset=COMMON_VIDEO_159, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_91EB:
	jne [0x0A], 0x02, LABEL_920F
	video type=0, offset=COMMON_VIDEO_157, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_920F:
	jne [0x0A], 0x03, LABEL_9233
	video type=0, offset=COMMON_VIDEO_155, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9233:
	video type=0, offset=COMMON_VIDEO_153, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9251:
	video type=0, offset=COMMON_VIDEO_038, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_039, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9262:
	video type=0, offset=COMMON_VIDEO_040, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_041, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9273:
	video type=0, offset=COMMON_VIDEO_042, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_043, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9284:
	video type=0, offset=COMMON_VIDEO_044, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_045, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_929B:
	video type=0, offset=COMMON_VIDEO_046, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_047, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_92AC:
	call LABEL_9182
	video type=0, offset=COMMON_VIDEO_016, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_017, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_92C0:
	video type=0, offset=COMMON_VIDEO_018, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_019, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_92D1:
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_92E2:
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_92F3:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9304:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9315:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_932C:
	video type=0, offset=COMMON_VIDEO_030, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_031, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_933D:
	call LABEL_9182
	video type=0, offset=COMMON_VIDEO_032, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_033, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9351:
	video type=0, offset=COMMON_VIDEO_034, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_035, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9362:
	video type=0, offset=COMMON_VIDEO_131, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9380:
	video type=0, offset=COMMON_VIDEO_293, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_9110
	jne [0x0A], 0x01, LABEL_93AD
	video type=0, offset=COMMON_VIDEO_126, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93AD:
	jne [0x0A], 0x02, LABEL_93B9
	video type=0, offset=COMMON_VIDEO_125, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93B9:
	jne [0x0A], 0x03, LABEL_93C5
	video type=0, offset=COMMON_VIDEO_124, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93C5:
	video type=0, offset=COMMON_VIDEO_122, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93E3:
	jne [0x05], 0x00, LABEL_93EF
	video type=0, offset=COMMON_VIDEO_000, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93EF:
	jne [0x05], 0x01, LABEL_93FB
	video type=0, offset=COMMON_VIDEO_342, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_93FB:
	jne [0x05], 0x02, LABEL_9407
	video type=0, offset=COMMON_VIDEO_127, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9407:
	jne [0x05], 0x03, LABEL_9413
	video type=0, offset=COMMON_VIDEO_341, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9413:
	ret

LABEL_9414:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
