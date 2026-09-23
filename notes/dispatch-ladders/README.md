# Reading the dispatch ladders

A ladder is a run of routines named `<something>_CASE_<hex>`, each guarding one
value of one variable and drawing one picture. `../gun-arm-dispatch/` argues at
length why reading the case number is legitimate where reading the
disassembler's encounter order is not: the case is **the value the VM compares
against**, so it carries the machine's meaning, not the tool's.

`ladder_index_check.py` checks the ladders against the families they select,
and reports two things that no count of unnamed constants can show.

## 1. A family can start late

CAPSULE's charged-blast fade is a contiguous nine-case ladder, `0x81..0x89`,
and the committed family covers `0x84..0x89` as indices 0..5. So
`CHARGED_BLAST_FADE_0` is the **fourth** frame of the fade and the three
earliest frames are unnamed.

**One attempt to fix it failed and was reverted.** The three unnamed arms are
`CINEMATIC_480/479/478` in amiga and `CINEMATIC_627/626/625` in msdos —
different numbers for the same role, which is ordinary. A rename keyed on the
amiga numbers wrote the new names onto msdos's `CINEMATIC_480/479/478`, which
are unrelated art drawn from `LABEL_9DF3` and `JUNK__9DD7`. `make test` stayed
at 29/29 and `undefined_symbols` stayed clean throughout, because **a name
cannot move a byte**.

It needs `apply_branch_scoped_names.py`, or a per-port proposal pair, so each
port gets the right offset under one name. And whatever does it must **read
the ladder back afterwards**, which is the only check that catches this.

## 2. A family can be a permutation of its ladder

CODE_WHEEL's `CINEMATIC_ALPHANUM_CODE_nn` was 31 contiguous cases whose family
indices did not follow them — case `0x05` drew `CODE_08`, `0x06` drew `CODE_07`,
`0x09` drew `CODE_05` — and the permutation differed between ports, the
signature of an index assigned by a tool rather than read from the machine.

They are not single characters. Rendered, they are **code strings** — `N1`,
`O3`, `U10` — the same kind PASSCODE displays, and `../passcode-glyph-probes/`
had just established how to read those: each is a group of inlined 5x7
character sub-groups, and normalising each child's leaf set to its own bounding
box gives a signature that matches the named font.

**The two stages share the font.** 33 of the 36 glyph shapes match
`CINEMATIC_PASSCODE_FONT_*` exactly across stage banks. The three that do not
— H, J and L — have different art in CODE_WHEEL's bank and were read from
renders, the same way the one port-divergent glyph (T) was.

All 32 decoded, and all 32 are named `CINEMATIC_CODEWHEEL_CODE_<text>`:

    N1  N6  N5  N7  N10  G20  O7  O4  O3  U10  U11  I15
    U15 I16 I19 I11 K14  G1   G2  G3  J18 G18  K3   L10
    I20 H19 H2  J5  G12  H13  O5  L12

Checked before naming, after the blast-fade failure: the 17 constants that
exist in **both** priority ports decode to the same text in both. The other 15
are msdos-only. Checked after naming: every one of the 47 applied names agrees
with **its own port's** art.

Two of them carry a `_STRING` tail. `L10` and `L12` would end the name `_L10`
and `_L12`, and `_L<n>` is this project's generated line-number label form, so
`naming_census.classify` refuses them as "still a generated form". The guard is
right; the tail works with it.

## Running it

    python3 notes/dispatch-ladders/ladder_index_check.py
    python3 notes/dispatch-ladders/ladder_index_check.py --all

Two false-positive classes are worth knowing, because both were hit:

  * a `_CASE_<hex>` tail is the case number in hex, not a decimal index. The
    checker skips those now; before it did not, and reported PASSCODE's
    alphanum ladder as a mismatch purely because `_CASE_10` is case `0x10`.
  * a case can be a signed quantity rather than an ordinal.
    `PRISON_CAGE_WITH_HERO_TILT_CASE_*` reports offsets around -65530 because
    its cases are tilt amounts near `0xFFFF`. Still reported, not suppressed:
    the shape of the number is the clue.
