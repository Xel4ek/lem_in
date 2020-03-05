/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:42:22 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:42:52 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void ft_del_graph(t_graph **graph)
{
	if (*graph)
		while((*graph)->vertex_list)
			ft_remove_vertex(graph,
					(t_vertex**)&(*graph)->vertex_list->content);
	ft_memdel((void**)graph);
}
