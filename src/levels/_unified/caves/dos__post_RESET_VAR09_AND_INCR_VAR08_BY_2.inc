DISPATCH_VAR09_OR_KILL_CHAN:
	je [0x09], 0x01, LABEL_30E3
	je [0x09], 0x02, LABEL_30B2
	killChannel

LABEL_2F60:
	mov [0x09], 0x0000
	mov [0x21], [0x07]
	mov [0x22], [0x07]
	sub [0x21], 0x000A
	add [0x22], 0x000A
	jl [0x01], [0x21], SHARED_RET
	jg [0x01], [0x22], SHARED_RET
	mov [0x21], [0x08]
	mov [0x22], [0x08]
	add [0x22], 0x005A
	jl [0x02], [0x21], SHARED_RET
	jg [0x02], [0x22], SHARED_RET
	sub [0x22], 0x0014
	mov [0x09], 0x0002
	jl [0x02], [0x22], LABEL_2FBB
	je [0x63], 0x05, SHARED_RET
	je [0x63], 0x06, SHARED_RET
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET

LABEL_2FBB:
	mov [0x09], 0x0000
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	mov [0x09], 0x0001
	ret

LABEL_2FCF:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_718, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_719, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_720, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_721, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_722, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_723, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_724, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_725, x=[0x07], y=[0x08]
	break

LABEL_302F:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_712, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_713, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_714, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_715, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_716, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_717, x=[0x07], y=[0x08]
	break
	jmp LABEL_2FCF
LABEL_307A:
	db 0x11

LABEL_307B:
	video offset=CINEMATIC_684, x=[0x07], y=[0x08]
	mov [0x6C], [0x07]
	mov [0x6D], [0x08]
	add [0x6D], 0x0028
	break
	video offset=CINEMATIC_711, x=[0x07], y=[0x08]
	sub [0x6D], 0x000C
	break
	video offset=CINEMATIC_733, x=[0x07], y=[0x08]
	sub [0x6D], 0x000A
	break
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]
	sub [0x6D], 0x000A

LABEL_30A8:
	break
	video offset=CINEMATIC_681, x=[0x07], y=[0x08]
	jmp LABEL_30A8
LABEL_30B1:
	db 0x11

LABEL_30B2:
	video offset=CINEMATIC_682, x=[0x07], y=[0x08]
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_711, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_682, x=[0x07], y=[0x08]
	break
	jmp LABEL_2FCF
	killChannel
	video offset=CINEMATIC_733, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_734, x=[0x07], y=[0x08]

LABEL_30D9:
	break
	video offset=CINEMATIC_681, x=[0x07], y=[0x08]
	jmp LABEL_30D9
LABEL_30E2:
	db 0x11

LABEL_30E3:
	video offset=CINEMATIC_682, x=[0x07], y=[0x08]
	or [0x04], 0x4000
	break
	video offset=CINEMATIC_683, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_684, x=[0x07], y=[0x08]
	deleteChannels first=0x14, last=0x16
	break
	video offset=CINEMATIC_685, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_686, x=[0x07], y=[0x08]
	break
	jne [0xDB], 0x00, LABEL_3145
	video offset=CINEMATIC_702, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_703, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_704, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_705, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_706, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_707, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_708, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_709, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_710, x=[0x07], y=[0x08]
	break

LABEL_3145:
	video offset=CINEMATIC_687, x=[0x07], y=[0x08]
	jmp LABEL_0F73
	break
	jmp LABEL_3145
LABEL_3151:
	db 0x11

LABEL_3152:
	video offset=CINEMATIC_555, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_555, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_556, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_556, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=160, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=160, y=[0xe6]
	break
	jmp LABEL_3152
LABEL_3179:
	db 0x11

LABEL_317A:
	video offset=CINEMATIC_555, x=157, y=54
	break
	video offset=CINEMATIC_555, x=157, y=54
	break
	video offset=CINEMATIC_556, x=157, y=54
	break
	video offset=CINEMATIC_556, x=157, y=54
	break
	video offset=CINEMATIC_557, x=157, y=54
	break
	video offset=CINEMATIC_557, x=157, y=54
	break
	jmp LABEL_317A
LABEL_319B:
	db 0x11

LABEL_319C:
	video offset=CINEMATIC_555, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_555, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_556, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_556, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=140, y=[0xe6]
	break
	video offset=CINEMATIC_557, x=140, y=[0xe6]
	break
	jmp LABEL_319C
LABEL_31C3:
	db 0x11

HANG_DRAW_CIN_743_VAR09_GUARD:
	jne [0x09], 0x00, LABEL_2A60
	video offset=CINEMATIC_743, x=[0x07], y=[0x08]
	break
	jmp HANG_DRAW_CIN_743_VAR09_GUARD
LABEL_31D3:
	db 0x11

LABEL_31D4:
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_743, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_754, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_749, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_745, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_747, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_745, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_749, x=[0x07], y=[0x08]
	break
	jne [0x09], 0x02, LABEL_2A60
	video offset=CINEMATIC_754, x=[0x07], y=[0x08]
	break
	jmp LABEL_31D4
LABEL_323D:
	db 0x11

LABEL_323E:
	or [0x04], 0x4000
	video offset=CINEMATIC_743, x=[0x07], y=[0x08]
	deleteChannels first=0x14, last=0x16
	break
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_744, x=[0x07], y=[0x08]
	video offset=CINEMATIC_745, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_746, x=[0x07], y=[0x08]
	video offset=CINEMATIC_747, x=[0x07], y=[0x08]
	break
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	video offset=CINEMATIC_748, x=[0x07], y=[0x08]
	video offset=CINEMATIC_747, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_749, x=[0x07], y=[0x08]
	video offset=CINEMATIC_750, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_743, x=[0x07], y=[0x08]
	video offset=CINEMATIC_751, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_745, x=[0x07], y=[0x08]
	video offset=CINEMATIC_752, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_747, x=[0x07], y=[0x08]
	video offset=CINEMATIC_753, x=[0x07], y=[0x08]
	jmp LABEL_0F73
LABEL_32A7:
	db 0x11

LABEL_32A8:
	video offset=CINEMATIC_301, x=56, y=100
	video offset=CINEMATIC_302, x=58, y=103
	break
	video offset=CINEMATIC_302, x=56, y=100
	video offset=CINEMATIC_301, x=57, y=101
	break
	video offset=CINEMATIC_303, x=56, y=100
	video offset=CINEMATIC_303, x=59, y=102
	break
	jmp LABEL_32A8
LABEL_32C6:
	db 0x11

LABEL_32C7:
	video offset=CINEMATIC_301, x=56, y=110
	video offset=CINEMATIC_302, x=58, y=115
	break
	video offset=CINEMATIC_302, x=56, y=110
	video offset=CINEMATIC_301, x=57, y=113
	break
	video offset=CINEMATIC_303, x=56, y=110
	video offset=CINEMATIC_303, x=59, y=114
	break
	jmp LABEL_32C7
LABEL_32E5:
	db 0x11

LABEL_32E6:
	video offset=CINEMATIC_307, x=130, y=100
	video offset=CINEMATIC_308, x=230, y=100
	break
	video offset=CINEMATIC_309, x=130, y=100
	video offset=CINEMATIC_309, x=230, y=100
	break
	video offset=CINEMATIC_308, x=130, y=100
	video offset=CINEMATIC_307, x=230, y=100
	break
	jmp LABEL_32E6
LABEL_3304:
	db 0x11

LABEL_3305:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_330F:
	video offset=CINEMATIC_304, x=[0xee], y=100
	break
	video offset=CINEMATIC_305, x=[0xee], y=100
	break
	video offset=CINEMATIC_304, x=[0xee], y=100
	break
	video offset=CINEMATIC_306, x=[0xee], y=100
	break
	jmp LABEL_330F
LABEL_332A:
	db 0x11

LABEL_332B:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_3335:
	video offset=CINEMATIC_304, x=[0xee], y=89
	break
	video offset=CINEMATIC_305, x=[0xee], y=89
	break
	video offset=CINEMATIC_304, x=[0xee], y=89
	break
	video offset=CINEMATIC_306, x=[0xee], y=89
	break
	jmp LABEL_3335
LABEL_3350:
	db 0x11

LABEL_3351:
	mov [0xEF], 0x004B
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]
	video offset=CINEMATIC_304, x=[0xef], y=75
	break
	video offset=CINEMATIC_305, x=[0xef], y=75
	break
	video offset=CINEMATIC_411, x=[0xef], y=75
	break
	video offset=CINEMATIC_412, x=[0xef], y=75
	break
	video offset=CINEMATIC_413, x=[0xef], y=70
	break
	video offset=CINEMATIC_414, x=[0xef], y=80
	break
	video offset=CINEMATIC_413, x=[0xef], y=120
	video offset=CINEMATIC_305, x=[0xef], y=65
	break
	video offset=CINEMATIC_414, x=[0xef], y=140
	video offset=CINEMATIC_305, x=[0xef], y=60
	break
	video offset=CINEMATIC_414, x=[0xef], y=200
	break
	mov [0xEF], 0x0001
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]

DELAY_LOOP_VAREF:
	break
	djnz [0xEF], DELAY_LOOP_VAREF
	jmp LABEL_3351

LABEL_33AD:
	mov [0xEC], 0x0039
	mov [0xED], 0x0014
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEC], [0x3A]
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xED], [0x3E]
	video offset=CINEMATIC_310, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_311, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_312, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_313, x=[0xec], y=[0xed]
	break
	video offset=CINEMATIC_314, x=[0xec], y=[0xed]
	mov [0xEC], 0x000A

DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	jmp LABEL_33AD
LABEL_33EA:
	db 0x11
