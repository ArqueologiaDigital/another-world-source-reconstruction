# Screen-name corrections in CAVES -- cartridge_1992

Derived by notes/screen-scope/screen_scope.py --proposals: the name states a screen the dataflow contradicts.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME | CAVES_SCREEN_EE_EVENT_PALETTE_FLASH_FRAME | high | the `setup` that installs it tests `[SCREEN_NUM]` and finds 0xEE, not the 0xED the name states |
