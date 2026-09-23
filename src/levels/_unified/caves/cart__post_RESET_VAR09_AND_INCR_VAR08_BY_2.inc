DISPATCH_VAR09_OR_KILL_CHAN:
	je [0x09], 0x01, LABEL_30B6
	je [0x09], 0x02, LABEL_3085
	killChannel

LABEL_2F33:
	mov [0x09], 0x0000
	mov [0x21], [0x07]
	mov [0x22], [0x07]
	sub [0x21], 0x000A
	add [0x22], 0x000A
	jl [HERO_X], [0x21], SHARED_RET
	jg [HERO_X], [0x22], SHARED_RET
	mov [0x21], [0x08]
	mov [0x22], [0x08]
	add [0x22], 0x005A
	jl [HERO_Y], [0x21], SHARED_RET
	jg [HERO_Y], [0x22], SHARED_RET
	sub [0x22], 0x0014
	mov [0x09], 0x0002
	jl [HERO_Y], [0x22], LABEL_2F8E
	je [0x63], 0x05, SHARED_RET
	je [0x63], 0x06, SHARED_RET
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET

LABEL_2F8E:
	mov [0x09], 0x0000
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	mov [0x09], 0x0001
	ret


LABEL_2FA2:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_709, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_710, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_711, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_712, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_713, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_0, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_1, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_2, x=[0x07], y=[0x08]
	break

LABEL_3002:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F6, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F7, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_0, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_1, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_2, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_708, x=[0x07], y=[0x08]
	break
	jmp LABEL_2FA2
LABEL_304D:
	db 0x11

CAVES_INIT_VARS_6D_71_70_L15:
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F13, x=[0x07], y=[0x08]
	mov [0x6C], [0x07]
	mov [0x6D], [0x08]
	add [0x6D], 0x0028
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F5, x=[0x07], y=[0x08]
	sub [0x6D], 0x000C
	break
	video offset=CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F1, x=[0x07], y=[0x08]
	sub [0x6D], 0x000A
	break
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F1, x=[0x07], y=[0x08]
	sub [0x6D], 0x000A

LABEL_307B:
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F10, x=[0x07], y=[0x08]
	jmp LABEL_307B
LABEL_3084:
	db 0x11

LABEL_3085:
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F11, x=[0x07], y=[0x08]
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F5, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F11, x=[0x07], y=[0x08]
	break
	jmp LABEL_2FA2
	killChannel
	video offset=CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F1, x=[0x07], y=[0x08]

LABEL_30AC:
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F10, x=[0x07], y=[0x08]
	jmp LABEL_30AC
LABEL_30B5:
	db 0x11

LABEL_30B6:
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F11, x=[0x07], y=[0x08]
	song id=0x0BDD, delay=0x0000, pos=0x00
	or [0x04], 0x4000
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F12, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F13, x=[0x07], y=[0x08]
	deleteChannels first=0x14, last=0x16
	break
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F14, x=[0x07], y=[0x08]
	break
	jne [0xDB], 0x00, LABEL_3127
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F2, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F5, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F2, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F4, x=[0x07], y=[0x08]
	jmp LABEL_0EF9
LABEL_3126:
	db 0x06

LABEL_3127:
	video offset=CINEMATIC_CAVES_BURST_CHUNKS_F0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_BURST_CHUNKS_F0, x=[0x07], y=[0x08]
	jmp LABEL_0EF9
LABEL_3135:
	db 0x11

LABEL_3136:
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=160, y=[0xe6]
	break
	jmp LABEL_3136
LABEL_315D:
	db 0x11

LABEL_315E:
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=157, y=54
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=157, y=54
	break
	video offset=CINEMATIC_557, x=157, y=54
	break
	video offset=CINEMATIC_557, x=157, y=54
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=157, y=54
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=157, y=54
	break
	jmp LABEL_315E
LABEL_317F:
	db 0x11

LABEL_3180:
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=140, y=[0xe6]
	break
	jmp LABEL_3180
LABEL_31A7:
	db 0x11

HANG_DRAW_CIN_734_VAR09_GUARD:
	jne [0x09], 0x00, LABEL_2A2D
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]
	break
	jmp HANG_DRAW_CIN_734_VAR09_GUARD
LABEL_31B7:
	db 0x11

LABEL_31B8:
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_7, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A2D
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_7, x=[0x07], y=[0x08]
	break
	jmp LABEL_31B8
LABEL_3221:
	db 0x11

LABEL_3222:
	or [0x04], 0x4000
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]
	deleteChannels first=0x14, last=0x16
	break
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_735, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_737, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0, x=[0x07], y=[0x08]
	break
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_5, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0, x=[0x07], y=[0x08]
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_6, x=[0x07], y=[0x08]
	jmp LABEL_0EF9
LABEL_328B:
	db 0x11

LABEL_328C:
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=56, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F0, x=58, y=103
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F0, x=56, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=57, y=101
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F1, x=56, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F1, x=59, y=102
	break
	jmp LABEL_328C
LABEL_32AA:
	db 0x11

LABEL_32AB:
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=56, y=110
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F0, x=58, y=115
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F0, x=56, y=110
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=57, y=113
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F1, x=56, y=110
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F1, x=59, y=114
	break
	jmp LABEL_32AB
LABEL_32C9:
	db 0x11

LABEL_32CA:
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F5, x=130, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F6, x=230, y=100
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F7, x=130, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F7, x=230, y=100
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F6, x=130, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F5, x=230, y=100
	break
	jmp LABEL_32CA
LABEL_32E8:
	db 0x11

LABEL_32E9:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_32F3:
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xee], y=100
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xee], y=100
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xee], y=100
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F4, x=[0xee], y=100
	break
	jmp LABEL_32F3
LABEL_330E:
	db 0x11

LABEL_330F:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_3319:
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xee], y=89
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xee], y=89
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xee], y=89
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F4, x=[0xee], y=89
	break
	jmp LABEL_3319
LABEL_3334:
	db 0x11

LABEL_3335:
	mov [0xEF], 0x004B
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xef], y=75
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xef], y=75
	break
	video offset=CINEMATIC_411, x=[0xef], y=75
	break
	video offset=CINEMATIC_412, x=[0xef], y=75
	break
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_0, x=[0xef], y=70
	break
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_1, x=[0xef], y=80
	break
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_0, x=[0xef], y=120
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xef], y=65
	break
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_1, x=[0xef], y=140
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xef], y=60
	break
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_1, x=[0xef], y=200
	break
	mov [0xEF], 0x0001
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]

DELAY_LOOP_VAREF:
	break
	djnz [0xEF], DELAY_LOOP_VAREF
	jmp LABEL_3335

LABEL_3391:
	mov [0xEC], 0x0039
	mov [0xED], 0x0014
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEC], [0x3A]
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xED], [0x3E]
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F8, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_310, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_311, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_312, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_313, x=[0xec], y=[0xed]
	mov [0xEC], 0x000A

DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	jmp LABEL_3391
LABEL_33CE:
	db 0x11
