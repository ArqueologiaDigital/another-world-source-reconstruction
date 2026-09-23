# Screen entry routines in CAPSULE -- chahi_amiga_1991

Derived by notes/screen-scope/screen_entry.py: the chain of je [SCREEN_NUM] lines whose every target writes the camera bounds, tears down the previous screen and sets a palette.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_8521 | CAPSULE_SCREEN_ENTRY_DISPATCH | high | it is the chain of 7 `je [SCREEN_NUM], 0xNN, T` lines whose every target writes the camera bounds `[0x40]..[0x47]`, tears down the previous screen's channels and sets a palette |
| LABEL_7FD7 | CAPSULE_SCREEN_4B_ENTRY | high | selected by `je [SCREEN_NUM], 0x4B` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_802A | CAPSULE_SCREEN_4C_ENTRY | high | selected by `je [SCREEN_NUM], 0x4C` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_805B | CAPSULE_SCREEN_4D_ENTRY | high | selected by `je [SCREEN_NUM], 0x4D` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_80A6 | CAPSULE_SCREEN_91_ENTRY | high | selected by `je [SCREEN_NUM], 0x91` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_80F2 | CAPSULE_SCREEN_92_ENTRY | high | selected by `je [SCREEN_NUM], 0x92` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
| LABEL_8094 | CAPSULE_SCREEN_64_ENTRY | high | selected by `je [SCREEN_NUM], 0x64` from the stage's screen-entry chain, and `screen_scope.py` independently pins it to that one screen; its body writes the camera bounds and re-installs the screen's threads |
