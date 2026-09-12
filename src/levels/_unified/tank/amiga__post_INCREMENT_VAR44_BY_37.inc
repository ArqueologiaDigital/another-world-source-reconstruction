TANK_CANNON_IMPACT_PLUME_LOOP:
	break
	je [0x45], 0x00, TANK_CANNON_IMPACT_PLUME_LOOP
	play id=0x008C, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_080, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_081, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_082, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_083, x=[0x42], y=[0x43], zoom=[0x44]
	je [0x57], 0x00, TANK_CANNON_IMPACT_SCORCH_TO_BACKGROUND
	jl [0x43], 0x69, TANK_CANNON_IMPACT_REARM_DONE

TANK_CANNON_IMPACT_SCORCH_TO_BACKGROUND:
	selectVideoPage 0x03
	video offset=CINEMATIC_084, x=[0x42], y=[0x43], zoom=[0x44]
	selectVideoPage 0xFF

TANK_CANNON_IMPACT_REARM_DONE:
	mov [0x45], 0x0000
	jmp TANK_CANNON_IMPACT_PLUME_LOOP
LABEL_10E0:
	db 0x11

TANK_GROUND_DEBRIS_WAIT_LOOP:
	break
	je [0x4F], 0x00, TANK_GROUND_DEBRIS_WAIT_LOOP
	sub [0x4F], 0x0001
