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

/*
**  after 	param ^= 9u;
**	| param | flow |orient|  cost  |
**	|-------|------|------|--------|
**	|   0   | 0(1) | 0(0) | -1( 1) |
**	|   1   | 1(0) | 0(0) | -1( 1) |
**	|   2   | 0(1) | 1(1) | -1( 1) |
**	|   3   | 1(0) | 1(1) | -1( 1) |
**	|   4   | 0(1) | 0(0) |  0( 0) |
**	|   5   | 1(0) | 0(0) |  0( 0) |
**	|   6   | 0(1) | 1(1) |  0( 0) |
**	|   7   | 1(0) | 1(1) |  0( 0) |
**	|   8   | 0(1) | 0(0) |  1(-1) |
**	|   9   | 1(0) | 0(0) |  1(-1) |
**	|  10   | 0(1) | 1(1) |  1(-1) |
**	|  11   | 1(0) | 1(1) |  1(-1) |
**	|  12   | 0(1) | 0(0) |  0( 0) |
**	|  13   | 1(0) | 0(0) |  0( 0) |
**	|  14   | 0(1) | 1(1) |  0( 0) |
**	|  15   | 1(0) | 1(1) |  0( 0) |
**	|-------|------|------|--------|
*/

void	ft_set_edge(t_edge *const edge, t_vertex *const start, \
		t_vertex *const end, unsigned int param)
{
	edge->start = start;
	edge->end = end;
	edge->param = param;
	edge->flow = (int)(param & 1u);
	edge->oriented = (int)((param >> 1u) & 1u);
	edge->cost = ((int)((param >> 2u) & 3u) - 1) % 2;
}

t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, unsigned int param)
{
	t_edge *ptr;

	if (!(ptr = (t_edge*)ft_memalloc(sizeof(t_edge))))
		return (NULL);
	ft_set_edge(ptr, start, end, param);
	return (ptr);
}
