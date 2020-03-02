#include "libft.h"

void *ft_pop_min_heap(t_heap **heap, int *key)
{
	void *item;
	t_heap *new_heap;

	if (!heap || !*heap)
		return NULL;
	item = (*heap)->value;
	*key = (*heap)->key;
	new_heap = ft_heap_merge((*heap)->left, (*heap)->right);
	ft_memdel((void**)heap);
	(*heap) = new_heap;
	return item;
}