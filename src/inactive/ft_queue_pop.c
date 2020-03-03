#include "lem_in.h"
#include "libft.h"

void	*ft_queue_min_pop(t_list **queue)
{
	t_list *ptr;
	t_list *min;
	t_list *head;
	void *item;

	item = NULL;
	if (queue && *queue)
	{
		min = *queue;
		head = *queue;
		while (1)
		{
			(*queue) = (*queue)->next;
			if(*queue == head)
				break;
			if ((*((t_vertex **) min->content))->weight >
			(*((t_vertex **) (*queue)->content))->weight)
				min = *queue;
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
