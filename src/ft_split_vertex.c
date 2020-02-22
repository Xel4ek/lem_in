#include "lem_in.h"
#include "libft.h"

void ft_split_vertex(t_graph **graph, t_vertex **vertex)
{
	t_vertex *new_vertex_out;
	size_t len;

	if (vertex && *vertex && graph && *graph)
		if ((*vertex)->id != (*graph)->source_id && (*vertex)->id != (*graph)->sink_id)
		{
			new_vertex_out = ft_new_verex((*vertex)->id + 1, (*vertex)->name);
			new_vertex_out->edge_out_list = (*vertex)->edge_out_list;
			new_vertex_out->edge_in_list = NULL;
			(*vertex)->edge_out_list = NULL;
			ft_add_vertex_back(*graph, new_vertex_out);
			len = ft_lstdlen(new_vertex_out->edge_out_list);
			while (len--)
			{
				(*(t_edge **) ((t_vertex *) (*graph)->vertex_list->prev->content)->edge_out_list->content)->start = ((t_vertex *) (*graph)->vertex_list->prev->content);
				((t_vertex *) (*graph)->vertex_list->prev->content)->edge_out_list = ((t_vertex *) (*graph)->vertex_list->prev->content)->edge_out_list->next;
			}
			ft_add_edge((t_vertex *) (*graph)->vertex_list->content,
						(t_vertex *) (*graph)->vertex_list->prev->content, 0,
						1);
		}
}