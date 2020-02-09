#include "lem_in.h"

void	ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, const int flow){
	edge->start = start;
	edge->end = end;
	edge->flow = flow;
}