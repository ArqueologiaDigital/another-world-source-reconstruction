LABEL_05CA:
	break
	video type=1, offset=CINEMATIC_422, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_05CA
	break
	video type=1, offset=CINEMATIC_421, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_420, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_419, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_418, x=[0x01], y=[0x02], zoom=0x40
	mov [0x03], 0x0009

LABEL_05F0:
	break
	video type=1, offset=CINEMATIC_215, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_05F0
	break
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	break
	play id=0x0060, freq=0x14, vol=0x1E, channel=0x00
	call LABEL_6BED
	setup channel=0x15, address=INLINE_SET_VAR03_TO_7
	break
	jmp LABEL_93F4
LABEL_061C:
	db 0x11
