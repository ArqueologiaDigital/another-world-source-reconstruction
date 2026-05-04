KILL_CHAN_AT_016E:
	killChannel

LABEL_016F:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	or [HERO_POS_MASK], 0x0004
	and [HERO_POS_MASK], 0x0007
	break
	jmp LABEL_016F
LABEL_0183:
	db 0x11

LABEL_0184:
	break
	break
	break
	break
	break
	break
	jne [HERO_ACTION], 0x00, LABEL_0190

LABEL_0190:
	break
	jne [HERO_ACTION], 0x00, LABEL_019B
	djnz [0x03], LABEL_0190

LABEL_019B:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_01A8
	setup channel=0x3C, address=LABEL_3F5C
	killChannel

LABEL_01A8:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	play id=0x0052, freq=0x14, vol=0x00, channel=0x02
	play id=0x0052, freq=0x14, vol=0x00, channel=0x03
	play id=0x0052, freq=0x14, vol=0x00, channel=0x01
	play id=0x0052, freq=0x14, vol=0x00, channel=0x00
	call LIKELY_A_COPY_PROTECTION_MECHANISM
	setup channel=0x3C, address=LABEL_3F5C
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D

LABEL_01D8:
	break
	jne [HERO_ACTION], 0x00, LABEL_01D8

LABEL_01DF:
	text id=0x013D, x=5, y=80, color=0x0E ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	call LABEL_02E0
	break
	je [HERO_ACTION], 0x00, LABEL_01DF
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_01FA:
	call COPY_VAR00_TO_VARF8
	jne [HACK_VAR_67], 0xCE, LABEL_0213
	jge [0xF8], 0x23, LABEL_0213
	jne [0xB0], 0x02, LABEL_0213
	mov [0xF8], 0x0023

LABEL_0213:
	jne [HACK_VAR_67], 0xA7, LABEL_022F
	jge [0xF8], 0x25, LABEL_022F
	jne [0xB0], 0x02, LABEL_022F
	jg [0x02], 0x64, LABEL_022F
	mov [0xF8], 0x0025

LABEL_022F:
	jne [HACK_VAR_67], 0x25, LABEL_023F
	jge [0xF8], 0x1E, LABEL_023F
	mov [0xF8], 0x001E

LABEL_023F:
	jne [HACK_VAR_67], 0x45, LABEL_024F
	jge [0xF8], 0x1F, LABEL_024F
	mov [0xF8], 0x001F

LABEL_024F:
	jne [HACK_VAR_67], 0x67, LABEL_0268
	jge [0xF8], 0x21, LABEL_0268
	load id=0x0000
	call LABEL_012C
	call PRELOAD_RES_6A_77_6D_6E_74_76_78_7C
	mov [0xF8], 0x0021

LABEL_0268:
	je [HACK_VAR_67], 0x6B, LABEL_0274
	jne [HACK_VAR_67], 0x4B, LABEL_0291

LABEL_0274:
	jne [0xB0], 0x03, LABEL_0291
	jge [0xF8], 0x27, LABEL_0291
	mov [HACK_VAR_67], 0x004B
	load id=0x0000
	call LABEL_012C
	call PRELOAD_CAVES_RESOURCES
	mov [0xF8], 0x0027

LABEL_0291:
	jne [0xB0], 0x03, LABEL_02C4
	jge [0xF8], 0x30, LABEL_02C4
	jle [0xF8], 0x2C, LABEL_02A9
	jge [0xF8], 0x29, DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29

LABEL_02A9:
	jne [HACK_VAR_67], 0x6F, LABEL_02C4
