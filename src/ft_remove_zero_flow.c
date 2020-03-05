/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_zero_flow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:51:16 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:51:43 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void ft_remove_zero_flow(t_graph *graph)
{
	int i;
	int j;
	t_vertex *vertex;

	i = graph->vertex_count;
	while (i--)
	{
		vertex = ((t_vertex *) graph->vertex_list->content);
		j = ft_lstdlen(vertex->edge_out_list);
		while (j--)
			if ((*((t_edge **) vertex->edge_out_list->content))->flow == 0)
				ft_remove_edge(((t_edge **) vertex->edge_out_list->content));
			else
				vertex->edge_out_list = vertex->edge_out_list->next;
		graph->vertex_list = graph->vertex_list->next;
	}
	i = graph->vertex_count;
	while (i--)
		if (!((t_vertex *) graph->vertex_list->content)->edge_out_list &&
			!((t_vertex *) graph->vertex_list->content)->edge_in_list)
			ft_remove_vertex(&graph,
							 (t_vertex **) &graph->vertex_list->content);
		else
			graph->vertex_list = graph->vertex_list->next;
}
