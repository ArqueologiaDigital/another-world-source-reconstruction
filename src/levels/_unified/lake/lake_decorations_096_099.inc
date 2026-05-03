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
	video type=1, offset=CINEMATIC_VINE_DECOR_F0, x=160, y=100
	mov [0x01], 0x0048
	mov [0x02], 0x00AB
	break
	jmp LOOP_DRAW_LAKE_096_DECOR_AT_72_171
	killChannel

LOOP_DRAW_LAKE_097_DECOR_AT_71_171:
	video type=1, offset=CINEMATIC_VINE_DECOR_F1, x=160, y=100
	mov [0x01], 0x0047
	mov [0x02], 0x00AB
	break
	jmp LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	killChannel

LOOP_DRAW_LAKE_098_DECOR_AT_70_172:
	video type=1, offset=CINEMATIC_VINE_DECOR_F2, x=160, y=100
	mov [0x01], 0x0046
	mov [0x02], 0x00AC
	break
	jmp LOOP_DRAW_LAKE_098_DECOR_AT_70_172
	killChannel

LOOP_DRAW_LAKE_099_DECOR_AT_69_172:
	video type=1, offset=CINEMATIC_VINE_DECOR_F3, x=160, y=100
	mov [0x01], 0x0045
	mov [0x02], 0x00AC
	break
	jmp LOOP_DRAW_LAKE_099_DECOR_AT_69_172
	killChannel

