#!/usr/bin/env python3
"""Scope a newly applied EQU to the branch that got it, so the other still builds.

Question answered
-----------------
A per-port naming pass renames `CINEMATIC_NNN` in one branch's canonical
`.asm`. The unified tree shares chunks between branches, and a definition sits
there unconditionally, so after the rename the *other* branch reads a chunk
that defines a name it never references -- or, worse, stops finding the name
it does. This wraps the affected definitions in a `.if BRANCH` guard naming
the branches that still use the old spelling.

It is the step between `apply_branch_scoped_names.py` and `make test`. Without
it, verify-unified drops while verify-stages stays at 29/29, because the
canonical files are fine and only the shared tree is inconsistent.

The bug it had, which is the reason it is committed
---------------------------------------------------
The first version scoped every row in the proposal table. The validator does
not apply every row -- it rejects some -- so in CAPSULE it scoped all 14 when
only 8 had landed, and the other branch, which still legitimately used the
remaining 6 under their old names, lost them. **A proposal is not an
application.** It now re-reads the target `.asm` and scopes only names it can
actually find defined there, and prints both counts so a mismatch is visible:

    8 of 14 name(s) actually applied

Signals read
------------
The proposal table's second column (the proposed name), the target branch's
`src/levels/<branch>/<STAGE>.asm` to see which of those landed, and every
`src/levels/_unified/<stage>/**/*.inc`. A definition is rewritten only when it
is currently **unconditional** -- `cond is None` -- so a definition already
inside an `.if` is left alone rather than nested.

Usage
-----
    python3 notes/unified-scoping/scope_fix.py <table.md> <STAGE> <port> <branch>

`<port>` is the branch that received the new names; the guard emitted is the
complement, so the definition survives for everyone else. Afterwards, always:

    python3 notes/unified-symbol-check/undefined_symbols.py
    make test

Exit status
-----------
0 always; the counts it prints are the result. It is a mutation tool, so read
them.
"""
import re, glob, sys
from pathlib import Path
tbl, stage, port, branch = sys.argv[1:5]
BR={"amiga":"chahi_amiga_1991","msdos":"dos_1992"}
proposed={l.split("|")[2].strip() for l in Path(tbl).read_text().splitlines()[2:] if l.startswith("|")}
asm=Path(f"src/levels/{BR[port]}/{stage}.asm").read_text(errors="replace")
applied={n for n in proposed if re.search(rf"^{re.escape(n)}\s+EQU", asm, re.M)}
print(f"  {len(applied)} of {len(proposed)} name(s) actually applied")
guard = ('.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")'
         if port=="amiga" else '.if BRANCH == "chahi_amiga_1991"')
n=0
for f in glob.glob(f"src/levels/_unified/{stage.lower()}/**/*.inc", recursive=True):
    p=Path(f); lines=p.read_text().splitlines(); cond=None; out=[]; ch=False
    for l in lines:
        s=l.strip()
        if s.startswith(".if ") or s.startswith(".elif "): cond=s
        elif s.startswith(".endif"): cond=None
        m=re.match(r"^(CINEMATIC_\w+)\s+EQU",s)
        if m and m.group(1) in applied and cond is None:
            out += [guard, l, ".endif"]; ch=True; n+=1; continue
        out.append(l)
    if ch: p.write_text("\n".join(out)+"\n")
print(f"  scoped {n} unconditional definition(s) to the other port")
