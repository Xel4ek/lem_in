#include "lem_in.h"
#include "libft.h"

t_list *ft_new_path_list(t_graph *graph)
{
	t_list *path_list;
	t_path *new_path;
	t_vertex *vertex;
	int i;

	path_list = NULL;
	i = ft_lstdlen(graph->sink->edge_out_list);
	while (i--)
	{
		vertex = (*(t_edge **) (graph->sink->edge_out_list->content))->end;
		new_path = ft_new_path(vertex);
		ft_lstd_push_front(&path_list, ft_lstdnew(
				new_path, sizeof(t_path)));
		ft_memdel((void **) &new_path);
		graph->sink->edge_out_list =
				graph->sink->edge_out_list->next;
	}
	return path_list;
}