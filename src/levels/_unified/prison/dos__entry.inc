; Unified source for PRISON with 256 folded shared bodies.
;
; Folded routines (in byte-address order):
;   DELAY_4_QUANTUMS  (2-arm: amiga, dos)
;   PRELOAD_PRISON_RESOURCES  (2-arm: amiga, dos)
;   BANK4_AFTER_CIN_414  (2-arm: amiga, dos)
;   DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB  (2-arm: amiga, dos)
;   INLINE_SET_VAR03_TO_7  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8  (2-arm: cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DRAW_CIN_311_THEN_CIN_314  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_313_2F_AT_6BB0E3FE  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_1550824C  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_26843400  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_2A88A18A  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_76F1E2F4  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_A6494EF7  (2-arm: amiga, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   DRAW_CIN_316_TO_316_2F_AT_A17C45BF  (2-arm: amiga, dos)
;   DRAW_CIN_319_TO_319_4F_AT_9E666694  (2-arm: amiga, dos)
;   DRAW_CIN_318_TO_318_2F_AT_93A8CE70  (2-arm: amiga, dos)
;   INLINE_SET_VARE6_TO_50  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE7_TO_5  (3-arm: amiga, cart, dos)
;   INIT_VARS_E7_E8  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE9_TO_8  (3-arm: amiga, cart, dos)
;   DRAW_CIN_154_TO_156_3F_AT_A74B7DB1  (2-arm: amiga, dos)
;   DRAW_CIN_151_TO_153_3F_AT_40D20636  (2-arm: amiga, dos)
;   DRAW_CIN_149_TO_150_2F_AT_F63AB95D  (2-arm: amiga, dos)
;   DRAW_CIN_132_TO_133_2F_AT_BB9185F0  (2-arm: amiga, dos)
;   DRAW_CIN_280_TO_281_2F_AT_75ED3E60  (2-arm: amiga, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_146_TO_147_4F_AT_8AA18039  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (3-arm: amiga, cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   DRAW_BUDDY_FIGURE_BASE  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARF1_TO_64  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_28  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR08_INIT_VAR29  (3-arm: amiga, cart, dos)
;   SET_VAR29_TO_000A  (3-arm: amiga, cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR29_BY_1  (3-arm: amiga, cart, dos)
;   BIT_EXTRACT_FROM_VAR24_TO_VAR25  (3-arm: amiga, cart, dos)
;   DRAW_CIN_569_TO_572_6F_AT_F8680E45  (2-arm: amiga, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001A  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_3  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_B2_2F_29  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_0009  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001B  (3-arm: amiga, cart, dos)
;   INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   PRISON_SHOT_BEAM_SINGLE_DOT  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   RET_THEN_KILL_CHANNEL  (2-arm: cart, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_LEFT  (2-arm: amiga, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   PRISON_SCREEN_02_BACKDROP_DRAW  (2-arm: amiga, dos)
;   PRISON_SCREEN_03_BACKDROP_DRAW  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_PAINT_BACKDROP  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_EYELID_FULLY_RAISED  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_BUDDY_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_HERO_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_157  (2-arm: amiga, dos)
;   DRAW_CIN_168  (2-arm: amiga, dos)
;   DRAW_CIN_169  (2-arm: amiga, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F13  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F05  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   PRISON_DRAW_HERO_RUN_LEFT_BODY_F09  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   STEP_VAR1A_DOWN5_VAR1B_UP2  (3-arm: amiga, cart, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_01  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_02  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_03  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_04  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_05  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_06  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_FROM_07  (2-arm: amiga, dos)
;   PRISON_CAGE_SWING_POSE_FROM_07_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_1  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_2  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_3  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_4  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_5  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_6  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_LEFT_LIMIT  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y  (3-arm: amiga, cart, dos)
;   RESET_HERO_POS_UP_DOWN  (2-arm: cart, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_TELEPORT_UP_BEAM_RIGHT  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_DOWN_BEAM_RIGHT  (2-arm: amiga, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   ADD_VAR43_VAR47_BY_20  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_FF_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_PAGE3_TO_PAGE0  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_PAGE_FF  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   WALK_LEFT_DRAW_CV140_MULTISTEP  (2-arm: cart, dos)
;   PRISON_HERO_WALK_LEFT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   PRISON_HERO_WALK_RIGHT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   DRAW_CIN_187_TO_222_2F_AT_8E66E193  (2-arm: amiga, dos)
;   DRAW_CIN_212_TO_213_2F_AT_6B0D0A47  (2-arm: amiga, dos)

; Unified source for PRISON with 256 folded shared bodies.
;
; Folded routines (in byte-address order):
;   DELAY_4_QUANTUMS  (2-arm: amiga, dos)
;   PRELOAD_PRISON_RESOURCES  (2-arm: amiga, dos)
;   BANK4_AFTER_CIN_414  (2-arm: amiga, dos)
;   DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB  (2-arm: amiga, dos)
;   INLINE_SET_VAR03_TO_7  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8  (2-arm: cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DRAW_CIN_311_THEN_CIN_314  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_313_2F_AT_6BB0E3FE  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_1550824C  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_26843400  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_2A88A18A  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_76F1E2F4  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_A6494EF7  (2-arm: amiga, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   DRAW_CIN_316_TO_316_2F_AT_A17C45BF  (2-arm: amiga, dos)
;   DRAW_CIN_319_TO_319_4F_AT_9E666694  (2-arm: amiga, dos)
;   DRAW_CIN_318_TO_318_2F_AT_93A8CE70  (2-arm: amiga, dos)
;   INLINE_SET_VARE6_TO_50  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE7_TO_5  (3-arm: amiga, cart, dos)
;   INIT_VARS_E7_E8  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE9_TO_8  (3-arm: amiga, cart, dos)
;   DRAW_CIN_154_TO_156_3F_AT_A74B7DB1  (2-arm: amiga, dos)
;   DRAW_CIN_151_TO_153_3F_AT_40D20636  (2-arm: amiga, dos)
;   DRAW_CIN_149_TO_150_2F_AT_F63AB95D  (2-arm: amiga, dos)
;   DRAW_CIN_132_TO_133_2F_AT_BB9185F0  (2-arm: amiga, dos)
;   DRAW_CIN_280_TO_281_2F_AT_75ED3E60  (2-arm: amiga, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_146_TO_147_4F_AT_8AA18039  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (3-arm: amiga, cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   DRAW_BUDDY_FIGURE_BASE  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARF1_TO_64  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_28  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR08_INIT_VAR29  (3-arm: amiga, cart, dos)
;   SET_VAR29_TO_000A  (3-arm: amiga, cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR29_BY_1  (3-arm: amiga, cart, dos)
;   BIT_EXTRACT_FROM_VAR24_TO_VAR25  (3-arm: amiga, cart, dos)
;   DRAW_CIN_569_TO_572_6F_AT_F8680E45  (2-arm: amiga, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001A  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_3  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_B2_2F_29  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_0009  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001B  (3-arm: amiga, cart, dos)
;   INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   PRISON_SHOT_BEAM_SINGLE_DOT  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   RET_THEN_KILL_CHANNEL  (2-arm: cart, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_LEFT  (2-arm: amiga, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   PRISON_SCREEN_02_BACKDROP_DRAW  (2-arm: amiga, dos)
;   PRISON_SCREEN_03_BACKDROP_DRAW  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_PAINT_BACKDROP  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_EYELID_FULLY_RAISED  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_BUDDY_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_HERO_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_157  (2-arm: amiga, dos)
;   DRAW_CIN_168  (2-arm: amiga, dos)
;   DRAW_CIN_169  (2-arm: amiga, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F13  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F05  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   PRISON_DRAW_HERO_RUN_LEFT_BODY_F09  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   STEP_VAR1A_DOWN5_VAR1B_UP2  (3-arm: amiga, cart, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_01  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_02  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_03  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_04  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_05  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_06  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_FROM_07  (2-arm: amiga, dos)
;   PRISON_CAGE_SWING_POSE_FROM_07_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_1  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_2  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_3  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_4  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_5  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_6  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_LEFT_LIMIT  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y  (3-arm: amiga, cart, dos)
;   RESET_HERO_POS_UP_DOWN  (2-arm: cart, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_TELEPORT_UP_BEAM_RIGHT  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_DOWN_BEAM_RIGHT  (2-arm: amiga, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   ADD_VAR43_VAR47_BY_20  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_FF_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_PAGE3_TO_PAGE0  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_PAGE_FF  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   WALK_LEFT_DRAW_CV140_MULTISTEP  (2-arm: cart, dos)
;   PRISON_HERO_WALK_LEFT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   PRISON_HERO_WALK_RIGHT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   DRAW_CIN_187_TO_222_2F_AT_8E66E193  (2-arm: amiga, dos)
;   DRAW_CIN_212_TO_213_2F_AT_6B0D0A47  (2-arm: amiga, dos)

; Unified source for PRISON with 238 folded shared bodies.
;
; Folded routines (in byte-address order):
;   DELAY_4_QUANTUMS  (2-arm: amiga, dos)
;   PRELOAD_PRISON_RESOURCES  (2-arm: amiga, dos)
;   BANK4_AFTER_CIN_414  (2-arm: amiga, dos)
;   DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB  (2-arm: amiga, dos)
;   INLINE_SET_VAR03_TO_7  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8  (2-arm: cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DRAW_CIN_311_THEN_CIN_314  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_313_2F_AT_6BB0E3FE  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_1550824C  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_26843400  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_2A88A18A  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_76F1E2F4  (2-arm: amiga, dos)
;   DRAW_CIN_311_TO_312_2F_AT_A6494EF7  (2-arm: amiga, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   DRAW_CIN_316_TO_316_2F_AT_A17C45BF  (2-arm: amiga, dos)
;   DRAW_CIN_319_TO_319_4F_AT_9E666694  (2-arm: amiga, dos)
;   DRAW_CIN_318_TO_318_2F_AT_93A8CE70  (2-arm: amiga, dos)
;   INLINE_SET_VARE6_TO_50  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE7_TO_5  (3-arm: amiga, cart, dos)
;   INIT_VARS_E7_E8  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE9_TO_8  (3-arm: amiga, cart, dos)
;   DRAW_CIN_154_TO_156_3F_AT_A74B7DB1  (2-arm: amiga, dos)
;   DRAW_CIN_151_TO_153_3F_AT_40D20636  (2-arm: amiga, dos)
;   DRAW_CIN_149_TO_150_2F_AT_F63AB95D  (2-arm: amiga, dos)
;   DRAW_CIN_132_TO_133_2F_AT_BB9185F0  (2-arm: amiga, dos)
;   DRAW_CIN_280_TO_281_2F_AT_75ED3E60  (2-arm: amiga, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_146_TO_147_4F_AT_8AA18039  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (3-arm: amiga, cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   DRAW_BUDDY_FIGURE_BASE  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_5  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_28  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR08_INIT_VAR29  (3-arm: amiga, cart, dos)
;   SET_VAR29_TO_000A  (3-arm: amiga, cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR29_BY_1  (3-arm: amiga, cart, dos)
;   BIT_EXTRACT_FROM_VAR24_TO_VAR25  (3-arm: amiga, cart, dos)
;   DRAW_CIN_569_TO_572_6F_AT_F8680E45  (2-arm: amiga, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001A  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_3  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_B2_2F_29  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_0009  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001B  (3-arm: amiga, cart, dos)
;   INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   PRISON_SHOT_BEAM_SINGLE_DOT  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_BLAST_FINAL_FRAME_LEFT  (2-arm: amiga, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   PRISON_SCREEN_02_BACKDROP_DRAW  (2-arm: amiga, dos)
;   PRISON_SCREEN_03_BACKDROP_DRAW  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_PAINT_BACKDROP  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_EYELID_FULLY_RAISED  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_BUDDY_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_PRISON_HERO_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_157  (2-arm: amiga, dos)
;   DRAW_CIN_168  (2-arm: amiga, dos)
;   DRAW_CIN_169  (2-arm: amiga, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F13  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F05  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   PRISON_DRAW_HERO_RUN_LEFT_BODY_F09  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_01  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_02  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_03  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_04  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_05  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_06  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_FROM_07  (2-arm: amiga, dos)
;   PRISON_CAGE_SWING_POSE_FROM_07_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_1  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_2  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_3  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_4  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_5  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_MINUS_6  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_HERO_PUMP_POSE_TILT_LEFT_LIMIT  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_UP_BEAM_RIGHT  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_DOWN_BEAM_RIGHT  (2-arm: amiga, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   ADD_VAR43_VAR47_BY_20  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_FF_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_PAGE3_TO_PAGE0  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_PAGE_FF  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   WALK_LEFT_DRAW_CV140_MULTISTEP  (2-arm: cart, dos)
;   PRISON_HERO_WALK_LEFT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   PRISON_HERO_WALK_RIGHT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   DRAW_CIN_187_TO_222_2F_AT_8E66E193  (2-arm: amiga, dos)
;   DRAW_CIN_212_TO_213_2F_AT_6B0D0A47  (2-arm: amiga, dos)

; Unified source for PRISON with 205 folded shared bodies.
;
; Folded routines (in byte-address order):
;   INLINE_SET_VAR03_TO_7  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8  (2-arm: cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DRAW_CIN_311_THEN_CIN_314  (2-arm: amiga, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   INLINE_SET_VARE6_TO_50  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE7_TO_5  (3-arm: amiga, cart, dos)
;   INIT_VARS_E7_E8  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE9_TO_8  (3-arm: amiga, cart, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (3-arm: amiga, cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARF1_TO_64  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_28  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR08_INIT_VAR29  (3-arm: amiga, cart, dos)
;   SET_VAR29_TO_000A  (3-arm: amiga, cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR29_BY_1  (3-arm: amiga, cart, dos)
;   BIT_EXTRACT_FROM_VAR24_TO_VAR25  (3-arm: amiga, cart, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001A  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_3  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_B2_2F_29  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_0009  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001B  (3-arm: amiga, cart, dos)
;   INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   RET_THEN_KILL_CHANNEL  (2-arm: cart, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_1  (2-arm: amiga, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_BUDDY_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_HERO_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_157  (2-arm: amiga, dos)
;   DRAW_CIN_168  (2-arm: amiga, dos)
;   DRAW_CIN_169  (2-arm: amiga, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F13  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F05  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   PRISON_DRAW_HERO_RUN_LEFT_BODY_F09  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   STEP_VAR1A_DOWN5_VAR1B_UP2  (3-arm: amiga, cart, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_SWING_POSE_FROM_07_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y  (3-arm: amiga, cart, dos)
;   RESET_HERO_POS_UP_DOWN  (2-arm: cart, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_TELEPORT_UP_BEAM_RIGHT  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_DOWN_BEAM_RIGHT  (2-arm: amiga, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   ADD_VAR43_VAR47_BY_20  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_FF_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_PAGE3_TO_PAGE0  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_PAGE_FF  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   WALK_LEFT_DRAW_CV140_MULTISTEP  (2-arm: cart, dos)
;   PRISON_HERO_WALK_LEFT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   PRISON_HERO_WALK_RIGHT_TURN_PRELUDE  (3-arm: amiga, cart, dos)

; Unified source for PRISON with 205 folded shared bodies.
;
; Folded routines (in byte-address order):
;   INLINE_SET_VAR03_TO_7  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8  (2-arm: cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DRAW_CIN_311_THEN_CIN_314  (2-arm: amiga, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   INLINE_SET_VARE6_TO_50  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE7_TO_5  (3-arm: amiga, cart, dos)
;   INIT_VARS_E7_E8  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE9_TO_8  (3-arm: amiga, cart, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (3-arm: amiga, cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR29_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARF1_TO_64  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   INLINE_SET_VAR29_TO_28  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR08_INIT_VAR29  (3-arm: amiga, cart, dos)
;   SET_VAR29_TO_000A  (3-arm: amiga, cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR29_BY_1  (3-arm: amiga, cart, dos)
;   BIT_EXTRACT_FROM_VAR24_TO_VAR25  (3-arm: amiga, cart, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001A  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_3  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_B2_2F_29  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_0009  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001B  (3-arm: amiga, cart, dos)
;   INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   RET_THEN_KILL_CHANNEL  (2-arm: cart, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_4  (2-arm: amiga, dos)
;   PRISON_SHOT_HIT_BURST_LEFT_FRAME_1  (2-arm: amiga, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_BUDDY_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_PRISON_BUDDY_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_PRISON_HERO_POSE_0_0  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_0_3  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_1  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_2  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_3  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_PRISON_HERO_POSE_5  (2-arm: amiga, dos)
;   DRAW_CIN_157  (2-arm: amiga, dos)
;   DRAW_CIN_168  (2-arm: amiga, dos)
;   DRAW_CIN_169  (2-arm: amiga, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F13  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_HERO_WALK_LEFT_F05  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0F_V2A_C0  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   PRISON_DRAW_HERO_RUN_LEFT_BODY_F09  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   STEP_VAR1A_DOWN5_VAR1B_UP2  (3-arm: amiga, cart, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_SWING_POSE_FROM_07_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE  (2-arm: amiga, dos)
;   PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y  (3-arm: amiga, cart, dos)
;   RESET_HERO_POS_UP_DOWN  (2-arm: cart, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   PRISON_DRAW_TELEPORT_UP_BEAM_RIGHT  (2-arm: amiga, dos)
;   PRISON_DRAW_TELEPORT_DOWN_BEAM_RIGHT  (2-arm: amiga, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   ADD_VAR43_VAR47_BY_20  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_FF_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_PAGE3_TO_PAGE0  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_PAGE_FF  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   WALK_LEFT_DRAW_CV140_MULTISTEP  (2-arm: cart, dos)
;   PRISON_HERO_WALK_LEFT_TURN_PRELUDE  (3-arm: amiga, cart, dos)
;   PRISON_HERO_WALK_RIGHT_TURN_PRELUDE  (3-arm: amiga, cart, dos)

; Unified source for PRISON with 5 folded shared bodies.
;
; Folded routines (in byte-address order):
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)

; Unified source for PRISON with 12 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_PRISON_RESOURCES  (2-arm: amiga, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)

; Unified source for PRISON with 12 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_PRISON_RESOURCES  (2-arm: amiga, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   DRAW_CIN_315_PROGRESSIVE  (2-arm: amiga, dos)
;   DRAW_CIN_284_BLOCK_95B  (2-arm: amiga, dos)
;   DRAW_CIN_137_138_BLOCK  (2-arm: amiga, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   DRAW_CIN_406_408_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_570_574_BLOCK  (2-arm: amiga, dos)
;   DRAW_CIN_576_578_BLOCK  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)

; Generated by AnotherWorld_VMTools
CINEMATIC_000		EQU 0x99DA
CINEMATIC_001		EQU 0x99C4
CINEMATIC_002		EQU 0x99AE
CINEMATIC_003		EQU 0x9998
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F0		EQU 0x9896
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F1		EQU 0x96AA
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F2		EQU 0x96FA
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F3		EQU 0x970A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F4		EQU 0x9722
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F5		EQU 0x973A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F6		EQU 0x9752
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F7		EQU 0x976A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F8		EQU 0x9782
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F9		EQU 0x979A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F0		EQU 0x98A2
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F1		EQU 0x94CA
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F2		EQU 0x950E
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F3		EQU 0x952A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F4		EQU 0x955A
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F5		EQU 0x9596
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F6		EQU 0x95C6
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F7		EQU 0x9602
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F8		EQU 0x963E
CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F9		EQU 0x967A
CINEMATIC_PRISON_WALL_RUBBLE_0		EQU 0x9012
CINEMATIC_PRISON_WALL_RUBBLE_1		EQU 0x9380
CINEMATIC_PRISON_WALL_RUBBLE_2		EQU 0x9364
CINEMATIC_PRISON_WALL_RUBBLE_3		EQU 0x9076
CINEMATIC_PRISON_WALL_RUBBLE_4		EQU 0x9136
CINEMATIC_029		EQU 0x9248
CINEMATIC_PRISON_WALL_PILLAR		EQU 0x4AAE
CINEMATIC_PRISON_GRATING_STRIP		EQU 0x57D8
CINEMATIC_PRISON_WALL_HIGHLIGHTS		EQU 0x4CA0
CINEMATIC_PRISON_WALL_SHADOW_BANDS		EQU 0x9414
CINEMATIC_PRISON_WALL_CORNER_SHADOW		EQU 0x88EE
CINEMATIC_PRISON_CAGE_BUDDY_SEATED		EQU 0x23B4
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_LEFT_LIMIT		EQU 0x210E
CINEMATIC_PRISON_CAGE_BARS_TILT_LEFT_LIMIT		EQU 0x165E
CINEMATIC_PRISON_CAGE_HERO_TILT_LEFT_LIMIT		EQU 0x1D2E
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_6		EQU 0x20E8
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_6		EQU 0x15D2
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_6		EQU 0x1D08
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_5		EQU 0x208E
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_5		EQU 0x1546
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_5		EQU 0x1CC6
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_4		EQU 0x2068
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_4		EQU 0x14BA
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_4		EQU 0x1CA0
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_3		EQU 0x2002
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_3		EQU 0x1442
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_3		EQU 0x1C7A
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_2		EQU 0x1FDC
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_2		EQU 0x13B6
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_2		EQU 0x1C54
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_1		EQU 0x1F42
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_1		EQU 0x132A
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_1		EQU 0x1C2E
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_FROM_07		EQU 0x1F1C
CINEMATIC_PRISON_CAGE_BARS_TILT_FROM_07		EQU 0x129E
CINEMATIC_PRISON_CAGE_HERO_TILT_FROM_07		EQU 0x1C08
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_6		EQU 0x1EF6
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_6		EQU 0x1212
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_6		EQU 0x1BE2
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_5		EQU 0x1E90
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_5		EQU 0x1186
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_5		EQU 0x1B9C
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_4		EQU 0x1E6A
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_4		EQU 0x10FA
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_4		EQU 0x1B76
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_3		EQU 0x1E04
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_3		EQU 0x106E
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_3		EQU 0x1B50
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_2		EQU 0x1DDE
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_2		EQU 0x0FE2
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_2		EQU 0x1B2A
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_1		EQU 0x1D54
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_1		EQU 0x0F56
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_1		EQU 0x1B04
CINEMATIC_078		EQU 0x1ADE
CINEMATIC_079		EQU 0x0EDA
CINEMATIC_PRISON_CAGE_LANDING_F0		EQU 0x264C
CINEMATIC_PRISON_CAGE_LANDING_F1		EQU 0x26C0
CINEMATIC_PRISON_CAGE_LANDING_F2		EQU 0x5730
CINEMATIC_PRISON_CAGE_LANDING_F3		EQU 0x2760
CINEMATIC_PRISON_CAGE_LANDING_F4		EQU 0x27D8
CINEMATIC_PRISON_GRAVEL_TILE_0		EQU 0xA1AC
CINEMATIC_PRISON_GRAVEL_TILE_1		EQU 0xA1F0
CINEMATIC_PRISON_DEBRIS_SHARDS_0		EQU 0xA8BC
CINEMATIC_PRISON_DEBRIS_SHARDS_1		EQU 0xA9C4
CINEMATIC_PRISON_DEBRIS_SHARDS_2		EQU 0xAAEC
CINEMATIC_PRISON_LIFT_LANDING_VAULT_HALF_0		EQU 0xC968
CINEMATIC_PRISON_LIFT_LANDING_VAULT_HALF_1		EQU 0xCFFC
CINEMATIC_PRISON_LIFT_LANDING_COLUMN		EQU 0x8E56
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_3		EQU 0x6E5A
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_2		EQU 0x6E2E
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_1		EQU 0x6E02
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_0		EQU 0x6DD6
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_0		EQU 0x6CE2
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_1		EQU 0x6D26
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_2		EQU 0x6D52
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_3		EQU 0x6D7E
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_4		EQU 0x6DAA
CINEMATIC_PRISON_LIFT_HERO_SILHOUETTE		EQU 0x8E5E
CINEMATIC_PRISON_LIFT_CAR_FLOOR		EQU 0x8E7E
CINEMATIC_PRISON_LIFT_LANDING_SLOPE		EQU 0xD044
CINEMATIC_105		EQU 0x841E
CINEMATIC_PRISON_LIFT_LANDING_WALL_PANEL		EQU 0x6CC2
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F0		EQU 0x84BA
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F1		EQU 0x84CE
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F2		EQU 0x84E2
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F3		EQU 0x84F6
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F4		EQU 0x850A
CINEMATIC_PRISON_TRACER_BURST_RIGHT_F5		EQU 0x851E
CINEMATIC_PRISON_TRACER_BURST_LEFT_F0		EQU 0x8442
CINEMATIC_PRISON_TRACER_BURST_LEFT_F1		EQU 0x8456
CINEMATIC_PRISON_TRACER_BURST_LEFT_F2		EQU 0x846A
CINEMATIC_PRISON_TRACER_BURST_LEFT_F3		EQU 0x847E
CINEMATIC_PRISON_TRACER_BURST_LEFT_F4		EQU 0x8492
CINEMATIC_PRISON_TRACER_BURST_LEFT_F5		EQU 0x84A6
CINEMATIC_PRISON_GREEN_TRACER_F0		EQU 0x864A
CINEMATIC_PRISON_GREEN_TRACER_F1		EQU 0x8678
CINEMATIC_PRISON_GREEN_TRACER_F2		EQU 0x8680
CINEMATIC_PRISON_GREEN_TRACER_F3		EQU 0x868E
CINEMATIC_PRISON_GREEN_TRACER_F4		EQU 0x869A
CINEMATIC_PRISON_GREEN_TRACER_F5		EQU 0x86A2
CINEMATIC_PRISON_GREEN_TRACER_F6		EQU 0x86AA
CINEMATIC_PRISON_GREEN_TRACER_F7		EQU 0x86B2
CINEMATIC_127		EQU 0xD092
CINEMATIC_128		EQU 0x8DBA
CINEMATIC_129		EQU 0x8D0A
CINEMATIC_PRISON_LIFT_CAR_BODY		EQU 0xD07E
CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE		EQU 0x9AF0
CINEMATIC_132		EQU 0x860A
CINEMATIC_133		EQU 0x8622
CINEMATIC_HERO_DEATH_KNEELING_LEFT_F0		EQU 0xAC9C
CINEMATIC_HERO_DEATH_KNEELING_LEFT_F1		EQU 0xAD0C
CINEMATIC_HERO_DEATH_KNEELING_LEFT_F2		EQU 0xAD9E
CINEMATIC_BLAST_MARK		EQU 0x7964
CINEMATIC_BLAST_DEBRIS_F0		EQU 0x7898
CINEMATIC_BLAST_DEBRIS_F1		EQU 0x7978
CINEMATIC_BLAST_DEBRIS_F2		EQU 0x7A04
CINEMATIC_BLAST_DEBRIS_SETTLED_0		EQU 0x7A7C
CINEMATIC_BLAST_DEBRIS_F3		EQU 0x7AA4
CINEMATIC_BLAST_DEBRIS_F4		EQU 0x7AE0
CINEMATIC_BLAST_DEBRIS_F5		EQU 0x7B34
CINEMATIC_BLAST_DEBRIS_SETTLED_1		EQU 0x7B74
CINEMATIC_HERO_DEATH_STANDING_RIGHT_F0		EQU 0x57F8
CINEMATIC_HERO_DEATH_STANDING_RIGHT_F1		EQU 0x5874
CINEMATIC_HERO_DEATH_STANDING_RIGHT_F2		EQU 0x5964
CINEMATIC_149		EQU 0x85DA
CINEMATIC_150		EQU 0x85F2
CINEMATIC_151		EQU 0x8592
CINEMATIC_152		EQU 0x85AA
CINEMATIC_153		EQU 0x85C2
CINEMATIC_154		EQU 0x854A
CINEMATIC_155		EQU 0x8562
CINEMATIC_156		EQU 0x857A
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_7_1		EQU 0xBEEC
CINEMATIC_158		EQU 0x8A76
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_4_1		EQU 0xBEBE
CINEMATIC_160		EQU 0x4270
CINEMATIC_161		EQU 0x4230
CINEMATIC_162		EQU 0x4218
CINEMATIC_163		EQU 0x41DC
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_0		EQU 0x17FA
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_1		EQU 0xB710
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_2		EQU 0xB738
CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_3		EQU 0xB760
CINEMATIC_PRISON_FIGURE_BELT_RIGHT		EQU 0xC408
CINEMATIC_169		EQU 0xC440
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_00		EQU 0x4062
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_00_CHARGE_BLINK		EQU 0x89FE
CINEMATIC_PRISON_GUN_ON_GROUND		EQU 0x8E4A
CINEMATIC_PRISON_GUN_CLOSEUP_BACKDROP_0		EQU 0xBD9C
CINEMATIC_PRISON_GUN_CLOSEUP_BACKDROP_1		EQU 0xBD78
CINEMATIC_THE_GUN		EQU 0xBCDC
CINEMATIC_PRISON_GUN_INDICATOR_DARK		EQU 0xBE90
CINEMATIC_PRISON_GUN_INDICATOR_LIT		EQU 0xBE7C
CINEMATIC_LESTER_HAND_GRABBING_GUN_F0		EQU 0xB7E4
CINEMATIC_LESTER_HAND_GRABBING_GUN_F1		EQU 0xB8E0
CINEMATIC_LESTER_HAND_GRABBING_GUN_F2		EQU 0xB94C
CINEMATIC_LESTER_HAND_GRABBING_GUN_F3		EQU 0xB9A0
CINEMATIC_LESTER_HAND_GRABBING_GUN_F4		EQU 0xBA1C
CINEMATIC_LESTER_HAND_GRABBING_GUN_F5		EQU 0xBB00
CINEMATIC_LESTER_HAND_GRABBING_GUN_F6		EQU 0xBBDA
CINEMATIC_LESTER_HAND_GRABBING_GUN_F7		EQU 0xBC70
CINEMATIC_186		EQU 0x0068
CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT		EQU 0x0B6E
CINEMATIC_PRISON_HERO_CROUCH_SHOOT_LEFT_F1		EQU 0x402E
CINEMATIC_PRISON_HERO_CROUCH_SHOOT_LEFT_F0		EQU 0x3FFA
CINEMATIC_ACTOR_CHARGE_GLOW_F1		EQU 0x5D9C
CINEMATIC_ACTOR_CHARGE_GLOW_F2		EQU 0x5DC8
CINEMATIC_ACTOR_CHARGE_GLOW_F3		EQU 0x5DF8
CINEMATIC_ACTOR_CHARGE_GLOW_F4		EQU 0x5E2C
CINEMATIC_ACTOR_CHARGE_GLOW_F5		EQU 0x5E60
CINEMATIC_ACTOR_CHARGE_GLOW_F6		EQU 0x5E6C
CINEMATIC_196		EQU 0x4DEC
CINEMATIC_197		EQU 0x4E00
CINEMATIC_198		EQU 0x4E14
CINEMATIC_199		EQU 0x4E8E
CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_3		EQU 0x4E80
CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_2		EQU 0x4E48
CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_0		EQU 0x5D34
CINEMATIC_ACTOR_CHARGE_GLOW_F0		EQU 0x5D60
CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_1		EQU 0x5D90
CINEMATIC_PRISON_HERO_STAND_ARMED_LEFT		EQU 0x0B92
CINEMATIC_PRISON_HERO_CROUCH_AIM_RIGHT		EQU 0x3C82
CINEMATIC_PRISON_HERO_CROUCH_AIM_RIGHT_CHARGE_DOT		EQU 0x89A6
CINEMATIC_PRISON_HERO_CROUCH_SHOOT_RIGHT_F0		EQU 0x3DBC
CINEMATIC_PRISON_HERO_CROUCH_SHOOT_RIGHT_F1		EQU 0x3DF0
CINEMATIC_210		EQU 0x4E2C
CINEMATIC_PRISON_HERO_STAND_ARMED_RIGHT		EQU 0x0938
CINEMATIC_PRISON_HERO_CROUCH_DOWN_RIGHT		EQU 0x08D4
CINEMATIC_PRISON_HERO_LUNGE_RIGHT		EQU 0x0988
CINEMATIC_214		EQU 0x0CD2
CINEMATIC_215		EQU 0x0870
CINEMATIC_216		EQU 0x8B4A
CINEMATIC_217		EQU 0x8AF2
CINEMATIC_218		EQU 0x8AAE
CINEMATIC_219		EQU 0x8CFA
CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F09		EQU 0x3BB4
CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10		EQU 0x3BBE
CINEMATIC_PRISON_HERO_LUNGE_LEFT		EQU 0x0DBA
CINEMATIC_223		EQU 0x0D96
CINEMATIC_PRISON_HERO_CROUCH_LEFT		EQU 0x0B4A
CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_0		EQU 0xBF36
CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_1		EQU 0xBF8C
CINEMATIC_PRISON_FIGURE_POSE_LEFT_6_ANY		EQU 0x53E0
CINEMATIC_PRISON_FIGURE_POSE_LEFT_5_ANY		EQU 0x531E
CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_1		EQU 0xD114
CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_OTHER		EQU 0x4338
CINEMATIC_PRISON_FIGURE_POSE_LEFT_3_ANY		EQU 0x4304
CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_1		EQU 0xD0E8
CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_OTHER		EQU 0x42EC
CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_1		EQU 0xD0AC
CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_OTHER		EQU 0x42B0
CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_0		EQU 0x2E6A
CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_1		EQU 0xBF64
CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_2		EQU 0xC5D2
CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_3		EQU 0xC5EC
CINEMATIC_PRISON_FIGURE_BELT_LEFT		EQU 0xC4FA
CINEMATIC_241		EQU 0xC4DE
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_02		EQU 0x41B0
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_02_CHARGE_BLINK		EQU 0x89C6
CINEMATIC_244		EQU 0xC994
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_13		EQU 0xC9EC
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_13		EQU 0xCA04
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_12		EQU 0xCC94
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_12		EQU 0xCA54
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_11		EQU 0xCCFC
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_11		EQU 0xCAF4
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_10		EQU 0xCDCC
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_10		EQU 0xCA2C
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_9		EQU 0xCCC8
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_9		EQU 0xCA7C
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_8		EQU 0xCD30
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_8		EQU 0xCACC
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_7		EQU 0xCD98
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_7		EQU 0xCAA4
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_6		EQU 0xCD64
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_6		EQU 0xCB1C
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_5		EQU 0xCE00
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_5		EQU 0xCB6C
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4		EQU 0xCF78
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_4		EQU 0xCB94
CINEMATIC_265		EQU 0xCFAC
CINEMATIC_266		EQU 0xCBBC
CINEMATIC_267		EQU 0xCEDC
CINEMATIC_268		EQU 0xCBE4
CINEMATIC_269		EQU 0xCF10
CINEMATIC_270		EQU 0xCC0C
CINEMATIC_271		EQU 0xCF44
CINEMATIC_272		EQU 0xCB44
CINEMATIC_273		EQU 0xCE34
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5		EQU 0x5700
CINEMATIC_275		EQU 0x9A20
CINEMATIC_276		EQU 0xC262
CINEMATIC_277		EQU 0xC17E
CINEMATIC_278		EQU 0xC194
CINEMATIC_279		EQU 0x0038
CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F0		EQU 0x59A0
CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F1		EQU 0x5A28
CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F2		EQU 0x5AEA
CINEMATIC_283		EQU 0x5B22
CINEMATIC_TUMBLING_CHUNK_F0		EQU 0x5B56
CINEMATIC_TUMBLING_CHUNK_F1		EQU 0x5B96
CINEMATIC_TUMBLING_CHUNK_F2		EQU 0x5B9E
CINEMATIC_TUMBLING_CHUNK_F3		EQU 0x5BA6
CINEMATIC_TUMBLING_CHUNK_F4		EQU 0x5BAE
CINEMATIC_TUMBLING_CHUNK_F5		EQU 0x5BB6
CINEMATIC_TUMBLING_CHUNK_F6		EQU 0x5BBE
CINEMATIC_TUMBLING_CHUNK_F7		EQU 0x5BC6
CINEMATIC_TUMBLING_CHUNK_F8		EQU 0x5BCE
CINEMATIC_TUMBLING_CHUNK_F9		EQU 0x5BD6
CINEMATIC_TUMBLING_CHUNK_F10		EQU 0x5BDE
CINEMATIC_TUMBLING_CHUNK_F11		EQU 0x5BE6
CINEMATIC_TUMBLING_CHUNK_F12		EQU 0x5C02
CINEMATIC_TUMBLING_CHUNK_F13		EQU 0x5C0A
CINEMATIC_HERO_DEATH_STANDING_LEFT_F0		EQU 0xAB94
CINEMATIC_HERO_DEATH_STANDING_LEFT_F1		EQU 0xABF8
CINEMATIC_HERO_DEATH_STANDING_LEFT_F2		EQU 0xAC60
CINEMATIC_301		EQU 0xC19C
CINEMATIC_302		EQU 0xC1A6
CINEMATIC_303		EQU 0xC1B2
CINEMATIC_304		EQU 0xC1BE
CINEMATIC_PRISON_CELLBLOCK_FLOOR		EQU 0x4D12
CINEMATIC_PRISON_SCREEN_02_BACKDROP_LAYER_1		EQU 0x9930
CINEMATIC_PRISON_SCREEN_02_BACKDROP_LAYER_2		EQU 0xA5D6
CINEMATIC_PRISON_SCREEN_02_BACKDROP_LAYER_3		EQU 0x9E60
CINEMATIC_PRISON_SCREEN_02_BACKDROP_LAYER_4		EQU 0xA052
CINEMATIC_310		EQU 0xC37E
CINEMATIC_311		EQU 0xC2AE
CINEMATIC_312		EQU 0xC362
CINEMATIC_313		EQU 0xC356
CINEMATIC_314		EQU 0xC34A
CINEMATIC_315		EQU 0xA79A
CINEMATIC_316		EQU 0xA7A6
CINEMATIC_317		EQU 0xA790
CINEMATIC_318		EQU 0xA77C
CINEMATIC_319		EQU 0xA786
CINEMATIC_320		EQU 0xA6EE
CINEMATIC_321		EQU 0xA706
CINEMATIC_322		EQU 0xA71E
CINEMATIC_323		EQU 0xA750
CINEMATIC_324		EQU 0xA72A
CINEMATIC_325		EQU 0xA73A
CINEMATIC_326		EQU 0xA6B8
CINEMATIC_327		EQU 0x0050
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_1		EQU 0x99F0
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_2		EQU 0x9BD8
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_3		EQU 0xA658
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_4		EQU 0xA67C
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_5		EQU 0x9BF4
CINEMATIC_PRISON_SCREEN_03_BACKDROP_LAYER_6		EQU 0xC732
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_01		EQU 0x40B4
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_01_CHARGE_BLINK		EQU 0x8A06
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_02		EQU 0x4106
CINEMATIC_PRISON_CV_FIGURE_GUN_UPPER_RIGHT_POSE_02_CHARGE_BLINK		EQU 0x8A0E
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_01		EQU 0x4184
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_01_CHARGE_BLINK		EQU 0x89BE
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_00		EQU 0x4158
CINEMATIC_PRISON_CV_FIGURE_GUN_LIMB_LEFT_POSE_00_CHARGE_BLINK		EQU 0x89B6
CINEMATIC_342		EQU 0x4A4A
CINEMATIC_343		EQU 0x5F4A
CINEMATIC_344		EQU 0x89CE
CINEMATIC_345		EQU 0x5F82
CINEMATIC_346		EQU 0x89D6
CINEMATIC_347		EQU 0x5FBA
CINEMATIC_348		EQU 0x89DE
CINEMATIC_349		EQU 0x60CA
CINEMATIC_350		EQU 0x5FE2
CINEMATIC_351		EQU 0x440A
CINEMATIC_352		EQU 0xC476
CINEMATIC_353		EQU 0x8A16
CINEMATIC_354		EQU 0x9AD8
CINEMATIC_355		EQU 0x4468
CINEMATIC_356		EQU 0x8A1E
CINEMATIC_357		EQU 0x9AE4
CINEMATIC_358		EQU 0x5042
CINEMATIC_359		EQU 0x8A26
CINEMATIC_360		EQU 0x6226
CINEMATIC_PRISON_SEGMENT_BAR_F0		EQU 0x80A6
CINEMATIC_PRISON_SEGMENT_BAR_F1		EQU 0x8158
CINEMATIC_PRISON_SEGMENT_BAR_F2		EQU 0x816E
CINEMATIC_PRISON_SEGMENT_BAR_F3		EQU 0x8186
CINEMATIC_XRAY_FLASH_LEFT		EQU 0xADDE
CINEMATIC_XRAY_SKELETON_LEFT_LIT		EQU 0xAE56
CINEMATIC_FALLING_DEBRIS_F0		EQU 0x7B94
CINEMATIC_FALLING_DEBRIS_F1		EQU 0x7C54
CINEMATIC_FALLING_DEBRIS_F2		EQU 0x7CE4
CINEMATIC_FALLING_DEBRIS_F3		EQU 0x7D74
CINEMATIC_FALLING_DEBRIS_F4		EQU 0x7E00
CINEMATIC_FALLING_DEBRIS_F5		EQU 0x7E80
CINEMATIC_FALLING_DEBRIS_F6		EQU 0x7EE8
CINEMATIC_FALLING_DEBRIS_F7		EQU 0x7F48
CINEMATIC_XRAY_SKELETON_LEFT_DARK		EQU 0xAEEE
CINEMATIC_XRAY_FLASH_RIGHT		EQU 0x6AA8
CINEMATIC_XRAY_SKELETON_RIGHT_LIT		EQU 0x6B20
CINEMATIC_XRAY_SKELETON_RIGHT_DARK		EQU 0x6C1E
CINEMATIC_379		EQU 0xC3DA
CINEMATIC_PRISON_DISCHARGE_FLASH_F0		EQU 0x80D4
CINEMATIC_PRISON_DISCHARGE_FLASH_F1		EQU 0x812C
CINEMATIC_PRISON_CHARGE_GLOW_F0		EQU 0x8100
CINEMATIC_PRISON_CHARGE_GLOW_F1		EQU 0x81E6
CINEMATIC_PRISON_CHARGE_BLAST		EQU 0x875A
CINEMATIC_PRISON_CHARGE_GLOW_F2		EQU 0x819E
CINEMATIC_PRISON_CHARGE_GLOW_F3		EQU 0x81CA
CINEMATIC_387		EQU 0x88A6
CINEMATIC_388		EQU 0x8876
CINEMATIC_BUDDY_HACKING_SECURITY_DOOR		EQU 0x4976
CINEMATIC_390		EQU 0x450A
CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F0		EQU 0xA274
CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F0		EQU 0xA7B2
CINEMATIC_PRISON_BUDDY_FIGURE_BASE		EQU 0xA7D2
CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F1		EQU 0xA27C
CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F2		EQU 0xA284
CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F1		EQU 0xA7BA
CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F3		EQU 0xA2C0
CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F2		EQU 0xA7C2
CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F3		EQU 0xA7CA
CINEMATIC_400		EQU 0xA2F8
CINEMATIC_401		EQU 0xA31C
CINEMATIC_402		EQU 0xA368
CINEMATIC_403		EQU 0xA374
CINEMATIC_404		EQU 0xA34C
CINEMATIC_405		EQU 0xBF1C
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F0		EQU 0xA380
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F1		EQU 0xA3C0
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F2		EQU 0xA3FC
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3		EQU 0xA420
CINEMATIC_410		EQU 0xC00E
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F4		EQU 0xA444
CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F5		EQU 0xA4A4
CINEMATIC_413		EQU 0xC068
CINEMATIC_414		EQU 0x68D4
CINEMATIC_415		EQU 0xBFEC
CINEMATIC_416		EQU 0xB408
CINEMATIC_417		EQU 0xC110
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F00		EQU 0x629C
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F01		EQU 0x6338
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F02		EQU 0x63D0
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F03		EQU 0x6460
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F04		EQU 0x64E4
CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F05		EQU 0x6950
CINEMATIC_424		EQU 0xB6D4
CINEMATIC_425		EQU 0xB6F2
CINEMATIC_PRISON_FIGURE_CROUCHED_F0		EQU 0xC6DA
CINEMATIC_PRISON_FIGURE_CROUCHED_F1		EQU 0xC6F4
CINEMATIC_PRISON_CELL_BLOCK_GIRDERS		EQU 0xA84C
CINEMATIC_PRISON_CELL_BLOCK_DEBRIS		EQU 0xAAB4
CINEMATIC_PRISON_CELL_BLOCK_FLOOR		EQU 0xA7FA
CINEMATIC_PRISON_CELL_ROW_BARS		EQU 0xA560
CINEMATIC_PRISON_SCREEN_04_BACKDROP_LAYER_13		EQU 0xA4D8
CINEMATIC_PRISON_SCREEN_04_BACKDROP_LAYER_14		EQU 0xA688
CINEMATIC_PRISON_SCREEN_23_BACKDROP_LAYER_8		EQU 0xB092
CINEMATIC_PRISON_SCREEN_23_BACKDROP_LAYER_9		EQU 0xC076
CINEMATIC_PRISON_SCREEN_23_BACKDROP_LAYER_10		EQU 0xC62A
CINEMATIC_PRISON_SCREEN_23_BACKDROP_LAYER_11		EQU 0xC696
CINEMATIC_PRISON_BUDDY_RISE_F0		EQU 0x8A2E
CINEMATIC_PRISON_BUDDY_RISE_F1		EQU 0x2A88
CINEMATIC_PRISON_BUDDY_RISE_F2		EQU 0x2AE8
CINEMATIC_PRISON_BUDDY_ARM_TAP		EQU 0x8BAE
CINEMATIC_442		EQU 0x8BEA
CINEMATIC_443		EQU 0x8C32
CINEMATIC_444		EQU 0x8C7E
CINEMATIC_445		EQU 0x87A2
CINEMATIC_446		EQU 0x87DE
CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT		EQU 0x882A
CINEMATIC_PRISON_SCREEN_24_BACKDROP_LAYER_8		EQU 0xAF9E
CINEMATIC_PRISON_SCREEN_24_BACKDROP_LAYER_9		EQU 0xB26C
CINEMATIC_PRISON_SCREEN_24_BACKDROP_LAYER_10		EQU 0xB2CC
CINEMATIC_PRISON_SCREEN_24_BACKDROP_LAYER_11		EQU 0xB364
CINEMATIC_452		EQU 0x73C6
CINEMATIC_453		EQU 0x5C62
CINEMATIC_454		EQU 0xC09C
CINEMATIC_455		EQU 0x0074
CINEMATIC_456		EQU 0x0020
CINEMATIC_457		EQU 0x0098
CINEMATIC_ENERGY_TRANSMISSION_LINE		EQU 0xB788
CINEMATIC_459		EQU 0xC0BC
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_0		EQU 0x7092
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_1		EQU 0x70AA
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_2		EQU 0x70C2
CINEMATIC_CHARGED_BLAST_SWEEP_NEAR		EQU 0x705E
CINEMATIC_PRISON_SHOT_IMPACT_8		EQU 0x7FAC
CINEMATIC_PRISON_SHOT_IMPACT_7		EQU 0x7828
CINEMATIC_PRISON_SHOT_IMPACT_6		EQU 0x7810
CINEMATIC_PRISON_SHOT_IMPACT_5		EQU 0x77F4
CINEMATIC_PRISON_SHOT_IMPACT_4		EQU 0x77D8
CINEMATIC_PRISON_SHOT_IMPACT_3		EQU 0x77B0
CINEMATIC_PRISON_SHOT_IMPACT_2		EQU 0x778C
CINEMATIC_PRISON_SHOT_IMPACT_1		EQU 0x8016
CINEMATIC_PRISON_SHOT_IMPACT_0		EQU 0x783C
CINEMATIC_PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT		EQU 0x76B6
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_7		EQU 0x7696
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_6		EQU 0x7650
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_5		EQU 0x75E4
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_4		EQU 0x758E
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_3		EQU 0x753E
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_2		EQU 0x74EE
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_1		EQU 0x747A
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_0		EQU 0x7418
CINEMATIC_482		EQU 0x739E
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_0		EQU 0x72E6
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_1		EQU 0x7302
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_2		EQU 0x731E
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_3		EQU 0x733E
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_4		EQU 0x735A
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_5		EQU 0x736E
CINEMATIC_PRISON_SHOT_BLAST_FINAL_FRAME_LEFT		EQU 0xB6BA
CINEMATIC_PRISON_SHOT_BLAST_LEFT_7		EQU 0xB69A
CINEMATIC_PRISON_SHOT_BLAST_LEFT_6		EQU 0xB654
CINEMATIC_PRISON_SHOT_BLAST_LEFT_5		EQU 0xB5E8
CINEMATIC_PRISON_SHOT_BLAST_LEFT_4		EQU 0xB592
CINEMATIC_PRISON_SHOT_BLAST_LEFT_3		EQU 0xB542
CINEMATIC_PRISON_SHOT_BLAST_LEFT_2		EQU 0xB4F2
CINEMATIC_PRISON_SHOT_BLAST_LEFT_1		EQU 0xB4A2
CINEMATIC_PRISON_SHOT_BLAST_LEFT_0		EQU 0xB47C
CINEMATIC_498		EQU 0xB430
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_0		EQU 0x70DA
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_1		EQU 0x710E
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_2		EQU 0x712A
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_3		EQU 0x714A
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_4		EQU 0x7166
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_5		EQU 0x717A
CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT		EQU 0x4D5E
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_0		EQU 0x4D72
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_0		EQU 0x7FD0
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_1		EQU 0x4D86
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_1		EQU 0x7FD8
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_2		EQU 0x4D9A
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_2		EQU 0x7FE0
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_3		EQU 0x4DAE
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_3		EQU 0x7FE8
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_4		EQU 0x4DC2
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_4		EQU 0x7FF0
CINEMATIC_516		EQU 0x800C
CINEMATIC_517		EQU 0x8002
CINEMATIC_518		EQU 0x9A38
CINEMATIC_519		EQU 0x9A40
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_5		EQU 0x4DD6
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_5		EQU 0x7FF8
CINEMATIC_522		EQU 0x719E
CINEMATIC_SHIELD_DECAY_PHASE_2_CASE_01		EQU 0x7256
CINEMATIC_SHIELD_DECAY_PHASE_3		EQU 0x4EDA
CINEMATIC_525		EQU 0x71D6
CINEMATIC_526		EQU 0x720A
CINEMATIC_SHIELD_DECAY_PHASE_3_DEFAULT		EQU 0x4E9A
CINEMATIC_SHIELD_DECAY_PHASE_3_CASE_01		EQU 0x4EBA
CINEMATIC_SHIELD_DECAY_PHASE_2_DEFAULT		EQU 0x723A
CINEMATIC_SHIELD_DECAY_PHASE_2		EQU 0x726E
CINEMATIC_SHIELD_DECAY_PHASE_1_DEFAULT		EQU 0x7286
CINEMATIC_PRISON_SHIELD_DECAY_PHASE_1_CASE_01		EQU 0x729A
CINEMATIC_SHIELD_DECAY_PHASE_1		EQU 0x72AC
CINEMATIC_SHIELD_DECAY_PHASE_0_DEFAULT		EQU 0x72BC
CINEMATIC_PRISON_SHIELD_DECAY_PHASE_0_CASE_01		EQU 0x72C8
CINEMATIC_SHIELD_DECAY_PHASE_0		EQU 0x72DA
CINEMATIC_537		EQU 0x5CBE
CINEMATIC_538		EQU 0x5C76
CINEMATIC_539		EQU 0x5CA6
CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F0		EQU 0x2820
CINEMATIC_PRISON_FLEXING_BAND_F0		EQU 0x2A6C
CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F1		EQU 0x2870
CINEMATIC_PRISON_FLEXING_BAND_F1		EQU 0x2A50
CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F2		EQU 0x2850
CINEMATIC_PRISON_FLEXING_BAND_F2		EQU 0x2A34
CINEMATIC_PRISON_FLEXING_BAND_F3		EQU 0x2A18
CINEMATIC_PRISON_FLEXING_BAND_F4		EQU 0x2A10
CINEMATIC_PRISON_FLEXING_BAND_F5		EQU 0x2A08
CINEMATIC_PRISON_CAGE_WRECK_AT_REST		EQU 0x5770
CINEMATIC_TELEPORT_DOWN_BEAM_RIGHT		EQU 0x4FFE
CINEMATIC_TELEPORT_DOWN_BEAM_LEFT		EQU 0x8216
CINEMATIC_TELEPORT_UP_BEAM_RIGHT		EQU 0x4FBA
CINEMATIC_TELEPORT_UP_BEAM_LEFT		EQU 0x8202
CINEMATIC_554		EQU 0x8CD6
CINEMATIC_555		EQU 0x0380
CINEMATIC_PRISON_HERO_STAND_LEFT		EQU 0x0BB6
CINEMATIC_557		EQU 0x0B26
CINEMATIC_PRISON_HERO_STAND_SHOOT_LEFT_F1		EQU 0x3E38
CINEMATIC_PRISON_HERO_STAND_SHOOT_LEFT_F0		EQU 0x3FB4
CINEMATIC_PRISON_HERO_ARM_OUT_LEFT		EQU 0x0AFC
CINEMATIC_PRISON_HERO_STAND_RIGHT		EQU 0x0D0A
CINEMATIC_562		EQU 0x084C
CINEMATIC_HERO_STAND_AIM_RIGHT		EQU 0x3D3A
CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT_CHARGE_DOT		EQU 0x89AE
CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F1		EQU 0x3BF0
CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F0		EQU 0x3D76
CINEMATIC_PRISON_HERO_ARM_OUT_RIGHT		EQU 0x07DA
CINEMATIC_HERO_LIFTOFF		EQU 0x041C
CINEMATIC_PRISON_BACKGROUND_DOORWAY_BACKDROP		EQU 0x9902
CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F0		EQU 0x5414
CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F3		EQU 0x5562
CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST		EQU 0x554E
CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F4		EQU 0x55F2
CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F2		EQU 0x54E4
CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F1		EQU 0x54A4
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F0		EQU 0x564C
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F1		EQU 0x5670
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F2		EQU 0x5698
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F3		EQU 0x56C4
CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F4		EQU 0x56E8
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_7		EQU 0x22A8
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_6		EQU 0x2294
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_5		EQU 0x2280
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_4		EQU 0x226C
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_3		EQU 0x2258
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_2		EQU 0x2244
CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_1		EQU 0x2230
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_7		EQU 0x221C
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_6		EQU 0x2208
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_5		EQU 0x21F4
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_4		EQU 0x21E0
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_3		EQU 0x21CC
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_2		EQU 0x21B8
CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_1		EQU 0x21A4
CINEMATIC_PRISON_CAGE_CHAIN_TILT_ZERO		EQU 0x2190
CINEMATIC_PRISON_CLOAKED_FIGURE_F0		EQU 0x4526
CINEMATIC_PRISON_CLOAKED_FIGURE_F1		EQU 0x4552
CINEMATIC_PRISON_CLOAKED_FIGURE_F2		EQU 0x46E6
CINEMATIC_PRISON_CLOAKED_FIGURE_F3		EQU 0x456E
CINEMATIC_PRISON_CLOAKED_FIGURE_F4		EQU 0x4702
CINEMATIC_PRISON_CLOAKED_FIGURE_F5		EQU 0x458A
CINEMATIC_PRISON_CLOAKED_FIGURE_F6		EQU 0x45DE
CINEMATIC_PRISON_CLOAKED_FIGURE_F7		EQU 0x461A
CINEMATIC_PRISON_CLOAKED_FIGURE_F8		EQU 0x4752
CINEMATIC_PRISON_CLOAKED_FIGURE_F9		EQU 0x4766
CINEMATIC_PRISON_CLOAKED_FIGURE_F10		EQU 0x4652
CINEMATIC_PRISON_CLOAKED_FIGURE_F11		EQU 0x477A
CINEMATIC_PRISON_CLOAKED_FIGURE_F12		EQU 0x4666
CINEMATIC_PRISON_CLOAKED_FIGURE_F13		EQU 0x47B6
CINEMATIC_PRISON_CLOAKED_FIGURE_F14		EQU 0x47F6
CINEMATIC_PRISON_CLOAKED_FIGURE_F15		EQU 0x46A6
CINEMATIC_PRISON_CLOAKED_FIGURE_F16		EQU 0x487A
CINEMATIC_PRISON_CLOAKED_FIGURE_F17		EQU 0x48CA
CINEMATIC_PRISON_CLOAKED_FIGURE_F18		EQU 0x492A
CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F0		EQU 0x5262
CINEMATIC_PRISON_STANDING_FIGURE_F0		EQU 0x49FA
CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F1		EQU 0x527A
CINEMATIC_PRISON_STANDING_FIGURE_F1		EQU 0x5172
CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F2		EQU 0x5292
CINEMATIC_PRISON_STANDING_FIGURE_F2		EQU 0x51C2
CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F3		EQU 0x52AA
CINEMATIC_PRISON_STANDING_FIGURE_F3		EQU 0x5212
CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F4		EQU 0x52C2
CINEMATIC_PRISON_BAR_PANEL_F0		EQU 0x514C
CINEMATIC_PRISON_BAR_PANEL_F1		EQU 0x512A
CINEMATIC_PRISON_BAR_PANEL_F2		EQU 0x510C
CINEMATIC_PRISON_BAR_PANEL_F3		EQU 0x50DA
CINEMATIC_PRISON_BAR_PANEL_F4		EQU 0x50B4
CINEMATIC_PRISON_FIGURE_ARM_GUN_UP		EQU 0x5356
CINEMATIC_PRISON_SHOT_UP_BEAM_F0		EQU 0x539E
CINEMATIC_PRISON_SHOT_UP_BEAM_F1		EQU 0x53C8
CINEMATIC_PRISON_CV_FIGURE_WALK_LEFT_BODY_F07		EQU 0x2C4C
CINEMATIC_633		EQU 0x4836
CINEMATIC_PRISON_PRISONER_BEHIND_BARS		EQU 0x3756
CINEMATIC_635		EQU 0xC5A6
CINEMATIC_PRISON_CELL_BARS		EQU 0xC58A
CINEMATIC_PRISON_WAKE_FIGURE_NECK_0		EQU 0x34F4
CINEMATIC_PRISON_WAKE_FIGURE_HEAD_0		EQU 0x3444
CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_0		EQU 0x3484
CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_0		EQU 0x34C4
CINEMATIC_PRISON_WAKE_FIGURE_NECK_1		EQU 0x34E0
CINEMATIC_PRISON_WAKE_FIGURE_HEAD_1		EQU 0x3428
CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_1		EQU 0x3460
CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_1		EQU 0x34A8
CINEMATIC_PRISON_WAKE_FIGURE_NECK_2		EQU 0x31F4
CINEMATIC_PRISON_WAKE_FIGURE_HEAD_2		EQU 0x31CC
CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_2		EQU 0x3230
CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_2		EQU 0x3214
CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_0		EQU 0x3508
CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_1		EQU 0x3254
CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_4		EQU 0x3726
CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_3		EQU 0x36AE
CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_2		EQU 0x3634
CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_1		EQU 0x3550
CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_0		EQU 0x351C
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_BASE		EQU 0xC756
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_6		EQU 0x3B9E
CINEMATIC_PRISON_WAKE_CLOSEUP_EYE_GLINT		EQU 0x378E
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_17		EQU 0x3A66
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_16		EQU 0x3A3A
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_15		EQU 0x3A0E
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_14		EQU 0x39E2
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_13		EQU 0x39B6
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_12		EQU 0x398A
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_11		EQU 0x395E
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_10		EQU 0x3932
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_9		EQU 0x3906
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_8		EQU 0x38DA
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_7		EQU 0x38AE
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_6		EQU 0x3882
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_5		EQU 0x3856
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_4		EQU 0x382A
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_3		EQU 0x37FE
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_2		EQU 0x37D2
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_1		EQU 0x37A6
CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_0		EQU 0x379A
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_5		EQU 0x3B92
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_4		EQU 0x3B86
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_3		EQU 0x3B7A
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2		EQU 0x3B6E
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1		EQU 0x3B62
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0		EQU 0x3A92
CINEMATIC_PRISON_WAKE_CLOSEUP_FACE_HALF_0		EQU 0x2EA2
CINEMATIC_PRISON_WAKE_CLOSEUP_FACE_HALF_1		EQU 0x32C0
CINEMATIC_PRISON_WAKE_CLOSEUP_IRIS_STRIATIONS		EQU 0x3782
CINEMATIC_686		EQU 0xC7BA
CINEMATIC_687		EQU 0xC7A2
CINEMATIC_688		EQU 0x44C6
CINEMATIC_689		EQU 0x44FA
CINEMATIC_PRISON_CV_FIGURE_FRONT_STANCE_WIDE		EQU 0x44AA
CINEMATIC_691		EQU 0xC50E
CINEMATIC_692		EQU 0x50A8
CINEMATIC_693		EQU 0x8266
CINEMATIC_PRISON_HERO_CRAWL_POSE_02		EQU 0x6660
CINEMATIC_PRISON_HERO_CRAWL_POSE_01		EQU 0x65E4
CINEMATIC_696		EQU 0x6564
CINEMATIC_697		EQU 0xC562
CINEMATIC_698		EQU 0xC546
CINEMATIC_699		EQU 0xC52A
CINEMATIC_700		EQU 0x88E2
CINEMATIC_701		EQU 0x88B2
CINEMATIC_702		EQU 0x8042
CINEMATIC_703		EQU 0xB3E4
CINEMATIC_704		EQU 0x0320
CINEMATIC_705		EQU 0xD160
CINEMATIC_706		EQU 0xD174
CINEMATIC_707		EQU 0xD188
CINEMATIC_708		EQU 0xD19C
CINEMATIC_709		EQU 0xD1B0
CINEMATIC_710		EQU 0x000C
HERO_WATER_DEPTH_LEFT_CASE_00		EQU 0x5DE4
HERO_STAND_LEFT_ARM		EQU 0x3322
HERO_STAND_LEFT_BODY		EQU 0x0358
HERO_JUMP_RIGHT_F00		EQU 0x4D98
HERO_JUMP_RIGHT_F01		EQU 0x4DE4
HERO_JUMP_RIGHT_F02		EQU 0x4E30
HERO_JUMP_RIGHT_F03		EQU 0x4E7C
HERO_JUMP_RIGHT_F04		EQU 0x4EC8
HERO_JUMP_RIGHT_F05		EQU 0x4F14
HERO_JUMP_RIGHT_F06		EQU 0x4F68
HERO_JUMP_RIGHT_F08		EQU 0x500C
HERO_JUMP_RIGHT_F09		EQU 0x5058
HERO_JUMP_RIGHT_F10		EQU 0x50A8
HERO_JUMP_RIGHT_F11		EQU 0x50F8
HERO_JUMP_RIGHT_F12		EQU 0x514C
HERO_STAND_RIGHT_BODY		EQU 0x0F90
HERO_STAND_RIGHT_ARM		EQU 0x338E
HERO_WALK_RIGHT_BODY_F00		EQU 0x0FF8
HERO_WALK_RIGHT_ARM_F00		EQU 0x3398
HERO_WALK_RIGHT_BODY_F01		EQU 0x1060
HERO_WALK_RIGHT_ARM_F01		EQU 0x33A2
HERO_WALK_RIGHT_BODY_F02		EQU 0x108C
HERO_WALK_RIGHT_ARM_F02		EQU 0x33AC
HERO_WALK_RIGHT_BODY_F03		EQU 0x10B8
HERO_WALK_RIGHT_ARM_F03		EQU 0x33B6
HERO_WALK_RIGHT_BODY_F04		EQU 0x10E4
HERO_WALK_RIGHT_ARM_F04		EQU 0x33C0
HERO_WALK_RIGHT_BODY_F05		EQU 0x1110
HERO_WALK_RIGHT_ARM_F05		EQU 0x33CA
HERO_WALK_RIGHT_BODY_F06		EQU 0x1136
HERO_WALK_RIGHT_ARM_F06		EQU 0x33D4
HERO_WALK_RIGHT_BODY_F07		EQU 0x115C
HERO_WALK_RIGHT_ARM_F07		EQU 0x33DE
HERO_WALK_RIGHT_BODY_F08		EQU 0x117E
HERO_WALK_RIGHT_ARM_F08		EQU 0x33E8
HERO_WALK_RIGHT_BODY_F09		EQU 0x0CBA
HERO_WALK_RIGHT_BODY_F10		EQU 0x0D48
HERO_WALK_RIGHT_BODY_F11		EQU 0x0DB6
HERO_WALK_RIGHT_ARM_F11		EQU 0x3366
HERO_WALK_RIGHT_BODY_F12		EQU 0x0E38
HERO_WALK_RIGHT_ARM_F12		EQU 0x3370
HERO_WALK_RIGHT_BODY_F13		EQU 0x0EB6
HERO_WALK_RIGHT_ARM_F13		EQU 0x337A
HERO_WALK_RIGHT_BODY_F14		EQU 0x0F28
HERO_WALK_RIGHT_ARM_F14		EQU 0x3384
HERO_JUMP_LEFT_F00		EQU 0x52C0
HERO_JUMP_LEFT_F01		EQU 0x52E0
HERO_JUMP_LEFT_F02		EQU 0x5300
HERO_JUMP_LEFT_F03		EQU 0x5320
HERO_JUMP_LEFT_F04		EQU 0x5340
HERO_JUMP_LEFT_F05		EQU 0x5360
HERO_JUMP_LEFT_F06		EQU 0x5380
HERO_JUMP_LEFT_F08		EQU 0x53C0
HERO_JUMP_LEFT_F09		EQU 0x53E0
HERO_JUMP_LEFT_F10		EQU 0x5400
HERO_JUMP_LEFT_F11		EQU 0x5420
HERO_JUMP_LEFT_F12		EQU 0x5444
HERO_WALK_LEFT_ARM_F00		EQU 0x332A
HERO_WALK_LEFT_ARM_F01		EQU 0x3332
HERO_WALK_LEFT_ARM_F02		EQU 0x333A
HERO_WALK_LEFT_ARM_F03		EQU 0x3342
HERO_WALK_LEFT_ARM_F04		EQU 0x334A
HERO_WALK_LEFT_BODY_F05		EQU 0x0814
HERO_WALK_LEFT_BODY_F13		EQU 0x0234
HERO_WALK_LEFT_ARM_F14		EQU 0x331A
HERO_RUN_RIGHT_BODY_F00		EQU 0x03E4
HERO_RUN_RIGHT_ARM_F00		EQU 0x34AA
HERO_RUN_RIGHT_BODY_F01		EQU 0x0472
HERO_RUN_RIGHT_ARM_F01		EQU 0x34B2
HERO_JUMP_RIGHT_F07		EQU 0x4FBC
HERO_RUN_RIGHT_BODY_F05		EQU 0x06A2
HERO_RUN_RIGHT_ARM_F05		EQU 0x34D6
HERO_RUN_RIGHT_BODY_F06		EQU 0x06C8
HERO_RUN_RIGHT_ARM_F06		EQU 0x34DE
HERO_RUN_RIGHT_BODY_F07		EQU 0x06EE
HERO_RUN_RIGHT_ARM_F07		EQU 0x34E6
HERO_RUN_RIGHT_BODY_F08		EQU 0x0714
HERO_RUN_RIGHT_ARM_F08		EQU 0x34EE
HERO_RUN_RIGHT_BODY_F09		EQU 0x073E
HERO_RUN_RIGHT_ARM_F09		EQU 0x34F6
HERO_JUMP_LEFT_F07		EQU 0x53A0
HERO_RUN_LEFT_BODY_F05		EQU 0x150A
HERO_RUN_LEFT_BODY_F09		EQU 0x15A2
HERO_RUN_LEFT_BODY_F00		EQU 0x11B8
HERO_RUN_RIGHT_BODY_F02		EQU 0x04F4
HERO_RUN_RIGHT_ARM_F02		EQU 0x34BA
HERO_RUN_RIGHT_BODY_F03		EQU 0x058E
HERO_RUN_RIGHT_ARM_F03		EQU 0x34C2
HERO_RUN_RIGHT_BODY_F04		EQU 0x0624
HERO_RUN_RIGHT_ARM_F04		EQU 0x34CE
HERO_GUN_ARM_LEFT_CASE_04		EQU 0x3614
HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK		EQU 0x5C8C
HERO_GUN_ARM_LEFT_CASE_03		EQU 0x35F8
HERO_GUN_ARM_LEFT_CASE_02		EQU 0x35D0
HERO_GUN_ARM_LEFT_CASE_01		EQU 0x35B4
HERO_WATER_DEPTH_LEFT_CASE_02		EQU 0x5E44
CV_FIGURE_PROFILE_STANCE		EQU 0x40CA
CV_FIGURE_WALK_RIGHT_UPPER_POSE_03		EQU 0x1B14
CV_5F94		EQU 0x5F94
HERO_CROUCH_AIM_LEFT		EQU 0x39A2
HERO_CROUCH_AIM_LEFT_CHARGE_DOT		EQU 0x5C94
HERO_PRONE_TRANSITION_LEFT_F00		EQU 0x57C4
HERO_PRONE_TRANSITION_LEFT_F01		EQU 0x5878
HERO_PRONE_TRANSITION_LEFT_F02		EQU 0x5944
HERO_PRONE_TRANSITION_LEFT_F03		EQU 0x5A08
HERO_PRONE_TRANSITION_LEFT_F04		EQU 0x5AAC
HERO_PRONE_TRANSITION_LEFT_F05		EQU 0x5B4C
HERO_CRAWL_POSE_10		EQU 0x4754
HERO_CRAWL_POSE_01		EQU 0x485C
HERO_CRAWL_POSE_09		EQU 0x4BC4
HERO_CRAWL_POSE_08		EQU 0x4B4C
HERO_CRAWL_POSE_07		EQU 0x4ACC
HERO_CRAWL_POSE_06		EQU 0x4A6C
HERO_CRAWL_POSE_05		EQU 0x4A04
HERO_CRAWL_POSE_04		EQU 0x49B0
HERO_CRAWL_POSE_02		EQU 0x48D8
HERO_CRAWL_POSE_03		EQU 0x4954
HERO_PRONE_TRANSITION_RIGHT_F04		EQU 0x46D4
HERO_PRONE_TRANSITION_RIGHT_F02		EQU 0x45C0
HERO_PRONE_TRANSITION_RIGHT_F01		EQU 0x4528
HERO_PRONE_TRANSITION_RIGHT_F00		EQU 0x448C
HERO_GUN_ARM_RIGHT_CASE_04		EQU 0x344E
HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK		EQU 0x5C1C
HERO_GUN_ARM_RIGHT_CASE_03		EQU 0x3420
HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK		EQU 0x5C14
HERO_GUN_ARM_RIGHT_CASE_02		EQU 0x33F2
HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK		EQU 0x5C0C
HERO_GUN_ARM_RIGHT_CASE_01		EQU 0x347C
HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK		EQU 0x5BF8
HERO_PRONE_TRANSITION_RIGHT_F03		EQU 0x4650
HERO_PRONE_TRANSITION_RIGHT_F05		EQU 0x4C40
HERO_CRAWL_POSE_00		EQU 0x47DC
CV_FIGURE_PROFILE_STRIDE		EQU 0x40EC
CV_FIGURE_WALK_LEFT_UPPER_POSE_01		EQU 0x2B0E
CV_5FCC		EQU 0x5FCC
CV_FIGURE_WALK_RIGHT_LIMB_POSE_00		EQU 0x247C
CV_FIGURE_WALK_RIGHT_BODY_F00		EQU 0x181C
CV_FIGURE_WALK_RIGHT_UPPER_POSE_00		EQU 0x1A84
CV_5F7C		EQU 0x5F7C
CV_FIGURE_WALK_RIGHT_BODY_F01		EQU 0x1866
CV_FIGURE_WALK_RIGHT_BODY_F02		EQU 0x18B0
CV_FIGURE_WALK_RIGHT_UPPER_POSE_01		EQU 0x1AB4
CV_5F84		EQU 0x5F84
CV_FIGURE_WALK_RIGHT_BODY_F03		EQU 0x18FA
CV_FIGURE_WALK_RIGHT_UPPER_POSE_02		EQU 0x1AE4
CV_5F8C		EQU 0x5F8C
CV_FIGURE_WALK_RIGHT_BODY_F04		EQU 0x1944
CV_FIGURE_WALK_RIGHT_LIMB_POSE_01		EQU 0x2474
CV_FIGURE_WALK_RIGHT_BODY_F05		EQU 0x198E
CV_FIGURE_WALK_RIGHT_UPPER_POSE_04		EQU 0x1B44
CV_5F9C		EQU 0x5F9C
CV_FIGURE_WALK_RIGHT_LIMB_POSE_02		EQU 0x246C
CV_FIGURE_WALK_RIGHT_BODY_F06		EQU 0x19C4
CV_FIGURE_WALK_RIGHT_UPPER_POSE_05		EQU 0x1B74
CV_5FA4		EQU 0x5FA4
CV_FIGURE_WALK_RIGHT_LIMB_POSE_04		EQU 0x245C
CV_FIGURE_WALK_RIGHT_BODY_F07		EQU 0x1A0E
CV_FIGURE_WALK_RIGHT_UPPER_POSE_06		EQU 0x1BA4
CV_5FAC		EQU 0x5FAC
CV_FIGURE_WALK_RIGHT_LIMB_POSE_03		EQU 0x2464
CV_FIGURE_WALK_RIGHT_BODY_F08		EQU 0x1D78
CV_FIGURE_WALK_RIGHT_UPPER_POSE_07		EQU 0x1BD4
CV_5FB4		EQU 0x5FB4
CV_FIGURE_WALK_RIGHT_BODY_F09		EQU 0x1D9A
CV_FIGURE_WALK_RIGHT_BODY_F10		EQU 0x1DBC
CV_FIGURE_WALK_RIGHT_BODY_F11		EQU 0x1DDE
CV_FIGURE_WALK_RIGHT_BODY_F12		EQU 0x1E00
CV_FIGURE_WALK_RIGHT_BODY_F13		EQU 0x1E22
CV_FIGURE_WALK_RIGHT_BODY_F14		EQU 0x1E44
CV_FIGURE_WALK_RIGHT_BODY_F15		EQU 0x1E66
CV_FIGURE_WALK_RIGHT_UPPER_POSE_08		EQU 0x1A54
CV_5F74		EQU 0x5F74
CV_FIGURE_WALK_LEFT_BODY_F00		EQU 0x257A
CV_FIGURE_WALK_LEFT_UPPER_POSE_00		EQU 0x2AC6
CV_5FC4		EQU 0x5FC4
CV_FIGURE_WALK_LEFT_BODY_F01		EQU 0x2610
CV_FIGURE_WALK_LEFT_BODY_F02		EQU 0x2672
CV_FIGURE_WALK_LEFT_BODY_F03		EQU 0x270C
CV_FIGURE_WALK_LEFT_UPPER_POSE_02		EQU 0x2B56
CV_5FD4		EQU 0x5FD4
CV_FIGURE_WALK_LEFT_BODY_F04		EQU 0x2786
CV_FIGURE_WALK_LEFT_UPPER_POSE_03		EQU 0x2B9E
CV_5FDC		EQU 0x5FDC
CV_FIGURE_WALK_LEFT_LIMB_POSE_01		EQU 0x2D66
CV_FIGURE_WALK_LEFT_BODY_F05		EQU 0x27FC
CV_FIGURE_WALK_LEFT_UPPER_POSE_04		EQU 0x2BE6
CV_5FE4		EQU 0x5FE4
CV_FIGURE_WALK_LEFT_LIMB_POSE_02		EQU 0x2D5E
CV_FIGURE_WALK_LEFT_BODY_F06		EQU 0x287E
CV_FIGURE_WALK_LEFT_UPPER_POSE_05		EQU 0x2C2E
CV_5FEC		EQU 0x5FEC
CV_FIGURE_WALK_LEFT_BODY_F07		EQU 0x28F8
CV_FIGURE_WALK_LEFT_UPPER_POSE_06		EQU 0x2C76
CV_5FF4		EQU 0x5FF4
CV_FIGURE_WALK_LEFT_LIMB_POSE_03		EQU 0x2D56
CV_FIGURE_WALK_LEFT_BODY_F08		EQU 0x296E
CV_FIGURE_WALK_LEFT_UPPER_POSE_07		EQU 0x2CBE
CV_5FFC		EQU 0x5FFC
CV_FIGURE_WALK_LEFT_BODY_F09		EQU 0x2990
CV_FIGURE_WALK_LEFT_BODY_F10		EQU 0x29B2
CV_FIGURE_WALK_LEFT_BODY_F11		EQU 0x29D4
CV_FIGURE_WALK_LEFT_BODY_F12		EQU 0x29F6
CV_FIGURE_WALK_LEFT_BODY_F13		EQU 0x2A18
CV_FIGURE_WALK_LEFT_BODY_F14		EQU 0x2A3A
CV_FIGURE_WALK_LEFT_BODY_F15		EQU 0x2A5C
CV_FIGURE_WALK_LEFT_UPPER_POSE_08		EQU 0x2A7E
CV_5FBC		EQU 0x5FBC
CV_FIGURE_RUN_RIGHT_LIMB_POSE_00		EQU 0x2566
CV_FIGURE_RUN_RIGHT_BODY_F00		EQU 0x1F70
CV_FIGURE_RUN_RIGHT_UPPER_POSE_00		EQU 0x6108
CV_FIGURE_RUN_RIGHT_LIMB_POSE_01		EQU 0x255C
CV_FIGURE_RUN_RIGHT_BODY_F01		EQU 0x1FE4
CV_FIGURE_RUN_RIGHT_LIMB_POSE_02		EQU 0x2552
CV_FIGURE_RUN_RIGHT_BODY_F02		EQU 0x2058
CV_FIGURE_RUN_RIGHT_LIMB_POSE_03		EQU 0x2548
CV_FIGURE_RUN_RIGHT_BODY_F03		EQU 0x20B8
CV_FIGURE_RUN_RIGHT_UPPER_POSE_03		EQU 0x2200
CV_2570		EQU 0x2570
CV_FIGURE_RUN_RIGHT_BODY_F04		EQU 0x2134
CV_FIGURE_RUN_RIGHT_UPPER_POSE_04		EQU 0x2212
CV_FIGURE_RUN_RIGHT_BODY_F05		EQU 0x2310
CV_FIGURE_RUN_RIGHT_BODY_F06		EQU 0x232C
CV_FIGURE_RUN_RIGHT_BODY_F07		EQU 0x2348
CV_FIGURE_RUN_RIGHT_BODY_F08		EQU 0x2364
CV_FIGURE_RUN_RIGHT_BODY_F09		EQU 0x2380
CV_FIGURE_RUN_LEFT_BODY_F00		EQU 0x2D76
CV_FIGURE_RUN_LEFT_UPPER_POSE_00		EQU 0x61A2
CV_FIGURE_RUN_LEFT_LIMB_POSE_01		EQU 0x3200
CV_FIGURE_RUN_LEFT_BODY_F01		EQU 0x2E0A
CV_FIGURE_RUN_LEFT_UPPER_POSE_01		EQU 0x3116
CV_FIGURE_RUN_LEFT_LIMB_POSE_02		EQU 0x31F6
CV_FIGURE_RUN_LEFT_BODY_F02		EQU 0x2E9E
CV_FIGURE_RUN_LEFT_UPPER_POSE_02		EQU 0x3124
CV_FIGURE_RUN_LEFT_LIMB_POSE_03		EQU 0x31EC
CV_FIGURE_RUN_LEFT_BODY_F03		EQU 0x2F3A
CV_FIGURE_RUN_LEFT_UPPER_POSE_03		EQU 0x316E
CV_3212		EQU 0x3212
CV_FIGURE_RUN_LEFT_BODY_F04		EQU 0x2FD6
CV_FIGURE_RUN_LEFT_UPPER_POSE_04		EQU 0x3180
CV_FIGURE_RUN_LEFT_BODY_F05		EQU 0x304A
CV_FIGURE_RUN_LEFT_BODY_F06		EQU 0x3066
CV_FIGURE_RUN_LEFT_BODY_F07		EQU 0x3082
CV_FIGURE_RUN_LEFT_UPPER_POSE_05		EQU 0x31A8
CV_FIGURE_RUN_LEFT_BODY_F08		EQU 0x309E
CV_FIGURE_RUN_LEFT_UPPER_POSE_06		EQU 0x31CA
CV_FIGURE_RUN_LEFT_BODY_F09		EQU 0x30BA
CV_FIGURE_CROUCH_FACING_RIGHT		EQU 0x4132
CV_42BA		EQU 0x42BA
CV_4314		EQU 0x4314
CV_FIGURE_CROUCH_FACING_LEFT		EQU 0x3E4E
CV_4324		EQU 0x4324
CV_426C		EQU 0x426C
CV_FIGURE_STAND_BODY		EQU 0x4346
CV_4368		EQU 0x4368
HERO_STAND_AIM_LEFT		EQU 0x3A64
HERO_STAND_AIM_LEFT_CHARGE_DOT		EQU 0x5C9C


	org 0x0000

ENTRY_POINT_OF_PRISON:
	call CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	mov [PAUSE_SLICES], 0x0004
	mov [0xF6], 0x0001
	mov [0x32], 0x0000
	mov [0xB6], 0x0000
	mov [0x0A], 0x0000
	call PRELOAD_PRISON_RESOURCES
	play id=0x0055, freq=0x14, vol=0x00, channel=0x01
	play id=0x0055, freq=0x14, vol=0x00, channel=0x02
	play id=0x0055, freq=0x14, vol=0x00, channel=0x03
	play id=0x0055, freq=0x14, vol=0x00, channel=0x00
	jge [0x00], 0x15, LABEL_0068
	mov [0x00], 0x0014
	jmp LABEL_005F
	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	setup channel=0x16, address=PRISON_HERO_POS_JUMP_DOWN_DISPATCH_CHECK_VAR63
	setup channel=0x0A, address=LABEL_0567
	call LABEL_07D8
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_457, x=0, y=90
	video offset=CINEMATIC_710, x=0, y=182
	killChannel
	killChannel

LABEL_005F:
	setup channel=0x01, address=FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA
	setup channel=0x02, address=LABEL_4F83
	killChannel

LABEL_0068:
	setup channel=0x22, address=LABEL_4CB9
	setup channel=0x23, address=PRISON_FILL_AND_DRAW_CIN_24_28_L0
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4
	setup channel=0x15, address=LABEL_7830
	setup channel=0x00, address=LABEL_1CB0
	call LABEL_1CC1
	killChannel

LIKELY_A_COPY_PROTECTION_MECHANISM:
	mov [0xF8], [0xBC]
	and [0xF8], 0x0010
	je [0xF8], 0x00, LABEL_0095
	jne [0xF2], 0x0FA0, LABEL_0095
	ret


LABEL_0095:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=KILL_CHANNEL_LANDING
	killChannel
