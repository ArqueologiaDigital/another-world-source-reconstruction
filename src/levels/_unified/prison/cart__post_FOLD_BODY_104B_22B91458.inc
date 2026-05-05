LABEL_4B6C:
	video offset=CINEMATIC_693, x=134, y=[0xf8]
	add [0xF8], 0x0010
	djnz [0x21], LABEL_4B6C
	killChannel

DRAW_CIN_SEQ_085_085_086:
	video offset=CINEMATIC_085, x=132, y=39
	video offset=CINEMATIC_085, x=297, y=39
	video offset=CINEMATIC_086, x=132, y=39
	video offset=CINEMATIC_086, x=297, y=39
	ret
LABEL_4B8D:
	db 0x11

LABEL_4B8E:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_306, x=160, y=100
	video offset=CINEMATIC_307, x=160, y=100
	video offset=CINEMATIC_308, x=160, y=100
	video offset=CINEMATIC_309, x=160, y=100
	ret

LABEL_4BA6:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_328, x=160, y=100
	video offset=CINEMATIC_329, x=160, y=100
	video offset=CINEMATIC_330, x=160, y=100
	video offset=CINEMATIC_331, x=160, y=100
	video offset=CINEMATIC_332, x=160, y=100
	video offset=CINEMATIC_333, x=160, y=100
	ret

LABEL_4BC6:
	mov [0x65], 0x0000
	call LABEL_82D1
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_428, x=160, y=100
	video offset=CINEMATIC_429, x=160, y=100
	video offset=CINEMATIC_430, x=160, y=100
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_431, x=160, y=100
	video offset=CINEMATIC_432, x=160, y=100
	video offset=CINEMATIC_433, x=160, y=100
	ret

LABEL_4BEF:
	call LABEL_82D1
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_448, x=160, y=100
	video offset=CINEMATIC_449, x=160, y=100
	video offset=CINEMATIC_450, x=160, y=100
	video offset=CINEMATIC_451, x=160, y=100
	ret

LABEL_4C08:
	mov [0x65], 0x0000
	call LABEL_82D1
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_435, x=160, y=100
	video offset=CINEMATIC_436, x=160, y=100
	video offset=CINEMATIC_437, x=160, y=100
	ret

LABEL_4C25:
	call LABEL_82D1
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_458, x=160, y=100
	ret

FILL_AND_DRAW_CIN_24_28:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_024, x=160, y=100
	video offset=CINEMATIC_025, x=160, y=100
	video offset=CINEMATIC_026, x=160, y=100
	video offset=CINEMATIC_027, x=160, y=100
	video offset=CINEMATIC_028, x=160, y=100
	video offset=CINEMATIC_029, x=160, y=400
	video offset=CINEMATIC_030, x=160, y=100
	video offset=CINEMATIC_031, x=160, y=100
	video offset=CINEMATIC_032, x=160, y=100
	video offset=CINEMATIC_033, x=160, y=100
	video offset=CINEMATIC_034, x=160, y=100
	ret

LABEL_4C64:
	song id=0x0BBD, delay=0x0000, pos=0x00
	video offset=CINEMATIC_596, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_597, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_598, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_599, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_600, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_601, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_602, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_603, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_604, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_605, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_606, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_607, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_608, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_609, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_610, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x22, address=LABEL_4DCF
	break
	video offset=CINEMATIC_611, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_612, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_613, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_614, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x22, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_342, x=[BUDDY_X], y=[BUDDY_Y]
	break
	setup channel=0x08, address=LABEL_4D9C
	video offset=CINEMATIC_615, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_617, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_619, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_621, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_623, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x21, address=LABEL_14B0
	setup channel=0x22, address=LABEL_1C5E
	setup channel=0x24, address=LABEL_14D3
	mov [HACK_VAR_67], 0x0001
	mov [0x68], 0x0118
	mov [0x69], 0x00B6
	mov [0x6A], 0x0001
	mov [0x6B], 0x2000
	mov [0x6D], 0x0011
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x08, address=LABEL_4D83
	killChannel

LABEL_4D83:
	video offset=CINEMATIC_624, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_628, x=160, y=100
	killChannel

LABEL_4D9C:
	video offset=CINEMATIC_628, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break

HANG_DRAW_CIN_624:
	video offset=CINEMATIC_624, x=160, y=100
	break
	jmp HANG_DRAW_CIN_624
LABEL_4DB8:
	db 0x11

LABEL_4DB9:
	mov [BUDDY_X], 0x0118
	mov [BUDDY_Y], 0x00B6
	mov [PAUSE_SLICES], 0x0007
	video offset=CINEMATIC_633, x=[BUDDY_X], y=[BUDDY_Y]
	break
	jmp LABEL_4DB9
LABEL_4DCE:
	db 0x11

LABEL_4DCF:
	video offset=CINEMATIC_229, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_632, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_4DD9:
	break
	video offset=CINEMATIC_237, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_632, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_4DD9
LABEL_4DE7:
	db 0x11

LABEL_4DE8:
	setPalette 0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x04
	video offset=CINEMATIC_683, x=160, y=100
	video offset=CINEMATIC_684, x=160, y=100
	video offset=CINEMATIC_685, x=160, y=100
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0xFF
	mov [0x1A], 0x00A0
	mov [0x1B], 0x0064
	mov [0x15], 0x0000
	mov [0x14], 0x0007

DELAY_LOOP_VAR14:
	break
	djnz [0x14], DELAY_LOOP_VAR14
	mov [0x14], 0x0005

LABEL_4E1A:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4E1A
	break
	mov [0x14], 0x000A

LABEL_4E28:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4E28
	mov [0x14], 0x0008

DELAY_LOOP_VAR14_AT_4E35:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4E35
	mov [0x14], 0x0004

LABEL_4E3E:
	break
	add [0x15], 0x0004
	djnz [0x14], LABEL_4E3E
	mov [0x14], 0x0004

LABEL_4E4B:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4E4B
	mov [0x14], 0x000E

LABEL_4E58:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4E58
	break
	sub [0x15], 0x0002
	break
	sub [0x15], 0x0008
	break
	add [0x16], 0x0001
	break
	add [0x15], 0x0014
	break
	sub [0x16], 0x0001
	mov [0x14], 0x0004
	add [0x15], 0x0002

LABEL_4E82:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4E82
	mov [0x14], 0x0006

DELAY_LOOP_VAR14_AT_4E8F:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4E8F
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	deleteChannels first=0x01, last=0x03
	setup channel=0x01, address=SET_PAL_07_FILL_TWO_PAGES_86243111
	setup channel=0x02, address=LABEL_50CC
	killChannel
