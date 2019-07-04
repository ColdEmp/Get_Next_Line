/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:21:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/04 14:48:49 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
	}
	return (0);
}
