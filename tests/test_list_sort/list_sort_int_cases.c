/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_int_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:38 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_sort.h"

void	list_sort_check_empty(void)
{
	t_list	*head;

	head = NULL;
	ft_list_sort(&head, NULL);
	ft_test(head == NULL, "ft_list_sort(NULL) leaves list empty");
}

void	check_single(void)
{
	int		value;
	int		expected[1];

	value = 42;
	expected[0] = 42;
	list_sort_check_case("single element", &value, 1, expected);
}

void	check_already_sorted(void)
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
	list_sort_check_case("already sorted", values, 4, expected);
}

void	check_reverse_sorted(void)
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
	list_sort_check_case("reverse sorted", values, 4, expected);
}

void	check_random_order(void)
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
	list_sort_check_case("random order", values, 5, expected);
}
