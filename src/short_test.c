#include "libft.h"
#include "lem_in.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

	int fd;
	char *line;
	t_mem *memory;
	size_t size;

	size = 1;
	if(!(memory = (t_mem*)malloc(sizeof(*memory))))
		return 0;
	if(!(memory->head = (char*)malloc(sizeof(char) * (size + 1))))
		return 0;
	memory->current = memory->head;
	memory->end = memory->current;
	memory->size = size;
	(*memory->current) = 0;
	fd = open("../four_ways", O_RDONLY);
//	fast_get_next_line(fd, &line, memory);
//	printf("%s\n", line );
//	fast_get_next_line(fd, &line, memory);
//	printf("%s\n", line );
//	fast_get_next_line(fd, &line, memory);
//	printf("%s\n", line );
//	fast_get_next_line(fd, &line, memory);
//	printf("%s\n", line );
//	fast_get_next_line(fd, &line, memory);
int temp;
temp  = 0;
	while (fast_get_next_line(fd, &line, memory) > 0)
	{
		temp += printf("%s\n", line);
	}
	write(1, memory->head, temp);
//	int len;
//    t_vertex **vertex;
//    t_graph *graph;
//    t_edge *edge;
//    t_heap *queue;
//    queue = NULL;
//	t_vertex *test;
//    graph = mygraph();
//	len = ft_lstdlen(graph->vertex_list);
//	while (len--)
//	{
//		ft_print_vertex((t_vertex *) graph->vertex_list->content);
//		graph->vertex_list = graph->vertex_list->next;
//	}
//	len = ft_lstdlen(graph->vertex_list);
//	while (len--)
//	{
//		vertex = (t_vertex**)&graph->vertex_list->content;
//		queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
//		graph->vertex_list = graph->vertex_list->prev;
//	}

//	vertex = (t_vertex**)&graph->vertex_list->next->content;
//	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
//	vertex = (t_vertex**)&graph->vertex_list->prev->content;
//	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));


//	((t_vertex*)graph->vertex_list->content)->weight = -1000;
//	vertex = (t_vertex**)&graph->vertex_list->prev->content;
//	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
//	ft_printf("---------------------\n");
//	int key;
//	while (queue)
//	{
//
//		test = *((t_vertex**)ft_pop_min_heap(&queue, &key));
//		ft_print_vertex(test);
//	}
//	test = *((t_vertex**)ft_pop_min_heap(&queue));
//	ft_print_vertex(test);
//	test = *((t_vertex**)ft_pop_min_heap(&queue));
//	ft_print_vertex(test);
//    ft_printf("vertex : %d\n", te);
//    ft_printf("size_t : %d\n", sizeof(size_t));
//    ft_printf(" int : %d\n", sizeof(int));
	return 0;
}