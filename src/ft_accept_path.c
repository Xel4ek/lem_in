#include "lem_in.h"
#include "libft.h"

static int ft_test_push_ants(const int *len, int size, int ant_count)
{
	int i;
	int price;
	int sended_ants;

	i = 0;
	price = 0;
	sended_ants = 0;
	while (ant_count > sended_ants && ++i < size)
	{
		sended_ants += (len[i] - len[i - 1]) * i;
		price += (len[i] - len[i - 1]);
	}
//	ft_printf("%d, send : %d\n",ant_count, sended_ants);
	price += ft_ceil((double) (ant_count - sended_ants) / (double) i);
	price += len[0];
	return (price);
}

int ft_accept_path(t_graph *graph)
{
	int len[graph->pash_count];
	int count;
	int index;
	int steps;
	t_list *list;

	index = 0;
	list = graph->sink->edge_out_list;
	count = ft_lstdlen(graph->sink->edge_out_list);
	while (count--)
	{
		if ((*(t_edge **) list->content)->flow)
			len[index++] = ft_get_pash_len(graph,
				 (t_vertex *) (*(t_edge **) list->content)->end) / 2;
		list = list->next;
	}
	ft_quick_sort(len, len + graph->pash_count - 1);
	steps = ft_test_push_ants(len, graph->pash_count, graph->ants_count);
	ft_printf("%d for pash: ",steps);
	for(int i = 0; i < graph->pash_count; i++)
		ft_printf("% d",len[i]);
	ft_printf("\n");
	if (steps > graph->path_lenght)
		return (0);
	graph->path_lenght = steps;
	return (1);
}