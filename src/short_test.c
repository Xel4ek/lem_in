#include "libft.h"
#include "lem_in.h"

int main()
{
    t_vertex *vertex;
    t_graph *graph;
    t_edge *edge;

    graph = NULL;

//    vertex = ft_new_verex(1, "123");
//    graph = ft_add_vertex_back(graph, vertex);
//    ft_add_edge(vertex, vertex);

    ft_printf("graph : %d\n", sizeof(t_vertex));
    ft_printf("vertex : %d\n", sizeof(t_graph));
    ft_printf("edge : %d\n", sizeof(t_edge));
}