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
;   DRAW_CIN_305_TO_309_5F_AT_AACB4DF5  (2-arm: amiga, dos)
;   DRAW_CIN_305_TO_333_7F_AT_96C7E6A8  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   DRAW_CIN_683_TO_685_3F_AT_1EB7324B  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
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
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV_078  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV_070  (2-arm: cart, dos)
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
;   DRAW_CV_106  (2-arm: cart, dos)
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
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
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
;   DRAW_CIN_305_TO_309_5F_AT_AACB4DF5  (2-arm: amiga, dos)
;   DRAW_CIN_305_TO_333_7F_AT_96C7E6A8  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   DRAW_CIN_683_TO_685_3F_AT_1EB7324B  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
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
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV_078  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV_070  (2-arm: cart, dos)
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
;   DRAW_CV_106  (2-arm: cart, dos)
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
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
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
;   DRAW_CIN_305_TO_309_5F_AT_AACB4DF5  (2-arm: amiga, dos)
;   DRAW_CIN_305_TO_333_7F_AT_96C7E6A8  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   DRAW_CIN_683_TO_685_3F_AT_1EB7324B  (2-arm: amiga, dos)
;   PRISON_WAKE_CLOSEUP_PUPIL_WIDEST  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
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
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV_078  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV_070  (2-arm: cart, dos)
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
;   DRAW_CV_106  (2-arm: cart, dos)
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
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
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
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV_078  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV_070  (2-arm: cart, dos)
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
;   DRAW_CV_106  (2-arm: cart, dos)
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
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
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
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV_078  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV_070  (2-arm: cart, dos)
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
;   DRAW_CV_106  (2-arm: cart, dos)
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
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
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
CINEMATIC_000		EQU 0x9368
CINEMATIC_001		EQU 0x9352
CINEMATIC_002		EQU 0x933C
CINEMATIC_003		EQU 0x9326
CINEMATIC_004		EQU 0x9224
CINEMATIC_005		EQU 0x9038
CINEMATIC_006		EQU 0x9088
CINEMATIC_007		EQU 0x9098
CINEMATIC_008		EQU 0x90B0
CINEMATIC_009		EQU 0x90C8
CINEMATIC_010		EQU 0x90E0
CINEMATIC_011		EQU 0x90F8
CINEMATIC_012		EQU 0x9110
CINEMATIC_013		EQU 0x9128
CINEMATIC_014		EQU 0x9230
CINEMATIC_015		EQU 0x8E58
CINEMATIC_016		EQU 0x8E9C
CINEMATIC_017		EQU 0x8EB8
CINEMATIC_018		EQU 0x8EE8
CINEMATIC_019		EQU 0x8F24
CINEMATIC_020		EQU 0x8F54
CINEMATIC_021		EQU 0x8F90
CINEMATIC_022		EQU 0x8FCC
CINEMATIC_023		EQU 0x9008
CINEMATIC_PRISON_WALL_RUBBLE_0		EQU 0x89A0
CINEMATIC_PRISON_WALL_RUBBLE_1		EQU 0x8D0E
CINEMATIC_PRISON_WALL_RUBBLE_2		EQU 0x8CF2
CINEMATIC_PRISON_WALL_RUBBLE_3		EQU 0x8A04
CINEMATIC_PRISON_WALL_RUBBLE_4		EQU 0x8AC4
CINEMATIC_029		EQU 0x8BD6
CINEMATIC_PRISON_WALL_PILLAR		EQU 0x469C
CINEMATIC_PRISON_GRATING_STRIP		EQU 0x53C6
CINEMATIC_032		EQU 0x488E
CINEMATIC_033		EQU 0x8DA2
CINEMATIC_034		EQU 0x827C
CINEMATIC_035		EQU 0x209A
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_LEFT_LIMIT		EQU 0x1E40
CINEMATIC_PRISON_CAGE_BARS_TILT_LEFT_LIMIT		EQU 0x1468
CINEMATIC_PRISON_CAGE_HERO_TILT_LEFT_LIMIT		EQU 0x1A60
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_6		EQU 0x1E1A
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_6		EQU 0x13DC
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_6		EQU 0x1A3A
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_5		EQU 0x1DC0
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_5		EQU 0x1350
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_5		EQU 0x19F8
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_4		EQU 0x1D9A
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_4		EQU 0x12C4
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_4		EQU 0x19D2
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_3		EQU 0x1D34
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_3		EQU 0x124C
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_3		EQU 0x19AC
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_2		EQU 0x1D0E
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_2		EQU 0x11C0
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_2		EQU 0x1986
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_MINUS_1		EQU 0x1C74
CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_1		EQU 0x1134
CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_1		EQU 0x1960
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_FROM_07		EQU 0x1C4E
CINEMATIC_PRISON_CAGE_BARS_TILT_FROM_07		EQU 0x10A8
CINEMATIC_PRISON_CAGE_HERO_TILT_FROM_07		EQU 0x193A
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_6		EQU 0x1C28
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_6		EQU 0x101C
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_6		EQU 0x1914
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_5		EQU 0x1BC2
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_5		EQU 0x0F90
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_5		EQU 0x18CE
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_4		EQU 0x1B9C
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_4		EQU 0x0F04
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_4		EQU 0x18A8
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_3		EQU 0x1B36
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_3		EQU 0x0E78
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_3		EQU 0x1882
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_2		EQU 0x1B10
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_2		EQU 0x0DEC
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_2		EQU 0x185C
CINEMATIC_PRISON_CAGE_HERO_PUMP_TILT_PLUS_1		EQU 0x1A86
CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_1		EQU 0x0D60
CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_1		EQU 0x1836
CINEMATIC_078		EQU 0x1810
CINEMATIC_079		EQU 0x0CE4
CINEMATIC_080		EQU 0x2332
CINEMATIC_081		EQU 0x23A6
CINEMATIC_082		EQU 0x531E
CINEMATIC_083		EQU 0x2446
CINEMATIC_084		EQU 0x24BE
CINEMATIC_085		EQU 0x9A7E
CINEMATIC_086		EQU 0x9AC2
CINEMATIC_087		EQU 0xA18E
CINEMATIC_088		EQU 0xA296
CINEMATIC_089		EQU 0xA3BE
CINEMATIC_090		EQU 0xC23A
CINEMATIC_091		EQU 0xC8CE
CINEMATIC_092		EQU 0x87E4
CINEMATIC_093		EQU 0x681C
CINEMATIC_094		EQU 0x67F0
CINEMATIC_095		EQU 0x67C4
CINEMATIC_096		EQU 0x6798
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_0		EQU 0x66A4
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_1		EQU 0x66E8
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_2		EQU 0x6714
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_3		EQU 0x6740
CINEMATIC_PRISON_LIFT_SHAFT_STRIP_4		EQU 0x676C
CINEMATIC_102		EQU 0x87EC
CINEMATIC_103		EQU 0x880C
CINEMATIC_104		EQU 0xC916
CINEMATIC_105		EQU 0x7DAC
CINEMATIC_106		EQU 0x6684
CINEMATIC_107		EQU 0x7E48
CINEMATIC_108		EQU 0x7E5C
CINEMATIC_109		EQU 0x7E70
CINEMATIC_110		EQU 0x7E84
CINEMATIC_111		EQU 0x7E98
CINEMATIC_112		EQU 0x7EAC
CINEMATIC_113		EQU 0x7DD0
CINEMATIC_114		EQU 0x7DE4
CINEMATIC_115		EQU 0x7DF8
CINEMATIC_116		EQU 0x7E0C
CINEMATIC_117		EQU 0x7E20
CINEMATIC_118		EQU 0x7E34
CINEMATIC_119		EQU 0x7FD8
CINEMATIC_120		EQU 0x8006
CINEMATIC_121		EQU 0x800E
CINEMATIC_122		EQU 0x801C
CINEMATIC_123		EQU 0x8028
CINEMATIC_124		EQU 0x8030
CINEMATIC_125		EQU 0x8038
CINEMATIC_126		EQU 0x8040
CINEMATIC_127		EQU 0xC964
CINEMATIC_128		EQU 0x8748
CINEMATIC_129		EQU 0x8698
CINEMATIC_130		EQU 0xC950
CINEMATIC_131		EQU 0x93EE
CINEMATIC_132		EQU 0x7F98
CINEMATIC_133		EQU 0x7FB0
CINEMATIC_134		EQU 0xA56E
CINEMATIC_135		EQU 0xA5DE
CINEMATIC_136		EQU 0xA670
CINEMATIC_137		EQU 0x7326
CINEMATIC_138		EQU 0x725A
CINEMATIC_139		EQU 0x733A
CINEMATIC_140		EQU 0x73C6
CINEMATIC_141		EQU 0x743E
CINEMATIC_142		EQU 0x7466
CINEMATIC_143		EQU 0x74A2
CINEMATIC_144		EQU 0x74F6
CINEMATIC_145		EQU 0x7536
CINEMATIC_146		EQU 0x53E6
CINEMATIC_147		EQU 0x5462
CINEMATIC_148		EQU 0x5552
CINEMATIC_149		EQU 0x7F68
CINEMATIC_150		EQU 0x7F80
CINEMATIC_151		EQU 0x7F20
CINEMATIC_152		EQU 0x7F38
CINEMATIC_153		EQU 0x7F50
CINEMATIC_154		EQU 0x7ED8
CINEMATIC_155		EQU 0x7EF0
CINEMATIC_156		EQU 0x7F08
CINEMATIC_157		EQU 0xB7BE
CINEMATIC_158		EQU 0x8404
CINEMATIC_159		EQU 0xB790
CINEMATIC_160		EQU 0x3E7E
CINEMATIC_161		EQU 0x3E3E
CINEMATIC_162		EQU 0x3E26
CINEMATIC_163		EQU 0x3DEA
CINEMATIC_164		EQU 0x1604
CINEMATIC_165		EQU 0xAFE2
CINEMATIC_166		EQU 0xB00A
CINEMATIC_167		EQU 0xB032
CINEMATIC_168		EQU 0xBCDA
CINEMATIC_169		EQU 0xBD12
CINEMATIC_170		EQU 0x3C70
CINEMATIC_171		EQU 0x838C
CINEMATIC_172		EQU 0x87D8
CINEMATIC_173		EQU 0xB66E
CINEMATIC_174		EQU 0xB64A
CINEMATIC_THE_GUN		EQU 0xB5AE
CINEMATIC_176		EQU 0xB762
CINEMATIC_177		EQU 0xB74E
CINEMATIC_LESTER_HAND_GRABBING_GUN_F0		EQU 0xB0B6
CINEMATIC_LESTER_HAND_GRABBING_GUN_F1		EQU 0xB1B2
CINEMATIC_LESTER_HAND_GRABBING_GUN_F2		EQU 0xB21E
CINEMATIC_LESTER_HAND_GRABBING_GUN_F3		EQU 0xB272
CINEMATIC_LESTER_HAND_GRABBING_GUN_F4		EQU 0xB2EE
CINEMATIC_LESTER_HAND_GRABBING_GUN_F5		EQU 0xB3D2
CINEMATIC_LESTER_HAND_GRABBING_GUN_F6		EQU 0xB4AC
CINEMATIC_LESTER_HAND_GRABBING_GUN_F7		EQU 0xB542
CINEMATIC_186		EQU 0x0068
CINEMATIC_187		EQU 0x0AD0
CINEMATIC_188		EQU 0x3C3C
CINEMATIC_189		EQU 0x3C08
CINEMATIC_190		EQU 0x598A
CINEMATIC_191		EQU 0x59B6
CINEMATIC_192		EQU 0x59E6
CINEMATIC_193		EQU 0x5A1A
CINEMATIC_194		EQU 0x5A4E
CINEMATIC_195		EQU 0x5A5A
CINEMATIC_196		EQU 0x49DA
CINEMATIC_197		EQU 0x49EE
CINEMATIC_198		EQU 0x4A02
CINEMATIC_199		EQU 0x4A7C
CINEMATIC_200		EQU 0x4A6E
CINEMATIC_201		EQU 0x4A36
CINEMATIC_202		EQU 0x5922
CINEMATIC_203		EQU 0x594E
CINEMATIC_204		EQU 0x597E
CINEMATIC_205		EQU 0x0AF4
CINEMATIC_206		EQU 0x3890
CINEMATIC_207		EQU 0x8334
CINEMATIC_208		EQU 0x39CA
CINEMATIC_209		EQU 0x39FE
CINEMATIC_210		EQU 0x4A1A
CINEMATIC_211		EQU 0x089A
CINEMATIC_212		EQU 0x0836
CINEMATIC_213		EQU 0x08EA
CINEMATIC_214		EQU 0x0B80
CINEMATIC_215		EQU 0x07D2
CINEMATIC_216		EQU 0x84D8
CINEMATIC_217		EQU 0x8480
CINEMATIC_218		EQU 0x843C
CINEMATIC_219		EQU 0x8688
CINEMATIC_220		EQU 0x37C2
CINEMATIC_221		EQU 0x37CC
CINEMATIC_222		EQU 0x0C68
CINEMATIC_223		EQU 0x0C44
CINEMATIC_224		EQU 0x0AAC
CINEMATIC_225		EQU 0xB808
CINEMATIC_226		EQU 0xB85E
CINEMATIC_227		EQU 0x4FCE
CINEMATIC_228		EQU 0x4F0C
CINEMATIC_229		EQU 0xC9E6
CINEMATIC_230		EQU 0x3F46
CINEMATIC_231		EQU 0x3F12
CINEMATIC_232		EQU 0xC9BA
CINEMATIC_233		EQU 0x3EFA
CINEMATIC_234		EQU 0xC97E
CINEMATIC_235		EQU 0x3EBE
CINEMATIC_236		EQU 0x2A78
CINEMATIC_237		EQU 0xB836
CINEMATIC_238		EQU 0xBEA4
CINEMATIC_239		EQU 0xBEBE
CINEMATIC_240		EQU 0xBDCC
CINEMATIC_241		EQU 0xBDB0
CINEMATIC_242		EQU 0x3DBE
CINEMATIC_243		EQU 0x8354
CINEMATIC_244		EQU 0xC266
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_9		EQU 0xC2BE
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_9		EQU 0xC2D6
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_8		EQU 0xC566
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_8		EQU 0xC326
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_7		EQU 0xC5CE
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_7		EQU 0xC3C6
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_6		EQU 0xC69E
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_6		EQU 0xC2FE
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_5		EQU 0xC59A
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_5		EQU 0xC34E
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4		EQU 0xC602
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_4		EQU 0xC39E
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_3		EQU 0xC66A
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_3		EQU 0xC376
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_2		EQU 0xC636
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_2		EQU 0xC3EE
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_1		EQU 0xC6D2
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_1		EQU 0xC43E
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_0		EQU 0xC84A
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_0		EQU 0xC466
CINEMATIC_265		EQU 0xC87E
CINEMATIC_266		EQU 0xC48E
CINEMATIC_267		EQU 0xC7AE
CINEMATIC_268		EQU 0xC4B6
CINEMATIC_269		EQU 0xC7E2
CINEMATIC_270		EQU 0xC4DE
CINEMATIC_271		EQU 0xC816
CINEMATIC_272		EQU 0xC416
CINEMATIC_273		EQU 0xC706
CINEMATIC_274		EQU 0x52EE
CINEMATIC_275		EQU 0x93AE
CINEMATIC_276		EQU 0xBB34
CINEMATIC_277		EQU 0xBA50
CINEMATIC_278		EQU 0xBA66
CINEMATIC_279		EQU 0x0038
CINEMATIC_280		EQU 0x558E
CINEMATIC_281		EQU 0x5616
CINEMATIC_282		EQU 0x56D8
CINEMATIC_283		EQU 0x5710
CINEMATIC_284		EQU 0x5744
CINEMATIC_285		EQU 0x5784
CINEMATIC_286		EQU 0x578C
CINEMATIC_287		EQU 0x5794
CINEMATIC_288		EQU 0x579C
CINEMATIC_289		EQU 0x57A4
CINEMATIC_290		EQU 0x57AC
CINEMATIC_291		EQU 0x57B4
CINEMATIC_292		EQU 0x57BC
CINEMATIC_293		EQU 0x57C4
CINEMATIC_294		EQU 0x57CC
CINEMATIC_295		EQU 0x57D4
CINEMATIC_296		EQU 0x57F0
CINEMATIC_297		EQU 0x57F8
CINEMATIC_PRISON_HERO_DEATH_F0		EQU 0xA466
CINEMATIC_PRISON_HERO_DEATH_F1		EQU 0xA4CA
CINEMATIC_PRISON_HERO_DEATH_F2		EQU 0xA532
CINEMATIC_301		EQU 0xBA6E
CINEMATIC_302		EQU 0xBA78
CINEMATIC_303		EQU 0xBA84
CINEMATIC_304		EQU 0xBA90
CINEMATIC_305		EQU 0x4900
CINEMATIC_306		EQU 0x92BE
CINEMATIC_307		EQU 0x9EA8
CINEMATIC_308		EQU 0x975E
CINEMATIC_309		EQU 0x9950
CINEMATIC_310		EQU 0xBC50
CINEMATIC_311		EQU 0xBB80
CINEMATIC_312		EQU 0xBC34
CINEMATIC_313		EQU 0xBC28
CINEMATIC_314		EQU 0xBC1C
CINEMATIC_315		EQU 0xA06C
CINEMATIC_316		EQU 0xA078
CINEMATIC_317		EQU 0xA062
CINEMATIC_318		EQU 0xA04E
CINEMATIC_319		EQU 0xA058
CINEMATIC_320		EQU 0x9FC0
CINEMATIC_321		EQU 0x9FD8
CINEMATIC_322		EQU 0x9FF0
CINEMATIC_323		EQU 0xA022
CINEMATIC_324		EQU 0x9FFC
CINEMATIC_325		EQU 0xA00C
CINEMATIC_326		EQU 0x9F8A
CINEMATIC_327		EQU 0x0050
CINEMATIC_328		EQU 0x937E
CINEMATIC_329		EQU 0x94D6
CINEMATIC_330		EQU 0x9F2A
CINEMATIC_331		EQU 0x9F4E
CINEMATIC_332		EQU 0x94F2
CINEMATIC_333		EQU 0xC004
CINEMATIC_334		EQU 0x3CC2
CINEMATIC_335		EQU 0x8394
CINEMATIC_336		EQU 0x3D14
CINEMATIC_337		EQU 0x839C
CINEMATIC_338		EQU 0x3D92
CINEMATIC_339		EQU 0x834C
CINEMATIC_340		EQU 0x3D66
CINEMATIC_341		EQU 0x8344
CINEMATIC_342		EQU 0x4638
CINEMATIC_343		EQU 0x5B38
CINEMATIC_344		EQU 0x835C
CINEMATIC_345		EQU 0x5B70
CINEMATIC_346		EQU 0x8364
CINEMATIC_347		EQU 0x5BA8
CINEMATIC_348		EQU 0x836C
CINEMATIC_349		EQU 0x5CB8
CINEMATIC_350		EQU 0x5BD0
CINEMATIC_351		EQU 0x4018
CINEMATIC_352		EQU 0xBD48
CINEMATIC_353		EQU 0x83A4
CINEMATIC_354		EQU 0x93D6
CINEMATIC_355		EQU 0x4076
CINEMATIC_356		EQU 0x83AC
CINEMATIC_357		EQU 0x93E2
CINEMATIC_358		EQU 0x4C30
CINEMATIC_359		EQU 0x83B4
CINEMATIC_360		EQU 0x5E14
CINEMATIC_361		EQU 0x7A68
CINEMATIC_362		EQU 0x7B1A
CINEMATIC_363		EQU 0x7B30
CINEMATIC_364		EQU 0x7B48
CINEMATIC_365		EQU 0xA6B0
CINEMATIC_366		EQU 0xA728
CINEMATIC_367		EQU 0x7556
CINEMATIC_368		EQU 0x7616
CINEMATIC_369		EQU 0x76A6
CINEMATIC_370		EQU 0x7736
CINEMATIC_371		EQU 0x77C2
CINEMATIC_372		EQU 0x7842
CINEMATIC_373		EQU 0x78AA
CINEMATIC_374		EQU 0x790A
CINEMATIC_375		EQU 0xA7C0
CINEMATIC_376		EQU 0x646A
CINEMATIC_377		EQU 0x64E2
CINEMATIC_378		EQU 0x65E0
CINEMATIC_379		EQU 0xBCAC
CINEMATIC_380		EQU 0x7A96
CINEMATIC_381		EQU 0x7AEE
CINEMATIC_382		EQU 0x7AC2
CINEMATIC_383		EQU 0x7BA8
CINEMATIC_384		EQU 0x80E8
CINEMATIC_385		EQU 0x7B60
CINEMATIC_386		EQU 0x7B8C
CINEMATIC_387		EQU 0x8234
CINEMATIC_388		EQU 0x8204
CINEMATIC_BUDDY_HACKING_SECURITY_DOOR		EQU 0x4564
CINEMATIC_390		EQU 0x40F8
CINEMATIC_391		EQU 0x9B46
CINEMATIC_392		EQU 0xA084
CINEMATIC_393		EQU 0xA0A4
CINEMATIC_394		EQU 0x9B4E
CINEMATIC_395		EQU 0x9B56
CINEMATIC_396		EQU 0xA08C
CINEMATIC_397		EQU 0x9B92
CINEMATIC_398		EQU 0xA094
CINEMATIC_399		EQU 0xA09C
CINEMATIC_400		EQU 0x9BCA
CINEMATIC_401		EQU 0x9BEE
CINEMATIC_402		EQU 0x9C3A
CINEMATIC_403		EQU 0x9C46
CINEMATIC_404		EQU 0x9C1E
CINEMATIC_405		EQU 0xB7EE
CINEMATIC_406		EQU 0x9C52
CINEMATIC_407		EQU 0x9C92
CINEMATIC_408		EQU 0x9CCE
CINEMATIC_409		EQU 0x9CF2
CINEMATIC_410		EQU 0xB8E0
CINEMATIC_411		EQU 0x9D16
CINEMATIC_412		EQU 0x9D76
CINEMATIC_413		EQU 0xB93A
CINEMATIC_414		EQU 0x62DE
CINEMATIC_415		EQU 0xB8BE
CINEMATIC_416		EQU 0xACDA
CINEMATIC_417		EQU 0xB9E2
CINEMATIC_418		EQU 0x5E8A
CINEMATIC_419		EQU 0x5F26
CINEMATIC_420		EQU 0x5FBE
CINEMATIC_421		EQU 0x604E
CINEMATIC_422		EQU 0x60D2
CINEMATIC_423		EQU 0x635A
CINEMATIC_424		EQU 0xAFA6
CINEMATIC_425		EQU 0xAFC4
CINEMATIC_426		EQU 0xBFAC
CINEMATIC_427		EQU 0xBFC6
CINEMATIC_428		EQU 0xA11E
CINEMATIC_429		EQU 0xA386
CINEMATIC_430		EQU 0xA0CC
CINEMATIC_431		EQU 0x9E32
CINEMATIC_432		EQU 0x9DAA
CINEMATIC_433		EQU 0x9F5A
CINEMATIC_434		EQU 0xA964
CINEMATIC_435		EQU 0xB948
CINEMATIC_436		EQU 0xBEFC
CINEMATIC_437		EQU 0xBF68
CINEMATIC_438		EQU 0x83BC
CINEMATIC_439		EQU 0x276E
CINEMATIC_440		EQU 0x27CE
CINEMATIC_441		EQU 0x853C
CINEMATIC_442		EQU 0x8578
CINEMATIC_443		EQU 0x85C0
CINEMATIC_444		EQU 0x860C
CINEMATIC_445		EQU 0x8130
CINEMATIC_446		EQU 0x816C
CINEMATIC_447		EQU 0x81B8
CINEMATIC_448		EQU 0xA870
CINEMATIC_449		EQU 0xAB3E
CINEMATIC_450		EQU 0xAB9E
CINEMATIC_451		EQU 0xAC36
CINEMATIC_452		EQU 0x6D88
CINEMATIC_453		EQU 0x5850
CINEMATIC_454		EQU 0xB96E
CINEMATIC_455		EQU 0x0074
CINEMATIC_456		EQU 0x0020
CINEMATIC_457		EQU 0x0098
CINEMATIC_ENERGY_TRANSMISSION_LINE		EQU 0xB05A
CINEMATIC_459		EQU 0xB98E
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_0		EQU 0x6A54
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_1		EQU 0x6A6C
CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_2		EQU 0x6A84
CINEMATIC_463		EQU 0x6A20
CINEMATIC_PRISON_SHOT_IMPACT_8		EQU 0x796E
CINEMATIC_PRISON_SHOT_IMPACT_7		EQU 0x71EA
CINEMATIC_PRISON_SHOT_IMPACT_6		EQU 0x71D2
CINEMATIC_PRISON_SHOT_IMPACT_5		EQU 0x71B6
CINEMATIC_PRISON_SHOT_IMPACT_4		EQU 0x719A
CINEMATIC_PRISON_SHOT_IMPACT_3		EQU 0x7172
CINEMATIC_PRISON_SHOT_IMPACT_2		EQU 0x714E
CINEMATIC_PRISON_SHOT_IMPACT_1		EQU 0x79D8
CINEMATIC_PRISON_SHOT_IMPACT_0		EQU 0x71FE
CINEMATIC_473		EQU 0x7078
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_7		EQU 0x7058
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_6		EQU 0x7012
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_5		EQU 0x6FA6
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_4		EQU 0x6F50
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_3		EQU 0x6F00
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_2		EQU 0x6EB0
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_1		EQU 0x6E3C
CINEMATIC_PRISON_SHOT_BLAST_RIGHT_0		EQU 0x6DDA
CINEMATIC_482		EQU 0x6D60
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_0		EQU 0x6CA8
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_1		EQU 0x6CC4
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_2		EQU 0x6CE0
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_3		EQU 0x6D00
CINEMATIC_PRISON_SHOT_HIT_BURST_RIGHT_4		EQU 0x6D1C
CINEMATIC_488		EQU 0x6D30
CINEMATIC_489		EQU 0xAF8C
CINEMATIC_PRISON_SHOT_BLAST_LEFT_7		EQU 0xAF6C
CINEMATIC_PRISON_SHOT_BLAST_LEFT_6		EQU 0xAF26
CINEMATIC_PRISON_SHOT_BLAST_LEFT_5		EQU 0xAEBA
CINEMATIC_PRISON_SHOT_BLAST_LEFT_4		EQU 0xAE64
CINEMATIC_PRISON_SHOT_BLAST_LEFT_3		EQU 0xAE14
CINEMATIC_PRISON_SHOT_BLAST_LEFT_2		EQU 0xADC4
CINEMATIC_PRISON_SHOT_BLAST_LEFT_1		EQU 0xAD74
CINEMATIC_PRISON_SHOT_BLAST_LEFT_0		EQU 0xAD4E
CINEMATIC_498		EQU 0xAD02
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_0		EQU 0x6A9C
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_1		EQU 0x6AD0
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_2		EQU 0x6AEC
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_3		EQU 0x6B0C
CINEMATIC_PRISON_SHOT_HIT_BURST_LEFT_4		EQU 0x6B28
CINEMATIC_504		EQU 0x6B3C
CINEMATIC_505		EQU 0x494C
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_0		EQU 0x4960
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_0		EQU 0x7992
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_1		EQU 0x4974
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_1		EQU 0x799A
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_2		EQU 0x4988
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_2		EQU 0x79A2
CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_3		EQU 0x499C
CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_3		EQU 0x79AA
CINEMATIC_514		EQU 0x49B0
CINEMATIC_515		EQU 0x79B2
CINEMATIC_516		EQU 0x79CE
CINEMATIC_517		EQU 0x79C4
CINEMATIC_518		EQU 0x93C6
CINEMATIC_519		EQU 0x93CE
CINEMATIC_520		EQU 0x49C4
CINEMATIC_521		EQU 0x79BA
CINEMATIC_522		EQU 0x6B60
CINEMATIC_523		EQU 0x6C18
CINEMATIC_524		EQU 0x4AC8
CINEMATIC_525		EQU 0x6B98
CINEMATIC_526		EQU 0x6BCC
CINEMATIC_527		EQU 0x4A88
CINEMATIC_528		EQU 0x4AA8
CINEMATIC_529		EQU 0x6BFC
CINEMATIC_530		EQU 0x6C30
CINEMATIC_531		EQU 0x6C48
CINEMATIC_532		EQU 0x6C5C
CINEMATIC_533		EQU 0x6C6E
CINEMATIC_534		EQU 0x6C7E
CINEMATIC_535		EQU 0x6C8A
CINEMATIC_536		EQU 0x6C9C
CINEMATIC_537		EQU 0x58AC
CINEMATIC_538		EQU 0x5864
CINEMATIC_539		EQU 0x5894
CINEMATIC_540		EQU 0x2506
CINEMATIC_541		EQU 0x2752
CINEMATIC_542		EQU 0x2556
CINEMATIC_543		EQU 0x2736
CINEMATIC_544		EQU 0x2536
CINEMATIC_545		EQU 0x271A
CINEMATIC_546		EQU 0x26FE
CINEMATIC_547		EQU 0x26F6
CINEMATIC_548		EQU 0x26EE
CINEMATIC_549		EQU 0x535E
CINEMATIC_550		EQU 0x4BEC
CINEMATIC_551		EQU 0x7BD8
CINEMATIC_552		EQU 0x4BA8
CINEMATIC_553		EQU 0x7BC4
CINEMATIC_554		EQU 0x8664
CINEMATIC_555		EQU 0x0380
CINEMATIC_556		EQU 0x0B18
CINEMATIC_557		EQU 0x0A88
CINEMATIC_558		EQU 0x3A46
CINEMATIC_559		EQU 0x3BC2
CINEMATIC_560		EQU 0x0A5E
CINEMATIC_561		EQU 0x0BB8
CINEMATIC_562		EQU 0x07AE
CINEMATIC_563		EQU 0x3948
CINEMATIC_564		EQU 0x833C
CINEMATIC_565		EQU 0x37FE
CINEMATIC_566		EQU 0x3984
CINEMATIC_567		EQU 0x073C
CINEMATIC_568		EQU 0x041C
CINEMATIC_569		EQU 0x9290
CINEMATIC_570		EQU 0x5002
CINEMATIC_571		EQU 0x5150
CINEMATIC_572		EQU 0x513C
CINEMATIC_573		EQU 0x51E0
CINEMATIC_574		EQU 0x50D2
CINEMATIC_575		EQU 0x5092
CINEMATIC_576		EQU 0x523A
CINEMATIC_577		EQU 0x525E
CINEMATIC_578		EQU 0x5286
CINEMATIC_579		EQU 0x52B2
CINEMATIC_580		EQU 0x52D6
CINEMATIC_581		EQU 0x1FDA
CINEMATIC_582		EQU 0x1FC6
CINEMATIC_583		EQU 0x1FB2
CINEMATIC_584		EQU 0x1F9E
CINEMATIC_585		EQU 0x1F8A
CINEMATIC_586		EQU 0x1F76
CINEMATIC_587		EQU 0x1F62
CINEMATIC_588		EQU 0x1F4E
CINEMATIC_589		EQU 0x1F3A
CINEMATIC_590		EQU 0x1F26
CINEMATIC_591		EQU 0x1F12
CINEMATIC_592		EQU 0x1EFE
CINEMATIC_593		EQU 0x1EEA
CINEMATIC_594		EQU 0x1ED6
CINEMATIC_595		EQU 0x1EC2
CINEMATIC_596		EQU 0x4114
CINEMATIC_597		EQU 0x4140
CINEMATIC_598		EQU 0x42D4
CINEMATIC_599		EQU 0x415C
CINEMATIC_600		EQU 0x42F0
CINEMATIC_601		EQU 0x4178
CINEMATIC_602		EQU 0x41CC
CINEMATIC_603		EQU 0x4208
CINEMATIC_604		EQU 0x4340
CINEMATIC_605		EQU 0x4354
CINEMATIC_606		EQU 0x4240
CINEMATIC_607		EQU 0x4368
CINEMATIC_608		EQU 0x4254
CINEMATIC_609		EQU 0x43A4
CINEMATIC_610		EQU 0x43E4
CINEMATIC_611		EQU 0x4294
CINEMATIC_612		EQU 0x4468
CINEMATIC_613		EQU 0x44B8
CINEMATIC_614		EQU 0x4518
CINEMATIC_615		EQU 0x4E50
CINEMATIC_616		EQU 0x45E8
CINEMATIC_617		EQU 0x4E68
CINEMATIC_618		EQU 0x4D60
CINEMATIC_619		EQU 0x4E80
CINEMATIC_620		EQU 0x4DB0
CINEMATIC_621		EQU 0x4E98
CINEMATIC_622		EQU 0x4E00
CINEMATIC_623		EQU 0x4EB0
CINEMATIC_624		EQU 0x4D3A
CINEMATIC_625		EQU 0x4D18
CINEMATIC_626		EQU 0x4CFA
CINEMATIC_627		EQU 0x4CC8
CINEMATIC_628		EQU 0x4CA2
CINEMATIC_629		EQU 0x4F44
CINEMATIC_630		EQU 0x4F8C
CINEMATIC_631		EQU 0x4FB6
CINEMATIC_632		EQU 0x2932
CINEMATIC_633		EQU 0x4424
CINEMATIC_634		EQU 0x3364
CINEMATIC_635		EQU 0xBE78
CINEMATIC_636		EQU 0xBE5C
CINEMATIC_637		EQU 0x3102
CINEMATIC_638		EQU 0x3052
CINEMATIC_639		EQU 0x3092
CINEMATIC_640		EQU 0x30D2
CINEMATIC_641		EQU 0x30EE
CINEMATIC_642		EQU 0x3036
CINEMATIC_643		EQU 0x306E
CINEMATIC_644		EQU 0x30B6
CINEMATIC_645		EQU 0x2E02
CINEMATIC_646		EQU 0x2DDA
CINEMATIC_647		EQU 0x2E3E
CINEMATIC_648		EQU 0x2E22
CINEMATIC_649		EQU 0x3116
CINEMATIC_650		EQU 0x2E62
CINEMATIC_651		EQU 0x3334
CINEMATIC_652		EQU 0x32BC
CINEMATIC_653		EQU 0x3242
CINEMATIC_654		EQU 0x315E
CINEMATIC_655		EQU 0x312A
CINEMATIC_656		EQU 0xC028
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2		EQU 0x37AC
CINEMATIC_658		EQU 0x339C
CINEMATIC_659		EQU 0x3674
CINEMATIC_660		EQU 0x3648
CINEMATIC_661		EQU 0x361C
CINEMATIC_662		EQU 0x35F0
CINEMATIC_663		EQU 0x35C4
CINEMATIC_664		EQU 0x3598
CINEMATIC_665		EQU 0x356C
CINEMATIC_666		EQU 0x3540
CINEMATIC_667		EQU 0x3514
CINEMATIC_668		EQU 0x34E8
CINEMATIC_669		EQU 0x34BC
CINEMATIC_670		EQU 0x3490
CINEMATIC_671		EQU 0x3464
CINEMATIC_672		EQU 0x3438
CINEMATIC_673		EQU 0x340C
CINEMATIC_674		EQU 0x33E0
CINEMATIC_675		EQU 0x33B4
CINEMATIC_676		EQU 0x33A8
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1		EQU 0x37A0
CINEMATIC_678		EQU 0x3794
CINEMATIC_679		EQU 0x3788
CINEMATIC_680		EQU 0x377C
CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0		EQU 0x3770
CINEMATIC_682		EQU 0x36A0
CINEMATIC_683		EQU 0x2AB0
CINEMATIC_684		EQU 0x2ECE
CINEMATIC_685		EQU 0x3390
CINEMATIC_686		EQU 0xC08C
CINEMATIC_687		EQU 0xC074
CINEMATIC_688		EQU 0x40D4
CINEMATIC_689		EQU 0x40E8
CINEMATIC_690		EQU 0x40B8
CINEMATIC_691		EQU 0xBDE0
CINEMATIC_692		EQU 0x4C96
CINEMATIC_693		EQU 0x7C28
CINEMATIC_694		EQU 0x624E
CINEMATIC_695		EQU 0x61D2
CINEMATIC_696		EQU 0x6152
CINEMATIC_697		EQU 0xBE34
CINEMATIC_698		EQU 0xBE18
CINEMATIC_699		EQU 0xBDFC
CINEMATIC_700		EQU 0x8270
CINEMATIC_701		EQU 0x8240
CINEMATIC_702		EQU 0x7A04
CINEMATIC_703		EQU 0xACB6
CINEMATIC_704		EQU 0x000C
HERO_WATER_DEPTH_LEFT_CASE_00		EQU 0x5DE4
HERO_STAND_LEFT_ARM		EQU 0x3322
HERO_STAND_LEFT_BODY		EQU 0x0358
CV_4D98		EQU 0x4D98
CV_4DE4		EQU 0x4DE4
CV_4E30		EQU 0x4E30
CV_4E7C		EQU 0x4E7C
CV_4EC8		EQU 0x4EC8
CV_4F14		EQU 0x4F14
CV_4F68		EQU 0x4F68
CV_500C		EQU 0x500C
CV_5058		EQU 0x5058
CV_50A8		EQU 0x50A8
CV_50F8		EQU 0x50F8
CV_514C		EQU 0x514C
CV_0F90		EQU 0x0F90
CV_338E		EQU 0x338E
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
CV_52C0		EQU 0x52C0
CV_52E0		EQU 0x52E0
CV_5300		EQU 0x5300
CV_5320		EQU 0x5320
CV_5340		EQU 0x5340
CV_5360		EQU 0x5360
CV_5380		EQU 0x5380
CV_53C0		EQU 0x53C0
CV_53E0		EQU 0x53E0
CV_5400		EQU 0x5400
CV_5420		EQU 0x5420
CV_5444		EQU 0x5444
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
CV_4FBC		EQU 0x4FBC
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
CV_53A0		EQU 0x53A0
CV_150A		EQU 0x150A
CV_15A2		EQU 0x15A2
CV_11B8		EQU 0x11B8
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
CV_1B14		EQU 0x1B14
CV_5F94		EQU 0x5F94
CV_39A2		EQU 0x39A2
CV_5C94		EQU 0x5C94
HERO_PRONE_TRANSITION_LEFT_F00		EQU 0x57C4
HERO_PRONE_TRANSITION_LEFT_F01		EQU 0x5878
HERO_PRONE_TRANSITION_LEFT_F02		EQU 0x5944
HERO_PRONE_TRANSITION_LEFT_F03		EQU 0x5A08
HERO_PRONE_TRANSITION_LEFT_F04		EQU 0x5AAC
HERO_PRONE_TRANSITION_LEFT_F05		EQU 0x5B4C
CV_4754		EQU 0x4754
CV_485C		EQU 0x485C
CV_4BC4		EQU 0x4BC4
CV_4B4C		EQU 0x4B4C
CV_4ACC		EQU 0x4ACC
CV_4A6C		EQU 0x4A6C
CV_4A04		EQU 0x4A04
CV_49B0		EQU 0x49B0
CV_48D8		EQU 0x48D8
CV_4954		EQU 0x4954
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
CV_47DC		EQU 0x47DC
CV_FIGURE_PROFILE_STRIDE		EQU 0x40EC
CV_2B0E		EQU 0x2B0E
CV_5FCC		EQU 0x5FCC
CV_FIGURE_WALK_RIGHT_LIMB_POSE_00		EQU 0x247C
CV_FIGURE_WALK_RIGHT_BODY_F00		EQU 0x181C
CV_1A84		EQU 0x1A84
CV_5F7C		EQU 0x5F7C
CV_FIGURE_WALK_RIGHT_BODY_F01		EQU 0x1866
CV_FIGURE_WALK_RIGHT_BODY_F02		EQU 0x18B0
CV_1AB4		EQU 0x1AB4
CV_5F84		EQU 0x5F84
CV_FIGURE_WALK_RIGHT_BODY_F03		EQU 0x18FA
CV_1AE4		EQU 0x1AE4
CV_5F8C		EQU 0x5F8C
CV_FIGURE_WALK_RIGHT_BODY_F04		EQU 0x1944
CV_FIGURE_WALK_RIGHT_LIMB_POSE_01		EQU 0x2474
CV_FIGURE_WALK_RIGHT_BODY_F05		EQU 0x198E
CV_1B44		EQU 0x1B44
CV_5F9C		EQU 0x5F9C
CV_FIGURE_WALK_RIGHT_LIMB_POSE_02		EQU 0x246C
CV_FIGURE_WALK_RIGHT_BODY_F06		EQU 0x19C4
CV_1B74		EQU 0x1B74
CV_5FA4		EQU 0x5FA4
CV_245C		EQU 0x245C
CV_FIGURE_WALK_RIGHT_BODY_F07		EQU 0x1A0E
CV_1BA4		EQU 0x1BA4
CV_5FAC		EQU 0x5FAC
CV_FIGURE_WALK_RIGHT_LIMB_POSE_03		EQU 0x2464
CV_FIGURE_WALK_RIGHT_BODY_F08		EQU 0x1D78
CV_1BD4		EQU 0x1BD4
CV_5FB4		EQU 0x5FB4
CV_FIGURE_WALK_RIGHT_BODY_F09		EQU 0x1D9A
CV_FIGURE_WALK_RIGHT_BODY_F10		EQU 0x1DBC
CV_FIGURE_WALK_RIGHT_BODY_F11		EQU 0x1DDE
CV_FIGURE_WALK_RIGHT_BODY_F12		EQU 0x1E00
CV_FIGURE_WALK_RIGHT_BODY_F13		EQU 0x1E22
CV_FIGURE_WALK_RIGHT_BODY_F14		EQU 0x1E44
CV_FIGURE_WALK_RIGHT_BODY_F15		EQU 0x1E66
CV_1A54		EQU 0x1A54
CV_5F74		EQU 0x5F74
CV_FIGURE_WALK_LEFT_BODY_F00		EQU 0x257A
CV_2AC6		EQU 0x2AC6
CV_5FC4		EQU 0x5FC4
CV_FIGURE_WALK_LEFT_BODY_F01		EQU 0x2610
CV_FIGURE_WALK_LEFT_BODY_F02		EQU 0x2672
CV_FIGURE_WALK_LEFT_BODY_F03		EQU 0x270C
CV_2B56		EQU 0x2B56
CV_5FD4		EQU 0x5FD4
CV_FIGURE_WALK_LEFT_BODY_F04		EQU 0x2786
CV_2B9E		EQU 0x2B9E
CV_5FDC		EQU 0x5FDC
CV_FIGURE_WALK_LEFT_LIMB_POSE_01		EQU 0x2D66
CV_FIGURE_WALK_LEFT_BODY_F05		EQU 0x27FC
CV_2BE6		EQU 0x2BE6
CV_5FE4		EQU 0x5FE4
CV_FIGURE_WALK_LEFT_LIMB_POSE_02		EQU 0x2D5E
CV_FIGURE_WALK_LEFT_BODY_F06		EQU 0x287E
CV_2C2E		EQU 0x2C2E
CV_5FEC		EQU 0x5FEC
CV_FIGURE_WALK_LEFT_BODY_F07		EQU 0x28F8
CV_2C76		EQU 0x2C76
CV_5FF4		EQU 0x5FF4
CV_FIGURE_WALK_LEFT_LIMB_POSE_03		EQU 0x2D56
CV_FIGURE_WALK_LEFT_BODY_F08		EQU 0x296E
CV_2CBE		EQU 0x2CBE
CV_5FFC		EQU 0x5FFC
CV_FIGURE_WALK_LEFT_BODY_F09		EQU 0x2990
CV_FIGURE_WALK_LEFT_BODY_F10		EQU 0x29B2
CV_FIGURE_WALK_LEFT_BODY_F11		EQU 0x29D4
CV_FIGURE_WALK_LEFT_BODY_F12		EQU 0x29F6
CV_FIGURE_WALK_LEFT_BODY_F13		EQU 0x2A18
CV_FIGURE_WALK_LEFT_BODY_F14		EQU 0x2A3A
CV_FIGURE_WALK_LEFT_BODY_F15		EQU 0x2A5C
CV_2A7E		EQU 0x2A7E
CV_5FBC		EQU 0x5FBC
CV_2566		EQU 0x2566
CV_FIGURE_RUN_RIGHT_BODY_F00		EQU 0x1F70
CV_6108		EQU 0x6108
CV_255C		EQU 0x255C
CV_FIGURE_RUN_RIGHT_BODY_F01		EQU 0x1FE4
CV_2552		EQU 0x2552
CV_FIGURE_RUN_RIGHT_BODY_F02		EQU 0x2058
CV_2548		EQU 0x2548
CV_FIGURE_RUN_RIGHT_BODY_F03		EQU 0x20B8
CV_2200		EQU 0x2200
CV_2570		EQU 0x2570
CV_FIGURE_RUN_RIGHT_BODY_F04		EQU 0x2134
CV_2212		EQU 0x2212
CV_FIGURE_RUN_RIGHT_BODY_F05		EQU 0x2310
CV_FIGURE_RUN_RIGHT_BODY_F06		EQU 0x232C
CV_FIGURE_RUN_RIGHT_BODY_F07		EQU 0x2348
CV_2364		EQU 0x2364
CV_2380		EQU 0x2380
CV_2D76		EQU 0x2D76
CV_61A2		EQU 0x61A2
CV_3200		EQU 0x3200
CV_2E0A		EQU 0x2E0A
CV_3116		EQU 0x3116
CV_31F6		EQU 0x31F6
CV_2E9E		EQU 0x2E9E
CV_3124		EQU 0x3124
CV_31EC		EQU 0x31EC
CV_2F3A		EQU 0x2F3A
CV_316E		EQU 0x316E
CV_3212		EQU 0x3212
CV_2FD6		EQU 0x2FD6
CV_3180		EQU 0x3180
CV_304A		EQU 0x304A
CV_3066		EQU 0x3066
CV_3082		EQU 0x3082
CV_31A8		EQU 0x31A8
CV_309E		EQU 0x309E
CV_31CA		EQU 0x31CA
CV_30BA		EQU 0x30BA
CV_FIGURE_CROUCH_FACING_RIGHT		EQU 0x4132
CV_42BA		EQU 0x42BA
CV_4314		EQU 0x4314
CV_FIGURE_CROUCH_FACING_LEFT		EQU 0x3E4E
CV_4324		EQU 0x4324
CV_426C		EQU 0x426C
CV_4346		EQU 0x4346
CV_4368		EQU 0x4368
CV_3A64		EQU 0x3A64
CV_5C9C		EQU 0x5C9C


	org 0x0000

ENTRY_POINT_OF_PRISON:
	call CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8
	mov [0xE3], 0x0000
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
	jge [0x00], 0x15, LABEL_00DC
	call LABEL_004A
	mov [0x00], 0x0014
	jmp LABEL_00CD

LABEL_004A:
	je [0xDB], 0x00, SHARED_RET
	bankSwitch 3;  TODO - Name this stage (bank number #3)	;@enc=legacy_d
	ret


LABEL_0054:
	je [0xDB], 0x00, SHARED_RET
	bankSwitch 4;  TODO - Name this stage (bank number #4)	;@enc=legacy_d
	ret


LABEL_005E:
	je [0xDB], 0x00, SHARED_RET
	bankSwitch 5;  TODO - Name this stage (bank number #5)	;@enc=legacy_d
	ret


LABEL_0068:
	jne [SCREEN_NUM], 0x04, SHARED_RET
	jne [0x72], [SCREEN_NUM], LABEL_007B
	jl [0x73], 0x4000, LABEL_0088

LABEL_007B:
	jne [0x7A], [SCREEN_NUM], SHARED_RET
	jge [0x7B], 0x4000, SHARED_RET

LABEL_0088:
	je [SCREEN_NUM], 0x01, SHARED_RET
	song id=0x0BBF, delay=0x0000, pos=0x00
	ret


	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	break
	setup channel=0x14, address=LABEL_90F7
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_8BC5
	setup channel=0x0A, address=LABEL_05EF
	call LABEL_0860
	mov [SCREEN_NUM], 0x0023
	call LABEL_884B
	setup channel=0x23, address=DRAW_CIN_406_408_BLOCK
	setup channel=0x3F, address=LABEL_897B
	mov [HERO_X], 0x0092
	mov [HERO_Y], 0x005C
	mov [0x28], [HERO_X]
	video offset=CINEMATIC_704, x=0, y=182
	killChannel
	killChannel

LABEL_00CD:
	setup channel=0x01, address=FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA
	setup channel=0x02, address=LABEL_5083
	song id=0x0BBC, delay=0x0000, pos=0x00
	killChannel

LABEL_00DC:
	setup channel=0x22, address=LABEL_4DB9
	setup channel=0x23, address=LABEL_4C64
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4
	setup channel=0x15, address=LABEL_7939
	setup channel=0x00, address=LABEL_1D52
	call LABEL_0054
	call LABEL_1D63
	killChannel

LIKELY_A_COPY_PROTECTION_MECHANISM:
	mov [0xF8], [0xBC]
	and [0xF8], 0x0010
	ret


	je [0xF8], 0x00, LABEL_010D
	jne [0xF2], 0x0FA0, LABEL_010D
	ret


LABEL_010D:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=KILL_CHANNEL_LANDING
	killChannel

DELAY_4_QUANTUMS:
	break
	break
	break
	break
	mov [0x03], 0x001E

LABEL_011E:
	break
	call LABEL_014F
	je [HERO_ACTION], 0x00, LABEL_012C
	djnz [0x03], LABEL_011E

LABEL_012C:
	mov [0x03], 0x001E

LABEL_0130:
	break
	call LABEL_014F
	jne [HERO_ACTION], 0x00, PRISON_ACCESS_CODE_SCREEN_START
	djnz [0x03], LABEL_0130

PRISON_ACCESS_CODE_SCREEN_START:
	deleteChannels first=0x00, last=0x3F
	freezeChannels first=0x00, last=0x3F
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	setup channel=0x00, address=LABEL_0161
	killChannel

LABEL_014F:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret


LABEL_0161:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	or [0xE3], 0x0001
	mov [PAUSE_SLICES], 0x0005
	setPalette 0x1D

LABEL_0179:
	break
	text id=0x013D, x=5, y=80, color=0x0D ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0C ; "        ACCESS CODE:"
	text id=0x015F, x=26, y=180, color=0x0E ; "HTDC"
	call LABEL_014F
	jne [HERO_ACTION], 0x00, LABEL_0179

LABEL_0195:
	text id=0x013D, x=5, y=80, color=0x0D ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0C ; "        ACCESS CODE:"
	text id=0x015F, x=26, y=180, color=0x0E ; "HTDC"
	break
	call LABEL_014F
	je [HERO_ACTION], 0x00, LABEL_0195
	mov [0x00], 0x0015
	setup channel=0x00, address=ENTRY_POINT_OF_PRISON
	killChannel

PRELOAD_PRISON_RESOURCES:
	jne [0xDB], 0x00, SHARED_RET
	load id=0x0052
	load id=0x0055
	load id=0x0056
	load id=0x0057
	load id=0x0058
	load id=0x0059
	load id=0x005A
	load id=0x005B
	load id=0x005C
	load id=0x005D
	load id=0x005E
	load id=0x005F
	load id=0x0060
	load id=0x0061
	load id=0x0062
	load id=0x0063
	load id=0x0064
	load id=0x0065
	load id=0x0073
	load id=0x0067
	load id=0x0070
	load id=0x0071
	load id=0x0072
	load id=0x0066
	load id=0x0068
	load id=0x0069
	ret
