#include "lem_in.h"
#include "libft.h"

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

		while (vertex->id != -2)
		{
//			ant_id = vertex->ant_id;
			ft_swap(&ant_id, &vertex->ant_id);
			if(vertex->ant_id)
				ft_printf("L%d-%s ",vertex->ant_id, vertex->name);
			vertex = (*(t_edge**)vertex->edge_in_list->content)->start;
			vertex = (*(t_edge**)vertex->edge_in_list->content)->start;
		}
//		ft_swap(&ant_id, &vertex->ant_id);
		if(ant_id)
			ft_printf("L%d-%s ",ant_id, vertex->name);
		path_list = path_list->next;
//		if (len)
//			ft_printf(" | ");
	}
}