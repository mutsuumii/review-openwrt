# Use-after-free pattern
# CWE-416 | Severity: HIGH
# File: target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c line 348

**Risk:** Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
