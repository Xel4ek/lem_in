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

static int	ft_free_map(t_map *map)
{
	if (map->map)
		ft_lstd_del(&(map->map));
	return (0);
}



static int ft_clear_all(t_hash **hashtab, t_map *map, char **buf, int res)
{
	if (res <= 0)
		ft_free_map(map);
	if (res < 0)
		ft_memdel((void **)buf);
	ft_delete_hashtab(hashtab, res);
	return (res <= 0 ? 0 : 1);
}

int			ft_get_graph(t_graph **graph, t_map *map)
{
	char 		*buf;
	t_hptrs		hptrs;

	if (!(hptrs.vhash = ft_init_hash(HASH_SIZE)))
		return (0);
	if (!(*graph = (t_graph *)malloc(sizeof(t_graph))))
		return (ft_delete_hashtab(hptrs.vhash, 0));
	hptrs.chash = NULL;
	(*graph)->vertex_list = NULL;
	if (((*graph)->ants_count = ft_get_ants_count(map)) == -1)
		return (ft_clear_all(hptrs.vhash, map, &buf, 0));
	if (!(buf = ft_get_vertex(*graph, map, &hptrs)))
		return (ft_clear_all(hptrs.vhash, map, &buf, 0));
	((*graph)->source) = NULL;
	((*graph)->sink) = NULL;
	if (!ft_check_start_end(*graph))
		return (ft_clear_all(hptrs.vhash, map, &buf,-1));
	if (!ft_strlen(buf))
		return (ft_clear_all(hptrs.vhash, map, &buf,-1));
	if (!ft_get_edges(*graph, buf, map, hptrs.vhash))
		return (ft_clear_all(hptrs.vhash, map, &buf, 0));
	return (ft_clear_all(hptrs.vhash, map, &buf, 1));
}
