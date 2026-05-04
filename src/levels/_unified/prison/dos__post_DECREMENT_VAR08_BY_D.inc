LABEL_665A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_6634
	ret

LABEL_6669:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_52B4
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_668B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_52B4
	ret

JUNK__669D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5F61
	sub [0x08], 0x000D
	ret

LABEL_66CC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5F61
	sub [0x08], 0x000D
	ret

LABEL_66E6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_701, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5F61
	sub [0x08], 0x000D
	ret

LABEL_670D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_700, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5F4B
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_673C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5234
	add [0x08], 0x000D
	ret

LABEL_6756:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_292, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_5262
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5294
	add [0x08], 0x000D
	ret

LABEL_6792:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5262
	add [0x08], 0x000D
	ret

GUARDED_HERO_ANIM_CV_291:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__67BB:
	call LABEL_65DC
	break
	call LABEL_65DC
	break
	call LABEL_65DC
	sub [0x07], 0x0001
	break
	call LABEL_65EE
	add [0x07], 0x0001
	break
	jmp JUNK__67BB
LABEL_67D6:
	db 0x11

LABEL_67D7:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_67E6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_67E6:
	call LABEL_5CAD
	add [0x07], 0x0007
	break
	mov [0xF8], [0x10]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, LABEL_67FF
	mov [0x29], 0x0082

LABEL_67FF:
	jl [0x07], [0x29], LABEL_680E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_680E:
	call LABEL_5CE0
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_6825
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_6825:
	call LABEL_5D05
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_683C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_683C:
	call LABEL_5D32
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_6853
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_6853:
	call LABEL_5D5F
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_686A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_686A:
	call LABEL_5D84
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_6881
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_6881:
	call LABEL_5DB7
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_6898
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_6898:
	call LABEL_5DDC
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_68AF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_68AF:
	call LABEL_5E09
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_68C6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_25FB

LABEL_68C6:
	call LABEL_5E36
	add [0x07], 0x000A
	break
	jmp LABEL_67D7
	killChannel

LABEL_68D2:
	call GUARDED_DRAW_CIN_242_243
	break
	jmp LABEL_68D2
LABEL_68D9:
	db 0x11

LABEL_68DA:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_68E9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_68E9:
	call LABEL_6013
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6900
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6900:
	call LABEL_6039
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6917
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6917:
	call LABEL_6067
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_692E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_692E:
	call LABEL_6088
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6945
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6945:
	call LABEL_60AF
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_695C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_695C:
	call LABEL_60D0
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6973
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6973:
	call LABEL_60F6
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_698A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_698A:
	call LABEL_611C
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_69A1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69A1:
	call LABEL_6142
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_69B8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69B8:
	call LABEL_6168
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_69CF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69CF:
	call LABEL_6196
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_69E6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69E6:
	call LABEL_61BC
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_69FD
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69FD:
	call LABEL_61E8
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A14
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A14:
	call LABEL_6209
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A2B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A2B:
	call LABEL_622A
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A42
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A42:
	call LABEL_624B
	add [0x07], 0x0002
	break
	jmp LABEL_68DA
LABEL_6A4D:
	db 0x11

LABEL_6A4E:
	call LABEL_6013
	add [0x07], 0x0002
	break
	call LABEL_6039
	add [0x07], 0x0002
	break
	call LABEL_6067
	add [0x07], 0x0003
	break
	call LABEL_6088
	add [0x07], 0x0003
	break
	call LABEL_60AF
	add [0x07], 0x0003
	break
	call LABEL_60D0
	add [0x07], 0x0003
	break
	call LABEL_60F6
	add [0x07], 0x0003
	break
	call LABEL_611C
	add [0x07], 0x0002
	break

LABEL_6A8E:
	call LABEL_6142
	add [0x07], 0x0002
	break
	call LABEL_6168
	add [0x07], 0x0002
	break
	call LABEL_6196
	add [0x07], 0x0003
	break
	call LABEL_61BC
	add [0x07], 0x0003
	break
	call LABEL_61E8
	add [0x07], 0x0003
	break
	call LABEL_6209
	add [0x07], 0x0003
	break
	call LABEL_622A
	add [0x07], 0x0003
	break
	call LABEL_624B
	add [0x07], 0x0002
	break
	jmp LABEL_6A4E
LABEL_6AD1:
	db 0x11

LABEL_6AD2:
	je [0x0A], [0x0C], KILL_CHANNEL_LANDING_002
	jg [0x0A], [0x0C], LABEL_6AF1

LABEL_6ADE:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_6AEA
	break

LABEL_6AEA:
	jl [0x0A], [0x0C], LABEL_6ADE
