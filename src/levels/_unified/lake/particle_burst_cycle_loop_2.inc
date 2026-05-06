;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_PARTICLE_BURST_2_FRAME_0		EQU 0xDC8A
CINEMATIC_PARTICLE_BURST_2_FRAME_1		EQU 0xDC9A
CINEMATIC_PARTICLE_BURST_2_FRAME_2		EQU 0xDCB2
CINEMATIC_PARTICLE_BURST_2_FRAME_3		EQU 0xDCC6
CINEMATIC_PARTICLE_BURST_2_FRAME_4		EQU 0xDCF6
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_PARTICLE_BURST_2_FRAME_0		EQU 0xF09A
CINEMATIC_PARTICLE_BURST_2_FRAME_1		EQU 0xF0AA
CINEMATIC_PARTICLE_BURST_2_FRAME_2		EQU 0xF0C2
CINEMATIC_PARTICLE_BURST_2_FRAME_3		EQU 0xF0D6
CINEMATIC_PARTICLE_BURST_2_FRAME_4		EQU 0xF106
;@endif

PARTICLE_BURST_CYCLE_LOOP_2:
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DC8A, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DC9A, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_2, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DCB2, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_2, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DC9A, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_1, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DC8A, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_0, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DCC6, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_4, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DCF6, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_4, x=[0x9a], y=[0x9b]
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_DCC6, x=[0x9a], y=[0x9b]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_PARTICLE_BURST_2_FRAME_3, x=[0x9a], y=[0x9b]
;@endif
	break
	jmp PARTICLE_BURST_CYCLE_LOOP_2
	killChannel

