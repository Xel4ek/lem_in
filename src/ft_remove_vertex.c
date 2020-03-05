/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:50:12 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:50:33 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void ft_remove_vertex(t_graph **graph, t_vertex **vertex){
	if(vertex && *vertex)
	{
		while ((*vertex)->edge_in_list)
			ft_remove_edge((t_edge**)(*vertex)->edge_in_list->content);
		while ((*vertex)->edge_out_list)
			ft_remove_edge((t_edge**)(*vertex)->edge_out_list->content);
		while (*vertex != (t_vertex*)(*graph)->vertex_list->content)
			(*graph)->vertex_list = (*graph)->vertex_list->next;
		ft_memdel((void**)&(*vertex)->name);
		ft_lstd_pop_front(&(*graph)->vertex_list);
		(*graph)->vertex_count--;
	}
}
