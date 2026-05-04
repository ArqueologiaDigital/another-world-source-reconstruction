LABEL_02C7:
	jne [0x00], 0x1E, LABEL_02D4
	text id=0x0160, x=26, y=180, color=0x0F ; "CLLD"
	ret

LABEL_02D4:
	jne [0x00], 0x1F, LABEL_02E1
	text id=0x0164, x=26, y=180, color=0x0F ; "LBKG"
	ret

LABEL_02E1:
	jne [0x00], 0x21, LABEL_02EE
	text id=0x0163, x=26, y=180, color=0x0F ; "XDDJ"
	ret

LABEL_02EE:
	jne [0x00], 0x23, LABEL_02FB
	text id=0x0161, x=26, y=180, color=0x0F ; "FXLC"
	ret

LABEL_02FB:
	jne [0x00], 0x25, LABEL_0308
	text id=0x0162, x=26, y=180, color=0x0F ; "KRFK"
	ret

LABEL_0308:
	jne [0x00], 0x27, LABEL_0315
	text id=0x0165, x=26, y=180, color=0x0F ; "KLFB"
	ret

LABEL_0315:
	jne [0x00], 0x29, LABEL_0322
	text id=0x0166, x=26, y=180, color=0x0F ; "TTCT"
	ret

LABEL_0322:
	jne [0x00], 0x2A, LABEL_032F
	text id=0x0167, x=26, y=180, color=0x0F ; "DDRX"
	ret

LABEL_032F:
	jne [0x00], 0x2B, LABEL_033C
	text id=0x0168, x=26, y=180, color=0x0F ; "TBHK"
	ret

LABEL_033C:
	jne [0x00], 0x2C, LABEL_0349
	text id=0x016C, x=26, y=180, color=0x0F ; "BFLX"
	ret

LABEL_0349:
	jne [0x00], 0x2D, LABEL_0356
	text id=0x016D, x=26, y=180, color=0x0F ; "XJRT"
	ret

LABEL_0356:
	jne [0x00], 0x2E, LABEL_0363
	text id=0x016E, x=26, y=180, color=0x0F ; "HRTB"
	ret

LABEL_0363:
	jne [0x00], 0x2F, LABEL_0370
	text id=0x016F, x=26, y=180, color=0x0F ; "HBHK"
	ret

LABEL_0370:
	jne [0x00], 0x30, LABEL_037D
	text id=0x0170, x=26, y=180, color=0x0F ; "JCGB"
	ret

LABEL_037D:
	jne [0x00], 0x31, SHARED_RET
	text id=0x0169, x=26, y=180, color=0x0F ; "BRTD"
	ret
LABEL_038A:
	db 0x11

SETUP_VAR8B_6E_VAR97_B7_VAR96_0:
	mov [0x8B], 0x006E
	or [0x8B], 0x8000
	mov [0x96], 0x0000
	mov [0x97], 0x00B7
	or [0x97], 0x4000
	ret
