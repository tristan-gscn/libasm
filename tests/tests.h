#ifndef TESTS_H
# define TESTS_H

# include <stddef.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);

#endif
