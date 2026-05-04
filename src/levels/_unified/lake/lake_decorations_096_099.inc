;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_VINE_DECOR_0		EQU 0x8A3E
CINEMATIC_VINE_DECOR_1		EQU 0x8A8E
CINEMATIC_VINE_DECOR_2		EQU 0x8ADE
CINEMATIC_VINE_DECOR_3		EQU 0x8B2E
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_VINE_DECOR_0		EQU 0x9E4E
CINEMATIC_VINE_DECOR_1		EQU 0x9E9E
CINEMATIC_VINE_DECOR_2		EQU 0x9EEE
CINEMATIC_VINE_DECOR_3		EQU 0x9F3E
;@endif

SCHEDULE_LAKE_DECORATIONS_096_TO_099:
	setup channel=0x04, address=LOOP_DRAW_LAKE_096_DECOR_AT_72_171
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_098_DECOR_AT_70_172
	break

SCHED_LAKE_DECOR_099_BACK:
	setup channel=0x04, address=LOOP_DRAW_LAKE_099_DECOR_AT_69_172
	break
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_098_DECOR_AT_70_172
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_096_DECOR_AT_72_171
	break
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_098_DECOR_AT_70_172
	break
	break
	jmp SCHED_LAKE_DECOR_099_BACK
	killChannel

LOOP_DRAW_LAKE_096_DECOR_AT_72_171:
	video type=1, offset=CINEMATIC_VINE_DECOR_0, x=160, y=100
	mov [0x01], 0x0048
	mov [0x02], 0x00AB
	break
	jmp LOOP_DRAW_LAKE_096_DECOR_AT_72_171
	killChannel

LOOP_DRAW_LAKE_097_DECOR_AT_71_171:
	video type=1, offset=CINEMATIC_VINE_DECOR_1, x=160, y=100
	mov [0x01], 0x0047
	mov [0x02], 0x00AB
	break
	jmp LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	killChannel

LOOP_DRAW_LAKE_098_DECOR_AT_70_172:
	video type=1, offset=CINEMATIC_VINE_DECOR_2, x=160, y=100
	mov [0x01], 0x0046
	mov [0x02], 0x00AC
	break
	jmp LOOP_DRAW_LAKE_098_DECOR_AT_70_172
	killChannel

LOOP_DRAW_LAKE_099_DECOR_AT_69_172:
	video type=1, offset=CINEMATIC_VINE_DECOR_3, x=160, y=100
	mov [0x01], 0x0045
	mov [0x02], 0x00AC
	break
	jmp LOOP_DRAW_LAKE_099_DECOR_AT_69_172
	killChannel

