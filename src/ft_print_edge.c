#include "lem_in.h"
#include "libft.h"

void ft_print_egde(t_edge *edge){
	ft_printf("{(%d, %d), %2d, %d}",
			  edge->start->id,
			  edge->end->id,
			  edge->flow,
			  edge->oriented);
}

void ft_print_egde_fd(int fd, t_edge *edge){
	ft_printf_fd(fd, "\t\"%d %s\" -> \"%d %s\";\n",
			  edge->start->id,
			  edge->start->name,
			  edge->end->id,
			  edge->end->name);
}


void ft_print_not_oriented_egde_fd(int fd, t_edge *edge){
	ft_printf_fd(fd, "\t\"%d %s\" -- \"%d %s\";\n",
				 edge->start->id,
				 edge->start->name,
				 edge->end->id,
				 edge->end->name);
}
