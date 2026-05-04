LABEL_101E:
	break
	video type=1, offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_101E
	killChannel
	video type=1, offset=CINEMATIC_376, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_702, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_103E
LABEL_103D:
	db 0x11

LABEL_103E:
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_367, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_368, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_369, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_370, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_371, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_372, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10A0
	video type=1, offset=CINEMATIC_373, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_374, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF

LABEL_10A0:
	call LABEL_2AE9
	jmp LABEL_10A7
LABEL_10A6:
	db 0x11

LABEL_10A7:
	call LABEL_2B0A
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	break
	jmp LABEL_10A7
LABEL_10B4:
	db 0x11

LABEL_10B5:
	call LABEL_2AFF
	jne [0x10], [HACK_VAR_67], LABEL_103E
	video type=1, offset=CINEMATIC_376, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_103E
	video type=1, offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_10D3:
	break
	jne [0x10], [HACK_VAR_67], LABEL_103E
	video type=1, offset=CINEMATIC_378, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_10EA
	djnz [0x29], LABEL_10D3

LABEL_10EA:
	break
	jne [0x10], [HACK_VAR_67], LABEL_10F6
	video type=1, offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40

LABEL_10F6:
	break
	jmp LABEL_103E
	killChannel
	video type=1, offset=CINEMATIC_365, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_702, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_103E
LABEL_1110:
	db 0x11

LABEL_1111:
	video type=1, offset=CINEMATIC_365, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_2AFF
	break
	video type=1, offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_1123:
	break
	jne [0x10], [HACK_VAR_67], LABEL_103E
	video type=1, offset=CINEMATIC_375, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_113A
	djnz [0x29], LABEL_1123

LABEL_113A:
	break
	jne [0x10], [HACK_VAR_67], LABEL_1146
	video type=1, offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40

LABEL_1146:
	break
	jmp LABEL_103E
LABEL_114A:
	db 0x11

LABEL_114B:
	mov [0x29], [0x09]
	and [0x09], 0x1FFF
	mov [0x08], [0x40]
	jl [0x09], 0x1000, DERIVE_VAR12_11_10_FROM_VAR9
	mov [0x08], [0x44]
