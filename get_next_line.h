/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:53:35 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/11 15:49:36 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int	get_next_line(const int fd, char **line);
#endif
