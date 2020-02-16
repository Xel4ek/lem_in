#include "lem_in.h"
#include "libft.h"

void ft_reset_edge_oriented(t_graph *graph)
{
	size_t vertex_count;
	size_t edge_count;

	vertex_count = ft_lstdlen(graph->vertex_list);
	while (vertex_count--) {
		edge_count = ft_lstdlen(((t_vertex *) graph->vertex_list->content)->edge_in_list);
		while (edge_count--)
		{
			(*((t_edge **)((t_vertex *) graph->vertex_list->content)->edge_in_list->content))->oriented = 0;
			((t_vertex *) graph->vertex_list->content)->edge_in_list = ((t_vertex *) graph->vertex_list->content)->edge_in_list->next;
		}

//		edge_count = ft_lstdlen(((t_vertex *) graph->vertex_list->content)->edge_out_list);
//		while (edge_count--)
//		{
//			(*((t_edge **)((t_vertex *) graph->vertex_list->content)->edge_out_list->content))->oriented = 0;
//			((t_vertex *) graph->vertex_list->content)->edge_out_list = ((t_vertex *) graph->vertex_list->content)->edge_out_list->next;
//		}
		graph->vertex_list = graph->vertex_list->next;
	}
}