TANK_PANEL_CURSOR_TOP_ROW_CLAMP_CASE_02:
	add [0x5F], 0x0008
	ret


.include "post_INCREMENT_VAR5F_BY_8.inc"

SET_VAR5F_TO_0018:
	mov [0x5F], 0x0018
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR5F_TO_0018.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR5F_TO_0018.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR5F_TO_0018.inc"
.endif

TANK_PANEL_CURSOR_RIGHT_COLUMN_BOTTOM_CLAMP:
	mov [0x5F], 0x0016
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR5F_TO_0016.inc"
.elif BRANCH in ("cartridge_1992", "dos_1992")
.include "cart_dos__post_SET_VAR5F_TO_0016.inc"
.endif

TANK_PANEL_CURSOR_RESTORE_PREV_CELL:
	mov [0x5F], [0x62]
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR62_TO_VAR5F.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR62_TO_VAR5F.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR62_TO_VAR5F.inc"
.endif

