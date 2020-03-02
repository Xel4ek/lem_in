#include "libft.h"
#include "lem_in.h"

void ft_reset_vertex_color(t_graph *graph)
{
	size_t graph_size;

	graph_size = graph->vertex_count;
	while (graph_size--)
	{
		((t_vertex *) graph->vertex_list->content)->color = white;
		((t_vertex *) graph->vertex_list->content)->parrent = NULL;
		((t_vertex *) graph->vertex_list->content)->potecial +=
				((t_vertex *) graph->vertex_list->content)->weight;
		((t_vertex *) graph->vertex_list->content)->weight = INT32_MAX;
		graph->vertex_list = graph->vertex_list->next;
	}
}

static void ft_add_implement_verses_in_queue_heap( t_heap **queue, t_vertex *vertex)
{
	int edge_count;
	t_vertex *current;
	int weight;

	edge_count = ft_lstdlen(vertex->edge_out_list);
	while (edge_count--)
	{
		current = (*(t_edge **) vertex->edge_out_list->content)->end;
		if (current->color != black)
		{
			weight =  vertex->potecial - current->potecial +
					  vertex->weight + (*(t_edge **) vertex->edge_out_list->content)->cost;
			if (current->weight > weight)
			{
				current->weight = weight;
				current->parrent = vertex;
				*queue = ft_heap_add(*queue, ft_wrap_heap(current->weight, &(*(t_edge **) vertex->edge_out_list->content)->end));
			}
		}
		vertex->edge_out_list = vertex->edge_out_list->next;
	}
}

int ft_min_cost_flow(t_graph *graph)
{
	t_heap *queue;
	t_vertex *current;
	ft_reset_vertex_color(graph);
	int key;
	queue = NULL;
	current = graph->source;
	current->color = grey;
	current->weight = 0;
	queue = ft_heap_add(queue, ft_wrap_heap(current->weight, (t_vertex **) &current));
	while (queue)
	{
		current = *((t_vertex **) ft_pop_min_heap(&queue, &key));
		if (key == current->weight)
		{
			current->color = black;
			ft_add_implement_verses_in_queue_heap(&queue, current);
		}
	}
	if (graph->sink->parrent)
	{
		current = graph->sink;
		while (current != graph->source)
		{
			ft_reverse_edge_vertex(current->parrent, current);
			current = current->parrent;
		}
		++(graph->pash_count);
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
	return 0;
}
