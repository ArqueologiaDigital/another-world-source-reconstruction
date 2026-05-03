SETUP_KILL_CHAN_3B_AT_LANDING:
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=KILL_CHANNEL_LANDING	;@raw=0x08,0x3B,0x01,0x60
	ret

DELETE_GAME_CHANS_AND_TEARDOWN:
	deleteChannels first=0x00, last=0x08
	call SETUP_KILL_CHAN_3B_AT_LANDING	;@raw=0x04,0xD4,0xFA
	ret
