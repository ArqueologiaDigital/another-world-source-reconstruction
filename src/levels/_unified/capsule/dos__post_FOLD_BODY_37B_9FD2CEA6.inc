LABEL_6051:
	video type=1, offset=CINEMATIC_703, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_704, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	video type=1, offset=CINEMATIC_704, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=1, offset=CINEMATIC_705, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_705, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_704, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	mov [0x03], 0x0028

LABEL_6090:
	break
	video type=1, offset=CINEMATIC_706, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_6090
LABEL_6099:
	db 0x11

LABEL_609A:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_5DFC
	jne [0x13], 0xFFFF, LABEL_60AC
	ret

LABEL_60AC:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call LABEL_60FC
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret
LABEL_60CA:
	db 0x11

LABEL_60CB:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_5DFC
	jne [0x13], 0xFFFF, LABEL_60DE
	ret
LABEL_60DD:
	db 0x11

LABEL_60DE:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call LABEL_625D
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret

LABEL_60FC:
	jge [0x13], 0x64, LABEL_6148
	jle [0x13], 0x03, LABEL_612A
	jle [0x13], 0x05, LABEL_6118
	video type=1, offset=CINEMATIC_643, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6118:
	jle [0x13], 0x04, DRAW_CIN_641
	video type=1, offset=CINEMATIC_642, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_641:
	video type=1, offset=CINEMATIC_641, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_612A:
	jle [0x13], 0x02, LABEL_6136
	video type=1, offset=CINEMATIC_640, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6136:
	jle [0x13], 0x01, DRAW_CIN_638
	video type=1, offset=CINEMATIC_639, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_638:
	video type=1, offset=CINEMATIC_638, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6148:
	jge [0x13], 0xC8, LABEL_625B
	je [0x13], 0x64, LABEL_63F6
	je [0x13], 0x65, LABEL_6416
	jge [0x13], 0x81, LABEL_61E5
	jne [0x13], 0x6E, LABEL_617B
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_496, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_637, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_617B:
	jne [0x13], 0x6F, LABEL_6187
	video type=1, offset=CINEMATIC_636, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6187:
	jne [0x13], 0x70, LABEL_6193
	video type=1, offset=CINEMATIC_635, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6193:
	jne [0x13], 0x71, LABEL_619F
	video type=1, offset=CINEMATIC_634, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_619F:
	jne [0x13], 0x72, LABEL_61AB
	video type=1, offset=CINEMATIC_633, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61AB:
	jne [0x13], 0x73, LABEL_61B7
	video type=1, offset=CINEMATIC_632, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61B7:
	jne [0x13], 0x74, LABEL_61C3
	video type=1, offset=CINEMATIC_631, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61C3:
	jne [0x13], 0x75, LABEL_61CF
	video type=1, offset=CINEMATIC_630, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61CF:
	jne [0x13], 0x76, LABEL_61DB
	video type=1, offset=CINEMATIC_629, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61DB:
	video type=1, offset=CINEMATIC_628, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_61E5:
	jne [0x13], 0x81, LABEL_61F7
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_627, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_61F7:
	jne [0x13], 0x82, LABEL_6203
	video type=1, offset=CINEMATIC_626, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6203:
	jne [0x13], 0x83, LABEL_620F
	video type=1, offset=CINEMATIC_625, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_620F:
	jne [0x13], 0x84, LABEL_621B
	video type=1, offset=CINEMATIC_624, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_621B:
	jne [0x13], 0x85, LABEL_6227
	video type=1, offset=CINEMATIC_623, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6227:
	jne [0x13], 0x86, LABEL_6233
	video type=1, offset=CINEMATIC_622, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6233:
	jne [0x13], 0x87, LABEL_623F
	video type=1, offset=CINEMATIC_621, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_623F:
	jne [0x13], 0x88, LABEL_624B
	video type=1, offset=CINEMATIC_620, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_624B:
	jne [0x13], 0x89, LABEL_625B
	video type=1, offset=CINEMATIC_619, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_625B:
	ret
LABEL_625C:
	db 0x11

LABEL_625D:
	jge [0x13], 0x64, LABEL_62A9
	jle [0x13], 0x03, LABEL_628B
	jle [0x13], 0x05, LABEL_6279
	video type=1, offset=CINEMATIC_659, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6279:
	jle [0x13], 0x04, DRAW_CIN_657
	video type=1, offset=CINEMATIC_658, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_657:
	video type=1, offset=CINEMATIC_657, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_628B:
	jle [0x13], 0x02, LABEL_6297
	video type=1, offset=CINEMATIC_656, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6297:
	jle [0x13], 0x01, DRAW_CIN_654
	video type=1, offset=CINEMATIC_655, x=[0x21], y=[0x27], zoom=0x40
	ret

DRAW_CIN_654:
	video type=1, offset=CINEMATIC_654, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62A9:
	jge [0x13], 0xC8, LABEL_63BC
	je [0x13], 0x64, LABEL_63BE
	je [0x13], 0x65, LABEL_63DE
	jge [0x13], 0x81, LABEL_6346
	jne [0x13], 0x6E, LABEL_62DC
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_496, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_637, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62DC:
	jne [0x13], 0x6F, LABEL_62E8
	video type=1, offset=CINEMATIC_653, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62E8:
	jne [0x13], 0x70, LABEL_62F4
	video type=1, offset=CINEMATIC_652, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_62F4:
	jne [0x13], 0x71, LABEL_6300
	video type=1, offset=CINEMATIC_651, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6300:
	jne [0x13], 0x72, LABEL_630C
	video type=1, offset=CINEMATIC_650, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_630C:
	jne [0x13], 0x73, LABEL_6318
	video type=1, offset=CINEMATIC_649, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6318:
	jne [0x13], 0x74, LABEL_6324
	video type=1, offset=CINEMATIC_648, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6324:
	jne [0x13], 0x75, LABEL_6330
	video type=1, offset=CINEMATIC_647, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6330:
	jne [0x13], 0x76, LABEL_633C
	video type=1, offset=CINEMATIC_646, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_633C:
	video type=1, offset=CINEMATIC_645, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_6346:
	jne [0x13], 0x81, LABEL_6358
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_627, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6358:
	jne [0x13], 0x82, LABEL_6364
	video type=1, offset=CINEMATIC_626, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6364:
	jne [0x13], 0x83, LABEL_6370
	video type=1, offset=CINEMATIC_625, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6370:
	jne [0x13], 0x84, LABEL_637C
	video type=1, offset=CINEMATIC_624, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_637C:
	jne [0x13], 0x85, LABEL_6388
	video type=1, offset=CINEMATIC_623, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6388:
	jne [0x13], 0x86, LABEL_6394
	video type=1, offset=CINEMATIC_622, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_6394:
	jne [0x13], 0x87, LABEL_63A0
	video type=1, offset=CINEMATIC_621, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_63A0:
	jne [0x13], 0x88, LABEL_63AC
	video type=1, offset=CINEMATIC_620, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_63AC:
	jne [0x13], 0x89, LABEL_63BC
	video type=1, offset=CINEMATIC_619, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_63BC:
	ret
LABEL_63BD:
	db 0x11

LABEL_63BE:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_6D08
	call LABEL_652C
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_642E
	video type=1, offset=CINEMATIC_618, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_63DE:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call LABEL_6D08
	call LABEL_652C
	mov [0x2C], 0x0001
	jmp LABEL_642E
LABEL_63F5:
	db 0x11

LABEL_63F6:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call LABEL_6D08
	call LABEL_652C
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_642E
	video type=1, offset=CINEMATIC_618, x=[0x22], y=[0x27], zoom=0x40
	ret

LABEL_6416:
	mov [0x22], [0x21]
	add [0x22], 0x0190
	mov [0x09], [0x22]
	call LABEL_6D08
	call LABEL_652C
	mov [0x2C], 0x0000
	jmp LABEL_642E
LABEL_642D:
	db 0x11

LABEL_642E:
	video type=1, offset=CINEMATIC_617, x=[0x22], y=[0x27], zoom=0x40
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_6590_AND_RET
	jl [0x1D], 0x14, LABEL_64A8
	jl [0x1D], 0x1E, LABEL_646D
	je [0x1D], 0x1E, LABEL_647C
	jge [0x1D], 0x28, LABEL_645C

CALL_LABEL_6590_AND_RET:
	call LABEL_6590
	ret

LABEL_645C:
	call LABEL_5F9F
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_63DE
	jmp LABEL_6416
LABEL_646C:
	db 0x05

LABEL_646D:
	call LABEL_6590
	call LABEL_659F
	mov [0x11], 0xFFFF
	call LABEL_65EE
	ret
LABEL_647B:
	db 0x11

LABEL_647C:
	call LABEL_5F5A
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_63DE
	jmp LABEL_6416
LABEL_648C:
	db 0x05

LABEL_648D:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_64D7
	jmp LABEL_64C9
LABEL_64A7:
	db 0x11

LABEL_64A8:
	call LABEL_661B
	call LABEL_6590
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_648D
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_64D0

LABEL_64C9:
	and [0x11], 0xFDFF
	jmp LABEL_64EA

LABEL_64D0:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_64D7:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp LABEL_64EA
