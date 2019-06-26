/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:18:08 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/25 10:32:06 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_test(*str)
{
	int i;

	i = 0;
	while (str)
	{
		if (str[i] == "\n")
			return (i);
		i++;
	}
	return (-1);
}
//*ft_strchr(str, "\n");

int	end_test(*str)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (str[i] == "\0")
			retirn (i);
		i++;
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			ret;
	int			nl;
	
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	while (buff)
	{
		if (buff[j] == "\n")
			return (1);
		j
	}
//	if (read < BUFF_SIZE)
//		return (0);
//	if (read < 0)
//		return (-1);
}
