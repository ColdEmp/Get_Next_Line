/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:21:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/18 13:40:24 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 3)
	{
		fd = open(argv[1], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		fd = open(argv[2], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		fd = open(argv[1], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		fd = open(argv[2], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
