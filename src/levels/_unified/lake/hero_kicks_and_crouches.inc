HERO_KICK_LEFT_LOOP:
	sub [0x01], 0x0004
	play id=0x003D, freq=0x0A, vol=0x0A, channel=0x00
	video type=1, offset=CINEMATIC_LEFT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x06], 0x0002
	mov [0x04], [0x01]
	mov [0x05], [0x02]
	sub [0x04], 0x000E
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_LEFT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x01], 0x0000
;@elif BRANCH == "chahi_amiga_1991"
	add [0x01], 0x0001
;@endif

HERO_LEFT_KICK_LOOP:
	break
	mov [0x06], 0x0000
	video type=1, offset=CINEMATIC_LEFT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_ACTION_POS_MASK], 0x80, HERO_LEFT_KICK_LOOP
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_LEFT_KICK_1, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x01], 0x0001
	mov [0x63], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp RESUME_L_CV079080_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif
	killChannel

HERO_KICK_RIGHT_LOOP:
	add [0x01], 0x0004
	play id=0x003D, freq=0x0A, vol=0x0A, channel=0x00
	video type=1, offset=CINEMATIC_RIGHT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x06], 0x0002
	mov [0x04], [0x01]
	mov [0x05], [0x02]
	add [0x04], 0x000E
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x01], 0x0000
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0001
;@endif
	video type=1, offset=CINEMATIC_RIGHT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	sub [0x01], 0x0001

HERO_RIGHT_KICK_LOOP:
	break
	mov [0x06], 0x0000
	video type=1, offset=CINEMATIC_RIGHT_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_ACTION_POS_MASK], 0x80, HERO_RIGHT_KICK_LOOP
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_RIGHT_KICK_1, x=[0x01], y=[0x02], zoom=[0x03]
	sub [0x01], 0x0001
	mov [0x63], 0x0002
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif
	killChannel

HERO_CROUCH_KICK_LEFT:
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_LEFT_CROUCHING_1, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x06], 0x0001
	mov [0x04], [0x01]
	mov [0x05], [0x02]
	sub [0x04], 0x001A
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x01], 0x0000
;@elif BRANCH == "chahi_amiga_1991"
	add [0x01], 0x0001
;@endif
	play id=0x003D, freq=0x0A, vol=0x0A, channel=0x00
	video type=1, offset=CINEMATIC_LEFT_CROUCH_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x01], 0x0001

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
HERO_LEFT_CROUCH_KICK_LOOP:
;@elif BRANCH == "chahi_amiga_1991"
HERO_LEFT_CROUCH_KICK_LOOP:
;@endif
	break
	mov [0x06], 0x0000
	video type=1, offset=CINEMATIC_LEFT_CROUCH_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [HERO_ACTION_POS_MASK], 0x84, HERO_LEFT_CROUCH_KICK_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	je [HERO_ACTION_POS_MASK], 0x84, HERO_LEFT_CROUCH_KICK_LOOP
;@endif
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_LEFT_CROUCH_KICK_1, x=[0x01], y=[0x02], zoom=[0x03]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [0x01], 0x0002
;@endif
	je [HERO_POS_JUMP_DOWN], 0x01, HERO_CROUCH_LEFT_HOLD
	mov [0x63], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp RESUME_L_CV079080_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif

HERO_CROUCH_KICK_RIGHT:
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_1, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x06], 0x0001
	mov [0x04], [0x01]
	mov [0x05], [0x02]
	add [0x04], 0x001A
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [0x01], 0x0000
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0001
;@endif
	play id=0x003D, freq=0x0A, vol=0x0A, channel=0x00
	video type=1, offset=CINEMATIC_RIGHT_CROUCH_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	sub [0x01], 0x0001

HERO_RIGHT_CROUCH_KICK_LOOP:
	break
	mov [0x06], 0x0000
	video type=1, offset=CINEMATIC_RIGHT_CROUCH_KICK_0, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_ACTION_POS_MASK], 0x84, HERO_RIGHT_CROUCH_KICK_LOOP
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCH_KICK_1, x=[0x01], y=[0x02], zoom=[0x03]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0002
;@endif
	je [HERO_POS_JUMP_DOWN], 0x01, HERO_CROUCH_RIGHT_HOLD
	mov [0x63], 0x0002
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif

HERO_CROUCH_LEFT_LOOP:
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_LEFT_CROUCHING_0, x=[0x01], y=[0x02], zoom=[0x03]

HERO_CROUCH_LEFT_HOLD:
	break
	je [HERO_ACTION_POS_MASK], 0x84, HERO_CROUCH_KICK_LEFT
	video type=1, offset=CINEMATIC_LEFT_CROUCHING_2, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_ACTION_POS_MASK], 0x04, HERO_CROUCH_LEFT_HOLD
	break
	video type=1, offset=CINEMATIC_LEFT_CROUCHING_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_LEFT_CROUCHING_0, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x63], 0x0001
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp RESUME_L_CV079080_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif
	killChannel

HERO_CROUCH_RIGHT_LOOP:
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_0, x=[0x01], y=[0x02], zoom=[0x03]

HERO_CROUCH_RIGHT_HOLD:
	break
	je [HERO_ACTION_POS_MASK], 0x84, HERO_CROUCH_KICK_RIGHT
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_2, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_ACTION_POS_MASK], 0x04, HERO_CROUCH_RIGHT_HOLD
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_0, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x63], 0x0002
	sub [0x01], 0x0002
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
	killChannel
	killChannel
	FILL(44547, 0xFF)
;@elif BRANCH == "gba_2004"
	jmp RESUME_R_AFTER_VINE_LAND
	FILL(44507, 0xFF)
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
	killChannel

HERO_GETTING_OUT_OF_POOL_LOOP:
	video type=1, offset=CINEMATIC_HERO_FALL_PRELUDE_FRAME, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_HERO_FALL_PRELUDE_FRAME, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x02], 0x0002
	add [0x01], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_HERO_OUT_POOL_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_HERO_OUT_POOL_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_HERO_OUT_POOL_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_HERO_OUT_POOL_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x02], 0x0002
	add [0x01], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_HERO_LIFTOFF, x=[0x01], y=[0x02], zoom=[0x03]

HOLD_CIN_147_WAIT_KEY:
	break
	video type=1, offset=CINEMATIC_HERO_LIFTOFF, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HOLD_CIN_147_WAIT_KEY
	break
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_LESTER_WAIT_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_LESTER_WAIT_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x02], 0x0002
	add [0x02], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_LESTER_WAIT_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_LESTER_WAIT_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x01], [HERO_POS_LEFT_RIGHT]
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_1, x=[0x01], y=[0x02], zoom=[0x03]

HOLD_POOL_F_1_WAIT_KEY:
	break
	video type=1, offset=CINEMATIC_GETTING_OUT_OF_THE_POOL_F_1, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HOLD_POOL_F_1_WAIT_KEY
	break
	add [0x02], 0x0001
	jmp HERO_GETTING_OUT_OF_POOL_LOOP
	killChannel

HOLD_POOL_LESTER_F0_WAIT:
	video type=1, offset=CINEMATIC_POOL_LESTER_0, x=[0x01], y=[0x02], zoom=[0x03]

HOLD_CIN_720_WAIT_KEY:
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_0, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HOLD_CIN_720_WAIT_KEY
	break
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_POOL_LESTER_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x02], 0x0002
	add [0x01], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_POOL_LESTER_2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_POOL_LESTER_3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x02], 0x0001
	add [0x01], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_POOL_LESTER_4, x=[0x01], y=[0x02], zoom=[0x03]

HOLD_CIN_724_WAIT_KEY:
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_4, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HOLD_CIN_724_WAIT_KEY
	break
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_POOL_LESTER_5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x02], 0x0002
	add [0x01], [HERO_POS_LEFT_RIGHT]
	video type=1, offset=CINEMATIC_POOL_LESTER_6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	sub [0x02], 0x0002
	video type=1, offset=CINEMATIC_POOL_LESTER_7, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_POOL_LESTER_7, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x01], [HERO_POS_LEFT_RIGHT]
	sub [0x02], 0x0001
	jmp HOLD_POOL_LESTER_F0_WAIT
	killChannel
	FILL(46078, 0xFF)
;@elif BRANCH == "dos_1992"
	jmp RESUME_R_AFTER_VINE_LAND
	killChannel
	killChannel
	FILL(44726, 0xFF)
;@endif
