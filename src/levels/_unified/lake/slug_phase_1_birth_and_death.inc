SLUG_PHASE_1_LEFT_INIT:
	mov [0x0D], 0x0001

SLUG_L_BIRTH_LOOP:
	video type=1, offset=CINEMATIC_SLUG_L_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_L_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_L_F2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_L_F3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_L_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	call JMP_TO_CHECK_BEAST_NEAR
	jne [0x07], 0x00, IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD
	video type=1, offset=CINEMATIC_SLUG_L_F5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_L_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_L_F7, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_L_F8, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0003
	video type=1, offset=CINEMATIC_SLUG_L_F9, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0002
	video type=1, offset=CINEMATIC_SLUG_L_F10, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_L_F11, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_L_F12, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0001
	video type=1, offset=CINEMATIC_BEAST_AI_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0002
	jmp SLUG_L_BIRTH_LOOP
	killChannel

SLUG_PHASE_1_RIGHT_INIT:
	mov [0x0D], 0x0001

SLUG_R_BIRTH_LOOP:
	video type=1, offset=CINEMATIC_SLUG_R_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	call CHECK_IF_BEAST_IS_NEAR_LESTER
	jne [0x07], 0x00, IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD_2
	video type=1, offset=CINEMATIC_SLUG_AFTER_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_AFTER_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_AFTER_F2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0003
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0002
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0002
	jmp SLUG_R_BIRTH_LOOP
	killChannel

SLUG_R_PHASE1_F6_THEN_DEATH:
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	jmp SLUG_R_DEATH_F10_TO_F26
	killChannel

SLUG_R_F4_RAND_DELAY_INIT:
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x13], [0x39]
	add [0x13], 0x0001

SLUG_R_F4_REPEAT_LOOP:
	video type=1, offset=CINEMATIC_SLUG_R_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	djnz [0x13], SLUG_R_F4_REPEAT_LOOP
	video type=1, offset=CINEMATIC_SLUG_R_F5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F7, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F8, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F9, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break

SLUG_R_DEATH_F10_TO_F26:
	video type=1, offset=CINEMATIC_SLUG_R_F10, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F11, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F10, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F12, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F13, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F9, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F13, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F14, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F14, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F14, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F14, x=[0x0c], y=[0x0d], zoom=0x40
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x13], [0x39]
	add [0x13], 0x0002

;@if BRANCH in ("cartridge_1992", "chahi_amiga_1991", "dos_1992")
SLUG_R_F6_RAND_HOLD:
;@elif BRANCH == "gba_2004"
SLUG_R_F6_RAND_HOLD:
;@endif
	break
	video type=1, offset=CINEMATIC_SLUG_R_F6, x=[0x0c], y=[0x0d], zoom=0x40
;@if BRANCH in ("cartridge_1992", "chahi_amiga_1991", "dos_1992")
	djnz [0x13], SLUG_R_F6_RAND_HOLD
;@elif BRANCH == "gba_2004"
	djnz [0x13], SLUG_R_F6_RAND_HOLD
;@endif
	break
	mov [0x13], 0x0002

SLUG_R_F15_DRIFT_DOWN:
	add [0x0D], 0x0009
	video type=1, offset=CINEMATIC_SLUG_R_F15, x=[0x0c], y=[0x0d], zoom=0x40
	break
	djnz [0x13], SLUG_R_F15_DRIFT_DOWN
	mov [0x13], 0x0003

SLUG_R_F16_DRIFT_DOWN:
	add [0x0D], 0x000A
	video type=1, offset=CINEMATIC_SLUG_R_F16, x=[0x0c], y=[0x0d], zoom=0x40
	break
	djnz [0x13], SLUG_R_F16_DRIFT_DOWN
	mov [0x13], 0x0003

SLUG_R_F17_DRIFT_DOWN:
	add [0x0D], 0x000C
	video type=1, offset=CINEMATIC_SLUG_R_F17, x=[0x0c], y=[0x0d], zoom=0x40
	break
	djnz [0x13], SLUG_R_F17_DRIFT_DOWN
	mov [0x13], 0x0007

SLUG_R_F18_DRIFT_DOWN:
	add [0x0D], 0x000E
	video type=1, offset=CINEMATIC_SLUG_R_F18, x=[0x0c], y=[0x0d], zoom=0x40
	break
	djnz [0x13], SLUG_R_F18_DRIFT_DOWN
	play id=0x003A, freq=0x14, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_SLUG_R_F19, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F20, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F21, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F22, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F23, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F24, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_PHASE1_F7, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F25, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_R_F26, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x0008
	jl [0x01], [0x0C], JMP_TO_SLUG_ANIMATION
	add [0x0C], 0x0008
	jmp SLUG_WALK_PROX_LOOP

JMP_TO_SLUG_ANIMATION:
	sub [0x0C], 0x0007
	jmp SLUG_ANIMATION
	killChannel

SHIFT_X_LEFT_THEN_DRAW_LAKE_167_169:
	sub [0x0C], 0x000A

DRAW_LAKE_167_169_WITH_SOUND_35:
	add [0x0C], 0x0002
	video type=1, offset=CINEMATIC_LAKE_167_F1_F0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	play id=0x0035, freq=0x0A, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_LAKE_167_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_167_F7, x=[0x0c], y=[0x0d], zoom=0x40
	break

