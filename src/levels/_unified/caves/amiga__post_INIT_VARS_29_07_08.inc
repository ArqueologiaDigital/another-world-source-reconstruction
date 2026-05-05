LABEL_45D7:
	break
	call LABEL_4627
	break
	call LABEL_4627
	add [0x07], 0x0003
	break
	call LABEL_4633
	break
	call LABEL_4633
	add [0x07], 0x0003
	break
	call LABEL_463F
	break
	call LABEL_463F
	add [0x07], 0x0002
	break
	call LABEL_464B
	break
	call LABEL_464B
	add [0x07], 0x0003
	break
	call LABEL_4657
	break
	call LABEL_4657
	add [0x07], 0x0003
	break
	call LABEL_4663
	break
	call LABEL_4663
	add [0x07], 0x0003
	jmp LABEL_45D7
LABEL_4622:
	db 0x09, 0x29, 0x45, 0xD7, 0x11

LABEL_4627:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_323, x=[0x07], y=[0x08]
	ret

LABEL_4633:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_325, x=[0x07], y=[0x08]
	ret

LABEL_463F:
	jne [0x10], [HACK_VAR_67], INCREMENT_VAR07_BY_4
	video offset=CINEMATIC_326, x=[0x07], y=[0x08]
	ret

LABEL_464B:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_327, x=[0x07], y=[0x08]
	ret

LABEL_4657:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_328, x=[0x07], y=[0x08]
	ret

LABEL_4663:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_329, x=[0x07], y=[0x08]
	ret
