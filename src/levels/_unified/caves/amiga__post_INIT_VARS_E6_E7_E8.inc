LABEL_065C:
	break
	sub [0xE7], 0x0008
	sub [0xE8], 0x0008
	video offset=CINEMATIC_562, x=159, y=[0xe7]
	jge [0x04], 0x4000, LABEL_0676
	video offset=CINEMATIC_563, x=179, y=[0xe8]

LABEL_0676:
	djnz [0xE6], LABEL_065C
	jge [0x04], 0x4000, KILL_CHAN_AT_0161
	mov [HERO_Y], 0xFFB0
	killChannel

LABEL_0686:
	jge [0x04], 0x4000, KILL_CHAN_AT_0161
	deleteChannels first=0x14, last=0x16
	killChannel

LABEL_0692:
	video offset=CINEMATIC_437, x=179, y=31
	video offset=CINEMATIC_437, x=179, y=62
	video offset=CINEMATIC_437, x=179, y=93
	break
	jmp LABEL_0692
LABEL_06A2:
	db 0x11

LABEL_06A3:
	video offset=CINEMATIC_615, x=2, y=186
	video offset=CINEMATIC_615, x=2, y=195
	break
	video offset=CINEMATIC_615, x=2, y=185
	video offset=CINEMATIC_615, x=2, y=194
	break
	video offset=CINEMATIC_424, x=3, y=184
	video offset=CINEMATIC_616, x=3, y=185
	video offset=CINEMATIC_615, x=2, y=193
	break
	video offset=CINEMATIC_616, x=3, y=184
	video offset=CINEMATIC_615, x=2, y=192
	break
	video offset=CINEMATIC_615, x=2, y=191
	video offset=CINEMATIC_615, x=2, y=200, zoom=0x40
	break
	video offset=CINEMATIC_615, x=2, y=190
	video offset=CINEMATIC_615, x=2, y=199
	break
	video offset=CINEMATIC_615, x=2, y=189
	video offset=CINEMATIC_615, x=2, y=198
	break
	video offset=CINEMATIC_615, x=2, y=188
	video offset=CINEMATIC_615, x=2, y=197
	break
	video offset=CINEMATIC_615, x=2, y=187
	video offset=CINEMATIC_615, x=2, y=196
	break
	jmp LABEL_06A3
LABEL_06FC:
	db 0x11
