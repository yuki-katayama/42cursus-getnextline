/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:55:58 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/06 21:54:41 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void				save_line_free(char **save)
{
	free(*save);
	*save = NULL;
}

static int				appendline_freesave(char **save, char **line)
{
	int			len;
	char		*tmp;

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
		save_line_free(&*save);
		return (READ_EOF);
	}
	return (READ);
}

static int				output(char **save, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *save == NULL)
	{
		if (*save != NULL)
		{
			*line = ft_strdup(*save);
			save_line_free(save);
		}
		else
			*line = ft_strdup("");
		return (READ_EOF);
	}
	else
		return (appendline_freesave(&*save, line));
}

int						get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*save;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0)
		return (READ_ERROR);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(save, buf);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (output(&save, line, ret));
}
