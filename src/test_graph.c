#include "lem_in.h"
#include "libft.h"

t_graph *mygraph(void)
{
	t_graph *graph;
	t_vertex	*vertex;
	t_edge *edge;

	if(!(graph = (t_graph*)malloc(sizeof(*graph))))
		return (NULL);
	graph->vertex_list = NULL;
	vertex = ft_new_verex(0,"zero");
	ft_add_vertex(graph, vertex);
	vertex = ft_new_verex(1,"one");
	ft_lstd_push_back(&graph->vertex_list , ft_lstdnew(vertex, sizeof(*vertex)));

	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 1, 0);

	vertex = ft_new_verex(2,"two");
	ft_lstd_push_back(&graph->vertex_list , ft_lstdnew(vertex, sizeof(*vertex)));
	vertex = ft_new_verex(3,"three");
	ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->next->content, 2, 0);
	ft_lstd_push_back(&graph->vertex_list , ft_lstdnew(vertex, sizeof(*vertex)));
	vertex = ft_new_verex(4,"four");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->prev->prev->content, 2, 0);
	ft_add_edge((t_vertex *)graph->vertex_list->next->next->content, (t_vertex *)graph->vertex_list->next->next->next->content, 2, 0);

	return (graph);
};