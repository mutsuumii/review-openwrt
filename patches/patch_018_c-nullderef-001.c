# Missing NULL check after allocation
# CWE-476 | Severity: HIGH
# File: target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c line 775

**Risk:** Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
