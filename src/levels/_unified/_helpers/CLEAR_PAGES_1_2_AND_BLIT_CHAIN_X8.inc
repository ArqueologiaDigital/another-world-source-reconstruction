CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8:
	fill page=0x01, color=0x00
	fill page=0x02, color=0x00
	selectVideoPage 0x01
	blitFramebuffer 0x01
	blitFramebuffer 0xFF
	blitFramebuffer 0x02
	ret
	killChannel
