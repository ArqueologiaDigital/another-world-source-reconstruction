KILL_CHAN_AT_01FB:
	killChannel

LABEL_01FC:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	or [HERO_POS_MASK], 0x0004
	and [HERO_POS_MASK], 0x0007
	break
	jmp LABEL_01FC
LABEL_0210:
	db 0x11

LABEL_0211:
	break
	break
	break
	break
	break

LABEL_0216:
	break
	call LABEL_02C1
	je [HERO_ACTION], 0x00, LABEL_0228
	djnz [0x03], LABEL_0216
	add [0x03], 0x0001

LABEL_0228:
	break
	call LABEL_02C1
	jne [HERO_ACTION], 0x00, LABEL_0236
	djnz [0x03], LABEL_0228

LABEL_0236:
	deleteChannels first=0x00, last=0x3F
	freezeChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_0247
	setup channel=0x3C, address=LABEL_3F46
	killChannel

LABEL_0247:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	play id=0x0052, freq=0x14, vol=0x00, channel=0x02
	play id=0x0052, freq=0x14, vol=0x00, channel=0x03
	play id=0x0052, freq=0x14, vol=0x00, channel=0x01
	play id=0x0052, freq=0x14, vol=0x00, channel=0x00
	call LABEL_00FB
	setup channel=0x3C, address=LABEL_3F46
	or [0xE3], 0x0001
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D
	je [0xE1], 0x01, LABEL_02B8

LABEL_0281:
	break
	text id=0x013D, x=5, y=80, color=0x0E ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	call LABEL_03B9
	call LABEL_02C1
	jne [HERO_ACTION], 0x00, LABEL_0281

LABEL_029A:
	text id=0x013D, x=5, y=80, color=0x0E ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	call LABEL_03B9
	break
	call LABEL_02C1
	je [HERO_ACTION], 0x00, LABEL_029A
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_02B8:
	load id=0x3E8A
	break
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_02C1:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_02D3:
	call COPY_VAR00_TO_VARF8
	jne [HACK_VAR_67], 0xCE, LABEL_02EC
	jge [0xF8], 0x23, LABEL_02EC
	jne [0xB0], 0x02, LABEL_02EC
	mov [0xF8], 0x0023

LABEL_02EC:
	jne [HACK_VAR_67], 0xA7, LABEL_0308
	jge [0xF8], 0x25, LABEL_0308
	jne [0xB0], 0x02, LABEL_0308
	jg [0x02], 0x64, LABEL_0308
	mov [0xF8], 0x0025

LABEL_0308:
	jne [HACK_VAR_67], 0x25, LABEL_0318
	jge [0xF8], 0x1E, LABEL_0318
	mov [0xF8], 0x001E

LABEL_0318:
	jne [HACK_VAR_67], 0x45, LABEL_0328
	jge [0xF8], 0x1F, LABEL_0328
	mov [0xF8], 0x001F

LABEL_0328:
	jne [HACK_VAR_67], 0x67, LABEL_0341
	jge [0xF8], 0x21, LABEL_0341
	load id=0x0000
	call LABEL_01B3
	call LABEL_0148
	mov [0xF8], 0x0021

LABEL_0341:
	je [HACK_VAR_67], 0x6B, LABEL_034D
	jne [HACK_VAR_67], 0x4B, LABEL_036A

LABEL_034D:
	jne [0xB0], 0x03, LABEL_036A
	jge [0xF8], 0x27, LABEL_036A
	mov [HACK_VAR_67], 0x004B
	load id=0x0000
	call LABEL_01B3
	call LABEL_0173
	mov [0xF8], 0x0027

LABEL_036A:
	jne [0xB0], 0x03, LABEL_039D
	jge [0xF8], 0x30, LABEL_039D
	jle [0xF8], 0x2C, LABEL_0382
	jge [0xF8], 0x29, DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29

LABEL_0382:
	jne [HACK_VAR_67], 0x6F, LABEL_039D
