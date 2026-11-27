# Buffer overflow via unsafe string function
# CWE-120 | Severity: CRITICAL
# File: package/network/services/ead/src/tinysrp/tphrase.c line 149

**Risk:** strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
