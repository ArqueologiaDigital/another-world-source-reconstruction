LABEL_675D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_6737
	ret

LABEL_676C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_53B7
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_678E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53B7
	ret

JUNK__67A0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6064
	sub [0x08], 0x000D
	ret

LABEL_67CF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6064
	sub [0x08], 0x000D
	ret

LABEL_67E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_701, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6064
	sub [0x08], 0x000D
	ret

LABEL_6810:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_700, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_604E
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_683F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5337
	add [0x08], 0x000D
	ret

LABEL_6859:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_292, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_5365
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5397
	add [0x08], 0x000D
	ret

LABEL_6895:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_5365
	add [0x08], 0x000D
	ret

GUARDED_HERO_ANIM_CV_291:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__68BE:
	call LABEL_66DF
	break
	call LABEL_66DF
	break
	call LABEL_66DF
	sub [0x07], 0x0001
	break
	call LABEL_66F1
	add [0x07], 0x0001
	break
	jmp JUNK__68BE
LABEL_68D9:
	db 0x11

LABEL_68DA:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_68E9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_68E9:
	call LABEL_5DB0
	add [0x07], 0x0007
	break
	mov [0xF8], [0x10]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, LABEL_6902
	mov [0x29], 0x0082

LABEL_6902:
	jl [0x07], [0x29], LABEL_6911
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_6911:
	call LABEL_5DE3
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_6928
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_6928:
	call LABEL_5E08
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_693F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_693F:
	call LABEL_5E35
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_6956
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_6956:
	call LABEL_5E62
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_696D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_696D:
	call LABEL_5E87
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_6984
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_6984:
	call LABEL_5EBA
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_699B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_699B:
	call LABEL_5EDF
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_69B2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_69B2:
	call LABEL_5F0C
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_69C9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_269D

LABEL_69C9:
	call LABEL_5F39
	add [0x07], 0x000A
	break
	jmp LABEL_68DA
	killChannel

LABEL_69D5:
	call GUARDED_DRAW_CIN_242_243
	break
	jmp LABEL_69D5
LABEL_69DC:
	db 0x11

LABEL_69DD:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_69EC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_69EC:
	call LABEL_6116
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6A03
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A03:
	call LABEL_613C
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6A1A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A1A:
	call LABEL_616A
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A31
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A31:
	call LABEL_618B
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A48
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A48:
	call LABEL_61B2
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A5F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A5F:
	call LABEL_61D3
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A76
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A76:
	call LABEL_61F9
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6A8D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6A8D:
	call LABEL_621F
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6AA4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6AA4:
	call LABEL_6245
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6ABB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6ABB:
	call LABEL_626B
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_6AD2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6AD2:
	call LABEL_6299
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6AE9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6AE9:
	call LABEL_62BF
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6B00
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6B00:
	call LABEL_62EB
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6B17
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6B17:
	call LABEL_630C
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6B2E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6B2E:
	call LABEL_632D
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_6B45
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, MAIN_GAME_LOOP_HERO_128

LABEL_6B45:
	call LABEL_634E
	add [0x07], 0x0002
	break
	jmp LABEL_69DD
LABEL_6B50:
	db 0x11

LABEL_6B51:
	call LABEL_6116
	add [0x07], 0x0002
	break
	call LABEL_613C
	add [0x07], 0x0002
	break
	call LABEL_616A
	add [0x07], 0x0003
	break
	call LABEL_618B
	add [0x07], 0x0003
	break
	call LABEL_61B2
	add [0x07], 0x0003
	break
	call LABEL_61D3
	add [0x07], 0x0003
	break
	call LABEL_61F9
	add [0x07], 0x0003
	break
	call LABEL_621F
	add [0x07], 0x0002
	break

LABEL_6B91:
	call LABEL_6245
	add [0x07], 0x0002
	break
	call LABEL_626B
	add [0x07], 0x0002
	break
	call LABEL_6299
	add [0x07], 0x0003
	break
	call LABEL_62BF
	add [0x07], 0x0003
	break
	call LABEL_62EB
	add [0x07], 0x0003
	break
	call LABEL_630C
	add [0x07], 0x0003
	break
	call LABEL_632D
	add [0x07], 0x0003
	break
	call LABEL_634E
	add [0x07], 0x0002
	break
	jmp LABEL_6B51
LABEL_6BD4:
	db 0x11

LABEL_6BD5:
	je [0x0A], [0x0C], 0x6BF3
	jg [0x0A], [0x0C], LABEL_6BF4

LABEL_6BE1:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_6BED
	break

LABEL_6BED:
	jl [0x0A], [0x0C], LABEL_6BE1
