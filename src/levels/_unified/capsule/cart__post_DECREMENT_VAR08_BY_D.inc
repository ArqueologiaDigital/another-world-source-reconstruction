LABEL_8D64:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_246, x=[0x07], y=[0x08]
	call LABEL_8D3E
	ret

LABEL_8D73:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_7898
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_8D95:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7898
	ret

LABEL_8DA7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8602
	sub [0x08], 0x000D
	ret

LABEL_8DD6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8602
	sub [0x08], 0x000D
	ret

LABEL_8DF0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_263, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8602
	sub [0x08], 0x000D
	ret

LABEL_8E17:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_262, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_85EC
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_8E46:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7818
	add [0x08], 0x000D
	ret

LABEL_8E60:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_292, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_7846
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7878
	add [0x08], 0x000D
	ret

LABEL_8E9C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7846
	add [0x08], 0x000D
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__8EC5:
	call LABEL_8CE6
	break
	call LABEL_8CE6
	break
	call LABEL_8CE6
	sub [0x07], 0x0001
	break
	call LABEL_8CF8
	add [0x07], 0x0001
	break
	jmp JUNK__8EC5
LABEL_8EE0:
	db 0x11

LABEL_8EE1:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8EF0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8EF0:
	call LABEL_82FC
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_8F07
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F07:
	call LABEL_8329
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_8F1E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F1E:
	call LABEL_834E
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_8F35
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F35:
	call LABEL_8381
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_8F4C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F4C:
	call LABEL_83AE
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_8F63
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F63:
	call LABEL_83D3
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_8F7A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F7A:
	call LABEL_8400
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_8F91
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F91:
	call LABEL_8425
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_8FA8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FA8:
	call LABEL_8458
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_8FBF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FBF:
	call LABEL_8485
	add [0x07], 0x000A
	break
	jmp LABEL_8EE1
	killChannel

LABEL_8FCB:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_8FCB
LABEL_8FD2:
	db 0x11

LABEL_8FD3:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8FE2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FE2:
	call LABEL_86B4
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_8FF9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_8FF9:
	call LABEL_86DA
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9010
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9010:
	call LABEL_8708
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9027
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9027:
	call LABEL_8729
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_903E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_903E:
	call LABEL_8756
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9055
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9055:
	call LABEL_8777
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_906C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_906C:
	call LABEL_879D
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9083
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9083:
	call LABEL_87C3
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_909A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_909A:
	call LABEL_87E9
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_90B1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90B1:
	call LABEL_880F
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_90C8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90C8:
	call LABEL_883D
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_90DF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90DF:
	call LABEL_8863
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_90F6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_90F6:
	call LABEL_8895
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_910D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_910D:
	call LABEL_88B6
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9124
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_9124:
	call LABEL_88D7
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_913B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_ALIEN_CV128

LABEL_913B:
	call LABEL_88F8
	add [0x07], 0x0002
	break
	jmp LABEL_8FD3
LABEL_9146:
	db 0x11

LABEL_9147:
	je [0x0A], [0x0C], KILL_CHAN_AT_9165
	jg [0x0A], [0x0C], LABEL_9166

LABEL_9153:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_915F
	break

LABEL_915F:
	jl [0x0A], [0x0C], LABEL_9153

KILL_CHAN_AT_9165:
	killChannel

LABEL_9166:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_9172
	break

LABEL_9172:
	jg [0x0A], [0x0C], LABEL_9166
	killChannel

LABEL_9179:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_91AE
	je [HERO_POS_MASK], 0x00, LABEL_919C
	call LABEL_3240
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_9147
	ret

LABEL_919C:
	call LABEL_3240
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_9147

LABEL_91AE:
	ret

LABEL_91AF:
	video type=0, offset=COMMON_VIDEO_331, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_332, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_91CD:
	video offset=CINEMATIC_332, x=[0x01], y=[0x02]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_91EB:
	jne [0x05], 0x00, LABEL_91F7
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_91F7:
	jne [0x05], 0x01, LABEL_9203
	video type=0, offset=COMMON_VIDEO_345, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9203:
	jne [0x05], 0x02, LABEL_920F
	video type=0, offset=COMMON_VIDEO_344, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_920F:
	jne [0x05], 0x03, LABEL_921B
	video type=0, offset=COMMON_VIDEO_343, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_921B:
	ret

LABEL_921C:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_037, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_159:
	call LABEL_9179
	jne [0x0A], 0x01, LABEL_9254
	video type=0, offset=COMMON_VIDEO_159, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9254:
	jne [0x0A], 0x02, LABEL_9278
	video type=0, offset=COMMON_VIDEO_157, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9278:
	jne [0x0A], 0x03, LABEL_929C
	video type=0, offset=COMMON_VIDEO_155, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_929C:
	video type=0, offset=COMMON_VIDEO_153, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_92BA:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_039, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_92CB:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_92DC:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_92ED:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9304:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9315:
	call LABEL_91EB
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9329:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_933A:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_934B:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_935C:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_936D:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_937E:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9395:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_93A6:
	call LABEL_91EB
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_93BA:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_93CB:
	video type=0, offset=COMMON_VIDEO_131, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_93E9:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_9179
	jne [0x0A], 0x01, LABEL_9416
	video type=0, offset=COMMON_VIDEO_126, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9416:
	jne [0x0A], 0x02, LABEL_9422
	video type=0, offset=COMMON_VIDEO_125, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9422:
	jne [0x0A], 0x03, LABEL_942E
	video type=0, offset=COMMON_VIDEO_124, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_942E:
	video type=0, offset=COMMON_VIDEO_122, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_944C:
	jne [0x05], 0x00, LABEL_9458
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9458:
	jne [0x05], 0x01, LABEL_9464
	video type=0, offset=COMMON_VIDEO_342, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9464:
	jne [0x05], 0x02, LABEL_9470
	video type=0, offset=COMMON_VIDEO_127, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9470:
	jne [0x05], 0x03, LABEL_947C
	video type=0, offset=COMMON_VIDEO_341, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_947C:
	ret

LABEL_947D:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
