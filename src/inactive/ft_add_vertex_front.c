void ft_add_vertex_front(t_graph *graph, t_vertex *vertex)
{
	t_list *new_vertex;

	new_vertex = ft_lstd_wrap(vertex, sizeof(*vertex));
	ft_lstd_push_front((t_list**)&graph->vertex_list, new_vertex);
}