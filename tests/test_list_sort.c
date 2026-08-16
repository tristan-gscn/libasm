/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 23:29:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/16 23:40:50 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdlib.h>

static void	free_list(t_list *list)
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

static void	check_int_case(const char *label, int *values, size_t n,
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

static void	check_empty(void)
{
	t_list	*head;

	head = NULL;
	ft_list_sort(&head, cmp_int);
	ft_test(head == NULL, "ft_list_sort(NULL) leaves list empty");
}

static void	check_single(void)
{
	int		value;
	int		expected[1];

	value = 42;
	expected[0] = 42;
	check_int_case("single element", &value, 1, expected);
}

static void	check_already_sorted(void)
{
	int	values[4];
	int	expected[4];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	values[3] = 4;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	expected[3] = 4;
	check_int_case("already sorted", values, 4, expected);
}

static void	check_reverse_sorted(void)
{
	int	values[4];
	int	expected[4];

	values[0] = 4;
	values[1] = 3;
	values[2] = 2;
	values[3] = 1;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	expected[3] = 4;
	check_int_case("reverse sorted", values, 4, expected);
}

static void	check_random_order(void)
{
	int	values[5];
	int	expected[5];

	values[0] = 5;
	values[1] = 3;
	values[2] = 4;
	values[3] = 1;
	values[4] = 2;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	expected[3] = 4;
	expected[4] = 5;
	check_int_case("random order", values, 5, expected);
}

static void	check_duplicates(void)
{
	int	values[5];
	int	expected[5];

	values[0] = 2;
	values[1] = 1;
	values[2] = 2;
	values[3] = 1;
	values[4] = 3;
	expected[0] = 1;
	expected[1] = 1;
	expected[2] = 2;
	expected[3] = 2;
	expected[4] = 3;
	check_int_case("duplicates", values, 5, expected);
}

static int	check_str_order(t_list *list, char **expected, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (list == NULL || list->data == NULL)
			return (0);
		if (ft_strcmp((char *)list->data, expected[i]) != 0)
			return (0);
		list = list->next;
		i++;
	}
	return (list == NULL);
}

static void	check_strings_with_ft_strcmp(void)
{
	char	*values[3];
	char	*expected[3];
	t_list	*head;

	values[0] = "banana";
	values[1] = "apple";
	values[2] = "cherry";
	expected[0] = "apple";
	expected[1] = "banana";
	expected[2] = "cherry";
	head = NULL;
	ft_list_push_front(&head, values[2]);
	ft_list_push_front(&head, values[1]);
	ft_list_push_front(&head, values[0]);
	ft_list_sort(&head, (int (*)())ft_strcmp);
	ft_test(check_str_order(head, expected, 3),
		"ft_list_sort() with ft_strcmp sorts strings alphabetically");
	free_list(head);
}

void	test_list_sort(void)
{
	printf("\n--- ft_list_sort ---\n");
	check_empty();
	check_single();
	check_already_sorted();
	check_reverse_sorted();
	check_random_order();
	check_duplicates();
	check_strings_with_ft_strcmp();
}
