DELAY_LOOP_VARE6_AT_1E5E:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E5E
	mov [0xE7], 0x00AA
	setup channel=0x36, address=LABEL_1E0F
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1E6F:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E6F
	mov [0xE7], 0x0064
	setup channel=0x36, address=LABEL_1E0F
	mov [0xE6], 0x0002
	or [0xB1], 0x0020

DELAY_LOOP_VARE6_AT_1E84:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E84
	mov [0xE8], 0x0082
	setup channel=0x39, address=LABEL_1E33
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1E95:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E95
	setup channel=0x38, address=LABEL_1F2D
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1E0F
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_1E33
	break
	break
	mov [0xE7], 0x0096
	setup channel=0x39, address=LABEL_1E0F
	break
	break
	mov [0xE6], 0x0007

DELAY_LOOP_VARE6_AT_1EC3:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1EC3
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1E0F
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1ED4:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1ED4
	mov [0xE8], 0x0064
	setup channel=0x39, address=LABEL_1E33
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1E0F
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_1E33
	break
	break
	mov [0xE7], 0x0064
	setup channel=0x39, address=LABEL_1E0F
	break
	break
	break
	setup channel=0x36, address=LABEL_1FFD
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1F0B:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1F0B
	setup channel=0x38, address=LABEL_2146
	break
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	break
	break
	break
	break
	setup channel=0x3A, address=LABEL_20A2
	break
	play id=0x0066, freq=0x04, vol=0x10, channel=0x02
	mov [0x74], 0x4018
	killChannel

LABEL_1F2D:
	video offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_280, x=65506, y=114, zoom=0x40
	break
	play id=0x0060, freq=0x14, vol=0x28, channel=0x00
	video offset=CINEMATIC_279, x=7, y=116
	video offset=CINEMATIC_281, x=7, y=116
	break
	video offset=CINEMATIC_279, x=43, y=120
	video offset=CINEMATIC_282, x=43, y=120
	break
	video offset=CINEMATIC_279, x=75, y=121
	video offset=CINEMATIC_283, x=75, y=121
	break
	video offset=CINEMATIC_279, x=119, y=116
	video offset=CINEMATIC_283, x=124, y=116
	break
	video offset=CINEMATIC_279, x=153, y=118
	video offset=CINEMATIC_282, x=153, y=118
	break
	video offset=CINEMATIC_279, x=190, y=120
	video offset=CINEMATIC_282, x=190, y=120
	break
	video offset=CINEMATIC_279, x=223, y=117
	video offset=CINEMATIC_281, x=223, y=117
	break
	video offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_280, x=266, y=112, zoom=0x40
	break
	video offset=CINEMATIC_279, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_281, x=301, y=114, zoom=0x40
	break
	video offset=CINEMATIC_279, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_282, x=331, y=114, zoom=0x40
	break
	killChannel
	video offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_246, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_249, x=180, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_252, x=200, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_255, x=220, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_259, x=240, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_261, x=260, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_243, x=280, y=100, zoom=0x40
	break
	video offset=CINEMATIC_279, x=121, y=118
	break
	video offset=CINEMATIC_279, x=154, y=120
	break
	video offset=CINEMATIC_279, x=186, y=116
	break
	video offset=CINEMATIC_279, x=219, y=112
	break
	video offset=CINEMATIC_279, x=251, y=114
	break
	video offset=CINEMATIC_279, x=281, y=116, zoom=0x40
	break
	video offset=CINEMATIC_279, x=310, y=117, zoom=0x40
	break
	video offset=CINEMATIC_279, x=329, y=118, zoom=0x40
	break
	video offset=CINEMATIC_279, x=352, y=114, zoom=0x40
	killChannel

LABEL_1FFD:
	video offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_280, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_284, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x14, vol=0x32, channel=0x02
	video offset=CINEMATIC_279, x=7, y=116
	video offset=CINEMATIC_281, x=7, y=116
	video offset=CINEMATIC_284, x=7, y=116
	break
	video offset=CINEMATIC_279, x=43, y=120
	video offset=CINEMATIC_282, x=43, y=120
	video offset=CINEMATIC_284, x=43, y=120
	break
	video offset=CINEMATIC_279, x=75, y=121
	video offset=CINEMATIC_283, x=75, y=121
	video offset=CINEMATIC_284, x=75, y=121
	break
	video offset=CINEMATIC_279, x=119, y=116
	video offset=CINEMATIC_283, x=124, y=116
	video offset=CINEMATIC_284, x=119, y=116
	break
	video offset=CINEMATIC_279, x=153, y=118
	video offset=CINEMATIC_282, x=153, y=118
	video offset=CINEMATIC_284, x=153, y=118
	break
	video offset=CINEMATIC_279, x=190, y=120
	video offset=CINEMATIC_282, x=190, y=120
	video offset=CINEMATIC_284, x=190, y=120
	break
	video offset=CINEMATIC_279, x=223, y=117
	video offset=CINEMATIC_281, x=223, y=117
	video offset=CINEMATIC_284, x=223, y=117
	break
	video offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_280, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_284, x=266, y=112, zoom=0x40
	break
	video offset=CINEMATIC_279, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_281, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_284, x=301, y=114, zoom=0x40
	break
	video offset=CINEMATIC_279, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_282, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_284, x=331, y=114, zoom=0x40
	break
	killChannel

LABEL_20A2:
	video offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_280, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_285, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x12, vol=0x32, channel=0x01
	video offset=CINEMATIC_279, x=7, y=116
	video offset=CINEMATIC_281, x=7, y=116
	video offset=CINEMATIC_285, x=7, y=116
	break
	video offset=CINEMATIC_279, x=43, y=120
	video offset=CINEMATIC_282, x=43, y=120
	video offset=CINEMATIC_285, x=43, y=120
	break
	video offset=CINEMATIC_279, x=75, y=121
	video offset=CINEMATIC_283, x=75, y=121
	video offset=CINEMATIC_285, x=75, y=121
	break
	video offset=CINEMATIC_279, x=119, y=116
	video offset=CINEMATIC_283, x=124, y=116
	video offset=CINEMATIC_285, x=119, y=116
	break
	video offset=CINEMATIC_279, x=153, y=118
	video offset=CINEMATIC_282, x=153, y=118
	video offset=CINEMATIC_285, x=153, y=118
	break
	video offset=CINEMATIC_279, x=190, y=120
	video offset=CINEMATIC_282, x=190, y=120
	video offset=CINEMATIC_285, x=190, y=120
	break
	video offset=CINEMATIC_279, x=223, y=117
	video offset=CINEMATIC_281, x=223, y=117
	video offset=CINEMATIC_285, x=223, y=117
	break
	video offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_280, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_285, x=266, y=112, zoom=0x40
	break
	video offset=CINEMATIC_279, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_281, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_285, x=301, y=114, zoom=0x40
	break
	video offset=CINEMATIC_279, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_282, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_285, x=331, y=114, zoom=0x40
	killChannel

LABEL_2146:
	video offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_280, x=65506, y=114, zoom=0x40
	video offset=CINEMATIC_286, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x17, vol=0x28, channel=0x00
	video offset=CINEMATIC_279, x=7, y=116
	video offset=CINEMATIC_281, x=7, y=116
	video offset=CINEMATIC_286, x=7, y=116
	break
	video offset=CINEMATIC_279, x=43, y=120
	video offset=CINEMATIC_282, x=43, y=120
	video offset=CINEMATIC_286, x=43, y=120
	break
	video offset=CINEMATIC_279, x=75, y=121
	video offset=CINEMATIC_283, x=75, y=121
	video offset=CINEMATIC_286, x=75, y=121
	break
	video offset=CINEMATIC_279, x=119, y=116
	video offset=CINEMATIC_283, x=124, y=116
	video offset=CINEMATIC_286, x=119, y=116
	break
	video offset=CINEMATIC_279, x=153, y=118
	video offset=CINEMATIC_282, x=153, y=118
	video offset=CINEMATIC_286, x=153, y=118
	break
	video offset=CINEMATIC_279, x=190, y=120
	video offset=CINEMATIC_282, x=190, y=120
	video offset=CINEMATIC_286, x=190, y=120
	break
	video offset=CINEMATIC_279, x=223, y=117
	video offset=CINEMATIC_281, x=223, y=117
	video offset=CINEMATIC_286, x=223, y=117
	break
	video offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_280, x=266, y=112, zoom=0x40
	video offset=CINEMATIC_286, x=266, y=112, zoom=0x40
	break
	video offset=CINEMATIC_279, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_281, x=301, y=114, zoom=0x40
	video offset=CINEMATIC_286, x=301, y=114, zoom=0x40
	break
	video offset=CINEMATIC_279, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_282, x=331, y=114, zoom=0x40
	video offset=CINEMATIC_286, x=331, y=114, zoom=0x40
	killChannel

LABEL_21EA:
	setPalette 0x11
	jl [0x01], 0xAE, LABEL_21FC
	jg [0x01], 0xE1, LABEL_21FC
	setPalette 0x09

LABEL_21FC:
	break
	jmp LABEL_21EA
LABEL_2200:
	db 0x11

LABEL_2201:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0xE8], [0x3D]
	add [0xE8], 0x008E
	mov [0xE7], 0x00A6
	video offset=CINEMATIC_322, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_323, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_324, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_325, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_326, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_327, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_328, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_329, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_330, x=[0xe8], y=[0xe7], zoom=0x40
	mov [0xE8], 0x000A

DELAY_LOOP_VARE8_AT_2248:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_2248
	jmp LABEL_2201
	killChannel
	mov [0xE6], 0x0000
	mov [0xE7], 0x0000
	mov [0xE9], 0x0032
