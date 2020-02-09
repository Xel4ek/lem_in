#include "lem_in.h"
#include "libft.h"

t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, const int flow){
	t_edge *ptr;

	if(!(ptr = (t_edge*)ft_memalloc(sizeof(*ptr))))
		return (NULL);
	ft_set_edge(ptr, start, end, flow);
	return ptr;
}