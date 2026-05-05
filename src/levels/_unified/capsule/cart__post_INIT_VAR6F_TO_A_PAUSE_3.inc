LABEL_376C:
	call LABEL_3724
	call GUARDED_ALIEN_ANIM_CV_128
	break
	jg [HERO_X], 0xAA, LABEL_376C
	djnz [0x6F], LABEL_376C
	mov [0x6F], 0x0003

LABEL_3781:
	jg [HERO_X], 0x7D, LABEL_37A7
	call LABEL_3724
	call LABEL_7D99
	break
	djnz [0x6F], LABEL_3781
	mov [0x6F], 0x0003

LABEL_3796:
	jg [HERO_X], 0x7D, LABEL_37A7
	call LABEL_3724
	call LABEL_7DB5
	break
	djnz [0x6F], LABEL_3796

LABEL_37A7:
	call LABEL_3724
	call GUARDED_DRAW_CV_304_305
	break
	jne [HACK_VAR_67], 0x6D, INIT_VAR6F_TO_A_PAUSE_3
	jl [HERO_X], 0x8F, LABEL_37A7
	jg [HERO_X], 0xA2, LABEL_37A7
	mov [0x63], 0x0064
	deleteChannels first=0x14, last=0x16
	call LABEL_3724
	call GUARDED_DRAW_CV_304_305
	break
	deleteChannels first=0x14, last=0x16
	jne [HACK_VAR_67], [0x6A], LABEL_37DE
	video offset=CINEMATIC_293, x=[0x68], y=[0x69]

LABEL_37DE:
	break
	or [0xB9], 0x0020
	jne [HACK_VAR_67], [0x6A], LABEL_37EE
	video offset=CINEMATIC_292, x=[0x68], y=[0x69]

LABEL_37EE:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_37FA
	video offset=CINEMATIC_291, x=[0x68], y=[0x69]

LABEL_37FA:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3806
	video offset=CINEMATIC_290, x=[0x68], y=[0x69]

LABEL_3806:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3812
	video offset=CINEMATIC_290, x=[0x68], y=[0x69]

LABEL_3812:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_381E
	video offset=CINEMATIC_289, x=[0x68], y=[0x69]

LABEL_381E:
	setup channel=0x14, address=LABEL_39A6
	mov [0x6F], 0x0007

LABEL_3826:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3832
	video offset=CINEMATIC_285, x=[0x68], y=[0x69]

LABEL_3832:
	djnz [0x6F], LABEL_3826
	add [0x68], 0x000A
	mov [0x6F], 0x0004

LABEL_383E:
	break
	call LABEL_3724
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x6F], LABEL_383E
	setup channel=0x23, address=LABEL_812B
	mov [0x6C], 0x0004
	mov [0x6F], 0x000A
	killChannel

LABEL_3856:
	mov [PAUSE_SLICES], 0x0004
	jne [HACK_VAR_67], [0x6A], LABEL_3865
	video offset=CINEMATIC_284, x=[0x07], y=[0x08]

LABEL_3865:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3871
	video offset=CINEMATIC_283, x=[0x07], y=[0x08]

LABEL_3871:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_387C
	video offset=CINEMATIC_282, x=156, y=98

LABEL_387C:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3887
	video offset=CINEMATIC_281, x=171, y=100

LABEL_3887:
	break
	or [0xB9], 0x0010
	jne [HACK_VAR_67], [0x6A], LABEL_38A0
	setup channel=0x04, address=KILL_CHANNEL_LANDING
	video offset=CINEMATIC_280, x=193, y=110
	play id=0x0060, freq=0x14, vol=0x40, channel=0x02

LABEL_38A0:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_38B0
	video offset=CINEMATIC_279, x=283, y=98
	video offset=CINEMATIC_280, x=217, y=125

LABEL_38B0:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_38C1
	video offset=CINEMATIC_277, x=283, y=98
	video offset=CINEMATIC_278, x=274, y=122

LABEL_38C1:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_38D2
	video offset=CINEMATIC_276, x=283, y=98
	video offset=CINEMATIC_275, x=281, y=157

LABEL_38D2:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_38E3
	video offset=CINEMATIC_274, x=283, y=98
	video offset=CINEMATIC_275, x=274, y=178

LABEL_38E3:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_38FE
	video offset=CINEMATIC_271, x=283, y=98
	video offset=CINEMATIC_119, x=284, y=224
	video offset=CINEMATIC_273, x=222, y=175
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x02

LABEL_38FE:
	break
	jne [HACK_VAR_67], [0x6A], INLINE_SET_VAR29_TO_6
	video offset=CINEMATIC_272, x=283, y=98
	video offset=CINEMATIC_119, x=285, y=234
	video offset=CINEMATIC_273, x=221, y=198
	play id=0x005E, freq=0x14, vol=0x20, channel=0x02
