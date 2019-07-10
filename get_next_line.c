/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:35:25 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/10 16:23:05 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strapptoc(char *dst, char const *src, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && src[j] != c)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

int		logic(char **buff, char **line)
{
	if (ft_strchr((char const*)*buff, '\n'))
	{
		*line = ft_strapptoc(*line, (char const*)*buff, '\n');
		*buff = ft_strcpy(*buff, (ft_strchr((char const*)*buff, '\n') + 1));
		return (1);
	}
	*line = ft_strcat(*line, (char const*)*buff);
	*buff[0] = '\0';
	return (0);
}

void	multiple_fd(t_list **head, fd)
{

}

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	int				ret;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!buff)
		buff = ft_strnew(BUFF_SIZE + 1);
	*line = ft_strnew(250000);
	while (buff[0] != '\0')
	{
		if (logic(&buff, &*line) == 1)
			return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (logic(&buff, &*line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (*line[0] == '\0'))
		return (0);
	return (1);
}
