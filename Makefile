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
OUTPUT_ROOT_amiga          := $(ARCHAEOLOGY)/tmp/output/amiga
OUTPUT_ROOT_msdos          := $(ARCHAEOLOGY)/tmp/output/msdos
OUTPUT_ROOT_gba_usa        := $(ARCHAEOLOGY)/tmp/output/gba_usa
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
	@echo "  make verify              bytecode + raw-asset byte-match for TARGET"
	@echo "  make verify-bytecode     just bytecode round-trip for TARGET"
	@echo "  make verify-resources    just raw-asset md5 check for TARGET"
	@echo "  make verify-all          everything for every supported port"
	@echo "  make plan                show PLAN.md"
	@echo "  make clean               wipe build/"
	@echo ""
	@echo "Supported TARGETs (Phase 1 + Phase 2 byte-match):"
	@echo "  amiga, msdos, genesis_europe, snes_eu, gba_usa"
	@echo ""
	@echo "Each TARGET corresponds to a releases/<target>.flags file"
	@echo "(symbolic flags) and a releases/<target>.resources.json file"
	@echo "(per-resource md5 manifest). See README.md and PLAN.md."

.PHONY: plan
plan:
	@cat PLAN.md

# -----------------------------------------------------------------------------
# Phase 1: byte-matching BYTECODE for $(TARGET).
# Driver lives in archaeology/tools/roundtrip_bytecode.py.

.PHONY: verify
verify: verify-bytecode verify-resources

.PHONY: verify-bytecode
verify-bytecode:
	@if [ -z "$(OUTPUT_ROOT)" ]; then \
	  echo "no OUTPUT_ROOT_$(TARGET) configured in Makefile" >&2; exit 1; \
	fi
	@if [ ! -d "$(OUTPUT_ROOT)" ]; then \
	  echo "$(OUTPUT_ROOT) not populated. Run awvm-disasm on user-supplied originals first." >&2; \
	  exit 1; \
	fi
	@python3 $(ARCHAEOLOGY)/tools/roundtrip_bytecode.py \
	    --port $(TARGET) --output-root $(OUTPUT_ROOT)

.PHONY: verify-resources
verify-resources:
	@if [ -z "$(OUTPUT_ROOT)" ]; then \
	  echo "no OUTPUT_ROOT_$(TARGET) configured in Makefile" >&2; exit 1; \
	fi
	@python3 $(ARCHAEOLOGY)/tools/verify_resources.py \
	    --port $(TARGET) --output-root $(OUTPUT_ROOT) \
	    --manifest releases/$(TARGET).resources.json

.PHONY: verify-all
verify-all: verify-bytecode-all verify-resources-all

.PHONY: verify-bytecode-all
verify-bytecode-all:
	@cd $(ARCHAEOLOGY) && python3 tools/roundtrip_bytecode.py --all

.PHONY: verify-resources-all
verify-resources-all:
	@cd $(ARCHAEOLOGY) && python3 tools/verify_resources.py --port _ --all

# Phase 3a: branch-organized canonical sources at src/levels/<branch>/<stage>.asm.
# One canonical .asm per (branch, stage); each ports's level slot maps to a
# (branch, stage) lookup at build time. The win: when two ports share
# byte-identical bytecode, they share ONE source file.
.PHONY: verify-stages
verify-stages:
	@cd $(ARCHAEOLOGY) && python3 tools/verify_stage.py \
	    --src-tree $(realpath src/levels)

# Phase 2 of the `;@raw=` migration: source must contain ZERO
# `;@raw=` annotations. awvm-asm now panics on any line carrying
# the marker (see AnotherWorld_VMTools commit a1c6661); this rule
# is the cheaper text-only check that catches it before the
# assembler does. Wire it into pre-commit / CI as
# `make lint-raw`.
.PHONY: lint-raw
lint-raw:
	@cd $(ARCHAEOLOGY) && python3 tools/audit_raw_annotations.py --strict

# Aggregate lint target. Add new lint rules here.
.PHONY: lint
lint: lint-raw

# Phase 3b: source files with `;@if BRANCH == "..."` conditional directives.
# `make preprocess SRC=path/to/foo.asm.in TARGET=cartridge_1992`
# emits the per-branch .asm to build/<TARGET>/.
.PHONY: preprocess
preprocess:
	@if [ -z "$(SRC)" ]; then echo "specify SRC=path/to/foo.asm.in" >&2; exit 1; fi
	@mkdir -p $(BUILD_DIR)
	@python3 $(ARCHAEOLOGY)/tools/awvm_preprocess.py \
	    $(SRC) $(FLAGS_FILE) \
	    -o $(BUILD_DIR)/$(notdir $(basename $(SRC)))

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
