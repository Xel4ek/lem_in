/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_shortest_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:43:41 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:44:05 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_path *ft_find_shortest_path(t_list *path_list)
{
	size_t len;
	t_path *shortest_path;

	len = ft_lstdlen(path_list);
	shortest_path = (t_path *) path_list->content;
	while (len--)
	{
		if (((t_path *) path_list->content)->price < shortest_path->price)
			shortest_path = path_list->content;
		path_list = path_list->next;
	}
	return shortest_path;
}
