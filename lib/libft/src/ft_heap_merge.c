#include "libft.h"


static void ft_heap_swap(t_heap **first, t_heap **second)
{
	void *temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

static void ft_heap_swap_chield(t_heap *heap)
{
	void *temp;
	temp = heap->right;
	heap->right = heap->left;
	heap->left = temp;
}

t_heap *ft_heap_merge(t_heap *first, t_heap *second)
{
	if (!first)
		return second;
	if(!second)
		return first;
	if(second->key < first->key)
		ft_heap_swap(&first, &second);
	first->right = ft_heap_merge(first->right, second);
	if(first->right && first->left)
		if (first->right->dist > first->left->dist)
			ft_heap_swap_chield(first);
	first->dist++;
	return first;

}