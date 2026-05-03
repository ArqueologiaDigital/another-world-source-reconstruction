CH_0A_INIT_VAR_02:
	break
	mov [0x02], 0x0032

LABEL_041C:
	break
	djnz [0x02], LABEL_041C
	play id=0x000E, freq=0x0A, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_049, x=160, y=100
	break
	play id=0x0008, freq=0x0A, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_050, x=160, y=100
	break
	video type=1, offset=CINEMATIC_049, x=160, y=100
	break
	video type=1, offset=CINEMATIC_051, x=160, y=100
	break
	video type=1, offset=CINEMATIC_052, x=160, y=100
	jmp CH_0A_INIT_VAR_02
LABEL_0448:
	killChannel

CH_0B_INIT_VAR_03:
	break
	mov [0x03], 0x0046

LABEL_044E:
	break
	djnz [0x03], LABEL_044E
	play id=0x000F, freq=0x0A, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_374, x=160, y=100
	break
	video type=1, offset=CINEMATIC_375, x=160, y=100
	break
	video type=1, offset=CINEMATIC_376, x=160, y=100
	break
	video type=1, offset=CINEMATIC_377, x=160, y=100
	break
	video type=1, offset=CINEMATIC_378, x=160, y=100
	break
	video type=1, offset=CINEMATIC_377, x=160, y=100
	break
	video type=1, offset=CINEMATIC_376, x=160, y=100
	break
	video type=1, offset=CINEMATIC_375, x=160, y=100
	break
	video type=1, offset=CINEMATIC_374, x=160, y=100
	play id=0x0008, freq=0x0C, vol=0x3F, channel=0x03
	jmp CH_0B_INIT_VAR_03
LABEL_048E:
	killChannel

CH_0C_INIT_VAR_04:
	break
	mov [0x04], 0x0050

LABEL_0494:
	break
	djnz [0x04], LABEL_0494
	video type=1, offset=CINEMATIC_368, x=160, y=100
	break
	video type=1, offset=CINEMATIC_369, x=160, y=100
	break
	video type=1, offset=CINEMATIC_370, x=160, y=100
	break
	video type=1, offset=CINEMATIC_371, x=160, y=100
	break
	video type=1, offset=CINEMATIC_372, x=160, y=100
	break
	video type=1, offset=CINEMATIC_373, x=160, y=100
	break
	video type=1, offset=CINEMATIC_372, x=180, y=100
	break
	video type=1, offset=CINEMATIC_372, x=200, y=100
	play id=0x0008, freq=0x01, vol=0x3F, channel=0x02
	jmp CH_0C_INIT_VAR_04
LABEL_04C9:
	killChannel

CH_0D_INIT_VAR_05:
	break
	mov [0x05], 0x0014

LABEL_04CF:
	break
	djnz [0x05], LABEL_04CF
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_358, x=160, y=100
	break
	play id=0x000E, freq=0x08, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_359, x=160, y=100
	break
	video type=1, offset=CINEMATIC_360, x=160, y=100
	break
	video type=1, offset=CINEMATIC_361, x=160, y=100
	break
	video type=1, offset=CINEMATIC_362, x=160, y=100
	break
	mov [0x05], 0x006E

LABEL_04FD:
	break
	djnz [0x05], LABEL_04FD
	video type=1, offset=CINEMATIC_363, x=160, y=100
	break
	video type=1, offset=CINEMATIC_364, x=160, y=100
	break
	video type=1, offset=CINEMATIC_365, x=160, y=100
	break
	video type=1, offset=CINEMATIC_366, x=160, y=100
	break
	video type=1, offset=CINEMATIC_367, x=160, y=100
	mov [0x05], 0x0046

LABEL_051E:
	break
	djnz [0x05], LABEL_051E
	jmp CH_0D_INIT_VAR_05
LABEL_0526:
	killChannel

CH_0E_INIT_VAR_06:
	break
	mov [0x06], 0x003C

LABEL_052C:
	break
	djnz [0x06], LABEL_052C
	setPalette 0x02
	break
	break
	break
	setPalette 0x19
	break
	mov [0x06], 0x0064

LABEL_053F:
	break
	djnz [0x06], LABEL_053F
	setPalette 0x02
	break
	break
	break
	setPalette 0x19
	break
	break
	break
	setPalette 0x02
	break
	break
	break
	setPalette 0x19
	killChannel

CH_0F_INIT_PARTICLE_POS:
	break
	mov [0x09], 0x0096
	mov [0x07], 0x0000
	mov [0x08], 0x0046

LABEL_0567:
	break
	add [0x07], 0x0007
	djnz [0x08], LABEL_0567
	mov [0x09], 0x0082
	mov [0x07], 0x0000
	mov [0x08], 0x0032

LABEL_057C:
	break
	add [0x07], 0x0007
	djnz [0x08], LABEL_057C
	killChannel

CH_10_DRAW_CIN_353_PARTICLE:
	break
	video type=1, offset=CINEMATIC_353, x=[0x07], y=[0x09], zoom=0x40
	break
	video type=1, offset=CINEMATIC_354, x=[0x07], y=[0x09], zoom=0x40
	break
	video type=1, offset=CINEMATIC_355, x=[0x07], y=[0x09], zoom=0x40
	break
	video type=1, offset=CINEMATIC_356, x=[0x07], y=[0x09], zoom=0x40
	break
	video type=1, offset=CINEMATIC_357, x=[0x07], y=[0x09], zoom=0x40
	jmp CH_10_DRAW_CIN_353_PARTICLE
LABEL_05A7:
	killChannel

CH_11_INIT_PARTICLE_POS_2:
	break
	mov [0x0A], 0xFFCE
	mov [0x0B], 0x0032

LABEL_05B1:
	video type=1, offset=CINEMATIC_352, x=[0x0a], y=50, zoom=0x40
	video type=1, offset=CINEMATIC_350, x=[0x0a], y=20, zoom=0x40
	video type=1, offset=CINEMATIC_351, x=[0x0a], y=110, zoom=0x40
	video type=1, offset=CINEMATIC_350, x=[0x0a], y=180, zoom=0x40
	add [0x0A], 0x000A
	break
	djnz [0x0B], LABEL_05B1
	jmp CH_11_INIT_PARTICLE_POS_2
LABEL_05D1:
	killChannel

CH_12_INIT_PARTICLE_POS_3:
	break
	mov [0x0C], 0xFFB0
	mov [0x0D], 0x003C

LABEL_05DB:
	video type=1, offset=CINEMATIC_349, x=[0x0c], y=140, zoom=0x40
	video type=1, offset=CINEMATIC_350, x=[0x0c], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_350, x=[0x0c], y=80, zoom=0x40
	video type=1, offset=CINEMATIC_351, x=[0x0c], y=10, zoom=0x40
	add [0x0C], 0x0009
	break
	djnz [0x0D], LABEL_05DB
	jmp CH_12_INIT_PARTICLE_POS_3
LABEL_05FB:
	killChannel

