#include "lem_in.h"
#include "libft.h"

void ft_remove_zero_flow(t_graph *graph)
{
	int i;
	int j;

	i = graph->vertex_count;
	while (i--)
	{
		j = ft_lstdlen(
				((t_vertex *) graph->vertex_list->content)->edge_out_list);
		while (j--)
		{
			if ((*((t_edge **) ((t_vertex *) graph->vertex_list->content)->edge_out_list->content))->flow == 0)
				ft_remove_edge(((t_edge **) ((t_vertex *) graph->vertex_list->content)->edge_out_list->content));
			else
				((t_vertex *) graph->vertex_list->content)->edge_out_list = ((t_vertex *) graph->vertex_list->content)->edge_out_list->next;

		}
		graph->vertex_list = graph->vertex_list->next;
	}
	i = graph->vertex_count;
	while (i--)
	{
		if (((t_vertex *) graph->vertex_list->content)->edge_out_list == NULL &&
			((t_vertex *) graph->vertex_list->content)->edge_in_list == NULL)
			ft_remove_vertex(&graph,
							 (t_vertex **) &graph->vertex_list->content);
		else
			graph->vertex_list = graph->vertex_list->next;
	}
}