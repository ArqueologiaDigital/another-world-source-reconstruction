LABEL_0E00:
	call LABEL_0E07
	jmp LABEL_3867
LABEL_0E06:
	db 0x05

LABEL_0E07:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_0E1D:
	db 0x11

LABEL_0E1E:
	call LABEL_0E33
	jmp LABEL_389A
LABEL_0E24:
	db 0x05

LABEL_0E25:
	call LABEL_0E33
	mov [0x21], 0xFFEC
	sub [0x27], 0x0040
	jmp LABEL_389A

LABEL_0E33:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0xFF24
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_0E49:
	db 0x11

LABEL_0E4A:
	break
	je [0x72], [HACK_VAR_67], LABEL_0E4A
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_0E61
	jmp LABEL_0E4A

LABEL_0E61:
	call LABEL_0E1E
	mov [0xAF], [0x3B]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF_AT_0E6B:
	break
	djnz [0xAF], DELAY_LOOP_VARAF_AT_0E6B
	jmp LABEL_0E4A
LABEL_0E73:
	db 0x11

LABEL_0E74:
	video offset=CINEMATIC_113, x=160, y=[0x19], zoom=0x40
	play id=0x005B, freq=0x05, vol=0x0A, channel=0x02
	break
	video offset=CINEMATIC_114, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_115, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_116, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_117, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_118, x=160, y=[0x19], zoom=0x40
	break
	jmp LABEL_0E74
LABEL_0EA1:
	db 0x11

LABEL_0EA2:
	video offset=CINEMATIC_107, x=160, y=[0x19], zoom=0x40
	play id=0x005B, freq=0x07, vol=0x0A, channel=0x03
	break
	video offset=CINEMATIC_108, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_109, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_110, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_111, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_112, x=160, y=[0x19], zoom=0x40
	break
	jmp LABEL_0EA2
LABEL_0ECF:
	db 0x11

LABEL_0ED0:
	video offset=CINEMATIC_119, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_120, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_121, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_122, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_123, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_124, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_125, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_126, x=160, y=[0x19], zoom=0x40
	break
	jmp LABEL_0ED0
LABEL_0F03:
	db 0x11

LABEL_0F04:
	video offset=CINEMATIC_154, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_155, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_156, x=160, y=[0x19], zoom=0x40
	killChannel

LABEL_0F1C:
	video offset=CINEMATIC_151, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x00
	break
	video offset=CINEMATIC_152, x=160, y=[0x19], zoom=0x40
	break
	video offset=CINEMATIC_153, x=160, y=[0x19], zoom=0x40
	killChannel

LABEL_0F34:
	video offset=CINEMATIC_149, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x0C, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_150, x=160, y=[0x19], zoom=0x40
	killChannel

LABEL_0F46:
	video offset=CINEMATIC_132, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x1C, channel=0x00
	break
	video offset=CINEMATIC_133, x=160, y=[0x19], zoom=0x40
	killChannel

LABEL_0F58:
	add [0x01], 0x0003
	video offset=CINEMATIC_134, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_135, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video offset=CINEMATIC_136, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_135, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0F7E:
	db 0x11

LABEL_0F7F:
	sub [0x01], 0x0003
	video offset=CINEMATIC_280, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video offset=CINEMATIC_281, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x0003

LABEL_0F9A:
	break
	video offset=CINEMATIC_282, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_0F9A
	setup channel=0x15, address=DRAW_CIN_284_BLOCK_95B
	mov [0x03], 0x0003

LABEL_0FAC:
	break
	video offset=CINEMATIC_283, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_0FAC
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0FB9:
	db 0x11

DRAW_CIN_284_BLOCK_95B:
	video offset=CINEMATIC_284, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_285, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_286, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_287, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_288, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_289, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_290, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_291, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_292, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_293, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_294, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_297, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40

LABEL_1019:
	break
	video offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_1019
LABEL_1022:
	db 0x11

LABEL_1023:
	video offset=CINEMATIC_298, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_300, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_137_138_BLOCK
LABEL_103D:
	db 0x11

LABEL_103E:
	video offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40

DRAW_CIN_137_138_BLOCK:
	selectVideoPage 0x00
	video offset=CINEMATIC_137, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_138, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_139, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_140, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_141, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_142, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_143, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_144, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_145, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	killChannel
	video offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40

LABEL_10A6:
	break
	video offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_10A6
	killChannel
	video offset=CINEMATIC_376, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_702, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_10C6
LABEL_10C5:
	db 0x11

LABEL_10C6:
	jne [0x10], [HACK_VAR_67], LABEL_1128
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_367, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_368, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_369, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_370, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_371, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_372, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_1128
	video offset=CINEMATIC_373, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_374, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF

LABEL_1128:
	call LABEL_2B8B
	jmp LABEL_112F
LABEL_112E:
	db 0x11

LABEL_112F:
	call LABEL_2BAC
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	break
	jmp LABEL_112F
LABEL_113C:
	db 0x11

LABEL_113D:
	call LABEL_2BA1
	jne [0x10], [HACK_VAR_67], LABEL_10C6
	video offset=CINEMATIC_376, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_10C6
	video offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_115B:
	break
	jne [0x10], [HACK_VAR_67], LABEL_10C6
	video offset=CINEMATIC_378, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_1172
	djnz [0x29], LABEL_115B

LABEL_1172:
	break
	jne [0x10], [HACK_VAR_67], LABEL_117E
	video offset=CINEMATIC_377, x=[0x07], y=[0x08], zoom=0x40

LABEL_117E:
	break
	jmp LABEL_10C6
	killChannel
	video offset=CINEMATIC_365, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_702, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_10C6
LABEL_1198:
	db 0x11

LABEL_1199:
	video offset=CINEMATIC_365, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_2BA1
	break
	video offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_11AB:
	break
	jne [0x10], [HACK_VAR_67], LABEL_10C6
	video offset=CINEMATIC_375, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_11C2
	djnz [0x29], LABEL_11AB

LABEL_11C2:
	break
	jne [0x10], [HACK_VAR_67], LABEL_11CE
	video offset=CINEMATIC_366, x=[0x07], y=[0x08], zoom=0x40

LABEL_11CE:
	break
	jmp LABEL_10C6
LABEL_11D2:
	db 0x11

LABEL_11D3:
	mov [0x29], [0x09]
	and [0x09], 0x1FFF
	mov [0x08], [0x40]
	jl [0x09], 0x1000, DERIVE_VAR12_11_10_FROM_VAR9
	mov [0x08], [0x44]
