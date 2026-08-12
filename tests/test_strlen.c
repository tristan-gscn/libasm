#include "tests.h"
#include <string.h>

static void	check(const char *s)
{
	size_t	result = ft_strlen(s);

	ft_test(result == strlen(s), "ft_strlen(\"%s\") = %zu", s, result);
}

static void	check_long(void)
{
	static char	big[10000];
	size_t		result;

	memset(big, 'a', sizeof(big) - 1);
	big[sizeof(big) - 1] = '\0';
	result = ft_strlen(big);
	ft_test(result == strlen(big), "ft_strlen(<%zu 'a' chars>) = %zu",
		sizeof(big) - 1, result);
}

void	test_strlen(void)
{
	printf("\n--- ft_strlen ---\n");
	check("");
	check("a");
	check("Hello World");
	check("with spaces  and\ttabs\n");
	check_long();
}
