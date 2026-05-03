LESTER_DRIFT_RIGHT_SEQ:
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	mov [0x02], 0x0007

LESTER_DRIFT_R_PHASE_1:
	break
	add [0x01], 0x0004
	djnz [0x02], LESTER_DRIFT_R_PHASE_1
	mov [0x02], 0x0007

LESTER_DRIFT_R_PHASE_2:
	break
	add [0x01], 0x0005
	djnz [0x02], LESTER_DRIFT_R_PHASE_2
	mov [0x02], 0x000A

LESTER_DRIFT_R_PHASE_3:
	break
	add [0x01], 0x0006
	djnz [0x02], LESTER_DRIFT_R_PHASE_3
	killChannel

LESTER_GRABS_A_VINE_AND_SWINGS:
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_0, x=107, y=148
	break
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_1, x=107, y=148
	break
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_2, x=106, y=151
	break
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_3, x=101, y=150
	break
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_3, x=97, y=149
	break
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_4, x=86, y=153
	break
	play id=0x002D, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_JUMPING_TOWARDS_VINE_4, x=82, y=160
	mov [0x1B], 0x0000
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	break
	video type=1, offset=CINEMATIC_STATIC_VINE_ABOUT_TO_SNAP_0, x=160, y=100
	video type=1, offset=CINEMATIC_LESTER_GRABBING_VINE_0, x=72, y=168
	setup channel=0x05, address=SCHEDULE_LAKE_DECORATIONS_096_TO_099
	break
	video type=1, offset=CINEMATIC_STATIC_VINE_ABOUT_TO_SNAP_1, x=160, y=100
	video type=1, offset=CINEMATIC_LESTER_GRABBING_VINE_1, x=67, y=170
	break
	video type=1, offset=CINEMATIC_LESTER_GRABBING_VINE_2, x=65, y=171
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_3, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_3, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_3, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_HANGING_ON_THE_VINE_1, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=LOOP_DRAW_LAKE_093_AT_CENTER
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_1, x=160, y=100
	break
	mov [0x01], 0x00A0
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_2, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_3, x=[0x01], y=100, zoom=0x40
	setup channel=0x04, address=LESTER_DRIFT_RIGHT_SEQ
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_4, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_5, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_6, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_7, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_8, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_9, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_10, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_11, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_12, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_13, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_14, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_15, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_16, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_17, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_18, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_19, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_20, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_21, x=[0x01], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_22, x=[0x01], y=100, zoom=0x40
	setup channel=0x3F, address=OUTSIDE_POOL_SCREEN
	break
	video type=1, offset=CINEMATIC_SWINGING_AFTER_VINE_SNAPS_23, x=[0x01], y=100, zoom=0x40
	setup channel=0x00, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	call KILL_CH_01_04_38
	break
	call ADVANCE_X_BACKWARD_ONE_SCREEN
	mov [0x01], 0x008C
	mov [0x02], 0x0050
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_3, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_4, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_5, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_6, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_7, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_8, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_9, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_10, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0051, freq=0x0A, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_11, x=[0x01], y=[0x02], zoom=0x40
	freezeChannels first=0x14, last=0x16
;@if BRANCH == "cartridge_1992"
	setup channel=0x14, address=RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	setup channel=0x14, address=RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	setup channel=0x14, address=MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	break
	video type=1, offset=CINEMATIC_LANDING_AFTER_SWING_12, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x5E], 0x0001
	mov [0x01], 0x0061
	mov [0x02], 0x00B6
	mov [0x63], 0x0002
	jne [0x2A], 0x04, KILL_IF_NOT_SCENE_4
	setup channel=0x28, address=BEAST_AI_SPAWN_FAR_LEFT
	setup channel=0x29, address=WAIT_UNTIL_BEAST_CLOSE
	mov [0x2A], 0x0005

