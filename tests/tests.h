#ifndef TESTS_H
# define TESTS_H

# include <stddef.h>
# include <stdio.h>

# define OK "\033[32mOK\033[0m"
# define KO "\033[31mKO\033[0m"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_test(int ok, const char *fmt, ...);
void	test_summary(void);

void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);

#endif
