# Another World — source reconstruction
#
# Top-level orchestrator. Each rule consumes:
#   - src/ + include/ (the reconstruction)
#   - releases/$(TARGET).flags (the per-release flag values)
# and produces a byte-matching artifact under build/$(TARGET)/.
#
# Status: see PLAN.md.
#
# Phase 1 (bytecode round-trip) is operational for 5 ports (2026-05-01):
#   amiga, msdos, genesis_europe, snes_eu, gba_usa.

TARGET ?= msdos

ARCHAEOLOGY := ../another-world-archaeology
ARCHIVE     := ../another-world-archive
AWVM_TOOLS  := ../AnotherWorld_VMTools
AWVM_ASM    := $(AWVM_TOOLS)/target/release/awvm-asm
AWVM_DISASM := $(AWVM_TOOLS)/target/release/awvm-disasm

BUILD_DIR := build/$(TARGET)
FLAGS_FILE := releases/$(TARGET).flags

# Per-target output-roots that hold disasm/ + resources/ (or romset/).
# These come from running awvm-disasm on user-supplied originals.
# Phase 1's verify rule treats these as "reference" outputs against which
# the build is checked. (User must populate them first.)
OUTPUT_ROOT_amiga          := /tmp/output/amiga
OUTPUT_ROOT_msdos          := /tmp/output/msdos
OUTPUT_ROOT_gba_usa        := /tmp/output/gba_usa
OUTPUT_ROOT_genesis_europe := $(ARCHAEOLOGY)/work/f15f23e1e0fa8d827c4b045d7ce3cf90
OUTPUT_ROOT_snes_eu        := $(ARCHAEOLOGY)/work/f65e3d6efe35900c0015bcb751ee567e
OUTPUT_ROOT                := $(OUTPUT_ROOT_$(TARGET))

# -----------------------------------------------------------------------------
# Targets

.PHONY: help
help:
	@echo "Another World — source reconstruction"
	@echo ""
	@echo "TARGET=$(TARGET)  (override with 'make TARGET=amiga' etc.)"
	@echo ""
	@echo "Targets:"
	@echo "  make help                this message"
	@echo "  make verify              round-trip BYTECODE for TARGET; report match"
	@echo "  make verify-all          round-trip BYTECODE for every supported port"
	@echo "  make plan                show PLAN.md"
	@echo "  make clean               wipe build/"
	@echo ""
	@echo "Supported TARGETs (Phase 1 bytecode round-trip):"
	@echo "  amiga, msdos, genesis_europe, snes_eu, gba_usa"
	@echo ""
	@echo "Each TARGET corresponds to a releases/<target>.flags file."
	@echo "See README.md for the strategy + PLAN.md for the phased roadmap."

.PHONY: plan
plan:
	@cat PLAN.md

# -----------------------------------------------------------------------------
# Phase 1: byte-matching BYTECODE for $(TARGET).
# Driver lives in archaeology/tools/roundtrip_bytecode.py.

.PHONY: verify
verify:
	@if [ -z "$(OUTPUT_ROOT)" ]; then \
	  echo "no OUTPUT_ROOT_$(TARGET) configured in Makefile" >&2; exit 1; \
	fi
	@if [ ! -d "$(OUTPUT_ROOT)" ]; then \
	  echo "$(OUTPUT_ROOT) not populated. Run awvm-disasm on user-supplied originals first." >&2; \
	  exit 1; \
	fi
	@python3 $(ARCHAEOLOGY)/tools/roundtrip_bytecode.py \
	    --port $(TARGET) --output-root $(OUTPUT_ROOT)

.PHONY: verify-all
verify-all:
	@cd $(ARCHAEOLOGY) && python3 tools/roundtrip_bytecode.py --all

# -----------------------------------------------------------------------------
# Phase 2 (not yet implemented): byte-matching BYTECODE + polygon resources +
# palettes + sound + bank packaging for the full DOS port. See issue #0060.

# -----------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -rf build/

# -----------------------------------------------------------------------------
# Sanity check: refuse `verify` with an unknown TARGET (no flags file).
$(FLAGS_FILE):
	@echo "no flags file at $@; create one for TARGET=$(TARGET) (see releases/template.flags)" >&2
	@false
