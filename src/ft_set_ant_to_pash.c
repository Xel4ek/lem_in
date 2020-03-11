/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ant_to_pash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:52:29 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:52:57 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "lem_in.h"

long int	ft_set_ant_to_pash(size_t total_ant, t_path *path_list, \
			int pash_count)
{
	int			i;
	long int	price;
	size_t		sended_ants;

	price = 0;
	sended_ants = 0;
	i = 0;
	while (total_ant > sended_ants && ++i < pash_count)
	{
		sended_ants += (path_list[i].price - path_list[i - 1].price) * i;
		price += (path_list[i].price - path_list[i - 1].price);
	}
	price += ft_ceil_ll((double)(total_ant - sended_ants) / (double)i);
	price += path_list[0].price;
	sended_ants = 0;
	while (i--)
	{
		path_list[i].ant_count = price - path_list[i].price;
		sended_ants += path_list[i].ant_count;
	}
	while (sended_ants-- != total_ant)
		path_list[++i].ant_count--;
	return (price);
}
