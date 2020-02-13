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
	vertex = ft_new_verex(2,"one");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 1, 0);
//	ft_add_edge((t_vertex *)graph->vertex_list->content, vertex, 1, 0);
	vertex = ft_new_verex(4,"two");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 1, 0);
	vertex = ft_new_verex(6,"three");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 1, 0);
	vertex = ft_new_verex(8,"four");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->content, (t_vertex *)graph->vertex_list->prev->content, 1, 0);
	vertex = ft_new_verex(10,"five");
	ft_add_vertex(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->prev->content, (t_vertex *)graph->vertex_list->prev->content, 1, 0);
//	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 1, 0);
	return (graph);
};
