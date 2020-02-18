#include "lem_in.h"
#include "libft.h"

void ft_add_ant(t_path *path)
{
//	path->head->ant_id = ant_id;
	++(path->price);
	++(path->ant_count);
}