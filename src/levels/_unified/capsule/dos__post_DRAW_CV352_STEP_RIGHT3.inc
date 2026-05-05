LABEL_BD20:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_92C0
	je [HERO_POS_MASK], 0x00, LABEL_BCEB
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_92D1
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD4C
	je [HERO_POS_MASK], 0x00, LABEL_BCE3
	add [0x01], 0x0001

LABEL_BD4C:
	add [0x01], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_92E2
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD68
	je [HERO_POS_MASK], 0x00, LABEL_BCDB
	add [0x01], 0x0001

LABEL_BD68:
	add [0x01], 0x0001
	mov [0x36], 0x0007
	break
	call LABEL_92F3
	mov [0x36], 0x0005
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD86
	add [0x01], 0x0002

LABEL_BD86:
	break
	call LABEL_9304
	add [0x01], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD9C
	add [0x01], 0x0001

LABEL_BD9C:
	break
	call LABEL_9315
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BDAE
	add [0x01], 0x0002

LABEL_BDAE:
	break
	call LABEL_932C
	mov [0x36], 0x0000
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BDC0
	add [0x01], 0x0002

LABEL_BDC0:
	break
	je [HERO_POS_MASK], 0x09, LABEL_C29D
	call SET_VAR04_TO_0030
	call LABEL_933D
	jne [HERO_POS_MASK], 0x01, LABEL_BDC0
	add [0x01], 0x0002
	mov [0x36], 0xFFFD
	break
	call LABEL_9351
	je [HERO_POS_MASK], 0x00, LABEL_BD0A
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_91B3
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE01
	je [HERO_POS_MASK], 0x00, LABEL_BD02
	add [0x01], 0x0001

LABEL_BE01:
	add [0x01], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_9251
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE1D
	je [HERO_POS_MASK], 0x00, LABEL_BCFA
	add [0x01], 0x0001

LABEL_BE1D:
	add [0x01], 0x0001
	mov [0x36], 0xFFF8
	break
	call LABEL_9262
	add [0x01], 0x0001
	mov [0x36], 0x0005
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE3B
	add [0x01], 0x0002

LABEL_BE3B:
	break
	call LABEL_9273
	add [0x01], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE51
	add [0x01], 0x0001

LABEL_BE51:
	break
	call LABEL_9284
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE63
	add [0x01], 0x0002

LABEL_BE63:
	break
	call LABEL_929B
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_C60F
	je [HERO_POS_MASK], 0x09, LABEL_C29D

LABEL_BE7E:
	call LABEL_92AC
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002
	mov [0x36], 0xFFFD
	break
	jmp LABEL_BD20
LABEL_BE96:
	db 0x11

LABEL_BE97:
	break
	je [0x63], 0x05, LABEL_BE97
	sub [0x01], 0x0003
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	killChannel

LABEL_BEBC:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_BEC3:
	db 0x11

LABEL_BEC4:
	sub [0x01], 0x0004
	video offset=CINEMATIC_327, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_BEBC
	break

LABEL_BED8:
	call LABEL_947C
	je [HERO_POS_MASK], 0x00, LABEL_BEBC
	break
	je [HERO_POS_MASK], 0x00, LABEL_BED8

LABEL_BEE8:
	setup channel=0x15, address=LABEL_BE97
	sub [0x01], 0x0004

LABEL_BEF0:
	call LABEL_9628
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [0x01], 0x0006
	break
	call LABEL_9645
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C1D6
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_965C
	sub [0x01], 0x0008
	break
	call LABEL_9673
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_968A
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_BEBC
	sub [0x01], 0x000A
	break

LABEL_BF38:
	mov [0x63], 0x0005
	call LABEL_9699
	sub [0x01], 0x0006
	break
	call LABEL_96B6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C1D6
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_96CD
	sub [0x01], 0x0008
	break
	call LABEL_96E4
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_96FB
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_BEBC
	sub [0x01], 0x000A
	break
	jmp LABEL_BEF0
LABEL_BF80:
	db 0x11

LABEL_BF81:
	break
	je [0x63], 0x06, LABEL_BF81
	add [0x01], 0x0003
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	killChannel

LABEL_BFA6:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_BFAD:
	db 0x11

LABEL_BFAE:
	video offset=CINEMATIC_327, x=[0x01], y=[0x02]
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_BFA6
	break

LABEL_BFBE:
	call LABEL_92AC
	je [HERO_POS_MASK], 0x00, LABEL_BFA6
	break
	je [HERO_POS_MASK], 0x00, LABEL_BFBE

LABEL_BFCE:
	setup channel=0x15, address=LABEL_BF81
	add [0x01], 0x0004

LABEL_BFD6:
	call LABEL_956C
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9583
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C34A
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9594
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_95A5
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_95B6
	je [HERO_POS_MASK], 0x00, LABEL_BFA6
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_C026:
	mov [0x63], 0x0006
	call LABEL_95C7
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_95DE
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C34A
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_95EF
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9600
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9611
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_BFA6
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_BFD6
LABEL_C082:
	db 0x11

LABEL_C083:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7449
	sub [0x01], 0x0003
	video offset=CINEMATIC_328, x=[0x01], y=[0x02]
	sub [0x01], 0x0001

LABEL_C09E:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C0CE
	call LABEL_9380
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C09E
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_328, x=[0x01], y=[0x02]
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_330, x=[0x01], y=[0x02]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C0CD:
	db 0x11

LABEL_C0CE:
	jne [0x0F], 0x00, LABEL_C107
	sub [0x01], 0x0002
	video offset=CINEMATIC_329, x=[0x01], y=[0x02]
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5B64
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_328, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C09E
	setup channel=0x17, address=LABEL_6AB2

LABEL_C106:
	break

LABEL_C107:
	call LABEL_9380
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C106
	jmp LABEL_C09E
	killChannel
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C0CE
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C128:
	db 0x11

LABEL_C129:
	je [HERO_POS_MASK], 0x09, LABEL_C29D
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_048, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_049, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_050, x=[0x01], y=[0x02], zoom=0x40
	break
	call SET_VAR04_TO_0024
	video type=0, offset=COMMON_VIDEO_051, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_052, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	mov [0x34], 0xFFFE
	sub [0x01], 0x000F
	call LABEL_706D
	break
	add [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	sub [0x01], 0x000F
	break
	add [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	call SET_VAR04_TO_0020
	sub [0x01], 0x000C
	break
	add [0x01], 0x000C
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0004
	sub [0x01], 0x0007
	break
	add [0x01], 0x0007
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_BCBE
LABEL_C1D5:
	db 0x11

LABEL_C1D6:
	je [HERO_POS_MASK], 0x09, LABEL_C34A
	sub [0x01], 0x0005
	sub [0x01], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C1F0:
	je [HERO_POS_MASK], 0x09, LABEL_C364
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
	sub [0x02], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	mov [0x34], 0xFFFB
	sub [0x01], 0x000F
	call LABEL_706D
	sub [0x01], 0x0002
	break
	add [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	call SET_VAR04_TO_0020
	sub [0x01], 0x000C
	break
	add [0x01], 0x000C
	sub [0x01], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_BF38
	add [0x01], 0x0005
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0004
	sub [0x01], 0x0007
	break
	add [0x01], 0x0007
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_BCBE
LABEL_C29C:
	db 0x11

LABEL_C29D:
	je [HERO_POS_MASK], 0x0A, LABEL_C129
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_003, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_004, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_005, x=[0x01], y=[0x02], zoom=0x40
	break
	call SET_VAR04_TO_0034
	video type=0, offset=COMMON_VIDEO_006, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_007, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	mov [0x34], 0x0002
	add [0x01], 0x000F
	call LABEL_706D
	break
	sub [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	add [0x01], 0x000F
	break
	sub [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	call SET_VAR04_TO_0030
	add [0x01], 0x000C
	break
	sub [0x01], 0x000C
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	add [0x01], 0x0007
	break
	sub [0x01], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_BE7E
LABEL_C349:
	db 0x11

LABEL_C34A:
	je [HERO_POS_MASK], 0x0A, LABEL_C1D6
	add [0x01], 0x0005
	add [0x01], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C364:
	je [HERO_POS_MASK], 0x0A, LABEL_C1F0
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
	sub [0x02], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	mov [0x34], 0x0005
	add [0x01], 0x000F
	call LABEL_706D
	add [0x01], 0x0002
	break
	sub [0x01], 0x000F
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	call SET_VAR04_TO_0030
	add [0x01], 0x000C
	break
	sub [0x01], 0x000C
	add [0x01], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_C026
	sub [0x01], 0x0005
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	add [0x01], 0x0007
	break
	sub [0x01], 0x0007
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_BE7E
LABEL_C410:
	db 0x11

LABEL_C411:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_7449
	add [0x01], 0x0004
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_C428:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C458
	call LABEL_9164
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C428
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_351, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C457:
	db 0x11

LABEL_C458:
	jne [0x0F], 0x00, LABEL_C491
	add [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_350, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5BE0
	break
	sub [0x01], 0x0001
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C428
	setup channel=0x17, address=LABEL_6B1B

LABEL_C490:
	break

LABEL_C491:
	call LABEL_9164
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C490
	jmp LABEL_C428
	killChannel
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_7449
	jne [0x0A], 0x00, LABEL_C458
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C4B5:
	db 0x11

LABEL_C4B6:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C4E0
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C4CA:
	db 0x11

LABEL_C4CB:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C584
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C4DF:
	db 0x11

LABEL_C4E0:
	jne [0x0F], 0x00, LABEL_C51C
	sub [0x01], 0x0003
	call LABEL_7449
	video type=0, offset=COMMON_VIDEO_338, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5B64
	break
	add [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_C543
	setup channel=0x17, address=LABEL_6AB2

LABEL_C51B:
	break

LABEL_C51C:
	call LABEL_9362
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C51B
	jmp LABEL_C543
LABEL_C528:
	db 0x11

LABEL_C529:
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7449
	add [0x01], 0x0003
	video type=0, offset=COMMON_VIDEO_336, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40

LABEL_C543:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C4E0
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_C4E0
	call LABEL_9362
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_C543
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_C56E:
	db 0x11

LABEL_C56F:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_C529
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C583:
	db 0x11

LABEL_C584:
	jne [0x0F], 0x00, LABEL_C5C0
	add [0x01], 0x0003
	call LABEL_7449
	video type=0, offset=COMMON_VIDEO_333, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5BE0
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_330, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_C5E3
	setup channel=0x17, address=LABEL_6B1B

LABEL_C5BF:
	break

LABEL_C5C0:
	call LABEL_9146
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C5BF
	jmp LABEL_C5E3
LABEL_C5CC:
	db 0x11

LABEL_C5CD:
	mov [0x2A], 0x0020
	call LABEL_7449
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_329, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_330, x=[0x01], y=[0x02], zoom=0x40

LABEL_C5E3:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C584
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_C584
	call LABEL_9146
	je [HERO_POS_MASK], 0x04, LABEL_C5E3
	break
	add [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_334, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C60E:
	db 0x11

LABEL_C60F:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_C5CD
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C623:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
	FILL(14797, 0xFF)
