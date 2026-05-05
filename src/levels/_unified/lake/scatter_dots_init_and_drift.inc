;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LAKE_018_CENTER_BG		EQU 0xDD9E
CINEMATIC_SCATTER_3DOT_F0		EQU 0xDD7E
CINEMATIC_SCATTER_3DOT_F1		EQU 0xDD86
CINEMATIC_SCATTER_3DOT_F2		EQU 0xDD92
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_LAKE_018_CENTER_BG		EQU 0xF1AE
CINEMATIC_SCATTER_3DOT_F0		EQU 0xF18E
CINEMATIC_SCATTER_3DOT_F1		EQU 0xF196
CINEMATIC_SCATTER_3DOT_F2		EQU 0xF1A2
;@endif

LOOP_DRAW_LAKE_018_AT_CENTER:
	video offset=CINEMATIC_LAKE_018_CENTER_BG, x=160, y=100
	break
	jmp LOOP_DRAW_LAKE_018_AT_CENTER

DRAW_3_SCATTER_DOTS_CYCLE:
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa6], y=[0xa7], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa6], y=[0xa7], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa6], y=[0xa7], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa6], y=[0xa7], zoom=0x40
	break
	jmp DRAW_3_SCATTER_DOTS_CYCLE
	killChannel

SCATTER_3DOT_BURST_LEFT:
	jmp INIT_SCATTER_DOTS_POSITIONS
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=143, y=104
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=159, y=110
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=117, y=105
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=183, y=108
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=191, y=110
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=220, y=106
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=126, y=92
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=167, y=106
	killChannel

INIT_SCATTER_DOTS_POSITIONS:
	mov [0xA2], 0x008F
	mov [0xA4], 0x009F
	mov [0xA6], 0x0075
	mov [0xA8], 0x00B7
	mov [0xAA], 0x00BF
	mov [0xAC], 0x00DC
	mov [0xAE], 0x007E
	mov [0xB0], 0x00A7
	mov [0xA3], 0x0068
	mov [0xA5], 0x006E
	mov [0xA7], 0x0069
	mov [0xA9], 0x006C
	mov [0xAB], 0x006E
	mov [0xAD], 0x006A
	mov [0xAF], 0x005C
	mov [0xB1], 0x006A
	mov [0x92], 0x006E

SCATTER_8DOT_DRIFT_RAW:
	add [0xA2], 0x0003
	add [0xA4], 0x0002
	add [0xA6], 0x0002
	add [0xA8], 0x0002
	add [0xAA], 0x0002
	add [0xAC], 0x0001
	add [0xAE], 0x0002
	add [0xB0], 0x0002
	break
	djnz [0x92], SCATTER_8DOT_DRIFT_RAW
	setup channel=0x36, address=KILL_CHANNEL_ROUTINE
	killChannel

SCATTER_3DOT_BURST_RIGHT:
	jmp INIT_SCATTER_DOTS_OFFSETS
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=143, y=104
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=159, y=110
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=117, y=105
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=183, y=108
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=191, y=110
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=220, y=106
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=126, y=92
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=167, y=106
	killChannel

INIT_SCATTER_DOTS_OFFSETS:
	mov [0xA2], 0xFFF9
	mov [0xA4], 0x0009
	mov [0xA6], 0xFFDF
	mov [0xA8], 0x0021
	mov [0xAA], 0x0029
	mov [0xAC], 0x0046
	mov [0xAE], 0xFFE8
	mov [0xB0], 0x0011
	mov [0xA3], 0x0068
	mov [0xA5], 0x006E
	mov [0xA7], 0x0069
	mov [0xA9], 0x006C
	mov [0xAB], 0x006E
	mov [0xAD], 0x006A
	mov [0xAF], 0x005C
	mov [0xB1], 0x006A
	mov [0x92], 0x00D2

SCATTER_8DOT_DRIFT_CLASSIFIED:
	add [0xA2], 0x0003
	add [0xA4], 0x0002
	add [0xA6], 0x0002
	add [0xA8], 0x0002
	add [0xAA], 0x0002
	add [0xAC], 0x0001
	add [0xAE], 0x0002
	add [0xB0], 0x0002
	mov [0x6C], [0xA2]
	mov [0x6D], [0xA3]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xA2], [0x6C]
	mov [0xA3], [0x6D]
	mov [0x6C], [0xA4]
	mov [0x6D], [0xA5]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xA4], [0x6C]
	mov [0xA5], [0x6D]
	mov [0x6C], [0xA6]
	mov [0x6D], [0xA7]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xA6], [0x6C]
	mov [0xA7], [0x6D]
	mov [0x6C], [0xA8]
	mov [0x6D], [0xA9]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xA8], [0x6C]
	mov [0xA9], [0x6D]
	mov [0x6C], [0xAA]
	mov [0x6D], [0xAB]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xAA], [0x6C]
	mov [0xAB], [0x6D]
	mov [0x6C], [0xAC]
	mov [0x6D], [0xAD]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xAC], [0x6C]
	mov [0xAD], [0x6D]
	mov [0x6C], [0xAE]
	mov [0x6D], [0xAF]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xAE], [0x6C]
	mov [0xAF], [0x6D]
	mov [0x6C], [0xB0]
	mov [0x6D], [0xB1]
	call CLASSIFY_VAR_6C_INTO_REGIONS_SMALL
	mov [0xB0], [0x6C]
	mov [0xB1], [0x6D]
	break
	djnz [0x92], SCATTER_8DOT_DRIFT_CLASSIFIED
	deleteChannels first=0x37, last=0x38
	killChannel

DRAW_8_SCATTER_DOTS_CYCLE:
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa6], y=[0xa7], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa8], y=[0xa9], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xaa], y=[0xab], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xac], y=[0xad], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xae], y=[0xaf], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xb0], y=[0xb1], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa6], y=[0xa7], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa8], y=[0xa9], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xaa], y=[0xab], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xac], y=[0xad], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xae], y=[0xaf], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xb0], y=[0xb1], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa6], y=[0xa7], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa8], y=[0xa9], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xaa], y=[0xab], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xac], y=[0xad], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xae], y=[0xaf], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xb0], y=[0xb1], zoom=0x40
	break
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xa2], y=[0xa3], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa4], y=[0xa5], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xa6], y=[0xa7], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xa8], y=[0xa9], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F2, x=[0xaa], y=[0xab], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xac], y=[0xad], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F1, x=[0xae], y=[0xaf], zoom=0x40
	video offset=CINEMATIC_SCATTER_3DOT_F0, x=[0xb0], y=[0xb1], zoom=0x40
	break
	jmp DRAW_8_SCATTER_DOTS_CYCLE
	killChannel

