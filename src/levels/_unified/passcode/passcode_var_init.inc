SET_VAR_E6_F_PAUSE_4:
	mov [0xE6], 0x000F
	mov [PAUSE_SLICES], 0x0004

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR_E6_F_PAUSE_4.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR_E6_F_PAUSE_4.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR_E6_F_PAUSE_4.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
SET_PAL_0_AND_RESTART:
	setPalette 0x00
	jmp ENTRY_POINT_OF_PASSCODE

; Preceding `jmp` doesn't fall through.
.if INCLUDE_UNREACHABLE_CODE == on
	killChannel
.endif

INTERPRET_KEY_TO_LETTER:
	jne [LAST_KEYCHAR], 0x0D, HANDLE_BACKSPACE_KEY
	mov [0x06], 0x0063
	ret


HANDLE_BACKSPACE_KEY:
	jne [LAST_KEYCHAR], 0x08, MAP_KEY_A_TO_Z_TO_INDEX
	mov [0x06], 0x0062
	ret


MAP_KEY_A_TO_Z_TO_INDEX:
	jl [LAST_KEYCHAR], 0x41, CLEAR_LAST_KEYCHAR
	jg [LAST_KEYCHAR], 0x5A, CLEAR_LAST_KEYCHAR
	mov [0x06], [LAST_KEYCHAR]
	sub [0x06], 0x0037
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CLEAR_LAST_KEYCHAR:
	mov [LAST_KEYCHAR], 0x0000
	ret


.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_CLEAR_LAST_KEYCHAR.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_CLEAR_LAST_KEYCHAR.inc"
.endif

INIT_VAR08_TO_150:
	mov [0x08], 0x0096

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VAR08_TO_150.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VAR08_TO_150.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VAR08_TO_150.inc"
.endif

