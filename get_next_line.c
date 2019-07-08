/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:18:08 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/08 15:18:32 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	next_line(char **buff, char **line)
{
	char	*shard;
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	shard = ft_strdup((char const*)*buff);
	while (i < (BUFF_SIZE + 1))
	{
		if (shard[i] == '\n' || nl)
		{
			shard[i] = '\0';
			nl = 1;
		}
		i++;
	}
	*line = ft_strjoin(*line, (char const*)shard);
	free(shard);
	*buff = ft_strcpy(*buff, (ft_strchr((char const*)*buff, '\n') + 1));
}

int		logic(char **buff, char **line)
{
	char	*temp;

	temp = *line;
	if (ft_strchr((char const*)*buff, '\n'))
	{
		next_line(buff, line);
		free(temp);
		return (1);
	}
	*line = ft_strjoin(*line, (char const*)*buff);
	free(temp);
	*buff[0] = '\0';
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	int				ret;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!buff)
		buff = ft_strnew(BUFF_SIZE + 1);
	*line = ft_strdup("");
	while (buff[0] != '\0')
	{
		if (logic(&buff, &*line) == 1)
			return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (logic(&buff, &*line) == 1)
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (*line[0] == '\0' || *line == NULL))
		return (0);
	return (1);
}
