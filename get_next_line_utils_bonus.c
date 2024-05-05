/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:20:52 by kaokazak          #+#    #+#             */
/*   Updated: 2024/05/05 18:57:57 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_linelen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	len;
	int		res_i;
	int		s_i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res_i = 0;
	s_i = 0;
	while (s1[s_i] != '\0')
		res[res_i++] = s1[s_i++];
	s_i = 0;
	while (s2[s_i] != '\0')
		res[res_i++] = s2[s_i++];
	res[res_i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
