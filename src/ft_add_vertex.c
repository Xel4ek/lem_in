#include "libft.h"
#include "lem_in.h"

t_vertex *ft_add_vertex_back(t_graph *graph, t_vertex *vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstd_wrap(vertex, sizeof(*vertex));
	ft_lstd_push_back((t_list**)&graph->vertex_list, new_vertex);
	return ((t_vertex *)new_vertex->content);
}
