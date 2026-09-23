ANIM_CIN_373_LOOP_VARE8:
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F0, x=137, y=100
	break
	djnz [0xE8], ANIM_CIN_373_LOOP_VARE8
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F1, x=137, y=100
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F2, x=137, y=100
	break
	mov [0xE8], 0x0014
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=100
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=102
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=106
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=108
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=112
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=116
	break
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=137, y=120
	killChannel

LABEL_2467:
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F2, x=66, y=91
	video offset=CINEMATIC_CAPSULE_ROBED_FIGURE_F3, x=95, y=97
	video offset=CINEMATIC_CAPSULE_LIT_PANEL, x=160, y=100
	break
	jmp LABEL_2467
LABEL_2477:
	db 0x11

LABEL_2478:
	mov [0x29], 0x03E8
	mov [0x2F], 0x0019
	setup channel=0x05, address=LABEL_2488
	jmp DISPATCH_VAR2F_STATE
LABEL_2487:
	db 0x11

LABEL_2488:
	add [0x68], 0x0001
	break
	jmp LABEL_2488

LABEL_2490:
	mov [0x2F], 0x0000
	jne [0x10], 0x6B, SHARED_RET
	mov [0x2F], 0x0023
	setup channel=0x38, address=LABEL_3D94
	ret


LABEL_24A3:
	mov [0x2F], 0x0019
	mov [0x29], 0x0320
	jne [0x10], 0x6D, SHARED_RET
	mov [0x2F], 0x001E
	ret


LABEL_24B6:
	mov [0x2F], 0x001F
	jg [BUDDY_X], 0x78, SHARED_RET
	mov [0x2F], 0x0019
	mov [0x29], 0x0096
	ret


LABEL_24C9:
	mov [0x2F], 0x0020
	je [0x10], 0x6F, LABEL_24E2
	jg [0x10], [SCREEN_NUM], LABEL_24E2
	mov [0x2F], 0x0019
	mov [0x29], 0x01C2
	ret


LABEL_24E2:
	mov [0x2F], 0x0012
	jg [BUDDY_X], 0xA0, SHARED_RET
	mov [0x2F], 0x0019
	mov [0x29], 0x00BA
	ret


LABEL_24F5:
	mov [0x2F], 0x0020
	jne [0x10], 0x8E, LABEL_24C9
	ret


; The full Buddy-smashing-window animation routine. Sets up
; position (0x68, 0x69), waits for Lester to be off-screen
; left (jl [HERO_X], 0x28), sets bit 0x40 in [0xB9] (some
; narrative-progress flag), then plays the smash animation
; via CINEMATIC_461 + BUDDY_SMASHING_WINDOW_F0..F15 with two
; hit sound effects (id=0x0075 and 0x006B).
BUDDY_SMASHING_WINDOW_ANIMATION:
	mov [0x68], 0x0090
	mov [0x69], 0x0062
	break
	jl [HERO_X], 0x28, BUDDY_SMASHING_WINDOW_ANIMATION
	or [0xB9], 0x0040
	selectVideoPage 0x00
	video offset=CINEMATIC_461, x=[0x68], y=[0x69]
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F0, x=[0x68], y=[0x69]
	play id=0x0075, freq=0x0F, vol=0x40, channel=0x00
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x02
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F1, x=[0x68], y=[0x69]
	break
	play id=0x006B, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F2, x=[0x68], y=[0x69]
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F3, x=[0x68], y=[0x69]
	selectVideoPage 0x00
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F4, x=[0x68], y=[0x69]
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F5, x=[0x68], y=[0x69]
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F6, x=[0x68], y=[0x69]
	selectVideoPage 0x00
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F7, x=[0x68], y=[0x69]
	selectVideoPage 0xFF
	play id=0x006B, freq=0x14, vol=0x20, channel=0x02
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F8, x=[0x68], y=[0x69]
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F9, x=[0x68], y=[0x69]
	selectVideoPage 0x00
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F10, x=[0x68], y=[0x69]
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F11, x=[0x68], y=[0x69]
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F12, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F11, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F13, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F14, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F15, x=[0x68], y=[0x69]
	setup channel=0x01, address=CAPSULE_RANDOM_OFFSET_VAR21_FOR_SCENE_4B
	call LABEL_340A
	killChannel

LABEL_25A7:
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F0, x=160, y=100
	play id=0x006B, freq=0x0A, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_F0, x=160, y=100
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x02
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_F1, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_F2, x=160, y=100
	play id=0x006B, freq=0x0A, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_F3, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F1, x=160, y=100
	play id=0x0055, freq=0x10, vol=0x20, channel=0x03
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F2, x=160, y=100
	play id=0x006B, freq=0x14, vol=0x40, channel=0x02
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F1, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F3, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F4, x=160, y=100
	break
	play id=0x006C, freq=0x14, vol=0x18, channel=0x02
	video offset=CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F3, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DEBRIS_RAIN_F5, x=160, y=100
	break
	video offset=CINEMATIC_419, x=144, y=127
	video offset=CINEMATIC_420, x=160, y=100
	break
	play id=0x006C, freq=0x18, vol=0x18, channel=0x02
	video offset=CINEMATIC_419, x=143, y=127
	video offset=CINEMATIC_421, x=160, y=100
	break
	video offset=CINEMATIC_419, x=142, y=127
	play id=0x006C, freq=0x12, vol=0x18, channel=0x01
	video offset=CINEMATIC_CAPSULE_ARCH_WALL_FAR, x=160, y=100
	break
	video offset=CINEMATIC_419, x=142, y=127
	play id=0x006C, freq=0x10, vol=0x18, channel=0x02
	video offset=CINEMATIC_CAPSULE_ARCH_WALL_NEAR, x=160, y=100
	mov [0xF0], 0x000A

LABEL_2645:
	break
	video offset=CINEMATIC_419, x=141, y=127
	djnz [0xF0], LABEL_2645
	break
	play id=0x0057, freq=0x10, vol=0x18, channel=0x02
	video offset=CINEMATIC_CAPSULE_SCREEN_4D_BACKDROP_LAYER_3, x=141, y=127
	break
	video offset=CINEMATIC_CAPSULE_SCREEN_4D_BACKDROP_LAYER_4, x=141, y=127
	break
	video offset=CINEMATIC_426, x=141, y=127
	break
	video offset=CINEMATIC_427, x=141, y=127
	setup channel=0x0F, address=HANG_DRAW_CIN_429
	setup channel=0x1D, address=HANG_DRAW_CIN_430
	selectVideoPage 0x00
	video offset=CINEMATIC_428, x=141, y=127
	selectVideoPage 0xFF
	call INIT_BIRD_AI_VARS
	mov [PAUSE_SLICES], 0x0004
	setup channel=0x14, address=LABEL_C29D
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=LABEL_B666
	killChannel

HANG_DRAW_CIN_429:
	video offset=CINEMATIC_429, x=141, y=127
	break
	jmp HANG_DRAW_CIN_429

HANG_DRAW_CIN_430:
	video offset=CINEMATIC_CAPSULE_SCREEN_91_BACKDROP_LAYER_1, x=141, y=127
	break
	jmp HANG_DRAW_CIN_430
	killChannel

LABEL_269D:
	break
	jl [HERO_X], 0xB4, LABEL_269D
	or [0x74], 0x4000
	setPalette 0x09
	killChannel

LABEL_26AC:
	setup channel=0x22, address=CAPSULE_ACTOR_CONTEXT_LOAD_SLOT0_LOOP
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	setup channel=0x24, address=CAPSULE_ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	setup channel=0x26, address=CAPSULE_ACTOR_CONTEXT_ROTATE_INTO_SLOT2_LOOP
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=CAPSULE_ACTOR_CONTEXT_COMMIT_SLOT2_LOOP
	ret


LABEL_26C9:
	je [SCREEN_NUM], 0xEC, LABEL_26D0
	ret


LABEL_26D0:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, LABEL_26E0
	call LABEL_3490

LABEL_26E0:
	mov [0xF8], [0xB4]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_26FC
	mov [0xA9], 0x00B9
	mov [0xAA], 0x03E8
	mov [0xAB], 0x00EC
	call LABEL_34B1

LABEL_26FC:
	ret


LABEL_26FD:
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CV_304_305
	break
	mov [0x0E], 0x0004
	call CAPSULE_BUDDY_IDLE_LEFT_DRAW_1
	break
	mov [0x0E], 0x0000
	call CAPSULE_BUDDY_IDLE_LEFT_DRAW_2
	break
	mov [0x29], 0x0002

LABEL_2719:
	mov [0x0E], 0x0003
	call CAPSULE_BUDDY_IDLE_LEFT_DRAW_2
	break
	djnz [0x29], LABEL_2719
	mov [0x29], 0x0002

LABEL_2729:
	mov [0x0E], 0x0000
	call CAPSULE_BUDDY_IDLE_LEFT_DRAW_1
	break
	djnz [0x29], LABEL_2729
	mov [0xF8], [BUDDY_X]
	sub [0xF8], [HERO_X]
	jl [0xF8], 0x64, LABEL_2750
	call LABEL_5423
	jne [0x12], 0x28, LABEL_2750
	je [0x21], 0x00, LABEL_26FD

LABEL_2750:
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	mov [0x29], 0x0002
	jmp DISPATCH_VAR2F_STATE
	killChannel
	mov [0xEE], 0x00FA
	mov [0xEF], 0x0005

LABEL_2768:
	video offset=CINEMATIC_718, x=[0xee], y=98
	sub [0xEE], 0x000A
	break
	djnz [0xEF], LABEL_2768
	mov [0xEF], 0x0004

LABEL_277A:
	video offset=CINEMATIC_718, x=[0xee], y=99
	sub [0xEE], 0x0008
	break
	djnz [0xEF], LABEL_277A
	mov [0xEF], 0x0004

LABEL_278C:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0006
	break
	djnz [0xEF], LABEL_278C
	mov [0xEF], 0x0004

LABEL_279E:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0004
	break
	djnz [0xEF], LABEL_279E
	mov [0xEF], 0x0004

LABEL_27B0:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0003
	break
	djnz [0xEF], LABEL_27B0
	mov [0xEF], 0x0004

LABEL_27C2:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0002
	break
	djnz [0xEF], LABEL_27C2
	mov [0xEF], 0x0004

LABEL_27D4:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0001
	break
	djnz [0xEF], LABEL_27D4
	mov [0xEF], 0x0002

LABEL_27E6:
	video offset=CINEMATIC_718, x=[0xee], y=100
	sub [0xEE], 0x0001
	break
	video offset=CINEMATIC_718, x=[0xee], y=100
	break
	djnz [0xEF], LABEL_27E6

HANG_DRAW_CIN_718:
	video offset=CINEMATIC_718, x=[0xee], y=100
	break
	jmp HANG_DRAW_CIN_718
	killChannel

LABEL_2804:
	je [0xB6], 0x00, CAPSULE_KILLCHAN_OR_SET_ACTION_MASK_BIT_2
	jne [SCREEN_NUM], [0xB6], CAPSULE_KILLCHAN_OR_SET_ACTION_MASK_BIT_2
	jl [HERO_X], 0x0148, LABEL_2824
	mov [HERO_X], 0x0148
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_2804
	killChannel

LABEL_2824:
	break
	jmp LABEL_2804
	killChannel

LABEL_2829:
	break
	jl [HERO_X], 0x78, LABEL_2829
	jg [HERO_X], 0xF0, LABEL_2829
	mov [0xF8], [0xB2]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, CAPSULE_KILLCHAN_OR_SET_ACTION_MASK_BIT_2
	or [0xB2], 0x0100
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	call LABEL_3514
	setup channel=0x34, address=CAPSULE_SHIELD_DEPLOY_AT_RIGHT_EDGE
	setup channel=0x33, address=CAPSULE_SHIELD_DEPLOY_AT_LEFT_EDGE
	break
	break
	break
	break
	break
	call LABEL_3514
	killChannel

LABEL_2863:
	jl [SCREEN_NUM], 0x4A, CAPSULE_ACTOR_FROM_LEFT_RESPAWN_TOKEN_SPEND
	jg [SCREEN_NUM], 0x4C, CAPSULE_ACTOR_FROM_LEFT_RESPAWN_TOKEN_SPEND
	jne [0x1D], 0x29, CAPSULE_ACTOR_FROM_LEFT_RESPAWN_TOKEN_SPEND
	je [0xB0], 0x00, SET_VARB1_TO_0000
	mov [0xB0], 0x0000
	ret
