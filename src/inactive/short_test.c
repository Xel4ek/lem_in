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

	t_set *set;
	set = NULL;
	t_vertex *vertex;
	char str[]="0";
	char str2[]="mi";
	vertex = ft_new_verex(12, "0 ");

	ft_printf("%d ",ft_set_insert_vertex(&set, vertex));
	ft_printf("size %d\n", set->size);
	vertex = ft_new_verex(13, "1");
	ft_print_vertex(ft_set_get_value(set, "0"));

	ft_printf("%d ",ft_set_insert_vertex(&set, vertex));
	ft_printf("size %d\n", set->size);
	ft_print_vertex(ft_set_get_value(set, "1"));
	ft_printf("%d ",ft_set_insert(&set, str2));
	ft_printf("size %d\n", set->size);
	ft_printf("value %s\n", ft_set_get_value(set, str2));

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