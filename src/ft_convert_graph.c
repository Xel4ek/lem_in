#include "lem_in.h"
#include "libft.h"

void ft_convert_graph_to_oriented(t_graph **graph)
{
	size_t vertex_count;
	size_t len;

	len = ft_lstdlen((*graph)->vertex_list);
	vertex_count = len;
	while (vertex_count--)
	{
		ft_split_all_edges((t_vertex *)(*graph)->vertex_list->content);
		(*graph)->vertex_list = (*graph)->vertex_list->next;
	}
	vertex_count = len;
	while (vertex_count--) {
		ft_split_vertex(*graph);
		(*graph)->vertex_list = (*graph)->vertex_list->next;
	}
}
