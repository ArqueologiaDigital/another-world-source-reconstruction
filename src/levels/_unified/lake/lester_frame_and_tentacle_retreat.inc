LESTER_FRAME_LOOP:
	mov [0x14], 0x000A
	mov [0x02], 0x00B6

LESTER_FRAME_LOOP_BODY:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_LESTER_FRAME_BUNDLE
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_LESTER_FRAME, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
	djnz [0x14], LESTER_FRAME_LOOP_BODY
;@if BRANCH in ("cartridge_1992", "gba_2004")
	song id=0x0BDD, delay=0x0000, pos=0x00
;@endif
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F4, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F4, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F4, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F5, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F5, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F6, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F6, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F7, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F8, x=[0x01], y=[0x02], zoom=0x40
	break
	play id=0x003A, freq=0x14, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F9, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F10, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F10, x=[0x01], y=[0x02], zoom=0x40
	play id=0x003A, freq=0x14, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F11, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F12, x=[0x01], y=[0x02], zoom=0x40
	mov [0x03], 0x0014
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_LAKE_051_SEQ_F13, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp INIT_VAR_03_TO_0x1E
;@elif BRANCH == "chahi_amiga_1991"
	jmp INIT_VAR_03_TO_0x1E
;@endif
	killChannel

PLAYBACK_CINEMATIC_TENTACLE_RETREAT_F0_TO_513:
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_F0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_F1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_F2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_F3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_F4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F2, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_TENTACLE_RETREAT_BG_F5, x=160, y=100
	break
	jmp PLAYBACK_CINEMATIC_TENTACLE_RETREAT_F0_TO_513
	killChannel

