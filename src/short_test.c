#include "libft.h"
#include "lem_in.h"
#include <stdio.h>
int main()
{
	int len;
    t_vertex **vertex;
    t_graph *graph;
    t_edge *edge;
    t_heap *queue;
    queue = NULL;
	t_vertex *test;
    graph = mygraph();
	len = ft_lstdlen(graph->vertex_list);
	while (len--)
	{
		ft_print_vertex((t_vertex *) graph->vertex_list->content);
		graph->vertex_list = graph->vertex_list->next;
	}
	len = ft_lstdlen(graph->vertex_list);
	while (len--)
	{
		vertex = (t_vertex**)&graph->vertex_list->content;
		queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
		graph->vertex_list = graph->vertex_list->prev;
	}

//	vertex = (t_vertex**)&graph->vertex_list->next->content;
//	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
//	vertex = (t_vertex**)&graph->vertex_list->prev->content;
//	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));


	((t_vertex*)graph->vertex_list->content)->weight = -1000;
	vertex = (t_vertex**)&graph->vertex_list->prev->content;
	queue = ft_heap_add(queue, ft_wrap_heap((*vertex)->weight, vertex));
	ft_printf("---------------------\n");
	while (queue)
	{

		test = *((t_vertex**)ft_pop_min_heap(&queue));
		ft_print_vertex(test);
	}
//	test = *((t_vertex**)ft_pop_min_heap(&queue));
//	ft_print_vertex(test);
//	test = *((t_vertex**)ft_pop_min_heap(&queue));
//	ft_print_vertex(test);
//    ft_printf("vertex : %d\n", te);
//    ft_printf("size_t : %d\n", sizeof(size_t));
//    ft_printf(" int : %d\n", sizeof(int));
}