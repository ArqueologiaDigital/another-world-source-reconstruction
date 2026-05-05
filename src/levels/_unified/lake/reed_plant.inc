;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_REED_PLANT_0		EQU 0xD820
CINEMATIC_REED_PLANT_1		EQU 0xD838
CINEMATIC_REED_PLANT_2		EQU 0xD850
CINEMATIC_REED_PLANT_3		EQU 0xD868
CINEMATIC_REED_PLANT_4		EQU 0xD880
CINEMATIC_REED_PLANT_5		EQU 0xB808
CINEMATIC_REED_PLANT_6		EQU 0xB8A0
CINEMATIC_REED_PLANT_7		EQU 0xB8EE
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_REED_PLANT_0		EQU 0xEC30
CINEMATIC_REED_PLANT_1		EQU 0xEC48
CINEMATIC_REED_PLANT_2		EQU 0xEC60
CINEMATIC_REED_PLANT_3		EQU 0xEC78
CINEMATIC_REED_PLANT_4		EQU 0xEC90
CINEMATIC_REED_PLANT_5		EQU 0xCC18
CINEMATIC_REED_PLANT_6		EQU 0xCCB0
CINEMATIC_REED_PLANT_7		EQU 0xCCFE
;@endif

REED_PLANT_ANIMATION:
	mov [0x1E], 0x003E
	mov [0x1F], 0x00BC
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x21], 0x0003
	mov [0x20], [0x21]

REED_PLANT_F0_REPEAT:
	video type=1, offset=CINEMATIC_REED_PLANT_0, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F0_REPEAT
	mov [0x20], [0x21]

REED_PLANT_F1_REPEAT:
	video type=1, offset=CINEMATIC_REED_PLANT_1, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F1_REPEAT
	mov [0x20], [0x21]

REED_PLANT_F2_REPEAT:
	video type=1, offset=CINEMATIC_REED_PLANT_2, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F2_REPEAT
	mov [0x20], [0x21]

REED_PLANT_F3_REPEAT:
	video type=1, offset=CINEMATIC_REED_PLANT_3, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F3_REPEAT
	mov [0x20], [0x21]

REED_PLANT_F4_REPEAT:
	video type=1, offset=CINEMATIC_REED_PLANT_4, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F4_REPEAT
	mov [0x20], [0x21]

REED_PLANT_F3_RETURN:
	video type=1, offset=CINEMATIC_REED_PLANT_3, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F3_RETURN
	mov [0x20], [0x21]

REED_PLANT_F2_RETURN:
	video type=1, offset=CINEMATIC_REED_PLANT_2, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], REED_PLANT_F2_RETURN
	mov [0x20], [0x21]

JMP_TO_REED_PLANT_ANIMATION:
	video type=1, offset=CINEMATIC_REED_PLANT_1, x=[0x1e], y=[0x1f], zoom=0x40
	break
	djnz [0x20], JMP_TO_REED_PLANT_ANIMATION
	jmp REED_PLANT_ANIMATION
	killChannel
;@if BRANCH in ("cartridge_1992", "dos_1992")

REED_PLANT_FRAMES_5_TO_7_LOOP:
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@elif BRANCH == "gba_2004"
REED_PLANT_FRAMES_5_TO_7_LOOP:
	video type=1, offset=ADDR_AT_B808, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"

REED_PLANT_FRAMES_5_TO_7_LOOP:
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B808, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8A0, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8A0, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8EE, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8EE, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8EE, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_7, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8A0, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B8A0, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_6, x=160, y=100
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@elif BRANCH == "gba_2004"
	video type=1, offset=ADDR_AT_B808, x=160, y=100
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_REED_PLANT_5, x=160, y=100
;@endif
	break
	jmp REED_PLANT_FRAMES_5_TO_7_LOOP
	killChannel

