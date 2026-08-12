#include "tests.h"

void	test_strcmp(void)
{
	printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
	printf("ft_strcmp(\"abc\", \"abd\") = %d\n", ft_strcmp("abc", "abd"));
	printf("ft_strcmp(\"abc\", \"ab\") = %d\n", ft_strcmp("abc", "ab"));
}
