#include "lem_in.h"
#include "libft.h"

t_list * ft_new_path_list(t_graph *graph){
	t_list *path_list;
	path_list = NULL;
	t_vertex* vertex;

	int i;

	i = graph->vertex_count;
	while (i-- && ((t_vertex*)graph->vertex_list->content)->id != 0)
		graph->vertex_list = graph->vertex_list->next;
	i = ft_lstdlen(((t_vertex *)graph->vertex_list->content)->edge_in_list);
	while (i--)
	{
		vertex = (*(t_edge**)(((t_vertex *)graph->vertex_list->content)->edge_in_list->content))->start;
		ft_lstd_push_front(&path_list, ft_lstdnew(
				ft_new_path(vertex), sizeof(t_path)));
		((t_vertex *)graph->vertex_list->content)->edge_in_list = ((t_vertex *)graph->vertex_list->content)->edge_in_list->next;
//		ft_printf("%d road len %d\n", j + 1, ((t_path *)path_list->content)->price);

	}
	return path_list;
}