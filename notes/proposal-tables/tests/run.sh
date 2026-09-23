#!/bin/sh
# Answers: does the splitter cut on the section separator, drop the repeated
# header and rule, and keep every row? Expected: two files, 2 rows and 1 row.
set -e
here=$(dirname "$0"); out=$(mktemp -d)
python3 "$here/../split_by_branch_stage.py" --out "$out" --header routine \
    --title 'Self test {stage} -- {branch}' --note synthetic < "$here/sections.txt"
a=$(grep -c '^| A_' "$out/proposals_chahi_amiga_1991__PRISON.md")
b=$(grep -c '^| B_' "$out/proposals_dos_1992__CAVES.md")
h=$(grep -c '^| routine |' "$out/proposals_chahi_amiga_1991__PRISON.md")
rm -rf "$out"
[ "$a" = 2 ] && [ "$b" = 1 ] && [ "$h" = 1 ] \
    && echo "PASS: 2 rows / 1 row / one header" \
    || { echo "FAIL: a=$a b=$b header=$h"; exit 1; }
