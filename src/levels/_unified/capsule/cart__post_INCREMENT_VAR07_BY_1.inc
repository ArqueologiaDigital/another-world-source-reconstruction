DRAW_ALIEN_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_84F4
	je [0xF8], 0x00, DRAW_CIN_102
	je [0xF8], 0x01, DRAW_CIN_103
	je [0xF8], 0x02, DRAW_CIN_104
	je [0xF8], 0x03, DRAW_CIN_105
	je [0xF8], 0x04, DRAW_CIN_106
	je [0xF8], 0x05, DRAW_CIN_027
	je [0xF8], 0x06, DRAW_CIN_107
	je [0xF8], 0x07, DRAW_CIN_108
	ret

LABEL_84F4:
	jne [0x0E], 0x01, LABEL_84FD
	jmp DRAW_CIN_101

LABEL_84FD:
	jne [0x0E], 0x02, LABEL_8506
	jmp DRAW_CIN_100

LABEL_8506:
	jne [0x0E], 0x03, LABEL_850F
	jmp DRAW_CIN_099

LABEL_850F:
	jne [0x0E], 0x04, LABEL_851E
	je [0xF8], 0x01, DRAW_CIN_097
	jmp DRAW_CIN_098

LABEL_851E:
	jne [0x0E], 0x05, LABEL_8527
	jmp DRAW_CIN_096

LABEL_8527:
	jne [0x0E], 0x07, LABEL_8534
	je [0xF8], 0x01, DRAW_CIN_095
	ret

LABEL_8534:
	ret

DRAW_CIN_102:
	video type=1, offset=CINEMATIC_102, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_103:
	video type=1, offset=CINEMATIC_103, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_104:
	video type=1, offset=CINEMATIC_104, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_105:
	video type=1, offset=CINEMATIC_105, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_106:
	video type=1, offset=CINEMATIC_106, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_107:
	video type=1, offset=CINEMATIC_107, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_108:
	video type=1, offset=CINEMATIC_108, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_101:
	video type=1, offset=CINEMATIC_101, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_100:
	video type=1, offset=CINEMATIC_100, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_099:
	video type=1, offset=CINEMATIC_099, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_098:
	video type=1, offset=CINEMATIC_098, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_097:
	video type=1, offset=CINEMATIC_097, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_096:
	video type=1, offset=CINEMATIC_096, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_095:
	video type=1, offset=CINEMATIC_095, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_8589:
	db 0x11

DRAW_CIN_109_110_111_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_109
	je [0xF8], 0x02, DRAW_CIN_110
	je [0xF8], 0x03, DRAW_CIN_111
	ret

DRAW_CIN_109:
	video type=1, offset=CINEMATIC_109, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_110:
	video type=1, offset=CINEMATIC_110, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_111:
	video type=1, offset=CINEMATIC_111, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_112_113_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_112
	je [0xF8], 0x02, DRAW_CIN_113
	ret

DRAW_CIN_112:
	video type=1, offset=CINEMATIC_112, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_113:
	video type=1, offset=CINEMATIC_113, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_85D6:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_85EC:
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_8602:
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_861C:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_8632:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_864C:
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_8666:
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_8680:
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_869A:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_86B4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_86D6
	call LABEL_826F
	jmp LABEL_86D9

LABEL_86D6:
	call LABEL_85EC

LABEL_86D9:
	ret

LABEL_86DA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8704
	call LABEL_826F
	jmp LABEL_8707

LABEL_8704:
	call LABEL_85EC

LABEL_8707:
	ret

LABEL_8708:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8725
	call LABEL_827B
	jmp LABEL_8728

LABEL_8725:
	call LABEL_8602

LABEL_8728:
	ret

LABEL_8729:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_8752
	call LABEL_827B
	jmp LABEL_8755

LABEL_8752:
	call LABEL_861C

LABEL_8755:
	ret

LABEL_8756:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8773
	call LABEL_827B
	jmp LABEL_8776

LABEL_8773:
	call LABEL_8632

LABEL_8776:
	ret

LABEL_8777:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8799
	call LABEL_829E
	jmp LABEL_879C

LABEL_8799:
	call LABEL_864C

LABEL_879C:
	ret

LABEL_879D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_87BF
	call LABEL_82AA
	jmp LABEL_87C2

LABEL_87BF:
	call LABEL_8666

LABEL_87C2:
	ret

LABEL_87C3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_87E5
	call LABEL_82CD
	jmp LABEL_87E8

LABEL_87E5:
	call LABEL_8680

LABEL_87E8:
	ret

LABEL_87E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_880B
	call LABEL_82F0
	jmp LABEL_880E

LABEL_880B:
	call LABEL_869A

LABEL_880E:
	ret

LABEL_880F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8831
	call LABEL_82F0
	jmp LABEL_883C

LABEL_8831:
	sub [0x07], 0x0001
	call LABEL_869A
	add [0x07], 0x0001

LABEL_883C:
	ret

LABEL_883D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_885F
	call LABEL_82CD
	jmp LABEL_8862

LABEL_885F:
	call LABEL_8666

LABEL_8862:
	ret

LABEL_8863:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_8891
	call LABEL_82CD
	jmp LABEL_8894

LABEL_8891:
	call LABEL_864C

LABEL_8894:
	ret

LABEL_8895:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_88B2
	call LABEL_82CD
	jmp LABEL_88B5

LABEL_88B2:
	call LABEL_8632

LABEL_88B5:
	ret

LABEL_88B6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_88D3
	call LABEL_82AA
	jmp LABEL_88D6

LABEL_88D3:
	call LABEL_861C

LABEL_88D6:
	ret

LABEL_88D7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_88F4
	call LABEL_829E
	jmp LABEL_88F7

LABEL_88F4:
	call LABEL_8602

LABEL_88F7:
	ret

LABEL_88F8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8915
	call LABEL_827B
	jmp LABEL_8918

LABEL_8915:
	call LABEL_85D6

LABEL_8918:
	ret

GUARDED_ALIEN_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8936
	call LABEL_827B
	jmp LABEL_8939

LABEL_8936:
	call LABEL_8632

LABEL_8939:
	ret

LABEL_893A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8957
	call LABEL_829E
	jmp LABEL_895A

LABEL_8957:
	call LABEL_864C

LABEL_895A:
	ret

LABEL_895B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	je [0x0D], 0x00, LABEL_8978
	call LABEL_82AA
	jmp LABEL_897B

LABEL_8978:
	call LABEL_8666

LABEL_897B:
	ret

JUNK__897C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_114, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	call LABEL_82AA
	ret

LABEL_8991:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_115, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	call LABEL_82AA
	ret

LABEL_89A6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_118, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	call LABEL_82AA
	ret

LABEL_89BB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_116, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_109_110_111_VAR09
	call LABEL_82AA
	ret

LABEL_89D0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_312, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89DF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_313, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89EE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_316, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89FD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=1, offset=CINEMATIC_314, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8A0C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_264, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8A18:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_265, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8A24:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8215
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_796B
	sub [0x08], 0x000D
	ret

LABEL_8A41:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_8233
	add [0x08], 0x0001
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7988
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_8A6E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8251
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_796B
	sub [0x08], 0x000D
	ret

LABEL_8A8B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8233
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_796B
	sub [0x08], 0x000D
	ret

LABEL_8AA8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8ABF
	add [0x08], 0x000D
	call DRAW_CV_304_THEN_305
	sub [0x08], 0x000D

LABEL_8ABF:
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7988
	sub [0x08], 0x000D
	ret

LABEL_8AD3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_246, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8AA8
	ret

LABEL_8AE2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7988
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_8B11:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_796B
	sub [0x08], 0x000D
	ret

LABEL_8B30:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_275, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_79A5
	sub [0x08], 0x000D
	ret

LABEL_8B5F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_79A5
	sub [0x08], 0x000D
	ret

LABEL_8B79:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_250, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_79A5
	sub [0x08], 0x000D
	ret

LABEL_8BA0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_249, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8CCE
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7988
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=COMMON_VIDEO_287, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video type=1, offset=CINEMATIC_704, x=[0x78], y=[0x79], zoom=0x40
	ret

LABEL_8BF0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8215
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_79E3
	ret

LABEL_8C0D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_8233
	add [0x08], 0x000E
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_290, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_79E3
	sub [0x07], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8251
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_79E3
	ret

LABEL_8C53:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8233
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_79E3
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8C7F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_357, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8C93:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_245, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_353, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_354, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__8CDA
	ret

LABEL_8CC2:
	add [0x08], 0x000E
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000E
	ret

LABEL_8CCE:
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000D
	ret

JUNK__8CDA:
	video type=1, offset=CINEMATIC_703, x=[0x07], y=[0x08], zoom=0x40
	ret
