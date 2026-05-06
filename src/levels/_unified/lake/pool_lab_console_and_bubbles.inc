LAB_CONSOLE_SINKING_ANIMATION:
	mov [0x0A], 0x0064
	mov [0x0B], 0x000F

FLOATING_LAB_CONSOLE_PHASE_1:
	video offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a]
	add [0x0A], 0x0002
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_1
	mov [0x0B], 0x000A

FLOATING_LAB_CONSOLE_PHASE_2:
	video offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a]
	add [0x0A], 0x0003
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_2
	setup channel=0x18, address=SETUP_TENTACLE_ANIMATIONS
	mov [HERO_ACTION_POS_MASK], 0x0008
	mov [0x0B], 0x000F

FLOATING_LAB_CONSOLE_PHASE_3:
	video offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a]
	add [0x0A], 0x0004
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_3
	killChannel
	jmp SETUP_TENTACLE_ANIMATIONS

SINKING_AT_CONSOLE:
	video offset=CINEMATIC_SITTING_AT_SINKING_CONSOLE, x=160, y=[0x0a]
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [HERO_POS_UP_DOWN], 0xFFFF, SWIMMING_UP
;@endif
	je [HERO_ACTION_POS_MASK], 0x00, SINKING_AT_CONSOLE
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")

SWIMMING_UP:
;@endif
	video offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_0, x=160, y=[0x0a]
	break
	video offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_1, x=160, y=[0x0a]
	break
	video offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_2, x=160, y=[0x0a]
	mov [HERO_Y], [0x0A]
	sub [HERO_Y], 0x000D
	mov [0x63], 0x0001
	setup channel=0x0C, address=SWIMMING_UP_LEGS_ANIMATION
	setup channel=0x0D, address=SWIMMING_UP_TORSO_ANIMATION
	setup channel=0x16, address=HERO_PHYSICS_TICK
	killChannel

UPDATE_POSITION_OF_BUBBLES:
	mov [0x13], 0x00A0
	mov [0x0C], 0x0055
	mov [0x0D], [0x0C]
	mov [0x0E], [0x0C]
	mov [0x0F], [0x0C]
	mov [COUNTER], [0x0C]
	mov [0x11], [0x0C]
	mov [0x12], 0x000F

BUBBLE_UPDATE_PHASE_1:
	sub [0x0C], 0x0009
	sub [0x0D], 0x0007
	sub [0x0E], 0x0006
	sub [0x0F], 0x0004
	sub [COUNTER], 0x0003
	sub [0x11], 0x0002
	break
	djnz [0x12], BUBBLE_UPDATE_PHASE_1
	mov [0x12], 0x0032

BUBBLE_UPDATE_PHASE_2:
	sub [0x0E], 0x0006
	sub [0x0F], 0x0004
	sub [COUNTER], 0x0003
	sub [0x11], 0x0002
	break
	djnz [0x12], BUBBLE_UPDATE_PHASE_2
	killChannel

INIT_HERO_AT_POOL_EXIT:
	mov [HERO_X], 0x00C8
	mov [HERO_Y], 0x00B6
	mov [0x03], 0x0040
	mov [0x1B], 0x0000
	mov [0x06], 0x0000
	mov [0x63], 0x0000
	mov [0x64], 0x0000
	killChannel

