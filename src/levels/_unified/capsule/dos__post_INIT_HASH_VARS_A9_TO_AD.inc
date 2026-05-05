LABEL_9C15:
	db 0x11

LABEL_9C16:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_000, x=160, y=100
	video offset=CINEMATIC_001, x=160, y=100
	ret

LABEL_9C22:
	fill page=0x00, color=0x0B
	video offset=CINEMATIC_339, x=160, y=100
	video offset=CINEMATIC_340, x=65513, y=96, zoom=0x40
	ret
	video offset=CINEMATIC_001, x=160, y=100
