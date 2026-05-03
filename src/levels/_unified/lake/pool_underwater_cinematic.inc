A_CALM_ALIEN_POOL_BEFORE_LESTERS_ARRIVAL:
	setup channel=0x3C, address=BLIT_FROM_PAGE_3_LOOP
	mov [0x01], 0x0085
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x63], 0x0000
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	fill page=0x03, color=0x00
	setup channel=0x01, address=DRAW_INSIDE_ALIEN_POOL_SCENARIO
	break
	mov [0x07], 0x00DC
	mov [0x08], 0x0064
	mov [0x09], 0x0046
	mov [0x04], 0x0056
	mov [0x05], 0x0064
	mov [0x06], 0x003C
	setup channel=0x04, address=UPDATE_POSITION_OF_FIRST_WAVY_GLARE
	setup channel=0x05, address=UPDATE_POSITION_OF_SECOND_WAVY_GLARE
	setup channel=0x07, address=POOL_WATER_WAVY_GLARE_ANIMATION
	setup channel=0x0A, address=POOL_SURFACE_WAVES_ANIMATION
	mov [0x14], 0x0014

THE_LAB_CONSOLE_SUDDENLY_APPEARS_INSIDE_THE_ALIEN_POOL:
	break
	djnz [0x14], THE_LAB_CONSOLE_SUDDENLY_APPEARS_INSIDE_THE_ALIEN_POOL
	unfreezeChannels first=0x04, last=0x05
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	break
	fill page=0xFF, color=0x0C
	video type=1, offset=CINEMATIC_CONSOLE_UNDERWATER_EXPLOSION_0, x=160, y=100
	break
;@if BRANCH == "gba_2004"
	song id=0x0FA1, delay=0x0000, pos=0x00
;@endif
	setPalette 0x02
	play id=0x003E, freq=0x01, vol=0x3F, channel=0x00
	play id=0x003E, freq=0x05, vol=0x3F, channel=0x01
	play id=0x003E, freq=0x07, vol=0x3F, channel=0x02
	play id=0x0031, freq=0x14, vol=0x3F, channel=0x03
	video type=1, offset=CINEMATIC_CONSOLE_UNDERWATER_EXPLOSION_1, x=160, y=100
	setup channel=0x0B, address=LAB_CONSOLE_SINKING_ANIMATION
	setup channel=0x0E, address=UPDATE_POSITION_OF_BUBBLES
	setup channel=0x0F, address=BUBBLES_A_ANIMATION
	setup channel=0x10, address=BUBBLES_B_ANIMATION
	setup channel=0x0C, address=SINKING_AT_CONSOLE
	break
	mov [0x04], 0x00CE
	mov [0x06], 0x0028
	mov [0x07], 0x0118
	mov [0x09], 0x0050
;@if BRANCH == "chahi_amiga_1991"
	setup channel=0x07, address=POOL_WATER_WAVY_GLARE_ANIMATION
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x07, address=POOL_WATER_WAVY_GLARE_ANIMATION
;@endif
	setup channel=0x0A, address=POOL_SURFACE_WAVES_ANIMATION
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xDB], 0x01, POST_BEETLE_PRE_PALETTE_03
	setup channel=0x07, address=POOL_WATER_WAVY_GLARE_ANIMATION

POST_BEETLE_PRE_PALETTE_03:
;@endif
	freezeChannels first=0x04, last=0x05
	setPalette 0x03
	play id=0x0032, freq=0x14, vol=0x3F, channel=0x03
	break
	break
	play id=0x0032, freq=0x14, vol=0x3F, channel=0x03
	break
	play id=0x0031, freq=0x14, vol=0x3F, channel=0x02
	break
	play id=0x0032, freq=0x14, vol=0x3F, channel=0x03
	break
	break
	break
	play id=0x0032, freq=0x14, vol=0x30, channel=0x03
	play id=0x0031, freq=0x14, vol=0x32, channel=0x02
	break
	break
	play id=0x0032, freq=0x14, vol=0x20, channel=0x03
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	play id=0x0031, freq=0x14, vol=0x08, channel=0x03
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	play id=0x0032, freq=0x14, vol=0x10, channel=0x02
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	play id=0x0031, freq=0x14, vol=0x08, channel=0x03

POOL_INTRO_PROTECT_DELAY_LOOP:
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	play id=0x0031, freq=0x14, vol=0x04, channel=0x02
	break
	break
	jle [0x02], 0x0A, INIT_CODEWHEEL_PROTECTION_SCENE
	break
	play id=0x0032, freq=0x14, vol=0x02, channel=0x02
	jmp POOL_INTRO_PROTECT_DELAY_LOOP
	killChannel

SETUP_TENTACLE_ANIMATIONS:
	setup channel=0x17, address=MAIN_TENTACLE_INSIDE_POOL_ANIMATION
	setup channel=0x34, address=OTHER_TENTACLES_INSIDE_POOL_ANIMATION
	call SET_INITIAL_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	mov [0x15], [0x01]
	mov [0x16], 0x012C

POOL_INIT_VAR_16_DESCENT:
	break
	sub [0x16], 0x000A
	mov [0x15], [0x01]
	jg [0x16], [0x02], POOL_INIT_VAR_16_DESCENT
	setup channel=0x16, address=KILL_CHANNEL_ROUTINE
	call ADVANCE_RING_Y_POSITIONS
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xDB], 0x00, POOL_INIT_VAR_16_RISE
	setup channel=0x07, address=POOL_WATER_WAVY_GLARE_ANIMATION
;@endif

POOL_INIT_VAR_16_RISE:
	break
	add [0x16], 0x0014
	mov [0x02], [0x16]
	jl [0x16], 0x0104, POOL_INIT_VAR_16_RISE
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp INIT_VAR_03_TO_0x1E
;@elif BRANCH == "chahi_amiga_1991"
	jmp INIT_VAR_03_TO_0x1E
;@endif
	killChannel

MAIN_TENTACLE_INSIDE_POOL_ANIMATION:
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x15], y=[0x16], zoom=0x40
	break
	jmp MAIN_TENTACLE_INSIDE_POOL_ANIMATION

OTHER_TENTACLES_INSIDE_POOL_ANIMATION:
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x46], y=[0x47], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x49], y=[0x4a], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x4c], y=[0x4d], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x4f], y=[0x50], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_2, x=[0x52], y=[0x53], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_3, x=[0x55], y=[0x56], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_1, x=[0x58], y=[0x59], zoom=0x40
	video type=1, offset=CINEMATIC_TENTACLE_WAVING_0, x=[0x5b], y=[0x5c], zoom=0x40
	call UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL
	break
	jmp OTHER_TENTACLES_INSIDE_POOL_ANIMATION

UPDATE_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL:
	add [0x47], [0x48]
	add [0x4A], [0x4B]
	add [0x4D], [0x4E]
	add [0x50], [0x51]
	add [0x53], [HACK_VAR_54]
	add [0x56], [0x57]
	add [0x59], [0x5A]
	add [0x5C], [0x5D]
	add [0x46], 0x0002
	add [0x49], 0x0002
	add [0x4C], 0x0001
	add [0x4F], 0x0001
	sub [0x52], 0x0001
	sub [0x55], 0x0001
	sub [0x58], 0x0002
	sub [0x5B], 0x0002
	ret

SET_INITIAL_POSITIONS_OF_TENTACLES_INSIDE_THE_POOL:
	mov [0x46], 0x0032
	mov [0x49], 0x0046
	mov [0x4C], 0x0064
	mov [0x4F], 0x0073
	mov [0x52], 0x0096
	mov [0x55], 0x00AA
	mov [0x58], 0x00D2
	mov [0x5B], 0x00E6
	mov [0x47], 0x00DC
	mov [0x4A], 0x00E6
	mov [0x4D], 0x00D2
	mov [0x50], 0x00C8
	mov [0x53], 0x0104
	mov [0x56], 0x00FA
	mov [0x59], 0x00DC
	mov [0x5C], 0x00FA
	mov [0x48], 0xFFFE
	mov [0x4B], 0xFFFA
	mov [0x4E], 0xFFFD
	mov [0x51], 0xFFFE
	mov [HACK_VAR_54], 0xFFFB
	mov [0x57], 0xFFFA
	mov [0x5A], 0xFFFB
	mov [0x5D], 0xFFF8
	ret

ADVANCE_RING_Y_POSITIONS:
	add [0x48], 0x000A
	add [0x4B], 0x000D
	add [0x4E], 0x000A
	add [0x51], 0x000A
	add [HACK_VAR_54], 0x000A
	add [0x57], 0x000A
	add [0x5A], 0x000F
	add [0x5D], 0x0014
	ret

POOL_SURFACE_WAVES_ANIMATION:
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_POOL_SURFACE_WAVES_6, x=160, y=100
	break
	jmp POOL_SURFACE_WAVES_ANIMATION
	killChannel

POOL_WATER_WAVY_GLARE_ANIMATION:
	video type=1, offset=CINEMATIC_POOL_WATER_WAVY_GLARE_EFFECT, x=[0x04], y=[0x05], zoom=0x40
	sub [0x04], 0x0064
	video type=1, offset=CINEMATIC_POOL_WATER_WAVY_GLARE_EFFECT, x=[0x04], y=[0x05], zoom=0x40
	add [0x04], 0x0064
	video type=1, offset=CINEMATIC_POOL_WATER_WAVY_GLARE_EFFECT, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x00A0
	video type=1, offset=CINEMATIC_POOL_WATER_WAVY_GLARE_EFFECT, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x00A0
	break
	jmp POOL_WATER_WAVY_GLARE_ANIMATION
	killChannel

INIT_SECOND_WAVY_GLARE_POS:
	mov [0x07], 0x0190
	mov [0x08], 0x0064
	mov [0x09], 0x0064

UPDATE_POSITION_OF_SECOND_WAVY_GLARE:
	sub [0x07], 0x0006
	break
	djnz [0x09], UPDATE_POSITION_OF_SECOND_WAVY_GLARE
	mov [0x09], 0x0064

JMP_TO_INIT_WAVY_GLARE:
	add [0x07], 0x0006
	break
	djnz [0x09], JMP_TO_INIT_WAVY_GLARE
	jmp INIT_SECOND_WAVY_GLARE_POS
	killChannel

INIT_FIRST_WAVY_GLARE_POS:
	mov [0x04], 0xFFA2
	mov [0x05], 0x0064
	mov [0x06], 0x005A

UPDATE_POSITION_OF_FIRST_WAVY_GLARE:
	add [0x04], 0x0006
	break
	djnz [0x06], UPDATE_POSITION_OF_FIRST_WAVY_GLARE
	mov [0x06], 0x005A

SECOND_WAVY_GLARE_DRIFT:
	sub [0x04], 0x0006
	break
	djnz [0x06], SECOND_WAVY_GLARE_DRIFT
	jmp INIT_FIRST_WAVY_GLARE_POS
	killChannel

SWIMMING_UP_TORSO_ANIMATION:
	video type=1, offset=CINEMATIC_SWIMMING_UP_TORSO_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_TORSO_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_TORSO_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_TORSO_1, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp SWIMMING_UP_TORSO_ANIMATION
	killChannel

BUBBLES_A_ANIMATION:
	video type=1, offset=CINEMATIC_BUBBLES_B_0, x=[0x13], y=[0x0d], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_1, x=[0x13], y=[0x0e], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_2, x=[0x13], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_3, x=[0x13], y=[0x10], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_4, x=[0x13], y=[0x11], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BUBBLES_B_5, x=[0x13], y=[0x0d], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_1, x=[0x13], y=[0x0e], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_2, x=[0x13], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_3, x=[0x13], y=[0x10], zoom=0x40
	video type=1, offset=CINEMATIC_BUBBLES_B_4, x=[0x13], y=[0x11], zoom=0x40
	break
	jmp BUBBLES_A_ANIMATION
	killChannel

BUBBLES_B_ANIMATION:
	video type=1, offset=CINEMATIC_BUBBLES_A_0, x=[0x13], y=[0x0c], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BUBBLES_A_1, x=[0x13], y=[0x0c], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BUBBLES_A_2, x=[0x13], y=[0x0c], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BUBBLES_A_1, x=[0x13], y=[0x0c], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BUBBLES_A_0, x=[0x13], y=[0x0c], zoom=0x40
	break
	jmp BUBBLES_B_ANIMATION
	killChannel

SWIMMING_UP_LEGS_ANIMATION:
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_3, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_4, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_5, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_6, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIMMING_UP_LEGS_7, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp SWIMMING_UP_LEGS_ANIMATION
	killChannel

LAB_CONSOLE_SINKING_ANIMATION:
	mov [0x0A], 0x0064
	mov [0x0B], 0x000F

FLOATING_LAB_CONSOLE_PHASE_1:
	video type=1, offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a], zoom=0x40
	add [0x0A], 0x0002
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_1
	mov [0x0B], 0x000A

FLOATING_LAB_CONSOLE_PHASE_2:
	video type=1, offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a], zoom=0x40
	add [0x0A], 0x0003
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_2
	setup channel=0x18, address=SETUP_TENTACLE_ANIMATIONS
	mov [HERO_ACTION_POS_MASK], 0x0008
	mov [0x0B], 0x000F

FLOATING_LAB_CONSOLE_PHASE_3:
	video type=1, offset=CINEMATIC_FLOATING_LAB_CONSOLE, x=160, y=[0x0a], zoom=0x40
	add [0x0A], 0x0004
	break
	djnz [0x0B], FLOATING_LAB_CONSOLE_PHASE_3
	killChannel
	jmp SETUP_TENTACLE_ANIMATIONS

SINKING_AT_CONSOLE:
	video type=1, offset=CINEMATIC_SITTING_AT_SINKING_CONSOLE, x=160, y=[0x0a], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [HERO_POS_UP_DOWN], 0xFFFF, SWIMMING_UP
;@endif
;@if BRANCH == "dos_1992"
	je [HERO_POS_UP_DOWN], 0xFFFF, SWIMMING_UP
;@endif
	je [HERO_ACTION_POS_MASK], 0x00, SINKING_AT_CONSOLE
;@if BRANCH in ("cartridge_1992", "gba_2004")

SWIMMING_UP:
;@endif
;@if BRANCH == "dos_1992"

SWIMMING_UP:
;@endif
	video type=1, offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_0, x=160, y=[0x0a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_1, x=160, y=[0x0a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWIM_OUT_OF_CONSOLE_2, x=160, y=[0x0a], zoom=0x40
	mov [0x02], [0x0A]
	sub [0x02], 0x000D
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
	mov [0x10], [0x0C]
	mov [0x11], [0x0C]
	mov [0x12], 0x000F

BUBBLE_UPDATE_PHASE_1:
	sub [0x0C], 0x0009
	sub [0x0D], 0x0007
	sub [0x0E], 0x0006
	sub [0x0F], 0x0004
	sub [0x10], 0x0003
	sub [0x11], 0x0002
	break
	djnz [0x12], BUBBLE_UPDATE_PHASE_1
	mov [0x12], 0x0032

BUBBLE_UPDATE_PHASE_2:
	sub [0x0E], 0x0006
	sub [0x0F], 0x0004
	sub [0x10], 0x0003
	sub [0x11], 0x0002
	break
	djnz [0x12], BUBBLE_UPDATE_PHASE_2
	killChannel

INIT_HERO_AT_POOL_EXIT:
	mov [0x01], 0x00C8
	mov [0x02], 0x00B6
	mov [0x03], 0x0040
	mov [0x1B], 0x0000
	mov [0x06], 0x0000
	mov [0x63], 0x0000
	mov [0x64], 0x0000
	killChannel

