/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:47:55 by hwolf             #+#    #+#             */
/*   Updated: 2020/03/03 18:48:18 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void ft_print_egde(t_edge *edge){
	ft_printf("{(%d, %d), %2d, %d}",
			  edge->start->id,
			  edge->end->id,
			  edge->flow,
			  edge->oriented);
}

void ft_print_egde_fd(int fd, t_edge *edge){
		if (edge->flow)
			ft_printf_fd(fd, "\t\"%d %s\" -> \"%d %s\" [dir = forward color = \"green\"];\n",
						 edge->start->id,
						 edge->start->name,
						 edge->end->id,
						 edge->end->name);
		else
			ft_printf_fd(fd, "\t\"%d %s\" -> \"%d %s\";\n",
						 edge->start->id,
						 edge->start->name,
						 edge->end->id,
						 edge->end->name);
}

void ft_print_not_oriented_egde_fd(int fd, t_edge *edge){
	ft_printf_fd(fd, "\t\"%d %s\" -- \"%d %s\";\n",
				 edge->start->id,
				 edge->start->name,
				 edge->end->id,
				 edge->end->name);
}
