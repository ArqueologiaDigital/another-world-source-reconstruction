;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_PARTICLE_BURST_0		EQU 0xDD0A
CINEMATIC_PARTICLE_BURST_1		EQU 0xDD1A
CINEMATIC_PARTICLE_BURST_2		EQU 0xDD32
CINEMATIC_PARTICLE_BURST_3		EQU 0xDD46
CINEMATIC_PARTICLE_BURST_4		EQU 0xDD5E
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_PARTICLE_BURST_0		EQU 0xF11A
CINEMATIC_PARTICLE_BURST_1		EQU 0xF12A
CINEMATIC_PARTICLE_BURST_2		EQU 0xF142
CINEMATIC_PARTICLE_BURST_3		EQU 0xF156
CINEMATIC_PARTICLE_BURST_4		EQU 0xF16E
;@endif

PARTICLE_BURST_CYCLE_LOOP:
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x9a], y=[0x9b]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9a], y=[0x9b]
	break
	jmp PARTICLE_BURST_CYCLE_LOOP
	killChannel
;@if BRANCH in ("chahi_amiga_1991", "cartridge_1992")

PARTICLE_BURST_3X_LOOP:
;@elif BRANCH in ("dos_1992", "gba_2004")
PARTICLE_BURST_3X_LOOP:
;@endif
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x98], y=[0x99]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x98], y=[0x99]
	break
	jmp PARTICLE_BURST_3X_LOOP
	killChannel

PARTICLE_BURST_7X_ENTRY:
	jmp PARTICLE_BURST_7X_INIT_POS
	video offset=CINEMATIC_PARTICLE_BURST_0, x=212, y=121
	video offset=CINEMATIC_PARTICLE_BURST_1, x=186, y=113
	video offset=CINEMATIC_PARTICLE_BURST_2, x=202, y=102
	video offset=CINEMATIC_PARTICLE_BURST_0, x=225, y=115
	video offset=CINEMATIC_PARTICLE_BURST_1, x=248, y=113
	video offset=CINEMATIC_PARTICLE_BURST_4, x=220, y=106
	video offset=CINEMATIC_PARTICLE_BURST_3, x=153, y=91

PARTICLE_BURST_7X_INIT_POS:
	mov [0x94], 0x00D4
	mov [0x95], 0x0079
	mov [0x96], 0x00BA
	mov [0x97], 0x0071
	mov [0x98], 0x00CA
	mov [0x99], 0x0066
	mov [0x9A], 0x00E1
	mov [0x9B], 0x0073
	mov [0x9C], 0x00F8
	mov [0x9D], 0x0071
	mov [0x9E], 0x00DC
	mov [0x9F], 0x006A
	mov [0xA0], 0x0099
	mov [0xA1], 0x005B
	mov [0x91], 0x0064

PARTICLE_BURST_7X_DRIFT_TICK:
	add [0x94], 0x0002
	add [0x96], 0x0003
	add [0x98], 0x0003
	add [0x9A], 0x0002
	add [0x9C], 0x0003
	add [0x9E], 0x0002
	add [0xA0], 0x0003
	break
	djnz [0x91], PARTICLE_BURST_7X_DRIFT_TICK
	setup channel=0x38, address=KILL_CHANNEL_ROUTINE
	killChannel

PARTICLE_BURST_7X_LOOP:
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_4, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0xa0], y=[0xa1]
	break
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0x94], y=[0x95]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x96], y=[0x97]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x98], y=[0x99]
	video offset=CINEMATIC_PARTICLE_BURST_2, x=[0x9a], y=[0x9b]
	video offset=CINEMATIC_PARTICLE_BURST_1, x=[0x9c], y=[0x9d]
	video offset=CINEMATIC_PARTICLE_BURST_0, x=[0x9e], y=[0x9f]
	video offset=CINEMATIC_PARTICLE_BURST_3, x=[0xa0], y=[0xa1]
	break
	jmp PARTICLE_BURST_7X_LOOP
	killChannel

DROPLET_DRIP_LOOP_RANDOM_X:
	break
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x82], 0x00AC
	add [0x82], [0x3B]
	mov [0x83], 0x0087
	mov [0x84], 0x0003

DROPLET_DRIP_NEW_ROW:
	mov [0x85], 0x0005

DROPLET_DRIP_FRAME_REPEAT:
	video offset=CINEMATIC_DROPLET_FALL_TRAIL, x=[0x82], y=[0x83]
	break
	djnz [0x85], DROPLET_DRIP_FRAME_REPEAT
	sub [0x83], 0x0001
	djnz [0x84], DROPLET_DRIP_NEW_ROW
	jmp DROPLET_DRIP_LOOP_RANDOM_X
	killChannel

