# How much of what is left can be named at all?

`shared-bank-naming/asset_naming_share.py` counts every unnamed
`CINEMATIC_*` / `CV_*` as work remaining. Some of it is not work, and it is
worth knowing which before anyone plans around the number.

```
$ python3 notes/unnamed-reachability/nameable_remaining.py
  port/stage                    unnamed   DRAWN  UNREACH   NEVER
  chahi/CODE_WHEEL                    1       0        1       0
  chahi/PRISON                      290     290        0       0
  chahi/CAVES                       443     442        1       0
  chahi/TANK                          3       3        0       0
  chahi/CAPSULE                     302     293        9       0
  chahi/PASSCODE                      2       0        0       2
  dos/CODE_WHEEL                      1       0        1       0
  dos/PRISON                        310     307        3       0
  dos/CAVES                         487     480        7       0
  dos/TANK                           13      13        0       0
  dos/CAPSULE                       460     447       13       0
  dos/ENDING                          3       0        3       0
  dos/PASSCODE                        4       1        1       2

  TOTAL                            2319    2276       39       4
```

**2,276 of 2,319 are real work.** The method does not get to shrink its own
denominator much, which is the honest answer.

What the other 43 are:

- **UNREACHABLE (39)** -- every draw of the constant is in bytes control cannot
  reach. dos/CODE_WHEEL's single one is inside a guard the disassembler itself
  annotated *"Nothing references this address."*; msdos/ENDING's last three sit
  on the three lines after a `killChannel` that follows a `jmp`. #0126 is
  explicit that a role name does not go on unreachable bytes, so these stay as
  they are and those stages cannot reach 100% by naming.
- **NEVER_DRAWN (4)** -- `CINEMATIC_055` and `056` in both ports' PASSCODE.
  The EQUs exist and nothing references them. There is art to render, but no
  draw site, no palette and no neighbours to read it against, and nothing to
  check a reading with.

## How reachability is decided

Conservatively, so the count never overstates how much is dead:

* a draw inside `.if INCLUDE_UNREACHABLE_CODE` is unreachable -- the tree says so;
* otherwise, walk back to the nearest label; a `ret`, `killChannel` or
  unconditional `jmp` between that label and the draw, with no label in
  between, makes it unreachable;
* everything else counts as reachable, including draws behind conditionals;
* one reachable draw makes the constant `DRAWN`, however many dead ones it
  also has.

## Where the work actually is

CAVES and CAPSULE hold **1,662 of the 2,276**, and PRISON another 597. The
three of them are 99% of what is left in the priority ports.

```
python3 notes/unnamed-reachability/nameable_remaining.py --stage PASSCODE --list
```
