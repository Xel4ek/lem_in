/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:52:29 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:52:57 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_path	ft_new_path(t_vertex *path_head, t_vertex *source)
{
	t_path path;

	path.price = 0;
	path.head = path_head;
	path.ant_count = 0;
	while (path_head != source)
	{
		path_head = (*(t_edge**)path_head->edge_out_list->content)->end;
		path_head = (*(t_edge**)path_head->edge_out_list->content)->end;
		++(path.price);
	}
	return (path);
}
