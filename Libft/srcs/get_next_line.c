/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:55:08 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/13 12:19:48 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*is_newline(char **st_line, char *buff, int fd)
{
	long	ret;
	char	*tmp;

	ret = 1;
	while (ret && (!(ft_strchr(*st_line, '\n'))))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		tmp = *st_line;
		if (!(*st_line = ft_strjoin(*st_line, buff)))
			return (NULL);
		free(tmp);
	}
	return (*st_line);
}

char	*fill_line(char **st_line)
{
	char	*good_line;
	char	*newline;
	char	*tmp;

	good_line = ft_strchr(*st_line, '\n');
	if (good_line)
	{
		if (!(newline = ft_strndup(*st_line, (size_t)(good_line - *st_line))))
			return (NULL);
		tmp = *st_line;
		if (!(*st_line = ft_strdup(good_line + 1)))
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	else if (!(newline = ft_strdup(*st_line)))
		return (NULL);
	if (!good_line)
	{
		free(*st_line);
		*st_line = NULL;
	}
	return (newline);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*st_line = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((st_line == NULL && (!(st_line = ft_strnew(0)))))
		return (-1);
	if (!(st_line = is_newline(&st_line, buff, fd)))
	{
		free(st_line);
		return (-1);
	}
	if (*st_line)
	{
		if (!(*line = fill_line(&st_line)))
		{
			free(st_line);
			return (-1);
		}
		return (1);
	}
	free(st_line);
	return (0);
}
