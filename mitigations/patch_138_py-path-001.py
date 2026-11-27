# Path traversal via unsanitized input
# CWE-22 | Severity: HIGH
# File: scripts/cfe-partition-tag.py line 60

**Risk:** File path built from user input. Attacker reads/writes arbitrary files using ../ sequences.

**Fix:** Use os.path.realpath() and verify result starts with the expected base directory.
