LABEL_1070:
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0002
	break
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0001
	break
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	break
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	sub [0x49], 0x0001
	break
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	break
	video offset=CINEMATIC_029, x=[0x48], y=[0x49]
	add [0x48], 0x0014
	add [0x49], 0x0001
	break
	djnz [0x4A], LABEL_1070
	video offset=CINEMATIC_030, x=160, y=100
	break
	video offset=CINEMATIC_031, x=160, y=100
	killChannel
