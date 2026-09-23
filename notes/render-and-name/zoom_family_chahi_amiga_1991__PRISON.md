# PRISON: the zoom-in cutscene family starts four steps earlier

The ladder draws its side panels in this order, and their widths fall
monotonically the whole way:

    272/273  79.0      266/267  72.0      LEFT_1  68.0
    270/271  74.5      LEFT_0   70.0      LEFT_2  65.5   ... down to 41.5

So `CINEMATIC_266..273` are four pairs of the **same** zoom sequence, drawn
before the ones already named, and the existing family is mis-based by four.
Left and right are settled by the signed bounding box, not by the order the
routine draws them: every `LEFT` spans negative x (e.g. -115.0..-36.0) and
every `RIGHT` the mirror of it.

Renumbering 20 earned names is the point of this table. The alternative is a
family that starts at 4, or a second family for the first four steps, and both
misdescribe one continuous camera move.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_9 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_13 | high | already named, shifted by four so the run starts at the first step actually drawn; 41.5 wide, which is index 13's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_9 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_13 | high | already named, shifted by four so the run starts at the first step actually drawn; 41.5 wide, which is index 13's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_8 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_12 | high | already named, shifted by four so the run starts at the first step actually drawn; 41.5 wide, which is index 12's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_8 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_12 | high | already named, shifted by four so the run starts at the first step actually drawn; 42.5 wide, which is index 12's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_7 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_11 | high | already named, shifted by four so the run starts at the first step actually drawn; 50.0 wide, which is index 11's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_7 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_11 | high | already named, shifted by four so the run starts at the first step actually drawn; 48.0 wide, which is index 11's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_6 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_10 | high | already named, shifted by four so the run starts at the first step actually drawn; 49.5 wide, which is index 10's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_6 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_10 | high | already named, shifted by four so the run starts at the first step actually drawn; 49.5 wide, which is index 10's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_5 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_9 | high | already named, shifted by four so the run starts at the first step actually drawn; 52.0 wide, which is index 9's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_5 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_9 | high | already named, shifted by four so the run starts at the first step actually drawn; 45.5 wide, which is index 9's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_8 | high | already named, shifted by four so the run starts at the first step actually drawn; 56.5 wide, which is index 8's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_4 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_8 | high | already named, shifted by four so the run starts at the first step actually drawn; 48.0 wide, which is index 8's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_3 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_7 | high | already named, shifted by four so the run starts at the first step actually drawn; 62.0 wide, which is index 7's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_3 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_7 | high | already named, shifted by four so the run starts at the first step actually drawn; 62.0 wide, which is index 7's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_2 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_6 | high | already named, shifted by four so the run starts at the first step actually drawn; 65.5 wide, which is index 6's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_2 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_6 | high | already named, shifted by four so the run starts at the first step actually drawn; 65.5 wide, which is index 6's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_1 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_5 | high | already named, shifted by four so the run starts at the first step actually drawn; 68.0 wide, which is index 5's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_1 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_5 | high | already named, shifted by four so the run starts at the first step actually drawn; 68.0 wide, which is index 5's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_0 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4 | high | already named, shifted by four so the run starts at the first step actually drawn; 70.0 wide, which is index 4's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_0 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_4 | high | already named, shifted by four so the run starts at the first step actually drawn; 70.0 wide, which is index 4's place in the monotonic fall from 79.0 to 41.5 |
| CINEMATIC_272 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_0 | high | 79.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 1. `LEFT` from the signed bounding box |
| CINEMATIC_273 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_0 | high | 79.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 1. `RIGHT` from the signed bounding box |
| CINEMATIC_270 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_1 | high | 74.5 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 2. `LEFT` from the signed bounding box |
| CINEMATIC_271 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_1 | high | 74.5 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 2. `RIGHT` from the signed bounding box |
| CINEMATIC_268 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_2 | high | 73.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 3. `LEFT` from the signed bounding box |
| CINEMATIC_269 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_2 | high | 73.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 3. `RIGHT` from the signed bounding box |
| CINEMATIC_266 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_3 | high | 72.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 4. `LEFT` from the signed bounding box |
| CINEMATIC_267 | CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_RIGHT_3 | high | 72.0 wide, 3 paths, 234 tall -- the same side panel as the rest of the family at a wider zoom step. Drawn by the zoom ladder immediately before the pair now at index 4. `RIGHT` from the signed bounding box |
