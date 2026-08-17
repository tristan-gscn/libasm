/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:38 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_sort.h"
#include <stdlib.h>

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

static t_list	*build_list(int *values, size_t n)
{
	t_list	*head;
	size_t	i;

	head = NULL;
	i = n;
	while (i > 0)
	{
		i--;
		ft_list_push_front(&head, &values[i]);
	}
	return (head);
}

/*
** Bounded on purpose: if ft_list_sort corrupts the chain into a cycle,
** a plain "while (list)" walk would hang the test suite forever.
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

void	list_sort_check_case(const char *label, int *values, size_t n,
	int *expected)
{
	t_list	*head;

	head = build_list(values, n);
	ft_list_sort(&head, cmp_int);
	ft_test(ft_list_size(head) == (unsigned int)n,
		"ft_list_sort(%s) keeps size = %u", label, n);
	ft_test(check_int_order(head, expected, n),
		"ft_list_sort(%s) sorts in ascending order", label);
	free_list(head);
}
