LABEL_0AE3:
	video offset=CINEMATIC_597, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jl [0x01], 0xB4, LABEL_0AE3
	video offset=CINEMATIC_616, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_617, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_618, x=[0xe6], y=[0xe7], zoom=0x40
	break
	play id=0x0030, freq=0x0A, vol=0x40, channel=0x03
	video offset=CINEMATIC_619, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_619, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_618, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_619, x=[0xe6], y=[0xe7], zoom=0x40
	play id=0x0030, freq=0x20, vol=0x20, channel=0x03
	break
	video offset=CINEMATIC_618, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_617, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_616, x=[0xe6], y=[0xe7], zoom=0x40
	call LABEL_3240
	mov [0xE8], 0x0001
	add [0xE8], [0x3A]

LABEL_0B40:
	break
	video offset=CINEMATIC_597, x=[0xe6], y=[0xe7], zoom=0x40
	djnz [0xE8], LABEL_0B40
	jmp INIT_VARS_E6_E7

LABEL_0B4D:
	video offset=CINEMATIC_598, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jl [0x01], 0xB4, LABEL_0B4D
	video offset=CINEMATIC_614, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_599, x=[0xe6], y=[0xe7], zoom=0x40
	break
	mov [0xE9], 0x000A

ANIM_CIN_615_LOOP_VARE9:
	video offset=CINEMATIC_615, x=[0xe6], y=[0xe7], zoom=0x40
	break
	djnz [0xE9], ANIM_CIN_615_LOOP_VARE9
	video offset=CINEMATIC_599, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_614, x=[0xe6], y=[0xe7], zoom=0x40
	break
	call LABEL_3240
	mov [0xE9], [0x39]
	add [0xE9], 0x0002

ANIM_CIN_598_LOOP_VARE9:
	video offset=CINEMATIC_598, x=[0xe6], y=[0xe7], zoom=0x40
	break
	djnz [0xE9], ANIM_CIN_598_LOOP_VARE9
	jmp LABEL_0B4D
LABEL_0B96:
	db 0x11

LABEL_0B97:
	break
	jne [HACK_VAR_67], 0xCA, LABEL_0B97
	jg [0x01], 0x6E, LABEL_0BC1
	mov [0xF8], [0xB9]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, LABEL_0BC7
	call LABEL_53FF
	je [0x21], 0x00, LABEL_0B97
	or [0xB9], 0x0004
	jmp LABEL_0BC7

LABEL_0BC1:
	song id=0x0BD4, delay=0x0000, pos=0x00

LABEL_0BC7:
	break
	call LABEL_3240
	jg [0x01], 0xE0, LABEL_0BC7
	jg [0x01], 0x6E, LABEL_0BFD
	jl [0x01], 0x0A, LABEL_0BC7
	jl [0x01], 0x14, LABEL_0BE9
	jl [0x01], 0x4C, LABEL_0BC7

LABEL_0BE9:
	mov [0xE6], 0x0048
	add [0xB8], 0x0008
	add [0xE6], [0x39]
	play id=0x0052, freq=0x16, vol=0x40, channel=0x03
	jmp LABEL_0C48

LABEL_0BFD:
	mov [0xE6], [0x01]
	play id=0x0052, freq=0x14, vol=0x40, channel=0x03
	add [0xB8], 0x0008
	video offset=CINEMATIC_320, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_299, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_320, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0003
	jg [0x01], [0xF8], LABEL_0C2A
	call LABEL_0C89

LABEL_0C2A:
	break
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x007F
	or [0x97], 0x4000
	video offset=CINEMATIC_299, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_300, x=[0xe6], y=100, zoom=0x40
	jmp LABEL_0BC7

LABEL_0C48:
	video offset=CINEMATIC_582, x=[0xe6], y=100, zoom=0x40
	break
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x007F
	video offset=CINEMATIC_583, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_582, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0003
	jl [0x01], [0xF8], LABEL_0C73
	call LABEL_0C89

LABEL_0C73:
	break
	video offset=CINEMATIC_300, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_583, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_300, x=[0xe6], y=100, zoom=0x40
	break
	break
	jmp LABEL_0BC7

LABEL_0C89:
	jl [0x04], 0x4000, LABEL_5F5D
	ret
	killChannel

LABEL_0C92:
	mov [0xE6], 0x000A

LABEL_0C96:
	mov [0xE7], 0x0072
	add [0xE7], [0xE6]
	mov [0xE8], 0x0004
	video offset=CINEMATIC_578, x=73, y=[0xe7], zoom=0x40
	video offset=CINEMATIC_578, x=263, y=[0xe7], zoom=0x40
	add [0xE7], 0x0003
	video offset=CINEMATIC_578, x=175, y=[0xe7], zoom=0x40
	video offset=CINEMATIC_579, x=73, y=124
	video offset=CINEMATIC_579, x=175, y=127
	video offset=CINEMATIC_579, x=263, y=124, zoom=0x40
	sub [0xE7], 0x0028
	break
	djnz [0xE6], LABEL_0C96
	jmp LABEL_0C92

LABEL_0CCD:
	mov [0xE6], 0x000A

LABEL_0CD1:
	mov [0xE7], 0x0028
	jne [HACK_VAR_67], 0xC8, LABEL_0CDF
	mov [0xE7], 0x0154

LABEL_0CDF:
	sub [0xE7], [0xE6]
	video offset=CINEMATIC_578, x=[0xe7], y=158, zoom=0x40
	sub [0xE7], 0x0028
	video offset=CINEMATIC_578, x=[0xe7], y=158, zoom=0x40
	video offset=CINEMATIC_579, x=60, y=158
	jne [HACK_VAR_67], 0xC8, LABEL_0CFF
	video offset=CINEMATIC_579, x=280, y=158, zoom=0x40

LABEL_0CFF:
	break
	djnz [0xE6], LABEL_0CD1
	jmp LABEL_0CCD

JUNK__0D07:
	mov [0xE6], 0x000A

LABEL_0D0B:
	mov [0xE7], 0x005A
	sub [0xE7], [0xE6]
	video offset=CINEMATIC_713, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_713, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_713, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_713, x=319, y=[0xe7], zoom=0x40
	break
	djnz [0xE6], LABEL_0D0B
	jmp JUNK__0D07

LABEL_0D3A:
	mov [0xE6], 0x0081
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE6], [RANDOM_SEED]
	jne [HACK_VAR_67], 0x8E, KILL_CHAN_AT_157F
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	video offset=CINEMATIC_298, x=[0xe6], y=150, zoom=0x40
	break
	jne [HACK_VAR_67], 0x8E, KILL_CHAN_AT_157F
	video offset=CINEMATIC_298, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0004
	jl [0x01], [0xE6], LABEL_0D77
	jg [0x01], [0xF8], LABEL_0D77
	call LABEL_0C89

LABEL_0D77:
	break
	play id=0x0052, freq=0x20, vol=0x40, channel=0x00
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x0064
	or [0x97], 0x4000
	video offset=CINEMATIC_299, x=[0xe6], y=73, zoom=0x40
	break
	video offset=CINEMATIC_300, x=[0xe6], y=73, zoom=0x40
	mov [0xE6], 0x0005
	add [0xE6], [0x3A]

DELAY_LOOP_VARE6_AT_0D9F:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_0D9F
	jmp LABEL_0D3A

LABEL_0DA7:
	break
	jne [HACK_VAR_67], 0x8E, LABEL_0DA7
	jl [0x01], 0xBB, LABEL_0DA7
	jg [0x01], 0xD4, LABEL_0DA7
	je [HERO_POS_UP_DOWN], 0xFFFF, LABEL_0DC8
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_0DA7

LABEL_0DC8:
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=INIT_VARS_03_01
	killChannel
