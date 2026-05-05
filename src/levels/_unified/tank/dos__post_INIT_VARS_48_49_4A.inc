LABEL_115C:
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0002
	break
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0001
	break
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	break
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	sub [0x49], 0x0001
	break
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	break
	video offset=CINEMATIC_178, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0001
	break
	djnz [0x4A], LABEL_115C
	video offset=CINEMATIC_179, x=160, y=100
	break
	video offset=CINEMATIC_180, x=160, y=100
	killChannel
