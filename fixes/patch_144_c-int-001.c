# Integer overflow in size calculation
# CWE-190 | Severity: HIGH
# File: target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c line 483

**Risk:** Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
