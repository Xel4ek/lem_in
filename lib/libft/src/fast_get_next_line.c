/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:12:19 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:55:38 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_mem	*ft_realloc_mem(t_mem *memory, size_t dif)
{
	char	*new_memory;

	if (!(new_memory = (char*)malloc(((memory->size + dif) * 2 + 1) * \
	sizeof(char))))
		return (NULL);
	new_memory = ft_memcpy(new_memory, memory->head, memory->size + 1);
	memory->size = (memory->size + dif) * 2;
	memory->current = (memory->current - memory->head) + new_memory;
	memory->end = (memory->end - memory->head) + new_memory;
	memory->endl = (memory->endl - memory->head) + new_memory;
	ft_memdel((void**)&(memory->head));
	memory->head = new_memory;
	return (memory);
}

static char		*ft_strjoin_mem(t_mem *const memory, char *const string)
{
	long long int	dif;
	size_t			len;

	if (memory && string)
	{
		len = ft_strlen(string);
		dif = (long long int)(((memory->end - memory->head) + len) - \
		memory->size);
		if (dif > 0)
			if (!ft_realloc_mem(memory, dif))
				return (0);
		ft_memcpy(memory->end, string, len + 1);
		memory->end += len;
		return (memory->current);
	}
	return (NULL);
}

int				fast_get_next_line(const int fd, char **line, \
				t_mem *const memory)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		ft_strjoin_mem(memory, buf);
		if ((memory->endl = ft_strch(memory->current, '\n')))
			break ;
	}
	if (memory->endl)
	{
		*(memory->endl) = 0;
		*line = memory->current;
		memory->current = memory->endl + 1;
		memory->endl = ft_strchr(memory->current, '\n');
		return (1);
	}
	*line = NULL;
	return (0);
}

int				fast_read_in_memory(const int fd, t_mem *const memory)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		ft_strjoin_mem(memory, buf);
	}
	memory->current = NULL;
	return (0);
}
