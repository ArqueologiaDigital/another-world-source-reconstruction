ENDING_SKY_SWEEP_FROM_RIGHT_PHASE_1:
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F0, x=160, y=100
	break
	djnz [0xE6], ENDING_SKY_SWEEP_FROM_RIGHT_PHASE_1
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F1, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F2, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F3, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F4, x=160, y=100
	mov [0xE6], 0x0007

ENDING_SKY_SWEEP_FROM_LEFT_PHASE_2:
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F4, x=160, y=100
	djnz [0xE6], ENDING_SKY_SWEEP_FROM_LEFT_PHASE_2
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F5, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F6, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F7, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F8, x=160, y=100
	mov [0xE6], 0x000A

ENDING_SWEEP_HOLD_THEN_CUT_TO_CLOSEUP:
	break
	video offset=CINEMATIC_ENDING_SKY_SWEEP_SILHOUETTE_F9, x=160, y=100
	djnz [0xE6], ENDING_SWEEP_HOLD_THEN_CUT_TO_CLOSEUP
	setup channel=0x0A, address=ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP
	setup channel=0x0B, address=ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_RISE
	setup channel=0x0C, address=ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP
	setup channel=0x0D, address=ENDING_CLOSEUP_SHOT_CUT_TO_FLY_AWAY_ENTRY
	killChannel

ENDING_DRAW_STARS_BG_PLAY_SOUND_08:
	call ENDING_CLOUD_SKY_BACKDROP_PAGE_0
	call ENDING_CLOUD_SKY_BACKDROP_PAGE_3
	setup channel=0x05, address=PTERANODON_HEAD_LOWERED_HOLD_LOOP
	selectVideoPage 0x00
	play id=0x0008, freq=0x05, vol=0x20, channel=0x00
	play id=0x0008, freq=0x07, vol=0x30, channel=0x01
	video offset=CINEMATIC_008, x=160, y=100
	video offset=CINEMATIC_009, x=160, y=100
	video offset=CINEMATIC_010, x=160, y=100
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0004
	mov [0x03], 0x000A
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	setPalette 0x0A

LESTER_PRONE_ARRIVAL_DELAY:
	break
	djnz [0x03], LESTER_PRONE_ARRIVAL_DELAY
	setup channel=0x05, address=PTERANODON_HEAD_RAISE_ANIM
	video offset=CINEMATIC_011, x=[0x01], y=[0x02]
	play id=0x0008, freq=0x0A, vol=0x16, channel=0x00
	play id=0x0057, freq=0x14, vol=0x20, channel=0x02
	break
	video offset=CINEMATIC_012, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F0, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F1, x=[0x01], y=[0x02]
	play id=0x000E, freq=0x03, vol=0x20, channel=0x03
	mov [0x03], 0x0014

LESTER_PRONE_TERRACE_HOLD:
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F2, x=[0x01], y=[0x02]
	djnz [0x03], LESTER_PRONE_TERRACE_HOLD
	mov [PAUSE_SLICES], 0x000A
	mov [0x03], 0x0006
	play id=0x000F, freq=0x03, vol=0x30, channel=0x03
	break
	play id=0x0008, freq=0x07, vol=0x11, channel=0x01

LESTER_PRONE_DRAW_THEN_CREDITS_MUSIC_CUE:
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F1, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F1, x=[0x01], y=[0x02]
	break
	jne [0x03], 0x04, LESTER_PRONE_CYCLE_AMBIENT_FADE_DOWN_CASE_03
	song id=0x008A, delay=0x3A98, pos=0x00
	play id=0x0008, freq=0x0A, vol=0x16, channel=0x00

LESTER_PRONE_CYCLE_AMBIENT_FADE_DOWN_CASE_03:
	jne [0x03], 0x03, LESTER_PRONE_CYCLE_SLOWDOWN_LOOP
	play id=0x0008, freq=0x0A, vol=0x0B, channel=0x00

LESTER_PRONE_CYCLE_SLOWDOWN_LOOP:
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F0, x=[0x01], y=[0x02]
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F3, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F3, x=[0x01], y=[0x02]
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F4, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F4, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F5, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F5, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F5, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F2, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_ENDING_LESTER_PRONE_F1, x=[0x01], y=[0x02]
	break
	add [PAUSE_SLICES], 0x0002
	djnz [0x03], LESTER_PRONE_DRAW_THEN_CREDITS_MUSIC_CUE
	mov [PAUSE_SLICES], 0x0006
	video offset=CINEMATIC_019, x=[0x01], y=[0x02]
	setup channel=0x14, address=ALIEN_ARRIVAL_POSITION_INIT

LESTER_PRONE_BODY_LOOP:
	break
	video offset=CINEMATIC_020, x=[0x01], y=[0x02]
	jmp LESTER_PRONE_BODY_LOOP
LABEL_0672:
	db 0x11
