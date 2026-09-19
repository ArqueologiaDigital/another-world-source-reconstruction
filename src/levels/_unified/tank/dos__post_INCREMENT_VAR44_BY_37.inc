TANK_CANNON_IMPACT_PLUME_LOOP:
	break
	je [0x45], 0x00, TANK_CANNON_IMPACT_PLUME_LOOP
	play id=0x008C, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_082, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_083, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_084, x=[0x42], y=[0x43], zoom=[0x44]
	break
	video offset=CINEMATIC_085, x=[0x42], y=[0x43], zoom=[0x44]
	je [0x57], 0x00, TANK_CANNON_IMPACT_SCORCH_TO_BACKGROUND
	jl [0x43], 0x69, TANK_CANNON_IMPACT_REARM_DONE

TANK_CANNON_IMPACT_SCORCH_TO_BACKGROUND:
	selectVideoPage 0x03
	video offset=CINEMATIC_086, x=[0x42], y=[0x43], zoom=[0x44]
	selectVideoPage 0xFF

TANK_CANNON_IMPACT_REARM_DONE:
	mov [0x45], 0x0000
	jmp TANK_CANNON_IMPACT_PLUME_LOOP
LABEL_15E2:
	db 0x11

; `break; if var4F == 0: loop; else sub var4F-=1`. A
; counter-based delay — yields a frame and tries again
; until var4F is non-zero, then decrements it. Different
; semantics from 17AB: this one DECREMENTS the counter on
; exit (consuming the trigger), 17AB just LEAVES the
; trigger for the caller to consume.
TANK_GROUND_DEBRIS_WAIT_LOOP:
	break
	je [0x4F], 0x00, TANK_GROUND_DEBRIS_WAIT_LOOP
	sub [0x4F], 0x0001
