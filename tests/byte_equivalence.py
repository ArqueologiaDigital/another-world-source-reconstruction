#!/usr/bin/env python3
"""Standalone byte-equivalence test driver for the source-reconstruction repo.

Wraps the per-stage / per-port verifiers (`make verify-stages`,
`make verify-unified`, `make verify-all`, `make lint`) into a single
aggregated PASS/FAIL report with structured per-artifact output. On
FAIL, surfaces the underlying tool's diagnostic lines so a CI log can
show what regressed without re-running each individual verifier by
hand.

Issue #0064 acceptance — the third remaining checkbox after the
`make test` aggregate rule landed.

Usage:

    python3 tests/byte_equivalence.py            # run all checks
    python3 tests/byte_equivalence.py --quick    # skip resource-heavy `verify-all`

Exit code is 0 iff every check passes.
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from dataclasses import dataclass


@dataclass
class CheckResult:
    name: str
    target: str
    passed: bool
    summary: str
    failures: list[str]


def run(cmd: list[str]) -> tuple[int, str]:
    proc = subprocess.run(cmd, capture_output=True, text=True)
    return proc.returncode, proc.stdout + proc.stderr


def extract_total(output: str) -> str | None:
    """Pull the trailing `TOTAL: N/M ...` line from a verifier."""
    for line in reversed(output.splitlines()):
        if line.startswith("TOTAL: "):
            return line.removeprefix("TOTAL: ").strip()
    return None


def extract_failures(output: str) -> list[str]:
    """Pull lines that look like per-artifact failure diagnostics:
    'expected at 0xNNNN: 0xXX', 'got at 0xNNNN: 0xYY', '<stage> FAIL ...',
    'verify_stage.py: ...'.
    """
    out = []
    fail_patterns = (
        re.compile(r"\bFAIL\b"),
        re.compile(r"^\s*expected at 0x[0-9A-Fa-f]+:"),
        re.compile(r"^\s*got at 0x[0-9A-Fa-f]+:"),
        re.compile(r"^\s*mismatch\b", re.IGNORECASE),
        re.compile(r"^Traceback "),
    )
    for line in output.splitlines():
        if any(p.search(line) for p in fail_patterns):
            out.append(line.rstrip())
    return out


def run_check(name: str, target: str, cmd: list[str]) -> CheckResult:
    rc, output = run(cmd)
    summary = extract_total(output) or ""
    if rc == 0 and not summary:
        # Tools that don't print TOTAL but exit 0 — e.g. `make lint`.
        summary = "(no TOTAL line; exit 0)"
    failures = extract_failures(output) if rc != 0 else []
    return CheckResult(
        name=name,
        target=target,
        passed=(rc == 0),
        summary=summary,
        failures=failures,
    )


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument(
        "--quick",
        action="store_true",
        help="skip the resource-heavy `verify-all` step",
    )
    ap.add_argument(
        "--no-lint",
        action="store_true",
        help="skip the lint step",
    )
    args = ap.parse_args()

    checks: list[CheckResult] = []

    checks.append(run_check(
        "verify-stages",
        "per-port .asm round-trip",
        ["make", "verify-stages"],
    ))
    checks.append(run_check(
        "verify-unified",
        "unified .asm.in round-trip",
        ["make", "verify-unified"],
    ))
    if not args.quick:
        checks.append(run_check(
            "verify-all",
            "bytecode + raw resources × 5 ports",
            ["make", "verify-all"],
        ))
    if not args.no_lint:
        checks.append(run_check(
            "lint",
            "source lint",
            ["make", "lint"],
        ))

    # Per-check report.
    name_w = max(len(c.name) for c in checks)
    target_w = max(len(c.target) for c in checks)
    print(f"{'check':<{name_w}}  {'target':<{target_w}}  status  summary")
    print(f"{'-' * name_w}  {'-' * target_w}  ------  -------")
    for c in checks:
        status = "PASS" if c.passed else "FAIL"
        print(f"{c.name:<{name_w}}  {c.target:<{target_w}}  {status:<6}  {c.summary}")

    # Failure detail.
    failed = [c for c in checks if not c.passed]
    if failed:
        print()
        print("Failure detail:")
        for c in failed:
            print(f"\n=== {c.name} ===")
            for line in c.failures[:30]:
                print(f"  {line}")
            if len(c.failures) > 30:
                print(f"  ... ({len(c.failures) - 30} more lines suppressed)")

    # Aggregate.
    n_pass = sum(1 for c in checks if c.passed)
    print()
    print(f"AGGREGATE: {n_pass}/{len(checks)} checks passed.")

    return 0 if n_pass == len(checks) else 1


if __name__ == "__main__":
    sys.exit(main())
