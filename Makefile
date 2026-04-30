# Another World — source reconstruction
#
# Top-level orchestrator. Each rule consumes:
#   - src/ + include/ (the reconstruction)
#   - releases/$(TARGET).flags (the per-release flag values)
# and produces a byte-matching artifact under build/$(TARGET)/.
#
# Phase 0 (this state): scaffolding. No real rules implemented yet.
#
# Status: see PLAN.md.

TARGET ?= msdos

ARCHAEOLOGY := ../another-world-archaeology
ARCHIVE     := ../another-world-archive
AWVM_TOOLS  := ../AnotherWorld_VMTools

BUILD_DIR := build/$(TARGET)
FLAGS_FILE := releases/$(TARGET).flags

# -----------------------------------------------------------------------------
# Targets

.PHONY: help
help:
	@echo "Another World — source reconstruction (Phase 0 scaffolding)"
	@echo ""
	@echo "TARGET=$(TARGET)  (override with 'make TARGET=amiga' etc.)"
	@echo ""
	@echo "Targets:"
	@echo "  make help                  this message"
	@echo "  make plan                  open PLAN.md"
	@echo "  make $(BUILD_DIR)/level-0.bin  (Phase 1 — not yet implemented)"
	@echo ""
	@echo "Each TARGET corresponds to a releases/<target>.flags file."
	@echo "See README.md for the strategy + PLAN.md for the phased roadmap."

.PHONY: plan
plan:
	@cat PLAN.md

# -----------------------------------------------------------------------------
# Phase 1 (not yet implemented): byte-matching level-0 bytecode for MS-DOS.
#
# $(BUILD_DIR)/level-0.bin: src/levels/level-0.asm $(FLAGS_FILE)
# 	@echo "[Phase 1 — not yet implemented]"
# 	@false

.PHONY: clean
clean:
	rm -rf build/

# -----------------------------------------------------------------------------
# Sanity check: refuse to run with an unknown TARGET.
$(FLAGS_FILE):
	@echo "no flags file at $@; create one for TARGET=$(TARGET) (see releases/template.flags)" >&2
	@false
