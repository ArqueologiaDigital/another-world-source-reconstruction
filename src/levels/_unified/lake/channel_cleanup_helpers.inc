KILL_CH_01_04_38:
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x38, address=KILL_CHANNEL_ROUTINE
	ret

DEL_CH_FOR_TRANSITION:
	deleteChannels first=0x00, last=0x08
	deleteChannels first=0x33, last=0x38
	ret

CLEANUP_BEFORE_S2_OR_OUTSIDE_POOL:
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	deleteChannels first=0x0B, last=0x13
	deleteChannels first=0x35, last=0x38
	ret

CLEANUP_BEFORE_S1_OR_S3:
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	deleteChannels first=0x0B, last=0x13
	deleteChannels first=0x35, last=0x38
	ret

DELETE_CH_01_06_RET:
	deleteChannels first=0x01, last=0x06
	ret
	killChannel

