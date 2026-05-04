LABEL_92B8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_060, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_9292
	ret

LABEL_92C7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_7F2C
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_92E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7F2C
	ret

LABEL_92FB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret

LABEL_932A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret

LABEL_9344:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_138, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret

LABEL_936B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_137, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BDC
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_939A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7EAC
	add [0x08], 0x000D
	ret

LABEL_93B4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_248, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_7EDA
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
LABEL_93D6:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x8A
	db 0xAE, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x7F, 0x0C, 0x03, 0x08, 0x00
	db 0x0D, 0x05

LABEL_93F0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7EDA
	add [0x08], 0x000D
	ret
LABEL_940A:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x8A
	db 0xAE, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x05, 0x04
	db 0x92, 0x3A, 0x06, 0x04, 0x92, 0x3A, 0x06, 0x04
	db 0x92, 0x3A, 0x03, 0x07, 0xFF, 0xFF, 0x06, 0x04
	db 0x92, 0x4C, 0x03, 0x07, 0x00, 0x01, 0x06, 0x07
	db 0x94, 0x19, 0x11

LABEL_9435:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_9444
LABEL_943B:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x03, 0x53
	db 0xB1

LABEL_9444:
	call LABEL_8904
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_945B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_945B:
	call LABEL_8931
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_9472
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_9472:
	call LABEL_8956
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_9489
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_9489:
	call LABEL_8983
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_94A0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_94A0:
	call LABEL_89B0
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_94B7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_94B7:
	call LABEL_89D5
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_94CE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_94CE:
	call LABEL_8A02
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_94E5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_94E5:
	call LABEL_8A27
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_94FC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_94FC:
	call LABEL_8A54
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_9513
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_53B1

LABEL_9513:
	call LABEL_8A81
	add [0x07], 0x000A
	break
	jmp LABEL_9435
LABEL_951E:
	db 0x11, 0x04, 0x83, 0xAD, 0x06, 0x07, 0x95, 0x1F
	db 0x11

LABEL_9527:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_9536
LABEL_952D:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x01, 0x53
	db 0xA0

LABEL_9536:
	call LABEL_8CA4
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_954D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_954D:
	call LABEL_8CCA
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9564
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9564:
	call GUARDED_HERO_ANIM_CV_128
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_957B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_957B:
	call LABEL_8D19
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9592
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9592:
	call LABEL_8D40
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_95A9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_95A9:
	call LABEL_8D61
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_95C0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_95C0:
	call LABEL_8D87
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_95D7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_95D7:
	call LABEL_8DAD
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_95EE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_95EE:
	call LABEL_8DD3
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9605
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9605:
	call LABEL_8DF9
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_961C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_961C:
	call LABEL_8E27
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9633
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9633:
	call LABEL_8E4D
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_964A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_964A:
	call LABEL_8E79
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9661
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9661:
	call LABEL_8E9A
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9678
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_9678:
	call LABEL_8EBB
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_968F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_968F:
	call LABEL_8EDC
	add [0x07], 0x0002
	break
	jmp LABEL_9527
LABEL_969A:
	db 0x11

LABEL_969B:
	je [0x0A], [0x0C], KILL_CHAN_AT_96B9
	jg [0x0A], [0x0C], LABEL_96BA

LABEL_96A7:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_96B3
	break

LABEL_96B3:
	jl [0x0A], [0x0C], LABEL_96A7

KILL_CHAN_AT_96B9:
	killChannel

LABEL_96BA:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_96C6
	break

LABEL_96C6:
	jg [0x0A], [0x0C], LABEL_96BA
	killChannel

LABEL_96CD:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_9702
	je [HERO_POS_MASK], 0x00, LABEL_96F0
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_969B
	ret

LABEL_96F0:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_969B

LABEL_9702:
	ret

LABEL_9703:
	video type=0, offset=COMMON_VIDEO_327, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_149__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_149__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_149, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9715:
	video type=0, offset=COMMON_VIDEO_328, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_150__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_329, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_150__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_150, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_973F:
	video type=0, offset=COMMON_VIDEO_330, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_151__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_151__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_151, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9751:
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_175__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_175__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_175, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9763:
	video type=1, offset=CINEMATIC_176, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_177__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_177__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_177, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_978D:
	video type=0, offset=COMMON_VIDEO_350, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_178__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_178__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_178, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_979F:
	jne [0x05], 0x00, LABEL_97AB
	video type=0, offset=COMMON_VIDEO_343, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_97AB:
	jne [0x05], 0x01, LABEL_97B7
	video type=0, offset=COMMON_VIDEO_342, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_97B7:
	jne [0x05], 0x02, LABEL_97C3
	video type=0, offset=COMMON_VIDEO_341, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_97C3:
	jne [0x05], 0x03, LABEL_97CF
	video type=0, offset=COMMON_VIDEO_340, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_97CF:
	ret

LABEL_97D0:
	video type=0, offset=COMMON_VIDEO_074, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_344, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_053:
	call LABEL_96CD
	jne [0x0A], 0x01, LABEL_9808
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9808:
	jne [0x0A], 0x02, LABEL_982C
	video type=0, offset=COMMON_VIDEO_051, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_052, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_982C:
	jne [0x0A], 0x03, LABEL_9850
	video type=0, offset=COMMON_VIDEO_049, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_050, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9850:
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_148__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_048, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_148__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_987A:
	video type=0, offset=COMMON_VIDEO_075, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_345, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_988B:
	video type=0, offset=COMMON_VIDEO_076, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_077, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_989C:
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_079, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_98AD:
	video type=0, offset=COMMON_VIDEO_080, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_081, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_98C4:
	video type=0, offset=COMMON_VIDEO_082, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_083, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_98D5:
	call LABEL_979F
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_98E9:
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_98FA:
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_990B:
	video type=0, offset=COMMON_VIDEO_060, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_061, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_991C:
	video type=0, offset=COMMON_VIDEO_062, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_063, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_992D:
	video type=0, offset=COMMON_VIDEO_064, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_065, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_993E:
	video type=0, offset=COMMON_VIDEO_066, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_067, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9955:
	video type=0, offset=COMMON_VIDEO_068, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_069, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9966:
	call LABEL_979F
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_071, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_997A:
	video type=0, offset=COMMON_VIDEO_072, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_053
	video type=0, offset=COMMON_VIDEO_073, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_998B:
	video type=0, offset=COMMON_VIDEO_334, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_162__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_162__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_162, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_999D:
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_163__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_163__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_163, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_99C7:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_164__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_164__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_164, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_99D9:
	video type=0, offset=COMMON_VIDEO_346, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_171__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_171__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_171, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_99EB:
	video type=0, offset=COMMON_VIDEO_249, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_172__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_250, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_172__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_172, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A15:
	video type=0, offset=COMMON_VIDEO_347, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_173__AMIGA__POST_DECREMENT_VAR08_BY_D
	ret

DRAW_CIN_173__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D:
	call LABEL_96CD
	jne [0x0A], 0x01, LABEL_9A36
	video type=0, offset=COMMON_VIDEO_004, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A36:
	jne [0x0A], 0x02, LABEL_9A42
	video type=0, offset=COMMON_VIDEO_003, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A42:
	jne [0x0A], 0x03, LABEL_9A4E
	video type=0, offset=COMMON_VIDEO_002, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A4E:
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_165__AMIGA__POST_DECREMENT_VAR08_BY_D
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_001, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_165__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=1, offset=CINEMATIC_165, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A78:
	jne [0x05], 0x00, LABEL_9A84
	video type=0, offset=COMMON_VIDEO_006, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A84:
	jne [0x05], 0x01, LABEL_9A90
	video type=0, offset=COMMON_VIDEO_339, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A90:
	jne [0x05], 0x02, LABEL_9A9C
	video type=0, offset=COMMON_VIDEO_005, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A9C:
	jne [0x05], 0x03, LABEL_9AA8
	video type=0, offset=COMMON_VIDEO_338, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AA8:
	ret

LABEL_9AA9:
	je [0x0A], 0x00, DRAW_CV_113__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_113__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_113, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AB8:
	je [0x0A], 0x00, DRAW_CV_114__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_114__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_114, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AC7:
	je [0x0A], 0x00, DRAW_CV_115__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_115__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_115, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AD6:
	je [0x0A], 0x00, DRAW_CV_116__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_116__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_116, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AE5:
	je [0x0A], 0x00, LABEL_9AEE
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9AEE:
	video type=0, offset=COMMON_VIDEO_117, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret

LABEL_9AFA:
	jne [0x0A], 0x00, LABEL_9B08
	video type=0, offset=COMMON_VIDEO_119, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_118__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B08:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_118__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_118, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B11:
	jne [0x0A], 0x00, LABEL_9B1F
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_9B22

LABEL_9B1F:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B22:
	call LABEL_9A78
	video type=0, offset=COMMON_VIDEO_007, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B2B:
	jne [0x0A], 0x00, LABEL_9B39
	video type=0, offset=COMMON_VIDEO_100, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_099__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B39:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_099__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_099, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B42:
	jne [0x0A], 0x00, LABEL_9B50
	video type=0, offset=COMMON_VIDEO_102, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_101__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B50:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_101__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_101, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B59:
	jne [0x0A], 0x00, LABEL_9B67
	video type=0, offset=COMMON_VIDEO_104, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_103__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B67:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_103__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_103, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B70:
	jne [0x0A], 0x00, LABEL_9B7E
	video type=0, offset=COMMON_VIDEO_106, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_105__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B7E:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_105__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_105, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B87:
	jne [0x0A], 0x00, LABEL_9B95
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_107__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9B95:
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_107__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_107, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B9E:
	je [0x0A], 0x00, LABEL_9BA7
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9BA7:
	video type=0, offset=COMMON_VIDEO_109, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret

LABEL_9BB3:
	je [0x0A], 0x00, DRAW_CV_110__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_110__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_110, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BC2:
	call LABEL_9A78
	je [0x0A], 0x00, DRAW_CV_111__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_111__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_111, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BD4:
	je [0x0A], 0x00, DRAW_CV_112__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call GUARDED_DRAW_CV_126__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_112__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_112, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_273__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_273, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_270__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_270, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_252__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_252, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_255__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_255, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_265__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_265, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C01:
	video type=0, offset=COMMON_VIDEO_251, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_253, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C18:
	video type=0, offset=COMMON_VIDEO_254, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_256, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C29:
	video type=0, offset=COMMON_VIDEO_269, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_270__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_271, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C3A:
	video type=0, offset=COMMON_VIDEO_272, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_274, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C4B:
	video type=0, offset=COMMON_VIDEO_275, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_276, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C5C:
	video type=0, offset=COMMON_VIDEO_258, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_259, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C73:
	video type=0, offset=COMMON_VIDEO_260, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_252__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_261, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C84:
	video type=0, offset=COMMON_VIDEO_262, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_263, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C95:
	video type=0, offset=COMMON_VIDEO_264, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_266, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CA6:
	video type=0, offset=COMMON_VIDEO_267, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	video type=0, offset=COMMON_VIDEO_268, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_279, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CBD:
	je [0x0A], 0x00, LABEL_9CC9
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp LABEL_9CCE

LABEL_9CC9:
	video type=0, offset=COMMON_VIDEO_277, x=[0x01], y=[0x02], zoom=0x40

LABEL_9CCE:
	video type=0, offset=COMMON_VIDEO_278, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret

LABEL_9CDA:
	je [0x0A], 0x00, LABEL_9CE6
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_281__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9CE6:
	video type=0, offset=COMMON_VIDEO_280, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_281__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_281, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9CF1:
	je [0x0A], 0x00, LABEL_9CFD
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_294__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9CFD:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_294__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D08:
	je [0x0A], 0x00, LABEL_9D14
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_296__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9D14:
	video type=0, offset=COMMON_VIDEO_295, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_296__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_296, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D1F:
	je [0x0A], 0x00, DRAW_CV_297__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

DRAW_CV_297__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_297, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D2E:
	je [0x0A], 0x00, LABEL_9D3A
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp LABEL_9D3F

LABEL_9D3A:
	video type=0, offset=COMMON_VIDEO_283, x=[0x01], y=[0x02], zoom=0x40

LABEL_9D3F:
	video type=0, offset=COMMON_VIDEO_284, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret

LABEL_9D4B:
	je [0x0A], 0x00, LABEL_9D57
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_286__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9D57:
	video type=0, offset=COMMON_VIDEO_285, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_286__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_286, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D62:
	je [0x0A], 0x00, LABEL_9D6E
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_288__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9D6E:
	video type=0, offset=COMMON_VIDEO_287, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_288__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_288, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D79:
	je [0x0A], 0x00, LABEL_9D85
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_290__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9D85:
	video type=0, offset=COMMON_VIDEO_289, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_290__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_290, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D90:
	je [0x0A], 0x00, LABEL_9D9C
	call DRAW_CV_279__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D
	jmp DRAW_CV_292__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D

LABEL_9D9C:
	video type=0, offset=COMMON_VIDEO_291, x=[0x01], y=[0x02], zoom=0x40

DRAW_CV_292__AMIGA__POST_DECREMENT_VAR08_BY_D__AMIGA__POST_DECREMENT_VAR08_BY_D:
	video type=0, offset=COMMON_VIDEO_292, x=[0x01], y=[0x02], zoom=0x40
	ret
LABEL_9DA7:
	db 0x0A, 0x00, 0x1F, 0x00, 0x9D, 0xD6, 0x0A, 0x04
	db 0x1E, 0x00, 0x9D, 0xC5, 0x00, 0x20, 0xFF, 0xFF
	db 0x13, 0x1E, 0x1F, 0x03, 0x20, 0x00, 0x01, 0x0A
	db 0x03, 0x1E, 0x00, 0x9D, 0xB7, 0x05, 0x00, 0x20
	db 0x00, 0x01, 0x02, 0x1E, 0x1F, 0x03, 0x20, 0xFF
	db 0xFF, 0x0A, 0x05, 0x1E, 0x00, 0x9D, 0xC9, 0x05
	db 0x11, 0x0A, 0x81, 0x67, 0x65, 0x9D, 0xF3, 0x0F
	db 0x03, 0xFF, 0x0F, 0x00, 0x03, 0x0F, 0xFF, 0x00
	db 0x01, 0x67, 0x65, 0x01, 0x65, 0x66, 0x01, 0x66
	db 0x67, 0x07, 0x9D, 0xF9, 0x0F, 0x00, 0x03, 0x01
	db 0x65, 0x66, 0x05

LABEL_9DFA:
	jg [0x02], [0x51], COPY_VAR51_TO_VAR02_KILL_CHANNEL
	add [0x02], 0x0001
	break
	jmp LABEL_9DFA
