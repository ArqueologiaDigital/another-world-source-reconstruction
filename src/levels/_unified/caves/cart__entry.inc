; Unified source for CAVES with 264 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_037  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_038  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_039  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_040  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   SHARED_RET  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_027  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_011  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_012  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_028  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 264 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   KILL_CHANNEL_LANDING  (3-arm: amiga, cart, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_037  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR76_TO_0001_038  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_039  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR7C_TO_0001_040  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_003  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_6B_001  (3-arm: amiga, cart, dos)
;   SHARED_RET  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_228_018  (2-arm: cart, dos)
;   INLINE_DRAW_CV_220_008  (2-arm: cart, dos)
;   INLINE_DRAW_CV_216_027  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_272_003  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_269_024  (2-arm: cart, dos)
;   INLINE_DRAW_CV_266_005  (2-arm: cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   INLINE_DRAW_CV_255_010  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_020  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_252_018  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   DEDUP_CAVES_5B_007  (3-arm: amiga, cart, dos)
;   INLINE_DRAW_CV_243_012  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_027  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_011  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_012  (3-arm: amiga, cart, dos)
;   DEDUP_CAVES_5B_028  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   INLINE_BREAK_035  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 218 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_446B_2519A417  (2-arm: amiga, dos)
;   PRELOAD_CAVES_RESOURCES  (2-arm: amiga, dos)
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_3  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8  (2-arm: amiga, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR6B_TO_1  (2-arm: amiga, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   FOLD_BODY_290B_04233270  (2-arm: amiga, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 213 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_237B_F9B523AC  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

; Unified source for CAVES with 213 folded shared bodies.
;
; Folded routines (in byte-address order):
;   FOLD_BODY_254B_838374D1  (3-arm: amiga, cart, dos)
;   COPY_VAR00_TO_VARF8  (3-arm: amiga, cart, dos)
;   COPY_VARF8_TO_VAR00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_237B_F9B523AC  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_E8_E8_PLUS3  (3-arm: amiga, cart, dos)
;   INIT_VARS_6D_71_70  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR70_TO_8  (3-arm: amiga, cart, dos)
;   INIT_VARS_71_6C_6D  (3-arm: amiga, cart, dos)
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
;   INIT_VARS_EB_EC_ED  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR79_TO_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_8EB32F8E  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_84B_B02DE811  (3-arm: amiga, cart, dos)
;   FOLD_BODY_219B_89086759  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE6_TO_32  (3-arm: amiga, cart, dos)
;   INLINE_SET_VARE8_TO_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_6C_6B  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR31  (3-arm: amiga, cart, dos)
;   SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_E7_EB  (2-arm: cart, dos)
;   INLINE_SET_VAR7F_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_67B_EB770918  (3-arm: amiga, cart, dos)
;   CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8  (2-arm: cart, dos)
;   COPY_HASH_VAR_37_TO_RANGE  (3-arm: amiga, cart, dos)
;   ACCUMULATE_HASH_INTO_VAR37_38  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_579DE25B  (2-arm: cart, dos)
;   FOLD_BODY_156B_62098AC6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_156B_189DA618  (2-arm: cart, dos)
;   FOLD_BODY_245B_6670034A  (3-arm: amiga, cart, dos)
;   INIT_HASH_VARS_67_66_65_68_69  (2-arm: amiga, cart)
;   INIT_VARS_29_07_08  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   SET_VARS_07_08  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH00  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_913256B4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   INLINE_COPY_VAR44_TO_VAR25  (3-arm: amiga, cart, dos)
;   INIT_VAR2B_2C_FROM_VAR01_VAR29_10  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_1F847B0B  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR22  (3-arm: amiga, cart, dos)
;   DECREMENT_VARF8_BY_10  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22_BY_10  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   FOLD_BODY_99B_D1658A70  (2-arm: cart, dos)
;   FOLD_BODY_99B_3B6BC4B3  (2-arm: cart, dos)
;   INCREMENT_VAR07_BY_1  (3-arm: amiga, cart, dos)
;   DRAW_CV_301  (2-arm: cart, dos)
;   DRAW_CV_355  (2-arm: cart, dos)
;   DECREMENT_VAR08_BY_D  (3-arm: amiga, cart, dos)
;   DRAW_CV_074  (2-arm: cart, dos)
;   DRAW_CV_075  (2-arm: cart, dos)
;   DRAW_CV_076  (2-arm: cart, dos)
;   DRAW_CV_077  (2-arm: cart, dos)
;   FOLD_BODY_200B_1AFE2B0B  (2-arm: cart, dos)
;   DRAW_CV_080  (2-arm: cart, dos)
;   DRAW_CV_061  (2-arm: cart, dos)
;   DRAW_CV_063  (2-arm: cart, dos)
;   DRAW_CV_065  (2-arm: cart, dos)
;   DRAW_CV_067  (2-arm: cart, dos)
;   DRAW_CV_069  (2-arm: cart, dos)
;   FOLD_BODY_200B_5D805D1F  (2-arm: cart, dos)
;   DRAW_CV_071  (2-arm: cart, dos)
;   DRAW_CV_072  (2-arm: cart, dos)
;   DRAW_CV_073  (2-arm: cart, dos)
;   DRAW_CV_300  (2-arm: cart, dos)
;   DRAW_CV_299  (2-arm: cart, dos)
;   DRAW_CV_295  (2-arm: cart, dos)
;   DRAW_CV_296  (2-arm: cart, dos)
;   DRAW_CV_297  (2-arm: cart, dos)
;   DRAW_CV_298  (2-arm: cart, dos)
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_37F93421  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_44886950  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (2-arm: cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   RESET_HERO_ACTION_KEEP_POS_4LSB  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_79EC0326  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_04CB328E  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_38FD38E3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_C4F9E873  (3-arm: amiga, cart, dos)
;   INIT_VARS_01_22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_A75D286E  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_57569B89  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_4CB9AFF5  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_E4233737  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_69E7A9C1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_615E7707  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_3714FA4E  (2-arm: cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_FF58C6C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_41906E76  (3-arm: amiga, cart, dos)
;   FOLD_BODY_144B_552673A7  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0042  (2-arm: cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
;   FOLD_BODY_189B_1A09E69C  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00B8  (3-arm: amiga, cart, dos)
;   INIT_VARS_EB_47  (3-arm: amiga, cart, dos)
;   PLAY_FX_6B_THEN_KILL_CHANNEL  (3-arm: amiga, cart, dos)
;   INIT_VARS_E6_EA  (3-arm: amiga, cart, dos)
;   FOLD_BODY_50B_2E2F4B8F  (3-arm: amiga, cart, dos)
;   COPY_PAGE0_TO_3_LOAD_RES45  (2-arm: cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_AA_AD_5B_5E_PLUS1  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7  (3-arm: amiga, cart, dos)
;   DELETE_GAME_AND_FX_CHANNELS  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_160F1222  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_53AF86AC  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_46DFEAE8  (3-arm: amiga, cart, dos)
;   FOLD_BODY_66B_F424839D  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_223B_DDF457BD  (2-arm: cart, dos)
;   FOLD_BODY_206B_44F9C1BD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_206B_F444FCB9  (3-arm: amiga, cart, dos)
;   FOLD_BODY_261B_7A9CE2F7  (2-arm: cart, dos)
;   FOLD_BODY_261B_43CF2CB1  (2-arm: cart, dos)

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
;   SET_VAR22_TO_006B  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0061  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C8  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AB  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_007D  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0080  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AC  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0087  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_0085  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00C3  (3-arm: amiga, cart, dos)
;   SET_VAR22_TO_00AE  (3-arm: amiga, cart, dos)
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
CINEMATIC_000		EQU 0xD5F8
CINEMATIC_001		EQU 0xB684
CINEMATIC_002		EQU 0xC0F4
CINEMATIC_003		EQU 0xB7FA
CINEMATIC_004		EQU 0xB812
CINEMATIC_005		EQU 0xB88A
CINEMATIC_006		EQU 0xB832
CINEMATIC_007		EQU 0xB852
CINEMATIC_008		EQU 0xADDE
CINEMATIC_009		EQU 0xAE0C
CINEMATIC_010		EQU 0xAE20
CINEMATIC_011		EQU 0xAE40
CINEMATIC_012		EQU 0xCF04
CINEMATIC_013		EQU 0x47A8
CINEMATIC_014		EQU 0xD63A
CINEMATIC_015		EQU 0x417A
CINEMATIC_016		EQU 0x3750
CINEMATIC_017		EQU 0x414C
CINEMATIC_018		EQU 0x0F80
CINEMATIC_019		EQU 0x0F40
CINEMATIC_020		EQU 0x0F28
CINEMATIC_021		EQU 0x0EEC
CINEMATIC_022		EQU 0x40D6
CINEMATIC_023		EQU 0x40FE
CINEMATIC_024		EQU 0x4118
CINEMATIC_025		EQU 0xE6C6
CINEMATIC_026		EQU 0xD46C
CINEMATIC_027		EQU 0xE712
CINEMATIC_028		EQU 0x4312
CINEMATIC_029		EQU 0x435A
CINEMATIC_030		EQU 0xE686
CINEMATIC_031		EQU 0x434A
CINEMATIC_032		EQU 0xE6BE
CINEMATIC_033		EQU 0x1A60
CINEMATIC_034		EQU 0x1A8C
CINEMATIC_035		EQU 0x1ABC
CINEMATIC_036		EQU 0x128E
CINEMATIC_037		EQU 0x12C6
CINEMATIC_038		EQU 0x41AA
CINEMATIC_039		EQU 0x4200
CINEMATIC_040		EQU 0x1508
CINEMATIC_041		EQU 0xE93A
CINEMATIC_042		EQU 0x1488
CINEMATIC_043		EQU 0xE974
CINEMATIC_044		EQU 0x1048
CINEMATIC_045		EQU 0x1014
CINEMATIC_046		EQU 0x0FFC
CINEMATIC_047		EQU 0x0FC0
CINEMATIC_048		EQU 0x0986
CINEMATIC_049		EQU 0x41D8
CINEMATIC_050		EQU 0x4414
CINEMATIC_051		EQU 0x442E
CINEMATIC_052		EQU 0xD448
CINEMATIC_053		EQU 0xE66A
CINEMATIC_054		EQU 0x4400
CINEMATIC_055		EQU 0xE74A
CINEMATIC_056		EQU 0xE72E
CINEMATIC_057		EQU 0x43E4
CINEMATIC_058		EQU 0xE742
CINEMATIC_059		EQU 0x1140
CINEMATIC_060		EQU 0x1C76
CINEMATIC_061		EQU 0x437C
CINEMATIC_062		EQU 0xE762
CINEMATIC_063		EQU 0x1232
CINEMATIC_064		EQU 0x1246
CINEMATIC_065		EQU 0x125A
CINEMATIC_066		EQU 0x12D4
CINEMATIC_067		EQU 0x1272
CINEMATIC_068		EQU 0x1AC8
CINEMATIC_069		EQU 0x1AF4
CINEMATIC_070		EQU 0x1B24
CINEMATIC_071		EQU 0x1B58
CINEMATIC_072		EQU 0x1B8C
CINEMATIC_073		EQU 0x1B98
CINEMATIC_074		EQU 0x35F8
CINEMATIC_075		EQU 0x35C8
CINEMATIC_076		EQU 0x32E0
CINEMATIC_077		EQU 0x3392
CINEMATIC_078		EQU 0x33A8
CINEMATIC_079		EQU 0x33C0
CINEMATIC_080		EQU 0x3CA2
CINEMATIC_081		EQU 0x3D1A
CINEMATIC_082		EQU 0x2DCE
CINEMATIC_083		EQU 0x2E8E
CINEMATIC_084		EQU 0x2F1E
CINEMATIC_085		EQU 0x2FAE
CINEMATIC_086		EQU 0x303A
CINEMATIC_087		EQU 0x30BA
CINEMATIC_088		EQU 0x3122
CINEMATIC_089		EQU 0x3182
CINEMATIC_090		EQU 0x3DB2
CINEMATIC_091		EQU 0x20C6
CINEMATIC_092		EQU 0x213E
CINEMATIC_093		EQU 0x223C
CINEMATIC_094		EQU 0x16E4
CINEMATIC_095		EQU 0x176C
CINEMATIC_096		EQU 0x182E
CINEMATIC_097		EQU 0x1866
CINEMATIC_098		EQU 0x2B9E
CINEMATIC_099		EQU 0x2AD2
CINEMATIC_100		EQU 0x2BB2
CINEMATIC_101		EQU 0x2C3E
CINEMATIC_102		EQU 0x2CB6
CINEMATIC_103		EQU 0x2CDE
CINEMATIC_104		EQU 0x2D1A
CINEMATIC_105		EQU 0x2D6E
CINEMATIC_106		EQU 0x2DAE
CINEMATIC_107		EQU 0x153C
CINEMATIC_108		EQU 0x15B8
CINEMATIC_109		EQU 0x16A8
CINEMATIC_110		EQU 0x189A
CINEMATIC_111		EQU 0x18DA
CINEMATIC_112		EQU 0x18E2
CINEMATIC_113		EQU 0x18EA
CINEMATIC_114		EQU 0x18F2
CINEMATIC_115		EQU 0x18FA
CINEMATIC_116		EQU 0x1902
CINEMATIC_117		EQU 0x190A
CINEMATIC_118		EQU 0x1912
CINEMATIC_119		EQU 0x191A
CINEMATIC_120		EQU 0x1922
CINEMATIC_121		EQU 0x192A
CINEMATIC_122		EQU 0x1946
CINEMATIC_123		EQU 0x194E
CINEMATIC_124		EQU 0x3B60
CINEMATIC_125		EQU 0x3BD0
CINEMATIC_126		EQU 0x3C62
CINEMATIC_127		EQU 0x3A58
CINEMATIC_128		EQU 0x3ABC
CINEMATIC_129		EQU 0x3B24
CINEMATIC_130		EQU 0x330E
CINEMATIC_131		EQU 0x3366
CINEMATIC_132		EQU 0x333A
CINEMATIC_133		EQU 0x3420
CINEMATIC_134		EQU 0x3580
CINEMATIC_135		EQU 0x33D8
CINEMATIC_136		EQU 0x3404
CINEMATIC_137		EQU 0x3634
CINEMATIC_138		EQU 0x3604
CINEMATIC_139		EQU 0x409A
CINEMATIC_140		EQU 0x40B8
CINEMATIC_141		EQU 0x44AE
CINEMATIC_142		EQU 0xBDBE
CINEMATIC_143		EQU 0xBE30
CINEMATIC_144		EQU 0xBE3C
CINEMATIC_145		EQU 0xBE48
CINEMATIC_146		EQU 0xBE54
CINEMATIC_147		EQU 0xBE60
CINEMATIC_148		EQU 0xF1DA
CINEMATIC_149		EQU 0xF192
CINEMATIC_150		EQU 0xF19A
CINEMATIC_151		EQU 0xF1A2
CINEMATIC_152		EQU 0x1320
CINEMATIC_153		EQU 0x24C0
CINEMATIC_154		EQU 0x24A8
CINEMATIC_155		EQU 0x2490
CINEMATIC_156		EQU 0x24D4
CINEMATIC_157		EQU 0x24E6
CINEMATIC_158		EQU 0x0474
CINEMATIC_159		EQU 0x04D8
CINEMATIC_160		EQU 0x061C
CINEMATIC_161		EQU 0x0640
CINEMATIC_162		EQU 0xF17A
CINEMATIC_163		EQU 0xF182
CINEMATIC_164		EQU 0xF18A
CINEMATIC_165		EQU 0xF1AA
CINEMATIC_166		EQU 0x05F8
CINEMATIC_167		EQU 0x4258
CINEMATIC_168		EQU 0x1340
CINEMATIC_169		EQU 0x4230
CINEMATIC_170		EQU 0x026C
CINEMATIC_171		EQU 0xF162
CINEMATIC_172		EQU 0xF16A
CINEMATIC_173		EQU 0xF172
CINEMATIC_174		EQU 0x05D4
CINEMATIC_175		EQU 0xF128
CINEMATIC_176		EQU 0x0BC4
CINEMATIC_177		EQU 0xF106
CINEMATIC_178		EQU 0xF130
CINEMATIC_179		EQU 0xBD64
CINEMATIC_180		EQU 0xBDA0
CINEMATIC_181		EQU 0xBD82
CINEMATIC_182		EQU 0xBE68
CINEMATIC_183		EQU 0xBE90
CINEMATIC_184		EQU 0xBED4
CINEMATIC_185		EQU 0xC1CC
CINEMATIC_186		EQU 0xBBAE
CINEMATIC_187		EQU 0xBC1A
CINEMATIC_188		EQU 0xBC7C
CINEMATIC_189		EQU 0xBCCE
CINEMATIC_190		EQU 0x4498
CINEMATIC_191		EQU 0xC4C8
CINEMATIC_192		EQU 0xF45C
CINEMATIC_193		EQU 0xF468
CINEMATIC_194		EQU 0xF49C
CINEMATIC_195		EQU 0xF474
CINEMATIC_196		EQU 0xF480
CINEMATIC_197		EQU 0xF490
CINEMATIC_198		EQU 0xF262
CINEMATIC_199		EQU 0xF2A6
CINEMATIC_200		EQU 0xF2EE
CINEMATIC_201		EQU 0xF338
CINEMATIC_202		EQU 0xF38E
CINEMATIC_203		EQU 0xF3B8
CINEMATIC_204		EQU 0xF3D0
CINEMATIC_205		EQU 0xF3FC
CINEMATIC_206		EQU 0xF420
CINEMATIC_207		EQU 0xF444
CINEMATIC_208		EQU 0xF450
CINEMATIC_209		EQU 0xC4EA
CINEMATIC_210		EQU 0xC538
CINEMATIC_211		EQU 0xC5A0
CINEMATIC_212		EQU 0xC602
CINEMATIC_213		EQU 0xC5C4
CINEMATIC_214		EQU 0xC474
CINEMATIC_215		EQU 0xC48C
CINEMATIC_216		EQU 0xC4A8
CINEMATIC_217		EQU 0x5D7A
CINEMATIC_218		EQU 0x5DC6
CINEMATIC_219		EQU 0x5E1E
CINEMATIC_220		EQU 0x5E7A
CINEMATIC_221		EQU 0x5EF6
CINEMATIC_222		EQU 0x4514
CINEMATIC_223		EQU 0x5F42
CINEMATIC_224		EQU 0x64E0
CINEMATIC_225		EQU 0xA79E
CINEMATIC_226		EQU 0xDFA4
CINEMATIC_227		EQU 0x2600
CINEMATIC_228		EQU 0x198E
CINEMATIC_229		EQU 0xCEF0
CINEMATIC_230		EQU 0xD8F4
CINEMATIC_231		EQU 0xD948
CINEMATIC_232		EQU 0xD9B4
CINEMATIC_233		EQU 0xDA28
CINEMATIC_234		EQU 0xDA9C
CINEMATIC_235		EQU 0xDB20
CINEMATIC_236		EQU 0xDBAC
CINEMATIC_237		EQU 0xDC30
CINEMATIC_238		EQU 0xDCCC
CINEMATIC_239		EQU 0xDD64
CINEMATIC_240		EQU 0xCF4C
CINEMATIC_241		EQU 0xD1A4
CINEMATIC_242		EQU 0xD044
CINEMATIC_243		EQU 0xD0B0
CINEMATIC_244		EQU 0xCFD0
CINEMATIC_245		EQU 0xD334
CINEMATIC_246		EQU 0xD3A0
CINEMATIC_247		EQU 0xD2C0
CINEMATIC_248		EQU 0xD23C
CINEMATIC_249		EQU 0xD124
CINEMATIC_250		EQU 0xE4C2
CINEMATIC_251		EQU 0xE5AE
CINEMATIC_252		EQU 0xE576
CINEMATIC_253		EQU 0xE53A
CINEMATIC_254		EQU 0x0E0C
CINEMATIC_255		EQU 0x0CC2
CINEMATIC_256		EQU 0xE7F2
CINEMATIC_257		EQU 0xE80A
CINEMATIC_258		EQU 0xE822
CINEMATIC_259		EQU 0xE842
CINEMATIC_260		EQU 0xE85A
CINEMATIC_261		EQU 0xE87A
CINEMATIC_262		EQU 0xE892
CINEMATIC_263		EQU 0xE5BA
CINEMATIC_264		EQU 0xE5F4
CINEMATIC_265		EQU 0xE62A
CINEMATIC_266		EQU 0xC752
CINEMATIC_267		EQU 0xC7B6
CINEMATIC_268		EQU 0xC7E6
CINEMATIC_269		EQU 0xC80E
CINEMATIC_270		EQU 0x693E
CINEMATIC_271		EQU 0x68FE
CINEMATIC_272		EQU 0x690E
CINEMATIC_273		EQU 0x691E
CINEMATIC_274		EQU 0x692E
CINEMATIC_275		EQU 0x671E
CINEMATIC_276		EQU 0x682E
CINEMATIC_277		EQU 0xDFB8
CINEMATIC_278		EQU 0xACB2
CINEMATIC_279		EQU 0xADBA
CINEMATIC_280		EQU 0xAD96
CINEMATIC_281		EQU 0xAD72
CINEMATIC_282		EQU 0xAD3A
CINEMATIC_283		EQU 0xAE5A
CINEMATIC_284		EQU 0xAEA6
CINEMATIC_285		EQU 0xAEBA
CINEMATIC_286		EQU 0xD4A8
CINEMATIC_287		EQU 0xD4CC
CINEMATIC_288		EQU 0xE8C0
CINEMATIC_289		EQU 0xE8FE
CINEMATIC_290		EQU 0xF232
CINEMATIC_291		EQU 0x9B0C
CINEMATIC_292		EQU 0x9B90
CINEMATIC_293		EQU 0xF224
CINEMATIC_294		EQU 0x9C90
CINEMATIC_295		EQU 0x6B86
CINEMATIC_296		EQU 0xF0B2
CINEMATIC_297		EQU 0xEA4C
CINEMATIC_298		EQU 0x6EE0
CINEMATIC_299		EQU 0x6D84
CINEMATIC_300		EQU 0xD664
CINEMATIC_301		EQU 0xD6A0
CINEMATIC_302		EQU 0xD6D8
CINEMATIC_303		EQU 0xE2BA
CINEMATIC_304		EQU 0xE294
CINEMATIC_305		EQU 0xE49C
CINEMATIC_306		EQU 0xE17C
CINEMATIC_307		EQU 0xE1C8
CINEMATIC_308		EQU 0xE208
CINEMATIC_309		EQU 0x730C
CINEMATIC_310		EQU 0x7348
CINEMATIC_311		EQU 0x7360
CINEMATIC_312		EQU 0x738C
CINEMATIC_313		EQU 0x737C
CINEMATIC_314		EQU 0x73D0
CINEMATIC_315		EQU 0x73A8
CINEMATIC_316		EQU 0x6BCE
CINEMATIC_317		EQU 0x6C52
CINEMATIC_318		EQU 0xA40C
CINEMATIC_319		EQU 0xA5E8
CINEMATIC_320		EQU 0xA72C
CINEMATIC_321		EQU 0xA748
CINEMATIC_322		EQU 0xA690
CINEMATIC_323		EQU 0xA698
CINEMATIC_324		EQU 0xA6A4
CINEMATIC_325		EQU 0xA6B4
CINEMATIC_326		EQU 0xA6C8
CINEMATIC_327		EQU 0xA6DC
CINEMATIC_328		EQU 0xA6F0
CINEMATIC_329		EQU 0xA704
CINEMATIC_330		EQU 0xA718
CINEMATIC_331		EQU 0xAF32
CINEMATIC_332		EQU 0xAFC8
CINEMATIC_333		EQU 0xB0A8
CINEMATIC_334		EQU 0xB014
CINEMATIC_335		EQU 0xAF08
CINEMATIC_336		EQU 0xB054
CINEMATIC_337		EQU 0xB07E
CINEMATIC_338		EQU 0x6F6C
CINEMATIC_339		EQU 0x9F26
CINEMATIC_340		EQU 0x6FB4
CINEMATIC_341		EQU 0x7260
CINEMATIC_342		EQU 0x7284
CINEMATIC_343		EQU 0x72A8
CINEMATIC_344		EQU 0x6FF8
CINEMATIC_345		EQU 0xAEDE
CINEMATIC_346		EQU 0x707A
CINEMATIC_347		EQU 0x71A2
CINEMATIC_348		EQU 0x71D0
CINEMATIC_349		EQU 0x7200
CINEMATIC_350		EQU 0x7230
CINEMATIC_351		EQU 0xAF5C
CINEMATIC_352		EQU 0xB8FA
CINEMATIC_353		EQU 0x9CDC
CINEMATIC_354		EQU 0xA760
CINEMATIC_355		EQU 0xE002
CINEMATIC_356		EQU 0xA3D4
CINEMATIC_357		EQU 0xA400
CINEMATIC_358		EQU 0xA348
CINEMATIC_359		EQU 0x6F0C
CINEMATIC_360		EQU 0x9D24
CINEMATIC_361		EQU 0xA804
CINEMATIC_362		EQU 0xA390
CINEMATIC_363		EQU 0xA83E
CINEMATIC_364		EQU 0xA88E
CINEMATIC_365		EQU 0xA8BE
CINEMATIC_366		EQU 0xDFF4
CINEMATIC_367		EQU 0x5FDA
CINEMATIC_368		EQU 0x78B8
CINEMATIC_369		EQU 0xA8DA
CINEMATIC_370		EQU 0x9F52
CINEMATIC_371		EQU 0x70DC
CINEMATIC_372		EQU 0xDE0A
CINEMATIC_373		EQU 0x7498
CINEMATIC_374		EQU 0xB9B4
CINEMATIC_375		EQU 0xB9A8
CINEMATIC_376		EQU 0x747C
CINEMATIC_377		EQU 0xB99C
CINEMATIC_378		EQU 0x7460
CINEMATIC_379		EQU 0xB990
CINEMATIC_380		EQU 0x7444
CINEMATIC_381		EQU 0xB984
CINEMATIC_382		EQU 0xB978
CINEMATIC_383		EQU 0x7428
CINEMATIC_384		EQU 0xB96C
CINEMATIC_385		EQU 0x740C
CINEMATIC_386		EQU 0xB960
CINEMATIC_387		EQU 0x72E4
CINEMATIC_388		EQU 0xD764
CINEMATIC_389		EQU 0xD756
CINEMATIC_390		EQU 0xD726
CINEMATIC_391		EQU 0xD70C
CINEMATIC_392		EQU 0x912C
CINEMATIC_393		EQU 0x9188
CINEMATIC_394		EQU 0xE450
CINEMATIC_395		EQU 0x90D2
CINEMATIC_396		EQU 0x906E
CINEMATIC_397		EQU 0x9BEE
CINEMATIC_398		EQU 0xEAF4
CINEMATIC_399		EQU 0x9118
CINEMATIC_400		EQU 0x44F8
CINEMATIC_401		EQU 0xEAD4
CINEMATIC_402		EQU 0xEAE4
CINEMATIC_403		EQU 0xEAB4
CINEMATIC_404		EQU 0xEA7C
CINEMATIC_405		EQU 0x44E8
CINEMATIC_406		EQU 0xEAC4
CINEMATIC_407		EQU 0xCF20
CINEMATIC_408		EQU 0x91AC
CINEMATIC_409		EQU 0xD4FC
CINEMATIC_410		EQU 0xEA42
CINEMATIC_411		EQU 0xE2E0
CINEMATIC_412		EQU 0xE312
CINEMATIC_413		EQU 0xE35C
CINEMATIC_414		EQU 0xE3A6
CINEMATIC_415		EQU 0x780C
CINEMATIC_416		EQU 0xDE44
CINEMATIC_417		EQU 0x9E64
CINEMATIC_418		EQU 0x9ED2
CINEMATIC_419		EQU 0x9EF6
CINEMATIC_420		EQU 0x9F0E
CINEMATIC_421		EQU 0xD76E
CINEMATIC_422		EQU 0x9DBE
CINEMATIC_423		EQU 0x9E08
CINEMATIC_424		EQU 0x9E1C
CINEMATIC_425		EQU 0x9E34
CINEMATIC_426		EQU 0x9E4C
CINEMATIC_427		EQU 0xDE18
CINEMATIC_428		EQU 0xDEA8
CINEMATIC_429		EQU 0xAA52
CINEMATIC_430		EQU 0xAA8E
CINEMATIC_431		EQU 0xDE90
CINEMATIC_432		EQU 0xDEF8
CINEMATIC_433		EQU 0xEA58
CINEMATIC_434		EQU 0xECCE
CINEMATIC_435		EQU 0xED08
CINEMATIC_436		EQU 0xD516
CINEMATIC_437		EQU 0xF06C
CINEMATIC_438		EQU 0xF076
CINEMATIC_439		EQU 0xF08A
CINEMATIC_440		EQU 0xF094
CINEMATIC_441		EQU 0xF09E
CINEMATIC_442		EQU 0xF0A8
CINEMATIC_443		EQU 0xF080
CINEMATIC_444		EQU 0xC200
CINEMATIC_445		EQU 0x0020
CINEMATIC_446		EQU 0xF4F0
CINEMATIC_447		EQU 0xF4B8
CINEMATIC_448		EQU 0xB9C2
CINEMATIC_449		EQU 0xBB86
CINEMATIC_450		EQU 0xBA2E
CINEMATIC_451		EQU 0xBAA2
CINEMATIC_452		EQU 0xBB12
CINEMATIC_453		EQU 0x34E0
CINEMATIC_454		EQU 0xAAB2
CINEMATIC_455		EQU 0x75D0
CINEMATIC_456		EQU 0x75E8
CINEMATIC_457		EQU 0x761C
CINEMATIC_458		EQU 0x84B8
CINEMATIC_459		EQU 0xD77A
CINEMATIC_460		EQU 0x7634
CINEMATIC_461		EQU 0x767C
CINEMATIC_462		EQU 0x76A4
CINEMATIC_463		EQU 0x76F0
CINEMATIC_464		EQU 0x7724
CINEMATIC_465		EQU 0x84D0
CINEMATIC_466		EQU 0x8514
CINEMATIC_467		EQU 0x8550
CINEMATIC_468		EQU 0x8596
CINEMATIC_469		EQU 0x85C8
CINEMATIC_470		EQU 0x842E
CINEMATIC_471		EQU 0x844A
CINEMATIC_472		EQU 0x5690
CINEMATIC_473		EQU 0x8F2A
CINEMATIC_474		EQU 0x8F9A
CINEMATIC_475		EQU 0x9006
CINEMATIC_476		EQU 0x56E0
CINEMATIC_477		EQU 0x570C
CINEMATIC_478		EQU 0x5738
CINEMATIC_479		EQU 0x5764
CINEMATIC_480		EQU 0x57EC
CINEMATIC_481		EQU 0x5820
CINEMATIC_482		EQU 0x583C
CINEMATIC_483		EQU 0x5858
CINEMATIC_484		EQU 0x5874
CINEMATIC_485		EQU 0x588C
CINEMATIC_486		EQU 0x58A8
CINEMATIC_487		EQU 0x58C0
CINEMATIC_488		EQU 0x58D8
CINEMATIC_489		EQU 0x58F8
CINEMATIC_490		EQU 0x5910
CINEMATIC_491		EQU 0x534C
CINEMATIC_492		EQU 0x53BC
CINEMATIC_493		EQU 0x5428
CINEMATIC_494		EQU 0x8E3E
CINEMATIC_495		EQU 0x8EA6
CINEMATIC_496		EQU 0x8F0A
CINEMATIC_497		EQU 0x8D8E
CINEMATIC_498		EQU 0x8DAA
CINEMATIC_499		EQU 0x8DC6
CINEMATIC_500		EQU 0x8DE2
CINEMATIC_501		EQU 0x8DFE
CINEMATIC_502		EQU 0xE9B6
CINEMATIC_503		EQU 0xE9C2
CINEMATIC_504		EQU 0xE9CE
CINEMATIC_505		EQU 0xE9DA
CINEMATIC_506		EQU 0xE9E6
CINEMATIC_507		EQU 0xE9F2
CINEMATIC_508		EQU 0xE9FE
CINEMATIC_509		EQU 0xEA0A
CINEMATIC_510		EQU 0xEA16
CINEMATIC_511		EQU 0xEA2A
CINEMATIC_512		EQU 0xEA36
CINEMATIC_513		EQU 0x8B44
CINEMATIC_514		EQU 0x8BA4
CINEMATIC_515		EQU 0x8E2A
CINEMATIC_516		EQU 0xB168
CINEMATIC_517		EQU 0xB1C6
CINEMATIC_518		EQU 0xB210
CINEMATIC_519		EQU 0xB258
CINEMATIC_520		EQU 0xB2A0
CINEMATIC_521		EQU 0xD786
CINEMATIC_522		EQU 0xD7E4
CINEMATIC_523		EQU 0xD82C
CINEMATIC_524		EQU 0xD874
CINEMATIC_525		EQU 0xD8B0
CINEMATIC_526		EQU 0xD55A
CINEMATIC_527		EQU 0xD58A
CINEMATIC_528		EQU 0xD5A2
CINEMATIC_529		EQU 0xD5BA
CINEMATIC_530		EQU 0xD5E2
CINEMATIC_531		EQU 0x59D0
CINEMATIC_532		EQU 0x5A68
CINEMATIC_533		EQU 0x5ACC
CINEMATIC_534		EQU 0x5AF4
CINEMATIC_535		EQU 0x5B1C
CINEMATIC_536		EQU 0x5B50
CINEMATIC_537		EQU 0x5B58
CINEMATIC_538		EQU 0x5B60
CINEMATIC_539		EQU 0x5B68
CINEMATIC_540		EQU 0x5BB0
CINEMATIC_541		EQU 0x5BB8
CINEMATIC_542		EQU 0x5BC4
CINEMATIC_543		EQU 0x5BD0
CINEMATIC_544		EQU 0x5BDC
CINEMATIC_545		EQU 0x5BE8
CINEMATIC_546		EQU 0x5BF4
CINEMATIC_547		EQU 0xC3B8
CINEMATIC_548		EQU 0xC390
CINEMATIC_549		EQU 0xC368
CINEMATIC_550		EQU 0xC3E0
CINEMATIC_551		EQU 0xC340
CINEMATIC_552		EQU 0xC30C
CINEMATIC_553		EQU 0xC2E4
CINEMATIC_554		EQU 0xC2BC
CINEMATIC_555		EQU 0xC294
CINEMATIC_556		EQU 0x74C0
CINEMATIC_557		EQU 0x74F4
CINEMATIC_558		EQU 0x7530
CINEMATIC_559		EQU 0xDF64
CINEMATIC_560		EQU 0xE778
CINEMATIC_561		EQU 0x0794
CINEMATIC_562		EQU 0xCEE4
CINEMATIC_563		EQU 0xEB72
CINEMATIC_564		EQU 0xA7E0
CINEMATIC_565		EQU 0xEDC2
CINEMATIC_566		EQU 0xEFD0
CINEMATIC_567		EQU 0xEFBC
CINEMATIC_568		EQU 0xEDF2
CINEMATIC_569		EQU 0xEE26
CINEMATIC_570		EQU 0xEEBA
CINEMATIC_571		EQU 0xEEC2
CINEMATIC_572		EQU 0xEECA
CINEMATIC_573		EQU 0xEF8C
CINEMATIC_574		EQU 0xEF68
CINEMATIC_575		EQU 0xEF44
CINEMATIC_576		EQU 0xEF20
CINEMATIC_577		EQU 0xEEFA
CINEMATIC_578		EQU 0xEED6
CINEMATIC_579		EQU 0x522E
CINEMATIC_580		EQU 0x52E6
CINEMATIC_581		EQU 0xBFC4
CINEMATIC_582		EQU 0x8466
CINEMATIC_583		EQU 0x8482
CINEMATIC_584		EQU 0x8CD0
CINEMATIC_585		EQU 0x8D22
CINEMATIC_586		EQU 0xBF08
CINEMATIC_587		EQU 0xBF54
CINEMATIC_588		EQU 0xBF8E
CINEMATIC_589		EQU 0x46B4
CINEMATIC_590		EQU 0xEAA4
CINEMATIC_591		EQU 0x4CFC
CINEMATIC_592		EQU 0x4B4C
CINEMATIC_593		EQU 0x9228
CINEMATIC_594		EQU 0xEA90
CINEMATIC_595		EQU 0x50D2
CINEMATIC_596		EQU 0x51B6
CINEMATIC_597		EQU 0x509E
CINEMATIC_598		EQU 0x920C
CINEMATIC_599		EQU 0x502A
CINEMATIC_600		EQU 0x47C8
CINEMATIC_601		EQU 0x49FC
CINEMATIC_602		EQU 0x816C
CINEMATIC_603		EQU 0x81A8
CINEMATIC_604		EQU 0x7864
CINEMATIC_605		EQU 0x7884
CINEMATIC_606		EQU 0x9BC8
CINEMATIC_607		EQU 0x91F4
CINEMATIC_608		EQU 0xE7E6
CINEMATIC_609		EQU 0xBFEC
CINEMATIC_610		EQU 0x1E8A
CINEMATIC_611		EQU 0xCD7A
CINEMATIC_612		EQU 0xCDA2
CINEMATIC_613		EQU 0xF240
CINEMATIC_614		EQU 0xCDDC
CINEMATIC_615		EQU 0xCE28
CINEMATIC_616		EQU 0xCE64
CINEMATIC_617		EQU 0xCEA4
CINEMATIC_618		EQU 0xAAF2
CINEMATIC_619		EQU 0xE118
CINEMATIC_620		EQU 0xEB40
CINEMATIC_621		EQU 0xEB48
CINEMATIC_622		EQU 0x783C
CINEMATIC_623		EQU 0xEC70
CINEMATIC_624		EQU 0xEBB6
CINEMATIC_625		EQU 0xEC24
CINEMATIC_626		EQU 0xECB4
CINEMATIC_627		EQU 0xEC9E
CINEMATIC_628		EQU 0x4D80
CINEMATIC_629		EQU 0xAB22
CINEMATIC_630		EQU 0xE03A
CINEMATIC_631		EQU 0xAB56
CINEMATIC_632		EQU 0xAB16
CINEMATIC_633		EQU 0xED2E
CINEMATIC_634		EQU 0x69B2
CINEMATIC_635		EQU 0x69EE
CINEMATIC_636		EQU 0xC676
CINEMATIC_637		EQU 0xC61E
CINEMATIC_638		EQU 0x9200
CINEMATIC_639		EQU 0x8AD8
CINEMATIC_640		EQU 0x9AFE
CINEMATIC_641		EQU 0x8AF0
CINEMATIC_642		EQU 0x8AA6
CINEMATIC_643		EQU 0x8AFC
CINEMATIC_644		EQU 0xEA6C
CINEMATIC_645		EQU 0x9F6A
CINEMATIC_646		EQU 0xA590
CINEMATIC_647		EQU 0xC408
CINEMATIC_648		EQU 0xEFF8
CINEMATIC_649		EQU 0x9240
CINEMATIC_650		EQU 0x6962
CINEMATIC_651		EQU 0x9992
CINEMATIC_652		EQU 0xE3E4
CINEMATIC_653		EQU 0x9A4A
CINEMATIC_654		EQU 0x9694
CINEMATIC_655		EQU 0xB34C
CINEMATIC_656		EQU 0xB390
CINEMATIC_657		EQU 0xB400
CINEMATIC_658		EQU 0xB46C
CINEMATIC_659		EQU 0xB4D8
CINEMATIC_660		EQU 0xB52C
CINEMATIC_661		EQU 0xB56C
CINEMATIC_662		EQU 0x9706
CINEMATIC_663		EQU 0x9756
CINEMATIC_664		EQU 0x97C6
CINEMATIC_665		EQU 0x9832
CINEMATIC_666		EQU 0x989E
CINEMATIC_667		EQU 0x98F2
CINEMATIC_668		EQU 0x9932
CINEMATIC_669		EQU 0x9A9E
CINEMATIC_670		EQU 0x9ABC
CINEMATIC_671		EQU 0x8112
CINEMATIC_672		EQU 0x7ECA
CINEMATIC_673		EQU 0x7F28
CINEMATIC_674		EQU 0x7F86
CINEMATIC_675		EQU 0x871E
CINEMATIC_676		EQU 0xF4A8
CINEMATIC_677		EQU 0xC9BE
CINEMATIC_678		EQU 0xCCFA
CINEMATIC_679		EQU 0xC946
CINEMATIC_680		EQU 0xC9E2
CINEMATIC_681		EQU 0xC99A
CINEMATIC_682		EQU 0xCA56
CINEMATIC_683		EQU 0xC9A6
CINEMATIC_684		EQU 0xCADA
CINEMATIC_685		EQU 0xC9B2
CINEMATIC_686		EQU 0xCB62
CINEMATIC_687		EQU 0xC9CA
CINEMATIC_688		EQU 0xCBE6
CINEMATIC_689		EQU 0xC9D6
CINEMATIC_690		EQU 0xCC5A
CINEMATIC_691		EQU 0x872A
CINEMATIC_692		EQU 0x8746
CINEMATIC_693		EQU 0x87C2
CINEMATIC_694		EQU 0x8832
CINEMATIC_695		EQU 0x8862
CINEMATIC_696		EQU 0x88CE
CINEMATIC_697		EQU 0x891A
CINEMATIC_698		EQU 0x897A
CINEMATIC_699		EQU 0x89CE
CINEMATIC_700		EQU 0x8A2A
CINEMATIC_701		EQU 0x8A72
CINEMATIC_702		EQU 0x7FE4
CINEMATIC_703		EQU 0x7E6A
CINEMATIC_704		EQU 0x7E7A
CINEMATIC_705		EQU 0x7E8A
CINEMATIC_706		EQU 0x7E9A
CINEMATIC_707		EQU 0x7EAA
CINEMATIC_708		EQU 0x7EBA
CINEMATIC_709		EQU 0x7DEA
CINEMATIC_710		EQU 0x7DFA
CINEMATIC_711		EQU 0x7E0A
CINEMATIC_712		EQU 0x7E1A
CINEMATIC_713		EQU 0x7E2A
CINEMATIC_714		EQU 0x7E3A
CINEMATIC_715		EQU 0x7E4A
CINEMATIC_716		EQU 0x7E5A
CINEMATIC_717		EQU 0x6976
CINEMATIC_718		EQU 0x6AAE
CINEMATIC_719		EQU 0x9640
CINEMATIC_720		EQU 0xC6D6
CINEMATIC_721		EQU 0xEB0C
CINEMATIC_722		EQU 0xEB24
CINEMATIC_723		EQU 0xE478
CINEMATIC_724		EQU 0x8042
CINEMATIC_725		EQU 0x80AC
CINEMATIC_726		EQU 0x6ABA
CINEMATIC_727		EQU 0x9516
CINEMATIC_728		EQU 0x953A
CINEMATIC_729		EQU 0xEB34
CINEMATIC_730		EQU 0x95A4
CINEMATIC_731		EQU 0x958C
CINEMATIC_732		EQU 0x95BC
CINEMATIC_733		EQU 0x95F0
CINEMATIC_734		EQU 0x756C
CINEMATIC_735		EQU 0x7590
CINEMATIC_736		EQU 0xB7B2
CINEMATIC_737		EQU 0x7B58
CINEMATIC_738		EQU 0xB7D6
CINEMATIC_739		EQU 0x7BC8
CINEMATIC_740		EQU 0xB78E
CINEMATIC_741		EQU 0x7C30
CINEMATIC_742		EQU 0x7C94
CINEMATIC_743		EQU 0x7CF8
CINEMATIC_744		EQU 0x7D60
CINEMATIC_745		EQU 0xB76A
CINEMATIC_746		EQU 0x9604
CINEMATIC_747		EQU 0x9634
CINEMATIC_748		EQU 0x9F96
CINEMATIC_749		EQU 0xF03C
CINEMATIC_750		EQU 0xAB6E
CINEMATIC_751		EQU 0xABDE
CINEMATIC_752		EQU 0xAC52
CINEMATIC_753		EQU 0xC008
CINEMATIC_754		EQU 0x943A
CINEMATIC_755		EQU 0x93F6
CINEMATIC_756		EQU 0x4E56
CINEMATIC_757		EQU 0xC278
CINEMATIC_758		EQU 0xF058
CINEMATIC_759		EQU 0xC24E
CINEMATIC_760		EQU 0xC23A
CINEMATIC_761		EQU 0x4ED0
CINEMATIC_762		EQU 0x4DE4
CINEMATIC_763		EQU 0x921C
CINEMATIC_764		EQU 0xF20A
CINEMATIC_765		EQU 0x22CC
CINEMATIC_766		EQU 0x22E4
CINEMATIC_767		EQU 0x22FC
CINEMATIC_768		EQU 0xE062
CINEMATIC_769		EQU 0x2298
CINEMATIC_770		EQU 0x31E6
CINEMATIC_771		EQU 0x2A62
CINEMATIC_772		EQU 0x2A4A
CINEMATIC_773		EQU 0x2A2E
CINEMATIC_774		EQU 0x2A12
CINEMATIC_775		EQU 0x29EA
CINEMATIC_776		EQU 0x29C6
CINEMATIC_777		EQU 0x3250
CINEMATIC_778		EQU 0x2A76
CINEMATIC_779		EQU 0x28F0
CINEMATIC_780		EQU 0x28D0
CINEMATIC_781		EQU 0x288A
CINEMATIC_782		EQU 0x281E
CINEMATIC_783		EQU 0x27C8
CINEMATIC_784		EQU 0x2778
CINEMATIC_785		EQU 0x2728
CINEMATIC_786		EQU 0x26B4
CINEMATIC_787		EQU 0x2652
CINEMATIC_788		EQU 0x3DF6
CINEMATIC_789		EQU 0x2520
CINEMATIC_790		EQU 0x253C
CINEMATIC_791		EQU 0x2558
CINEMATIC_792		EQU 0x2578
CINEMATIC_793		EQU 0x2594
CINEMATIC_794		EQU 0x25A8
CINEMATIC_795		EQU 0x8188
CINEMATIC_796		EQU 0x4600
CINEMATIC_797		EQU 0x45CC
CINEMATIC_798		EQU 0x4598
CINEMATIC_799		EQU 0x4564
CINEMATIC_800		EQU 0x4530
CINEMATIC_801		EQU 0x8416
CINEMATIC_802		EQU 0x86AA
CINEMATIC_803		EQU 0x8652
CINEMATIC_804		EQU 0x86DE
CINEMATIC_805		EQU 0x46D4
CINEMATIC_806		EQU 0x46BC
CINEMATIC_807		EQU 0x471C
CINEMATIC_808		EQU 0x4704
CINEMATIC_809		EQU 0x46EC
CINEMATIC_810		EQU 0x5490
CINEMATIC_811		EQU 0x54B8
CINEMATIC_812		EQU 0x54F4
CINEMATIC_813		EQU 0x551C
CINEMATIC_814		EQU 0x556C
CINEMATIC_815		EQU 0x85E2
CINEMATIC_816		EQU 0x821C
CINEMATIC_817		EQU 0x826E
CINEMATIC_818		EQU 0x82DA
CINEMATIC_819		EQU 0x8606
CINEMATIC_820		EQU 0x863C
CINEMATIC_821		EQU 0x861C
CINEMATIC_822		EQU 0x4080
CINEMATIC_823		EQU 0x4060
CINEMATIC_824		EQU 0x401A
CINEMATIC_825		EQU 0x3FAE
CINEMATIC_826		EQU 0x3F58
CINEMATIC_827		EQU 0x3F08
CINEMATIC_828		EQU 0x3EB8
CINEMATIC_829		EQU 0x3E68
CINEMATIC_830		EQU 0x3E42
CINEMATIC_831		EQU 0x2314
CINEMATIC_832		EQU 0x2348
CINEMATIC_833		EQU 0x2364
CINEMATIC_834		EQU 0x2384
CINEMATIC_835		EQU 0x23A0
CINEMATIC_836		EQU 0x23B4
CINEMATIC_837		EQU 0x11A4
CINEMATIC_838		EQU 0x11B8
CINEMATIC_839		EQU 0x320A
CINEMATIC_840		EQU 0x11CC
CINEMATIC_841		EQU 0x3212
CINEMATIC_842		EQU 0x11E0
CINEMATIC_843		EQU 0x321A
CINEMATIC_844		EQU 0x11F4
CINEMATIC_845		EQU 0x3222
CINEMATIC_846		EQU 0x1208
CINEMATIC_847		EQU 0x322A
CINEMATIC_848		EQU 0x3246
CINEMATIC_849		EQU 0x323C
CINEMATIC_850		EQU 0x3A20
CINEMATIC_851		EQU 0x3A28
CINEMATIC_852		EQU 0x121C
CINEMATIC_853		EQU 0x3232
CINEMATIC_854		EQU 0x23D8
CINEMATIC_855		EQU 0x2410
CINEMATIC_856		EQU 0x2444
CINEMATIC_857		EQU 0x12E0
CINEMATIC_858		EQU 0x1300
CINEMATIC_859		EQU 0x2474
CINEMATIC_860		EQU 0x24F6
CINEMATIC_861		EQU 0x2502
CINEMATIC_862		EQU 0x2514
CINEMATIC_863		EQU 0x19EA
CINEMATIC_864		EQU 0x19A2
CINEMATIC_865		EQU 0x19D2
CINEMATIC_866		EQU 0x1444
CINEMATIC_867		EQU 0x3450
CINEMATIC_868		EQU 0x1400
CINEMATIC_869		EQU 0x343C
CINEMATIC_870		EQU 0x5594
CINEMATIC_871		EQU 0x55A8
CINEMATIC_872		EQU 0x55C0
CINEMATIC_873		EQU 0x55E0
CINEMATIC_874		EQU 0x55EC
CINEMATIC_875		EQU 0x55F4
CINEMATIC_876		EQU 0x5610
CINEMATIC_877		EQU 0x562C
CINEMATIC_878		EQU 0x5644
CINEMATIC_879		EQU 0x5668
CINEMATIC_880		EQU 0x5674
CINEMATIC_881		EQU 0x005C
CINEMATIC_882		EQU 0x10C0
CINEMATIC_883		EQU 0x14C0
CINEMATIC_884		EQU 0x200E
CINEMATIC_885		EQU 0x1F92
CINEMATIC_886		EQU 0x1F12
CINEMATIC_887		EQU 0x1E0A
CINEMATIC_888		EQU 0x327C
CINEMATIC_889		EQU 0x8B14
CINEMATIC_890		EQU 0xA5C4
CINEMATIC_891		EQU 0xC02C
CINEMATIC_892		EQU 0xC090
CINEMATIC_893		EQU 0x0200
COMMON_VIDEO_000		EQU 0x5DE4
COMMON_VIDEO_001		EQU 0x3322
COMMON_VIDEO_002		EQU 0x0358
COMMON_VIDEO_003		EQU 0x4D98
COMMON_VIDEO_004		EQU 0x4DE4
COMMON_VIDEO_005		EQU 0x4E30
COMMON_VIDEO_006		EQU 0x4E7C
COMMON_VIDEO_007		EQU 0x4EC8
COMMON_VIDEO_008		EQU 0x4F14
COMMON_VIDEO_009		EQU 0x4F68
COMMON_VIDEO_010		EQU 0x500C
COMMON_VIDEO_011		EQU 0x5058
COMMON_VIDEO_012		EQU 0x50A8
COMMON_VIDEO_013		EQU 0x50F8
COMMON_VIDEO_014		EQU 0x514C
COMMON_VIDEO_015		EQU 0x5DDC
COMMON_VIDEO_016		EQU 0x0F90
COMMON_VIDEO_017		EQU 0x338E
COMMON_VIDEO_018		EQU 0x0FF8
COMMON_VIDEO_019		EQU 0x3398
COMMON_VIDEO_020		EQU 0x1060
COMMON_VIDEO_021		EQU 0x33A2
COMMON_VIDEO_022		EQU 0x108C
COMMON_VIDEO_023		EQU 0x33AC
COMMON_VIDEO_024		EQU 0x10B8
COMMON_VIDEO_025		EQU 0x33B6
COMMON_VIDEO_026		EQU 0x10E4
COMMON_VIDEO_027		EQU 0x33C0
COMMON_VIDEO_028		EQU 0x1110
COMMON_VIDEO_029		EQU 0x33CA
COMMON_VIDEO_030		EQU 0x1136
COMMON_VIDEO_031		EQU 0x33D4
COMMON_VIDEO_032		EQU 0x115C
COMMON_VIDEO_033		EQU 0x33DE
COMMON_VIDEO_034		EQU 0x117E
COMMON_VIDEO_035		EQU 0x33E8
COMMON_VIDEO_036		EQU 0x0CBA
COMMON_VIDEO_037		EQU 0x3352
COMMON_VIDEO_038		EQU 0x0D48
COMMON_VIDEO_039		EQU 0x335C
COMMON_VIDEO_040		EQU 0x0DB6
COMMON_VIDEO_041		EQU 0x3366
COMMON_VIDEO_042		EQU 0x0E38
COMMON_VIDEO_043		EQU 0x3370
COMMON_VIDEO_044		EQU 0x0EB6
COMMON_VIDEO_045		EQU 0x337A
COMMON_VIDEO_046		EQU 0x0F28
COMMON_VIDEO_047		EQU 0x3384
COMMON_VIDEO_048		EQU 0x52C0
COMMON_VIDEO_049		EQU 0x52E0
COMMON_VIDEO_050		EQU 0x5300
COMMON_VIDEO_051		EQU 0x5320
COMMON_VIDEO_052		EQU 0x5340
COMMON_VIDEO_053		EQU 0x5360
COMMON_VIDEO_054		EQU 0x5380
COMMON_VIDEO_055		EQU 0x53C0
COMMON_VIDEO_056		EQU 0x53E0
COMMON_VIDEO_057		EQU 0x5400
COMMON_VIDEO_058		EQU 0x5420
COMMON_VIDEO_059		EQU 0x5444
COMMON_VIDEO_060		EQU 0x332A
COMMON_VIDEO_061		EQU 0x037C
COMMON_VIDEO_062		EQU 0x3332
COMMON_VIDEO_063		EQU 0x0764
COMMON_VIDEO_064		EQU 0x333A
COMMON_VIDEO_065		EQU 0x0790
COMMON_VIDEO_066		EQU 0x3342
COMMON_VIDEO_067		EQU 0x07BC
COMMON_VIDEO_068		EQU 0x334A
COMMON_VIDEO_069		EQU 0x07E8
COMMON_VIDEO_070		EQU 0x0814
COMMON_VIDEO_071		EQU 0x0844
COMMON_VIDEO_072		EQU 0x0874
COMMON_VIDEO_073		EQU 0x08A0
COMMON_VIDEO_074		EQU 0x0020
COMMON_VIDEO_075		EQU 0x00B4
COMMON_VIDEO_076		EQU 0x0128
COMMON_VIDEO_077		EQU 0x01B0
COMMON_VIDEO_078		EQU 0x0234
COMMON_VIDEO_079		EQU 0x331A
COMMON_VIDEO_080		EQU 0x02AC
COMMON_VIDEO_081		EQU 0x03E4
COMMON_VIDEO_082		EQU 0x34AA
COMMON_VIDEO_083		EQU 0x0472
COMMON_VIDEO_084		EQU 0x34B2
COMMON_VIDEO_085		EQU 0x4FBC
COMMON_VIDEO_086		EQU 0x06A2
COMMON_VIDEO_087		EQU 0x34D6
COMMON_VIDEO_088		EQU 0x06C8
COMMON_VIDEO_089		EQU 0x34DE
COMMON_VIDEO_090		EQU 0x06EE
COMMON_VIDEO_091		EQU 0x34E6
COMMON_VIDEO_092		EQU 0x0714
COMMON_VIDEO_093		EQU 0x34EE
COMMON_VIDEO_094		EQU 0x073E
COMMON_VIDEO_095		EQU 0x34F6
COMMON_VIDEO_096		EQU 0x53A0
COMMON_VIDEO_097		EQU 0x3650
COMMON_VIDEO_098		EQU 0x150A
COMMON_VIDEO_099		EQU 0x3674
COMMON_VIDEO_100		EQU 0x1530
COMMON_VIDEO_101		EQU 0x3658
COMMON_VIDEO_102		EQU 0x1556
COMMON_VIDEO_103		EQU 0x3660
COMMON_VIDEO_104		EQU 0x157C
COMMON_VIDEO_105		EQU 0x366C
COMMON_VIDEO_106		EQU 0x15A2
COMMON_VIDEO_107		EQU 0x3630
COMMON_VIDEO_108		EQU 0x11B8
COMMON_VIDEO_109		EQU 0x3638
COMMON_VIDEO_110		EQU 0x125A
COMMON_VIDEO_111		EQU 0x3640
COMMON_VIDEO_112		EQU 0x1304
COMMON_VIDEO_113		EQU 0x3648
COMMON_VIDEO_114		EQU 0x13B2
COMMON_VIDEO_115		EQU 0x1474
COMMON_VIDEO_116		EQU 0x04F4
COMMON_VIDEO_117		EQU 0x34BA
COMMON_VIDEO_118		EQU 0x058E
COMMON_VIDEO_119		EQU 0x34C2
COMMON_VIDEO_120		EQU 0x0624
COMMON_VIDEO_121		EQU 0x34CE
COMMON_VIDEO_122		EQU 0x3614
COMMON_VIDEO_123		EQU 0x5C8C
COMMON_VIDEO_124		EQU 0x35F8
COMMON_VIDEO_125		EQU 0x35D0
COMMON_VIDEO_126		EQU 0x35B4
COMMON_VIDEO_127		EQU 0x5E44
COMMON_VIDEO_128		EQU 0x40CA
COMMON_VIDEO_129		EQU 0x1B14
COMMON_VIDEO_130		EQU 0x5F94
COMMON_VIDEO_131		EQU 0x39A2
COMMON_VIDEO_132		EQU 0x5C94
COMMON_VIDEO_133		EQU 0x57C4
COMMON_VIDEO_134		EQU 0x5878
COMMON_VIDEO_135		EQU 0x5944
COMMON_VIDEO_136		EQU 0x5A08
COMMON_VIDEO_137		EQU 0x5AAC
COMMON_VIDEO_138		EQU 0x5B4C
COMMON_VIDEO_139		EQU 0x4754
COMMON_VIDEO_140		EQU 0x485C
COMMON_VIDEO_141		EQU 0x4BC4
COMMON_VIDEO_142		EQU 0x4B4C
COMMON_VIDEO_143		EQU 0x4ACC
COMMON_VIDEO_144		EQU 0x4A6C
COMMON_VIDEO_145		EQU 0x4A04
COMMON_VIDEO_146		EQU 0x49B0
COMMON_VIDEO_147		EQU 0x48D8
COMMON_VIDEO_148		EQU 0x4954
COMMON_VIDEO_149		EQU 0x46D4
COMMON_VIDEO_150		EQU 0x45C0
COMMON_VIDEO_151		EQU 0x4528
COMMON_VIDEO_152		EQU 0x448C
COMMON_VIDEO_153		EQU 0x344E
COMMON_VIDEO_154		EQU 0x5C1C
COMMON_VIDEO_155		EQU 0x3420
COMMON_VIDEO_156		EQU 0x5C14
COMMON_VIDEO_157		EQU 0x33F2
COMMON_VIDEO_158		EQU 0x5C0C
COMMON_VIDEO_159		EQU 0x347C
COMMON_VIDEO_160		EQU 0x5BF8
COMMON_VIDEO_161		EQU 0x4650
COMMON_VIDEO_162		EQU 0x4C40
COMMON_VIDEO_163		EQU 0x47DC
COMMON_VIDEO_164		EQU 0x40EC
COMMON_VIDEO_165		EQU 0x2B0E
COMMON_VIDEO_166		EQU 0x5FCC
COMMON_VIDEO_167		EQU 0x247C
COMMON_VIDEO_168		EQU 0x181C
COMMON_VIDEO_169		EQU 0x1A84
COMMON_VIDEO_170		EQU 0x5F7C
COMMON_VIDEO_171		EQU 0x1866
COMMON_VIDEO_172		EQU 0x18B0
COMMON_VIDEO_173		EQU 0x1AB4
COMMON_VIDEO_174		EQU 0x5F84
COMMON_VIDEO_175		EQU 0x18FA
COMMON_VIDEO_176		EQU 0x1AE4
COMMON_VIDEO_177		EQU 0x5F8C
COMMON_VIDEO_178		EQU 0x1944
COMMON_VIDEO_179		EQU 0x2474
COMMON_VIDEO_180		EQU 0x198E
COMMON_VIDEO_181		EQU 0x1B44
COMMON_VIDEO_182		EQU 0x5F9C
COMMON_VIDEO_183		EQU 0x246C
COMMON_VIDEO_184		EQU 0x19C4
COMMON_VIDEO_185		EQU 0x1B74
COMMON_VIDEO_186		EQU 0x5FA4
COMMON_VIDEO_187		EQU 0x245C
COMMON_VIDEO_188		EQU 0x1A0E
COMMON_VIDEO_189		EQU 0x1BA4
COMMON_VIDEO_190		EQU 0x5FAC
COMMON_VIDEO_191		EQU 0x2464
COMMON_VIDEO_192		EQU 0x1D78
COMMON_VIDEO_193		EQU 0x1BD4
COMMON_VIDEO_194		EQU 0x5FB4
COMMON_VIDEO_195		EQU 0x1D9A
COMMON_VIDEO_196		EQU 0x1DBC
COMMON_VIDEO_197		EQU 0x1DDE
COMMON_VIDEO_198		EQU 0x1E00
COMMON_VIDEO_199		EQU 0x1E22
COMMON_VIDEO_200		EQU 0x1E44
COMMON_VIDEO_201		EQU 0x1E66
COMMON_VIDEO_202		EQU 0x1A54
COMMON_VIDEO_203		EQU 0x5F74
COMMON_VIDEO_204		EQU 0x2D6E
COMMON_VIDEO_205		EQU 0x257A
COMMON_VIDEO_206		EQU 0x2AC6
COMMON_VIDEO_207		EQU 0x5FC4
COMMON_VIDEO_208		EQU 0x2610
COMMON_VIDEO_209		EQU 0x2672
COMMON_VIDEO_210		EQU 0x270C
COMMON_VIDEO_211		EQU 0x2B56
COMMON_VIDEO_212		EQU 0x5FD4
COMMON_VIDEO_213		EQU 0x2786
COMMON_VIDEO_214		EQU 0x2B9E
COMMON_VIDEO_215		EQU 0x5FDC
COMMON_VIDEO_216		EQU 0x2D66
COMMON_VIDEO_217		EQU 0x27FC
COMMON_VIDEO_218		EQU 0x2BE6
COMMON_VIDEO_219		EQU 0x5FE4
COMMON_VIDEO_220		EQU 0x2D5E
COMMON_VIDEO_221		EQU 0x287E
COMMON_VIDEO_222		EQU 0x2C2E
COMMON_VIDEO_223		EQU 0x5FEC
COMMON_VIDEO_224		EQU 0x2D4E
COMMON_VIDEO_225		EQU 0x28F8
COMMON_VIDEO_226		EQU 0x2C76
COMMON_VIDEO_227		EQU 0x5FF4
COMMON_VIDEO_228		EQU 0x2D56
COMMON_VIDEO_229		EQU 0x296E
COMMON_VIDEO_230		EQU 0x2CBE
COMMON_VIDEO_231		EQU 0x5FFC
COMMON_VIDEO_232		EQU 0x2990
COMMON_VIDEO_233		EQU 0x29B2
COMMON_VIDEO_234		EQU 0x29D4
COMMON_VIDEO_235		EQU 0x29F6
COMMON_VIDEO_236		EQU 0x2A18
COMMON_VIDEO_237		EQU 0x2A3A
COMMON_VIDEO_238		EQU 0x2A5C
COMMON_VIDEO_239		EQU 0x2A7E
COMMON_VIDEO_240		EQU 0x5FBC
COMMON_VIDEO_241		EQU 0x2566
COMMON_VIDEO_242		EQU 0x1F70
COMMON_VIDEO_243		EQU 0x6108
COMMON_VIDEO_244		EQU 0x255C
COMMON_VIDEO_245		EQU 0x1FE4
COMMON_VIDEO_246		EQU 0x21A8
COMMON_VIDEO_247		EQU 0x2552
COMMON_VIDEO_248		EQU 0x2058
COMMON_VIDEO_249		EQU 0x21D6
COMMON_VIDEO_250		EQU 0x2548
COMMON_VIDEO_251		EQU 0x20B8
COMMON_VIDEO_252		EQU 0x2200
COMMON_VIDEO_253		EQU 0x2570
COMMON_VIDEO_254		EQU 0x2134
COMMON_VIDEO_255		EQU 0x2212
COMMON_VIDEO_256		EQU 0x2310
COMMON_VIDEO_257		EQU 0x232C
COMMON_VIDEO_258		EQU 0x2348
COMMON_VIDEO_259		EQU 0x224C
COMMON_VIDEO_260		EQU 0x2364
COMMON_VIDEO_261		EQU 0x2276
COMMON_VIDEO_262		EQU 0x2380
COMMON_VIDEO_263		EQU 0x320A
COMMON_VIDEO_264		EQU 0x2D76
COMMON_VIDEO_265		EQU 0x61A2
COMMON_VIDEO_266		EQU 0x3200
COMMON_VIDEO_267		EQU 0x2E0A
COMMON_VIDEO_268		EQU 0x3116
COMMON_VIDEO_269		EQU 0x31F6
COMMON_VIDEO_270		EQU 0x2E9E
COMMON_VIDEO_271		EQU 0x3124
COMMON_VIDEO_272		EQU 0x31EC
COMMON_VIDEO_273		EQU 0x2F3A
COMMON_VIDEO_274		EQU 0x316E
COMMON_VIDEO_275		EQU 0x3212
COMMON_VIDEO_276		EQU 0x2FD6
COMMON_VIDEO_277		EQU 0x3180
COMMON_VIDEO_278		EQU 0x304A
COMMON_VIDEO_279		EQU 0x3066
COMMON_VIDEO_280		EQU 0x3082
COMMON_VIDEO_281		EQU 0x31A8
COMMON_VIDEO_282		EQU 0x309E
COMMON_VIDEO_283		EQU 0x31CA
COMMON_VIDEO_284		EQU 0x30BA
COMMON_VIDEO_285		EQU 0x4132
COMMON_VIDEO_286		EQU 0x42BA
COMMON_VIDEO_287		EQU 0x4314
COMMON_VIDEO_288		EQU 0x3E4E
COMMON_VIDEO_289		EQU 0x4324
COMMON_VIDEO_290		EQU 0x426C
COMMON_VIDEO_291		EQU 0x4346
COMMON_VIDEO_292		EQU 0x4368
COMMON_VIDEO_293		EQU 0x3A64
COMMON_VIDEO_294		EQU 0x5C9C
COMMON_VIDEO_295		EQU 0x3542
COMMON_VIDEO_296		EQU 0x3558
COMMON_VIDEO_297		EQU 0x34FE
COMMON_VIDEO_298		EQU 0x367C
COMMON_VIDEO_299		EQU 0x352C
COMMON_VIDEO_300		EQU 0x356E
COMMON_VIDEO_301		EQU 0x1C78
COMMON_VIDEO_302		EQU 0x3B44
COMMON_VIDEO_303		EQU 0x5CA4
COMMON_VIDEO_304		EQU 0x3C92
COMMON_VIDEO_305		EQU 0x5C6C
COMMON_VIDEO_306		EQU 0x3C66
COMMON_VIDEO_307		EQU 0x5C64
COMMON_VIDEO_308		EQU 0x3C3A
COMMON_VIDEO_309		EQU 0x5C5C
COMMON_VIDEO_310		EQU 0x3B96
COMMON_VIDEO_311		EQU 0x5CAC
COMMON_VIDEO_312		EQU 0x3BE8
COMMON_VIDEO_313		EQU 0x5CB4
COMMON_VIDEO_314		EQU 0x41A8
COMMON_VIDEO_315		EQU 0x5C74
COMMON_VIDEO_316		EQU 0x41E0
COMMON_VIDEO_317		EQU 0x5C7C
COMMON_VIDEO_318		EQU 0x4218
COMMON_VIDEO_319		EQU 0x5C84
COMMON_VIDEO_320		EQU 0x3EEC
COMMON_VIDEO_321		EQU 0x5CBC
COMMON_VIDEO_322		EQU 0x6004
COMMON_VIDEO_323		EQU 0x3F4A
COMMON_VIDEO_324		EQU 0x5CC4
COMMON_VIDEO_325		EQU 0x6010
COMMON_VIDEO_326		EQU 0x4058
COMMON_VIDEO_327		EQU 0x5CCC
COMMON_VIDEO_328		EQU 0x4416
COMMON_VIDEO_329		EQU 0x1600
COMMON_VIDEO_330		EQU 0x38D2
COMMON_VIDEO_331		EQU 0x3764
COMMON_VIDEO_332		EQU 0x5C4C
COMMON_VIDEO_333		EQU 0x389E
COMMON_VIDEO_334		EQU 0x1664
COMMON_VIDEO_335		EQU 0x61B0
COMMON_VIDEO_336		EQU 0x17A8
COMMON_VIDEO_337		EQU 0x3B10
COMMON_VIDEO_338		EQU 0x3ADC
COMMON_VIDEO_339		EQU 0x17CC
COMMON_VIDEO_340		EQU 0x1784
COMMON_VIDEO_341		EQU 0x5E9C
COMMON_VIDEO_342		EQU 0x5DEC
COMMON_VIDEO_343		EQU 0x5D84
COMMON_VIDEO_344		EQU 0x5D2C
COMMON_VIDEO_345		EQU 0x5CD4
COMMON_VIDEO_346		EQU 0x391A
COMMON_VIDEO_347		EQU 0x3A96
COMMON_VIDEO_348		EQU 0x36D2
COMMON_VIDEO_349		EQU 0x5C54
COMMON_VIDEO_350		EQU 0x3858
COMMON_VIDEO_351		EQU 0x15DC
COMMON_VIDEO_352		EQU 0x09F6
COMMON_VIDEO_353		EQU 0x3FA8
COMMON_VIDEO_354		EQU 0x3F8C
COMMON_VIDEO_355		EQU 0x3FB8
COMMON_VIDEO_356		EQU 0x3FD4
COMMON_VIDEO_357		EQU 0x40BE


	org 0x0000

LABEL_0000:
	call CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8	;@raw=0x04,0x42,0xC9
	setup channel=0x3C, address=LABEL_3F46	;@raw=0x08,0x3C,0x3F,0x46
	mov [PAUSE_SLICES], 0x0004
	mov [0xF6], 0x0001
	mov [0xE3], 0x0000
	mov [0x32], 0x0000
	break
	play id=0x006A, freq=0x14, vol=0x00, channel=0x02
	play id=0x006A, freq=0x14, vol=0x00, channel=0x03
	play id=0x006A, freq=0x14, vol=0x00, channel=0x01
	play id=0x006A, freq=0x14, vol=0x00, channel=0x00
	call INIT_HASH_VARS_67_66_65_68_69	;@raw=0x04,0x47,0x38
	call LABEL_DDE2	;@raw=0x04,0xDD,0xE2
	call LABEL_43A5	;@raw=0x04,0x43,0xA5
	call LABEL_1456	;@raw=0x04,0x14,0x56
	setup channel=0x14, address=LABEL_39E3	;@raw=0x08,0x14,0x39,0xE3
	setup channel=0x15, address=LABEL_3A26	;@raw=0x08,0x15,0x3A,0x26
	setup channel=0x14, address=LABEL_EA2E	;@raw=0x08,0x14,0xEA,0x2E
	setup channel=0x15, address=KILL_CHANNEL_LANDING	;@raw=0x08,0x15,0x01,0xFA
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63	;@raw=0x08,0x16,0xE5,0x14
	call LABEL_DACD	;@raw=0x04,0xDA,0xCD
	setup channel=0x3F, address=LABEL_DD1F	;@raw=0x08,0x3F,0xDD,0x1F
	killChannel

LABEL_0058:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	load id=0x07D7	;@raw=0x19,0x07,0xD7
	ret

LABEL_0062:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	load id=0x07D8	;@raw=0x19,0x07,0xD8
	ret

LABEL_006C:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	load id=0x07D9	;@raw=0x19,0x07,0xD9
	ret

LABEL_0076:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	load id=0x07DA	;@raw=0x19,0x07,0xDA
	ret

LABEL_0080:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	load id=0x07DB	;@raw=0x19,0x07,0xDB
	ret

LABEL_008A:
	je [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x00,0xDB,0x00,0x82,0x87
	bankSwitch 0;  Arrival at the Lake & Beast Chase	;@raw=0x19,0x07,0xE0
	ret

LABEL_0094:
	jne [HACK_VAR_67], 0x70, SHARED_RET	;@raw=0x0A,0x01,0x67,0x70,0x82,0x87
	jne [0x72], [HACK_VAR_67], LABEL_00C0	;@raw=0x0A,0x81,0x72,0x67,0x00,0xC0
	jge [0x73], 0x4000, LABEL_00C0	;@raw=0x0A,0x43,0x73,0x40,0x00,0x00,0xC0

LABEL_00A7:
	je [HACK_VAR_67], 0x6D, SHARED_RET	;@raw=0x0A,0x00,0x67,0x6D,0x82,0x87
	je [HACK_VAR_67], 0x6C, SHARED_RET	;@raw=0x0A,0x00,0x67,0x6C,0x82,0x87
	jge [HACK_VAR_67], 0xC8, SHARED_RET	;@raw=0x0A,0x03,0x67,0xC8,0x82,0x87
	song id=0x0BBF, delay=0x0000, pos=0x00	;@raw=0x1A,0x0B,0xBF,0x00,0x00,0x00
	ret

LABEL_00C0:
	jne [0x7A], [HACK_VAR_67], SHARED_RET	;@raw=0x0A,0x81,0x7A,0x67,0x82,0x87
	jl [0x7B], 0x4000, LABEL_00A7	;@raw=0x0A,0x44,0x7B,0x40,0x00,0x00,0xA7
	ret
	setup channel=0x05, address=LABEL_3778	;@raw=0x08,0x05,0x37,0x78
	copyVideoPage src=0x03, dst=0x00
	killChannel
	copyVideoPage src=0x00, dst=0x03
	killChannel
	mov [0x00], [0x18]
	mov [0xF8], [0x00]
	shr [0xF8], 0x0008
	video type=1, offset=CINEMATIC_445, x=[0xf8], y=0, zoom=0x40	;@raw=0x58,0x00,0x10,0xF8,0x00
	mov [0xF8], [0x00]
	and [0xF8], 0x00FF
	video type=1, offset=CINEMATIC_445, x=[0xf8], y=1, zoom=0x40	;@raw=0x58,0x00,0x10,0xF8,0x01
	video type=1, offset=CINEMATIC_881, x=[0x01], y=2, zoom=0x40	;@raw=0x58,0x00,0x2E,0x01,0x02
	killChannel

LABEL_00FB:
	and [0xBC], 0x0010
	mov [0xF8], [0xC6]
	and [0xF8], 0x0080
	ret
	je [0xBC], 0x00, LABEL_012E	;@raw=0x0A,0x00,0xBC,0x00,0x01,0x2E
	je [0xF8], 0x00, LABEL_012E	;@raw=0x0A,0x00,0xF8,0x00,0x01,0x2E
	mov [0xF8], [0xE4]
	and [0xF8], 0x003C
	jne [0xF8], 0x14, LABEL_012E	;@raw=0x0A,0x01,0xF8,0x14,0x01,0x2E
	jne [0xF2], 0x0FA0, LABEL_012E	;@raw=0x0A,0x41,0xF2,0x0F,0xA0,0x01,0x2E
	jne [HACK_VAR_DC], 0x21, LABEL_012E	;@raw=0x0A,0x01,0xDC,0x21,0x01,0x2E
	ret

LABEL_012E:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=KILL_CHANNEL_LANDING	;@raw=0x08,0x3C,0x01,0xFA
	killChannel
	mov [0xBC], 0x00FF
	mov [0xC6], 0x00FF
	mov [0xF2], 0x1770
	mov [HACK_VAR_DC], 0x0021
	killChannel

LABEL_0148:
	jne [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x01,0xDB,0x00,0x82,0x87
	load id=0x006A	;@raw=0x19,0x00,0x6A
	load id=0x0077	;@raw=0x19,0x00,0x77
	load id=0x006D	;@raw=0x19,0x00,0x6D
	load id=0x006E	;@raw=0x19,0x00,0x6E
	load id=0x0074	;@raw=0x19,0x00,0x74
	load id=0x0076	;@raw=0x19,0x00,0x76
	load id=0x0078	;@raw=0x19,0x00,0x78
	load id=0x007C	;@raw=0x19,0x00,0x7C
	load id=0x0079	;@raw=0x19,0x00,0x79
	load id=0x007A	;@raw=0x19,0x00,0x7A
	load id=0x007B	;@raw=0x19,0x00,0x7B
	load id=0x006C	;@raw=0x19,0x00,0x6C
	ret

LABEL_0173:
	jne [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x01,0xDB,0x00,0x82,0x87
	load id=0x006B	;@raw=0x19,0x00,0x6B
	load id=0x0055	;@raw=0x19,0x00,0x55
	load id=0x0056	;@raw=0x19,0x00,0x56
	load id=0x0057	;@raw=0x19,0x00,0x57
	load id=0x005E	;@raw=0x19,0x00,0x5E
	load id=0x005F	;@raw=0x19,0x00,0x5F
	load id=0x006B	;@raw=0x19,0x00,0x6B
	load id=0x006C	;@raw=0x19,0x00,0x6C
	load id=0x006D	;@raw=0x19,0x00,0x6D
	load id=0x0075	;@raw=0x19,0x00,0x75
	load id=0x0074	;@raw=0x19,0x00,0x74
	load id=0x0078	;@raw=0x19,0x00,0x78
	load id=0x007A	;@raw=0x19,0x00,0x7A
	load id=0x0077	;@raw=0x19,0x00,0x77
	load id=0x0066	;@raw=0x19,0x00,0x66
	load id=0x0088	;@raw=0x19,0x00,0x88
	load id=0x0070	;@raw=0x19,0x00,0x70
	load id=0x0071	;@raw=0x19,0x00,0x71
	load id=0x0072	;@raw=0x19,0x00,0x72
	ret

LABEL_01B3:
	play id=0x006A, freq=0x14, vol=0x00, channel=0x02
	play id=0x006A, freq=0x14, vol=0x00, channel=0x03
	play id=0x006A, freq=0x14, vol=0x00, channel=0x01
	play id=0x006A, freq=0x14, vol=0x00, channel=0x00
	jne [0xDB], 0x00, SHARED_RET	;@raw=0x0A,0x01,0xDB,0x00,0x82,0x87
	load id=0x0052	;@raw=0x19,0x00,0x52
	load id=0x0058	;@raw=0x19,0x00,0x58
	load id=0x0059	;@raw=0x19,0x00,0x59
	load id=0x005A	;@raw=0x19,0x00,0x5A
	load id=0x005B	;@raw=0x19,0x00,0x5B
	load id=0x005C	;@raw=0x19,0x00,0x5C
	load id=0x005D	;@raw=0x19,0x00,0x5D
	load id=0x0060	;@raw=0x19,0x00,0x60
	ret
	mov [0x01], 0x03E8

LABEL_01EE:
	video type=1, offset=CINEMATIC_893, x=160, y=100	;@raw=0x81,0x00,0xA0,0x64
	djnz [0x01], LABEL_01EE	;@raw=0x09,0x01,0x01,0xEE
	break
	setPalette 0x0C	;@raw=0x0B,0x0C,0xFF
