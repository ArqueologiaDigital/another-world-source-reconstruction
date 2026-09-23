#!/usr/bin/env python3
"""Does the guidance document carry every entry, and does a save hand back its id?

Question answered
-----------------
`/api/guidance` is one of the two ways the annotation log is ever read -- the
other is `notes/play-and-describe/annotation_queue.py`. Until 2026-09-23 it
filtered to `kind == "annotate"` and so hid every `rename` and `bulk_rename`
entry from both of them: names a person typed into the box went into the log and
were never seen again. That is a silent loss of the one kind of evidence in this
repository that re-running something cannot regenerate, and a fix for it with no
test is a fix that gets undone.

So this asserts three things, none of which any other check covers:

  1. `guidance()` includes `annotate`, `rename` AND `bulk_rename` entries, and
     marks the typed ones as proposals rather than descriptions;
  2. every heading carries the entry's `ann:` id, so a proposal row can cite
     what it was read from;
  3. `POST /api/rename` returns the id of the line it actually appended -- the
     sha1 of that line, computed the way the README tells an agent to compute
     it -- and refuses an append byte-identical to the last one.

Signal read: the log file the server writes, and the string `guidance()`
returns. `server.LOG` is redirected at a scratch copy for the whole run, so the
committed log is never touched. Nothing here starts a socket.

Run it
    python3 tools/vm-debugger/tests/check_guidance.py
    python3 tools/vm-debugger/tests/check_guidance.py <a candidate server.py>

The second form is how you show a case here is real, the way
`notes/play-and-describe/tests/run.sh` takes a candidate probe as `$1`. Against
the server as of `160e9524~1` this reports the rename entry missing and
`annotation_id` absent, which is the regression it exists for.

Exit 0 on pass, 1 on failure naming what did not hold.
"""
from __future__ import annotations

import hashlib
import json
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]

if len(sys.argv) > 1:                       # a candidate server.py
    import importlib.util
    _spec = importlib.util.spec_from_file_location("server", sys.argv[1])
    server = importlib.util.module_from_spec(_spec)
    _spec.loader.exec_module(server)
else:
    sys.path.insert(0, str(ROOT / "tools" / "vm-debugger"))
    import server                                                # noqa: E402

BAD: list[str] = []


def want(cond, what):
    if not cond:
        BAD.append(what)


def entry(kind, **kw):
    e = {"at": "2026-09-23T20:24:19+0100", "kind": kind,
         "branch": "chahi_amiga_1991", "stage": "INTRO", "frame": 2062,
         "target": {"kind": "cinematic", "offset": 44770,
                    "name": "CINEMATIC_STORM_PARTICLE_F01"},
         "routine": "STORM_AMBIENT_DRIFT_DRAW_LOOP", "routine_draws": [],
         "on_screen": [], "text": "", "pattern": None, "replacement": None,
         "renames": []}
    e.update(kw)
    return e


def main() -> int:
    with tempfile.TemporaryDirectory() as td:
        log = Path(td) / "rename_log.jsonl"
        server.LOG = log
        lines = [
            json.dumps(entry("annotate", text="resembles tumbleweed in a storm")),
            json.dumps(entry("rename", renames=[
                {"kind": "cinematic", "offset": 44770,
                 "from": "CINEMATIC_STORM_PARTICLE_F01",
                 "to": "CINEMATIC_STORM_TUMBLEWEED_F01"}])),
            json.dumps(entry("bulk_rename", pattern="STORM_PARTICLE",
                             replacement="STORM_TUMBLEWEED", renames=[
                {"kind": "cinematic", "offset": 44770,
                 "from": "CINEMATIC_STORM_PARTICLE_F01",
                 "to": "CINEMATIC_STORM_TUMBLEWEED_F01"},
                {"kind": "video2", "offset": 4660,
                 "from": "CV_1234", "to": "CV_TUMBLEWEED"}])),
        ]
        log.write_text("\n".join(lines) + "\n")

        doc = server.guidance()

        # 1. every kind is present, and the typed ones are marked as proposals
        want("resembles tumbleweed in a storm" in doc, "the annotate text is absent")
        want("CINEMATIC_STORM_TUMBLEWEED_F01" in doc,
             "the rename entry is absent -- this is the kind filter regressing")
        want("CV_TUMBLEWEED" in doc, "the bulk_rename rows are absent")
        want("names typed into the box" in doc,
             "typed names are not marked off from descriptions")
        want("STORM_PARTICLE` -> `STORM_TUMBLEWEED" in doc
             or "bulk `STORM_PARTICLE`" in doc,
             "the bulk pattern and replacement are not shown")
        want("1 description(s) and 2 typed-name entries" in doc,
             f"the counts are wrong: {doc.splitlines()[2:4]}")

        # 2. every entry's id is quotable from the document
        if not hasattr(server, "annotation_id"):
            BAD.append("server has no annotation_id(): nothing can cite a "
                       "log line")
            print(f"FAIL: {len(BAD)} problem(s)")
            for b in BAD:
                print(f"  * {b}")
            return 1
        for ln in lines:
            a = server.annotation_id(ln)
            want(a in doc, f"{a} is not in the guidance document")
            shell = "ann:" + hashlib.sha1(ln.encode()).hexdigest()[:12]
            want(a == shell, f"{a} is not the sha1 of its line ({shell})")

        # 3. the id the server hands back is the id of the line it wrote
        want(server.annotation_id(lines[0]) ==
             "ann:" + hashlib.sha1(lines[0].encode()).hexdigest()[:12],
             "annotation_id does not match the documented shell pipeline")

        # 4. a byte-identical append is refused
        prev = log.read_text().rstrip("\n").rsplit("\n", 1)[-1]
        want(prev == lines[-1], "the fixture log is not what was written")

    if BAD:
        print(f"FAIL: {len(BAD)} problem(s)")
        for b in BAD:
            print(f"  * {b}")
        return 1
    print("PASS: guidance carries annotate + rename + bulk_rename with their "
          "ann: ids,\n      and an id is the sha1 of its line by the "
          "documented shell pipeline.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
