#include <ft_printf.h>
#include "libft.h"
#include "lem_in.h"

void ft_reset_vertex_color(t_graph *graph)
{
	size_t graph_size;

	graph_size = graph->vertex_count;
	while (graph_size--)
	{
		((t_vertex*)graph->vertex_list->content)->color = white;
		((t_vertex*)graph->vertex_list->content)->parrent = NULL;
		graph->vertex_list = graph->vertex_list->next;
	}
}

void ft_add_implement_verses_in_queue(t_vertex *vertex, t_list **queue)
{
	size_t edge_count;
	t_vertex *current;

	edge_count = ft_lstdlen(vertex->edge_out_list);
	while (edge_count--)
	{
		if((*(t_edge **)vertex->edge_out_list->content)->end->color == white)
		{
			current = (*(t_edge **)vertex->edge_out_list->content)->end;
			current->color = grey;
			current->parrent = vertex;
			ft_lstd_push_back(queue, ft_queue_new(&(*(t_edge **)vertex->edge_out_list->content)->end));
		}
		vertex->edge_out_list = vertex->edge_out_list->next;
	}

}

int ft_graph_dfs(t_graph *graph, int target_id)
{
	t_list *queue;
	t_vertex *current;

	ft_reset_vertex_color(graph);
	queue = NULL;
	current = (t_vertex*)graph->vertex_list->content;

	ft_lstd_push_front(&queue, ft_queue_new((t_vertex**)&graph->vertex_list->content));
	current->color = grey;
	current->test = 1;
	while (queue)
	{
		current = *((t_vertex**)ft_queue_pop(&queue));
		if (current->id == target_id)
		{
			while(current->id)
			{
				ft_printf("%d -> ",current->id);
				current->test = 1;
				current = current->parrent;
			}
			ft_printf("\n");
			while (queue)
				ft_queue_pop(&queue);
			return 1;
		}
		current->color = black;
		ft_add_implement_verses_in_queue(current, &queue);
	}
	return 0;
}
/*
int ft_graph_bfs_keep(t_graph *graph, int target_id, int *const prev_pash_len, int *const path_id)
{
	t_list *queue;
	t_vertex *current;
	t_vertex *test;
	int count = 0;
	int i;
	double ok1 = (1e64);
	double ok2;
	ft_reset_vertex_color(graph);
	queue = NULL;
	i = ft_lstdlen(graph->vertex_list);
	while (i-- && ((t_vertex*)graph->vertex_list->content)->id != 0)
		graph->vertex_list = graph->vertex_list->next;
	current = (t_vertex*)graph->vertex_list->content;

	ft_lstd_push_back(&queue, ft_queue_new((t_vertex**)&graph->vertex_list->content));
	current->color = grey;
	i = 0;
	while (queue)
	{
		current = *((t_vertex**)ft_queue_pop(&queue));
		if (current->id == target_id)
		{
			test = current;
			while (test->id)
			{
				while (((t_vertex*)(*(t_edge**)test->edge_in_list->content)->start) != test->parrent)
					test->edge_in_list = test->edge_in_list->next;
				if ((*(t_edge**)test->edge_in_list->content)->flow) {
					i -= 3;
					count++;
				}
				++i;
				test = test->parrent;
			}
//			if (count)
//				i -= 2;
			ft_printf(GREEN"Renew egdes :%d\n"RESET, count);
			int test3;
			test3 = 0;
			if (*path_id != 0)
				ft_printf("need time %d (%d) {%f}  - ",
						  test3 = (*prev_pash_len   + graph->ants_count - 1), test3, ok1 = (double)test3 / (double)*path_id);


			(*prev_pash_len) += (i - 1) /2 ;
			(*path_id)++;

			int test2;

				ft_printf("%d (%d) {%f} \n",
			test2 = (*prev_pash_len  + graph->ants_count - 1), test2, ok2 = (double)test2 / (double)*path_id);
			if (*path_id == 16)
//			if (ok2 > ok1)
				return 0;
			while(current->id)
			{

				ft_reverse_edge_vertex(current->parrent, current, *path_id);
				current = current->parrent;
			}

			while (queue)
				ft_queue_pop(&queue);
			return --i;
		}
		current->color = black;
		ft_add_implement_verses_in_queue(current, &queue);
	}
	return 0;
}
*/
int ft_graph_bfs(t_graph *graph)
{
	t_list *queue;
	t_vertex *current;

	ft_reset_vertex_color(graph);
	queue = NULL;
	current = graph->source;
	ft_lstd_push_back(&queue, ft_queue_new((t_vertex**)&current));
	current->color = grey;
	while (queue)
	{
		current = *((t_vertex**)ft_queue_pop(&queue));
		if (current == graph->sink)
		{
			while(current != graph->source)
			{
				ft_reverse_edge_vertex(current->parrent, current, graph->pash_count);
				current = current->parrent;
			}
			(graph->pash_count)++;
			while (queue)
				ft_queue_pop(&queue);
			if(!ft_accept_path(graph))
			{
				current = graph->sink;
				while (current != graph->source)
				{
					ft_reverse_edge_vertex(current, current->parrent, graph->pash_count);
					current = current->parrent;
				}
				return 0;
			}
			return graph->pash_count;
		}
		current->color = black;
		ft_add_implement_verses_in_queue(current, &queue);
	}
	return 0;
}