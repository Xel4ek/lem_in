/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:54:05 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:54:25 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_split_vertex(t_graph *graph)
{
	t_vertex	*new_vertex;
	t_vertex	*current;
	size_t		len;

	current = (t_vertex *)graph->vertex_list->content;
	if (current != graph->source && current != graph->sink)
	{
		new_vertex = ft_new_verex(current->name);
		new_vertex->edge_out_list = current->edge_out_list;
		new_vertex->edge_in_list = NULL;
		current->edge_out_list = NULL;
		len = ft_lstdlen(new_vertex->edge_out_list);
		ft_add_vertex_back(graph, new_vertex);
		new_vertex = (t_vertex *)graph->vertex_list->prev->content;
		while (len--)
		{
			(*(t_edge **)new_vertex->edge_out_list->content)->start =
					new_vertex;
			new_vertex->edge_out_list = new_vertex->edge_out_list->next;
		}
		ft_add_edge(current, new_vertex, 6);
	}
}
