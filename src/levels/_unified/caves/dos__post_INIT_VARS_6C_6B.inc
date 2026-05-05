LABEL_39D4:
	mov [0x09], 0x0087
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00A8
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call LABEL_3656
	call GUARDED_DRAW_CIN_600_810
	add [0x08], 0x000A
	call GUARDED_DRAW_CIN_600_810
	break
	djnz [0x6B], LABEL_39D4
	killChannel

LABEL_39F9:
	mov [0x63], 0x0001
	video offset=CINEMATIC_819, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_820, x=[HERO_X], y=[HERO_Y]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3A15
	play id=0x006C, freq=0x14, vol=0x20, channel=0x00

LABEL_3A15:
	video offset=CINEMATIC_821, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_822, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_823, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_822, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_821, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_820, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_39F9

LABEL_3A3C:
	video offset=CINEMATIC_880, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_881, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_882, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_883, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_884, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_885, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_886, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_887, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_888, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_889, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_890, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3A3C
	killChannel

HANG_DRAW_CIN_903:
	video offset=CINEMATIC_903, x=[HERO_X], y=[HERO_Y]
	break
	jmp HANG_DRAW_CIN_903
LABEL_3A8B:
	db 0x11

LABEL_3A8C:
	mov [0x63], 0x0064
	video offset=CINEMATIC_492, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_491, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_490, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp LABEL_39F9

LABEL_3ABD:
	setup channel=0x15, address=LABEL_3B3F
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3ACA:
	setup channel=0x15, address=LABEL_3BA9
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AD7:
	setup channel=0x15, address=LABEL_3C81
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AE4:
	setup channel=0x15, address=LABEL_3D58
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AF1:
	setup channel=0x15, address=LABEL_3BE3
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AFE:
	setup channel=0x15, address=LABEL_3D27
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B0B:
	setup channel=0x15, address=LABEL_3A8C
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B18:
	setup channel=0x15, address=LABEL_3B78
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B25:
	setup channel=0x15, address=LABEL_3C14
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B32:
	setup channel=0x15, address=LABEL_3CBA
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B3F:
	mov [0x63], 0x0068
	video offset=CINEMATIC_490, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_491, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_492, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp LABEL_3D91

LABEL_3B78:
	mov [0x63], 0x0064
	video offset=CINEMATIC_514, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_513, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_512, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp LABEL_39F9

LABEL_3BA9:
	mov [0x63], 0x0067
	video offset=CINEMATIC_512, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_513, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_514, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DCC
	break
	jmp LABEL_3E87
LABEL_3BE2:
	db 0x11

LABEL_3BE3:
	mov [0x63], 0x0064
	video offset=CINEMATIC_474, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_473, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_472, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3C14:
	mov [0x63], 0x0064
	video offset=CINEMATIC_554, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_552, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_549, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_548, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_547, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_546, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3C81:
	mov [0x63], 0x0068
	video offset=CINEMATIC_472, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_473, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_474, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp LABEL_3D91

LABEL_3CBA:
	mov [0x63], 0x0064
	video offset=CINEMATIC_546, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_547, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_548, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_549, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_552, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_554, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp LABEL_39F9

LABEL_3D27:
	mov [0x63], 0x0064
	video offset=CINEMATIC_495, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_494, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	break
	video offset=CINEMATIC_493, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3D58:
	mov [0x63], 0x0067
	video offset=CINEMATIC_493, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_494, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_495, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DCC
	break
	jmp LABEL_3E87

LABEL_3D91:
	mov [0x63], 0x0004
	mov [0x19], 0x001E
	video offset=CINEMATIC_471, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_475, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_476, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_477, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_478, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_477, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_476, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_475, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3D91

LABEL_3DCC:
	video offset=CINEMATIC_501, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_502, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_503, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_504, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_505, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_506, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_507, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_508, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_509, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_510, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_511, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3DCC
LABEL_3E11:
	db 0x11

LABEL_3E12:
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	call LABEL_E3C1
	je [0x22], 0x03E8, LABEL_3E12
	jmp LABEL_3E60

LABEL_3E37:
	video offset=CINEMATIC_479, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_480, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_481, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_482, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_483, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_484, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_485, x=[HERO_X], y=[HERO_Y]

LABEL_3E60:
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	call LABEL_E3C1
	je [0x22], 0x03E8, LABEL_3E12
	break
	video offset=CINEMATIC_488, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_489, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3E37
LABEL_3E86:
	db 0x11

LABEL_3E87:
	mov [0x63], 0x0003
	video offset=CINEMATIC_496, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_497, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_498, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_499, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_500, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_499, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_498, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_497, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3E87
LABEL_3EBE:
	db 0x11

LABEL_3EBF:
	mov [0x63], 0x0002
	video offset=CINEMATIC_530, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_531, x=[HERO_X], y=[HERO_Y]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3EDB
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01

LABEL_3EDB:
	video offset=CINEMATIC_532, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_533, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_534, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_533, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_532, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_531, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3EBF

LABEL_3F02:
	video offset=CINEMATIC_535, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_536, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_537, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_538, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_539, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_540, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_541, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_542, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_543, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_544, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_545, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3F02
LABEL_3F47:
	db 0x11
