LABEL_9CAF:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_528, x=160, y=100
	video offset=CINEMATIC_529, x=160, y=100
	video offset=CINEMATIC_530, x=160, y=100
	video offset=CINEMATIC_531, x=160, y=100
	ret

LABEL_9CC3:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_528, x=160, y=100
	video offset=CINEMATIC_557, x=160, y=100
	video offset=CINEMATIC_558, x=160, y=100
	video offset=CINEMATIC_559, x=160, y=100
	video offset=CINEMATIC_560, x=160, y=100
	ret
	fill page=0x00, color=0x08
	video offset=CINEMATIC_528, x=160, y=100
	video offset=CINEMATIC_557, x=160, y=100
	video offset=CINEMATIC_558, x=160, y=100
	video offset=CINEMATIC_559, x=160, y=100
	video offset=CINEMATIC_560, x=160, y=100
	ret

LABEL_9CF3:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_571, x=160, y=198
	video offset=CINEMATIC_572, x=160, y=198
	video offset=CINEMATIC_573, x=160, y=100
	video offset=CINEMATIC_574, x=160, y=100
	ret

LABEL_9D07:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_577, x=160, y=100
	ret

LABEL_9D0F:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_498, x=160, y=100
	ret

LABEL_9D17:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_567, x=160, y=100
	video offset=CINEMATIC_568, x=160, y=100
	video offset=CINEMATIC_569, x=160, y=100
	ret

LABEL_9D27:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_561, x=155, y=95
	video offset=CINEMATIC_562, x=160, y=100
	ret

LABEL_9D33:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_571, x=160, y=151
	video offset=CINEMATIC_620, x=160, y=100
	ret

LABEL_9D3F:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_503, x=160, y=100
	video offset=CINEMATIC_504, x=160, y=100
	ret

LABEL_9D4B:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_509, x=160, y=100
	video offset=CINEMATIC_510, x=160, y=100
	video offset=CINEMATIC_511, x=160, y=100
	ret

LABEL_9D5B:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_580, x=160, y=100
	video offset=CINEMATIC_581, x=160, y=100
	ret

LABEL_9D67:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_571, x=160, y=187
	video offset=CINEMATIC_584, x=160, y=100
	ret

LABEL_9D73:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_561, x=160, y=23
	video offset=CINEMATIC_601, x=160, y=50
	mov [0xF8], [0xB9]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, DRAW_CIN_600_THEN_CIN_346
	video offset=CINEMATIC_596, x=232, y=65
	video offset=CINEMATIC_600, x=151, y=14
	ret

DRAW_CIN_600_THEN_CIN_346:
	video offset=CINEMATIC_600, x=151, y=65496, zoom=0x40
	video offset=CINEMATIC_346, x=6, y=99
	ret

LABEL_9D9F:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_561, x=160, y=23
	video offset=CINEMATIC_595, x=160, y=100
	video offset=CINEMATIC_596, x=74, y=64
	video offset=CINEMATIC_597, x=74, y=64
	video offset=CINEMATIC_598, x=74, y=64
	video offset=CINEMATIC_596, x=191, y=65
	video offset=CINEMATIC_597, x=191, y=65
	video offset=CINEMATIC_598, x=191, y=65
	video offset=CINEMATIC_596, x=295, y=64, zoom=0x40
	video offset=CINEMATIC_597, x=295, y=64, zoom=0x40
	video offset=CINEMATIC_599, x=295, y=64, zoom=0x40
	video offset=CINEMATIC_600, x=65528, y=15, zoom=0x40
	video offset=CINEMATIC_600, x=107, y=14
	video offset=CINEMATIC_600, x=212, y=15
	call LABEL_3708
	mov [0x10], [HACK_VAR_67]
	mov [0x08], [0x40]
	mov [0x07], 0x0064
	mov [0x09], 0x0001
	call GUARDED_ALIEN_ANIM_CV_128
	mov [0x09], 0x0033
	mov [0x07], 0x0050
	call GUARDED_ALIEN_ANIM_CV_128
	mov [0x09], 0x0001
	mov [0x07], 0x046A
	call GUARDED_ALIEN_ANIM_CV_128
	mov [0x09], 0x0001
	mov [0x07], 0x0032
	call GUARDED_ALIEN_ANIM_CV_128
	mov [0x09], 0x0001
	mov [0x07], 0x005A
	call GUARDED_ALIEN_ANIM_CV_128
	mov [0x09], 0x0033
	mov [0x07], 0x047E
	call GUARDED_ALIEN_ANIM_CV_128
	ret

LABEL_9E2B:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_436, x=160, y=100
	video offset=CINEMATIC_437, x=160, y=100
	video offset=CINEMATIC_438, x=160, y=100
	video offset=CINEMATIC_439, x=160, y=100
	ret

LABEL_9E3F:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_482, x=160, y=100
	video offset=CINEMATIC_483, x=160, y=100
	video offset=CINEMATIC_438, x=160, y=100
	video offset=CINEMATIC_484, x=160, y=100
	video offset=CINEMATIC_485, x=160, y=100
	ret
	fill page=0x00, color=0x01
	video offset=CINEMATIC_462, x=160, y=100
	video offset=CINEMATIC_437, x=160, y=100
	ret

LABEL_9E63:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_461, x=160, y=100
	video offset=CINEMATIC_462, x=160, y=100
	video offset=CINEMATIC_438, x=160, y=100
	video offset=CINEMATIC_463, x=160, y=100
	video offset=CINEMATIC_464, x=160, y=100
	ret

LABEL_9E7B:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_461, x=160, y=100
	video offset=CINEMATIC_462, x=160, y=100
	video offset=CINEMATIC_438, x=160, y=100
	video offset=CINEMATIC_463, x=160, y=100
	video offset=CINEMATIC_464, x=160, y=100
	video offset=CINEMATIC_489, x=160, y=100
	ret

LABEL_9E97:
	fill page=0x00, color=0x01
	video offset=CINEMATIC_482, x=160, y=100
	video offset=CINEMATIC_483, x=160, y=100
	video offset=CINEMATIC_438, x=160, y=100
	video offset=CINEMATIC_484, x=160, y=100
	video offset=CINEMATIC_490, x=160, y=100
	video offset=CINEMATIC_491, x=160, y=100
	video offset=CINEMATIC_492, x=58, y=100
	ret
	fill page=0x00, color=0x01
	video offset=CINEMATIC_701, x=160, y=100
	video offset=CINEMATIC_702, x=160, y=100
	ret

LABEL_9EC3:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_493, x=160, y=100
	ret

LABEL_9ECB:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_512, x=160, y=100
	ret

LABEL_9ED3:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_527, x=160, y=100
	ret

LABEL_9EDB:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_622, x=160, y=100
	ret

LABEL_9EE3:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_575, x=188, y=99
	video offset=CINEMATIC_576, x=188, y=99
	ret

LABEL_9EEF:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_593, x=188, y=99
	ret

LABEL_9EF7:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_594, x=160, y=100
	ret

LABEL_9EFF:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_495, x=160, y=229, zoom=0x40
	video offset=CINEMATIC_496, x=160, y=100
	ret

LABEL_9F0C:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_621, x=160, y=100
	ret

LABEL_9F14:
	jg [0x22], 0xBE, SET_VAR22_TO_010E
	mov [0x22], 0x00B9
	jle [0x21], 0x0C, SHARED_RET
	jg [0x21], 0x25, SHARED_RET

SET_VAR22_TO_010E:
	mov [0x22], 0x010E
	ret
	jg [0x22], 0x96, SET_VAR22_TO_00B8
	mov [0x22], 0x0062
	jle [0x21], 0x60, SHARED_RET
