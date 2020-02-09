/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:12:19 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:31:11 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char		*ft_replace(char *str, int c)
{
	while (*str != c)
	{
		if (*str == 0)
			return (str);
		++str;
	}
	*str = 0;
	return (str + 1);
}

static int		get_new_line(char **line, t_forward_list **ptr)
{
	char *temp;

	if (*(char*)(*ptr)->content)
	{
		temp = ft_strdup(ft_replace((*ptr)->content, '\n'));
		*line = ft_strdup((*ptr)->content);
		ft_memdel(&(*ptr)->content);
		(*ptr)->content = (void*)temp;
		return (1);
	}
	ft_memdel(&(*ptr)->content);
	ft_memdel((void**)ptr);
	*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char					buf[BUFF_SIZE + 1];
	int						ret;
	static t_forward_list	*ptr[MAX_FD];
	char					*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (ptr[fd] == NULL || ptr[fd]->content == NULL)
		ptr[fd] = ft_lstnew("", 1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strjoin(ptr[fd]->content, buf);
		free(ptr[fd]->content);
		ptr[fd]->content = tmp;
		if (ft_strchr(ptr[fd]->content, '\n'))
			break ;
	}
	return (get_new_line(line, ptr + fd));
}
