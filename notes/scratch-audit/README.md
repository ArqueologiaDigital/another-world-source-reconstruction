# Does anything in the scratch directory need rescuing?

Question answered
-----------------
At the end of a long session the scratchpad held 48,508 files. The working
rules say to sweep for anything that exists only in scratch and either commit
it or state explicitly that it is disposable. "I looked and it seemed fine" is
not a sweep, so this is the sweep, written down.

The answer was **no: 41 files were proposed for rescue and all 41 were
refuted.** `verdicts.md` has the grounds, one entry per file.

How it was run
--------------
`preserve_scratch_audit.js` is the workflow script, committed because it
produced that verdict. Ten agents each took a tenth of the 194 non-render
files, read them, and grepped both repos to decide preserve vs disposable.
Behind each, a second agent was told to **refute** the preserve calls and to
default to rejecting.

    Workflow({scriptPath: 'notes/scratch-audit/preserve_scratch_audit.js'})

It expects the slices in `/tmp/slices.json`; regenerate with

    find <scratchpad> -type f ! -name '*.svg' ! -name '*.png' \
        ! -name '*.ppm' ! -name '*.bin' | sort > /tmp/todo.txt
    python3 -c "import json;f=[l.strip() for l in open('/tmp/todo.txt') if l.strip()];\
json.dump([f[i::10] for i in range(10)], open('/tmp/slices.json','w'))"

18 agents, 837 tool calls, 2.27M subagent tokens, ~30 minutes.

What the refutations actually did
---------------------------------
This is the part worth keeping. The verifiers did not argue; they
reconstructed. The strongest ones checked out the pre-apply tree in a
throwaway worktree and re-ran the committed probe:

    git worktree add --detach WT 7703f365
    git -C WT checkout 7703f365^ -- src
    python3 notes/sole-named-drawer/nameable_from_drawer.py --proposals y.md

and showed the output was **byte-identical** to the scratch file. Sixteen
files were dismissed that way.

Recurring grounds, by count -- reproduce with `grounds.py`:

    27  conclusion already in a committed note or a commit diff
    18  regenerable byte-for-byte from a committed probe
    10  byte-identical to a sibling already in scratch
    10  the "evidence" column is a hardcoded literal
     3  the filename misattributes the port or the stage

A verdict may give several grounds, so these sum past 41. Six verdicts match
no keyword at all, so **the tally is a floor**, and `grounds.py` names those
six rather than hiding them.

An earlier version of this file printed `21 / 16 / 15 / 10 / 3`. That came
from a shell one-liner that was never committed and used looser substrings --
`"byte-identical"` where `grounds.py` requires `"byte-identical to"`, and so
on. Neither tally is more correct; the committed one is the one you can
check, which is the whole point. The shape of the finding is unchanged: most
proposals died because the content was already recorded or regenerable.

Three findings that outlived the audit
--------------------------------------
1. **A commit diff beats a proposal table.** Repeatedly the verifier pointed
   out that the rename's `-`/`+` lines carry the same pairs *plus* the EQU
   offsets the table lacks. Git history is the better record.

2. **The evidence column can be boilerplate.** For tables written by
   `sole-named-drawer/nameable_from_drawer.py`, "evidence" is one hardcoded
   string at lines 432-438, appended unchanged to every row it has ever
   written. `../naming-proposals/README.md` had claimed per-row evidence and
   now says which 14 of its 69 tables do not have it.

3. **A counted hold sent someone rummaging in /tmp.**
   `../crossstage-transfer/transfer_across_stages.py` computed
   `CINEMATIC_555 -> CINEMATIC_HERO_FALL_PRELUDE_FRAME` from HEAD and then
   printed only "1 held". An agent went looking for it in scratch. It now has
   `--held`, which names all 95 held candidates.

The audit's own limits
----------------------
It read the 194 non-render files. It did **not** examine the 46,991 SVGs,
1,089 PNGs, 19 PPMs or 146 unpacked `.bin` resources, which are covered by the
regeneration recipes in `../HANDOFF.md` rather than by inspection. A verdict of
"disposable" here means "recoverable or already recorded", never "worthless".
