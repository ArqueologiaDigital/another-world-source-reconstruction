KILL_IF_NOT_SCENE_4:
	killChannel

INIT_GETTING_OUT_OF_POOL_ANIMATION:
	mov [0x14], 0x00A0
	mov [0x15], 0x00A0
	mov [0x16], 0x0005

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_0:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_0, x=[0x14], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_1, x=[0x15], y=100, zoom=0x40
	sub [0x14], 0x0001
	add [0x15], 0x0001
	selectVideoPage 0xFF
	break
	break
	djnz [0x16], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_0
	mov [0x14], 0x00A0
	mov [0x15], 0x00A0
	mov [0x16], 0x0005

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_1:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_2, x=[0x14], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_3, x=[0x15], y=100, zoom=0x40
	sub [0x14], 0x0001
	add [0x15], 0x0001
	selectVideoPage 0xFF
	break
	break
	break
	djnz [0x16], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_1
	mov [0x14], 0x00A0
	mov [0x16], 0x0005

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_2:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_4, x=[0x14], y=100, zoom=0x40
	sub [0x14], 0x0001
	selectVideoPage 0xFF
	break
	break
	break
	break
	djnz [0x16], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_2
	killChannel

GETTING_OUT_POOL_PART_3_RPT:
	mov [0x17], 0x0002

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_3:
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_6, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_7, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_8, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_A_9, x=160, y=100
	break
	djnz [0x17], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_3
	killChannel

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_4:
	mov [0x33], 0x0078
;@if BRANCH == "gba_2004"
	song id=0x0FA2, delay=0x0000, pos=0x00
;@endif
	play id=0x004B, freq=0x0F, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_0, x=160, y=100
	play id=0x004B, freq=0x0F, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_B_6, x=160, y=100
	mov [0x18], 0x000A

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_5:
	break
	djnz [0x18], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_5
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_2, x=160, y=100
	break
	play id=0x0039, freq=0x0F, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_C_5, x=160, y=100
	play id=0x0039, freq=0x07, vol=0x20, channel=0x01
	break
	setup channel=0x16, address=HERO_AI_DISPATCH
	setup channel=0x0A, address=INIT_GETTING_OUT_OF_POOL_ANIMATION
	copyVideoPage src=0x00, dst=0x03
	mov [0x18], 0x000F
	mov [PAUSE_SLICES], 0x0004

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_6:
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_0, x=160, y=100
	break
	djnz [0x18], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_6
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_1, x=160, y=100
	setup channel=0x17, address=GETTING_OUT_POOL_PART_3_RPT
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_6, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_7, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_8, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_9, x=160, y=100
	break
	play id=0x004B, freq=0x14, vol=0x14, channel=0x01
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_10, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_11, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_12, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_13, x=160, y=100
	mov [0x18], 0x0014

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_7:
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_14, x=160, y=100
	djnz [0x18], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_7
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_15, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_15, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_16, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_16, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_17, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_17, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_18, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_18, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_19, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_19, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_20, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_20, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_21, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_D_21, x=160, y=100
	mov [0x18], 0x0014

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_8:
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_0, x=160, y=100
	djnz [0x18], GETTING_OUT_OF_THE_POOL__ANIMATION_PART_8
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_3, x=160, y=100
	play id=0x0051, freq=0x14, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_5, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_6, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_6, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_7, x=160, y=100
	play id=0x0051, freq=0x16, vol=0x1D, channel=0x01
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_7, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_8, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_8, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_9, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_9, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_10, x=160, y=100
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_E_10, x=160, y=100
	break
	play id=0x0051, freq=0x14, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_0, x=199, y=182
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_0, x=199, y=182
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_1, x=199, y=182
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_1, x=199, y=182

GETTING_OUT_OF_THE_POOL__ANIMATION_PART_9:
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_1, x=199, y=182
	jmp GETTING_OUT_OF_THE_POOL__ANIMATION_PART_9
	killChannel

