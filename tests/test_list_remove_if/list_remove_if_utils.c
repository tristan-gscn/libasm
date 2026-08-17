/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:36 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_remove_if.h"
#include <stdlib.h>

static int	*new_int(int value)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = value;
	return (p);
}

void	free_int_list(t_list *list)
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

int	cmp_int(void *data, void *data_ref)
{
	return (*(int *)data - *(int *)data_ref);
}

void	free_int(void *data)
{
	free(data);
}

t_list	*build_int_list(int *values, size_t n)
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
