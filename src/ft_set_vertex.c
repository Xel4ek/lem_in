#include "lem_in.h"
#include "libft.h"

void ft_set_vertex(t_vertex *vertex, const int vertex_id, const char *name)
{
	vertex->id = vertex_id;
	ft_strcpy(vertex->name, name);

}