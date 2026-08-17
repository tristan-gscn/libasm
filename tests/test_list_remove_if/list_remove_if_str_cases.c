/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_str_cases.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:34 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_remove_if.h"
#include <stdlib.h>

static void	free_noop(void *data)
{
	(void)data;
}

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
	char	*target;
	t_list	*head;

	values[0] = "banana";
	values[1] = "apple";
	values[2] = "cherry";
	expected[0] = "banana";
	expected[1] = "cherry";
	target = "apple";
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
	list_remove_if_check_empty();
	check_no_match();
	check_remove_all();
	check_remove_head();
	check_remove_tail();
	check_remove_middle();
	check_remove_adjacent_duplicates();
	check_remove_alternating();
	check_strings_with_ft_strcmp();
}
