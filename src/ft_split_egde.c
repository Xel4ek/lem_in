#include "libft.h"
#include "lem_in.h"

void ft_split_edge(t_edge **edge)
{
	t_edge *edge_ptr;

	if (*edge && !(*edge)->oriented)
	{
		edge_ptr = *edge;
		ft_add_edge(edge_ptr->start, edge_ptr->end, edge_ptr->flow, 1);
		ft_add_edge(edge_ptr->end, edge_ptr->start, edge_ptr->flow, 1);
		ft_remove_edge(edge);
	}
}