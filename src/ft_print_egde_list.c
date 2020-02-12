#include "lem_in.h"
#include "libft.h"

void ft_print_egde_list(t_list *egde_list)
{
	size_t len;
	t_list *edge_ptr;

	len = ft_lstdlen(egde_list);
	edge_ptr = egde_list;
	while (len--)
	{
		ft_print_egde(*(t_edge**)edge_ptr->content);
		ft_printf("\t");
		edge_ptr = edge_ptr->next;
	}
}