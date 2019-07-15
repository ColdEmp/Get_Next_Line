/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:35:25 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/15 17:56:45 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcattoc(char *dst, char const *src, char c)
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
		*line = ft_strcattoc(*line, (char const*)*buff, '\n');
		*buff = ft_strcpy(*buff, (ft_strchr((char const*)*buff, '\n') + 1));
		return (1);
	}
	*line = ft_strcat(*line, (char const*)*buff);
	*buff[0] = '\0';
	return (0);
}

char	*multiple_fd_setup(t_list **head, int fd)
{
	t_list	*temp;

	if (!*head)
	{
		*head = ft_lstnew((ft_strnew(BUFF_SIZE + 1)),
				BUFF_SIZE + 1);
		(*head)->content_size = fd;
		(*head)->next = NULL;
	}
	temp = *head;
	while (temp->next)
	{
		if ((temp->content_size) == (size_t)fd)
			break ;
		temp = temp->next;
	}
	if (temp->content_size != (size_t)fd)
	{
		temp->next = ft_lstnew((ft_strnew(BUFF_SIZE + 1)),
				BUFF_SIZE + 1);
		temp = temp->next;
		temp->content_size = fd;
		temp->next = NULL;
	}
	return ((char*)(temp->content));
}

void	lstfree(t_list **list)
{
	t_list *temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free((void*)((*list)->content_size));
		free(*list);
		*list = NULL;
		*list = temp;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*buff;
	int				ret;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	buff = multiple_fd_setup(&head, fd);
	*line = ft_strnew(250000);
	while (buff[0] != '\0')
		if (logic(&buff, &*line) == 1)
			return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (logic(&buff, &*line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (*line[0] == '\0'))
	{
		//lstfree(&head);
		return (0);
	}
	return (1);
}
