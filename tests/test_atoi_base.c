/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:32:26 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/13 16:35:31 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	check(const char *str, const char *base, int expected)
{
	int	result;

	result = ft_atoi_base((char *)str, (char *)base);
	ft_test(result == expected,
		"ft_atoi_base(\"%s\", \"%s\") = %d", str, base, result);
}

static void	check_bases(void)
{
	check("42", "0123456789", 42);
	check("0", "0123456789", 0);
	check("1010", "01", 10);
	check("777", "01234567", 511);
	check("FF", "0123456789ABCDEF", 255);
	check("zz", "abcdefghijklmnopqrstuvwxyz", 675);
	check("a", "0123456789a", 10);
}

static void	check_parsing(void)
{
	check("   42", "0123456789", 42);
	check("\t\n 42", "0123456789", 42);
	check("-42", "0123456789", -42);
	check("+42", "0123456789", 42);
	check("  -101", "01", -5);
	check("+0", "0123456789", 0);
	check("--42", "0123456789", 0);
	check("42abc", "0123456789", 42);
	check("", "0123456789", 0);
	check("   ", "0123456789", 0);
	check("-", "0123456789", 0);
	check("abc", "0123456789", 0);
}

static void	check_invalid_base(void)
{
	check("42", "", 0);
	check("42", "0", 0);
	check("42", "0123456789A0", 0);
	check("42", "01234+6789", 0);
	check("42", "01234-6789", 0);
	check("42", "01234 6789", 0);
	check("42", "01234\t6789", 0);
	check("101", "00", 0);
}

void	test_atoi_base(void)
{
	printf("\n--- ft_atoi_base ---\n");
	check_bases();
	check_parsing();
	check_invalid_base();
}
