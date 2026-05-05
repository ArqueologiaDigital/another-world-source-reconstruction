DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	add [0x02], 0x0002
	break
	add [0x02], 0x0007
	mov [0x42], 0x00BC
	setup channel=0x34, address=HANG_DRAW_CIN_275
	mov [0x03], 0x0006

DELAY_LOOP_VAR03_AT_0601:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_0601
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_554, x=[0x01], y=[0x02], zoom=0x40
	mov [0x05], 0x0001
	mov [0x03], 0x0006

LABEL_061C:
	break
	call LABEL_6C9A
	djnz [0x03], LABEL_061C
	break
	video offset=CINEMATIC_555, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	mov [0x03], 0x0002

LABEL_0632:
	break
	sub [0x01], 0x0001
	call LABEL_6E5E
	mov [0x05], 0x0003
	djnz [0x03], LABEL_0632
	mov [0x03], 0x000F

LABEL_0646:
	break
	call LABEL_6E5E
	djnz [0x03], LABEL_0646
	mov [0x05], 0x0000
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_90C6
	setup channel=0x16, address=LABEL_8A67
	killChannel
