# Missing NULL check after allocation
# CWE-476 | Severity: HIGH
# File: package/utils/ucode-mod-pkgen/src/ucode.c line 502

**Risk:** Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
