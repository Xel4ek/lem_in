/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:48:50 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:49:13 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void ft_print_path(t_vertex *head, t_vertex *source)
{
	char *name;
	int *cur_id;
	if (head->ant_id)
		ft_printf("L%d-%s ", head->ant_id,
				  (*(t_edge **) head->edge_in_list->content)->start->name);
	while (head != source)
	{
		name = head->name;
		cur_id = &head->ant_id;
		head = (*(t_edge **) head->edge_out_list->content)->end;
		head = (*(t_edge **) head->edge_out_list->content)->end;
		if (head->ant_id)
			ft_printf("L%d-%s ", head->ant_id, name);
		*cur_id = head->ant_id;
	}
}

void ft_push_ant(t_path *path_list, t_graph *graph, int *id)
{
	size_t len;
	t_vertex *vertex;

	len = graph->pash_count;
	while (len--)
	{
		vertex = (t_vertex *) path_list[len].head;
		if (path_list[len].ant_count && graph->ants_count >= *id)
		{
			graph->source->ant_id = ++(*id);
			path_list[len].ant_count--;
		}
		else
			graph->source->ant_id = 0;
		ft_print_path(vertex, graph->source);
	}
}
