/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:54 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:44:29 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <unistd.h>

//static int ft_clear_all(t_hash_old **hashtab, int res)
//{
//	ft_delete_hashtab(hashtab, res);
//	return (res);
//}
//
//int			ft_get_graph(t_graph **graph, t_mem *mem, int fd)
//{
//	t_hptrs		hptrs;
//	int 		res;
//
//	if (fast_read_in_memory(fd, mem) < 0 )
//		return (-3);
//	if (mem->head[0] == 0)
//		return (-14);
//	if (!(hptrs.vhash = ft_init_hash(HASH_SIZE)))
//		return (0);
//	if (!(*graph = ft_init_graph()))
//		return (ft_delete_hashtab(hptrs.vhash, 0));
//	hptrs.chash = NULL;
//	if ((res = ft_get_ants_count(mem)) < 0)
//		return (ft_clear_all(hptrs.vhash, res));
//	(*graph)->ants_count = (long int)res;
//	if ((res = ft_get_vertex(*graph, mem, &hptrs)) <= 0)
//		return (ft_clear_all(hptrs.vhash, res));
//	if (!(mem->current[0]))
//		return (ft_clear_all(hptrs.vhash, -9));
//	if (!((*graph)->sink) || !((*graph)->source))
//		return (ft_clear_all(hptrs.vhash, -10));
//	if ((res = ft_get_edges(*graph, mem, hptrs.vhash)) <= 0)
//		return (ft_clear_all(hptrs.vhash,  res));
//	return (ft_clear_all(hptrs.vhash, 1));
//}

int			ft_get_graph_2(t_graph **graph, t_mem *mem, int fd)
{
	t_set	*vset;
	int 	res;

	vset = NULL;
	res = 1;
	if (fast_read_in_memory(fd, mem) < 0)
		return (-3);
	if (mem->head[0] == 0)
		return (-14);
	if (!(*graph = ft_init_graph()))
		res = 0;
	if (res > 0)
		res = ft_get_ants_count(mem);
	(*graph)->ants_count = res;
	if (res > 0)
		res = ft_get_vertex_2(*graph, mem, &vset);
	if (!((*graph)->sink && (*graph)->source) && res > 0)
		res = -10;
	if (!(mem->current[0]) && res > 0)
		res = -9;
	if (res > 0)
		res = ft_get_edges_2(mem, vset);
	ft_set_destroy(&vset);
	return (res);
}

