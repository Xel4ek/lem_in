/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_edge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:51:55 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:52:16 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	ft_reverse_edge_vertex(t_vertex *start, t_vertex *end)
{
	size_t start_len;
	size_t end_len;
	size_t i;

	start_len = ft_lstdlen(start->edge_out_list);
	end_len = ft_lstdlen(end->edge_in_list);
	while (start_len--)
	{
		i = end_len;
		while (i--)
		{
			if (((t_vertex*)(*(t_edge**)end->edge_in_list->content)->start) ==
				start)
			{
				ft_add_edge(end, start,
					(((*(t_edge**)end->edge_in_list->content)->param ^ 9u)));
				ft_remove_edge(((t_edge**)end->edge_in_list->content));
				return ;
			}
			end->edge_in_list = end->edge_in_list->next;
		}
		start->edge_out_list = start->edge_out_list->next;
	}
}
