LABEL_02F6:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_02F6
	mov [0x29], 0x000A
	mov [0x0E], 0x0001

LABEL_0306:
	call LABEL_7CDA
	break
	djnz [0x29], LABEL_0306
	mov [0x29], 0x0007
	mov [0x0E], 0x0002

LABEL_0316:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_0316
	call LABEL_8C2A
	break
	mov [0x29], 0x000A
	mov [0x0E], 0x0005

LABEL_032A:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_032A
	mov [0x29], 0x0014
	mov [0x0E], 0x0003

LABEL_033A:
	call LABEL_88F2
	break
	djnz [0x29], LABEL_033A
	mov [0x0E], 0x0000
	call LABEL_88D1
	break
	mov [0x0E], 0x0004
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call LABEL_8C2A
	break
	jmp INIT_VARS_29_0E
LABEL_0359:
	db 0x11

LABEL_035A:
	break
	jl [HERO_X], 0x96, LABEL_035A
	deleteChannels first=0x14, last=0x16

LABEL_0365:
	break
	jl [0x68], 0xB3, LABEL_0365
	break
	break
	break
	break
	break
	mov [0x00], 0x0032
	bankSwitch 5;  Tank in the Battle Arena
	killChannel
