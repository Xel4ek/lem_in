#include "lem_in.h"
#include "libft.h"

void ft_split_vertex(t_graph **graph, t_vertex **vertex)
{
	t_vertex *new_vertex_in;
	t_vertex *new_vertex_out;
	size_t len;

	if (vertex && *vertex && graph && *graph)
	{
		new_vertex_in = ft_new_verex((*vertex)->id , (*vertex)->name);
		new_vertex_out = ft_new_verex((*vertex)->id + 1, (*vertex)->name);
		new_vertex_in->edge_in_list = (*vertex)->edge_in_list;
		new_vertex_in->edge_out_list = NULL;
		(*vertex)->edge_in_list = NULL;

		len = ft_lstdlen(new_vertex_in->edge_in_list);

		while (len--)
		{
			(*((t_edge**)new_vertex_in->edge_in_list->content))->end = new_vertex_in;
			new_vertex_in->edge_in_list = new_vertex_in->edge_in_list->next;
		}

		new_vertex_out->edge_out_list = (*vertex)->edge_out_list;
		new_vertex_out->edge_in_list = NULL;
		(*vertex)->edge_out_list = NULL;

		len = ft_lstdlen(new_vertex_out->edge_out_list);
		while (len--)
		{
			(*((t_edge**)new_vertex_out->edge_out_list->content))->start = new_vertex_out;
			new_vertex_out->edge_out_list = new_vertex_out->edge_out_list->next;
		}
		ft_add_edge(new_vertex_in, new_vertex_out, 1 , 1);
		ft_add_vertex(*graph , new_vertex_in);
		ft_add_vertex(*graph, new_vertex_out);
		ft_remove_vertex(graph, vertex);
	}
}