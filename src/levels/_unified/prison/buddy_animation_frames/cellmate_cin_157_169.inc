; Cellmate (BUDDY) animation frames CIN_157..169 — 13 single-frame
; draw routines used by the var-29 / var-2F state machine to render
; the cellmate buddy at his current screen position
; (ACTOR_X / ACTOR_Y, the per-stage var aliases for 0x07 / 0x08).
;
; Frames are emitted in byte-address order: 164, 165, 166, 167,
; 163, 162, 161, 160, 159, 158, 157, 168, 169 — NOT numerical
; order. The state machine looks them up by label, so the
; byte-order doesn't matter to the dispatcher.
;
; Split out of `prison_dedups_and_landing_kill.inc` (audit
; commit reference — research/21 PRISON section) where they
; lived sandwiched between dedup helpers and the
; KILL_CHANNEL_LANDING tail. Sibling cellmate-frame ranges are
; tracked separately in the audit doc.

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_0_0:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_0, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_0_1:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_1, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_0_2:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_2, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_0_3:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_3, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_1:
	video offset=CINEMATIC_163, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_2:
	video offset=CINEMATIC_162, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_3:
	video offset=CINEMATIC_161, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_160:
	video offset=CINEMATIC_160, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_159:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_4_1, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_HERO_POSE_5:
	video offset=CINEMATIC_158, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_157:
	video offset=CINEMATIC_PRISON_FIGURE_POSE_RIGHT_7_1, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_157_L0:
	db 0x11

DRAW_CIN_168_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_168
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_168:
	video offset=CINEMATIC_PRISON_FIGURE_BELT_RIGHT, x=[ACTOR_X], y=[ACTOR_Y]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "../post_DRAW_CIN_168.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169:
	video offset=CINEMATIC_169, x=[0xf5], y=[ACTOR_Y]
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "../amiga__post_DRAW_CIN_169.inc"
.elif BRANCH == "dos_1992"
.include "../dos__post_DRAW_CIN_169.inc"
.endif

