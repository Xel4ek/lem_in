#include <ft_printf.h>
#include "libft.h"
#include "lem_in.h"

static void ft_push_in_queue(t_list **queue, t_edge *edge)
{
	t_list **temp;

	temp = queue;
//	edge->end->weight += edge->cost;
//	edge->end->weight++;
	if (*queue == NULL)
		ft_lstd_push_back(queue, ft_queue_new(
				&edge->end));
	else if(((t_vertex*)(*queue)->content)->weight > edge->end->weight)
		ft_lstd_push_front(queue, ft_queue_new(
				&edge->end));
//	else if (((t_vertex*)(*queue)->prev->content)->weight < edge->end->weight)
//		ft_lstd_push_back(queue, ft_queue_new(
//				&edge->end));
	else
//	if (edge->flow)
//		ft_lstd_push_front(queue, ft_queue_new(
//				&edge->end));
//	else
		ft_lstd_push_back(queue, ft_queue_new(
				&edge->end));
}

// static void ft_push_in_queue(t_list **queue, t_vertex *vertex)
//{
//	(*(t_edge **) vertex->edge_out_list->content)->end->weight++;
//	if ((*(t_edge **) vertex->edge_out_list->content)->flow)
//		ft_lstd_push_front(queue, ft_queue_new(
//				&(*(t_edge **) vertex->edge_out_list->content)->end));
//	else
//		ft_lstd_push_back(queue, ft_queue_new(
//				&(*(t_edge **) vertex->edge_out_list->content)->end));
//}

void ft_reset_vertex_color(t_graph *graph)
{
	size_t graph_size;

	graph_size = graph->vertex_count;
	while (graph_size--)
	{
		((t_vertex *) graph->vertex_list->content)->color = white;
		((t_vertex *) graph->vertex_list->content)->parrent = NULL;
		graph->vertex_list = graph->vertex_list->next;
	}
}

void ft_add_implement_verses_in_queue( t_list **queue, t_vertex *vertex)
{
	size_t edge_count;
	t_vertex *current;

	edge_count = ft_lstdlen(vertex->edge_out_list);
	while (edge_count--)
	{
		if ((*(t_edge **) vertex->edge_out_list->content)->end->color == white)
		{
			current = (*(t_edge **) vertex->edge_out_list->content)->end;
			current->color = grey;
			current->parrent = vertex;
			ft_push_in_queue(queue, *(t_edge **) vertex->edge_out_list->content);
//			if ((*(t_edge **) vertex->edge_out_list->content)->flow)
//				ft_lstd_push_front(queue, ft_queue_new(
//						&(*(t_edge **) vertex->edge_out_list->content)->end));
//			else
//				ft_lstd_push_back(queue, ft_queue_new(
//						&(*(t_edge **) vertex->edge_out_list->content)->end));
		}
		vertex->edge_out_list = vertex->edge_out_list->prev;
	}

}
void ft_add_implement_verses_in_queue_bfs( t_list **queue, t_vertex *vertex)
{
	size_t edge_count;
	t_vertex *current;

	edge_count = ft_lstdlen(vertex->edge_out_list);
	while (edge_count--)
	{
		if ((*(t_edge **) vertex->edge_out_list->content)->end->color == white)
		{
			current = (*(t_edge **) vertex->edge_out_list->content)->end;
			current->color = grey;
			current->parrent = vertex;
			current->weight = vertex->weight + 1;
			ft_lstd_push_front(queue, ft_queue_new(
					&(*(t_edge **) vertex->edge_out_list->content)->end));
		}
		vertex->edge_out_list = vertex->edge_out_list->prev;
	}

}

void ft_ford_bellman(t_graph *graph)
{
	t_list *queue;
	t_vertex *current;

	ft_reset_vertex_color(graph);
	queue = NULL;
	current = graph->source;
	ft_lstd_push_back(&queue, ft_queue_new((t_vertex **) &current));
	current->color = grey;
	while (queue)
	{
		current = *((t_vertex **) ft_queue_pop(&queue));
		current->color = black;
		ft_add_implement_verses_in_queue_bfs(&queue, current);
	}
}


int ft_min_cost_flow(t_graph *graph)
{
	t_list *queue;
	t_vertex *current;

	ft_reset_vertex_color(graph);
	queue = NULL;
	current = graph->source;
	ft_lstd_push_back(&queue, ft_queue_new((t_vertex **) &current));
	current->color = grey;
	while (queue)
	{
		current = *((t_vertex **) ft_queue_pop(&queue));
		if (current == graph->sink)
		{
			while (current != graph->source)
			{
				ft_reverse_edge_vertex(current->parrent, current);
				current = current->parrent;
			}
			++(graph->pash_count);
			while (queue)
				ft_queue_pop(&queue);
			if (!ft_accept_path(graph))
			{
				current = graph->sink;
				while (current != graph->source)
				{
					ft_reverse_edge_vertex(current, current->parrent);
					current = current->parrent;
				}
				--(graph->pash_count);
				return 0;
			}
			return graph->pash_count;
		}
		current->color = black;
		ft_add_implement_verses_in_queue(&queue, current);
	}
	return 0;
}