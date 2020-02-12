#include "lem_in.h"
#include "libft.h"

void ft_print_egde(t_edge *edge){
	ft_printf("{(%d, %d), %2d, %d}",
			  edge->start->id,
			  edge->end->id,
			  edge->flow,
			  edge->oriented);
}