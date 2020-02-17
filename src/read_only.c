#include "libft.h"
#include "lem_in.h"
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	t_graph *graph;
	int fd;

	fd = open("../input.txt", O_RDONLY);
//	fd = 0;
	graph = NULL;
	if (!ft_get_graph(&graph, fd))
		return (write(2, "Error\n", 6));
	close(fd);

	fd = open("../out.gv", O_CREAT | O_RDWR | O_TRUNC);
	ft_printf("realy?\n");
	ft_print_graph(graph);
	ft_save_graph_as_dot(fd, graph);
	close(fd);
	return (0);
}