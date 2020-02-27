#include "libft.h"
#include "lem_in.h"
#include <stdio.h>
int main()
{
    t_vertex *vertex;
    t_graph *graph;
    t_edge *edge;

    graph = NULL;

//    vertex = ft_new_verex(1, "123");
//    graph = ft_add_vertex_back(graph, vertex);
//    ft_add_edge(vertex, vertex);
	printf("test %zu\n", ft_strlen(""));
	printf("test %zu - \n", strlen(""));

	printf("test %zu\n", ft_strlen("111923"));
	printf("test %zu - \n", strlen("111923"));
	printf("test %zu\n", ft_strlen("1119238120381238128301928najksandkiasndandoqnoiandpwPNDNDpDNPANDAINDAODNWOAD3"));
	printf("test %zu - \n", strlen("1119238120381238128301928najksandkiasndandoqnoiandpwPNDNDpDNPANDAINDAODNWOAD3"));
    ft_printf("graph : %d\n", sizeof(t_vertex));
    ft_printf("vertex : %d\n", sizeof(t_graph));
    ft_printf("edge : %d\n", sizeof(t_edge));
    ft_printf("path : %d\n", sizeof(t_path));
    ft_printf("gptr : %d\n", sizeof(t_gptr));
}