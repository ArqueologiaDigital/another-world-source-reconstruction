# One picture, several names — across stages

`../crossport-transfer/ --duplicates` enforces one name per picture **between
ports** and has caught real errors. Nothing enforced anything **between
stages of one port**, and the cinematic banks share a lot of art.

    $ python3 notes/crossstage-duplicates/one_picture_many_names.py
    amiga: 2044 named pictures, 60 carry two or more different names
          49  family      9  same-stage      2  singleton
    msdos: 2013 named pictures, 59 carry two or more different names
          48  family      9  same-stage      2  singleton

## The dominant case: one animation named three times

    CAPSULE/CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_5
    CAVES/CINEMATIC_CAVES_LASER_BLAST_8
    PRISON/CINEMATIC_PRISON_SHOT_IMPACT_8

Byte-identical, three stages, three names — and three index bases, CAPSULE
running three behind the other two, frame for frame down the whole fade.
This is the `../crossstage-transfer/` de-prefix situation with **no unnamed
member** to give it away, which is why that pass could not see it.

**Reported, not rewritten.** Reconciling three earned names means choosing
among them, and #0120 says a tool must not. A person has to decide whether
CAPSULE's fade, CAVES' blast and PRISON's impact are one name.

## Not every group is an error

Identical art at two *different offsets* can legitimately carry two names.
`CINEMATIC_ENDING_CLOUD_SKY_F0` and `..._CLOUD_SKY_PAGE3_F0` are the same
picture blitted to two pages, and the second name says which. That is why the
probe reports a **shape** per group rather than a verdict: `family` is one
animation named twice, `same-stage` is two names inside one stage, and
`singleton` is a one-off.

## A forbidden name that is not a rename away from fixed

The `same-stage` list turned up `CINEMATIC_DECOR_AT_305_155_F7`, and
NAMING.md §1 uses **that exact name** as its example of what not to write:
"Never embed screen coordinates … both leaks a magic number and breaks
frame-index parsing". 22 such names survive, in two LAKE families.

They survive because the coordinate is the only thing distinguishing them,
and removing it needs a subject. So the obvious fix — drop `_AT_305_155_`,
keep `CINEMATIC_LAKE_DECOR_F<n>`, which is free — is wrong, because there is
a second family at `327_164` that would collide, and because **the first
family is not one subject at all**:

    F00        47x3/1          F07,F08    0x1/1  (specks)
    F01..F04   ~40x16/12       F09..F13   22x48/5
    F05,F06    33x34/12        F14        20x69/1
                               F15..F18   39x24 -> 17x32/12

Five or more distinct things, at scattered offsets (0xEAF4, 0xE82A, 0xDA0A,
0xD876 …) rather than a run. The group was formed by **where it is drawn**,
not by what it is — which is precisely why the coordinate ended up in the
name, and why fixing it means splitting the group by subject from renders,
not renaming it.

Recorded here so the next attempt starts from that, rather than from the
appealing and wrong one-line rename.
