#include "libft.h"
#include "lem_in.h"

t_vertex *ft_find_vertex_in_hash(t_hash **hashtab, char *name, unsigned int hash)
{
	unsigned int	i;
	t_hash			*temp;
	t_vertex		*vertex;

	vertex = NULL;
	i = hash;
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

int		ft_find_edge_in_hash(t_hash **hashtab, char *name, unsigned int hash)
{
	unsigned int	i;
	t_hash			*temp;
	char			*str;

	i = hash;
	if (!hashtab[i])
		return (0);
	temp = hashtab[i];
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

int		ft_find_coord_in_hash(t_hash **hashtab, t_coord *coord)
{
	unsigned int	i;
	t_hash			*temp;
	t_coord			*hashcoord;

	i = (coord->x + coord->y) % HASH_SIZE;
	if (!hashtab[i])
		return (0);
	temp = hashtab[i];
	while (temp)
	{
		hashcoord = (t_coord *)temp->cmp_ptr;
		if (hashcoord->x == coord->x && hashcoord->y == coord->y)
			break ;
		temp = temp->next;
	}
	if (temp)
		return (1);
	return (0);
}