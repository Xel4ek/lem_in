#include "libft.h"


t_list			*ft_queue_new(void *content)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = content;
	ptr->content_size = 0;
	ptr->next = ptr;
	ptr->prev = ptr;
	return (ptr);
}