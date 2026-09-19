LABEL_8D64:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_246, x=[BUDDY_X], y=[BUDDY_Y]
	call BUDDY_RIGHT_FIRE_AIM_PHASE_1
	ret


LABEL_8D73:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call LABEL_8CC2
	video type=0, offset=CV_4324, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_7898
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret


LABEL_8D95:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7898
	ret


LABEL_8DA7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0004
	video type=0, offset=CV_2570, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0004
	sub [BUDDY_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8602
	sub [BUDDY_Y], 0x000D
	ret


LABEL_8DD6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8602
	sub [BUDDY_Y], 0x000D
	ret


LABEL_8DF0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_263, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_8602
	sub [BUDDY_Y], 0x000D
	ret


LABEL_8E17:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_262, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_4324, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_85EC
	sub [BUDDY_Y], 0x000D
	add [BUDDY_X], 0x0001
	ret


LABEL_8E46:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_7818
	add [BUDDY_Y], 0x000D
	ret


LABEL_8E60:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4368, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000E
	call LABEL_7846
	add [BUDDY_Y], 0x000E
	add [BUDDY_X], 0x0001
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_7878
	add [BUDDY_Y], 0x000D
	ret


LABEL_8E9C:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x000D
	call LABEL_7846
	add [BUDDY_Y], 0x000D
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


JUNK__8EC5:
	call LABEL_8CE6
	break
	call LABEL_8CE6
	break
	call LABEL_8CE6
	sub [BUDDY_X], 0x0001
	break
	call LABEL_8CF8
	add [BUDDY_X], 0x0001
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
	add [BUDDY_X], 0x0007
	break
	jl [BUDDY_X], [0x29], LABEL_8F07
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F07:
	call LABEL_8329
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8F1E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F1E:
	call CAPSULE_ACTOR_RUN_RIGHT_DRAW_2
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8F35
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F35:
	call LABEL_8381
	add [BUDDY_X], 0x0008
	break
	jl [BUDDY_X], [0x29], LABEL_8F4C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F4C:
	call LABEL_83AE
	add [BUDDY_X], 0x000A
	break
	jl [BUDDY_X], [0x29], LABEL_8F63
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F63:
	call LABEL_83D3
	add [BUDDY_X], 0x0007
	break
	jl [BUDDY_X], [0x29], LABEL_8F7A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F7A:
	call LABEL_8400
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8F91
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F91:
	call LABEL_8425
	add [BUDDY_X], 0x0009
	break
	jl [BUDDY_X], [0x29], LABEL_8FA8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FA8:
	call CAPSULE_ACTOR_RUN_RIGHT_DRAW_8
	add [BUDDY_X], 0x0008
	break
	jl [BUDDY_X], [0x29], LABEL_8FBF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FBF:
	call CAPSULE_DRAW_CV261_AT_X07_Y08_L0
	add [BUDDY_X], 0x000A
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
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_8FE2:
	call LABEL_86B4
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_8FF9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_8FF9:
	call LABEL_86DA
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_9010
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9010:
	call LABEL_8708
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9027
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9027:
	call LABEL_8729
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_903E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_903E:
	call LABEL_8756
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9055
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9055:
	call LABEL_8777
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_906C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_906C:
	call LABEL_879D
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9083
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9083:
	call LABEL_87C3
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_909A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_909A:
	call LABEL_87E9
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_90B1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90B1:
	call LABEL_880F
	add [BUDDY_X], 0x0002
	break
	jl [BUDDY_X], [0x29], LABEL_90C8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90C8:
	call LABEL_883D
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_90DF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90DF:
	call LABEL_8863
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_90F6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90F6:
	call LABEL_8895
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_910D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_910D:
	call LABEL_88B6
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_9124
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9124:
	call LABEL_88D7
	add [BUDDY_X], 0x0003
	break
	jl [BUDDY_X], [0x29], LABEL_913B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_913B:
	call LABEL_88F8
	add [BUDDY_X], 0x0002
	break
	jmp LABEL_8FD3
CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK:
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
	video type=0, offset=CV_3764, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C4C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_91CD:
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C54, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_91EB:
	jne [0x05], 0x00, LABEL_91F7
	video type=0, offset=CV_5DDC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_91F7:
	jne [0x05], 0x01, LABEL_9203
	video type=0, offset=CV_5CD4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9203:
	jne [0x05], 0x02, LABEL_920F
	video type=0, offset=CV_5D2C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_920F:
	jne [0x05], 0x03, LABEL_921B
	video type=0, offset=CV_5D84, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_921B:
	ret


LABEL_921C:
	video type=0, offset=CV_0CBA, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_3352, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


GUARDED_DRAW_CV_159:
	call LABEL_9179
	jne [0x0A], 0x01, LABEL_9254
	video type=0, offset=CV_347C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5BF8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9254:
	jne [0x0A], 0x02, LABEL_9278
	video type=0, offset=CV_33F2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C0C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9278:
	jne [0x0A], 0x03, LABEL_929C
	video type=0, offset=CV_3420, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_929C:
	video type=0, offset=CV_344E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C1C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92BA:
	video type=0, offset=CV_0D48, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_335C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92CB:
	video type=0, offset=CV_0DB6, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_3366, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92DC:
	video type=0, offset=CV_0E38, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_3370, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92ED:
	video type=0, offset=CV_0EB6, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_337A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_WALK_RIGHT_DRAW_4:
	video type=0, offset=CV_0F28, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_3384, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1:
	call LABEL_91EB
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9329:
	video type=0, offset=CV_0FF8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_3398, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_933A:
	video type=0, offset=CV_1060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_934B:
	video type=0, offset=CV_108C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33AC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_935C:
	video type=0, offset=CV_10B8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33B6, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_936D:
	video type=0, offset=CV_10E4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_937E:
	video type=0, offset=CV_1110, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33CA, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9395:
	video type=0, offset=CV_1136, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33D4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93A6:
	call LABEL_91EB
	video type=0, offset=CV_115C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33DE, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93BA:
	video type=0, offset=CV_117E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_33E8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93CB:
	video type=0, offset=CV_39A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C94, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93E9:
	video type=0, offset=CV_3A64, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C9C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


GUARDED_DRAW_CV_126:
	call LABEL_9179
	jne [0x0A], 0x01, LABEL_9416
	video type=0, offset=CV_35B4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9416:
	jne [0x0A], 0x02, LABEL_9422
	video type=0, offset=CV_35D0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9422:
	jne [0x0A], 0x03, LABEL_942E
	video type=0, offset=CV_35F8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_942E:
	video type=0, offset=CV_3614, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C8C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_DRAW_CV_071_L1:
	jne [0x05], 0x00, LABEL_9458
	video type=0, offset=CV_5DE4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9458:
	jne [0x05], 0x01, LABEL_9464
	video type=0, offset=CV_5DEC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9464:
	jne [0x05], 0x02, LABEL_9470
	video type=0, offset=CV_5E44, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9470:
	jne [0x05], 0x03, LABEL_947C
	video type=0, offset=CV_5E9C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_947C:
	ret


CAPSULE_HERO_WALK_LEFT_DRAW_9:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
