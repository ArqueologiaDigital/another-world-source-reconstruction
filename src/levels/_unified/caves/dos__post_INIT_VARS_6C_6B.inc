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
	video offset=CINEMATIC_819, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_820, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3A15
	play id=0x006C, freq=0x14, vol=0x20, channel=0x00

LABEL_3A15:
	video offset=CINEMATIC_821, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_822, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_823, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_822, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_821, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_820, x=[0x01], y=[0x02]
	break
	jmp LABEL_39F9

LABEL_3A3C:
	video offset=CINEMATIC_880, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_881, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_882, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_883, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_884, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_885, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_886, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_887, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_888, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_889, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_890, x=[0x01], y=[0x02]
	break
	jmp LABEL_3A3C
	killChannel

HANG_DRAW_CIN_903:
	video offset=CINEMATIC_903, x=[0x01], y=[0x02]
	break
	jmp HANG_DRAW_CIN_903
LABEL_3A8B:
	db 0x11

LABEL_3A8C:
	mov [0x63], 0x0064
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_490, x=[0x01], y=[0x02]
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
	video offset=CINEMATIC_490, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp LABEL_3D91

LABEL_3B78:
	mov [0x63], 0x0064
	video offset=CINEMATIC_514, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_513, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_512, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp LABEL_39F9

LABEL_3BA9:
	mov [0x63], 0x0067
	video offset=CINEMATIC_512, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_513, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_514, x=[0x01], y=[0x02]
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
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_472, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3C14:
	mov [0x63], 0x0064
	video offset=CINEMATIC_554, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_553, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_552, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_551, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_549, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_548, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_547, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_546, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3C81:
	mov [0x63], 0x0068
	video offset=CINEMATIC_472, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp LABEL_3D91

LABEL_3CBA:
	mov [0x63], 0x0064
	video offset=CINEMATIC_546, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_547, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_548, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_549, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_551, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_552, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_553, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_554, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp LABEL_39F9

LABEL_3D27:
	mov [0x63], 0x0064
	video offset=CINEMATIC_495, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_494, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	break
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp LABEL_3EBF

LABEL_3D58:
	mov [0x63], 0x0067
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_494, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_495, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DCC
	break
	jmp LABEL_3E87

LABEL_3D91:
	mov [0x63], 0x0004
	mov [0x19], 0x001E
	video offset=CINEMATIC_471, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_475, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_476, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_477, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_478, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_477, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_476, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_475, x=[0x01], y=[0x02]
	break
	jmp LABEL_3D91

LABEL_3DCC:
	video offset=CINEMATIC_501, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_502, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_503, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_504, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_505, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_506, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_507, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_508, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_509, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_510, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_511, x=[0x01], y=[0x02]
	break
	jmp LABEL_3DCC
LABEL_3E11:
	db 0x11

LABEL_3E12:
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	call LABEL_E3C1
	je [0x22], 0x03E8, LABEL_3E12
	jmp LABEL_3E60

LABEL_3E37:
	video offset=CINEMATIC_479, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_480, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_481, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_482, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_483, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_484, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_485, x=[0x01], y=[0x02]

LABEL_3E60:
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	call LABEL_E3C1
	je [0x22], 0x03E8, LABEL_3E12
	break
	video offset=CINEMATIC_488, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_489, x=[0x01], y=[0x02]
	break
	jmp LABEL_3E37
LABEL_3E86:
	db 0x11

LABEL_3E87:
	mov [0x63], 0x0003
	video offset=CINEMATIC_496, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_497, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_498, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_499, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_500, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_499, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_498, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_497, x=[0x01], y=[0x02]
	break
	jmp LABEL_3E87
LABEL_3EBE:
	db 0x11

LABEL_3EBF:
	mov [0x63], 0x0002
	video offset=CINEMATIC_530, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_531, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3EDB
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01

LABEL_3EDB:
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_534, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_531, x=[0x01], y=[0x02]
	break
	jmp LABEL_3EBF

LABEL_3F02:
	video offset=CINEMATIC_535, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_536, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_537, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_538, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_539, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_540, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_541, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_542, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_543, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_544, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_545, x=[0x01], y=[0x02]
	break
	jmp LABEL_3F02
LABEL_3F47:
	db 0x11
