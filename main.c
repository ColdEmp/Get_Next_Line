/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:21:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/15 17:50:10 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	//int		fd;
	int		ret;
	int		i;
	char	*line;
	ft_putstr_fd(argv[0],2);
	i = 0;
	if (argc == 2)
	{
		//fd = open(argv[1], 'r');
		while ((ret=get_next_line(0, &line)) >= 0)
		{
			//ret = get_next_line(fd, &line);
			ft_putstr(line);
			ft_putchar('\n');
			ft_putstr("|| return is ");
			ft_putnbr(ret);
			ft_putstr(" ||\n");
			i++;
		}
	}
	while (1);
	return (0);
}
