/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:41:59 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 18:47:13 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_delete_graph(t_graph **graph)
{
	t_vertex	*vertex;

	if (graph && *graph)
	{
		while ((*graph)->vertex_list)
		{
			vertex = (t_vertex *)((*graph)->vertex_list->content);
			ft_memdel((void **)&vertex->name);
			ft_remove_vertex(graph, &vertex);
		}
		free(*graph);
	}
}
