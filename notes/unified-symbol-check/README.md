# The check that should have existed before today

`awvm-asm` accepts an undefined symbol and emits bytes for it. Issue #0073
records the specific case that was fixed — an identifier containing `EQU` —
but the general behaviour stands: **a reference with no definition does not
fail the assembler, it changes the output.**

Only `verify-unified` notices, and it says `26/29`. It does not say which
symbol, in which chunk, for which branch.

That cost **four backouts in one day** on a single attempted rename batch in
msdos/INTRO. Each round I formed a theory from the file list, acted on it, and
watched the gate drop again:

| theory | what was actually wrong |
|---|---|
| shared chunks reference the constants, so arming is needed | 192 of the 194 sites were already inside a `.if` |
| the other branches need renaming too | they did, and it still broke |
| renaming creates a duplicate EQU | no duplicate existed |
| the descriptive name is defined only in amiga's arm | **correct** — found by bisecting to ONE constant |

The fourth is right, and two minutes of bisection found it after three rounds
of guessing did not. `CINEMATIC_CARPARK_NEAR_PILLAR EQU 0x1742` lives inside
`.if BRANCH == "chahi_amiga_1991"`, so pointing dos, cartridge and gba's
references at that name leaves them undefined — and silently wrong.

## `undefined_symbols.py`

```bash
python3 notes/unified-symbol-check/undefined_symbols.py
python3 notes/unified-symbol-check/undefined_symbols.py --stage INTRO
```

Exit 1 if any branch references a symbol it cannot see. **Run it after any
rename touching the unified tree and before `make test`** — it localises in
seconds what the byte gate only reports in aggregate.

It walks `_unified/<STAGE>.asm.in` once per branch, following `.include` and
honouring `.if BRANCH`, so it sees exactly the text that branch assembles.
The per-branch walk is the whole point: a name defined only inside
`.if BRANCH == "chahi_amiga_1991"` is perfectly defined for amiga and missing
for everyone else, and no whole-file grep can see that.

On the broken tree it named the five dangling symbols instantly —
`CINEMATIC_182`, `_444`, `_446`, `_530`, `_535`, with file and line — where
the gate had said only "26/29" four times.

## What it does not catch

Resolution is not correctness. After fixing all five the tree resolved
cleanly and `verify-unified` went to **25/29**, worse than before: the
references now pointed at names that *are* defined for those branches but
carry a **different offset**. This tool answers "is it defined?", never "is it
the right one?". The byte gate remains the authority on that, and the whole
msdos/INTRO attempt was reverted.

See `notes/crossport-name-transfer/` for the 66 verified name matches and why
applying them needs `canonicalize_cinematic_refs.py` rather than a rename.
