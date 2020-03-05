#include "libft.h"

t_set *ft_init_set(size_t size)
{
	t_set *set;
	if(!(set = (t_set*)malloc(sizeof(*set))))
		return (NULL);
	set->hashtab = ft_hash_init(size);
	set->size = 0;
	set->capacity = size;
	return (set);
}

void *ft_set_isexist(t_set *set, size_t key)
{
	t_hash *item;
	size_t index;

	index = key % set->capacity;
	if ((item = &set->hashtab[index])->value)
		while (item)
		{
			if (item->key == key)
				return (item->value);
			item = item->next;
		}
	return (NULL);
}

void *ft_set_get_value(t_set *set, char *value)
{
	return (ft_set_isexist(set, ft_hash(value, set->capacity).key));
}

static t_set *ft_set_cpy(t_set *src, t_set *dst)
{
	int i;
	t_hash hash;
	i = src->capacity;
	while(i--)
	{
		hash = src->hashtab[i];
		while (hash.value)
		{
			hash.index = hash.key % dst->capacity;
			ft_hash_insert(dst->hashtab, hash);
			dst->size++;
			if (hash.next)
				hash = *(hash.next);
			else
				break;
		}
	}
	return (dst);
}

t_set *ft_set_update(t_set *set)
{
	t_set *newset;

	if(!(newset = ft_init_set(set->capacity * 2)))
		return (NULL);
	ft_set_cpy(set, newset);
	ft_set_destroy(&set);
	return newset;
}

int ft_set_insert(t_set **set, char *name)
{
	t_hash item;

	if (*set == NULL && !(*set = ft_init_set(INITHASHSIZE)))
		return (-1);
	if ((*set)->capacity * 3 < (*set)->size * 4)
		*set = ft_set_update(*set);
	item = ft_hash(name, (*set)->capacity);
	if(!ft_set_isexist(*set, item.key))
	{
		(*set)->size++;
		return (ft_hash_insert((*set)->hashtab, item));
	}
	return (0);
}

void ft_set_destroy(t_set **set)
{
	if (set && *set)
	{
		ft_hash_destroy(&(*set)->hashtab, (*set)->capacity);
		ft_memdel((void**)set);
	}

}
