/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:42:02 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/13 17:42:12 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
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

static void	check_single(void)
{
	t_list	*head;
	int		value;

	value = 42;
	head = NULL;
	ft_list_push_front(&head, &value);
	ft_test(head != NULL && head->data == &value && head->next == NULL,
		"push_front(NULL, &value) -> data=%p next=%p",
		head->data, (void *)head->next);
	free_list(head);
}

static void	check_order(void)
{
	t_list	*head;
	int		a;
	int		b;
	int		c;

	a = 1;
	b = 2;
	c = 3;
	head = NULL;
	ft_list_push_front(&head, &a);
	ft_list_push_front(&head, &b);
	ft_list_push_front(&head, &c);
	ft_test(ft_list_size(head) == 3,
		"push_front() x3 -> ft_list_size() = %u", ft_list_size(head));
	ft_test(head && head->data == &c
		&& head->next && head->next->data == &b
		&& head->next->next && head->next->next->data == &a
		&& head->next->next->next == NULL,
		"push_front() x3 keeps LIFO order (c -> b -> a)");
	free_list(head);
}

static void	check_null_data(void)
{
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, NULL);
	ft_test(head != NULL && head->data == NULL && head->next == NULL,
		"push_front(NULL, NULL) accepts NULL data");
	free_list(head);
}

void	test_list_push_front(void)
{
	printf("\n--- ft_list_push_front ---\n");
	check_single();
	check_order();
	check_null_data();
}
