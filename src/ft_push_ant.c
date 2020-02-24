#include "lem_in.h"
#include "libft.h"

static  void ft_print_path(t_vertex *head, int *ant_id)
{
	while (head->id != -2)
	{
		ft_swap(ant_id, &head->ant_id);
		if(head->ant_id)
			ft_printf("L%d-%s ", head->ant_id, head->name);
		head = (*(t_edge**)head->edge_in_list->content)->start;
		head = (*(t_edge**)head->edge_in_list->content)->start;
	}
	if(*ant_id)
		ft_printf("L%d-%s", head->ant_id, head->name);
}

void ft_push_ant(t_list *path_list, int *id, int max_id)
{
	size_t len;
	t_vertex *vertex;
	int ant_id;

	len = ft_lstdlen(path_list);
	while(len--)
	{
		vertex = (t_vertex*)((t_path*)path_list->content)->head;
		if(((t_path*)path_list->content)->ant_count && max_id >= *id)
		{
			ant_id = (*id)++;
			(((t_path*)path_list->content)->ant_count)--;
		} else
			ant_id = 0;
		ft_print_path(vertex, &ant_id);
		path_list = path_list->next;
	}
}