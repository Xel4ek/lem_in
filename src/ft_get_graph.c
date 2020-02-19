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

int	ft_get_graph(t_graph **graph, int fd)
{
	char *buf;

	if (!(*graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	(*graph)->vertex_list = NULL;
	if (((*graph)->ants_count = ft_get_ants_count(fd)) == -1)
		return (0);
	if (!(buf = ft_get_vertex(*graph, fd)))
		return (0);
	if (!ft_strlen(buf))
	{
		ft_memdel((void **)&buf);
		return (0);
	}
	if (!ft_get_edges(*graph, buf, fd))
		return (0);
	return (1);
}
