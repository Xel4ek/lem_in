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

static int ft_free_str(char **str)
{
	ft_memdel((void **)str);
	return (0);
}

int	ft_get_graph(t_graph **graph, int fd, char **map)
{
	char *buf;

	if (!(*graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	(*graph)->vertex_list = NULL;
	if (((*graph)->ants_count = ft_get_ants_count(fd, map)) == -1)
		return (ft_free_str(map));
	if (!(buf = ft_get_vertex(*graph, fd, map)))
		return (ft_free_str(map));
	if (!ft_strlen(buf))
		return (ft_free_str(&buf));
	if (!ft_get_edges(*graph, buf, fd, map))
		return (ft_free_str(map));
	return (1);
}
