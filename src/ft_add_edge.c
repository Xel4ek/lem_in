#include "lem_in.h"
#include "libft.h"

int ft_add_edge(t_vertex *start, t_vertex *end, int flow, int oriented, int cost)
{
	t_edge *new_edge;
	t_list *new;

	if (!(new_edge = ft_new_edge(start, end, flow, oriented, cost)))
		return (0);
	new = ft_lstdnew(&new_edge, sizeof(t_edge *));
	if (start->edge_out_list)
		ft_lstd_push_back(&start->edge_out_list, new);
	else
		start->edge_out_list = new;
	new = ft_lstdnew(&new_edge, sizeof(t_edge *));
	if (end->edge_in_list)
		ft_lstd_push_back(&end->edge_in_list, new);
	else
		end->edge_in_list = new;
	return (1);
}