; The drifting reed's moving parts, for SCENE_TRANSITION_TO_GETTING_OUT_OF_POOL.
;
; NOT at a fixed screen position: [0x32],[0x33] is a shared draw
; position that MULTIPLEX_ANIM_RING3_SLOT_0..2 rotate between three
; records each frame, so one set of draw loops serves three reeds at
; three places, and DRAW_REED_DRIFT_LEFT_LOOP walks each one left a
; pixel per draw. The (305, 155) in the old name was the value the
; pair happened to hold at one moment in a different scene.
;
; REED_SWAY_F0..F4 is a stalk with two fronds drawn over
; CINEMATIC_LAKE_REED at the same anchor; REED_SWAY_CYCLE ping-pongs
; F0,F1,F2,F1,F0 then F3,F4,F3 and repeats, so F0 is the rest frame.
; REED_TIP_SPECK_F0/F1 is a 0x1 hairline near the reed's top -- and the
; two are the SAME picture, differing only in a byte the VM discards,
; so REED_TIP_SPECK_LOOP's alternation changes nothing on screen.
; REED_SWAY_F0_TO_BACKGROUND lays reed + F0 into the background page,
; sets palette 0x06 and kills the channel.
;
; Measured in notes/lake-shooting/ (composite_at_anchor.py draws the
; layers at their shared anchor, which is what the separate per-offset
; renders could not show).

.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LAKE_REED		EQU 0xC226
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_LAKE_REED		EQU 0xD636
.endif

.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LAKE_REED_SWAY_F1		EQU 0xC48A
CINEMATIC_LAKE_REED_SWAY_F2		EQU 0xC4BA
CINEMATIC_LAKE_REED_SWAY_F3		EQU 0xC4EA
CINEMATIC_LAKE_REED_SWAY_F4		EQU 0xC51A
CINEMATIC_LAKE_REED_TIP_SPECK_F0		EQU 0xC804
CINEMATIC_LAKE_REED_TIP_SPECK_F1		EQU 0xC7FA
CINEMATIC_LAKE_REED_SWAY_F0		EQU 0xC466
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_LAKE_REED_SWAY_F1		EQU 0xD89A
CINEMATIC_LAKE_REED_SWAY_F2		EQU 0xD8CA
CINEMATIC_LAKE_REED_SWAY_F3		EQU 0xD8FA
CINEMATIC_LAKE_REED_SWAY_F4		EQU 0xD92A
CINEMATIC_LAKE_REED_TIP_SPECK_F0		EQU 0xDC14
CINEMATIC_LAKE_REED_TIP_SPECK_F1		EQU 0xDC0A
CINEMATIC_LAKE_REED_SWAY_F0		EQU 0xD876
.endif

REED_TIP_SPECK_LOOP:
	mov [0x14], 0x0003

REED_TIP_SPECK_F0_HOLD:
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_TIP_SPECK_F0_HOLD
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	mov [0x14], 0x0006

REED_TIP_SPECK_F1_HOLD:
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_TIP_SPECK_F1_HOLD
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F1, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	video offset=CINEMATIC_LAKE_REED_TIP_SPECK_F0, x=[0x32], y=[0x33]
	break
	mov [0x14], 0x0006
	jmp REED_TIP_SPECK_F0_HOLD
	killChannel

REED_SWAY_CYCLE:
	mov [0x14], 0x0002

REED_SWAY_F0_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F0, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F0_HOLD
	mov [0x14], 0x0003

REED_SWAY_F1_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F1, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F1_HOLD
	mov [0x14], 0x0003

REED_SWAY_F2_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F2, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F2_HOLD
	mov [0x14], 0x0003

REED_SWAY_F1_RETURN_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F1, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F1_RETURN_HOLD
	mov [0x14], 0x0002

REED_SWAY_F0_RETURN_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F0, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F0_RETURN_HOLD
	mov [0x14], 0x0003

REED_SWAY_F3_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F3, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F3_HOLD
	mov [0x14], 0x0003

REED_SWAY_F4_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F4, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F4_HOLD
	mov [0x14], 0x0003

REED_SWAY_F3_RETURN_HOLD:
	video offset=CINEMATIC_LAKE_REED_SWAY_F3, x=[0x32], y=[0x33]
	break
	djnz [0x14], REED_SWAY_F3_RETURN_HOLD
	mov [0x14], 0x0002
	jmp REED_SWAY_F0_HOLD
	killChannel

REED_SWAY_F0_TO_BACKGROUND:
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_LAKE_REED, x=[0x32], y=[0x33]
	video offset=CINEMATIC_LAKE_REED_SWAY_F0, x=[0x32], y=[0x33]
	selectVideoPage 0xFF
	video offset=CINEMATIC_LAKE_REED, x=[0x32], y=[0x33]
	video offset=CINEMATIC_LAKE_REED_SWAY_F0, x=[0x32], y=[0x33]
	break
	setPalette 0x06
	killChannel

