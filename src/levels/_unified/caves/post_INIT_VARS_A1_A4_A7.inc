SETUP_KILL_CHAN_3B_AT_LANDING:
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	ret

DELETE_GAME_CHANS_AND_TEARDOWN:
	deleteChannels first=0x00, last=0x08
	call SETUP_KILL_CHAN_3B_AT_LANDING
	ret
