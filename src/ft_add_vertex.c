#include "libft.h"
#include "lem_in.h"

void ft_add_vertex(t_graph *graph, t_vertex *vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstdnew(vertex, sizeof(*vertex));
	ft_lstd_push_back((t_list**)&graph->vertex_list, new_vertex);
}