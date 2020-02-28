#include "libft.h"
#include "lem_in.h"
#include <unistd.h>

static char	*ft_str_copy(char *dst, const char *src, size_t len)
{
	ft_memcpy(dst, src, len + 1);
	return (dst + len);
}

void	ft_print_map(t_map *map)
{
	t_list	*next;
	t_list	*head;
	char 	*begin;
	char	*str;

	next = map->map;
	head = NULL;
	str = (char *)ft_memalloc(sizeof(char) * (map->size + 1));
	begin =  str;
	while (next && next != head)
	{
		str = ft_str_copy(str, (char *)next->content, next->content_size);
		str = ft_str_copy(str, "\n", 1);
		if (!head)
			head = next;
		next = next->next;
	}
	write(1, begin, map->size);
	write(1, "\n", 1);
	ft_memdel((void **)&begin);
	ft_lstd_del(&(map->map));
}