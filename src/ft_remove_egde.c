/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_egde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:49:22 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:50:03 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void ft_remove_edge(t_edge **edge)
{
	t_edge *edge_ptr;
	edge_ptr = *edge;
	while(*(t_edge**)edge_ptr->start->edge_out_list->content != edge_ptr)
	{
		edge_ptr->start->edge_out_list = edge_ptr->start->edge_out_list->next;
	}
	while(*(t_edge**)edge_ptr->end->edge_in_list->content != edge_ptr)
	{
		edge_ptr->end->edge_in_list = edge_ptr->end->edge_in_list->next;
	}
	ft_lstd_pop_front(&edge_ptr->start->edge_out_list);
	ft_lstd_pop_front(&edge_ptr->end->edge_in_list);
	ft_memdel((void**)&edge_ptr);
}
