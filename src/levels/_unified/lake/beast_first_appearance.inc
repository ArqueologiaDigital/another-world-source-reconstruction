;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_BACKGROUND_BEAST_BODY		EQU 0x5FE6
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_0		EQU 0x6006
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_1		EQU 0x6026
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_2		EQU 0x604A
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_3		EQU 0x606E
CINEMATIC_BEAST_BG_F0		EQU 0x51A6
CINEMATIC_BEAST_BG_F1		EQU 0x5202
CINEMATIC_BEAST_BG_F10		EQU 0x5506
CINEMATIC_BEAST_BG_F11		EQU 0x55E6
CINEMATIC_BEAST_BG_F2		EQU 0x525E
CINEMATIC_BEAST_BG_F3		EQU 0x52BA
CINEMATIC_BEAST_BG_F4		EQU 0x5316
CINEMATIC_BEAST_BG_F5		EQU 0x5372
CINEMATIC_BEAST_BG_F6		EQU 0x53CE
CINEMATIC_BEAST_BG_F7		EQU 0x50D2
CINEMATIC_BEAST_BG_F8		EQU 0x542A
CINEMATIC_BEAST_BG_F9		EQU 0x5496
CINEMATIC_BEAST_FIRST_F0		EQU 0x514A
CINEMATIC_BEAST_FIRST_F1		EQU 0x5576
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_BACKGROUND_BEAST_BODY		EQU 0x73F6
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_0		EQU 0x7416
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_1		EQU 0x7436
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_2		EQU 0x745A
CINEMATIC_BACKGROUND_BEAST_HEAD_TURNING_3		EQU 0x747E
CINEMATIC_BEAST_BG_F0		EQU 0x65B6
CINEMATIC_BEAST_BG_F1		EQU 0x6612
CINEMATIC_BEAST_BG_F10		EQU 0x6916
CINEMATIC_BEAST_BG_F11		EQU 0x69F6
CINEMATIC_BEAST_BG_F2		EQU 0x666E
CINEMATIC_BEAST_BG_F3		EQU 0x66CA
CINEMATIC_BEAST_BG_F4		EQU 0x6726
CINEMATIC_BEAST_BG_F5		EQU 0x6782
CINEMATIC_BEAST_BG_F6		EQU 0x67DE
CINEMATIC_BEAST_BG_F7		EQU 0x64E2
CINEMATIC_BEAST_BG_F8		EQU 0x683A
CINEMATIC_BEAST_BG_F9		EQU 0x68A6
CINEMATIC_BEAST_FIRST_F0		EQU 0x655A
CINEMATIC_BEAST_FIRST_F1		EQU 0x6986
;@endif

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

