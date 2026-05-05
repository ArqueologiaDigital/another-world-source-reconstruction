LABEL_1D2F:
	db 0x11

LABEL_1D30:
	mov [0x27], 0x0000
	selectVideoPage 0x00
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	deleteChannels first=0x01, last=0x04
	ret

LABEL_1D52:
	setPalette 0x02
	selectVideoPage 0x00
	call FILL_AND_DRAW_CIN_24_28
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	killChannel

LABEL_1D63:
	setup channel=0x01, address=LABEL_1DF1
	setup channel=0x02, address=LABEL_1DFA
	setup channel=0x03, address=LABEL_1ECD
	setup channel=0x04, address=LABEL_1DFA
	setup channel=0x05, address=LABEL_1DA3
	play id=0x0061, freq=0x0A, vol=0x07, channel=0x02
	mov [0x80], 0x005A
	shl [0x80], 0x0008
	or [0x80], 0x0096
	mov [0x81], 0x0046
	shl [0x81], 0x0008
	or [0x81], 0x0094
	mov [0x82], 0x006E
	shl [0x82], 0x0008
	or [0x82], 0x0082
	ret
LABEL_1DA2:
	db 0x11

LABEL_1DA3:
	mov [0xF8], [0x31]
	and [0xF8], 0x000F
	jne [0xF8], 0x00, LABEL_1DEA
	mov [0xF8], [0x31]
	and [0xF8], 0x003F
	selectVideoPage 0x00
	jne [0xF8], 0x00, LABEL_1DC6
	video offset=CINEMATIC_003, x=160, y=100
	jmp LABEL_1DEA

LABEL_1DC6:
	jne [0xF8], 0x10, LABEL_1DD3
	video offset=CINEMATIC_002, x=160, y=100
	jmp LABEL_1DEA

LABEL_1DD3:
	jne [0xF8], 0x20, LABEL_1DE0
	video offset=CINEMATIC_001, x=160, y=100
	jmp LABEL_1DEA

LABEL_1DE0:
	jne [0xF8], 0x30, LABEL_1DEA
	video offset=CINEMATIC_000, x=160, y=100

LABEL_1DEA:
	selectVideoPage 0xFF
	break
	jmp LABEL_1DA3
LABEL_1DF0:
	db 0x11

LABEL_1DF1:
	mov [0x27], 0x0000
	break
	jmp LABEL_1DF1
LABEL_1DF9:
	db 0x11

LABEL_1DFA:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video offset=CINEMATIC_014, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1E0C

LABEL_1E09:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1E0C:
	video offset=CINEMATIC_015, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1E39
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E24:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E57
	jmp LABEL_1E24

LABEL_1E39:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_016, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1E4E
	jmp LABEL_1E39

LABEL_1E4E:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_017, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1E57:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_018, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_019, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_020, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_021, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x1E, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1E09
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_022, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_023, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1E09
LABEL_1ECC:
	db 0x11

LABEL_1ECD:
	call INCREMENT_VAR27_AND_DISPATCH
	selectVideoPage 0x00
	video offset=CINEMATIC_004, x=[0x24], y=[0x25], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1EDF

LABEL_1EDC:
	call INCREMENT_VAR27_AND_DISPATCH

LABEL_1EDF:
	video offset=CINEMATIC_005, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x39], 0x02, LABEL_1F0C
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1EF7:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1F2A
	jmp LABEL_1EF7

LABEL_1F0C:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_006, x=[0x24], y=[0x25], zoom=0x40
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_1F21
	jmp LABEL_1F0C

LABEL_1F21:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_007, x=[0x24], y=[0x25], zoom=0x40
	break

LABEL_1F2A:
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_008, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_009, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_010, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_011, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	play id=0x0065, freq=0x20, vol=0x20, channel=0x03
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jne [0x39], 0x00, LABEL_1EDC
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_012, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	call INCREMENT_VAR27_AND_DISPATCH
	video offset=CINEMATIC_013, x=[0x24], y=[0x25], zoom=0x40
	break
	jmp LABEL_1EDC
LABEL_1F9F:
	db 0x11

LABEL_1FA0:
	selectVideoPage 0x00
	video offset=CINEMATIC_569, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_570, x=228, y=175
	break
	video offset=CINEMATIC_571, x=232, y=175
	video offset=CINEMATIC_572, x=160, y=100
	break
	video offset=CINEMATIC_573, x=245, y=175
	video offset=CINEMATIC_572, x=160, y=100
	killChannel

DRAW_CIN_570_574_BLOCK:
	mov [0x57], 0x0002
	video offset=CINEMATIC_574, x=239, y=175
	video offset=CINEMATIC_572, x=160, y=100
	break
	video offset=CINEMATIC_570, x=230, y=175
	video offset=CINEMATIC_574, x=230, y=175
	video offset=CINEMATIC_572, x=160, y=100
	break
	video offset=CINEMATIC_570, x=228, y=175
	break
	video offset=CINEMATIC_575, x=227, y=175
	break
	video offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0x00
	video offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0xFF
	killChannel

DRAW_CIN_576_578_BLOCK:
	video offset=CINEMATIC_576, x=215, y=131
	break
	video offset=CINEMATIC_577, x=227, y=141
	break
	mov [0x31], 0x0000
	video offset=CINEMATIC_578, x=231, y=158
	break
	video offset=CINEMATIC_579, x=239, y=175
	break
	video offset=CINEMATIC_578, x=243, y=174
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_274, x=245, y=175
	mov [0x31], 0x0000
	break
	video offset=CINEMATIC_580, x=247, y=175
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_274, x=249, y=175
	break
	video offset=CINEMATIC_274, x=250, y=175
	selectVideoPage 0x00
	video offset=CINEMATIC_274, x=251, y=175
	selectVideoPage 0xFF
	killChannel

LABEL_203A:
	call LABEL_63B1
	add [0x07], 0x0001
	break
	call LABEL_6390
	add [0x07], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	break
	call GUARDED_DRAW_CIN_342
	sub [0x01], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	break
	jmp LABEL_5A05
LABEL_2065:
	db 0x11

LABEL_2066:
	call LABEL_5811
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	break
	call GUARDED_DRAW_CIN_342
	add [0x07], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	add [0x07], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	break
	jmp LABEL_6B91
LABEL_2091:
	db 0x11

LABEL_2092:
	mov [0x29], 0x0002
	call LABEL_5811
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [0x07], 0x0001
	break
	mov [0x29], 0x000A
	mov [0x0E], 0x0002

LABEL_20AE:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_20AE
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x0003

LABEL_20C2:
	call LABEL_5811
	break
	djnz [0x29], LABEL_20C2
	mov [0x0E], 0x0004
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x00FF
	jmp LABEL_5A05
LABEL_20D9:
	db 0x11

LABEL_20DA:
	call LABEL_5811
	mov [0x0E], 0x0005
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [0x07], 0x0001

LABEL_20ED:
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_21F2
	jl [0x3A], 0x02, LABEL_21C6
	jl [0x3A], 0x04, LABEL_2234
	je [0x3A], 0x04, LABEL_213C
	je [0x3A], 0x05, LABEL_2168
	je [0x3A], 0x06, LABEL_219A
	jmp LABEL_2118

LABEL_2118:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0071, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	call GUARDED_DRAW_CIN_338_339
	break
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_20ED

LABEL_213C:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0070, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_20ED

LABEL_2168:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0072, freq=0x11, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	play id=0x0071, freq=0x0F, vol=0x40, channel=0x01
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_20ED

LABEL_219A:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0070, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_20ED

LABEL_21C6:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0072, freq=0x0F, vol=0x40, channel=0x01
	mov [0x0E], 0x0003
	break
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call LABEL_5811
	break
	call GUARDED_DRAW_CIN_338_339
	mov [0x29], 0x000A

LABEL_21E7:
	break
	call GUARDED_DRAW_CIN_242_243
	djnz [0x29], LABEL_21E7
	jmp LABEL_20ED

LABEL_21F2:
	call LABEL_582F
	break
	call LABEL_582F
	jl [0x15], 0x1E, LABEL_20ED
	break
	setPalette 0x0F
	play id=0x0052, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_630, x=[0x07], y=110, zoom=0x40
	call LABEL_582F
	break
	setPalette 0x02
	video offset=CINEMATIC_631, x=[0x07], y=80, zoom=0x40
	call GUARDED_DRAW_CIN_338_339
	break
	video offset=CINEMATIC_630, x=[0x07], y=65516, zoom=0x40
	call GUARDED_DRAW_CIN_242_243
	je [0x57], 0x02, LABEL_20ED
	setup channel=0x11, address=DRAW_CIN_570_574_BLOCK
	jmp LABEL_20ED

LABEL_2234:
	mov [0x29], 0x0004
	call GUARDED_DRAW_CIN_338_339

LABEL_223B:
	break
	call LABEL_5811
	djnz [0x29], LABEL_223B
	jmp LABEL_20ED
LABEL_2246:
	db 0x11

LABEL_2247:
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000

LABEL_225E:
	break
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_225E
LABEL_2265:
	db 0x11

LABEL_2266:
	call LABEL_6390
	add [0x07], 0x0001
	break
	mov [0x0E], 0x0001
	call GUARDED_HERO_ANIM_CV_128
	add [0x07], 0x0001
	break
	mov [0x0D], 0x0001
	mov [0x0E], 0x0000
	call LABEL_6390
	break
	mov [0x0E], 0x0002
	mov [0x29], 0x0003

LABEL_228E:
	call LABEL_63B1
	break
	djnz [0x29], LABEL_228E
	call GUARDED_DRAW_CIN_342
	break
	mov [0x0E], 0x0000
	sub [0x07], 0x0001
	call GUARDED_DRAW_CIN_242_243
	break

LABEL_22A6:
	sub [0x07], 0x0001
	mov [0x0D], 0x0001
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	mov [0x29], 0x00FF
	jmp LABEL_5A05
LABEL_22C1:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_643E
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_22D4:
	call LABEL_66DF
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_22E6:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_22F7
	mov [0x2F], 0x0005
	jmp LABEL_25BB

LABEL_22F7:
	jl [0xF8], 0x1000, LABEL_2360
	jmp LABEL_2302
LABEL_2301:
	db 0x11

LABEL_2302:
	call LABEL_6737
	break
	call LABEL_66F1
	break
	call LABEL_6725
	break
	call LABEL_22D4
	jne [0x10], [HACK_VAR_67], LABEL_231C
	video offset=CINEMATIC_196, x=[0x21], y=[0x22], zoom=0x40

LABEL_231C:
	break
	call LABEL_22D4
	jne [0x10], [HACK_VAR_67], LABEL_232B
	video offset=CINEMATIC_197, x=[0x21], y=[0x22], zoom=0x40

LABEL_232B:
	break
	call LABEL_22D4
	jne [0x10], [HACK_VAR_67], LABEL_233A
	video offset=CINEMATIC_198, x=[0x21], y=[0x22], zoom=0x40

LABEL_233A:
	break
	call LABEL_22D4
	jne [0x10], [HACK_VAR_67], LABEL_2349
	video offset=CINEMATIC_210, x=[0x21], y=[0x22], zoom=0x40

LABEL_2349:
	break
	call LABEL_22D4
	jne [0x10], [HACK_VAR_67], LABEL_235B
	video offset=CINEMATIC_200, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_4231

LABEL_235B:
	break
	jmp LABEL_2619
LABEL_235F:
	db 0x11

LABEL_2360:
	call LABEL_64C2
	break
	call LABEL_645B
	break
	call LABEL_64A5
	break
	call COMPUTE_OFFSET_VAR21_22
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [0x10], [HACK_VAR_67], LABEL_2380
	video offset=CINEMATIC_196, x=[0x21], y=[0x22], zoom=0x40

LABEL_2380:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_238F
	video offset=CINEMATIC_197, x=[0x21], y=[0x22], zoom=0x40

LABEL_238F:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_23A4
	video offset=CINEMATIC_198, x=[0x21], y=[0x22], zoom=0x40
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01

LABEL_23A4:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_23B3
	video offset=CINEMATIC_199, x=[0x21], y=[0x22], zoom=0x40

LABEL_23B3:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_23C5
	video offset=CINEMATIC_200, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_4231

LABEL_23C5:
	break
	jmp LABEL_25F9
LABEL_23C9:
	db 0x11

LABEL_23CA:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_23CA
	jl [0x70], 0xC8, LABEL_23CA

LABEL_23DB:
	jne [HACK_VAR_67], 0x04, LABEL_23EF
	call LABEL_244E
	je [0x23], 0x00, LABEL_2432
	video offset=CINEMATIC_202, x=[0x21], y=[0x08], zoom=0x40

LABEL_23EF:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2404
	call LABEL_244E
	je [0x23], 0x00, LABEL_2432
	video offset=CINEMATIC_203, x=[0x21], y=[0x08], zoom=0x40

LABEL_2404:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2419
	call LABEL_244E
	je [0x23], 0x00, LABEL_2432
	video offset=CINEMATIC_204, x=[0x21], y=[0x08], zoom=0x40

LABEL_2419:
	break
	jne [HACK_VAR_67], 0x04, LABEL_242E
	call LABEL_244E
	je [0x23], 0x00, LABEL_2432
	video offset=CINEMATIC_203, x=[0x21], y=[0x08], zoom=0x40

LABEL_242E:
	break
	jmp LABEL_23DB

LABEL_2432:
	call LABEL_244E
	video offset=CINEMATIC_210, x=[0x21], y=[0x08], zoom=0x40
	break
	call LABEL_244E
	video offset=CINEMATIC_200, x=[0x21], y=[0x71], zoom=0x40
	mov [0x08], [0x71]
	mov [0x10], 0x0004
	call LABEL_4231
	killChannel

LABEL_244E:
	mov [0x08], [0x71]
	sub [0x08], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_2467
	add [0x33], 0x0003
	ret

LABEL_2467:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_2473:
	je [0x08], [0x52], LABEL_250D
	jmp LABEL_248D

LABEL_247C:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_2639
	jmp LABEL_267B

LABEL_248D:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_6432
	break
	mov [0x08], [0x52]
	call LABEL_6432
	jmp LABEL_247C

LABEL_24A1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_202, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24AD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_203, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24B9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_204, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24C5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_190, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24D1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_191, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24DD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_192, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_193, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_24F5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_194, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_2501:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_195, x=[0x21], y=[0x22], zoom=0x40
	ret

LABEL_250D:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_6426
	break
	mov [0x08], [0x51]
	call LABEL_6426
	jmp LABEL_247C
LABEL_2521:
	db 0x11

LABEL_2522:
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_196, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_197, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_198, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_199, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0003

LABEL_254A:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24A1
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24AD
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24B9
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24AD
	break
	djnz [0x29], LABEL_254A
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24C5
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24D1
	break
	mov [0x29], 0x0002

LABEL_257C:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24DD
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24E9
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_24F5
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2501
	break
	djnz [0x29], LABEL_257C
	jne [HACK_VAR_67], [0x10], LABEL_25F9
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000
	jmp LABEL_25F9
LABEL_25BA:
	db 0x11

LABEL_25BB:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_25C9
	sub [0xF8], 0x2000

LABEL_25C9:
	jl [0xF8], 0x1000, LABEL_25DD
	je [0x2F], 0x05, LABEL_260A
	je [0x2F], 0x0F, LABEL_266C
	killChannel

LABEL_25DD:
	je [0x2F], 0x05, LABEL_25EA
	je [0x2F], 0x0F, LABEL_262A
	killChannel

LABEL_25EA:
	jl [0x11], 0x2000, LABEL_25F9
	sub [0x11], 0x2000
	call LABEL_64ED
	break

LABEL_25F9:
	call LABEL_64C2
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_25F9
LABEL_2609:
	db 0x11

LABEL_260A:
	jl [0x11], 0x2000, LABEL_2619
	sub [0x11], 0x2000
	call LABEL_675D
	break

LABEL_2619:
	call LABEL_6737
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2619
LABEL_2629:
	db 0x11

LABEL_262A:
	jge [0x11], 0x2000, LABEL_2639
	add [0x11], 0x2000
	call LABEL_64ED
	break

LABEL_2639:
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2639
LABEL_2649:
	db 0x11

GAME_LOOP_DRAW_CIN_242_243:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_DRAW_CIN_242_243
LABEL_265A:
	db 0x11

LABEL_265B:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_265B
LABEL_266B:
	db 0x11

LABEL_266C:
	jge [0x11], 0x2000, LABEL_267B
	add [0x11], 0x2000
	call LABEL_675D
	break

LABEL_267B:
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_267B
LABEL_268B:
	db 0x11

MAIN_GAME_LOOP_HERO_128:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp MAIN_GAME_LOOP_HERO_128
LABEL_269C:
	db 0x11

LABEL_269D:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_269D
LABEL_26AD:
	db 0x11

LABEL_26AE:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_26C5
	je [0x2F], 0x10, LABEL_69DD
	jmp LABEL_68DA

LABEL_26C5:
	je [0x2F], 0x10, LABEL_5851
	jmp LABEL_5BDF
LABEL_26CE:
	db 0x11

LABEL_26CF:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_26E6
	je [0x2F], 0x01, LABEL_69DD
	jmp LABEL_2A56

LABEL_26E6:
	je [0x2F], 0x02, LABEL_5851
	jmp LABEL_2A81
LABEL_26EF:
	db 0x11

LABEL_26F0:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_26CF
	mov [0x2F], 0x0002
	jmp LABEL_26CF

LABEL_2701:
	jg [0x29], [0x07], LABEL_68DA
	jmp LABEL_5BDF
	killChannel
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_2723
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_25EA
	jmp LABEL_260A

LABEL_2723:
	jl [0xF8], 0x1000, LABEL_272E
	jmp LABEL_277B
LABEL_272D:
	db 0x11

LABEL_272E:
	call LABEL_654A
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_2739:
	break
	call LABEL_6579
	djnz [0x29], LABEL_2739
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	call LABEL_359F
	break
	call LABEL_65BA
	break
	call LABEL_65BA
	break
	call LABEL_6593
	mov [0x29], 0x0005

LABEL_275E:
	break
	call LABEL_6579
	djnz [0x29], LABEL_275E
	mov [0x0E], 0x0000

LABEL_276A:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_64C2
	jmp LABEL_276A
	killChannel

LABEL_277B:
	call JUNK__67A0
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_2786:
	break
	call LABEL_67CF
	djnz [0x29], LABEL_2786
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	call LABEL_359F
	break
	call LABEL_6810
	break
	call LABEL_6810
	break
	call LABEL_67E9
	mov [0x29], 0x0005

LABEL_27AB:
	break
	call LABEL_67CF
	djnz [0x29], LABEL_27AB
	mov [0x0E], 0x0000

LABEL_27B7:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6737
	jmp LABEL_27B7
LABEL_27C7:
	db 0x11

LABEL_27C8:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_27EF
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_27E6
	je [0x2F], 0x07, LABEL_2968
	jmp LABEL_260A

LABEL_27E6:
	je [0x2F], 0x07, LABEL_2815
	jmp LABEL_25EA

LABEL_27EF:
	jl [0xF8], 0x1000, LABEL_2805
	je [0x2F], 0x08, LABEL_2999
	je [0x2F], 0x09, LABEL_29DE
	jmp LABEL_266C

LABEL_2805:
	je [0x2F], 0x08, LABEL_2846
	je [0x2F], 0x09, LABEL_288B
	jmp LABEL_262A
LABEL_2814:
	db 0x11

LABEL_2815:
	call LABEL_65E9
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_387F
	break
	call LABEL_6606
	break
	call LABEL_664C
	break
	call LABEL_65E9

LABEL_2835:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_2835
LABEL_2845:
	db 0x11

LABEL_2846:
	call LABEL_643E
	je [0x29], 0x00, LABEL_2857
	break
	sub [0x29], 0x0001
	jmp LABEL_2846

LABEL_2857:
	jne [HACK_VAR_67], [0x10], LABEL_286E
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_387F

LABEL_286E:
	break
	call LABEL_645B
	break
	call LABEL_64A5
	break
	call LABEL_643E

LABEL_287A:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_64C2
	jmp LABEL_287A
LABEL_288A:
	db 0x11

LABEL_288B:
	call LABEL_6488
	je [0x29], 0x00, LABEL_289C
	break
	sub [0x29], 0x0001
	jmp LABEL_288B

LABEL_289C:
	jne [HACK_VAR_67], [0x10], LABEL_28B3
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_387F

LABEL_28B3:
	break
	call LABEL_64FC
	break
	call LABEL_652B
	break
	call LABEL_6488

LABEL_28BF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_64C2
	jmp LABEL_28BF
	killChannel
	call LABEL_63B1
	add [0x07], 0x0002
	deleteChannels first=0x14, last=0x16
	setup channel=0x15, address=DRAW_CIN_694_695_PROGRESSIVE
	mov [0x01], [0x07]
	add [0x01], 0x0010
	break
	call JUNK__63D2
	add [0x07], 0x0002
	break
	call LABEL_6411
	add [0x07], 0x0002
	break
	call LABEL_6411
	add [0x07], 0x0001
	break
	call LABEL_6411
	add [0x07], 0x0001
	break
	call LABEL_6411
	sub [0x07], 0x0002
	break
	call LABEL_63FC
	sub [0x07], 0x0003
	break
	call LABEL_63E7
	break
	mov [0x29], [0x07]
	add [0x29], 0x003C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_2929:
	db 0x11

LABEL_292A:
	call LABEL_643E
	deleteChannels first=0x14, last=0x16
	mov [0x03], 0x0014
	setup channel=0x3F, address=LABEL_0116
	mov [0x29], 0x0001

LABEL_293D:
	break
	video offset=CINEMATIC_426, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_293D
	break
	video offset=CINEMATIC_427, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	mov [0x29], 0x0003

LABEL_2957:
	break
	video offset=CINEMATIC_427, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_2957
	mov [0x29], 0x0002
	jmp LABEL_293D

LABEL_2968:
	call LABEL_683F
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_3876
	break
	call LABEL_6859
	break
	call LABEL_6895
	break
	call LABEL_683F

LABEL_2988:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_2988
LABEL_2998:
	db 0x11

LABEL_2999:
	call LABEL_66DF
	je [0x29], 0x00, LABEL_29AA
	break
	sub [0x29], 0x0001
	jmp LABEL_2999

LABEL_29AA:
	jne [HACK_VAR_67], [0x10], LABEL_29C1
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_3876

LABEL_29C1:
	break
	call LABEL_66F1
	break
	call LABEL_6725
	break
	call LABEL_66DF

LABEL_29CD:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6737
	jmp LABEL_29CD
LABEL_29DD:
	db 0x11

LABEL_29DE:
	call LABEL_6713
	je [0x29], 0x00, LABEL_29EF
	break
	sub [0x29], 0x0001
	jmp LABEL_29DE

LABEL_29EF:
	jne [HACK_VAR_67], [0x10], LABEL_2A06
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_3876

LABEL_2A06:
	break
	call LABEL_676C
	break
	call LABEL_678E
	break
	call LABEL_6713

LABEL_2A12:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6737
	jmp LABEL_2A12
LABEL_2A22:
	db 0x11

LABEL_2A23:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2A81
	jmp LABEL_2A56
LABEL_2A34:
	db 0x11

LABEL_2A35:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2A4C
	je [0x2F], 0x13, LABEL_2A56
	jmp LABEL_267B

LABEL_2A4C:
	je [0x2F], 0x12, LABEL_2A81
	jmp LABEL_2639
LABEL_2A55:
	db 0x11

LABEL_2A56:
	call LABEL_63B1
	add [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_2A70:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_2A70
LABEL_2A80:
	db 0x11

LABEL_2A81:
	call LABEL_5811
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [0x07], 0x0001
	break
	call LABEL_6390
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_2A9B:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_2A9B
LABEL_2AAB:
	db 0x11
