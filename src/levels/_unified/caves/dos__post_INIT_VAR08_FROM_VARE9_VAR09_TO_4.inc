LABEL_357F:
	mov [0x21], [0xE8]
	mov [0x22], [0x08]
	mov [0x23], [0xEC]
	add [0x23], [0x09]
	call LABEL_350E
	add [0x08], 0x0014
	djnz [0x09], LABEL_357F
	mov [0x21], [0xE8]
	mov [0x22], [0xE9]
	mov [0x23], [0xEC]
	add [0x22], 0x000A
	add [0x21], 0x0000
	call LABEL_350E
	break
	jmp INIT_VAR08_FROM_VARE9_VAR09_TO_4
LABEL_35AE:
	db 0x11

LABEL_35AF:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jne [0x6D], 0x00, LABEL_35C1
	video offset=CINEMATIC_818, x=[0x07], y=[0x08]
	ret

LABEL_35C1:
	jne [0x6D], 0x01, LABEL_35CD
	video offset=CINEMATIC_817, x=[0x07], y=[0x08]
	ret

LABEL_35CD:
	jne [0x6D], 0x02, LABEL_35D9
	video offset=CINEMATIC_816, x=[0x07], y=[0x08]
	ret

LABEL_35D9:
	jne [0x6D], 0x03, DRAW_CIN_814
	video offset=CINEMATIC_815, x=[0x07], y=[0x08]
	ret

DRAW_CIN_814:
	video offset=CINEMATIC_814, x=[0x07], y=[0x08]
	ret

GUARDED_DRAW_CIN_600_810:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x00
	video offset=CINEMATIC_600, x=[0x07], y=[0x08]
	video offset=CINEMATIC_810, x=[0x07], y=[0x08]
	selectVideoPage 0xFF
	add [0x07], 0x000B
	call LABEL_3620
	sub [0x07], 0x000B
	ret

LABEL_360B:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x03
	video offset=CINEMATIC_600, x=[0x07], y=[0x08]
	video offset=CINEMATIC_810, x=[0x07], y=[0x08]
	selectVideoPage 0xFF
	ret

LABEL_3620:
	jne [0x6D], 0x00, LABEL_362C
	video offset=CINEMATIC_812, x=[0x07], y=[0x08]
	ret

LABEL_362C:
	jne [0x6D], 0x01, LABEL_3638
	video offset=CINEMATIC_811, x=[0x07], y=[0x08]
	ret

LABEL_3638:
	jne [0x6D], 0x02, LABEL_3644
	video offset=CINEMATIC_813, x=[0x07], y=[0x08]
	ret

LABEL_3644:
	jne [0x6D], 0x03, DRAW_CIN_811
	video offset=CINEMATIC_812, x=[0x07], y=[0x08]
	ret

DRAW_CIN_811:
	video offset=CINEMATIC_811, x=[0x07], y=[0x08]
	ret

LABEL_3656:
	jg [HACK_VAR_67], [0x09], LABEL_3675
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jl [0x04], 0x4000, LABEL_366F
	mov [HERO_X], [0x07]
	jmp LABEL_3684

LABEL_366F:
	jl [HERO_X], [0x07], LABEL_3684

LABEL_3675:
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_250D
	mov [0x04], 0x4000
	jmp LABEL_1C56

LABEL_3684:
	jne [0x6D], 0x00, LABEL_3690
	video offset=CINEMATIC_809, x=[0x07], y=[0x08]
	ret

LABEL_3690:
	jne [0x6D], 0x01, LABEL_369C
	video offset=CINEMATIC_808, x=[0x07], y=[0x08]
	ret

LABEL_369C:
	jne [0x6D], 0x02, LABEL_36A8
	video offset=CINEMATIC_807, x=[0x07], y=[0x08]
	ret

LABEL_36A8:
	jne [0x6D], 0x03, DRAW_CIN_805
	video offset=CINEMATIC_806, x=[0x07], y=[0x08]
	ret

DRAW_CIN_805:
	video offset=CINEMATIC_805, x=[0x07], y=[0x08]
	ret

LABEL_36BA:
	break
	add [0x6D], 0x0001
	jl [0x6D], 0x05, LABEL_36BA
	mov [0x6D], 0x0000
	jmp LABEL_36BA
LABEL_36CC:
	db 0x11
