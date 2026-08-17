/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:37 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_sort.h"

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
	list_sort_check_case("duplicates", values, 5, expected);
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
	list_sort_check_empty();
	check_single();
	check_already_sorted();
	check_reverse_sorted();
	check_random_order();
	check_duplicates();
	check_strings_with_ft_strcmp();
}
