LABEL_065C:
	break
	sub [0xE7], 0x0008
	sub [0xE8], 0x0008
	video type=1, offset=CINEMATIC_562, x=159, y=[0xe7], zoom=0x40
	jge [0x04], 0x4000, LABEL_0676
	video type=1, offset=CINEMATIC_563, x=179, y=[0xe8], zoom=0x40

LABEL_0676:
	djnz [0xE6], LABEL_065C
	jge [0x04], 0x4000, KILL_CHAN_AT_0161
	mov [0x02], 0xFFB0
	killChannel

LABEL_0686:
	jge [0x04], 0x4000, KILL_CHAN_AT_0161
	deleteChannels first=0x14, last=0x16
	killChannel

LABEL_0692:
	video type=1, offset=CINEMATIC_437, x=179, y=31
	video type=1, offset=CINEMATIC_437, x=179, y=62
	video type=1, offset=CINEMATIC_437, x=179, y=93
	break
	jmp LABEL_0692
LABEL_06A2:
	db 0x11

LABEL_06A3:
	video type=1, offset=CINEMATIC_615, x=2, y=186
	video type=1, offset=CINEMATIC_615, x=2, y=195
	break
	video type=1, offset=CINEMATIC_615, x=2, y=185
	video type=1, offset=CINEMATIC_615, x=2, y=194
	break
	video type=1, offset=CINEMATIC_424, x=3, y=184
	video type=1, offset=CINEMATIC_616, x=3, y=185
	video type=1, offset=CINEMATIC_615, x=2, y=193
	break
	video type=1, offset=CINEMATIC_616, x=3, y=184
	video type=1, offset=CINEMATIC_615, x=2, y=192
	break
	video type=1, offset=CINEMATIC_615, x=2, y=191
	video type=1, offset=CINEMATIC_615, x=2, y=200, zoom=0x40
	break
	video type=1, offset=CINEMATIC_615, x=2, y=190
	video type=1, offset=CINEMATIC_615, x=2, y=199
	break
	video type=1, offset=CINEMATIC_615, x=2, y=189
	video type=1, offset=CINEMATIC_615, x=2, y=198
	break
	video type=1, offset=CINEMATIC_615, x=2, y=188
	video type=1, offset=CINEMATIC_615, x=2, y=197
	break
	video type=1, offset=CINEMATIC_615, x=2, y=187
	video type=1, offset=CINEMATIC_615, x=2, y=196
	break
	jmp LABEL_06A3
LABEL_06FC:
	db 0x11
