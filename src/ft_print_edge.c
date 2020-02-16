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
		if ((edge->start->test == 1 && edge->end->test == 1 && edge->start->id == (edge->end->parrent == NULL ? 0 : edge->end->parrent->id)) ||
				(edge->end->test == 1 && edge->start->test == 1 && edge->end->id == (edge->start->parrent == NULL ? 0 : edge->start->parrent->id)))
			ft_printf_fd(fd, "\t\"%d %s\" -> \"%d %s\" [dir = forward color = \"green\"];\n",
						 edge->start->id,
						 edge->start->name,
						 edge->end->id,
						 edge->end->name);
		else
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
