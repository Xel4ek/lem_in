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

#include "lem_in.h"

int ft_set_ant_to_pash(int total_ant, t_list *path_list)
{
	t_path *path;
	int min_path;

	min_path = -1;
	while (total_ant--)
	{
		path = ft_find_shortest_path(path_list);
		if (min_path == -1)
			min_path = path->price;
		ft_add_ant(path);
	}
	return (min_path);
}
