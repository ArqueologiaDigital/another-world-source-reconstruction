DRAW_CIN_694_695_PROGRESSIVE:
	video offset=CINEMATIC_694, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0004
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	break
	video offset=CINEMATIC_696, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_696, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	mov [0x03], 0x0028

LABEL_3CA3:
	break
	video offset=CINEMATIC_422, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_3CA3
LABEL_3CAC:
	db 0x11

PRISON_SHOT_RIGHT_IMPACT_RESOLVE:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call PRISON_SHOT_IMPACT_TARGET_DISPATCH
	jne [0x13], 0xFFFF, LABEL_3CBF
	ret


LABEL_3CBF:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call LABEL_3D0F
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


LABEL_3CDD:
	db 0x11

PRISON_SHOT_LEFT_IMPACT_RESOLVE:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call PRISON_SHOT_IMPACT_TARGET_DISPATCH
	jne [0x13], 0xFFFF, LABEL_3CF1
	ret


LABEL_3CF0:
	db 0x11

LABEL_3CF1:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call LABEL_3E6C
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


LABEL_3D0F:
	jge [0x13], 0x64, LABEL_3D5B
	jle [0x13], 0x03, LABEL_3D3D
	jle [0x13], 0x05, LABEL_3D2B
	video offset=CINEMATIC_488, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_3D2B:
	jle [0x13], 0x04, PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4
	video offset=CINEMATIC_487, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_HIT_BURST_RIGHT_FRAME_4:
	video offset=CINEMATIC_486, x=[0x21], y=[0x27]
	ret


LABEL_3D3D:
	jle [0x13], 0x02, LABEL_3D49
	video offset=CINEMATIC_485, x=[0x21], y=[0x27]
	ret


LABEL_3D49:
	jle [0x13], 0x01, PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1
	video offset=CINEMATIC_484, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_HIT_BURST_RIGHT_FRAME_1:
	video offset=CINEMATIC_483, x=[0x21], y=[0x27]
	ret


LABEL_3D5B:
	jge [0x13], 0xC8, LABEL_3E6A
	je [0x13], 0x64, PRISON_SUPERBLAST_ADVANCE_RIGHT_CASE_64
	je [0x13], 0x65, PRISON_SUPERBLAST_SWEEP_RIGHT_CASE_65
	jge [0x13], 0x81, PRISON_SHOT_IMPACT_RIGHT_CASE_81
	jne [0x13], 0x6E, LABEL_3D8E
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_482, x=[0x21], y=[0x27]
	ret


LABEL_3D8E:
	jne [0x13], 0x6F, LABEL_3D9A
	video offset=CINEMATIC_481, x=[0x21], y=[0x27]
	ret


LABEL_3D9A:
	jne [0x13], 0x70, LABEL_3DA6
	video offset=CINEMATIC_480, x=[0x21], y=[0x27]
	ret


LABEL_3DA6:
	jne [0x13], 0x71, LABEL_3DB2
	video offset=CINEMATIC_479, x=[0x21], y=[0x27]
	ret


LABEL_3DB2:
	jne [0x13], 0x72, LABEL_3DBE
	video offset=CINEMATIC_478, x=[0x21], y=[0x27]
	ret


LABEL_3DBE:
	jne [0x13], 0x73, LABEL_3DCA
	video offset=CINEMATIC_477, x=[0x21], y=[0x27]
	ret


LABEL_3DCA:
	jne [0x13], 0x74, LABEL_3DD6
	video offset=CINEMATIC_476, x=[0x21], y=[0x27]
	ret


LABEL_3DD6:
	jne [0x13], 0x75, LABEL_3DE2
	video offset=CINEMATIC_475, x=[0x21], y=[0x27]
	ret


LABEL_3DE2:
	jne [0x13], 0x76, PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT
	video offset=CINEMATIC_474, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT:
	video offset=CINEMATIC_473, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


PRISON_SHOT_IMPACT_RIGHT_CASE_81:
	jne [0x13], 0x81, LABEL_3E0A
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_472, x=[0x21], y=[0x27]
	ret


LABEL_3E0A:
	jne [0x13], 0x82, LABEL_3E16
	video offset=CINEMATIC_471, x=[0x21], y=[0x27]
	ret


LABEL_3E16:
	jne [0x13], 0x83, LABEL_3E22
	video offset=CINEMATIC_470, x=[0x21], y=[0x27]
	ret


LABEL_3E22:
	jne [0x13], 0x84, LABEL_3E2E
	video offset=CINEMATIC_469, x=[0x21], y=[0x27]
	ret


LABEL_3E2E:
	jne [0x13], 0x85, LABEL_3E3A
	video offset=CINEMATIC_468, x=[0x21], y=[0x27]
	ret


LABEL_3E3A:
	jne [0x13], 0x86, LABEL_3E46
	video offset=CINEMATIC_467, x=[0x21], y=[0x27]
	ret


LABEL_3E46:
	jne [0x13], 0x87, LABEL_3E52
	video offset=CINEMATIC_466, x=[0x21], y=[0x27]
	ret


LABEL_3E52:
	jne [0x13], 0x88, LABEL_3E5E
	video offset=CINEMATIC_465, x=[0x21], y=[0x27]
	ret


LABEL_3E5E:
	jne [0x13], 0x89, LABEL_3E6A
	video offset=CINEMATIC_464, x=[0x21], y=[0x27]
	ret


LABEL_3E6A:
	ret


LABEL_3E6B:
	db 0x11

LABEL_3E6C:
	jge [0x13], 0x64, LABEL_3EB8
	jle [0x13], 0x03, LABEL_3E9A
	jle [0x13], 0x05, LABEL_3E88
	video offset=CINEMATIC_504, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_3E88:
	jle [0x13], 0x04, PRISON_SHOT_HIT_BURST_LEFT_FRAME_4
	video offset=CINEMATIC_503, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_HIT_BURST_LEFT_FRAME_4:
	video offset=CINEMATIC_502, x=[0x21], y=[0x27]
	ret


LABEL_3E9A:
	jle [0x13], 0x02, LABEL_3EA6
	video offset=CINEMATIC_501, x=[0x21], y=[0x27]
	ret


LABEL_3EA6:
	jle [0x13], 0x01, PRISON_SHOT_HIT_BURST_LEFT_FRAME_1
	video offset=CINEMATIC_500, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_HIT_BURST_LEFT_FRAME_1:
	video offset=CINEMATIC_499, x=[0x21], y=[0x27]
	ret


LABEL_3EB8:
	jge [0x13], 0xC8, LABEL_3FC7
	je [0x13], 0x64, PRISON_SUPERBLAST_ADVANCE_LEFT_CASE_64
	je [0x13], 0x65, PRISON_SUPERBLAST_SWEEP_LEFT_CASE_65
	jge [0x13], 0x81, PRISON_SHOT_IMPACT_LEFT_CASE_81
	jne [0x13], 0x6E, LABEL_3EEB
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_498, x=[0x21], y=[0x27]
	ret


LABEL_3EEB:
	jne [0x13], 0x6F, LABEL_3EF7
	video offset=CINEMATIC_497, x=[0x21], y=[0x27]
	ret


LABEL_3EF7:
	jne [0x13], 0x70, LABEL_3F03
	video offset=CINEMATIC_496, x=[0x21], y=[0x27]
	ret


LABEL_3F03:
	jne [0x13], 0x71, LABEL_3F0F
	video offset=CINEMATIC_495, x=[0x21], y=[0x27]
	ret


LABEL_3F0F:
	jne [0x13], 0x72, LABEL_3F1B
	video offset=CINEMATIC_494, x=[0x21], y=[0x27]
	ret


LABEL_3F1B:
	jne [0x13], 0x73, LABEL_3F27
	video offset=CINEMATIC_493, x=[0x21], y=[0x27]
	ret


LABEL_3F27:
	jne [0x13], 0x74, LABEL_3F33
	video offset=CINEMATIC_492, x=[0x21], y=[0x27]
	ret


LABEL_3F33:
	jne [0x13], 0x75, LABEL_3F3F
	video offset=CINEMATIC_491, x=[0x21], y=[0x27]
	ret


LABEL_3F3F:
	jne [0x13], 0x76, PRISON_SHOT_BLAST_FINAL_FRAME_LEFT
	video offset=CINEMATIC_490, x=[0x21], y=[0x27]
	ret


PRISON_SHOT_BLAST_FINAL_FRAME_LEFT:
	video offset=CINEMATIC_489, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


PRISON_SHOT_IMPACT_LEFT_CASE_81:
	jne [0x13], 0x81, LABEL_3F67
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_472, x=[0x21], y=[0x27]
	ret


LABEL_3F67:
	jne [0x13], 0x82, LABEL_3F73
	video offset=CINEMATIC_471, x=[0x21], y=[0x27]
	ret


LABEL_3F73:
	jne [0x13], 0x83, LABEL_3F7F
	video offset=CINEMATIC_470, x=[0x21], y=[0x27]
	ret


LABEL_3F7F:
	jne [0x13], 0x84, LABEL_3F8B
	video offset=CINEMATIC_469, x=[0x21], y=[0x27]
	ret


LABEL_3F8B:
	jne [0x13], 0x85, LABEL_3F97
	video offset=CINEMATIC_468, x=[0x21], y=[0x27]
	ret


LABEL_3F97:
	jne [0x13], 0x86, LABEL_3FA3
	video offset=CINEMATIC_467, x=[0x21], y=[0x27]
	ret


LABEL_3FA3:
	jne [0x13], 0x87, LABEL_3FAF
	video offset=CINEMATIC_466, x=[0x21], y=[0x27]
	ret


LABEL_3FAF:
	jne [0x13], 0x88, LABEL_3FBB
	video offset=CINEMATIC_465, x=[0x21], y=[0x27]
	ret


LABEL_3FBB:
	jne [0x13], 0x89, LABEL_3FC7
	video offset=CINEMATIC_464, x=[0x21], y=[0x27]
	ret


LABEL_3FC7:
	ret


LABEL_3FC8:
	db 0x11

PRISON_SUPERBLAST_ADVANCE_LEFT_CASE_64:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call PRISON_SHOT_SWEEP_HIT_SCAN
	call LABEL_4117
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_4039
	video offset=CINEMATIC_463, x=[0x22], y=[0x27]
	ret


PRISON_SUPERBLAST_SWEEP_LEFT_CASE_65:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call PRISON_SHOT_SWEEP_HIT_SCAN
	call LABEL_4117
	mov [0x2C], 0x0001
	jmp LABEL_4039
LABEL_4000:
	db 0x11

PRISON_SUPERBLAST_ADVANCE_RIGHT_CASE_64:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call PRISON_SHOT_SWEEP_HIT_SCAN
	call LABEL_4117
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_4039
	video offset=CINEMATIC_463, x=[0x22], y=[0x27]
	ret


PRISON_SUPERBLAST_SWEEP_RIGHT_CASE_65:
	mov [0x22], [0x21]
	add [0x22], 0x0140
	mov [0x09], [0x22]
	call PRISON_SHOT_SWEEP_HIT_SCAN
	call LABEL_4117
	mov [0x2C], 0x0000
	jmp LABEL_4039
LABEL_4038:
	db 0x11

LABEL_4039:
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_4177_AND_RET
	jl [0x1D], 0x14, LABEL_4097
	jl [0x1D], 0x1E, LABEL_406D
	jge [0x1D], 0x28, LABEL_405C

CALL_LABEL_4177_AND_RET:
	call PRISON_SHOT_Y_SNAP_TO_FLOOR
	ret


LABEL_405C:
	call PRISON_SHOT_HIT_TARGET
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, PRISON_SUPERBLAST_SWEEP_LEFT_CASE_65
	jmp PRISON_SUPERBLAST_SWEEP_RIGHT_CASE_65
LABEL_406C:
	db 0x05

LABEL_406D:
	call PRISON_SHOT_Y_SNAP_TO_FLOOR
	call PRISON_SHIELD_ENERGY_LOAD_CASE_14
	mov [0x11], 0xFFFF
	call PRISON_SHIELD_ENERGY_STORE_CASE_14
	ret


LABEL_407B:
	db 0x11

LABEL_407C:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_40C6
	jmp LABEL_40B8
LABEL_4096:
	db 0x11

LABEL_4097:
	call LABEL_41E0
	call PRISON_SHOT_Y_SNAP_TO_FLOOR
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_407C
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_40BF

LABEL_40B8:
	and [0x11], 0xFDFF
	jmp LABEL_40D9

LABEL_40BF:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_40C6:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp LABEL_40D9
