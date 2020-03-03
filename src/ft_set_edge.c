/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:53:10 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:53:30 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_edge(t_edge *const edge, t_vertex *const start, t_vertex *const end, int flow, int oriented, int cost){
	edge->start = start;
	edge->end = end;
	edge->flow = flow;
	edge->cost = cost;
	edge->oriented = oriented;
}
