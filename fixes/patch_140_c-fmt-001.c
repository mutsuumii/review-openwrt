# Format string vulnerability
# CWE-134 | Severity: CRITICAL
# File: package/network/services/ead/src/tinysrp/clitest.c line 63

**Risk:** User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
