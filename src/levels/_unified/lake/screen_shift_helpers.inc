; Generic per-screen X-shift helpers — used by hero (Lester drift,
; lake-edge handling), screen-edge transitions, and beast drift.
; ADVANCE_X_FORWARD/BACKWARD shift the on-screen X by 0x172 (the
; LAKE between-screen step) when var [0x2A] < 4 (a scene-state
; gate); SHIFT_X_RIGHT/LEFT_320 always shift var [0x0A] by exactly
; 0x140 (one full 320-px screen).

ADVANCE_X_FORWARD_ONE_SCREEN:
	jl [0x2A], 0x04, SHIFT_X_RIGHT_320
	add [0x0E], 0x0172

SHIFT_X_RIGHT_320:
	add [0x0A], 0x0140
	ret

ADVANCE_X_BACKWARD_ONE_SCREEN:
	jl [0x2A], 0x04, SHIFT_X_LEFT_320
	sub [0x0E], 0x0172

SHIFT_X_LEFT_320:
	sub [0x0A], 0x0140
	ret

