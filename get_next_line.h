#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h> //read .

char *get_next_line(int fd);
// utils .
size_t	ft_strlen(const char *s);
int	ft_linelen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif