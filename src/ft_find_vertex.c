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

t_vertex	*ft_find_vertex_by_coo(t_graph *graph, int x, int y)
{
	t_list		*list;
	t_list		*head;
	t_vertex	*vertex;

	list = (t_list *)graph->vertex_list;
	head = NULL;
	while (list && list != head)
	{
		vertex = (t_vertex *)list->content;
		if (vertex->x == x && vertex->y == y)
			return (vertex);
		if (!head)
			head = list;
		list = list->next;
	}
	return (NULL);
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

t_vertex	*ft_find_vertex_by_name(t_graph *graph, char *name)
{
	t_list		*list;
	t_list		*head;
	t_vertex	*vertex;

	list = (t_list *)graph->vertex_list;
	head = NULL;
	while (list && list != head)
	{
		vertex = (t_vertex *)list->content;
		if ((vertex->name)[0] == name[0] && (vertex->name)[1] == name[1])
		{
			if (!ft_strcmp(vertex->name, name))
				return (vertex);
		}
		if (!head)
			head = list;
		list = list->next;
	}
	return (NULL);
}