LABEL_2E2C:
	db 0x11

COPY_PAGE_40_BREAK_LOOP:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp COPY_PAGE_40_BREAK_LOOP

JUNK__2E3B:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__2E3B

LABEL_2E43:
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

LABEL_2E5C:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp LABEL_2E5C

JUNK__2E6A:
	copyVideoPage src=0xFF, dst=0x03
	copyVideoPage src=0x83, dst=0xFF
	jmp COPY_PAGE_40_BREAK_LOOP

LABEL_2E73:
	copyVideoPage src=0xFF, dst=0x00
	copyVideoPage src=0x80, dst=0xFF
	jmp LABEL_B5FF
	copyVideoPage src=0x83, dst=0xFF
	jmp COPY_PAGE_40_BREAK_LOOP
	copyVideoPage src=0x83, dst=0xFF
	mov [SCROLL_Y], 0x0005
	jmp JUNK__2E6A

LABEL_2E8C:
	call INCREMENT_VAR31
	call LABEL_2E9D
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp LABEL_2E8C

LABEL_2E9D:
	mov [0xF8], [0xB8]
	and [0xF8], 0x00FF
	jne [0xB8], 0x00, LABEL_2EAE
	setPalette 0x00
	ret

LABEL_2EAE:
	jl [0xF8], 0x08, LABEL_2EBB
	sub [0xB8], 0x0001
	setPalette 0x14

LABEL_2EBB:
	jne [0xF8], 0x07, LABEL_2EC4
	setPalette 0x15

LABEL_2EC4:
	jne [0xF8], 0x06, LABEL_2ECD
	setPalette 0x16

LABEL_2ECD:
	jne [0xF8], 0x05, LABEL_2ED6
	setPalette 0x17

LABEL_2ED6:
	jne [0xF8], 0x04, LABEL_2EDF
	setPalette 0x18

LABEL_2EDF:
	jne [0xF8], 0x03, LABEL_2EE8
	setPalette 0x19

LABEL_2EE8:
	jne [0xF8], 0x02, LABEL_2EF1
	setPalette 0x1A

LABEL_2EF1:
	jne [0xF8], 0x01, LABEL_2EFA
	setPalette 0x1B

LABEL_2EFA:
	sub [0xB8], 0x0001
	jg [0xB8], 0x00, LABEL_2F08
	mov [0xB8], 0x0000

LABEL_2F08:
	jl [0xB8], 0x09, SHARED_RET
	mov [0xB8], 0x0009
	ret

LABEL_2F13:
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

LABEL_2F4F:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jge [SCROLL_Y], 0xFF38, LABEL_2F5E
	add [SCROLL_Y], 0x00C8

LABEL_2F5E:
	jl [SCROLL_Y], 0xC8, LABEL_2F68
	sub [SCROLL_Y], 0x00C8

LABEL_2F68:
	copyVideoPage src=0x80, dst=0xFF
	jl [SCROLL_Y], 0x00, SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	jmp LABEL_2F8A
