SHIFT_X_LEFT_F_AND_JMP:
	sub [0x0E], 0x000F
	jmp BEAST_APPROACH_F1_TICK

BEAST_APPROACH_FAST_LOOP:
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000F
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F4, x=[0x0e], y=[0x0f], zoom=0x40
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=RENDER_FRAME_DISPATCH
	break
	play id=0x003A, freq=0x0A, vol=0x18, channel=0x00
	sub [0x0E], 0x000D
	jmp BEAST_ARRIVAL_DECEL

DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME:
	video type=1, offset=CINEMATIC_BEAST_PREROLL, x=[0x0e], y=[0x0f], zoom=0x40
	break

DRAW_BEAST_DRIFT_LEFT_LOOP:
	sub [0x0E], 0x000B
	video type=1, offset=CINEMATIC_BEAST_DRIFT_FRAME, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_1, x=[0x0e], y=[0x0f], zoom=0x40
	call RANDOM_BEAST_AMBIENT_SOUND
	break
	sub [0x0E], 0x000C
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0001
	jmp SHIFT_X_LEFT_F_AND_JMP
	killChannel

ADVANCE_X_FORWARD_ONE_SCREEN:
	jl [0x2A], 0x04, SHIFT_X_RIGHT_320
	add [0x0E], 0x0172

SHIFT_X_RIGHT_320:
	add [0x0A], 0x0140
	ret

ADVANCE_X_BACKWARD_ONE_SCREEN:
	jl [0x2A], 0x04, SHIFT_X_LEFT_320
	sub [0x0E], 0x0172

SHIFT_X_LEFT_320:
	sub [0x0A], 0x0140
	ret

