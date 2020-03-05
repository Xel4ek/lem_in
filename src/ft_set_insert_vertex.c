#include "libft.h"
#include "lem_in.h"

t_vertex *ft_set_get_vertex(t_set *set, char *value)
{
	return ((t_vertex *)ft_set_isexist(set, ft_hash(value, set->capacity).key));
}

int ft_set_insert_vertex(t_set **set, t_vertex *vertex)
{
	t_hash item;

	if (*set == NULL && !(*set = ft_init_set(INITHASHSIZE)))
		return (-1);
	if ((*set)->capacity * 3 < (*set)->size * 4)
		*set = ft_set_update(*set);
	item = ft_hash(vertex->name, (*set)->capacity);
	item.value = vertex;
	if(!ft_set_isexist(*set, item.key))
	{
		(*set)->size++;
		return (ft_hash_insert((*set)->hashtab, item));
	}
	return (0);
}