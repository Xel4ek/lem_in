/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:29 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:46:51 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, int flow, int oriented,int cost){
	t_edge *ptr;

	if(!(ptr = (t_edge*)ft_memalloc(sizeof(t_edge))))
		return (NULL);
	ft_set_edge(ptr, start, end, flow, oriented, cost);
	return ptr;
}
