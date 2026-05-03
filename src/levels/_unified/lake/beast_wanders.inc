THE_BEAST_WANDERS_ON_THE_FIRST_SCREEN_TO_THE_RIGHT:
	mov [0x0E], 0x0045
	mov [0x0F], 0x0063

BEAST_WANDER_F1_UNTIL_X_LT_3C:
	video type=1, offset=CINEMATIC_BEAST_WANDER_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	jl [0x01], 0x3C, BEAST_WANDER_F1_UNTIL_X_LT_3C
	video type=1, offset=CINEMATIC_BEAST_FIRST_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0000
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	sub [0x0F], 0x0002
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0003
	video type=1, offset=CINEMATIC_BEAST_FIRST_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0004
	video type=1, offset=CINEMATIC_BEAST_FIRST_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0006
	video type=1, offset=CINEMATIC_BEAST_FIRST_F9, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0006
	add [0x0F], 0x0007
	video type=1, offset=CINEMATIC_BEAST_FIRST_F9, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0F], 0x0003
	video type=1, offset=CINEMATIC_BEAST_FIRST_F10, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F2, x=[0x0e], y=[0x0f], zoom=0x40
	play id=0x003C, freq=0x0A, vol=0x0C, channel=0x00
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F11, x=[0x0e], y=[0x0f], zoom=0x40
	add [0x0E], 0x001C
	mov [0x10], 0x0014

BEAST_WANDER_F1_HOLD_20A:
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F1, x=[0x0e], y=[0x0f], zoom=0x40
	djnz [0x10], BEAST_WANDER_F1_HOLD_20A
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F4, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BEAST_WANDER_F5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F6, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BEAST_WANDER_F5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F7, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BEAST_WANDER_F5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F0, x=[0x0e], y=[0x0f], zoom=0x40
	video type=1, offset=CINEMATIC_BEAST_WANDER_F5, x=160, y=100
	killChannel

THE_BEAST_WANDERS_ON_THE_SECOND_SCREEN_TO_THE_RIGHT:
	mov [0x0E], 0x008B
	mov [0x0F], 0x008C
	mov [0x10], 0x0006

BEAST_WANDER_F1_HOLD_6:
	video type=1, offset=CINEMATIC_BEAST_WANDER_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_WANDER_F1_HOLD_6
	video type=1, offset=CINEMATIC_BEAST_FIRST_F5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0002
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0009
	video type=1, offset=CINEMATIC_BEAST_FIRST_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0009
	video type=1, offset=CINEMATIC_BEAST_FIRST_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0009
	video type=1, offset=CINEMATIC_BEAST_FIRST_F9, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0003
	add [0x0F], 0x0001
	video type=1, offset=CINEMATIC_BEAST_FIRST_F10, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F2, x=[0x0e], y=[0x0f], zoom=0x40
	play id=0x003C, freq=0x0A, vol=0x0C, channel=0x00
	break
	add [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_FIRST_F11, x=[0x0e], y=[0x0f], zoom=0x40
	add [0x0E], 0x001D
	mov [0x10], 0x0014

BEAST_WANDER_F1_HOLD_20B:
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F1, x=[0x0e], y=[0x0f], zoom=0x40
	djnz [0x10], BEAST_WANDER_F1_HOLD_20B
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_FIRST_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	play id=0x0050, freq=0x14, vol=0x20, channel=0x00
	video type=1, offset=CINEMATIC_BEAST_WANDER_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_WANDER_F0, x=[0x0e], y=[0x0f], zoom=0x40
	killChannel

