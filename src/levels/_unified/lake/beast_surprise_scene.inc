BEAST_SURPRISE_SCENE_INIT:
	setup channel=0x2D, address=KILL_CHANNEL_ROUTINE
	unfreezeChannels first=0x00, last=0x2C
	unfreezeChannels first=0x2F, last=0x3B
	unfreezeChannels first=0x3D, last=0x3F
	selectVideoPage 0x00
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_BEAST_SURPRISE_SCENARIO_BACKGROUND, x=160, y=100
	selectVideoPage 0xFF
	mov [0x0A], 0x00A0
	mov [0x0B], 0x0000
	mov [0x09], 0x0032
	mov [0x08], 0x0004
	break
	setPalette 0x07

BEAST_INIT_TICK_PHASE_1:
	break
	add [0x09], 0x0001
	add [0x0B], 0x0014
	djnz [0x08], BEAST_INIT_TICK_PHASE_1
	mov [0x08], 0x0003

BEAST_INIT_TICK_PHASE_2:
	break
	add [0x09], 0x0001
	add [0x0B], 0x0007
	djnz [0x08], BEAST_INIT_TICK_PHASE_2
	break
	add [0x09], 0x0028
	break
	add [0x09], 0x002D
	break
	add [0x09], 0x0032
	break
	add [0x09], 0x003C
	setup channel=0x2D, address=BEAST_FLASH_LOOP
	fill page=0x00, color=0x00
	killChannel

BEAST_FLASH_LOOP:
	setPalette 0x0A
	break
	break
	fill page=0xFF, color=0x0F
	break
	fill page=0xFF, color=0x03
	break
	fill page=0xFF, color=0x08
	killChannel
	mov [0x06], 0x012C
	mov [0x07], 0x00B6
	break
	killChannel

