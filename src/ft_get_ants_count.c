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

int	ft_get_ants_count(int fd, char **map)
{
	int		nbr;
	char	*buf;

	if (!get_next_line(fd, &buf))
		return (-1);
	nbr = ft_get_valid_nbr(buf);
	ft_add_line(map, &buf);
	ft_memdel((void**)&buf);
	return ((nbr <= 0) ? -1 : nbr);
}