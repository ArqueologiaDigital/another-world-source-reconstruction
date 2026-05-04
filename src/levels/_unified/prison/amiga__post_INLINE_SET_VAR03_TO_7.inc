DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	add [0x02], 0x0002
	break
	add [0x02], 0x0007
	mov [0x42], 0x00BC
	setup channel=0x34, address=HANG_DRAW_CIN_275
	mov [0x03], 0x0006

DELAY_LOOP_VAR03_AT_063B:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_063B
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_554, x=[0x01], y=[0x02], zoom=0x40
	mov [0x05], 0x0001
	mov [0x03], 0x0006

LABEL_0656:
	break
	call LABEL_6BED
	djnz [0x03], LABEL_0656
	break
	video type=1, offset=CINEMATIC_555, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	mov [0x03], 0x0002

LABEL_066C:
	break
	sub [0x01], 0x0001
	call LABEL_6DB1
	mov [0x05], 0x0003
	djnz [0x03], LABEL_066C
	mov [0x03], 0x000F

LABEL_0680:
	break
	call LABEL_6DB1
	djnz [0x03], LABEL_0680
	mov [0x05], 0x0000
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_8F00
	setup channel=0x16, address=LABEL_8944
	killChannel
