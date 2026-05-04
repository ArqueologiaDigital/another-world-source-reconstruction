LABEL_9616:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_060, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_95F0
	ret

LABEL_9625:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_828A
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_9647:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_828A
	ret

LABEL_9659:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8F50
	sub [0x08], 0x000D
	ret

LABEL_9688:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8F50
	sub [0x08], 0x000D
	ret

LABEL_96A2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_138, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8F50
	sub [0x08], 0x000D
	ret

LABEL_96C9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_137, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8F3A
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_96F8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_820A
	add [0x08], 0x000D
	ret

LABEL_9712:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_292, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_8238
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_826A
	add [0x08], 0x000D
	ret

LABEL_974E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8238
	add [0x08], 0x000D
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__9777:
	call LABEL_9598
	break
	call LABEL_9598
	break
	call LABEL_9598
	sub [0x07], 0x0001
	break
	call LABEL_95AA
	add [0x07], 0x0001
	break
	jmp JUNK__9777
LABEL_9792:
	db 0x11

LABEL_9793:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_97A2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_97A2:
	call LABEL_8C62
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_97B9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_97B9:
	call LABEL_8C8F
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97D0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_97D0:
	call LABEL_8CB4
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97E7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_97E7:
	call LABEL_8CE1
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_97FE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_97FE:
	call LABEL_8D0E
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_9815
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_9815:
	call LABEL_8D33
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_982C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_982C:
	call LABEL_8D60
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_9843
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_9843:
	call LABEL_8D85
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_985A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_985A:
	call LABEL_8DB2
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_9871
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_56D4

LABEL_9871:
	call LABEL_8DDF
	add [0x07], 0x000A
	break
	jmp LABEL_9793
	killChannel

LABEL_987D:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_987D
LABEL_9884:
	db 0x11

LABEL_9885:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_9894
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9894:
	call LABEL_9002
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98AB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_98AB:
	call LABEL_9028
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98C2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_98C2:
	call LABEL_9056
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_98D9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_98D9:
	call LABEL_9077
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_98F0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_98F0:
	call LABEL_909E
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9907
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9907:
	call LABEL_90BF
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_991E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_991E:
	call LABEL_90E5
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9935
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9935:
	call LABEL_910B
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_994C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_994C:
	call LABEL_9131
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9963
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9963:
	call LABEL_9157
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_997A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_997A:
	call LABEL_9185
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9991
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9991:
	call LABEL_91AB
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_99A8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_99A8:
	call LABEL_91D7
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_99BF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_99BF:
	call LABEL_91F8
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_99D6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_99D6:
	call LABEL_9219
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_99ED
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_99ED:
	call LABEL_923A
	add [0x07], 0x0002
	break
	jmp LABEL_9885
LABEL_99F8:
	db 0x11

LABEL_99F9:
	je [0x0A], [0x0C], KILL_CHAN_AT_9A17
	jg [0x0A], [0x0C], LABEL_9A18

LABEL_9A05:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_9A11
	break

LABEL_9A11:
	jl [0x0A], [0x0C], LABEL_9A05

KILL_CHAN_AT_9A17:
	killChannel

LABEL_9A18:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_9A24
	break

LABEL_9A24:
	jg [0x0A], [0x0C], LABEL_9A18
	killChannel

LABEL_9A2B:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_9A60
	je [HERO_POS_MASK], 0x00, LABEL_9A4E
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_99F9
	ret

LABEL_9A4E:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_99F9

LABEL_9A60:
	ret

LABEL_9A61:
	video type=0, offset=COMMON_VIDEO_330, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_149__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_149__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_149, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A73:
	video type=0, offset=COMMON_VIDEO_331, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_150__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_332, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_150__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_150, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A9D:
	video type=0, offset=COMMON_VIDEO_333, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_151__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_151__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_151, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AAF:
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_175__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_175__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_175, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AC1:
	video type=1, offset=CINEMATIC_176, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_177__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_177__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_177, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AEB:
	video type=0, offset=COMMON_VIDEO_350, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_178__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_178__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_178, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AFD:
	jne [0x05], 0x00, LABEL_9B09
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B09:
	jne [0x05], 0x01, LABEL_9B15
	video type=0, offset=COMMON_VIDEO_345, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B15:
	jne [0x05], 0x02, LABEL_9B21
	video type=0, offset=COMMON_VIDEO_344, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B21:
	jne [0x05], 0x03, LABEL_9B2D
	video type=0, offset=COMMON_VIDEO_343, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B2D:
	ret

LABEL_9B2E:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_037, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D:
	call LABEL_9A2B
	jne [0x0A], 0x01, LABEL_9B66
	video type=0, offset=COMMON_VIDEO_159, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B66:
	jne [0x0A], 0x02, LABEL_9B8A
	video type=0, offset=COMMON_VIDEO_157, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B8A:
	jne [0x0A], 0x03, LABEL_9BAE
	video type=0, offset=COMMON_VIDEO_155, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BAE:
	video type=0, offset=COMMON_VIDEO_153, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_148__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_148__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BD8:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_039, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BE9:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BFA:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C0B:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C22:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C33:
	call LABEL_9AFD
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C47:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C58:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C69:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C7A:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C8B:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C9C:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CB3:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CC4:
	call LABEL_9AFD
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CD8:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159__DOS__POST_DECREMENT_VAR08_BY_D__DOS__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CE9:
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_162__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_162__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_162, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CFB:
	video type=0, offset=COMMON_VIDEO_131, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_163__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_163__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_163, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D25:
	video type=0, offset=COMMON_VIDEO_338, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_164__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_164__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_164, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D37:
	video type=0, offset=COMMON_VIDEO_346, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_171__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_171__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_171, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D49:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_172__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_172__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_172, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D73:
	video type=0, offset=COMMON_VIDEO_347, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_173__DOS__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_173__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_9A2B
	jne [0x0A], 0x01, LABEL_9D94
	video type=0, offset=COMMON_VIDEO_126, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D94:
	jne [0x0A], 0x02, LABEL_9DA0
	video type=0, offset=COMMON_VIDEO_125, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DA0:
	jne [0x0A], 0x03, LABEL_9DAC
	video type=0, offset=COMMON_VIDEO_124, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DAC:
	video type=0, offset=COMMON_VIDEO_122, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_165__DOS__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_165__DOS__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_165, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DD6:
	jne [0x05], 0x00, LABEL_9DE2
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DE2:
	jne [0x05], 0x01, LABEL_9DEE
	video type=0, offset=COMMON_VIDEO_342, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DEE:
	jne [0x05], 0x02, LABEL_9DFA
	video type=0, offset=COMMON_VIDEO_127, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9DFA:
	jne [0x05], 0x03, LABEL_9E06
	video type=0, offset=COMMON_VIDEO_341, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9E06:
	ret

LABEL_9E07:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
