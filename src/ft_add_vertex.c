/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:39:42 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:40:22 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_vertex	*ft_add_vertex_back(t_graph *graph, t_vertex *vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstd_wrap(vertex, sizeof(*vertex));
	ft_lstd_push_back((t_list**)&graph->vertex_list, new_vertex);
	graph->vertex_count++;
	return ((t_vertex *)new_vertex->content);
}
