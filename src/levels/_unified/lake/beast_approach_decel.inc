;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_BEAST_DECEL_F0		EQU 0xBD2C
CINEMATIC_BEAST_DECEL_F1		EQU 0xBD80
CINEMATIC_BEAST_DECEL_F2		EQU 0xBDC0
CINEMATIC_BEAST_DECEL_F3		EQU 0xBDCC
CINEMATIC_BEAST_DECEL_F4		EQU 0xBE20
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_3		EQU 0xBC28
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_4		EQU 0xBC80
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5		EQU 0xBCD8
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_BEAST_DECEL_F0		EQU 0xD13C
CINEMATIC_BEAST_DECEL_F1		EQU 0xD190
CINEMATIC_BEAST_DECEL_F2		EQU 0xD1D0
CINEMATIC_BEAST_DECEL_F3		EQU 0xD1DC
CINEMATIC_BEAST_DECEL_F4		EQU 0xD230
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_3		EQU 0xD038
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_4		EQU 0xD090
CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5		EQU 0xD0E8
;@endif

BEAST_APPROACH_F1_TICK:
	jne [0x66], 0x01, BEAST_APPROACH_FAST_LOOP
	jl [0x2A], 0x04, BEAST_APPROACH_FAST_LOOP
	jg [0x0E], 0xFA, BEAST_APPROACH_FAST_LOOP
	sub [0x0F], 0x000A
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000F
	sub [0x0F], 0x0008
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	sub [0x0F], 0x0005
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	sub [0x0F], 0x0005
	video type=1, offset=CINEMATIC_BEAST_APPROACH_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	sub [0x0F], 0x0002
	video type=1, offset=CINEMATIC_BEAST_PREROLL, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000B
	video type=1, offset=CINEMATIC_BEAST_DRIFT_FRAME, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000C
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_2, x=[0x0e], y=[0x0f], zoom=0x40
	mov [0x10], 0x0003
	play id=0x004E, freq=0x1C, vol=0x3F, channel=0x00
	play id=0x0030, freq=0x1C, vol=0x3F, channel=0x01
	play id=0x0030, freq=0x14, vol=0x20, channel=0x02

BEAST_PRE_HOLD_LOOP:
	break
	sub [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_HOLD_POSE, x=[0x0e], y=[0x0f], zoom=0x40
	djnz [0x10], BEAST_PRE_HOLD_LOOP
	play id=0x004E, freq=0x1C, vol=0x30, channel=0x00

BEAST_FINAL_HOLD_LOOP:
	break
	video type=1, offset=CINEMATIC_BEAST_HOLD_POSE, x=[0x0e], y=[0x0f], zoom=0x40
	jmp BEAST_FINAL_HOLD_LOOP
	killChannel

BEAST_ARRIVAL_DECEL:
	jg [0x2A], 0x04, DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME
	jne [0x66], 0x03, DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME
	jl [0x0E], 0x78, DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME
	jg [0x0E], 0xF0, DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME
	mov [0x6E], 0x0078
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x29, address=KILL_CHANNEL_ROUTINE
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x29, address=KILL_CHANNEL_ROUTINE
;@endif
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_3, x=[0x0e], y=[0x0f], zoom=0x40
	play id=0x0030, freq=0x1C, vol=0x20, channel=0x00
	break
	sub [0x0E], 0x000B
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000B
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x000A
	video type=1, offset=CINEMATIC_BEAST_DECEL_F0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0009
	video type=1, offset=CINEMATIC_BEAST_DECEL_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0009
	video type=1, offset=CINEMATIC_BEAST_DECEL_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0008
	video type=1, offset=CINEMATIC_BEAST_DECEL_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0008
	video type=1, offset=CINEMATIC_BEAST_DECEL_F4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0008
	video type=1, offset=CINEMATIC_BEAST_DECEL_F3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_DECEL_F2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0005
	video type=1, offset=CINEMATIC_BEAST_DECEL_F1, x=[0x0e], y=[0x0f], zoom=0x40
	break
	sub [0x0E], 0x0004
	video type=1, offset=CINEMATIC_BEAST_DECEL_F0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	mov [0x10], 0x0005

BEAST_DECEL_STEP_3_LOOP:
	sub [0x0E], 0x0003
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_DECEL_STEP_3_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
;@if BRANCH == "dos_1992"
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
	mov [0x10], 0x0007

BEAST_DECEL_STEP_2_LOOP:
	sub [0x0E], 0x0002
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_DECEL_STEP_2_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
;@if BRANCH == "dos_1992"
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
	mov [0x10], 0x0003

BEAST_DECEL_STEP_1_LOOP:
	sub [0x0E], 0x0001
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_DECEL_STEP_1_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
;@if BRANCH == "dos_1992"
	jl [0x0E], [0x01], BEAST_PASS_HERO_DECEL
;@endif
	mov [0x10], 0x0005

HOLD_LAKE_139_FOR_N_FRAMES:
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], HOLD_LAKE_139_FOR_N_FRAMES
;@if BRANCH in ("cartridge_1992", "gba_2004")

BEAST_PASS_HERO_DECEL:
;@endif
;@if BRANCH == "dos_1992"

BEAST_PASS_HERO_DECEL:
;@endif
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_DRIFT_LEFT_FRAME_3, x=[0x0e], y=[0x0f], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x29, address=CHECK_IF_THE_BEAST_HAS_ALREADY_REACHED_LESTER
	jg [0x0E], [0x01], DRAW_BEAST_DRIFT_LEFT_LOOP
	setup channel=0x29, address=WAIT_UNTIL_BEAST_CLOSE
	jmp BEAST_AI_INIT_POS_HEINEMAN
;@elif BRANCH == "chahi_amiga_1991"
	jmp DRAW_BEAST_DRIFT_LEFT_LOOP
;@endif
	killChannel

WAIT_BEAST_TRIGGER_THEN_INIT:
	break
	jne [0x66], 0x05, WAIT_BEAST_TRIGGER_THEN_INIT
	jl [0x01], 0x64, WAIT_BEAST_TRIGGER_THEN_INIT
;@if BRANCH == "gba_2004"
	song id=0x0FA3, delay=0x0000, pos=0x02
;@endif
	mov [0x2A], 0x0004
	copyVideoPage src=0x00, dst=0x03
	mov [0x65], 0x0005
	fill page=0x00, color=0x0B
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_SCENARIO_BACKGROUND, x=160, y=100
	selectVideoPage 0xFF
	unfreezeChannels first=0x00, last=0x27
	unfreezeChannels first=0x29, last=0x3B
	unfreezeChannels first=0x3D, last=0x3F
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	break
	setPalette 0x0D
	mov [0x10], 0x0002

