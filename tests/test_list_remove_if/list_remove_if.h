/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:35 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_REMOVE_IF_H
# define LIST_REMOVE_IF_H

# include "../tests.h"

typedef struct s_remove_case
{
	const char	*label;
	int			*values;
	size_t		n;
	int			target;
	int			*expected;
	size_t		expected_n;
}	t_remove_case;

void	free_int_list(t_list *list);
int		cmp_int(void *data, void *data_ref);
void	free_int(void *data);
t_list	*build_int_list(int *values, size_t n);

void	list_remove_if_check_case(t_remove_case *c);
void	list_remove_if_check_empty(void);
void	check_no_match(void);
void	check_remove_all(void);

void	check_remove_head(void);
void	check_remove_tail(void);
void	check_remove_middle(void);
void	check_remove_adjacent_duplicates(void);
void	check_remove_alternating(void);

#endif
