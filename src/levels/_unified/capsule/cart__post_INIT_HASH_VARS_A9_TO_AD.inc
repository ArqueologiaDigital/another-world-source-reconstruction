LABEL_9C86:
	db 0x11

LABEL_9C87:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_001, x=160, y=100
	ret


LABEL_9C93:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_CAPSULE_SCREEN_6B_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_341, x=65513, y=96
	ret


	video offset=CINEMATIC_001, x=160, y=100
