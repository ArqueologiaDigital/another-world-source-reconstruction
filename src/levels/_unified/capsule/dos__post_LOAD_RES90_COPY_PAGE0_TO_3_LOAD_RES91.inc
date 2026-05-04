LABEL_9C3E:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_522, x=160, y=100
	video type=1, offset=CINEMATIC_523, x=160, y=100
	video type=1, offset=CINEMATIC_524, x=160, y=100
	video type=1, offset=CINEMATIC_525, x=160, y=100
	ret

LABEL_9C52:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_522, x=160, y=100
	video type=1, offset=CINEMATIC_551, x=160, y=100
	video type=1, offset=CINEMATIC_552, x=160, y=100
	video type=1, offset=CINEMATIC_553, x=160, y=100
	video type=1, offset=CINEMATIC_554, x=160, y=100
	ret
	video type=1, offset=CINEMATIC_698, x=160, y=100
	video type=1, offset=CINEMATIC_699, x=160, y=100
	ret
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_522, x=160, y=100
	video type=1, offset=CINEMATIC_551, x=160, y=100
	video type=1, offset=CINEMATIC_552, x=160, y=100
	video type=1, offset=CINEMATIC_553, x=160, y=100
	video type=1, offset=CINEMATIC_554, x=160, y=100
	ret

LABEL_9C8B:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_562, x=160, y=198
	video type=1, offset=CINEMATIC_563, x=160, y=198
	video type=1, offset=CINEMATIC_564, x=160, y=100
	video type=1, offset=CINEMATIC_565, x=160, y=100
	ret

LABEL_9C9F:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_568, x=160, y=100
	ret

LABEL_9CA7:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_495, x=160, y=100
	ret

LABEL_9CAF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_559, x=160, y=100
	video type=1, offset=CINEMATIC_560, x=160, y=100
	video type=1, offset=CINEMATIC_558, x=160, y=100
	ret

LABEL_9CBF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_555, x=155, y=95
	video type=1, offset=CINEMATIC_556, x=160, y=100
	ret

LABEL_9CCB:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_562, x=160, y=151
	video type=1, offset=CINEMATIC_611, x=160, y=100
	ret

LABEL_9CD7:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_500, x=160, y=100
	video type=1, offset=CINEMATIC_501, x=160, y=100
	ret

LABEL_9CE3:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_506, x=160, y=100
	video type=1, offset=CINEMATIC_507, x=160, y=100
	video type=1, offset=CINEMATIC_508, x=160, y=100
	ret

LABEL_9CF3:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_571, x=160, y=100
	video type=1, offset=CINEMATIC_572, x=160, y=100
	ret

LABEL_9CFF:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_562, x=160, y=187
	video type=1, offset=CINEMATIC_575, x=160, y=100
	ret

LABEL_9D0B:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_555, x=160, y=23
	video type=1, offset=CINEMATIC_592, x=160, y=50
	mov [0xF8], [0xB9]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, DRAW_CIN_591_THEN_CIN_345
	video type=1, offset=CINEMATIC_587, x=232, y=65
	video type=1, offset=CINEMATIC_591, x=151, y=14
	ret

DRAW_CIN_591_THEN_CIN_345:
	video type=1, offset=CINEMATIC_591, x=151, y=65496, zoom=0x40
	video type=1, offset=CINEMATIC_345, x=6, y=99
	ret

LABEL_9D37:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_555, x=160, y=23
	video type=1, offset=CINEMATIC_586, x=160, y=100
	video type=1, offset=CINEMATIC_587, x=74, y=64
	video type=1, offset=CINEMATIC_588, x=74, y=64
	video type=1, offset=CINEMATIC_589, x=74, y=64
	video type=1, offset=CINEMATIC_587, x=191, y=65
	video type=1, offset=CINEMATIC_588, x=191, y=65
	video type=1, offset=CINEMATIC_589, x=191, y=65
	video type=1, offset=CINEMATIC_587, x=295, y=64, zoom=0x40
	video type=1, offset=CINEMATIC_588, x=295, y=64, zoom=0x40
	video type=1, offset=CINEMATIC_590, x=295, y=64, zoom=0x40
	video type=1, offset=CINEMATIC_591, x=65528, y=15, zoom=0x40
	video type=1, offset=CINEMATIC_591, x=107, y=14
	video type=1, offset=CINEMATIC_591, x=212, y=15
	call LABEL_369F
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

LABEL_9DC3:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_432, x=160, y=100
	video type=1, offset=CINEMATIC_433, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_435, x=160, y=100
	ret

JUNK__9DD7:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_478, x=160, y=100
	video type=1, offset=CINEMATIC_479, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_696, x=160, y=100
	video type=1, offset=CINEMATIC_697, x=160, y=100
	ret
	video type=1, offset=CINEMATIC_695, x=160, y=100

LABEL_9DF3:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_478, x=160, y=100
	video type=1, offset=CINEMATIC_479, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_480, x=160, y=100
	video type=1, offset=CINEMATIC_481, x=160, y=100
	ret

LABEL_9E0B:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_485, x=160, y=100
	ret
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_458, x=160, y=100
	video type=1, offset=CINEMATIC_433, x=160, y=100
	ret

LABEL_9E1F:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_457, x=160, y=100
	video type=1, offset=CINEMATIC_458, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_459, x=160, y=100
	video type=1, offset=CINEMATIC_460, x=160, y=100
	ret

LABEL_9E37:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_457, x=160, y=100
	video type=1, offset=CINEMATIC_458, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_459, x=160, y=100
	video type=1, offset=CINEMATIC_460, x=160, y=100
	video type=1, offset=CINEMATIC_486, x=160, y=100
	ret
	video type=1, offset=CINEMATIC_694, x=4, y=65518, zoom=0x40

LABEL_9E59:
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_478, x=160, y=100
	video type=1, offset=CINEMATIC_479, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_480, x=160, y=100
	video type=1, offset=CINEMATIC_487, x=160, y=100
	video type=1, offset=CINEMATIC_488, x=160, y=100
	video type=1, offset=CINEMATIC_489, x=58, y=100
	ret
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_692, x=160, y=100
	video type=1, offset=CINEMATIC_693, x=160, y=100
	ret

LABEL_9E85:
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_490, x=160, y=100
	ret

LABEL_9E8D:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_509, x=160, y=100
	ret

LABEL_9E95:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_521, x=160, y=100
	ret

LABEL_9E9D:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_613, x=160, y=100
	ret

LABEL_9EA5:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_566, x=188, y=99
	video type=1, offset=CINEMATIC_567, x=188, y=99
	ret

LABEL_9EB1:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_584, x=188, y=99
	ret

LABEL_9EB9:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_585, x=160, y=100
	ret

LABEL_9EC1:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_492, x=160, y=229, zoom=0x40
	video type=1, offset=CINEMATIC_493, x=160, y=100
	ret

LABEL_9ECE:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_612, x=160, y=100
	ret

LABEL_9ED6:
	mov [0x22], 0x00B9
	jle [0x21], 0x0C, SHARED_RET
	jg [0x21], 0x25, SHARED_RET
	mov [0x22], 0x010E
	ret
	jg [0x22], 0x96, SET_VAR22_TO_00B8
	mov [0x22], 0x0062
	jle [0x21], 0x60, SHARED_RET
