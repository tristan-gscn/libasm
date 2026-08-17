/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:39 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SORT_H
# define LIST_SORT_H

# include "../tests.h"

void	free_list(t_list *list);
void	list_sort_check_case(const char *label, int *values, size_t n,
			int *expected);
void	list_sort_check_empty(void);
void	check_single(void);
void	check_already_sorted(void);
void	check_reverse_sorted(void);
void	check_random_order(void);

#endif
