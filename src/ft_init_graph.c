/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:31 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:33 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_graph	*ft_init_graph(void)
{
	t_graph	*graph;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	graph->sink = NULL;
	graph->source = NULL;
	graph->vertex_list = NULL;
	graph->ants_count = 0;
	graph->pash_count = 0;
	graph->path_lenght = INT64_MAX;
	graph->vertex_count = 0;
	return (graph);
}
