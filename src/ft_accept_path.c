#include "lem_in.h"
#include "libft.h"


int ft_accept_path(t_graph *graph)
{

	if (graph->pash_count == 16)
		return 0;
	return 1;
}

//			test = current;
//			while (test->id)
//			{
//				while (((t_vertex*)(*(t_edge**)test->edge_in_list->content)->start) != test->parrent)
//					test->edge_in_list = test->edge_in_list->next;
//				if ((*(t_edge**)test->edge_in_list->content)->flow) {
//					i -= 3;
//					count++;
//				}

//				test = test->parrent;
//			}
//			if (count)
//				i -= 2;
//			ft_printf(GREEN"Renew egdes :%d\n"RESET, count);
//			int test3;
//			test3 = 0;
//			if (*path_id != 0)
//				ft_printf("need time %d (%d) {%f}  - ",
//						  test3 = (*prev_pash_len   + graph->ants_count - 1), test3, ok1 = (double)test3 / (double)*path_id);
//
//
//			(*prev_pash_len) += (i - 1) /2 ;

//
//			int test2;
//
//			ft_printf("%d (%d) {%f} \n",
//					  test2 = (*prev_pash_len  + graph->ants_count - 1), test2, ok2 = (double)test2 / (double)*path_id);
//			if (*path_id == 16)
////			if (ok2 > ok1)
//				return 0;