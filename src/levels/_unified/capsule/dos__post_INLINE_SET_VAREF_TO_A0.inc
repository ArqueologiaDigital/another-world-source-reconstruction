LABEL_21DD:
	video offset=CINEMATIC_348, x=[0xef], y=120
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=114
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=110
	sub [0xEF], 0x0014
	break
	play id=0x008D, freq=0x22, vol=0x0A, channel=0x02
	video offset=CINEMATIC_348, x=[0xef], y=108
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=110
	sub [0xEF], 0x0014
	break
	play id=0x0060, freq=0x16, vol=0x14, channel=0x00
	video offset=CINEMATIC_348, x=[0xef], y=114
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=116
	sub [0xEF], 0x0014
	break
	jmp LABEL_21DD

LABEL_2238:
	video offset=CINEMATIC_CAPSULE_FIGURE_UPRIGHT, x=[0xe9], y=[0xea]
	play id=0x008D, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F1, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F2, x=[0xe9], y=[0xea]
	play id=0x0074, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F3, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F4, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F5, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F6, x=[0xe9], y=[0xea]
	killChannel

LABEL_2274:
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0, x=[0xeb], y=[0xec]
	play id=0x008D, freq=0x14, vol=0x40, channel=0x03
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F1, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F2, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F3, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F4, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F5, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F6, x=[0xeb], y=[0xec]
	killChannel

CAPSULE_PALETTE_FLASH_INTO_PAGE_0_PRESENT:
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F1, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F2, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F3, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F4, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F5, x=2, y=103
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F6, x=2, y=103
	killChannel

LABEL_22C7:
	video offset=CINEMATIC_361, x=179, y=100
	break
	video offset=CINEMATIC_361, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F0, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F1, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F2, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F3, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F4, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F5, x=179, y=100
	break
	video offset=CINEMATIC_CAPSULE_FIGURE_DISSOLVE_F6, x=179, y=100
	killChannel

LABEL_22F4:
	video offset=CINEMATIC_CAPSULE_FLYER_F0, x=[0xe6], y=[0xe7]
	play id=0x006C, freq=0x14, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F1, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F2, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F3, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F4, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F5, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F6, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F7, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_CAPSULE_FLYER_F7, x=[0xe6], y=[0xe7]
	break
	jmp LABEL_22F4
LABEL_2333:
	db 0x11
