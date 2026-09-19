INIT_TANK_DRIVE_VARS:
	mov [0x0F], 0x008C
	mov [0x10], 0x0064
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x3E], 0x0000
	mov [0x41], 0x0000
	mov [0x37], 0x0000
	mov [0x45], 0x0000
	mov [0x46], 0x0000
	mov [0x47], 0x0000
	mov [0x4E], 0x0000
	mov [0x4F], 0x0000
	mov [0x56], 0x0000
	mov [0x57], 0x0000
	mov [0x62], 0x000B
	mov [0x5F], 0x000B
	mov [0x63], 0x0000
	mov [SCREEN_NUM], 0x0000
	ret


TANK_ARENA_CREATURE_CHARGE_PAST:
	break
	break
	break
	video offset=CINEMATIC_036, x=6, y=126
	break
	video offset=CINEMATIC_036, x=221, y=109
	break
	video offset=CINEMATIC_036, x=486, y=102
	killChannel

TANK_ARENA_CREATURE_CHARGE_AND_SCENE_REARM:
	video offset=CINEMATIC_036, x=6, y=126
	setup channel=0x01, address=TANK_STAGE_BOOT_SETUP_CHANNELS
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	break
	selectVideoPage 0x00
	call DRAW_CIN_6_AND_RET
	video offset=CINEMATIC_000, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_036, x=221, y=109
	break
	video offset=CINEMATIC_036, x=486, y=102
	killChannel
	break
	break
	break
	video offset=CINEMATIC_036, x=73, y=56
	break
	video offset=CINEMATIC_036, x=266, y=79
	break
	video offset=CINEMATIC_036, x=576, y=91
	killChannel

TANK_ARENA_CREATURE_RUN_INIT:
	mov [0x52], 0x017C
	mov [0x53], 0x0075
	mov [HACK_VAR_54], 0x0040
	mov [0x55], 0x0008

TANK_ARENA_CREATURE_RUN_ACROSS_LOOP:
	video offset=CINEMATIC_037, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0004
	video offset=CINEMATIC_038, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0002
	video offset=CINEMATIC_039, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_040, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_041, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_042, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_043, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_044, x=[0x52], y=[0x53], zoom=[0x54]
	break
	video offset=CINEMATIC_045, x=[0x52], y=[0x53], zoom=[0x54]
	break
	sub [0x52], 0x0048
	djnz [0x55], TANK_ARENA_CREATURE_RUN_ACROSS_LOOP
	mov [0x55], 0x001E

TANK_ARENA_CREATURE_RUN_RESTART_DELAY:
	break
	djnz [0x55], TANK_ARENA_CREATURE_RUN_RESTART_DELAY
	jmp TANK_ARENA_CREATURE_RUN_INIT
LABEL_0ED7:
	db 0x11, 0x00, 0x52, 0x01, 0x7C, 0x00, 0x53, 0x00
	db 0x75, 0x00, 0x54, 0x00, 0x40, 0x00, 0x55, 0x00
	db 0x08, 0x03, 0x52, 0xFF, 0xFC, 0x55, 0x0F, 0x61
	db 0x52, 0x53, 0x54, 0x06, 0x03, 0x52, 0xFF, 0xFE
	db 0x55, 0x0F, 0xB1, 0x52, 0x53, 0x54, 0x06, 0x55
	db 0x10, 0x01, 0x52, 0x53, 0x54, 0x06, 0x55, 0x10
	db 0x51, 0x52, 0x53, 0x54, 0x06, 0x55, 0x10, 0xA1
	db 0x52, 0x53, 0x54, 0x03, 0x52, 0xFF, 0xB8, 0x06
	db 0x09, 0x55, 0x0E, 0xE8, 0x07, 0x0E, 0xD8, 0x11

TANK_ARENA_GUN_ACTIVATION_WAIT_INIT:
	break
	jle [0x37], 0x00, TANK_ARENA_GUN_ACTIVATION_WAIT_INIT
	sub [0x37], 0x0001
	mov [0x39], 0x00A0
	mov [0x3A], 0x0064
	mov [0x38], 0x0000
	mov [0x3B], 0x0006

TANK_ARENA_GUN_TRAVERSE_FIRE_LOOP:
	break
	call TANK_ARENA_GUN_TRAVERSE_PHASE_1
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_2
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_3
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_4
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_5
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	add [0x38], 0x0001
	call TANK_CANNON_SWEEP_FLASH_PHASE_6
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_5
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_4
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_3
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_2
	call APPLY_HERO_DAMAGE_AND_HIT
	break
	sub [0x38], 0x0001
	call TANK_ARENA_GUN_TRAVERSE_PHASE_1
	call APPLY_HERO_DAMAGE_AND_HIT
	jmp TANK_ARENA_GUN_TRAVERSE_FIRE_LOOP
LABEL_0FB2:
	db 0x11

TANK_ARENA_GUN_TRAVERSE_PHASE_1:
	video offset=CINEMATIC_101, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_102, x=[0x39], y=[0x3a]
	ret


TANK_ARENA_GUN_TRAVERSE_PHASE_2:
	video offset=CINEMATIC_103, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_104, x=[0x39], y=[0x3a]
	ret


TANK_ARENA_GUN_TRAVERSE_PHASE_3:
	video offset=CINEMATIC_105, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_106, x=[0x39], y=[0x3a]
	ret


TANK_ARENA_GUN_TRAVERSE_PHASE_4:
	video offset=CINEMATIC_107, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_108, x=[0x39], y=[0x3a]
	ret


TANK_ARENA_GUN_TRAVERSE_PHASE_5:
	video offset=CINEMATIC_109, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_110, x=[0x39], y=[0x3a]
	ret


TANK_CANNON_SWEEP_FLASH_PHASE_6:
	video offset=CINEMATIC_111, x=[0x39], y=[0x3a]
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	video offset=CINEMATIC_112, x=[0x39], y=[0x3a]
	ret


APPLY_HERO_DAMAGE_AND_HIT:
	jle [0x37], 0x00, SHARED_RET
	jne [0x45], 0x00, SHARED_RET
	sub [0x37], 0x0001
	mov [0x45], 0x0001
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x42], [0x64]
	and [0x42], 0x001F
	mov [0xF8], [0x38]
	shl [0xF8], 0x0004
	add [0x42], [0xF8]
	shl [0xF8], 0x0001
	add [0x42], [0xF8]
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x43], [0x64]
	and [0x43], 0x000F
	add [0x43], 0x005F
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x44], [0x64]
	and [0x44], 0x000F
	je [0x57], 0x00, TANK_CANNON_IMPACT_ZOOM_BASE_DONE
	add [0x43], 0x000F
	and [0x44], 0x0003
	add [0x44], 0x0007
