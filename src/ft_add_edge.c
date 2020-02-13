#include "lem_in.h"
#include "libft.h"

int ft_add_edge(t_vertex *start, t_vertex *end, int flow, int oriented)
{
	t_edge *new_edge;

	if (!(new_edge = ft_new_edge(start, end, flow, oriented)))
		return (0);

	if (start->edge_out_list)
		ft_lstd_push_front(&start->edge_out_list,
						  ft_lstdnew(&new_edge, sizeof(t_edge *)));
	else
		start->edge_out_list = ft_lstdnew(&new_edge, sizeof(t_edge *));
	if (end->edge_in_list)
		ft_lstd_push_front(&end->edge_in_list,
						  ft_lstdnew(&new_edge, sizeof(t_edge *)));
	else
		end->edge_in_list = ft_lstdnew(&new_edge, sizeof(t_edge *));
	return (1);
}