# CAPSULE (msdos) — the impact bursts and the beam spans, on msdos's art

Branch-scoped to dos_1992, rendered at msdos stage 6 palette 0. Structure is
identical to the amiga batch and checked here rather than assumed: eight case
frames a side over 0x6F..0x76 plus a `_DONE` join, and the render shows the
same progression — 636 and 653 are solid wedges, the ladders disperse, and the
two `_DONE` constants 628 and 645 are the widest, sparsest scatters, so they
are frame 8.

Like msdos CAVES, the beam span set has a **fifth** length the amiga release
lacks: `FROM_3E`, measured at 62 px. Four lengths on amiga, five on msdos, in
both stages that carry the set.

| constant | proposed name | confidence | evidence |
|---|---|---|---|
| CINEMATIC_636 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_0 | high | case 0x6F; rendered |
| CINEMATIC_635 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_1 | high | case 0x70; rendered |
| CINEMATIC_634 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_2 | high | case 0x71; rendered |
| CINEMATIC_633 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_3 | high | case 0x72; rendered |
| CINEMATIC_632 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_4 | high | case 0x73; rendered |
| CINEMATIC_631 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_5 | high | case 0x74; rendered |
| CINEMATIC_630 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_6 | high | case 0x75; rendered |
| CINEMATIC_629 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_7 | high | case 0x76; rendered |
| CINEMATIC_628 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_RIGHT_8 | high | the _DONE join, widest and sparsest frame; rendered |
| CINEMATIC_653 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_0 | high | case 0x6F; rendered |
| CINEMATIC_652 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_1 | high | case 0x70; rendered |
| CINEMATIC_651 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_2 | high | case 0x71; rendered |
| CINEMATIC_650 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_3 | high | case 0x72; rendered |
| CINEMATIC_649 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_4 | high | case 0x73; rendered |
| CINEMATIC_648 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_5 | high | case 0x74; rendered |
| CINEMATIC_647 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_6 | high | case 0x75; rendered |
| CINEMATIC_646 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_7 | high | case 0x76; rendered |
| CINEMATIC_645 | CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_LEFT_8 | high | the _DONE join, widest and sparsest frame; rendered |
| CINEMATIC_661 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_0 | high | 1px bar right from x=64, length 2; measured |
| CINEMATIC_663 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_1 | high | 1px bar right from x=64, length 6; measured |
| CINEMATIC_665 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_2 | high | 1px bar right from x=64, length 14; measured |
| CINEMATIC_667 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_3 | high | 1px bar right from x=64, length 30; measured |
| CINEMATIC_669 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_4 | high | 1px bar right from x=64, length 62; measured |
| CINEMATIC_662 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_0 | high | 1px bar, left variant, length 2; measured |
| CINEMATIC_664 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_1 | high | 1px bar, left variant, length 6; measured |
| CINEMATIC_666 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_2 | high | 1px bar, left variant, length 14; measured |
| CINEMATIC_668 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_3 | high | 1px bar, left variant, length 30; measured |
| CINEMATIC_670 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_4 | high | 1px bar, left variant, length 62; measured |
