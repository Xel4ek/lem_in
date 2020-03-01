#include "libft.h"

void *ft_pop_min_heap(t_heap **heap, int *key)
{
	void* item;

	item = NULL;
	if (heap && *heap)
	{
		item = (*heap)->value;
		*key = (*heap)->key;
		(*heap) = ft_heap_merge((*heap)->left, (*heap)->right);
	}

	return item;
}