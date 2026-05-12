; 3-digit codewheel check chain.
;
; Reads the entered code digits (var 0x2A, 0x2B, 0x2C) and compares
; each against the per-puzzle expected values (var 0x1E, 0x1F, 0x20,
; 0x21). Any digit that matches any expected slot chains to the next
; digit's check; the final var 0x2C check that matches lands on
; SETUP_CODEWHEEL_CHANNELS (success). Any digit that fails to match
; any slot jumps to RESUME_GAME_INIT_CHANNELS (failure).
;
; Used live in dos (called from CODEWHEEL_CHECK_ENTERED_CODE after
; the var 0x29 prefix check). Also emitted dead at byte 0x0A17 in
; amiga — amiga's simpler CODEWHEEL_CHECK_ENTERED_CODE doesn't call
; into this chain, but the original compiler emitted it anyway, so
; the bytecode contains the same 81-byte chain twice across the two
; ports (live in dos, dead in amiga).

CHECK_VAR2A_OR_DISPATCH_RANGE:
	je [0x2A], [0x1E], CHECK_VAR2B_OR_DISPATCH_RANGE
	je [0x2A], [0x1F], CHECK_VAR2B_OR_DISPATCH_RANGE
	je [0x2A], [0x20], CHECK_VAR2B_OR_DISPATCH_RANGE
	je [0x2A], [0x21], CHECK_VAR2B_OR_DISPATCH_RANGE
	jmp RESUME_GAME_INIT_CHANNELS

CHECK_VAR2B_OR_DISPATCH_RANGE:
	je [0x2B], [0x1E], CHECK_VAR2C_RANGE_OR_RESUME
	je [0x2B], [0x1F], CHECK_VAR2C_RANGE_OR_RESUME
	je [0x2B], [0x20], CHECK_VAR2C_RANGE_OR_RESUME
	je [0x2B], [0x21], CHECK_VAR2C_RANGE_OR_RESUME
	jmp RESUME_GAME_INIT_CHANNELS

CHECK_VAR2C_RANGE_OR_RESUME:
	je [0x2C], [0x1E], SETUP_CODEWHEEL_CHANNELS
	je [0x2C], [0x1F], SETUP_CODEWHEEL_CHANNELS
	je [0x2C], [0x20], SETUP_CODEWHEEL_CHANNELS
	je [0x2C], [0x21], SETUP_CODEWHEEL_CHANNELS
	jmp RESUME_GAME_INIT_CHANNELS
