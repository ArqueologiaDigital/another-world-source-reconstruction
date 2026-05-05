LABEL_1C8D:
	db 0x11

LABEL_1C8E:
	mov [0x27], 0x0000
	selectVideoPage 0x00
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	deleteChannels first=0x01, last=0x04
	ret

LABEL_1CB0:
	setPalette 0x02
	selectVideoPage 0x00
	call FILL_AND_DRAW_CIN_24_28
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	killChannel

LABEL_1CC1:
	setup channel=0x01, address=LABEL_1D4F
	setup channel=0x02, address=LABEL_1D58
	setup channel=0x03, address=LABEL_1E2B
	setup channel=0x04, address=LABEL_1D58
	setup channel=0x05, address=LABEL_1D01
	play id=0x0061, freq=0x0A, vol=0x07, channel=0x02
	mov [0x80], 0x005A
	shl [0x80], 0x0008
	or [0x80], 0x0096
	mov [0x81], 0x0046
	shl [0x81], 0x0008
	or [0x81], 0x0094
	mov [0x82], 0x006E
	shl [0x82], 0x0008
	or [0x82], 0x0082
	ret
LABEL_1D00:
	db 0x11

LABEL_1D01:
	mov [0xF8], [0x31]
	and [0xF8], 0x000F
	jne [0xF8], 0x00, LABEL_1D48
	mov [0xF8], [0x31]
	and [0xF8], 0x003F
	selectVideoPage 0x00
	jne [0xF8], 0x00, LABEL_1D24
	video offset=CINEMATIC_003, x=160, y=100
	jmp LABEL_1D48

LABEL_1D24:
	jne [0xF8], 0x10, LABEL_1D31
	video offset=CINEMATIC_002, x=160, y=100
	jmp LABEL_1D48

LABEL_1D31:
	jne [0xF8], 0x20, LABEL_1D3E
	video offset=CINEMATIC_001, x=160, y=100
	jmp LABEL_1D48

LABEL_1D3E:
	jne [0xF8], 0x30, LABEL_1D48
	video offset=CINEMATIC_000, x=160, y=100

LABEL_1D48:
	selectVideoPage 0xFF
	break
	jmp LABEL_1D01
LABEL_1D4E:
	db 0x11

LABEL_1D4F:
	mov [0x27], 0x0000
	break
	jmp LABEL_1D4F
LABEL_1D57:
	db 0x11

LABEL_1D58:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video offset=CINEMATIC_014, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1D6A

LABEL_1D67:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1D6A:
	video offset=CINEMATIC_015, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1D97
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1D82:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1DB5
	jmp LABEL_1D82

LABEL_1D97:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1DAC
	jmp LABEL_1D97

LABEL_1DAC:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1DB5:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_018, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_019, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_020, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_021, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x1E, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1D67
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1D67
LABEL_1E2A:
	db 0x11

LABEL_1E2B:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video offset=CINEMATIC_004, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1E3D

LABEL_1E3A:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1E3D:
	video offset=CINEMATIC_005, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1E6A
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E55:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E88
	jmp LABEL_1E55

LABEL_1E6A:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E7F
	jmp LABEL_1E6A

LABEL_1E7F:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E88:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_008, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_009, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_010, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_011, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x20, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1E3A
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1E3A
LABEL_1EFD:
	db 0x11
