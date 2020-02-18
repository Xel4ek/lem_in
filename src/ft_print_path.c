#include "libft.h"
#include "lem_in.h"

void ft_print_path(t_path *path)
{
	t_vertex *ptr;

	ptr = path->head;
	while (ptr->id != -2)
	{
		if(ptr->ant_id)
			ft_printf("L%d-%s ", ptr->ant_id, ptr->name);
		ptr = (*(t_edge**)ptr->edge_in_list->content)->start;
		ptr = (*(t_edge**)ptr->edge_in_list->content)->start;
	}
	if(ptr->ant_id)
		ft_printf("L%d-%s", ptr->ant_id, ptr->name);
}

void ft_print_path_list(t_list *path_list)
{
	size_t i;


	i = ft_lstdlen(path_list);
	while (i--)
	{
		ft_print_path(path_list->content);
		if(i)
			ft_printf( " | ");
		path_list = path_list->next;
	}
	ft_printf("\n");
}