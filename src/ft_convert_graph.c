#include "lem_in.h"
#include "libft.h"

void ft_convert_graph_to_oriented(t_graph **graph)
{
	size_t vertex_count;

	vertex_count = ft_lstdlen((*graph)->vertex_list);
	while (vertex_count--)
	{
		ft_split_all_edges((t_vertex *)(*graph)->vertex_list->content);
		(*graph)->vertex_list = (*graph)->vertex_list->next;
	}

	vertex_count = ft_lstdlen((*graph)->vertex_list);
	while (vertex_count--)
		ft_split_vertex(graph, (t_vertex **)&(*graph)->vertex_list->content);
}
