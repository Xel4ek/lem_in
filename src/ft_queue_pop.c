#include "lem_in.h"
#include "libft.h"

void	*ft_queue_pop(t_list **queue)
{
	t_list *ptr;
	void *item;

	item = NULL;
	if (queue && *queue)
	{
		ptr = *queue;
		if (ptr != (*queue)->next)
			ptr = (*queue)->next;
		else
			ptr = NULL;
		if (ptr != NULL)
		{
			ptr->prev = ptr->prev->prev;
			ptr->prev->next = ptr;
		}
		item = (*queue)->content;
		ft_memdel((void**)queue);
		(*queue) = ptr;
	}
	return item;
}

void	*ft_queue_min_pop(t_list **queue)
{
	t_list *ptr;
	t_list *min;
	void *item;

	item = NULL;
	if (queue && *queue)
	{
		int i;
		int temp;
		i = ft_lstdlen(*queue);
		min = *queue;
		while (i--)
		{
			(*queue) = (*queue)->next;
			temp =  (*((t_vertex **) (*queue)->content))->weight;
			if ( (*((t_vertex **)min->content))->weight > temp)
			{
				min = *queue;
			}

		}
		*queue = min;
		ptr = *queue;
		if (ptr != (*queue)->next)
			ptr = (*queue)->next;
		else
			ptr = NULL;
		if (ptr != NULL)
		{
			ptr->prev = ptr->prev->prev;
			ptr->prev->next = ptr;
		}
		item = (*queue)->content;
		ft_memdel((void**)queue);
		(*queue) = ptr;
	}
	return item;
}
