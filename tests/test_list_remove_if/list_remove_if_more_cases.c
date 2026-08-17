/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_more_cases.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/17 03:02:33 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_remove_if.h"

void	check_remove_head(void)
{
	int				values[3];
	int				expected[2];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 2;
	expected[1] = 3;
	c.label = "remove head";
	c.values = values;
	c.n = 3;
	c.target = 1;
	c.expected = expected;
	c.expected_n = 2;
	list_remove_if_check_case(&c);
}

void	check_remove_tail(void)
{
	int				values[3];
	int				expected[2];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 2;
	c.label = "remove tail";
	c.values = values;
	c.n = 3;
	c.target = 3;
	c.expected = expected;
	c.expected_n = 2;
	list_remove_if_check_case(&c);
}

void	check_remove_middle(void)
{
	int				values[3];
	int				expected[2];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	expected[0] = 1;
	expected[1] = 3;
	c.label = "remove middle";
	c.values = values;
	c.n = 3;
	c.target = 2;
	c.expected = expected;
	c.expected_n = 2;
	list_remove_if_check_case(&c);
}

void	check_remove_adjacent_duplicates(void)
{
	int				values[4];
	int				expected[2];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 2;
	values[3] = 3;
	expected[0] = 1;
	expected[1] = 3;
	c.label = "adjacent duplicates";
	c.values = values;
	c.n = 4;
	c.target = 2;
	c.expected = expected;
	c.expected_n = 2;
	list_remove_if_check_case(&c);
}

void	check_remove_alternating(void)
{
	int				values[5];
	int				expected[2];
	t_remove_case	c;

	values[0] = 1;
	values[1] = 2;
	values[2] = 1;
	values[3] = 2;
	values[4] = 1;
	expected[0] = 2;
	expected[1] = 2;
	c.label = "alternating";
	c.values = values;
	c.n = 5;
	c.target = 1;
	c.expected = expected;
	c.expected_n = 2;
	list_remove_if_check_case(&c);
}
