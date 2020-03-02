/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:54 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 19:03:44 by ayooden          ###   ########.fr       */
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

	if (fast_read_in_memory(fd, mem) < 0)
		return (0);
	mem->current = NULL;
	if (!(hptrs.vhash = ft_init_hash(HASH_SIZE)))
		return (0);
	if (!(*graph = ft_init_graph()))
		return (ft_delete_hashtab(hptrs.vhash, 0));
	hptrs.chash = NULL;
	if (((*graph)->ants_count = ft_get_ants_count(mem)) == -1)
		return (ft_clear_all(hptrs.vhash, 0));
	if (ft_get_vertex(*graph, mem, &hptrs))
		return (ft_clear_all(hptrs.vhash, 0));
	((*graph)->source) = NULL;
	((*graph)->sink) = NULL;
	if (!(mem->current[0]))
		return (ft_clear_all(hptrs.vhash, 0));
	if (!ft_check_start_end(*graph))
		return (ft_clear_all(hptrs.vhash, 0));
	if (!ft_get_edges(*graph, mem, hptrs.vhash))
		return (ft_clear_all(hptrs.vhash,  0));
	return (ft_clear_all(hptrs.vhash, 1));
}
