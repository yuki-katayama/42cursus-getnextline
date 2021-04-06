/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:57:15 by kyuki             #+#    #+#             */
/*   Updated: 2021/04/06 10:06:19 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_malloc_p(void **p, size_t len)
{
	*p = malloc(len);
	if (*p == NULL)
		return (0);
	return (1);
}

static void	update_save(char **save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buf);
	free(*save);
	*save = tmp;
}

static int	appendline_freesave(char **save, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		tmp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = tmp;
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (READ_EOF);
	}
	return (READ);
}

static int	output(char **save, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && save[fd] == NULL)
	{
		if (save[fd] != NULL)
		{
			*line = ft_strdup(save[fd]);
			free(save[fd]);
			save[fd] = NULL;
		}
		else
			*line = ft_strdup("");
		return (READ_EOF);
	}
	else
		return (appendline_freesave(&save[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*save[FOPEN_MAX];
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0)
		return (READ_ERROR);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret >= 0)
			buf[ret] = '\0';
		if (ret <= 0)
			break ;
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buf);
		else
			update_save(&save[fd], buf);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (output(save, line, ret, fd));
}
