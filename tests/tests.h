/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:05:40 by trgascoi          #+#    #+#             */
/*   Updated: 2026/08/12 15:07:41 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>

# define OK "\033[32mOK\033[0m"
# define KO "\033[31mKO\033[0m"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);
int				ft_atoi_base(char *str, char *base);
unsigned int	ft_list_size(t_list *begin_list);
void			ft_list_push_front(t_list **begin_list, void *data);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));

void			ft_test(int ok, const char *fmt, ...);
void			test_summary(void);

void			test_strlen(void);
void			test_strcpy(void);
void			test_strcmp(void);
void			test_write(void);
void			test_read(void);
void			test_strdup(void);
void			test_atoi_base(void);
void			test_list_size(void);
void			test_list_push_front(void);
void			test_list_sort(void);
void			test_list_remove_if(void);

#endif
