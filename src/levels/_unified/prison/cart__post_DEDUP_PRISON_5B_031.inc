LABEL_46E4:
	play id=0x0059, freq=0x14, vol=0x40, channel=0x00
	call PROJECT_POS_BY_VAR04_OR_807B
	video type=1, offset=CINEMATIC_190, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video type=1, offset=CINEMATIC_191, x=[0x21], y=[0x22], zoom=0x40

LABEL_46FB:
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video type=1, offset=CINEMATIC_192, x=[0x21], y=[0x22], zoom=0x40
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_475C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_475C
	je [HERO_ACTION], 0x00, LABEL_475C
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video type=1, offset=CINEMATIC_193, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_475C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_475C
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video type=1, offset=CINEMATIC_194, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_475C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_475C
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video type=1, offset=CINEMATIC_195, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_475C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_475C
	jmp LABEL_46FB

LABEL_475C:
	break
	sub [0x06], 0x0064
	call PROJECT_POS_VAR04_OR_7F4C
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DEDUP_CAVES_5B_003__PRISON_INLINE_SETTERS_AND_INIT
	or [0x91], 0x4000
