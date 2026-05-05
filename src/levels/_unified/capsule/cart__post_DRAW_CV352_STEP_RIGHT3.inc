LABEL_BE04:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_9329
	je [HERO_POS_MASK], 0x00, LABEL_BDCF
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_933A
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE30
	je [HERO_POS_MASK], 0x00, LABEL_BDC7
	add [HERO_X], 0x0001

LABEL_BE30:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_934B
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE4C
	je [HERO_POS_MASK], 0x00, LABEL_BDBF
	add [HERO_X], 0x0001

LABEL_BE4C:
	add [HERO_X], 0x0001
	mov [0x36], 0x0007
	break
	call LABEL_935C
	mov [0x36], 0x0005
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE6A
	add [HERO_X], 0x0002

LABEL_BE6A:
	break
	call LABEL_936D
	add [HERO_X], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE80
	add [HERO_X], 0x0001

LABEL_BE80:
	break
	call LABEL_937E
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE92
	add [HERO_X], 0x0002

LABEL_BE92:
	break
	call LABEL_9395
	mov [0x36], 0x0000
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BEA4
	add [HERO_X], 0x0002

LABEL_BEA4:
	break
	je [HERO_POS_MASK], 0x09, LABEL_C381
	call SET_VAR04_TO_0030
	call LABEL_93A6
	jne [HERO_POS_MASK], 0x01, LABEL_BEA4
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	call LABEL_93BA
	je [HERO_POS_MASK], 0x00, LABEL_BDEE
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_921C
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BEE5
	je [HERO_POS_MASK], 0x00, LABEL_BDE6
	add [HERO_X], 0x0001

LABEL_BEE5:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_92BA
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BF01
	je [HERO_POS_MASK], 0x00, LABEL_BDDE
	add [HERO_X], 0x0001

LABEL_BF01:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF8
	break
	call LABEL_92CB
	add [HERO_X], 0x0001
	mov [0x36], 0x0005
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BF1F
	add [HERO_X], 0x0002

LABEL_BF1F:
	break
	call LABEL_92DC
	add [HERO_X], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BF35
	add [HERO_X], 0x0001

LABEL_BF35:
	break
	call LABEL_92ED
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BF47
	add [HERO_X], 0x0002

LABEL_BF47:
	break
	call LABEL_9304
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_C6F3
	je [HERO_POS_MASK], 0x09, LABEL_C381

LABEL_BF62:
	call LABEL_9315
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	jmp LABEL_BE04
LABEL_BF7A:
	db 0x11

LABEL_BF7B:
	break
	je [0x63], 0x05, LABEL_BF7B
	sub [HERO_X], 0x0003
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	killChannel

LABEL_BFA0:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_BFA7:
	db 0x11

LABEL_BFA8:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_328, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_BFA0
	break

LABEL_BFBC:
	call LABEL_94E5
	je [HERO_POS_MASK], 0x00, LABEL_BFA0
	break
	je [HERO_POS_MASK], 0x00, LABEL_BFBC

LABEL_BFCC:
	setup channel=0x15, address=LABEL_BF7B
	sub [HERO_X], 0x0004

LABEL_BFD4:
	call LABEL_9691
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [HERO_X], 0x0006
	break
	call LABEL_96AE
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C2BA
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_96C5
	sub [HERO_X], 0x0008
	break
	call LABEL_96DC
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_96F3
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_BFA0
	sub [HERO_X], 0x000A
	break

LABEL_C01C:
	mov [0x63], 0x0005
	call LABEL_9702
	sub [HERO_X], 0x0006
	break
	call LABEL_971F
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C2BA
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_9736
	sub [HERO_X], 0x0008
	break
	call LABEL_974D
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_9764
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_BFA0
	sub [HERO_X], 0x000A
	break
	jmp LABEL_BFD4
LABEL_C064:
	db 0x11

LABEL_C065:
	break
	je [0x63], 0x06, LABEL_C065
	add [HERO_X], 0x0003
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	killChannel

LABEL_C08A:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C091:
	db 0x11

LABEL_C092:
	video offset=CINEMATIC_328, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_C08A
	break

LABEL_C0A2:
	call LABEL_9315
	je [HERO_POS_MASK], 0x00, LABEL_C08A
	break
	je [HERO_POS_MASK], 0x00, LABEL_C0A2

LABEL_C0B2:
	setup channel=0x15, address=LABEL_C065
	add [HERO_X], 0x0004

LABEL_C0BA:
	call LABEL_95D5
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_95EC
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C42E
	add [HERO_X], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_95FD
	add [HERO_X], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_960E
	add [HERO_X], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_961F
	je [HERO_POS_MASK], 0x00, LABEL_C08A
	add [HERO_X], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_C10A:
	mov [0x63], 0x0006
	call LABEL_9630
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9647
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C42E
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9658
	add [HERO_X], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9669
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_967A
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_C08A
	add [HERO_X], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_C0BA
LABEL_C166:
	db 0x11

LABEL_C167:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_74B2
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_329, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_C182:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C1B2
	call LABEL_93E9
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C182
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_329, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_331, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C1B1:
	db 0x11

LABEL_C1B2:
	jne [0x0F], 0x00, LABEL_C1EB
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_330, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5B67
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_329, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C182
	setup channel=0x17, address=LABEL_6AC1

LABEL_C1EA:
	break

LABEL_C1EB:
	call LABEL_93E9
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C1EA
	jmp LABEL_C182
	killChannel
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C1B2
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C20C:
	db 0x11

LABEL_C20D:
	je [HERO_POS_MASK], 0x09, LABEL_C381
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_048, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_049, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_050, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0024
	video type=0, offset=COMMON_VIDEO_051, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_052, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	mov [0x34], 0xFFFE
	sub [HERO_X], 0x000F
	call LABEL_70C5
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x000F
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_BDA2
LABEL_C2B9:
	db 0x11

LABEL_C2BA:
	je [HERO_POS_MASK], 0x09, LABEL_C42E
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C2D4:
	je [HERO_POS_MASK], 0x09, LABEL_C448
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x34], 0xFFFB
	sub [HERO_X], 0x000F
	call LABEL_70C5
	sub [HERO_X], 0x0002
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	sub [HERO_X], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_C01C
	add [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_BDA2
LABEL_C380:
	db 0x11

LABEL_C381:
	je [HERO_POS_MASK], 0x0A, LABEL_C20D
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_003, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_004, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_005, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0034
	video type=0, offset=COMMON_VIDEO_006, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_007, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_009, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	mov [0x34], 0x0002
	add [HERO_X], 0x000F
	call LABEL_70C5
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_010, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x000F
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_011, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_BF62
LABEL_C42D:
	db 0x11

LABEL_C42E:
	je [HERO_POS_MASK], 0x0A, LABEL_C2BA
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C448:
	je [HERO_POS_MASK], 0x0A, LABEL_C2D4
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_009, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_085, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_085, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_010, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x34], 0x0005
	add [HERO_X], 0x000F
	call LABEL_70C5
	add [HERO_X], 0x0002
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_011, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	add [HERO_X], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_C10A
	sub [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_BF62
LABEL_C4F4:
	db 0x11

LABEL_C4F5:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_74B2
	add [HERO_X], 0x0004
	video type=0, offset=COMMON_VIDEO_348, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001

LABEL_C50C:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C53C
	call LABEL_91CD
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C50C
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_348, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_351, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C53B:
	db 0x11

LABEL_C53C:
	jne [0x0F], 0x00, LABEL_C575
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_350, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5BE3
	break
	sub [HERO_X], 0x0001
	video type=0, offset=COMMON_VIDEO_348, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C50C
	setup channel=0x17, address=LABEL_6B2A

LABEL_C574:
	break

LABEL_C575:
	call LABEL_91CD
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C574
	jmp LABEL_C50C
	killChannel
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_74B2
	jne [0x0A], 0x00, LABEL_C53C
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C599:
	db 0x11

LABEL_C59A:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C5C4
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C5AE:
	db 0x11

LABEL_C5AF:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C668
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C5C3:
	db 0x11

LABEL_C5C4:
	jne [0x0F], 0x00, LABEL_C600
	sub [HERO_X], 0x0003
	call LABEL_74B2
	video type=0, offset=COMMON_VIDEO_338, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5B67
	break
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_337, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_C627
	setup channel=0x17, address=LABEL_6AC1

LABEL_C5FF:
	break

LABEL_C600:
	call LABEL_93CB
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C5FF
	jmp LABEL_C627
LABEL_C60C:
	db 0x11

LABEL_C60D:
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_74B2
	add [HERO_X], 0x0003
	video type=0, offset=COMMON_VIDEO_336, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_337, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_C627:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C5C4
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_C5C4
	call LABEL_93CB
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_C627
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_C652:
	db 0x11

LABEL_C653:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_C60D
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C667:
	db 0x11

LABEL_C668:
	jne [0x0F], 0x00, LABEL_C6A4
	add [HERO_X], 0x0003
	call LABEL_74B2
	video type=0, offset=COMMON_VIDEO_333, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5BE3
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_330, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_C6C7
	setup channel=0x17, address=LABEL_6B2A

LABEL_C6A3:
	break

LABEL_C6A4:
	call LABEL_91AF
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C6A3
	jmp LABEL_C6C7
LABEL_C6B0:
	db 0x11

LABEL_C6B1:
	mov [0x2A], 0x0020
	call LABEL_74B2
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_329, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_330, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_C6C7:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C668
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_C668
	call LABEL_91AF
	je [HERO_POS_MASK], 0x04, LABEL_C6C7
	break
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_334, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C6F2:
	db 0x11

LABEL_C6F3:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_C6B1
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C707:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
	FILL(14569, 0xFF)
