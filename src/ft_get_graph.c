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

static int ft_clear_all(t_hash **hashtab, int res)
{
	ft_delete_hashtab(hashtab, res);
	return (res);
}

int			ft_get_graph(t_graph **graph, t_mem *mem, int fd)
{
	t_hptrs		hptrs;
	int 		res;

	if (fast_read_in_memory(fd, mem) < 0 )
		return (-3);
	if (mem->head[0] == 0)
		return (-14);
	if (!(hptrs.vhash = ft_init_hash(HASH_SIZE)))
		return (0);
	if (!(*graph = ft_init_graph()))
		return (ft_delete_hashtab(hptrs.vhash, 0));
	hptrs.chash = NULL;
	if ((res = ft_get_ants_count(mem)) < 0)
		return (ft_clear_all(hptrs.vhash, res));
	(*graph)->ants_count = (long int)res;
	if ((res = ft_get_vertex(*graph, mem, &hptrs)) <= 0)
		return (ft_clear_all(hptrs.vhash, res));
	if (!(mem->current[0]))
		return (ft_clear_all(hptrs.vhash, -9));
	if (!((*graph)->sink) || !((*graph)->source))
		return (ft_clear_all(hptrs.vhash, -10));
	if ((res = ft_get_edges(*graph, mem, hptrs.vhash)) <= 0)
		return (ft_clear_all(hptrs.vhash,  res));
	return (ft_clear_all(hptrs.vhash, 1));
}
