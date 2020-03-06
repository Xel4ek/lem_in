#include "libft.h"
#include "lem_in.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void ft_print_vertex(t_vertex *vertex)
{
	if (!vertex)
	{
		ft_printf("No vertex");
		return;
	}
	if (vertex->parrent)
		ft_printf("{%d, %s, parent: %d, color: %d, weight: %d}\n",
				  vertex->id,
				  vertex->name,
				  vertex->parrent->id,
				  vertex->color,
				  vertex->weight);
	else
		ft_printf("{%d, %s, parent: %d, color: %d, weight: %d}\n",
				  vertex->id,
				  vertex->name,
				  0,
				  vertex->color,
				  vertex->weight);

}


int main()
{

	unsigned int param;
	int flow;
	int cost;
	int oprient;
	int nflow;
	int ncost;
	int noprient;
	param = 8;
	/*
	*	| param | flow |orient|  cost  |
	*	|-------|------|------|--------|
	*	|   0   | 0(1) | 0(0) | -1( 0) |
	|*	|   1   | 1(1) | 0(0) | -1( 0) |
	|*	|   2   | 0(1) | 1(1) | -1( 0) |
	|*	|   3   | 1(1) | 1(1) | -1( 0) |
	|*	|   4   | 0(1) | 0(0) |  0( 0) |
	|*	|   5   | 1(1) | 0(0) |  0( 0) |
	|*	|   6   | 0(1) | 1(1) |  0( 0) |
	|*	|   7   | 1(1) | 1(1) |  0( 0) |
	|*	|   8   | 0(1) | 0(0) |  1(-1) |
	|*	|   9   | 1(1) | 0(0) |  1(-1) |
	|*	|  10   | 0(1) | 1(1) |  1(-1) |
	|*	|  11   | 1(1) | 1(1) |  1(-1) |
	|*	|  12   | 0(1) | 0(0) | -1(-1) |
	|*	|  13   | 1(1) | 0(0) | -1(-1) |
	|*	|  14   | 0(1) | 1(1) | -1(-1) |
	|*	|  15   | 1(1) | 1(1) | -1(-1) |
	|*	|-------|------|------|--------|
	*/
	flow = (int)(param & 1u);
	oprient = (int)((param >> 1u) & 1u);
	cost = (int)((param >> 1u) & 3u);

	printf("*\t| param | flow |orient|  cost  |\n");
	printf("*\t|-------|------|------|--------|\n");
	int i;
	i = 0;
	while (i < 16)
	{
		param = i++;
		printf("*\t| %3d   |", param);
		flow = (int) (param & 1u);
		oprient = (int) ((param >> 1u) & 1u);
		cost = ((int) ((param >> 2u) & 3u) - 1)  % 2;
		param ^= 9u;
//		param = param ^ (1 << 3);
////		param-=5;
		nflow = (int) (param  & 1u);
		noprient = (int) ((param >> 1u) & 1u);
		ncost = ((int) ((param >> 2u) & 3u) - 1)  % 2;

		printf(" %d(%d) |", flow, nflow);
		printf(" %d(%d) |", oprient, noprient);
//		printf(" %d%d(%d%d) |\n|", (cost>>1) &1 ,cost &1, (ncost>>1) &1,ncost &1 );
		printf(" %2d(%2d) |\n", cost ,ncost );
	}
	printf("*\t|-------|------|------|--------|\n");

//	printf(" %d", flow);
//	printf(" %d", flow);
//	printf(" %d", flow);

//	int fd;
//	char *line;
//	t_mem *memory;
//	size_t size;
//
//	size = 1;
//	if(!(memory = (t_mem*)malloc(sizeof(*memory))))
//		return 0;
//	if(!(memory->head = (char*)malloc(sizeof(char) * (size + 1))))
//		return 0;
//	memory->current = memory->head;
//	memory->end = memory->current;
//	memory->size = size;
//	(*memory->current) = 0;
//	fd = open("../four_ways", O_RDONLY);
////	fast_get_next_line(fd, &line, memory);
////	printf("%s\n", line );
////	fast_get_next_line(fd, &line, memory);
////	printf("%s\n", line );
////	fast_get_next_line(fd, &line, memory);
////	printf("%s\n", line );
////	fast_get_next_line(fd, &line, memory);
////	printf("%s\n", line );
////	fast_get_next_line(fd, &line, memory);
//int temp;
//temp  = 0;
//	while (fast_get_next_line(fd, &line, memory) > 0)
//	{
//		temp += printf("%s\n", line);
//	}
//	write(1, memory->head, temp);
////	int len;
////    t_vertex **vertex;
////    t_graph *graph;
////    t_edge *edge;
////    t_heap *queue;
////    queue = NULL;
////	t_vertex *test;
////    graph = mygraph();
////	len = ft_lstdlen(graph->vertex_list);
////	while (len--)
////	{
////		ft_print_vertex((t_vertex *) graph->vertex_list->content);
////		graph->vertex_list = graph->vertex_list->next;
////	}
////	len = ft_lstdlen(graph->vertex_list);
////	while (len--)
////	{
////		vertex = (t_vertex**)&graph->vertex_list->content;
////		queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
////		graph->vertex_list = graph->vertex_list->prev;
////	}
//
////	vertex = (t_vertex**)&graph->vertex_list->next->content;
////	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
////	vertex = (t_vertex**)&graph->vertex_list->prev->content;
////	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
//
//
////	((t_vertex*)graph->vertex_list->content)->weight = -1000;
////	vertex = (t_vertex**)&graph->vertex_list->prev->content;
////	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
////	ft_printf("---------------------\n");
////	int key;
////	while (queue)
////	{
////
////		test = *((t_vertex**)ft_pop_min_heap(&queue, &key));
////		ft_print_vertex(test);
////	}
////	test = *((t_vertex**)ft_pop_min_heap(&queue));
////	ft_print_vertex(test);
////	test = *((t_vertex**)ft_pop_min_heap(&queue));
////	ft_print_vertex(test);
////    ft_printf("vertex : %d\n", te);
////    ft_printf("size_t : %d\n", sizeof(size_t));
////    ft_printf(" int : %d\n", sizeof(int));
	return 0;
}