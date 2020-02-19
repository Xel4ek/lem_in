/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:12 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 18:48:51 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_vertex	*ft_find_vertex_by_id(t_graph *graph, int id)
{
	t_vertex	*vertex;
	int			i;

	i = ft_lstdlen(graph->vertex_list);
	while (i--)
	{
		vertex = (t_vertex *)graph->vertex_list->content;
		if (vertex->id == id)
			return (vertex);
		graph->vertex_list = graph->vertex_list->next;
	}
	return (NULL);
}

t_vertex	*ft_find_vertex_by_name(t_graph *graph, char *name)
{
	t_vertex	*vertex;
	int			i;

	i = ft_lstdlen(graph->vertex_list);
	while (i--)
	{
		vertex = (t_vertex *)graph->vertex_list->content;
		if (!ft_strcmp(vertex->name, name))
			return (vertex);
		graph->vertex_list = graph->vertex_list->next;
	}
	return (NULL);
}
