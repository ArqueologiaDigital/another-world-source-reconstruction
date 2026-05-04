TEARDOWN_CHANS_AND_KILL_LANDING:
	deleteChannels first=0x00, last=0x08
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=0x020F
	ret

LABEL_882F:
	mov [0x23], 0x0001
	jl [0x02], [0x41], LABEL_883D
	mov [0x23], 0x0000

LABEL_883D:
	ret

LABEL_883E:
	mov [0x02], [0x40]
	je [0x23], 0x00, LABEL_884A
	mov [0x02], [0x44]

LABEL_884A:
	ret

LABEL_884B:
	setup channel=0x10, address=LABEL_136A
	call LABEL_00F7
	setup channel=0x18, address=LABEL_433F
	setup channel=0x2F, address=LABEL_395D
	setup channel=0x3B, address=0x020F
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	call LABEL_882F
	call INIT_RANGE_48_TO_4D_TO_MAX
	call INIT_VARS_A1_A4_A7_AA_PLUS4
	mov [0x27], [HACK_VAR_67]
	call LABEL_872B
	je [HACK_VAR_67], 0x65, LABEL_86E7
	je [HACK_VAR_67], 0x01, LABEL_831C
	je [HACK_VAR_67], 0x02, LABEL_8385
	je [HACK_VAR_67], 0x03, LABEL_83C9
	je [HACK_VAR_67], 0x04, LABEL_8412
	je [HACK_VAR_67], 0x05, LABEL_8470
	je [HACK_VAR_67], 0x23, LABEL_85F1
	je [HACK_VAR_67], 0x24, LABEL_8582
	je [HACK_VAR_67], 0x25, LABEL_84C1
	je [HACK_VAR_67], 0x44, LABEL_86A2
	je [HACK_VAR_67], 0x45, LABEL_863D

VAR66_RANGE_DISPATCH_BY_VAR01:
	je [0x66], [HACK_VAR_67], COPY_HACK67_TO_VAR66
	mov [0xF8], [0x66]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, COPY_PAGE0_TO_PAGE_FF
	jl [0x01], 0x8C, COPY_PAGE0_TO_PAGE_FF
	jl [0x01], 0xBE, COPY_HACK67_TO_VAR66
