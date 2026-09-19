; ENDING credits cinematic-draw loops. The credits sequence
; iterates through CIN_097..104 (the alien-natives celebration
; animation), then CIN_058 (the spaceship ascent), then
; CIN_059..065 (the freeze-frame credits roll). Each loop runs as
; its own channel.
;
; Several labels carry an `__ENDING_CHANNEL_CLEANUP` suffix as a
; historical marker — the base names (e.g. `DRAW_CIN_103_LOOP`)
; collide with labels in `cart__post_DELETE_ALL_CHANS_AND_KILL.inc`,
; so the suffix disambiguates. Suffix preserved verbatim during
; the split out of `ending_channel_cleanup.inc`.

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP:
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F0, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F1, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F2, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F3, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F2, x=160, y=100
	break
	video offset=CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F1, x=160, y=100
	break
	jmp ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "post_DRAW_CIN_97_TO_100.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_RISE:
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F0, x=160, y=125
	setPalette 0x0C
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F0, x=160, y=118
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F1, x=160, y=112
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F2, x=160, y=107
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F3, x=160, y=105
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F3, x=160, y=109
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F3, x=160, y=110
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F2, x=160, y=115
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_LOOP:
	break
	video offset=CINEMATIC_ENDING_BUDDY_HOLDS_LESTER_F2, x=160, y=118
	jmp ENDING_BUDDY_HOLDS_LESTER_CLOSEUP_LOOP
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "post_DRAW_CIN_103_LOOP.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_LEDGE_SWELL_DRAW_LOOP:
	video offset=CINEMATIC_ENDING_LEDGE_SWELL, x=160, y=100, zoom=[0x04]
	break
	jmp ENDING_LEDGE_SWELL_DRAW_LOOP
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "post_DRAW_CIN_58_ANIM_LOOP.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PTERANODON_LEG_DANGLE_LOOP:
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F4, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_LEG_DANGLE_F6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp PTERANODON_LEG_DANGLE_LOOP
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
.endif

