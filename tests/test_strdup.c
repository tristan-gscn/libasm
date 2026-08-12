/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:47:32 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 17:48:27 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>
#include <stdlib.h>

static void	check(const char *s)
{
	char		*result;
	int			ok;
	const char	*display;

	result = ft_strdup(s);
	ok = result != NULL && strcmp(result, s) == 0 && result != s;
	display = "(null)";
	if (result != NULL)
		display = result;
	ft_test(ok, "ft_strdup(\"%s\") = \"%s\"", s, display);
	free(result);
}

void	test_strdup(void)
{
	printf("\n--- ft_strdup ---\n");
	check("");
	check("a");
	check("Hello World");
	check("with spaces  and\ttabs\n");
}
