# Buffer overflow via unsafe string function
# CWE-120 | Severity: CRITICAL
# File: package/network/ipv6/464xlat/src/464xlatcfg.c line 74

**Risk:** strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
