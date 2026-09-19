.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PAL_CODEWHEEL_PRE_TITLE_RAMP:
	setPalette 0x17
	break
	setPalette 0x16
	break
	setPalette 0x15
	break
	setPalette 0x14
	break
	setPalette 0x13
	break
	setPalette 0x12
	break
	setPalette 0x11
	break
	setPalette 0x10
	break
	setPalette 0x0F
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PAL_CODEWHEEL_PUBLISHER_LOGO_FADE_OUT:
	setPalette 0x04
	break
	setPalette 0x05
	break
	setPalette 0x06
	break
	setPalette 0x07
	break
	setPalette 0x18
	break
	setPalette 0x19
	break
	setPalette 0x1A
	break
	setPalette 0x00
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PAL_CODEWHEEL_PUBLISHER_LOGO_FADE_IN:
	setPalette 0x1A
	break
	setPalette 0x19
	break
	setPalette 0x18
	break
	setPalette 0x07
	break
	setPalette 0x06
	break
	setPalette 0x05
	break
	setPalette 0x04
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PAL_CODEWHEEL_TITLE_SCREEN_FADE_IN:
	setPalette 0x0E
	break
	setPalette 0x0D
	break
	setPalette 0x0C
	break
	setPalette 0x0B
	break
	setPalette 0x0A
	break
	setPalette 0x09
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PAL_CODEWHEEL_TITLE_SCREEN_FADE_OUT:
	setPalette 0x09
	break
	setPalette 0x0A
	break
	setPalette 0x0B
	break
	setPalette 0x0C
	break
	setPalette 0x0D
	break
	setPalette 0x0E
	killChannel
.endif

