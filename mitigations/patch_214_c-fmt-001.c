# Format string vulnerability
# CWE-134 | Severity: CRITICAL
# File: target/linux/realtek/files-6.18/drivers/net/dsa/rtl83xx/rtl931x.c line 281

**Risk:** User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
