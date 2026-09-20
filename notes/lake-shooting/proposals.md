# LAKE: the scene the coordinate group was hiding

Evidence column cites `shooting_scene_geometry.py` output (amiga; msdos
identical, 16 of 16 by `canonical_md5`). Screen spans are anchor + signed
bbox. Apply with:

    python3 ../../../another-world-archaeology/tools/apply_cinematic_renames.py \
        --stage LAKE --proposals notes/lake-shooting/proposals.md --apply

| constant | proposed name | confidence | evidence |
| CINEMATIC_LAKE_DECOR_AT_327_164 | CINEMATIC_LAKE_SHOOTER_AIM_LEFT_F0 | high | 63x58/5 at x282..345 y126..184, right screen edge; torso plus an arm extended LEFT holding a barrel whose y matches the beam. Drawn before the shot. |
| CINEMATIC_LAKE_SCENE_DECOR_RIGHT | CINEMATIC_LAKE_SHOOTER_AIM_LEFT_F1 | high | same subject, same anchor, 5 leaves; arm reaches 3px further left (x0 -48 vs -45). Drawn after the shot and in the standalone hold loop. |
| CINEMATIC_DECOR_AT_327_164_F0 | CINEMATIC_LAKE_SHOT_BEAM_HEAD | high | 221x16/5 at x232..454 y148..164, flare at the LEFT end, abutting the shooter's left edge (282). Drawn first, with `play id=0x0052`. |
| CINEMATIC_DECOR_AT_327_164_F1 | CINEMATIC_LAKE_SHOT_BEAM_SPAN | high | 213x2/3 bar, drawn three times one frame apart at x100..314, -40..174, -166..46 — stepping leftwards off the screen, all at y154..156. |
| CINEMATIC_DECOR_AT_305_155_F0 | CINEMATIC_LAKE_SHOT_MUZZLE_BEAM | high | 47x3/1 at x282..328 y154..156 — exactly the shooter's left edge at barrel height; looped on its own channel from the shot until the body settles. |
| CINEMATIC_LAKE_LESTER_RECOVER | CINEMATIC_LAKE_SHOT_BEAM_IMPACT | high | not a pose: a group of a 17x26 solid plus three 213x1 bars, 216 wide, drawn at the hero slot the frame the beam arrives. Nothing in it recovers. |
| CINEMATIC_LAKE_LESTER_RISE | CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F0 | high | 65x25/15 horizontal body, 25 tall against 48 standing, drawn at the hero slot after `sub [HERO_X],12 / add [HERO_Y],3`. Moving left and DOWN: nothing rises. |
| CINEMATIC_DECOR_AT_305_155_F1 | CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F1 | high | 41x19/12 at the hero slot, step -10x/+5y, continuous with F0. |
| CINEMATIC_DECOR_AT_305_155_F2 | CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F2 | high | 29x23/10 at the hero slot, step -3x, four frames. |
| CINEMATIC_DECOR_AT_305_155_F3 | CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F3 | high | 39x16/12 at the hero slot, step -2x. |
| CINEMATIC_DECOR_AT_305_155_F4 | CINEMATIC_LAKE_LESTER_KNOCKED_BACK_F4 | high | 43x13/11 at the hero slot, step -1x, flattest of the run, then held forever while `LAKE_PALETTE_FADE_IN` takes the freed channel. |
