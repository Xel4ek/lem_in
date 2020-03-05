#include "lem_in.h"
#include "libft.h"

t_path ft_new_path(t_vertex *path_head)
{
	t_path path;

	path.price = 0;
	path.head = path_head;
	path.ant_count = 0;
	while (path_head->id != 0)
	{
		path_head = (*(t_edge**)path_head->edge_out_list->content)->end;
		path_head = (*(t_edge**)path_head->edge_out_list->content)->end;
		++(path.price);
	}
	return (path);
}