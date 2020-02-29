#include "libft.h"

void *ft_pop_min_heap(t_heap **heap)
{
	void* item;

	item = NULL;
	if (heap && *heap)
	{
		item = (*heap)->value;
		(*heap) = ft_heap_merge((*heap)->left, (*heap)->right);
	}
	return item;
}