/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:56:08 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/11 23:36:27 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	printf("%zu\n", ft_strlen("Hello World"));
	return (0);
}
