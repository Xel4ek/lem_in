/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:47:26 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:47:47 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_vertex *ft_new_verex(const int vertex_id, char* name){
	t_vertex *new_vertex;

	if(!(new_vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		return (NULL);
	if(!(new_vertex->name = (char*)ft_memalloc(ft_strlen(name) + 1)))
	{
		ft_memdel((void**)&new_vertex);
		return (NULL);
	}
	new_vertex->edge_in_list = NULL;
	new_vertex->edge_out_list = NULL;
	new_vertex->color = white;
	new_vertex->parrent = 0;
	new_vertex->weight = 0;
	new_vertex->potecial = 0;
	new_vertex->id = vertex_id;
	ft_strcpy(new_vertex->name, name);
	return (new_vertex);
}
