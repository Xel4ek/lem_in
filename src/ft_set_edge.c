#include "lem_in.h"

void	ft_set_edge(t_edge *const edge, t_vertex *const start, t_vertex *const end, int flow, int oriented){
	edge->start = start;
	edge->end = end;
	edge->oriented = oriented;
	edge->flow = flow;
}