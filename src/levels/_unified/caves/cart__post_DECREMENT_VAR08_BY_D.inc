LABEL_958D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08]
	call LABEL_9567
	ret

LABEL_959C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_8201
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_95BE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8201
	ret

LABEL_95D0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret

LABEL_95FF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret

LABEL_9619:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_138, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret

LABEL_9640:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_137, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EB1
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret

LABEL_966F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_8181
	add [0x08], 0x000D
	ret

LABEL_9689:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_292, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_81AF
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_81E1
	add [0x08], 0x000D
	ret

LABEL_96C5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_81AF
	add [0x08], 0x000D
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_291, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__96EE:
	call LABEL_950F
	break
	call LABEL_950F
	break
	call LABEL_950F
	sub [0x07], 0x0001
	break
	call LABEL_9521
	add [0x07], 0x0001
	break
	jmp JUNK__96EE
LABEL_9709:
	db 0x11

LABEL_970A:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_9719
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9719:
	call LABEL_8BD9
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_9730
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9730:
	call LABEL_8C06
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_9747
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9747:
	call LABEL_8C2B
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_975E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_975E:
	call LABEL_8C58
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_9775
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9775:
	call LABEL_8C85
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_978C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_978C:
	call LABEL_8CAA
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_97A3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97A3:
	call LABEL_8CD7
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97BA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97BA:
	call LABEL_8CFC
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97D1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97D1:
	call LABEL_8D29
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_97E8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97E8:
	call LABEL_8D56
	add [0x07], 0x000A
	break
	jmp LABEL_970A
	killChannel

LABEL_97F4:
	call GUARDED_BEAST_OR_CV_304_305
	break
	jmp LABEL_97F4
LABEL_97FB:
	db 0x11

LABEL_97FC:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_980B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_980B:
	call LABEL_8F79
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9822
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9822:
	call LABEL_8F9F
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9839
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9839:
	call LABEL_8FCD
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9850
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9850:
	call LABEL_8FEE
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9867
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9867:
	call LABEL_9015
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_987E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_987E:
	call LABEL_9036
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9895
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9895:
	call LABEL_905C
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_98AC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98AC:
	call LABEL_9082
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98C3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98C3:
	call LABEL_90A8
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98DA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98DA:
	call LABEL_90CE
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98F1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98F1:
	call LABEL_90FC
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9908
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9908:
	call LABEL_9122
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_991F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_991F:
	call LABEL_914E
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9936
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9936:
	call LABEL_916F
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_994D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_994D:
	call LABEL_9190
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9964
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9964:
	call LABEL_91B1
	add [0x07], 0x0002
	break
	jmp LABEL_97FC
LABEL_996F:
	db 0x11

LABEL_9970:
	je [0x0A], [0x0C], KILL_CHAN_AT_998E
	jg [0x0A], [0x0C], LABEL_998F

LABEL_997C:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_9988
	break

LABEL_9988:
	jl [0x0A], [0x0C], LABEL_997C

KILL_CHAN_AT_998E:
	killChannel

LABEL_998F:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_999B
	break

LABEL_999B:
	jg [0x0A], [0x0C], LABEL_998F
	killChannel

LABEL_99A2:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_99D7
	je [HERO_POS_MASK], 0x00, LABEL_99C5
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_9970
	ret

LABEL_99C5:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_9970

LABEL_99D7:
	ret

LABEL_99D8:
	video type=0, offset=COMMON_VIDEO_330, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_149
	ret

DRAW_CIN_149:
	video offset=CINEMATIC_149, x=[0x01], y=[0x02]
	ret

LABEL_99EA:
	video type=0, offset=COMMON_VIDEO_331, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_150
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_332, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_150:
	video offset=CINEMATIC_150, x=[0x01], y=[0x02]
	ret

LABEL_9A14:
	video type=0, offset=COMMON_VIDEO_333, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_151
	ret

DRAW_CIN_151:
	video offset=CINEMATIC_151, x=[0x01], y=[0x02]
	ret

LABEL_9A26:
	video type=0, offset=COMMON_VIDEO_348, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_175
	ret

DRAW_CIN_175:
	video offset=CINEMATIC_175, x=[0x01], y=[0x02]
	ret

LABEL_9A38:
	video offset=CINEMATIC_176, x=[0x01], y=[0x02]
	je [0xBE], 0x03, DRAW_CIN_177
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_349, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_177:
	video offset=CINEMATIC_177, x=[0x01], y=[0x02]
	ret

LABEL_9A62:
	video type=0, offset=COMMON_VIDEO_350, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_178
	ret

DRAW_CIN_178:
	video offset=CINEMATIC_178, x=[0x01], y=[0x02]
	ret

LABEL_9A74:
	jne [0x05], 0x00, LABEL_9A80
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A80:
	jne [0x05], 0x01, LABEL_9A8C
	video type=0, offset=COMMON_VIDEO_345, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A8C:
	jne [0x05], 0x02, LABEL_9A98
	video type=0, offset=COMMON_VIDEO_344, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9A98:
	jne [0x05], 0x03, LABEL_9AA4
	video type=0, offset=COMMON_VIDEO_343, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9AA4:
	ret

LABEL_9AA5:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_037, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_159:
	call LABEL_99A2
	jne [0x0A], 0x01, LABEL_9ADD
	video type=0, offset=COMMON_VIDEO_159, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9ADD:
	jne [0x0A], 0x02, LABEL_9B01
	video type=0, offset=COMMON_VIDEO_157, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B01:
	jne [0x0A], 0x03, LABEL_9B25
	video type=0, offset=COMMON_VIDEO_155, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B25:
	video type=0, offset=COMMON_VIDEO_153, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_148
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_148:
	video offset=CINEMATIC_148, x=[0x01], y=[0x02]
	ret

LABEL_9B4F:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_039, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B60:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B71:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B82:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9B99:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BAA:
	call LABEL_9A74
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BBE:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BCF:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BE0:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9BF1:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C02:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C13:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C2A:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C3B:
	call LABEL_9A74
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C4F:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9C60:
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_162
	ret

DRAW_CIN_162:
	video offset=CINEMATIC_162, x=[0x01], y=[0x02]
	ret

LABEL_9C72:
	video type=0, offset=COMMON_VIDEO_131, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_163
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_163:
	video offset=CINEMATIC_163, x=[0x01], y=[0x02]
	ret

LABEL_9C9C:
	video type=0, offset=COMMON_VIDEO_338, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_164
	ret

DRAW_CIN_164:
	video offset=CINEMATIC_164, x=[0x01], y=[0x02]
	ret

LABEL_9CAE:
	video type=0, offset=COMMON_VIDEO_346, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_171
	ret

DRAW_CIN_171:
	video offset=CINEMATIC_171, x=[0x01], y=[0x02]
	ret

LABEL_9CC0:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_172
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_172:
	video offset=CINEMATIC_172, x=[0x01], y=[0x02]
	ret

LABEL_9CEA:
	video type=0, offset=COMMON_VIDEO_347, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_173
	ret

DRAW_CIN_173:
	video offset=CINEMATIC_173, x=[0x01], y=[0x02]
	ret

GUARDED_DRAW_CV_126:
	call LABEL_99A2
	jne [0x0A], 0x01, LABEL_9D0B
	video type=0, offset=COMMON_VIDEO_126, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D0B:
	jne [0x0A], 0x02, LABEL_9D17
	video type=0, offset=COMMON_VIDEO_125, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D17:
	jne [0x0A], 0x03, LABEL_9D23
	video type=0, offset=COMMON_VIDEO_124, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D23:
	video type=0, offset=COMMON_VIDEO_122, x=[0x01], y=[0x02], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_165
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CIN_165:
	video offset=CINEMATIC_165, x=[0x01], y=[0x02]
	ret

LABEL_9D4D:
	jne [0x05], 0x00, LABEL_9D59
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D59:
	jne [0x05], 0x01, LABEL_9D65
	video type=0, offset=COMMON_VIDEO_342, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D65:
	jne [0x05], 0x02, LABEL_9D71
	video type=0, offset=COMMON_VIDEO_127, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D71:
	jne [0x05], 0x03, LABEL_9D7D
	video type=0, offset=COMMON_VIDEO_341, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9D7D:
	ret

LABEL_9D7E:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
