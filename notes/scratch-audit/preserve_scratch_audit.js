export const meta = {
  name: 'preserve-scratch-audit',
  description: 'Audit 194 volatile scratch artefacts and decide which must be committed',
  phases: [
    { title: 'Audit', detail: 'read each scratch file, classify preserve vs disposable' },
    { title: 'Verify', detail: 'adversarially re-check each preserve call against the repo' },
  ],
}

const REPO = '/home/fsanches/compartilhado/another-world-source-reconstruction'
const ARCH = '/home/fsanches/compartilhado/another-world-archaeology'

const AUDIT_SCHEMA = {
  type: 'object',
  properties: {
    files: {
      type: 'array',
      items: {
        type: 'object',
        properties: {
          path: { type: 'string' },
          kind: { type: 'string', description: 'proposal-table | probe-output | grep-dump | script | binary | notes | unknown' },
          verdict: { type: 'string', enum: ['preserve', 'disposable'] },
          reason: { type: 'string', description: 'why, citing what you checked in the repo' },
          summary: { type: 'string', description: 'one line: what question this file answers' },
          suggested_dest: { type: 'string', description: 'repo-relative dir if preserve, else empty' },
        },
        required: ['path', 'kind', 'verdict', 'reason', 'summary', 'suggested_dest'],
      },
    },
  },
  required: ['files'],
}

const VERIFY_SCHEMA = {
  type: 'object',
  properties: {
    confirmed: {
      type: 'array',
      items: {
        type: 'object',
        properties: {
          path: { type: 'string' },
          summary: { type: 'string' },
          suggested_dest: { type: 'string' },
          reason: { type: 'string' },
        },
        required: ['path', 'summary', 'suggested_dest', 'reason'],
      },
    },
    rejected: {
      type: 'array',
      items: {
        type: 'object',
        properties: {
          path: { type: 'string' },
          why: { type: 'string' },
        },
        required: ['path', 'why'],
      },
    },
  },
  required: ['confirmed', 'rejected'],
}

const CONTEXT = `
You are auditing a volatile scratch directory for a reverse-engineering project.

Two sibling git repos hold the permanent record:
  ${REPO}           (source tree + notes/ + docs/)
  ${ARCH}           (tools/)

The governing rule: "If a number is worth writing down, the thing that produced
it is worth committing." Anything in scratch that is EVIDENCE for a claim already
made in the repo, or a PROBE/SCRIPT that produces such a number, must be
preserved. Anything regenerable by a recorded command, or whose conclusions are
already fully written into a committed note, is disposable.

Already preserved this session (do NOT re-preserve; check before claiming):
  ${REPO}/notes/naming-proposals/tables/   -- 69 markdown proposal tables
  ${REPO}/notes/lake-shooting/             -- probes + README for the LAKE scene
  ${REPO}/notes/HANDOFF.md

Known-disposable classes, already documented as such in notes/HANDOFF.md:
  *.svg *.png *.ppm   -- renders, regenerable by:
       awvm-render-polygons --port P --stage N --romset DIR --bank cinematic --out DIR
  res/resources/*.bin -- unpacked game resources, regenerable by tools/aw_unpacker.py
  romset/*.rom        -- built by tools/build_romset.py
`

const auditPrompt = (i) => `${CONTEXT}

Get your file list with:
  python3 -c "import json;print(chr(10).join(json.load(open('/tmp/slices.json'))[${i}]))"

For EVERY file in that list:
1. Read it (head -50 is fine for big ones; note the size).
2. Work out what question it answers.
3. Check whether its content is ALREADY in the repo. Actually run the checks --
   grep distinctive strings from the file against ${REPO}/notes ${REPO}/docs
   ${ARCH}/tools. Do not guess.
4. Decide preserve or disposable.

Mark "preserve" only when ALL hold:
  - it carries evidence, a measurement, a probe, or a script
  - that content is NOT already committed (you grepped and it is absent)
  - it is not trivially regenerable by a command recorded in the repo

Mark "disposable" for: grep dumps whose conclusion is already in a note,
intermediate one-liners, duplicates of committed files, .bak copies of committed
scripts, binaries covered by the regeneration recipes above, and empty files.

Be strict. A false "preserve" costs repo clutter; a false "disposable" loses
evidence permanently. When genuinely torn, choose preserve and say why you were
torn. Return one entry per file in your list -- do not skip any.`

const verifyPrompt = (audit, i) => {
  const keep = (audit && audit.files ? audit.files : []).filter(f => f.verdict === 'preserve')
  if (!keep.length) return null
  return `${CONTEXT}

Another agent audited scratch slice ${i} and wants to COMMIT these files to the
repo. Your job is to REFUTE each one. Default to rejecting.

${keep.map(f => `- ${f.path}
    claim: ${f.summary}
    reason given: ${f.reason}
    proposed destination: ${f.suggested_dest}`).join('\n')}

For each, actually check:
  * Is this content already in the repo? grep distinctive strings from the file
    against ${REPO}/notes ${REPO}/docs ${REPO}/notas ${ARCH}/tools. Include
    ${REPO}/notes/naming-proposals/tables/ -- 69 tables already landed there and
    a near-duplicate must be rejected.
  * Is it regenerable by a command already recorded in the repo?
  * Is it actually evidence, or just intermediate grep output someone kept?
  * Is the proposed destination sensible, i.e. beside the thing it measures?

Reject anything already covered, regenerable, or merely intermediate. Confirm
only what would genuinely be LOST and MISSED if the /tmp directory vanished.
For confirmed ones, give a clean one-line summary and a sensible repo-relative
destination directory.`
}

phase('Audit')
const slices = Array.from({ length: 10 }, (_, i) => i)

const results = await pipeline(
  slices,
  (i) => agent(auditPrompt(i), { label: `audit:slice-${i}`, phase: 'Audit', schema: AUDIT_SCHEMA }),
  (audit, i) => {
    const p = verifyPrompt(audit, i)
    if (!p) return { confirmed: [], rejected: [] }
    return agent(p, { label: `verify:slice-${i}`, phase: 'Verify', schema: VERIFY_SCHEMA })
  }
)

const confirmed = []
const rejected = []
for (const r of results) {
  if (!r) continue
  for (const c of (r.confirmed || [])) confirmed.push(c)
  for (const x of (r.rejected || [])) rejected.push(x)
}

log(`confirmed for preservation: ${confirmed.length}; rejected: ${rejected.length}`)
return { confirmed, rejected }
