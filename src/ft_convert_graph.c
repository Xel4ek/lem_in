/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_optimal_ways.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:41:43 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:42:05 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_convert_graph_to_oriented(t_graph *graph)
{
	size_t vertex_count;

	vertex_count = graph->vertex_count;
	while (vertex_count--)
	{
		ft_split_all_edges((t_vertex *)graph->vertex_list->content);
		graph->vertex_list = graph->vertex_list->next;
	}
	vertex_count = graph->vertex_count;
	while (vertex_count--)
	{
		ft_split_vertex(graph);
		graph->vertex_list = graph->vertex_list->next;
	}
}
