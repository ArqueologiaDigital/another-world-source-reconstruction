; EQU aliases for stuck literal-address operands in LAKE.
; Each block is guarded by .if BRANCH in (...) so only the branches
; that actually reference the alias see the EQU declaration.

.if BRANCH == "gba_2004"
ADDR_AT_08FC	EQU 0x08FC
DRAW_LAKE_018_CENTER_BG_LOOP_AT_0C1E	EQU 0x0C1E
ADDR_AT_B808	EQU 0xB808
ADDR_AT_B8A0	EQU 0xB8A0
ADDR_AT_B8EE	EQU 0xB8EE
ADDR_AT_DC8A	EQU 0xDC8A
ADDR_AT_DC9A	EQU 0xDC9A
ADDR_AT_DCB2	EQU 0xDCB2
ADDR_AT_DCC6	EQU 0xDCC6
ADDR_AT_DCF6	EQU 0xDCF6
.endif
