# Missing NULL check after allocation
# CWE-476 | Severity: HIGH
# File: target/linux/generic/files/drivers/platform/mikrotik/rb_lz77.c line 317

**Risk:** Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
