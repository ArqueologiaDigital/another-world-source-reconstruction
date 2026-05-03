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
;   DRAW_CIN_393_AT_VAR07_08  (2-arm: amiga, dos)
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
;   FOLD_BODY_144B_5C7E9C90  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   FOLD_BODY_104B_F18A2F7D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_9BEF2C97  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   FOLD_BODY_37B_9FD2CEA6  (2-arm: cart, dos)
;   DRAW_CIN_486  (2-arm: amiga, dos)
;   DRAW_CIN_483  (2-arm: amiga, dos)
;   FOLD_BODY_156B_9635F3D1  (2-arm: amiga, dos)
;   DRAW_CIN_502  (2-arm: amiga, dos)
;   DRAW_CIN_499  (2-arm: amiga, dos)
;   FOLD_BODY_156B_C0A1A8CA  (2-arm: amiga, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_B2820056  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_96B_2FC90B25  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_CIN_236  (2-arm: amiga, dos)
;   DRAW_CIN_237  (2-arm: amiga, dos)
;   DRAW_CIN_238  (2-arm: amiga, dos)
;   DRAW_CIN_239  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_CIN_231  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_CIN_228  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
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
;   DRAW_CIN_164  (2-arm: amiga, dos)
;   DRAW_CIN_165  (2-arm: amiga, dos)
;   DRAW_CIN_166  (2-arm: amiga, dos)
;   DRAW_CIN_167  (2-arm: amiga, dos)
;   DRAW_CIN_163  (2-arm: amiga, dos)
;   DRAW_CIN_162  (2-arm: amiga, dos)
;   DRAW_CIN_161  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_CIN_158  (2-arm: amiga, dos)
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
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_12AD66EF  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_FF681770  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   DRAW_CV_106  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_04347EF0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_7EA5CCF5  (2-arm: amiga, dos)
;   DRAW_CIN_076  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B0A5B60F  (2-arm: amiga, dos)
;   DRAW_CIN_073  (2-arm: amiga, dos)
;   FOLD_BODY_96B_787FEDD5  (2-arm: amiga, dos)
;   DRAW_CIN_070  (2-arm: amiga, dos)
;   FOLD_BODY_96B_C7EF291A  (2-arm: amiga, dos)
;   DRAW_CIN_067  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8FDF7DB5  (2-arm: amiga, dos)
;   DRAW_CIN_064  (2-arm: amiga, dos)
;   FOLD_BODY_96B_BEDD0A4B  (2-arm: amiga, dos)
;   DRAW_CIN_061  (2-arm: amiga, dos)
;   FOLD_BODY_96B_D2F4C2E9  (2-arm: amiga, dos)
;   DRAW_CIN_058  (2-arm: amiga, dos)
;   FOLD_BODY_96B_1558398F  (2-arm: amiga, dos)
;   FOLD_BODY_96B_3E51165F  (2-arm: amiga, dos)
;   DRAW_CIN_052  (2-arm: amiga, dos)
;   FOLD_BODY_96B_FC4E0356  (2-arm: amiga, dos)
;   DRAW_CIN_049  (2-arm: amiga, dos)
;   FOLD_BODY_96B_08D73B81  (2-arm: amiga, dos)
;   DRAW_CIN_046  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B594DD37  (2-arm: amiga, dos)
;   DRAW_CIN_043  (2-arm: amiga, dos)
;   FOLD_BODY_96B_28B75A30  (2-arm: amiga, dos)
;   DRAW_CIN_040  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8BB50141  (2-arm: amiga, dos)
;   DRAW_CIN_037  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   FOLD_BODY_153B_C643A158  (3-arm: amiga, cart, dos)
;   FOLD_BODY_56B_4EE7BD2B  (2-arm: cart, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
;   FOLD_BODY_127B_F42DCE4F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_5CFB4923  (3-arm: amiga, cart, dos)
;   FOLD_BODY_76B_D2CE1407  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_52FF562C  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_A9F04A42  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_467B_FEBF74B5  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_358B_DF9AE0DF  (2-arm: cart, dos)
;   FOLD_BODY_203B_06F694A2  (3-arm: amiga, cart, dos)
;   FOLD_BODY_203B_4BED9F88  (3-arm: amiga, cart, dos)
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
;   DRAW_CIN_393_AT_VAR07_08  (2-arm: amiga, dos)
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
;   FOLD_BODY_144B_5C7E9C90  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   FOLD_BODY_104B_F18A2F7D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_9BEF2C97  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   FOLD_BODY_37B_9FD2CEA6  (2-arm: cart, dos)
;   DRAW_CIN_486  (2-arm: amiga, dos)
;   DRAW_CIN_483  (2-arm: amiga, dos)
;   FOLD_BODY_156B_9635F3D1  (2-arm: amiga, dos)
;   DRAW_CIN_502  (2-arm: amiga, dos)
;   DRAW_CIN_499  (2-arm: amiga, dos)
;   FOLD_BODY_156B_C0A1A8CA  (2-arm: amiga, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_B2820056  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_96B_2FC90B25  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_CIN_236  (2-arm: amiga, dos)
;   DRAW_CIN_237  (2-arm: amiga, dos)
;   DRAW_CIN_238  (2-arm: amiga, dos)
;   DRAW_CIN_239  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_CIN_231  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_CIN_228  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
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
;   DRAW_CIN_164  (2-arm: amiga, dos)
;   DRAW_CIN_165  (2-arm: amiga, dos)
;   DRAW_CIN_166  (2-arm: amiga, dos)
;   DRAW_CIN_167  (2-arm: amiga, dos)
;   DRAW_CIN_163  (2-arm: amiga, dos)
;   DRAW_CIN_162  (2-arm: amiga, dos)
;   DRAW_CIN_161  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_CIN_158  (2-arm: amiga, dos)
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
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_12AD66EF  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_FF681770  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   DRAW_CV_106  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_04347EF0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_7EA5CCF5  (2-arm: amiga, dos)
;   DRAW_CIN_076  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B0A5B60F  (2-arm: amiga, dos)
;   DRAW_CIN_073  (2-arm: amiga, dos)
;   FOLD_BODY_96B_787FEDD5  (2-arm: amiga, dos)
;   DRAW_CIN_070  (2-arm: amiga, dos)
;   FOLD_BODY_96B_C7EF291A  (2-arm: amiga, dos)
;   DRAW_CIN_067  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8FDF7DB5  (2-arm: amiga, dos)
;   DRAW_CIN_064  (2-arm: amiga, dos)
;   FOLD_BODY_96B_BEDD0A4B  (2-arm: amiga, dos)
;   DRAW_CIN_061  (2-arm: amiga, dos)
;   FOLD_BODY_96B_D2F4C2E9  (2-arm: amiga, dos)
;   DRAW_CIN_058  (2-arm: amiga, dos)
;   FOLD_BODY_96B_1558398F  (2-arm: amiga, dos)
;   FOLD_BODY_96B_3E51165F  (2-arm: amiga, dos)
;   DRAW_CIN_052  (2-arm: amiga, dos)
;   FOLD_BODY_96B_FC4E0356  (2-arm: amiga, dos)
;   DRAW_CIN_049  (2-arm: amiga, dos)
;   FOLD_BODY_96B_08D73B81  (2-arm: amiga, dos)
;   DRAW_CIN_046  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B594DD37  (2-arm: amiga, dos)
;   DRAW_CIN_043  (2-arm: amiga, dos)
;   FOLD_BODY_96B_28B75A30  (2-arm: amiga, dos)
;   DRAW_CIN_040  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8BB50141  (2-arm: amiga, dos)
;   DRAW_CIN_037  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   FOLD_BODY_153B_C643A158  (3-arm: amiga, cart, dos)
;   FOLD_BODY_56B_4EE7BD2B  (2-arm: cart, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
;   FOLD_BODY_127B_F42DCE4F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_5CFB4923  (3-arm: amiga, cart, dos)
;   FOLD_BODY_76B_D2CE1407  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_52FF562C  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_A9F04A42  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_467B_FEBF74B5  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_358B_DF9AE0DF  (2-arm: cart, dos)
;   FOLD_BODY_203B_06F694A2  (3-arm: amiga, cart, dos)
;   FOLD_BODY_203B_4BED9F88  (3-arm: amiga, cart, dos)
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
;   DRAW_CIN_393_AT_VAR07_08  (2-arm: amiga, dos)
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
;   FOLD_BODY_144B_5C7E9C90  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   SET_VARS_29_2F  (2-arm: amiga, dos)
;   FOLD_BODY_104B_F18A2F7D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_9BEF2C97  (2-arm: amiga, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   DRAW_CIN_486  (2-arm: amiga, dos)
;   DRAW_CIN_483  (2-arm: amiga, dos)
;   FOLD_BODY_156B_9635F3D1  (2-arm: amiga, dos)
;   DRAW_CIN_502  (2-arm: amiga, dos)
;   DRAW_CIN_499  (2-arm: amiga, dos)
;   FOLD_BODY_156B_C0A1A8CA  (2-arm: amiga, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_B2820056  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   DRAW_CIN_305_TO_309_5F_AT_AACB4DF5  (2-arm: amiga, dos)
;   DRAW_CIN_305_TO_333_7F_AT_96C7E6A8  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   DRAW_CIN_624_TO_628_5F_AT_499AFE0A  (2-arm: amiga, dos)
;   DRAW_CIN_628_TO_625_4F_AT_2F47D6D0  (2-arm: amiga, dos)
;   DRAW_CIN_229_TO_632_2F_AT_1C4A817A  (2-arm: amiga, dos)
;   DRAW_CIN_683_TO_685_3F_AT_1EB7324B  (2-arm: amiga, dos)
;   FOLD_BODY_96B_2FC90B25  (2-arm: amiga, dos)
;   INLINE_DRAW_CIN_659_AT_160_100  (2-arm: amiga, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_CIN_236  (2-arm: amiga, dos)
;   DRAW_CIN_237  (2-arm: amiga, dos)
;   DRAW_CIN_238  (2-arm: amiga, dos)
;   DRAW_CIN_239  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_CIN_231  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_CIN_228  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
;   FOLD_BODY_99B_C6015BD9  (2-arm: cart, dos)
;   FOLD_BODY_189B_794E4590  (2-arm: cart, dos)
;   FOLD_BODY_99B_D8CF1AF9  (2-arm: cart, dos)
;   FOLD_BODY_99B_535C94C0  (2-arm: cart, dos)
;   FOLD_BODY_99B_76C60EB2  (2-arm: cart, dos)
;   FOLD_BODY_99B_95D61F48  (2-arm: cart, dos)
;   FOLD_BODY_99B_3F1B076D  (2-arm: cart, dos)
;   DRAW_CIN_164  (2-arm: amiga, dos)
;   DRAW_CIN_165  (2-arm: amiga, dos)
;   DRAW_CIN_166  (2-arm: amiga, dos)
;   DRAW_CIN_167  (2-arm: amiga, dos)
;   DRAW_CIN_163  (2-arm: amiga, dos)
;   DRAW_CIN_162  (2-arm: amiga, dos)
;   DRAW_CIN_161  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_CIN_158  (2-arm: amiga, dos)
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
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_12AD66EF  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_FF681770  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   DRAW_CV_106  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   FOLD_BODY_96B_7EA5CCF5  (2-arm: amiga, dos)
;   DRAW_CIN_076  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B0A5B60F  (2-arm: amiga, dos)
;   DRAW_CIN_073  (2-arm: amiga, dos)
;   FOLD_BODY_96B_787FEDD5  (2-arm: amiga, dos)
;   DRAW_CIN_070  (2-arm: amiga, dos)
;   FOLD_BODY_96B_C7EF291A  (2-arm: amiga, dos)
;   DRAW_CIN_067  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8FDF7DB5  (2-arm: amiga, dos)
;   DRAW_CIN_064  (2-arm: amiga, dos)
;   FOLD_BODY_96B_BEDD0A4B  (2-arm: amiga, dos)
;   DRAW_CIN_061  (2-arm: amiga, dos)
;   FOLD_BODY_96B_D2F4C2E9  (2-arm: amiga, dos)
;   DRAW_CIN_058  (2-arm: amiga, dos)
;   FOLD_BODY_96B_1558398F  (2-arm: amiga, dos)
;   FOLD_BODY_96B_3E51165F  (2-arm: amiga, dos)
;   DRAW_CIN_052  (2-arm: amiga, dos)
;   FOLD_BODY_96B_FC4E0356  (2-arm: amiga, dos)
;   DRAW_CIN_049  (2-arm: amiga, dos)
;   FOLD_BODY_96B_08D73B81  (2-arm: amiga, dos)
;   DRAW_CIN_046  (2-arm: amiga, dos)
;   FOLD_BODY_96B_B594DD37  (2-arm: amiga, dos)
;   DRAW_CIN_043  (2-arm: amiga, dos)
;   FOLD_BODY_96B_28B75A30  (2-arm: amiga, dos)
;   DRAW_CIN_040  (2-arm: amiga, dos)
;   FOLD_BODY_96B_8BB50141  (2-arm: amiga, dos)
;   DRAW_CIN_037  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   DRAW_CIN_090_TO_104_3F_AT_8C208B32  (2-arm: amiga, dos)
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
;   FOLD_BODY_127B_F42DCE4F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_5CFB4923  (3-arm: amiga, cart, dos)
;   FOLD_BODY_76B_D2CE1407  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_52FF562C  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_A9F04A42  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_467B_FEBF74B5  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_358B_DF9AE0DF  (2-arm: cart, dos)
;   FOLD_BODY_203B_06F694A2  (3-arm: amiga, cart, dos)
;   FOLD_BODY_203B_4BED9F88  (3-arm: amiga, cart, dos)
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
;   FOLD_BODY_144B_5C7E9C90  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_F18A2F7D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   FOLD_BODY_37B_9FD2CEA6  (2-arm: cart, dos)
;   DRAW_CIN_486  (2-arm: amiga, dos)
;   DRAW_CIN_483  (2-arm: amiga, dos)
;   DRAW_CIN_502  (2-arm: amiga, dos)
;   DRAW_CIN_499  (2-arm: amiga, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_B2820056  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_CIN_236  (2-arm: amiga, dos)
;   DRAW_CIN_237  (2-arm: amiga, dos)
;   DRAW_CIN_238  (2-arm: amiga, dos)
;   DRAW_CIN_239  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_CIN_231  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_CIN_228  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
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
;   DRAW_CIN_164  (2-arm: amiga, dos)
;   DRAW_CIN_165  (2-arm: amiga, dos)
;   DRAW_CIN_166  (2-arm: amiga, dos)
;   DRAW_CIN_167  (2-arm: amiga, dos)
;   DRAW_CIN_163  (2-arm: amiga, dos)
;   DRAW_CIN_162  (2-arm: amiga, dos)
;   DRAW_CIN_161  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_CIN_158  (2-arm: amiga, dos)
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
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_12AD66EF  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_FF681770  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   DRAW_CV_106  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_04347EF0  (3-arm: amiga, cart, dos)
;   DRAW_CIN_076  (2-arm: amiga, dos)
;   DRAW_CIN_073  (2-arm: amiga, dos)
;   DRAW_CIN_070  (2-arm: amiga, dos)
;   DRAW_CIN_067  (2-arm: amiga, dos)
;   DRAW_CIN_064  (2-arm: amiga, dos)
;   DRAW_CIN_061  (2-arm: amiga, dos)
;   DRAW_CIN_058  (2-arm: amiga, dos)
;   DRAW_CIN_052  (2-arm: amiga, dos)
;   DRAW_CIN_049  (2-arm: amiga, dos)
;   DRAW_CIN_046  (2-arm: amiga, dos)
;   DRAW_CIN_043  (2-arm: amiga, dos)
;   DRAW_CIN_040  (2-arm: amiga, dos)
;   DRAW_CIN_037  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   FOLD_BODY_153B_C643A158  (3-arm: amiga, cart, dos)
;   FOLD_BODY_56B_4EE7BD2B  (2-arm: cart, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
;   FOLD_BODY_127B_F42DCE4F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_5CFB4923  (3-arm: amiga, cart, dos)
;   FOLD_BODY_76B_D2CE1407  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_52FF562C  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_A9F04A42  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_467B_FEBF74B5  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_358B_DF9AE0DF  (2-arm: cart, dos)
;   FOLD_BODY_203B_06F694A2  (3-arm: amiga, cart, dos)
;   FOLD_BODY_203B_4BED9F88  (3-arm: amiga, cart, dos)

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
;   FOLD_BODY_144B_5C7E9C90  (3-arm: amiga, cart, dos)
;   INIT_VARS_29_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_07_2F  (3-arm: amiga, cart, dos)
;   INIT_VARS_2F_29_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_F18A2F7D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_94B_44BEEF04  (3-arm: amiga, cart, dos)
;   INCREMENT_VAR21_BY_F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR22_BY_23  (3-arm: amiga, cart, dos)
;   INLINE_OR_VAR2B_WITH_4000  (3-arm: amiga, cart, dos)
;   COPY_VAR22_TO_VAR07  (3-arm: amiga, cart, dos)
;   FOLD_BODY_39B_42136843  (3-arm: amiga, cart, dos)
;   COPY_VAR27_TO_VAR07  (3-arm: amiga, cart, dos)
;   SET_VAR13_TO_FFFF  (3-arm: amiga, cart, dos)
;   PLAY_SFX_005C_CH01  (3-arm: amiga, cart, dos)
;   FOLD_BODY_37B_9FD2CEA6  (2-arm: cart, dos)
;   DRAW_CIN_486  (2-arm: amiga, dos)
;   DRAW_CIN_483  (2-arm: amiga, dos)
;   DRAW_CIN_502  (2-arm: amiga, dos)
;   DRAW_CIN_499  (2-arm: amiga, dos)
;   FOLD_BODY_89B_E0F8C267  (3-arm: amiga, cart, dos)
;   INLINE_ADD_VAR2C_BY_1  (3-arm: amiga, cart, dos)
;   COPY_VAR40_TO_VAR27  (3-arm: amiga, cart, dos)
;   COPY_VARAD_TO_VAR11  (3-arm: amiga, cart, dos)
;   COPY_VAR11_TO_VARAD  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR22  (3-arm: amiga, cart, dos)
;   FOLD_BODY_79B_5AA87B0D  (3-arm: amiga, cart, dos)
;   FOLD_BODY_84B_B2820056  (3-arm: amiga, cart, dos)
;   COPY_VAR01_TO_VAR28  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_22B91458  (2-arm: cart, dos)
;   DRAW_CIN_SEQ_085_085_086  (2-arm: amiga, dos)
;   FILL_AND_DRAW_CIN_24_28  (2-arm: amiga, dos)
;   INIT_VARS_16_17  (3-arm: amiga, cart, dos)
;   FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA  (3-arm: amiga, cart, dos)
;   SET_PAL_07_FILL_TWO_PAGES_86243111  (3-arm: amiga, cart, dos)
;   DRAW_CIN_236  (2-arm: amiga, dos)
;   DRAW_CIN_237  (2-arm: amiga, dos)
;   DRAW_CIN_238  (2-arm: amiga, dos)
;   DRAW_CIN_239  (2-arm: amiga, dos)
;   DRAW_CIN_235  (2-arm: amiga, dos)
;   DRAW_CIN_234  (2-arm: amiga, dos)
;   DRAW_CIN_233  (2-arm: amiga, dos)
;   DRAW_CIN_232  (2-arm: amiga, dos)
;   DRAW_CIN_231  (2-arm: amiga, dos)
;   DRAW_CIN_230  (2-arm: amiga, dos)
;   DRAW_CIN_229  (2-arm: amiga, dos)
;   DRAW_CIN_228  (2-arm: amiga, dos)
;   DRAW_CIN_225  (2-arm: amiga, dos)
;   DRAW_CIN_226  (2-arm: amiga, dos)
;   DRAW_CIN_352  (2-arm: amiga, dos)
;   DRAW_CIN_240  (2-arm: amiga, dos)
;   DRAW_CIN_241  (2-arm: amiga, dos)
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
;   DRAW_CIN_164  (2-arm: amiga, dos)
;   DRAW_CIN_165  (2-arm: amiga, dos)
;   DRAW_CIN_166  (2-arm: amiga, dos)
;   DRAW_CIN_167  (2-arm: amiga, dos)
;   DRAW_CIN_163  (2-arm: amiga, dos)
;   DRAW_CIN_162  (2-arm: amiga, dos)
;   DRAW_CIN_161  (2-arm: amiga, dos)
;   DRAW_CIN_160  (2-arm: amiga, dos)
;   DRAW_CIN_159  (2-arm: amiga, dos)
;   DRAW_CIN_158  (2-arm: amiga, dos)
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
;   FOLD_BODY_99B_8CB26FD2  (2-arm: cart, dos)
;   FOLD_BODY_200B_12AD66EF  (2-arm: cart, dos)
;   FOLD_BODY_99B_B1A35EFA  (2-arm: cart, dos)
;   DRAW_CV_110  (2-arm: cart, dos)
;   FOLD_BODY_99B_79867FEB  (2-arm: cart, dos)
;   DRAW_CV_112  (2-arm: cart, dos)
;   FOLD_BODY_99B_AA083516  (2-arm: cart, dos)
;   DRAW_CV_114  (2-arm: cart, dos)
;   DRAW_CV_115  (2-arm: cart, dos)
;   FOLD_BODY_99B_903D2AE1  (2-arm: cart, dos)
;   FOLD_BODY_200B_FF681770  (2-arm: cart, dos)
;   FOLD_BODY_99B_A1B2ECF4  (2-arm: cart, dos)
;   DRAW_CV_100  (2-arm: cart, dos)
;   FOLD_BODY_99B_6E4C0150  (2-arm: cart, dos)
;   DRAW_CV_102  (2-arm: cart, dos)
;   FOLD_BODY_99B_DC229063  (2-arm: cart, dos)
;   DRAW_CV_104  (2-arm: cart, dos)
;   FOLD_BODY_99B_C53D6EC4  (2-arm: cart, dos)
;   DRAW_CV_106  (2-arm: cart, dos)
;   INLINE_SET_VAR20_TO_1  (3-arm: amiga, cart, dos)
;   INIT_VARS_02_06  (3-arm: amiga, cart, dos)
;   ACCUMULATE_VAR_03_04_BY_01_02  (3-arm: amiga, cart, dos)
;   FOLD_BODY_104B_04347EF0  (3-arm: amiga, cart, dos)
;   DRAW_CIN_076  (2-arm: amiga, dos)
;   DRAW_CIN_073  (2-arm: amiga, dos)
;   DRAW_CIN_070  (2-arm: amiga, dos)
;   DRAW_CIN_067  (2-arm: amiga, dos)
;   DRAW_CIN_064  (2-arm: amiga, dos)
;   DRAW_CIN_061  (2-arm: amiga, dos)
;   DRAW_CIN_058  (2-arm: amiga, dos)
;   DRAW_CIN_052  (2-arm: amiga, dos)
;   DRAW_CIN_049  (2-arm: amiga, dos)
;   DRAW_CIN_046  (2-arm: amiga, dos)
;   DRAW_CIN_043  (2-arm: amiga, dos)
;   DRAW_CIN_040  (2-arm: amiga, dos)
;   DRAW_CIN_037  (2-arm: amiga, dos)
;   DRAW_CIN_540_543_WITH_SFX_57  (2-arm: amiga, dos)
;   INIT_VARS_15_19_18_14_PLUS4  (3-arm: amiga, cart, dos)
;   DRAW_CIN_092  (2-arm: amiga, dos)
;   FOLD_BODY_153B_C643A158  (3-arm: amiga, cart, dos)
;   FOLD_BODY_56B_4EE7BD2B  (2-arm: cart, dos)
;   INLINE_SET_VAR16_TO_0  (3-arm: amiga, cart, dos)
;   FOLD_BODY_93B_2C2B4311  (2-arm: cart, dos)
;   FOLD_BODY_62B_70C62EFD  (3-arm: amiga, cart, dos)
;   FOLD_BODY_62B_8F5AB86B  (3-arm: amiga, cart, dos)
;   DRAW_CIN_552  (2-arm: amiga, dos)
;   DRAW_CIN_550  (2-arm: amiga, dos)
;   FOLD_BODY_127B_F42DCE4F  (3-arm: amiga, cart, dos)
;   INLINE_SUB_VAR50_BY_14  (3-arm: amiga, cart, dos)
;   FOLD_BODY_89B_5CFB4923  (3-arm: amiga, cart, dos)
;   FOLD_BODY_76B_D2CE1407  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_52FF562C  (3-arm: amiga, cart, dos)
;   INIT_RANGE_48_TO_4D_TO_MAX  (3-arm: amiga, cart, dos)
;   INIT_VARS_A1_A4_A7_AA_PLUS4  (3-arm: amiga, cart, dos)
;   FOLD_BODY_53B_A9F04A42  (3-arm: amiga, cart, dos)
;   FOLD_BODY_61B_7F8B309C  (3-arm: amiga, cart, dos)
;   DECREMENT_VAR10_BY_1  (3-arm: amiga, cart, dos)
;   FOLD_BODY_467B_FEBF74B5  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0020  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0030  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0000  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0010  (3-arm: amiga, cart, dos)
;   SET_VAR04_TO_0008  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_1  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_2  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_5  (3-arm: amiga, cart, dos)
;   INLINE_SET_VAR63_TO_6  (3-arm: amiga, cart, dos)
;   FOLD_BODY_358B_6F629262  (2-arm: cart, dos)
;   FOLD_BODY_358B_DF9AE0DF  (2-arm: cart, dos)
;   FOLD_BODY_203B_06F694A2  (3-arm: amiga, cart, dos)
;   FOLD_BODY_203B_4BED9F88  (3-arm: amiga, cart, dos)

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
RANDOM_SEED		EQU 0x3C
HACK_VAR_54		EQU 0x54
HACK_VAR_67		EQU 0x67
LAST_KEYCHAR		EQU 0xDA
HACK_VAR_DC		EQU 0xDC
HERO_POS_UP_DOWN		EQU 0xE5
MUS_MARK		EQU 0xF4
HACK_VAR_F7		EQU 0xF7
SCROLL_Y		EQU 0xF9
HERO_ACTION		EQU 0xFA
HERO_POS_JUMP_DOWN		EQU 0xFB
HERO_POS_LEFT_RIGHT		EQU 0xFC
HERO_POS_MASK		EQU 0xFD
HERO_ACTION_POS_MASK		EQU 0xFE
PAUSE_SLICES		EQU 0xFF
CINEMATIC_000		EQU 0x99DA
CINEMATIC_001		EQU 0x99C4
CINEMATIC_002		EQU 0x99AE
CINEMATIC_003		EQU 0x9998
CINEMATIC_004		EQU 0x9896
CINEMATIC_005		EQU 0x96AA
CINEMATIC_006		EQU 0x96FA
CINEMATIC_007		EQU 0x970A
CINEMATIC_008		EQU 0x9722
CINEMATIC_009		EQU 0x973A
CINEMATIC_010		EQU 0x9752
CINEMATIC_011		EQU 0x976A
CINEMATIC_012		EQU 0x9782
CINEMATIC_013		EQU 0x979A
CINEMATIC_014		EQU 0x98A2
CINEMATIC_015		EQU 0x94CA
CINEMATIC_016		EQU 0x950E
CINEMATIC_017		EQU 0x952A
CINEMATIC_018		EQU 0x955A
CINEMATIC_019		EQU 0x9596
CINEMATIC_020		EQU 0x95C6
CINEMATIC_021		EQU 0x9602
CINEMATIC_022		EQU 0x963E
CINEMATIC_023		EQU 0x967A
CINEMATIC_024		EQU 0x9012
CINEMATIC_025		EQU 0x9380
CINEMATIC_026		EQU 0x9364
CINEMATIC_027		EQU 0x9076
CINEMATIC_028		EQU 0x9136
CINEMATIC_029		EQU 0x9248
CINEMATIC_030		EQU 0x4AAE
CINEMATIC_031		EQU 0x57D8
CINEMATIC_032		EQU 0x4CA0
CINEMATIC_033		EQU 0x9414
CINEMATIC_034		EQU 0x88EE
CINEMATIC_035		EQU 0x23B4
CINEMATIC_036		EQU 0x210E
CINEMATIC_037		EQU 0x165E
CINEMATIC_038		EQU 0x1D2E
CINEMATIC_039		EQU 0x20E8
CINEMATIC_040		EQU 0x15D2
CINEMATIC_041		EQU 0x1D08
CINEMATIC_042		EQU 0x208E
CINEMATIC_043		EQU 0x1546
CINEMATIC_044		EQU 0x1CC6
CINEMATIC_045		EQU 0x2068
CINEMATIC_046		EQU 0x14BA
CINEMATIC_047		EQU 0x1CA0
CINEMATIC_048		EQU 0x2002
CINEMATIC_049		EQU 0x1442
CINEMATIC_050		EQU 0x1C7A
CINEMATIC_051		EQU 0x1FDC
CINEMATIC_052		EQU 0x13B6
CINEMATIC_053		EQU 0x1C54
CINEMATIC_054		EQU 0x1F42
CINEMATIC_055		EQU 0x132A
CINEMATIC_056		EQU 0x1C2E
CINEMATIC_057		EQU 0x1F1C
CINEMATIC_058		EQU 0x129E
CINEMATIC_059		EQU 0x1C08
CINEMATIC_060		EQU 0x1EF6
CINEMATIC_061		EQU 0x1212
CINEMATIC_062		EQU 0x1BE2
CINEMATIC_063		EQU 0x1E90
CINEMATIC_064		EQU 0x1186
CINEMATIC_065		EQU 0x1B9C
CINEMATIC_066		EQU 0x1E6A
CINEMATIC_067		EQU 0x10FA
CINEMATIC_068		EQU 0x1B76
CINEMATIC_069		EQU 0x1E04
CINEMATIC_070		EQU 0x106E
CINEMATIC_071		EQU 0x1B50
CINEMATIC_072		EQU 0x1DDE
CINEMATIC_073		EQU 0x0FE2
CINEMATIC_074		EQU 0x1B2A
CINEMATIC_075		EQU 0x1D54
CINEMATIC_076		EQU 0x0F56
CINEMATIC_077		EQU 0x1B04
CINEMATIC_078		EQU 0x1ADE
CINEMATIC_079		EQU 0x0EDA
CINEMATIC_080		EQU 0x264C
CINEMATIC_081		EQU 0x26C0
CINEMATIC_082		EQU 0x5730
CINEMATIC_083		EQU 0x2760
CINEMATIC_084		EQU 0x27D8
CINEMATIC_085		EQU 0xA1AC
CINEMATIC_086		EQU 0xA1F0
CINEMATIC_087		EQU 0xA8BC
CINEMATIC_088		EQU 0xA9C4
CINEMATIC_089		EQU 0xAAEC
CINEMATIC_090		EQU 0xC968
CINEMATIC_091		EQU 0xCFFC
CINEMATIC_092		EQU 0x8E56
CINEMATIC_093		EQU 0x6E5A
CINEMATIC_094		EQU 0x6E2E
CINEMATIC_095		EQU 0x6E02
CINEMATIC_096		EQU 0x6DD6
CINEMATIC_097		EQU 0x6CE2
CINEMATIC_098		EQU 0x6D26
CINEMATIC_099		EQU 0x6D52
CINEMATIC_100		EQU 0x6D7E
CINEMATIC_101		EQU 0x6DAA
CINEMATIC_102		EQU 0x8E5E
CINEMATIC_103		EQU 0x8E7E
CINEMATIC_104		EQU 0xD044
CINEMATIC_105		EQU 0x841E
CINEMATIC_106		EQU 0x6CC2
CINEMATIC_107		EQU 0x84BA
CINEMATIC_108		EQU 0x84CE
CINEMATIC_109		EQU 0x84E2
CINEMATIC_110		EQU 0x84F6
CINEMATIC_111		EQU 0x850A
CINEMATIC_112		EQU 0x851E
CINEMATIC_113		EQU 0x8442
CINEMATIC_114		EQU 0x8456
CINEMATIC_115		EQU 0x846A
CINEMATIC_116		EQU 0x847E
CINEMATIC_117		EQU 0x8492
CINEMATIC_118		EQU 0x84A6
CINEMATIC_119		EQU 0x864A
CINEMATIC_120		EQU 0x8678
CINEMATIC_121		EQU 0x8680
CINEMATIC_122		EQU 0x868E
CINEMATIC_123		EQU 0x869A
CINEMATIC_124		EQU 0x86A2
CINEMATIC_125		EQU 0x86AA
CINEMATIC_126		EQU 0x86B2
CINEMATIC_127		EQU 0xD092
CINEMATIC_128		EQU 0x8DBA
CINEMATIC_129		EQU 0x8D0A
CINEMATIC_130		EQU 0xD07E
CINEMATIC_131		EQU 0x9AF0
CINEMATIC_132		EQU 0x860A
CINEMATIC_133		EQU 0x8622
CINEMATIC_134		EQU 0xAC9C
CINEMATIC_135		EQU 0xAD0C
CINEMATIC_136		EQU 0xAD9E
CINEMATIC_137		EQU 0x7964
CINEMATIC_138		EQU 0x7898
CINEMATIC_139		EQU 0x7978
CINEMATIC_140		EQU 0x7A04
CINEMATIC_141		EQU 0x7A7C
CINEMATIC_142		EQU 0x7AA4
CINEMATIC_143		EQU 0x7AE0
CINEMATIC_144		EQU 0x7B34
CINEMATIC_145		EQU 0x7B74
CINEMATIC_146		EQU 0x57F8
CINEMATIC_147		EQU 0x5874
CINEMATIC_148		EQU 0x5964
CINEMATIC_149		EQU 0x85DA
CINEMATIC_150		EQU 0x85F2
CINEMATIC_151		EQU 0x8592
CINEMATIC_152		EQU 0x85AA
CINEMATIC_153		EQU 0x85C2
CINEMATIC_154		EQU 0x854A
CINEMATIC_155		EQU 0x8562
CINEMATIC_156		EQU 0x857A
CINEMATIC_157		EQU 0xBEEC
CINEMATIC_158		EQU 0x8A76
CINEMATIC_159		EQU 0xBEBE
CINEMATIC_160		EQU 0x4270
CINEMATIC_161		EQU 0x4230
CINEMATIC_162		EQU 0x4218
CINEMATIC_163		EQU 0x41DC
CINEMATIC_164		EQU 0x17FA
CINEMATIC_165		EQU 0xB710
CINEMATIC_166		EQU 0xB738
CINEMATIC_167		EQU 0xB760
CINEMATIC_168		EQU 0xC408
CINEMATIC_169		EQU 0xC440
CINEMATIC_170		EQU 0x4062
CINEMATIC_171		EQU 0x89FE
CINEMATIC_172		EQU 0x8E4A
CINEMATIC_173		EQU 0xBD9C
CINEMATIC_174		EQU 0xBD78
CINEMATIC_175		EQU 0xBCDC
CINEMATIC_176		EQU 0xBE90
CINEMATIC_177		EQU 0xBE7C
CINEMATIC_178		EQU 0xB7E4
CINEMATIC_179		EQU 0xB8E0
CINEMATIC_180		EQU 0xB94C
CINEMATIC_181		EQU 0xB9A0
CINEMATIC_182		EQU 0xBA1C
CINEMATIC_183		EQU 0xBB00
CINEMATIC_184		EQU 0xBBDA
CINEMATIC_185		EQU 0xBC70
CINEMATIC_186		EQU 0x0068
CINEMATIC_187		EQU 0x0B6E
CINEMATIC_188		EQU 0x402E
CINEMATIC_189		EQU 0x3FFA
CINEMATIC_190		EQU 0x5D9C
CINEMATIC_191		EQU 0x5DC8
CINEMATIC_192		EQU 0x5DF8
CINEMATIC_193		EQU 0x5E2C
CINEMATIC_194		EQU 0x5E60
CINEMATIC_195		EQU 0x5E6C
CINEMATIC_196		EQU 0x4DEC
CINEMATIC_197		EQU 0x4E00
CINEMATIC_198		EQU 0x4E14
CINEMATIC_199		EQU 0x4E8E
CINEMATIC_200		EQU 0x4E80
CINEMATIC_201		EQU 0x4E48
CINEMATIC_202		EQU 0x5D34
CINEMATIC_203		EQU 0x5D60
CINEMATIC_204		EQU 0x5D90
CINEMATIC_205		EQU 0x0B92
CINEMATIC_206		EQU 0x3C82
CINEMATIC_207		EQU 0x89A6
CINEMATIC_208		EQU 0x3DBC
CINEMATIC_209		EQU 0x3DF0
CINEMATIC_210		EQU 0x4E2C
CINEMATIC_211		EQU 0x0938
CINEMATIC_212		EQU 0x08D4
CINEMATIC_213		EQU 0x0988
CINEMATIC_214		EQU 0x0CD2
CINEMATIC_215		EQU 0x0870
CINEMATIC_216		EQU 0x8B4A
CINEMATIC_217		EQU 0x8AF2
CINEMATIC_218		EQU 0x8AAE
CINEMATIC_219		EQU 0x8CFA
CINEMATIC_220		EQU 0x3BB4
CINEMATIC_221		EQU 0x3BBE
CINEMATIC_222		EQU 0x0DBA
CINEMATIC_223		EQU 0x0D96
CINEMATIC_224		EQU 0x0B4A
CINEMATIC_225		EQU 0xBF36
CINEMATIC_226		EQU 0xBF8C
CINEMATIC_227		EQU 0x53E0
CINEMATIC_228		EQU 0x531E
CINEMATIC_229		EQU 0xD114
CINEMATIC_230		EQU 0x4338
CINEMATIC_231		EQU 0x4304
CINEMATIC_232		EQU 0xD0E8
CINEMATIC_233		EQU 0x42EC
CINEMATIC_234		EQU 0xD0AC
CINEMATIC_235		EQU 0x42B0
CINEMATIC_236		EQU 0x2E6A
CINEMATIC_237		EQU 0xBF64
CINEMATIC_238		EQU 0xC5D2
CINEMATIC_239		EQU 0xC5EC
CINEMATIC_240		EQU 0xC4FA
CINEMATIC_241		EQU 0xC4DE
CINEMATIC_242		EQU 0x41B0
CINEMATIC_243		EQU 0x89C6
CINEMATIC_244		EQU 0xC994
CINEMATIC_245		EQU 0xCB44
CINEMATIC_246		EQU 0xCE34
CINEMATIC_247		EQU 0xCC0C
CINEMATIC_248		EQU 0xCF44
CINEMATIC_249		EQU 0xCBE4
CINEMATIC_250		EQU 0xCF10
CINEMATIC_251		EQU 0xCBBC
CINEMATIC_252		EQU 0xCEDC
CINEMATIC_253		EQU 0xCB94
CINEMATIC_254		EQU 0xCFAC
CINEMATIC_255		EQU 0xCB6C
CINEMATIC_256		EQU 0xCF78
CINEMATIC_257		EQU 0xCB1C
CINEMATIC_258		EQU 0xCE00
CINEMATIC_259		EQU 0xCAA4
CINEMATIC_260		EQU 0xCD64
CINEMATIC_261		EQU 0xCACC
CINEMATIC_262		EQU 0xCD98
CINEMATIC_263		EQU 0xCA7C
CINEMATIC_264		EQU 0xCD30
CINEMATIC_265		EQU 0xC9EC
CINEMATIC_266		EQU 0xCA2C
CINEMATIC_267		EQU 0xCCC8
CINEMATIC_268		EQU 0xCAF4
CINEMATIC_269		EQU 0xCDCC
CINEMATIC_270		EQU 0xCA54
CINEMATIC_271		EQU 0xCCFC
CINEMATIC_272		EQU 0xCA04
CINEMATIC_273		EQU 0xCC94
CINEMATIC_274		EQU 0x5700
CINEMATIC_275		EQU 0x9A20
CINEMATIC_276		EQU 0xC262
CINEMATIC_277		EQU 0xC17E
CINEMATIC_278		EQU 0xC194
CINEMATIC_279		EQU 0x0038
CINEMATIC_280		EQU 0x59A0
CINEMATIC_281		EQU 0x5A28
CINEMATIC_282		EQU 0x5AEA
CINEMATIC_283		EQU 0x5B22
CINEMATIC_284		EQU 0x5B56
CINEMATIC_285		EQU 0x5B96
CINEMATIC_286		EQU 0x5B9E
CINEMATIC_287		EQU 0x5BA6
CINEMATIC_288		EQU 0x5BAE
CINEMATIC_289		EQU 0x5BB6
CINEMATIC_290		EQU 0x5BBE
CINEMATIC_291		EQU 0x5BC6
CINEMATIC_292		EQU 0x5BCE
CINEMATIC_293		EQU 0x5BD6
CINEMATIC_294		EQU 0x5BDE
CINEMATIC_295		EQU 0x5BE6
CINEMATIC_296		EQU 0x5C02
CINEMATIC_297		EQU 0x5C0A
CINEMATIC_298		EQU 0xAB94
CINEMATIC_299		EQU 0xABF8
CINEMATIC_300		EQU 0xAC60
CINEMATIC_301		EQU 0xC19C
CINEMATIC_302		EQU 0xC1A6
CINEMATIC_303		EQU 0xC1B2
CINEMATIC_304		EQU 0xC1BE
CINEMATIC_305		EQU 0x4D12
CINEMATIC_306		EQU 0x9930
CINEMATIC_307		EQU 0xA5D6
CINEMATIC_308		EQU 0x9E60
CINEMATIC_309		EQU 0xA052
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
CINEMATIC_328		EQU 0x99F0
CINEMATIC_329		EQU 0x9BD8
CINEMATIC_330		EQU 0xA658
CINEMATIC_331		EQU 0xA67C
CINEMATIC_332		EQU 0x9BF4
CINEMATIC_333		EQU 0xC732
CINEMATIC_334		EQU 0x40B4
CINEMATIC_335		EQU 0x8A06
CINEMATIC_336		EQU 0x4106
CINEMATIC_337		EQU 0x8A0E
CINEMATIC_338		EQU 0x4184
CINEMATIC_339		EQU 0x89BE
CINEMATIC_340		EQU 0x4158
CINEMATIC_341		EQU 0x89B6
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
CINEMATIC_361		EQU 0x80A6
CINEMATIC_362		EQU 0x8158
CINEMATIC_363		EQU 0x816E
CINEMATIC_364		EQU 0x8186
CINEMATIC_365		EQU 0xADDE
CINEMATIC_366		EQU 0xAE56
CINEMATIC_367		EQU 0xAEEE
CINEMATIC_368		EQU 0x7B94
CINEMATIC_369		EQU 0x7C54
CINEMATIC_370		EQU 0x7CE4
CINEMATIC_371		EQU 0x7D74
CINEMATIC_372		EQU 0x7E00
CINEMATIC_373		EQU 0x7E80
CINEMATIC_374		EQU 0x7EE8
CINEMATIC_375		EQU 0x7F48
CINEMATIC_376		EQU 0x6AA8
CINEMATIC_377		EQU 0x6B20
CINEMATIC_378		EQU 0x6C1E
CINEMATIC_379		EQU 0xC3DA
CINEMATIC_380		EQU 0x80D4
CINEMATIC_381		EQU 0x812C
CINEMATIC_382		EQU 0x8100
CINEMATIC_383		EQU 0x81E6
CINEMATIC_384		EQU 0x875A
CINEMATIC_385		EQU 0x819E
CINEMATIC_386		EQU 0x81CA
CINEMATIC_387		EQU 0x88A6
CINEMATIC_388		EQU 0x8876
CINEMATIC_389		EQU 0x4976
CINEMATIC_390		EQU 0x450A
CINEMATIC_391		EQU 0xA274
CINEMATIC_392		EQU 0xA7B2
CINEMATIC_393		EQU 0xA7D2
CINEMATIC_394		EQU 0xA27C
CINEMATIC_395		EQU 0xA284
CINEMATIC_396		EQU 0xA7BA
CINEMATIC_397		EQU 0xA2C0
CINEMATIC_398		EQU 0xA7C2
CINEMATIC_399		EQU 0xA7CA
CINEMATIC_400		EQU 0xA2F8
CINEMATIC_401		EQU 0xA31C
CINEMATIC_402		EQU 0xA368
CINEMATIC_403		EQU 0xA374
CINEMATIC_404		EQU 0xA34C
CINEMATIC_405		EQU 0xBF1C
CINEMATIC_406		EQU 0xA380
CINEMATIC_407		EQU 0xA3C0
CINEMATIC_408		EQU 0xA3FC
CINEMATIC_409		EQU 0xA420
CINEMATIC_410		EQU 0xC00E
CINEMATIC_411		EQU 0xA444
CINEMATIC_412		EQU 0xA4A4
CINEMATIC_413		EQU 0xC068
CINEMATIC_414		EQU 0x68D4
CINEMATIC_415		EQU 0xBFEC
CINEMATIC_416		EQU 0xB408
CINEMATIC_417		EQU 0xC110
CINEMATIC_418		EQU 0x629C
CINEMATIC_419		EQU 0x6338
CINEMATIC_420		EQU 0x63D0
CINEMATIC_421		EQU 0x6460
CINEMATIC_422		EQU 0x64E4
CINEMATIC_423		EQU 0x6950
CINEMATIC_424		EQU 0xB6D4
CINEMATIC_425		EQU 0xB6F2
CINEMATIC_426		EQU 0xC6DA
CINEMATIC_427		EQU 0xC6F4
CINEMATIC_428		EQU 0xA84C
CINEMATIC_429		EQU 0xAAB4
CINEMATIC_430		EQU 0xA7FA
CINEMATIC_431		EQU 0xA560
CINEMATIC_432		EQU 0xA4D8
CINEMATIC_433		EQU 0xA688
CINEMATIC_434		EQU 0xB092
CINEMATIC_435		EQU 0xC076
CINEMATIC_436		EQU 0xC62A
CINEMATIC_437		EQU 0xC696
CINEMATIC_438		EQU 0x8A2E
CINEMATIC_439		EQU 0x2A88
CINEMATIC_440		EQU 0x2AE8
CINEMATIC_441		EQU 0x8BAE
CINEMATIC_442		EQU 0x8BEA
CINEMATIC_443		EQU 0x8C32
CINEMATIC_444		EQU 0x8C7E
CINEMATIC_445		EQU 0x87A2
CINEMATIC_446		EQU 0x87DE
CINEMATIC_447		EQU 0x882A
CINEMATIC_448		EQU 0xAF9E
CINEMATIC_449		EQU 0xB26C
CINEMATIC_450		EQU 0xB2CC
CINEMATIC_451		EQU 0xB364
CINEMATIC_452		EQU 0x73C6
CINEMATIC_453		EQU 0x5C62
CINEMATIC_454		EQU 0xC09C
CINEMATIC_455		EQU 0x0074
CINEMATIC_456		EQU 0x0020
CINEMATIC_457		EQU 0x0098
CINEMATIC_458		EQU 0xB788
CINEMATIC_459		EQU 0xC0BC
CINEMATIC_460		EQU 0x7092
CINEMATIC_461		EQU 0x70AA
CINEMATIC_462		EQU 0x70C2
CINEMATIC_463		EQU 0x705E
CINEMATIC_464		EQU 0x7FAC
CINEMATIC_465		EQU 0x7828
CINEMATIC_466		EQU 0x7810
CINEMATIC_467		EQU 0x77F4
CINEMATIC_468		EQU 0x77D8
CINEMATIC_469		EQU 0x77B0
CINEMATIC_470		EQU 0x778C
CINEMATIC_471		EQU 0x8016
CINEMATIC_472		EQU 0x783C
CINEMATIC_473		EQU 0x76B6
CINEMATIC_474		EQU 0x7696
CINEMATIC_475		EQU 0x7650
CINEMATIC_476		EQU 0x75E4
CINEMATIC_477		EQU 0x758E
CINEMATIC_478		EQU 0x753E
CINEMATIC_479		EQU 0x74EE
CINEMATIC_480		EQU 0x747A
CINEMATIC_481		EQU 0x7418
CINEMATIC_482		EQU 0x739E
CINEMATIC_483		EQU 0x72E6
CINEMATIC_484		EQU 0x7302
CINEMATIC_485		EQU 0x731E
CINEMATIC_486		EQU 0x733E
CINEMATIC_487		EQU 0x735A
CINEMATIC_488		EQU 0x736E
CINEMATIC_489		EQU 0xB6BA
CINEMATIC_490		EQU 0xB69A
CINEMATIC_491		EQU 0xB654
CINEMATIC_492		EQU 0xB5E8
CINEMATIC_493		EQU 0xB592
CINEMATIC_494		EQU 0xB542
CINEMATIC_495		EQU 0xB4F2
CINEMATIC_496		EQU 0xB4A2
CINEMATIC_497		EQU 0xB47C
CINEMATIC_498		EQU 0xB430
CINEMATIC_499		EQU 0x70DA
CINEMATIC_500		EQU 0x710E
CINEMATIC_501		EQU 0x712A
CINEMATIC_502		EQU 0x714A
CINEMATIC_503		EQU 0x7166
CINEMATIC_504		EQU 0x717A
CINEMATIC_505		EQU 0x4D5E
CINEMATIC_506		EQU 0x4D72
CINEMATIC_507		EQU 0x7FD0
CINEMATIC_508		EQU 0x4D86
CINEMATIC_509		EQU 0x7FD8
CINEMATIC_510		EQU 0x4D9A
CINEMATIC_511		EQU 0x7FE0
CINEMATIC_512		EQU 0x4DAE
CINEMATIC_513		EQU 0x7FE8
CINEMATIC_514		EQU 0x4DC2
CINEMATIC_515		EQU 0x7FF0
CINEMATIC_516		EQU 0x800C
CINEMATIC_517		EQU 0x8002
CINEMATIC_518		EQU 0x9A38
CINEMATIC_519		EQU 0x9A40
CINEMATIC_520		EQU 0x4DD6
CINEMATIC_521		EQU 0x7FF8
CINEMATIC_522		EQU 0x719E
CINEMATIC_523		EQU 0x7256
CINEMATIC_524		EQU 0x4EDA
CINEMATIC_525		EQU 0x71D6
CINEMATIC_526		EQU 0x720A
CINEMATIC_527		EQU 0x4E9A
CINEMATIC_528		EQU 0x4EBA
CINEMATIC_529		EQU 0x723A
CINEMATIC_530		EQU 0x726E
CINEMATIC_531		EQU 0x7286
CINEMATIC_532		EQU 0x729A
CINEMATIC_533		EQU 0x72AC
CINEMATIC_534		EQU 0x72BC
CINEMATIC_535		EQU 0x72C8
CINEMATIC_536		EQU 0x72DA
CINEMATIC_537		EQU 0x5CBE
CINEMATIC_538		EQU 0x5C76
CINEMATIC_539		EQU 0x5CA6
CINEMATIC_540		EQU 0x2820
CINEMATIC_541		EQU 0x2A6C
CINEMATIC_542		EQU 0x2870
CINEMATIC_543		EQU 0x2A50
CINEMATIC_544		EQU 0x2850
CINEMATIC_545		EQU 0x2A34
CINEMATIC_546		EQU 0x2A18
CINEMATIC_547		EQU 0x2A10
CINEMATIC_548		EQU 0x2A08
CINEMATIC_549		EQU 0x5770
CINEMATIC_550		EQU 0x4FFE
CINEMATIC_551		EQU 0x8216
CINEMATIC_552		EQU 0x4FBA
CINEMATIC_553		EQU 0x8202
CINEMATIC_554		EQU 0x8CD6
CINEMATIC_555		EQU 0x0380
CINEMATIC_556		EQU 0x0BB6
CINEMATIC_557		EQU 0x0B26
CINEMATIC_558		EQU 0x3E38
CINEMATIC_559		EQU 0x3FB4
CINEMATIC_560		EQU 0x0AFC
CINEMATIC_561		EQU 0x0D0A
CINEMATIC_562		EQU 0x084C
CINEMATIC_563		EQU 0x3D3A
CINEMATIC_564		EQU 0x89AE
CINEMATIC_565		EQU 0x3BF0
CINEMATIC_566		EQU 0x3D76
CINEMATIC_567		EQU 0x07DA
CINEMATIC_568		EQU 0x041C
CINEMATIC_569		EQU 0x9902
CINEMATIC_570		EQU 0x5414
CINEMATIC_571		EQU 0x5562
CINEMATIC_572		EQU 0x554E
CINEMATIC_573		EQU 0x55F2
CINEMATIC_574		EQU 0x54E4
CINEMATIC_575		EQU 0x54A4
CINEMATIC_576		EQU 0x564C
CINEMATIC_577		EQU 0x5670
CINEMATIC_578		EQU 0x5698
CINEMATIC_579		EQU 0x56C4
CINEMATIC_580		EQU 0x56E8
CINEMATIC_581		EQU 0x22A8
CINEMATIC_582		EQU 0x2294
CINEMATIC_583		EQU 0x2280
CINEMATIC_584		EQU 0x226C
CINEMATIC_585		EQU 0x2258
CINEMATIC_586		EQU 0x2244
CINEMATIC_587		EQU 0x2230
CINEMATIC_588		EQU 0x221C
CINEMATIC_589		EQU 0x2208
CINEMATIC_590		EQU 0x21F4
CINEMATIC_591		EQU 0x21E0
CINEMATIC_592		EQU 0x21CC
CINEMATIC_593		EQU 0x21B8
CINEMATIC_594		EQU 0x21A4
CINEMATIC_595		EQU 0x2190
CINEMATIC_596		EQU 0x4526
CINEMATIC_597		EQU 0x4552
CINEMATIC_598		EQU 0x46E6
CINEMATIC_599		EQU 0x456E
CINEMATIC_600		EQU 0x4702
CINEMATIC_601		EQU 0x458A
CINEMATIC_602		EQU 0x45DE
CINEMATIC_603		EQU 0x461A
CINEMATIC_604		EQU 0x4752
CINEMATIC_605		EQU 0x4766
CINEMATIC_606		EQU 0x4652
CINEMATIC_607		EQU 0x477A
CINEMATIC_608		EQU 0x4666
CINEMATIC_609		EQU 0x47B6
CINEMATIC_610		EQU 0x47F6
CINEMATIC_611		EQU 0x46A6
CINEMATIC_612		EQU 0x487A
CINEMATIC_613		EQU 0x48CA
CINEMATIC_614		EQU 0x492A
CINEMATIC_615		EQU 0x5262
CINEMATIC_616		EQU 0x49FA
CINEMATIC_617		EQU 0x527A
CINEMATIC_618		EQU 0x5172
CINEMATIC_619		EQU 0x5292
CINEMATIC_620		EQU 0x51C2
CINEMATIC_621		EQU 0x52AA
CINEMATIC_622		EQU 0x5212
CINEMATIC_623		EQU 0x52C2
CINEMATIC_624		EQU 0x514C
CINEMATIC_625		EQU 0x512A
CINEMATIC_626		EQU 0x510C
CINEMATIC_627		EQU 0x50DA
CINEMATIC_628		EQU 0x50B4
CINEMATIC_629		EQU 0x5356
CINEMATIC_630		EQU 0x539E
CINEMATIC_631		EQU 0x53C8
CINEMATIC_632		EQU 0x2C4C
CINEMATIC_633		EQU 0x4836
CINEMATIC_634		EQU 0x3756
CINEMATIC_635		EQU 0xC5A6
CINEMATIC_636		EQU 0xC58A
CINEMATIC_637		EQU 0x34F4
CINEMATIC_638		EQU 0x3444
CINEMATIC_639		EQU 0x3484
CINEMATIC_640		EQU 0x34C4
CINEMATIC_641		EQU 0x34E0
CINEMATIC_642		EQU 0x3428
CINEMATIC_643		EQU 0x3460
CINEMATIC_644		EQU 0x34A8
CINEMATIC_645		EQU 0x31F4
CINEMATIC_646		EQU 0x31CC
CINEMATIC_647		EQU 0x3230
CINEMATIC_648		EQU 0x3214
CINEMATIC_649		EQU 0x3508
CINEMATIC_650		EQU 0x3254
CINEMATIC_651		EQU 0x3726
CINEMATIC_652		EQU 0x36AE
CINEMATIC_653		EQU 0x3634
CINEMATIC_654		EQU 0x3550
CINEMATIC_655		EQU 0x351C
CINEMATIC_656		EQU 0xC756
CINEMATIC_657		EQU 0x3B9E
CINEMATIC_658		EQU 0x378E
CINEMATIC_659		EQU 0x3A66
CINEMATIC_660		EQU 0x3A3A
CINEMATIC_661		EQU 0x3A0E
CINEMATIC_662		EQU 0x39E2
CINEMATIC_663		EQU 0x39B6
CINEMATIC_664		EQU 0x398A
CINEMATIC_665		EQU 0x395E
CINEMATIC_666		EQU 0x3932
CINEMATIC_667		EQU 0x3906
CINEMATIC_668		EQU 0x38DA
CINEMATIC_669		EQU 0x38AE
CINEMATIC_670		EQU 0x3882
CINEMATIC_671		EQU 0x3856
CINEMATIC_672		EQU 0x382A
CINEMATIC_673		EQU 0x37FE
CINEMATIC_674		EQU 0x37D2
CINEMATIC_675		EQU 0x37A6
CINEMATIC_676		EQU 0x379A
CINEMATIC_677		EQU 0x3B92
CINEMATIC_678		EQU 0x3B86
CINEMATIC_679		EQU 0x3B7A
CINEMATIC_680		EQU 0x3B6E
CINEMATIC_681		EQU 0x3B62
CINEMATIC_682		EQU 0x3A92
CINEMATIC_683		EQU 0x2EA2
CINEMATIC_684		EQU 0x32C0
CINEMATIC_685		EQU 0x3782
CINEMATIC_686		EQU 0xC7BA
CINEMATIC_687		EQU 0xC7A2
COMMON_VIDEO_000		EQU 0x3614
COMMON_VIDEO_001		EQU 0x5C8C
COMMON_VIDEO_002		EQU 0x35F8
COMMON_VIDEO_003		EQU 0x35D0
COMMON_VIDEO_004		EQU 0x35B4
COMMON_VIDEO_005		EQU 0x5E44
COMMON_VIDEO_006		EQU 0x5DE4
COMMON_VIDEO_007		EQU 0x0358
COMMON_VIDEO_008		EQU 0x3322
COMMON_VIDEO_009		EQU 0x40CA
COMMON_VIDEO_010		EQU 0x1B14
COMMON_VIDEO_011		EQU 0x5F94
COMMON_VIDEO_012		EQU 0x39A2
COMMON_VIDEO_013		EQU 0x5C94
COMMON_VIDEO_014		EQU 0x57C4
COMMON_VIDEO_015		EQU 0x5878
COMMON_VIDEO_016		EQU 0x5944
COMMON_VIDEO_017		EQU 0x5A08
COMMON_VIDEO_018		EQU 0x5AAC
COMMON_VIDEO_019		EQU 0x5B4C
COMMON_VIDEO_020		EQU 0x4754
COMMON_VIDEO_021		EQU 0x485C
COMMON_VIDEO_022		EQU 0x4BC4
COMMON_VIDEO_023		EQU 0x4B4C
COMMON_VIDEO_024		EQU 0x4ACC
COMMON_VIDEO_025		EQU 0x4A6C
COMMON_VIDEO_026		EQU 0x4A04
COMMON_VIDEO_027		EQU 0x49B0
COMMON_VIDEO_028		EQU 0x48D8
COMMON_VIDEO_029		EQU 0x4954
COMMON_VIDEO_030		EQU 0x46D4
COMMON_VIDEO_031		EQU 0x45C0
COMMON_VIDEO_032		EQU 0x4528
COMMON_VIDEO_033		EQU 0x448C
COMMON_VIDEO_034		EQU 0x4D98
COMMON_VIDEO_035		EQU 0x4DE4
COMMON_VIDEO_036		EQU 0x4E30
COMMON_VIDEO_037		EQU 0x4E7C
COMMON_VIDEO_038		EQU 0x4EC8
COMMON_VIDEO_039		EQU 0x4F14
COMMON_VIDEO_040		EQU 0x4F68
COMMON_VIDEO_041		EQU 0x500C
COMMON_VIDEO_042		EQU 0x5058
COMMON_VIDEO_043		EQU 0x50A8
COMMON_VIDEO_044		EQU 0x50F8
COMMON_VIDEO_045		EQU 0x514C
COMMON_VIDEO_046		EQU 0x0F90
COMMON_VIDEO_047		EQU 0x344E
COMMON_VIDEO_048		EQU 0x5C1C
COMMON_VIDEO_049		EQU 0x3420
COMMON_VIDEO_050		EQU 0x5C14
COMMON_VIDEO_051		EQU 0x33F2
COMMON_VIDEO_052		EQU 0x5C0C
COMMON_VIDEO_053		EQU 0x347C
COMMON_VIDEO_054		EQU 0x5BF8
COMMON_VIDEO_055		EQU 0x338E
COMMON_VIDEO_056		EQU 0x0FF8
COMMON_VIDEO_057		EQU 0x3398
COMMON_VIDEO_058		EQU 0x1060
COMMON_VIDEO_059		EQU 0x33A2
COMMON_VIDEO_060		EQU 0x108C
COMMON_VIDEO_061		EQU 0x33AC
COMMON_VIDEO_062		EQU 0x10B8
COMMON_VIDEO_063		EQU 0x33B6
COMMON_VIDEO_064		EQU 0x10E4
COMMON_VIDEO_065		EQU 0x33C0
COMMON_VIDEO_066		EQU 0x1110
COMMON_VIDEO_067		EQU 0x33CA
COMMON_VIDEO_068		EQU 0x1136
COMMON_VIDEO_069		EQU 0x33D4
COMMON_VIDEO_070		EQU 0x115C
COMMON_VIDEO_071		EQU 0x33DE
COMMON_VIDEO_072		EQU 0x117E
COMMON_VIDEO_073		EQU 0x33E8
COMMON_VIDEO_074		EQU 0x0CBA
COMMON_VIDEO_075		EQU 0x0D48
COMMON_VIDEO_076		EQU 0x0DB6
COMMON_VIDEO_077		EQU 0x3366
COMMON_VIDEO_078		EQU 0x0E38
COMMON_VIDEO_079		EQU 0x3370
COMMON_VIDEO_080		EQU 0x0EB6
COMMON_VIDEO_081		EQU 0x337A
COMMON_VIDEO_082		EQU 0x0F28
COMMON_VIDEO_083		EQU 0x3384
COMMON_VIDEO_084		EQU 0x4650
COMMON_VIDEO_085		EQU 0x4C40
COMMON_VIDEO_086		EQU 0x47DC
COMMON_VIDEO_087		EQU 0x52C0
COMMON_VIDEO_088		EQU 0x52E0
COMMON_VIDEO_089		EQU 0x5300
COMMON_VIDEO_090		EQU 0x5320
COMMON_VIDEO_091		EQU 0x5340
COMMON_VIDEO_092		EQU 0x5360
COMMON_VIDEO_093		EQU 0x5380
COMMON_VIDEO_094		EQU 0x53C0
COMMON_VIDEO_095		EQU 0x53E0
COMMON_VIDEO_096		EQU 0x5400
COMMON_VIDEO_097		EQU 0x5420
COMMON_VIDEO_098		EQU 0x5444
COMMON_VIDEO_099		EQU 0x037C
COMMON_VIDEO_100		EQU 0x332A
COMMON_VIDEO_101		EQU 0x0764
COMMON_VIDEO_102		EQU 0x3332
COMMON_VIDEO_103		EQU 0x0790
COMMON_VIDEO_104		EQU 0x333A
COMMON_VIDEO_105		EQU 0x07BC
COMMON_VIDEO_106		EQU 0x3342
COMMON_VIDEO_107		EQU 0x07E8
COMMON_VIDEO_108		EQU 0x334A
COMMON_VIDEO_109		EQU 0x0814
COMMON_VIDEO_110		EQU 0x0844
COMMON_VIDEO_111		EQU 0x0874
COMMON_VIDEO_112		EQU 0x08A0
COMMON_VIDEO_113		EQU 0x0020
COMMON_VIDEO_114		EQU 0x00B4
COMMON_VIDEO_115		EQU 0x0128
COMMON_VIDEO_116		EQU 0x01B0
COMMON_VIDEO_117		EQU 0x0234
COMMON_VIDEO_118		EQU 0x02AC
COMMON_VIDEO_119		EQU 0x331A
COMMON_VIDEO_120		EQU 0x40EC
COMMON_VIDEO_121		EQU 0x2B0E
COMMON_VIDEO_122		EQU 0x5FCC
COMMON_VIDEO_123		EQU 0x247C
COMMON_VIDEO_124		EQU 0x181C
COMMON_VIDEO_125		EQU 0x1A84
COMMON_VIDEO_126		EQU 0x5F7C
COMMON_VIDEO_127		EQU 0x1866
COMMON_VIDEO_128		EQU 0x18B0
COMMON_VIDEO_129		EQU 0x1AB4
COMMON_VIDEO_130		EQU 0x5F84
COMMON_VIDEO_131		EQU 0x18FA
COMMON_VIDEO_132		EQU 0x1AE4
COMMON_VIDEO_133		EQU 0x5F8C
COMMON_VIDEO_134		EQU 0x1944
COMMON_VIDEO_135		EQU 0x2474
COMMON_VIDEO_136		EQU 0x198E
COMMON_VIDEO_137		EQU 0x1B44
COMMON_VIDEO_138		EQU 0x5F9C
COMMON_VIDEO_139		EQU 0x246C
COMMON_VIDEO_140		EQU 0x19C4
COMMON_VIDEO_141		EQU 0x1B74
COMMON_VIDEO_142		EQU 0x5FA4
COMMON_VIDEO_143		EQU 0x245C
COMMON_VIDEO_144		EQU 0x1A0E
COMMON_VIDEO_145		EQU 0x1BA4
COMMON_VIDEO_146		EQU 0x5FAC
COMMON_VIDEO_147		EQU 0x2464
COMMON_VIDEO_148		EQU 0x1D78
COMMON_VIDEO_149		EQU 0x1BD4
COMMON_VIDEO_150		EQU 0x5FB4
COMMON_VIDEO_151		EQU 0x1D9A
COMMON_VIDEO_152		EQU 0x1DBC
COMMON_VIDEO_153		EQU 0x1DDE
COMMON_VIDEO_154		EQU 0x1E00
COMMON_VIDEO_155		EQU 0x1E22
COMMON_VIDEO_156		EQU 0x1E44
COMMON_VIDEO_157		EQU 0x1E66
COMMON_VIDEO_158		EQU 0x1A54
COMMON_VIDEO_159		EQU 0x5F74
COMMON_VIDEO_160		EQU 0x2D6E
COMMON_VIDEO_161		EQU 0x257A
COMMON_VIDEO_162		EQU 0x2AC6
COMMON_VIDEO_163		EQU 0x5FC4
COMMON_VIDEO_164		EQU 0x2610
COMMON_VIDEO_165		EQU 0x2672
COMMON_VIDEO_166		EQU 0x270C
COMMON_VIDEO_167		EQU 0x2B56
COMMON_VIDEO_168		EQU 0x5FD4
COMMON_VIDEO_169		EQU 0x2786
COMMON_VIDEO_170		EQU 0x2B9E
COMMON_VIDEO_171		EQU 0x5FDC
COMMON_VIDEO_172		EQU 0x2D66
COMMON_VIDEO_173		EQU 0x27FC
COMMON_VIDEO_174		EQU 0x2BE6
COMMON_VIDEO_175		EQU 0x5FE4
COMMON_VIDEO_176		EQU 0x2D5E
COMMON_VIDEO_177		EQU 0x287E
COMMON_VIDEO_178		EQU 0x2C2E
COMMON_VIDEO_179		EQU 0x5FEC
COMMON_VIDEO_180		EQU 0x2D4E
COMMON_VIDEO_181		EQU 0x28F8
COMMON_VIDEO_182		EQU 0x2C76
COMMON_VIDEO_183		EQU 0x5FF4
COMMON_VIDEO_184		EQU 0x2D56
COMMON_VIDEO_185		EQU 0x296E
COMMON_VIDEO_186		EQU 0x2CBE
COMMON_VIDEO_187		EQU 0x5FFC
COMMON_VIDEO_188		EQU 0x2990
COMMON_VIDEO_189		EQU 0x29B2
COMMON_VIDEO_190		EQU 0x29D4
COMMON_VIDEO_191		EQU 0x29F6
COMMON_VIDEO_192		EQU 0x2A18
COMMON_VIDEO_193		EQU 0x2A3A
COMMON_VIDEO_194		EQU 0x2A5C
COMMON_VIDEO_195		EQU 0x2A7E
COMMON_VIDEO_196		EQU 0x5FBC
COMMON_VIDEO_197		EQU 0x2566
COMMON_VIDEO_198		EQU 0x1F70
COMMON_VIDEO_199		EQU 0x6108
COMMON_VIDEO_200		EQU 0x255C
COMMON_VIDEO_201		EQU 0x1FE4
COMMON_VIDEO_202		EQU 0x21A8
COMMON_VIDEO_203		EQU 0x2552
COMMON_VIDEO_204		EQU 0x2058
COMMON_VIDEO_205		EQU 0x21D6
COMMON_VIDEO_206		EQU 0x2548
COMMON_VIDEO_207		EQU 0x20B8
COMMON_VIDEO_208		EQU 0x2200
COMMON_VIDEO_209		EQU 0x2570
COMMON_VIDEO_210		EQU 0x2134
COMMON_VIDEO_211		EQU 0x2212
COMMON_VIDEO_212		EQU 0x2310
COMMON_VIDEO_213		EQU 0x232C
COMMON_VIDEO_214		EQU 0x2348
COMMON_VIDEO_215		EQU 0x224C
COMMON_VIDEO_216		EQU 0x2364
COMMON_VIDEO_217		EQU 0x2276
COMMON_VIDEO_218		EQU 0x2380
COMMON_VIDEO_219		EQU 0x320A
COMMON_VIDEO_220		EQU 0x2D76
COMMON_VIDEO_221		EQU 0x61A2
COMMON_VIDEO_222		EQU 0x3200
COMMON_VIDEO_223		EQU 0x2E0A
COMMON_VIDEO_224		EQU 0x3116
COMMON_VIDEO_225		EQU 0x31F6
COMMON_VIDEO_226		EQU 0x2E9E
COMMON_VIDEO_227		EQU 0x3124
COMMON_VIDEO_228		EQU 0x31EC
COMMON_VIDEO_229		EQU 0x2F3A
COMMON_VIDEO_230		EQU 0x316E
COMMON_VIDEO_231		EQU 0x3212
COMMON_VIDEO_232		EQU 0x2FD6
COMMON_VIDEO_233		EQU 0x3180
COMMON_VIDEO_234		EQU 0x304A
COMMON_VIDEO_235		EQU 0x3066
COMMON_VIDEO_236		EQU 0x3082
COMMON_VIDEO_237		EQU 0x31A8
COMMON_VIDEO_238		EQU 0x309E
COMMON_VIDEO_239		EQU 0x31CA
COMMON_VIDEO_240		EQU 0x30BA
COMMON_VIDEO_241		EQU 0x4132
COMMON_VIDEO_242		EQU 0x42BA
COMMON_VIDEO_243		EQU 0x4314
COMMON_VIDEO_244		EQU 0x3E4E
COMMON_VIDEO_245		EQU 0x4324
COMMON_VIDEO_246		EQU 0x426C
COMMON_VIDEO_247		EQU 0x4346
COMMON_VIDEO_248		EQU 0x4368
COMMON_VIDEO_249		EQU 0x3A64
COMMON_VIDEO_250		EQU 0x5C9C
COMMON_VIDEO_251		EQU 0x03E4
COMMON_VIDEO_252		EQU 0x3542
COMMON_VIDEO_253		EQU 0x34AA
COMMON_VIDEO_254		EQU 0x0472
COMMON_VIDEO_255		EQU 0x3558
COMMON_VIDEO_256		EQU 0x34B2
COMMON_VIDEO_257		EQU 0x4FBC
COMMON_VIDEO_258		EQU 0x06A2
COMMON_VIDEO_259		EQU 0x34D6
COMMON_VIDEO_260		EQU 0x06C8
COMMON_VIDEO_261		EQU 0x34DE
COMMON_VIDEO_262		EQU 0x06EE
COMMON_VIDEO_263		EQU 0x34E6
COMMON_VIDEO_264		EQU 0x0714
COMMON_VIDEO_265		EQU 0x34FE
COMMON_VIDEO_266		EQU 0x34EE
COMMON_VIDEO_267		EQU 0x073E
COMMON_VIDEO_268		EQU 0x34F6
COMMON_VIDEO_269		EQU 0x04F4
COMMON_VIDEO_270		EQU 0x352C
COMMON_VIDEO_271		EQU 0x34BA
COMMON_VIDEO_272		EQU 0x058E
COMMON_VIDEO_273		EQU 0x356E
COMMON_VIDEO_274		EQU 0x34C2
COMMON_VIDEO_275		EQU 0x0624
COMMON_VIDEO_276		EQU 0x34CE
COMMON_VIDEO_277		EQU 0x3630
COMMON_VIDEO_278		EQU 0x11B8
COMMON_VIDEO_279		EQU 0x367C
COMMON_VIDEO_280		EQU 0x3638
COMMON_VIDEO_281		EQU 0x125A
COMMON_VIDEO_282		EQU 0x53A0
COMMON_VIDEO_283		EQU 0x3650
COMMON_VIDEO_284		EQU 0x150A
COMMON_VIDEO_285		EQU 0x3674
COMMON_VIDEO_286		EQU 0x1530
COMMON_VIDEO_287		EQU 0x3658
COMMON_VIDEO_288		EQU 0x1556
COMMON_VIDEO_289		EQU 0x3660
COMMON_VIDEO_290		EQU 0x157C
COMMON_VIDEO_291		EQU 0x366C
COMMON_VIDEO_292		EQU 0x15A2
COMMON_VIDEO_293		EQU 0x3640
COMMON_VIDEO_294		EQU 0x1304
COMMON_VIDEO_295		EQU 0x3648
COMMON_VIDEO_296		EQU 0x13B2
COMMON_VIDEO_297		EQU 0x1474


	org 0x0000

LABEL_0000:
	call LABEL_0720	;@raw=0x04,0x07,0x20
	setup channel=0x3C, address=LABEL_069F	;@raw=0x08,0x3C,0x06,0x9F
	mov [PAUSE_SLICES], 0x0004	;@raw=0x00,0xFF,0x00,0x04
	mov [0xF6], 0x0001	;@raw=0x00,0xF6,0x00,0x01
	mov [0x32], 0x0000	;@raw=0x00,0x32,0x00,0x00
	mov [0xB6], 0x0000	;@raw=0x00,0xB6,0x00,0x00
	mov [0x0A], 0x0000	;@raw=0x00,0x0A,0x00,0x00
	call PRELOAD_PRISON_RESOURCES	;@raw=0x04,0x00,0xFE
	play id=0x0055, freq=0x14, vol=0x00, channel=0x01	;@raw=0x18,0x00,0x55,0x14,0x00,0x01
	play id=0x0055, freq=0x14, vol=0x00, channel=0x02	;@raw=0x18,0x00,0x55,0x14,0x00,0x02
	play id=0x0055, freq=0x14, vol=0x00, channel=0x03	;@raw=0x18,0x00,0x55,0x14,0x00,0x03
	play id=0x0055, freq=0x14, vol=0x00, channel=0x00	;@raw=0x18,0x00,0x55,0x14,0x00,0x00
	jge [0x00], 0x15, LABEL_0068	;@raw=0x0A,0x03,0x00,0x15,0x00,0x68
	mov [0x00], 0x0014	;@raw=0x00,0x00,0x00,0x14
	jmp LABEL_005F	;@raw=0x07,0x00,0x5F
LABEL_0043:
	db 0x08, 0x15, 0x89, 0x02, 0x08, 0x16, 0x89, 0x44
	db 0x08, 0x0A, 0x05, 0xA1, 0x04, 0x07, 0xFC, 0x0F
	db 0x03, 0x00, 0x80, 0x4C, 0x00, 0x5A, 0x80, 0x06
	db 0x00, 0xB6, 0x11, 0x11

LABEL_005F:
	setup channel=0x01, address=FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA	;@raw=0x08,0x01,0x4E,0x7A
	setup channel=0x02, address=LABEL_4EDA	;@raw=0x08,0x02,0x4E,0xDA
	killChannel	;@raw=0x11

LABEL_0068:
	setup channel=0x22, address=LABEL_4C18	;@raw=0x08,0x22,0x4C,0x18
	setup channel=0x23, address=LABEL_4AC9	;@raw=0x08,0x23,0x4A,0xC9
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4	;@raw=0x08,0x14,0x78,0x27
	setup channel=0x15, address=LABEL_777F	;@raw=0x08,0x15,0x77,0x7F
	setup channel=0x00, address=LABEL_1CB8	;@raw=0x08,0x00,0x1C,0xB8
	call LABEL_1CC9	;@raw=0x04,0x1C,0xC9
	killChannel	;@raw=0x11

LIKELY_A_COPY_PROTECTION_MECHANISM:
	mov [0xF8], [0xBC]	;@raw=0x01,0xF8,0xBC
	and [0xF8], 0x0010	;@raw=0x14,0xF8,0x00,0x10
	je [0xF8], 0x00, LABEL_0095	;@raw=0x0A,0x00,0xF8,0x00,0x00,0x95
	jne [0xF2], 0x1770, LABEL_0095	;@raw=0x0A,0x41,0xF2,0x17,0x70,0x00,0x95
	ret	;@raw=0x05

LABEL_0095:
	deleteChannels first=0x00, last=0x3F	;@raw=0x0C,0x00,0x3F,0x02
	setup channel=0x3C, address=KILL_CHANNEL_LANDING	;@raw=0x08,0x3C,0x01,0x7F
	killChannel	;@raw=0x11
