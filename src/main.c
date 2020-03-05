/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:54:36 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:54:55 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>

static void	ft_clear_all(t_mem **mem, t_graph **graph)
{
	if (mem && (*mem))
	{
		ft_memdel((void **)&(*mem)->head);
		ft_memdel((void **)mem);
	}
	if (graph && *graph)
		ft_del_graph(graph);
}

static void	ft_convert_graph(t_graph **graph)
{
	ft_convert_graph_to_oriented(graph);
	(*graph)->vertex_count = ft_lstdlen((*graph)->vertex_list);
	(*graph)->path_lenght = INT64_MAX;
	while (ft_min_cost_flow((*graph)))
		;
}

static long int	ft_find_path(t_graph *graph, t_path **path_list)
{
	long int tail;

	ft_remove_zero_flow(graph);
	*path_list = ft_new_path_list(graph);
//	temp = graph->pash_count;
//	while(temp--)
//		ft_printf("%d ", (*path_list)[temp].price);
	tail = ft_set_ant_to_pash(graph->ants_count, *path_list, graph->pash_count);
//	tail = 0;
//	pash_count = ft_lstdlen(*path_list);
//	while (pash_count--)
//	{
//		if (tail < ((t_path *)(*path_list)->content)->price && \
//			tail < ((t_path *)(*path_list)->content)->ant_count)
//			tail = ((t_path *)(*path_list)->content)->price;
//		*path_list = (*path_list)->next;
//	}
	return (tail);
}

static void	ft_print_path(t_path *path_list, t_graph *graph, long int  tail, \
			t_mem **mem)
{
	long int	temp;
	int	id;

	id = 0;
	temp = tail;
	ft_print_mem(mem);
	while (temp--)
	{
		ft_push_ant(path_list, graph, &id);
		ft_printf("\n");
	}
}

int			main(void)
{
	t_graph	*graph;
	t_path	*path_list;
	int		fd;
	t_mem	*memory;
	int		res;

	fd = 0;

	if (!(memory = ft_init_memory()))
		return (0);
	if ((res = ft_get_graph_2(&graph, memory, fd)) <= 0)
	{
		ft_clear_all(&memory, &graph);
		return (ft_print_error(res));
	}
	ft_convert_graph(&graph);
	if (!graph->pash_count)
	{
		ft_clear_all(&memory, &graph);
		return (ft_print_error(-13));
	}
//	res = ft_find_path(graph, &path_list);
	long int tail;
	tail = ft_find_path(graph, &path_list);
	ft_print_path(path_list, graph, tail, &memory);
	ft_del_graph(&graph);
	ft_memdel((void**)&path_list);
	return (0);
}
