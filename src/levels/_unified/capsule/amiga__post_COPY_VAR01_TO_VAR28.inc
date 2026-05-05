LABEL_5C32:
	mov [0x21], [0x28]
	sub [0x22], [0x2A]
	call LABEL_5C5A
	add [0x22], [0x2A]
	jle [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
LABEL_5C4B:
	db 0x11

LABEL_5C4C:
	mov [0x23], 0x0000
	jg [0x27], [0x44], LABEL_5C5A
	mov [0x23], 0x0001

LABEL_5C5A:
	jl [0x22], [0x21], LABEL_5CAB
	je [0x23], 0x00, LABEL_5C76
	jg [0x47], [0x22], LABEL_5C83
	mov [0x22], [0x47]
	mov [0x1D], 0x0004
	jmp LABEL_5C83

LABEL_5C76:
	jg [0x43], [0x22], LABEL_5C83
	mov [0x22], [0x43]
	mov [0x1D], 0x0002

LABEL_5C83:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_5D7A
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_5D7A
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_5D7A
	ret

LABEL_5CAB:
	je [0x23], 0x00, LABEL_5CC1
	jl [0x46], [0x22], LABEL_5CCE
	mov [0x22], [0x46]
	mov [0x1D], 0x0003
	jmp LABEL_5CCE

LABEL_5CC1:
	jl [0x42], [0x22], LABEL_5CCE
	mov [0x22], [0x42]
	mov [0x1D], 0x0001

LABEL_5CCE:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_5CF6
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_5CF6
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_5CF6
	ret

LABEL_5CF6:
	jge [0x25], 0x2000, LABEL_5D79
	jge [0x25], 0x1000, LABEL_5D0D
	je [0x23], 0x01, LABEL_5D79
	jmp LABEL_5D17

LABEL_5D0D:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_5D79

LABEL_5D17:
	add [0x24], 0x0008
	jl [0x25], 0x0200, LABEL_5D38
	sub [0x25], 0x0200
	jg [0x24], [0x21], LABEL_5D79
	jl [0x24], [0x22], LABEL_5D38
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_5D38:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_5D59
	sub [0x25], 0x0100
	jg [0x24], [0x21], LABEL_5D79
	jl [0x24], [0x22], LABEL_5D59
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_5D59:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_5D79
	sub [0x25], 0x0080
	jg [0x24], [0x21], LABEL_5D79
	jl [0x24], [0x22], LABEL_5D79
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_5D79:
	ret

LABEL_5D7A:
	jge [0x25], 0x2000, LABEL_5DE7
	jge [0x25], 0x1000, LABEL_5D91
	je [0x23], 0x01, LABEL_5DE7
	jmp LABEL_5D9B

LABEL_5D91:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_5DE7

LABEL_5D9B:
	jl [0x25], 0x0200, LABEL_5DB1
	jl [0x24], [0x21], LABEL_5DB1
	jg [0x24], [0x22], LABEL_5DB1
	jmp LABEL_5DE1

LABEL_5DB1:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_5DCB
	jl [0x24], [0x21], LABEL_5DCB
	jg [0x24], [0x22], LABEL_5DCB
	jmp LABEL_5DE1

LABEL_5DCB:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_5DE7
	jl [0x24], [0x21], LABEL_5DE7
	jg [0x24], [0x22], LABEL_5DE7

LABEL_5DE1:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_5DE7:
	ret

LABEL_5DE8:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_5E24
	je [0xF8], 0x00, DRAW_CIN_195
	je [0xF8], 0x01, DRAW_CIN_196
	je [0xF8], 0x02, DRAW_CIN_197
	je [0xF8], 0x03, DRAW_CIN_198
	je [0xF8], 0x04, DRAW_CIN_199
	je [0xF8], 0x05, DRAW_CIN_178
	je [0xF8], 0x06, DRAW_CIN_200
	ret

LABEL_5E24:
	jne [0x0E], 0x01, LABEL_5E2D
	jmp DRAW_CIN_194

LABEL_5E2D:
	jne [0x0E], 0x02, LABEL_5E36
	jmp DRAW_CIN_193

LABEL_5E36:
	jne [0x0E], 0x03, LABEL_5E45
	je [0xF8], 0x03, DRAW_CIN_188
	jmp DRAW_CIN_192

LABEL_5E45:
	jne [0x0E], 0x04, LABEL_5E54
	je [0xF8], 0x03, DRAW_CIN_190
	jmp DRAW_CIN_191

LABEL_5E54:
	jne [0x0E], 0x05, LABEL_5E63
	je [0xF8], 0x03, DRAW_CIN_188
	jmp DRAW_CIN_189

LABEL_5E63:
	jne [0x0E], 0x06, LABEL_5E6F
	video offset=CINEMATIC_187, x=[0x07], y=[0x08]
	ret

LABEL_5E6F:
	jne [0x0E], 0x07, LABEL_5E82
	je [0xF8], 0x00, DRAW_CIN_185
	je [0xF8], 0x01, DRAW_CIN_186
	ret

LABEL_5E82:
	ret
LABEL_5E83:
	db 0x11

DRAW_CIN_195:
	video offset=CINEMATIC_195, x=[0x07], y=[0x08]
	ret

DRAW_CIN_196:
	video offset=CINEMATIC_196, x=[0x07], y=[0x08]
	ret

DRAW_CIN_197:
	video offset=CINEMATIC_197, x=[0x07], y=[0x08]
	ret

DRAW_CIN_198:
	video offset=CINEMATIC_198, x=[0x07], y=[0x08]
	ret

DRAW_CIN_199:
	video offset=CINEMATIC_199, x=[0x07], y=[0x08]
	ret

DRAW_CIN_178:
	video offset=CINEMATIC_178, x=[0x07], y=[0x08]
	ret

DRAW_CIN_200:
	video offset=CINEMATIC_200, x=[0x07], y=[0x08]
	ret

DRAW_CIN_194:
	video offset=CINEMATIC_194, x=[0x07], y=[0x08]
	ret

DRAW_CIN_193:
	video offset=CINEMATIC_193, x=[0x07], y=[0x08]
	ret

DRAW_CIN_192:
	video offset=CINEMATIC_192, x=[0x07], y=[0x08]
	ret

DRAW_CIN_188:
	video offset=CINEMATIC_188, x=[0x07], y=[0x08]
	ret

DRAW_CIN_191:
	video offset=CINEMATIC_191, x=[0x07], y=[0x08]
	ret

DRAW_CIN_190:
	video offset=CINEMATIC_190, x=[0x07], y=[0x08]
	ret

DRAW_CIN_189:
	video offset=CINEMATIC_189, x=[0x07], y=[0x08]
	ret

DRAW_CIN_185:
	video offset=CINEMATIC_185, x=[0x07], y=[0x08]
	ret

DRAW_CIN_186:
	video offset=CINEMATIC_186, x=[0x07], y=[0x08]
	ret

LABEL_5EE4:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_208
	je [0xF8], 0x02, DRAW_CIN_209
	ret

DRAW_CIN_208:
	video offset=CINEMATIC_208, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_209:
	video offset=CINEMATIC_209, x=[0xf5], y=[0x08]
	ret

LABEL_5F04:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_5F18
	je [0xF8], 0x02, LABEL_5F2E
	ret

LABEL_5F18:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_183, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_5F2E:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_184, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_5F44:
	video type=0, offset=COMMON_VIDEO_317, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_5F57
	video type=0, offset=COMMON_VIDEO_319, x=[0x07], y=[0x08], zoom=0x40

LABEL_5F57:
	jg [0x13], [0x30], LABEL_5EE4
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5EE4
	video type=0, offset=COMMON_VIDEO_318, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_5EE4

LABEL_5F72:
	video type=0, offset=COMMON_VIDEO_320, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_5F89
	video type=0, offset=COMMON_VIDEO_322, x=[0x07], y=[0x08], zoom=0x40

LABEL_5F89:
	jg [0x13], [0x30], LABEL_5EE4
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5EE4
	video type=0, offset=COMMON_VIDEO_321, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_5EE4

LABEL_5FA4:
	video type=0, offset=COMMON_VIDEO_323, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], LABEL_5F04
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5F04
	video type=0, offset=COMMON_VIDEO_324, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_5F04

LABEL_5FC4:
	video type=0, offset=COMMON_VIDEO_325, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_5F04

LABEL_5FCC:
	sub [0x07], 0x0001
	call LABEL_5FD8
	add [0x07], 0x0001
	ret

LABEL_5FD8:
	video type=0, offset=COMMON_VIDEO_305, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_306, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5FF6:
	sub [0x07], 0x0001
	call LABEL_6002
	add [0x07], 0x0001
	ret

LABEL_6002:
	video type=0, offset=COMMON_VIDEO_303, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_304, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_6020:
	video type=0, offset=COMMON_VIDEO_301, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_302, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_603E:
	add [0x07], 0x0001
	call LABEL_6020
	sub [0x07], 0x0001
	ret

SHARED_RET:
	ret

DRAW_CIN_201_202_203_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_201
	je [0xF8], 0x02, DRAW_CIN_202
	je [0xF8], 0x03, DRAW_CIN_203
	ret

DRAW_CIN_201:
	video offset=CINEMATIC_201, x=[0x07], y=[0x08]
	ret

DRAW_CIN_202:
	video offset=CINEMATIC_202, x=[0x07], y=[0x08]
	ret

DRAW_CIN_203:
	video offset=CINEMATIC_203, x=[0x07], y=[0x08]
	ret

DRAW_CIN_204_205_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_204
	je [0xF8], 0x02, DRAW_CIN_205
	ret

DRAW_CIN_204:
	video offset=CINEMATIC_204, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_205:
	video offset=CINEMATIC_205, x=[0xf5], y=[0x08]
	ret

LABEL_6097:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_60B4:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_162, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_163, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_60D1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_121, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_122, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_60F2:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_610F:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_6130:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_6151:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_6172:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_6193:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_204_205_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61B4:
	video type=0, offset=COMMON_VIDEO_224, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61BF:
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61CA:
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61D5:
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61E0:
	video type=0, offset=COMMON_VIDEO_237, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61EB:
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_61F6:
	video type=0, offset=COMMON_VIDEO_221, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_204_205_VAR09_LOW

LABEL_6201:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6213
	call LABEL_603E
	jmp LABEL_6218

LABEL_6213:
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40

LABEL_6218:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_161, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60B4
	ret

LABEL_6227:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6239
	call LABEL_603E
	jmp LABEL_6246

LABEL_6239:
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001

LABEL_6246:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60B4
	ret

LABEL_6255:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6264
	call LABEL_6020

LABEL_6264:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60D1
	ret

LABEL_6273:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6282
	call LABEL_6020

LABEL_6282:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60F2
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	ret

LABEL_6297:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_62A6
	call LABEL_6020

LABEL_62A6:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_610F
	ret

LABEL_62B5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_62C7
	call LABEL_6002
	jmp LABEL_62CC

LABEL_62C7:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_62CC:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6130
	ret

LABEL_62DB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_62ED
	call LABEL_5FF6
	jmp LABEL_62F2

LABEL_62ED:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_62F2:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6151
	ret

LABEL_6301:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6313
	call LABEL_5FD8
	jmp LABEL_6318

LABEL_6313:
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40

LABEL_6318:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6172
	ret

LABEL_6327:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6339
	call LABEL_5FCC
	jmp LABEL_633E

LABEL_6339:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_633E:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6193
	ret

LABEL_634D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_635F
	call LABEL_5FCC
	jmp LABEL_6364

LABEL_635F:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_6364:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	add [0x07], 0x0001
	call LABEL_6193
	sub [0x07], 0x0001
	ret

LABEL_637B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_638D
	call LABEL_5FD8
	jmp LABEL_6392

LABEL_638D:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_6392:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6151
	ret

LABEL_63A1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_63B3
	call LABEL_5FD8
	jmp LABEL_63B8

LABEL_63B3:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_63B8:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6130
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	ret

LABEL_63CD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_63DC
	call LABEL_5FD8

LABEL_63DC:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_610F
	ret

LABEL_63EB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_63FA
	call LABEL_5FF6

LABEL_63FA:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60F2
	ret

LABEL_6409:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6418
	call LABEL_6002

LABEL_6418:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60D1
	ret

LABEL_6427:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6436
	call LABEL_6020

LABEL_6436:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_6097
	ret

LABEL_6445:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6454
	call LABEL_6020

LABEL_6454:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60D1
	ret

LABEL_6463:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6472
	call LABEL_6002

LABEL_6472:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_60F2
	ret

LABEL_6481:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6490
	call LABEL_5FF6

LABEL_6490:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_201_202_203_VAR09
	call LABEL_610F
	ret
LABEL_649F:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x54, 0x0E
	db 0x2F, 0x07, 0x08, 0x04, 0x5D, 0xE8, 0x57, 0x20
	db 0x76, 0x07, 0x08, 0x04, 0x60, 0x4B, 0x04, 0x60
	db 0xF2, 0x05, 0x04, 0x72, 0xBF, 0x06, 0x07, 0x64
	db 0xB9, 0x11

LABEL_64C1:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_64D0
LABEL_64C7:
	db 0x04, 0x3B, 0x79, 0x0A, 0x01, 0x2F, 0x02, 0x35
	db 0x29

LABEL_64D0:
	call LABEL_6201
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_64E7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_64E7:
	call LABEL_6227
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_64FE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_64FE:
	call LABEL_6255
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_6515
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6515:
	call LABEL_6273
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_652C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_652C:
	call LABEL_6297
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_6543
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6543:
	call LABEL_62B5
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_655A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_655A:
	call LABEL_62DB
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_6571
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6571:
	call LABEL_6301
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_6588
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6588:
	call LABEL_6327
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_659F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_659F:
	call LABEL_634D
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_65B6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_65B6:
	call LABEL_637B
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_65CD
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_65CD:
	call LABEL_63A1
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_65E4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_65E4:
	call LABEL_63CD
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_65FB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_65FB:
	call LABEL_63EB
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_6612
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6612:
	call LABEL_6409
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_6629
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, LABEL_3529

LABEL_6629:
	call LABEL_6427
	sub [0x07], 0x0002
	break
	jmp LABEL_64C1
LABEL_6634:
	db 0x11

LABEL_6635:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_664B
	call LABEL_5FF6
	jmp LABEL_6650

LABEL_664B:
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40

LABEL_6650:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61F6
	add [0x08], 0x0001
	ret

LABEL_6660:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6672
	call LABEL_5FF6
	jmp LABEL_6677

LABEL_6672:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_6677:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61B4
	ret

LABEL_6683:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_6699
	call LABEL_6020
	jmp LABEL_669E

LABEL_6699:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_669E:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61BF
	sub [0x08], 0x0001
	ret

LABEL_66AE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_66C4
	call LABEL_6020
	jmp LABEL_66C9

LABEL_66C4:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_66C9:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_229, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61CA
	sub [0x08], 0x0001
	ret

LABEL_66D9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_66EB
	call LABEL_6020
	jmp LABEL_66F0

LABEL_66EB:
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40

LABEL_66F0:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_232, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61D5
	ret

LABEL_66FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_6712
	call LABEL_5FF6
	jmp LABEL_6717

LABEL_6712:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_6717:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_234, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61D5
	add [0x08], 0x0001
	ret

LABEL_6727:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6739
	call LABEL_5FF6
	jmp LABEL_673E

LABEL_6739:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_673E:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_235, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61CA
	ret

LABEL_674A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_6760
	call LABEL_5FD8
	jmp LABEL_6765

LABEL_6760:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_6765:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_236, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61E0
	sub [0x08], 0x0001
	ret

LABEL_6775:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_678B
	call LABEL_5FCC
	jmp LABEL_6790

LABEL_678B:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_6790:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_238, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_61EB
	sub [0x08], 0x0001
	ret

LABEL_67A0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_67B2
	call LABEL_5FD8
	jmp LABEL_67B7

LABEL_67B2:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_67B7:
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_61F6
	sub [0x07], 0x0001
	ret

LABEL_67CB:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_67DA
LABEL_67D1:
	db 0x04, 0x3B, 0x79, 0x0A, 0x01, 0x2F, 0x04, 0x35
	db 0x3A

LABEL_67DA:
	call LABEL_6635
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_67F1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_67F1:
	call LABEL_6660
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_6808
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_6808:
	call LABEL_6683
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_681F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_681F:
	call LABEL_66AE
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_6836
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_6836:
	call LABEL_66D9
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_684D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_684D:
	call LABEL_66FC
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_6864
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_6864:
	call LABEL_6727
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_687B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_687B:
	call LABEL_674A
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_6892
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_6892:
	call LABEL_6775
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_68A9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_353A

LABEL_68A9:
	call LABEL_67A0
	sub [0x07], 0x000A
	break
	jmp LABEL_67CB
LABEL_68B4:
	db 0x11

LABEL_68B5:
	video type=0, offset=COMMON_VIDEO_311, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_312, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_68D3:
	video type=0, offset=COMMON_VIDEO_313, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_314, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_68F1:
	video type=0, offset=COMMON_VIDEO_315, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_316, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_690F:
	add [0x07], 0x0001
	call LABEL_691B
	sub [0x07], 0x0001
	ret

LABEL_691B:
	video type=0, offset=COMMON_VIDEO_299, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_183_184_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_300, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_693E:
	add [0x07], 0x0001
	call LABEL_694A
	sub [0x07], 0x0001
	ret

LABEL_694A:
	video type=0, offset=COMMON_VIDEO_307, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_183_184_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_308, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_696D:
	video type=0, offset=COMMON_VIDEO_309, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_183_184_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_310, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6990:
	sub [0x07], 0x0001
	call LABEL_693E
	add [0x07], 0x0001
	ret

LABEL_699C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_69BF
	call LABEL_693E
	jmp LABEL_69C4

LABEL_69BF:
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40

LABEL_69C4:
	add [0x08], 0x0001
	ret

LABEL_69C9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_69E8
	call LABEL_693E
	jmp LABEL_69ED

LABEL_69E8:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40

LABEL_69ED:
	ret

LABEL_69EE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_204, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6A11
	call LABEL_691B
	jmp LABEL_6A16

LABEL_6A11:
	video type=0, offset=COMMON_VIDEO_205, x=[0x07], y=[0x08], zoom=0x40

LABEL_6A16:
	sub [0x08], 0x0001
	ret

LABEL_6A1B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6A3E
	call LABEL_690F
	jmp LABEL_6A43

LABEL_6A3E:
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40

LABEL_6A43:
	sub [0x08], 0x0001
	ret

LABEL_6A48:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_210, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6A67
	call LABEL_691B
	jmp LABEL_6A6C

LABEL_6A67:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40

LABEL_6A6C:
	ret

LABEL_6A6D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6A90
	call LABEL_693E
	jmp LABEL_6A95

LABEL_6A90:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40

LABEL_6A95:
	add [0x08], 0x0001
	ret

LABEL_6A9A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_213, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6AB9
	call LABEL_693E
	jmp LABEL_6ABE

LABEL_6AB9:
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40

LABEL_6ABE:
	ret

LABEL_6ABF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6AE2
	call LABEL_696D
	jmp LABEL_6AE7

LABEL_6AE2:
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40

LABEL_6AE7:
	sub [0x08], 0x0001
	ret

LABEL_6AEC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_6B0F
	call LABEL_6990
	jmp LABEL_6B14

LABEL_6B0F:
	video type=0, offset=COMMON_VIDEO_217, x=[0x07], y=[0x08], zoom=0x40

LABEL_6B14:
	sub [0x08], 0x0001
	ret

LABEL_6B19:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, LABEL_6B3C
	call LABEL_696D
	jmp INCREMENT_VAR07_BY_1

LABEL_6B3C:
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
