LABEL_032E:
	break
	jne [HERO_ACTION], 0x00, LABEL_032E

LABEL_0335:
	break
	jne [HERO_ACTION], 0x00, LABEL_0340
	djnz [0x03], LABEL_0335

LABEL_0340:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_0349
	killChannel

LABEL_0349:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=LABEL_21C5
	play id=0x005E, freq=0x00, vol=0x00, channel=0x00
	play id=0x005E, freq=0x00, vol=0x00, channel=0x01
	play id=0x005E, freq=0x00, vol=0x00, channel=0x02
	play id=0x005E, freq=0x00, vol=0x00, channel=0x03
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D

LABEL_0376:
	text id=0x013D, x=5, y=80, color=0x0C ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0E ; "        ACCESS CODE:"
	text id=0x016B, x=26, y=180, color=0x0D ; "LFCK"
	break
	je [HERO_ACTION], 0x00, LABEL_0376
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_0398:
	text id=0x0135, x=20, y=100, color=0x0B ; "9"
	break
	text id=0x0134, x=20, y=100, color=0x0B ; "8"
	break
	text id=0x0133, x=20, y=100, color=0x0B ; "7"
	break
	text id=0x0132, x=20, y=100, color=0x0B ; "6"
	break
	text id=0x0131, x=20, y=100, color=0x0B ; "5"
	break
	text id=0x0130, x=20, y=100, color=0x0B ; "4"
	break
	text id=0x012F, x=20, y=100, color=0x0B ; "3"
	break
	text id=0x012E, x=20, y=100, color=0x0B ; "2"
	break
	text id=0x012D, x=20, y=100, color=0x0B ; "1"
	break
	text id=0x012C, x=20, y=100, color=0x0B ; "0"
	break
	jmp LABEL_0398
LABEL_03E1:
	db 0x00, 0x01, 0x03, 0xE8, 0x81, 0x00, 0xA0, 0x64
	db 0x09, 0x01, 0x03, 0xE5, 0x06, 0x0B, 0x0C, 0xFF

KILL_CHANNEL_LANDING:
	killChannel

KILL_CHAN_AT_03F2:
	killChannel

LABEL_03F3:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_03F3
LABEL_03FF:
	db 0x11, 0x0A, 0x02, 0xEF, 0x00, 0x04, 0x0A, 0xEE
	db 0x5B, 0xA0, 0x64, 0x0A, 0x02, 0xEF, 0x01, 0x04
	db 0x14, 0xEE, 0x5F, 0xA0, 0x64, 0x0A, 0x02, 0xEF
	db 0x02, 0x04, 0x1E, 0xEE, 0x63, 0xA0, 0x64, 0x0A
	db 0x02, 0xEF, 0x03, 0x04, 0x28, 0xEE, 0x67, 0xA0
	db 0x64, 0x0A, 0x02, 0xEF, 0x04, 0x04, 0x32, 0xEE
	db 0x6B, 0xA0, 0x64, 0x0A, 0x02, 0xEF, 0x05, 0x04
	db 0x3C, 0xEE, 0x6F, 0xA0, 0x64, 0x0A, 0x02, 0xEF
	db 0x06, 0x04, 0x46, 0xEE, 0x73, 0xA0, 0x64, 0x0A
	db 0x02, 0xEF, 0x07, 0x04, 0x50, 0xEE, 0x77, 0xA0
	db 0x64, 0x0A, 0x02, 0xEF, 0x08, 0x04, 0x5A, 0xEE
	db 0x7B, 0xA0, 0x64, 0x0A, 0x02, 0xEF, 0x09, 0x04
	db 0x64, 0xEE, 0x7F, 0xA0, 0x64, 0x0A, 0x02, 0xEF
	db 0x0A, 0x04, 0x6E, 0xEE, 0x83, 0xA0, 0x64, 0x0A
	db 0x02, 0xEF, 0x0B, 0x04, 0x78, 0xEE, 0x87, 0xA0
	db 0x64, 0x0A, 0x02, 0xEF, 0x0C, 0x04, 0x82, 0xEE
	db 0x8B, 0xA0, 0x64, 0x0A, 0x02, 0xEF, 0x0D, 0x04
	db 0x8C, 0xEE, 0x8F, 0xA0, 0x64, 0x0A, 0x02, 0xEF
	db 0x0E, 0x04, 0x96, 0xEE, 0x93, 0xA0, 0x64, 0x0A
	db 0x02, 0xEF, 0x0F, 0x04, 0xA0, 0xEE, 0x97, 0xA0
	db 0x64, 0x0A, 0x02, 0xEF, 0x10, 0x60, 0x4A, 0xEE
	db 0x97, 0xA0, 0x64, 0x05

LABEL_04AB:
	video offset=CINEMATIC_370, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION], 0x01, LABEL_0518
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_0826
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_04AB
	add [0x01], 0x0002
	video offset=CINEMATIC_385, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_384, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_383, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0xE6], 0x0006

ANIM_CIN_382_LOOP_VARE6_AT_04E6:
	video offset=CINEMATIC_382, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0xE6], ANIM_CIN_382_LOOP_VARE6_AT_04E6
	add [0x01], 0x0000
	video offset=CINEMATIC_381, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_380, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0000
	video offset=CINEMATIC_379, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_370, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_04AB
LABEL_0517:
	db 0x11

LABEL_0518:
	video offset=CINEMATIC_371, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_369, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_368, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_367, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_366, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_372, x=[0x01], y=[0x02], zoom=0x40
	break
	jl [0x01], 0x0107, LABEL_080B
	jg [0xB7], 0x01, LABEL_080B
	je [0xB7], 0x01, LABEL_058A
	mov [0xB7], 0x0001
	mov [0x01], 0x010A
	selectVideoPage 0x00
	video offset=CINEMATIC_373, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_374, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_397, x=160, y=100
	video offset=CINEMATIC_376, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_398, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_378, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_367, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x01, address=LABEL_05C5
	break
	jmp LABEL_0826

LABEL_058A:
	mov [0x01], 0x010C
	mov [0xB7], 0x0002
	selectVideoPage 0x00
	video offset=CINEMATIC_373, x=163, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_374, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_375, x=160, y=100
	video offset=CINEMATIC_376, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_377, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_378, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_367, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x01, address=LABEL_0636
	break
	jmp LABEL_0826

LABEL_05C5:
	setPalette 0x0E
	setup channel=0x3C, address=LABEL_22A4
	play id=0x005D, freq=0x14, vol=0x40, channel=0x02
	play id=0x005D, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0057, freq=0x0A, vol=0x40, channel=0x03
	jl [0x70], 0x78, LABEL_05F4
	jg [0x70], 0xB4, LABEL_05F4
	mov [0x1D], 0x0029
	call LABEL_4835
	jmp LABEL_0600

LABEL_05F4:
	video offset=CINEMATIC_399, x=160, y=100
	break
	video offset=CINEMATIC_399, x=160, y=100
	break
	break
	killChannel

LABEL_0600:
	video offset=CINEMATIC_399, x=160, y=100
	break
	video offset=CINEMATIC_399, x=160, y=100
	break
	break
	or [0x73], 0x4000
	killChannel
	video offset=CINEMATIC_400, x=160, y=100
	break
	video offset=CINEMATIC_401, x=160, y=100
	break
	video offset=CINEMATIC_402, x=160, y=100
	break
	video offset=CINEMATIC_403, x=160, y=100
	break
	video offset=CINEMATIC_404, x=160, y=100
	break
	video offset=CINEMATIC_405, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_406, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_0636:
	selectVideoPage 0x00
	setPalette 0x0C
	video offset=CINEMATIC_386, x=160, y=100
	selectVideoPage 0xFF
	play id=0x0066, freq=0x07, vol=0x20, channel=0x02
	play id=0x0066, freq=0x05, vol=0x20, channel=0x03
	video offset=CINEMATIC_387, x=160, y=100
	break
	video offset=CINEMATIC_387, x=160, y=98
	break
	video offset=CINEMATIC_387, x=160, y=96
	break
	video offset=CINEMATIC_387, x=160, y=94
	break
	video offset=CINEMATIC_388, x=160, y=100
	break
	video offset=CINEMATIC_389, x=160, y=100
	break
	video offset=CINEMATIC_390, x=160, y=100
	break
	video offset=CINEMATIC_391, x=160, y=100
	break
	video offset=CINEMATIC_392, x=160, y=100
	break
	video offset=CINEMATIC_393, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_393, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x04, address=LABEL_068B
	killChannel

LABEL_068B:
	jl [0x01], 0x78, LABEL_06B2
	jg [0x01], 0xB4, LABEL_06B2
	jg [0x01], 0xA5, LABEL_06A4
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_06B2

LABEL_06A4:
	jge [0x04], 0x4000, LABEL_06B2
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	jmp LABEL_06B6

LABEL_06B2:
	break
	jmp LABEL_068B

LABEL_06B6:
	deleteChannels first=0x14, last=0x16
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x00
	play id=0x0057, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_394, x=162, y=100
	break
	video offset=CINEMATIC_395, x=162, y=100
	break
	video offset=CINEMATIC_396, x=162, y=100
	break
	bankSwitch 7;  Game Ending Sequence
	killChannel

LABEL_06DA:
	mov [0xE8], 0x00B4
	mov [0xE9], 0x0064
	video offset=CINEMATIC_356, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_356, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_356, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_356, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_357, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_357, x=[0xe8], y=[0xe9], zoom=0x40
	break
	setup channel=0x07, address=INLINE_SET_VAREC_TO_AF

LABEL_070A:
	video offset=CINEMATIC_358, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_358, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_359, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_359, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_360, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_360, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_361, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_361, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_362, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_362, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_363, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_363, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_364, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_364, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_365, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video offset=CINEMATIC_365, x=[0xe8], y=[0xe9], zoom=0x40
	break
	add [0xE8], 0x000D
	jmp LABEL_070A

LABEL_0771:
	video offset=CINEMATIC_407, x=[0xea], y=157, zoom=0x40
	play id=0x0052, freq=0x1C, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_408, x=[0xea], y=157, zoom=0x40
	break
	video offset=CINEMATIC_409, x=[0xea], y=157, zoom=0x40
	break
	video offset=CINEMATIC_410, x=[0xea], y=157, zoom=0x40
	killChannel

LABEL_078F:
	video offset=CINEMATIC_407, x=[0xeb], y=157, zoom=0x40
	play id=0x0052, freq=0x18, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_408, x=[0xeb], y=157, zoom=0x40
	break
	video offset=CINEMATIC_409, x=[0xeb], y=157, zoom=0x40
	break
	video offset=CINEMATIC_410, x=[0xeb], y=157, zoom=0x40
	killChannel
