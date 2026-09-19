; Unified source for ENDING with 28 folded shared bodies.
;
; Folded routines (in byte-address order):
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   DELETE_ALL_CHANS_AND_KILL  (3-arm: amiga, cart, dos)
;   ENDING_RESOURCE_PRELOAD  (2-arm: amiga, dos)
;   ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP  (2-arm: amiga, dos)
;   ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_RISE  (2-arm: amiga, dos)
;   DRAW_CIN_103_LOOP  (2-arm: amiga, dos)
;   ENDING_LEDGE_SWELL_DRAW_LOOP  (2-arm: amiga, dos)
;   PTERANODON_LEG_DANGLE_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_4_PLUS_10_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_TWO_BRKS  (2-arm: amiga, dos)
;   DELAY_VAR6_THEN_VAR3_MINUS_1  (2-arm: amiga, dos)
;   DELAY_VAR6_THEN_KILL_CHAN  (2-arm: amiga, dos)
;   INIT_VARE_TO_12  (3-arm: amiga, cart, dos)
;   DRIFT_VAR_F_PLUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_4_LOOP  (2-arm: amiga, dos)
;   DELAY_VARE_THEN_INIT_VARE_5  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_8_LOOP  (2-arm: amiga, dos)
;   ENDING_THE_END_CAPTION_DRAW_LOOP  (2-arm: amiga, dos)
;   PAL_ENDING_CREDITS_FADE_18_TO_1D  (3-arm: amiga, cart, dos)
;   PTERANODON_HEAD_RAISE_ANIM  (2-arm: amiga, dos)
;   PTERANODON_HEAD_BEAK_OPEN_ANIM  (2-arm: amiga, dos)
;   ENDING_SKY_SHOT_ENTRY  (3-arm: amiga, cart, dos)
;   ALIEN_ARRIVAL_POSITION_INIT  (3-arm: amiga, cart, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_0  (2-arm: amiga, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_3  (2-arm: amiga, dos)
;   DRAW_STARS_CIN_38_39_40_5_6  (2-arm: amiga, dos)
;   CLEAR_PAGES_1_2_AND_BLIT  (3-arm: amiga, cart, dos)

; Unified source for ENDING with 7 folded shared bodies.
;
; Folded routines (in byte-address order):
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   DELETE_ALL_CHANS_AND_KILL  (3-arm: amiga, cart, dos)
;   INIT_VARE_TO_12  (3-arm: amiga, cart, dos)
;   PAL_ENDING_CREDITS_FADE_18_TO_1D  (3-arm: amiga, cart, dos)
;   ENDING_SKY_SHOT_ENTRY  (3-arm: amiga, cart, dos)
;   ALIEN_ARRIVAL_POSITION_INIT  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT  (3-arm: amiga, cart, dos)

wrote src/levels/_unified/ending/amiga__entry.inc (530 lines)
wrote src/levels/_unified/ending/amiga__post_PRELOAD_RESOURCES_8_TO_1.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_97_TO_100.inc (3 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_101_102_FADE_PAL_C.inc (34 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_58_ANIM_LOOP.inc (3 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_59_TO_64_VAR_POS.inc (18 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_4_PLUS_10_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_3_MINUS_1_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_3_MINUS_1_TWO_BRKS.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DELAY_VAR6_THEN_VAR3_MINUS_1.inc (9 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_F_PLUS_1_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_F_PLUS_4_LOOP.inc (5 lines)
wrote src/levels/_unified/ending/amiga__post_DRIFT_VAR_F_PLUS_8_LOOP.inc (110 lines)
wrote src/levels/_unified/ending/amiga__post_PAL_FADE_18_TO_1D.inc (0 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_71_72_FADE.inc (12 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_CIN_106_107_FX_57.inc (234 lines)
wrote src/levels/_unified/ending/amiga__post_INIT_VARS_07_08_09.inc (165 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_STARS_PAGE0_CIN_000.inc (3 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_STARS_PAGE3_CIN_004.inc (3 lines)
wrote src/levels/_unified/ending/amiga__post_DRAW_STARS_CIN_38_39_40_5_6.inc (17 lines)
wrote src/levels/_unified/ending/amiga__post_CLEAR_PAGES_1_2_AND_BLIT.inc (7875 lines)
wrote src/levels/_unified/ending/cart__entry.inc (1055 lines)
wrote src/levels/_unified/ending/cart__post_PAL_FADE_18_TO_1D.inc (281 lines)
wrote src/levels/_unified/ending/cart__post_INIT_VARS_07_08_09.inc (313 lines)
wrote src/levels/_unified/ending/cart__post_CLEAR_PAGES_1_2_AND_BLIT.inc (7830 lines)
wrote src/levels/_unified/ending/dos__entry.inc (536 lines)
wrote src/levels/_unified/ending/dos__post_PRELOAD_RESOURCES_8_TO_1.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_97_TO_100.inc (3 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_101_102_FADE_PAL_C.inc (34 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_58_ANIM_LOOP.inc (3 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_59_TO_64_VAR_POS.inc (18 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_4_PLUS_10_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_3_MINUS_1_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_3_MINUS_1_TWO_BRKS.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DELAY_VAR6_THEN_VAR3_MINUS_1.inc (9 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_F_PLUS_1_LOOP.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_F_PLUS_4_LOOP.inc (5 lines)
wrote src/levels/_unified/ending/dos__post_DRIFT_VAR_F_PLUS_8_LOOP.inc (207 lines)
wrote src/levels/_unified/ending/dos__post_PAL_FADE_18_TO_1D.inc (0 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_71_72_FADE.inc (12 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_CIN_106_107_FX_57.inc (234 lines)
wrote src/levels/_unified/ending/dos__post_INIT_VARS_07_08_09.inc (167 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_STARS_PAGE0_CIN_000.inc (3 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_STARS_PAGE3_CIN_004.inc (3 lines)
wrote src/levels/_unified/ending/dos__post_DRAW_STARS_CIN_38_39_40_5_6.inc (51 lines)
wrote src/levels/_unified/ending/dos__post_CLEAR_PAGES_1_2_AND_BLIT.inc (7833 lines)
; Unified source for ENDING with 20 folded shared bodies.
;
; Folded routines (in byte-address order):
;   ENDING_RESOURCE_PRELOAD  (2-arm: amiga, dos)
;   ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP  (2-arm: amiga, dos)
;   ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_RISE  (2-arm: amiga, dos)
;   ENDING_LEDGE_SWELL_DRAW_LOOP  (2-arm: amiga, dos)
;   PTERANODON_LEG_DANGLE_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_4_PLUS_10_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_TWO_BRKS  (2-arm: amiga, dos)
;   DELAY_VAR6_THEN_VAR3_MINUS_1  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_4_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_8_LOOP  (2-arm: amiga, dos)
;   PAL_ENDING_CREDITS_FADE_18_TO_1D  (3-arm: amiga, cart, dos)
;   PTERANODON_HEAD_RAISE_ANIM  (2-arm: amiga, dos)
;   PTERANODON_HEAD_BEAK_OPEN_ANIM  (2-arm: amiga, dos)
;   ALIEN_ARRIVAL_POSITION_INIT  (3-arm: amiga, cart, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_0  (2-arm: amiga, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_3  (2-arm: amiga, dos)
;   DRAW_STARS_CIN_38_39_40_5_6  (2-arm: amiga, dos)
;   CLEAR_PAGES_1_2_AND_BLIT  (3-arm: amiga, cart, dos)

; Unified source for ENDING with 20 folded shared bodies.
;
; Folded routines (in byte-address order):
;   ENDING_RESOURCE_PRELOAD  (2-arm: amiga, dos)
;   ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP  (2-arm: amiga, dos)
;   ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_RISE  (2-arm: amiga, dos)
;   ENDING_LEDGE_SWELL_DRAW_LOOP  (2-arm: amiga, dos)
;   PTERANODON_LEG_DANGLE_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_4_PLUS_10_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_3_MINUS_1_TWO_BRKS  (2-arm: amiga, dos)
;   DELAY_VAR6_THEN_VAR3_MINUS_1  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_1_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_4_LOOP  (2-arm: amiga, dos)
;   DRIFT_VAR_F_PLUS_8_LOOP  (2-arm: amiga, dos)
;   PAL_ENDING_CREDITS_FADE_18_TO_1D  (3-arm: amiga, cart, dos)
;   PTERANODON_HEAD_RAISE_ANIM  (2-arm: amiga, dos)
;   PTERANODON_HEAD_BEAK_OPEN_ANIM  (2-arm: amiga, dos)
;   ALIEN_ARRIVAL_POSITION_INIT  (3-arm: amiga, cart, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_0  (2-arm: amiga, dos)
;   ENDING_CLOUD_SKY_BACKDROP_PAGE_3  (2-arm: amiga, dos)
;   DRAW_STARS_CIN_38_39_40_5_6  (2-arm: amiga, dos)
;   CLEAR_PAGES_1_2_AND_BLIT  (3-arm: amiga, cart, dos)

; Generated by AnotherWorld_VMTools
CINEMATIC_ENDING_CLOUD_SKY_F0		EQU 0x121C
CINEMATIC_ENDING_CLOUD_SKY_F1		EQU 0x0DDC
CINEMATIC_ENDING_CLOUD_SKY_F2		EQU 0x1078
CINEMATIC_ENDING_CLOUD_SKY_F3		EQU 0x0D64
CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0		EQU 0x2ED0
CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1		EQU 0x25B0
CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2		EQU 0x2824
CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F3		EQU 0x337C
CINEMATIC_008		EQU 0x1238
CINEMATIC_009		EQU 0x1318
CINEMATIC_010		EQU 0x4498
CINEMATIC_011		EQU 0x179A
CINEMATIC_012		EQU 0x1730
CINEMATIC_013		EQU 0x1480
CINEMATIC_014		EQU 0x15E8
CINEMATIC_015		EQU 0x1594
CINEMATIC_016		EQU 0x1498
CINEMATIC_017		EQU 0x14EC
CINEMATIC_018		EQU 0x1540
CINEMATIC_019		EQU 0x1800
CINEMATIC_020		EQU 0x1854
CINEMATIC_ENDING_ALIEN_DISSOLVE_F0		EQU 0x1968
CINEMATIC_ENDING_ALIEN_DISSOLVE_F1		EQU 0x18A8
CINEMATIC_ENDING_ALIEN_DISSOLVE_F2		EQU 0x190A
CINEMATIC_024		EQU 0x16C4
CINEMATIC_ENDING_ALIEN_STANDING		EQU 0x163C
CINEMATIC_ENDING_ALIEN_WALK_F0		EQU 0x1A88
CINEMATIC_ENDING_ALIEN_WALK_F1		EQU 0x1B48
CINEMATIC_ENDING_ALIEN_WALK_F2		EQU 0x1C10
CINEMATIC_ENDING_ALIEN_WALK_F3		EQU 0x1CC8
CINEMATIC_ENDING_ALIEN_WALK_F4		EQU 0x1D80
CINEMATIC_ENDING_ALIEN_WALK_F5		EQU 0x1E38
CINEMATIC_ENDING_ALIEN_LIFT_F0		EQU 0x1F4C
CINEMATIC_ENDING_ALIEN_LIFT_F1		EQU 0x2004
CINEMATIC_ENDING_ALIEN_LIFT_F2		EQU 0x20CC
CINEMATIC_ENDING_ALIEN_LIFT_F3		EQU 0x2194
CINEMATIC_ENDING_ALIEN_LIFT_F4		EQU 0x2258
CINEMATIC_ENDING_ALIEN_LIFT_F5		EQU 0x23C0
CINEMATIC_038		EQU 0x2758
CINEMATIC_039		EQU 0x290A
CINEMATIC_040		EQU 0x267E
CINEMATIC_041		EQU 0x29C8
CINEMATIC_042		EQU 0x29E4
CINEMATIC_043		EQU 0x2A24
CINEMATIC_044		EQU 0x2A64
CINEMATIC_045		EQU 0x2AB4
CINEMATIC_046		EQU 0x2B1C
CINEMATIC_047		EQU 0x2B88
CINEMATIC_048		EQU 0x2BC8
CINEMATIC_049		EQU 0x2C08
CINEMATIC_050		EQU 0x2C58
CINEMATIC_051		EQU 0x2CC0
CINEMATIC_052		EQU 0x3F60
CINEMATIC_053		EQU 0x3F04
CINEMATIC_054		EQU 0x3E4C
CINEMATIC_055		EQU 0x3D8C
CINEMATIC_056		EQU 0x3DEC
CINEMATIC_057		EQU 0x3EA8
CINEMATIC_ENDING_LEDGE_SWELL		EQU 0x4AE0
CINEMATIC_PTERANODON_LEG_DANGLE_F0		EQU 0x4D76
CINEMATIC_PTERANODON_LEG_DANGLE_F1		EQU 0x4D92
CINEMATIC_PTERANODON_LEG_DANGLE_F2		EQU 0x4DAE
CINEMATIC_PTERANODON_LEG_DANGLE_F3		EQU 0x4DCA
CINEMATIC_PTERANODON_LEG_DANGLE_F4		EQU 0x4DE6
CINEMATIC_PTERANODON_LEG_DANGLE_F5		EQU 0x4E02
CINEMATIC_PTERANODON_LEG_DANGLE_F6		EQU 0x4E1E
CINEMATIC_PTERANODON_RIDER		EQU 0x35F8
CINEMATIC_067		EQU 0x49DC
CINEMATIC_068		EQU 0x47D4
CINEMATIC_069		EQU 0x48D8
CINEMATIC_ENDING_THE_END_CAPTION		EQU 0x4D6A
CINEMATIC_PTERANODON_HEAD_RAISE_F0		EQU 0x46E8
CINEMATIC_PTERANODON_HEAD_RAISE_F1		EQU 0x46A8
CINEMATIC_PTERANODON_HEAD_RAISE_F2		EQU 0x4668
CINEMATIC_PTERANODON_HEAD_RAISED		EQU 0x4654
CINEMATIC_PTERANODON_WING_RIGHT_F0		EQU 0x3ACC
CINEMATIC_PTERANODON_WING_RIGHT_F1		EQU 0x3B18
CINEMATIC_PTERANODON_WING_RIGHT_F2		EQU 0x3B64
CINEMATIC_PTERANODON_WING_RIGHT_F3		EQU 0x3BAC
CINEMATIC_PTERANODON_WING_RIGHT_F4		EQU 0x3C00
CINEMATIC_PTERANODON_WING_RIGHT_F5		EQU 0x3C58
CINEMATIC_PTERANODON_WING_RIGHT_F6		EQU 0x3CA0
CINEMATIC_PTERANODON_WING_RIGHT_F7		EQU 0x3CEC
CINEMATIC_PTERANODON_WING_RIGHT_F8		EQU 0x3D38
CINEMATIC_PTERANODON_WING_RIGHT_F9		EQU 0x3A7C
CINEMATIC_PTERANODON_WING_RIGHT_F10		EQU 0x3A2C
CINEMATIC_PTERANODON_WING_LEFT_F0		EQU 0x36D4
CINEMATIC_PTERANODON_WING_LEFT_F1		EQU 0x38B0
CINEMATIC_PTERANODON_WING_LEFT_F2		EQU 0x3814
CINEMATIC_PTERANODON_WING_LEFT_F3		EQU 0x385C
CINEMATIC_PTERANODON_WING_LEFT_F4		EQU 0x3720
CINEMATIC_PTERANODON_WING_LEFT_F5		EQU 0x38FC
CINEMATIC_PTERANODON_WING_LEFT_F6		EQU 0x3778
CINEMATIC_PTERANODON_WING_LEFT_F7		EQU 0x3994
CINEMATIC_PTERANODON_WING_LEFT_F8		EQU 0x39E0
CINEMATIC_PTERANODON_WING_LEFT_F9		EQU 0x3944
CINEMATIC_PTERANODON_WING_LEFT_F10		EQU 0x37C4
CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F0		EQU 0x42A4
CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F1		EQU 0x42E8
CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F2		EQU 0x432C
CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F3		EQU 0x4370
CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F0		EQU 0x3FE0
CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F1		EQU 0x408C
CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F2		EQU 0x4138
CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F3		EQU 0x41E4
CINEMATIC_ENDING_CLOSEUP_ZOOM_TARGET		EQU 0x43CC
CINEMATIC_PTERANODON_BEAK_OPEN_F0		EQU 0x4728
CINEMATIC_PTERANODON_BEAK_OPEN_F1		EQU 0x477E
CINEMATIC_108		EQU 0x000C
CV_1B14		EQU 0x1B14
CV_181C		EQU 0x181C
CV_1A84		EQU 0x1A84
CV_1866		EQU 0x1866
CV_18B0		EQU 0x18B0
CV_1AB4		EQU 0x1AB4
CV_18FA		EQU 0x18FA
CV_1AE4		EQU 0x1AE4
CV_1944		EQU 0x1944
CV_198E		EQU 0x198E
CV_1B44		EQU 0x1B44
CV_19C4		EQU 0x19C4
CV_1B74		EQU 0x1B74
CV_1A0E		EQU 0x1A0E
CV_1BA4		EQU 0x1BA4
CV_1D78		EQU 0x1D78
CV_1BD4		EQU 0x1BD4
CV_1D9A		EQU 0x1D9A
CV_1DBC		EQU 0x1DBC
CV_1DDE		EQU 0x1DDE
CV_1E00		EQU 0x1E00
CV_1E22		EQU 0x1E22
CV_1E44		EQU 0x1E44
CV_1E66		EQU 0x1E66
CV_1A54		EQU 0x1A54
CV_4346		EQU 0x4346
CV_1C78		EQU 0x1C78


	org 0x0000

ENTRY_POINT_OF_ENDING:
	call CLEAR_PAGES_1_2_AND_BLIT
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_00
	mov [PAUSE_SLICES], 0x0004
	break
	song id=0x0000, delay=0x0000, pos=0x00
	call ENDING_RESOURCE_PRELOAD
	call LIKELY_A_COPY_PROTECTION_MECHANISM
	setup channel=0x1E, address=ENDING_DRAW_STARS_BG_PLAY_SOUND_08
	killChannel
	copyVideoPage src=0x00, dst=0x03
	killChannel
	copyVideoPage src=0x03, dst=0x00
