#include "lem_in.h"
#include "libft.h"

void ft_split_vertex(t_graph *graph)//, t_vertex **vertex)
{
	t_vertex *new_vertex_out;
	t_vertex *current;
	size_t len;

	current = (t_vertex*)graph->vertex_list->content;
	if (current->id != graph->source_id && current->id != graph->sink_id)
	{
		new_vertex_out = ft_new_verex(current->id + 1, current->name);
		new_vertex_out->edge_out_list = current->edge_out_list;
		new_vertex_out->edge_in_list = NULL;
		current->edge_out_list = NULL;
		len = ft_lstdlen(new_vertex_out->edge_out_list);
		ft_add_vertex_back(graph, new_vertex_out);
		ft_memdel((void **) &new_vertex_out);
		new_vertex_out = (t_vertex*)graph->vertex_list->prev->content;
		while (len--)
		{
			(*(t_edge **) (new_vertex_out)->edge_out_list->content)->start = new_vertex_out;
			new_vertex_out->edge_out_list = new_vertex_out->edge_out_list->next;
		}
		ft_add_edge(current, new_vertex_out, 0,1);
	}
}