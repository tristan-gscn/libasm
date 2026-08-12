/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:05:40 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 15:06:29 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

static void	check(const char *src)
{
	char	expected[256];
	char	result[256];
	char	*ret;

	ret = ft_strcpy(result, src);
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
