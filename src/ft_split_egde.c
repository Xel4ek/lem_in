/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_egde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:53:37 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:53:58 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void ft_split_edge(t_edge **edge)
{
	t_edge *edge_ptr;

	if (*edge && !(*edge)->oriented)
	{
		edge_ptr = *edge;
		ft_add_edge(edge_ptr->start, edge_ptr->end, edge_ptr->flow, 1, 1);
		ft_add_edge(edge_ptr->end, edge_ptr->start, edge_ptr->flow, 1, 1);
		ft_remove_edge(edge);
	}
}

void ft_split_all_edges(t_vertex *vertex)
{
	size_t edge_count;

	edge_count = ft_lstdlen(vertex->edge_in_list);
	while (edge_count--)
	{
		ft_split_edge(((t_edge **)vertex->edge_in_list->content));
	}
}
