#include "lem_in.h"
#include "libft.h"

int ft_get_pash_len(const t_graph *const graph, t_vertex *vertex)
{
	size_t len;
	int temp;
	t_vertex *ptr;

	ptr = vertex;
	len = 0;
	while (ptr != graph->source)
	{
		temp = ft_lstdlen(ptr->edge_out_list);
		while ((*(t_edge **) ptr->edge_out_list->content)->flow == 0 && temp--)
			ptr->edge_out_list = ptr->edge_out_list->next;
		if (temp == -1)
			return (0);
		ptr = (t_vertex *) (*(t_edge **) ptr->edge_out_list->content)->end;
		++len;
	}
	return (len);
}
