#include "tests.h"

void	test_strcpy(void)
{
	char	dst[32];

	ft_strcpy(dst, "Hello World");
	printf("ft_strcpy(\"Hello World\") = %s\n", dst);
}
