DELAY_LOOP_VARE6_AT_1E23:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E23
	song id=0x0BBF, delay=0x0000, pos=0x00
	mov [0xE7], 0x00AA
	setup channel=0x36, address=LABEL_1DD4
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1E3A:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E3A
	mov [0xE7], 0x0064
	setup channel=0x36, address=LABEL_1DD4
	mov [0xE6], 0x0002
	or [0xB1], 0x0020

DELAY_LOOP_VARE6_AT_1E4F:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E4F
	mov [0xE8], 0x0082
	setup channel=0x39, address=LABEL_1DF8
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1E60:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E60
	setup channel=0x38, address=LABEL_1EF4
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1DD4
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_1DF8
	break
	break
	mov [0xE7], 0x0096
	setup channel=0x39, address=LABEL_1DD4
	break
	break
	mov [0xE6], 0x0007

DELAY_LOOP_VARE6_AT_1E8E:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E8E
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1DD4
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1E9F:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1E9F
	mov [0xE8], 0x0064
	setup channel=0x39, address=LABEL_1DF8
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=LABEL_1DD4
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=LABEL_1DF8
	break
	break
	mov [0xE7], 0x0064
	setup channel=0x39, address=LABEL_1DD4
	break
	break
	break
	setup channel=0x36, address=LABEL_1FC4
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1ED6:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1ED6
	setup channel=0x38, address=LABEL_210D
	break
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	break
	break
	break
	break
	setup channel=0x3A, address=LABEL_2069
	break
	play id=0x0066, freq=0x04, vol=0x10, channel=0x02
	killChannel

LABEL_1EF4:
	video type=1, offset=CINEMATIC_278, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	break
	play id=0x0060, freq=0x14, vol=0x28, channel=0x00
	video type=1, offset=CINEMATIC_278, x=7, y=116
	video type=1, offset=CINEMATIC_280, x=7, y=116
	break
	video type=1, offset=CINEMATIC_278, x=43, y=120
	video type=1, offset=CINEMATIC_281, x=43, y=120
	break
	video type=1, offset=CINEMATIC_278, x=75, y=121
	video type=1, offset=CINEMATIC_282, x=75, y=121
	break
	video type=1, offset=CINEMATIC_278, x=119, y=116
	video type=1, offset=CINEMATIC_282, x=124, y=116
	break
	video type=1, offset=CINEMATIC_278, x=153, y=118
	video type=1, offset=CINEMATIC_281, x=153, y=118
	break
	video type=1, offset=CINEMATIC_278, x=190, y=120
	video type=1, offset=CINEMATIC_281, x=190, y=120
	break
	video type=1, offset=CINEMATIC_278, x=223, y=117
	video type=1, offset=CINEMATIC_280, x=223, y=117
	break
	video type=1, offset=CINEMATIC_278, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_280, x=301, y=114, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_281, x=331, y=114, zoom=0x40
	break
	killChannel
	video type=1, offset=CINEMATIC_278, x=65506, y=114, zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_246, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_249, x=180, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_252, x=200, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_255, x=220, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_259, x=240, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_261, x=260, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_243, x=280, y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=121, y=118
	break
	video type=1, offset=CINEMATIC_278, x=154, y=120
	break
	video type=1, offset=CINEMATIC_278, x=186, y=116
	break
	video type=1, offset=CINEMATIC_278, x=219, y=112
	break
	video type=1, offset=CINEMATIC_278, x=251, y=114
	break
	video type=1, offset=CINEMATIC_278, x=281, y=116, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=310, y=117, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=329, y=118, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=352, y=114, zoom=0x40
	killChannel

LABEL_1FC4:
	video type=1, offset=CINEMATIC_278, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_283, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x14, vol=0x32, channel=0x02
	video type=1, offset=CINEMATIC_278, x=7, y=116
	video type=1, offset=CINEMATIC_280, x=7, y=116
	video type=1, offset=CINEMATIC_283, x=7, y=116
	break
	video type=1, offset=CINEMATIC_278, x=43, y=120
	video type=1, offset=CINEMATIC_281, x=43, y=120
	video type=1, offset=CINEMATIC_283, x=43, y=120
	break
	video type=1, offset=CINEMATIC_278, x=75, y=121
	video type=1, offset=CINEMATIC_282, x=75, y=121
	video type=1, offset=CINEMATIC_283, x=75, y=121
	break
	video type=1, offset=CINEMATIC_278, x=119, y=116
	video type=1, offset=CINEMATIC_282, x=124, y=116
	video type=1, offset=CINEMATIC_283, x=119, y=116
	break
	video type=1, offset=CINEMATIC_278, x=153, y=118
	video type=1, offset=CINEMATIC_281, x=153, y=118
	video type=1, offset=CINEMATIC_283, x=153, y=118
	break
	video type=1, offset=CINEMATIC_278, x=190, y=120
	video type=1, offset=CINEMATIC_281, x=190, y=120
	video type=1, offset=CINEMATIC_283, x=190, y=120
	break
	video type=1, offset=CINEMATIC_278, x=223, y=117
	video type=1, offset=CINEMATIC_280, x=223, y=117
	video type=1, offset=CINEMATIC_283, x=223, y=117
	break
	video type=1, offset=CINEMATIC_278, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_283, x=266, y=112, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_280, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_283, x=301, y=114, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_281, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_283, x=331, y=114, zoom=0x40
	break
	killChannel

LABEL_2069:
	video type=1, offset=CINEMATIC_278, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_284, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x12, vol=0x32, channel=0x01
	video type=1, offset=CINEMATIC_278, x=7, y=116
	video type=1, offset=CINEMATIC_280, x=7, y=116
	video type=1, offset=CINEMATIC_284, x=7, y=116
	break
	video type=1, offset=CINEMATIC_278, x=43, y=120
	video type=1, offset=CINEMATIC_281, x=43, y=120
	video type=1, offset=CINEMATIC_284, x=43, y=120
	break
	video type=1, offset=CINEMATIC_278, x=75, y=121
	video type=1, offset=CINEMATIC_282, x=75, y=121
	video type=1, offset=CINEMATIC_284, x=75, y=121
	break
	video type=1, offset=CINEMATIC_278, x=119, y=116
	video type=1, offset=CINEMATIC_282, x=124, y=116
	video type=1, offset=CINEMATIC_284, x=119, y=116
	break
	video type=1, offset=CINEMATIC_278, x=153, y=118
	video type=1, offset=CINEMATIC_281, x=153, y=118
	video type=1, offset=CINEMATIC_284, x=153, y=118
	break
	video type=1, offset=CINEMATIC_278, x=190, y=120
	video type=1, offset=CINEMATIC_281, x=190, y=120
	video type=1, offset=CINEMATIC_284, x=190, y=120
	break
	video type=1, offset=CINEMATIC_278, x=223, y=117
	video type=1, offset=CINEMATIC_280, x=223, y=117
	video type=1, offset=CINEMATIC_284, x=223, y=117
	break
	video type=1, offset=CINEMATIC_278, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_284, x=266, y=112, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_280, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_284, x=301, y=114, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_281, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_284, x=331, y=114, zoom=0x40
	killChannel

LABEL_210D:
	video type=1, offset=CINEMATIC_278, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=65506, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_285, x=65506, y=114, zoom=0x40
	break
	play id=0x0055, freq=0x17, vol=0x28, channel=0x00
	video type=1, offset=CINEMATIC_278, x=7, y=116
	video type=1, offset=CINEMATIC_280, x=7, y=116
	video type=1, offset=CINEMATIC_285, x=7, y=116
	break
	video type=1, offset=CINEMATIC_278, x=43, y=120
	video type=1, offset=CINEMATIC_281, x=43, y=120
	video type=1, offset=CINEMATIC_285, x=43, y=120
	break
	video type=1, offset=CINEMATIC_278, x=75, y=121
	video type=1, offset=CINEMATIC_282, x=75, y=121
	video type=1, offset=CINEMATIC_285, x=75, y=121
	break
	video type=1, offset=CINEMATIC_278, x=119, y=116
	video type=1, offset=CINEMATIC_282, x=124, y=116
	video type=1, offset=CINEMATIC_285, x=119, y=116
	break
	video type=1, offset=CINEMATIC_278, x=153, y=118
	video type=1, offset=CINEMATIC_281, x=153, y=118
	video type=1, offset=CINEMATIC_285, x=153, y=118
	break
	video type=1, offset=CINEMATIC_278, x=190, y=120
	video type=1, offset=CINEMATIC_281, x=190, y=120
	video type=1, offset=CINEMATIC_285, x=190, y=120
	break
	video type=1, offset=CINEMATIC_278, x=223, y=117
	video type=1, offset=CINEMATIC_280, x=223, y=117
	video type=1, offset=CINEMATIC_285, x=223, y=117
	break
	video type=1, offset=CINEMATIC_278, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=266, y=112, zoom=0x40
	video type=1, offset=CINEMATIC_285, x=266, y=112, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_280, x=301, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_285, x=301, y=114, zoom=0x40
	break
	video type=1, offset=CINEMATIC_278, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_281, x=331, y=114, zoom=0x40
	video type=1, offset=CINEMATIC_285, x=331, y=114, zoom=0x40
	killChannel

LABEL_21B1:
	setPalette 0x11
	jl [0x01], 0xAE, LABEL_21C3
	jg [0x01], 0xE1, LABEL_21C3
	setPalette 0x09

LABEL_21C3:
	break
	jmp LABEL_21B1
LABEL_21C7:
	db 0x11

LABEL_21C8:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0xE8], [0x3D]
	add [0xE8], 0x008E
	mov [0xE7], 0x00A6
	video type=1, offset=CINEMATIC_322, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_323, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_324, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_325, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_326, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_327, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_328, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_329, x=[0xe8], y=[0xe7], zoom=0x40
	break
	video type=1, offset=CINEMATIC_330, x=[0xe8], y=[0xe7], zoom=0x40
	mov [0xE8], 0x000A

DELAY_LOOP_VARE8_AT_220F:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_220F
	jmp LABEL_21C8
	killChannel
	mov [0xE6], 0x0000
	mov [0xE7], 0x0000
	mov [0xE9], 0x0032
