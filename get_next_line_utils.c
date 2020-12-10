/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:54:51 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/17 20:54:54 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	i = 0;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int c)
{
	size_t		length;
	size_t		i;

	i = 0;
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		length;
	size_t		i;
	char		*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1);
	length += ft_strlen(s2);
	if (!(dest = malloc(sizeof(char *) * (length))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(char *src)
{
	char	*dest;
	int		size;
	int		i;

	size = 0;
	while (src[size])
		size++;
	if (!(dest = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
