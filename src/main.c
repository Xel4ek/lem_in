/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:54:36 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/06 19:28:15 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_init(t_mem **memory, t_graph **graph)
{
	if (!(*memory = ft_init_memory()))
		return (0);
	if (!(*graph = ft_init_graph()))
	{
		ft_memdel((void **)&(*memory)->head);
		ft_memdel((void **)memory);
		return (0);
	}
	return (1);
}

static int	ft_free_alloceted(t_mem **mem, t_graph **graph, int err)
{
	if (mem && *mem)
	{
		ft_memdel((void **)&(*mem)->head);
		ft_memdel((void **)mem);
	}
	if (graph)
		ft_del_graph(graph);
	if (err < 0)
		ft_print_error(err);
	return (0);
}

static int	ft_search_optimal_ways(t_graph *graph)
{
	ft_convert_graph_to_oriented(graph);
	while (ft_min_cost_flow(graph))
		;
	ft_remove_zero_flow(graph);
	return (graph->pash_count);
}

static void	ft_output(t_graph *graph, t_mem *memory)
{
	t_path		*path_list;
	long int	tail;
	int			id;

	id = 0;
	path_list = ft_new_path_list(graph);
	tail = ft_set_ant_to_pash(graph->ants_count, path_list, graph->pash_count);
	ft_printf("%s\n", memory->head);
	while (tail--)
	{
		ft_push_ant(path_list, graph, &id);
		ft_printf("\n");
	}
	ft_memdel((void**)&path_list);
}

int			main(void)
{
	t_graph	*graph;
	t_mem	*memory;
	int		fd;
	int		res;

	fd = STDIN_FILENO;
	if (!(ft_init(&memory, &graph)))
		return (0);
	if ((res = ft_get_graph(graph, memory, fd)) <= 0)
		return (ft_free_alloceted(&memory, &graph, res));
	if (!ft_search_optimal_ways(graph))
		return (ft_free_alloceted(&memory, &graph, -13));
	ft_output(graph, memory);
	return (ft_free_alloceted(&memory, &graph, 0));
}
