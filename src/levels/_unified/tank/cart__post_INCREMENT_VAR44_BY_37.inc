TANK_CANNON_IMPACT_PLUME_LOOP:
	break
	je [0x45], 0x00, TANK_CANNON_IMPACT_PLUME_LOOP
	play id=0x008C, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_4, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_110, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_015, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_016, x=[0x42], y=[0x43], zoom=[0x44]
	je [0x57], 0x00, LABEL_14E5
	jl [0x43], 0x69, LABEL_14EF

LABEL_14E5:
	selectVideoPage 0x03
	video offset=CINEMATIC_TANK_CANNON_IMPACT_SCORCH_TO_BACKGROUND, x=[0x42], y=[0x43], zoom=[0x44]
	selectVideoPage 0xFF

LABEL_14EF:
	mov [0x45], 0x0000
	jmp TANK_CANNON_IMPACT_PLUME_LOOP
LABEL_14F6:
	db 0x11

LABEL_14F7:
	break
	je [0x4F], 0x00, LABEL_14F7
	sub [0x4F], 0x0001
