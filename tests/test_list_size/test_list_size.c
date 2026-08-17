/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:54:56 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/13 17:04:45 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	check(t_list *list, unsigned int expected)
{
	unsigned int	result;

	result = ft_list_size(list);
	ft_test(result == expected, "ft_list_size(<%u elem list>) = %u",
		expected, result);
}

void	test_list_size(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	printf("\n--- ft_list_size ---\n");
	check(NULL, 0);
	a.data = NULL;
	a.next = NULL;
	check(&a, 1);
	a.next = &b;
	b.data = NULL;
	b.next = NULL;
	check(&a, 2);
	b.next = &c;
	c.data = NULL;
	c.next = NULL;
	check(&a, 3);
}
