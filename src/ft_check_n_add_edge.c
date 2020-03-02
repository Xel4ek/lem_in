#include "libft.h"
#include "lem_in.h"

static int 	ft_check_repeat(t_hash **edge_hash, t_vertex *v1, t_vertex *v2)
{
	int		res;
	char	*str1;
	char	*str2;

	str1 = ft_strjoin(v1->name, v2->name);
	str2 = ft_strjoin(v2->name, v1->name);
	res = 0;
	if (ft_find_edge_in_hash(edge_hash, str1, ft_hash(str1, HASH_SIZE)) && \
		!((v1->id == 0 && v2->id == -2) || (v1->id == -2 && v2->id == 0)))
		res = 1;
	if (ft_find_edge_in_hash(edge_hash, str2, ft_hash(str2, HASH_SIZE)) && \
		!((v1->id == 0 && v2->id == -2) || (v1->id == -2 && v2->id == 0)))
		res = 1;
	ft_memdel((void **)&str2);
	if (!res)
		ft_add_to_hash(edge_hash, (void *)str1, (void *)str1, \
		ft_hash(str1, HASH_SIZE));
	else
		ft_memdel((void **)&str1);
	return (res);
}

static int 	ft_clear_names(char **name1, char **name2, int res)
{
	ft_memdel((void **)name1);
	ft_memdel((void **)name2);
	return (res);
}

int			ft_check_n_add_edge(t_edgename *enames, t_hash **edge_hash, \
			t_hash **hashtab)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;

	if (!ft_strcmp(enames->name1, enames->name2))
		return (ft_clear_names(&(enames->name1), &(enames->name2), 1));
	if (!(vertex1 = ft_find_vertex_in_hash(hashtab, (void *)enames->name1, \
	ft_hash(enames->name1, HASH_SIZE))))
		return (ft_clear_names(&(enames->name1), &(enames->name2), 0));
	if (!(vertex2 = ft_find_vertex_in_hash(hashtab, (void *)enames->name2, \
	ft_hash(enames->name2, HASH_SIZE))))
		return (ft_clear_names(&(enames->name1), &(enames->name2), 0));
	if (ft_check_repeat(edge_hash, vertex1, vertex2))
		return (ft_clear_names(&(enames->name1), &(enames->name2), 1));
	ft_add_edge(vertex1, vertex2, 0, 0,1);
	return (ft_clear_names(&(enames->name1), &(enames->name2), 1));
}