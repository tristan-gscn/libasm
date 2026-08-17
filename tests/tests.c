/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:05:40 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 15:06:08 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdarg.h>

static int	g_total = 0;
static int	g_passed = 0;

void	ft_test(int ok, const char *fmt, ...)
{
	char		buf[256];
	va_list		ap;
	const char	*status;

	va_start(ap, fmt);
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	status = KO;
	if (ok)
		status = OK;
	printf("%-80s [%s]\n", buf, status);
	g_total++;
	g_passed += (ok != 0);
}

void	test_summary(void)
{
	printf("\n%d/%d tests passed\n", g_passed, g_total);
}
