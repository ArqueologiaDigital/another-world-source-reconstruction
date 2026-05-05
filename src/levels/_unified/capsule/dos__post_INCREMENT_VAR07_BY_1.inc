DRAW_ALIEN_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_848B
	je [0xF8], 0x00, DRAW_CIN_101
	je [0xF8], 0x01, DRAW_CIN_102
	je [0xF8], 0x02, DRAW_CIN_103
	je [0xF8], 0x03, DRAW_CIN_104
	je [0xF8], 0x04, DRAW_CIN_105
	je [0xF8], 0x05, DRAW_CIN_027
	je [0xF8], 0x06, DRAW_CIN_106
	je [0xF8], 0x07, DRAW_CIN_107
	ret

LABEL_848B:
	jne [0x0E], 0x01, LABEL_8494
	jmp DRAW_CIN_100

LABEL_8494:
	jne [0x0E], 0x02, LABEL_849D
	jmp DRAW_CIN_099

LABEL_849D:
	jne [0x0E], 0x03, LABEL_84A6
	jmp DRAW_CIN_098

LABEL_84A6:
	jne [0x0E], 0x04, LABEL_84B5
	je [0xF8], 0x01, DRAW_CIN_096
	jmp DRAW_CIN_097

LABEL_84B5:
	jne [0x0E], 0x05, LABEL_84BE
	jmp DRAW_CIN_095

LABEL_84BE:
	jne [0x0E], 0x07, LABEL_84CB
	je [0xF8], 0x01, DRAW_CIN_094
	ret

LABEL_84CB:
	ret

DRAW_CIN_101:
	video offset=CINEMATIC_101, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_102:
	video offset=CINEMATIC_102, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_103:
	video offset=CINEMATIC_103, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_104:
	video offset=CINEMATIC_104, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_105:
	video offset=CINEMATIC_105, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_106:
	video offset=CINEMATIC_106, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_107:
	video offset=CINEMATIC_107, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_100:
	video offset=CINEMATIC_100, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_099:
	video offset=CINEMATIC_099, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_098:
	video offset=CINEMATIC_098, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_097:
	video offset=CINEMATIC_097, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_096:
	video offset=CINEMATIC_096, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_095:
	video offset=CINEMATIC_095, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_094:
	video offset=CINEMATIC_094, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_8520:
	db 0x11

DRAW_CIN_108_109_110_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_108
	je [0xF8], 0x02, DRAW_CIN_109
	je [0xF8], 0x03, DRAW_CIN_110
	ret

DRAW_CIN_108:
	video offset=CINEMATIC_108, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_109:
	video offset=CINEMATIC_109, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_110:
	video offset=CINEMATIC_110, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_111_112_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_111
	je [0xF8], 0x02, DRAW_CIN_112
	ret

DRAW_CIN_111:
	video offset=CINEMATIC_111, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_112:
	video offset=CINEMATIC_112, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_856D:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8583:
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8599:
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_85B3:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_85C9:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_85E3:
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_85FD:
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8617:
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8631:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_864B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_866D
	call LABEL_8206
	jmp LABEL_8670

LABEL_866D:
	call LABEL_8583

LABEL_8670:
	ret

LABEL_8671:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_869B
	call LABEL_8206
	jmp LABEL_869E

LABEL_869B:
	call LABEL_8583

LABEL_869E:
	ret

LABEL_869F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_86BC
	call LABEL_8212
	jmp LABEL_86BF

LABEL_86BC:
	call LABEL_8599

LABEL_86BF:
	ret

LABEL_86C0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_86E9
	call LABEL_8212
	jmp LABEL_86EC

LABEL_86E9:
	call LABEL_85B3

LABEL_86EC:
	ret

LABEL_86ED:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_870A
	call LABEL_8212
	jmp LABEL_870D

LABEL_870A:
	call LABEL_85C9

LABEL_870D:
	ret

LABEL_870E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_8730
	call LABEL_8235
	jmp LABEL_8733

LABEL_8730:
	call LABEL_85E3

LABEL_8733:
	ret

LABEL_8734:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_8756
	call LABEL_8241
	jmp LABEL_8759

LABEL_8756:
	call LABEL_85FD

LABEL_8759:
	ret

LABEL_875A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_877C
	call LABEL_8264
	jmp LABEL_877F

LABEL_877C:
	call LABEL_8617

LABEL_877F:
	ret

LABEL_8780:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_87A2
	call LABEL_8287
	jmp LABEL_87A5

LABEL_87A2:
	call LABEL_8631

LABEL_87A5:
	ret

LABEL_87A6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_87C8
	call LABEL_8287
	jmp LABEL_87D3

LABEL_87C8:
	sub [0x07], 0x0001
	call LABEL_8631
	add [0x07], 0x0001

LABEL_87D3:
	ret

LABEL_87D4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_87F6
	call LABEL_8264
	jmp LABEL_87F9

LABEL_87F6:
	call LABEL_85FD

LABEL_87F9:
	ret

LABEL_87FA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_8828
	call LABEL_8264
	jmp LABEL_882B

LABEL_8828:
	call LABEL_85E3

LABEL_882B:
	ret

LABEL_882C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_8849
	call LABEL_8264
	jmp LABEL_884C

LABEL_8849:
	call LABEL_85C9

LABEL_884C:
	ret

LABEL_884D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_886A
	call LABEL_8241
	jmp LABEL_886D

LABEL_886A:
	call LABEL_85B3

LABEL_886D:
	ret

LABEL_886E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_888B
	call LABEL_8235
	jmp LABEL_888E

LABEL_888B:
	call LABEL_8599

LABEL_888E:
	ret

LABEL_888F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_88AC
	call LABEL_8212
	jmp LABEL_88AF

LABEL_88AC:
	call LABEL_856D

LABEL_88AF:
	ret

GUARDED_ALIEN_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_88CD
	call LABEL_8212
	jmp LABEL_88D0

LABEL_88CD:
	call LABEL_85C9

LABEL_88D0:
	ret

LABEL_88D1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_88EE
	call LABEL_8235
	jmp LABEL_88F1

LABEL_88EE:
	call LABEL_85E3

LABEL_88F1:
	ret

LABEL_88F2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	je [0x0D], 0x00, LABEL_890F
	call LABEL_8241
	jmp LABEL_8912

LABEL_890F:
	call LABEL_85FD

LABEL_8912:
	ret

JUNK__8913:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_113, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	call LABEL_8241
	ret

LABEL_8928:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_114, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	call LABEL_8241
	ret

LABEL_893D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_117, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	call LABEL_8241
	ret

LABEL_8952:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_115, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_108_109_110_VAR09
	call LABEL_8241
	ret

LABEL_8967:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_311, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8976:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_312, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8985:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_315, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8994:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video offset=CINEMATIC_313, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89A3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_263, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89AF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_264, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_89BB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_81AC
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7902
	sub [0x08], 0x000D
	ret

LABEL_89D8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_81CA
	add [0x08], 0x0001
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_791F
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_8A05:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_81E8
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7902
	sub [0x08], 0x000D
	ret

LABEL_8A22:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_81CA
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7902
	sub [0x08], 0x000D
	ret

LABEL_8A3F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8A56
	add [0x08], 0x000D
	call DRAW_CV_304_THEN_305
	sub [0x08], 0x000D

LABEL_8A56:
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_791F
	sub [0x08], 0x000D
	ret

LABEL_8A6A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_245, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8A3F
	ret

LABEL_8A79:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_791F
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_8AA8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7902
	sub [0x08], 0x000D
	ret

LABEL_8AC7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_275, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_793C
	sub [0x08], 0x000D
	ret

LABEL_8AF6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_793C
	sub [0x08], 0x000D
	ret

LABEL_8B10:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_249, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_793C
	sub [0x08], 0x000D
	ret

LABEL_8B37:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_248, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8C65
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_791F
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=COMMON_VIDEO_287, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video offset=CINEMATIC_701, x=[0x78], y=[0x79], zoom=0x40
	ret

LABEL_8B87:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_81AC
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_797A
	ret

LABEL_8BA4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_81CA
	add [0x08], 0x000E
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_290, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_797A
	sub [0x07], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_81E8
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_797A
	ret

LABEL_8BEA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_81CA
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_797A
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8C16:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_357, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8C2A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_244, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_353, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_354, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__8C71
	ret

LABEL_8C59:
	add [0x08], 0x000E
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000E
	ret

LABEL_8C65:
	add [0x08], 0x000D
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000D
	ret

JUNK__8C71:
	video offset=CINEMATIC_700, x=[0x07], y=[0x08], zoom=0x40
	ret
