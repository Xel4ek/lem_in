#include "libft.h"
#include "lem_in.h"

void ft_split_all_graph_edge(t_graph *graph) {
	size_t vertex_count;

	vertex_count = ft_lstdlen(graph->vertex_list);
	while (vertex_count--) {
		ft_split_all_edges((t_vertex *) graph->vertex_list->content);
		graph->vertex_list = graph->vertex_list->next;
	}
}