#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void ft_print_graph(const t_graph *graph){
	size_t len;
	t_list *vertex_ptr;

	len = ft_lstdlen(graph->vertex_list);
	vertex_ptr = graph->vertex_list;
	while (len--){
		ft_print_vertex((t_vertex *) vertex_ptr->content);
		if(((t_vertex *) vertex_ptr->content)->edge_in_list) {
			ft_printf(GREEN"\tIncoming edges:\n"RESET);
			ft_printf("\t\t");
			ft_print_egde_list(((t_vertex *) vertex_ptr->content)->edge_in_list);
			ft_printf("\n");

		}
		if(((t_vertex *) vertex_ptr->content)->edge_out_list) {
			ft_printf(GREEN"\tOutgoing edges:\n"RESET);
			ft_printf("\t\t");
			ft_print_egde_list(((t_vertex *) vertex_ptr->content)->edge_out_list);
			ft_printf("\n");
		}
		vertex_ptr = vertex_ptr->next;

	}
}