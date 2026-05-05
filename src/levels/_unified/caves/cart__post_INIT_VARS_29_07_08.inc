LABEL_47A5:
	break
	call LABEL_47F5
	break
	call LABEL_47F5
	add [0x07], 0x0003
	break
	call LABEL_4801
	break
	call LABEL_4801
	add [0x07], 0x0003
	break
	call LABEL_480D
	break
	call LABEL_480D
	add [0x07], 0x0002
	break
	call LABEL_4819
	break
	call LABEL_4819
	add [0x07], 0x0003
	break
	call LABEL_4825
	break
	call LABEL_4825
	add [0x07], 0x0003
	break
	call LABEL_4831
	break
	call LABEL_4831
	add [0x07], 0x0003
	jmp LABEL_47A5
	djnz [0x29], LABEL_47A5
	killChannel

LABEL_47F5:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4801:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_346, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_480D:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_347, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4819:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_348, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4825:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_349, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4831:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	ret
