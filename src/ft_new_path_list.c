#include "lem_in.h"
#include "libft.h"

t_list * ft_new_path_list(t_graph *graph){
	t_list *path_list;
	t_path *new_path;
	t_vertex* vertex;
	path_list = NULL;
	int i;

	i = graph->vertex_count;
	while (((t_vertex*)graph->vertex_list->content)->id != 0 && i--)
		graph->vertex_list = graph->vertex_list->next;
	i = ft_lstdlen(((t_vertex *)graph->vertex_list->content)->edge_in_list);
	while (i--)
	{
		vertex = (*(t_edge**)(((t_vertex *)graph->vertex_list->content)->edge_in_list->content))->start;
		new_path = ft_new_path(vertex);
		ft_lstd_push_front(&path_list, ft_lstdnew(
				new_path, sizeof(t_path)));
		ft_memdel((void**)&new_path);
		((t_vertex *)graph->vertex_list->content)->edge_in_list = ((t_vertex *)graph->vertex_list->content)->edge_in_list->next;
	}
	return path_list;
}