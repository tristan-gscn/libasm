/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:32 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_remove_if.h"

/*
** Bounded on purpose: if ft_list_remove_if mishandles unlinking, a plain
** "while (list)" walk on a corrupted chain could hang the test suite.
*/
static int	check_int_order(t_list *list, int *expected, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (list == NULL || list->data == NULL)
			return (0);
		if (*(int *)list->data != expected[i])
			return (0);
		list = list->next;
		i++;
	}
	return (list == NULL);
}

void	list_remove_if_check_case(t_remove_case *c)
{
	t_list	*head;
	int		ref;

	head = build_int_list(c->values, c->n);
	ref = c->target;
	ft_list_remove_if(&head, &ref, cmp_int, free_int);
	ft_test(ft_list_size(head) == (unsigned int)c->expected_n,
		"ft_list_remove_if(%s) keeps size = %u", c->label, c->expected_n);
	ft_test(check_int_order(head, c->expected, c->expected_n),
		"ft_list_remove_if(%s) leaves the right elements in order",
		c->label);
	free_int_list(head);
}

void	list_remove_if_check_empty(void)
{
	t_list	*head;
	int		ref;

	head = NULL;
	ref = 0;
	ft_list_remove_if(&head, &ref, cmp_int, free_int);
	ft_test(head == NULL, "ft_list_remove_if(NULL) leaves list empty");
}

void	check_no_match(void)
{
	int				values[3];
	int				expected[3];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	c.label = "no match";
	c.values = values;
	c.n = 3;
	c.target = 99;
	c.expected = expected;
	c.expected_n = 3;
	list_remove_if_check_case(&c);
}

void	check_remove_all(void)
{
	int				values[3];
	t_remove_case	c;

	values[0] = 5;
	values[1] = 5;
	values[2] = 5;
	c.label = "remove all";
	c.values = values;
	c.n = 3;
	c.target = 5;
	c.expected = NULL;
	c.expected_n = 0;
	list_remove_if_check_case(&c);
}
