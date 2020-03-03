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
	if (!mem && !(*mem))
	{
		ft_memdel((void **)&(*mem)->head);
		ft_memdel((void **)mem);
	}
	if (!graph && !*graph)
		ft_del_graph(graph);
}

static void	ft_convert_graph(t_graph **graph)
{
	ft_convert_graph_to_oriented(graph);
	(*graph)->vertex_count = ft_lstdlen((*graph)->vertex_list);
	(*graph)->path_lenght = (*graph)->vertex_count + (*graph)->ants_count + 1;
	while (ft_min_cost_flow((*graph)))
		;
}

static int	ft_find_path(t_graph *graph, t_list **path_list)
{
	int	tail;
	int	pash_count;

	ft_remove_zero_flow(graph);
	*path_list = ft_new_path_list(graph);
	ft_set_ant_to_pash(graph->ants_count, *path_list);
	tail = 0;
	pash_count = ft_lstdlen(*path_list);
	while (pash_count--)
	{
		if (tail < ((t_path *)(*path_list)->content)->price && \
			tail < ((t_path *)(*path_list)->content)->ant_count)
			tail = ((t_path *)(*path_list)->content)->price;
		*path_list = (*path_list)->next;
	}
	return (tail);
}

static void	ft_print_path(t_list *path_list, t_graph *graph, int tail, \
			t_mem **mem)
{
	int	temp;
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
	t_list	*path_list;
	int		fd;
	t_mem	*memory;
	int		res;

	fd = 0;
	if (!(memory = ft_init_memory()))
		return (0);
	if ((res = ft_get_graph(&graph, memory, fd)) <= 0)
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
	res = ft_find_path(graph, &path_list);
	ft_print_path(path_list, graph, res, &memory);
	ft_del_graph(&graph);
	ft_lstd_del(&path_list);
	return (0);
}
