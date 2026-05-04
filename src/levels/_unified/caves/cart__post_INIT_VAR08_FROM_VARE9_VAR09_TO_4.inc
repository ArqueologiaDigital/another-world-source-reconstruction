LABEL_3563:
	mov [0x21], [0xE8]
	mov [0x22], [0x08]
	mov [0x23], [0xEC]
	add [0x23], [0x09]
	call LABEL_34F2
	add [0x08], 0x0014
	djnz [0x09], LABEL_3563
	mov [0x21], [0xE8]
	mov [0x22], [0xE9]
	mov [0x23], [0xEC]
	add [0x22], 0x000A
	add [0x21], 0x0000
	call LABEL_34F2
	break
	jmp INIT_VAR08_FROM_VARE9_VAR09_TO_4
LABEL_3592:
	db 0x11

LABEL_3593:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jne [0x6D], 0x00, LABEL_35A5
	video type=1, offset=CINEMATIC_809, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_35A5:
	jne [0x6D], 0x01, LABEL_35B1
	video type=1, offset=CINEMATIC_808, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_35B1:
	jne [0x6D], 0x02, LABEL_35BD
	video type=1, offset=CINEMATIC_807, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_35BD:
	jne [0x6D], 0x03, DRAW_CIN_805
	video type=1, offset=CINEMATIC_806, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_805:
	video type=1, offset=CINEMATIC_805, x=[0x07], y=[0x08], zoom=0x40
	ret

GUARDED_DRAW_CIN_589_801:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_589, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_801, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF
	add [0x07], 0x000B
	call LABEL_3604
	sub [0x07], 0x000B
	ret

LABEL_35EF:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_589, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_801, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_3604:
	jne [0x6D], 0x00, LABEL_3610
	video type=1, offset=CINEMATIC_803, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3610:
	jne [0x6D], 0x01, LABEL_361C
	video type=1, offset=CINEMATIC_802, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_361C:
	jne [0x6D], 0x02, LABEL_3628
	video type=1, offset=CINEMATIC_804, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3628:
	jne [0x6D], 0x03, DRAW_CIN_802
	video type=1, offset=CINEMATIC_803, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_802:
	video type=1, offset=CINEMATIC_802, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_363A:
	jg [HACK_VAR_67], [0x09], LABEL_3659
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jl [0x04], 0x4000, LABEL_3653
	mov [0x01], [0x07]
	jmp LABEL_3668

LABEL_3653:
	jl [0x01], [0x07], LABEL_3668

LABEL_3659:
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_24D4
	mov [0x04], 0x4000
	jmp LABEL_1C15

LABEL_3668:
	jne [0x6D], 0x00, LABEL_3674
	video type=1, offset=CINEMATIC_800, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3674:
	jne [0x6D], 0x01, LABEL_3680
	video type=1, offset=CINEMATIC_799, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3680:
	jne [0x6D], 0x02, LABEL_368C
	video type=1, offset=CINEMATIC_798, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_368C:
	jne [0x6D], 0x03, DRAW_CIN_796
	video type=1, offset=CINEMATIC_797, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_796:
	video type=1, offset=CINEMATIC_796, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_369E:
	break
	add [0x6D], 0x0001
	jl [0x6D], 0x05, LABEL_369E
	mov [0x6D], 0x0000
	jmp LABEL_369E
LABEL_36B0:
	db 0x11
