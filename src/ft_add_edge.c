/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:39:42 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:40:22 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int	ft_add_edge(t_vertex *start, t_vertex *end, unsigned int param)
{
	t_edge *new_edge;
	t_list *new;

	if (!(new_edge = ft_new_edge(start, end, param)))
		return (0);
	new = ft_lstdnew(&new_edge, sizeof(t_edge *));
	if (start->edge_out_list)
		ft_lstd_push_back(&start->edge_out_list, new);
	else
		start->edge_out_list = new;
	new = ft_lstdnew(&new_edge, sizeof(t_edge *));
	if (end->edge_in_list)
		ft_lstd_push_back(&end->edge_in_list, new);
	else
		end->edge_in_list = new;
	return (1);
}
