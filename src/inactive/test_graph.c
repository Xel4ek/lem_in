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
	vertex->weight = 123;
	ft_add_vertex_back(graph, vertex);
	vertex = ft_new_verex(2,"one");
	vertex->weight = 456;
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 0, 0,1);
	vertex = ft_new_verex(4,"two");
	vertex->weight = -789;
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
	vertex = ft_new_verex(6,"three");
	vertex->weight = 12345;
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
	vertex = ft_new_verex(8,"four");
	vertex->weight = 75676;
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->prev->content, (t_vertex *)graph->vertex_list->prev->prev->prev->content, 0, 0,1);
	vertex = ft_new_verex(10,"five");
	vertex->weight = 65657;
	ft_add_vertex_back(graph, vertex);
	ft_add_edge((t_vertex *)graph->vertex_list->next->content, (t_vertex *)graph->vertex_list->prev->content, 0, 0,1);
    vertex = ft_new_verex(12,"six");
	vertex->weight = 14912803;
    ft_add_vertex_back(graph, vertex);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->prev->prev->content, 0, 0,1);
    vertex = ft_new_verex(-2,"seven");
	vertex->weight = -12;
    ft_add_vertex_back(graph, vertex);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->prev->prev->content, 0, 0,1);
    ft_add_edge((t_vertex *)graph->vertex_list->prev->content, (t_vertex *)graph->vertex_list->next->next->content, 0, 0,1);
//	ft_add_edge((t_vertex *)graph->vertex_list->content, (t_vertex *)graph->vertex_list->next->content, 1, 0);
	return (graph);
};
