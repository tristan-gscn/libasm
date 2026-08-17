/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdlib.h>

static int	*new_int(int value)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = value;
	return (p);
}

static void	free_int_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->data);
		free(list);
		list = next;
	}
}

/*
** ft_list_remove_if() already frees the nodes it removes; this only frees
** what's left standing after a test. Data here is a string literal, not
** malloc'd, so unlike free_int_list() above it must not touch ->data.
*/
static void	free_str_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

static int	cmp_int(void *data, void *data_ref)
{
	return (*(int *)data - *(int *)data_ref);
}

static void	free_int(void *data)
{
	free(data);
}

static t_list	*build_int_list(int *values, size_t n)
{
	t_list	*head;
	size_t	i;

	head = NULL;
	i = n;
	while (i > 0)
	{
		i--;
		ft_list_push_front(&head, new_int(values[i]));
	}
	return (head);
}

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

static void	check_int_case(const char *label, int *values, size_t n,
	int target, int *expected, size_t expected_n)
{
	t_list	*head;
	int		ref;

	head = build_int_list(values, n);
	ref = target;
	ft_list_remove_if(&head, &ref, cmp_int, free_int);
	ft_test(ft_list_size(head) == (unsigned int)expected_n,
		"ft_list_remove_if(%s) keeps size = %u", label, expected_n);
	ft_test(check_int_order(head, expected, expected_n),
		"ft_list_remove_if(%s) leaves the right elements in order", label);
	free_int_list(head);
}

static void	check_empty(void)
{
	t_list	*head;
	int		ref;

	head = NULL;
	ref = 0;
	ft_list_remove_if(&head, &ref, cmp_int, free_int);
	ft_test(head == NULL, "ft_list_remove_if(NULL) leaves list empty");
}

static void	check_no_match(void)
{
	int	values[3];
	int	expected[3];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	check_int_case("no match", values, 3, 99, expected, 3);
}

static void	check_remove_all(void)
{
	int	values[3];

	values[0] = 5;
	values[1] = 5;
	values[2] = 5;
	check_int_case("remove all", values, 3, 5, NULL, 0);
}

static void	check_remove_head(void)
{
	int	values[3];
	int	expected[2];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 2;
	expected[1] = 3;
	check_int_case("remove head", values, 3, 1, expected, 2);
}

static void	check_remove_tail(void)
{
	int	values[3];
	int	expected[2];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 2;
	check_int_case("remove tail", values, 3, 3, expected, 2);
}

static void	check_remove_middle(void)
{
	int	values[3];
	int	expected[2];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 3;
	check_int_case("remove middle", values, 3, 2, expected, 2);
}

static void	check_remove_adjacent_duplicates(void)
{
	int	values[4];
	int	expected[2];

	values[0] = 1;
	values[1] = 2;
	values[2] = 2;
	values[3] = 3;
	expected[0] = 1;
	expected[1] = 3;
	check_int_case("adjacent duplicates", values, 4, 2, expected, 2);
}

static void	check_remove_alternating(void)
{
	int	values[5];
	int	expected[2];

	values[0] = 1;
	values[1] = 2;
	values[2] = 1;
	values[3] = 2;
	values[4] = 1;
	expected[0] = 2;
	expected[1] = 2;
	check_int_case("alternating", values, 5, 1, expected, 2);
}

static void	free_noop(void *data)
{
	(void)data;
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
	char	*expected[2];
	char	target[] = "apple";
	t_list	*head;

	values[0] = "banana";
	values[1] = "apple";
	values[2] = "cherry";
	expected[0] = "banana";
	expected[1] = "cherry";
	head = NULL;
	ft_list_push_front(&head, values[2]);
	ft_list_push_front(&head, values[1]);
	ft_list_push_front(&head, values[0]);
	ft_list_remove_if(&head, target, (int (*)())ft_strcmp, free_noop);
	ft_test(check_str_order(head, expected, 2),
		"ft_list_remove_if() with ft_strcmp removes the matching string");
	free_str_list(head);
}

void	test_list_remove_if(void)
{
	printf("\n--- ft_list_remove_if ---\n");
	check_empty();
	check_no_match();
	check_remove_all();
	check_remove_head();
	check_remove_tail();
	check_remove_middle();
	check_remove_adjacent_duplicates();
	check_remove_alternating();
	check_strings_with_ft_strcmp();
}
