LABEL_7FA2:
	ret

JUNK__7FA3:
	jne [HACK_VAR_67], [0x65], COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [HACK_VAR_67], [0x65]
	mov [0x65], [0x66]
	mov [0x66], [HACK_VAR_67]
	jmp LABEL_7FC4
