LABEL_2FA9:
	db 0x11

COPY_PAGE_40_BREAK_LOOP:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp COPY_PAGE_40_BREAK_LOOP

JUNK__2FB8:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__2FB8

LABEL_2FC0:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp COPY_PAGE_40_BREAK_LOOP

LABEL_2FD9:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp LABEL_2FD9

JUNK__2FE7:
	copyVideoPage src=0xFF, dst=0x03
	copyVideoPage src=0x83, dst=0xFF
	jmp COPY_PAGE_40_BREAK_LOOP

LABEL_2FF0:
	copyVideoPage src=0xFF, dst=0x00
	copyVideoPage src=0x80, dst=0xFF
	jmp LABEL_B6E3
	copyVideoPage src=0x83, dst=0xFF
	jmp COPY_PAGE_40_BREAK_LOOP
	copyVideoPage src=0x83, dst=0xFF
	mov [SCROLL_Y], 0x0005
	jmp JUNK__2FE7

LABEL_3009:
	call INCREMENT_VAR31
	call LABEL_301A
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp LABEL_3009

LABEL_301A:
	mov [0xF8], [0xB8]
	and [0xF8], 0x00FF
	jne [0xB8], 0x00, LABEL_302B
	setPalette 0x00
	ret

LABEL_302B:
	jl [0xF8], 0x08, LABEL_3038
	sub [0xB8], 0x0001
	setPalette 0x14

LABEL_3038:
	jne [0xF8], 0x07, LABEL_3041
	setPalette 0x15

LABEL_3041:
	jne [0xF8], 0x06, LABEL_304A
	setPalette 0x16

LABEL_304A:
	jne [0xF8], 0x05, LABEL_3053
	setPalette 0x17

LABEL_3053:
	jne [0xF8], 0x04, LABEL_305C
	setPalette 0x18

LABEL_305C:
	jne [0xF8], 0x03, LABEL_3065
	setPalette 0x19

LABEL_3065:
	jne [0xF8], 0x02, LABEL_306E
	setPalette 0x1A

LABEL_306E:
	jne [0xF8], 0x01, LABEL_3077
	setPalette 0x1B

LABEL_3077:
	sub [0xB8], 0x0001
	jg [0xB8], 0x00, LABEL_3085
	mov [0xB8], 0x0000

LABEL_3085:
	jl [0xB8], 0x09, SHARED_RET
	mov [0xB8], 0x0009
	ret

LABEL_3090:
	break
	break
	break
	setPalette 0x1B
	break
	setPalette 0x1A
	break
	setPalette 0x19
	break
	setPalette 0x18
	break
	setPalette 0x17
	break
	setPalette 0x16
	break
	setPalette 0x15
	killChannel
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x02
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp COPY_PAGE_40_BREAK_LOOP

LABEL_30CC:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jge [SCROLL_Y], 0xFF38, LABEL_30DB
	add [SCROLL_Y], 0x00C8

LABEL_30DB:
	jl [SCROLL_Y], 0xC8, LABEL_30E5
	sub [SCROLL_Y], 0x00C8

LABEL_30E5:
	copyVideoPage src=0x80, dst=0xFF
	jl [SCROLL_Y], 0x00, SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	jmp LABEL_3107
