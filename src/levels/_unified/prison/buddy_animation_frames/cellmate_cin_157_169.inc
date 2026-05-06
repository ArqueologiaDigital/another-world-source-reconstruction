; Cellmate (BUDDY) animation frames CIN_157..169 — 13 single-frame
; draw routines used by the var-29 / var-2F state machine to render
; the cellmate buddy at his current screen position
; (BUDDY_X / BUDDY_Y, the per-stage var aliases for 0x07 / 0x08).
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

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_164:
	video offset=CINEMATIC_164, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_165:
	video offset=CINEMATIC_165, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_166:
	video offset=CINEMATIC_166, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_167:
	video offset=CINEMATIC_167, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_163:
	video offset=CINEMATIC_163, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_162:
	video offset=CINEMATIC_162, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_161:
	video offset=CINEMATIC_161, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_160:
	video offset=CINEMATIC_160, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_159:
	video offset=CINEMATIC_159, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_158:
	video offset=CINEMATIC_158, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_157:
	video offset=CINEMATIC_157, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "../amiga__post_DRAW_CIN_157.inc"
;@elif BRANCH == "dos_1992"
;@include "../dos__post_DRAW_CIN_157.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_168:
	video offset=CINEMATIC_168, x=[BUDDY_X], y=[BUDDY_Y]
	ret
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "../post_DRAW_CIN_168.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169:
	video offset=CINEMATIC_169, x=[0xf5], y=[BUDDY_Y]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "../amiga__post_DRAW_CIN_169.inc"
;@elif BRANCH == "dos_1992"
;@include "../dos__post_DRAW_CIN_169.inc"
;@endif

