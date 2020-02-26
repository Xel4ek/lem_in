#include "libft.h"
#include "lem_in.h"

t_vertex *ft_add_and_return_vertex_back(t_graph *graph, t_vertex **vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstdnew(*vertex, sizeof(t_vertex));
	ft_lstd_push_back((t_list**)&graph->vertex_list, new_vertex);
	ft_memdel((void **)vertex);
	return ((t_vertex *)new_vertex->content);
}

t_vertex *ft_add_and_return_vertex_front(t_graph *graph, t_vertex **vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstdnew(*vertex, sizeof(t_vertex));
	ft_lstd_push_front((t_list**)&graph->vertex_list, new_vertex);
	ft_memdel((void **)vertex);
	return ((t_vertex *)new_vertex->content);
}