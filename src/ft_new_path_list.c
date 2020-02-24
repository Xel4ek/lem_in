#include "lem_in.h"
#include "libft.h"

t_list *ft_new_path_list(t_graph *graph)
{
	t_list *path_list;
	t_path *new_path;
	t_vertex *vertex;
	int i;

	path_list = NULL;
	i = ft_lstdlen(graph->source->edge_in_list);
	while (i--)
	{
		vertex = (*(t_edge **) (graph->source->edge_in_list->content))->start;
		new_path = ft_new_path(vertex);
		ft_lstd_push_front(&path_list, ft_lstdnew(
				new_path, sizeof(t_path)));
		ft_memdel((void **) &new_path);
		graph->source->edge_in_list =
				graph->source->edge_in_list->next;
	}
	return path_list;
}