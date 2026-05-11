; mirrors CAPSULE
CAVES_SET_PROJECTILE_POS_Y_150_FROM_VAR07:
	mov [0x21], [0x07]
	mov [0x22], 0x0096
	call LABEL_7CE8
	jg [0x22], 0xC8, SHARED_RET
	mov [0x08], [0x22]
	ret
