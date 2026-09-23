# Screen entry routines in PRISON -- chahi_amiga_1991

Derived by notes/screen-scope/screen_entry.py: the chain of je [SCREEN_NUM] lines whose every target writes the camera bounds, tears down the previous screen and sets a palette.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_85F5 | PRISON_SCREEN_ENTRY_DISPATCH | high | it is the chain of 11 `je [SCREEN_NUM], 0xNN, T` lines whose every target writes the camera bounds `[0x40]..[0x47]`, tears down the previous screen's channels and sets a palette |
| LABEL_8491 | PRISON_SCREEN_65_ENTRY | high | selected by `je [SCREEN_NUM], 0x65` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_80F5 | PRISON_SCREEN_01_ENTRY | high | selected by `je [SCREEN_NUM], 0x01` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_815E | PRISON_SCREEN_02_ENTRY | high | selected by `je [SCREEN_NUM], 0x02` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_81A2 | PRISON_SCREEN_03_ENTRY | high | selected by `je [SCREEN_NUM], 0x03` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_81EB | PRISON_SCREEN_04_ENTRY | high | selected by `je [SCREEN_NUM], 0x04` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_8249 | PRISON_SCREEN_05_ENTRY | high | selected by `je [SCREEN_NUM], 0x05` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_83C4 | PRISON_SCREEN_23_ENTRY | high | selected by `je [SCREEN_NUM], 0x23` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_8355 | PRISON_SCREEN_24_ENTRY | high | selected by `je [SCREEN_NUM], 0x24` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_8294 | PRISON_SCREEN_25_ENTRY | high | selected by `je [SCREEN_NUM], 0x25` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_844C | PRISON_SCREEN_44_ENTRY | high | selected by `je [SCREEN_NUM], 0x44` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_8410 | PRISON_SCREEN_45_ENTRY | high | selected by `je [SCREEN_NUM], 0x45` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
