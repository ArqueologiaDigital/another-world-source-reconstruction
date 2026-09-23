# Turning a probe's proposals into the tables the appliers take

| file | question it answers | command |
| --- | --- | --- |
| `split_by_branch_stage.py` | How were the committed `proposals_<branch>__<STAGE>.md` tables produced from a probe that scans the whole tree at once? | see below |
| `tests/run.sh` | Does the splitter cut on the separator, drop the repeated header, and keep every row? | `sh notes/proposal-tables/tests/run.sh` |

Every applier in `tools/` takes one `--branch`, one `--stage` and one
proposal file. Every probe that *derives* proposals scans the whole tree and
emits one stream, sectioned by

```
----- <branch> / <STAGE> -----
```

The split between the two was being done by hand, which left the committed
proposal tables readable but not regenerable. This closes that.

```
python3 notes/laser-impact-anim/impact_ladder.py --proposals \
  | python3 notes/proposal-tables/split_by_branch_stage.py \
      --out notes/laser-impact-anim \
      --title 'The shot-impact burst in {stage} -- {branch}' \
      --note 'Derived by notes/laser-impact-anim/impact_ladder.py.'

python3 notes/draw-label-follows-constant/label_vs_constant.py --proposals \
  | python3 notes/proposal-tables/split_by_branch_stage.py \
      --out notes/draw-label-follows-constant --header routine \
      --title 'Draw-only labels in {stage} -- {branch}'

python3 notes/motion-word-audit/piece_family_vs_label.py --proposals \
  | python3 notes/proposal-tables/split_by_branch_stage.py \
      --out notes/motion-word-audit --header routine \
      --title 'Actor gait labels in {stage} -- {branch}'
```

`--header routine` writes the column `apply_routine_renames.py` expects;
the default `constant` is for `apply_cinematic_renames.py` and
`apply_branch_scoped_names.py`. `--dry` prints what it would write.

**Re-running these three today writes nothing**, because all of their
proposals were applied on 2026-09-23 and each probe now reports zero. That is
the read-back working, not the splitter failing — `tests/run.sh` exercises it
on a fixed input that does not depend on the tree's state.

## Note on the cartridge branch

`cartridge_1992` reaches its byte baseline through a **relative** root, so its
appliers must be run from the `another-world-archaeology` working directory or
they revert every rename. `../laser-impact-anim/README.md` has the measurement
and the corrected error message.
