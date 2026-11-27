# Format string vulnerability
# CWE-134 | Severity: CRITICAL
# File: target/linux/mvebu/files/drivers/hwmon/iei-wt61p803-puzzle-hwmon.c line 378

**Risk:** User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
