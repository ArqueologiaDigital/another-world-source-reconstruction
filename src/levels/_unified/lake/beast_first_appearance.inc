THE_BEAST_APPEARS_FOR_THE_FIRST_TIME_IN_THE_BACKGROUND:
	mov [0x0E], 0x0148
	mov [0x0F], 0x005B
	mov [0x10], 0x0019

BEAST_INTRO_INITIAL_DELAY:
	break
	djnz [0x10], BEAST_INTRO_INITIAL_DELAY
	video type=1, offset=CINEMATIC_BEAST_FIRST_F0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_BG_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0007
	video type=1, offset=CINEMATIC_BEAST_BG_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x001E
	play id=0x003C, freq=0x0A, vol=0x0C, channel=0x00
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0001
	mov [0x10], 0x0014

BEAST_BG_F7_HOLD_LOOP:
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_BG_F7_HOLD_LOOP
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	mov [0x10], 0x001E

BEAST_HEAD_TURNING_3_LOOP:
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_HEAD_TURNING_3_LOOP
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_BODY, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	mov [0x10], 0x0002

BEAST_BG_F7_HOLD_LOOP_SHORT:
	video type=1, offset=CINEMATIC_BEAST_BG_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_BG_F7_HOLD_LOOP_SHORT
	video type=1, offset=CINEMATIC_BEAST_BG_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F9, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F10, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_BG_F11, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0005
	video type=1, offset=CINEMATIC_BEAST_FIRST_F5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_FIRST_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	video type=1, offset=CINEMATIC_BEAST_FIRST_F9, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_FIRST_F10, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F11, x=[0x0e], y=[0x0f], zoom=0x40
	killChannel

