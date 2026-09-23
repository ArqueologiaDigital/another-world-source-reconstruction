TANK_ARENA_ENTRY_DRIVE_ACROSS_LOOP:
	break
	call DRAW_TANK_FLYBY_CRAFT
	mov [0xF8], [0x2B]
	add [0xF8], 0x0003
	add [0x01], [0xF8]
	djnz [0x2B], TANK_ARENA_ENTRY_DRIVE_ACROSS_LOOP
	jmp TANK_STAGE_BOOT_SETUP_CHANNELS

RESET_PAGES_AND_SETUP_CH_0A:
	killChannel
	copyVideoPage src=0x03, dst=0x00
	killChannel
	setup channel=0x0A, address=TANK_DRAW_CIN_087_THREE_VARYING_POSITIONS

TANK_ARENA_ENTRY_WALL_REDRAW_LOOP:
	video offset=CINEMATIC_037, x=160, y=100
	break
	jmp TANK_ARENA_ENTRY_WALL_REDRAW_LOOP

TANK_ARENA_ENTRY_WALL_OCCLUDER_REDRAW_LOOP:
	video offset=CINEMATIC_036, x=160, y=100
	break
	jmp TANK_ARENA_ENTRY_WALL_OCCLUDER_REDRAW_LOOP
LABEL_0112:
	db 0x11

TANK_DRAW_CIN_087_THREE_VARYING_POSITIONS:
	video offset=CINEMATIC_TANK_FALLING_STREAK, x=81, y=131
	break
	video offset=CINEMATIC_TANK_FALLING_STREAK, x=96, y=121
	break
	video offset=CINEMATIC_TANK_FALLING_STREAK, x=86, y=127
	break
	jmp TANK_DRAW_CIN_087_THREE_VARYING_POSITIONS
LABEL_0125:
	db 0x11

; Draws CINEMATIC_275 four times at descending Y positions
; (101, 136, 124, 112) with break-pauses between — the
; target reticle "scanning down" or "falling" effect on
; the tank's HUD/viewfinder.
DRAW_4_TARGET_RETICLES_FALLING:
	video offset=CINEMATIC_275, x=152, y=101
	break
	video offset=CINEMATIC_275, x=143, y=136
	break
	video offset=CINEMATIC_275, x=148, y=124
	break
	video offset=CINEMATIC_275, x=151, y=112
	break
	video offset=CINEMATIC_275, x=206, y=52
	break
	video offset=CINEMATIC_275, x=205, y=166
	break
	video offset=CINEMATIC_275, x=196, y=50
	break
	video offset=CINEMATIC_275, x=188, y=49
	break
	video offset=CINEMATIC_275, x=179, y=49
	break
	video offset=CINEMATIC_275, x=179, y=78
	break
	video offset=CINEMATIC_275, x=205, y=81
	break
	video offset=CINEMATIC_275, x=103, y=89
	break
	video offset=CINEMATIC_275, x=51, y=130
	break
	video offset=CINEMATIC_275, x=104, y=46
	break
	video offset=CINEMATIC_275, x=101, y=46
	break
	video offset=CINEMATIC_275, x=99, y=48
	break
	video offset=CINEMATIC_275, x=95, y=50
	break
	video offset=CINEMATIC_275, x=96, y=60
	break
	video offset=CINEMATIC_275, x=98, y=69
	break
	video offset=CINEMATIC_275, x=95, y=72
	break
	video offset=CINEMATIC_275, x=92, y=75
	break
	video offset=CINEMATIC_275, x=49, y=69
	break
	video offset=CINEMATIC_275, x=51, y=76
	break
	video offset=CINEMATIC_275, x=54, y=83
	break
	video offset=CINEMATIC_275, x=56, y=92
	break
	video offset=CINEMATIC_275, x=62, y=88
	break
	video offset=CINEMATIC_275, x=66, y=85
	break
	video offset=CINEMATIC_275, x=71, y=82
	break
	video offset=CINEMATIC_275, x=70, y=75
	break
	video offset=CINEMATIC_275, x=66, y=76
	break
	video offset=CINEMATIC_275, x=63, y=79
	break
	video offset=CINEMATIC_275, x=60, y=80
	break
	video offset=CINEMATIC_275, x=59, y=74
	break
	video offset=CINEMATIC_275, x=62, y=72
	break
	video offset=CINEMATIC_275, x=65, y=70
	break
	video offset=CINEMATIC_275, x=69, y=68
	break
	video offset=CINEMATIC_275, x=228, y=107
	break
	video offset=CINEMATIC_275, x=227, y=112
	break
	video offset=CINEMATIC_275, x=225, y=117
	break
	video offset=CINEMATIC_275, x=265, y=70
	break
	video offset=CINEMATIC_275, x=268, y=73
	break
	video offset=CINEMATIC_275, x=271, y=78
	break
	video offset=CINEMATIC_275, x=273, y=82
	break
	video offset=CINEMATIC_275, x=275, y=87
	break
	video offset=CINEMATIC_275, x=225, y=50
	break
	video offset=CINEMATIC_275, x=225, y=58
	break
	video offset=CINEMATIC_275, x=153, y=36
	break
	video offset=CINEMATIC_275, x=111, y=125
	break
	video offset=CINEMATIC_275, x=120, y=37
	break
	video offset=CINEMATIC_275, x=23, y=110
	break
	video offset=CINEMATIC_275, x=27, y=95
	break
	jmp DRAW_4_TARGET_RETICLES_FALLING
LABEL_022D:
	db 0x11

; Sequential setPalette through 0x0A → 0x0D → 0x0E → 0x0F
; with one-tick breaks. Atmospheric palette flicker — likely
; the muzzle-flash + recoil flash for the tank firing, or
; the impact flash when shot.
PALETTE_FLICKER_0A_TO_0F:
	setPalette 0x0A
	break
	setPalette 0x0D
	break
	setPalette 0x0E
	break
	setPalette 0x0F
	break
	setPalette 0x10
	break
	setPalette 0x10
	break
	setPalette 0x0F
	break
	setPalette 0x0E
	break
	setPalette 0x0D
	break
	setPalette 0x0A
	break
	setPalette 0x0A
	break
	jmp PALETTE_FLICKER_0A_TO_0F

CAPSULE_DOME_CLOSING_PHASE_1_ENTRY:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x0A, address=DRAW_4_TARGET_RETICLES_FALLING
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F3, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0B
	setup channel=0x3B, address=CAPSULE_DOME_CLOSED_REDRAW_LOOP
	mov [0x02], 0x00FA
	mov [0x03], 0x0014

CAPSULE_DOME_TOP_DROP_LOOP:
	break
	play id=0x0058, freq=0x07, vol=0x10, channel=0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F4, x=160, y=[0x02]
	sub [0x02], 0x0005
	djnz [0x03], CAPSULE_DOME_TOP_DROP_LOOP
	setup channel=0x09, address=PALETTE_FLICKER_0A_TO_0F
	setup channel=0x0B, address=DRAW_4_TARGET_RETICLES_FALLING
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F5, x=160, y=[0x02]
	setPalette 0x0B
	mov [0x03], 0x000F

CAPSULE_DOME_TOP_LIFT_LOOP:
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F5, x=160, y=[0x02]
	sub [0x02], 0x0005
	djnz [0x03], CAPSULE_DOME_TOP_LIFT_LOOP
	add [0x02], 0x0002
	selectVideoPage 0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F5, x=160, y=[0x02]
	selectVideoPage 0xFF
	setPalette 0x0A
	play id=0x0057, freq=0x02, vol=0x20, channel=0x00
	setup channel=0x37, address=CAPSULE_DOME_CLOSING_LATE_FRAMES
	deleteChannels first=0x09, last=0x0B
	mov [0x03], 0x0014

CAPSULE_DOME_PHASE_1_TO_2_DELAY:
	break
	djnz [0x03], CAPSULE_DOME_PHASE_1_TO_2_DELAY
	setup channel=0x37, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	jmp CAPSULE_DOME_CLOSING_PHASE_2_ENTRY
LABEL_02F2:
	db 0x11

CAPSULE_DOME_CLOSING_PHASE_2_ENTRY:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x3B, address=CAPSULE_DOME_CLOSED_REDRAW_LOOP
	setup channel=0x37, address=CAPSULE_DOME_CLOSING_PHASE_3_FRAMES
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00
	deleteChannels first=0x09, last=0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F6, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F7, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F8, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F9, x=160, y=[0x02]
	setPalette 0x13
	mov [0x03], 0x0032

CAPSULE_DOME_F9_HOLD_LOOP:
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F9, x=160, y=[0x02]
	break
	djnz [0x03], CAPSULE_DOME_F9_HOLD_LOOP
	killChannel

CAPSULE_DOME_CLOSING_PHASE_3_FRAMES:
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F10, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F11, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F12, x=160, y=100
	break
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x01
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F13, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F14, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F15, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F16, x=160, y=100
	play id=0x008B, freq=0x12, vol=0x20, channel=0x01
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0003

CAPSULE_DOME_F16_DIVERGE_LOOP:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F16, x=[0xe6], y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F16, x=[0xe7], y=100
	djnz [0xE8], CAPSULE_DOME_F16_DIVERGE_LOOP
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0006

CAPSULE_DOME_F17_DIVERGE_LOOP:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F17, x=[0xe6], y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F17, x=[0xe7], y=100
	djnz [0xE8], CAPSULE_DOME_F17_DIVERGE_LOOP
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE9], 0x0040
	mov [0xE8], 0x0018

CAPSULE_DOME_F18_ZOOM_DIVERGE_LOOP:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	sub [0xE6], 0x0001
	add [0xE7], 0x0001
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F18, x=[0xe6], y=100, zoom=[0xe9]
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F18, x=[0xe7], y=100, zoom=[0xe9]
	djnz [0xE8], CAPSULE_DOME_F18_ZOOM_DIVERGE_LOOP
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x01
	deleteChannels first=0x00, last=0x36
	deleteChannels first=0x38, last=0x3B
	deleteChannels first=0x3D, last=0x3F
	jmp TANK_DRIVE_SCENE_INIT
LABEL_03FE:
	db 0x11

CAPSULE_DOME_CLOSING_REENTRY:
	call TANK_SCENE_INIT_FILL_PAGE_3_COLOR_0C
	jmp CAPSULE_DOME_CLOSING_PHASE_1_ENTRY
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F3, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0C
	setup channel=0x3B, address=CAPSULE_DOME_CLOSED_REDRAW_LOOP
	mov [0x02], 0x00FA
	mov [0x03], 0x0023

CAPSULE_BUDDY_DROP_LOOP:
	break
	video offset=CINEMATIC_BUDDY, x=160, y=[0x02]
	sub [0x02], 0x0005
	djnz [0x03], CAPSULE_BUDDY_DROP_LOOP
	mov [0x03], 0x000F

CAPSULE_BUDDY_LIFT_LOOP:
	break
	video offset=CINEMATIC_BUDDY, x=160, y=[0x02]
	djnz [0x03], CAPSULE_BUDDY_LIFT_LOOP
	add [0x02], 0x0002
	selectVideoPage 0x00
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F5, x=160, y=[0x02]
	selectVideoPage 0xFF
	jmp CAPSULE_DOME_CLOSING_PHASE_1_ENTRY
LABEL_045C:
	db 0x11

CAPSULE_DOME_CLOSED_REDRAW_LOOP:
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F48, x=160, y=100
	break
	jmp CAPSULE_DOME_CLOSED_REDRAW_LOOP
LABEL_0465:
	db 0x11

CAPSULE_DOME_CLOSING_LATE_FRAMES:
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F19, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F20, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F21, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F22, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F23, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F24, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F25, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F26, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F27, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F28, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F29, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F30, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F31, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F32, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F33, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F34, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F35, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F36, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F37, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F38, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F39, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F40, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F41, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F42, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F43, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F44, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F45, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F46, x=160, y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F45, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F46, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=132, y=115
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=162, y=115
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F45, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F46, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=159, y=102
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=135, y=102
	play id=0x0057, freq=0x18, vol=0x40, channel=0x00

; Infinite-jmp redraw of CAPSULE_DOME_CLOSING_F45/F46/F47
; (F47 drawn at two X positions) — the dome's locked-into-
; tank visual held forever on its own channel as the
; static foreground.
CAPSULE_DOME_LOCKED_REDRAW_LOOP:
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F45, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F46, x=160, y=100
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=158, y=102
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F47, x=141, y=100
	jmp CAPSULE_DOME_LOCKED_REDRAW_LOOP
LABEL_051F:
	db 0x11

TANK_STAGE_EXIT_CAPSULE_LAUNCH_TO_BATHS:
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F0, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F1, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F2, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F3, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F4, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video offset=CINEMATIC_TANK_LAUNCH_PLUME_F1, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video offset=CINEMATIC_TANK_LAUNCH_BASE_BAR, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	jmp TANK_STAGE_EXIT_CAPSULE_LAUNCH_TO_BATHS
LABEL_0571:
	db 0x11
