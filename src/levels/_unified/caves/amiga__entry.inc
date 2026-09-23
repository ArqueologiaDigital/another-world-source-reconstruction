; Unified source for CAVES with 264 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_037  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_038  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_039  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_040  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   SHARED_RET  (3-arm: amiga, cart, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_68_SEGMENT_16  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4C_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_69_SEGMENT_7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_035  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_036  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 264 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_037  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_038  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_039  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_040  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   SHARED_RET  (3-arm: amiga, cart, dos)
;   DRAW_CV204_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV204_AT_X07_PLUS1_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   DRAW_CV224_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   DRAW_CV263_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   DRAW_CV275_AT_X07_Y08  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   DRAW_CV246_AT_X07_Y08  (2-arm: cart, dos)
;   DRAW_CV249_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DRAW_CV259_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   DRAW_CV261_AT_X07_Y08  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_68_SEGMENT_16  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4C_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_69_SEGMENT_7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_035  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_036  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_RES_6A_77_6D_6E_74_76_78_7C  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 213 folded shared bodies.
;
; Folded routines (in byte-address order):
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   SETUP_VAR8B_6E_VAR97_B7_VAR96_0  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 213 folded shared bodies.
;
; Folded routines (in byte-address order):
;   DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_LOAD  (3-arm: amiga, cart, dos)
;   CAVES_ACCESS_CODE_INDEX_COMMIT  (3-arm: amiga, cart, dos)
;   SETUP_VAR8B_6E_VAR97_B7_VAR96_0  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_ENTRY_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6D_71_70  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_1  (2-arm: cart, dos)
;   INIT_VARS_E6_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_E6_E7_E9_E8  (2-arm: cart, dos)
;   INIT_VARS_0E_29  (3-arm: amiga, cart, dos)
;   INIT_VARS_EE_EF  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAREF_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR68_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6A_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR01_TO_E  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_1E  (3-arm: amiga, cart, dos)
;   INIT_VARS_E8_E6  (2-arm: cart, dos)
;   INIT_VARS_E6_68_69_6B  (3-arm: amiga, cart, dos)
;   CAVES_TWIN_COLUMN_RISE_INIT  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VAR09_TO_7_VAR08_FROM_VAR22  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR74_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR75_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_6  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR73_TO_6  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_DECR_VAR08_BY_4  (3-arm: amiga, cart, dos)
;   RESET_VAR09_AND_INCR_VAR08_BY_2  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EA_EB  (3-arm: amiga, cart, dos)
;   COPY_VARE6E7_TO_VARE8_E9_EA_EB  (3-arm: amiga, cart, dos)
;   STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6  (3-arm: amiga, cart, dos)
;   INIT_VAR08_FROM_VARE9_VAR09_TO_4  (3-arm: amiga, cart, dos)
;   MUL_VAR6B_BY_11_INTO_VAR21  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   SET_VARE6_TO_64_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   SETUP_67_45_VAR01_46_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_67_VAR01_1E_VARBE_3  (3-arm: amiga, cart, dos)
;   SETUP_67_25_VAR06_0_VARB1_NOSIGN  (2-arm: cart, dos)
;   SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1  (3-arm: amiga, cart, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   CAVES_CREATURE_WALK_RIGHT_INIT  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR07_BY_4  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR22_TO_VAR08  (2-arm: cart, dos)
;   SPLIT_VAR09_BITS_INTO_VAR0D  (3-arm: amiga, cart, dos)
;   AND_VAR11_WITH_EFFF  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR11_WITH_1000  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   STEP_VAR29_DOWN10_SET_VAR2F_11  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_29E88AAE  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_12  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR26_AS_VAR21_MINUS_VAR22  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   ADD_VAR2C_TO_VAR22  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   MASK_VAR11_NOSIGN_INCR_VAR21_BY_14  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   COMPUTE_VAR22_AS_VAR40_MINUS_28  (3-arm: amiga, cart, dos)
;   COMPUTE_VARF8_AS_VAR22_MINUS_VAR09  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   ADD_VAR11_TO_VAR34  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
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
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   CAVES_DRAW_HERO_WALK_LEFT_BODY_F09  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   DRAW_CV078_PLAY_60_F0B_V22_C1  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   DRAW_CV070_PLAY_60_F14_V20_C1  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_HERO_POSE_0_0  (2-arm: cart, dos)
;   DRAW_CV107_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV108_PLAY_60_F0F_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV109_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   DRAW_CV111_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   DRAW_CV113_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   DRAW_CV097_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV098_PLAY_60_F0A_V2A_C1  (2-arm: cart, dos)
;   DRAW_CV099_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   DRAW_CV101_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   DRAW_CV103_AT_X01_Y02  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   DRAW_CV105_AT_X01_Y02  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   SHELVE_BACKDROP_TO_PAGE3  (2-arm: cart, dos)
;   COPY_VAR51_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   COPY_VAR52_TO_VAR02_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_67_SEGMENT_11  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_13  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A7_SEGMENT_26  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C8_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_8  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_C9_SEGMENT_15  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CA_SEGMENT_20  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREENS_CB_CC_CE_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_CD_SEGMENT_8  (3-arm: amiga, cart, dos)
;   PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_88_SEGMENT_9  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_89_SEGMENT_17  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   LOAD_RES44_AND_RET  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   CACHE_SCREEN_NUM_RET  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_DOWN_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_UP_ONE_ROW  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_LEFT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   SCREEN_STEP_RIGHT_ONE_COLUMN  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   WALK_RIGHT_DRAW_CV142_MULTISTEP  (2-arm: cart, dos)
;   STEP_LEFT4_DRAW_CV140_LEFT4  (2-arm: cart, dos)
;   STEP_DRAW_CV352_LEFT4_RIGHT1  (3-arm: amiga, cart, dos)
;   DRAW_CV352_STEP_RIGHT3  (3-arm: amiga, cart, dos)
;   HERO_CROUCH_DOWN_LEFT_STEP  (2-arm: cart, dos)
;   HERO_CROUCH_DOWN_RIGHT_STEP  (2-arm: cart, dos)

; Unified source for CAVES with 33 folded shared bodies.
;
; Folded routines (in byte-address order):
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000F  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_001D  (3-arm: amiga, cart, dos)
;   SET_VAR2F_TO_000D  (3-arm: amiga, cart, dos)
;   SET_VAR21_TO_0001  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_85_SEGMENT_6  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_A6_SEGMENT_5  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_87_SEGMENT_18  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6F_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_AF_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_71_SEGMENT_2  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_48_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_49_SEGMENT_4  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_28_SEGMENT_3  (3-arm: amiga, cart, dos)
;   CAVES_GROUND_MAP_SCREEN_6D_SEGMENT_10  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0034  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0024  (3-arm: amiga, cart, dos)
;   SET_VAR18_TO_0122  (3-arm: amiga, cart, dos)

wrote src/levels/_unified/caves/amiga__entry.inc (1335 lines)
wrote src/levels/_unified/caves/amiga__post_PRELOAD_CAVES_RESOURCES.inc (5841 lines)
wrote src/levels/_unified/caves/amiga__post_COPY_HASH_VAR_37_TO_RANGE.inc (316 lines)
wrote src/levels/_unified/caves/amiga__post_INIT_HASH_VARS_67_66_65_68_69.inc (520 lines)
wrote src/levels/_unified/caves/amiga__post_DERIVE_VAR12_11_10_FROM_VAR9.inc (12771 lines)
wrote src/levels/_unified/caves/amiga__post_INIT_RANGE_48_TO_4D_TO_MAX.inc (294 lines)
wrote src/levels/_unified/caves/amiga__post_INIT_AI_VARS_AT_280_10.inc (2492 lines)
wrote src/levels/_unified/caves/cart__entry.inc (7594 lines)
wrote src/levels/_unified/caves/cart__post_COPY_HASH_VAR_37_TO_RANGE.inc (322 lines)
wrote src/levels/_unified/caves/cart__post_INIT_HASH_VARS_67_66_65_68_69.inc (522 lines)
wrote src/levels/_unified/caves/cart__post_DERIVE_VAR12_11_10_FROM_VAR9.inc (13258 lines)
wrote src/levels/_unified/caves/cart__post_INIT_RANGE_48_TO_4D_TO_MAX.inc (319 lines)
wrote src/levels/_unified/caves/cart__post_INIT_AI_VARS_AT_280_10.inc (2433 lines)
wrote src/levels/_unified/caves/dos__entry.inc (1383 lines)
wrote src/levels/_unified/caves/dos__post_PRELOAD_CAVES_RESOURCES.inc (6221 lines)
wrote src/levels/_unified/caves/dos__post_COPY_HASH_VAR_37_TO_RANGE.inc (995 lines)
wrote src/levels/_unified/caves/dos__post_DERIVE_VAR12_11_10_FROM_VAR9.inc (13122 lines)
wrote src/levels/_unified/caves/dos__post_INIT_RANGE_48_TO_4D_TO_MAX.inc (318 lines)
wrote src/levels/_unified/caves/dos__post_INIT_AI_VARS_AT_280_10.inc (2450 lines)
; Unified source for CAVES with 6 folded shared bodies.
;
; Folded routines (in byte-address order):
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   DERIVE_VAR12_11_10_FROM_VAR9  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_AI_VARS_AT_280_10  (3-arm: amiga, cart, dos)

; Unified source for CAVES with one folded shared body.
;
; Architecture: each per-arm `.inc` file is split into `_pre` and
; `_post` chunks separated by the byte address of the shared
; routine. Shared bodies live at the top level and are emitted into
; the assembled output for each branch at the natural assembled
; layout's byte address (no `org` directive needed).
;
; Currently folded routines (in byte-address order within the file):
;   PRELOAD_CAVES_RESOURCES  (58 bytes — amiga+dos only, NOT cart)
;   COPY_HASH_VAR_37_TO_RANGE  (117 bytes — also in CAPSULE, PRISON, 3-arm)
;   INIT_HASH_VARS_67_66_65_68_69  (97 bytes — amiga+cart only, NOT dos)
;   DERIVE_VAR12_11_10_FROM_VAR9  (69 bytes — also in CAPSULE, PRISON, 3-arm)
;   INIT_RANGE_48_TO_4D_TO_MAX  (61 bytes — also in CAPSULE, PRISON, 3-arm)
;   INIT_AI_VARS_AT_280_10  (44 bytes — 3-arm, late-stage object init)
;
; Per-arm split layout:
;   amiga: pre_a, pre_b, post_a, post_b, post_c, post_d, post_e
;   cart:  pre,                post_a, post_b, post_c, post_d, post_e
;   dos:   pre_a, pre_b, post_a,         post_c, post_d, post_e

; Generated by AnotherWorld_VMTools
CINEMATIC_000		EQU 0xDEB0
CINEMATIC_001		EQU 0xBF34
CINEMATIC_002		EQU 0xC9A4
CINEMATIC_003		EQU 0xC0AA
CINEMATIC_004		EQU 0xC0C2
CINEMATIC_005		EQU 0xC13A
CINEMATIC_006		EQU 0xC0E2
CINEMATIC_007		EQU 0xC102
CINEMATIC_WIDE_FLASH_F0		EQU 0xB68E
CINEMATIC_WIDE_FLASH_F1		EQU 0xB6BC
CINEMATIC_WIDE_FLASH_F2		EQU 0xB6D0
CINEMATIC_WIDE_FLASH_F3		EQU 0xB6F0
CINEMATIC_012		EQU 0xD7BC
CINEMATIC_013		EQU 0x5064
CINEMATIC_014		EQU 0xDEF2
CINEMATIC_CAVES_FIGURE_POSE_RIGHT_7_1		EQU 0x4920
CINEMATIC_016		EQU 0x3D7E
CINEMATIC_CAVES_FIGURE_POSE_RIGHT_4_1		EQU 0x48F2
CINEMATIC_018		EQU 0x13E8
CINEMATIC_019		EQU 0x13A8
CINEMATIC_020		EQU 0x1390
CINEMATIC_021		EQU 0x1354
CINEMATIC_022		EQU 0x487C
CINEMATIC_023		EQU 0x48A4
CINEMATIC_024		EQU 0x48BE
CINEMATIC_025		EQU 0xEF7E
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_5		EQU 0xDD24
CINEMATIC_027		EQU 0xEFCA
CINEMATIC_028		EQU 0x4BCE
CINEMATIC_029		EQU 0x4C16
CINEMATIC_030		EQU 0xEF3E
CINEMATIC_031		EQU 0x4C06
CINEMATIC_032		EQU 0xEF76
CINEMATIC_SHIELD_DEPLOY_PHASE_0		EQU 0x1FF6
CINEMATIC_ACTOR_CHARGE_GLOW_F0		EQU 0x2022
CINEMATIC_SHIELD_DEPLOY_PHASE_1		EQU 0x2052
CINEMATIC_SHIELD_DEPLOY_PHASE_2		EQU 0x17D4
CINEMATIC_SHIELD_DEPLOY_PHASE_3		EQU 0x180C
CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_0		EQU 0x4950
CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_1		EQU 0x49A6
CINEMATIC_040		EQU 0x1A9E
CINEMATIC_041		EQU 0xF1F2
CINEMATIC_042		EQU 0x1A1E
CINEMATIC_CAVES_FIGURE_POSE_LEFT_4_3		EQU 0xF22C
CINEMATIC_044		EQU 0x14B0
CINEMATIC_045		EQU 0x147C
CINEMATIC_046		EQU 0x1464
CINEMATIC_047		EQU 0x1428
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_0		EQU 0x0DEE
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_1		EQU 0x497E
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_2		EQU 0x4CD0
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_3		EQU 0x4CEA
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_4		EQU 0xDD00
CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_6		EQU 0xEF22
CINEMATIC_054		EQU 0x4CBC
CINEMATIC_055		EQU 0xF002
CINEMATIC_056		EQU 0xEFE6
CINEMATIC_057		EQU 0x4CA0
CINEMATIC_058		EQU 0xEFFA
CINEMATIC_059		EQU 0x1686
CINEMATIC_060		EQU 0x220C
CINEMATIC_061		EQU 0x4C38
CINEMATIC_062		EQU 0xF01A
CINEMATIC_063		EQU 0x1778
CINEMATIC_064		EQU 0x178C
CINEMATIC_065		EQU 0x17A0
CINEMATIC_066		EQU 0x181A
CINEMATIC_067		EQU 0x17B8
CINEMATIC_ACTOR_CHARGE_GLOW_F1		EQU 0x205E
CINEMATIC_ACTOR_CHARGE_GLOW_F2		EQU 0x208A
CINEMATIC_ACTOR_CHARGE_GLOW_F3		EQU 0x20BA
CINEMATIC_ACTOR_CHARGE_GLOW_F4		EQU 0x20EE
CINEMATIC_ACTOR_CHARGE_GLOW_F5		EQU 0x2122
CINEMATIC_ACTOR_CHARGE_GLOW_F6		EQU 0x212E
CINEMATIC_074		EQU 0x3C26
CINEMATIC_075		EQU 0x3BF6
CINEMATIC_CAVES_SEGMENT_BAR_F0		EQU 0x3876
CINEMATIC_CAVES_SEGMENT_BAR_F1		EQU 0x3928
CINEMATIC_CAVES_SEGMENT_BAR_F2		EQU 0x393E
CINEMATIC_CAVES_SEGMENT_BAR_F3		EQU 0x3956
CINEMATIC_XRAY_FLASH_LEFT		EQU 0x4448
CINEMATIC_XRAY_SKELETON_LEFT_LIT		EQU 0x44C0
CINEMATIC_XRAY_SKELETON_LEFT_DARK		EQU 0x4558
CINEMATIC_FALLING_DEBRIS_F0		EQU 0x3364
CINEMATIC_FALLING_DEBRIS_F1		EQU 0x3424
CINEMATIC_FALLING_DEBRIS_F2		EQU 0x34B4
CINEMATIC_FALLING_DEBRIS_F3		EQU 0x3544
CINEMATIC_FALLING_DEBRIS_F4		EQU 0x35D0
CINEMATIC_FALLING_DEBRIS_F5		EQU 0x3650
CINEMATIC_FALLING_DEBRIS_F6		EQU 0x36B8
CINEMATIC_FALLING_DEBRIS_F7		EQU 0x3718
CINEMATIC_XRAY_FLASH_RIGHT		EQU 0x265C
CINEMATIC_XRAY_SKELETON_RIGHT_LIT		EQU 0x26D4
CINEMATIC_XRAY_SKELETON_RIGHT_DARK		EQU 0x27D2
CINEMATIC_094		EQU 0x1C7A
CINEMATIC_095		EQU 0x1D02
CINEMATIC_096		EQU 0x1DC4
CINEMATIC_097		EQU 0x1DFC
CINEMATIC_BLAST_MARK		EQU 0x3134
CINEMATIC_BLAST_DEBRIS_F0		EQU 0x3068
CINEMATIC_BLAST_DEBRIS_F1		EQU 0x3148
CINEMATIC_BLAST_DEBRIS_F2		EQU 0x31D4
CINEMATIC_BLAST_DEBRIS_SETTLED_0		EQU 0x324C
CINEMATIC_BLAST_DEBRIS_F3		EQU 0x3274
CINEMATIC_BLAST_DEBRIS_F4		EQU 0x32B0
CINEMATIC_BLAST_DEBRIS_F5		EQU 0x3304
CINEMATIC_BLAST_DEBRIS_SETTLED_1		EQU 0x3344
CINEMATIC_107		EQU 0x1AD2
CINEMATIC_108		EQU 0x1B4E
CINEMATIC_109		EQU 0x1C3E
CINEMATIC_TUMBLING_CHUNK_F0		EQU 0x1E30
CINEMATIC_TUMBLING_CHUNK_F1		EQU 0x1E70
CINEMATIC_TUMBLING_CHUNK_F2		EQU 0x1E78
CINEMATIC_TUMBLING_CHUNK_F3		EQU 0x1E80
CINEMATIC_TUMBLING_CHUNK_F4		EQU 0x1E88
CINEMATIC_TUMBLING_CHUNK_F5		EQU 0x1E90
CINEMATIC_TUMBLING_CHUNK_F6		EQU 0x1E98
CINEMATIC_TUMBLING_CHUNK_F7		EQU 0x1EA0
CINEMATIC_TUMBLING_CHUNK_F8		EQU 0x1EA8
CINEMATIC_TUMBLING_CHUNK_F9		EQU 0x1EB0
CINEMATIC_TUMBLING_CHUNK_F10		EQU 0x1EB8
CINEMATIC_TUMBLING_CHUNK_F11		EQU 0x1EC0
CINEMATIC_TUMBLING_CHUNK_F12		EQU 0x1EDC
CINEMATIC_TUMBLING_CHUNK_F13		EQU 0x1EE4
CINEMATIC_124		EQU 0x4306
CINEMATIC_125		EQU 0x4376
CINEMATIC_126		EQU 0x4408
CINEMATIC_HERO_DEATH_F0		EQU 0x41FE
CINEMATIC_HERO_DEATH_F1		EQU 0x4262
CINEMATIC_HERO_DEATH_F2		EQU 0x42CA
CINEMATIC_CAVES_DISCHARGE_FLASH_F0		EQU 0x38A4
CINEMATIC_CAVES_DISCHARGE_FLASH_F1		EQU 0x38FC
CINEMATIC_CAVES_CHARGE_GLOW_F0		EQU 0x38D0
CINEMATIC_CAVES_CHARGE_GLOW_F1		EQU 0x39B6
CINEMATIC_CAVES_CHARGE_BLAST		EQU 0x3B16
CINEMATIC_CAVES_CHARGE_GLOW_F2		EQU 0x396E
CINEMATIC_CAVES_CHARGE_GLOW_F3		EQU 0x399A
CINEMATIC_137		EQU 0x3C62
CINEMATIC_138		EQU 0x3C32
CINEMATIC_139		EQU 0x4840
CINEMATIC_140		EQU 0x485E
CINEMATIC_141		EQU 0x4D6A
CINEMATIC_142		EQU 0xC66E
CINEMATIC_CAVES_SWINGING_LIMB_F0		EQU 0xC6E0
CINEMATIC_CAVES_SWINGING_LIMB_F1		EQU 0xC6EC
CINEMATIC_CAVES_SWINGING_LIMB_F2		EQU 0xC6F8
CINEMATIC_CAVES_SWINGING_LIMB_F3		EQU 0xC704
CINEMATIC_CAVES_SWINGING_LIMB_F4		EQU 0xC710
CINEMATIC_148		EQU 0xFCE4
CINEMATIC_149		EQU 0xFC9C
CINEMATIC_150		EQU 0xFCA4
CINEMATIC_151		EQU 0xFCAC
CINEMATIC_SHIELD_DECAY_PHASE_3		EQU 0x1866
CINEMATIC_SHIELD_DECAY_PHASE_1_DEFAULT		EQU 0x2A56
CINEMATIC_SHIELD_DECAY_PHASE_2		EQU 0x2A3E
CINEMATIC_SHIELD_DECAY_PHASE_2_CASE_01		EQU 0x2A26
CINEMATIC_156		EQU 0x2A6A
CINEMATIC_SHIELD_DECAY_PHASE_1		EQU 0x2A7C
CINEMATIC_CAVES_HERO_CROUCH_DOWN_RIGHT		EQU 0x056C
CINEMATIC_CAVES_HERO_STAND_ARMED_RIGHT		EQU 0x05D0
CINEMATIC_160		EQU 0x0714
CINEMATIC_CAVES_HERO_STAND_ARMED_LEFT		EQU 0x0738
CINEMATIC_162		EQU 0xFC84
CINEMATIC_163		EQU 0xFC8C
CINEMATIC_164		EQU 0xFC94
CINEMATIC_165		EQU 0xFCB4
CINEMATIC_CAVES_HERO_CROUCH_LEFT		EQU 0x06F0
CINEMATIC_167		EQU 0x49FE
CINEMATIC_168		EQU 0x1886
CINEMATIC_169		EQU 0x49D6
CINEMATIC_HERO_LIFTOFF		EQU 0x02D8
CINEMATIC_171		EQU 0xFC6C
CINEMATIC_172		EQU 0xFC74
CINEMATIC_173		EQU 0xFC7C
CINEMATIC_174		EQU 0x06CC
CINEMATIC_175		EQU 0xFC32
CINEMATIC_HERO_STAND_AIM_RIGHT		EQU 0x102C
CINEMATIC_177		EQU 0xFC10
CINEMATIC_178		EQU 0xFC3A
CINEMATIC_179		EQU 0xC614
CINEMATIC_180		EQU 0xC650
CINEMATIC_181		EQU 0xC632
CINEMATIC_182		EQU 0xC718
CINEMATIC_183		EQU 0xC740
CINEMATIC_184		EQU 0xC784
CINEMATIC_185		EQU 0xCA7C
CINEMATIC_186		EQU 0xC45E
CINEMATIC_187		EQU 0xC4CA
CINEMATIC_188		EQU 0xC52C
CINEMATIC_189		EQU 0xC57E
CINEMATIC_190		EQU 0x4D54
CINEMATIC_191		EQU 0xCD2A
CINEMATIC_192		EQU 0xCD42
CINEMATIC_193		EQU 0xCD5E
CINEMATIC_CAVES_SHATTER_F0		EQU 0xCD7E
CINEMATIC_CAVES_SHATTER_F1		EQU 0xCDA0
CINEMATIC_CAVES_SHATTER_F2		EQU 0xCDEE
CINEMATIC_CAVES_SHATTER_F3		EQU 0xCE56
CINEMATIC_CAVES_SHATTER_F4		EQU 0xCEB8
CINEMATIC_CAVES_SHATTER_F5		EQU 0xCE7A
CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_0		EQU 0x6636
CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_1		EQU 0x6682
CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_2		EQU 0x66DA
CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_3		EQU 0x6736
CINEMATIC_CAVES_GANTRY_PLATFORMS_BG_4		EQU 0x67B2
CINEMATIC_205		EQU 0x4DD0
CINEMATIC_CAVES_SCREEN_45_BACKDROP_LAYER_0		EQU 0x67FE
CINEMATIC_CAVES_SCREEN_45_BACKDROP_LAYER_1		EQU 0x6D9C
CINEMATIC_CAVES_SCREEN_45_BACKDROP_LAYER_2		EQU 0xB04E
CINEMATIC_CAVES_SCREEN_45_BACKDROP_LAYER_3		EQU 0xE85C
CINEMATIC_210		EQU 0x2B96
CINEMATIC_211		EQU 0x1F24
CINEMATIC_212		EQU 0xD7A6
CINEMATIC_CAVES_CRACK_SPREAD_F0		EQU 0xE1AC
CINEMATIC_CAVES_CRACK_SPREAD_F1		EQU 0xE200
CINEMATIC_CAVES_CRACK_SPREAD_F2		EQU 0xE26C
CINEMATIC_CAVES_CRACK_SPREAD_F3		EQU 0xE2E0
CINEMATIC_CAVES_CRACK_SPREAD_F4		EQU 0xE354
CINEMATIC_CAVES_CRACK_SPREAD_F5		EQU 0xE3D8
CINEMATIC_CAVES_CRACK_SPREAD_F6		EQU 0xE464
CINEMATIC_CAVES_CRACK_SPREAD_F7		EQU 0xE4E8
CINEMATIC_CAVES_CRACK_SPREAD_F8		EQU 0xE584
CINEMATIC_CAVES_CRACK_SPREAD_F9		EQU 0xE61C
CINEMATIC_223		EQU 0xD804
CINEMATIC_224		EQU 0xDA5C
CINEMATIC_225		EQU 0xD8FC
CINEMATIC_226		EQU 0xD968
CINEMATIC_227		EQU 0xD888
CINEMATIC_228		EQU 0xDBEC
CINEMATIC_229		EQU 0xDC58
CINEMATIC_230		EQU 0xDB78
CINEMATIC_231		EQU 0xDAF4
CINEMATIC_232		EQU 0xD9DC
CINEMATIC_233		EQU 0xED7A
CINEMATIC_234		EQU 0xEE66
CINEMATIC_235		EQU 0xEE2E
CINEMATIC_236		EQU 0xEDF2
CINEMATIC_CAVES_HERO_STAND_AIM_LEFT		EQU 0x1274
CINEMATIC_CAVES_HERO_STAND_SHOOT_LEFT_F1		EQU 0x112A
CINEMATIC_CAVES_SPINNING_SPIKE_0_F0		EQU 0xF0AA
CINEMATIC_CAVES_SPINNING_SPIKE_0_F1		EQU 0xF0C2
CINEMATIC_CAVES_SPINNING_SPIKE_0_F2		EQU 0xF0DA
CINEMATIC_CAVES_SPINNING_SPIKE_0_F3		EQU 0xF0FA
CINEMATIC_CAVES_SPINNING_SPIKE_0_F4		EQU 0xF112
CINEMATIC_CAVES_SPINNING_SPIKE_0_F5		EQU 0xF132
CINEMATIC_CAVES_SPINNING_SPIKE_0_F6		EQU 0xF14A
CINEMATIC_246		EQU 0xEE72
CINEMATIC_247		EQU 0xEEAC
CINEMATIC_248		EQU 0xEEE2
CINEMATIC_249		EQU 0xD008
CINEMATIC_250		EQU 0xD06C
CINEMATIC_251		EQU 0xD09C
CINEMATIC_252		EQU 0xD0C4
CINEMATIC_253		EQU 0x71FA
CINEMATIC_254		EQU 0x71BA
CINEMATIC_255		EQU 0x71CA
CINEMATIC_256		EQU 0x71DA
CINEMATIC_257		EQU 0x71EA
CINEMATIC_CAVES_SCREEN_46_BACKDROP_0		EQU 0x6FDA
CINEMATIC_CAVES_SCREEN_46_BACKDROP_1		EQU 0x70EA
CINEMATIC_CAVES_SCREEN_46_BACKDROP_2		EQU 0xE870
CINEMATIC_261		EQU 0xB562
CINEMATIC_262		EQU 0xB66A
CINEMATIC_263		EQU 0xB646
CINEMATIC_264		EQU 0xB622
CINEMATIC_265		EQU 0xB5EA
CINEMATIC_266		EQU 0xB70A
CINEMATIC_267		EQU 0xB756
CINEMATIC_268		EQU 0xB76A
CINEMATIC_269		EQU 0xDD84
CINEMATIC_270		EQU 0xF178
CINEMATIC_271		EQU 0xF1B6
CINEMATIC_272		EQU 0xA3BC
CINEMATIC_273		EQU 0xA440
CINEMATIC_CAVES_SCREEN_49_BACKDROP_LAYER_0		EQU 0xA540
CINEMATIC_CAVES_LEDGE_SEGMENT		EQU 0x7442
CINEMATIC_276		EQU 0xFBBC
CINEMATIC_277		EQU 0xF304
CINEMATIC_278		EQU 0x779C
CINEMATIC_CAVES_WATERFALL		EQU 0x7640
CINEMATIC_CAVES_FALLING_STREAK_F0		EQU 0xDF1C
CINEMATIC_CAVES_FALLING_STREAK_F1		EQU 0xDF58
CINEMATIC_CAVES_FALLING_STREAK_F2		EQU 0xDF90
CINEMATIC_CAVES_BAR_CLUSTER_F0		EQU 0xEB72
CINEMATIC_CAVES_BAR_CLUSTER_F1		EQU 0xEB4C
CINEMATIC_CAVES_BAR_CLUSTER_F2		EQU 0xED54
CINEMATIC_CAVES_SPRAY_LINE_F0		EQU 0xEA34
CINEMATIC_CAVES_SPRAY_LINE_F1		EQU 0xEA80
CINEMATIC_CAVES_SPRAY_LINE_F2		EQU 0xEAC0
CINEMATIC_CAVES_DROPLET_F0		EQU 0x7BC8
CINEMATIC_CAVES_DROPLET_F1		EQU 0x7C04
CINEMATIC_CAVES_DROPLET_F2		EQU 0x7C1C
CINEMATIC_CAVES_DROPLET_F3		EQU 0x7C48
CINEMATIC_CAVES_DROPLET_F4		EQU 0x7C38
CINEMATIC_294		EQU 0x7C8C
CINEMATIC_WATERFALL_LEFT_STAIRS_BG		EQU 0x7C64
CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0		EQU 0x748A
CINEMATIC_CAVES_BUDDY_CRAWLING_BG_1		EQU 0x750E
CINEMATIC_CAVES_BUDDY_CRAWLING_BG_2		EQU 0xACBC
CINEMATIC_CAVES_BUDDY_CRAWLING_BG_3		EQU 0xAE98
CINEMATIC_CAVES_WATERFALL_BG		EQU 0xAFDC
CINEMATIC_CAVES_WATERFALL_DRIP_F0		EQU 0xAF40
CINEMATIC_CAVES_WATERFALL_DRIP_F1		EQU 0xAF48
CINEMATIC_CAVES_WATERFALL_DRIP_F2		EQU 0xAF54
CINEMATIC_CAVES_WATERFALL_DRIP_F3		EQU 0xAF64
CINEMATIC_CAVES_WATERFALL_DRIP_F4		EQU 0xAF78
CINEMATIC_CAVES_WATERFALL_DRIP_F5		EQU 0xAF8C
CINEMATIC_CAVES_WATERFALL_DRIP_F6		EQU 0xAFA0
CINEMATIC_CAVES_WATERFALL_DRIP_F7		EQU 0xAFB4
CINEMATIC_CAVES_WATERFALL_DRIP_F8		EQU 0xAFC8
CINEMATIC_310		EQU 0xB7E2
CINEMATIC_311		EQU 0xB878
CINEMATIC_312		EQU 0xB958
CINEMATIC_313		EQU 0xB8C4
CINEMATIC_314		EQU 0xB7B8
CINEMATIC_315		EQU 0xB904
CINEMATIC_316		EQU 0xB92E
CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING		EQU 0x7828
CINEMATIC_318		EQU 0xA7D6
CINEMATIC_319		EQU 0x7870
CINEMATIC_320		EQU 0x7B1C
CINEMATIC_321		EQU 0x7B40
CINEMATIC_322		EQU 0x7B64
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F0		EQU 0x78B4
CINEMATIC_324		EQU 0xB78E
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F1		EQU 0x7936
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F2		EQU 0x7A5E
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F3		EQU 0x7A8C
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F4		EQU 0x7ABC
CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F5		EQU 0x7AEC
CINEMATIC_330		EQU 0xB80C
CINEMATIC_331		EQU 0xC1AA
CINEMATIC_CAVES_SCREEN_4C_CAVERN_COLUMNS		EQU 0xA58C
CINEMATIC_CAVES_SCREEN_4C_CAVERN_ARCH		EQU 0xB010
CINEMATIC_CAVES_DIAGONAL_GIRDER		EQU 0xE8BA
CINEMATIC_CAVES_ROCK_FLECK		EQU 0xAC84
CINEMATIC_CAVES_DRIFT_MOTE		EQU 0xACB0
CINEMATIC_CAVES_GLOW_STONE		EQU 0xABF8
CINEMATIC_338		EQU 0xAFF8
CINEMATIC_339		EQU 0x77C8
CINEMATIC_CAVES_SCREEN_4D_ARCHES		EQU 0xA5D4
CINEMATIC_CAVES_SCREEN_4D_CAVERN_COLUMNS		EQU 0xB0B4
CINEMATIC_CAVES_SCREEN_4D_ROCK_CORNER		EQU 0xAC40
CINEMATIC_CAVES_SCREEN_4E_BACKDROP_LAYER_0		EQU 0xB0EE
CINEMATIC_CAVES_SCREEN_4F_BACKDROP_LAYER_0		EQU 0xB13E
CINEMATIC_CAVES_SCREEN_4F_BACKDROP_LAYER_1		EQU 0xB16E
CINEMATIC_CAVES_RING_OUTLINE		EQU 0xE8AC
CINEMATIC_347		EQU 0x6896
CINEMATIC_CAVES_CAVERN_DOME		EQU 0x8174
CINEMATIC_CAVES_SCREEN_50_BACKDROP_LAYER_1		EQU 0xB18A
CINEMATIC_CAVES_SCREEN_50_BACKDROP_LAYER_2		EQU 0xA802
CINEMATIC_351		EQU 0x7998
CINEMATIC_352		EQU 0xE6C2
CINEMATIC_353		EQU 0x7D54
CINEMATIC_354		EQU 0xC264
CINEMATIC_355		EQU 0xC258
CINEMATIC_356		EQU 0x7D38
CINEMATIC_357		EQU 0xC24C
CINEMATIC_358		EQU 0x7D1C
CINEMATIC_359		EQU 0xC240
CINEMATIC_360		EQU 0x7D00
CINEMATIC_361		EQU 0xC234
CINEMATIC_362		EQU 0xC228
CINEMATIC_363		EQU 0x7CE4
CINEMATIC_364		EQU 0xC21C
CINEMATIC_365		EQU 0x7CC8
CINEMATIC_366		EQU 0xC210
CINEMATIC_367		EQU 0x7BA0
CINEMATIC_368		EQU 0xE01C
CINEMATIC_369		EQU 0xE00E
CINEMATIC_370		EQU 0xDFDE
CINEMATIC_371		EQU 0xDFC4
CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0		EQU 0x99DC
CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_1		EQU 0x9A38
CINEMATIC_374		EQU 0xED08
CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_0		EQU 0x9982
CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_1		EQU 0x991E
CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_2		EQU 0xA49E
CINEMATIC_378		EQU 0xF3AC
CINEMATIC_379		EQU 0x99C8
CINEMATIC_380		EQU 0x4DB4
CINEMATIC_381		EQU 0xF38C
CINEMATIC_382		EQU 0xF39C
CINEMATIC_383		EQU 0xF36C
CINEMATIC_384		EQU 0x4DA4
CINEMATIC_385		EQU 0xF37C
CINEMATIC_386		EQU 0xD7D8
CINEMATIC_CAVES_SCREEN_69_BACKDROP_LAYER_0		EQU 0x9A5C
CINEMATIC_CAVES_SCREEN_69_BACKDROP_LAYER_1		EQU 0xDDB4
CINEMATIC_389		EQU 0xF2FA
CINEMATIC_390		EQU 0xEB98
CINEMATIC_391		EQU 0xEBCA
CINEMATIC_392		EQU 0xEC14
CINEMATIC_CAVES_FIRST_ROOM_BG_F0		EQU 0xEC5E
CINEMATIC_CAVES_FIRST_ROOM_BG_F1		EQU 0x80C8
CINEMATIC_CAVES_ROCK_ARC_LARGE		EQU 0xE6FC
CINEMATIC_CAVES_SCREEN_6B_BACKDROP_LAYER_14		EQU 0xA714
CINEMATIC_397		EQU 0xA782
CINEMATIC_398		EQU 0xA7A6
CINEMATIC_399		EQU 0xA7BE
CINEMATIC_400		EQU 0xE026
CINEMATIC_401		EQU 0xA66E
CINEMATIC_CAVES_WALL_BREACH_STRAND		EQU 0xA6B8
CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F0		EQU 0xA6CC
CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F1		EQU 0xA6E4
CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F2		EQU 0xA6FC
CINEMATIC_CAVES_SCREEN_6C_ROCK_ARC_SMALL		EQU 0xE6D0
CINEMATIC_CAVES_SCREEN_6C_DRIFT_MOTE_CLUSTER		EQU 0xE760
CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMNS		EQU 0xB302
CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMN_LARGE		EQU 0xB33E
CINEMATIC_CAVES_SCREEN_6C_STALAGMITE		EQU 0xE748
CINEMATIC_CAVES_SCREEN_6C_FLAT_SLIVER		EQU 0xE7B0
CINEMATIC_412		EQU 0xF310
CINEMATIC_CAVES_SCREEN_6D_BACKDROP_0		EQU 0xF65C
CINEMATIC_CAVES_SCREEN_6D_BACKDROP_1		EQU 0xF696
CINEMATIC_CAVES_SCREEN_6D_BACKDROP_2		EQU 0xDDCE
CINEMATIC_CAVES_SPINNING_SPIKE_1_F0		EQU 0xFB76
CINEMATIC_CAVES_SPINNING_SPIKE_1_F1		EQU 0xFB80
CINEMATIC_CAVES_SPINNING_SPIKE_1_F3		EQU 0xFB94
CINEMATIC_CAVES_SPINNING_SPIKE_1_F4		EQU 0xFB9E
CINEMATIC_CAVES_SPINNING_SPIKE_1_F5		EQU 0xFBA8
CINEMATIC_CAVES_SPINNING_SPIKE_1_F6		EQU 0xFBB2
CINEMATIC_CAVES_SPINNING_SPIKE_1_F2		EQU 0xFB8A
CINEMATIC_CAVES_DROPPED_GUN		EQU 0xCAB0
CINEMATIC_424		EQU 0x0020
CINEMATIC_425		EQU 0xB24E
CINEMATIC_426		EQU 0xC272
CINEMATIC_427		EQU 0xC436
CINEMATIC_428		EQU 0xC2DE
CINEMATIC_429		EQU 0xC352
CINEMATIC_430		EQU 0xC3C2
CINEMATIC_CAVES_HERO_PRONE_TRANSITION_LEFT_F04		EQU 0x3A76
CINEMATIC_432		EQU 0xB362
CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_0		EQU 0x7E8C
CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_1		EQU 0x7EA4
CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_2		EQU 0x7ED8
CINEMATIC_CAVES_BACKDROP_FIELD_LARGE		EQU 0x8D74
CINEMATIC_437		EQU 0xE032
CINEMATIC_CAVES_LANDING_SPLASH_F0		EQU 0x7EF0
CINEMATIC_CAVES_LANDING_SPLASH_F1		EQU 0x7F38
CINEMATIC_CAVES_LANDING_SPLASH_F2		EQU 0x7F60
CINEMATIC_CAVES_LANDING_SPLASH_F3		EQU 0x7FAC
CINEMATIC_CAVES_LANDING_SPLASH_F4		EQU 0x7FE0
CINEMATIC_CAVES_LANDING_SPLASH_F5		EQU 0x8D8C
CINEMATIC_CAVES_LANDING_SPLASH_F6		EQU 0x8DD0
CINEMATIC_CAVES_LANDING_SPLASH_F7		EQU 0x8E0C
CINEMATIC_CAVES_LANDING_SPLASH_F8		EQU 0x8E52
CINEMATIC_CAVES_LANDING_SPLASH_F9		EQU 0x8E84
CINEMATIC_448		EQU 0x8CEA
CINEMATIC_449		EQU 0x8D06
CINEMATIC_CAVES_HERO_IDLE_DOWN_0		EQU 0x5F4C
CINEMATIC_HERO_SWIM_PITCH_RIGHT_0		EQU 0x97DA
CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_0		EQU 0x984A
CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_1		EQU 0x98B6
CINEMATIC_454		EQU 0x5F9C
CINEMATIC_CAVES_HERO_IDLE_DOWN_2		EQU 0x5FC8
CINEMATIC_456		EQU 0x5FF4
CINEMATIC_CAVES_HERO_IDLE_DOWN_4		EQU 0x6020
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F0		EQU 0x60A8
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F1		EQU 0x60DC
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F2		EQU 0x60F8
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F3		EQU 0x6114
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F4		EQU 0x6130
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F5		EQU 0x6148
CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F6		EQU 0x6164
CINEMATIC_465		EQU 0x617C
CINEMATIC_466		EQU 0x6194
CINEMATIC_467		EQU 0x61B4
CINEMATIC_468		EQU 0x61CC
CINEMATIC_HERO_SWIM_PITCH_LEFT_0		EQU 0x5C08
CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_0		EQU 0x5C78
CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_1		EQU 0x5CE4
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_0		EQU 0x96EE
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_1		EQU 0x9756
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_2		EQU 0x97BA
CINEMATIC_CAVES_HERO_IDLE_UP_0		EQU 0x963E
CINEMATIC_CAVES_HERO_IDLE_UP_1		EQU 0x965A
CINEMATIC_CAVES_HERO_IDLE_UP_2		EQU 0x9676
CINEMATIC_CAVES_HERO_IDLE_UP_3		EQU 0x9692
CINEMATIC_CAVES_HERO_IDLE_UP_4		EQU 0x96AE
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F0		EQU 0xF26E
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F1		EQU 0xF27A
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F2		EQU 0xF286
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F3		EQU 0xF292
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F4		EQU 0xF29E
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F5		EQU 0xF2AA
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F6		EQU 0xF2B6
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F7		EQU 0xF2C2
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F8		EQU 0xF2CE
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F9		EQU 0xF2E2
CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F10		EQU 0xF2EE
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_0		EQU 0x93F4
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_1		EQU 0x9454
CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_2		EQU 0x96DA
CINEMATIC_HERO_SWIM_PITCH_RIGHT_1		EQU 0xBA18
CINEMATIC_HERO_SWIM_PITCH_RIGHT_2		EQU 0xBA76
CINEMATIC_HERO_SWIM_PITCH_RIGHT_3		EQU 0xBAC0
CINEMATIC_HERO_SWIM_PITCH_RIGHT_4		EQU 0xBB08
CINEMATIC_HERO_SWIM_PITCH_RIGHT_5		EQU 0xBB50
CINEMATIC_HERO_SWIM_PITCH_LEFT_1		EQU 0xE03E
CINEMATIC_HERO_SWIM_PITCH_LEFT_2		EQU 0xE09C
CINEMATIC_HERO_SWIM_PITCH_LEFT_3		EQU 0xE0E4
CINEMATIC_HERO_SWIM_PITCH_LEFT_4		EQU 0xE12C
CINEMATIC_HERO_SWIM_PITCH_LEFT_5		EQU 0xE168
CINEMATIC_RISING_SPECKS_0		EQU 0xDE12
CINEMATIC_RISING_SPECKS_1		EQU 0xDE42
CINEMATIC_RISING_SPECKS_2		EQU 0xDE5A
CINEMATIC_RISING_SPECKS_3		EQU 0xDE72
CINEMATIC_RISING_SPECKS_4		EQU 0xDE9A
CINEMATIC_509		EQU 0x628C
CINEMATIC_510		EQU 0x6324
CINEMATIC_CAVES_HERO_IDLE_RIGHT_0		EQU 0x6388
CINEMATIC_CAVES_HERO_IDLE_RIGHT_1		EQU 0x63B0
CINEMATIC_CAVES_HERO_IDLE_RIGHT_2		EQU 0x63D8
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F0		EQU 0x640C
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F1		EQU 0x6414
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F2		EQU 0x641C
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F3		EQU 0x6424
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F4		EQU 0x646C
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F5		EQU 0x6474
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F6		EQU 0x6480
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F7		EQU 0x648C
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F8		EQU 0x6498
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F9		EQU 0x64A4
CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F10		EQU 0x64B0
CINEMATIC_CAVES_HERO_TURN_0		EQU 0xCC6E
CINEMATIC_CAVES_HERO_TURN_1		EQU 0xCC46
CINEMATIC_CAVES_HERO_TURN_2		EQU 0xCC1E
CINEMATIC_CAVES_HERO_TURN_3		EQU 0xCC96
CINEMATIC_CAVES_HERO_TURN_4		EQU 0xCBF6
CINEMATIC_CAVES_HERO_TURN_5		EQU 0xCBC2
CINEMATIC_CAVES_HERO_TURN_6		EQU 0xCB9A
CINEMATIC_CAVES_HERO_TURN_7		EQU 0xCB72
CINEMATIC_CAVES_HERO_TURN_8		EQU 0xCB4A
CINEMATIC_CAVES_HERO_IDLE_RIGHT_4		EQU 0x7D7C
CINEMATIC_CAVES_RIPPLE_LINE_F1		EQU 0x7DB0
CINEMATIC_CAVES_RIPPLE_LINE_F2		EQU 0x7DEC
CINEMATIC_CAVES_SCREEN_70_BACKDROP_LAYER_0		EQU 0xE81C
CINEMATIC_538		EQU 0xF030
CINEMATIC_539		EQU 0x0AE8
CINEMATIC_540		EQU 0xF42A
CINEMATIC_541		EQU 0xB090
CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_0		EQU 0xF5EE
CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_1		EQU 0xF636
CINEMATIC_544		EQU 0xFACA
CINEMATIC_545		EQU 0x4D20
CINEMATIC_546		EQU 0xF850
CINEMATIC_547		EQU 0xF96E
CINEMATIC_548		EQU 0xF99A
CINEMATIC_549		EQU 0xF9C6
CINEMATIC_550		EQU 0xF9FA
CINEMATIC_551		EQU 0xFA2A
CINEMATIC_552		EQU 0xFA56
CINEMATIC_553		EQU 0xFA82
CINEMATIC_554		EQU 0x4A24
CINEMATIC_555		EQU 0xFAAA
CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4		EQU 0xF750
CINEMATIC_557		EQU 0xF95E
CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5		EQU 0xF94A
CINEMATIC_559		EQU 0xF780
CINEMATIC_560		EQU 0xF7B4
CINEMATIC_561		EQU 0xF848
CINEMATIC_562		EQU 0xF858
CINEMATIC_563		EQU 0xF91A
CINEMATIC_564		EQU 0xF8F6
CINEMATIC_565		EQU 0xF8D2
CINEMATIC_566		EQU 0xF8AE
CINEMATIC_567		EQU 0xF888
CINEMATIC_568		EQU 0xF864
CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_0		EQU 0x5AEA
CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_1		EQU 0x5BA2
CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_2		EQU 0xC874
CINEMATIC_CAVES_COLUMN_EMERGE_F0		EQU 0x8D22
CINEMATIC_CAVES_COLUMN_EMERGE_F1		EQU 0x8D3E
CINEMATIC_CAVES_COLUMN_EMERGE_F2		EQU 0x9580
CINEMATIC_CAVES_COLUMN_EMERGE_F3		EQU 0x95D2
CINEMATIC_CAVES_COLUMN_EMERGE_F4		EQU 0xC7B8
CINEMATIC_CAVES_COLUMN_EMERGE_F5		EQU 0xC804
CINEMATIC_CAVES_COLUMN_EMERGE_F6		EQU 0xC83E
CINEMATIC_579		EQU 0x4F70
CINEMATIC_580		EQU 0xF35C
CINEMATIC_CAVES_SCREEN_88_BACKDROP_0		EQU 0x55B8
CINEMATIC_CAVES_SCREEN_88_BACKDROP_1		EQU 0x5408
CINEMATIC_CAVES_SCREEN_88_BACKDROP_2		EQU 0x9AD8
CINEMATIC_584		EQU 0xF348
CINEMATIC_CAVES_SCREEN_89_BACKDROP_LAYER_0		EQU 0x598E
CINEMATIC_CAVES_SCREEN_89_BACKDROP_LAYER_1		EQU 0x5A72
CINEMATIC_587		EQU 0x9ABC
CINEMATIC_588		EQU 0x58E6
CINEMATIC_CAVES_SCREEN_8A_CAVERN_WALL		EQU 0x5084
CINEMATIC_CAVES_SCREEN_8A_CAVERN_RIDGE		EQU 0x52B8
CINEMATIC_591		EQU 0x8A28
CINEMATIC_592		EQU 0x8A64
CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_0		EQU 0x8120
CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_1		EQU 0x8140
CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_2		EQU 0xA478
CINEMATIC_CAVES_BACKDROP_FIELD_MEDIUM		EQU 0x9AA4
CINEMATIC_597		EQU 0xF09E
CINEMATIC_598		EQU 0xC89C
CINEMATIC_599		EQU 0x2420
CINEMATIC_600		EQU 0xD630
CINEMATIC_601		EQU 0xD658
CINEMATIC_602		EQU 0xD692
CINEMATIC_603		EQU 0xD6DE
CINEMATIC_604		EQU 0xD71A
CINEMATIC_605		EQU 0xD75A
CINEMATIC_CAVES_CAVERN_WALL_AND_FLOOR		EQU 0xB3A2
CINEMATIC_CAVES_SCREEN_91_GLOW_MOUND		EQU 0xE9D0
CINEMATIC_CAVES_SCREEN_91_COLUMN_0		EQU 0xF3F8
CINEMATIC_CAVES_SCREEN_91_COLUMN_1		EQU 0xF400
CINEMATIC_CAVES_SCREEN_91_COLUMN_2		EQU 0x80F8
CINEMATIC_CAVES_SCREEN_91_COLUMN_3		EQU 0xF528
CINEMATIC_612		EQU 0xF46E
CINEMATIC_613		EQU 0xF4DC
CINEMATIC_614		EQU 0xF56C
CINEMATIC_615		EQU 0xF556
CINEMATIC_616		EQU 0x563C
CINEMATIC_CAVES_SCREEN_92_BACKDROP_LAYER_1		EQU 0xB3D2
CINEMATIC_618		EQU 0xE8F2
CINEMATIC_CAVES_SCREEN_93_BACKDROP_LAYER_1		EQU 0xB406
CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_2		EQU 0xB3C6
CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_3		EQU 0xF6BC
CINEMATIC_622		EQU 0x726E
CINEMATIC_623		EQU 0x72AA
CINEMATIC_CAVES_FALLING_ROCK_MEDIUM		EQU 0xCF2C
CINEMATIC_CAVES_FALLING_ROCK_SMALL		EQU 0xCED4
CINEMATIC_626		EQU 0x938E
CINEMATIC_627		EQU 0xA3AE
CINEMATIC_628		EQU 0x93A6
CINEMATIC_629		EQU 0x9362
CINEMATIC_630		EQU 0x93B2
CINEMATIC_631		EQU 0xF324
CINEMATIC_632		EQU 0xF334
CINEMATIC_CAVES_SCREEN_A8_BACKDROP_LAYER_0		EQU 0xA81A
CINEMATIC_CAVES_SHAFT_COLUMN		EQU 0xAE40
CINEMATIC_CAVES_SCREEN_AD_BACKDROP_LAYER_0		EQU 0xCCBE
CINEMATIC_CAVES_SCREEN_AD_BACKDROP_FIELD_SMALL		EQU 0x9AB0
CINEMATIC_637		EQU 0xFB02
CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_0		EQU 0x9AF0
CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_1		EQU 0x721E
CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_2		EQU 0xA242
CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_3		EQU 0xEC9C
CINEMATIC_642		EQU 0xA2FA
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0		EQU 0x9F44
CINEMATIC_644		EQU 0xBBFC
CINEMATIC_645		EQU 0xBC40
CINEMATIC_646		EQU 0xBCB0
CINEMATIC_647		EQU 0xBD1C
CINEMATIC_648		EQU 0xBD88
CINEMATIC_649		EQU 0xBDDC
CINEMATIC_650		EQU 0xBE1C
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F1		EQU 0x9FB6
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F2		EQU 0xA006
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F3		EQU 0xA076
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F4		EQU 0xA0E2
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F5		EQU 0xA14E
CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F6		EQU 0xA1A2
CINEMATIC_657		EQU 0xA1E2
CINEMATIC_658		EQU 0xA34E
CINEMATIC_659		EQU 0xA36C
CINEMATIC_660		EQU 0x89CE
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F0		EQU 0x8786
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F1		EQU 0x87E4
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F2		EQU 0x8842
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F3		EQU 0x8FDA
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F4		EQU 0x8FE6
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F5		EQU 0x9002
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F6		EQU 0x907E
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F7		EQU 0x90EE
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F8		EQU 0x911E
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F9		EQU 0x918A
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F10		EQU 0x91D6
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F11		EQU 0x9236
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F12		EQU 0x928A
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F13		EQU 0x92E6
CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F14		EQU 0x932E
CINEMATIC_CAVES_BURST_CHUNKS_F0		EQU 0xD274
CINEMATIC_CAVES_BURST_STREAKS_F0		EQU 0xD5B0
CINEMATIC_CAVES_BURST_CHUNKS_F1		EQU 0xD1FC
CINEMATIC_CAVES_BURST_STREAKS_F1		EQU 0xD298
CINEMATIC_CAVES_BURST_CHUNKS_F2		EQU 0xD250
CINEMATIC_CAVES_BURST_STREAKS_F2		EQU 0xD30C
CINEMATIC_CAVES_BURST_CHUNKS_F3		EQU 0xD25C
CINEMATIC_CAVES_BURST_STREAKS_F3		EQU 0xD390
CINEMATIC_CAVES_BURST_CHUNKS_F4		EQU 0xD268
CINEMATIC_CAVES_BURST_STREAKS_F4		EQU 0xD418
CINEMATIC_CAVES_BURST_CHUNKS_F5		EQU 0xD280
CINEMATIC_CAVES_BURST_STREAKS_F5		EQU 0xD49C
CINEMATIC_CAVES_BURST_CHUNKS_F6		EQU 0xD28C
CINEMATIC_CAVES_BURST_STREAKS_F6		EQU 0xD510
CINEMATIC_690		EQU 0x88A0
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F0		EQU 0x8726
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F1		EQU 0x8736
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F2		EQU 0x8746
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F3		EQU 0x8756
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F4		EQU 0x8766
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F5		EQU 0x8776
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F0		EQU 0x86A6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F1		EQU 0x86B6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F2		EQU 0x86C6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F3		EQU 0x86D6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F4		EQU 0x86E6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F5		EQU 0x86F6
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F6		EQU 0x8706
CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F7		EQU 0x8716
CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_0		EQU 0x7232
CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_1		EQU 0x736A
CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_2		EQU 0x9EF0
CINEMATIC_CAVES_FALLING_ROCK_LARGE		EQU 0xCF8C
CINEMATIC_709		EQU 0xF3C4
CINEMATIC_710		EQU 0xF3DC
CINEMATIC_711		EQU 0xED30
CINEMATIC_712		EQU 0x88FE
CINEMATIC_713		EQU 0x8968
CINEMATIC_CAVES_SCREEN_CA_BACKDROP_0		EQU 0x7376
CINEMATIC_CAVES_SCREEN_CA_BACKDROP_1		EQU 0x9DC6
CINEMATIC_CAVES_SCREEN_CA_BACKDROP_2		EQU 0x9DEA
CINEMATIC_717		EQU 0xF3EC
CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT		EQU 0x9E54
CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT		EQU 0x9E3C
CINEMATIC_CAVES_SCREEN_CB_BACKDROP_LAYER_2		EQU 0x9E6C
CINEMATIC_CAVES_SCREEN_CB_BACKDROP_LAYER_3		EQU 0x9EA0
CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F0		EQU 0x7E28
CINEMATIC_CAVES_HERO_COLLAPSE_F0		EQU 0x7E4C
CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F1		EQU 0xC062
CINEMATIC_CAVES_HERO_COLLAPSE_F1		EQU 0x8414
CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F2		EQU 0xC086
CINEMATIC_CAVES_HERO_COLLAPSE_F2		EQU 0x8484
CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F3		EQU 0xC03E
CINEMATIC_CAVES_HERO_COLLAPSE_F3		EQU 0x84EC
CINEMATIC_CAVES_HERO_COLLAPSE_F4		EQU 0x8550
CINEMATIC_CAVES_HERO_COLLAPSE_F5		EQU 0x85B4
CINEMATIC_CAVES_HERO_COLLAPSE_F6		EQU 0x861C
CINEMATIC_733		EQU 0xC01A
CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_LEFT		EQU 0x9EB4
CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_RIGHT		EQU 0x9EE4
CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4		EQU 0xA846
CINEMATIC_737		EQU 0xFB46
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0		EQU 0xB41E
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1		EQU 0xB48E
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2		EQU 0xB502
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_3		EQU 0xC8B8
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_4		EQU 0xCB28
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_5		EQU 0x578C
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_6		EQU 0x56A0
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_7		EQU 0x9CA6
CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_8		EQU 0x9CEA
CINEMATIC_747		EQU 0xFB62
CINEMATIC_748		EQU 0xCAEA
CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_0		EQU 0x2862
CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_1		EQU 0x287A
CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_2		EQU 0x2892
CINEMATIC_752		EQU 0xE91A
CINEMATIC_CHARGED_BLAST_SWEEP_NEAR		EQU 0x282E
CINEMATIC_CAVES_LASER_BLAST_8		EQU 0x377C
CINEMATIC_CAVES_LASER_BLAST_7		EQU 0x2FF8
CINEMATIC_CAVES_LASER_BLAST_6		EQU 0x2FE0
CINEMATIC_CAVES_LASER_BLAST_5		EQU 0x2FC4
CINEMATIC_CAVES_LASER_BLAST_4		EQU 0x2FA8
CINEMATIC_CAVES_LASER_BLAST_3		EQU 0x2F80
CINEMATIC_CAVES_LASER_BLAST_2		EQU 0x2F5C
CINEMATIC_CAVES_LASER_BLAST_1		EQU 0x37E6
CINEMATIC_CAVES_LASER_BLAST_0		EQU 0x300C
CINEMATIC_763		EQU 0x2E86
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_7		EQU 0x2E66
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_6		EQU 0x2E20
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_5		EQU 0x2DB4
CINEMATIC_767		EQU 0x2D5E
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_3		EQU 0x2D0E
CINEMATIC_769		EQU 0x2CBE
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_1		EQU 0x2C4A
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_0		EQU 0x2BE8
CINEMATIC_CAVES_SCREEN_EE_BACKDROP_LAYER_6		EQU 0x459C
CINEMATIC_CAVES_SCREEN_EE_BACKDROP_LAYER_7		EQU 0x2AB6
CINEMATIC_774		EQU 0x2AD2
CINEMATIC_775		EQU 0x2AEE
CINEMATIC_776		EQU 0x2B0E
CINEMATIC_777		EQU 0x2B2A
CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_5		EQU 0x2B3E
CINEMATIC_CAVES_SCREEN_48_BACKDROP_LAYER_0		EQU 0xDD60
CINEMATIC_780		EQU 0x8A44
CINEMATIC_781		EQU 0x4EBC
CINEMATIC_782		EQU 0x4E88
CINEMATIC_783		EQU 0x4E54
CINEMATIC_784		EQU 0x4E20
CINEMATIC_785		EQU 0x4DEC
CINEMATIC_786		EQU 0x8CD2
CINEMATIC_787		EQU 0x8F66
CINEMATIC_788		EQU 0x8F0E
CINEMATIC_789		EQU 0x8F9A
CINEMATIC_790		EQU 0x4F90
CINEMATIC_791		EQU 0x4F78
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_4		EQU 0x4FD8
CINEMATIC_793		EQU 0x4FC0
CINEMATIC_CAVES_LASER_IMPACT_RIGHT_2		EQU 0x4FA8
CINEMATIC_795		EQU 0x5D4C
CINEMATIC_796		EQU 0x5D74
CINEMATIC_CAVES_HERO_IDLE_LEFT_0		EQU 0x5DB0
CINEMATIC_CAVES_HERO_IDLE_LEFT_1		EQU 0x5DD8
CINEMATIC_CAVES_HERO_IDLE_LEFT_2		EQU 0x5E28
CINEMATIC_CAVES_GROUND_BREACH_F0		EQU 0x8E9E
CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_3		EQU 0x8AD8
CINEMATIC_CAVES_GROUND_BREACH_F2		EQU 0x8B2A
CINEMATIC_CAVES_GROUND_BREACH_F3		EQU 0x8B96
CINEMATIC_CAVES_GROUND_BREACH_F4		EQU 0x8EC2
CINEMATIC_CAVES_GROUND_BREACH_F5		EQU 0x8EF8
CINEMATIC_806		EQU 0x8ED8
CINEMATIC_807		EQU 0x4826
CINEMATIC_CAVES_LASER_IMPACT_LEFT_7		EQU 0x4806
CINEMATIC_CAVES_LASER_IMPACT_LEFT_6		EQU 0x47C0
CINEMATIC_810		EQU 0x4754
CINEMATIC_CAVES_LASER_IMPACT_LEFT_4		EQU 0x46FE
CINEMATIC_CAVES_LASER_IMPACT_LEFT_3		EQU 0x46AE
CINEMATIC_CAVES_LASER_IMPACT_LEFT_2		EQU 0x465E
CINEMATIC_CAVES_LASER_IMPACT_LEFT_1		EQU 0x460E
CINEMATIC_CAVES_LASER_IMPACT_LEFT_0		EQU 0x45E8
CINEMATIC_816		EQU 0x28AA
CINEMATIC_817		EQU 0x28DE
CINEMATIC_818		EQU 0x28FA
CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_3		EQU 0x291A
CINEMATIC_820		EQU 0x2936
CINEMATIC_821		EQU 0x294A
CINEMATIC_CAVES_HERO_IDLE_LEFT_3		EQU 0x16EA
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_0		EQU 0x16FE
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_0		EQU 0x37A0
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_1		EQU 0x1712
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_1		EQU 0x37A8
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_2		EQU 0x1726
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_2		EQU 0x37B0
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_3		EQU 0x173A
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_3		EQU 0x37B8
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_4		EQU 0x174E
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_4		EQU 0x37C0
CINEMATIC_833		EQU 0x37DC
CINEMATIC_CAVES_LASER_IMPACT_LEFT_5		EQU 0x37D2
CINEMATIC_835		EQU 0x411E
CINEMATIC_836		EQU 0x4126
CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_5		EQU 0x1762
CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_5		EQU 0x37C8
CINEMATIC_839		EQU 0xCB3E
CINEMATIC_840		EQU 0x296E
CINEMATIC_841		EQU 0x29A6
CINEMATIC_842		EQU 0x29DA
CINEMATIC_SHIELD_DECAY_PHASE_3_DEFAULT		EQU 0x1826
CINEMATIC_SHIELD_DECAY_PHASE_3_CASE_01		EQU 0x1846
CINEMATIC_SHIELD_DECAY_PHASE_2_DEFAULT		EQU 0x2A0A
CINEMATIC_SHIELD_DECAY_PHASE_0_DEFAULT		EQU 0x2A8C
CINEMATIC_847		EQU 0x2A98
CINEMATIC_SHIELD_DECAY_PHASE_0		EQU 0x2AAA
CINEMATIC_849		EQU 0x1F80
CINEMATIC_850		EQU 0x1F38
CINEMATIC_851		EQU 0x1F68
CINEMATIC_852		EQU 0x005C
CINEMATIC_TELEPORT_DOWN_BEAM_RIGHT		EQU 0x198A
CINEMATIC_TELEPORT_DOWN_BEAM_LEFT		EQU 0x39E6
CINEMATIC_TELEPORT_UP_BEAM_RIGHT		EQU 0x1946
CINEMATIC_TELEPORT_UP_BEAM_LEFT		EQU 0x39D2
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F0		EQU 0x5E50
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F1		EQU 0x5E64
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F2		EQU 0x5E7C
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F3		EQU 0x5E9C
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F4		EQU 0x5EA8
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F5		EQU 0x5EB0
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F6		EQU 0x5ECC
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F7		EQU 0x5EE8
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F8		EQU 0x5F00
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F9		EQU 0x5F24
CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F10		EQU 0x5F30
HERO_GUN_ARM_LEFT_CASE_04		EQU 0x3614
HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK		EQU 0x5C8C
HERO_GUN_ARM_LEFT_CASE_03		EQU 0x35F8
HERO_GUN_ARM_LEFT_CASE_02		EQU 0x35D0
HERO_GUN_ARM_LEFT_CASE_01		EQU 0x35B4
HERO_WATER_DEPTH_LEFT_CASE_02		EQU 0x5E44
HERO_WATER_DEPTH_LEFT_CASE_00		EQU 0x5DE4
HERO_STAND_LEFT_BODY		EQU 0x0358
HERO_STAND_LEFT_ARM		EQU 0x3322
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
HERO_GUN_ARM_RIGHT_CASE_04		EQU 0x344E
HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK		EQU 0x5C1C
HERO_GUN_ARM_RIGHT_CASE_03		EQU 0x3420
HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK		EQU 0x5C14
HERO_GUN_ARM_RIGHT_CASE_02		EQU 0x33F2
HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK		EQU 0x5C0C
HERO_GUN_ARM_RIGHT_CASE_01		EQU 0x347C
HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK		EQU 0x5BF8
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
HERO_CRAWL_POSE_00		EQU 0x47DC
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
HERO_WALK_LEFT_BODY_F00		EQU 0x037C
HERO_WALK_LEFT_ARM_F00		EQU 0x332A
HERO_WALK_LEFT_BODY_F01		EQU 0x0764
HERO_WALK_LEFT_ARM_F01		EQU 0x3332
HERO_WALK_LEFT_BODY_F02		EQU 0x0790
HERO_WALK_LEFT_ARM_F02		EQU 0x333A
HERO_WALK_LEFT_BODY_F03		EQU 0x07BC
HERO_WALK_LEFT_ARM_F03		EQU 0x3342
HERO_WALK_LEFT_BODY_F04		EQU 0x07E8
HERO_WALK_LEFT_ARM_F04		EQU 0x334A
HERO_WALK_LEFT_BODY_F05		EQU 0x0814
HERO_WALK_LEFT_BODY_F06		EQU 0x0844
HERO_WALK_LEFT_BODY_F07		EQU 0x0874
HERO_WALK_LEFT_BODY_F08		EQU 0x08A0
HERO_WALK_LEFT_BODY_F09		EQU 0x0020
HERO_WALK_LEFT_BODY_F10		EQU 0x00B4
HERO_WALK_LEFT_BODY_F11		EQU 0x0128
HERO_WALK_LEFT_BODY_F12		EQU 0x01B0
HERO_WALK_LEFT_BODY_F13		EQU 0x0234
HERO_WALK_LEFT_BODY_F14		EQU 0x02AC
HERO_WALK_LEFT_ARM_F14		EQU 0x331A
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
CV_245C		EQU 0x245C
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
CV_FIGURE_WALK_LEFT_LIMB_POSE_00		EQU 0x2D6E
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
CV_2D4E		EQU 0x2D4E
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
CV_FIGURE_RUN_RIGHT_UPPER_POSE_01		EQU 0x21A8
CV_FIGURE_RUN_RIGHT_LIMB_POSE_02		EQU 0x2552
CV_FIGURE_RUN_RIGHT_BODY_F02		EQU 0x2058
CV_FIGURE_RUN_RIGHT_UPPER_POSE_02		EQU 0x21D6
CV_FIGURE_RUN_RIGHT_LIMB_POSE_03		EQU 0x2548
CV_FIGURE_RUN_RIGHT_BODY_F03		EQU 0x20B8
CV_FIGURE_RUN_RIGHT_UPPER_POSE_03		EQU 0x2200
CV_2570		EQU 0x2570
CV_FIGURE_RUN_RIGHT_BODY_F04		EQU 0x2134
CV_FIGURE_RUN_RIGHT_UPPER_POSE_04		EQU 0x2212
CV_FIGURE_RUN_RIGHT_BODY_F05		EQU 0x2310
CV_FIGURE_RUN_RIGHT_BODY_F06		EQU 0x232C
CV_FIGURE_RUN_RIGHT_BODY_F07		EQU 0x2348
CV_FIGURE_RUN_RIGHT_UPPER_POSE_05		EQU 0x224C
CV_FIGURE_RUN_RIGHT_BODY_F08		EQU 0x2364
CV_FIGURE_RUN_RIGHT_UPPER_POSE_06		EQU 0x2276
CV_FIGURE_RUN_RIGHT_BODY_F09		EQU 0x2380
CV_FIGURE_RUN_LEFT_LIMB_POSE_00		EQU 0x320A
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
CV_4346		EQU 0x4346
CV_4368		EQU 0x4368
HERO_STAND_AIM_LEFT		EQU 0x3A64
HERO_STAND_AIM_LEFT_CHARGE_DOT		EQU 0x5C9C
HERO_RUN_RIGHT_BODY_F00		EQU 0x03E4
HERO_RUN_RIGHT_GUN_ARM_POSE_00		EQU 0x3542
HERO_RUN_RIGHT_ARM_F00		EQU 0x34AA
HERO_RUN_RIGHT_BODY_F01		EQU 0x0472
HERO_RUN_RIGHT_GUN_ARM_POSE_01		EQU 0x3558
HERO_RUN_RIGHT_ARM_F01		EQU 0x34B2
HERO_JUMP_RIGHT_F07		EQU 0x4FBC
HERO_RUN_RIGHT_BODY_F05		EQU 0x06A2
HERO_RUN_RIGHT_ARM_F05		EQU 0x34D6
HERO_RUN_RIGHT_BODY_F06		EQU 0x06C8
HERO_RUN_RIGHT_ARM_F06		EQU 0x34DE
HERO_RUN_RIGHT_BODY_F07		EQU 0x06EE
HERO_RUN_RIGHT_ARM_F07		EQU 0x34E6
HERO_RUN_RIGHT_BODY_F08		EQU 0x0714
HERO_RUN_RIGHT_GUN_ARM_POSE_04		EQU 0x34FE
HERO_RUN_RIGHT_ARM_F08		EQU 0x34EE
HERO_RUN_RIGHT_BODY_F09		EQU 0x073E
HERO_RUN_RIGHT_ARM_F09		EQU 0x34F6
HERO_RUN_RIGHT_BODY_F02		EQU 0x04F4
HERO_RUN_RIGHT_GUN_ARM_POSE_02		EQU 0x352C
HERO_RUN_RIGHT_ARM_F02		EQU 0x34BA
HERO_RUN_RIGHT_BODY_F03		EQU 0x058E
HERO_RUN_RIGHT_GUN_ARM_POSE_03		EQU 0x356E
HERO_RUN_RIGHT_ARM_F03		EQU 0x34C2
HERO_RUN_RIGHT_BODY_F04		EQU 0x0624
HERO_RUN_RIGHT_ARM_F04		EQU 0x34CE
HERO_RUN_LEFT_ARM_F00		EQU 0x3630
HERO_RUN_LEFT_BODY_F00		EQU 0x11B8
CV_367C		EQU 0x367C
HERO_RUN_LEFT_ARM_F01		EQU 0x3638
HERO_RUN_LEFT_BODY_F01		EQU 0x125A
HERO_JUMP_LEFT_F07		EQU 0x53A0
HERO_RUN_LEFT_ARM_F05		EQU 0x3650
HERO_RUN_LEFT_BODY_F05		EQU 0x150A
HERO_RUN_LEFT_ARM_F06		EQU 0x3674
HERO_RUN_LEFT_BODY_F06		EQU 0x1530
HERO_RUN_LEFT_ARM_F07		EQU 0x3658
HERO_RUN_LEFT_BODY_F07		EQU 0x1556
HERO_RUN_LEFT_ARM_F08		EQU 0x3660
HERO_RUN_LEFT_BODY_F08		EQU 0x157C
HERO_RUN_LEFT_ARM_F09		EQU 0x366C
HERO_RUN_LEFT_BODY_F09		EQU 0x15A2
HERO_RUN_LEFT_ARM_F02		EQU 0x3640
HERO_RUN_LEFT_BODY_F02		EQU 0x1304
HERO_RUN_LEFT_ARM_F03		EQU 0x3648
HERO_RUN_LEFT_BODY_F03		EQU 0x13B2
HERO_RUN_LEFT_BODY_F04		EQU 0x1474
CV_1C78		EQU 0x1C78
CV_FIGURE_GUN_UPPER_RIGHT_POSE_00		EQU 0x3B44
CV_FIGURE_GUN_UPPER_RIGHT_POSE_00_CHARGE_BLINK		EQU 0x5CA4
CV_FIGURE_GUN_LIMB_LEFT_POSE_02		EQU 0x3C92
CV_FIGURE_GUN_LIMB_LEFT_POSE_02_CHARGE_BLINK		EQU 0x5C6C
CV_FIGURE_GUN_LIMB_LEFT_POSE_01		EQU 0x3C66
CV_FIGURE_GUN_LIMB_LEFT_POSE_01_CHARGE_BLINK		EQU 0x5C64
CV_FIGURE_GUN_LIMB_LEFT_POSE_00		EQU 0x3C3A
CV_FIGURE_GUN_LIMB_LEFT_POSE_00_CHARGE_BLINK		EQU 0x5C5C
CV_FIGURE_GUN_UPPER_RIGHT_POSE_01		EQU 0x3B96
CV_FIGURE_GUN_UPPER_RIGHT_POSE_01_CHARGE_BLINK		EQU 0x5CAC
CV_FIGURE_GUN_UPPER_RIGHT_POSE_02		EQU 0x3BE8
CV_FIGURE_GUN_UPPER_RIGHT_POSE_02_CHARGE_BLINK		EQU 0x5CB4
CV_41A8		EQU 0x41A8
CV_5C74		EQU 0x5C74
CV_41E0		EQU 0x41E0
CV_5C7C		EQU 0x5C7C
CV_4218		EQU 0x4218
CV_5C84		EQU 0x5C84
CV_3EEC		EQU 0x3EEC
CV_5CBC		EQU 0x5CBC
CV_6004		EQU 0x6004
CV_3F4A		EQU 0x3F4A
CV_5CC4		EQU 0x5CC4
CV_6010		EQU 0x6010
CV_4058		EQU 0x4058
CV_5CCC		EQU 0x5CCC
CV_4416		EQU 0x4416
HERO_CROUCH_DOWN_RIGHT		EQU 0x1600
HERO_CROUCH_SHOOT_RIGHT_F1		EQU 0x38D2
HERO_CROUCH_AIM_RIGHT		EQU 0x3764
HERO_CROUCH_AIM_RIGHT_CHARGE_DOT		EQU 0x5C4C
HERO_CROUCH_SHOOT_RIGHT_F0		EQU 0x389E
HERO_STAND_ARMED_RIGHT		EQU 0x1664
HERO_CROUCH_RIGHT		EQU 0x61B0
HERO_CROUCH_DOWN_LEFT		EQU 0x17A8
HERO_CROUCH_SHOOT_LEFT_F1		EQU 0x3B10
HERO_CROUCH_SHOOT_LEFT_F0		EQU 0x3ADC
HERO_STAND_ARMED_LEFT		EQU 0x17CC
HERO_CROUCH_LEFT		EQU 0x1784
HERO_WATER_DEPTH_LEFT_CASE_03		EQU 0x5E9C
HERO_WATER_DEPTH_LEFT_CASE_01		EQU 0x5DEC
HERO_WATER_DEPTH_RIGHT_CASE_03		EQU 0x5D84
HERO_WATER_DEPTH_RIGHT_CASE_02		EQU 0x5D2C
HERO_WATER_DEPTH_RIGHT_CASE_01		EQU 0x5CD4
HERO_WATER_DEPTH_RIGHT_CASE_00		EQU 0x5DDC
HERO_WALK_RIGHT_ARM_F09		EQU 0x3352
HERO_WALK_RIGHT_ARM_F10		EQU 0x335C
HERO_STAND_SHOOT_LEFT_F1		EQU 0x391A
HERO_STAND_SHOOT_LEFT_F0		EQU 0x3A96
HERO_STAND_SHOOT_RIGHT_F1		EQU 0x36D2
HERO_STAND_AIM_RIGHT_CHARGE_DOT		EQU 0x5C54
HERO_STAND_SHOOT_RIGHT_F0		EQU 0x3858
HERO_STAND_GUN_LOWER_RIGHT		EQU 0x15DC


	org 0x0000

ENTRY_POINT_OF_CAVES:
	call CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8
	setup channel=0x3C, address=FRAME_PRESENT_RESTORE_PAGE_0_LOOP
	mov [PAUSE_SLICES], 0x0004
	mov [0xF6], 0x0001
	mov [0x32], 0x0000
	break
	play id=0x006A, freq=0x14, vol=0x00, channel=0x02
	play id=0x006A, freq=0x14, vol=0x00, channel=0x03
	play id=0x006A, freq=0x14, vol=0x00, channel=0x01
	play id=0x006A, freq=0x14, vol=0x00, channel=0x00
	call INIT_HASH_VARS_67_66_65_68_69
	call INIT_AI_VARS_AT_280_10
	call LABEL_40B6
	call LABEL_12FB
	setup channel=0x14, address=HERO_DIRECTION_LEFT_IDLE_ENTRY
	setup channel=0x15, address=LABEL_3813
	setup channel=0x14, address=LABEL_E41E
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=LABEL_DF3B
	call CAVES_SCREEN_ENTRY_DISPATCH
	setup channel=0x3F, address=LABEL_D7A5
	killChannel
	setup channel=0x05, address=INLINE_SET_VAR6B_TO_1
	copyVideoPage src=0x03, dst=0x00
	killChannel
	copyVideoPage src=0x00, dst=0x03
	killChannel
	mov [0x00], [0x18]
	mov [0xF8], [0x00]
	shr [0xF8], 0x0008
	video offset=CINEMATIC_424, x=[0xf8], y=0
	mov [0xF8], [0x00]
	and [0xF8], 0x00FF
	video offset=CINEMATIC_424, x=[0xf8], y=1
	video offset=CINEMATIC_852, x=[HERO_X], y=2
	killChannel

LIKELY_A_COPY_PROTECTION_MECHANISM:
	and [0xBC], 0x0010
	mov [0xF8], [0xC6]
	and [0xF8], 0x0080
	je [0xBC], 0x00, LABEL_00A6
	je [0xF8], 0x00, LABEL_00A6
	jne [0xF2], 0x1770, LABEL_00A6
	jne [COPY_PROTECT_TOKEN], 0x21, LABEL_00A6
	ret


LABEL_00A6:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=KILL_CHANNEL_LANDING
	killChannel
	mov [0xBC], 0x00FF
	mov [0xC6], 0x00FF
	mov [0xF2], 0x1770
	mov [COPY_PROTECT_TOKEN], 0x0021
	killChannel
