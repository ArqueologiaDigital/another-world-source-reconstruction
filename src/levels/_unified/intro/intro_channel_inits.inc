CINEMATIC_352		EQU 0x0630

CINEMATIC_049		EQU 0xAB5E
CINEMATIC_050		EQU 0xAB92
CINEMATIC_051		EQU 0xABC6
CINEMATIC_052		EQU 0xABFA
CINEMATIC_349		EQU 0x0648
CINEMATIC_350		EQU 0x063C
CINEMATIC_351		EQU 0x0654
CINEMATIC_353		EQU 0xAE36
CINEMATIC_354		EQU 0xAE54
CINEMATIC_355		EQU 0xAE72
CINEMATIC_356		EQU 0xAE90
CINEMATIC_357		EQU 0xAEAE
CINEMATIC_358		EQU 0xACFA
CINEMATIC_359		EQU 0xAD2E
CINEMATIC_360		EQU 0xAD7E
CINEMATIC_361		EQU 0xADC6
CINEMATIC_362		EQU 0xAE0E
CINEMATIC_363		EQU 0xB0FC
CINEMATIC_364		EQU 0xB130
CINEMATIC_365		EQU 0xB180
CINEMATIC_366		EQU 0xB200
CINEMATIC_367		EQU 0xB27C
CINEMATIC_368		EQU 0xAC82
CINEMATIC_369		EQU 0xAC96
CINEMATIC_370		EQU 0xACAA
CINEMATIC_371		EQU 0xACBE
CINEMATIC_372		EQU 0xACD2
CINEMATIC_373		EQU 0xACE6
CINEMATIC_374		EQU 0xAC1E
CINEMATIC_375		EQU 0xAC32
CINEMATIC_376		EQU 0xAC46
CINEMATIC_377		EQU 0xAC5A
CINEMATIC_378		EQU 0xAC6E

CH_0A_INIT_VAR_02:
	break
	mov [0x02], 0x0032

CH_0A_VAR_02_WAIT_LOOP:
	break
	djnz [0x02], CH_0A_VAR_02_WAIT_LOOP
	play id=0x000E, freq=0x0A, vol=0x3F, channel=0x00
	video offset=CINEMATIC_049, x=160, y=100
	break
	play id=0x0008, freq=0x0A, vol=0x3F, channel=0x01
	video offset=CINEMATIC_050, x=160, y=100
	break
	video offset=CINEMATIC_049, x=160, y=100
	break
	video offset=CINEMATIC_051, x=160, y=100
	break
	video offset=CINEMATIC_052, x=160, y=100
	jmp CH_0A_INIT_VAR_02
LABEL_0448:
	killChannel

CH_0B_INIT_VAR_03:
	break
	mov [0x03], 0x0046

CH_0B_VAR_03_WAIT_LOOP:
	break
	djnz [0x03], CH_0B_VAR_03_WAIT_LOOP
	play id=0x000F, freq=0x0A, vol=0x3F, channel=0x00
	video offset=CINEMATIC_374, x=160, y=100
	break
	video offset=CINEMATIC_375, x=160, y=100
	break
	video offset=CINEMATIC_376, x=160, y=100
	break
	video offset=CINEMATIC_377, x=160, y=100
	break
	video offset=CINEMATIC_378, x=160, y=100
	break
	video offset=CINEMATIC_377, x=160, y=100
	break
	video offset=CINEMATIC_376, x=160, y=100
	break
	video offset=CINEMATIC_375, x=160, y=100
	break
	video offset=CINEMATIC_374, x=160, y=100
	play id=0x0008, freq=0x0C, vol=0x3F, channel=0x03
	jmp CH_0B_INIT_VAR_03
LABEL_048E:
	killChannel

CH_0C_INIT_VAR_04:
	break
	mov [0x04], 0x0050

CH_0C_VAR_04_WAIT_LOOP:
	break
	djnz [0x04], CH_0C_VAR_04_WAIT_LOOP
	video offset=CINEMATIC_368, x=160, y=100
	break
	video offset=CINEMATIC_369, x=160, y=100
	break
	video offset=CINEMATIC_370, x=160, y=100
	break
	video offset=CINEMATIC_371, x=160, y=100
	break
	video offset=CINEMATIC_372, x=160, y=100
	break
	video offset=CINEMATIC_373, x=160, y=100
	break
	video offset=CINEMATIC_372, x=180, y=100
	break
	video offset=CINEMATIC_372, x=200, y=100
	play id=0x0008, freq=0x01, vol=0x3F, channel=0x02
	jmp CH_0C_INIT_VAR_04
LABEL_04C9:
	killChannel

CH_0D_INIT_VAR_05:
	break
	mov [0x05], 0x0014

CH_0D_VAR_05_WAIT_20:
	break
	djnz [0x05], CH_0D_VAR_05_WAIT_20
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x00
	video offset=CINEMATIC_358, x=160, y=100
	break
	play id=0x000E, freq=0x08, vol=0x3F, channel=0x01
	video offset=CINEMATIC_359, x=160, y=100
	break
	video offset=CINEMATIC_360, x=160, y=100
	break
	video offset=CINEMATIC_361, x=160, y=100
	break
	video offset=CINEMATIC_362, x=160, y=100
	break
	mov [0x05], 0x006E

CH_0D_VAR_05_WAIT_110:
	break
	djnz [0x05], CH_0D_VAR_05_WAIT_110
	video offset=CINEMATIC_363, x=160, y=100
	break
	video offset=CINEMATIC_364, x=160, y=100
	break
	video offset=CINEMATIC_365, x=160, y=100
	break
	video offset=CINEMATIC_366, x=160, y=100
	break
	video offset=CINEMATIC_367, x=160, y=100
	mov [0x05], 0x0046

CH_0D_VAR_05_WAIT_70:
	break
	djnz [0x05], CH_0D_VAR_05_WAIT_70
	jmp CH_0D_INIT_VAR_05
LABEL_0526:
	killChannel

CH_0E_INIT_VAR_06:
	break
	mov [0x06], 0x003C

CH_0E_VAR_06_WAIT_60:
	break
	djnz [0x06], CH_0E_VAR_06_WAIT_60
	setPalette 0x02
	break
	break
	break
	setPalette 0x19
	break
	mov [0x06], 0x0064

CH_0E_VAR_06_WAIT_100:
	break
	djnz [0x06], CH_0E_VAR_06_WAIT_100
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

DRIFT_VAR07_BY_7_FOR_70:
	break
	add [0x07], 0x0007
	djnz [0x08], DRIFT_VAR07_BY_7_FOR_70
	mov [0x09], 0x0082
	mov [0x07], 0x0000
	mov [0x08], 0x0032

DRIFT_VAR07_BY_7_FOR_50:
	break
	add [0x07], 0x0007
	djnz [0x08], DRIFT_VAR07_BY_7_FOR_50
	killChannel

CH_10_DRAW_CIN_353_PARTICLE:
	break
	video offset=CINEMATIC_353, x=[0x07], y=[0x09], zoom=0x40
	break
	video offset=CINEMATIC_354, x=[0x07], y=[0x09], zoom=0x40
	break
	video offset=CINEMATIC_355, x=[0x07], y=[0x09], zoom=0x40
	break
	video offset=CINEMATIC_356, x=[0x07], y=[0x09], zoom=0x40
	break
	video offset=CINEMATIC_357, x=[0x07], y=[0x09], zoom=0x40
	jmp CH_10_DRAW_CIN_353_PARTICLE
LABEL_05A7:
	killChannel

CH_11_INIT_PARTICLE_POS_2:
	break
	mov [0x0A], 0xFFCE
	mov [0x0B], 0x0032

CH_11_DRAW_PARTICLES_LOOP:
	video offset=CINEMATIC_352, x=[0x0a], y=50, zoom=0x40
	video offset=CINEMATIC_350, x=[0x0a], y=20, zoom=0x40
	video offset=CINEMATIC_351, x=[0x0a], y=110, zoom=0x40
	video offset=CINEMATIC_350, x=[0x0a], y=180, zoom=0x40
	add [0x0A], 0x000A
	break
	djnz [0x0B], CH_11_DRAW_PARTICLES_LOOP
	jmp CH_11_INIT_PARTICLE_POS_2
LABEL_05D1:
	killChannel

CH_12_INIT_PARTICLE_POS_3:
	break
	mov [0x0C], 0xFFB0
	mov [0x0D], 0x003C

CH_12_DRAW_PARTICLES_LOOP:
	video offset=CINEMATIC_349, x=[0x0c], y=140, zoom=0x40
	video offset=CINEMATIC_350, x=[0x0c], y=100, zoom=0x40
	video offset=CINEMATIC_350, x=[0x0c], y=80, zoom=0x40
	video offset=CINEMATIC_351, x=[0x0c], y=10, zoom=0x40
	add [0x0C], 0x0009
	break
	djnz [0x0D], CH_12_DRAW_PARTICLES_LOOP
	jmp CH_12_INIT_PARTICLE_POS_3
LABEL_05FB:
	killChannel

