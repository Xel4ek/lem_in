#include "lem_in.h"
#include "libft.h"

void ft_set_ant_to_pash(int total_ant, t_list *path_list)
{
	t_path *path;

	while (total_ant--)
	{
		path = ft_find_shortest_path(path_list);
		ft_add_ant(path);
	}
}