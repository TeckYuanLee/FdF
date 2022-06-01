/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:28:12 by telee             #+#    #+#             */
/*   Updated: 2022/06/01 15:41:24 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_or_eof(char **line, char **str)
{
	char	*tmp;
	int		j;

	j = 0;
	while ((*str)[j] != '\n' && (*str)[j] != '\0')
		j++;
	if ((*str)[j] == '\n')
	{
		*line = ft_substr(*str, 0, j);
		tmp = ft_strdup((*str) + j + 1);
		free(*str);
		*str = tmp;
	}
	else if ((*str)[j] == '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	if (!(*str))
		return (0);
	return (1);
}

int	ft_joinstr(int fd, char **str, char **line)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		tmp = ft_strjoin(*str, buf);
		free(*str);
		*str = tmp;
		if (ft_strrchr(*str, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (i < 0)
	{
		free(*str);
		*str = 0;
		return (-1);
	}
	return (line_or_eof(line, str));
}

int	get_next_line(int fd, char **line)
{
	static char	*str;

	if (fd == -1 || !line)
		return (-1);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 1);
		if (str)
			str[0] = '\0';
	}
	return (ft_joinstr(fd, &str, line));
}
