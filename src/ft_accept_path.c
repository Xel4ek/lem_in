/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:54:36 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:54:55 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static size_t	ft_test_push_ants(const int *len, int size, int ant_count)
{
	int		i;
	size_t	price;
	size_t	sended_ants;

	i = 0;
	price = 0;
	sended_ants = 0;
	while (ant_count > sended_ants && ++i < size)
	{
		sended_ants += (len[i] - len[i - 1]) * i;
		price += (len[i] - len[i - 1]);
	}
	price += (size_t)ft_ceil_ll((double)(ant_count - sended_ants) / (double)i);
	price += (size_t)len[0];
	return (price);
}

int				ft_accept_path(t_graph *graph)
{
	int		*len;
	int		count;
	size_t	index;
	t_list	*list;

	index = 0;
	if(!(len = (int*)malloc(sizeof(*len) * graph->pash_count)))
		return (0);
	list = graph->sink->edge_out_list;
	count = ft_lstdlen(graph->sink->edge_out_list);
	while (count--)
	{
		if ((*(t_edge **)list->content)->flow)
			len[index++] = ft_get_pash_len(graph, \
			(t_vertex *)(*(t_edge **)list->content)->end) / 2;
		list = list->next;
	}
	ft_quick_sort(len, len + graph->pash_count - 1);
	index = ft_test_push_ants(len, graph->pash_count, graph->ants_count);
	ft_memdel((void**)&len);
	if (index > graph->path_lenght)
		return (0);
	graph->path_lenght = index;
	return (1);
}
