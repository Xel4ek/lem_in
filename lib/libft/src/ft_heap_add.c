#include "libft.h"

t_heap *ft_heap_add(t_heap *heap, t_heap *new_item)
{
	return ft_heap_merge(heap, new_item);
}