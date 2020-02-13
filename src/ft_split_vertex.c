#include "lem_in.h"
#include "libft.h"

void ft_split_vertex(t_graph **graph, t_vertex **vertex)
{
	t_vertex *new_vertex_in;
	t_vertex *new_vertex_out;
	size_t len;

	if (vertex && *vertex && graph && *graph)
	{
//		new_vertex_in = ft_new_verex((*vertex)->id , (*vertex)->name);
		new_vertex_out = ft_new_verex((*vertex)->id + 1, (*vertex)->name);
//		new_vertex_in->edge_in_list = (*vertex)->edge_in_list;
//		new_vertex_in->edge_out_list = NULL;
//		(*vertex)->edge_in_list = NULL;
//
//		len = ft_lstdlen(new_vertex_in->edge_in_list);
//
//		while (len--)
//		{
//			(*((t_edge**)new_vertex_in->edge_in_list->content))->end = new_vertex_in;
//			new_vertex_in->edge_in_list = new_vertex_in->edge_in_list->next;
//		}


		new_vertex_out->edge_out_list = (*vertex)->edge_out_list;
		new_vertex_out->edge_in_list = NULL;
		(*vertex)->edge_out_list = NULL;

		ft_add_vertex_front(*graph, new_vertex_out);

		len = ft_lstdlen(new_vertex_out->edge_out_list);
		while (len--)
		{
			(*(t_edge**)( (t_vertex*)(*graph)->vertex_list->prev->content)->edge_out_list->content)->start = ( (t_vertex*)(*graph)->vertex_list->prev->content);
			((t_vertex*)(*graph)->vertex_list->prev->content)->edge_out_list = ((t_vertex*)(*graph)->vertex_list->prev->content)->edge_out_list->next;
		}



		ft_add_edge((t_vertex*)(*graph)->vertex_list->content, (t_vertex*)(*graph)->vertex_list->prev->content, 1 , 1);


//		ft_add_vertex_back(*graph , new_vertex_in);

//		ft_remove_vertex(graph, vertex);
	}
}