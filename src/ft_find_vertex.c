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

int			ft_check_start_end(t_graph *graph)
{
	t_list		*list;
	t_list		*head;
	t_vertex	*vertex;

	list = (t_list *)graph->vertex_list;
	head = NULL;
	while (list && list != head && !(graph->sink && graph->source))
	{
		vertex = (t_vertex *)list->content;
		if (vertex->id == 0)
			graph->source = vertex;
		if (vertex->id == -2)
			graph->sink = vertex;
		if (!head)
			head = list;
		list = list->next;
	}
	if (!graph->sink || !graph->source)
		return (0);
	return (1);
}

t_vertex	*ft_find_vertex_by_id(t_graph *graph, int id)
{
	t_list		*list;
	t_list		*head;
	t_vertex	*vertex;

	list = (t_list *)graph->vertex_list;
	head = NULL;
	while (list && list != head)
	{
		vertex = (t_vertex *)list->content;
		if (vertex->id == id)
			return (vertex);
		if (!head)
			head = list;
		list = list->next;
	}
	return (NULL);
}
