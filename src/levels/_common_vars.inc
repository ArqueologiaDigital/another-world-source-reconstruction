; Shared VM variable aliases — common to all branches and stages.
; The Another World VM has 256 16-bit variables; these names alias
; the well-known engine slots that every level/branch uses identically.
; Per-stage CINEMATIC_NNN / COMMON_VIDEO_NNN EQUs remain in each
; stage's own file because their values are stage-and-branch specific.

RANDOM_SEED		EQU 0x3C
HACK_VAR_54		EQU 0x54
HACK_VAR_67		EQU 0x67
LAST_KEYCHAR		EQU 0xDA
HACK_VAR_DC		EQU 0xDC
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
