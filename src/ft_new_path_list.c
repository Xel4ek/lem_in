/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_path_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:47:00 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:47:21 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	ft_pswap(t_path *first, t_path *second)
{
	t_path	temp;

	temp = *second;
	*second = *first;
	*first = temp;
}

static void	ft_psort_helper(t_path **pivot_left, \
			t_path **pivot_right, long int pivot)
{
	while (*pivot_left < *pivot_right)
	{
		while ((*pivot_left)->price < pivot)
			++(*pivot_left);
		while (pivot < (*pivot_right)->price)
			--(*pivot_right);
		if (*pivot_left <= *pivot_right)
		{
			if ((*pivot_left)->price > (*pivot_right)->price)
				ft_pswap(*pivot_left, *pivot_right);
			++(*pivot_left);
			--(*pivot_right);
		}
	}
}

static void	ft_psort(t_path *start, t_path *finish)
{
	t_path		*pivot_left;
	t_path		*pivot_right;
	long int	pivot;

	pivot_left = start;
	pivot_right = finish;
	if (pivot_left < pivot_right)
	{
		pivot = (start->price + finish->price) / 2;
		ft_psort_helper(&pivot_left, &pivot_right, pivot);
		if (pivot_left < finish)
			ft_psort(pivot_left, finish);
		if (start < pivot_right)
			ft_psort(start, pivot_right);
	}
}

t_path		*ft_new_path_list(t_graph *graph)
{
	t_path		*path_list;
	t_vertex	*vertex;
	int			i;

	if (!(path_list = (t_path*)malloc(graph->pash_count * sizeof(*path_list))))
		return (NULL);
	i = graph->pash_count;
	while (i--)
	{
		vertex = (*(t_edge **)(graph->sink->edge_out_list->content))->end;
		path_list[i] = ft_new_path(vertex, graph->source);
		graph->sink->edge_out_list =
				graph->sink->edge_out_list->next;
	}
	ft_psort(path_list, path_list + graph->pash_count - 1);
	return (path_list);
}
