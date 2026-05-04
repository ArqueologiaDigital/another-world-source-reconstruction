;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_BEAST_KILLED_F0		EQU 0xC80E
CINEMATIC_BEAST_KILLED_F1		EQU 0xC874
CINEMATIC_BEAST_KILLED_F2		EQU 0xC8E2
CINEMATIC_BEAST_KILLED_F3		EQU 0xC9BE
CINEMATIC_BEAST_KILLED_F4		EQU 0xCA2E
CINEMATIC_BEAST_KILLED_F5		EQU 0xCAA0
CINEMATIC_BEAST_KILLED_F6		EQU 0xCB12
CINEMATIC_BEAST_KILLED_F7		EQU 0xCB6C
CINEMATIC_BEAST_KILLED_F8		EQU 0xCBC0
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_BEAST_KILLED_F0		EQU 0xDC1E
CINEMATIC_BEAST_KILLED_F1		EQU 0xDC84
CINEMATIC_BEAST_KILLED_F2		EQU 0xDCF2
CINEMATIC_BEAST_KILLED_F3		EQU 0xDDCE
CINEMATIC_BEAST_KILLED_F4		EQU 0xDE3E
CINEMATIC_BEAST_KILLED_F5		EQU 0xDEB0
CINEMATIC_BEAST_KILLED_F6		EQU 0xDF22
CINEMATIC_BEAST_KILLED_F7		EQU 0xDF7C
CINEMATIC_BEAST_KILLED_F8		EQU 0xDFD0
;@endif

THE_BEAST_IS_KILLED_BY_A_LASER_SHOT:
	video type=1, offset=CINEMATIC_BEAST_KILLED_F0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000A
	video type=1, offset=CINEMATIC_BEAST_KILLED_F1, x=[0x0e], y=[0x0f], zoom=0x40
	play id=0x0052, freq=0x1E, vol=0x3F, channel=0x00
	break
	sub [0x0E], 0x0010
	video type=1, offset=CINEMATIC_BEAST_KILLED_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0018
	video type=1, offset=CINEMATIC_BEAST_KILLED_F3, x=[0x0e], y=[0x0f], zoom=0x40
	play id=0x0030, freq=0x1E, vol=0x3F, channel=0x02
	break
	sub [0x0E], 0x0012
	video type=1, offset=CINEMATIC_BEAST_KILLED_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000C
	video type=1, offset=CINEMATIC_BEAST_KILLED_F5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0008
	video type=1, offset=CINEMATIC_BEAST_KILLED_F6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_KILLED_F7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0004
	play id=0x003C, freq=0x0A, vol=0x18, channel=0x00
	video type=1, offset=CINEMATIC_BEAST_KILLED_F8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0002
	video type=1, offset=CINEMATIC_BEAST_KILLED_F8, x=[0x0e], y=[0x0f], zoom=0x40
	mov [0x10], 0x0005

BEAST_KILLED_F8_REPEAT:
	break
	sub [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_KILLED_F8, x=[0x0e], y=[0x0f], zoom=0x40
	djnz [0x10], BEAST_KILLED_F8_REPEAT
;@if BRANCH in ("cartridge_1992", "gba_2004")
	song id=0x0BBB, delay=0x0000, pos=0x00
;@endif
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_BEAST_KILLED_F8, x=[0x0e], y=[0x0f], zoom=0x40
	selectVideoPage 0xFF
	killChannel

