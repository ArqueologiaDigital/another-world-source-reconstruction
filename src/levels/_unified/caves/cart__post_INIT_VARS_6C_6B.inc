LABEL_39BE:
	mov [0x09], 0x0087
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00A8
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call LABEL_363A
	call GUARDED_DRAW_CIN_589_801
	add [0x08], 0x000A
	call GUARDED_DRAW_CIN_589_801
	break
	djnz [0x6B], LABEL_39BE
	killChannel

LABEL_39E3:
	mov [0x63], 0x0001
	video offset=CINEMATIC_810, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_811, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_39FF
	play id=0x006C, freq=0x14, vol=0x20, channel=0x00

LABEL_39FF:
	video offset=CINEMATIC_812, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_813, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_814, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_813, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_812, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_811, x=[0x01], y=[0x02]
	break
	jmp LABEL_39E3

LABEL_3A26:
	video offset=CINEMATIC_870, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_871, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_872, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_873, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_874, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_875, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_876, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_877, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_878, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_879, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_880, x=[0x01], y=[0x02]
	break
	jmp LABEL_3A26
	killChannel

HANG_DRAW_CIN_889:
	video offset=CINEMATIC_889, x=[0x01], y=[0x02]
	break
	jmp HANG_DRAW_CIN_889
LABEL_3A75:
	db 0x11

LABEL_3A76:
	mov [0x63], 0x0064
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A26
	break
	jmp LABEL_39E3

LABEL_3AA7:
	setup channel=0x15, address=LABEL_3B29
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AB4:
	setup channel=0x15, address=LABEL_3B93
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AC1:
	setup channel=0x15, address=LABEL_3C6B
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3ACE:
	setup channel=0x15, address=LABEL_3D42
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3ADB:
	setup channel=0x15, address=LABEL_3BCD
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AE8:
	setup channel=0x15, address=LABEL_3D11
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3AF5:
	setup channel=0x15, address=LABEL_3A76
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B02:
	setup channel=0x15, address=LABEL_3B62
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B0F:
	setup channel=0x15, address=LABEL_3BFE
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B1C:
	setup channel=0x15, address=LABEL_3CA4
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret

LABEL_3B29:
	mov [0x63], 0x0068
	video offset=CINEMATIC_491, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_492, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_493, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E21
	break
	jmp LABEL_3D7B

LABEL_3B62:
	mov [0x63], 0x0064
	video offset=CINEMATIC_515, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_514, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_513, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A26
	break
	jmp LABEL_39E3

LABEL_3B93:
	mov [0x63], 0x0067
	video offset=CINEMATIC_513, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_514, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_515, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DB6
	break
	jmp LABEL_3E71
LABEL_3BCC:
	db 0x11

LABEL_3BCD:
	mov [0x63], 0x0064
	video offset=CINEMATIC_475, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3EEC
	break
	jmp LABEL_3EA9

LABEL_3BFE:
	mov [0x63], 0x0064
	video offset=CINEMATIC_555, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_554, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_553, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_552, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_551, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_550, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_549, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_548, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_547, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3EEC
	break
	jmp LABEL_3EA9

LABEL_3C6B:
	mov [0x63], 0x0068
	video offset=CINEMATIC_473, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_474, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_475, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E21
	break
	jmp LABEL_3D7B

LABEL_3CA4:
	mov [0x63], 0x0064
	video offset=CINEMATIC_547, x=[0x01], y=[0x02]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_548, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_549, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_550, x=[0x01], y=[0x02]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_551, x=[0x01], y=[0x02]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_552, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_553, x=[0x01], y=[0x02]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_554, x=[0x01], y=[0x02]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_555, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A26
	break
	jmp LABEL_39E3

LABEL_3D11:
	mov [0x63], 0x0064
	video offset=CINEMATIC_496, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_495, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	break
	video offset=CINEMATIC_494, x=[0x01], y=[0x02]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3EEC
	break
	jmp LABEL_3EA9

LABEL_3D42:
	mov [0x63], 0x0067
	video offset=CINEMATIC_494, x=[0x01], y=[0x02]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_495, x=[0x01], y=[0x02]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_496, x=[0x01], y=[0x02]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DB6
	break
	jmp LABEL_3E71

LABEL_3D7B:
	mov [0x63], 0x0004
	mov [0x19], 0x001E
	video offset=CINEMATIC_472, x=[0x01], y=[0x02]
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
	jmp LABEL_3D7B

LABEL_3DB6:
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
	video offset=CINEMATIC_512, x=[0x01], y=[0x02]
	break
	jmp LABEL_3DB6
LABEL_3DFB:
	db 0x11

LABEL_3DFC:
	break
	video offset=CINEMATIC_488, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_488, x=[0x01], y=[0x02]
	call LABEL_E44A
	je [0x22], 0x03E8, LABEL_3DFC
	jmp LABEL_3E4A

LABEL_3E21:
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

LABEL_3E4A:
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_488, x=[0x01], y=[0x02]
	call LABEL_E44A
	je [0x22], 0x03E8, LABEL_3DFC
	break
	video offset=CINEMATIC_489, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_490, x=[0x01], y=[0x02]
	break
	jmp LABEL_3E21
LABEL_3E70:
	db 0x11

LABEL_3E71:
	mov [0x63], 0x0003
	video offset=CINEMATIC_497, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_498, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_499, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_500, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_501, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_500, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_499, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_498, x=[0x01], y=[0x02]
	break
	jmp LABEL_3E71
LABEL_3EA8:
	db 0x11

LABEL_3EA9:
	mov [0x63], 0x0002
	video offset=CINEMATIC_531, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	break
	jne [HACK_VAR_67], 0x6E, LABEL_3EC5
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01

LABEL_3EC5:
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_534, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_535, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_534, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_533, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_532, x=[0x01], y=[0x02]
	break
	jmp LABEL_3EA9

LABEL_3EEC:
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
	video offset=CINEMATIC_546, x=[0x01], y=[0x02]
	break
	jmp LABEL_3EEC
LABEL_3F31:
	db 0x11
