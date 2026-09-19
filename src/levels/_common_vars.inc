; Shared VM variable aliases — common to all branches and stages.
; The Another World VM has 256 16-bit variables; these names alias
; the well-known engine slots that every level/branch uses identically.
; Per-stage CINEMATIC_NNN / COMMON_VIDEO_NNN EQUs remain in each
; stage's own file because their values are stage-and-branch specific.

RANDOM_SEED		EQU 0x3C
HACK_VAR_54		EQU 0x54
; 0x67 is a screen index into a 32-column row-major grid, not an unknown slot.
; The only arithmetic ever applied to it is +/-1 and +/-0x20 (29 sites, four
; ports), and those four steps are exactly the generic fall-through tails of the
; four *_SCREEN_EXIT_<DIR>_LINK_CASE_* chains: DOWN +0x20, UP -0x20, RIGHT +1,
; LEFT -1. The immediates it is assigned cluster into bands whose starts are a
; multiple of 0x20 apart, and CAPSULE and PRISON extract the column outright with
; `and [0xF8], 0x001F` after copying it. Renamed from HACK_VAR_67 2026-09-19;
; 6,242 references, the largest placeholder in the tree. The evidence is a
; committed probe: notes/screen-index-probes/var67_screen_grid.py.
; 0x66 caches it per stage -- see CACHED_SCREEN_NUM, which is NOT declared here
; because TANK reuses 0x66 as a plain djnz counter.
SCREEN_NUM		EQU 0x67
LAST_KEYCHAR		EQU 0xDA
; 0xDC is a tamper token, not an unknown slot. Every one of its 32 references is
; either `mov [0xDC], 0x0021` or `jne [0xDC], 0x21, <halt>` — SHUTDOWN_VM,
; KILL_ALL_CHANNELS_AND_KILL or a restart. It is one of five constants checked by
; LIKELY_A_COPY_PROTECTION_MECHANISM, and one label already spelled it out:
; PASSCODE_DRAW_COPY_PROTECT_TOKEN_MARKER. Renamed from HACK_VAR_DC 2026-09-12.
COPY_PROTECT_TOKEN		EQU 0xDC
HERO_POS_UP_DOWN	EQU 0xE5
MUS_MARK		EQU 0xF4
HACK_VAR_F7		EQU 0xF7
SCROLL_Y		EQU 0xF9
HERO_ACTION		EQU 0xFA
HERO_POS_JUMP_DOWN	EQU 0xFB
HERO_POS_LEFT_RIGHT	EQU 0xFC
HERO_POS_MASK		EQU 0xFD
HERO_ACTION_POS_MASK	EQU 0xFE
PAUSE_SLICES		EQU 0xFF
