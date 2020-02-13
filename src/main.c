#include "libft.h"
#include "lem_in.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	t_graph *graph;
	t_vertex *vertex;
	int temp;
	int fd;

	graph = mygraph();
	ft_print_graph(graph);
	fd = open("../2.gv", O_CREAT | O_WRONLY | O_TRUNC);
	ft_save_graph_as_dot(fd, graph);
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

	while(((t_vertex*)graph->vertex_list->content)->id)
		graph->vertex_list = graph->vertex_list->next;
	temp = ft_graph_dfs(graph, 11);

	ft_printf("-%d-----------------------------\n",temp);
	vertex = ((t_vertex *)graph->vertex_list->prev->content);
	ft_print_graph(graph);

	fd = open("../1.gv", O_CREAT | O_WRONLY | O_TRUNC);
	ft_save_digraph_as_dot(fd, graph);
	close(fd);
	ft_printf("\nDone\n");
	return 0;
}
