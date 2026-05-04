LABEL_6975:
	or [0x04], 0x4000
	mov [0x03], 0x0014
	setup channel=0x3F, address=LABEL_0184
	deleteChannels first=0x14, last=0x16
	mov [0x13], 0xFFFF
	mov [0xF8], [0x04]
	and [0xF8], 0x00FF
	play id=0x005D, freq=0x14, vol=0x40, channel=0x01
	jl [0xF8], 0x20, LABEL_69AF
	sub [0xF8], 0x0020
	setup channel=0x14, address=LABEL_4C69
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_4C84
	ret

LABEL_69AF:
	setup channel=0x14, address=LABEL_4B9E
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_4BC5
	ret

LABEL_69BE:
	call LABEL_6A32
	mov [0xF8], [0x2B]
	and [0xF8], 0x0800
	jne [0xF8], 0x00, LABEL_6A26
	play id=0x005D, freq=0x14, vol=0x40, channel=0x00
	call LABEL_1ACA
	mov [0xF8], [0x2B]
	and [0xF8], 0x1000
	jne [0x1D], 0x28, LABEL_69F2
	setup channel=0x23, address=LABEL_4D87
	je [0xF8], 0x00, LABEL_6A1A
	setup channel=0x23, address=LABEL_4DE0

LABEL_69F2:
	jne [0x1D], 0x29, LABEL_6A06
	setup channel=0x25, address=LABEL_4D87
	je [0xF8], 0x00, LABEL_6A1A
	setup channel=0x25, address=LABEL_4DE0

LABEL_6A06:
	jne [0x1D], 0x2A, LABEL_6A1A
	setup channel=0x27, address=LABEL_4D87
	je [0xF8], 0x00, LABEL_6A1A
	setup channel=0x27, address=LABEL_4DE0

LABEL_6A1A:
	or [0x2B], 0x0800
	call LABEL_6A51
	mov [0x13], 0xFFFF
	ret

LABEL_6A26:
	or [0x2B], 0x4000
	call LABEL_6A51
	mov [0x13], 0xFFFF
	ret

LABEL_6A32:
	jne [0x1D], 0x28, LABEL_6A3C
	mov [0x2B], [0x6B]
	ret

LABEL_6A3C:
	jne [0x1D], 0x29, LABEL_6A46
	mov [0x2B], [0x73]
	ret

LABEL_6A46:
	jne [0x1D], 0x2A, LABEL_6A4F
	mov [0x2B], [0x7B]

LABEL_6A4F:
	ret
LABEL_6A50:
	db 0x11

LABEL_6A51:
	jne [0x1D], 0x28, LABEL_6A5B
	mov [0x6B], [0x2B]
	ret

LABEL_6A5B:
	jne [0x1D], 0x29, LABEL_6A65
	mov [0x73], [0x2B]
	ret

LABEL_6A65:
	jne [0x1D], 0x2A, LABEL_6A6E
	mov [0x7B], [0x2B]

LABEL_6A6E:
	ret
	killChannel
	video type=1, offset=CINEMATIC_893, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_894, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	video type=1, offset=CINEMATIC_894, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=1, offset=CINEMATIC_895, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_895, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_894, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	mov [0x03], 0x0028

LABEL_6AAF:
	break
	video type=1, offset=CINEMATIC_896, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_6AAF
LABEL_6AB8:
	db 0x11

LABEL_6AB9:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_680C
	jne [0x13], 0xFFFF, LABEL_6ACB
	ret

LABEL_6ACB:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call LABEL_6B1B
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret
LABEL_6AE9:
	db 0x11

LABEL_6AEA:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_680C
	jne [0x13], 0xFFFF, LABEL_6AFD
	ret
LABEL_6AFC:
	db 0x11

LABEL_6AFD:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call LABEL_6C7C
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret

LABEL_6B1B:
	jge [0x13], 0x64, LABEL_6B67
	jle [0x13], 0x03, LABEL_6B49
	jle [0x13], 0x05, LABEL_6B37
	video type=1, offset=CINEMATIC_803, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6B37:
	jle [0x13], 0x04, DRAW_CIN_801
	video type=1, offset=CINEMATIC_802, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_801:
	video type=1, offset=CINEMATIC_801, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6B49:
	jle [0x13], 0x02, LABEL_6B55
	video type=1, offset=CINEMATIC_800, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6B55:
	jle [0x13], 0x01, DRAW_CIN_798
	video type=1, offset=CINEMATIC_799, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_798:
	video type=1, offset=CINEMATIC_798, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6B67:
	jge [0x13], 0xC8, LABEL_6C7A
	je [0x13], 0x64, LABEL_6E15
	je [0x13], 0x65, LABEL_6E35
	jge [0x13], 0x81, LABEL_6C04
	jne [0x13], 0x6E, LABEL_6B9A
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_227, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_797, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6B9A:
	jne [0x13], 0x6F, LABEL_6BA6
	video type=1, offset=CINEMATIC_796, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BA6:
	jne [0x13], 0x70, LABEL_6BB2
	video type=1, offset=CINEMATIC_795, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BB2:
	jne [0x13], 0x71, LABEL_6BBE
	video type=1, offset=CINEMATIC_794, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BBE:
	jne [0x13], 0x72, LABEL_6BCA
	video type=1, offset=CINEMATIC_793, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BCA:
	jne [0x13], 0x73, LABEL_6BD6
	video type=1, offset=CINEMATIC_792, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BD6:
	jne [0x13], 0x74, LABEL_6BE2
	video type=1, offset=CINEMATIC_791, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BE2:
	jne [0x13], 0x75, LABEL_6BEE
	video type=1, offset=CINEMATIC_790, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BEE:
	jne [0x13], 0x76, LABEL_6BFA
	video type=1, offset=CINEMATIC_789, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6BFA:
	video type=1, offset=CINEMATIC_788, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6C04:
	jne [0x13], 0x81, LABEL_6C16
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_787, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C16:
	jne [0x13], 0x82, LABEL_6C22
	video type=1, offset=CINEMATIC_786, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C22:
	jne [0x13], 0x83, LABEL_6C2E
	video type=1, offset=CINEMATIC_785, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C2E:
	jne [0x13], 0x84, LABEL_6C3A
	video type=1, offset=CINEMATIC_784, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C3A:
	jne [0x13], 0x85, LABEL_6C46
	video type=1, offset=CINEMATIC_783, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C46:
	jne [0x13], 0x86, LABEL_6C52
	video type=1, offset=CINEMATIC_782, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C52:
	jne [0x13], 0x87, LABEL_6C5E
	video type=1, offset=CINEMATIC_781, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C5E:
	jne [0x13], 0x88, LABEL_6C6A
	video type=1, offset=CINEMATIC_780, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6C6A:
	jne [0x13], 0x89, LABEL_6C7A
	video type=1, offset=CINEMATIC_779, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6C7A:
	ret
LABEL_6C7B:
	db 0x11

LABEL_6C7C:
	jge [0x13], 0x64, LABEL_6CC8
	jle [0x13], 0x03, LABEL_6CAA
	jle [0x13], 0x05, LABEL_6C98
	video type=1, offset=CINEMATIC_845, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6C98:
	jle [0x13], 0x04, DRAW_CIN_843
	video type=1, offset=CINEMATIC_844, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_843:
	video type=1, offset=CINEMATIC_843, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6CAA:
	jle [0x13], 0x02, LABEL_6CB6
	video type=1, offset=CINEMATIC_842, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6CB6:
	jle [0x13], 0x01, DRAW_CIN_840
	video type=1, offset=CINEMATIC_841, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_840:
	video type=1, offset=CINEMATIC_840, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6CC8:
	jge [0x13], 0xC8, LABEL_6DDB
	je [0x13], 0x64, LABEL_6DDD
	je [0x13], 0x65, LABEL_6DFD
	jge [0x13], 0x81, LABEL_6D65
	jne [0x13], 0x6E, LABEL_6CFB
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_227, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_797, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6CFB:
	jne [0x13], 0x6F, LABEL_6D07
	video type=1, offset=CINEMATIC_839, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D07:
	jne [0x13], 0x70, LABEL_6D13
	video type=1, offset=CINEMATIC_838, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D13:
	jne [0x13], 0x71, LABEL_6D1F
	video type=1, offset=CINEMATIC_837, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D1F:
	jne [0x13], 0x72, LABEL_6D2B
	video type=1, offset=CINEMATIC_836, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D2B:
	jne [0x13], 0x73, LABEL_6D37
	video type=1, offset=CINEMATIC_835, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D37:
	jne [0x13], 0x74, LABEL_6D43
	video type=1, offset=CINEMATIC_834, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D43:
	jne [0x13], 0x75, LABEL_6D4F
	video type=1, offset=CINEMATIC_833, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D4F:
	jne [0x13], 0x76, LABEL_6D5B
	video type=1, offset=CINEMATIC_832, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D5B:
	video type=1, offset=CINEMATIC_831, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6D65:
	jne [0x13], 0x81, LABEL_6D77
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_787, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D77:
	jne [0x13], 0x82, LABEL_6D83
	video type=1, offset=CINEMATIC_786, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D83:
	jne [0x13], 0x83, LABEL_6D8F
	video type=1, offset=CINEMATIC_785, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D8F:
	jne [0x13], 0x84, LABEL_6D9B
	video type=1, offset=CINEMATIC_784, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6D9B:
	jne [0x13], 0x85, LABEL_6DA7
	video type=1, offset=CINEMATIC_783, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6DA7:
	jne [0x13], 0x86, LABEL_6DB3
	video type=1, offset=CINEMATIC_782, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6DB3:
	jne [0x13], 0x87, LABEL_6DBF
	video type=1, offset=CINEMATIC_781, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6DBF:
	jne [0x13], 0x88, LABEL_6DCB
	video type=1, offset=CINEMATIC_780, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6DCB:
	jne [0x13], 0x89, LABEL_6DDB
	video type=1, offset=CINEMATIC_779, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6DDB:
	ret
LABEL_6DDC:
	db 0x11

LABEL_6DDD:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_7700
	call LABEL_6F4B
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_6E4D
	video type=1, offset=CINEMATIC_778, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_6DFD:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call LABEL_7700
	call LABEL_6F4B
	mov [0x2C], 0x0001
	jmp LABEL_6E4D
LABEL_6E14:
	db 0x11

LABEL_6E15:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_7700
	call LABEL_6F4B
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_6E4D
	video type=1, offset=CINEMATIC_778, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_6E35:
	mov [0x22], [0x21]
	add [0x22], 0x0190
	mov [0x09], [0x22]
	call LABEL_7700
	call LABEL_6F4B
	mov [0x2C], 0x0000
	jmp LABEL_6E4D
LABEL_6E4C:
	db 0x11

LABEL_6E4D:
	video type=1, offset=CINEMATIC_777, x=[0x22], y=[0x27], zoom=0x40
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_6FAB_AND_RET
	jl [0x1D], 0x14, LABEL_6EC7
	jl [0x1D], 0x1E, LABEL_6E8C
	je [0x1D], 0x1E, LABEL_6E9B
	jge [0x1D], 0x28, LABEL_6E7B

CALL_LABEL_6FAB_AND_RET:
	call LABEL_6FAB
	ret

LABEL_6E7B:
	call LABEL_69BE
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_6DFD
	jmp LABEL_6E35
LABEL_6E8B:
	db 0x05

LABEL_6E8C:
	call LABEL_6FAB
	call LABEL_6FBA
	mov [0x11], 0xFFFF
	call LABEL_7009
	ret
LABEL_6E9A:
	db 0x11

LABEL_6E9B:
	call LABEL_6975
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_6DFD
	jmp LABEL_6E35
LABEL_6EAB:
	db 0x05

LABEL_6EAC:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_6EF6
	jmp LABEL_6EE8
LABEL_6EC6:
	db 0x11

LABEL_6EC7:
	call LABEL_7036
	call LABEL_6FAB
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_6EAC
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_6EEF

LABEL_6EE8:
	and [0x11], 0xFDFF
	jmp LABEL_6F09

LABEL_6EEF:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_6EF6:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp LABEL_6F09
