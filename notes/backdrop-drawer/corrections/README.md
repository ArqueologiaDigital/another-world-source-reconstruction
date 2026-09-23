# The four renames this module's control forced, with their tables

These were applied by hand rather than from `--proposals`, because each is a
correction rather than a derivation: the probe found the contradiction, and
what to do about it needed reading the code. The tables are here so the
evidence is next to the change, in the form
`apply_routine_renames.py --proposals` takes.

| # | what was wrong |
| --- | --- |
| 01 | amiga CAVES carried `DRAW_CAVES_FIRST_ROOM_BG` on a `break; jmp` join that draws nothing |
| 02 | the msdos counterpart of that join was the unnamed `LABEL_D1E3` |
| 03 | the amiga painter took the earned name the other port had used all along |
| 04 | a screen number carried across ports by `align_branch_names.py`, onto a port that never guards on it |

Run them from the archaeology repo, in this order — 01 frees the name that 03
then takes:

    for t in 01 02 03 04; do
      python3 tools/apply_routine_renames.py --stage <STAGE> --branch <BRANCH> \
        --proposals ../another-world-source-reconstruction/notes/backdrop-drawer/corrections/${t}_*.md --apply
    done

The measurement behind #04 is `backdrop_drawer.py --guards`: amiga CAPSULE
compares `[SCREEN_NUM]` to 0x4C four times and to 0x6C **not once**, while
msdos and cartridge compare it to both. 42 values across the three big stages
are guarded by one branch and not another, so this is a class of name, not one
accident.
