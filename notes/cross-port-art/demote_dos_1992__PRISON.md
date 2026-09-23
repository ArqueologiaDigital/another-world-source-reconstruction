# One rename reverted -- it is referenced from a shared chunk

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_PRISON_HERO_STAND_NEUTRAL_BODY | CINEMATIC_555 | high | `prison/prison_step_draws_and_breaks.inc` is included unconditionally, so every branch reads that draw line; renaming the EQU in only two branches left their copies of the symbol undefined. It needs a rename in every branch at once, which needs cartridge's art verified, and cartridge has no extracted ROM |
