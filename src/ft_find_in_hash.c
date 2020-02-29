#include "libft.h"
#include "lem_in.h"

t_vertex *ft_find_vertex_in_hash(t_hash **hashtab, char *name)
{
	unsigned int 		i;
	t_hash 		*temp;
	t_vertex	*vertex;

	vertex = NULL;
	i = ft_hash(name, HASHTAB_SIZE);
	if (!hashtab[i])
		return (NULL);
	temp = hashtab[i];
	while (temp)
	{
		vertex = (t_vertex *)temp->content;
		if (!ft_strcmp(vertex->name, name))
			break ;
		temp = temp->next;
	}
	if (temp)
		return (vertex);
	return (NULL);
}

int		ft_find_edge_in_hash(t_hash **hash, char *name)
{
	unsigned int 		i;
	t_hash 		*temp;
	char 		*str;

	i = ft_hash(name, HASHTAB_SIZE);
	if (!hash[i])
		return (0);
	temp = hash[i];
	while (temp)
	{
		str = (char *)temp->content;
		if (!ft_strcmp(str, name))
			break ;
		temp = temp->next;
	}
	if (temp)
		return (1);
	return (0);
}