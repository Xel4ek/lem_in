#include "libft.h"
#include "lem_in.h"

void	ft_add_to_map(t_map *map, char **line, int size)
{
	t_list	*new;

	if (!(*line))
		return ;
	new = ft_lstd_wrap(*line, size);
	ft_lstd_push_back(&map->map, new);
	map->size += size + 1;
}