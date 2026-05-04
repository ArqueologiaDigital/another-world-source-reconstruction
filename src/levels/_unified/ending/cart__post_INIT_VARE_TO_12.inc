DRIFT_VAR_F_PLUS_1_LOOP:
	break
	add [0x0F], 0x0001
	djnz [0x0E], DRIFT_VAR_F_PLUS_1_LOOP
	mov [0x0E], 0x0009

DRIFT_VAR_F_PLUS_4_LOOP:
	break
	add [0x0F], 0x0004
	djnz [0x0E], DRIFT_VAR_F_PLUS_4_LOOP
	mov [0x0E], 0x0032

DELAY_VARE_THEN_INIT_VARE_5:
	break
	djnz [0x0E], DELAY_VARE_THEN_INIT_VARE_5
	mov [0x0E], 0x0005

DRIFT_VAR_F_PLUS_8_LOOP:
	break
	add [0x0F], 0x0008
	djnz [0x0E], DRIFT_VAR_F_PLUS_8_LOOP
	setup channel=0x36, address=LABEL_023B
	break
	add [0x0F], 0x000C
	break
	add [0x0F], 0x0018
	break
	add [0x0F], 0x0026
	break
	add [0x0F], 0x0038
	killChannel

DRAW_CIN_70_ANIM_LOOP:
	video type=1, offset=CINEMATIC_070, x=[0x01], y=[0x02], zoom=[0x0f]
	break
	jmp DRAW_CIN_70_ANIM_LOOP
LABEL_023A:
	db 0x11

LABEL_023B:
	setPalette 0x10
	break
	setPalette 0x11
	break
	setPalette 0x12
	break
	setPalette 0x13
	break
	setPalette 0x14
	break
	setPalette 0x15
	break
	setPalette 0x16
	break
	setPalette 0x17
	deleteChannels first=0x0A, last=0x11
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	break
	jne [0xDB], 0x01, LABEL_035A
	selectVideoPage 0x00
	text id=0x0258, x=2, y=10, color=0x0C ; "Design ............... Eric Chahi"
	text id=0x0259, x=2, y=40, color=0x0C ; "Original Programmer .. Eric Chahi"
	text id=0x025A, x=2, y=70, color=0x0C ; "Genesis Programmer ... Michael Burton


Exec. Producer. Stephen Clarke-Willson"
	text id=0x025B, x=1, y=100, color=0x0C ; "
 U.K. Producer ........Matthew Spall
 Virgin Games, Inc. Producer . Erik Yeo
 Interplay Producer ...... Alan Pavlish

 Music ...... Tommy Tallarico
       ...... Jean-Francois Freitas

 Sound ...... Tommy Tallarico
       ...... Jean-Francois Freitas
       ...... Eric Chahi

"
	text id=0x025C, x=2, y=130, color=0x0C ; "string_025C"
	text id=0x025D, x=2, y=140, color=0x0C ; "string_025D"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_80
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x000A

DELAY_LOOP_VAR01:
	break
	djnz [0x01], DELAY_LOOP_VAR01
	setup channel=0x14, address=PAL_FADE_18_TO_1D
	mov [0x01], 0x00AF

LABEL_02B0:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02B0
	mov [0x01], 0x00C8

DELAY_LOOP_VAR01_AT_02BD:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_02BD
	mov [0x01], 0x00B4

LABEL_02C6:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02C6
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0263, x=6, y=0, color=0x0C ; "Title Animation . Jason Magness

Q.A. Manager .... Michael Gater

"
	text id=0x0264, x=6, y=30, color=0x0C ; "
Quality Assurance Team 

Noah Tool     Justin Norr
Danny Lewis   Mike Glosecki
Eugene Martin Tommy Hulett
Joey Kuras    Tim Williams

Manual ...Robin Kausch

Thanks to 

Jesus Martinez     Daniel Morais
Frederic Savoir    Cecile Chahi
Philippe Delamarre Philippe Ulrich
Sebastien Berthet  Pierre Gousseau
Bill Heineman      Jason Ferris
"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0096

LABEL_02EA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02EA
	mov [0x01], 0x00C8

DELAY_LOOP_VAR01_AT_02F7:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_02F7
	mov [0x01], 0x00C8

LABEL_0300:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0300
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0265, x=6, y=0, color=0x0C ; "   Now Go Out Of This World"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0064

LABEL_031E:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_031E
	mov [0x01], 0x00AA

DELAY_LOOP_VAR01_AT_032B:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_032B
	GameOver
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	selectVideoPage 0x00
	text id=0x017C, x=9, y=10, color=0x0C ; "string_017C"
	text id=0x017D, x=19, y=40, color=0x05 ; "string_017D"
	text id=0x017E, x=13, y=90, color=0x0B ; "string_017E"
	text id=0x0180, x=12, y=120, color=0x0D ; "string_0180"
	text id=0x017F, x=12, y=150, color=0x0E ; "string_017F"
	selectVideoPage 0xFF
	killChannel

LABEL_035A:
	load id=0x3E89
	killChannel
	selectVideoPage 0x03
	text id=0x0258, x=2, y=20, color=0x0C ; "Design ............... Eric Chahi"
	text id=0x0259, x=2, y=50, color=0x0C ; "Original Programmer .. Eric Chahi"
	text id=0x025A, x=2, y=80, color=0x0C ; "Genesis Programmer ... Michael Burton


Exec. Producer. Stephen Clarke-Willson"
	text id=0x025B, x=2, y=130, color=0x0C ; "
 U.K. Producer ........Matthew Spall
 Virgin Games, Inc. Producer . Erik Yeo
 Interplay Producer ...... Alan Pavlish

 Music ...... Tommy Tallarico
       ...... Jean-Francois Freitas

 Sound ...... Tommy Tallarico
       ...... Jean-Francois Freitas
       ...... Eric Chahi

"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	setup channel=0x3C, address=SCROLL_Y_BLIT_DISPATCHER
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x000A

DELAY_LOOP_VAR01_AT_038A:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_038A
	setup channel=0x14, address=PAL_FADE_18_TO_1D
	mov [0x01], 0x00C8

LABEL_0397:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0397
	selectVideoPage 0x00
	text id=0x025C, x=2, y=2, color=0x0C ; "string_025C"
	text id=0x025E, x=2, y=82, color=0x0C ; "string_025E"
	text id=0x025F, x=2, y=162, color=0x0C ; "string_025F"
	selectVideoPage 0xFF
	mov [0x01], 0x00C8

LABEL_03BA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03BA
	fill page=0x03, color=0x00
	selectVideoPage 0x03
	text id=0x0260, x=2, y=45, color=0x0C ; "string_0260"
	text id=0x0261, x=2, y=172, color=0x0C ; "string_0261"
	selectVideoPage 0xFF
	mov [0x01], 0x00C8

LABEL_03DA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03DA
	fill page=0x00, color=0x00
	mov [0x01], 0x00C8

LABEL_03EA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03EA
	fill page=0x03, color=0x00
	selectVideoPage 0x03
	text id=0x0263, x=5, y=50, color=0x0C ; "Title Animation . Jason Magness

Q.A. Manager .... Michael Gater

"
	text id=0x0264, x=2, y=90, color=0x0C ; "
Quality Assurance Team 

Noah Tool     Justin Norr
Danny Lewis   Mike Glosecki
Eugene Martin Tommy Hulett
Joey Kuras    Tim Williams

Manual ...Robin Kausch

Thanks to 

Jesus Martinez     Daniel Morais
Frederic Savoir    Cecile Chahi
Philippe Delamarre Philippe Ulrich
Sebastien Berthet  Pierre Gousseau
Bill Heineman      Jason Ferris
"
	selectVideoPage 0xFF
	sub [SCROLL_Y], 0x0032
	mov [0x01], 0x0096

LABEL_040E:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_040E
	mov [0x01], 0x0028

DELAY_LOOP_VAR01_AT_041B:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_041B
	fill page=0x00, color=0x00
	mov [0x01], 0x00BE

LABEL_0427:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0427
	sub [SCROLL_Y], 0x000A
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	text id=0x0265, x=6, y=0, color=0x0C ; "   Now Go Out Of This World"
	selectVideoPage 0xFF
	mov [0x01], 0x0064

LABEL_0445:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0445
	mov [0x01], 0x0096
	GameOver
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
	killChannel
