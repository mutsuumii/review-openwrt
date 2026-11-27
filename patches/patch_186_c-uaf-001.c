# Use-after-free pattern
# CWE-416 | Severity: HIGH
# File: package/network/services/ead/src/tinysrp/tphrase.c line 173

**Risk:** Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
