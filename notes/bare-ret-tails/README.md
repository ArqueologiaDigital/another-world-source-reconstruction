# A bare-`ret` tail takes its one caller's name

| file | question it answers | command |
| --- | --- | --- |
| `owner_ret.py` | Which placeholder labels are a routine's return tail, and what is that routine called? | `python3 notes/bare-ret-tails/owner_ret.py` |
| | Does `<owner>_RET` reproduce the names already written in that position? | `... --control` |
| | | `... --proposals` |
| `proposals_<branch>__<STAGE>.md` | the tables `apply_routine_renames.py` consumes | `... --proposals \| python3 notes/proposal-tables/split_by_branch_stage.py --out notes/bare-ret-tails --header routine` |

`../placeholder-census/` counts 828 placeholders that are a *position* inside
an already-named routine, and declines to name them because the positional
vocabulary would have to be invented — of 3,384 named forward-conditional
targets only 67 end in `DONE` and 58 in `RET`.

That is true of the 828 as a whole and **false of one slice of it**. For a
label whose entire body is a bare `ret`, reached only from inside one named
routine, `<owner>_RET` is not invented:

| | |
| --- | --- |
| the stem is exactly the owner's name | **174** |
| the stem is the owner with a trailing qualifier dropped | 10 |
| the stem is something else | 14 |

The 10 are the same rule applied with more judgement —
`PRISON_HERO_FRONT_X_RET` off `PRISON_HERO_FRONT_X_BY_FACING`, dropping a
qualifier the return does not need — and #0120 leaves them alone. Of the 14,
`TRIVIAL_RET` and `SHARED_RET` are tails several routines fall into, which the
one-owner rule excludes before a name is ever derived.

**6 named.** `DRAW_HERO_WATER_DEPTH_{LEFT,RIGHT}_CASE_03_RET` in CAPSULE
across three branches — the "not this case" arm of a case test, which returns
without drawing.

## Why so few, and the filter that had to be borrowed

34 are held because the owning routine's *own* name is mechanical:
`FILL_PAGE_00_COLOR_08_RET` would propagate a placeholder rather than remove
one.

Two filters run. `../sole-named-drawer/`'s, and `naming_census.classify`,
which is what the applier itself uses. The second was added because the
applier rejected `CHECK_HERO_Y_LT_VAR41_RET` as `operand_mech` after the first
had passed it — a probe that proposes rows its applier throws away is
measuring the wrong thing, and the honest fix is to run the applier's own
test rather than approximate it.

That is the shape of the remainder generally: the 828 positional labels are
not blocked on the positional vocabulary so much as on their **owners** still
being unnamed or mechanically named. Each owner that gains a real name frees
its tails.
