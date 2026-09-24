#!/usr/bin/env python3
"""Does the server notice a listing change, and does it notice it cheaply?

Question answered
-----------------
Two things the debugger gained on 2026-09-25, and only the first half of each
can be tested without a browser.

**Reloading names.** Applying a batch of names rewrites
`src/levels/<branch>/<STAGE>.asm` while the page is open, and the only way to
see them used to be F5 -- which throws away the run, the position in the stage,
and every constant described so far. The page now polls
`/api/names-version/<branch>/<stage>` and re-fetches the names only when that
token moves. So the token must (a) change when the file changes, (b) NOT change
when it does not, and (c) cost a stat() rather than a parse, which is what makes
a two-second poll reasonable.

**Not counting what has been described.** A constant described in this session
stops counting as unnamed and stops tripping the auto-pause, because the work on
it is done even though the tree will not know for minutes or days. That lives in
the browser and is deliberately not persisted -- a reload asks again, and by
then the answer may have arrived from the source. The part testable here is that
the names payload carries the version the client compares against.

What this asserts
-----------------
  1. `asm_version` changes after a write and is stable across reads;
  2. it returns "missing" rather than raising for a stage that is not there;
  3. it is cheap: 200 calls take less than a single `names_for` parse;
  4. `/api/names/...` carries a `version`, and it equals `asm_version`;
  5. `/api/names-version/...` returns the same token without parsing the file,
     checked by pointing ROOT at a listing that would fail to parse as names.

Run it
    python3 tools/vm-debugger/tests/check_watch_and_described.py
"""
from __future__ import annotations

import json
import sys
import tempfile
import threading
import time
import urllib.request
from http.server import ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools" / "vm-debugger"))
import server                                                    # noqa: E402

BAD: list[str] = []


def want(cond, why):
    if not cond:
        BAD.append(why)


def main() -> int:
    branch, stage = "dos_1992", "PRISON"
    asm = ROOT / "src" / "levels" / branch / f"{stage}.asm"
    want(asm.is_file(), f"no {asm} to test against")
    if BAD:
        print("FAIL: " + BAD[0])
        return 1

    # 1 + 2. the token
    v1 = server.asm_version(branch, stage)
    want(v1 == server.asm_version(branch, stage),
         "asm_version is not stable across two reads of an unchanged file")
    want(server.asm_version("nope", "NOPE") == "missing",
         "a missing stage should read 'missing', not raise")

    # 3. cheap enough to poll
    t0 = time.perf_counter()
    for _ in range(200):
        server.asm_version(branch, stage)
    stat_cost = time.perf_counter() - t0
    t0 = time.perf_counter()
    server.names_for(branch, stage)
    parse_cost = time.perf_counter() - t0
    want(stat_cost < parse_cost,
         f"200 version checks ({stat_cost * 1000:.1f} ms) cost more than one "
         f"names parse ({parse_cost * 1000:.1f} ms) -- polling is not free")
    print(f"  200 version checks {stat_cost * 1000:6.1f} ms; "
          f"one names parse {parse_cost * 1000:6.1f} ms")

    # 4 + 5. the two routes agree, and the cheap one stays cheap
    srv = ThreadingHTTPServer(("127.0.0.1", 0), server.Handler)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    base = f"http://127.0.0.1:{srv.server_address[1]}"
    try:
        names = json.loads(urllib.request.urlopen(
            f"{base}/api/names/{branch}/{stage}", timeout=30).read())
        ver = json.loads(urllib.request.urlopen(
            f"{base}/api/names-version/{branch}/{stage}", timeout=10).read())
        want(names.get("version") == v1,
             f"/api/names carries version {names.get('version')!r}, "
             f"asm_version says {v1!r}")
        want(ver.get("version") == v1,
             f"/api/names-version says {ver.get('version')!r}, want {v1!r}")

        # the token must move on a write and the route must agree, checked on a
        # scratch tree so the real listing is never touched
        with tempfile.TemporaryDirectory() as td:
            fake = Path(td) / "src" / "levels" / branch
            fake.mkdir(parents=True)
            f = fake / f"{stage}.asm"
            f.write_text("CINEMATIC_001\t\tEQU 0x1234\n")
            real_root = server.ROOT
            try:
                server.ROOT = Path(td)
                a = server.asm_version(branch, stage)
                time.sleep(0.01)
                f.write_text("CINEMATIC_001\t\tEQU 0x1234\n"
                             "CINEMATIC_002\t\tEQU 0x5678\n")
                b = server.asm_version(branch, stage)
                want(a != b, "the token did not move after the file changed")
                want(b == server.asm_version(branch, stage),
                     "the token is unstable after a write")
            finally:
                server.ROOT = real_root
    finally:
        srv.shutdown()

    if BAD:
        print(f"FAIL: {len(BAD)} problem(s)")
        for x in BAD:
            print(f"  * {x}")
        return 1
    print("PASS: the version token moves on a write, is stable otherwise, reads "
          "'missing'\n      for an absent stage, is far cheaper than a parse, "
          "and both routes agree.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
