#!/usr/bin/env python3
"""Which screen does each block of the CAVES ground map belong to?

Question answered
-----------------
CAVES.asm contains one 1,700-line region of tiny arithmetic blocks that every
naming pass so far has transcribed as operands (CAVES_PROJ_VAR22_68_MINUS_
VAR21_MINUS_F2_SHR4_L3 and friends).  This probe shows what they are: the
stage's per-screen ground-height map.

The signal
----------
  * CAVES_GROUND_MAP_DISPATCH (CAVES_COPY_VAR40_TO_VAR22_L1 before the family
    pass named it) is a 33-arm `je [HACK_VAR_67], 0xHH, <head>`
    ladder.  HACK_VAR_67 is the screen number (docs/NAMING.md section 3).
  * Its caller CAVES_COPY_VAR40_TO_VAR22_L3 loads [0x21] <- HERO_X and
    [0x22] <- HERO_Y, calls the ladder, and CAVES_COPY_VAR40_TO_VAR22_L5
    writes the answer back with `mov [HERO_Y], [0x22]`.
    CAVES_COPY_VAR40_TO_VAR22_L4 starts a fall when [0x22] - HERO_Y >= 0x10.
    So the ladder answers "what is the surface Y under this X on this screen".
  * Each arm is a chain of x-range segments:
    `jg [0x21], <bound>, <next>` / optional `sub,shr` / `mov [0x22], <base>` /
    optional `add|sub [0x22], [0x21]` / `ret`  -- flat ledges and slopes.

What the probe prints, and what counts as pass
----------------------------------------------
  1. arms: 33
  2. reachable blocks 225, uniquely attributable to one screen 218,
     shared 7 (0xCB/0xCC/0xCE share one head, 0x4A/0x6A share one head,
     plus SHARED_RET).
  3. every uniquely-owned block lies in lines 18215-19956, and each screen's
     blocks form a CONTIGUOUS line run.
  4. "referenced from outside the ground region: 0" once the 33 dispatcher
     arm lines (12853-12885) are discounted -- i.e. nothing else in the stage
     jumps into this table, so the per-screen attribution is exclusive.

Any of those four changing means the region is not what this probe claims and
the CAVES_GROUND_MAP_SCREEN_<HH>_SEGMENT_<n> names must be re-derived.

Run
---
    python3 notes/caves-ground-map-probe/ground_map_attribution.py \
        src/levels/chahi_amiga_1991/CAVES.asm
"""
import re, sys, collections

DISPATCH = 'CAVES_GROUND_MAP_DISPATCH'
LO, HI = 18215, 19960          # the ground-map line region (informational)


def load(path):
    lines = open(path).read().split('\n')
    lab, order = {}, []
    for i, l in enumerate(lines):
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):\s*$', l)
        if m:
            lab[m.group(1)] = i
            order.append((i, m.group(1)))
    order.sort()
    return lines, lab, order


def arms(lines, lab):
    out, j = [], lab[DISPATCH] + 1
    while j < len(lines):
        s = lines[j].strip()
        m = re.match(r'je \[HACK_VAR_67\], (0x[0-9A-F]+), (\w+)$', s)
        if m:
            out.append((m.group(1), m.group(2)))
        elif s and not s.startswith('je '):
            break
        j += 1
    return out


def block(lines, lab, order, name):
    """Successors of one block: conditional targets, jmp target, fall-through."""
    j, tgts, term = lab[name] + 1, [], None
    while j < len(lines):
        s = lines[j].strip()
        if re.match(r'^[A-Za-z_][A-Za-z0-9_]*:$', s) or s.startswith('db '):
            break
        m = re.match(r'^j(ne|e|g|l|ge|le)\b.*,\s*(\w+)$', s)
        if m:
            tgts.append(m.group(2))
        m2 = re.match(r'^jmp (\w+)$', s)
        if m2:
            tgts.append(m2.group(1)); term = 'jmp'; break
        if s == 'ret':
            term = 'ret'; break
        if s == 'killChannel':
            term = 'kill'; break
        j += 1
    fall = None
    if term is None:
        for li, nm in order:
            if li >= j:
                fall = nm
                break
    return tgts, fall


def main(path):
    lines, lab, order = load(path)
    A = arms(lines, lab)
    print('arms: %d' % len(A))

    owner = collections.defaultdict(set)
    for scr, head in A:
        seen, stack = set(), [head]
        while stack:
            n = stack.pop()
            if n in seen or n not in lab:
                continue
            seen.add(n)
            t, f = block(lines, lab, order, n)
            stack += t + ([f] if f else [])
        for n in seen:
            owner[n].add(scr)

    uniq = {n: sorted(s)[0] for n, s in owner.items() if len(s) == 1}
    shared = {n: sorted(s) for n, s in owner.items() if len(s) > 1}
    print('reachable blocks: %d  unique: %d  shared: %d'
          % (len(owner), len(uniq), len(shared)))
    for n, s in sorted(shared.items(), key=lambda kv: lab[kv[0]]):
        print('  shared %-52s %s' % (n, ','.join(s)))

    ln = [lab[n] + 1 for n in uniq if n != 'SHARED_RET']
    print('unique blocks span lines %d-%d' % (min(ln), max(ln)))

    refs = collections.defaultdict(list)
    for i, l in enumerate(lines):
        s = l.strip()
        if s.endswith(':') or s.startswith('db '):
            continue
        for m in re.finditer(r'\b([A-Z][A-Z0-9_]{3,})\b', s):
            refs[m.group(1)].append(i + 1)
    dispatch_lines = set(range(lab[DISPATCH] + 1, lab[DISPATCH] + 2 + len(A)))
    outside = 0
    for n in list(uniq) + list(shared):
        if n == 'SHARED_RET':
            continue
        for r in refs.get(n, []):
            if not (LO <= r <= HI) and r not in dispatch_lines:
                print('  LEAK %s referenced at line %d' % (n, r))
                outside += 1
    print('referenced from outside the ground region: %d' % outside)

    byscr = collections.defaultdict(list)
    for n, s in uniq.items():
        if n != 'SHARED_RET':
            byscr[s].append((lab[n] + 1, n))
    for s in byscr:
        byscr[s].sort()
    print('\nscreen  segs  lines            head')
    for s in sorted(byscr, key=lambda x: byscr[x][0][0]):
        l = byscr[s]
        contiguous = all(b > a for (a, _), (b, _) in zip(l, l[1:]))
        print('%-6s  %-4d  %-15s  %s%s'
              % (s, len(l), '%d-%d' % (l[0][0], l[-1][0]), l[0][1],
                 '' if contiguous else '   *NOT ORDERED*'))


if __name__ == '__main__':
    main(sys.argv[1] if len(sys.argv) > 1
         else 'src/levels/chahi_amiga_1991/CAVES.asm')
