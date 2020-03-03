/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:40:47 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:41:12 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_vertex *ft_add_vertex_back(t_graph *graph, t_vertex *vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstd_wrap(vertex, sizeof(*vertex));
	ft_lstd_push_back((t_list**)&graph->vertex_list, new_vertex);
	return ((t_vertex *)new_vertex->content);
}
