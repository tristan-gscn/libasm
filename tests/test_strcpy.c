#include "tests.h"
#include <string.h>

static void	check(const char *src)
{
	char	expected[256];
	char	result[256];
	char	*ret = ft_strcpy(result, src);

	strcpy(expected, src);
	ft_test(strcmp(expected, result) == 0 && ret == result,
		"ft_strcpy(\"%s\") = \"%s\"", src, result);
}

void	test_strcpy(void)
{
	printf("\n--- ft_strcpy ---\n");
	check("");
	check("a");
	check("Hello World");
	check("with spaces  and\ttabs\n");
}
