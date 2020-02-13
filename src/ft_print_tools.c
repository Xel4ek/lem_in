#include "lem_in.h"
#include "libft.h"

void ft_print_vertex(t_vertex *vertex)
{
	if (vertex->parrent)
		ft_printf("{%d, %s, parent: %d, color: %d, test: %d}\n",
				  vertex->id,
				  vertex->name,
				  vertex->parrent->id,
				  vertex->color,
				  vertex->test);
	else
		ft_printf("{%d, %s, parent: %d, color: %d, test: %d}\n",
				  vertex->id,
				  vertex->name,
				  0,
				  vertex->color,
				  vertex->test);

}

void ft_print_vertex_all(t_vertex **vertex_list_link, const int size)
{
	int i;
	t_vertex *vertex_list;

	vertex_list = *vertex_list_link;
	i = -1;
	while (++i < size)
		ft_printf("{%d, %s}\n", vertex_list[i].id, vertex_list[i].name);
}

void ft_print_vertex_dot(int fd, t_vertex *vertex)
{
		ft_printf_fd(fd, "\t\"%d %s\";\n",
				  vertex->id,
				  vertex->name);
}