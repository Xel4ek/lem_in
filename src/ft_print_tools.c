#include "lem_in.h"
#include "libft.h"

void ft_print_vertex(t_vertex **vertex_list_link, const int size)
{
	int i;
	t_vertex *vertex_list;

	vertex_list = *vertex_list_link;
	i = -1;
	while (++i < size)
		ft_printf("{%d, %s}\n", vertex_list[i].id, vertex_list[i].name);
}