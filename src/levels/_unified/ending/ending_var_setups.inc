INIT_VARE_TO_12:
	mov [0x0E], 0x000C

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARE_TO_12.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_THE_END_ZOOM_IN_PHASE_1:
	break
	add [0x0F], 0x0001
	djnz [0x0E], ENDING_THE_END_ZOOM_IN_PHASE_1
	mov [0x0E], 0x0009
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_THE_END_ZOOM_IN_PHASE_2:
	break
	add [0x0F], 0x0004
	djnz [0x0E], ENDING_THE_END_ZOOM_IN_PHASE_2
	mov [0x0E], 0x0032
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_VARE_THEN_INIT_VARE_5__ENDING_VAR_SETUPS:
	break
	djnz [0x0E], DELAY_VARE_THEN_INIT_VARE_5__ENDING_VAR_SETUPS
	mov [0x0E], 0x0005
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_THE_END_CAPTION_FINAL_SWELL_INTO_CREDITS:
	break
	add [0x0F], 0x0008
	djnz [0x0E], ENDING_THE_END_CAPTION_FINAL_SWELL_INTO_CREDITS
	setup channel=0x36, address=ENDING_CREDITS_ROLL_ENTRY
	break
	add [0x0F], 0x000C
	break
	add [0x0F], 0x0018
	break
	add [0x0F], 0x0026
	break
	add [0x0F], 0x0038
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_THE_END_CAPTION_DRAW_LOOP:
	video offset=CINEMATIC_070, x=[0x01], y=[0x02], zoom=[0x0f]
	break
	jmp ENDING_THE_END_CAPTION_DRAW_LOOP
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_70_ANIM_LOOP.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_70_ANIM_LOOP.inc"
.endif
