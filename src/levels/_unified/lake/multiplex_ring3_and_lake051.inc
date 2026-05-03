MULTIPLEX_ANIM_RING3_SLOT_0:
	mov [0x4C], [0x32]
	mov [0x4D], [0x33]
	mov [0x4E], [0x14]
	mov [0x32], [0x46]
	mov [0x33], [0x47]
	mov [0x14], [0x48]
	break
	jmp MULTIPLEX_ANIM_RING3_SLOT_0
	killChannel

MULTIPLEX_ANIM_RING3_SLOT_1:
	mov [0x46], [0x32]
	mov [0x47], [0x33]
	mov [0x48], [0x14]
	mov [0x32], [0x49]
	mov [0x33], [0x4A]
	mov [0x14], [0x4B]
	break
	jmp MULTIPLEX_ANIM_RING3_SLOT_1
	killChannel

MULTIPLEX_ANIM_RING3_SLOT_2:
	mov [0x49], [0x32]
	mov [0x4A], [0x33]
	mov [0x4B], [0x14]
	mov [0x32], [0x4C]
	mov [0x33], [0x4D]
	mov [0x14], [0x4E]
	break
	jmp MULTIPLEX_ANIM_RING3_SLOT_2
	killChannel

DRAW_LAKE_051_SEQ_FROM_WORKING_POS:
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F14, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F0, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F1, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F2, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F3, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_REED_RING_F0, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_REED_RING_F1, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_REED_RING_F2, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0002
	video type=1, offset=CINEMATIC_REED_RING_F3, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0001
	video type=1, offset=CINEMATIC_REED_RING_F4, x=[0x32], y=[0x33], zoom=0x40
	break
	sub [0x32], 0x0002
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F14, x=[0x32], y=[0x33], zoom=0x40
	break
	jmp DRAW_LAKE_051_SEQ_FROM_WORKING_POS
	killChannel

