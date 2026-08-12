#include "tests.h"
#include <stdarg.h>

static int	g_total = 0;
static int	g_passed = 0;

void	ft_test(int ok, const char *fmt, ...)
{
	char	buf[256];
	va_list	ap;

	va_start(ap, fmt);
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	printf("%-45s [%s]\n", buf, ok ? OK : KO);
	g_total++;
	g_passed += (ok != 0);
}

void	test_summary(void)
{
	printf("\n%d/%d tests passed\n", g_passed, g_total);
}
