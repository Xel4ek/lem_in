#include "lem_in.h"
#include "libft.h"

int ft_accept_new_path(t_graph *graph, int graph_len, int current_cost)
{
	t_list *path_list;
	int pash_count;
	int total = 0;
	int temp = 0;
	int temp1 = 0;


	path_list =  ft_new_path_list(graph, graph_len);
	ft_set_ant_to_pash(graph->ants_count, path_list);
	pash_count = ft_lstdlen(path_list);
	while (pash_count--)
	{
		ft_printf("push %d - count %d - price - %d diff %d\n", ++temp,
				  ((t_path *)path_list->content)->ant_count, ((t_path *)path_list->content)->price,
				  ((t_path *)path_list->content)->price - ((t_path *)path_list->content)->ant_count);
		temp1 +=((t_path *)path_list->content)->price - ((t_path *)path_list->content)->ant_count;
		total += ((t_path *)path_list->content)->ant_count;
		path_list = path_list->next;
	}
	ft_printf("total diff : %d\n",temp1);
	ft_lstd_del(&path_list);
	return 1;
}
