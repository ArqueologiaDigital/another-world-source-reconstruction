DELAY_LOOP_VAR7F_AT_4223:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_4223
	mov [0x77], 0x0046
	mov [0x78], 0xFF6A
	mov [0x79], 0x0001
	setup channel=0x2C, address=INLINE_SET_VAR79_TO_1
	mov [0x74], 0x006E
	mov [0x75], 0xFFE2
	mov [0x76], 0x0001
	setup channel=0x2B, address=INLINE_SET_VAR76_TO_0001_037
	mov [0x7A], 0x0096
	mov [0x7B], 0xFF9C
	mov [0x7C], 0x0001
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_040
	mov [0x7F], 0x0013

DELAY_LOOP_VAR7F_AT_425C:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_425C
	mov [0x7A], 0x00C8
	mov [0x7B], 0xFF9C
	mov [0x7C], 0x0001
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_040
	killChannel
	mov [0xE6], 0x0032

DELAY_LOOP_VARE6_AT_4276:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_4276
	mov [SCROLL_Y], 0xFF6A
	setup channel=0x3C, address=LABEL_3F87
	break
	add [SCROLL_Y], 0x001C
	setup channel=0x3C, address=LABEL_3F87
	break
	setup channel=0x3C, address=LABEL_3F8D
	add [SCROLL_Y], 0x0024
	copyVideoPage src=0x83, dst=0x00
	killChannel
