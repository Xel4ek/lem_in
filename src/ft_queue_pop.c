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
