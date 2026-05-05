DISPATCH_VAR09_OR_KILL_CHAN:
	je [0x09], 0x01, LABEL_2EC0
	je [0x09], 0x02, LABEL_2E8F
	killChannel

LABEL_2D3D:
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
	jl [0x02], [0x22], LABEL_2D98
	je [0x63], 0x05, SHARED_RET
	je [0x63], 0x06, SHARED_RET
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET

LABEL_2D98:
	mov [0x09], 0x0000
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	mov [0x09], 0x0001
	ret

LABEL_2DAC:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_697, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_698, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_699, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_700, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_701, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_702, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_703, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_704, x=[0x07], y=[0x08], zoom=0x40
	break

LABEL_2E0C:
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_691, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_692, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_693, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_694, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_695, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x00, DISPATCH_VAR09_OR_KILL_CHAN
	video offset=CINEMATIC_696, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_2DAC
LABEL_2E57:
	db 0x11

LABEL_2E58:
	video offset=CINEMATIC_663, x=[0x07], y=[0x08], zoom=0x40
	mov [0x6C], [0x07]
	mov [0x6D], [0x08]
	add [0x6D], 0x0028
	break
	video offset=CINEMATIC_690, x=[0x07], y=[0x08], zoom=0x40
	sub [0x6D], 0x000C
	break
	video offset=CINEMATIC_712, x=[0x07], y=[0x08], zoom=0x40
	sub [0x6D], 0x000A
	break
	video offset=CINEMATIC_713, x=[0x07], y=[0x08], zoom=0x40
	sub [0x6D], 0x000A

LABEL_2E85:
	break
	video offset=CINEMATIC_660, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_2E85
LABEL_2E8E:
	db 0x11

LABEL_2E8F:
	video offset=CINEMATIC_661, x=[0x07], y=[0x08], zoom=0x40
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_690, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_661, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_2DAC
LABEL_2EAA:
	db 0x11, 0x54, 0x44, 0x7F, 0x07, 0x08, 0x06, 0x54
	db 0x44, 0xB4, 0x07, 0x08, 0x06, 0x54, 0x44, 0xE7
	db 0x07, 0x08, 0x07, 0x2E, 0xB6, 0x11

LABEL_2EC0:
	video offset=CINEMATIC_661, x=[0x07], y=[0x08], zoom=0x40
	or [0x04], 0x4000
	break
	video offset=CINEMATIC_662, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_663, x=[0x07], y=[0x08], zoom=0x40
	deleteChannels first=0x14, last=0x16
	break
	video offset=CINEMATIC_664, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_665, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_666, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_667, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_668, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_669, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_670, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_671, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_672, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_673, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_674, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_675, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_0F52
LABEL_2F24:
	db 0x06, 0x07, 0x2F, 0x1C, 0x11

LABEL_2F29:
	video offset=CINEMATIC_534, x=160, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_534, x=160, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_535, x=160, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_535, x=160, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_536, x=160, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_536, x=160, y=[0xe6], zoom=0x40
	break
	jmp LABEL_2F29
LABEL_2F50:
	db 0x11

LABEL_2F51:
	video offset=CINEMATIC_534, x=157, y=54
	break
	video offset=CINEMATIC_534, x=157, y=54
	break
	video offset=CINEMATIC_535, x=157, y=54
	break
	video offset=CINEMATIC_535, x=157, y=54
	break
	video offset=CINEMATIC_536, x=157, y=54
	break
	video offset=CINEMATIC_536, x=157, y=54
	break
	jmp LABEL_2F51
LABEL_2F72:
	db 0x11

LABEL_2F73:
	video offset=CINEMATIC_534, x=140, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_534, x=140, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_535, x=140, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_535, x=140, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_536, x=140, y=[0xe6], zoom=0x40
	break
	video offset=CINEMATIC_536, x=140, y=[0xe6], zoom=0x40
	break
	jmp LABEL_2F73
LABEL_2F9A:
	db 0x11

LABEL_2F9B:
	jne [0x09], 0x00, LABEL_285F
	video offset=CINEMATIC_722, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_2F9B
LABEL_2FAA:
	db 0x11

LABEL_2FAB:
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_722, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_733, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_728, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_724, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_726, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_724, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_728, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x09], 0x02, LABEL_285F
	video offset=CINEMATIC_733, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_2FAB
LABEL_3014:
	db 0x11

LABEL_3015:
	or [0x04], 0x4000
	video offset=CINEMATIC_722, x=[0x07], y=[0x08], zoom=0x40
	deleteChannels first=0x14, last=0x16
	break
	play id=0x007C, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_723, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_724, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_725, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_726, x=[0x07], y=[0x08], zoom=0x40
	break
	play id=0x007C, freq=0x0F, vol=0x20, channel=0x01
	video offset=CINEMATIC_727, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_726, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_728, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_729, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_722, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_730, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_724, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_731, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_726, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_732, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_0F52
LABEL_307E:
	db 0x11

LABEL_307F:
	video offset=CINEMATIC_280, x=56, y=100
	video offset=CINEMATIC_281, x=58, y=103
	break
	video offset=CINEMATIC_281, x=56, y=100
	video offset=CINEMATIC_280, x=57, y=101
	break
	video offset=CINEMATIC_282, x=56, y=100
	video offset=CINEMATIC_282, x=59, y=102
	break
	jmp LABEL_307F
LABEL_309D:
	db 0x11

LABEL_309E:
	video offset=CINEMATIC_280, x=56, y=110
	video offset=CINEMATIC_281, x=58, y=115
	break
	video offset=CINEMATIC_281, x=56, y=110
	video offset=CINEMATIC_280, x=57, y=113
	break
	video offset=CINEMATIC_282, x=56, y=110
	video offset=CINEMATIC_282, x=59, y=114
	break
	jmp LABEL_309E
LABEL_30BC:
	db 0x11

LABEL_30BD:
	video offset=CINEMATIC_286, x=130, y=100
	video offset=CINEMATIC_287, x=230, y=100
	break
	video offset=CINEMATIC_288, x=130, y=100
	video offset=CINEMATIC_288, x=230, y=100
	break
	video offset=CINEMATIC_287, x=130, y=100
	video offset=CINEMATIC_286, x=230, y=100
	break
	jmp LABEL_30BD
LABEL_30DB:
	db 0x11

LABEL_30DC:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_30E6:
	video offset=CINEMATIC_283, x=[0xee], y=100, zoom=0x40
	break
	video offset=CINEMATIC_284, x=[0xee], y=100, zoom=0x40
	break
	video offset=CINEMATIC_283, x=[0xee], y=100, zoom=0x40
	break
	video offset=CINEMATIC_285, x=[0xee], y=100, zoom=0x40
	break
	jmp LABEL_30E6
LABEL_3101:
	db 0x11

LABEL_3102:
	mov [0xEE], 0x0050
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEE], [0x3E]

LABEL_310C:
	video offset=CINEMATIC_283, x=[0xee], y=89, zoom=0x40
	break
	video offset=CINEMATIC_284, x=[0xee], y=89, zoom=0x40
	break
	video offset=CINEMATIC_283, x=[0xee], y=89, zoom=0x40
	break
	video offset=CINEMATIC_285, x=[0xee], y=89, zoom=0x40
	break
	jmp LABEL_310C
LABEL_3127:
	db 0x11

LABEL_3128:
	mov [0xEF], 0x004B
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]
	video offset=CINEMATIC_283, x=[0xef], y=75, zoom=0x40
	break
	video offset=CINEMATIC_284, x=[0xef], y=75, zoom=0x40
	break
	video offset=CINEMATIC_390, x=[0xef], y=75, zoom=0x40
	break
	video offset=CINEMATIC_391, x=[0xef], y=75, zoom=0x40
	break
	video offset=CINEMATIC_392, x=[0xef], y=70, zoom=0x40
	break
	video offset=CINEMATIC_393, x=[0xef], y=80, zoom=0x40
	break
	video offset=CINEMATIC_392, x=[0xef], y=120, zoom=0x40
	video offset=CINEMATIC_284, x=[0xef], y=65, zoom=0x40
	break
	video offset=CINEMATIC_393, x=[0xef], y=140, zoom=0x40
	video offset=CINEMATIC_284, x=[0xef], y=60, zoom=0x40
	break
	video offset=CINEMATIC_393, x=[0xef], y=200, zoom=0x40
	break
	mov [0xEF], 0x0001
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEF], [0x3B]

DELAY_LOOP_VAREF:
	break
	djnz [0xEF], DELAY_LOOP_VAREF
	jmp LABEL_3128

LABEL_3184:
	mov [0xEC], 0x0039
	mov [0xED], 0x0014
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xEC], [0x3A]
	call SETUP_HASH_AND_DERIVE_BUCKETS
	add [0xED], [0x3E]
	video offset=CINEMATIC_289, x=[0xec], y=[0xed], zoom=0x40
	break
	video offset=CINEMATIC_290, x=[0xec], y=[0xed], zoom=0x40
	break
	video offset=CINEMATIC_291, x=[0xec], y=[0xed], zoom=0x40
	break
	video offset=CINEMATIC_292, x=[0xec], y=[0xed], zoom=0x40
	break
	video offset=CINEMATIC_293, x=[0xec], y=[0xed], zoom=0x40
	mov [0xEC], 0x000A

DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	jmp LABEL_3184
LABEL_31C1:
	db 0x11
