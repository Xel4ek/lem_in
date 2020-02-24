#include "lem_in.h"
#include "libft.h"

void ft_del_graph(t_graph **graph)
{
	if (*graph)
		while((*graph)->vertex_list)
			ft_remove_vertex(graph, (t_vertex**)&(*graph)->vertex_list->content);
	ft_memdel((void**)graph);
}