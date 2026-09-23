CAPSULE_SCREEN_91_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_523, x=160, y=100
	video offset=CINEMATIC_524, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_91_BACKDROP_LAYER_3, x=160, y=100
	ret


LABEL_9C52:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_551, x=160, y=100
	video offset=CINEMATIC_552, x=160, y=100
	video offset=CINEMATIC_553, x=160, y=100
	video offset=CINEMATIC_554, x=160, y=100
	ret


	video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_5, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_6, x=160, y=100
	ret


	fill page=0x00, color=0x08
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_551, x=160, y=100
	video offset=CINEMATIC_552, x=160, y=100
	video offset=CINEMATIC_553, x=160, y=100
	video offset=CINEMATIC_554, x=160, y=100
	ret


LABEL_9C8B:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_0, x=160, y=198
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_1, x=160, y=198
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_3, x=160, y=100
	ret


CAPSULE_SCREEN_C8_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_C8_BACKDROP_LAYER_0, x=160, y=100
	ret


CAPSULE_SCREEN_8A_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_8A_BACKDROP_LAYER_0, x=160, y=100
	ret


CAPSULE_SCREEN_AA_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_AA_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_AA_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_558, x=160, y=100
	ret


CAPSULE_SCREEN_A9_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_555, x=155, y=95
	video offset=CINEMATIC_CAPSULE_SCREEN_A9_BACKDROP_LAYER_1, x=160, y=100
	ret


LABEL_9CCB:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_0, x=160, y=151
	video offset=CINEMATIC_611, x=160, y=100
	ret


CAPSULE_SCREEN_8B_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_6, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_5, x=160, y=100
	ret


CAPSULE_SCREEN_8C_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_8C_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_8C_BACKDROP_LAYER_2, x=160, y=100
	ret


CAPSULE_SCREEN_CA_BACKDROP_DRAW:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_CA_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_CA_BACKDROP_LAYER_1, x=160, y=100
	ret


LABEL_9CFF:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_0, x=160, y=187
	video offset=CINEMATIC_575, x=160, y=100
	ret


CAPSULE_SCREEN_EB_BACKDROP_DRAW:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_555, x=160, y=23
	video offset=CINEMATIC_CAPSULE_SCREEN_EB_BACKDROP_LAYER_1, x=160, y=50
	mov [0xF8], [0xB9]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, DRAW_CIN_591_THEN_CIN_345
	video offset=CINEMATIC_587, x=232, y=65
	video offset=CINEMATIC_591, x=151, y=14
	ret


DRAW_CIN_591_THEN_CIN_345:
	video offset=CINEMATIC_591, x=151, y=65496
	video offset=CINEMATIC_345, x=6, y=99
	ret


LABEL_9D37:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_555, x=160, y=23
	video offset=CINEMATIC_586, x=160, y=100
	video offset=CINEMATIC_587, x=74, y=64
	video offset=CINEMATIC_588, x=74, y=64
	video offset=CINEMATIC_589, x=74, y=64
	video offset=CINEMATIC_587, x=191, y=65
	video offset=CINEMATIC_588, x=191, y=65
	video offset=CINEMATIC_589, x=191, y=65
	video offset=CINEMATIC_587, x=295, y=64
	video offset=CINEMATIC_588, x=295, y=64
	video offset=CINEMATIC_590, x=295, y=64
	video offset=CINEMATIC_591, x=65528, y=15
	video offset=CINEMATIC_591, x=107, y=14
	video offset=CINEMATIC_591, x=212, y=15
	call LABEL_369F
	mov [0x10], [SCREEN_NUM]
	mov [BUDDY_Y], [0x40]
	mov [BUDDY_X], 0x0064
	mov [0x09], 0x0001
	call CAPSULE_BUDDY_PER_FRAME_TICK
	mov [0x09], 0x0033
	mov [BUDDY_X], 0x0050
	call CAPSULE_BUDDY_PER_FRAME_TICK
	mov [0x09], 0x0001
	mov [BUDDY_X], 0x046A
	call CAPSULE_BUDDY_PER_FRAME_TICK
	mov [0x09], 0x0001
	mov [BUDDY_X], 0x0032
	call CAPSULE_BUDDY_PER_FRAME_TICK
	mov [0x09], 0x0001
	mov [BUDDY_X], 0x005A
	call CAPSULE_BUDDY_PER_FRAME_TICK
	mov [0x09], 0x0033
	mov [BUDDY_X], 0x047E
	call CAPSULE_BUDDY_PER_FRAME_TICK
	ret


; Fill page 0 with color 0x01 + draw CINEMATIC_FINAL_ESCAPE_-
; LESTER_RUNNING + 3 supporting frames (433/434/435). The
; 4-element BG composite for the final-escape running scene.
DRAW_FINAL_ESCAPE_LESTER_RUNNING_BG:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_FINAL_ESCAPE_LESTER_RUNNING, x=160, y=100
	video offset=CINEMATIC_433, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_435, x=160, y=100
	ret


JUNK__9DD7:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_696, x=160, y=100
	video offset=CINEMATIC_697, x=160, y=100
	ret


	video offset=CINEMATIC_695, x=160, y=100

LABEL_9DF3:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_8, x=160, y=100
	ret


CAPSULE_SCREEN_2A_BACKDROP_DRAW:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_4, x=160, y=100
	ret


	fill page=0x00, color=0x01
	video offset=CINEMATIC_458, x=160, y=100
	video offset=CINEMATIC_433, x=160, y=100
	ret


LABEL_9E1F:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_457, x=160, y=100
	video offset=CINEMATIC_458, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_459, x=160, y=100
	video offset=CINEMATIC_460, x=160, y=100
	ret


CAPSULE_SCREEN_6C_BACKDROP_DRAW:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_457, x=160, y=100
	video offset=CINEMATIC_458, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_459, x=160, y=100
	video offset=CINEMATIC_460, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_3, x=160, y=100
	ret


	video offset=CINEMATIC_CAPSULE_SCREEN_6C_BACKDROP_LAYER_6, x=4, y=65518

LABEL_9E59:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1, x=160, y=100
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_2, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_1, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_0, x=58, y=100
	ret


	fill page=0x00, color=0x01
	video offset=CINEMATIC_CAPSULE_SCREEN_6D_BACKDROP_LAYER_7, x=160, y=100
	video offset=CINEMATIC_CAPSULE_SCREEN_6D_BACKDROP_LAYER_8, x=160, y=100
	ret


CAPSULE_SCREEN_6E_BACKDROP_DRAW:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_6E_BACKDROP_LAYER_0, x=160, y=100
	ret


CAPSULE_SCREEN_8D_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_8D_BACKDROP_LAYER_0, x=160, y=100
	ret


CAPSULE_SCREEN_8E_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_3, x=160, y=100
	ret


CAPSULE_SCREEN_EE_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_EE_BACKDROP_LAYER_0, x=160, y=100
	ret


CAPSULE_SCREEN_AD_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_AD_BACKDROP_LAYER_0, x=188, y=99
	video offset=CINEMATIC_CAPSULE_SCREEN_AD_BACKDROP_LAYER_1, x=188, y=99
	ret


CAPSULE_SCREEN_CD_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_CD_BACKDROP_LAYER_0, x=188, y=99
	ret


LABEL_9EB9:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_585, x=160, y=100
	ret


; Fill page 0 with color 0x08 + draw CINEMATIC_492 at (160,
; 229) + CINEMATIC_TANK_REVEAL_BG at center. The
; 2-element composite for the first reveal of the tank.
DRAW_TANK_REVEAL_BG:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_492, x=160, y=229, zoom=0x40
	video offset=CINEMATIC_TANK_REVEAL_BG, x=160, y=100
	ret


CAPSULE_SCREEN_ED_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAPSULE_SCREEN_ED_BACKDROP_LAYER_0, x=160, y=100
	ret


LABEL_9ED6:
	mov [0x22], 0x00B9
	jle [0x21], 0x0C, SHARED_RET
	jg [0x21], 0x25, SHARED_RET
	mov [0x22], 0x010E
	ret


	jg [0x22], 0x96, SET_VAR22_TO_00B8
	mov [0x22], 0x0062
	jle [0x21], 0x60, SHARED_RET
