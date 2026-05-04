LABEL_1C95:
	db 0x11

LABEL_1C96:
	mov [0x27], 0x0000
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	deleteChannels first=0x01, last=0x04
	ret

LABEL_1CB8:
	setPalette 0x02
	selectVideoPage 0x00
	call FILL_AND_DRAW_CIN_24_28
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	killChannel

LABEL_1CC9:
	setup channel=0x01, address=LABEL_1D57
	setup channel=0x02, address=LABEL_1D60
	setup channel=0x03, address=LABEL_1E33
	setup channel=0x04, address=LABEL_1D60
	setup channel=0x05, address=LABEL_1D09
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
LABEL_1D08:
	db 0x11

LABEL_1D09:
	mov [0xF8], [0x31]
	and [0xF8], 0x000F
	jne [0xF8], 0x00, LABEL_1D50
	mov [0xF8], [0x31]
	and [0xF8], 0x003F
	selectVideoPage 0x00
	jne [0xF8], 0x00, LABEL_1D2C
	video type=1, offset=CINEMATIC_003, x=160, y=100
	jmp LABEL_1D50

LABEL_1D2C:
	jne [0xF8], 0x10, LABEL_1D39
	video type=1, offset=CINEMATIC_002, x=160, y=100
	jmp LABEL_1D50

LABEL_1D39:
	jne [0xF8], 0x20, LABEL_1D46
	video type=1, offset=CINEMATIC_001, x=160, y=100
	jmp LABEL_1D50

LABEL_1D46:
	jne [0xF8], 0x30, LABEL_1D50
	video type=1, offset=CINEMATIC_000, x=160, y=100

LABEL_1D50:
	selectVideoPage 0xFF
	break
	jmp LABEL_1D09
LABEL_1D56:
	db 0x11

LABEL_1D57:
	mov [0x27], 0x0000
	break
	jmp LABEL_1D57
LABEL_1D5F:
	db 0x11

LABEL_1D60:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_014, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1D72

LABEL_1D6F:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1D72:
	video type=1, offset=CINEMATIC_015, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1D9F
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1D8A:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1DBD
	jmp LABEL_1D8A

LABEL_1D9F:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1DB4
	jmp LABEL_1D9F

LABEL_1DB4:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1DBD:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_018, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_019, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_020, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_021, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x1E, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1D6F
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1D6F
LABEL_1E32:
	db 0x11

LABEL_1E33:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_004, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1E45

LABEL_1E42:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1E45:
	video type=1, offset=CINEMATIC_005, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1E72
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E5D:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E90
	jmp LABEL_1E5D

LABEL_1E72:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E87
	jmp LABEL_1E72

LABEL_1E87:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E90:
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_008, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_009, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_010, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_011, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x20, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1E42
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video type=1, offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1E42
LABEL_1F05:
	db 0x11
