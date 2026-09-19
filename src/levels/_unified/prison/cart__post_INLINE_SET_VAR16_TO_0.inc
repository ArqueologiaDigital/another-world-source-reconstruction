LABEL_7FA2:
	ret


JUNK__7FA3:
	jne [SCREEN_NUM], [0x65], SHELVE_BACKDROP_TO_PAGE3
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [SCREEN_NUM], [0x65]
	mov [0x65], [CACHED_SCREEN_NUM]
	mov [CACHED_SCREEN_NUM], [SCREEN_NUM]
	jmp PRISON_SHELVE_BACKDROP_TO_PAGE3_L0
