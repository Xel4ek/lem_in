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
	int i;
	int graph_len;
//	graph = mygraph();
	fd = open("../input.txt", O_RDONLY);
//	fd = 0;
	graph = NULL;
	if (!ft_get_graph(&graph, fd))
		return (write(2, "Error\n", 6));
	close(fd);
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

	ft_printf("------------------------------\n");
	vertex = ((t_vertex *)graph->vertex_list->prev->content);
	ft_print_graph(graph);

	fd = open("../1.gv", O_CREAT | O_WRONLY | O_TRUNC);
	ft_save_digraph_as_dot(fd, graph);
	close(fd);
	temp = 0;
	while(ft_graph_bfs(graph, -2))
		++temp;
//	temp = ft_graph_dfs(graph, 8);

//	ft_reset_edge_oriented(graph);
//	ft_split_all_graph_edge(graph);
	ft_printf("--%d-----------------------------\n",temp);
//	residual
	ft_print_graph(graph);

	fd = open("../3.gv", O_CREAT | O_WRONLY | O_TRUNC);
	ft_save_digraph_as_dot(fd, graph);
	close(fd);



//	temp = ft_graph_dfs(graph, 10);

	ft_printf("--------------------------------\n");

//	ft_reverse_edge((t_edge **)((t_vertex*)graph->vertex_list->content)->edge_in_list->content);
//	ft_remove_edge((t_edge **)((t_vertex*)graph->vertex_list->content)->edge_in_list->content);
	graph_len = ft_lstdlen(graph->vertex_list);
	t_vertex *vertex1;
	t_vertex *vertex2;
	i = graph_len;
	while (i-- && ((t_vertex*)graph->vertex_list->content)->id != 3)
		graph->vertex_list = graph->vertex_list->next;
	vertex1 = (t_vertex*)graph->vertex_list->content;

	i = graph_len;
	while (i-- && ((t_vertex*)graph->vertex_list->content)->id != 0)
		graph->vertex_list = graph->vertex_list->next;
	vertex2 = (t_vertex*)graph->vertex_list->content;

//	ft_reverse_edge_vertex(vertex1, vertex2);

	i = graph_len;
	while (i-- && ((t_vertex*)graph->vertex_list->content)->id != 0)
		graph->vertex_list = graph->vertex_list->next;
	ft_print_graph(graph);
	fd = open("../4.gv", O_CREAT | O_WRONLY | O_TRUNC);

	ft_save_digraph_as_dot(fd, graph);

//	ft_reverse_edge(((t_vertex*)graph->vertex_list->next->next->content)->edge_in_list->content);
	i = graph_len;
	while (i--) {
		if (((t_vertex *)graph->vertex_list->content)->test)
			graph->vertex_list = graph->vertex_list->next;
		else
			ft_remove_vertex(&graph,(t_vertex**)&graph->vertex_list->content);
	}
	ft_print_graph(graph);
	fd = open("../5.gv", O_CREAT | O_WRONLY | O_TRUNC);

	ft_save_digraph_as_dot(fd, graph);


	close(fd);


	ft_printf("\nDone\n");
	return 0;
}
