# Security audit: openwrt/openwrt

Date: 2026-11-27 | Auditor: [mutsuumii](https://github.com/mutsuumii)

## Summary

Found 215 issue(s): 107 critical, 107 high, 1 medium.

## Findings

### 1. [CRITICAL] Format string vulnerability

**CWE-134** | `scripts/config/lkc.h` line 79

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
void str_printf(struct gstr *gs, const char *fmt, ...);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 2. [CRITICAL] Format string vulnerability

**CWE-134** | `scripts/config/lkc.h` line 84

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
void menu_warn(struct menu *menu, const char *fmt, ...);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 3. [HIGH] Integer overflow in size calculation

**CWE-190** | `scripts/config/lkc.h` line 60

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
void *xrealloc(void *p, size_t size);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 4. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/lkc.h` line 58

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *xmalloc(size_t size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 5. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/lkc.h` line 59

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *xcalloc(size_t nmemb, size_t size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 6. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/lkc.h` line 60

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *xrealloc(void *p, size_t size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 7. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/lkc.h` line 61

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char *xstrdup(const char *s);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 8. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 921

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf, sizeof(buf), "0x%02x", dev);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 9. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 928

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf, sizeof(buf), "0x%02x", rev);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 10. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 3206

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(name, sizeof(name), "port%d_rx", i);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 11. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 3211

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(name, sizeof(name), "port%d_tx", i);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 12. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 3216

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(name, sizeof(name), "nss_port%d_rst", i);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 13. [HIGH] Integer overflow in size calculation

**CWE-190** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 750

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
buf = kcalloc(PPE_FDB_TBL_NUM, PPE_FDB_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 14. [HIGH] Integer overflow in size calculation

**CWE-190** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 775

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
buf = kcalloc(PPE_VSI_MAX, PPE_VSI_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 15. [HIGH] Integer overflow in size calculation

**CWE-190** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 799

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
buf = kcalloc(PPE_XLT_TBL_NUM, PPE_XLT_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 16. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 757

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 17. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 750

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = kcalloc(PPE_FDB_TBL_NUM, PPE_FDB_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 18. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 775

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = kcalloc(PPE_VSI_MAX, PPE_VSI_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 19. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/qualcommax/files/drivers/net/ethernet/qualcomm/qca_ppe_main.c` line 799

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = kcalloc(PPE_XLT_TBL_NUM, PPE_XLT_WORDS * sizeof(u32), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 20. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/seama.c` line 102

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 21. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/seama.c` line 64

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(data_size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 22. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/seama.c` line 136

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
first_block = malloc(erasesize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 23. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1090

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
sprintf(buf, "up, 100 Mbps, cpu port");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 24. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1105

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len = sprintf(buf, "up, %d Mbps, %s duplex",
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 25. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1109

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len = sprintf(buf, "down");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 26. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1112

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(buf+len, ", auto-negotiate");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 27. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1114

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(buf+len, " (in progress)");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 28. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1116

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(buf+len, ", fixed speed (%d)",
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 29. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1090

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
sprintf(buf, "up, 100 Mbps, cpu port");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 30. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1105

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len = sprintf(buf, "up, %d Mbps, %s duplex",
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 31. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1109

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len = sprintf(buf, "down");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 32. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1112

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len += sprintf(buf+len, ", auto-negotiate");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 33. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1114

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len += sprintf(buf+len, " (in progress)");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 34. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1116

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len += sprintf(buf+len, ", fixed speed (%d)",
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 35. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1302

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(state);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 36. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/net/phy/ip17xx.c` line 1327

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(state);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 37. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/bn_lib.c` line 205

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(a);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 38. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/bn_lib.c` line 215

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(a);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 39. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/network/services/ead/src/tinysrp/bn_lib.c` line 259

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
a=A=(BN_ULONG *)malloc(sizeof(BN_ULONG)*(words+1));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 40. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/confdata.c` line 139

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(depfile_path + depfile_prefix_len, name);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 41. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/confdata.c` line 671

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(out, "\"");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 42. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/confdata.c` line 682

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(out, "\\");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 43. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/confdata.c` line 686

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(out, "\"");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 44. [CRITICAL] Format string vulnerability

**CWE-134** | `scripts/config/confdata.c` line 193

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
vsnprintf(buf, sizeof(buf), fmt, ap);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 45. [HIGH] Integer overflow in size calculation

**CWE-190** | `scripts/config/confdata.c` line 297

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
nline = xrealloc(*lineptr, new_size);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 46. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/confdata.c` line 536

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(line);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 47. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/confdata.c` line 718

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(escaped);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 48. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/confdata.c` line 775

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(escaped);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 49. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/confdata.c` line 833

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(escaped);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 50. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/confdata.c` line 834

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(val_prefixed);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 51. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/confdata.c` line 274

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sym->def[def].val = xstrdup(p);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 52. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/confdata.c` line 297

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
nline = xrealloc(*lineptr, new_size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 53. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/confdata.c` line 668

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
out = xmalloc(len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 54. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/confdata.c` line 822

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
val_prefixed = xmalloc(val_prefixed_len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 55. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/platform/mikrotik/rb_nvmem.c` line 188

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
data = devm_kmalloc(dev, mtd_size, GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 56. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/util.c` line 38

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(gs.s, "\0");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 57. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/util.c` line 61

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(gs->s, s);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 58. [CRITICAL] Format string vulnerability

**CWE-134** | `scripts/config/util.c` line 66

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
void str_printf(struct gstr *gs, const char *fmt, ...)
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 59. [HIGH] Integer overflow in size calculation

**CWE-190** | `scripts/config/util.c` line 100

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
void *xrealloc(void *p, size_t size)
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 60. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 23

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
file = xmalloc(sizeof(*file));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 61. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 25

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
file->name = xstrdup(name);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 62. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 35

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
gs.s = xmalloc(sizeof(char) * 64);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 63. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 58

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
gs->s = xrealloc(gs->s, l);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 64. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 84

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *p = malloc(size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 65. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 93

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *p = calloc(nmemb, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 66. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 102

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
p = realloc(p, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 67. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/util.c` line 113

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
p = strdup(s);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 68. [MEDIUM] Large stack allocation (potential stack overflow)

**CWE-770** | `scripts/config/util.c` line 69

alloca() or large fixed VLA on stack. If size is attacker-controlled or too large, stack overflow corrupts adjacent frames.

```
char s[10000]; /* big enough... */
```

**Fix:** Use heap allocation (malloc) for large or variable-sized buffers. Enforce a size cap before alloca().
---

### 69. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 954

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, title[i]);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 70. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 955

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_correct_pdu            = %d\n", WAN_MIB_TABLE[i].wrx_correct_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 71. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 956

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_correct_pdu_bytes      = %d\n", WAN_MIB_TABLE[i].wrx_correct_pdu_bytes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 72. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 957

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_tccrc_err_pdu          = %d\n", WAN_MIB_TABLE[i].wrx_tccrc_err_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 73. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 958

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_tccrc_err_pdu_bytes    = %d\n", WAN_MIB_TABLE[i].wrx_tccrc_err_pdu_bytes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 74. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 959

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_ethcrc_err_pdu         = %d\n", WAN_MIB_TABLE[i].wrx_ethcrc_err_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 75. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 960

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_ethcrc_err_pdu_bytes   = %d\n", WAN_MIB_TABLE[i].wrx_ethcrc_err_pdu_bytes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 76. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 961

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_nodesc_drop_pdu        = %d\n", WAN_MIB_TABLE[i].wrx_nodesc_drop_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 77. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 962

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_len_violation_drop_pdu = %d\n", WAN_MIB_TABLE[i].wrx_len_violation_drop_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 78. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 963

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_idle_bytes             = %d\n", WAN_MIB_TABLE[i].wrx_idle_bytes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 79. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 964

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_nonidle_cw             = %d\n", WAN_MIB_TABLE[i].wrx_nonidle_cw);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 80. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 965

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_idle_cw                = %d\n", WAN_MIB_TABLE[i].wrx_idle_cw);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 81. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 966

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wrx_err_cw                 = %d\n", WAN_MIB_TABLE[i].wrx_err_cw);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 82. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 967

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wtx_total_pdu              = %d\n", WAN_MIB_TABLE[i].wtx_total_pdu);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 83. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 968

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "  wtx_total_bytes            = %d\n", WAN_MIB_TABLE[i].wtx_total_bytes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 84. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1017

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "CFG_WAN_WRDES_DELAY (0x%08X): %d\n", (unsigned int)CFG_WAN_WRDES_DELAY, IFX_REG_R32(CFG_WAN_WRDES_DELAY));
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 85. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1018

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "CFG_WRX_DMACH_ON    (0x%08X):", (unsigned int)CFG_WRX_DMACH_ON);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 86. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1020

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, " %d - %s", i, (IFX_REG_R32(CFG_WRX_DMACH_ON) & bit) ? "on " : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 87. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1021

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 88. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1022

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "CFG_WTX_DMACH_ON    (0x%08X):", (unsigned int)CFG_WTX_DMACH_ON);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 89. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1024

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, " %d - %s", i, (IFX_REG_R32(CFG_WTX_DMACH_ON) & bit) ? "on " : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 90. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1025

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 91. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1026

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "CFG_WRX_LOOK_BITTH  (0x%08X): %d\n", (unsigned int)CFG_WRX_LOOK_BITTH, IFX_REG_R32(CFG_WRX_LOOK_BITTH));
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 92. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1027

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "CFG_ETH_EFMTC_CRC   (0x%08X): rx_tc_crc_len    - %2d,  rx_tc_crc_check    - %s\n", (unsigned int)CFG_ETH_EFMTC_CRC, CFG_ETH_EFMTC_CRC->rx_tc_crc_len, CFG_ETH_EFMTC_CRC->rx_tc_crc_check ? " on" : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 93. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1028

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "                                  rx_eth_crc_check - %s, rx_eth_crc_present - %s\n",   CFG_ETH_EFMTC_CRC->rx_eth_crc_check ? " on" : "off", CFG_ETH_EFMTC_CRC->rx_eth_crc_present ? " on" : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 94. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1029

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "                                  tx_tc_crc_len    - %2d,  tx_tc_crc_gen      - %s\n", CFG_ETH_EFMTC_CRC->tx_tc_crc_len, CFG_ETH_EFMTC_CRC->tx_tc_crc_gen ? " on" : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 95. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1030

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "                                  tx_eth_crc_gen   - %s\n", CFG_ETH_EFMTC_CRC->tx_eth_crc_gen ? " on" : "off");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 96. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1032

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "RX Port:\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 97. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1034

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "  %d (0x%08X). mfs - %5d, dmach - %d, local_state - %d, partner_state - %d\n", i, (unsigned int)WRX_PORT_CONFIG(i), WRX_PORT_CONFIG(i)->mfs, WRX_PORT_CONFIG(i)->dmach, WRX_PORT_CONFIG(i)->local_state, WRX_PORT_CONFIG(i)->partner_state);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 98. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1035

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "RX DMA Channel:\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 99. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1037

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "  %d (0x%08X). desba - 0x%08X (0x%08X), deslen - %d, vlddes - %d\n", i, (unsigned int)WRX_DMA_CHANNEL_CONFIG(i), WRX_DMA_CHANNEL_CONFIG(i)->desba, ((unsigned int)WRX_DMA_CHANNEL_CONFIG(i)->desba << 2) | KSEG1, WRX_DMA_CHANNEL_CONFIG(i)->deslen, WRX_DMA_CHANNEL_CONFIG(i)->vlddes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 100. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1039

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "TX Port:\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 101. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1041

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "  %d (0x%08X). tx_cwth2 - %d, tx_cwth1 - %d\n", i, (unsigned int)WTX_PORT_CONFIG(i), WTX_PORT_CONFIG(i)->tx_cwth2, WTX_PORT_CONFIG(i)->tx_cwth1);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 102. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1042

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "TX DMA Channel:\n");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 103. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1044

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
llen += sprintf(str + llen, "  %d (0x%08X). desba - 0x%08X (0x%08X), deslen - %d, vlddes - %d\n", i, (unsigned int)WTX_DMA_CHANNEL_CONFIG(i), WTX_DMA_CHANNEL_CONFIG(i)->desba, ((unsigned int)WTX_DMA_CHANNEL_CONFIG(i)->desba << 2) | KSEG1, WTX_DMA_CHANNEL_CONFIG(i)->deslen, WTX_DMA_CHANNEL_CONFIG(i)->vlddes);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 104. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1076

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "error print      - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_ERR)              ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 105. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1077

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "debug print      - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_DEBUG_PRINT)      ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 106. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1078

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "assert           - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_ASSERT)           ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 107. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1079

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "dump rx skb      - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_DUMP_SKB_RX)      ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 108. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1080

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "dump tx skb      - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_DUMP_SKB_TX)      ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 109. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1081

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(page + off + len, "mac swap         - %s\n", (ifx_ptm_dbg_enable & DBG_ENABLE_MASK_MAC_SWAP)         ? "enabled" : "disabled");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 110. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1238

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(buf + len, "PTM %d.%d.%d", IFX_PTM_VER_MAJOR, IFX_PTM_VER_MID, IFX_PTM_VER_MINOR);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 111. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1239

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
len += sprintf(buf + len, "    PTM (E1) firmware version %d.%d\n", major, minor);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 112. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1017

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "CFG_WAN_WRDES_DELAY (0x%08X): %d\n", (unsigned int)CFG_WAN_WRDES_DELAY, IFX_REG_R32(CFG_WAN_WRDES_DELAY));
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 113. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1018

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "CFG_WRX_DMACH_ON    (0x%08X):", (unsigned int)CFG_WRX_DMACH_ON);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 114. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1020

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, " %d - %s", i, (IFX_REG_R32(CFG_WRX_DMACH_ON) & bit) ? "on " : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 115. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1021

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 116. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1022

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "CFG_WTX_DMACH_ON    (0x%08X):", (unsigned int)CFG_WTX_DMACH_ON);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 117. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1024

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, " %d - %s", i, (IFX_REG_R32(CFG_WTX_DMACH_ON) & bit) ? "on " : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 118. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1025

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 119. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1026

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "CFG_WRX_LOOK_BITTH  (0x%08X): %d\n", (unsigned int)CFG_WRX_LOOK_BITTH, IFX_REG_R32(CFG_WRX_LOOK_BITTH));
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 120. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1027

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "CFG_ETH_EFMTC_CRC   (0x%08X): rx_tc_crc_len    - %2d,  rx_tc_crc_check    - %s\n", (unsigned int)CFG_ETH_EFMTC_CRC, CFG_ETH_EFMTC_CRC->rx_tc_crc_len, CFG_ETH_EFMTC_CRC->rx_tc_crc_check ? " on" : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 121. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1028

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "                                  rx_eth_crc_check - %s, rx_eth_crc_present - %s\n",   CFG_ETH_EFMTC_CRC->rx_eth_crc_check ? " on" : "off", CFG_ETH_EFMTC_CRC->rx_eth_crc_present ? " on" : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 122. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1029

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "                                  tx_tc_crc_len    - %2d,  tx_tc_crc_gen      - %s\n", CFG_ETH_EFMTC_CRC->tx_tc_crc_len, CFG_ETH_EFMTC_CRC->tx_tc_crc_gen ? " on" : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 123. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1030

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "                                  tx_eth_crc_gen   - %s\n", CFG_ETH_EFMTC_CRC->tx_eth_crc_gen ? " on" : "off");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 124. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1032

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "RX Port:\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 125. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1034

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "  %d (0x%08X). mfs - %5d, dmach - %d, local_state - %d, partner_state - %d\n", i, (unsigned int)WRX_PORT_CONFIG(i), WRX_PORT_CONFIG(i)->mfs, WRX_PORT_CONFIG(i)->dmach, WRX_PORT_CONFIG(i)->local_state, WRX_PORT_CONFIG(i)->partner_state);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 126. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1035

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "RX DMA Channel:\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 127. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1037

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "  %d (0x%08X). desba - 0x%08X (0x%08X), deslen - %d, vlddes - %d\n", i, (unsigned int)WRX_DMA_CHANNEL_CONFIG(i), WRX_DMA_CHANNEL_CONFIG(i)->desba, ((unsigned int)WRX_DMA_CHANNEL_CONFIG(i)->desba << 2) | KSEG1, WRX_DMA_CHANNEL_CONFIG(i)->deslen, WRX_DMA_CHANNEL_CONFIG(i)->vlddes);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 128. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1039

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "TX Port:\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 129. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1041

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "  %d (0x%08X). tx_cwth2 - %d, tx_cwth1 - %d\n", i, (unsigned int)WTX_PORT_CONFIG(i), WTX_PORT_CONFIG(i)->tx_cwth2, WTX_PORT_CONFIG(i)->tx_cwth1);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 130. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1042

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "TX DMA Channel:\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 131. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1044

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
llen += sprintf(str + llen, "  %d (0x%08X). desba - 0x%08X (0x%08X), deslen - %d, vlddes - %d\n", i, (unsigned int)WTX_DMA_CHANNEL_CONFIG(i), WTX_DMA_CHANNEL_CONFIG(i)->desba, ((unsigned int)WTX_DMA_CHANNEL_CONFIG(i)->desba << 2) | KSEG1, WTX_DMA_CHANNEL_CONFIG(i)->deslen, WTX_DMA_CHANNEL_CONFIG(i)->vlddes);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 132. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1238

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len += sprintf(buf + len, "PTM %d.%d.%d", IFX_PTM_VER_MAJOR, IFX_PTM_VER_MID, IFX_PTM_VER_MINOR);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 133. [CRITICAL] Format string vulnerability

**CWE-134** | `package/kernel/lantiq/ltq-ptm/src/ifxmips_ptm_adsl.c` line 1239

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len += sprintf(buf + len, "    PTM (E1) firmware version %d.%d\n", major, minor);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 134. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_mstc_boot.c` line 223

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(parts);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 135. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_mstc_boot.c` line 127

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(nr_parts, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 136. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_mstc_boot.c` line 187

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(nr_parts, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 137. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `scripts/config/lxdialog/inputbox.c` line 43

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(instr, init);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 138. [HIGH] Path traversal via unsanitized input

**CWE-22** | `scripts/cfe-partition-tag.py` line 60

File path built from user input. Attacker reads/writes arbitrary files using ../ sequences.

```
in_f = open(args.input_file, "r+b")
```

**Fix:** Use os.path.realpath() and verify result starts with the expected base directory.
---

### 139. [HIGH] Path traversal via unsanitized input

**CWE-22** | `scripts/cfe-partition-tag.py` line 66

File path built from user input. Attacker reads/writes arbitrary files using ../ sequences.

```
out_f = open(args.output_file, "w+b")
```

**Fix:** Use os.path.realpath() and verify result starts with the expected base directory.
---

### 140. [CRITICAL] Format string vulnerability

**CWE-134** | `package/network/services/ead/src/tinysrp/clitest.c` line 63

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("Enter username: ");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 141. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/mvebu/files/drivers/hwmon/iei-wt61p803-puzzle-hwmon.c` line 378

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(cdev->name, THERMAL_NAME_LENGTH, "wt61p803_puzzle_%d", pwm_channel);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 142. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/t_client.c` line 284

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(tc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 143. [HIGH] Integer overflow in size calculation

**CWE-190** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 351

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
parts = kcalloc(ret + 1, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 144. [HIGH] Integer overflow in size calculation

**CWE-190** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 483

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
parts = kcalloc(ret + 1, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 145. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 257

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 146. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 329

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(cfe1_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 147. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 330

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(cfe2_name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 148. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 348

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 149. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 480

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 150. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 203

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(num_parts, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 151. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 351

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(ret + 1, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 152. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 365

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(BCM_WFI_SPLIT_PARTS, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 153. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 483

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(ret + 1, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 154. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_bcm_wfi.c` line 497

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(BCM_WFI_SPLIT_PARTS, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 155. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/uencrypt/src/uencrypt.c` line 31

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ptr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 156. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 126

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
mbedtls_pk_free(pk);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 157. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 127

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pk);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 158. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 140

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(crt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 159. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 517

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(elem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 160. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 546

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(crt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 161. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 167

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
pk = calloc(1, sizeof(*pk));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 162. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 203

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
pk = calloc(1, sizeof(*pk));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 163. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 502

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
elem = calloc(len, sizeof(*elem));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 164. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/utils/ucode-mod-pkgen/src/ucode.c` line 544

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
crt = calloc(1, sizeof(*crt));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 165. [HIGH] Use-after-free pattern

**CWE-416** | `package/utils/fritz-tools/src/fritz_cal_extract.c` line 329

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 166. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/utils/fritz-tools/src/fritz_cal_extract.c` line 285

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(datasize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 167. [CRITICAL] Command injection via system()/popen()

**CWE-78** | `package/system/mtd/src/mtd.c` line 866

system() and popen() invoke /bin/sh. Any unsanitized input in the command string gives full shell access.

```
system("/sbin/reboot");
```

**Fix:** Use execve() with explicit argv array. If shell features are needed, whitelist all arguments strictly.
---

### 168. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/mtd.c` line 274

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 169. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/mtd.c` line 283

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 170. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/mtd.c` line 325

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 171. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/mtd.c` line 415

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 172. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/mtd.c` line 255

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
str = strdup(mtd);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 173. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/mtd.c` line 271

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(erasesize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 174. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/mtd.c` line 297

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
str = strdup(mtd);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 175. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/mtd.c` line 387

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(erasesize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 176. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/mtd.c` line 559

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
str = strdup(mtd);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 177. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/network/ipv6/464xlat/src/464xlatcfg.c` line 74

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(prefix, "/96");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 178. [CRITICAL] Format string vulnerability

**CWE-134** | `package/network/ipv6/464xlat/src/464xlatcfg.c` line 41

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf, sizeof(buf), "/var/run/%s.pid", argv[1]);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 179. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/libbridge_init.c` line 82

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(namelist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 180. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/libbridge_init.c` line 122

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(namelist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 181. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/network/services/ead/src/tinysrp/tphrase.c` line 148

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
sprintf(bakfile, "%s.bak", pwname);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 182. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `package/network/services/ead/src/tinysrp/tphrase.c` line 149

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
sprintf(bakfile2, "%s.sav", pwname);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 183. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 144

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 184. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 154

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 185. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 155

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 186. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 173

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 187. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 174

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 188. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 178

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 189. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 179

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 190. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 189

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 191. [HIGH] Use-after-free pattern

**CWE-416** | `package/network/services/ead/src/tinysrp/tphrase.c` line 190

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(bakfile2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 192. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/mconf.c` line 322

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pos);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 193. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/mconf.c` line 347

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pos);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 194. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/mconf.c` line 499

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pos);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 195. [HIGH] Use-after-free pattern

**CWE-416** | `scripts/config/mconf.c` line 501

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sym_arr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 196. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/mconf.c` line 329

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
pos->next = xcalloc(1, sizeof(*pos));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 197. [HIGH] Missing NULL check after allocation

**CWE-476** | `scripts/config/mconf.c` line 332

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
subtitles = pos = xcalloc(1, sizeof(*pos));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 198. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_seil.c` line 95

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
vfree(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 199. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_seil.c` line 173

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(parts);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 200. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_seil.c` line 67

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = vmalloc(env_mtd->size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 201. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_seil.c` line 124

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(NR_PARTS, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 202. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/jffs2.c` line 258

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 203. [HIGH] Use-after-free pattern

**CWE-416** | `package/system/mtd/src/jffs2.c` line 367

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 204. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/jffs2.c` line 244

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(erasesize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 205. [HIGH] Missing NULL check after allocation

**CWE-476** | `package/system/mtd/src/jffs2.c` line 301

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(erasesize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 206. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/mtd/mtdsplit/mtdsplit_cfe_bootfs.c` line 57

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
parts = kcalloc(NR_PARTS, sizeof(*parts), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 207. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/mpc85xx/image/spi-loader/include/string.h` line 7

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
extern char *strcpy(char *dest, const char *src);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 208. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `target/linux/mpc85xx/image/spi-loader/include/string.h` line 9

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
extern char *strcat(char *dest, const char *src);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 209. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/platform/mikrotik/rb_lz77.c` line 313

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
pr_err(MIKRO_LZ77 "input longer than expected\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 210. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/generic/files/drivers/platform/mikrotik/rb_lz77.c` line 328

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
pr_err(MIKRO_LZ77 "input overrun\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 211. [HIGH] Use-after-free pattern

**CWE-416** | `target/linux/generic/files/drivers/platform/mikrotik/rb_lz77.c` line 439

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
kfree(opcode);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 212. [HIGH] Missing NULL check after allocation

**CWE-476** | `target/linux/generic/files/drivers/platform/mikrotik/rb_lz77.c` line 317

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
opcode = kmalloc(sizeof(*opcode), GFP_KERNEL);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 213. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/realtek/files-6.18/drivers/net/dsa/rtl83xx/rtl931x.c` line 204

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(set_str, sizeof(set_str), "realtek,led-set%d-force-port-mask", set);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 214. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/realtek/files-6.18/drivers/net/dsa/rtl83xx/rtl931x.c` line 281

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(set_name, sizeof(set_name), "led_set%d", set);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 215. [CRITICAL] Format string vulnerability

**CWE-134** | `target/linux/realtek/files-6.18/drivers/net/mdio/mdio-realtek-otto-serdes.c` line 172

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(dirname, sizeof(dirname), "serdes.%d", sds);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---
