#!/usr/bin/env python3
"""Is every script in a scratchpad accounted for in verdicts.md?

Question answered
-----------------
The working rule is that a script which produced a number worth writing down
must be committed beside what it measures, and that anything left in scratch
must be *explicitly* called disposable with a reason. `verdicts.md` in this
directory is where those reasons live.

That leaves one thing unchecked, and it is the thing that actually goes wrong at
the end of a long session: a script nobody has ruled on either way. It is not
promoted, it is not called disposable -- it is simply unmentioned, and an
unmentioned script reads exactly like a settled one when the sweep is a prose
exercise. This makes the sweep mechanical: name a scratchpad, and it says which
scripts have no verdict.

Signal read
-----------
Every `*.py`, `*.mjs`, `*.js` and `*.sh` under the scratchpad, against the
basenames appearing anywhere in `notes/scratch-audit/verdicts.md`. A basename is
enough because the audit refers to scripts by name and the names are
distinctive; a bare `run.sh` would be a false pass, so those are reported
separately as too-generic to match on.

**A file whose content is already a blob in this repository is not a scratch
artefact and is skipped**, by asking git whether it has that object. That is
what catches the two things a naive sweep drowns in: whole working copies of the
repo left under the scratchpad, and `git show` output taken to diff a change
against its predecessor. Both are already stored -- that is the entire point of
them -- so demanding a verdict on each would be demanding a verdict on the
repository.

It deliberately does NOT try to judge whether a verdict is right. "Disposable
because it is one `git show`" is a claim a person makes and this cannot check.
What it checks is that the claim exists.

Run it
    python3 notes/scratch-audit/covered.py <scratchpad dir> [more dirs...]
    python3 notes/scratch-audit/covered.py --hook    # read the path from CLAUDE_SCRATCHPAD

Exit 0 when every script is named, 1 when any is not, 2 on usage.
"""
from __future__ import annotations

import hashlib
import os
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
VERDICTS = HERE / "verdicts.md"
SUFFIXES = (".py", ".mjs", ".js", ".sh")
# Names common enough that finding them in the prose proves nothing.
GENERIC = {"run.sh", "main.py", "test.py", "index.js", "setup.py", "build.sh"}


def in_repo(paths: list[Path], repo: Path) -> set[Path]:
    """The subset whose exact content git already has an object for."""
    want: dict[str, list[Path]] = {}
    for p in paths:
        try:
            data = p.read_bytes()
        except OSError:
            continue
        h = hashlib.sha1(b"blob %d\0" % len(data) + data).hexdigest()
        want.setdefault(h, []).append(p)
    if not want:
        return set()
    try:
        r = subprocess.run(["git", "-C", str(repo), "cat-file", "--batch-check"],
                           input="\n".join(want) + "\n",
                           capture_output=True, text=True, timeout=120)
    except (OSError, subprocess.SubprocessError):
        return set()
    out: set[Path] = set()
    for line in r.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 2 and parts[1] == "blob":
            out.update(want.get(parts[0], []))
    return out


def scripts(root: Path) -> list[Path]:
    out = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d != "__pycache__"]
        for f in filenames:
            if f.endswith(SUFFIXES):
                out.append(Path(dirpath) / f)
    return sorted(out)


def main(argv: list[str]) -> int:
    if "--hook" in argv:
        env = os.environ.get("CLAUDE_SCRATCHPAD", "")
        argv = [a for a in argv if a != "--hook"] + ([env] if env else [])
    roots = [Path(a) for a in argv if not a.startswith("-")]
    if not roots:
        print(__doc__.strip().splitlines()[0], file=sys.stderr)
        print("usage: covered.py <scratchpad dir> [...]", file=sys.stderr)
        return 2
    if not VERDICTS.is_file():
        print(f"no {VERDICTS}", file=sys.stderr)
        return 2
    text = VERDICTS.read_text()

    all_scripts: list[Path] = []
    for root in roots:
        if not root.is_dir():
            print(f"  skipped, not a directory: {root}")
            continue
        all_scripts += scripts(root)
    stored = in_repo(all_scripts, HERE.parents[1])

    found = unnamed = generic = 0
    missing: list[Path] = []
    for p in all_scripts:
        if p in stored:
            continue
        found += 1
        if p.name in GENERIC:
            generic += 1
            continue
        if p.name in text:
            continue
        unnamed += 1
        missing.append(p)

    if missing:
        print(f"FAIL: {unnamed} of {found} loose script(s) have no verdict in "
              f"{VERDICTS.relative_to(HERE.parents[1])}:")
        for p in missing:
            print(f"  * {p}")
        print("\n  Not a demand to keep them. A verdict is a sentence saying "
              "promoted-to-<path>\n  or disposable-because-<reason>; what this "
              "refuses is silence, because an\n  unmentioned script reads "
              "exactly like a settled one.")
        return 1
    extra = f", {generic} skipped as too generic to match on" if generic else ""
    print(f"PASS: all {found} script(s) under "
          f"{', '.join(str(r) for r in roots)} are named in verdicts.md{extra}"
          f"; {len(stored)} more are byte-identical to something git already "
          f"has and are not artefacts.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
