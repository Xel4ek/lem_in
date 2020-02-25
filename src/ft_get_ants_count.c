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

int	ft_get_ants_count(t_map *map)
{
	int		nbr;
	char	*buf;

	if (!get_next_line(map->fd, &buf))
		return (-1);
	nbr = ft_get_valid_nbr(buf);
	if (nbr > 0)
		ft_add_to_map(map, &buf, ft_strlen(buf));
	return ((nbr <= 0) ? -1 : nbr);
}