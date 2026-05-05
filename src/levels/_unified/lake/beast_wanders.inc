;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_BEAST_WANDER_0		EQU 0x5BDA
CINEMATIC_BEAST_WANDER_1		EQU 0x57A2
CINEMATIC_BEAST_WANDER_2		EQU 0x5A26
CINEMATIC_BEAST_WANDER_3		EQU 0x5ADE
CINEMATIC_BEAST_WANDER_4		EQU 0x5B22
CINEMATIC_BEAST_WANDER_5		EQU 0xBC10
CINEMATIC_BEAST_WANDER_6		EQU 0x5B66
CINEMATIC_BEAST_WANDER_7		EQU 0x5BA6
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_BEAST_WANDER_0		EQU 0x6FEA
CINEMATIC_BEAST_WANDER_1		EQU 0x6BB2
CINEMATIC_BEAST_WANDER_2		EQU 0x6E36
CINEMATIC_BEAST_WANDER_3		EQU 0x6EEE
CINEMATIC_BEAST_WANDER_4		EQU 0x6F32
CINEMATIC_BEAST_WANDER_5		EQU 0xD020
CINEMATIC_BEAST_WANDER_6		EQU 0x6F76
CINEMATIC_BEAST_WANDER_7		EQU 0x6FB6
;@endif

THE_BEAST_WANDERS_ON_THE_FIRST_SCREEN_TO_THE_RIGHT:
	mov [0x0E], 0x0045
	mov [0x0F], 0x0063

BEAST_WANDER_F1_UNTIL_X_LT_3C:
	video offset=CINEMATIC_BEAST_WANDER_1, x=[0x0e], y=[0x0f]
	break
	jl [0x01], 0x3C, BEAST_WANDER_F1_UNTIL_X_LT_3C
	video offset=CINEMATIC_BEAST_FIRST_6, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0000
	video offset=CINEMATIC_BEAST_FIRST_7, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0007
	sub [0x0F], 0x0002
	video offset=CINEMATIC_BEAST_FIRST_7, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0007
	video offset=CINEMATIC_BEAST_FIRST_7, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0003
	video offset=CINEMATIC_BEAST_FIRST_8, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0004
	video offset=CINEMATIC_BEAST_FIRST_8, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0007
	add [0x0F], 0x0006
	video offset=CINEMATIC_BEAST_FIRST_9, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0006
	add [0x0F], 0x0007
	video offset=CINEMATIC_BEAST_FIRST_9, x=[0x0e], y=[0x0f]
	break
	add [0x0F], 0x0003
	video offset=CINEMATIC_BEAST_FIRST_10, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_2, x=[0x0e], y=[0x0f]
	play id=0x003C, freq=0x0A, vol=0x0C, channel=0x00
	break
	video offset=CINEMATIC_BEAST_FIRST_11, x=[0x0e], y=[0x0f]
	add [0x0E], 0x001C
	mov [0x10], 0x0014

BEAST_WANDER_F1_HOLD_20A:
	break
	video offset=CINEMATIC_BEAST_WANDER_1, x=[0x0e], y=[0x0f]
	djnz [0x10], BEAST_WANDER_F1_HOLD_20A
	break
	video offset=CINEMATIC_BEAST_FIRST_4, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_FIRST_3, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_FIRST_2, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_3, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_4, x=[0x0e], y=[0x0f]
	video offset=CINEMATIC_BEAST_WANDER_5, x=160, y=100
	break
	video offset=CINEMATIC_BEAST_WANDER_6, x=[0x0e], y=[0x0f]
	video offset=CINEMATIC_BEAST_WANDER_5, x=160, y=100
	break
	video offset=CINEMATIC_BEAST_WANDER_7, x=[0x0e], y=[0x0f]
	video offset=CINEMATIC_BEAST_WANDER_5, x=160, y=100
	break
	video offset=CINEMATIC_BEAST_WANDER_0, x=[0x0e], y=[0x0f]
	video offset=CINEMATIC_BEAST_WANDER_5, x=160, y=100
	killChannel

THE_BEAST_WANDERS_ON_THE_SECOND_SCREEN_TO_THE_RIGHT:
	mov [0x0E], 0x008B
	mov [0x0F], 0x008C
	mov [0x10], 0x0006

BEAST_WANDER_F1_HOLD_6:
	video offset=CINEMATIC_BEAST_WANDER_1, x=[0x0e], y=[0x0f]
	break
	djnz [0x10], BEAST_WANDER_F1_HOLD_6
	video offset=CINEMATIC_BEAST_FIRST_5, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_FIRST_6, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0002
	video offset=CINEMATIC_BEAST_FIRST_7, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0009
	video offset=CINEMATIC_BEAST_FIRST_7, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0009
	video offset=CINEMATIC_BEAST_FIRST_8, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0009
	video offset=CINEMATIC_BEAST_FIRST_9, x=[0x0e], y=[0x0f]
	break
	add [0x0E], 0x0003
	add [0x0F], 0x0001
	video offset=CINEMATIC_BEAST_FIRST_10, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_2, x=[0x0e], y=[0x0f]
	play id=0x003C, freq=0x0A, vol=0x0C, channel=0x00
	break
	add [0x0E], 0x0001
	video offset=CINEMATIC_BEAST_FIRST_11, x=[0x0e], y=[0x0f]
	add [0x0E], 0x001D
	mov [0x10], 0x0014

BEAST_WANDER_F1_HOLD_20B:
	break
	video offset=CINEMATIC_BEAST_WANDER_1, x=[0x0e], y=[0x0f]
	djnz [0x10], BEAST_WANDER_F1_HOLD_20B
	break
	video offset=CINEMATIC_BEAST_FIRST_4, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_FIRST_3, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_FIRST_2, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_3, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_4, x=[0x0e], y=[0x0f]
	break
	play id=0x0050, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_BEAST_WANDER_6, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_7, x=[0x0e], y=[0x0f]
	break
	video offset=CINEMATIC_BEAST_WANDER_0, x=[0x0e], y=[0x0f]
	killChannel

