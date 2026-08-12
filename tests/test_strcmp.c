/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:05:40 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 15:06:40 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

static int	sign(int x)
{
	return ((x > 0) - (x < 0));
}

static void	check(const char *a, const char *b)
{
	int	result;

	result = sign(ft_strcmp(a, b));
	ft_test(result == sign(strcmp(a, b)),
		"ft_strcmp(\"%s\", \"%s\") = %d", a, b, result);
}

static void	check_high_bytes(void)
{
	const char	a[2] = {(char)0xff, '\0'};
	const char	b[2] = {(char)0x01, '\0'};
	int			result;

	result = sign(ft_strcmp(a, b));
	ft_test(result == sign(strcmp(a, b)), "ft_strcmp(0xff, 0x01) = %d", result);
}

void	test_strcmp(void)
{
	printf("\n--- ft_strcmp ---\n");
	check("abc", "abc");
	check("abc", "abd");
	check("abc", "abb");
	check("abc", "ab");
	check("ab", "abc");
	check("", "");
	check("a", "");
	check("", "a");
	check("ABC", "abc");
	check_high_bytes();
}
