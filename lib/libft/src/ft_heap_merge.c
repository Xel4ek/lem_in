#include "libft.h"


static void ft_heap_swap(t_heap **first, t_heap **second){
	int key;
	unsigned int dist;
	int *value;
	key = (*first)->key;
	dist = (*first)->dist;
	value = (*first)->value;
	(*first)->key = (*second)->key;
	(*first)->dist = (*second)->dist;
	(*first)->value = (*second)->value;
	(*first)->content_size = (*second)->content_size;
	(*second)->key = key;
	(*second)->dist = dist;
	(*second)->value = value;
//	(*second)->content_size = temp->content_size;

}
static int ft_head_get_dist(t_heap *heap)
{
	return 0;
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
			ft_heap_swap(&first->left, &first->right);
	first->dist++;
	return first;

}