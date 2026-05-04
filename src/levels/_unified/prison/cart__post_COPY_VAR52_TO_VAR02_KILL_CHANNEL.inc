LABEL_7FE9:
	mov [0x63], 0x0064
	mov [0x02], [0x52]
	sub [0x02], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_8049
	break
	mov [0x02], [0x52]
	call LABEL_8049
	setup channel=0x1A, address=LABEL_7FD7
	jmp LABEL_8062
LABEL_800B:
	db 0x11

LABEL_800C:
	mov [0x63], 0x0064
	mov [0x02], [0x51]
	add [0x02], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_802F
	break
	mov [0x02], [0x51]
	call LABEL_802F
	setup channel=0x1A, address=LABEL_7FC5
	jmp LABEL_8062
LABEL_802E:
	db 0x11

LABEL_802F:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_552__CART__POST_COPY_VAR52_TO_VAR02_KILL_CHANNEL
	video type=1, offset=CINEMATIC_553, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_552__CART__POST_COPY_VAR52_TO_VAR02_KILL_CHANNEL:
	video type=1, offset=CINEMATIC_552, x=[0x01], y=[0x02], zoom=0x40
	ret
LABEL_8048:
	db 0x11

LABEL_8049:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_550__CART__POST_COPY_VAR52_TO_VAR02_KILL_CHANNEL
	video type=1, offset=CINEMATIC_551, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_550__CART__POST_COPY_VAR52_TO_VAR02_KILL_CHANNEL:
	video type=1, offset=CINEMATIC_550, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_8062:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	mov [0x63], 0x0002
	jne [0xF8], 0x00, HERO_WALK_RIGHT_LOOP
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_807A:
	db 0x11
