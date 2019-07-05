/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:21:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/05 10:48:28 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	
	//line = (char *)malloc(1);
	if (argc == 2)
	{
		fd = open(argv[1], 'r');
		get_next_line(fd, &line);
		ft_putstr(line);
	}
	return (0);
}
