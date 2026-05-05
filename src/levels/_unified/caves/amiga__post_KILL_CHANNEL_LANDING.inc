KILL_CHAN_AT_0161:
	killChannel

LABEL_0162:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_0162
LABEL_016E:
	db 0x11

LABEL_016F:
	break
	break
	break
	break
	break
	break
	jne [HERO_ACTION], 0x00, LABEL_017B

LABEL_017B:
	break
	jne [HERO_ACTION], 0x00, LABEL_0186
	djnz [0x03], LABEL_017B

LABEL_0186:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_018F
	killChannel

LABEL_018F:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	play id=0x0052, freq=0x14, vol=0x00, channel=0x02
	play id=0x0052, freq=0x14, vol=0x00, channel=0x03
	play id=0x0052, freq=0x14, vol=0x00, channel=0x01
	play id=0x0052, freq=0x14, vol=0x00, channel=0x00
	call LIKELY_A_COPY_PROTECTION_MECHANISM
	setup channel=0x3C, address=LABEL_3D25
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D

LABEL_01BF:
	break
	jne [HERO_ACTION], 0x00, LABEL_01BF

LABEL_01C6:
	text id=0x013D, x=5, y=80, color=0x0E ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	call LABEL_02C7
	break
	je [HERO_ACTION], 0x00, LABEL_01C6
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_01E1:
	call COPY_VAR00_TO_VARF8
	jne [HACK_VAR_67], 0xCE, LABEL_01FA
	jge [0xF8], 0x23, LABEL_01FA
	jne [0xB0], 0x02, LABEL_01FA
	mov [0xF8], 0x0023

LABEL_01FA:
	jne [HACK_VAR_67], 0xA7, LABEL_0216
	jge [0xF8], 0x25, LABEL_0216
	jne [0xB0], 0x02, LABEL_0216
	jg [HERO_Y], 0x64, LABEL_0216
	mov [0xF8], 0x0025

LABEL_0216:
	jne [HACK_VAR_67], 0x25, LABEL_0226
	jge [0xF8], 0x1E, LABEL_0226
	mov [0xF8], 0x001E

LABEL_0226:
	jne [HACK_VAR_67], 0x45, LABEL_0236
	jge [0xF8], 0x1F, LABEL_0236
	mov [0xF8], 0x001F

LABEL_0236:
	jne [HACK_VAR_67], 0x67, LABEL_024F
	jge [0xF8], 0x21, LABEL_024F
	load id=0x0000
	call LABEL_011F
	call PRELOAD_RES_6A_77_6D_6E_74_76_78_7C
	mov [0xF8], 0x0021

LABEL_024F:
	je [HACK_VAR_67], 0x6B, LABEL_025B
	jne [HACK_VAR_67], 0x4B, LABEL_0278

LABEL_025B:
	jne [0xB0], 0x03, LABEL_0278
	jge [0xF8], 0x27, LABEL_0278
	mov [HACK_VAR_67], 0x004B
	load id=0x0000
	call LABEL_011F
	call PRELOAD_CAVES_RESOURCES
	mov [0xF8], 0x0027

LABEL_0278:
	jne [0xB0], 0x03, LABEL_02AB
	jge [0xF8], 0x30, LABEL_02AB
	jle [0xF8], 0x2C, LABEL_0290
	jge [0xF8], 0x29, DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29

LABEL_0290:
	jne [HACK_VAR_67], 0x6F, LABEL_02AB
