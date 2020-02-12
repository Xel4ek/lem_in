#include "libft.h"
#include "lem_in.h"

int main()
{
	t_graph *graph;
	t_vertex *vertex;
	int temp;

	graph = mygraph();
	ft_print_graph(graph);
//	ft_split_edge((t_edge **)((t_vertex *)graph->vertex_list->prev->content)->edge_out_list->content);
//	ft_printf("--------------------------------\n");
//	ft_print_graph(graph);
//
//	ft_split_vertex(&graph,
//					(t_vertex **)&graph->vertex_list->prev->prev->content);
//	ft_printf("--------------------------------\n");
//	while (((t_vertex *)graph->vertex_list->content)->id != 0)
//		graph->vertex_list = graph->vertex_list->next;
	ft_convert_graph_to_oriented(&graph);
//	vertex = (t_vertex *)graph->vertex_list->next->next->content;
//	ft_printf("-With---------------------------\n");
//	ft_print_vertex(vertex);
	ft_printf("--------------------------------\n");
//	ft_split_all_edges(vertex);
	ft_print_graph(graph);
	ft_printf("--------------------------------\n");
	temp = ft_graph_dfs(graph, 7);
	ft_printf("-%d-----------------------------\n",temp);
	ft_print_graph(graph);

	ft_printf("\nDone\n");
	return 0;
}
