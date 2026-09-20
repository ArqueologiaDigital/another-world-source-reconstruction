# The `FROM_64` arm of the beam-span ladder, on both stages

msdos CAVES and CAPSULE each have one more arm above the `FROM_3E` one named
today, and it was still a placeholder. Both guard `jl [0x26], 0x64, <FROM_3E>`
— so the arm runs when `[0x26] >= 0x64`, which is `_FROM_64` by NAMING.md §1's
range-ladder table — and both draw the length-62 span pair that the `FROM_3E`
arm also draws.

| routine | new name | confidence |
|---|---|---|
| LABEL_64EC | CAVES_LASER_BOLT_SPAN_FROM_64 | high |
