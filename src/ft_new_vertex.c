#include "libft.h"
#include "lem_in.h"

t_vertex *ft_new_verex(const int vertex_id, char* name){
	t_vertex *new_vertex;

	if(!(new_vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		return (NULL);
	if(!(new_vertex->name = (char*)ft_memalloc(ft_strlen(name) + 1)))
	{
		ft_memdel((void**)&new_vertex);
		return (NULL);
	}
	new_vertex->edge_in_list = NULL;
	new_vertex->edge_out_list = NULL;
	new_vertex->color = 0;
	new_vertex->parrent = 0;
	new_vertex->test = 0;
	ft_set_vertex(new_vertex, vertex_id, name);
	return (new_vertex);
}