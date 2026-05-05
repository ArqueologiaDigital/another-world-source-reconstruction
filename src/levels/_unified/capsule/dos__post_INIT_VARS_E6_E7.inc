LABEL_0A2D:
	video offset=CINEMATIC_588, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jl [0x01], 0xB4, LABEL_0A2D
	video offset=CINEMATIC_607, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_608, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_609, x=[0xe6], y=[0xe7], zoom=0x40
	break
	play id=0x0030, freq=0x0A, vol=0x40, channel=0x03
	video offset=CINEMATIC_610, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_610, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_609, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_610, x=[0xe6], y=[0xe7], zoom=0x40
	play id=0x0030, freq=0x20, vol=0x20, channel=0x03
	break
	video offset=CINEMATIC_609, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_608, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_607, x=[0xe6], y=[0xe7], zoom=0x40
	call LABEL_30C3
	mov [0xE8], 0x0001
	add [0xE8], [0x3A]

LABEL_0A8A:
	break
	video offset=CINEMATIC_588, x=[0xe6], y=[0xe7], zoom=0x40
	djnz [0xE8], LABEL_0A8A
	jmp INIT_VARS_E6_E7

LABEL_0A97:
	video offset=CINEMATIC_589, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jl [0x01], 0xB4, LABEL_0A97
	video offset=CINEMATIC_605, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_590, x=[0xe6], y=[0xe7], zoom=0x40
	break
	mov [0xE9], 0x000A

ANIM_CIN_606_LOOP_VARE9:
	video offset=CINEMATIC_606, x=[0xe6], y=[0xe7], zoom=0x40
	break
	djnz [0xE9], ANIM_CIN_606_LOOP_VARE9
	video offset=CINEMATIC_590, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_605, x=[0xe6], y=[0xe7], zoom=0x40
	break
	call LABEL_30C3
	mov [0xE9], [0x39]
	add [0xE9], 0x0002

ANIM_CIN_589_LOOP_VARE9:
	video offset=CINEMATIC_589, x=[0xe6], y=[0xe7], zoom=0x40
	break
	djnz [0xE9], ANIM_CIN_589_LOOP_VARE9
	jmp LABEL_0A97
LABEL_0AE0:
	db 0x11

LABEL_0AE1:
	break
	jne [HACK_VAR_67], 0xCA, LABEL_0AE1
	jg [0x01], 0x6E, LABEL_0B08
	mov [0xF8], [0xB9]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, LABEL_0B08
	call LABEL_5423
	je [0x21], 0x00, LABEL_0AE1
	or [0xB9], 0x0004

LABEL_0B08:
	break
	call LABEL_30C3
	jg [0x01], 0xE0, LABEL_0B08
	jg [0x01], 0x6E, LABEL_0B3E
	jl [0x01], 0x0A, LABEL_0B08
	jl [0x01], 0x14, LABEL_0B2A
	jl [0x01], 0x4C, LABEL_0B08

LABEL_0B2A:
	mov [0xE6], 0x0048
	add [0xB8], 0x0008
	add [0xE6], [0x39]
	play id=0x0052, freq=0x16, vol=0x40, channel=0x03
	jmp LABEL_0B89

LABEL_0B3E:
	mov [0xE6], [0x01]
	play id=0x0052, freq=0x14, vol=0x40, channel=0x03
	add [0xB8], 0x0008
	video offset=CINEMATIC_319, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_296, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_319, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0003
	jg [0x01], [0xF8], LABEL_0B6B
	call LABEL_0BCA

LABEL_0B6B:
	break
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x007F
	or [0x97], 0x4000
	video offset=CINEMATIC_296, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_297, x=[0xe6], y=100, zoom=0x40
	jmp LABEL_0B08

LABEL_0B89:
	video offset=CINEMATIC_573, x=[0xe6], y=100, zoom=0x40
	break
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x007F
	video offset=CINEMATIC_574, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_573, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0003
	jl [0x01], [0xF8], LABEL_0BB4
	call LABEL_0BCA

LABEL_0BB4:
	break
	video offset=CINEMATIC_297, x=[0xe6], y=100, zoom=0x40
	video offset=CINEMATIC_574, x=[0xe6], y=100, zoom=0x40
	break
	video offset=CINEMATIC_297, x=[0xe6], y=100, zoom=0x40
	break
	break
	jmp LABEL_0B08

LABEL_0BCA:
	jl [0x04], 0x4000, LABEL_5F5A
	ret
	killChannel

LABEL_0BD3:
	mov [0xE6], 0x000A

LABEL_0BD7:
	mov [0xE7], 0x0072
	add [0xE7], [0xE6]
	mov [0xE8], 0x0004
	video offset=CINEMATIC_569, x=73, y=[0xe7], zoom=0x40
	video offset=CINEMATIC_569, x=263, y=[0xe7], zoom=0x40
	add [0xE7], 0x0003
	video offset=CINEMATIC_569, x=175, y=[0xe7], zoom=0x40
	video offset=CINEMATIC_570, x=73, y=124
	video offset=CINEMATIC_570, x=175, y=127
	video offset=CINEMATIC_570, x=263, y=124, zoom=0x40
	sub [0xE7], 0x0028
	break
	djnz [0xE6], LABEL_0BD7
	jmp LABEL_0BD3

LABEL_0C0E:
	mov [0xE6], 0x000A

LABEL_0C12:
	mov [0xE7], 0x0028
	jne [HACK_VAR_67], 0xC8, LABEL_0C20
	mov [0xE7], 0x0154

LABEL_0C20:
	sub [0xE7], [0xE6]
	video offset=CINEMATIC_569, x=[0xe7], y=158, zoom=0x40
	sub [0xE7], 0x0028
	video offset=CINEMATIC_569, x=[0xe7], y=158, zoom=0x40
	video offset=CINEMATIC_570, x=60, y=158
	jne [HACK_VAR_67], 0xC8, LABEL_0C40
	video offset=CINEMATIC_570, x=280, y=158, zoom=0x40

LABEL_0C40:
	break
	djnz [0xE6], LABEL_0C12
	jmp LABEL_0C0E

JUNK__0C48:
	mov [0xE6], 0x000A

LABEL_0C4C:
	mov [0xE7], 0x005A
	sub [0xE7], [0xE6]
	video offset=CINEMATIC_720, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_720, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_720, x=319, y=[0xe7], zoom=0x40
	add [0xE7], 0x0028
	video offset=CINEMATIC_720, x=319, y=[0xe7], zoom=0x40
	break
	djnz [0xE6], LABEL_0C4C
	jmp JUNK__0C48

LABEL_0C7B:
	mov [0xE6], 0x0081
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE6], [RANDOM_SEED]
	video offset=CINEMATIC_295, x=[0xe6], y=150, zoom=0x40
	break
	video offset=CINEMATIC_295, x=[0xe6], y=100, zoom=0x40
	mov [0xF8], [0xE6]
	add [0xF8], 0x0004
	jl [0x01], [0xE6], LABEL_0CA6
	jg [0x01], [0xF8], LABEL_0CA6
	call LABEL_0BCA

LABEL_0CA6:
	break
	mov [0x8B], 0x8001
	mov [0x96], [0xE6]
	mov [0x97], 0x0064
	or [0x97], 0x4000
	video offset=CINEMATIC_296, x=[0xe6], y=73, zoom=0x40
	break
	video offset=CINEMATIC_297, x=[0xe6], y=73, zoom=0x40
	mov [0xE6], 0x0005
	add [0xE6], [0x3A]

DELAY_LOOP_VARE6_AT_0CC8:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_0CC8
	jmp LABEL_0C7B

LABEL_0CD0:
	break
	jl [0x01], 0xBB, LABEL_0CD0
	jg [0x01], 0xD4, LABEL_0CD0
	je [HERO_POS_UP_DOWN], 0xFFFF, LABEL_0CEB
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_0CD0

LABEL_0CEB:
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=INIT_VARS_03_01
	killChannel
