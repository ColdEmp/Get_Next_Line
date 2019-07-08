/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:21:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/08 15:17:44 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], 'r');
		//while ((ret = get_next_line(fd, &line)) == 1)
		while (i < 8)
		{
			ret = get_next_line(fd, &line);
			ft_putstr(line);
			ft_putstr("\n|| return is ");
			ft_putnbr(ret);
			ft_putstr(" ||\n");
			i++;
		}
	}
	return (0);
}
