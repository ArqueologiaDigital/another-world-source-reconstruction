TANK_ARRIVAL_DRIVE_IN_PRELUDE:
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	sub [0x2B], 0x0001
	jg [0x2B], 0x20, TANK_ARRIVAL_DRIVE_IN_PRELUDE

TANK_ARRIVAL_DRIVE_IN_LOOP:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	call DRAW_TANK_FLYBY_CRAFT
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	djnz [0x2B], TANK_ARRIVAL_DRIVE_IN_LOOP
	play id=0x008B, freq=0x22, vol=0x00, channel=0x01
	play id=0x0084, freq=0x14, vol=0x20, channel=0x02
	play id=0x0084, freq=0x0F, vol=0x10, channel=0x03
	setup channel=0x39, address=TANK_HULL_BODY_REPEAT
	setup channel=0x01, address=TANK_CONSOLE_CURSOR_INPUT_LOOP
	setup channel=0x3B, address=TANK_CONSOLE_HAND_HOVER_LOOP
	selectVideoPage 0x03
	call DRAW_TANK_FLYBY_CRAFT
	selectVideoPage 0x00
	call TANK_HULL_BODY_AND_DETAIL_STAMP
	call DRAW_TANK_FLYBY_CRAFT
	call TANK_HULL_BODY_AND_DETAIL_STAMP
	selectVideoPage 0xFF
	jmp TANK_HULL_FRONT_REPEAT
	mov [0x3E], 0x0014
	mov [0x41], 0x000A
	mov [0x37], 0x0014
	mov [0x46], 0x0001
	mov [0x47], 0x0001
	mov [0x4F], 0x0064
	mov [0x56], 0x0001
	mov [0x57], 0x0001
	killChannel

TANK_INIT_PROJECTILE_POOL_CHANNELS_14_TO_25:
	setup channel=0x14, address=TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP
	setup channel=0x15, address=TANK_FIREFIGHT_PAIR_FIRE_AND_STEP_PRELUDE
	setup channel=0x16, address=TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP
	setup channel=0x17, address=TANK_FIREFIGHT_SOLDIER_SHOT_AND_FALLS
	setup channel=0x18, address=TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP
	setup channel=0x19, address=TANK_FIREFIGHT_PAIR_POSE_PRELUDE
	setup channel=0x1A, address=TANK_THIRD_GUARD_PAIR_DRAW_LOOP
	mov [0x14], 0x0028
	mov [0x15], 0x0071
	mov [0x16], 0x0040
	mov [0x17], 0x0001
	mov [0x18], 0x0039
	mov [0x19], 0x0001
	mov [0x1A], 0x0104
	mov [0x1B], 0x006C
	mov [0x1C], 0x0055
	mov [0x1D], 0x0001
	mov [0x1E], 0x0118
	mov [0x1F], 0x0001
	mov [0x20], 0x00DC
	mov [0x21], 0x0071
	mov [0x22], 0x0040
	mov [0x23], 0x0001
	mov [0x24], 0x00ED
	mov [0x25], 0x0001
	mov [0x68], 0x0032

TANK_GUARD_CAST_INIT_DELAY:
	break
	djnz [0x68], TANK_GUARD_CAST_INIT_DELAY
	setup channel=0x37, address=TANK_ARENA_CREATURE_CHARGE_PAST
	killChannel

PROJECT_AND_DRAW_TWICE_Y_PLUS_9:
	call TANK_GUARD_FRAME_DISPATCH_CASE_01
	mov [0x07], [0x05]
	mov [0x06], [0x04]
	add [0x06], 0x0009
	call TANK_GUARD_FRAME_DISPATCH_CASE_01
	ret


TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP:
	mov [0x07], [0x14]
	mov [0x08], [0x15]
	mov [0x09], [0x16]
	mov [0x06], [0x17]
	mov [0x05], [0x18]
	mov [0x04], [0x19]
	break
	jmp TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP
LABEL_19BD:
	db 0x11

TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP:
	mov [0x14], [0x07]
	mov [0x15], [0x08]
	mov [0x16], [0x09]
	mov [0x17], [0x06]
	mov [0x18], [0x05]
	mov [0x19], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	mov [0x07], [0x1A]
	mov [0x08], [0x1B]
	mov [0x09], [0x1C]
	mov [0x06], [0x1D]
	mov [0x05], [0x1E]
	mov [0x04], [0x1F]
	break
	jmp TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP
LABEL_19E9:
	db 0x11

; Six-var save: var04..var09 → var1A..var1F. The first of
; two adjacent state-save slots used by the projectile pool.
TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP:
	mov [0x1A], [0x07]
	mov [0x1B], [0x08]
	mov [0x1C], [0x09]
	mov [0x1D], [0x06]
	mov [0x1E], [0x05]
	mov [0x1F], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	mov [0x07], [0x20]
	mov [0x08], [0x21]
	mov [0x09], [0x22]
	mov [0x06], [0x23]
	mov [0x05], [0x24]
	mov [0x04], [0x25]
	break
	jmp TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP
LABEL_1A15:
	db 0x11

; Second state-save slot: var04..var09 → var20..var25. The
; pair (1A-1F, 20-25) typically corresponds to two parallel
; projectile/enemy state tracks.
TANK_THIRD_GUARD_PAIR_DRAW_LOOP:
	mov [0x20], [0x07]
	mov [0x21], [0x08]
	mov [0x22], [0x09]
	mov [0x23], [0x06]
	mov [0x24], [0x05]
	mov [0x25], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	break
	jmp TANK_THIRD_GUARD_PAIR_DRAW_LOOP
LABEL_1A2F:
	db 0x11

TANK_GUARD_FRAME_DISPATCH_CASE_01:
	jne [0x06], 0x01, TANK_GUARD_FRAME_DISPATCH_CASE_02
	video offset=CINEMATIC_220, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_02:
	jne [0x06], 0x02, TANK_GUARD_FRAME_DISPATCH_CASE_03
	video offset=CINEMATIC_219, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_03:
	jne [0x06], 0x03, TANK_GUARD_FRAME_DISPATCH_CASE_04
	video offset=CINEMATIC_218, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_04:
	jne [0x06], 0x04, TANK_GUARD_FRAME_DISPATCH_CASE_05
	video offset=CINEMATIC_217, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_05:
	jne [0x06], 0x05, TANK_GUARD_FRAME_DISPATCH_CASE_06
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_06:
	jne [0x06], 0x06, TANK_GUARD_FRAME_DISPATCH_CASE_07
	video offset=CINEMATIC_215, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_07:
	jne [0x06], 0x07, TANK_GUARD_FRAME_DISPATCH_CASE_08
	video offset=CINEMATIC_214, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_08:
	jne [0x06], 0x08, TANK_GUARD_FRAME_DISPATCH_CASE_09
	video offset=CINEMATIC_213, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_09:
	jne [0x06], 0x09, TANK_GUARD_FRAME_DISPATCH_CASE_0A
	video offset=CINEMATIC_212, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_0A:
	jne [0x06], 0x0A, TANK_GUARD_FRAME_DISPATCH_CASE_0B
	video offset=CINEMATIC_211, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_0B:
	jne [0x06], 0x0B, TANK_FIREFIGHT_SOLDIER_POSE_CASE_0C
	video offset=CINEMATIC_210, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_FIREFIGHT_SOLDIER_POSE_CASE_0C:
	jne [0x06], 0x0C, TANK_FIREFIGHT_SOLDIER_POSE_CASE_0D
	video offset=CINEMATIC_209, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_FIREFIGHT_SOLDIER_POSE_CASE_0D:
	jne [0x06], 0x0D, SHARED_RET
	video offset=CINEMATIC_208, x=[0x07], y=[0x08], zoom=[0x09]
	ret