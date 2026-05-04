LABEL_605A:
	video type=1, offset=CINEMATIC_706, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_707, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	video type=1, offset=CINEMATIC_707, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=1, offset=CINEMATIC_708, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_708, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_707, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	mov [0x03], 0x0028

LABEL_6099:
	break
	video type=1, offset=CINEMATIC_709, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_6099
LABEL_60A2:
	db 0x11

LABEL_60A3:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_5DFF
	jne [0x13], 0xFFFF, LABEL_60B5
	ret

LABEL_60B5:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call LABEL_6105
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret
LABEL_60D3:
	db 0x11

LABEL_60D4:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_5DFF
	jne [0x13], 0xFFFF, LABEL_60E7
	ret
LABEL_60E6:
	db 0x11

LABEL_60E7:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call LABEL_6266
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret

LABEL_6105:
	jge [0x13], 0x64, LABEL_6151
	jle [0x13], 0x03, LABEL_6133
	jle [0x13], 0x05, LABEL_6121
	video type=1, offset=CINEMATIC_652, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6121:
	jle [0x13], 0x04, DRAW_CIN_650
	video type=1, offset=CINEMATIC_651, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_650:
	video type=1, offset=CINEMATIC_650, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6133:
	jle [0x13], 0x02, LABEL_613F
	video type=1, offset=CINEMATIC_649, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_613F:
	jle [0x13], 0x01, DRAW_CIN_647
	video type=1, offset=CINEMATIC_648, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_647:
	video type=1, offset=CINEMATIC_647, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6151:
	jge [0x13], 0xC8, LABEL_6264
	je [0x13], 0x64, LABEL_63FF
	je [0x13], 0x65, LABEL_641F
	jge [0x13], 0x81, LABEL_61EE
	jne [0x13], 0x6E, LABEL_6184
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_499, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_646, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6184:
	jne [0x13], 0x6F, LABEL_6190
	video type=1, offset=CINEMATIC_645, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6190:
	jne [0x13], 0x70, LABEL_619C
	video type=1, offset=CINEMATIC_644, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_619C:
	jne [0x13], 0x71, LABEL_61A8
	video type=1, offset=CINEMATIC_643, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61A8:
	jne [0x13], 0x72, LABEL_61B4
	video type=1, offset=CINEMATIC_642, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61B4:
	jne [0x13], 0x73, LABEL_61C0
	video type=1, offset=CINEMATIC_641, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61C0:
	jne [0x13], 0x74, LABEL_61CC
	video type=1, offset=CINEMATIC_640, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61CC:
	jne [0x13], 0x75, LABEL_61D8
	video type=1, offset=CINEMATIC_639, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61D8:
	jne [0x13], 0x76, LABEL_61E4
	video type=1, offset=CINEMATIC_638, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61E4:
	video type=1, offset=CINEMATIC_637, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_61EE:
	jne [0x13], 0x81, LABEL_6200
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_636, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6200:
	jne [0x13], 0x82, LABEL_620C
	video type=1, offset=CINEMATIC_635, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_620C:
	jne [0x13], 0x83, LABEL_6218
	video type=1, offset=CINEMATIC_634, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6218:
	jne [0x13], 0x84, LABEL_6224
	video type=1, offset=CINEMATIC_633, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6224:
	jne [0x13], 0x85, LABEL_6230
	video type=1, offset=CINEMATIC_632, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6230:
	jne [0x13], 0x86, LABEL_623C
	video type=1, offset=CINEMATIC_631, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_623C:
	jne [0x13], 0x87, LABEL_6248
	video type=1, offset=CINEMATIC_630, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6248:
	jne [0x13], 0x88, LABEL_6254
	video type=1, offset=CINEMATIC_629, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6254:
	jne [0x13], 0x89, LABEL_6264
	video type=1, offset=CINEMATIC_628, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6264:
	ret
LABEL_6265:
	db 0x11

LABEL_6266:
	jge [0x13], 0x64, LABEL_62B2
	jle [0x13], 0x03, LABEL_6294
	jle [0x13], 0x05, LABEL_6282
	video type=1, offset=CINEMATIC_668, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6282:
	jle [0x13], 0x04, DRAW_CIN_666
	video type=1, offset=CINEMATIC_667, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_666:
	video type=1, offset=CINEMATIC_666, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6294:
	jle [0x13], 0x02, LABEL_62A0
	video type=1, offset=CINEMATIC_665, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62A0:
	jle [0x13], 0x01, DRAW_CIN_663
	video type=1, offset=CINEMATIC_664, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_663:
	video type=1, offset=CINEMATIC_663, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62B2:
	jge [0x13], 0xC8, LABEL_63C5
	je [0x13], 0x64, LABEL_63C7
	je [0x13], 0x65, LABEL_63E7
	jge [0x13], 0x81, LABEL_634F
	jne [0x13], 0x6E, LABEL_62E5
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_499, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_646, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62E5:
	jne [0x13], 0x6F, LABEL_62F1
	video type=1, offset=CINEMATIC_662, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62F1:
	jne [0x13], 0x70, LABEL_62FD
	video type=1, offset=CINEMATIC_661, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62FD:
	jne [0x13], 0x71, LABEL_6309
	video type=1, offset=CINEMATIC_660, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6309:
	jne [0x13], 0x72, LABEL_6315
	video type=1, offset=CINEMATIC_659, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6315:
	jne [0x13], 0x73, LABEL_6321
	video type=1, offset=CINEMATIC_658, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6321:
	jne [0x13], 0x74, LABEL_632D
	video type=1, offset=CINEMATIC_657, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_632D:
	jne [0x13], 0x75, LABEL_6339
	video type=1, offset=CINEMATIC_656, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6339:
	jne [0x13], 0x76, LABEL_6345
	video type=1, offset=CINEMATIC_655, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6345:
	video type=1, offset=CINEMATIC_654, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_634F:
	jne [0x13], 0x81, LABEL_6361
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_636, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6361:
	jne [0x13], 0x82, LABEL_636D
	video type=1, offset=CINEMATIC_635, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_636D:
	jne [0x13], 0x83, LABEL_6379
	video type=1, offset=CINEMATIC_634, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6379:
	jne [0x13], 0x84, LABEL_6385
	video type=1, offset=CINEMATIC_633, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6385:
	jne [0x13], 0x85, LABEL_6391
	video type=1, offset=CINEMATIC_632, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6391:
	jne [0x13], 0x86, LABEL_639D
	video type=1, offset=CINEMATIC_631, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_639D:
	jne [0x13], 0x87, LABEL_63A9
	video type=1, offset=CINEMATIC_630, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_63A9:
	jne [0x13], 0x88, LABEL_63B5
	video type=1, offset=CINEMATIC_629, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_63B5:
	jne [0x13], 0x89, LABEL_63C5
	video type=1, offset=CINEMATIC_628, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_63C5:
	ret
LABEL_63C6:
	db 0x11

LABEL_63C7:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_6D60
	call LABEL_6535
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_6437
	video type=1, offset=CINEMATIC_627, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_63E7:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call LABEL_6D60
	call LABEL_6535
	mov [0x2C], 0x0001
	jmp LABEL_6437
LABEL_63FE:
	db 0x11

LABEL_63FF:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_6D60
	call LABEL_6535
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_6437
	video type=1, offset=CINEMATIC_627, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_641F:
	mov [0x22], [0x21]
	add [0x22], 0x0190
	mov [0x09], [0x22]
	call LABEL_6D60
	call LABEL_6535
	mov [0x2C], 0x0000
	jmp LABEL_6437
LABEL_6436:
	db 0x11

LABEL_6437:
	video type=1, offset=CINEMATIC_626, x=[0x22], y=[0x27], zoom=0x40
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_6599_AND_RET
	jl [0x1D], 0x14, LABEL_64B1
	jl [0x1D], 0x1E, LABEL_6476
	je [0x1D], 0x1E, LABEL_6485
	jge [0x1D], 0x28, LABEL_6465

CALL_LABEL_6599_AND_RET:
	call LABEL_6599
	ret

LABEL_6465:
	call LABEL_5FA8
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_63E7
	jmp LABEL_641F
LABEL_6475:
	db 0x05

LABEL_6476:
	call LABEL_6599
	call LABEL_65A8
	mov [0x11], 0xFFFF
	call LABEL_65F7
	ret
LABEL_6484:
	db 0x11

LABEL_6485:
	call LABEL_5F5D
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_63E7
	jmp LABEL_641F
LABEL_6495:
	db 0x05

LABEL_6496:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_64E0
	jmp LABEL_64D2
LABEL_64B0:
	db 0x11

LABEL_64B1:
	call LABEL_6624
	call LABEL_6599
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_6496
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_64D9

LABEL_64D2:
	and [0x11], 0xFDFF
	jmp LABEL_64F3

LABEL_64D9:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_64E0:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp LABEL_64F3
