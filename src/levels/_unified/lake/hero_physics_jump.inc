HERO_JUMP_RISE_PARABOLA:
	sub [0x02], 0x0003
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0001
	break
	sub [0x02], 0x0002
	break
	sub [0x02], 0x0001
	killChannel

HERO_PHYSICS_TICK:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x02], [HERO_POS_UP_DOWN]
;@elif BRANCH == "chahi_amiga_1991"
	add [0x02], [HERO_POS_JUMP_DOWN]
;@endif
	add [0x02], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x02], [HERO_POS_UP_DOWN]
;@elif BRANCH == "chahi_amiga_1991"
	add [0x02], [HERO_POS_JUMP_DOWN]
;@endif
	add [0x01], [HERO_POS_LEFT_RIGHT]
	je [HERO_ACTION], 0x00, HERO_PHYSICS_DISPATCH
	sub [0x02], 0x0002

HERO_PHYSICS_DISPATCH:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [HERO_POS_UP_DOWN], 0xFFFF, HERO_PHYSICS_QUEUE_JUMP_RISE
;@elif BRANCH == "chahi_amiga_1991"
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_PHYSICS_QUEUE_JUMP_RISE
;@endif
	setup channel=0x14, address=KILL_CHANNEL_ROUTINE
	sub [0x02], 0x0002
	mov [0x63], 0x0001
	jmp HERO_PHYSICS_TICK_LOOP

HERO_PHYSICS_QUEUE_JUMP_RISE:
	jne [0x63], 0x01, HERO_PHYSICS_TICK_LOOP
	sub [0x02], 0x0003
	mov [0x63], 0x0000
	setup channel=0x14, address=HERO_JUMP_RISE_PARABOLA

HERO_PHYSICS_TICK_LOOP:
	break
	jmp HERO_PHYSICS_TICK
	killChannel

