LABEL_23F6:
	break
	mov [0x69], 0x00BA
	video type=1, offset=CINEMATIC_331, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_23F6
	mov [0xE6], 0x000A
	setup channel=0x03, address=KILL_CHANNEL_LANDING

LABEL_240C:
	break
	video type=1, offset=CINEMATIC_332, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_240C
	mov [0xE6], 0x0005

LABEL_241A:
	break
	video type=1, offset=CINEMATIC_333, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_241A
	mov [0xE6], 0x0006

LABEL_2428:
	break
	video type=1, offset=CINEMATIC_332, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_2428
	mov [0xE6], 0x0005

LABEL_2436:
	break
	video type=1, offset=CINEMATIC_333, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_2436
	mov [0xE6], 0x0005

LABEL_2444:
	break
	video type=1, offset=CINEMATIC_332, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_2444
	mov [0xE6], 0x0005

LABEL_2452:
	break
	video type=1, offset=CINEMATIC_334, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_2452
	mov [0xE6], 0x0005

LABEL_2460:
	break
	video type=1, offset=CINEMATIC_332, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_2460
	mov [0xE6], 0x0005

LABEL_246E:
	break
	video type=1, offset=CINEMATIC_334, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_246E
	mov [0xE6], 0x0005

LABEL_247C:
	break
	video type=1, offset=CINEMATIC_332, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_247C
	mov [0xE6], 0x0005
	setup channel=0x03, address=HANG_DRAW_CIN_351

LABEL_248E:
	break
	video type=1, offset=CINEMATIC_331, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_248E
	mov [0xE6], 0x0006

LABEL_249C:
	break
	video type=1, offset=CINEMATIC_335, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_249C
	mov [0xE6], 0x0005

LABEL_24AA:
	break
	video type=1, offset=CINEMATIC_336, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_24AA
	mov [0xE6], 0x0005

LABEL_24B8:
	break
	video type=1, offset=CINEMATIC_337, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_24B8
	mov [0xE6], 0x0014

LABEL_24C6:
	break
	video type=1, offset=CINEMATIC_335, x=[0x68], y=[0x69], zoom=0x40
	djnz [0xE6], LABEL_24C6
	jmp INIT_VARS_E6_68_69_6B
LABEL_24D3:
	db 0x11

LABEL_24D4:
	break
	jmp LABEL_24D4

LABEL_24D8:
	jg [0x02], 0x46, LABEL_2505
	jl [0x01], 0xC2, LABEL_2505
	jg [0x01], 0xD0, LABEL_24FB
	mov [0x46], 0xF060
	setup channel=0x14, address=LABEL_250A
	setup channel=0x15, address=LABEL_2587
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_24FB:
	jg [0x01], 0xF3, LABEL_2505
	mov [0x46], 0xF060

LABEL_2505:
	break
	jmp LABEL_24D8
LABEL_2509:
	db 0x11

LABEL_250A:
	mov [0x63], 0x0000
	jne [HERO_POS_UP_DOWN], 0xFFFF, LABEL_2519
	mov [0x63], 0x0003

LABEL_2519:
	jne [HERO_POS_UP_DOWN], 0x01, LABEL_2523
	mov [0x63], 0x0004

LABEL_2523:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_252E
	mov [0x63], 0x0001

LABEL_252E:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_2538
	mov [0x63], 0x0002

LABEL_2538:
	break
	jmp LABEL_250A
LABEL_253C:
	db 0x11

LABEL_253D:
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_669, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x02], 0x0001
	video type=1, offset=CINEMATIC_670, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_669, x=[0x01], y=[0x02], zoom=0x40
	killChannel

LABEL_2557:
	add [0x02], 0x0004
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	je [HERO_POS_UP_DOWN], 0x01, LABEL_2557
	add [0x02], 0x0003
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	add [0x02], 0x0002
	jmp LABEL_25A1
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	killChannel

LABEL_2587:
	video type=1, offset=CINEMATIC_654, x=198, y=43
	break
	video type=1, offset=CINEMATIC_654, x=198, y=44
	mov [0x01], 0x00C6
	mov [0x02], 0x002D
	mov [0x03], 0x0001
	mov [0x19], 0x0037
	break

LABEL_25A1:
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	je [0x63], 0x01, LABEL_25EE
	jne [0x63], 0x02, LABEL_25BD
	sub [0x03], 0x0001
	jmp LABEL_25EE

LABEL_25BD:
	jne [0x63], 0x03, LABEL_25D5
	jl [0x02], 0x14, LABEL_25A1
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x16, address=LABEL_253D
	jmp LABEL_25E7

LABEL_25D5:
	jne [0x63], 0x04, LABEL_25A1
	jmp LABEL_2557
	video type=1, offset=CINEMATIC_669, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x16, address=LABEL_2557

LABEL_25E7:
	break
	break
	break
	break
	jmp LABEL_25A1

LABEL_25EE:
	jne [0x03], 0x01, LABEL_2600
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	mov [0x19], 0x0037

LABEL_2600:
	jne [0x03], 0x02, LABEL_2612
	mov [0x34], 0x0003
	mov [0x35], 0x0002
	mov [0x19], 0x0037

LABEL_2612:
	jne [0x03], 0x03, LABEL_2624
	mov [0x34], 0x0002
	mov [0x35], 0x0000
	mov [0x19], 0x001E

LABEL_2624:
	jne [0x03], 0x04, LABEL_2636
	mov [0x34], 0x0002
	mov [0x35], 0xFFFF
	mov [0x19], 0x0028

LABEL_2636:
	jne [0x03], 0x05, LABEL_2648
	mov [0x34], 0xFFFC
	mov [0x35], 0x0001
	mov [0x19], 0x0030

LABEL_2648:
	jne [0x03], 0x06, LABEL_265A
	mov [0x34], 0xFFF7
	mov [0x35], 0x0000
	mov [0x19], 0x001E

LABEL_265A:
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	je [0x63], 0x02, LABEL_26DC
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_662, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x0001
	sub [0x01], 0x0009
	video type=1, offset=CINEMATIC_663, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0005
	add [0x01], [0x34]
	video type=1, offset=CINEMATIC_664, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0008
	add [0x01], [0x34]
	video type=1, offset=CINEMATIC_665, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x02], 0x0002
	sub [0x01], 0x0007
	add [0x01], [0x34]
	video type=1, offset=CINEMATIC_666, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_667, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	add [0x02], 0x0002
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_668, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x0001
	sub [0x01], 0x0002
	add [0x01], [0x35]
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x03], 0x0001
	jmp LABEL_25A1

LABEL_26DC:
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_655, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	add [0x02], 0x0001
	add [0x01], 0x0009
	video type=1, offset=CINEMATIC_656, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0005
	sub [0x01], [0x34]
	video type=1, offset=CINEMATIC_657, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0008
	sub [0x01], [0x34]
	video type=1, offset=CINEMATIC_658, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_2752
	break
	sub [0x02], 0x0002
	add [0x01], 0x0007
	sub [0x01], [0x34]
	video type=1, offset=CINEMATIC_659, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_660, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x0002
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_661, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x0001
	add [0x01], 0x0002
	sub [0x01], [0x35]
	video type=1, offset=CINEMATIC_654, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_25A1

LABEL_2752:
	je [0x03], 0x00, LABEL_275F
	jg [0x02], [0x19], LABEL_2782
	ret

LABEL_275F:
	setup channel=0x14, address=LABEL_EBC2
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	call SET_VAR04_TO_0020
	add [0x01], 0x0005
	mov [0x03], 0x0000
	mov [0x34], 0x0005
	mov [0x35], 0x0000
	call LABEL_79C2
	ret

LABEL_2782:
	setup channel=0x14, address=LABEL_EBC2
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	call SET_VAR04_TO_0020
	mov [0x2E], [0x01]
	mov [0x03], 0x0000
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	call LABEL_79C2
	mov [0x01], [0x2E]
	add [0x01], 0x0005
	add [0x02], 0x001E
	ret
	mov [0xEA], 0x000A

ANIM_CIN_641_LOOP_VAREA:
	video type=1, offset=CINEMATIC_641, x=160, y=100
	break
	djnz [0xEA], ANIM_CIN_641_LOOP_VAREA
	video type=1, offset=CINEMATIC_642, x=160, y=100
	video type=1, offset=CINEMATIC_643, x=160, y=100
	break

HANG_DRAW_CIN_643:
	video type=1, offset=CINEMATIC_643, x=160, y=100
	break
	jmp HANG_DRAW_CIN_643
LABEL_27CD:
	db 0x11

LABEL_27CE:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	setup channel=0x01, address=LABEL_315E
	mov [0x02], 0x0056
	jne [HACK_VAR_67], 0x6F, LABEL_27F5
	setup channel=0x01, address=LABEL_3136
	mov [0x02], 0x0086
	jg [0x01], 0x50, LABEL_27F5
	mov [0x01], 0x0050

LABEL_27F5:
	jne [0xF8], 0x00, LABEL_2817
	video type=1, offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x000C
	video type=1, offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x000D
	video type=1, offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_2830

LABEL_2817:
	video type=1, offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x000C
	video type=1, offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x000D
	video type=1, offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40

LABEL_2830:
	break
	sub [0x02], 0x0018
	video type=1, offset=CINEMATIC_472, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_472, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x0005
	call LABEL_DEFC
	setup channel=0x14, address=LABEL_E164
	call SET_VAR18_TO_0122
	mov [0x19], 0x0000
	mov [0x2A], 0x0000
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	mov [0x05], 0x0003
	mov [0x02], 0x0054
	jne [HACK_VAR_67], 0x6F, LABEL_2874
	mov [0x02], 0x0084

LABEL_2874:
	break
	jmp LABEL_3D7B
LABEL_2878:
	db 0x11

LABEL_2879:
	video type=1, offset=CINEMATIC_460, x=[0x01], y=[0x1a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_461, x=[0x01], y=[0x1a], zoom=0x40
	play id=0x0074, freq=0x14, vol=0x40, channel=0x00
	break
	video type=1, offset=CINEMATIC_462, x=[0x01], y=[0x1a], zoom=0x40
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_463, x=[0x01], y=[0x1a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_464, x=[0x01], y=[0x1a], zoom=0x40
	break
	play id=0x006C, freq=0x14, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_465, x=[0x01], y=[0x1a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_466, x=[0x01], y=[0x1a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_467, x=[0x01], y=[0x1a], zoom=0x40
	break
	video type=1, offset=CINEMATIC_468, x=[0x01], y=[0x1a], zoom=0x40
	break
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_469, x=[0x01], y=[0x1a], zoom=0x40
	break
	mov [PAUSE_SLICES], 0x0008
	killChannel
