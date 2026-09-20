# CAVES (msdos) — the same four families, on msdos's own art

The amiga batches for this stage were branch-scoped because the two ports'
banks do not align, which means msdos got nothing from them. This is the same
work done against msdos's own constants and msdos's own renders (stage 4,
palette 0), scoped to dos_1992.

Same three structural findings hold here, checked on this port rather than
assumed from the other: both turn routines draw the *same nine* constants
(554 down to 546 one way, 546 up to 554 the other), and both blast ladders draw
the *same nine* — so neither carries a direction. The impact ladders are a
genuine split.

**One real difference from the amiga release**: msdos's `LASER_BOLT_SPAN` has a
**fifth** length, `FROM_3E`, measured at 62 px. The amiga set stops at 30. The
1992 port extended the beam tile set.

| constant | proposed name | confidence | evidence |
|---|---|---|---|
| CINEMATIC_546 | CINEMATIC_CAVES_HERO_TURN_0 | high | frame 0 of the nine shared by both turn routines; rendered |
| CINEMATIC_547 | CINEMATIC_CAVES_HERO_TURN_1 | high | frame 1 of the nine shared by both turn routines; rendered |
| CINEMATIC_548 | CINEMATIC_CAVES_HERO_TURN_2 | high | frame 2 of the nine shared by both turn routines; rendered |
| CINEMATIC_549 | CINEMATIC_CAVES_HERO_TURN_3 | high | frame 3 of the nine shared by both turn routines; rendered |
| CINEMATIC_550 | CINEMATIC_CAVES_HERO_TURN_4 | high | frame 4 of the nine shared by both turn routines; rendered |
| CINEMATIC_551 | CINEMATIC_CAVES_HERO_TURN_5 | high | frame 5 of the nine shared by both turn routines; rendered |
| CINEMATIC_552 | CINEMATIC_CAVES_HERO_TURN_6 | high | frame 6 of the nine shared by both turn routines; rendered |
| CINEMATIC_553 | CINEMATIC_CAVES_HERO_TURN_7 | high | frame 7 of the nine shared by both turn routines; rendered |
| CINEMATIC_554 | CINEMATIC_CAVES_HERO_TURN_8 | high | frame 8 of the nine shared by both turn routines; rendered |
| CINEMATIC_787 | CINEMATIC_CAVES_LASER_BLAST_0 | high | case 0x81, shared by both blast ladders so no side; rendered |
| CINEMATIC_786 | CINEMATIC_CAVES_LASER_BLAST_1 | high | case 0x82, shared by both blast ladders so no side; rendered |
| CINEMATIC_785 | CINEMATIC_CAVES_LASER_BLAST_2 | high | case 0x83, shared by both blast ladders so no side; rendered |
| CINEMATIC_784 | CINEMATIC_CAVES_LASER_BLAST_3 | high | case 0x84, shared by both blast ladders so no side; rendered |
| CINEMATIC_783 | CINEMATIC_CAVES_LASER_BLAST_4 | high | case 0x85, shared by both blast ladders so no side; rendered |
| CINEMATIC_782 | CINEMATIC_CAVES_LASER_BLAST_5 | high | case 0x86, shared by both blast ladders so no side; rendered |
| CINEMATIC_781 | CINEMATIC_CAVES_LASER_BLAST_6 | high | case 0x87, shared by both blast ladders so no side; rendered |
| CINEMATIC_780 | CINEMATIC_CAVES_LASER_BLAST_7 | high | case 0x88, shared by both blast ladders so no side; rendered |
| CINEMATIC_779 | CINEMATIC_CAVES_LASER_BLAST_8 | high | case 0x89, shared by both blast ladders so no side; rendered |
| CINEMATIC_796 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_0 | high | case 0x6F; rendered |
| CINEMATIC_795 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_1 | high | case 0x70; rendered |
| CINEMATIC_794 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_2 | high | case 0x71; rendered |
| CINEMATIC_793 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_3 | high | case 0x72; rendered |
| CINEMATIC_792 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_4 | high | case 0x73; rendered |
| CINEMATIC_791 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_5 | high | case 0x74; rendered |
| CINEMATIC_790 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_6 | high | case 0x75; rendered |
| CINEMATIC_789 | CINEMATIC_CAVES_LASER_IMPACT_RIGHT_7 | high | case 0x76; rendered |
| CINEMATIC_839 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_0 | high | case 0x6F; rendered |
| CINEMATIC_838 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_1 | high | case 0x70; rendered |
| CINEMATIC_837 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_2 | high | case 0x71; rendered |
| CINEMATIC_836 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_3 | high | case 0x72; rendered |
| CINEMATIC_835 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_4 | high | case 0x73; rendered |
| CINEMATIC_834 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_5 | high | case 0x74; rendered |
| CINEMATIC_833 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_6 | high | case 0x75; rendered |
| CINEMATIC_832 | CINEMATIC_CAVES_LASER_IMPACT_LEFT_7 | high | case 0x76; rendered |
| CINEMATIC_847 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_0 | high | 1px bar right from x=64, length 2; measured |
| CINEMATIC_849 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_1 | high | 1px bar right from x=64, length 6; measured |
| CINEMATIC_851 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_2 | high | 1px bar right from x=64, length 14; measured |
| CINEMATIC_853 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_3 | high | 1px bar right from x=64, length 30; measured |
| CINEMATIC_855 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_4 | high | 1px bar right from x=64, length 62; measured |
| CINEMATIC_848 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_0 | high | 1px bar, left variant, length 2; measured |
| CINEMATIC_850 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_1 | high | 1px bar, left variant, length 6; measured |
| CINEMATIC_852 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_2 | high | 1px bar, left variant, length 14; measured |
| CINEMATIC_854 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_3 | high | 1px bar, left variant, length 30; measured |
| CINEMATIC_856 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_4 | high | 1px bar, left variant, length 62; measured |
