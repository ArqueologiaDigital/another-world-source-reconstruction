LABEL_0675:
	break
	sub [0xE7], 0x0008
	sub [0xE8], 0x0008
	video type=1, offset=CINEMATIC_583, x=159, y=[0xe7], zoom=0x40
	jge [0x04], 0x4000, LABEL_068F
	video type=1, offset=CINEMATIC_584, x=179, y=[0xe8], zoom=0x40

LABEL_068F:
	djnz [0xE6], LABEL_0675
	jge [0x04], 0x4000, KILL_CHAN_AT_016E
	mov [0x00], 0x0040
	bankSwitch 6;  Capsule Lands at the Bath
	killChannel
	mov [0x02], 0xFFB0
	killChannel

LABEL_06A7:
	jge [0x04], 0x4000, KILL_CHAN_AT_016E
	deleteChannels first=0x14, last=0x16
	killChannel

LABEL_06B3:
	video type=1, offset=CINEMATIC_458, x=179, y=31
	video type=1, offset=CINEMATIC_458, x=179, y=62
	video type=1, offset=CINEMATIC_458, x=179, y=93
	break
	jmp LABEL_06B3
LABEL_06C3:
	db 0x11

LABEL_06C4:
	video type=1, offset=CINEMATIC_636, x=2, y=186
	video type=1, offset=CINEMATIC_636, x=2, y=195
	break
	video type=1, offset=CINEMATIC_636, x=2, y=185
	video type=1, offset=CINEMATIC_636, x=2, y=194
	break
	video type=1, offset=CINEMATIC_445, x=3, y=184
	video type=1, offset=CINEMATIC_637, x=3, y=185
	video type=1, offset=CINEMATIC_636, x=2, y=193
	break
	video type=1, offset=CINEMATIC_637, x=3, y=184
	video type=1, offset=CINEMATIC_636, x=2, y=192
	break
	video type=1, offset=CINEMATIC_636, x=2, y=191
	video type=1, offset=CINEMATIC_636, x=2, y=200, zoom=0x40
	break
	video type=1, offset=CINEMATIC_636, x=2, y=190
	video type=1, offset=CINEMATIC_636, x=2, y=199
	break
	video type=1, offset=CINEMATIC_636, x=2, y=189
	video type=1, offset=CINEMATIC_636, x=2, y=198
	break
	video type=1, offset=CINEMATIC_636, x=2, y=188
	video type=1, offset=CINEMATIC_636, x=2, y=197
	break
	video type=1, offset=CINEMATIC_636, x=2, y=187
	video type=1, offset=CINEMATIC_636, x=2, y=196
	break
	jmp LABEL_06C4
LABEL_071D:
	db 0x11
