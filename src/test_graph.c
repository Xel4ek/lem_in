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
	graph->ants_count = 12;
	vertex = ft_new_verex(0,"zero");
	ft_add_vertex_back(graph, vertex);
	vertex = ft_new_verex(2,"one");
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 0, 0,1);
	vertex = ft_new_verex(4,"two");
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
	vertex = ft_new_verex(6,"three");
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
	vertex = ft_new_verex(8,"four");
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->content, (t_vertex *)graph->vertex_list->prev->prev->prev->content, 0, 0,1);
	vertex = ft_new_verex(10,"five");
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
    vertex = ft_new_verex(12,"six");
    ft_add_vertex_back(graph, vertex);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->prev->prev->content, 0, 0,1);
    vertex = ft_new_verex(-2,"seven");
    ft_add_vertex_back(graph, vertex);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->prev->prev->content, 0, 0,1);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->next->next->content, 0, 0,1);
//	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 1, 0);
	return (graph);
};
