#include "libft.h"
#include "lem_in.h"

void ft_reset_vertex_color(t_graph *graph)
{
	size_t graph_size;

	graph_size = ft_lstdlen(graph->vertex_list);
	while (graph_size--)
	{
		((t_vertex*)graph->vertex_list->content)->color = white;
		((t_vertex*)graph->vertex_list->content)->parrent = 0;
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
		if((*((t_edge **)vertex->edge_out_list->content))->end->color == white)
		{
			current = (*((t_edge **)vertex->edge_out_list->content))->end;
			current->color = grey;
			current->parrent = vertex;
			ft_lstd_push_front(queue, ft_lstdnew(&current, sizeof(t_vertex)));
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
	current->color = grey;
	ft_lstd_push_front(&queue, ft_lstdnew(&current, sizeof(t_vertex*)));
	while (queue)
	{
		current = *((t_vertex**)ft_queue_pop(&queue));
		if (current->id == target_id)
		{
			while(current->id)
			{
				ft_printf("%d -> ",current->id);
				current = current->parrent;
			}
			ft_printf("\n");
			return 1;
		}
		current->color = black;
		ft_add_implement_verses_in_queue(current, &queue);
	}
	return 0;
}