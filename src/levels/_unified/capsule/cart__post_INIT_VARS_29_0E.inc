LABEL_0363:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_0363
	mov [0x29], 0x000A
	mov [0x0E], 0x0001

LABEL_0373:
	call LABEL_7D43
	break
	djnz [0x29], LABEL_0373
	mov [0x29], 0x0007
	mov [0x0E], 0x0002

LABEL_0383:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_0383
	call LABEL_8C93
	break
	mov [0x29], 0x000A
	mov [0x0E], 0x0005

LABEL_0397:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	djnz [0x29], LABEL_0397
	mov [0x29], 0x0014
	mov [0x0E], 0x0003

LABEL_03A7:
	call LABEL_895B
	break
	djnz [0x29], LABEL_03A7
	mov [0x0E], 0x0000
	call LABEL_893A
	break
	mov [0x0E], 0x0004
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call LABEL_8C93
	break
	jmp INIT_VARS_29_0E
LABEL_03C6:
	db 0x11

LABEL_03C7:
	break
	jl [HERO_X], 0x96, LABEL_03C7
	deleteChannels first=0x14, last=0x16

LABEL_03D2:
	break
	jl [0x68], 0xB3, LABEL_03D2
	break
	break
	break
	break
	break
	mov [0x00], 0x0032
	bankSwitch 5;  TODO - Name this stage (bank number #5)
	killChannel
