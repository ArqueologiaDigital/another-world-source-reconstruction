LABEL_3703:
	call LABEL_36BB
	call GUARDED_ALIEN_ANIM_CV_128
	break
	jg [0x01], 0xAA, LABEL_3703
	djnz [0x6F], LABEL_3703
	mov [0x6F], 0x0003

LABEL_3718:
	jg [0x01], 0x7D, LABEL_373E
	call LABEL_36BB
	call LABEL_7D30
	break
	djnz [0x6F], LABEL_3718
	mov [0x6F], 0x0003

LABEL_372D:
	jg [0x01], 0x7D, LABEL_373E
	call LABEL_36BB
	call LABEL_7D4C
	break
	djnz [0x6F], LABEL_372D

LABEL_373E:
	call LABEL_36BB
	call GUARDED_DRAW_CV_304_305
	break
	jne [HACK_VAR_67], 0x6D, INIT_VAR6F_TO_A_PAUSE_3
	jl [0x01], 0x8F, LABEL_373E
	jg [0x01], 0xA2, LABEL_373E
	mov [0x63], 0x0064
	deleteChannels first=0x14, last=0x16
	call LABEL_36BB
	call GUARDED_DRAW_CV_304_305
	break
	deleteChannels first=0x14, last=0x16
	jne [HACK_VAR_67], [0x6A], LABEL_3775
	video type=1, offset=CINEMATIC_292, x=[0x68], y=[0x69], zoom=0x40

LABEL_3775:
	break
	or [0xB9], 0x0020
	jne [HACK_VAR_67], [0x6A], LABEL_3785
	video type=1, offset=CINEMATIC_291, x=[0x68], y=[0x69], zoom=0x40

LABEL_3785:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3791
	video type=1, offset=CINEMATIC_290, x=[0x68], y=[0x69], zoom=0x40

LABEL_3791:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_379D
	video type=1, offset=CINEMATIC_289, x=[0x68], y=[0x69], zoom=0x40

LABEL_379D:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_37A9
	video type=1, offset=CINEMATIC_289, x=[0x68], y=[0x69], zoom=0x40

LABEL_37A9:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_37B5
	video type=1, offset=CINEMATIC_288, x=[0x68], y=[0x69], zoom=0x40

LABEL_37B5:
	setup channel=0x14, address=LABEL_393D
	mov [0x6F], 0x0007

LABEL_37BD:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_37C9
	video type=1, offset=CINEMATIC_284, x=[0x68], y=[0x69], zoom=0x40

LABEL_37C9:
	djnz [0x6F], LABEL_37BD
	add [0x68], 0x000A
	mov [0x6F], 0x0004

LABEL_37D5:
	break
	call LABEL_36BB
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x6F], LABEL_37D5
	setup channel=0x23, address=LABEL_80C2
	mov [0x6C], 0x0004
	mov [0x6F], 0x000A
	killChannel

LABEL_37ED:
	mov [PAUSE_SLICES], 0x0004
	jne [HACK_VAR_67], [0x6A], LABEL_37FC
	video type=1, offset=CINEMATIC_283, x=[0x07], y=[0x08], zoom=0x40

LABEL_37FC:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3808
	video type=1, offset=CINEMATIC_282, x=[0x07], y=[0x08], zoom=0x40

LABEL_3808:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3813
	video type=1, offset=CINEMATIC_281, x=156, y=98

LABEL_3813:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_381E
	video type=1, offset=CINEMATIC_280, x=171, y=100

LABEL_381E:
	break
	or [0xB9], 0x0010
	jne [HACK_VAR_67], [0x6A], LABEL_3837
	setup channel=0x04, address=KILL_CHANNEL_LANDING
	video type=1, offset=CINEMATIC_279, x=193, y=110
	play id=0x0060, freq=0x14, vol=0x40, channel=0x02

LABEL_3837:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3847
	video type=1, offset=CINEMATIC_278, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_279, x=217, y=125

LABEL_3847:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3858
	video type=1, offset=CINEMATIC_276, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_277, x=274, y=122, zoom=0x40

LABEL_3858:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3869
	video type=1, offset=CINEMATIC_275, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_274, x=281, y=157, zoom=0x40

LABEL_3869:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_387A
	video type=1, offset=CINEMATIC_273, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_274, x=274, y=178, zoom=0x40

LABEL_387A:
	break
	jne [HACK_VAR_67], [0x6A], LABEL_3895
	video type=1, offset=CINEMATIC_270, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_118, x=284, y=224, zoom=0x40
	video type=1, offset=CINEMATIC_272, x=222, y=175
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x02

LABEL_3895:
	break
	jne [HACK_VAR_67], [0x6A], INLINE_SET_VAR29_TO_6
	video type=1, offset=CINEMATIC_271, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_118, x=285, y=234, zoom=0x40
	video type=1, offset=CINEMATIC_272, x=221, y=198
	play id=0x005E, freq=0x14, vol=0x20, channel=0x02
