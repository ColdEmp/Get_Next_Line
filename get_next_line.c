/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:18:08 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/05 16:20:59 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char*	next_line(char *buff, char **line)
{
	char	*shard;
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	shard = strdup((char const*)buff);
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
	buff = (ft_strchr((char const*)buff, '\n') + 1);
	return (buff);
}

/*char*	logic(char *buff, char **line)
{
	char	*temp;

	temp = *line;
	if (ft_strchr((char const*)buff, '\n'))
	{
		buff = next_line(buff, line);
		free(temp);
		return (buff);
	}
	*line = ft_strjoin(*line, (char const*)buff);
	free(temp);
	return (buff);
}*/

int	get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = strdup("");
	/*if (buff[0] != '\0')
	{
		temp = *line;
		if (ft_strchr((char const*)buff, '\n'))
		{
			buff = next_line(buff, line);
			free(temp);
			return (1);
		}
		*line = ft_strjoin(*line, (char const*)buff);
		free(temp);
	}*/
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		temp = *line;
		if (ft_strchr((char const*)buff, '\n'))
		{
			buff = next_line(buff, line);
			free(temp);
			break ;
		}
		*line = ft_strjoin(*line, (char const*)buff);
		free(temp);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		return (0);
	return (1);
}


//str = "abduraghmaan";

//str[3];
//str = (*str+3);
