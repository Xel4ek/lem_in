#include "libft.h"
#include "lem_in.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <ft_printf.h>

int main()
{
	t_graph *graph;
	int temp;
	int fd;
	int i;

	time_t total_t;
	time_t open_t;
	time_t read_t;
	time_t calc_t;
	time_t print_t;
	total_t = clock();
	open_t = clock();

//	fd = open("../checker/lemin-tools/maps/valid/map_jk_weird", O_RDONLY);
	fd = open("../checker/lemin-tools/maps/valid/big_sup/map_big_sup_17", O_RDONLY);
//	fd = open("../four_ways", O_RDONLY); //segfault //FIX
//	fd = open("../three_ways", O_RDONLY); //segfault // FIX
//	fd = open("../checker/lemin-tools/maps/valid/map_loop", O_RDONLY); //strange output
//	fd = open("../10K.map", O_RDONLY);
//	fd = open("../10k_432", O_RDONLY);
//	fd = 0;
	graph = NULL;
	t_map 	map;
	t_list	*maphead;
	map.map = NULL;
	map.size = 0;
	map.fd = fd;
	open_t = clock() - open_t;
	read_t = clock();
	if (!ft_get_graph(&graph, &map))
		return (ft_printf(RED"Error"RESET"\n"));
	close(fd);
	graph->sink_id = -2;
	graph->source_id = 0;

	read_t = clock() - read_t;
	calc_t = clock();
//		fd = open("../1.gv", O_CREAT | O_RDWR | O_TRUNC );
//		ft_save_graph_as_dot(fd, graph);
//		close(fd);
	ft_convert_graph_to_oriented(&graph);
//		fd = open("../2.gv", O_CREAT | O_RDWR | O_TRUNC );
//		ft_save_digraph_as_dot(fd, graph);
//		close(fd);
	graph->pash_count = 0;
	graph->vertex_count = ft_lstdlen(graph->vertex_list);
	graph->path_lenght = graph->vertex_count + graph->ants_count + 1;

	while (ft_min_cost_flow(graph))
		;
//	ft_printf("path %d - path_length : %d\n",graph->pash_count, graph->path_lenght);
	if (!graph->pash_count) {
		ft_printf(RED"Error"RESET"\n");
		return (0);
	}
	int j;
	i = graph->vertex_count;

	while (i--)
	{
		j = ft_lstdlen(
				((t_vertex *) graph->vertex_list->content)->edge_out_list);
		while (j--)
		{
			if((*((t_edge**)((t_vertex *) graph->vertex_list->content)->edge_out_list->content))->flow == 0)
				ft_remove_edge(((t_edge**)((t_vertex *) graph->vertex_list->content)->edge_out_list->content));
			else
				((t_vertex *) graph->vertex_list->content)->edge_out_list = ((t_vertex *) graph->vertex_list->content)->edge_out_list->next;

		}
		graph->vertex_list = graph->vertex_list->next;
	}
	i = graph->vertex_count;
	while (i--)
	{
		if(((t_vertex*)graph->vertex_list->content)->edge_out_list == NULL && ((t_vertex*)graph->vertex_list->content)->edge_in_list == NULL)
			ft_remove_vertex(&graph, (t_vertex**)&graph->vertex_list->content );
		else
			graph->vertex_list = graph->vertex_list->next;
	}

	t_list *path_list;
	path_list =  ft_new_path_list(graph);

	temp = 0;
	int tail;
	ft_set_ant_to_pash(graph->ants_count, path_list);
	tail = 0;
	int pash_count;
	int total = 0;
	int total_price = 0;
	pash_count = ft_lstdlen(path_list);
	int temp1;
	temp1= 0;
	while (pash_count--)
	{
//		ft_printf("push %d - count %d - price - %d diff %d\n", ++temp,
//				((t_path *)path_list->content)->ant_count, ((t_path *)path_list->content)->price,
//				  ((t_path *)path_list->content)->price - ((t_path *)path_list->content)->ant_count);
//		temp1 +=((t_path *)path_list->content)->price - ((t_path *)path_list->content)->ant_count;
		if (tail < ((t_path *)path_list->content)->price && tail < ((t_path *)path_list->content)->ant_count)
			tail = ((t_path *)path_list->content)->price;
//		total += ((t_path *)path_list->content)->ant_count;
//		total_price += ((t_path *)path_list->content)->price;
		path_list = path_list->next;
	}
//	ft_printf("total diff : %d - price %d\n",temp1, total_price);
	int id = 0;
	calc_t = clock() - calc_t;
	print_t = clock();
//	temp = 0;
	ft_print_map(&map);

	while (tail--)
	{
		temp++;
		ft_push_ant(path_list, graph, &id);
		ft_printf("\n");
	}

	ft_printf("steps :%d\n", temp);
	ft_printf("vertex: %d\n", (graph->vertex_count + 2)/2);
	ft_printf("open: \t%f s\n", (double) open_t / (double )CLOCKS_PER_SEC);
	ft_printf("read: \t%f s\n", (double) read_t /  (double )CLOCKS_PER_SEC);
	ft_printf("calc: \t%f s\n", (double) calc_t /  (double )CLOCKS_PER_SEC);
	print_t = clock() - print_t;
	ft_printf("print: \t%f s\n", (double) print_t /  (double )CLOCKS_PER_SEC);
	total_t = clock() - total_t;
	ft_printf(GREEN"total: \t%f s"RESET"\n",(double) total_t /  (double )CLOCKS_PER_SEC);
	ft_printf("diff: \t%f s\n",(double)(total_t - print_t -calc_t -read_t -open_t)/ (double)CLOCKS_PER_SEC);
	ft_del_graph(&graph);
	ft_lstd_del(&path_list);
	ft_printf(GREEN"\n\tDone\n"RESET);
	return 0;
}
