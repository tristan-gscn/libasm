/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:56:08 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 14:52:58 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

#ifdef BONUS

static void	test_bonus(void)
{
	test_atoi_base();
	test_list_size();
}

#else

static void	test_bonus(void)
{
}

#endif

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	test_bonus();
	test_summary();
	return (0);
}
