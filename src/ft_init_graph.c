#include "lem_in.h"
#include "libft.h"

t_graph	*ft_init_graph(void)
{
	t_graph	*graph;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	graph->sink = NULL;
	graph->source = NULL;
	graph->vertex_list = NULL;
	graph->ants_count = 0;
	graph->pash_count = 0;
	graph->path_lenght = 0;
	graph->vertex_count = 0;
	return (graph);
}