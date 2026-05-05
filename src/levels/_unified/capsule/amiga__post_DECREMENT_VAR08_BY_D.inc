LABEL_73A4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_207, x=[0x07], y=[0x08]
	call LABEL_737E
	ret

LABEL_73B3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_5FC4
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_73D5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5FC4
	ret

LABEL_73E7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6C8A
	sub [0x08], 0x000D
	ret

LABEL_7416:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6C8A
	sub [0x08], 0x000D
	ret

LABEL_7430:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_273, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6C8A
	sub [0x08], 0x000D
	ret

LABEL_7457:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_272, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6C74
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_7486:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5F44
	add [0x08], 0x000D
	ret

LABEL_74A0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_248, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_5F72
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
LABEL_74C2:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x6B
	db 0x46, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x5F, 0xA4, 0x03, 0x08, 0x00
	db 0x0D, 0x05

LABEL_74DC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5F72
	add [0x08], 0x000D
	ret
LABEL_74F6:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x6B
	db 0x46, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x05, 0x04
	db 0x73, 0x26, 0x06, 0x04, 0x73, 0x26, 0x06, 0x04
	db 0x73, 0x26, 0x03, 0x07, 0xFF, 0xFF, 0x06, 0x04
	db 0x73, 0x38, 0x03, 0x07, 0x00, 0x01, 0x06, 0x07
	db 0x75, 0x05, 0x11

LABEL_7521:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_7530
LABEL_7527:
	db 0x04, 0x3B, 0x79, 0x0A, 0x01, 0x2F, 0x03, 0x35
	db 0x7C

LABEL_7530:
	call LABEL_699C
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_7547
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_7547:
	call LABEL_69C9
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_755E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_755E:
	call LABEL_69EE
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_7575
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_7575:
	call LABEL_6A1B
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_758C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_758C:
	call LABEL_6A48
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_75A3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_75A3:
	call LABEL_6A6D
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_75BA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_75BA:
	call LABEL_6A9A
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_75D1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_75D1:
	call LABEL_6ABF
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_75E8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_75E8:
	call LABEL_6AEC
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_75FF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_357C

LABEL_75FF:
	call LABEL_6B19
	add [0x07], 0x000A
	break
	jmp LABEL_7521
LABEL_760A:
	db 0x11, 0x04, 0x64, 0x45, 0x06, 0x07, 0x76, 0x0B
	db 0x11

LABEL_7613:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_7622
LABEL_7619:
	db 0x04, 0x3B, 0x79, 0x0A, 0x01, 0x2F, 0x01, 0x35
	db 0x6B

LABEL_7622:
	call LABEL_6D3C
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_7639
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7639:
	call LABEL_6D62
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_7650
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7650:
	call LABEL_6D90
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_7667
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7667:
	call LABEL_6DB1
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_767E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_767E:
	call LABEL_6DD8
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_7695
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7695:
	call LABEL_6DF9
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_76AC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_76AC:
	call LABEL_6E1F
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_76C3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_76C3:
	call LABEL_6E45
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_76DA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_76DA:
	call LABEL_6E6B
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_76F1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_76F1:
	call LABEL_6E91
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_7708
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7708:
	call LABEL_6EBF
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_771F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_771F:
	call LABEL_6EE5
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_7736
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7736:
	call LABEL_6F11
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_774D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_774D:
	call LABEL_6F32
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_7764
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_7764:
	call LABEL_6F53
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_777B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, LABEL_356B

LABEL_777B:
	call LABEL_6F74
	add [0x07], 0x0002
	break
	jmp LABEL_7613
LABEL_7786:
	db 0x11

LABEL_7787:
	je [0x0A], [0x0C], KILL_CHAN_AT_77A5
	jg [0x0A], [0x0C], LABEL_77A6

LABEL_7793:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_779F
	break

LABEL_779F:
	jl [0x0A], [0x0C], LABEL_7793

KILL_CHAN_AT_77A5:
	killChannel

LABEL_77A6:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_77B2
	break

LABEL_77B2:
	jg [0x0A], [0x0C], LABEL_77A6
	killChannel

LABEL_77B9:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_77EE
	je [HERO_POS_MASK], 0x00, LABEL_77DC
	call LABEL_239C
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_7787
	ret

LABEL_77DC:
	call LABEL_239C
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_7787

LABEL_77EE:
	ret

LABEL_77EF:
	video type=0, offset=COMMON_VIDEO_328, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_329, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_780D:
	video offset=CINEMATIC_118, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_782B:
	jne [0x05], 0x00, LABEL_7837
	video type=0, offset=COMMON_VIDEO_343, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7837:
	jne [0x05], 0x01, LABEL_7843
	video type=0, offset=COMMON_VIDEO_342, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7843:
	jne [0x05], 0x02, LABEL_784F
	video type=0, offset=COMMON_VIDEO_341, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_784F:
	jne [0x05], 0x03, LABEL_785B
	video type=0, offset=COMMON_VIDEO_340, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_785B:
	ret

LABEL_785C:
	video type=0, offset=COMMON_VIDEO_074, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_344, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_786D:
	call LABEL_77B9
	jne [0x0A], 0x01, LABEL_7894
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7894:
	jne [0x0A], 0x02, LABEL_78B8
	video type=0, offset=COMMON_VIDEO_051, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_052, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_78B8:
	jne [0x0A], 0x03, LABEL_78DC
	video type=0, offset=COMMON_VIDEO_049, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_050, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_78DC:
	video type=0, offset=COMMON_VIDEO_047, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_048, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_78FA:
	video type=0, offset=COMMON_VIDEO_075, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_345, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_790B:
	video type=0, offset=COMMON_VIDEO_076, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_077, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_791C:
	video type=0, offset=COMMON_VIDEO_078, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_079, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_792D:
	video type=0, offset=COMMON_VIDEO_080, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_081, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7944:
	video type=0, offset=COMMON_VIDEO_082, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_083, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7955:
	call LABEL_782B
	video type=0, offset=COMMON_VIDEO_046, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7969:
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_797A:
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_798B:
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_061, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_799C:
	video type=0, offset=COMMON_VIDEO_062, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_063, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_79AD:
	video type=0, offset=COMMON_VIDEO_064, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_065, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_79BE:
	video type=0, offset=COMMON_VIDEO_066, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_067, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_79D5:
	video type=0, offset=COMMON_VIDEO_068, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_069, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_79E6:
	call LABEL_782B
	video type=0, offset=COMMON_VIDEO_070, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_071, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_79FA:
	video type=0, offset=COMMON_VIDEO_072, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, LABEL_786D
	video type=0, offset=COMMON_VIDEO_073, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A0B:
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A29:
	video type=0, offset=COMMON_VIDEO_249, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_250, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A47:
	call LABEL_77B9
	jne [0x0A], 0x01, LABEL_7A56
	video type=0, offset=COMMON_VIDEO_004, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A56:
	jne [0x0A], 0x02, LABEL_7A62
	video type=0, offset=COMMON_VIDEO_003, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A62:
	jne [0x0A], 0x03, LABEL_7A6E
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A6E:
	video type=0, offset=COMMON_VIDEO_000, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A8C:
	jne [0x05], 0x00, LABEL_7A98
	video type=0, offset=COMMON_VIDEO_006, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7A98:
	jne [0x05], 0x01, LABEL_7AA4
	video type=0, offset=COMMON_VIDEO_339, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7AA4:
	jne [0x05], 0x02, LABEL_7AB0
	video type=0, offset=COMMON_VIDEO_005, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7AB0:
	jne [0x05], 0x03, LABEL_7ABC
	video type=0, offset=COMMON_VIDEO_338, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7ABC:
	ret

LABEL_7ABD:
	je [0x0A], 0x00, DRAW_CV_113
	call LABEL_7A47

DRAW_CV_113:
	video type=0, offset=COMMON_VIDEO_113, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7ACC:
	je [0x0A], 0x00, DRAW_CV_114
	call LABEL_7A47

DRAW_CV_114:
	video type=0, offset=COMMON_VIDEO_114, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7ADB:
	je [0x0A], 0x00, DRAW_CV_115
	call LABEL_7A47

DRAW_CV_115:
	video type=0, offset=COMMON_VIDEO_115, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7AEA:
	je [0x0A], 0x00, DRAW_CV_116
	call LABEL_7A47

DRAW_CV_116:
	video type=0, offset=COMMON_VIDEO_116, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7AF9:
	je [0x0A], 0x00, LABEL_7B02
	call LABEL_7A47

LABEL_7B02:
	video type=0, offset=COMMON_VIDEO_117, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret

LABEL_7B0E:
	jne [0x0A], 0x00, LABEL_7B1C
	video type=0, offset=COMMON_VIDEO_119, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_118

LABEL_7B1C:
	call LABEL_7A47

DRAW_CV_118:
	video type=0, offset=COMMON_VIDEO_118, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B25:
	jne [0x0A], 0x00, LABEL_7B33
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_7B36

LABEL_7B33:
	call LABEL_7A47

LABEL_7B36:
	call LABEL_7A8C
	video type=0, offset=COMMON_VIDEO_007, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B3F:
	jne [0x0A], 0x00, LABEL_7B4D
	video type=0, offset=COMMON_VIDEO_100, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_099

LABEL_7B4D:
	call LABEL_7A47

DRAW_CV_099:
	video type=0, offset=COMMON_VIDEO_099, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B56:
	jne [0x0A], 0x00, LABEL_7B64
	video type=0, offset=COMMON_VIDEO_102, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_101

LABEL_7B64:
	call LABEL_7A47

DRAW_CV_101:
	video type=0, offset=COMMON_VIDEO_101, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B6D:
	jne [0x0A], 0x00, LABEL_7B7B
	video type=0, offset=COMMON_VIDEO_104, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_103

LABEL_7B7B:
	call LABEL_7A47

DRAW_CV_103:
	video type=0, offset=COMMON_VIDEO_103, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B84:
	jne [0x0A], 0x00, LABEL_7B92
	video type=0, offset=COMMON_VIDEO_106, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_105

LABEL_7B92:
	call LABEL_7A47

DRAW_CV_105:
	video type=0, offset=COMMON_VIDEO_105, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7B9B:
	jne [0x0A], 0x00, LABEL_7BA9
	video type=0, offset=COMMON_VIDEO_108, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_107

LABEL_7BA9:
	call LABEL_7A47

DRAW_CV_107:
	video type=0, offset=COMMON_VIDEO_107, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7BB2:
	je [0x0A], 0x00, LABEL_7BBB
	call LABEL_7A47

LABEL_7BBB:
	video type=0, offset=COMMON_VIDEO_109, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret

LABEL_7BC7:
	je [0x0A], 0x00, DRAW_CV_110
	call LABEL_7A47

DRAW_CV_110:
	video type=0, offset=COMMON_VIDEO_110, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7BD6:
	call LABEL_7A8C
	je [0x0A], 0x00, DRAW_CV_111
	call LABEL_7A47

DRAW_CV_111:
	video type=0, offset=COMMON_VIDEO_111, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7BE8:
	je [0x0A], 0x00, DRAW_CV_112
	call LABEL_7A47

DRAW_CV_112:
	video type=0, offset=COMMON_VIDEO_112, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_273:
	video type=0, offset=COMMON_VIDEO_273, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_270:
	video type=0, offset=COMMON_VIDEO_270, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_252:
	video type=0, offset=COMMON_VIDEO_252, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_255:
	video type=0, offset=COMMON_VIDEO_255, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_265:
	video type=0, offset=COMMON_VIDEO_265, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C15:
	video type=0, offset=COMMON_VIDEO_251, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_253, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C2C:
	video type=0, offset=COMMON_VIDEO_254, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=COMMON_VIDEO_256, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C3D:
	video type=0, offset=COMMON_VIDEO_269, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_270
	video type=0, offset=COMMON_VIDEO_271, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C4E:
	video type=0, offset=COMMON_VIDEO_272, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=COMMON_VIDEO_274, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C5F:
	video type=0, offset=COMMON_VIDEO_275, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=COMMON_VIDEO_276, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C70:
	video type=0, offset=COMMON_VIDEO_258, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_259, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C87:
	video type=0, offset=COMMON_VIDEO_260, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_261, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7C98:
	video type=0, offset=COMMON_VIDEO_262, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=COMMON_VIDEO_263, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7CA9:
	video type=0, offset=COMMON_VIDEO_264, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=COMMON_VIDEO_266, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7CBA:
	video type=0, offset=COMMON_VIDEO_267, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=COMMON_VIDEO_268, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_279:
	video type=0, offset=COMMON_VIDEO_279, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7CD1:
	je [0x0A], 0x00, LABEL_7CDD
	call DRAW_CV_279
	jmp LABEL_7CE2

LABEL_7CDD:
	video type=0, offset=COMMON_VIDEO_277, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_7CE2:
	video type=0, offset=COMMON_VIDEO_278, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret

LABEL_7CEE:
	je [0x0A], 0x00, LABEL_7CFA
	call DRAW_CV_279
	jmp DRAW_CV_281

LABEL_7CFA:
	video type=0, offset=COMMON_VIDEO_280, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_281:
	video type=0, offset=COMMON_VIDEO_281, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D05:
	je [0x0A], 0x00, LABEL_7D11
	call DRAW_CV_279
	jmp DRAW_CV_294

LABEL_7D11:
	video type=0, offset=COMMON_VIDEO_293, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_294:
	video type=0, offset=COMMON_VIDEO_294, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D1C:
	je [0x0A], 0x00, LABEL_7D28
	call DRAW_CV_279
	jmp DRAW_CV_296

LABEL_7D28:
	video type=0, offset=COMMON_VIDEO_295, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_296:
	video type=0, offset=COMMON_VIDEO_296, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D33:
	je [0x0A], 0x00, DRAW_CV_297
	call DRAW_CV_279

DRAW_CV_297:
	video type=0, offset=COMMON_VIDEO_297, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D42:
	je [0x0A], 0x00, LABEL_7D4E
	call DRAW_CV_279
	jmp LABEL_7D53

LABEL_7D4E:
	video type=0, offset=COMMON_VIDEO_283, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_7D53:
	video type=0, offset=COMMON_VIDEO_284, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret

LABEL_7D5F:
	je [0x0A], 0x00, LABEL_7D6B
	call DRAW_CV_279
	jmp DRAW_CV_286

LABEL_7D6B:
	video type=0, offset=COMMON_VIDEO_285, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_286:
	video type=0, offset=COMMON_VIDEO_286, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D76:
	je [0x0A], 0x00, LABEL_7D82
	call DRAW_CV_279
	jmp DRAW_CV_288

LABEL_7D82:
	video type=0, offset=COMMON_VIDEO_287, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_288:
	video type=0, offset=COMMON_VIDEO_288, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7D8D:
	je [0x0A], 0x00, LABEL_7D99
	call DRAW_CV_279
	jmp DRAW_CV_290

LABEL_7D99:
	video type=0, offset=COMMON_VIDEO_289, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_290:
	video type=0, offset=COMMON_VIDEO_290, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7DA4:
	je [0x0A], 0x00, LABEL_7DB0
	call DRAW_CV_279
	jmp DRAW_CV_292

LABEL_7DB0:
	video type=0, offset=COMMON_VIDEO_291, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_292:
	video type=0, offset=COMMON_VIDEO_292, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
LABEL_7DBB:
	db 0x0A, 0x00, 0x1F, 0x00, 0x7D, 0xEA, 0x0A, 0x04
	db 0x1E, 0x00, 0x7D, 0xD9, 0x00, 0x20, 0xFF, 0xFF
	db 0x13, 0x1E, 0x1F, 0x03, 0x20, 0x00, 0x01, 0x0A
	db 0x03, 0x1E, 0x00, 0x7D, 0xCB, 0x05, 0x00, 0x20
	db 0x00, 0x01, 0x02, 0x1E, 0x1F, 0x03, 0x20, 0xFF
	db 0xFF, 0x0A, 0x05, 0x1E, 0x00, 0x7D, 0xDD, 0x05
	db 0x11, 0x0A, 0x81, 0x67, 0x65, 0x7E, 0x07, 0x0F
	db 0x03, 0xFF, 0x0F, 0x00, 0x03, 0x0F, 0xFF, 0x00
	db 0x01, 0x67, 0x65, 0x01, 0x65, 0x66, 0x01, 0x66
	db 0x67, 0x07, 0x7E, 0x0D, 0x0F, 0x00, 0x03, 0x01
	db 0x65, 0x66, 0x05

LABEL_7E0E:
	jg [HERO_Y], [0x51], COPY_VAR51_TO_VAR02_KILL_CHANNEL
	add [HERO_Y], 0x0001
	break
	jmp LABEL_7E0E
