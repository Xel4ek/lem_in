#include "libft.h"
#include "lem_in.h"

//void ft_reverse_edge(t_edge **edge)
//{
//	t_edge *edge_ptr;
//
//	edge_ptr = *edge;
//	while (*(t_edge **) edge_ptr->start->edge_out_list->content != edge_ptr)
//	{
//		edge_ptr->start->edge_out_list = edge_ptr->start->edge_out_list->next;
//	}
//	while (*(t_edge **) edge_ptr->end->edge_in_list->content != edge_ptr)
//	{
//		edge_ptr->end->edge_in_list = edge_ptr->end->edge_in_list->next;
//	}
////	ft_swap((void*)edge_ptr->start->edge_out_list, (void*)edge_ptr->end->edge_in_list);
////	ft_swap((void*)edge_ptr->start, (void*)edge_ptr->end);
//	ft_lstd_pop_front(&edge_ptr->start->edge_out_list);
//	ft_lstd_pop_front(&edge_ptr->end->edge_in_list);
//	ft_add_edge(edge_ptr->end, edge_ptr->start, edge_ptr->flow,
//				edge_ptr->oriented, edge_ptr->cost);
//}

void ft_reverse_edge_vertex(t_vertex *start, t_vertex *end)
{
	size_t start_len;
	size_t end_len;
	size_t i;

	start_len = ft_lstdlen(start->edge_out_list);
	end_len = ft_lstdlen(end->edge_in_list);
	while (start_len--)
	{
		i = end_len;
		while (i--)
		{
			if (((t_vertex *) (*(t_edge **) end->edge_in_list->content)->start) ==
				start)
			{
//				int temp;
//				if ((*(t_edge **) end->edge_in_list->content)->cost == 2)
//					temp = 0;
//			if ((*(t_edge **) end->edge_in_list->content)->cost == 0)
//					temp = 2;
//			if ((*(t_edge **) end->edge_in_list->content)->cost == 1)
//					temp = 1;

				ft_add_edge(end, start,
							(((*(t_edge**)end->edge_in_list->content)->flow) + 1) % 2,
							(*(t_edge **) end->edge_in_list->content)->oriented,
//							temp);
							-(*(t_edge **) end->edge_in_list->content)->cost);
				ft_remove_edge(((t_edge**)end->edge_in_list->content));
				return;
			}
			end->edge_in_list = end->edge_in_list->next;
		}
		start->edge_out_list = start->edge_out_list->next;
	}
}