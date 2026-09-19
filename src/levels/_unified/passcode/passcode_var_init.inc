PASSCODE_INVALID_MESSAGE_PRELUDE:
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

.if BRANCH in ("cartridge_1992", "dos_1992")
KEY_PRESSED_DISPATCH:
	mov [0x05], [0x01]
	je [LAST_KEYCHAR], 0x00, PASSCODE_SELECT_KEY_UNDER_CURSOR
	call INTERPRET_KEY_TO_LETTER
	je [LAST_KEYCHAR], 0x00, DRAW_PASSCODE_FRAME_AND_WAIT_KEY
	jmp PROCESS_PASSCODE_SUBMIT

PASSCODE_SELECT_KEY_UNDER_CURSOR:
	call PASSCODE_GRID_KEY_LOOKUP_CASE_00

PROCESS_PASSCODE_SUBMIT:
	mov [0x22], [0x02]
	je [0x06], 0x63, VALIDATE_PASSCODE_LDKD
	jne [0x06], 0x62, CHECK_ALL_4_LETTERS_ENTERED
	mov [0x06], 0xFFFF
	sub [0x22], 0x0001
	jg [0x22], 0x00, STORE_LETTER_IN_PASSCODE_BUFFER
	mov [0x22], 0x0000
	jmp STORE_LETTER_IN_PASSCODE_BUFFER

CHECK_ALL_4_LETTERS_ENTERED:
	je [0x02], 0x04, DRAW_PASSCODE_FRAME_AND_WAIT_KEY
	add [0x22], 0x0001
	add [0x02], 0x0001

STORE_LETTER_IN_PASSCODE_BUFFER:
	jne [0x02], 0x01, SAVE_PASSCODE_LETTER_2
	mov [0x1E], [0x06]

SAVE_PASSCODE_LETTER_2:
	jne [0x02], 0x02, SAVE_PASSCODE_LETTER_3
	mov [0x1F], [0x06]

SAVE_PASSCODE_LETTER_3:
	jne [0x02], 0x03, SAVE_PASSCODE_LETTER_4
	mov [0x20], [0x06]

SAVE_PASSCODE_LETTER_4:
	jne [0x02], 0x04, PASSCODE_LETTER_STORE_DONE
	mov [0x21], [0x06]

PASSCODE_LETTER_STORE_DONE:
	call DRAW_PASSCODE_LETTER_FRAME
	mov [0x02], [0x22]

DRAW_PASSCODE_FRAME_AND_WAIT_KEY:
	mov [0x05], [0x01]
	call PASSCODE_GRID_CELL_POSITION
	video offset=CINEMATIC_PASSCODE_CURSOR, x=[0x07], y=[0x08]
	break
	jne [LAST_KEYCHAR], 0x00, DRAW_PASSCODE_FRAME_AND_WAIT_KEY
.if BRANCH == "cartridge_1992"
; cart-only "if you press jump-down, set HERO_ACTION = 1" behavior —
; lets the player back out of the passcode screen with the jump key.
; dos+amiga don't have this; pressing any HERO_ACTION key proceeds.
	je [0xDB], 0x00, RESUME_PASSCODE_INPUT
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, RESUME_PASSCODE_INPUT
	mov [HERO_ACTION], 0x0001

RESUME_PASSCODE_INPUT:
.endif
	jne [HERO_ACTION], 0x00, DRAW_PASSCODE_FRAME_AND_WAIT_KEY
	jmp HANDLE_PASSCODE_INPUT_OR_DISPATCH

; Unreachable `db 0x11` filler — preceding `jmp` doesn't fall through.
.if INCLUDE_UNREACHABLE_CODE == on
	killChannel
.endif

DRAW_PASSCODE_LETTER_FRAME:
	mov [0x07], 0x00BC
	mov [0x08], 0x0054
	selectVideoPage 0x00
	video offset=CINEMATIC_PASSCODE_LETTER_FRAME, x=160, y=100
	text id=0x013C, x=2, y=80, color=0x06 ; "        ACCESS CODE:"
	mov [0x06], [0x1E]
	call BLINK_LETTER_DISPATCHER
	add [0x07], 0x0008
	mov [0x06], [0x1F]
	call BLINK_LETTER_DISPATCHER
	add [0x07], 0x0008
	mov [0x06], [0x20]
	call BLINK_LETTER_DISPATCHER
	add [0x07], 0x0008
	mov [0x06], [0x21]
	call BLINK_LETTER_DISPATCHER
	selectVideoPage 0xFF
	ret


PASSCODE_GRID_CELL_POSITION:
	mov [0x07], [0x05]
	mov [0x08], [0x05]
	and [0x07], 0x0007
	and [0x08], 0x0008
	jne [0x08], 0x00, PASSCODE_GRID_ROW_LOWER_Y
	mov [0x08], 0x0086
	jmp PASSCODE_GRID_COLUMN_SCREEN_X
.endif

PASSCODE_GRID_ROW_LOWER_Y:
	mov [0x08], 0x0096

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VAR08_TO_150.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VAR08_TO_150.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VAR08_TO_150.inc"
.endif

