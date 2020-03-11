/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:43:02 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:26 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	ft_vertex_validate(char *src, char **name, char **point)
{
	int		vlen;
	char	*x;
	char	*y;

	if (*src == 'L' || *src == '#' || !*src || ft_strchr(src, '-'))
		return (-2);
	vlen = ft_char_in_str(src, ' ');
	if (vlen < 0)
		return (-2);
	*name = src;
	(*name)[vlen] = 0;
	*point = src + vlen + 1;
	x = *point;
	y = ft_strchr(*point, ' ');
	if (!y)
		return (-2);
	*y++ = 0;
	if (((ft_get_valid_nbr(x)) < 0) || ((ft_get_valid_nbr(y)) < 0))
		return (-1);
	*(--y) = ' ';
	return (1);
}

static int	ft_get_new_vertex(t_graph *graph, t_mem *mem, \
			t_set **vset, t_set **coords)
{
	t_vertex	*vertex;
	char		*name;
	char		*point;
	int			res;

	res = 1;
	if (ft_vertex_validate(mem->current, &name, &point) != 1)
		return (-2);
	vertex = ft_new_verex(name);
	vertex = ft_add_vertex_back(graph, vertex);
	if (!ft_set_insert_vertex(vset, vertex))
		res = -6;
	if (res > 0 && !ft_set_insert(coords, point))
		res = -5;
	*(--point) = ' ';
	return (res);
}

static int	ft_get_start_end(t_graph *graph, t_mem *mem, \
			t_set **vset, t_set **coords)
{
	int status;
	int	res;

	status = !(ft_strcmp(mem->current, START)) ? 0 : 1;
	status = !(ft_strcmp(mem->current, END)) ? -2 : status;
	if (status == 1)
		return (1);
	if (status == 0 && graph->source)
		return (-7);
	if (status == -2 && graph->sink)
		return (-7);
	if (!ft_get_next_pointer(mem))
		return (-8);
	res = ft_get_new_vertex(graph, mem, vset, coords);
	if (res > 0)
	{
		if (status == 0)
			graph->source = (t_vertex *)(graph->vertex_list->prev->content);
		if (status == -2)
			graph->sink = (t_vertex *)(graph->vertex_list->prev->content);
	}
	res = (res < 0) ? -8 : res;
	return (res);
}

int			ft_get_vertex(t_graph *graph, t_mem *mem, t_set **vset)
{
	t_set	*coords;
	int		id;
	int		err;

	coords = NULL;
	id = 2;
	err = -15;
	while (ft_get_next_pointer(mem) && (mem->current[0]) && \
			(mem->current[0] == '#' || ft_count_char(mem->current, ' ') == 2))
	{
		err = 1;
		if (mem->current[0] != '#')
		{
			err = ft_get_new_vertex(graph, mem, vset, &coords);
			id += 2;
		}
		else if (mem->current[1] == '#')
			err = ft_get_start_end(graph, mem, vset, &coords);
		if (err <= 0)
			break ;
	}
	ft_set_destroy(&coords);
	return (err);
}
