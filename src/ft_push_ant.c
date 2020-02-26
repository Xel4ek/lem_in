#include "lem_in.h"
#include "libft.h"

static  void ft_print_path(t_vertex *head)
{
	char *name;
	int *cur_id;
	if(head->ant_id)
		ft_printf("L%d-%s ", head->ant_id,  (*(t_edge **) head->edge_in_list->content)->start->name);
//	cur_id = &head->ant_id;
	while (head->id != 0)
	{
//		ft_swap(ant_id, &head->ant_id);
//		if (head->ant_id)
		name = head->name;
		cur_id = &head->ant_id;
//		head->ant_id = *cur_id;
		head = (*(t_edge **) head->edge_out_list->content)->end;
		head = (*(t_edge **) head->edge_out_list->content)->end;
		if(head->ant_id)
			ft_printf("L%d-%s ", head->ant_id, name);
		*cur_id = head->ant_id;
	}

}

void ft_push_ant(t_list *path_list, t_graph *graph, int *id)
{
	size_t len;
	t_vertex *vertex;
	int ant_id;

	len = ft_lstdlen(path_list);
	while(len--)
	{
		vertex = (t_vertex*)((t_path*)path_list->content)->head;
		if(((t_path*)path_list->content)->ant_count && graph->ants_count>= *id)
		{
			graph->source->ant_id = ++(*id);
			(((t_path*)path_list->content)->ant_count)--;
		} else
			graph->source->ant_id = 0;

		ft_print_path(vertex);
		path_list = path_list->next;
	}
}