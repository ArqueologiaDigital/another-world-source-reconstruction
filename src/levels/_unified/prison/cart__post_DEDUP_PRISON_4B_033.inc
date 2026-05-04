LABEL_7C89:
	db 0x11

LABEL_7C8A:
	je [0x16], 0x00, DEDUP_PRISON_4B_034
	je [0x17], 0x01, DEDUP_PRISON_4B_034
	copyVideoPage src=0x80, dst=0xFF
	ret
