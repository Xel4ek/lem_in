#include "lem_in.h"
#include "libft.h"

t_path *ft_new_path(t_vertex *path_head)
{
	t_path *path;

	if(!(path = (t_path*)ft_memalloc(sizeof((*path)))))
		return (NULL);
	path->price = 0;
	path->head = path_head;
	path->ant_count = 0;
	while (path_head->id != -2)
	{
		path_head = (*(t_edge**)path_head->edge_in_list->content)->start;
		path_head = (*(t_edge**)path_head->edge_in_list->content)->start;
		++(path->price);
	}
	return (path);
}