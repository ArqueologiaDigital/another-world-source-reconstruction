LABEL_37AB:
	mov [0x09], 0x0087
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00A8
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call LABEL_342D
	call GUARDED_DRAW_CIN_579_786
	add [0x08], 0x000A
	call GUARDED_DRAW_CIN_579_786
	break
	djnz [0x6B], LABEL_37AB
	killChannel

LABEL_37D0:
	mov [0x63], 0x0001
	video offset=CINEMATIC_795, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_796, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_37EC
	play id=0x006C, freq=0x14, vol=0x20, channel=0x00

LABEL_37EC:
	video offset=CINEMATIC_797, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_798, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_799, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_798, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_797, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_796, x=[0x01], y=[0x02]
	break
	jmp LABEL_37D0

LABEL_3813:
	video offset=CINEMATIC_857, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_858, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_859, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_860, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_861, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_862, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_863, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_864, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_865, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_866, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_867, x=[0x01], y=[0x02]
	break
	jmp LABEL_3813
LABEL_3858:
	db 0x11, 0x54, 0x49, 0xE2, 0x01, 0x02, 0x06, 0x07
	db 0x38, 0x59, 0x11

LABEL_3863:
	mov [0x63], 0x0064
	video offset=CINEMATIC_471, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_470, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_469, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3813
	break
	jmp LABEL_37D0

LABEL_3894:
	setup channel=0x15, address=LABEL_3916
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38A1:
	setup channel=0x15, address=LABEL_3980
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38AE:
	setup channel=0x15, address=LABEL_3A58
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38BB:
	setup channel=0x15, address=LABEL_3B2F
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38C8:
	setup channel=0x15, address=LABEL_39BA
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38D5:
	setup channel=0x15, address=LABEL_3AFE
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38E2:
	setup channel=0x15, address=LABEL_3863
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38EF:
	setup channel=0x15, address=LABEL_394F
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_38FC:
	setup channel=0x15, address=LABEL_39EB
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3909:
	setup channel=0x15, address=LABEL_3A91
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3916:
	mov [0x63], 0x0064
	video offset=CINEMATIC_469, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_470, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_471, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3C0E
	break
	jmp LABEL_3B68

LABEL_394F:
	mov [0x63], 0x0064
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3813
	break
	jmp LABEL_37D0

LABEL_3980:
	mov [0x63], 0x0064
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3BA3
	break
	jmp LABEL_3C5E
LABEL_39B9:
	db 0x11

LABEL_39BA:
	mov [0x63], 0x0064
	video offset=CINEMATIC_453, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_452, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_451, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3CD9
	break
	jmp LABEL_3C96

LABEL_39EB:
	mov [0x63], 0x0064
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_531, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_530, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_529, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_528, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_527, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_526, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_525, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3CD9
	break
	jmp LABEL_3C96

LABEL_3A58:
	mov [0x63], 0x0064
	video offset=CINEMATIC_451, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_452, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_453, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3C0E
	break
	jmp LABEL_3B68

LABEL_3A91:
	mov [0x63], 0x0064
	video offset=CINEMATIC_525, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_526, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_527, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_528, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_529, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_530, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_531, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3813
	break
	jmp LABEL_37D0

LABEL_3AFE:
	mov [0x63], 0x0064
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	break
	video offset=CINEMATIC_472, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3CD9
	break
	jmp LABEL_3C96

LABEL_3B2F:
	mov [0x63], 0x0064
	video offset=CINEMATIC_472, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3BA3
	break
	jmp LABEL_3C5E

LABEL_3B68:
	mov [0x63], 0x0004
	mov [0x19], 0x001E
	video offset=CINEMATIC_450, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_454, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_455, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_456, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_457, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_456, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_455, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_454, x=[0x01], y=[0x02]
	break
	jmp LABEL_3B68

LABEL_3BA3:
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
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_488, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_489, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_490, x=[0x01], y=[0x02]
	break
	jmp LABEL_3BA3
LABEL_3BE8:
	db 0x11

LABEL_3BE9:
	break
	video offset=CINEMATIC_466, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_465, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_465, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_466, x=[0x01], y=[0x02]
	call LABEL_DE71
	je [0x22], 0x03E8, LABEL_3BE9
	jmp LABEL_3C37

LABEL_3C0E:
	video offset=CINEMATIC_458, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_459, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_460, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_461, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_462, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_463, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_464, x=[0x01], y=[0x02]

LABEL_3C37:
	break
	video offset=CINEMATIC_465, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_466, x=[0x01], y=[0x02]
	call LABEL_DE71
	je [0x22], 0x03E8, LABEL_3BE9
	break
	video offset=CINEMATIC_467, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_468, x=[0x01], y=[0x02]
	break
	jmp LABEL_3C0E
LABEL_3C5D:
	db 0x11

LABEL_3C5E:
	mov [0x63], 0x0003
	video offset=CINEMATIC_475, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_476, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_477, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_478, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_479, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_478, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_477, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_476, x=[0x01], y=[0x02]
	break
	jmp LABEL_3C5E
LABEL_3C95:
	db 0x11

LABEL_3C96:
	mov [0x63], 0x0002
	video offset=CINEMATIC_509, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_510, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3CB2
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01

LABEL_3CB2:
	video offset=CINEMATIC_511, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_512, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_513, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_512, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_511, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_510, x=[0x01], y=[0x02]
	break
	jmp LABEL_3C96

LABEL_3CD9:
	video offset=CINEMATIC_514, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_515, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_516, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_517, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_518, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_519, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_520, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_521, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_522, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_523, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_524, x=[0x01], y=[0x02]
	break
	jmp LABEL_3CD9
LABEL_3D1E:
	db 0x11
