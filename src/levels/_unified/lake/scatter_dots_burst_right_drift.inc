SCATTER_DOTS_BURST_RIGHT_SEQ:
	mov [0x9C], 0x0032

SCATTER_DOTS_BURST_RIGHT_DELAY:
	break
	djnz [0x9C], SCATTER_DOTS_BURST_RIGHT_DELAY
	mov [0x9A], 0x0054
	mov [0x9B], 0x005A
	mov [0x9C], 0x0015
	setup channel=0x36, address=PARTICLE_BURST_CYCLE_LOOP

SCATTER_DOTS_BURST_RIGHT_DRIFT:
	break
	add [0x9A], 0x0003
	djnz [0x9C], SCATTER_DOTS_BURST_RIGHT_DRIFT
	setup channel=0x36, address=KILL_CHANNEL_ROUTINE
	break
	break
	break
	break
	setup channel=0x36, address=PARTICLE_BURST_CYCLE_LOOP
	mov [0x9A], 0x009B
	mov [0x9C], 0x0010

SCATTER_DOTS_BURST_RIGHT_PHASE2:
	break
	add [0x9A], 0x0003
	break
	add [0x9A], 0x0003
	add [0x9B], 0x0001
	djnz [0x9C], SCATTER_DOTS_BURST_RIGHT_PHASE2
	mov [0x9C], 0x000A
	sub [0x9A], 0x0001
	sub [0x9B], 0x0001

SCATTER_DOTS_BURST_R_PHASE3:
	break
	add [0x9A], 0x0003
	djnz [0x9C], SCATTER_DOTS_BURST_R_PHASE3
	setup channel=0x36, address=KILL_CHANNEL_ROUTINE
	killChannel

