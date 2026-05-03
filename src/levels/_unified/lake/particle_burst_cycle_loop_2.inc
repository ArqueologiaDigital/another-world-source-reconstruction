PARTICLE_BURST_CYCLE_LOOP_2:
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDC8A, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDC9A, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_2, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDCB2, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_2, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDC9A, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDC8A, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDCC6, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_4, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDCF6, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_4, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "gba_2004"
	video type=1, offset=0xDCC6, x=[0x9a], y=[0x9b], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b], zoom=0x40
;@endif
	break
	jmp PARTICLE_BURST_CYCLE_LOOP_2
	killChannel
	mov [0x01], 0x0000
	mov [0x02], 0x0000
	mov [0x03], 0x0000
	mov [0x04], 0x0000
	mov [0x05], 0x0000
	mov [0x06], 0x0000
	mov [0x07], 0x0000
	mov [0x08], 0x0000
	mov [0x09], 0x0000
	mov [0x0A], 0x0000
	mov [0x0B], 0x0000
	mov [0x0C], 0x0000
	mov [0x0D], 0x0000
	mov [0x0E], 0x0000
	mov [0x0F], 0x0000
	mov [0x10], 0x0000
	mov [0x11], 0x0000
	mov [0x12], 0x0000
	mov [0x13], 0x0000
	mov [0x14], 0x0000
	mov [0x15], 0x0000
	mov [0x16], 0x0000
	mov [0x17], 0x0000
	mov [0x18], 0x0000
	mov [0x19], 0x0000
	mov [0x1A], 0x0000
	mov [0x1B], 0x0000
	mov [0x1C], 0x0000
	mov [0x1D], 0x0000
	mov [0x1E], 0x0000
	mov [0x1F], 0x0000
	mov [0x20], 0x0000
	mov [0x21], 0x0000
	mov [0x22], 0x0000
	mov [0x23], 0x0000
	mov [0x24], 0x0000
	mov [0x25], 0x0000
	mov [0x26], 0x0000
	mov [0x27], 0x0000
	mov [0x28], 0x0000
	mov [0x29], 0x0000
	mov [0x2A], 0x0000
	mov [0x2B], 0x0000
	mov [0x2C], 0x0000
	mov [0x2D], 0x0000
	mov [0x2E], 0x0000
	mov [0x2F], 0x0000
	mov [0x30], 0x0000
	mov [0x31], 0x0000
	mov [0x32], 0x0000
	mov [0x33], 0x0000
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	mov [0x36], 0x0000
	mov [0x37], 0x0000
	mov [0x38], 0x0000
	mov [0x39], 0x0000
	mov [0x3A], 0x0000
	mov [0x3B], 0x0000
	mov [RANDOM_SEED], 0x0000
	mov [0x3D], 0x0000
	mov [0x3E], 0x0000
	mov [0x3F], 0x0000
	mov [0x40], 0x0000
	mov [0x41], 0x0000
	mov [0x42], 0x0000
	mov [0x43], 0x0000
	mov [0x44], 0x0000
	mov [0x45], 0x0000
	mov [0x46], 0x0000
	mov [SCROLL_Y], 0x0000
	ret

