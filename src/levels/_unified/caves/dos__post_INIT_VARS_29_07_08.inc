LABEL_48E8:
	break
	call LABEL_4938
	break
	call LABEL_4938
	add [0x07], 0x0003
	break
	call LABEL_4944
	break
	call LABEL_4944
	add [0x07], 0x0003
	break
	call LABEL_4950
	break
	call LABEL_4950
	add [0x07], 0x0002
	break
	call LABEL_495C
	break
	call LABEL_495C
	add [0x07], 0x0003
	break
	call LABEL_4968
	break
	call LABEL_4968
	add [0x07], 0x0003
	break
	call LABEL_4974
	break
	call LABEL_4974
	add [0x07], 0x0003
	jmp LABEL_48E8
	djnz [0x29], LABEL_48E8
	killChannel

LABEL_4938:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4944:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_346, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4950:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_347, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_495C:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_348, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4968:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_349, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_4974:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	ret
