; Animated decor element at fixed screen position (305, 155).
; Frames F7..F14 cycle as a background detail during the LAKE
; intro, gated by var [0x32] / [0x33] (positional vars set by the
; scene transition). The cycle is: F7-blink-3x → F8-hold → F9/F10
; alternation with several repeats → F11/F12/F13 holds and repeats
; → F14_F9_BG copy-video-page handoff that sets palette 0x06 and
; kills the channel.

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_DECOR_AT_305_155_F14		EQU 0xC226
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_DECOR_AT_305_155_F14		EQU 0xD636
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_DECOR_AT_305_155_F10		EQU 0xC48A
CINEMATIC_DECOR_AT_305_155_F11		EQU 0xC4BA
CINEMATIC_DECOR_AT_305_155_F12		EQU 0xC4EA
CINEMATIC_DECOR_AT_305_155_F13		EQU 0xC51A
CINEMATIC_DECOR_AT_305_155_F7		EQU 0xC804
CINEMATIC_DECOR_AT_305_155_F8		EQU 0xC7FA
CINEMATIC_DECOR_AT_305_155_F9		EQU 0xC466
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_DECOR_AT_305_155_F10		EQU 0xD89A
CINEMATIC_DECOR_AT_305_155_F11		EQU 0xD8CA
CINEMATIC_DECOR_AT_305_155_F12		EQU 0xD8FA
CINEMATIC_DECOR_AT_305_155_F13		EQU 0xD92A
CINEMATIC_DECOR_AT_305_155_F7		EQU 0xDC14
CINEMATIC_DECOR_AT_305_155_F8		EQU 0xDC0A
CINEMATIC_DECOR_AT_305_155_F9		EQU 0xD876
;@endif

DECOR_F7_BLINK_3X_LOOP:
	mov [0x14], 0x0003

DECOR_F7_BLINK_3X_LOOP_BODY:
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F7_BLINK_3X_LOOP_BODY
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	mov [0x14], 0x0006

DECOR_F8_HOLD_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F8_HOLD_LOOP
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33]
	break
	mov [0x14], 0x0006
	jmp DECOR_F7_BLINK_3X_LOOP_BODY
	killChannel

DECOR_F9_THEN_F10_LOOP:
	mov [0x14], 0x0002

DECOR_F9_THEN_F10_F9_BODY:
	video offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F9_THEN_F10_F9_BODY
	mov [0x14], 0x0003

DECOR_F9_THEN_F10_F10_BODY:
	video offset=CINEMATIC_DECOR_AT_305_155_F10, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F9_THEN_F10_F10_BODY
	mov [0x14], 0x0003

DECOR_F11_HOLD_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F11, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F11_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F10_REPEAT_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F10, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F10_REPEAT_LOOP
	mov [0x14], 0x0002

DECOR_F9_REPEAT_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F9_REPEAT_LOOP
	mov [0x14], 0x0003

DECOR_F12_HOLD_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F12, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F12_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F13_HOLD_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F13, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F13_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F12_REPEAT_LOOP:
	video offset=CINEMATIC_DECOR_AT_305_155_F12, x=[0x32], y=[0x33]
	break
	djnz [0x14], DECOR_F12_REPEAT_LOOP
	mov [0x14], 0x0002
	jmp DECOR_F9_THEN_F10_F9_BODY
	killChannel

DECOR_AT_305_155_F14_F9_BG:
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_DECOR_AT_305_155_F14, x=[0x32], y=[0x33]
	video offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33]
	selectVideoPage 0xFF
	video offset=CINEMATIC_DECOR_AT_305_155_F14, x=[0x32], y=[0x33]
	video offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33]
	break
	setPalette 0x06
	killChannel

