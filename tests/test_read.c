/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:16:28 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 17:16:28 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

static void	check_read(const char *s)
{
	int		fds[2];
	char	buf[256];
	ssize_t	ret;

	pipe(fds);
	write(fds[1], s, strlen(s));
	close(fds[1]);
	memset(buf, 0, sizeof(buf));
	ret = ft_read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	ft_test(ret == (ssize_t)strlen(s) && strcmp(buf, s) == 0,
		"ft_read(pipe, \"%s\") = %zd, read \"%s\"", s, ret, buf);
}

static void	check_eof(void)
{
	int		fds[2];
	char	buf[8];
	ssize_t	ret;

	pipe(fds);
	close(fds[1]);
	ret = ft_read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	ft_test(ret == 0, "ft_read(empty pipe) = %zd (EOF expected)", ret);
}

static void	check_error(void)
{
	char	buf[8];
	ssize_t	ret;
	int		err;

	errno = 0;
	ret = ft_read(-1, buf, sizeof(buf));
	err = errno;
	ft_test(ret == -1 && err == EBADF,
		"ft_read(-1, ...) = %zd, errno = %d", ret, err);
}

void	test_read(void)
{
	printf("\n--- ft_read ---\n");
	check_read("");
	check_read("Hello World");
	check_eof();
	check_error();
}
