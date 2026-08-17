/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:28:05 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 15:33:54 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

static void	check_success(const char *s)
{
	int		fds[2];
	char	buf[256];
	ssize_t	ret;
	ssize_t	n;

	pipe(fds);
	ret = ft_write(fds[1], s, strlen(s));
	close(fds[1]);
	n = read(fds[0], buf, sizeof(buf));
	buf[n] = '\0';
	close(fds[0]);
	ft_test(ret == (ssize_t)strlen(s) && strcmp(buf, s) == 0,
		"ft_write(pipe, \"%s\") = %zd, read back \"%s\"", s, ret, buf);
}

static void	check_error(void)
{
	ssize_t	ret;
	int		err;

	errno = 0;
	ret = ft_write(-1, "x", 1);
	err = errno;
	ft_test(ret == -1 && err == EBADF,
		"ft_write(-1, \"x\") = %zd, errno = %d", ret, err);
}

void	test_write(void)
{
	printf("\n--- ft_write ---\n");
	check_success("");
	check_success("Hello World");
	check_error();
}
