#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void ft_save_digraph_as_dot(int fd, const t_graph *graph){
	size_t len;
	t_list *vertex_ptr;

	len = ft_lstdlen(graph->vertex_list);
	vertex_ptr = graph->vertex_list;
	ft_printf_fd(fd, "digraph %s {\n", ft_itoa(fd));
	while (len--)
	{
		ft_print_vertex_dot(fd, (t_vertex *) vertex_ptr->content);
		vertex_ptr = vertex_ptr->next;
	}
	len = ft_lstdlen(graph->vertex_list);
	vertex_ptr = graph->vertex_list;
	while (len--){
//		ft_print_vertex_dot(fd, (t_vertex *) vertex_ptr->content);
		if(((t_vertex *) vertex_ptr->content)->edge_in_list) {
			ft_print_egde_list_dot(fd, ((t_vertex *) vertex_ptr->content)->edge_in_list);
		}
		vertex_ptr = vertex_ptr->next;
	}
	ft_printf_fd(fd, "\t}\n");
}


void ft_save_graph_as_dot(int fd, const t_graph *graph){
	size_t len;
	t_list *vertex_ptr;

	len = ft_lstdlen(graph->vertex_list);
	vertex_ptr = graph->vertex_list;
	ft_printf_fd(fd, "graph %s {\n", ft_itoa(fd));
	while(len--)
	{
		ft_print_vertex_dot(fd, (t_vertex *) vertex_ptr->content);
		vertex_ptr = vertex_ptr->next;
	}
	len = ft_lstdlen(graph->vertex_list);
	vertex_ptr = graph->vertex_list;
	while (len--){

		if(((t_vertex *) vertex_ptr->content)->edge_in_list) {
			ft_print_not_oriented_egde_list_dot(fd, ((t_vertex *) vertex_ptr->content)->edge_in_list);
		}
		vertex_ptr = vertex_ptr->next;
	}
	ft_printf_fd(fd, "\t}\n");
}