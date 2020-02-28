/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:28 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 18:53:22 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int ft_clear_buf(char **buf)
{
	ft_memdel((void **)buf);
	return (-1);
}

int	ft_get_ants_count(t_map *map)
{
	int		nbr;
	char	*buf;

	buf = NULL;
	while (get_next_line(map->fd, &buf) && buf[0] == '#')
	{
		if  (!ft_strcmp(START, buf) || !ft_strcmp(END, buf))
			return (ft_clear_buf(&buf));
		ft_memdel((void **) &buf);
	}
	if (!buf)
		return (-1);
	if (!ft_strlen(buf))
		return (ft_clear_buf(&buf));
	nbr = ft_get_valid_nbr(buf);
	if (nbr > 0)
		ft_add_to_map(map, &buf, ft_strlen(buf));
	else
		ft_memdel((void **)&buf);
	return ((nbr <= 0) ? -1 : nbr);
}