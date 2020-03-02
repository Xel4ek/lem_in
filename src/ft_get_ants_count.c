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

int	ft_get_ants_count(t_mem *mem)
{
	int		nbr;

	while (ft_get_next_pointer(mem) && mem->current[0] == '#')
	{
		if  (!ft_strcmp(START, mem->current) || !ft_strcmp(END, mem->current))
			return (-1);
		ft_get_next_pointer(mem);
	}
	if (!(mem->current[0]))
		return (-1);
	nbr = ft_get_valid_nbr(mem->current);
	return ((nbr <= 0) ? -1 : nbr);
}